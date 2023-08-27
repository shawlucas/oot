#include "global.h"
#include "terminal.h"

#define GFXPOOL_HEAD_MAGIC 0x1234
#define GFXPOOL_TAIL_MAGIC 0x5678

/**
 * The time at which the previous `Graph_Update` ended.
 */
OSTime sGraphPrevUpdateEndTime;

/**
 * The time at which the previous graphics task was scheduled to run.
 */
OSTime sGraphPrevTaskTimeStart;

FaultClient sGraphFaultClient;
CfbInfo sGraphCfbInfos[3];
FaultClient sGraphUcodeFaultClient;

UCodeInfo D_8012D230[3] = {
    { UCODE_F3DZEX, gspF3DZEX2_NoN_PosLight_fifoTextStart },
    { UCODE_UNK, NULL },
    { UCODE_S2DEX, gspS2DEX2d_fifoTextStart },
};

UCodeInfo D_8012D248[3] = {
    { UCODE_F3DZEX, gspF3DZEX2_NoN_PosLight_fifoTextStart },
    { UCODE_UNK, NULL },
    { UCODE_S2DEX, gspS2DEX2d_fifoTextStart },
};

void Graph_FaultClient(void) {
    void* nextFb = osViGetNextFramebuffer();
    void* newFb = (SysCfb_GetFbPtr(0) != nextFb) ? SysCfb_GetFbPtr(0) : SysCfb_GetFbPtr(1);

    osViSwapBuffer(newFb);
    Fault_WaitForInput();
    osViSwapBuffer(nextFb);
}

// TODO: merge Gfx and GfxMod to make this function's arguments consistent
void UCodeDisas_Disassemble(UCodeDisas*, Gfx*);

void Graph_DisassembleUCode(Gfx* workBuf) {
    UCodeDisas disassembler;

    if (R_HREG_MODE == HREG_MODE_UCODE_DISAS && R_UCODE_DISAS_TOGGLE != 0) {
        UCodeDisas_Init(&disassembler);
        disassembler.enableLog = R_UCODE_DISAS_LOG_LEVEL;

        UCodeDisas_RegisterUCode(&disassembler, ARRAY_COUNT(D_8012D230), D_8012D230);
        UCodeDisas_SetCurUCode(&disassembler, gspF3DZEX2_NoN_PosLight_fifoTextStart);

        UCodeDisas_Disassemble(&disassembler, workBuf);

        R_UCODE_DISAS_DL_COUNT = disassembler.dlCnt;
        R_UCODE_DISAS_TOTAL_COUNT =
            disassembler.tri2Cnt * 2 + disassembler.tri1Cnt + (disassembler.quadCnt * 2) + disassembler.lineCnt;
        R_UCODE_DISAS_VTX_COUNT = disassembler.vtxCnt;
        R_UCODE_DISAS_SPVTX_COUNT = disassembler.spvtxCnt;
        R_UCODE_DISAS_TRI1_COUNT = disassembler.tri1Cnt;
        R_UCODE_DISAS_TRI2_COUNT = disassembler.tri2Cnt;
        R_UCODE_DISAS_QUAD_COUNT = disassembler.quadCnt;
        R_UCODE_DISAS_LINE_COUNT = disassembler.lineCnt;
        R_UCODE_DISAS_SYNC_ERROR_COUNT = disassembler.syncErr;
        R_UCODE_DISAS_LOAD_COUNT = disassembler.loaducodeCnt;

        if (R_UCODE_DISAS_LOG_MODE == 1 || R_UCODE_DISAS_LOG_MODE == 2) {
            osSyncPrintf("vtxCnt=%d\n", disassembler.vtxCnt);
            osSyncPrintf("spvtxCnt=%d\n", disassembler.spvtxCnt);
            osSyncPrintf("tri1Cnt=%d\n", disassembler.tri1Cnt);
            osSyncPrintf("tri2Cnt=%d\n", disassembler.tri2Cnt);
            osSyncPrintf("quadCnt=%d\n", disassembler.quadCnt);
            osSyncPrintf("lineCnt=%d\n", disassembler.lineCnt);
            osSyncPrintf("syncErr=%d\n", disassembler.syncErr);
            osSyncPrintf("loaducodeCnt=%d\n", disassembler.loaducodeCnt);
            osSyncPrintf("dlDepth=%d\n", disassembler.dlDepth);
            osSyncPrintf("dlCnt=%d\n", disassembler.dlCnt);
        }

        UCodeDisas_Destroy(&disassembler);
    }
}

void Graph_UCodeFaultClient(Gfx* workBuf) {
    UCodeDisas disassembler;

    UCodeDisas_Init(&disassembler);
    disassembler.enableLog = true;
    UCodeDisas_RegisterUCode(&disassembler, ARRAY_COUNT(D_8012D248), D_8012D248);
    UCodeDisas_SetCurUCode(&disassembler, gspF3DZEX2_NoN_PosLight_fifoTextStart);
    UCodeDisas_Disassemble(&disassembler, workBuf);
    UCodeDisas_Destroy(&disassembler);
}

void Graph_InitTHGA(GraphicsContext* gfxCtx) {
    GfxPool* pool = &gGfxPools[gfxCtx->gfxPoolIdx & 1];

    pool->headMagic = GFXPOOL_HEAD_MAGIC;
    pool->tailMagic = GFXPOOL_TAIL_MAGIC;
    THGA_Init(&gfxCtx->polyOpa, pool->polyOpaBuffer, sizeof(pool->polyOpaBuffer));
    THGA_Init(&gfxCtx->polyXlu, pool->polyXluBuffer, sizeof(pool->polyXluBuffer));
    THGA_Init(&gfxCtx->overlay, pool->overlayBuffer, sizeof(pool->overlayBuffer));
    THGA_Init(&gfxCtx->work, pool->workBuffer, sizeof(pool->workBuffer));

    gfxCtx->polyOpaBuffer = pool->polyOpaBuffer;
    gfxCtx->polyXluBuffer = pool->polyXluBuffer;
    gfxCtx->overlayBuffer = pool->overlayBuffer;
    gfxCtx->workBuffer = pool->workBuffer;

    gfxCtx->curFrameBuffer = SysCfb_GetFbPtr(gfxCtx->fbIdx % 2);
    gfxCtx->unk_014 = 0;
}

GameStateOverlay* Graph_GetNextGameState(GameState* gameState) {
    void* gameStateInitFunc = GameState_GetInit(gameState);

    // Generates code to match gameStateInitFunc to a gamestate entry and returns it if found
#define DEFINE_GAMESTATE_INTERNAL(typeName, enumName) \
    if (gameStateInitFunc == typeName##_Init) {       \
        return &gGameStateOverlayTable[enumName];     \
    }
#define DEFINE_GAMESTATE(typeName, enumName, name) DEFINE_GAMESTATE_INTERNAL(typeName, enumName)
#include "tables/gamestate_table.h"
#undef DEFINE_GAMESTATE
#undef DEFINE_GAMESTATE_INTERNAL

    LOG_ADDRESS("game_init_func", gameStateInitFunc, "../graph.c", __LINE__);
    return NULL;
}

void Graph_Init(GraphicsContext* gfxCtx) {
    bzero(gfxCtx, sizeof(GraphicsContext));
    gfxCtx->gfxPoolIdx = 0;
    gfxCtx->fbIdx = 0;
    gfxCtx->viMode = NULL;
    gfxCtx->viFeatures = gViConfigFeatures;
    gfxCtx->xScale = gViConfigXScale;
    gfxCtx->yScale = gViConfigYScale;
    osCreateMesgQueue(&gfxCtx->queue, gfxCtx->msgBuff, ARRAY_COUNT(gfxCtx->msgBuff));
    func_800D31F0();
    Fault_AddClient(&sGraphFaultClient, Graph_FaultClient, NULL, NULL);
}

void Graph_Destroy(GraphicsContext* gfxCtx) {
    func_800D3210();
    Fault_RemoveClient(&sGraphFaultClient);
}

void Graph_TaskSet00(GraphicsContext* gfxCtx) {
    static Gfx* sPrevTaskWorkBuffer = NULL;
    static s32 sGraphCfbInfoIdx = 0;

    OSTime timeNow;
    OSTimer timer;
    OSMesg msg;
    OSTask_t* task = &gfxCtx->task.list.t;
    OSScTask* scTask = &gfxCtx->task;
    CfbInfo* cfb;

    gGfxTaskSentToNextReadyMinusAudioThreadUpdateTime =
        osGetTime() - sGraphPrevTaskTimeStart - gAudioThreadUpdateTimeAcc;

    osSetTimer(&timer, OS_USEC_TO_CYCLES(3000000), 0, &gfxCtx->queue, (OSMesg)666);

    osRecvMesg(&gfxCtx->queue, &msg, OS_MESG_BLOCK);
    osStopTimer(&timer);

    if (msg == (OSMesg)666) {
        osSyncPrintf(VT_FGCOL(RED));
        osSyncPrintf("RCP did not return"); // "RCP did not return."
        osSyncPrintf(VT_RST);

        LogUtils_LogHexDump((void*)PHYS_TO_K1(SP_BASE_REG), 0x20);
        LogUtils_LogHexDump((void*)PHYS_TO_K1(DPC_BASE_REG), 0x20);
        LogUtils_LogHexDump(gGfxSPTaskYieldBuffer, sizeof(gGfxSPTaskYieldBuffer));

        SREG(6) = -1;
        if (sPrevTaskWorkBuffer != NULL) {
            R_HREG_MODE = HREG_MODE_UCODE_DISAS;
            R_UCODE_DISAS_TOGGLE = 1;
            R_UCODE_DISAS_LOG_LEVEL = 2;
            sPrevTaskWorkBuffer = sPrevTaskWorkBuffer;
            Graph_DisassembleUCode(sPrevTaskWorkBuffer);
        }

        Fault_AddHungupAndCrashImpl("RCP is HUNG UP!!", "Oh! MY GOD!!");
    }

    osRecvMesg(&gfxCtx->queue, &msg, OS_MESG_NOBLOCK);

    sPrevTaskWorkBuffer = gfxCtx->workBuffer;
    if (gfxCtx->callback != NULL) {
        gfxCtx->callback(gfxCtx, gfxCtx->callbackParam);
    }

    timeNow = osGetTime();
    if (gAudioThreadUpdateTimeStart != 0) {
        // The audio thread update is running
        // Add the time already spent to the accumulator and leave the rest for the next cycle

        gAudioThreadUpdateTimeAcc += timeNow - gAudioThreadUpdateTimeStart;
        gAudioThreadUpdateTimeStart = timeNow;
    }
    gAudioThreadUpdateTimeTotalPerGfxTask = gAudioThreadUpdateTimeAcc;
    gAudioThreadUpdateTimeAcc = 0;

    sGraphPrevTaskTimeStart = osGetTime();

    task->type = M_GFXTASK;
    task->flags = OS_SC_DRAM_DLIST;
    task->ucode_boot = SysUcode_GetUCodeBoot();
    task->ucode_boot_size = SysUcode_GetUCodeBootSize();
    task->ucode = SysUcode_GetUCode();
    task->ucode_data = SysUcode_GetUCodeData();
    task->ucode_size = SP_UCODE_SIZE;
    task->ucode_data_size = SP_UCODE_DATA_SIZE;
    task->dram_stack = gGfxSPTaskStack;
    task->dram_stack_size = sizeof(gGfxSPTaskStack);
    task->output_buff = gGfxSPTaskOutputBuffer;
    task->output_buff_size = gGfxSPTaskOutputBuffer + ARRAY_COUNT(gGfxSPTaskOutputBuffer);
    task->data_ptr = (u64*)gfxCtx->workBuffer;

    OPEN_DISPS(gfxCtx, "../graph.c", __LINE__);
    task->data_size = (uintptr_t)WORK_DISP - (uintptr_t)gfxCtx->workBuffer;
    CLOSE_DISPS(gfxCtx, "../graph.c", __LINE__);

    { s32 pad2; } // Necessary to match stack usage

    task->yield_data_ptr = gGfxSPTaskYieldBuffer;
    task->yield_data_size = sizeof(gGfxSPTaskYieldBuffer);

    scTask->next = NULL;
    scTask->flags = OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP | OS_SC_SWAPBUFFER | OS_SC_LAST_TASK;
    if (R_GRAPH_TASKSET00_FLAGS & 1) {
        R_GRAPH_TASKSET00_FLAGS &= ~1;
        scTask->flags &= ~OS_SC_SWAPBUFFER;
        gfxCtx->fbIdx--;
    }

    scTask->msgQueue = &gfxCtx->queue;
    scTask->msg = NULL;

    cfb = &sGraphCfbInfos[sGraphCfbInfoIdx++];
    cfb->framebuffer = gfxCtx->curFrameBuffer;
    cfb->swapBuffer = gfxCtx->curFrameBuffer;
    cfb->viMode = gfxCtx->viMode;
    cfb->viFeatures = gfxCtx->viFeatures;
    cfb->xScale = gfxCtx->xScale;
    cfb->yScale = gfxCtx->yScale;
    cfb->unk_10 = 0;
    cfb->updateRate = R_UPDATE_RATE;

    scTask->framebuffer = cfb;
    sGraphCfbInfoIdx %= ARRAY_COUNT(sGraphCfbInfos);

    if (1) {}

    gfxCtx->schedMsgQueue = &gScheduler.cmdQueue;

    osSendMesg(&gScheduler.cmdQueue, (OSMesg)scTask, OS_MESG_BLOCK);
    Sched_Notify(&gScheduler);
}

void Graph_Update(GraphicsContext* gfxCtx, GameState* gameState) {
    u32 problem;

    gameState->inPreNMIState = false;
    Graph_InitTHGA(gfxCtx);

    OPEN_DISPS(gfxCtx, "../graph.c", __LINE__);

    gDPNoOpString(WORK_DISP++, "WORK_DISP START", 0);
    gDPNoOpString(POLY_OPA_DISP++, "POLY_OPA_DISP START", 0);
    gDPNoOpString(POLY_XLU_DISP++, "POLY_XLU_DISP START", 0);
    gDPNoOpString(OVERLAY_DISP++, "OVERLAY_DISP START", 0);

    CLOSE_DISPS(gfxCtx, "../graph.c", __LINE__);

    GameState_ReqPadData(gameState);
    GameState_Update(gameState);

    OPEN_DISPS(gfxCtx, "../graph.c", __LINE__);

    gDPNoOpString(WORK_DISP++, "WORK_DISP END", 0);
    gDPNoOpString(POLY_OPA_DISP++, "POLY_OPA_DISP END", 0);
    gDPNoOpString(POLY_XLU_DISP++, "POLY_XLU_DISP END", 0);
    gDPNoOpString(OVERLAY_DISP++, "OVERLAY_DISP END", 0);

    CLOSE_DISPS(gfxCtx, "../graph.c", __LINE__);

    OPEN_DISPS(gfxCtx, "../graph.c", __LINE__);

    gSPBranchList(WORK_DISP++, gfxCtx->polyOpaBuffer);
    gSPBranchList(POLY_OPA_DISP++, gfxCtx->polyXluBuffer);
    gSPBranchList(POLY_XLU_DISP++, gfxCtx->overlayBuffer);
    gDPPipeSync(OVERLAY_DISP++);
    gDPFullSync(OVERLAY_DISP++);
    gSPEndDisplayList(OVERLAY_DISP++);

    CLOSE_DISPS(gfxCtx, "../graph.c", __LINE__);

    if (R_HREG_MODE == HREG_MODE_PLAY && R_PLAY_ENABLE_UCODE_DISAS == 2) {
        R_HREG_MODE = HREG_MODE_UCODE_DISAS;
        R_UCODE_DISAS_TOGGLE = -1;
        R_UCODE_DISAS_LOG_LEVEL = R_PLAY_UCODE_DISAS_LOG_LEVEL;
    }

    if (R_HREG_MODE == HREG_MODE_UCODE_DISAS && R_UCODE_DISAS_TOGGLE != 0) {
        if (R_UCODE_DISAS_LOG_MODE == 3) {
            Fault_AddClient(&sGraphUcodeFaultClient, Graph_UCodeFaultClient, gfxCtx->workBuffer, "do_count_fault");
        }

        Graph_DisassembleUCode(gfxCtx->workBuffer);

        if (R_UCODE_DISAS_LOG_MODE == 3) {
            Fault_RemoveClient(&sGraphUcodeFaultClient);
        }

        if (R_UCODE_DISAS_TOGGLE < 0) {
            LogUtils_LogHexDump((void*)PHYS_TO_K1(SP_BASE_REG), 0x20);
            LogUtils_LogHexDump((void*)PHYS_TO_K1(DPC_BASE_REG), 0x20);
        }

        if (R_UCODE_DISAS_TOGGLE < 0) {
            R_UCODE_DISAS_TOGGLE = 0;
        }
    }

    problem = false;

    {
        GfxPool* pool = &gGfxPools[gfxCtx->gfxPoolIdx & 1];

        if (pool->headMagic != GFXPOOL_HEAD_MAGIC) {
            //! @bug (?) : "problem = true;" may be missing
            osSyncPrintf("%c", BEL);
            // "Dynamic area head is destroyed"
            osSyncPrintf(VT_COL(RED, WHITE) "Dynamic region head is destroyed\n" VT_RST);
            Fault_AddHungupAndCrash("../graph.c", __LINE__);
        }
        if (pool->tailMagic != GFXPOOL_TAIL_MAGIC) {
            problem = true;
            osSyncPrintf("%c", BEL);
            // "Dynamic region tail is destroyed"
            osSyncPrintf(VT_COL(RED, WHITE) "Dynamic region tail is destroyed\n" VT_RST);
            Fault_AddHungupAndCrash("../graph.c", __LINE__);
        }
    }

    if (THGA_IsCrash(&gfxCtx->polyOpa)) {
        problem = true;
        osSyncPrintf("%c", BEL);
        // "Zelda 0 is dead"
        osSyncPrintf(VT_COL(RED, WHITE) "Zelda 0 is dead(graph_alloc is empty)\n" VT_RST);
    }
    if (THGA_IsCrash(&gfxCtx->polyXlu)) {
        problem = true;
        osSyncPrintf("%c", BEL);
        // "Zelda 1 is dead"
        osSyncPrintf(VT_COL(RED, WHITE) "Zelda 1 is dead(graph_alloc is empty)\n" VT_RST);
    }
    if (THGA_IsCrash(&gfxCtx->overlay)) {
        problem = true;
        osSyncPrintf("%c", BEL);
        // "Zelda 4 is dead"
        osSyncPrintf(VT_COL(RED, WHITE) "Zelda 4 is dead(graph_alloc is empty)\n" VT_RST);
    }

    if (!problem) {
        Graph_TaskSet00(gfxCtx);
        gfxCtx->gfxPoolIdx++;
        gfxCtx->fbIdx++;
    }

    func_800F3054();

    {
        OSTime timeNow = osGetTime();
        s32 pad[4];

        gRSPGfxTimeTotal = gRSPGfxTimeAcc;
        gRSPAudioTimeTotal = gRSPAudioTimeAcc;
        gRDPTimeTotal = gRDPTimeAcc;
        gRSPGfxTimeAcc = 0;
        gRSPAudioTimeAcc = 0;
        gRDPTimeAcc = 0;

        if (sGraphPrevUpdateEndTime != 0) {
            gGraphUpdatePeriod = timeNow - sGraphPrevUpdateEndTime;
        }
        sGraphPrevUpdateEndTime = timeNow;
    }

    if (gIsCtrlr2Valid && CHECK_BTN_ALL(gameState->input[0].press.button, BTN_Z) &&
        CHECK_BTN_ALL(gameState->input[0].cur.button, BTN_L | BTN_R)) {
        gSaveContext.gameMode = GAMEMODE_NORMAL;
        SET_NEXT_GAMESTATE(gameState, MapSelect_Init, MapSelectState);
        gameState->running = false;
    }

    if (gIsCtrlr2Valid && PreNmiBuff_IsResetting(gAppNmiBufferPtr) && !gameState->inPreNMIState) {
        // "To reset mode"
        osSyncPrintf(VT_COL(YELLOW, BLACK) "Shift to reset mode by PRE-NMI\n" VT_RST);
        SET_NEXT_GAMESTATE(gameState, PreNMI_Init, PreNMIState);
        gameState->running = false;
    }
}

void Graph_ThreadEntry(void* arg0) {
    GraphicsContext gfxCtx;
    GameState* gameState;
    u32 size;
    GameStateOverlay* nextOvl = &gGameStateOverlayTable[GAMESTATE_SETUP];
    GameStateOverlay* ovl;
    char faultMsg[0x50];

    osSyncPrintf("Start GRAPH thread execution\n"); // "Start graphic thread execution"
    Graph_Init(&gfxCtx);

    while (nextOvl != NULL) {
        ovl = nextOvl;
        Overlay_LoadGameState(ovl);

        size = ovl->instanceSize;
        osSyncPrintf("ovl->instanceSize = %d bytes\n", size); // "Class size = %d bytes"

        gameState = SystemArena_MallocDebug(size, "../graph.c", __LINE__);

        if (gameState == NULL) {
            osSyncPrintf("Failure to secure\n"); // "Failure to secure"

            sprintf(faultMsg, "ovl->instanceSize = %d bytes", size);
            Fault_AddHungupAndCrashImpl("GAME CLASS MALLOC FAILED", faultMsg);
        }

        GameState_Init(gameState, ovl->init, &gfxCtx);

        while (GameState_IsRunning(gameState)) {
            Graph_Update(&gfxCtx, gameState);
        }

        nextOvl = Graph_GetNextGameState(gameState);
        GameState_Destroy(gameState);
        SystemArena_FreeDebug(gameState, "../graph.c", __LINE__);
        Overlay_FreeGameState(ovl);
    }
    Graph_Destroy(&gfxCtx);
    osSyncPrintf("End GRAPH thread execution\n"); // "End of graphic thread execution"
}

void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size) {
    TwoHeadGfxArena* thga = &gfxCtx->polyOpa;

    if (HREG(59) == 1) {
        osSyncPrintf("Graph_Alloc size=%d thga->size=%08X thga->start=%08X thga->p=%08X thga->d=%08X\n", size, thga->size, thga->start,
                     thga->p, thga->d);
    }
    return THGA_AllocTail(&gfxCtx->polyOpa, ALIGN16(size));
}

void* Graph_Alloc2(GraphicsContext* gfxCtx, size_t size) {
    TwoHeadGfxArena* thga = &gfxCtx->polyOpa;

    if (HREG(59) == 1) {
        osSyncPrintf("Graph_Alloc2 size=%d thga->size=%08X thga->start=%08X thga->p=%08X thga->d=%08X\n", size, thga->size, thga->start,
                     thga->p, thga->d);
    }
    return THGA_AllocTail(&gfxCtx->polyOpa, ALIGN16(size));
}

void Graph_OpenDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line) {
    if (R_HREG_MODE == HREG_MODE_UCODE_DISAS && R_UCODE_DISAS_LOG_MODE != 4) {
        dispRefs[0] = gfxCtx->polyOpa.p;
        dispRefs[1] = gfxCtx->polyXlu.p;
        dispRefs[2] = gfxCtx->overlay.p;

        gDPNoOpOpenDisp(gfxCtx->polyOpa.p++, file, line);
        gDPNoOpOpenDisp(gfxCtx->polyXlu.p++, file, line);
        gDPNoOpOpenDisp(gfxCtx->overlay.p++, file, line);
    }
}

void Graph_CloseDisps(Gfx** dispRefs, GraphicsContext* gfxCtx, const char* file, s32 line) {
    if (R_HREG_MODE == HREG_MODE_UCODE_DISAS && R_UCODE_DISAS_LOG_MODE != 4) {
        if (dispRefs[0] + 1 == gfxCtx->polyOpa.p) {
            gfxCtx->polyOpa.p = dispRefs[0];
        } else {
            gDPNoOpCloseDisp(gfxCtx->polyOpa.p++, file, line);
        }

        if (dispRefs[1] + 1 == gfxCtx->polyXlu.p) {
            gfxCtx->polyXlu.p = dispRefs[1];
        } else {
            gDPNoOpCloseDisp(gfxCtx->polyXlu.p++, file, line);
        }

        if (dispRefs[2] + 1 == gfxCtx->overlay.p) {
            gfxCtx->overlay.p = dispRefs[2];
        } else {
            gDPNoOpCloseDisp(gfxCtx->overlay.p++, file, line);
        }
    }
}

Gfx* Graph_GfxPlusOne(Gfx* gfx) {
    return gfx + 1;
}

Gfx* Graph_BranchDlist(Gfx* gfx, Gfx* dst) {
    gSPBranchList(gfx, dst);
    return dst;
}

void* Graph_DlistAlloc(Gfx** gfx, u32 size) {
    u8* ptr;
    Gfx* dst;

    size = ALIGN8(size);

    ptr = (u8*)(*gfx + 1);

    dst = (Gfx*)(ptr + size);
    gSPBranchList(*gfx, dst);

    *gfx = dst;
    return ptr;
}
