#include <global.h>

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F1F0.s")
extern UNK_TYPE D_808321B0;

void func_8081F1F0(GlobalContext* globalCtx)
{
    Gfx* displayList;
    Gfx* prevDisplayList;
    u16* curFrameBuffer;
    Gfx* dispRefs[5];
    
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    curFrameBuffer = gfxCtx->curFrameBuffer;
    Graph_OpenDisps(dispRefs, globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 496);

    prevDisplayList = gfxCtx->polyOpa.p;
    displayList = Graph_GfxPlusOne(gfxCtx->polyOpa.p);
    gSPDisplayList(gfxCtx->work.p++, displayList);

    func_800C0ED8(&D_808321B0, 0x40, 0x70, curFrameBuffer, NULL);
    func_800C1F20(&D_808321B0, &displayList);
    func_800C20B4(&D_808321B0, &displayList);
    gSPEndDisplayList(displayList++);
    Graph_BranchDlist(prevDisplayList, displayList);
    gfxCtx->polyOpa.p = displayList;
    SREG(33) |= 1;
    Graph_CloseDisps(dispRefs, globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 509);

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

#ifdef NON_MATCHING
// Functionally equivalent. Minor reordering
void func_8081F81C(GlobalContext* globalCtx, u16 arg1)
{
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    pauseCtx->unk_23A = 0;
    pauseCtx->unk_238 = arg1;
    Audio_PlaySoundGeneral(NA_SE_SY_DECIDE, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
}
#else 
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8081F81C.s")
#endif

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

void KaleidoScope_Draw(GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input[0];
    PauseContext* pauseCtx = &globalCtx->pauseCtx;
    InterfaceContext* interfaceCtx = &globalCtx->interfaceCtx;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    Gfx* dispRefs[4];

    Graph_OpenDisps(dispRefs, globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 3188);

    pauseCtx->inputX = input->rel.in.x;
    pauseCtx->inputY = input->rel.in.y;

    gSPSegment(gfxCtx->polyOpa.p++, 0x02, interfaceCtx->parameterSegment);
    gSPSegment(gfxCtx->polyOpa.p++, 0x07, pauseCtx->unk_13C);
    gSPSegment(gfxCtx->polyOpa.p++, 0x08, pauseCtx->unk_128);
    gSPSegment(gfxCtx->polyOpa.p++, 0x09, pauseCtx->unk_12C);
    gSPSegment(gfxCtx->polyOpa.p++, 0x0A, pauseCtx->unk_138);
    gSPSegment(gfxCtx->polyOpa.p++, 0x0C, pauseCtx->unk_130);
    gSPSegment(gfxCtx->polyOpa.p++, 0x0D, pauseCtx->unk_134);

    if (pauseCtx->flag == 0) {
        func_80823994(pauseCtx, pauseCtx->unk_1D8.x, pauseCtx->unk_1D8.y, pauseCtx->unk_1D8.z);
        func_800949A8(globalCtx->state.gfxCtx);
        func_8082409C(globalCtx, globalCtx->state.gfxCtx);
        func_80820434(globalCtx, globalCtx->state.gfxCtx);
        func_800949A8(globalCtx->state.gfxCtx);

        gDPSetCombineLERP(gfxCtx->polyOpa.p++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);

        func_80823994(pauseCtx, 0.0f, 0.0f, 64.0f);
        if (pauseCtx->state < 8 || 17 < pauseCtx->state) {
            func_80821C10(globalCtx);
        }
    }
    if (pauseCtx->state > 10 && pauseCtx->state <= 17) {
        func_80825C14(globalCtx);
    }
    if (pauseCtx->flag == 1 || pauseCtx->flag == 2) {
        func_808161AC(globalCtx);
    }

    Graph_CloseDisps(dispRefs, globalCtx->state.gfxCtx, "../z_kaleido_scope_PAL.c", 3254);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_8082650C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808265BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_808267AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80826AEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/func_80826BA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_kaleido_scope/KaleidoScope_Update.s")
