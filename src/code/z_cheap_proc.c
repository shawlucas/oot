#include <ultra64.h>
#include <global.h>

void Gfx_DrawDListOpa(GlobalContext* globalCtx, Gfx* dlist) {

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_cheap_proc.c", 214);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(NEXT_DISP, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_cheap_proc.c", 216),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(NEXT_DISP, dlist);

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_cheap_proc.c", 219);
}

void Gfx_DrawDListXlu(GlobalContext* globalCtx, Gfx* dlist) {

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_cheap_proc.c", 228);

    func_80093D84(globalCtx->state.gfxCtx);
    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_cheap_proc.c", 230),
              G_MTX_MODELVIEW | G_MTX_LOAD);
    gSPDisplayList(NEXT_POLY_XLU_DISP, dlist);

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_cheap_proc.c", 233);
}
