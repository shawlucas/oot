#include <global.h>
#include <alloca.h>
#include "menu.h"
#include "../libgz/list.h"

char *strcpy(char *str1, const char *str2)
{
    char *p;
    p = str1;
    while(*str2) *p++ = *str2++;
    *p = '\0';
    return  str1;
}

void Menu_Init(Menu* menu, s32 cellWidth, s32 cellHeight, GfxFont* font) {
    menu->cxOfffset = MENU_NOVALUE;
    menu->cyOffset = MENU_NOVALUE;
    menu->pxOffset = MENU_NOVALUE;
    menu->pyOffset = MENU_NOVALUE;
    menu->cellWidth = cellWidth;
    menu->cellHeight = cellHeight;
    menu->font = font;
    menu->alpha = 1.f;
    list_init(&menu->items, sizeof(MenuItem));
    menu->selector = NULL;
    menu->parent = NULL;
    menu->child = NULL;
    menu->highlightColorAnimated = 0x000000;
    menu->highlightColorStatic = 0x2020FF;
    menu->highlightState[0] = 17;
    menu->highlightState[1] = 19;
    menu->highlightState[2] = 23;
}

void Menu_Imitate(Menu* dest, Menu* src) {
    dest->cellWidth = src->cellWidth;
    dest->cellHeight = src->cellHeight;
    dest->font = src->font;
    dest->alpha = src->alpha;
    dest->highlightColorStatic = src->highlightColorStatic;
}

void Menu_Destroy(Menu* menu) {
    while (menu->items.first) {
        Menu_ItemRemove(menu->items.first);
    }
}

s32 Menu_GetCxOffset(Menu* menu, u8 inherit) {
    s32 cxOffset = menu->cxOfffset;

    if (inherit && menu->parent) {
        cxOffset += Menu_GetCxOffset(menu->parent, 1);
    }

    return cxOffset;
}

void Menu_SetCxOffset(Menu* menu, s32 cxOffset) {
    menu->cxOfffset = cxOffset;
}

s32 Menu_GetCyOffset(Menu* menu, u8 inherit) {
    s32 cyOffset = menu->cyOffset;

    if (inherit && menu->parent) {
        cyOffset += Menu_GetCyOffset(menu->parent, 1);
    }

    return cyOffset;
}

void Menu_SetCyOffset(Menu* menu, s32 cyOffset) {
    menu->cyOffset = cyOffset;
}

s32 Menu_GetPxOffset(Menu* menu, u8 inherit) {
    s32 pxOffset = menu->pxOffset;

    if (inherit && menu->parent) {
        pxOffset += Menu_GetPxOffset(menu->parent, 1);
    }

    return pxOffset;
}

void Menu_SetPxOffset(Menu* menu, s32 pxOffset) {
    menu->pxOffset = pxOffset;
}

s32 Menu_GetPyOffset(Menu* menu, u8 inherit) {
    s32 pyOffset = menu->pyOffset;

    if (inherit && menu->parent) {
        pyOffset += Menu_GetPyOffset(menu->parent, 1);
    }

    return pyOffset;
}

void Menu_SetPyOffset(Menu* menu, s32 pyOffset) {
    menu->pyOffset = pyOffset;
}

s32 Menu_GetCellWidth(Menu* menu, u8 inherit) {
    if (inherit && menu->parent && menu->cellWidth == MENU_NOVALUE) {
        return Menu_GetCellWidth(menu->parent, 1);
    }

    return menu->cellWidth;
}

void Menu_SetCellWidth(Menu* menu, s32 cellWidth) {
    menu->cellWidth = cellWidth;
}

s32 Menu_GetCellHeight(Menu* menu, u8 inherit) {
    if (inherit && menu->parent && menu->cellHeight == MENU_NOVALUE) {
        return Menu_GetCellHeight(menu->parent, 1);
    }

    return menu->cellHeight;
}

void Menu_SetCellHeight(Menu* menu, s32 cellHeight) {
    menu->cellHeight = cellHeight;
}

GfxFont* Menu_GetFont(Menu* menu, u8 inherit) {
    if (inherit  && menu->parent && menu->font == MENU_NOVALUE) {
        return Menu_GetFont(menu->parent, 1);
    }

    return menu->font;
}

void Menu_SetFont(Menu* menu, GfxFont* font) {
    menu->font = font;
}

f32 Menu_GetAlpha(Menu* menu, u8 inherit) {
    f32 alpha = menu->alpha;

    if (inherit && menu->parent) {
        alpha *= Menu_GetAlpha(menu->parent, 1);
    }

    return alpha;
}

u8 Menu_GetAlphaI(Menu* menu, u8 inherit) {
    f32 alpha = Menu_GetAlpha(menu, inherit);

    if (alpha < 0.f) {
        alpha = 0.f;
    } else if (alpha > 1.f)
        alpha = 1.f;
    return alpha * 255;
}

void Menu_SetAlpha(Menu* menu, f32 alpha) {
    menu->alpha = alpha;
}

s32 Menu_CellScreenX(Menu* menu, s32 x) {
    return (x + Menu_GetCxOffset(menu , 1)) * Menu_GetCellWidth(menu, 1) + Menu_GetPxOffset(menu, 1);
}

s32 Menu_CellScreenY(Menu* menu, s32 y) {
    return (y + Menu_GetCyOffset(menu, 1)) * Menu_GetCellHeight(menu, 1) + Menu_GetPyOffset(menu, 1);
}

MenuItem* Menu_GetSelector(Menu* menu) {
    if (menu->child != NULL) {
        return Menu_GetSelector(menu->child);
    }

    return menu->selector;
}

Menu* Menu_GetTop(Menu* menu) {
    if (menu->parent != NULL) {
        return Menu_GetTop(menu->parent);
    }

    return menu;
}

Menu* Menu_GetFront(Menu* menu) {
    if (menu->child != NULL) {
        return Menu_GetFront(menu->child);
    }

    return menu;
}

s32 Menu_Think(Menu* menu) {
    MenuItem* item;

    if (menu->child != NULL) {
        return Menu_Think(menu->child);
    }

    for (item = menu->items.first; item; item = list_next(item)) {
        if (!item->enabled) {
            continue;
        }

        if (item->think && item->think(item)) {
            return 1;
        }

        if (item->imenu && Menu_Think(item->imenu)) {
            return 1;
        }
    }

    return 0;
}

void Menu_Draw(Menu* menu) {
    static MenuDrawParams drawParams = { 0 };
    s32 i;
    GfxFont* font;
    u8 alpha;
    MenuItem* item;
    

    if (menu->child != NULL) {
        Menu_Draw(menu->child);
    }

    for (i = 0; i < 3; ++i) {
        s32 shift = i * 8;
        u32 mask = 0xFF << shift;
        s32 v = (menu->highlightColorAnimated & mask) >> shift;
        v += menu->highlightState[i];

        if (v < 0x00 || v > 0xFF) {
            v = -v + (v > 0xFF ? 2 * 0xFF : 0);
            menu->highlightState[i] = -menu->highlightState[i];
        }

        menu->highlightColorAnimated &= ~mask;
        menu->highlightColorAnimated |= (u32)v << shift;
    }


    font = Menu_GetFont(menu, 1);
    alpha = Menu_GetAlphaI(menu, 1);

    for (item = menu->items.first; item; item = list_next(item)) {
        if (!item->enabled) {
            continue;
        }

        drawParams.x = Menu_ItemScreenX(item);
        drawParams.y = Menu_ItemScreenY(item);
        drawParams.text = item->text;
        drawParams.font = font;
        drawParams.color = (item == menu->selector ? (item->animateHighlight ? menu->highlightColorAnimated : menu->highlightColorStatic) : item->color);
        drawParams.alpha = alpha;

        if (item->draw && item->draw(item, &drawParams)) {
            continue;
        }

        if (item->imenu != NULL) {
            Menu_Draw(item->imenu);
        }

        if (drawParams.text == NULL || drawParams.font == NULL) {
            continue;
        }

        GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams.color, drawParams.alpha));
        Gfx_Printf(drawParams.font, drawParams.x, drawParams.y, "%s", drawParams.text);
    }

}

static void Menu_NavCompare(Menu* menu, MenuItem* selector, s32 navX, s32 navY, MenuItem** nearItem, MenuItem** farItem, s32* npa, s32* fpa, s32* npe, s32* fpe) {
    if (menu->child != NULL) {
        Menu_NavCompare(menu->child, selector, navX, navY, nearItem, farItem, npa, fpa, npe, fpe);
    } else {
        MenuItem* item;
        s32 dx;
        s32 dy;
        s32 dpa;
        s32 dpe;
        s32 selX = selector ? Menu_ItemScreenX(selector) : 0;
        s32 selY = selector ? Menu_ItemScreenY(selector) : 0;

        for (item = menu->items.first; item; item = list_next(item)) {
            if (!item->enabled) {
                continue;
            }

            if (item->imenu != NULL) {
                Menu_NavCompare(item->imenu, selector, navX, navY, nearItem, farItem, npa, fpa, npe, fpe);
            }

            if (item == menu->selector || !item->selectable) {
                continue;
            }

            dx = Menu_ItemScreenX(item) - selX;
            dy = Menu_ItemScreenY(item) - selY;
            dpa = (navX ? dx * navX : dy * navY);
            dpe = (navY ? dx : dy);

            if (dpe < 0) {
                dpe = -dpe;
            }

            if (dpa > 0 && (*nearItem == NULL || dpe < *npe || (dpe == *npe && dpa < *npa))) {
                *npa = dpa;
                *npe = dpe;
                *nearItem = item;
            }

            if (dpa < 0 && (*farItem == NULL || -dpa > *fpa || (-dpa == *fpa && dpe < *fpe))) {
                *fpa = -dpa;
                *fpe = dpe;
                *farItem = item;
            }


        }
    }
}

void Menu_Navigate(Menu* menu, MenuNavigation nav) {
    s32 navX;
    s32 navY;
    s32 npa;
    s32 fpa;
    s32 npe;
    s32 fpe;
    MenuItem* nearItem;
    MenuItem* farItem;

    if (menu->child != NULL) {
        Menu_Navigate(menu->child, nav);
    }

    if (menu->selector != NULL && menu->selector->navigate && menu->selector->navigate(menu->selector, nav)) {
        return;
    }

    navX = (nav == MENU_NAVIGATE_LEFT ? -1 : (nav == MENU_NAVIGATE_RIGHT ? 1 : 0));
    navY = (nav == MENU_NAVIGATE_UP ? -1 : (nav == MENU_NAVIGATE_DOWN ? 1 : 0));

    if (navX == 0 && navY == 0) {
        return;
    }

    npa = 0;
    fpa = 0;
    npe = 0;
    fpe = 0;
    nearItem = NULL;
    farItem = NULL;

    Menu_NavCompare(menu, menu->selector, navX, navY, &nearItem, &farItem, &npa, &fpa, &npe, &fpe);

    if (nearItem) {
        Menu_Select(menu, nearItem);
    } else if (farItem) {
        Menu_Select(menu, farItem);
    }
}

void Menu_Activate(Menu* menu) {
    if (menu->child != NULL) {
         Menu_Activate(menu->child);
    }

    if (menu->selector != NULL && menu->selector->activate) {
        menu->selector->activate(menu->selector);
    }
}

void Menu_Enter(Menu* menu, Menu* submenu) {
    if (menu->child != NULL) {
        Menu_Enter(menu->child, submenu);
    }

    Menu_SignalLeave(menu, MENU_SWITCH_ENTER);
    menu->child = submenu;
    submenu->parent = menu;
    Menu_SignalEnter(submenu, MENU_SWITCH_ENTER);
}

Menu* Menu_Return(Menu* menu) {
    Menu* parent;

    if (menu->child != NULL) {
        return Menu_Return(menu->child);
    }

    parent = menu->parent;
    
    if (parent == NULL || parent->child != menu) {
        return NULL;
    }

    Menu_SignalLeave(menu, MENU_SWITCH_RETURN);
    menu->parent = NULL;
    parent->child = NULL;
    Menu_SignalEnter(parent, MENU_SWITCH_RETURN);
    return parent;
}

void Menu_Select(Menu* menu, MenuItem* item) {
    if (menu->child != NULL) {
        Menu_Select(menu->child, item);
    }

    if (menu->selector != NULL) {
        menu->selector->owner->selector = NULL;
    }

    menu->selector = item;
    item->owner->selector = item;
}

void Menu_SignalEnter(Menu* menu, MenuSwitchReason reason) {
    MenuItem* item;

    if (menu->child != NULL) {
        Menu_SignalEnter(menu->child, reason);
    }

    for (item = menu->items.first; item; item = list_next(item)) {
        if (item->entry && item->entry(item, reason)) {
            continue;
        }

        if (item->imenu != NULL) {
            Menu_SignalEnter(item->imenu, reason);
        }
    }

}

void Menu_SignalLeave(Menu* menu, MenuSwitchReason reason) {
    MenuItem* item;

    if (menu->child != NULL) {
        Menu_SignalLeave(menu->child, reason);
    }

    for (item = menu->items.first; item; item = list_next(item)) {
        if (item->leave && item->leave(item, reason)) {
            continue;
        }

        if (item->imenu != NULL) {
            Menu_SignalLeave(item->imenu, reason);
        }
    }
}

void Menu_NavigateTop(Menu* menu, MenuNavigation nav) {
    if (menu->parent != NULL) {
        Menu_NavigateTop(menu->parent, nav);
    }

    Menu_Navigate(menu, nav);
}

void Menu_ActivateTop(Menu* menu) {
    if (menu->parent != NULL) {
        Menu_ActivateTop(menu->parent);
    }

    Menu_Activate(menu);
}

void Menu_EnterTop(Menu* menu, Menu* submenu) {
    if (menu->parent != NULL) {
        Menu_EnterTop(menu->parent, submenu);
    }

    Menu_Enter(menu, submenu);
}

Menu* Menu_ReturnTop(Menu* menu) {
    if (menu->parent != NULL) {
        return Menu_ReturnTop(menu->parent);
    }

    return Menu_Return(menu);
}

void Menu_SelectTop(Menu* menu, MenuItem* item) {
    if (menu->parent != NULL) {
        Menu_SelectTop(menu->parent, item);
    }

    Menu_Select(menu, item);
}

MenuItem* Menu_ItemAdd(Menu* menu, s32 x, s32 y, const char* text, u32 color) {
    MenuItem* item = list_push_back(&menu->items, NULL);

    if (item != NULL) {
        item->owner = menu;
        item->enabled = true;
        item->x = x;
        item->y = y;
        item->pxOffset = 0;
        item->pyOffset = 0;

        if (text != NULL) {
            item->text = DebugArena_MallocDebug(strlen(text) + 1, __FILE__, __LINE__);
            strcpy(item->text, text);
        } else {
            item->text = NULL;
        }
            item->tooltip = NULL;
            item->color = color;
            item->animateHighlight = 0;
            item->data = NULL;
            item->selectable = true;
            item->imenu = NULL;
            item->entry = NULL;
            item->leave = NULL;
            item->think = NULL;
            item->draw = NULL;
            item->navigate = NULL;
            item->activate = NULL;
            item->destroy = NULL;
    }

    return item;
}

static void Menu_Deselect(Menu* menu, MenuItem* item) {
    if (menu->selector == item) {
        menu->selector = NULL;
    }

    if (menu->parent != NULL && menu->parent->child != menu) {
        Menu_Deselect(menu->parent, item);
    }
}

void Menu_ItemEnable(MenuItem* item) {
    item->enabled = true;
}

void Menu_ItemDisable(MenuItem* item) {
    item->enabled = false;
    Menu_Deselect(item->owner, item);
}

void Menu_ItemTransfer(MenuItem* item, Menu* menu) {
    if (menu == item->owner) {
        return;
    }

    Menu_Deselect(item->owner, item);
    list_transfer(&menu->items, NULL, &item->owner->items, item);
    item->owner = menu;
}

void Menu_ItemRemove(MenuItem* item) {
    if (item->destroy == NULL || item->destroy(item) == 0) {
        if (item->imenu != NULL) {
            Menu_Destroy(item->imenu);
            DebugArena_FreeDebug(item->imenu, __FILE__, __LINE__);
        }

        if (item->text != NULL) {
            DebugArena_FreeDebug(item->text, __FILE__, __LINE__);
        }
    
        if (item->data != NULL) {
            DebugArena_FreeDebug(item->data, __FILE__, __LINE__);
        }
    }

    Menu_Deselect(item->owner, item);
    list_erase(&item->owner->items, item);
}

s32 Menu_ItemScreenX(MenuItem* item) {
    return Menu_CellScreenX(item->owner, item->x) + item->pxOffset;
}

s32 Menu_ItemScreenY(MenuItem* item) {
    return Menu_CellScreenY(item->owner, item->y) + item->pyOffset;
}