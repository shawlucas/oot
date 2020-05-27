#include <ultra64.h>
#include <global.h>

s32 osContSetCh(u8 ch) {
    s32 ret = 0;

    __osSiGetAccess();

    if (ch > MAXCONTROLLERS) {
        __osMaxControllers = MAXCONTROLLERS;
    } else {
        __osMaxControllers = ch;
    }
    __osContLastPollType = CONT_CMD_END;
    __osSiRelAccess();
    return ret;
}
