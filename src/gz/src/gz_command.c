#include <ultra64.h>
#include <global.h>
#include "gz.h"
#include "menu.h"
#include "settings.h"

CommandInfo gGZCommandInfo[COMMAND_MAX] = 
{
      {"show/hide menu",    NULL,                  CMDACT_PRESS_ONCE},
      {"return from menu",  NULL,                  CMDACT_PRESS_ONCE},
      {"break free",        CommandInfo_Break,         CMDACT_HOLD},
      {"levitate",          CommandInfo_Levitate,      CMDACT_HOLD},
      {"fall",              CommandInfo_Fall,          CMDACT_HOLD},
      {"turbo",             CommandInfo_Turbo,         CMDACT_HOLD},
      {"file select",       CommandInfo_FileSelect,    CMDACT_PRESS_ONCE},
      {"reload scene",      CommandInfo_Reload,        CMDACT_PRESS_ONCE},
      {"void out",          CommandInfo_Void,          CMDACT_PRESS_ONCE},
      {"toggle age",        CommandInfo_Age,           CMDACT_PRESS_ONCE},
      {"save state",        CommandInfo_Savestate,     CMDACT_PRESS_ONCE},
      {"load state",        CommandInfo_Loadstate,     CMDACT_PRESS_ONCE},
      {"save memfile",      CommandInfo_SaveMemFile,   CMDACT_PRESS_ONCE},
      {"load memfile",      CommandInfo_LoadMemFile,   CMDACT_PRESS_ONCE},
      {"save position",     CommandInfo_SavePos,       CMDACT_HOLD},
      {"load position",     CommandInfo_LoadPos,       CMDACT_HOLD},
      {"previous state",    CommandInfo_PrevState,     CMDACT_PRESS_ONCE},
      {"next state",        CommandInfo_NextState,     CMDACT_PRESS_ONCE},
      {"previous memfile",  CommandInfo_PrevFile,      CMDACT_PRESS_ONCE},
      {"next memfile",      CommandInfo_NextFile,      CMDACT_PRESS_ONCE},
      {"previous position", CommandInfo_PrevPos,       CMDACT_PRESS_ONCE},
      {"next position",     CommandInfo_NextPos,       CMDACT_PRESS_ONCE},
      {"pause/unpause",     CommandInfo_Pause,         CMDACT_PRESS_ONCE},
      {"frame advance",     CommandInfo_Advance,       CMDACT_PRESS},
      {"record macro",      CommandInfo_RecordMacro,   CMDACT_PRESS_ONCE},
      {"play macro",        CommandInfo_PlayMacro,     CMDACT_PRESS_ONCE},
      {"collision view",    CommandInfo_ColView,       CMDACT_PRESS_ONCE},
      {"hitbox view",       CommandInfo_HitView,       CMDACT_PRESS_ONCE},
      {"explore prev room", NULL,                  CMDACT_PRESS},
      {"explore next room", NULL,                  CMDACT_PRESS},
      {"reset lag counter", CommandInfo_ResetLag,      CMDACT_HOLD},
      {"toggle watches",    CommandInfo_ToggleWatches, CMDACT_PRESS},
      {"start/stop timer",  CommandInfo_Timer,         CMDACT_PRESS_ONCE},
      {"reset timer",       CommandInfo_ResetTimer,    CMDACT_HOLD},
      {"start timer",       CommandInfo_StartTimer,    CMDACT_PRESS_ONCE},
      {"stop timer",        CommandInfo_StopTimer,     CMDACT_PRESS_ONCE},
      {"reset",             CommandInfo_Reset,         CMDACT_PRESS_ONCE},
};

void gz_apply_settings() {
    Menu_SetCellWidth(gz.menuMain, 16 + 4);
    Menu_SetCellHeight(gz.menuMain, 256 + 4);
    Menu_SetPxOffset(gz.menuMain, settings->menuX);
    Menu_SetPyOffset(gz.menuMain, settings->menuY);
    Menu_Imitate(gz.menuGlobal, gz.menuMain);
    Watchlist_Fetch(gz.menuWatchlist);
}

void gz_show_menu(void) {
    Menu_SignalEnter(gz.menuMain, MENU_SWITCH_SHOW);
    gz.menuActive = 1;
    Input_Reverse(BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT | BTN_L);
    Input_ReservationSet(1);
}

void gz_hide_menu(void) {
    Menu_SignalLeave(gz.menuMain, MENU_SWITCH_HIDE);
    gz.menuActive = 0;
    Input_Free(BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT | BTN_L);
    Input_ReservationSet(0);
}

void gz_log(const char* fmt, ...) {
    va_list va;
    s32 l;
    s32 i;
    LogEntry* ent = &gz.log[SETTINGS_LOG_MAX - 1];
    if (ent->msg)
        free(ent->msg);
    for (i = SETTINGS_LOG_MAX - 1; i > 0; --i) 
        gz.log[i] = gz.log[i - 1];
    
    va_start(va, fmt);
    l = vsprintf(NULL, fmt, va);
    va_end(va);

    ent = &gz.log[0];
    ent->msg = malloc(l + 1);
    if (!ent->msg)
        return;
    va_start(va, fmt);
    vsprintf(ent->msg, fmt, va);
    va_end(va);
    ent->age = 0;
}

void gz_warp(GameState* game, s16 entranceIdx, s32 age) {
    GlobalContext* globalCtx = (GlobalContext *)game;
    if (age == 0)
        age = globalCtx->linkAgeOnLoad;
    else
        --age;

    if (globalCtx->linkAgeOnLoad == age)
        gSaveContext.linkAge = age;
    else
        globalCtx->linkAgeOnLoad = age;

    Select_LoadGame(globalCtx, entranceIdx);      
}

void gz_set_input_mask(u16 button, u8 x, u8 y) {
    gz.zInputMask.button = button;
    gz.zInputMask.stick_x = x;
    gz.zInputMask.stick_y = y;
}

void gz_save_memfile(GlobalContext* globalCtx, gzMemFile* memfile) {
    #if 0
    u32 f;
    ActorContext* actorCtx = &globalCtx->actorCtx;

    memcpy(&memfile->saveCtx, &gSaveContext, sizeof(memfile->saveCtx));
    memfile->entranceOverride = gz.entranceOverrideNext;
    memfile->nextEntrance = gz.nextEntrance;
    memfile->sceneIdx = globalCtx->sceneNum;
    f = actorCtx->flags.chest;
    memfile->saveCtx.sceneFlags[globalCtx->sceneNum].chest = f;
    f = actorCtx->flags.swch;
    memfile->saveCtx.sceneFlags[globalCtx->sceneNum].swch = f;
    f = actorCtx->flags.clear;
    memfile->saveCtx.sceneFlags[globalCtx->sceneNum].clear = f;
    f = actorCtx->flags.collect;
    memfile->saveCtx.sceneFlags[globalCtx->sceneNum].collect = f;
    memcpy(&memfile->sceneFlags, &actorCtx->flags.swch, sizeof(memfile->sceneFlags));

    /* pause screen stuff */
    {
        /*
        PauseContext* pauseCtx = &globalCtx->pauseCtx;
        memfile->startIconDD = ZREG(48); //
        memfile->pauseScreen = pauseCtx->kscpPos;
        */
    }
    #endif
}

void gz_load_memfile(gzMemFile* memfile) {
    #if 0

    #endif
}

void CommandInfo_Break(void) {
    if ()
}