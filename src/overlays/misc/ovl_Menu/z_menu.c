#include "z_menu.h"
#include "alloca.h"
#include "vt.h"

#define FLAGS ACTOR_FLAG_4

void MenuContext_Init(Actor* thisx, GlobalContext* globalCtx);
void MenuContext_Destroy(Actor* thisx, GlobalContext* globalCtx);
void MenuContext_Update(Actor* thisx, GlobalContext* globalCtx);
void MenuContext_Draw(Actor* thisx, GlobalContext* globalCtx);

const ActorInit Menu_InitVars = {
    ACTOR_MENUCONTEXT,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(MenuContext),
    (ActorFunc)MenuContext_Init,
    (ActorFunc)MenuContext_Destroy,
    (ActorFunc)MenuContext_Update,
    (ActorFunc)MenuContext_Draw,
};

void MenuContext_Init(Actor* thisx, GlobalContext* globalCtx) {
    MenuContext* this = (MenuContext*)thisx;

    osSyncPrintf(VT_FGCOL(GREEN) "Menu context init!\n");
}

void MenuContext_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void MenuContext_Update(Actor* thisx, GlobalContext* globalCtx) {
}

void MenuContext_PrintMenu(GfxPrint* printer) {
    GfxPrint_SetPos(printer, 2, 4);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    GfxPrint_Printf(printer, "Test");
}

void MenuContext_DrawMenu(MenuContext* this, GlobalContext* globalCtx) {
    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_menu.c", __LINE__);

    this->printer = alloca(sizeof(GfxPrint));
    GfxPrint_Init(this->printer);
    GfxPrint_Open(this->printer, POLY_OPA_DISP);
    MenuContext_PrintMenu(this->printer);
    POLY_OPA_DISP = GfxPrint_Close(this->printer);
    GfxPrint_Destroy(this->printer);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_menu.c", __LINE__);
}

void MenuContext_Draw(Actor* thisx, GlobalContext* globalCtx) {
    MenuContext* this = (MenuContext*)thisx;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_menu.c", __LINE__);

    MenuContext_DrawMenu(this, globalCtx);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_menu.c", __LINE__);
}
