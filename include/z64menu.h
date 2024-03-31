#ifndef _Z64_MENU_H_
#define _Z64_MENU_H_

#include <global.h>

struct ZeldaMenu;

typedef struct ZeldaMenu {
 /* 0x000 */ s32 idx;
 /* 0x004 */ struct MenuItem** items;
 /* 0x008 */ s32 numItems;
} ZeldaMenu;

typedef struct MenuItem {
    /* 0x00 */ const char* name;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0C */ struct ZeldaMenu* submenu;
} MenuItem;

typedef enum {
    /* 0x00 */ MENU_WARPS,
    /* 0x01 */ MENU_ITEM1,
    /* 0x02 */ MENU_ITEM2,
    /* 0x03 */ MENU_MAX
} MenuIdx;

typedef enum {
    /* 0x00 */ DEKU_TREE,
    /* 0x01 */ WARP_01,
    /* 0x02 */ WARP_02
} WarpsIdx;

extern void ZeldaMenu_Init();
extern void ZeldaMenu_Destroy();
extern void ZeldaMenu_Draw(PlayState* play);
extern ZeldaMenu* gZeldaMenu;

s32 ZeldaMenu_AddItem(ZeldaMenu* menu, const char* name, s32 x, s32 y);
void ZeldaMenu_SetItem(ZeldaMenu* menu, const char* name, s32 x, s32 y, s32 idx);
void ZeldaMenu_Update(ZeldaMenu* menu, PlayState* play);
MenuItem** MenuItem_AllocArray(s32 numItems);

#endif
