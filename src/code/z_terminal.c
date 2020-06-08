#include <ultra64.h>
#include <global.h>

typedef struct {
    /* 0x00 */ 
} Terminal;
void Terminal_SetupTerminal(GlobalContext* globalCtx, GfxPrint* gfxp)
{
    GraphicsContext* gfxCtx;
    Gfx* dispRefs[4];

    gfxCtx = globalCtx->state.gfxCtx;

    Graph_OpenDisps(dispRefs, globalCtx->state.gfxCtx, "../z_terminal.c", 11);
    GfxPrint_SetPos(gfxp, 1, 1);
    GfxPrint_Printf(gfxp, "%s", "Hello, World!");
}