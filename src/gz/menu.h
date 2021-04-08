#ifndef MENU_H
#define MENU_H

#define MENU_NOVALUE 0 

#include <global.h>
#include "../libgz/list.h"
#include "gfx.h"

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

typedef enum
{
  MENU_SWITCH_ENTER,
  MENU_SWITCH_RETURN,
  MENU_SWITCH_SHOW,
  MENU_SWITCH_HIDE
} MenuSwitchReason;

typedef struct
{
  s32               x;
  s32               y;
  const char       *text;
  GfxFont  *font;
  u32          color;
  u8           alpha;
} MenuDrawParams;

typedef struct Menu
{
  s32               cxOfffset;
  s32               cyOffset;
  s32               pxOffset;
  s32               pyOffset;
  s32               cellWidth;
  s32               cellHeight;
  GfxFont  *font;
  f32             alpha;
  struct list       items;
  struct MenuItem *selector;
  struct Menu      *parent;
  struct Menu      *child;
  u32          highlightColorStatic;
  u32          highlightColorAnimated;
  s32               highlightState[3];
} Menu;

typedef struct MenuItem
{
  Menu      *owner;
  u8             enabled;
  s32               x;
  s32               y;
  s32               pxOffset;
  s32               pyOffset;
  char             *text;
  const char       *tooltip;
  u32          color;
  u8             animateHighlight;
  void             *data;
  u8             selectable;
  Menu      *imenu;
  s32             (*entry)   (struct MenuItem *item,
                                   MenuSwitchReason reason);
  s32             (*leave)   (struct MenuItem *item,
                                    MenuSwitchReason reason);
  s32             (*think)   (struct MenuItem *item);
  s32             (*draw)    (struct MenuItem *item,
                                  MenuDrawParams *draw_params);
  s32             (*navigate)(struct MenuItem *item,
                                 MenuNavigation nav);
  s32             (*activate)(struct MenuItem *item);
  s32             (*destroy) (struct MenuItem *item);
} MenuItem;

typedef s32  (*MenuGeneric)(MenuItem *item,
                                MenuCallbackReason reason,
                                      void *data);
typedef void (*MenuAction) (MenuItem *item, void *data);
typedef s32  (*MenuPrompt) (s32 optionIndex, void *data);

typedef enum
{
  WATCH_TYPE_U8,
  WATCH_TYPE_S8,
  WATCH_TYPE_X8,
  WATCH_TYPE_U16,
  WATCH_TYPE_S16,
  WATCH_TYPE_X16,
  WATCH_TYPE_U32,
  WATCH_TYPE_S32,
  WATCH_TYPE_X32,
  WATCH_TYPE_F32,
  WATCH_TYPE_MAX
} WatchType;

void                Menu_Init(Menu* menu,
                              s32 cellWidth, s32 cellHeight,
                              GfxFont *font);
void                Menu_Imitate(Menu *dest, Menu *src);
void                Menu_Destroy(Menu* menu);
s32                 Menu_GetCxOffset(Menu* menu, u8 inherit);
void                Menu_SetCxOffset(Menu* menu, s32 cxOfffset);
s32                 Menu_GetCyOffset(Menu* menu, u8 inherit);
void                Menu_SetCyOffset(Menu* menu, s32 cyOffset);
s32                 Menu_GetPxOffset(Menu* menu, u8 inherit);
void                Menu_SetPxOffset(Menu* menu, s32 pxOffset);
s32                 Menu_GetPyOffset(Menu* menu, u8 inherit);
void                Menu_SetPyOffset(Menu* menu, s32 pyOffset);
s32                 Menu_GetCellWidth(Menu* menu, u8 inherit);
void                Menu_SetCellWidth(Menu* menu, s32 cellWidth);
s32                 Menu_GetCellHeight(Menu* menu, u8 inherit);
void                Menu_SetCellHeight(Menu* menu, s32 cellHeight);
GfxFont    *Menu_GetFont(Menu* menu, u8 inherit);
void                Menu_SetFont(Menu* menu, GfxFont *font);
f32               Menu_GetAlpha(Menu* menu, u8 inherit);
u8             Menu_GetAlphaI(Menu* menu, u8 inherit);
void                Menu_SetAlpha(Menu* menu, f32 alpha);
s32                 Menu_CellScreenX(Menu* menu, s32 cell_x);
s32                 Menu_CellScreenY(Menu* menu, s32 cell_y);
MenuItem   *Menu_GetSelector(Menu* menu);
Menu        *Menu_GetTop(Menu* menu);
Menu        *Menu_GetFront(Menu* menu);
s32                 Menu_Think(Menu* menu);
void                Menu_Draw(Menu* menu);
void                Menu_Navigate(Menu* menu, MenuNavigation nav);
void                Menu_Activate(Menu* menu);
void                Menu_Enter(Menu* menu, Menu *submenu);
Menu        *Menu_Return(Menu* menu);
void                Menu_Select(Menu* menu, MenuItem *item);
void                Menu_SignalEnter(Menu* menu,
                                      MenuSwitchReason reason);
void                Menu_SignalLeave(Menu* menu,
                                      MenuSwitchReason reason);
void                Menu_NavigateTop(Menu* menu,
                                      MenuNavigation nav);
void                Menu_ActivateTop(Menu* menu);
void                Menu_EnterTop(Menu* menu, Menu *submenu);
Menu        *Menu_ReturnTop(Menu* menu);
void                Menu_SelectTop(Menu* menu, MenuItem *item);

MenuItem   *Menu_ItemAdd(Menu* menu, s32 x, s32 y,
                                  const char *text, u32 color);
void                Menu_ItemEnable(MenuItem *item);
void                Menu_ItemDisable(MenuItem *item);
void                Menu_ItemTransfer(MenuItem *item,
                                       Menu* menu);
void                Menu_ItemRemove(MenuItem *item);
s32                 Menu_ItemScreenX(MenuItem *item);
s32                 Menu_ItemScreenY(MenuItem *item);
MenuItem   *Menu_AddStatic(Menu* menu, s32 x, s32 y,
                                    const char *text, u32 color);
MenuItem   *Menu_AddStaticIcon(Menu* menu, s32 x, s32 y,
                                         GfxTexture* texture,
                                         s32 texture_tile,
                                         u32 color, f32 scale);
MenuItem   *Menu_AddStaticCustom(Menu* menu, s32 x, s32 y,
                                           s32 (*draw)
                                           (MenuItem *item,
                                            MenuDrawParams
                                            *draw_params),
                                           const char *text, u32 color);
MenuItem   *Menu_AddTooltip(Menu* menu, s32 x, s32 y,
                                     Menu *tool_menu, u32 color);
MenuItem   *Menu_AddIMenu(Menu* menu, s32 x, s32 y,
                                   Menu **p_imenu);
MenuItem   *Menu_AddTab(Menu* menu, s32 x, s32 y,
                                 Menu *tabs, s32 n_tabs);
void                Menu_TabGoto(MenuItem *item, s32 tab_index);
void                Menu_TabPrevious(MenuItem *item);
void                Menu_TabNext(MenuItem *item);


MenuItem   *Menu_AddIntInput(Menu* menu, s32 x, s32 y,
                                      s32 base, s32 length,
                                      MenuGeneric callback_proc,
                                      void *callback_data);
u32            Menu_GetIntInput(MenuItem *item);
s32             Menu_GetsIntInput(MenuItem *item);
void                Menu_SetIntInput(MenuItem *item, u32 value);
MenuItem   *Menu_AddFloatInput(Menu* menu, s32 x, s32 y,
                                        s32 sig_precis, s32 exp_precis,
                                        MenuGeneric callback_proc,
                                        void *callback_data);
f32               Menu_GetFloatInput(MenuItem *item);
void                Menu_SetFloatInput(MenuItem *item, f32 value);
MenuItem   *Menu_AddStrInput(Menu* menu, s32 x, s32 y,
                                      s32 length,
                                      MenuGeneric callback_proc,
                                      void *callback_data);
void                Menu_GetStrInput(MenuItem *item, char *buf);
void                Menu_SetStrInput(MenuItem *item, const char *str);
MenuItem   *Menu_AddOption(Menu* menu, s32 x, s32 y,
                                    const char *options,
                                    MenuGeneric callback_proc,
                                    void *callback_data);
s32                 Menu_GetOption(MenuItem *item);
void                Menu_SetOption(MenuItem *item,
                                    s32 value);
void                Menu_Prompt(Menu* menu, const char *prompt,
                                const char *options, s32 default_option,
                                MenuPrompt callback_proc,
                                void *callback_data);
MenuItem   *Menu_AddWatch(Menu* menu, s32 x, s32 y,
                                   u32 address, WatchType type);
u32            Menu_GetWatchAddress(MenuItem *item);
void                Menu_SetWatchAddress(MenuItem *item,
                                           u32 address);
WatchType     Menu_GetWatchType(MenuItem *item);
void                Menu_SetWatchType(MenuItem *item,
                                        WatchType type);
MenuItem   *Menu_AddUserwatch(Menu* menu, s32 x, s32 y,
                                       u32 address, WatchType type);
MenuItem   *Menu_UserwatchAddress(MenuItem *item);
MenuItem   *Menu_UserwatchType(MenuItem *item);
MenuItem   *Menu_UserwatchWatch(MenuItem *item);
MenuItem   *Menu_AddSubmenu(Menu* menu, s32 x, s32 y,
                                     Menu *submenu, const char *name);
MenuItem   *Menu_AddSwitch(Menu* menu, s32 x, s32 y,
                                    GfxTexture* texture_on,
                                    s32 texture_tile_on, u32 color_on,
                                    GfxTexture* texture_off,
                                    s32 texture_tile_off, u32 color_off,
                                    f32 scale, u8 disable_shadow,
                                    MenuGeneric callback_proc,
                                    void *callback_data);
void                Menu_SetSwitch(MenuItem *item, u8 state);
u8               Menu_GetSwitch(MenuItem *item);
void                Menu_ToggleSwitch(MenuItem *item);
MenuItem   *Menu_AddButton(Menu* menu, s32 x, s32 y,
                                    const char *name,
                                    MenuAction callback_proc,
                                    void *callback_data);
MenuItem   *Menu_AddButtonIcon(Menu* menu, s32 x, s32 y,
                                         GfxTexture* texture,
                                         s32 texture_tile, u32 color,
                                         MenuAction callback_proc,
                                         void *callback_data);
void                Menu_SetButtonTexture(MenuItem *item,
                                            GfxTexture* texture,
                                            s32 texture_tile);
MenuItem   *Menu_AddPositioning(Menu* menu, s32 x, s32 y,
                                         MenuGeneric callback_proc,
                                         void *callback_data);
MenuItem   *Menu_AddCheckbox(Menu* menu, s32 x, s32 y,
                                      MenuGeneric callback_proc,
                                      void *callback_data);
u8               Menu_GetCheckbox(MenuItem *item);
void                Menu_SetCheckbox(MenuItem *item, u8 state);

#endif
