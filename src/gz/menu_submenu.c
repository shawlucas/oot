#include <global.h>
#include "menu.h"

static s32 activate(MenuItem* item) {
    if (item->data != NULL) {
        Menu_EnterTop(item->owner, item->data);
    } else {
        Menu_ReturnTop(item->owner);
    }

    return 1;
}

MenuItem* Menu_AddSubmenu(Menu* menu, s32 x, s32 y, Menu* submenu, const char* name) {
    MenuItem* item = Menu_ItemAdd(menu, x, y, name, 0xFFFFFF);

    item->data = submenu;
    item->activate = activate;

    return item;
}
