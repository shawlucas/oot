#include <ultra64.h>
#include <global.h>

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80813820.s")

s32 func_80815CC8(PauseContext* pauseCtx, s32 curStatusCursorPos)
{
    pauseCtx->statusCursorPos = curStatusCursorPos;
    return 1;
}