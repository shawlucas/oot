#include <ultra64.h>
#include <global.h>
#include "menu.h"

void Menu_Init(Menu *menu, s32 cellWidth, s32 cellHeight,
               GfxPrint* printer)
{
  menu->cxoffset = MENU_NOVALUE;
  menu->cyoffset = MENU_NOVALUE;
  menu->pxoffset = MENU_NOVALUE;
  menu->pyoffset = MENU_NOVALUE;
  menu->cellWidth = cellWidth;
  menu->cellHeight = cellHeight;
  menu->printer = printer;
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

void Menu_Imitate(Menu* dest, Menu* src)
{
  dest->cellWidth = src->cellWidth;
  dest->cellHeight = src->cellHeight;
  dest->printer = src->printer;
  dest->alpha = src->alpha;
  dest->highlightColorStatic = src->highlightColorStatic;
}

void Menu_Destroy(Menu* menu)
{
  while (menu->items.first)
    MenuItem_Remove(menu->items.first);
}

s32 Menu_GetCxOffset(Menu *menu, u8 inherit)
{
  s32 cxoffset = menu->cxoffset;
  if (inherit && menu->parent)
    cxoffset += Menu_GetCxOffset(menu->parent, 1);
  return cxoffset;
}

void Menu_SetCxOffset(Menu *menu, s32 cxoffset)
{
  menu->cxoffset = cxoffset;
}

s32 Menu_GetCyOffset(Menu *menu, u8 inherit)
{
  s32 cyoffset = menu->cyoffset;
  if (inherit && menu->parent)
    cyoffset += Menu_GetCyOffset(menu->parent, 1);
  return cyoffset;
}

void Menu_SetCyOffset(Menu *menu, s32 cyoffset)
{
  menu->cyoffset = cyoffset;
}

s32 Menu_GetPxOffset(Menu *menu, u8 inherit)
{
  s32 pxoffset = menu->pxoffset;
  if (inherit && menu->parent)
    pxoffset += Menu_GetPxOffset(menu->parent, 1);
  return pxoffset;
}

void Menu_SetPxOffset(Menu *menu, s32 pxoffset)
{
  menu->pxoffset = pxoffset;
}

s32 Menu_GetPyOffset(Menu *menu, u8 inherit)
{
  s32 pyoffset = menu->pyoffset;
  if (inherit && menu->parent)
    pyoffset += Menu_GetPyOffset(menu->parent, 1);
  return pyoffset;
}

void Menu_SetPyOffset(Menu *menu, s32 pyoffset)
{
  menu->pyoffset = pyoffset;
}

s32 Menu_GetCellWidth(Menu *menu, u8 inherit)
{
  if (inherit && menu->parent && menu->cellWidth == MENU_NOVALUE)
    return Menu_GetCellWidth(menu->parent, 1);
  return menu->cellWidth;
}

void Menu_SetCellWidth(Menu *menu, s32 cellWidth)
{
  menu->cellWidth = cellWidth;
}

s32 Menu_GetCellHeight(Menu *menu, u8 inherit)
{
  if (inherit && menu->parent && menu->cellHeight == MENU_NOVALUE)
    return Menu_GetCellHeight(menu->parent, 1);
  return menu->cellHeight;
}

void Menu_SetCellHeight(Menu *menu, s32 cellHeight)
{
  menu->cellHeight = cellHeight;
}

GfxPrint* Menu_GetPrinter(Menu *menu, u8 inherit)
{
  if (inherit && menu->parent && menu->printer == MENU_NOVALUE)
    return Menu_GetPrinter(menu->parent, 1);
  return menu->printer;
}

void Menu_SetPrinter(Menu *menu, GfxPrint* printer)
{
  menu->printer = printer;
}

f32 Menu_GetAlpha(Menu *menu, u8 inherit)
{
  f32 alpha = menu->alpha;
  if (inherit && menu->parent)
    alpha *= Menu_GetAlpha(menu->parent, 1);
  return alpha;
}

u8 Menu_GetAlpha_i(Menu *menu, u8 inherit)
{
  f32 alpha = Menu_GetAlpha(menu, inherit);
  if (alpha < 0.f)
    alpha = 0.f;
  else if (alpha > 1.f)
    alpha = 1.f;
  return alpha * 0xFF;
}

void Menu_SetAlpha(Menu *menu, f32 alpha)
{
  menu->alpha = alpha;
}

s32 Menu_CellScreenX(Menu *menu, s32 x)
{
  return (x + Menu_GetCxOffset(menu, 1)) * Menu_GetCellWidth(menu, 1) +
         Menu_GetPxOffset(menu, 1);
}

s32 Menu_CellScreenY(Menu *menu, s32 y)
{
  return (y + Menu_GetCyOffset(menu, 1)) * Menu_GetCellHeight(menu, 1) +
         Menu_GetPyOffset(menu, 1);
}

MenuItem *Menu_GetSelector(Menu *menu)
{
  if (menu->child)
    return Menu_GetSelector(menu->child);
  return menu->selector;
}

Menu *Menu_GetTop(Menu *menu)
{
  if (menu->parent)
    return Menu_GetTop(menu->parent);
  return menu;
}

Menu *Menu_GetFront(Menu *menu)
{
  if (menu->child)
    return Menu_GetFront(menu->child);
  return menu;
}

s32 Menu_Think(Menu *menu)
{
    MenuItem* item;
  if (menu->child)
    return Menu_Think(menu->child);
  for (item = menu->items.first;
       item; item = list_next(item))
  {
    if (!item->enabled)
      continue;
    if (item->think && item->think(item))
      return 1;
    if (item->imenu && Menu_Think(item->imenu))
      return 1;
  }
  return 0;
}

void Menu_Draw(Menu *menu)
{
    s32 i;
    GfxPrint* printer;
    u8 alpha;
    MenuItem* item;
    MenuDrawParams drawParams;
  if (menu->child)
    Menu_Draw(menu->child);
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
  printer = Menu_GetPrinter(menu, 1);
    alpha = Menu_GetAlpha_i(menu, 1);
  for (item = menu->items.first;
       item; item = list_next(item))
  {
    if (!item->enabled)
      continue;

    drawParams.x = MenuItem_ScreenX(item);
    drawParams.y = MenuItem_ScreenY(item);
    drawParams.text = item->text;
    drawParams.printer = printer;
    drawParams.color = (item == menu->selector ? (item->animateHighlight ?
                                 menu->highlightColorAnimated :
                                 menu->highlightColorStatic) : item->color);
    drawParams.alpha = alpha;

    if (item->draw && item->draw(item, &drawParams))
      continue;
    if (item->imenu)
      Menu_Draw(item->imenu);
    if (!drawParams.text || !drawParams.printer)
      continue;
    GfxPrint_SetColor(drawParams.printer, (drawParams.color >> 16) & 0xFF, (drawParams.color >> 8) & 0xFF, drawParams.color >> 0 & 0xFF, drawParams.alpha);
    GfxPrint_SetPos(printer, drawParams.x, drawParams.y);
    GfxPrint_Printf(drawParams.printer, "%s", drawParams.text);
  }
}

static void Menu_NavCompare(Menu *menu,
                             MenuItem *selector,
                             s32 navX, s32 navY,
                             MenuItem **nearItem,
                             MenuItem **farItem,
                             s32 *npa, s32 *fpa, s32 *npe, s32 *fpe)
{
    MenuItem* item;
    s32 selX;
    s32 selY;
    s32 dx;
    s32 dy;
    s32 dpa;
    s32 dpe;
  if (menu->child)
    Menu_NavCompare(menu->child, selector, navX, navY,
                            nearItem, farItem, npa, fpa, npe, fpe);
  selX = selector ? MenuItem_ScreenX(selector) : 0;
  selY = selector ? MenuItem_ScreenY(selector) : 0;
  for (item = menu->items.first;
       item; item = list_next(item))
  {
    if (!item->enabled)
      continue;
    if (item->imenu)
      Menu_NavCompare(item->imenu, selector, navX, navY,
                       nearItem, farItem, npa, fpa, npe, fpe);
    if (item == menu->selector || !item->selectable)
      continue;
    dx = MenuItem_ScreenX(item) - selX;
    dy = MenuItem_ScreenY(item) - selY;
    dpa = (navX ? dx * navX : dy * navY);
    dpe = (navY ? dx : dy);
    if (dpe < 0)
      dpe = -dpe;
    if (dpa > 0 && (*nearItem == NULL || dpe < *npe ||
                            (dpe == *npe && dpa < *npa)))
    {
      *npa = dpa;
      *npe = dpe;
      *nearItem = item;
    }
    if (dpa < 0 && (*farItem == NULL || -dpa > *fpa ||
                            (-dpa == *fpa && dpe < *fpe)))
    {
      *fpa = -dpa;
      *fpe = dpe;
      *farItem = item;
    }
  }
}

void Menu_Navigate(struct Menu *menu, MenuNavigation nav)
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
    Menu_Navigate(menu->child, nav);
  if (menu->selector && menu->selector->navigate &&
      menu->selector->navigate(menu->selector, nav))
    return;
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
  Menu_NavCompare(menu, menu->selector, navX, navY,
                   &nearItem, &farItem, &npa, &fpa, &npe, &fpe);
  if (nearItem)
    Menu_Select(menu, nearItem);
  else if (farItem)
    Menu_Select(menu, farItem);
}

void Menu_Activate(Menu *menu)
{
  if (menu->child)
    Menu_Activate(menu->child);
  if (menu->selector && menu->selector->activate)
    menu->selector->activate(menu->selector);
}

void Menu_Enter(Menu *menu, Menu *submenu)
{
  if (menu->child)
    Menu_Enter(menu->child, submenu);
  Menu_SignalLeave(menu, MENU_SWITCH_ENTER);
  menu->child = submenu;
  submenu->parent = menu;
  Menu_SignalEnter(submenu, MENU_SWITCH_ENTER);
}

Menu *Menu_Return(Menu *menu)
{
    Menu* parent;
  if (menu->child)
    return Menu_Return(menu->child);
  parent = menu->parent;
  if (!parent || parent->child != menu)
    return NULL;
  Menu_SignalLeave(menu, MENU_SWITCH_RETURN);
  menu->parent = NULL;
  parent->child = NULL;
  Menu_SignalEnter(parent, MENU_SWITCH_RETURN);
  return parent;
}

void Menu_Select(Menu *menu, MenuItem *item)
{
  if (menu->child)
    Menu_Select(menu->child, item);
  if (menu->selector)
    menu->selector->owner->selector = NULL;
  menu->selector = item;
  item->owner->selector = item;
}

void Menu_SignalEnter(Menu *menu, MenuSwitchReason reason)
{
  MenuItem* item;
  if (menu->child)
    Menu_SignalEnter(menu->child, reason);
  for (item = menu->items.first;
       item; item = list_next(item))
  {
    if (item->enter && item->enter(item, reason))
      continue;
    if (item->imenu)
      Menu_SignalEnter(item->imenu, reason);
  }
}

void Menu_SignalLeave(Menu *menu, MenuSwitchReason reason)
{
    MenuItem* item;
  if (menu->child)
    Menu_SignalLeave(menu->child, reason);
  for (item = menu->items.first;
       item; item = list_next(item))
  {
    if (item->leave && item->leave(item, reason))
      continue;
    if (item->imenu)
      Menu_SignalLeave(item->imenu, reason);
  }
}

void Menu_NavigateTop(Menu *menu, MenuNavigation nav)
{
  if (menu->parent)
    Menu_NavigateTop(menu->parent, nav);
  Menu_Navigate(menu, nav);
}

void Menu_ActivateTop(Menu *menu)
{
  if (menu->parent)
    Menu_ActivateTop(menu->parent);
  Menu_Activate(menu);
}

void Menu_EnterTop(Menu *menu, Menu *submenu)
{
  if (menu->parent)
    Menu_EnterTop(menu->parent, submenu);
  Menu_Enter(menu, submenu);
}

Menu *Menu_ReturnTop(Menu *menu)
{
  if (menu->parent)
    return Menu_ReturnTop(menu->parent);
  return Menu_Return(menu);
}

void Menu_SelectTop(Menu *menu, MenuItem *item)
{
  if (menu->parent)
    Menu_SelectTop(menu->parent, item);
  Menu_Select(menu, item);
}

MenuItem *MenuItem_Add(Menu *menu, s32 x, s32 y,
                                const char *text, u32 color)
{
  MenuItem *item = list_push_back(&menu->items, NULL);
  if (item) {
    item->owner = menu;
    item->enabled = 1;
    item->x = x;
    item->y = y;
    item->pxoffset = 0;
    item->pyoffset = 0;
    if (text) {
      item->text = malloc(strlen(text) + 1);
      strcpy(item->text, text);
    }
    else
      item->text = NULL;
    item->tooltip = NULL;
    item->color = color;
    item->animateHighlight = 0;
    item->data = NULL;
    item->selectable = 1;
    item->imenu = NULL;
    item->enter = NULL;
    item->leave = NULL;
    item->think = NULL;
    item->draw = NULL;
    item->navigate = NULL;
    item->activate = NULL;
    item->destroy = NULL;
  }
  return item;
}

static void Menu_Deselect(Menu *menu, MenuItem *item)
{
  if (menu->selector == item)
    menu->selector = NULL;
  if (menu->parent && menu->parent->child != menu)
    Menu_Deselect(menu->parent, item);
}

void MenuItem_Enable(MenuItem *item)
{
  item->enabled = 1;
}

void MenuItem_Disable(MenuItem *item)
{
  item->enabled = 0;
  Menu_Deselect(item->owner, item);
}

void MenuItem_Transfer(MenuItem *item, Menu *menu)
{
  if (menu == item->owner)
    return;
  Menu_Deselect(item->owner, item);
  list_transfer(&menu->items, NULL, &item->owner->items, item);
  item->owner = menu;
}

void MenuItem_Remove(MenuItem *item)
{
  if (!item->destroy || !item->destroy(item)) {
    if (item->imenu) {
      Menu_Destroy(item->imenu);
      free(item->imenu);
    }
    if (item->text)
      free(item->text);
    if (item->data)
      free(item->data);
  }
  Menu_Deselect(item->owner, item);
  list_erase(&item->owner->items, item);
}

s32 MenuItem_ScreenX(MenuItem *item)
{
  return Menu_CellScreenX(item->owner, item->x) + item->pxoffset;
}

s32 MenuItem_ScreenY(MenuItem *item)
{
  return Menu_CellScreenY(item->owner, item->y) + item->pyoffset;
}