#include "global.h"
#include "terminal.h"

SpeedMeter D_801664D0;
struct_801664F0 D_801664F0;
struct_80166500 D_80166500;
VisMono sMonoColors;
ViMode sViMode;
FaultClient sGameFaultClient;
u16 sLastButtonPressed;

void GameState_FaultPrint(void) {
    static char sBtnChars[] = "ABZSuldr*+LRudlr";
    s32 i;

    osSyncPrintf("sLastButtonPressed = %04X\n", sLastButtonPressed);
    FaultDrawer_DrawText(120, 180, "%08X", sLastButtonPressed);
    for (i = 0; i < ARRAY_COUNT(sBtnChars); i++) {
        if (sLastButtonPressed & (1 << i)) {
            FaultDrawer_DrawText((i * 8) + 120, 190, "%c", sBtnChars[i]);
        }
    }
}

void GameState_SetFBFilter(Gfx** gfx) {
    Gfx* gfxP = *gfx;

    if ((R_FB_FILTER_TYPE > 0) && (R_FB_FILTER_TYPE < 5)) {
        D_801664F0.type = R_FB_FILTER_TYPE;
        D_801664F0.color.r = R_FB_FILTER_PRIM_COLOR(0);
        D_801664F0.color.g = R_FB_FILTER_PRIM_COLOR(1);
        D_801664F0.color.b = R_FB_FILTER_PRIM_COLOR(2);
        D_801664F0.color.a = R_FB_FILTER_A;
        func_800ACE98(&D_801664F0, &gfxP);
    } else if ((R_FB_FILTER_TYPE == 5) || (R_FB_FILTER_TYPE == 6)) {
        D_80166500.useRgba = (R_FB_FILTER_TYPE == 6);
        D_80166500.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
        D_80166500.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
        D_80166500.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
        D_80166500.primColor.a = R_FB_FILTER_A;
        D_80166500.envColor.r = R_FB_FILTER_ENV_COLOR(0);
        D_80166500.envColor.g = R_FB_FILTER_ENV_COLOR(1);
        D_80166500.envColor.b = R_FB_FILTER_ENV_COLOR(2);
        D_80166500.envColor.a = R_FB_FILTER_A;
        func_800AD958(&D_80166500, &gfxP);
    } else if (R_FB_FILTER_TYPE == 7) {
        sMonoColors.unk_00 = 0;
        sMonoColors.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
        sMonoColors.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
        sMonoColors.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
        sMonoColors.primColor.a = R_FB_FILTER_A;
        sMonoColors.envColor.r = R_FB_FILTER_ENV_COLOR(0);
        sMonoColors.envColor.g = R_FB_FILTER_ENV_COLOR(1);
        sMonoColors.envColor.b = R_FB_FILTER_ENV_COLOR(2);
        sMonoColors.envColor.a = R_FB_FILTER_A;
        VisMono_Draw(&sMonoColors, &gfxP);
    }
    *gfx = gfxP;
}

void func_800C4344(GameState* gameState) {
    Input* selectedInput;
    s32 hexDumpSize;
    u16 inputCompareValue;

    if (R_HREG_MODE == HREG_MODE_HEAP_FREE_BLOCK_TEST) {
        __osMalloc_FreeBlockTest_Enable = R_HEAP_FREE_BLOCK_TEST_TOGGLE;
    }

    if (R_HREG_MODE == HREG_MODE_INPUT_TEST) {
        selectedInput =
            &gameState->input[(u32)R_INPUT_TEST_CONTROLLER_PORT < MAXCONTROLLERS ? R_INPUT_TEST_CONTROLLER_PORT : 0];

        inputCompareValue = R_INPUT_TEST_COMPARE_VALUE;
        R_INPUT_TEST_BUTTON_CUR = selectedInput->cur.button;
        R_INPUT_TEST_BUTTON_PRESS = selectedInput->press.button;
        R_INPUT_TEST_REL_STICK_X = selectedInput->rel.stick_x;
        R_INPUT_TEST_REL_STICK_Y = selectedInput->rel.stick_y;
        R_INPUT_TEST_REL_STICK_X_2 = selectedInput->rel.stick_x;
        R_INPUT_TEST_REL_STICK_Y_2 = selectedInput->rel.stick_y;
        R_INPUT_TEST_CUR_STICK_X = selectedInput->cur.stick_x;
        R_INPUT_TEST_CUR_STICK_Y = selectedInput->cur.stick_y;
        R_INPUT_TEST_COMPARE_BUTTON_CUR = (selectedInput->cur.button == inputCompareValue);
        R_INPUT_TEST_COMPARE_COMBO_CUR = CHECK_BTN_ALL(selectedInput->cur.button, inputCompareValue);
        R_INPUT_TEST_COMPARE_COMBO_PRESS = CHECK_BTN_ALL(selectedInput->press.button, inputCompareValue);
    }

    if (gIsCtrlr2Valid) {
        Regs_UpdateEditor(&gameState->input[1]);
    }

    gDmaMgrVerbose = HREG(60);
    gDmaMgrDmaBuffSize = SREG(21) != 0 ? ALIGN16(SREG(21)) : DMAMGR_DEFAULT_BUFSIZE;
    gSystemArenaLogSeverity = HREG(61);
    gZeldaArenaLogSeverity = HREG(62);

    if (R_HREG_MODE == HREG_MODE_PRINT_MEMORY) {
        if (R_PRINT_MEMORY_INIT != HREG_MODE_PRINT_MEMORY) {
            R_PRINT_MEMORY_INIT = HREG_MODE_PRINT_MEMORY;
            R_PRINT_MEMORY_TRIGGER = 0;
            R_PRINT_MEMORY_ADDR = 0;
            R_PRINT_MEMORY_SIZE = 0;
        }

        if (R_PRINT_MEMORY_TRIGGER < 0) {
            R_PRINT_MEMORY_TRIGGER = 0;
            hexDumpSize = (u32)(R_PRINT_MEMORY_SIZE == 0 ? 0x100 : R_PRINT_MEMORY_SIZE * 0x10);
            LogUtils_LogHexDump((void*)(0x80000000 + (R_PRINT_MEMORY_ADDR << 8)), hexDumpSize);
        }
    }
}

void GameState_DrawInputDisplay(u16 input, Gfx** gfx) {
    static const u16 sInpDispBtnColors[] = {
        GPACK_RGBA5551(255, 255, 0, 1),   GPACK_RGBA5551(255, 255, 0, 1),   GPACK_RGBA5551(255, 255, 0, 1),
        GPACK_RGBA5551(255, 255, 0, 1),   GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1),
        GPACK_RGBA5551(0, 255, 255, 1),   GPACK_RGBA5551(255, 0, 255, 1),   GPACK_RGBA5551(120, 120, 120, 1),
        GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(120, 120, 120, 1),
        GPACK_RGBA5551(255, 0, 0, 1),     GPACK_RGBA5551(120, 120, 120, 1), GPACK_RGBA5551(0, 255, 0, 1),
        GPACK_RGBA5551(0, 0, 255, 1),
    };
    s32 i, j, k;
    Gfx* gfxP = *gfx;

    gDPPipeSync(gfxP++);
    gDPSetOtherMode(gfxP++,
                    G_AD_PATTERN | G_CD_MAGICSQ | G_CK_NONE | G_TC_CONV | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                        G_TD_CLAMP | G_TP_NONE | G_CYC_FILL | G_PM_NPRIMITIVE,
                    G_AC_NONE | G_ZS_PIXEL | G_RM_NOOP | G_RM_NOOP2);

    for (i = 0; i < 16; i++) {
        j = i;
        if (input & (1 << i)) {
            gDPSetFillColor(gfxP++, (sInpDispBtnColors[i] << 0x10) | sInpDispBtnColors[i]);
            k = i + 1;
            gDPFillRectangle(gfxP++, (j * 4) + 226, 220, (k * 4) + 225, 223);
            gDPPipeSync(gfxP++);
        }
    }

    *gfx = gfxP;
}

void GameState_Draw(GameState* gameState, GraphicsContext* gfxCtx) {
    Gfx* newDList;
    Gfx* polyOpaP;

    OPEN_DISPS(gfxCtx, "../game.c", __LINE__);

    newDList = Graph_GfxPlusOne(polyOpaP = POLY_OPA_DISP);
    gSPDisplayList(OVERLAY_DISP++, newDList);

    if (R_ENABLE_FB_FILTER == 1) {
        GameState_SetFBFilter(&newDList);
    }

    sLastButtonPressed = gameState->input[0].press.button | gameState->input[0].cur.button;
    if (R_DISABLE_INPUT_DISPLAY == 0) {
        GameState_DrawInputDisplay(sLastButtonPressed, &newDList);
    }

    if (R_ENABLE_AUDIO_DBG & 1) {
        s32 pad;
        GfxPrint printer;

        GfxPrint_Init(&printer);
        GfxPrint_Open(&printer, newDList);
        AudioDebug_Draw(&printer);
        newDList = GfxPrint_Close(&printer);
        GfxPrint_Destroy(&printer);
    }

    if (R_ENABLE_ARENA_DBG < 0) {
        s32 pad;

        DebugArena_Display();
        SystemArena_Display();
        // "%08X bytes left until the death of Hyrule (game_alloc)"
        osSyncPrintf("%08X bytes left until the death of Hyrule(Game_Alloc)\n", THA_GetRemaining(&gameState->tha));
        R_ENABLE_ARENA_DBG = 0;
    }

    gSPEndDisplayList(newDList++);
    Graph_BranchDlist(polyOpaP, newDList);
    POLY_OPA_DISP = newDList;

    CLOSE_DISPS(gfxCtx, "../game.c", __LINE__);

    Debug_DrawText(gfxCtx);

    if (R_ENABLE_ARENA_DBG != 0) {
        SpeedMeter_DrawTimeEntries(&D_801664D0, gfxCtx);
        SpeedMeter_DrawAllocEntries(&D_801664D0, gfxCtx, gameState);
    }
}

void GameState_SetFrameBuffer(GraphicsContext* gfxCtx) {
    OPEN_DISPS(gfxCtx, "../game.c", __LINE__);

    gSPSegment(POLY_OPA_DISP++, 0, 0);
    gSPSegment(POLY_OPA_DISP++, 0xF, gfxCtx->curFrameBuffer);
    gSPSegment(POLY_OPA_DISP++, 0xE, gZBuffer);
    gSPSegment(POLY_XLU_DISP++, 0, 0);
    gSPSegment(POLY_XLU_DISP++, 0xF, gfxCtx->curFrameBuffer);
    gSPSegment(POLY_XLU_DISP++, 0xE, gZBuffer);
    gSPSegment(OVERLAY_DISP++, 0, 0);
    gSPSegment(OVERLAY_DISP++, 0xF, gfxCtx->curFrameBuffer);
    gSPSegment(OVERLAY_DISP++, 0xE, gZBuffer);

    CLOSE_DISPS(gfxCtx, "../game.c", __LINE__);
}

void func_800C49F4(GraphicsContext* gfxCtx) {
    Gfx* newDlist;
    Gfx* polyOpaP;

    OPEN_DISPS(gfxCtx, "../game.c", __LINE__);

    newDlist = Graph_GfxPlusOne(polyOpaP = POLY_OPA_DISP);
    gSPDisplayList(OVERLAY_DISP++, newDlist);

    gSPEndDisplayList(newDlist++);
    Graph_BranchDlist(polyOpaP, newDlist);
    POLY_OPA_DISP = newDlist;

    CLOSE_DISPS(gfxCtx, "../game.c", __LINE__);
}

void PadMgr_RequestPadData(PadMgr* padMgr, Input* inputs, s32 gameRequest);

void GameState_ReqPadData(GameState* gameState) {
    PadMgr_RequestPadData(&gPadMgr, gameState->input, true);
}

void GameState_Update(GameState* gameState) {
    GraphicsContext* gfxCtx = gameState->gfxCtx;

    GameState_SetFrameBuffer(gfxCtx);

    gameState->main(gameState);

    func_800C4344(gameState);

    if (SREG(63) == 1u) {
        if (R_VI_MODE_EDIT_STATE < VI_MODE_EDIT_STATE_INACTIVE) {
            R_VI_MODE_EDIT_STATE = VI_MODE_EDIT_STATE_INACTIVE;
            gfxCtx->viMode = &gViConfigMode;
            gfxCtx->viFeatures = gViConfigFeatures;
            gfxCtx->xScale = gViConfigXScale;
            gfxCtx->yScale = gViConfigYScale;
        } else if (R_VI_MODE_EDIT_STATE > VI_MODE_EDIT_STATE_INACTIVE) {
            ViMode_Update(&sViMode, &gameState->input[0]);
            gfxCtx->viMode = &sViMode.customViMode;
            gfxCtx->viFeatures = sViMode.viFeatures;
            gfxCtx->xScale = 1.0f;
            gfxCtx->yScale = 1.0f;
        }
    } else if (SREG(63) >= 2) {
        gfxCtx->viMode = &gViConfigMode;
        gfxCtx->viFeatures = gViConfigFeatures;
        gfxCtx->xScale = gViConfigXScale;
        gfxCtx->yScale = gViConfigYScale;

        if (SREG(63) == 6 || (SREG(63) == 2u && osTvType == OS_TV_NTSC)) {
            gfxCtx->viMode = &osViModeNtscLan1;
            gfxCtx->yScale = 1.0f;
        }

        if (SREG(63) == 5 || (SREG(63) == 2u && osTvType == OS_TV_MPAL)) {
            gfxCtx->viMode = &osViModeMpalLan1;
            gfxCtx->yScale = 1.0f;
        }

        if (SREG(63) == 4 || (SREG(63) == 2u && osTvType == OS_TV_PAL)) {
            gfxCtx->viMode = &osViModePalLan1;
            gfxCtx->yScale = 1.0f;
        }

        if (SREG(63) == 3 || (SREG(63) == 2u && osTvType == OS_TV_PAL)) {
            gfxCtx->viMode = &osViModeFpalLan1;
            gfxCtx->yScale = 0.833f;
        }
    } else {
        gfxCtx->viMode = NULL;
    }

    if (R_HREG_MODE == HREG_MODE_VI) {
        if (R_VI_INIT != HREG_MODE_VI) {
            R_VI_INIT = HREG_MODE_VI;
            R_VI_NEXT_Y_SCALE_MODE = 0;
            R_VI_NEXT_ADDI_SCAN_LINES = gViConfigAdditionalScanLines;
            R_VI_CUR_ADDI_SCAN_LINES = 0;
            R_VI_CUR_Y_SCALE_MODE = 0;
        }

        if (R_VI_NEXT_ADDI_SCAN_LINES < 0) {
            R_VI_NEXT_ADDI_SCAN_LINES = 0;
        }

        if (R_VI_NEXT_ADDI_SCAN_LINES > 0x30) {
            R_VI_NEXT_ADDI_SCAN_LINES = 0x30;
        }

        if ((R_VI_CUR_ADDI_SCAN_LINES != R_VI_NEXT_ADDI_SCAN_LINES) ||
            R_VI_CUR_Y_SCALE_MODE != R_VI_NEXT_Y_SCALE_MODE) {

            R_VI_CUR_ADDI_SCAN_LINES = R_VI_NEXT_ADDI_SCAN_LINES;
            R_VI_CUR_Y_SCALE_MODE = R_VI_NEXT_Y_SCALE_MODE;

            gViConfigAdditionalScanLines = R_VI_NEXT_ADDI_SCAN_LINES;
            gViConfigYScale = R_VI_NEXT_Y_SCALE_MODE == 0
                                  ? ((f32)SCREEN_HEIGHT) / (gViConfigAdditionalScanLines + (f32)SCREEN_HEIGHT)
                                  : 1.0f;
            D_80009430 = 1;
        }
    }

    if (R_PAUSE_BG_PRERENDER_STATE != (u32)PAUSE_BG_PRERENDER_PROCESS) {
        GameState_Draw(gameState, gfxCtx);
        func_800C49F4(gfxCtx);
    }

    gameState->frames++;
}

void GameState_InitArena(GameState* gameState, size_t size) {
    void* arena;

    osSyncPrintf("Hyrule reserved size＝%u bytes\n"); // "Hyrule reserved size = %u bytes"
    arena = GameAlloc_MallocDebug(&gameState->alloc, size, "../game.c", __LINE__);
    if (arena != NULL) {
        THA_Init(&gameState->tha, arena, size);
        osSyncPrintf("Successful Hyrule\n"); // "Successful Hyral"
    } else {
        THA_Init(&gameState->tha, NULL, 0);
        osSyncPrintf("Failure to secure Hyrule\n"); // "Failure to secure Hyrule"
        Fault_AddHungupAndCrash("../game.c", __LINE__);
    }
}

void GameState_Realloc(GameState* gameState, size_t size) {
    GameAlloc* alloc = &gameState->alloc;
    void* gameArena;
    u32 systemMaxFree;
    u32 systemFree;
    u32 systemAlloc;
    void* thaStart = gameState->tha.start;

    THA_Destroy(&gameState->tha);
    GameAlloc_Free(alloc, thaStart);
    osSyncPrintf("Hyrule temporarily released!!\n"); // "Hyrule temporarily released!!"
    SystemArena_GetSizes(&systemMaxFree, &systemFree, &systemAlloc);
    if ((systemMaxFree - 0x10) < size) {
        osSyncPrintf("%c", BEL);
        osSyncPrintf(VT_FGCOL(RED));

        // "Not enough memory. Change the hyral size to the largest possible value"
        osSyncPrintf("Not enough memory. Change the hyral size to the largest possible value\n");
        osSyncPrintf("(size=%08X systemMaxFree=%08X systemFree=%08X systemAlloc=%08X)\n", size, systemMaxFree, systemFree, systemAlloc);
        osSyncPrintf(VT_RST);
        size = systemMaxFree - 0x10;
    }

    osSyncPrintf("Hyrule reallocate size＝%u bytes\n", size); // "Hyral reallocate size = %u bytes"
    gameArena = GameAlloc_MallocDebug(alloc, size, "../game.c", __LINE__);
    if (gameArena != NULL) {
        THA_Init(&gameState->tha, gameArena, size);
        osSyncPrintf("Successful reacquisition of Hyrule\n"); // "Successful reacquisition of Hyrule"
    } else {
        THA_Init(&gameState->tha, NULL, 0);
        osSyncPrintf("Failure to secure Hyrule\n"); // "Failure to secure Hyral"
        SystemArena_Display();
        Fault_AddHungupAndCrash("../game.c", __LINE__);
    }
}

void GameState_Init(GameState* gameState, GameStateFunc init, GraphicsContext* gfxCtx) {
    OSTime startTime;
    OSTime endTime;

    osSyncPrintf("GameState_Init START\n"); // "game constructor start"
    gameState->gfxCtx = gfxCtx;
    gameState->frames = 0;
    gameState->main = NULL;
    gameState->destroy = NULL;
    gameState->running = 1;
    startTime = osGetTime();
    gameState->size = 0;
    gameState->init = NULL;
    endTime = osGetTime();

    // "game_set_next_game_null processing time %d us"
    osSyncPrintf("SET_NEXT_GAMESTATE processing time %d us\n", OS_CYCLES_TO_USEC(endTime - startTime));
    startTime = endTime;
    GameAlloc_Init(&gameState->alloc);

    endTime = osGetTime();
    // "gamealloc_init processing time %d us"
    osSyncPrintf("GameAlloc_Init processing time %d us\n", OS_CYCLES_TO_USEC(endTime - startTime));

    startTime = endTime;
    GameState_InitArena(gameState, 0x100000);
    R_UPDATE_RATE = 3;
    init(gameState);

    endTime = osGetTime();
    // "init processing time %d us"
    osSyncPrintf("GameState_InitArena processing time %d us\n", OS_CYCLES_TO_USEC(endTime - startTime));

    startTime = endTime;
    LogUtils_CheckNullPointer("gameState->destroy", gameState->destroy, "../game.c", __LINE__);
    func_800ACE70(&D_801664F0);
    func_800AD920(&D_80166500);
    VisMono_Init(&sMonoColors);
    if (R_VI_MODE_EDIT_STATE == VI_MODE_EDIT_STATE_INACTIVE) {
        ViMode_Init(&sViMode);
    }
    SpeedMeter_Init(&D_801664D0);
    Rumble_Init();
    osSendMesg(&gameState->gfxCtx->queue, NULL, OS_MESG_BLOCK);

    endTime = osGetTime();
    // "Other initialization processing time %d us"
    osSyncPrintf("Other initialization processing time %d us\n", OS_CYCLES_TO_USEC(endTime - startTime));

    Fault_AddClient(&sGameFaultClient, GameState_FaultPrint, NULL, NULL);

    osSyncPrintf("GameState_Init END\n"); // "game constructor end"
}

void GameState_Destroy(GameState* gameState) {
    osSyncPrintf("GameState_Destroy START\n"); // "game destructor start"
    AudioMgr_StopAllSfx();
    func_800F3054();
    osRecvMesg(&gameState->gfxCtx->queue, NULL, OS_MESG_BLOCK);
    LogUtils_CheckNullPointer("gameState->destroy", gameState->destroy, "../game.c", __LINE__);
    if (gameState->destroy != NULL) {
        gameState->destroy(gameState);
    }
    Rumble_Destroy();
    SpeedMeter_Destroy(&D_801664D0);
    func_800ACE90(&D_801664F0);
    func_800AD950(&D_80166500);
    VisMono_Destroy(&sMonoColors);
    if (R_VI_MODE_EDIT_STATE == VI_MODE_EDIT_STATE_INACTIVE) {
        ViMode_Destroy(&sViMode);
    }
    THA_Destroy(&gameState->tha);
    GameAlloc_Cleanup(&gameState->alloc);
    SystemArena_Display();
    Fault_RemoveClient(&sGameFaultClient);

    osSyncPrintf("GameState_Destroy END\n"); // "game destructor end"
}

GameStateFunc GameState_GetInit(GameState* gameState) {
    return gameState->init;
}

size_t GameState_GetSize(GameState* gameState) {
    return gameState->size;
}

u32 GameState_IsRunning(GameState* gameState) {
    return gameState->running;
}

void* GameState_Alloc(GameState* gameState, size_t size, char* file, s32 line) {
    void* ret;

    if (THA_IsCrash(&gameState->tha)) {
        osSyncPrintf("Hyrule is dying\n");
        ret = NULL;
    } else if ((u32)THA_GetRemaining(&gameState->tha) < size) {
        // "Hyral on the verge of extinction does not have %d bytes left (%d bytes until extinction)"
        osSyncPrintf("Hyral on the verge of extinction does not have %d bytes left (%d bytes until extinction) \n", size,
                     THA_GetRemaining(&gameState->tha));
        ret = NULL;
    } else {
        ret = THA_AllocTailAlign16(&gameState->tha, size);
        if (THA_IsCrash(&gameState->tha)) {
            osSyncPrintf("Hyrule has been destroyed\n"); // "Hyrule has been destroyed"
            ret = NULL;
        }
    }
    if (ret != NULL) {
        osSyncPrintf(VT_FGCOL(GREEN));
        osSyncPrintf("GameState_Alloc(%08X) %08X-%08X [%s:%d]\n", size, ret, (uintptr_t)ret + size, file, line);
        osSyncPrintf(VT_RST);
    }
    return ret;
}

void* GameState_AllocEndAlign16(GameState* gameState, size_t size) {
    return THA_AllocTailAlign16(&gameState->tha, size);
}

s32 GameState_GetArenaSize(GameState* gameState) {
    return THA_GetRemaining(&gameState->tha);
}
