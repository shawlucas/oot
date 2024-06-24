#include "global.h"
#include "terminal.h"

// For retail BSS ordering, the block number of sMainThread must be 0 or
// just above (the exact upper bound depends on the block numbers assigned to
// extern variables declared in headers).
#pragma increment_block_number 60

OSThread sMainThread;
STACK(sMainStack, 0x900);
StackEntry sMainStackInfo;
OSMesg sPiMgrCmdBuff[50];
OSMesgQueue gPiMgrCmdQueue;
OSViMode gViConfigMode;
u8 gViConfigModeType;

s8 D_80009430 = 1;
vu8 gViConfigBlack = true;
u8 gViConfigAdditionalScanLines = 0;
u32 gViConfigFeatures = OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF;
f32 gViConfigXScale = 1.0;
f32 gViConfigYScale = 1.0;

void Main_ThreadEntry(void* arg) {
    OSTime time;

    PRINTF("Main_ThreadEntry execution start\n");
    DmaMgr_Init();
    PRINTF("code segment loading...");
    time = osGetTime();
    DMA_REQUEST_SYNC(_codeSegmentStart, (uintptr_t)_codeSegmentRomStart, _codeSegmentRomEnd - _codeSegmentRomStart,
                     "../idle.c", 238);
    time -= osGetTime();
    PRINTF("\rcode segment loading...complete\n");
    PRINTF("transfer time %6.3f\n");
    bzero(_codeSegmentBssStart, _codeSegmentBssEnd - _codeSegmentBssStart);
    PRINTF("code segment BSS clear complete \n");
    Main(arg);
    PRINTF("mainx 実行終了\n");
}

void Idle_ThreadEntry(void* arg) {
    PRINTF("idle thread (idleproc) execution start\n");
    PRINTF("creator    : %s\n", gBuildTeam);
    PRINTF("creation date  : %s\n", gBuildDate);
    PRINTF("MAKEOPTION: %s\n", gBuildMakeOption);
    PRINTF(VT_FGCOL(GREEN));
    PRINTF("ＲＡＭ size is %d kilobytes (osMemSize/osGetMemSize)\n", (s32)osMemSize / 1024);
    PRINTF("_bootSegmentEnd(%08x) and above RAM area was cleared (boot)\n", _bootSegmentEnd);
    PRINTF("Z buffer size is %d kilobytes\n", 0x96);
    PRINTF("dynamic buffer size is %d kilobytes\n", 0x92);
    PRINTF("ＦＩＦＯ buffer size is %d kilobytes\n", 0x60);
    PRINTF("ＹＩＥＬＤ buffer size is %d kilobytes\n", 3);
    PRINTF("audio heap size is %d kilobytes\n",
           ((intptr_t)&gAudioHeap[ARRAY_COUNT(gAudioHeap)] - (intptr_t)gAudioHeap) / 1024);
    PRINTF(VT_RST);

    osCreateViManager(OS_PRIORITY_VIMGR);

    gViConfigFeatures = OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON;
    gViConfigXScale = 1.0f;
    gViConfigYScale = 1.0f;

    switch (osTvType) {
#if !OOT_DEBUG
        case OS_TV_PAL:
#endif
        case OS_TV_NTSC:
            gViConfigModeType = OS_VI_NTSC_LAN1;
            gViConfigMode = osViModeNtscLan1;
            break;

        case OS_TV_MPAL:
            gViConfigModeType = OS_VI_MPAL_LAN1;
            gViConfigMode = osViModeMpalLan1;
            break;

#if OOT_DEBUG
        case OS_TV_PAL:
            gViConfigModeType = OS_VI_FPAL_LAN1;
            gViConfigMode = osViModeFpalLan1;
            gViConfigYScale = 0.833f;
            break;
#endif
    }

    D_80009430 = 1;
    osViSetMode(&gViConfigMode);
    ViConfig_UpdateVi(true);
    osViBlack(true);
    osViSwapBuffer((void*)0x803DA80); //! @bug Invalid vram address (probably intended to be 0x803DA800)
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPiMgrCmdQueue, sPiMgrCmdBuff, ARRAY_COUNT(sPiMgrCmdBuff));
    StackCheck_Init(&sMainStackInfo, sMainStack, STACK_TOP(sMainStack), 0, 0x400, "main");
    osCreateThread(&sMainThread, THREAD_ID_MAIN, Main_ThreadEntry, arg, STACK_TOP(sMainStack), THREAD_PRI_MAIN_INIT);
    osStartThread(&sMainThread);
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    for (;;) {}
}
