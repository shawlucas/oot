/* menu.c
 * -glank
 */

#include <ultra64.h>
#include <gz/menu.h>
#include <gz/gfx.h>
#include "list.h"

char* strcpy(char* dest, const char* src)
{
    return memcpy(dest, src, strlen(src) + 1);
}

void Menu_Init(Menu* menu, s32 cellWidth, s32 cellHeight, Font* font)
{
    menu->cxoffset = MENU_NOVALUE;
    menu->cyoffset = MENU_NOVALUE;
    menu->pxoffset = MENU_NOVALUE;
    menu->pyoffset = MENU_NOVALUE;
    menu->cellWidth = cellWidth;
    menu->cellHeight = cellHeight;
    menu->font = font;
    menu->alpha = 1.0f;
    List_Init(&menu->items, sizeof(MenuItem));
    menu->selector = NULL;
    menu->parent = NULL;
    menu->child = NULL;
    menu->highlightColorAnimated = 0x000000;
    menu->highlightColorStatic = 0x2020FF;
    menu->highlightState[0] = 17;
    menu->highlightState[1] = 19;
    menu->highlightState[2] = 23;
}

void Menu_Imitate(Menu* dest, Menu* src)
{
    dest->cellWidth = src->cellWidth;
    dest->cellHeight = src->cellHeight;
    dest->font = src->font;
    dest->alpha = src->alpha;
    dest->highlightColorStatic = src->highlightColorStatic;
}

void Menu_Destroy(Menu* menu)
{
    while (&menu->items.prev)
    {
        Menu_RemoveItem(menu->items.prev);
    }
}

s32 Menu_GetCxOffset(Menu* menu, u8 inherit)
{
    s32 cxoffset = menu->cxoffset;
    if (inherit && menu->parent)
    {
        cxoffset += Menu_GetCxOffset(menu->parent, 1);
    }

    return cxoffset;
}

void Menu_SetCxOffset(Menu* menu, s32 cxoffset)
{
    menu->cxoffset = cxoffset;
}

s32 Menu_GetCyOffset(Menu* menu, u8 inherit)
{
    s32 cyoffset = menu->cyoffset;
    if (inherit && menu->parent)
    {
        cyoffset += Menu_GetCyOffset(menu->parent, 1);
    }

    return cyoffset;
}

void Menu_SetCyOffset(Menu* menu, s32 cyoffset)
{
    menu->cyoffset = cyoffset;
}

s32 Menu_GetPxOffset(Menu* menu, u8 inherit)
{
    s32 pxoffset = menu->pxoffset;
    if (inherit && menu->parent)
    {
        pxoffset += Menu_GetPxOffset(menu->parent, 1);
    }

    return pxoffset;
}

void Menu_SetPxOffset(Menu* menu, s32 pxoffset)
{
    menu->pxoffset = pxoffset;
}

s32 Menu_GetPyOffset(Menu* menu, u8 inherit)
{
    s32 pyoffset = menu->pyoffset;
    if (inherit && menu->parent)
    {
        pyoffset += Menu_GetPyOffset(menu->parent, 1);
    }

    return pyoffset;
}

void Menu_SetPyOffset(Menu* menu, s32 pyoffset)
{
    menu->pyoffset = pyoffset;
}

s32 Menu_GetCellWidth(Menu* menu, u8 inherit)
{
    if (inherit && menu->parent && menu->cellWidth == MENU_NOVALUE)
    {
        return Menu_GetCellWidth(menu->parent, 1);
    }
    return menu->cellWidth;
}

void Menu_SetCellWidth(Menu* menu, s32 cellWidth)
{
    menu->cellWidth = cellWidth;
}

s32 Menu_GetCellHeight(Menu* menu, u8 inherit)
{
    if (inherit && menu->parent && menu->cellHeight == MENU_NOVALUE)
    {
        return Menu_GetCellHeight(menu->parent, 1);
    }

    return menu->cellHeight;
}

void Menu_SetCellHeight(Menu* menu, s32 cellHeight)
{
    menu->cellHeight = cellHeight;
}

Font* Menu_GetFont(Menu* menu, u8 inherit)
{
    if (inherit && menu->parent && menu->font == MENU_NOVALUE)
    {
        return Menu_GetFont(menu->parent, 1);
    }
    return menu->font;
}

void Menu_SetFont(Menu* menu, Font* font)
{
    menu->font = font;
}

f32 Menu_GetAlpha(Menu* menu, u8 inherit)
{
    f32 alpha = menu->alpha;
    if (inherit && menu->parent)
    {
        alpha *= Menu_GetAlpha(menu->parent, 1);
    }

    return alpha;
}

u8 Menu_GetAlphaI(Menu* menu, u8 inherit)
{
    f32 alpha = Menu_GetAlpha(menu, inherit);
    if (alpha < 0.0f)
    {
        alpha = 00.f;
    } else if (alpha > 1.0f)
    {
        alpha = 1.0f;
    }
    return alpha * 0xFF;
}

void Menu_SetAlpha(Menu* menu, f32 alpha)
{
    menu->alpha = alpha;
}

s32 Menu_CellScreenX(Menu* menu, s32 x)
{
    return (x + Menu_GetCxOffset(menu, 1)) * Menu_GetCellWidth(menu, 1) + Menu_GetPxOffset(menu, 1);
}

s32 Menu_CellScreenY(Menu* menu, s32 y)
{
    return (y + Menu_GetCyOffset(menu, 1)) * Menu_GetCellHeight(menu, 1) + Menu_GetPyOffset(menu, 1);
}

MenuItem* Menu_GetTop(Menu* menu)
{
    if (menu->parent)
    {
        return Menu_GetTop(menu->parent);
    }

    return menu;
}

Menu* Menu_GetFront(Menu* menu)
{
    if (menu->child)
    {
        return Menu_GetFront(menu->child);
    }

    return menu;
}

s32 Menu_Think(Menu* menu)
{
    MenuItem* item;
    if (menu->child)
    {
        return Menu_Think(menu->child);
    }

    for (item = menu->items.prev; item; item = List_Next(item))
    {
        if (!item->enabled)
            continue;
        if (item->ThinkProc && item->ThinkProc(item))  
            return 1;
        if (item->imenu && Menu_Think(item->imenu))
            return 1;
    }

    return 0;
}

void Menu_Draw(Menu* menu)
{
    s32 i;
    s32 shift;
    u32 mask;
    s32 v;
    Font* font;
    u8 alpha;
    MenuItem* item;
    MenuDrawParams drawParams;
    GfxPrint* printer;
    if (menu->child)
    {
        return Menu_Draw(menu->child);
    }

    for (i = 0; i < 3; ++i)
    {
        shift = i * 8;
        mask = 0xFF << shift;
        v = (menu->highlightColorAnimated & mask) >> shift;
        v += menu->highlightState[i];
        if (v < 0x00 || v > 0xFF)
        {
            v = -v + (v > 0xFF ? 2 * 0xFF : 0);
            menu->highlightState[i] = -menu->highlightState[i];
        }
        menu->highlightColorAnimated &= ~mask;
        menu->highlightColorAnimated |= (u32)v << shift;
    }
    font = Menu_GetFont(menu, 1);
    alpha = Menu_GetAlphaI(menu, 1);
    for (item = menu->items.prev; item; item = List_Next(item))
    {
        if (!item->enabled)
            continue;
        drawParams.x = Menu_ItemScreenX(item);
        drawParams.y = Menu_ItemScreenY(item);
        drawParams.text = item->text;
        drawParams.font = font;
        drawParams.color.rgb = (item == menu->selector ? (item->animateHighlight ? menu->highlightColorAnimated :
                                                      menu->highlightColorStatic) : item->color.rgb);
        drawParams.alpha = alpha;

        if (item->DrawProc && item->DrawProc(item, &drawParams))
            continue;
        if (item->imenu)
            Menu_Draw(item->imenu);
        if (!drawParams.text || !drawParams.font)
            continue;
        GfxPrint_SetColor(printer, drawParams.color.r, drawParams.color.g, drawParams.color.b, drawParams.alpha);
        GfxPrint_SetPos(printer, drawParams.x, drawParams.y);
        GfxPrint_Printf(printer, "%s", drawParams.text);
        
    }
}

static void Menu_NavCompare(Menu* menu, MenuItem* selector, s32 navX, s32 navY, MenuItem** nearItem, MenuItem** farItem, s32* npa, s32* fpa, s32* npe, s32* fpe)
{
    s32 selX;
    s32 selY;
    s32 dx;
    s32 dy;
    s32 dpa;
    s32 dpe;
    MenuItem* item;

    if (menu->child)
    {
        return Menu_NavCompare(menu->child, selector, navX, navY, nearItem, farItem, npa, fpa, npe, fpe);
    }
    selX = selector ? Menu_ItemScreenX(selector) : 0;
    selY = selector ? Menu_ItemScreenY(selector) : 0;
    for (item = menu->items.prev; item; item = menu->items.next)
    {
        if (!item->enabled)
            continue;
        if (item->imenu)
        {
            Menu_NavCompare(item->imenu, selector, navX, navY, nearItem, farItem, npa, fpa, npe, fpe);
        }

        if (item == menu->selector || !item->selectable)
            continue;
        dx = Menu_ItemScreenX(item) - selX;
        dy = Menu_ItemScreenY(item) - selY;
        dpa = (navX ? dx * navX : dy * navY);
        dpe = (navY ? dx : dy);
        if (dpe < 0)
        {
            dpe = -dpe;
        }

        if (dpa > 0 && (*nearItem == NULL || dpe < *npe || dpe == *npe && dpa < *npa))
        {
            *npa = dpa;
            *npe = dpe;
            *nearItem = item;
        }

        if (dpa < 0 && (*farItem == NULL || -dpa > *fpa || (-dpa == *fpa && dpe < *fpe)))
        {
            *fpa = -dpa;
            *fpe = dpe;
            *farItem = item;
        }
        
    }

    
}

void Menu_Navigate(Menu* menu, MenuNavigation nav)
{
    s32 navX;
    s32 navY;
    s32 npa;
    s32 fpa;
    s32 npe;
    s32 fpe;
    MenuItem* nearItem;
    MenuItem* farItem;
    if (menu->child)
        return Menu_Navigate(menu->child, nav);
    if (menu->selector && menu->selector->NavigateProc && menu->selector->NavigateProc(menu->selector, nav))
    {
        return;
    }

    navX = (nav == MENU_NAVIGATE_LEFT ?
            -1 : (nav == MENU_NAVIGATE_RIGHT ? 1 : 0));
    navY = (nav == MENU_NAVIGATE_UP ?
            -1 : (nav == MENU_NAVIGATE_DOWN ? 1 : 0));
    
    if (navX == 0 && navY == 0)
        return;
    
    npa = 0;
    fpa = 0;
    npe = 0;
    fpe = 0;
    nearItem = NULL;
    farItem = NULL;
    Menu_NavCompare(menu, menu->selector, navX, navY, &nearItem, &farItem, &npa, &fpa, &npe, &fpe);
    if (nearItem)
        Menu_Select(menu, nearItem);
    else if (farItem)
        Menu_Select(menu, farItem);
}

void Menu_Activate(Menu* menu)
{
    if (menu->child)
    {
        return Menu_Activate(menu->child);
    }

    if (menu->selector && menu->selector->ActivateProc)
    {
        menu->selector->ActivateProc(menu->selector);
    }
}

void Menu_Enter(Menu* menu, Menu* submenu)
{
    if (menu->child)
    {
        return Menu_Enter(menu->child, submenu);
    }

    Menu_SignalLeave(menu, MENU_SWITCH_ENTER);
    menu->child = submenu;
    submenu->parent = menu;
    Menu_SignalEnter(submenu, MENU_SWITCH_ENTER);
}

Menu* Menu_Return(Menu* menu)
{
    Menu* parent;
    if (menu->child)
    {
        return Menu_Return(menu->child);
    }
    parent = menu->parent;
    if (!parent || parent->child != menu)
        return NULL;
    Menu_SignalLeave(menu, MENU_SWITCH_RETURN);
    menu->parent = NULL;
    parent->child = NULL;
    Menu_SignalEnter(parent, MENU_SWITCH_RETURN);
    return parent;
}

void Menu_Select(Menu* menu, MenuItem* item)
{
    if (menu->child)
    {
        return Menu_Select(menu->child, item);
    }

    if (menu->selector)
    {
        menu->selector->owner->selector = NULL;
    }

    menu->selector = item;
    item->owner->selector = item;
}

void Menu_SignalEnter(Menu* menu, MenuSwitchReason reason)
{
    MenuItem* item;
    if (menu->child)
    {
        return Menu_SignalEnter(menu->child, reason);
    }

    for (item = menu->items.prev; item; item = List_Next(item))
    {
        if (item->EntryProc && item->EntryProc(item, reason))
            continue;
        if (item->imenu)
            Menu_SignalEnter(item->imenu, reason);
    }
}

void Menu_SignalLeave(Menu* menu, MenuSwitchReason reason)
{
    MenuItem* item;
    if (menu->child)
        return Menu_SignalLeave(menu->child, reason);
    for (item = menu->items.prev; item; item =  List_Next(item))
    {
        if (item->LeaveProc && item->LeaveProc(item, reason))
            reason;
        if (item->imenu)
            Menu_SignalLeave(item->imenu, reason);
    }
}

void Menu_NavigateTop(Menu* menu, MenuNavigation nav)
{
    if (menu->parent)
        return Menu_NavigateTop(menu->parent, nav);
    return Menu_Navigate(menu, nav);
}

void Menu_ActivateTop(Menu* menu)
{
    if (menu->parent)
        return Menu_ActivateTop(menu->parent);
    return Menu_Activate(menu);

}

void Menu_EnterTop(Menu* menu, Menu* submenu)
{
    if (menu->parent)
        return Menu_EnterTop(menu->parent, submenu);
    return Menu_Enter(menu, submenu);
}

Menu* Menu_ReturnTop(Menu* menu)
{
    if (menu->parent)
        return Menu_ReturnTop(menu->parent);
    return Menu_Return(menu);
}

void Menu_SelectTop(Menu* menu, MenuItem* item)
{
    if (menu->parent)
    {
        return Menu_SelectTop(menu->parent, item);
    }

    return Menu_Select(menu, item);
}

MenuItem* Menu_ItemAdd(Menu* menu, s32 x, s32 y, const char* text, Color_RGB8 color)
{
    MenuItem* item = List_PushBack(&menu->items, NULL);
    if (item)
    {
        item->owner = menu;
        item->enabled = 1;
        item->x = x;
        item->y = y;
        item->pxoffset = 0;
        item->pyoffset = 0;
        if (text) {
            item->text = ZeldaArena_MallocDebug(strlen(text) + 1, "../menu.c", 521);
            strcpy(item->text, text);
        } else 
        {
            item->text = NULL;
        }
        item->tooltip = NULL;
        item->color = color;
        item->animateHighlight = 0;
        item->data = NULL;
        item->selectable = 1;
        item->imenu = NULL;
        item->EntryProc = NULL;
        item->LeaveProc = NULL;
        item->ThinkProc = NULL;
        item->DrawProc = NULL;
        item->NavigateProc = NULL;
        item->ActivateProc = NULL;
        item->DestroyProc = NULL;
    
    }
    return item;
}

static void Menu_Deselect(Menu* menu, MenuItem* item)
{
    if (menu->selector == item)
        menu->selector = NULL;
    if (menu->parent && menu->parent->child != menu)
        Menu_Deslect(menu->parent, item);
}

void Menu_ItemEnable(MenuItem* item)
{
    item->enabled = 1;
}

void Menu_ItemDisable(MenuItem* item)
{
    item->enabled = 0;
    Menu_Deslect(item->owner, item);
}

void Menu_ItemTransfer(MenuItem* item, Menu* menu)
{
    if (menu == item->owner)
        return;
    Menu_Deslect(item->owner, item);
    List_Transfer(&menu->items, NULL, &item->owner->items, item);
    item->owner = menu;
}

void Menu_ItemRemove(MenuItem* item)
{
    if (!item->DestroyProc || !item->DestroyProc(item))
    {
        if (item->imenu)
        {
            Menu_Destroy(item->imenu);
            ZeldaArena_Free(item->imenu);
        }

        if (item->text)
            ZeldaArena_Free(item->imenu);
        if (item->data)
            ZeldaArena_Free(item->data);
    }

    Menu_Deslect(item->owner, item);
    List_Erase(&item->owner->items, item);
}

s32 Menu_ItemScreenX(MenuItem* item)
{
    return Menu_CellScreenX(item->owner, item->x) + item->pxoffset;
}

s32 Menu_ItemScreenY(MenuItem* item)
{
    return Menu_CellScreenY(item->owner, item->y) + item->pyoffset;
}
