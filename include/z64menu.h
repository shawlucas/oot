#ifndef _Z64_MENU_H_
#define _Z64_MENU_H_

#include <global.h>

typedef struct {
    /* 0x00 */ const char* name;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
} MenuItem;

typedef struct {
 /* 0x000 */ s32 idx;
 /* 0x004 */ MenuItem** items;
} ZeldaMenu;

extern void ZeldaMenu_Init();
extern void ZeldaMenu_Destroy();
extern void ZeldaMenu_Draw(PlayState* play);
extern ZeldaMenu* gZeldaMenu;

void ZeldaMenu_AddItem(const char* name, s32 x, s32 y, s32 numElements);

#endif
