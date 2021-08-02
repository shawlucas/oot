#include "ultra64.h"

#define SYS_FIFO_SIZE 0x18000

// 0x18000 bytes
u64 gGfxSPTaskOutputBuffer[SYS_FIFO_SIZE / sizeof(u64)];
