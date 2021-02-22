#include "global.h"

u32 __osPiAccessQueueEnabled = false;

OSMesg piAccessBuf;
OSMesgQueue __osPiAccessQueue;

void __osPiCreateAccessQueue(void) {
    __osPiAccessQueueEnabled = true;
    osCreateMesgQueue(&__osPiAccessQueue, &piAccessBuf, 1);
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

void __osPiGetAccess(void) {
    OSMesg mesg;

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }

    osRecvMesg(&__osPiAccessQueue, &mesg, OS_MESG_BLOCK);
}

void __osPiRelAccess(void) {
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
