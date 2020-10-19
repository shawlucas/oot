#ifndef __MENU_H_
#define __MENU_H_

#include <ultra64.h>
#include <list/list.h>

#define MENU_NOVALUE 0

typedef enum
{
  MENU_NAVIGATE_UP,
  MENU_NAVIGATE_DOWN,
  MENU_NAVIGATE_LEFT,
  MENU_NAVIGATE_RIGHT
} MenuNavigation;

typedef enum
{
  MENU_CALLBACK_THINK,
  MENU_CALLBACK_THINK_ACTIVE,
  MENU_CALLBACK_THINK_INACTIVE,
  MENU_CALLBACK_ACTIVATE,
  MENU_CALLBACK_DEACTIVATE,
  MENU_CALLBACK_SWITCH_ON,
  MENU_CALLBACK_SWITCH_OFF,
  MENU_CALLBACK_NAV_UP,
  MENU_CALLBACK_NAV_DOWN,
  MENU_CALLBACK_NAV_LEFT,
  MENU_CALLBACK_NAV_RIGHT,
  MENU_CALLBACK_CHANGED
} MenuCallbackReason;

typedef enum MenuSwitchReason
{
  MENU_SWITCH_ENTER,
  MENU_SWITCH_RETURN,
  MENU_SWITCH_SHOW,
  MENU_SWITCH_HIDE
} MenuSwitchReason;


typedef struct MenuItem
{
  struct Menu      *owner;
  u8             enabled;
  s32               x;
  s32               y;
  s32               pxoffset;
  s32               pyoffset;
  char             *text;
  const char       *tooltip;
  u32               color;
  u8             animateHighlight;
  void             *data;
  u8             selectable;
  struct Menu      *imenu;
  s32             (*enter)   (struct MenuItem *item,
                                   MenuSwitchReason reason);
  s32             (*leave)   (struct MenuItem *item,
                                   MenuSwitchReason reason);
  s32             (*think)   (struct MenuItem *item);
  s32             (*draw)    (struct MenuItem *item,
                                   struct MenuDrawParams *draw_params);
  s32             (*navigate)(struct MenuItem *item,
                                   MenuNavigation nav);
  s32             (*activate)(struct MenuItem *item);
  s32             (*destroy) (struct MenuItem *item);
} MenuItem;

typedef struct Menu
{
  s32               cxoffset;
  s32               cyoffset;
  s32               pxoffset;
  s32               pyoffset;
  s32               cellWidth;
  s32               cellHeight;
  GfxPrint*         printer;
  f32               alpha;
  struct list       items;
  MenuItem   *selector;
  struct Menu       *parent;
  struct Menu       *child;
  u32          highlightColorStatic;
  u32          highlightColorAnimated;
  s32               highlightState[3];
} Menu;

typedef struct
{
  s32               x;
  s32               y;
  const char       *text;
  GfxPrint*         printer;
  u32         color;
  u8           alpha;
} MenuDrawParams;

typedef void (*MenuActionCallback) (MenuItem *item, void *data);

void Menu_SignalEnter(Menu *menu, MenuSwitchReason reason);
void Menu_Select(Menu *menu, MenuItem *item);
void Menu_SignalLeave(Menu *menu, MenuSwitchReason reason);
void MenuItem_Remove(MenuItem *item);
Menu *Menu_Return(Menu *menu);
void Menu_Navigate(struct Menu *menu, MenuNavigation nav);
void Menu_Activate(Menu *menu);
s32 Menu_Think(Menu *menu);
GfxPrint* Menu_GetPrinter(Menu *menu, u8 inherit);
u8 Menu_GetAlpha_i(Menu *menu, u8 inherit);
s32 Menu_GetCellWidth(Menu *menu, u8 inherit);
s32 Menu_GetCellHeight(Menu *menu, u8 inherit);
void Menu_SetCellWidth(Menu *menu, s32 cellWidth);
void Menu_SetCellHeight(Menu *menu, s32 cellHeight);
void Menu_SetPyOffset(Menu *menu, s32 pyoffset);
void Menu_SetPxOffset(Menu *menu, s32 pxoffset);
s32 Menu_GetPyOffset(Menu *menu, u8 inherit);
s32 Menu_GetPxOffset(Menu *menu, u8 inherit);
void Menu_Imitate(Menu* dest, Menu* src);

#endif
