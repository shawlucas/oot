#include "global.h"
#include "z_rando.h"
#include <alloca.h>

void RandoContext_Main(GameState* thisx) {
    RandoContext* this = (RandoContext *)thisx;

    func_80095248(this->state.gfxCtx, 0, 0, 0);
    RandoContext_DrawTest(thisx);

    SET_NEXT_GAMESTATE(&this->state, Gameplay_Init, GlobalContext);
}

void RandoContext_DrawTest(GameState* thisx) {
    RandoContext* this = (RandoContext *)thisx;
    GraphicsContext* gfxCtx = this->state.gfxCtx;
    GfxPrint* printer = alloca(sizeof(GfxPrint));

    OPEN_DISPS(this->state.gfxCtx, __FILE__, __LINE__);

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, POLY_OPA_DISP);
    GfxPrint_SetColor(printer, 255, 155, 150, 255);
    GfxPrint_SetPos(printer, 12, 2);
    GfxPrint_Printf(printer, "TEST PRINT");
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    POLY_OPA_DISP = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);

    CLOSE_DISPS(this->state.gfxCtx, __FILE__, __LINE__);
}
void RandoContext_Destroy(GameState* thisx) {

}

void RandoContext_Init(GameState* thisx) {
    RandoContext* this = (RandoContext *)thisx;

    Matrix_Init(&this->state);
    View_Init(&this->view, this->state.gfxCtx);

    this->state.main = RandoContext_Main;
    this->state.destroy = RandoContext_Destroy;
}
