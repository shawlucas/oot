#include <ultra64.h>
#include <global.h>
#include "settings.h"

Settings gSettingsStore;
SettingsData* gSettings = &gSettingsStore.data;

static u16 Settings_ComputeChecksum(Settings *settings)
{
  u16 checksum = 0;
  u16 *p = (void*)&settings->data;
  u16 *e = p + sizeof(settings->data) / sizeof(*p);
  while (p < e)
    checksum += *p++;
  return checksum;
}

static u8 Settings_Validate(Settings *settings)
{
  return settings->header.version == SETTINGS_VERSION &&
         settings->header.dataSize == sizeof(settings->data) &&
         settings->header.dataChecksum == Settings_ComputeChecksum(settings);
}

void Settings_LoadDefault(void)
{
  gSettingsStore.header.version = SETTINGS_VERSION;
  gSettingsStore.header.dataSize = sizeof(gSettingsStore.data);
  SettingsData *d = &gSettingsStore.data;
  d->bits.fontResource = 0;
  d->bits.dropShadow = 1;
  d->bits.inputDisplay = 1;
  d->bits.log = 1;
  d->bits.lagCounter = 0;
  d->bits.lagUnit = SETTINGS_LAG_FRAMES;
  d->bits.timer = 0;
  d->bits.pauseDisplay = 1;
  d->bits.macroInput = 0;
  d->bits.hackOcaInput = 1;
  d->bits.hackOcaSync = 1;
  d->bits.hackRoomLoad = 1;
#ifdef WIIVC
  d->bits.wiiVCCam = 1;
#else
  d->bits.wiiVCCam = 0;
#endif
  d->bits.breakType = SETTINGS_BREAK_NORMAL;
  d->bits.warpAge = 0;
  d->bits.warpCutscene = 0;
  d->bits.loadTo = SETTINGS_LOADTO_ZFILE;
  d->bits.onLoad = SETTINGS_ONLOAD_NOTHING;
  d->bits.colViewMode = SETTINGS_COLVIEW_DECAL;
  d->bits.colViewXlu = 1;
  d->bits.colViewLine = 0;
  d->bits.colViewShade = 1;
  d->bits.colViewRd = 0;
  d->bits.colViewUpd = 1;
  d->bits.hitViewXlu = 1;
  d->bits.hitViewShade = 1;
  d->bits.watchesVisible = 1;
  d->menuX = 20;
  d->menuY = 64;
  d->inputDisplayX = 20;
  d->inputDisplayY = SCREEN_HEIGHT - 10;
  d->logX = SCREEN_WIDTH - 16;
  d->logY = SCREEN_HEIGHT - 18;
  d->lagCounterX = SCREEN_WIDTH - 16;
  d->lagCounterY = 24;
  d->timerX = 20;
  d->timerY = 24;
  d->n_watches = 0;
  d->cheats = 0;
  for (int i = 0; i < SETTINGS_TELEPORT_MAX; ++i) {
    d->teleportPos[i].x = 0.f;
    d->teleportPos[i].y = 0.f;
    d->teleportPos[i].z = 0.f;
    d->teleportRot[i] = 0;
  }
  d->teleport_slot = 0;
  d->warpEntrance = 0;
  d->binds[COMMAND_MENU] = bind_make(2, BTN_R, BTN_L);
  d->binds[COMMAND_RETURN] = bind_make(2, BTN_R, BTN_DLEFT);
#ifndef WIIVC
  d->binds[CommandInfo_Break] = bind_make(2, BTN_CUP, BTN_L);
#else
  d->binds[CommandInfo_Break] = bind_make(2, BUTTON_START, BTN_L);
#endif
  d->binds[CommandInfo_Levitate] = bind_make(1, BTN_L);
  d->binds[CommandInfo_Fall] = bind_make(2, BTN_Z, BTN_L);
  d->binds[CommandInfo_Turbo] = bind_make(0);
  d->binds[CommandInfo_FileSelect] = bind_make(2, BTN_B, BTN_L);
  d->binds[CommandInfo_Reload] = bind_make(2, BTN_A, BTN_L);
  d->binds[CommandInfo_Void] = bind_make(3, BTN_A, BTN_B, BTN_L);
  d->binds[CommandInfo_Age] = bind_make(0);
  d->binds[CommandInfo_Savestate] = bind_make(1, BTN_DLEFT);
  d->binds[CommandInfo_Loadstate] = bind_make(1, BTN_DRIGHT);
  d->binds[CommandInfo_SaveMemFile] = bind_make(0);
  d->binds[CommandInfo_LoadMemFile] = bind_make(0);
  d->binds[CommandInfo_SavePos] = bind_make(0);
  d->binds[CommandInfo_LoadPos] = bind_make(0);
  d->binds[CommandInfo_PrevState] = bind_make(0);
  d->binds[CommandInfo_NextState] = bind_make(0);
  d->binds[CommandInfo_PrevFile] = bind_make(0);
  d->binds[CommandInfo_NextFile] = bind_make(0);
  d->binds[CommandInfo_PrevPos] = bind_make(0);
  d->binds[CommandInfo_NextPos] = bind_make(0);
  d->binds[CommandInfo_Pause] = bind_make(1, BTN_DDOWN);
  d->binds[CommandInfo_Advance] = bind_make(1, BTN_DUP);
  d->binds[CommandInfo_RecordMacro] = bind_make(0);
  d->binds[CommandInfo_PlayMacro] = bind_make(0);
  d->binds[CommandInfo_ColView] = bind_make(0);
  d->binds[CommandInfo_HitView] = bind_make(0);
  d->binds[COMMAND_PREVROOM] = bind_make(2, BTN_R, BTN_DDOWN);
  d->binds[COMMAND_NEXTROOM] = bind_make(2, BTN_R, BTN_DUP);
  d->binds[CommandInfo_ResetLag] = bind_make(3, BTN_R, BTN_B, BTN_DRIGHT);
  d->binds[CommandInfo_ToggleWatches] = bind_make(2, BTN_R, BTN_DRIGHT);
  d->binds[CommandInfo_Timer] = bind_make(3, BTN_R, BTN_A, BTN_DLEFT);
  d->binds[CommandInfo_ResetTimer] = bind_make(3, BTN_R, BTN_B,
                                           BTN_DLEFT);
  d->binds[CommandInfo_StartTimer] = bind_make(0);
  d->binds[CommandInfo_StopTimer] = bind_make(0);
  d->binds[CommandInfo_Reset] = bind_make(0);
}

void Settings_Save(s32 profile)
{
  u16 *checksum = &gSettingsStore.header.dataChecksum;
  *checksum = Settings_ComputeChecksum(&gSettingsStore);
  ssSRAMWrite(&gSettingsStore, SETTINGS_ADDRESS + SETTINGS_PADSIZE * profile,
                sizeof(gSettingsStore));
}

u8 Settings_Load(int profile)
{
 /* _Alignas(16) */
  Settings settingsTmp;
  ssSRAMRead(&settingsTmp, SETTINGS_ADDRESS + SETTINGS_PADSIZE * profile,
               sizeof(settingsTmp));
  if (Settings_Validate(&settingsTmp)) {
    memcpy(&gSettingsStore, &settingsTmp, sizeof(settingsTmp));
    return 1;
  }
  else
    return 0;
}