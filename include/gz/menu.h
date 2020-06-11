#ifndef _MENU_H_
#define _MENU_H_

#include <ultra64.h>
#include <global.h>

struct Menu;
struct MenuItem;

#define MENU_NOVALUE 0

typedef enum 
{
    MENU_NAVIGATE_UP,
    MENU_NAVIGATE_DOWN,
    MENU_NAVIGATE_LEFT,
    MENU_NAVIGATE_RIGHT,
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
  MENU_CALLBACK_CHANGED,
} MenuCallbackReason;


typedef enum
{
  MENU_SWITCH_ENTER,
  MENU_SWITCH_RETURN,
  MENU_SWITCH_SHOW,
  MENU_SWITCH_HIDE,
} MenuSwitchReason;

typedef s32 (*Menu_GenericCallback)(struct MenuItem* item, MenuCallbackReason reason, void* data);
typedef void (*Menu_ActionCallback)(struct MenuItem* item, void* data);
typedef s32 (*Menu_PromptCallback)(s32 optionIndex, void* data);

typedef struct MenuItem
{
    Menu* owner;
    u8 enabled;
    s32 x;
    s32 y;
    s32 pxoffset;
    s32 pyoffset;
    char* text;
    const char* tooltip;
    Color_RGB8 color;
    u8 animateHighlight;
    void* data;
    u8 selectable;
    Menu* imenu;

    s32 (*EntryProc)(struct MenuItem* item, MenuSwitchReason reason);
    s32 (*LeaveProc)(struct MenuItem* item, MenuSwitchReason reason);
    s32 (*ThinkProc)(struct Menuitem* item);
    s32 (*DrawProc)(struct MenuItem* item, struct MenuDrawParams* params);
    s32 (*NavigateProc)(struct MenuItem* item, MenuNavigation nav);
    s32 (*ActivateProc)(struct MenuItem* item);
    s32 (*DestroyProc)(struct MenuItem* item);
} MenuItem;

typedef struct Menu
{
    s32 cxoffset;
    s32 cyoffset;
    s32 pxoffset;
    s32 pyoffset;
    s32 cellWidth;
    s32 cellHeight;
    Font* font;
    f32 alpha;
    ListAlloc items;
    MenuItem* selector;
    struct Menu* parent;
    struct Menu* child;
    u32 highlightColorStatic;
    u32 highlightColorAnimated;
    s32 highlightState[3];
} Menu;

typedef struct 
{
    s32 x;
    s32 y;
    const char* text;
    Font* font;
    Color_RGB8 color;
    u8 alpha;
} MenuDrawParams;

enum MenuWatchType
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
  WATCH_TYPE_MAX,
};

#endif