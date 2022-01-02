#include "global.h"
#include "z64menu.h"
#include "vt.h"
#include "alloca.h"

u8 gMenuInitialized = false;

Menu gMenu[][MENU_MAX] = {
    { "Return", 0, ENTRYCNT_TOP }, 
    { "Warps" , 1, ENTRYCNT_WARPS },
};

MenuSystem* sMenuSystem;

void Menu_UpdatePad(GameState* gameState) {
    Input* input = &gameState->input[0];

    if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN) && sMenuSystem->cursorPos < gMenu[sMenuSystem->cursorPos]->entryCnt) {
        sMenuSystem->cursorPos++;
    } else if (CHECK_BTN_ALL(input->cur.button, BTN_DUP) && sMenuSystem->cursorPos > 0) {
        sMenuSystem->cursorPos--;
    }
}

void Menu_Print(GfxPrint* printer) {
    s32 i;
    const char* name;

    GfxPrint_SetPos(printer, 2, 2);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);

    for (i = 0; i < MENU_MAX; i++) {
        GfxPrint_SetPos(printer, 2, i + 4);

        if (sMenuSystem->cursorPos == i) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 255, 255, 255, 255);
        }

        name = gMenu[i]->name;

        GfxPrint_Printf(printer, "%s", name);
    }
}

void Menu_Draw(GameState* gameState) {
    GraphicsContext* gfxCtx = gameState->gfxCtx;
    GfxPrint* printer;

    OPEN_DISPS(gfxCtx, "../z_menu.c", __LINE__);

    printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(printer);
    GfxPrint_Open(printer, OVERLAY_DISP);
    Menu_Print(printer);
    OVERLAY_DISP = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);

    CLOSE_DISPS(gfxCtx, "../z_menu.c", __LINE__);
}

void Menu_Destroy() {
    gMenuInitialized = false;
}

void Menu_Update(GameState* gameState) {
    Menu_UpdatePad(gameState);
}

void MenuSystem_Init() {
    sMenuSystem = DebugArena_MallocDebug(sizeof(MenuSystem), "../z_menu.c", __LINE__);

    if (sMenuSystem == NULL) {
        osSyncPrintf(VT_FGCOL(RED) "Could not allocate memory for MenuSystem!\n" VT_RST);
        Menu_Destroy();
        return;
    }

    sMenuSystem->cursorPos = POS_RET;
    sMenuSystem->curEntryCnt = 1;

    osSyncPrintf(VT_FGCOL(GREEN) "Menu initialized!!\n" VT_RST);
}
