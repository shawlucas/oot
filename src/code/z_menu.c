#include "global.h"
#include "z_menu.h"
#include "alloca.h"

#define INIT_SIZE 3

Menu* gMenu;
u8 gMenuActive = 0;

const char* sMainMenuNames[] = {
    "warps", "item1", "item2", "return",
};

Menu** Menu_Alloc(s32 numItems) {
    Menu** ret = DEBUG_ARENA_MALLOC(sizeof(Menu*) * numItems, "../z_menu.c", __LINE__); 

    if (ret == NULL) {
        osSyncPrintf("Could not allocate memory for Menu!\n");
        return NULL;
    }
    
    return ret;
}

Menu* MenuItem_Alloc(void) {
    Menu* ret = DEBUG_ARENA_MALLOC(sizeof(Menu), "../z_menu.c", __LINE__); 

    if (ret == NULL) {
        osSyncPrintf("Could not allocate memory for Menu item!\n");
        return NULL;
    }
    
    return ret;
}

void Menu_Create(void) {
    gMenu = MenuItem_Alloc();

    if (gMenu == NULL) {
        PRINTF("gMenu is NULL!\n");
        Fault_AddHungupAndCrash("../z_menu.c", __LINE__);
    }
}

void Menu_Destroy(Menu* this, PlayState* play) {
    if (gMenu != NULL) {
        DEBUG_ARENA_FREE(gMenu, "../z_menu.c", __LINE__);
    }
    PRINTF("Menu destroyed!\n");
}

void Menu_Update(Menu* this, PlayState* play) {

}

void Menu_Draw(Menu* this, PlayState* play) {
    if (gMenuActive) {
        GraphicsContext* gfxCtx = play->state.gfxCtx;
        GfxPrint* printer;

        OPEN_DISPS(gfxCtx, "../z_menu.c", __LINE__);

        printer = alloca(sizeof(GfxPrint));
        GfxPrint_Init(printer);
        GfxPrint_Open(printer, POLY_OPA_DISP);

        GfxPrint_SetColor(printer, 255, 255, 255, 255);
        GfxPrint_SetPos(printer, 5, 2);
        GfxPrint_Printf(printer, this->items[0]->name);

        POLY_OPA_DISP = GfxPrint_Close(printer);
        GfxPrint_Destroy(printer);
        CLOSE_DISPS(gfxCtx, "../z_menu.c", __LINE__);
    }
}

void Menu_Init(Menu* this, PlayState* play) {
    s32 i = 0;
    s32 j = 0;

    PRINTF("Menu active!\n");

    this->head = NULL;

    this->items = Menu_Alloc(INIT_SIZE);
    this->items[0] = MenuItem_Alloc();
    this->items[0]->name = sMainMenuNames[0];
  //  for (j = 0; j < INIT_SIZE; j++) {
    //    PRINTF("Item %d starting!\n", j);
     //   this->items[j] = Menu_Alloc();
      //  this->items[j]->name = sMainMenuNames[j];
    //}
}
