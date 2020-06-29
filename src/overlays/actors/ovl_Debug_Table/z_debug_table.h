#ifndef _Z_DEBUG_TABLE_H_
#define _Z_DEBUG_TABLE_H_

#include <ultra64.h>
#include <global.h>

#define NUM_OF_ITEMS 2
#define NUM_OF_WARP_CATEGORIES 1
#define NUM_OF_DUNGEONS 9

struct DebugTable;
struct MenuItem;

typedef enum {
    DUNGEON_DEKU,
    DUNGEON_DODONGO,
    DUNGEON_JABU,
    DUNGEON_FOREST,
    DUNGEON_FIRE,
    DUNGEON_WATER,
    DUNGEON_SHADOW,
    DUNGEON_SPIRIT,
    DUNGEON_GANON,
} Dungeons;

typedef enum {
    MENU_DEBUG,
    MENU_WARPS,
    ITEM_2,
    ITEM_3,
} CursorPos;

typedef enum {
    MAIN_MENU,
    WARP_CATEGORY_MENU,
    WARP_DUNGEON_MENU,
    DEBUG_MENU,
} ActiveMenus;

typedef enum {
    WARPS_DUNGEONS,
} WarpNames;

typedef struct MenuItem {
    Vec2s pos;
    char* name;
} MenuItem;

typedef struct DebugTable {
    Actor actor;
    u32 cursorPos;
    u32 menuDepth;
    u8 activeMenu;
    u8 pressed;
    s16 actionTimer;
    s32 currentScene;
    SceneSelectEntry* scenes;
    MenuItem mainMenu[NUM_OF_ITEMS];
    MenuItem warpMenu[NUM_OF_WARP_CATEGORIES];
    MenuItem dungeonMenu[NUM_OF_DUNGEONS];
} DebugTable; // size =

extern const ActorInit Debug_Table_InitVars;

#endif