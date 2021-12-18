#include "global.h"
#include "vt.h"

StackEntry sDmaMgrStackInfo;
OSMesgQueue sDmaMgrMsgQueue;
OSMesg sDmaMgrMsgs[0x20];
OSThread sDmaMgrThread;
u8 sDmaMgrStack[0x500];
const char* sDmaMgrCurFileName;
s32 sDmaMgrCurFileLine;

u32 D_80009460 = 0;
u32 gDmaMgrDmaBuffSize = 0x2000;
u32 sDmaMgrDataExistError = 0;

// dmadata filenames
#define DEFINE_DMA_ENTRY(name) #name,

const char* sDmaMgrFileNames[] = {
#include "tables/dmadata_table.h"
};

#undef DEFINE_DMA_ENTRY

s32 DmaMgr_CompareName(const char* name1, const char* name2) {
    while (*name1 != 0u) {
        if (*name1 > *name2) {
            return 1;
        }

        if (*name1 < *name2) {
            return -1;
        }

        name1++;
        name2++;
    }

    if (*name2 > 0) {
        return -1;
    }

    return 0;
}

s32 DmaMgr_DmaRomToRam(u32 rom, u32 ram, u32 size) {
    OSIoMesg ioMsg;
    OSMesgQueue queue;
    OSMesg msg;
    s32 ret;
    u32 buffSize = gDmaMgrDmaBuffSize;
    s32 pad[2];

    if (buffSize == 0) {
        buffSize = 0x2000;
    }

    osInvalICache((void*)ram, size);
    osInvalDCache((void*)ram, size);
    osCreateMesgQueue(&queue, &msg, 1);

    while (size > buffSize) {
         
        ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
        ioMsg.hdr.retQueue = &queue;
        ioMsg.devAddr = rom;
        ioMsg.dramAddr = (void*)ram;
        ioMsg.size = buffSize;

        if (D_80009460 == 10) {
            osSyncPrintf("%10lld Normal DMA %08X %08X %08X (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), ioMsg.dramAddr,
                         ioMsg.devAddr, ioMsg.size, gPiMgrCmdQ.validCount);
        }

        ret = osEPiStartDma(gCartHandle, &ioMsg, OS_READ);
        if (ret) {
            goto end;
        }

        if (D_80009460 == 10) {
            osSyncPrintf("%10lld Normal DMA START (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), gPiMgrCmdQ.validCount);
        }

        osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
        if (D_80009460 == 10) {
            osSyncPrintf("%10lld Normal DMA END (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), gPiMgrCmdQ.validCount);
        }

        size -= buffSize;
        rom += buffSize;
        ram += buffSize;
    }

     // Also necessary to match

    ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMsg.hdr.retQueue = &queue;
    ioMsg.devAddr = rom;
    ioMsg.dramAddr = (void*)ram;
    ioMsg.size = size;

    if (D_80009460 == 10) {
        osSyncPrintf("%10lld Normal DMA %08X %08X %08X (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), ioMsg.dramAddr,
                     ioMsg.devAddr, ioMsg.size, gPiMgrCmdQ.validCount);
    }

    ret = osEPiStartDma(gCartHandle, &ioMsg, OS_READ);
    if (ret) {
        goto end;
    }

    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    if (D_80009460 == 10) {
        osSyncPrintf("%10lld Normal DMA END (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), gPiMgrCmdQ.validCount);
    }

end:
    osInvalICache((void*)ram, size);
    osInvalDCache((void*)ram, size);

    return ret;
}

s32 DmaMgr_DmaHandler(OSPiHandle* pihandle, OSIoMesg* mb, s32 direction) {
    s32 ret;

    ASSERT(pihandle == gCartHandle, "pihandle == gCartHandle", "../z_std_dma.c", __LINE__);
    ASSERT(direction == OS_READ, "direction == OS_READ", "../z_std_dma.c", __LINE__);
    ASSERT(mb != NULL, "mb != NULL", "../z_std_dma.c", __LINE__);

    if (D_80009460 == 10) {
        osSyncPrintf("%10lld Sound DMA %08X %08X %08X (%d)\n", OS_CYCLES_TO_USEC(osGetTime()), mb->dramAddr,
                     mb->devAddr, mb->size, gPiMgrCmdQ.validCount);
    }

    ret = osEPiStartDma(pihandle, mb, direction);
    if (ret) {
        osSyncPrintf("OOPS!!\n");
    }
    return ret;
}

void DmaMgr_DmaFromDriveRom(u32 ram, u32 rom, u32 size) {
    OSPiHandle* handle = osDriveRomInit();
    OSMesgQueue queue;
    OSMesg msg;
    OSIoMesg ioMsg;

    osInvalICache((void*)ram, size);
    osInvalDCache((void*)ram, size);
    osCreateMesgQueue(&queue, &msg, 1);

    ioMsg.hdr.retQueue = &queue;
    ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMsg.devAddr = rom;
    ioMsg.dramAddr = (void*)ram;
    ioMsg.size = size;
    handle->transferInfo.cmdType = 2;

    osEPiStartDma(handle, &ioMsg, OS_READ);
    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    return;
}

void DmaMgr_Error(DmaRequest* req, const char* file, const char* errorName, const char* errorDesc) {
    u32 vrom = req->vromAddr;
    u32 ram = (u32)req->dramAddr;
    u32 size = req->size;
    char buff1[80];
    char buff2[80];

    osSyncPrintf("%c", 7);
    osSyncPrintf(VT_FGCOL(RED));
    osSyncPrintf("DMA fatal error(%s)\nROM:%X RAM:%X SIZE:%X %s\n",
                 errorDesc != NULL ? errorDesc : (errorName != NULL ? errorName : "???"), vrom, ram, size,
                 file != NULL ? file : "???");

    if (req->filename) {
        osSyncPrintf("DMA ERROR: %s %d", req->filename, req->line);
    } else if (sDmaMgrCurFileName) {
        osSyncPrintf("DMA ERROR: %s %d", sDmaMgrCurFileName, sDmaMgrCurFileLine);
    }

    osSyncPrintf(VT_RST);

    if (req->filename) {
        sprintf(buff1, "DMA ERROR: %s %d", req->filename, req->line);
    } else if (sDmaMgrCurFileName) {
        sprintf(buff1, "DMA ERROR: %s %d", sDmaMgrCurFileName, sDmaMgrCurFileLine);
    } else {
        sprintf(buff1, "DMA ERROR: %s", errorName != NULL ? errorName : "???");
    }

    sprintf(buff2, "%07X %08X %X %s", vrom, ram, size, file != NULL ? file : "???");
    Fault_AddHungupAndCrashImpl(buff1, buff2);
}

const char* DmaMgr_GetFileNameImpl(u32 vrom) {
    DmaEntry* iter = gDmaDataTable;
    const char** name = sDmaMgrFileNames;

    while (iter->vromEnd) {
        if (vrom >= iter->vromStart && vrom < iter->vromEnd) {
            return *name;
        }

        iter++;
        name++;
    }
    //! @bug Since there is no return, in case the file isn't found, the return value will be a pointer to the end
    // of gDmaDataTable
}

const char* DmaMgr_GetFileName(u32 vrom) {
    const char* ret = DmaMgr_GetFileNameImpl(vrom);

    if (ret == NULL) {
        return "(unknown)";
    }

    if (DmaMgr_CompareName(ret, "kanji") == 0 || DmaMgr_CompareName(ret, "link_animetion") == 0) {
        return NULL;
    }

    return ret;
}

void DmaMgr_ProcessMsg(DmaRequest* req) {
    u32 vrom = req->vromAddr;
    void* ram = req->dramAddr;
    u32 size = req->size;
    u32 romStart;
    u32 romSize;
    u8 found = false;
    DmaEntry* iter;
    const char* filename;

    if (0) {
        // the string is defined in .rodata but not used, suggesting
        // a debug print is here but optimized out in some way
        osSyncPrintf("DMA ROM:%08X RAM:%08X SIZE:%08X %s\n");
        // the last arg of this print looks like it may be filename, but
        // filename above this block does not match
    }

    filename = DmaMgr_GetFileName(vrom);
    iter = gDmaDataTable;

    while (iter->vromEnd) {
        if (vrom >= iter->vromStart && vrom < iter->vromEnd) {
             
            if (iter->romEnd == 0) {
                if (iter->vromEnd < vrom + size) {
                    DmaMgr_Error(req, filename, "Segment Alignment Error",
                                 "DMA transfers across segment boundaries are not allowed.");
                }

                DmaMgr_DmaRomToRam(iter->romStart + (vrom - iter->vromStart), (u32)ram, size);
                found = true;

                if (0) {
                    osSyncPrintf("No Press ROM:%08X RAM:%08X SIZE:%08X\n", vrom, ram, size);
                }
            } else {
                romStart = iter->romStart;
                romSize = iter->romEnd - iter->romStart;

                if (vrom != iter->vromStart) {
                    DmaMgr_Error(req, filename, "Can't Transfer Segment",
                                 "DMA transfer from the middle of a compressed segment is not possible.");
                }

                if (size != iter->vromEnd - iter->vromStart) {
                    DmaMgr_Error(req, filename, "Can't Transfer Segment",
                                 "It is not possible to transfer only a part of a compressed segment through DMA");
                }

                osSetThreadPri(NULL, Z_PRIORITY_MAIN);
                Yaz0_Decompress(romStart, ram, romSize);
                osSetThreadPri(NULL, Z_PRIORITY_DMAMGR);
                found = true;

                if (0) {
                    osSyncPrintf("   Press ROM:%X RAM:%X SIZE:%X\n", vrom, ram, size);
                }
            }
            break;
        }
        iter++;
    }

    if (!found) {
        if (sDmaMgrDataExistError) {
            DmaMgr_Error(req, NULL, "DATA DOESN'T EXIST", "No applicable data exists.");
            return;
        }

        DmaMgr_DmaRomToRam(vrom, (u32)ram, size);

        if (0) {
            osSyncPrintf("No Press ROM:%08X RAM:%08X SIZE:%08X (informal)\n", vrom, ram, size);
        }
    }
}

void DmaMgr_ThreadEntry(void* arg0) {
    OSMesg msg;
    DmaRequest* req;

    osSyncPrintf("Start execution of DMA manager thread\n");
    while (true) {
        osRecvMesg(&sDmaMgrMsgQueue, &msg, OS_MESG_BLOCK);
        req = (DmaRequest*)msg;
        if (req == NULL) {
            break;
        }

        if (0) {
            osSyncPrintf("DMA registration accepted req=%08X\n", req);
        }

        DmaMgr_ProcessMsg(req);
        if (req->notifyQueue) {
            osSendMesg(req->notifyQueue, req->notifyMsg, OS_MESG_NOBLOCK);
            if (0) {
                osSyncPrintf("osSendMesg: req=%08X, req->notifyQueue=%08x, req->notifyMsg=%08X \n", req, req->notifyQueue, req->notifyMsg);
            }
        }
    }
    osSyncPrintf("End of DMA manager thread execution\n");
}

s32 DmaMgr_SendRequestImpl(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk, OSMesgQueue* queue, OSMesg msg) {
    static s32 sDmaMgrQueueFullLogged = 0;

    if ((1 && (ram == 0)) || (osMemSize < ram + size + 0x80000000) || (vrom & 1) || (vrom > 0x4000000) || (size == 0) ||
        (size & 1)) {
        DmaMgr_Error(req, NULL, "ILLEGAL DMA-FUNCTION CALL", "Parameter error");
    }

    req->vromAddr = vrom;
    req->dramAddr = (void*)ram;
    req->size = size;
    req->unk_14 = 0;
    req->notifyQueue = queue;
    req->notifyMsg = msg;

    if (1) {
        if ((sDmaMgrQueueFullLogged == 0) && (sDmaMgrMsgQueue.validCount >= sDmaMgrMsgQueue.msgCount)) {
            sDmaMgrQueueFullLogged++;
            osSyncPrintf("%c", 7);
            osSyncPrintf(VT_FGCOL(RED));
            osSyncPrintf("sDmaMgrMsgQueue is full. We recommend that you reconsider the queue size.");
            LOG_NUM("(sizeof(sDmaMgrMsgs) / sizeof(sDmaMgrMsgs[0]))", ARRAY_COUNT(sDmaMgrMsgs),
                    "../z_std_dma.c", __LINE__);
            osSyncPrintf(VT_RST);
        }
    }

    osSendMesg(&sDmaMgrMsgQueue, req, OS_MESG_BLOCK);
    return 0;
}

s32 DmaMgr_SendRequest0(u32 ram, u32 vrom, u32 size) {
    DmaRequest req;
    OSMesgQueue queue;
    OSMesg msg;
    s32 ret;

    osCreateMesgQueue(&queue, &msg, 1);
    ret = DmaMgr_SendRequestImpl(&req, ram, vrom, size, 0, &queue, NULL);
    if (ret == -1) {
        return ret;
    }

    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    return 0;
}

void DmaMgr_Init(void) {
    const char** name;
    s32 idx;
    DmaEntry* iter;

    DmaMgr_DmaRomToRam((u32)_dmadataSegmentRomStart, (u32)_dmadataSegmentStart,
                       (u32)(_dmadataSegmentRomEnd - _dmadataSegmentRomStart));
    osSyncPrintf("gDmaDataTable[]\n");

    sDmaMgrDataExistError = 0;
    name = sDmaMgrFileNames;
    iter = gDmaDataTable;
    idx = 0;

    while (iter->vromEnd != 0) {
        if (iter->romEnd != 0) {
            sDmaMgrDataExistError = 1;
        }

        osSyncPrintf(
            "%3d %08x %08x %08x %08x %08x %c %s\n", idx, iter->vromStart, iter->vromEnd, iter->romStart, iter->romEnd,
            (iter->romEnd != 0) ? iter->romEnd - iter->romStart : iter->vromEnd - iter->vromStart,
            (((iter->romEnd != 0) ? iter->romEnd - iter->romStart : 0) > 0x10000) ? '*' : ' ', name ? *name : "");

        idx++;
        iter++;

        if (name) {
            name++;
        }
    }

    if ((u32)_bootSegmentRomStart != gDmaDataTable[0].vromEnd) {
        osSyncPrintf("_bootSegmentRomStart(%08x) != dma_rom_ad[0].rom_b(%08x)\n", _bootSegmentRomStart,
                     gDmaDataTable[0].vromEnd);
        Fault_AddHungupAndCrash("../z_std_dma.c", 1055);
    }

    osCreateMesgQueue(&sDmaMgrMsgQueue, sDmaMgrMsgs, ARRAY_COUNT(sDmaMgrMsgs));
    StackCheck_Init(&sDmaMgrStackInfo, sDmaMgrStack, sDmaMgrStack + sizeof(sDmaMgrStack), 0, 0x100, "dmamgr");
    osCreateThread(&sDmaMgrThread, 0x12, DmaMgr_ThreadEntry, 0, sDmaMgrStack + sizeof(sDmaMgrStack), Z_PRIORITY_DMAMGR);
    osStartThread(&sDmaMgrThread);
}

s32 DmaMgr_SendRequest2(DmaRequest* req, u32 ram, u32 vrom, u32 size, u32 unk5, OSMesgQueue* queue, OSMesg msg,
                        const char* file, s32 line) {
    req->filename = file;
    req->line = line;
    DmaMgr_SendRequestImpl(req, ram, vrom, size, unk5, queue, msg);
}

s32 DmaMgr_SendRequest1(void* ram0, u32 vrom, u32 size, const char* file, s32 line) {
    DmaRequest req;
    s32 ret;
    OSMesgQueue queue;
    OSMesg msg;
    u32 ram = (u32)ram0;

    req.filename = file;
    req.line = line;
    osCreateMesgQueue(&queue, &msg, 1);
    ret = DmaMgr_SendRequestImpl(&req, ram, vrom, size, 0, &queue, 0);
    if (ret == -1) {
        return ret;
    }

    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    return 0;
}
