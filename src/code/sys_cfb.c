#include "global.h"

u32 sSysCfbFbPtr[2];
u32 sSysCfbEnd;

void SysCfb_Init(s32 n64dd) {
    u32 screenSize;
    u32 tmpFbEnd;

    if (osMemSize >= 0x800000) {
        // "8MB or more memory is installed"
        osSyncPrintf("At least 8 MB of memory is installed\n");
        tmpFbEnd = 0x8044BE80;
        if (n64dd == 1) {
            osSyncPrintf("RAM 8M mode (N64DD compatible)\n"); // "RAM 8M mode (N64DD compatible)"
            sSysCfbEnd = 0x805FB000;
        } else {
            // "The margin for this version is %dK bytes"
            osSyncPrintf("The margin for this version is %dK bytes\n", (0x4BC00 / 1024));
            sSysCfbEnd = tmpFbEnd;
        }
    } else if (osMemSize >= 0x400000) {
        osSyncPrintf("RAM 4M mode\n");
        sSysCfbEnd = 0x80400000;
    } else {
        LogUtils_HungupThread("../sys_cfb.c", __LINE__);
    }

    screenSize = SCREEN_WIDTH * SCREEN_HEIGHT;
    sSysCfbEnd &= ~0x3F;
    // "The final address used by the system is %08X"
    osSyncPrintf("The final address used by the system is 0x%08X\n", sSysCfbEnd);
    sSysCfbFbPtr[0] = sSysCfbEnd - (screenSize * 4);
    sSysCfbFbPtr[1] = sSysCfbEnd - (screenSize * 2);
    // "Frame buffer addresses are %08X and %08X"
    osSyncPrintf("Frame buffer addresses are 0x%08X and 0x%08X\n", sSysCfbFbPtr[0], sSysCfbFbPtr[1]);
}

void SysCfb_Reset() {
    sSysCfbFbPtr[0] = 0;
    sSysCfbFbPtr[1] = 0;
    sSysCfbEnd = 0;
}

u32 SysCfb_GetFbPtr(s32 idx) {
    if (idx < 2) {
        return sSysCfbFbPtr[idx];
    }
    return 0;
}

u32 SysCfb_GetFbEnd() {
    return sSysCfbEnd;
}
