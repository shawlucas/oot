#include <global.h>
#include "z64menu.h"
#include "alloca.h"

ZeldaMenu* gZeldaMenu;
ZeldaMenu* activeMenu;
s32 baseNumItems = 3;
s32 numScenes = 3;

#define GLOBAL_MENU_COUNT 3
#define NUM_WARPS 3

static const char* sceneNames[] = {
    "Deku Tree",
    "Dodongo's Cavern",
    "Jabu Jabu"
};

ZeldaMenu* ZeldaMenu_Setup(ZeldaMenu* baseMenu, s32 numItems) {
    s32 i;
    baseMenu = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu), "../z_menu.c", __LINE__);
    baseMenu->idx = 0;
    baseMenu->numItems = numItems;
    baseMenu->items = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu *) * baseMenu->numItems, "../z_menu.c", __LINE__);

    for (i = 0; i < baseMenu->numItems; i++) {
        // Initialize each item in top level menu
        baseMenu->items[i] = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu) * baseMenu->numItems, "../z_menu.c", __LINE__);
    }

    return baseMenu;
}

ZeldaMenu* MenuItem_GetSubmenu(MenuItem* item) {
    return item->submenu; 
}

void MenuItem_SetAttributes(MenuItem* item, const char* name, s32 x, s32 y, ZeldaMenu* submenu) {
    item->name = name;
    item->x = x;
    item->y = y;
    
    if (submenu != NULL) {
        item->submenu = submenu;
    } else {
        item->submenu = NULL;
    }
}

MenuItem** Menu_GetItems(ZeldaMenu* menu, s32 idx) {
    return menu->items[idx];
}

void ZeldaMenu_Init() {
    s32 i;
    MenuItem* warpsItem;
    MenuItem* item1;
    MenuItem* item2;    
    ZeldaMenu* warpsMenu;

    gZeldaMenu = ZeldaMenu_Setup(gZeldaMenu, GLOBAL_MENU_COUNT);
    activeMenu = gZeldaMenu;

    
    warpsItem = Menu_GetItems(gZeldaMenu, MENU_WARPS);
    MenuItem_SetAttributes(warpsItem, "Warps", 2, 2, ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu) * NUM_WARPS, "../z_menu.c", __LINE__));

    item1 = Menu_GetItems(gZeldaMenu, MENU_ITEM1);
    MenuItem_SetAttributes()
   warpsItem = gZeldaMenu->items[MENU_WARPS];
   item1 = gZeldaMenu->items[MENU_ITEM1];
   item2 = gZeldaMenu->items[MENU_ITEM2];

   warpsItem->name = "Warps 0";
   item1->name = "Item 1";
   item2->name = "Item 2";

   warpsItem->x = 2;
   item1->x = 2;
   item2->x = 2;

   warpsItem->y = 2;
   item1->y = 4;
   item2->y = 6;

   /* Create Submenu for warps menu */
   warpsMenu = warpsItem->submenu = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu) * NUM_WARPS, "../z_menu.c", __LINE__);
   warpsMenu->numItems = NUM_WARPS;
   warpsMenu->idx = DEKU_TREE;
   warpsMenu->items = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu*) * warpsMenu->numItems, "../z_menu.c", __LINE__);
   
   for (i = 0; i < warpsMenu->numItems; i++) {
        warpsMenu->items[i] = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu) * warpsMenu->numItems, "../z_menu.c", __LINE__);
   }

   warpsMenu->items[DEKU_TREE]->name = sceneNames[0];
   warpsMenu->items[WARP_01]->name = sceneNames[1];
   warpsMenu->items[WARP_02]->name = sceneNames[2];
   warpsMenu->items[DEKU_TREE]->x = 2;
   warpsMenu->items[DEKU_TREE]->y = 2;
   warpsMenu->items[WARP_01]->x = 2;
   warpsMenu->items[WARP_01]->y = 4;
   warpsMenu->items[WARP_02]->x = 2;
   warpsMenu->items[WARP_02]->y = 6;

   
}

void ZeldaMenu_Destroy() {
    if (gZeldaMenu != NULL) {
        ZELDA_ARENA_FREE(gZeldaMenu, "../z_menu.c", __LINE__);
    }
}

void MenuItem_SetName(MenuItem* item, const char* name) {
    item->name = name;
}

s32 ZeldaMenu_AddItem(ZeldaMenu* menu, const char* name, s32 x, s32 y) {
    s32 idx = menu->numItems;

    ZeldaArena_ReallocDebug(gZeldaMenu->items, sizeof(ZeldaMenu*) * menu->numItems, "../z_menu.c", __LINE__);
    menu->items[idx] = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu), "../z_menu.c", __LINE__);

    menu->items[idx]->name = name;
    menu->items[idx]->x = x;
    menu->items[idx]->y = y;
    
    menu->numItems++;

    return idx;
}

void ZeldaMenu_AddSubmenu(const char* name, ZeldaMenu* parent) {
}

void ZeldaMenu_SetItem(ZeldaMenu* menu, const char* name, s32 x, s32 y, s32 idx) {
  // menu->items[idx]->name = name;
  // menu->x = x;
  // menu->y = y;
}

void ZeldaMenu_Update(ZeldaMenu* menu, PlayState* play) {
    Input* input = &play->state.input[0];
    s32 idx = menu->idx;

    if (CHECK_BTN_ALL(input->press.button, BTN_DDOWN) && menu->idx < MENU_MAX - 1) {
        menu->idx++;
    } else if (CHECK_BTN_ALL(input->press.button, BTN_DUP) && menu->idx > 0) {
        menu->idx--;
    }

    if (CHECK_BTN_ALL(input->press.button, BTN_L)) {
        if (activeMenu->items[idx]->submenu != NULL) {
            activeMenu = activeMenu->items[idx]->submenu;
        }
    }

//    if (CHECK_BTN_ALL(input->press.button, BTN_L) && menu->items[idx]->submenu != NULL) {
//
  //  }
}
    
void ZeldaMenu_Draw(PlayState* play) {
    Gfx* gfx;
    Gfx* opaStart;
    GfxPrint* printer;
    s32 i;
    s32 idx = gZeldaMenu->idx;
    OPEN_DISPS(play->state.gfxCtx, "../z_menu.c", __LINE__);

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    opaStart = POLY_OPA_DISP;
    gfx = Gfx_Open(POLY_OPA_DISP);
    gSPDisplayList(OVERLAY_DISP++, gfx);
    GfxPrint_Open(printer, gfx);

    
    for (i = 0; i < activeMenu->numItems; i++) {
        if (i == idx) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 255, 255, 255, 255);
        }
        GfxPrint_SetPos(printer, activeMenu->items[i]->x, activeMenu->items[i]->y);
        GfxPrint_Printf(printer, activeMenu->items[i]->name);
        
    }
    
    gfx = GfxPrint_Close(printer);
    gSPEndDisplayList(gfx++);
    Gfx_Close(opaStart, gfx);
    POLY_OPA_DISP = gfx;
    GfxPrint_Destroy(printer);

    CLOSE_DISPS(play->state.gfxCtx, "../z_menu.c", __LINE__);
}
