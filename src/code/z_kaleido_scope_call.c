#include "global.h"
#include "vt.h"

void (*sKaleidoScopeUpdateFunc)(GlobalContext* globalCtx);
void (*sKaleidoScopeDrawFunc)(GlobalContext* globalCtx);
f32 gBossMarkScale;
u32 D_8016139C;
PauseMapMarksData* gLoadedPauseMarkDataTable;

extern void KaleidoScope_Update(GlobalContext* globalCtx);
extern void KaleidoScope_Draw(GlobalContext* globalCtx);

void KaleidoScopeCall_LoadPlayer() {
    KaleidoMgrOverlay* playerActorOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_PLAYER_ACTOR];

    if (gKaleidoMgrCurOvl != playerActorOvl) {
        if (gKaleidoMgrCurOvl != NULL) {
            osSyncPrintf(VT_FGCOL(GREEN));
            osSyncPrintf("Kaleido area forced removal\n");
            osSyncPrintf(VT_RST);

            KaleidoManager_ClearOvl(gKaleidoMgrCurOvl);
        }

        osSyncPrintf(VT_FGCOL(GREEN));
        osSyncPrintf("Player actor import\n");
        osSyncPrintf(VT_RST);

        KaleidoManager_LoadOvl(playerActorOvl);
    }
}

void KaleidoScopeCall_Init(GlobalContext* globalCtx) {
    osSyncPrintf("Kaleidoscope replacement construction \n");

    sKaleidoScopeUpdateFunc = KaleidoManager_GetRamAddr(KaleidoScope_Update);
    sKaleidoScopeDrawFunc = KaleidoManager_GetRamAddr(KaleidoScope_Draw);

    LOG_ADDRESS("KaleidoScope_Update", KaleidoScope_Update, "../z_kaleido_scope_call.c", __LINE__);
    LOG_ADDRESS("sKaleidoScopeUpdateFunc", sKaleidoScopeUpdateFunc, "../z_kaleido_scope_call.c", __LINE__);
    LOG_ADDRESS("KaleidoScope_Draw", KaleidoScope_Draw, "../z_kaleido_scope_call.c", __LINE__);
    LOG_ADDRESS("sKaleidoScopeDrawFunc", sKaleidoScopeDrawFunc, "../z_kaleido_scope_call.c", __LINE__);

    KaleidoSetup_Init(globalCtx);
}

void KaleidoScopeCall_Destroy(GlobalContext* globalCtx) {
    osSyncPrintf("Kaleidoscope replacement destruction\n");

    KaleidoSetup_Destroy(globalCtx);
}

void KaleidoScopeCall_Update(GlobalContext* globalCtx) {
    KaleidoMgrOverlay* kaleidoScopeOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_KALEIDO_SCOPE];
    PauseContext* pauseCtx = &globalCtx->pauseCtx;

    if ((pauseCtx->state != 0) || (pauseCtx->debugState != 0)) {
        if (pauseCtx->state == 1) {
            if (ShrinkWindow_GetCurrentVal() == 0) {
                HREG(80) = 7;
                HREG(82) = 3;
                R_PAUSE_MENU_MODE = 1;
                pauseCtx->unk_1E4 = 0;
                pauseCtx->unk_1EC = 0;
                pauseCtx->state = (pauseCtx->state & 0xFFFF) + 1;
            }
        } else if (pauseCtx->state == 8) {
            HREG(80) = 7;
            HREG(82) = 3;
            R_PAUSE_MENU_MODE = 1;
            pauseCtx->unk_1E4 = 0;
            pauseCtx->unk_1EC = 0;
            pauseCtx->state = (pauseCtx->state & 0xFFFF) + 1;
        } else if ((pauseCtx->state == 2) || (pauseCtx->state == 9)) {
            osSyncPrintf("R_PAUSE_MENU_MODE = %d\n", R_PAUSE_MENU_MODE);

            if (R_PAUSE_MENU_MODE >= 3) {
                pauseCtx->state++;
            }
        } else if (pauseCtx->state != 0) {
            if (gKaleidoMgrCurOvl != kaleidoScopeOvl) {
                if (gKaleidoMgrCurOvl != NULL) {
                    osSyncPrintf(VT_FGCOL(GREEN));
                    osSyncPrintf("Kaleido area Player Forced Elimination\n");
                    osSyncPrintf(VT_RST);

                    KaleidoManager_ClearOvl(gKaleidoMgrCurOvl);
                }

                osSyncPrintf(VT_FGCOL(GREEN));
                osSyncPrintf("Kaleido area Kaleidoscope loading\n");
                osSyncPrintf(VT_RST);

                KaleidoManager_LoadOvl(kaleidoScopeOvl);
            }

            if (gKaleidoMgrCurOvl == kaleidoScopeOvl) {
                sKaleidoScopeUpdateFunc(globalCtx);

                if ((globalCtx->pauseCtx.state == 0) && (globalCtx->pauseCtx.debugState == 0)) {
                    osSyncPrintf(VT_FGCOL(GREEN));
                    osSyncPrintf("Kaleido area Kaleidoscope Emission\n");
                    osSyncPrintf(VT_RST);

                    KaleidoManager_ClearOvl(kaleidoScopeOvl);
                    KaleidoScopeCall_LoadPlayer();
                }
            }
        }
    }
}

void KaleidoScopeCall_Draw(GlobalContext* globalCtx) {
    KaleidoMgrOverlay* kaleidoScopeOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_KALEIDO_SCOPE];

    if (R_PAUSE_MENU_MODE >= 3) {
        if (((globalCtx->pauseCtx.state >= 4) && (globalCtx->pauseCtx.state <= 7)) ||
            ((globalCtx->pauseCtx.state >= 11) && (globalCtx->pauseCtx.state <= 18))) {
            if (gKaleidoMgrCurOvl == kaleidoScopeOvl) {
                sKaleidoScopeDrawFunc(globalCtx);
            }
        }
    }
}
