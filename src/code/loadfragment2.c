#include "global.h"

void* Overlay_AllocateAndLoad(u32 vRomStart, u32 vRomEnd, void* vRamStart, void* vRamEnd) {
    void* allocatedVRamAddr = SystemArena_MallocRDebug((s32)vRamEnd - (s32)vRamStart, "../loadfragment2.c", __LINE__);

    if (gOverlayLogSeverity >= 3) {
        osSyncPrintf("OVL:SPEC(%08X-%08X) REAL(%08X-%08X) OFFSET(%08X)\n", vRamStart, vRamEnd, allocatedVRamAddr,
                     ((u32)vRamEnd - (u32)vRamStart) + (u32)allocatedVRamAddr, (u32)vRamStart - (u32)allocatedVRamAddr);
    }

    if (allocatedVRamAddr != NULL) {
        Overlay_Load(vRomStart, vRomEnd, vRamStart, vRamEnd, allocatedVRamAddr);
    }

    return allocatedVRamAddr;
}
