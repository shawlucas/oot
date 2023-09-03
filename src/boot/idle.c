#include "global.h"
#include "terminal.h"

OSThread gMainThread;
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

    osSyncPrintf("Main_ThreadEntry Execution Start\n");
    DmaMgr_Init();
    osSyncPrintf("code segment loading...");
    time = osGetTime();
    DmaMgr_RequestSyncDebug(_codeSegmentStart, (uintptr_t)_codeSegmentRomStart,
                            _codeSegmentRomEnd - _codeSegmentRomStart, "../idle.c", __LINE__);
    time -= osGetTime();
    osSyncPrintf("\rcode segment loading... complete\n");
    osSyncPrintf("transfer time %6.3f\n");
    bzero(_codeSegmentBssStart, _codeSegmentBssEnd - _codeSegmentBssStart);
    osSyncPrintf("code segment BBS clear complete\n");
    Main(arg);
    osSyncPrintf("Main_ThreadEntry Execution End\n");
}

void Idle_ThreadEntry(void* arg) {
    osSyncPrintf("Idle_ThreadEntry Execution Start\n");
    osSyncPrintf("CREATOR    : %s\n", gBuildTeam);
    osSyncPrintf("CREATION DATE  : %s\n", gBuildDate);
    osSyncPrintf("MAKEOPTION: %s\n", gBuildMakeOption);
    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("ＲＡＭ size is %d kilobytes (osMemSize/osGetMemSize)\n", (s32)osMemSize / 1024);
    osSyncPrintf("_bootSegmentEnd(0x%08X) and above RAM area was cleared (boot)\n", _bootSegmentEnd);
    osSyncPrintf("Ｚ buffer size is %d kilobytes\n", 0x96);
    osSyncPrintf("Dynamic buffer size is %d kilobytes\n", 0x92);
    osSyncPrintf("ＦＩＦＯ buffer size is %d kilobytes\n", 0x60);
    osSyncPrintf("ＹＩＥＬＤ buffer size is %d kilobytes\n", 3);
    osSyncPrintf("Audio heap size is %d kilobytes\n",
                 ((intptr_t)gSystemHeap - (intptr_t)gAudioHeap) / 1024);
    osSyncPrintf(VT_RST);

    osCreateViManager(OS_PRIORITY_VIMGR);

    gViConfigFeatures = OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON;
    gViConfigXScale = 1.0f;
    gViConfigYScale = 1.0f;

    switch (osTvType) {
        case OS_TV_NTSC:
            gViConfigModeType = OS_VI_NTSC_LAN1;
            gViConfigMode = osViModeNtscLan1;
            break;

        case OS_TV_MPAL:
            gViConfigModeType = OS_VI_MPAL_LAN1;
            gViConfigMode = osViModeMpalLan1;
            break;

        case OS_TV_PAL:
            gViConfigModeType = OS_VI_FPAL_LAN1;
            gViConfigMode = osViModeFpalLan1;
            gViConfigYScale = 0.833f;
            break;
    }

    D_80009430 = 1;
    osViSetMode(&gViConfigMode);
    ViConfig_UpdateVi(true);
    osViBlack(true);
    osViSwapBuffer((void*)0x803DA80); //! @bug Invalid vram address (probably intended to be 0x803DA800)
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPiMgrCmdQueue, sPiMgrCmdBuff, ARRAY_COUNT(sPiMgrCmdBuff));
    StackCheck_Init(&sMainStackInfo, sMainStack, STACK_TOP(sMainStack), 0, 0x400, "main");
    osCreateThread(&gMainThread, THREAD_ID_MAIN, Main_ThreadEntry, arg, STACK_TOP(sMainStack), THREAD_PRI_MAIN_INIT);
    osStartThread(&gMainThread);
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (1) {
        ;
    }
}
