#include <ultra64.h>
#include <global.h>

/*
    Original name: osPfsIsPlug
    Detects which Controller contains a Controller Pak
*/

s32 osMempakIsPlug(OSMesgQueue* queue, u8* bitPattern) {
    s32 ret = 0;
    OSMesg mesg;
    u8 patternArg;
    OSContStatus contData[MAXCONTROLLERS];
    s32 channel;
    u8 bits = 0;
    s32 crcErrorCount = 3;

    __osSiGetAccess();

    do {
        __osMempakRequestData(CONT_CMD_REQUEST_STATUS);

        ret = __osSiRawStartDma(OS_WRITE, &pifMempakBuf);
        osRecvMesg(queue, &mesg, OS_MESG_BLOCK);

        ret = __osSiRawStartDma(OS_READ, &pifMempakBuf);
        osRecvMesg(queue, &mesg, OS_MESG_BLOCK);

        __osMempakGetInitData(&patternArg, &contData[0]);

        for (channel = 0; channel < __osMaxControllers; channel++) {
            if ((contData[channel].status & CONT_ADDR_CRC_ER) == 0) {
                crcErrorCount--;
                break;
            }
        }
        if (channel == __osMaxControllers) {
            crcErrorCount = 0;
        }
    } while (crcErrorCount > 0);
    for (channel = 0; channel < __osMaxControllers; channel++) {
        if ((contData[channel].errno == 0) && ((contData[channel].status & CONT_CARD_ON) != 0)) {
            bits |= (1 << channel);
        }
    }

    __osSiRelAccess();
    *bitPattern = bits;
    return ret;
}

void __osMempakRequestData(u8 pollType) {
    u8* ptr = (u8*)(&pifMempakBuf);
    __OSContRequestFormat contRequest;
    s32 idx;

    __osContLastPollType = pollType;

    pifMempakBuf.status_control = CONT_CMD_EXE;

    contRequest.dummy = 0xFF;
    contRequest.txsize = 1;
    contRequest.rxsize = 3;
    contRequest.poll = pollType;
    contRequest.typeh = 0xFF;
    contRequest.typel = 0xFF;
    contRequest.status = 0xFF;
    contRequest.dummy1 = 0xFF;

    for (idx = 0; idx < __osMaxControllers; idx++) {

        *((__OSContRequestFormat*)ptr) = contRequest;
        ptr += sizeof(contRequest);
    }

    *((u8*)ptr) = CONT_CMD_END;
}

void __osMempakGetInitData(u8* bitPattern, OSContStatus* data) {
    u8* ptr;
    __OSContRequestFormat contRequest;
    s32 i;
    u8 bits = 0;

    ptr = (u8*)(&pifMempakBuf);

    for (i = 0; i < __osMaxControllers; i++, ptr += sizeof(contRequest), data++) {

        contRequest = *((__OSContRequestFormat*)ptr);
        data->errno = ((contRequest.rxsize & CONT_CMD_ERR_MASK) >> 4);

        if (data->errno) {
            continue;
        }
        data->type = ((contRequest.typel << 8) | contRequest.typeh);
        data->status = contRequest.status;
        bits |= (1 << i);
    }
    *bitPattern = bits;
}
