#ifndef GZ_H
#define GZ_H
#include <stdint.h>
#include <vector/vector.h>
#include <ultra64.h>
#include <global.h>
#include "settings.h"
#include "menu.h"

typedef enum CmdAct
{
  CMDACT_HOLD,
  CMDACT_PRESS,
  CMDACT_PRESS_ONCE,
} CmdAct;

typedef struct CommandInfo
{
  const char           *name;
  void                (*update)(void);
  CmdAct           activationType;
} CommandInfo;

typedef enum ColViewState
{
  COLVIEW_INACTIVE,
  COLVIEW_START,
  COLVIEW_ACTIVE,
  COLVIEW_BEGIN_STOP,
  COLVIEW_STOP,
  COLVIEW_BEGIN_RESTART,
  COLVIEW_RESTART,
} ColViewState;

typedef enum HitViewState
{
  HITVIEW_INACTIVE,
  HITVIEW_START,
  HITVIEW_ACTIVE,
  HITVIEW_BEGIN_STOP,
  HITVIEW_STOP,
} HitViewState;

typedef enum CamMode
{
  CAMMODE_CAMERA,
  CAMMODE_VIEW,
} CamMode;

typedef enum CamBhv
{
  CAMBHV_MANUAL,
  CAMBHV_BIRDSEYE,
  CAMBHV_RADIAL,
} CamBhv;

typedef struct gzMemFile
{
  SaveContext            saveCtx;
  u8                 entranceOverride;
  s32               nextEntrance;
  u16              sceneIdx;
  u32              sceneFlags[9];
  qs510_t               startIconDD;
  u16              pauseScreen;
  s16               itemScreenCursor;
  s16               questScreenCursor;
  s16               equipScreenCursor;
  s16               mapScreenCursor;
  s16               itemScreenX;
  s16               equipmentScreenX;
  s16               itemScreenY;
  s16               equipmentScreenY;
  s16               pauseScreenCursor;
  s16               questScreenItem;
  s16               questScreenHilite;
  s16               questScreenSong;
} gzMemFile;

typedef enum
{
  MOVIE_IDLE,
  MOVIE_RECORDING,
  MOVIE_PLAYING
} MovieState;

typedef struct MovieInput
{
  Input      raw;            /* 0x0000 */
  u16        padDelta;      /* 0x0004 */
                                        /* 0x0006 */
} MovieInput;

typedef struct MovieSeed
{
  s32                   frameIdx;
  u32              oldSeed;
  u32              newSeed;
} MovieSeed;

typedef struct MovieOcaInput
{
  s32               frameIdx;
  u16              pad;
  s8                adjustedX;
  s8                adjustedY;
} MovieOcaInput;

typedef struct MovieOcaSync
{
  s32               frameIdx;
  s32               audioFrames;
} MovieOcaSync;

typedef struct MovieRoomLoad
{
  s32               frameIdx;
} MovieRoomLoad;

typedef struct LogEntry
{
  char                 *msg;
  s32                   age;
} LogEntry;

typedef struct gz
{
  u8                 ready;
  u8               profile;
  Menu          *menuGlobal;
  Menu          *menuMain;
  Menu          *menuExplorer;
  Menu          *menuMem;
  MenuItem     *menuWatchlist;
  u8                 menuActive;
  LogEntry      log[SETTINGS_LOG_MAX];
  u8                 entranceOverrideOnce;
  u8                 entranceOverrideNext;
  s32               nextEntrance;
  u16              dayTimePrev;
  s32                   targetDayTime;
  s32               framesQueued;
 // struct zu_disp_p      z_disp_p;
  u32              dispHookSize[4];
  u32              dispHookP[4];
  u32              dispHookD[4];
  MovieState            movieState;
  Input                 movieInputStart;
  struct vector         MovieInput;
  struct vector         MovieSeed;
  struct vector         MovieOcaInput;
  struct vector         MovieOcaSync;
  struct vector         MovieRoomLoad;
  s32                   movieFrame;
  s32                   movieSeedPos;
  s32                   movieOcaInputPos;
  s32                   movieOcaSyncPos;
  s32                   movieRoomLoadPos;
  u8                 ocaInputFlag;
  u8                 ocaSyncFlag;
  u8                 roomLoadFlag;
  Input             zInputMask;
  u8                 vcontEnabled[4];
  Input           vcontInput[4];
  s32               frameCounter;
  s32               lagViOffset;
  int64_t               cpuCounter;
  s32               cpuCounterFreq;
  u8                 timerActive;
  int64_t               timerCounterOffset;
  int64_t               timerCounterPrev;
  s32                   colViewState;
  s32                   hitViewState;
  u8                 hideRooms;
  u8                 hideActors;
  u8                 freeCam;
  u8                 lockCam;
  CamMode         CamMode;
  CamBhv          CamBhv;
  s16               camDistMin;
  s16               camDistMax;
  f32                 camPitch;
  f32                 camYaw;
  Vec3f            camPos;
  gzMemFile   *memfile;
  u8                 memfileSaved[SETTINGS_MEMFILE_MAX];
  u8               memfileSlot;
  void                 *stateBuf[SETTINGS_STATE_MAX];
  u8               stateSlot;
  u8                 resetFlag;
  u8                 frameFlag;
} GZ;

void          gz_apply_settings();
void          gz_show_menu(void);
void          gz_hide_menu(void);
void          gz_log(const char *fmt, ...);
void          gz_save_memfile(struct gzMemFile *memfile);
void          gz_load_memfile(struct gzMemFile *memfile);
void          gz_warp(s16 entrance_index,
                      u16 cutsceneIdx, int age);
void          gz_set_input_mask(u16 pad, u8 x, u8 y);

void          CommandInfo_Break(void);
void          CommandInfo_Levitate(void);
void          CommandInfo_Fall(void);
void          CommandInfo_Turbo(void);
void          CommandInfo_FileSelect(void);
void          CommandInfo_Reload(void);
void          CommandInfo_Void(void);
void          CommandInfo_Age(void);
void          CommandInfo_Savestate(void);
void          CommandInfo_Loadstate(void);
void          CommandInfo_SaveMemFile(void);
void          CommandInfo_LoadMemFile(void);
void          CommandInfo_SavePos(void);
void          CommandInfo_LoadPos(void);
void          CommandInfo_PrevState(void);
void          CommandInfo_NextState(void);
void          CommandInfo_PrevFile(void);
void          CommandInfo_NextFile(void);
void          CommandInfo_PrevPos(void);
void          CommandInfo_NextPos(void);
void          CommandInfo_Pause(void);
void          CommandInfo_Advance(void);
void          CommandInfo_RecordMacro(void);
void          CommandInfo_PlayMacro(void);
void          CommandInfo_ColView(void);
void          CommandInfo_HitView(void);
void          CommandInfo_ResetLag(void);
void          CommandInfo_ToggleWatches(void);
void          CommandInfo_Timer(void);
void          CommandInfo_ResetTimer(void);
void          CommandInfo_StartTimer(void);
void          CommandInfo_StopTimer(void);
void          CommandInfo_Reset(void);

void          z_to_movie(s32 movieFrame, Input* input, u8 reset);
void          movie_to_z(s32 movieFrame, Input* input, u8 *reset);
void          gz_movie_rewind(void);
void          gz_movie_seek(s32 frame);

void          gz_vcont_set(s32 port, u8 plugged, Input *cont);
void          gz_vcont_get(s32 port, Input *input);

void          gz_col_view(void);
void          gz_hit_view(void);

void          gz_update_cam(void);
void          gz_free_view(void);

Menu  *gz_warps_menu(void);
Menu  *gz_scene_menu(void);
Menu  *gz_cheats_menu(void);
Menu  *gz_inventory_menu(void);
Menu  *gz_equips_menu(void);
Menu  *gsaveCtx_menu(void);
Menu  *gz_macro_menu(void);
Menu  *gz_debug_menu(void);
Menu  *gz_settings_menu(void);

extern struct gz            gz;
extern CommandInfo gGZCommandInfo[COMMAND_MAX];

#endif
