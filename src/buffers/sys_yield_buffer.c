#include "ultra64.h"

#define SYS_YIELD_SIZE OS_YIELD_DATA_SIZE

u64 gGfxSPTaskYieldBuffer[SYS_YIELD_SIZE / sizeof(u64)];
