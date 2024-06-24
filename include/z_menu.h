#ifndef _Z_MENU_H_
#define _Z_MENU_H_

#include <global.h>

struct Menu;

typedef void (*MenuFunc)(struct Menu*, PlayState*);

typedef struct Menu {
    const char* name;
    struct Menu* head;
    struct Menu** items;
    MenuFunc init;
    MenuFunc destroy;
    MenuFunc update;
    MenuFunc draw;
} Menu;

extern Menu* gMenu;
extern u8 gMenuActive;

void Menu_Init(Menu* this, PlayState* play);
void Menu_Update(Menu* this, PlayState* play);
void Menu_Draw(Menu* this, PlayState* play);
void Menu_Destroy(Menu* this, PlayState* play);

Menu** Menu_Alloc(s32 numItems);
Menu* MenuItem_Alloc(void);
void Menu_Create(void);

#endif
