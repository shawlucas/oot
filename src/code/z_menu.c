#include <global.h>
#include "z64menu.h"
#include "alloca.h"

ZeldaMenu* gZeldaMenu;
s32 zeldaMenuSize = 10;

void ZeldaMenu_Init() {
    s32 i;
    gZeldaMenu = ZELDA_ARENA_MALLOC(sizeof(ZeldaMenu), "../z_menu.c", __LINE__);

    gZeldaMenu->items = (MenuItem **)ZELDA_ARENA_MALLOC(sizeof(MenuItem*) * zeldaMenuSize, "../z_menu.c", __LINE__);

    // Allocate Items
    for (i = 0; i < zeldaMenuSize; i++) {
       gZeldaMenu->items[i] = (MenuItem *)ZELDA_ARENA_MALLOC(zeldaMenuSize * sizeof(MenuItem), "../z_menu.c", __LINE__);
    }

   ZeldaMenu_AddItem("Test 11", 12, 2, zeldaMenuSize + 1);
}

void ZeldaMenu_Destroy() {
    if (gZeldaMenu != NULL) {
        ZELDA_ARENA_FREE(gZeldaMenu, "../z_menu.c", __LINE__);
    }
}

void ZeldaMenu_AddItem(const char* name, s32 x, s32 y, s32 numElements) {
    gZeldaMenu->items = ZeldaArena_ReallocDebug(gZeldaMenu->items, sizeof(MenuItem *) * numElements,
                          "../z_menu.c", __LINE__);
    gZeldaMenu->items[numElements - 1]->name = name;
    gZeldaMenu->items[numElements - 1]->x = x;
    gZeldaMenu->items[numElements - 1]->y = y;
    zeldaMenuSize++;
}

void ZeldaMenu_Draw(PlayState* play) {
    GfxPrint* printer;
    s32 i;
    OPEN_DISPS(play->state.gfxCtx, "../z_menu.c", __LINE__);

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    GfxPrint_Open(printer, POLY_OPA_DISP);

    
    GfxPrint_SetColor(printer, 255, 255, 255, 255);

    for (i = 0; i < zeldaMenuSize - 1; i++) {
        GfxPrint_SetPos(printer, gZeldaMenu->items[i]->x, gZeldaMenu->items[i]->y);
        GfxPrint_Printf(printer, gZeldaMenu->items[i]->name);
    }
    
    POLY_OPA_DISP = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);

    CLOSE_DISPS(play->state.gfxCtx, "../z_menu.c", __LINE__);
}
