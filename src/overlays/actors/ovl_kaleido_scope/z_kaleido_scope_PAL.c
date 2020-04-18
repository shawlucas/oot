#include <ultra64.h>
#include <global.h>
#include "z_kaleido_scope.h"

extern char D_8082FA60[];
extern UNK_TYPE D_808321B0;
extern char D_8082FA7C[];
void func_8081F1F0(Kaleido* kscope)
{
    Gfx* displayList;
    Gfx* prevDisplayList;
    u16* curFrameBuffer;
    GraphicsContext* gfxCtx;
    Gfx* dispRefs[4];

    gfxCtx = kscope->state.gfxCtx;
    curFrameBuffer = kscope->state.gfxCtx->curFrameBuffer;
    Graph_OpenDisps(dispRefs, kscope->state.gfxCtx, D_8082FA60, 496);
    prevDisplayList = gfxCtx->polyOpa.p;
    displayList = Graph_GfxPlusOne(gfxCtx->polyOpa.p);
    gSPDisplayList(gfxCtx->work.p++, displayList);
    func_800C0ED8(&D_808321B0, 0x40, 0x70, curFrameBuffer, 0);
    func_800C1F20(&D_808321B0, &displayList);
    func_800C20B4(&D_808321B0, &displayList);
    gSPEndDisplayList(displayList++);
    Graph_BranchDlist(prevDisplayList, displayList);
    gfxCtx->polyOpa.p = displayList;
    SREG(33) |= 1;
    Graph_CloseDisps(dispRefs, kscope->state.gfxCtx, D_8082FA7C, 509);
}

void func_8081F2FC(void)
{
    Sleep_Msec(50);
    func_800C3770(&D_808321B0);
    func_800C0F08(&D_808321B0);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F334.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F50C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F6E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F81C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F87C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081FABC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081FB7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081FCF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081FE30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8082018C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80820434.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80821C10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80823548.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808237B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80823994.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80823A0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8082409C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80825C14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/KaleidoScope_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8082650C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808265BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808267AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80826AEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80826BA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80826CB4.s")