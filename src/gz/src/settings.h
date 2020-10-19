#ifndef SETTINGS_H
#define SETTINGS_H

#include <global.h>

#define SETTINGS_ADDRESS            0x7A00
#define SETTINGS_MAXSIZE            (0x8000-(SETTINGS_ADDRESS))
#define SETTINGS_PADSIZE            ((sizeof(Settings)+1)/2*2)
#define SETTINGS_PROFILE_MAX        ((SETTINGS_MAXSIZE)/(SETTINGS_PADSIZE))
#define SETTINGS_VERSION            0x0003
#define SETTINGS_STATE_VERSION      0x0003

#define SETTINGS_WATCHES_MAX        18
#define SETTINGS_TELEPORT_MAX       9
#define SETTINGS_MEMFILE_MAX        10
#define SETTINGS_STATE_MAX          3
#define SETTINGS_BIND_MAX           COMMAND_MAX
#define SETTINGS_LOG_MAX            4

#define SETTINGS_LAG_FRAMES         0
#define SETTINGS_LAG_SECONDS        1

#define SETTINGS_BREAK_NORMAL       0
#define SETTINGS_BREAK_AGGRESSIVE   1

#define SETTINGS_LOADTO_ZFILE       0
#define SETTINGS_LOADTO_MEMFILE     1
#define SETTINGS_LOADTO_BOTH        2

#define SETTINGS_ONLOAD_NOTHING     0
#define SETTINGS_ONLOAD_RELOAD      1
#define SETTINGS_ONLOAD_VOID        2

#define SETTINGS_COLVIEW_DECAL      0
#define SETTINGS_COLVIEW_SURFACE    1

typedef enum
{
  CHEAT_ENERGY,
  CHEAT_MAGIC,
  CHEAT_STICKS,
  CHEAT_NUTS,
  CHEAT_BOMBS,
  CHEAT_ARROWS,
  CHEAT_SEEDS,
  CHEAT_BOMBCHUS,
  CHEAT_BEANS,
  CHEAT_KEYS,
  CHEAT_RUPEES,
  CHEAT_NL,
  CHEAT_FREEZETIME,
  CHEAT_NOMUSIC,
  CHEAT_USEITEMS,
  CHEAT_NOMAP,
  CHEAT_ISG,
  CHEAT_QUICKTEXT,
  CHEAT_MAX,
} Cheats;

typedef enum
{
  COMMAND_MENU,
  COMMAND_RETURN,
  CommandInfo_Break,
  CommandInfo_Levitate,
  CommandInfo_Fall,
  CommandInfo_Turbo,
  CommandInfo_FileSelect,
  CommandInfo_Reload,
  CommandInfo_Void,
  CommandInfo_Age,
  CommandInfo_Savestate,
  CommandInfo_Loadstate,
  CommandInfo_SaveMemFile,
  CommandInfo_LoadMemFile,
  CommandInfo_SavePos,
  CommandInfo_LoadPos,
  CommandInfo_PrevState,
  CommandInfo_NextState,
  CommandInfo_PrevFile,
  CommandInfo_NextFile,
  CommandInfo_PrevPos,
  CommandInfo_NextPos,
  CommandInfo_Pause,
  CommandInfo_Advance,
  CommandInfo_RecordMacro,
  CommandInfo_PlayMacro,
  CommandInfo_ColView,
  CommandInfo_HitView,
  COMMAND_PREVROOM,
  COMMAND_NEXTROOM,
  CommandInfo_ResetLag,
  CommandInfo_ToggleWatches,
  CommandInfo_Timer,
  CommandInfo_ResetTimer,
  CommandInfo_StartTimer,
  CommandInfo_StopTimer,
  CommandInfo_Reset,
  COMMAND_MAX,
} Commands;

typedef struct WatchInfo
{
  u8 type          : 4;
  u8 anchored      : 1;
  u8 position_set  : 1;
} WatchInfo;

typedef struct SettingsBits
{
  u32 fontResource   : 4;
  u32 dropShadow     : 1;
  u32 inputDisplay   : 1;
  u32 log             : 1;
  u32 lagCounter     : 1;
  u32 lagUnit        : 1;
  u32 timer           : 1;
  u32 pauseDisplay   : 1;
  u32 macroInput     : 1;
  u32 hackOcaInput  : 1;
  u32 hackOcaSync   : 1;
  u32 hackRoomLoad  : 1;
  u32 wiiVCCam       : 1;
  u32 breakType      : 1;
  u32 warpAge        : 2;
  u32 warpCutscene   : 5;
  u32 loadTo         : 2;
  u32 onLoad         : 2;
  u32 colViewMode   : 1;
  u32 colViewXlu    : 1;
  u32 colViewLine   : 1;
  u32 colViewShade  : 1;
  u32 colViewRd     : 1;
  u32 colViewUpd    : 1;
  u32 hitViewXlu    : 1;
  u32 hitViewShade  : 1;
  u32 watchesVisible : 1;
} SettingsBits;

typedef struct SettingsData
{
  /* order elements by size for space-efficient packing */
  Vec3f            teleportPos[SETTINGS_TELEPORT_MAX];
  u32              watchAddress[SETTINGS_WATCHES_MAX];
  u32              cheats;
  u16           teleportRot[SETTINGS_TELEPORT_MAX];
  struct SettingsBits  bits;
  s16               menuX;
  s16               menuY;
  s16               inputDisplayX;
  s16               inputDisplayY;
  s16               logX;
  s16               logY;
  s16               lagCounterX;
  s16               lagCounterY;
  s16               timerX;
  s16               timerY;
  s16               watchX[SETTINGS_WATCHES_MAX];
  s16               watchY[SETTINGS_WATCHES_MAX];
  u16              warpEntrance;
  u16              binds[SETTINGS_BIND_MAX];
  struct WatchInfo     watchInfo[SETTINGS_WATCHES_MAX];
  u8               teleport_slot;
  u8               n_watches;
} SettingsData;

typedef struct SettingsHeader
{
  u16  version;
  u16  dataSize;
  u16  dataChecksum;
} SettingsHeader;

typedef struct Settings
{
  struct SettingsHeader  header;
  struct SettingsData    data;
} Settings;

void Settings_LoadDefault(void);
void  Settings_Save(s32 profile);
u8 Settings_Load(s32 profile);

extern struct SettingsData *settings;

#endif
