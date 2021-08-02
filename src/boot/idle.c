#include "global.h"
#include "vt.h"

#define NUM_PI_MSGS 50

OSThread gMainThread;
u8 sMainStack[0x900];
StackEntry sMainStackInfo;
OSMesg sPiMgrCmdBuff[NUM_PI_MSGS];
OSMesgQueue gPiMgrCmdQ;
OSViMode gViConfigMode;
u8 gViModeNum;

s8 gViDirty = 1;
vu8 gViConfigUseDefault = 1;
u8 gViConfigAdditionalScanLines = 0;
u32 gViConfigFeatures = OS_VI_DITHER_FILTER_ON | OS_VI_GAMMA_OFF;
f32 gViConfigXScale = 1.0;
f32 gViConfigYScale = 1.0;

static void Main_ThreadEntry(void* arg) {
    OSTime time;

    osSyncPrintf("mainx 実行開始\n");
    DmaMgr_Init();
    osSyncPrintf("codeセグメントロード中...");
    time = osGetTime();
    DmaMgr_SendRequest1(_codeSegmentStart, (u32)_codeSegmentRomStart, _codeSegmentRomEnd - _codeSegmentRomStart,
                        "../idle.c", 238);
    time -= osGetTime();
    osSyncPrintf("\rcodeセグメントロード中...完了\n");
    osSyncPrintf("転送時間 %6.3f\n");
    bzero(_codeSegmentBssStart, _codeSegmentBssEnd - _codeSegmentBssStart);
    osSyncPrintf("codeセグメントBSSクリア完了\n");
    Main(arg);
    osSyncPrintf("mainx 実行終了\n");
}

extern void Idle_ThreadEntry(void* arg) {
    osSyncPrintf("アイドルスレッド(idleproc)実行開始\n");
    osSyncPrintf("作製者    : %s\n", gBuildTeam);
    osSyncPrintf("作成日時  : %s\n", gBuildDate);
    osSyncPrintf("MAKEOPTION: %s\n", gBuildMakeOption);
    osSyncPrintf(VT_FGCOL(GREEN));
    osSyncPrintf("ＲＡＭサイズは %d キロバイトです(osMemSize/osGetMemSize)\n", (s32)osMemSize / 1024);
    osSyncPrintf("_bootSegmentEnd(%08x) 以降のＲＡＭ領域はクリアされました(boot)\n", _bootSegmentEnd);
    osSyncPrintf("Ｚバッファのサイズは %d キロバイトです\n", sizeof(gZBuffer) / 1024);
    osSyncPrintf("ダイナミックバッファのサイズは %d キロバイトです\n", sizeof(gGfxPools) / 1024);
    osSyncPrintf("ＦＩＦＯバッファのサイズは %d キロバイトです\n", sizeof(gGfxSPTaskOutputBuffer) / 1024);
    osSyncPrintf("ＹＩＥＬＤバッファのサイズは %d キロバイトです\n", sizeof(gGfxSPTaskYieldBuffer) / 1024);
    osSyncPrintf("オーディオヒープのサイズは %d キロバイトです\n", (_AudioheapSegmentEnd - _AudioheapSegmentStart) / 1024);
    osSyncPrintf(VT_RST);

    /*
      * Video initialization
      * -Start VI Manager
      * ・ Screen mode: NTSC, anti-alias, low resolution, high color
      * ・ Special features: Gamma off, dither filter off
      * ・ Make the screen black
      */
    osCreateViManager(OS_PRIORITY_VIMGR);

    gViConfigFeatures = OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON;
    gViConfigXScale = 1.0f;
    gViConfigYScale = 1.0f;

    switch (osTvType) {
        case OS_TV_NTSC:
            gViModeNum = OS_VI_NTSC_LAN1;
            gViConfigMode = osViModeNtscLan1;
            break;

        case OS_TV_MPAL:
            gViModeNum = OS_VI_MPAL_LAN1;
            gViConfigMode = osViModeMpalLan1;
            break;

        case OS_TV_PAL:
            gViModeNum = OS_VI_FPAL_LAN1;
            gViConfigMode = osViModeFpalLan1;
            gViConfigYScale = 0.833f;
            break;
    }

    gViDirty = true;
    osViSetMode(&gViConfigMode);
    ViConfig_UpdateVi(1);
    osViBlack(true);
    osViSwapBuffer(0x803DA80); //! @bug Invalid vram address (probably intended to be 0x803DA800)
    osCreatePiManager(OS_PRIORITY_PIMGR, &gPiMgrCmdQ, sPiMgrCmdBuff, NUM_PI_MSGS);
    StackCheck_Init(&sMainStackInfo, sMainStack, sMainStack + sizeof(sMainStack), 0, 0x400, "main");
    osCreateThread(&gMainThread, 3, Main_ThreadEntry, arg, sMainStack + sizeof(sMainStack), Z_PRIORITY_MAIN);
    osStartThread(&gMainThread);
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (1) {
        ;
    }
}
