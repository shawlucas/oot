#include <ultra64.h>
#include <global.h>

void func_80026230(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3) {
    f32 cos;
    Gfx* displayListHead;
    f32 absCos;

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 113);

    displayListHead = NOW_DISP;
    cos = Math_Coss((0x8000 / arg3) * arg2);
    absCos = ABS(cos);

    gDPPipeSync(displayListHead++);

    if (color == NULL) {
        gDPSetFogColor(displayListHead++, 255, 0, 0, 0);
    } else {
        gDPSetFogColor(displayListHead++, color->r, color->g, color->b, color->a);
    }

    gSPFogPosition(displayListHead++, 0, (s16)(absCos * 3000.0f) + 1500);

    SET_NOW_DISP(displayListHead);

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 129);
}

void func_80026400(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3) {
    Gfx* displayListHead;
    f32 cos;

    if (arg3 != 0) {
        OPEN_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 141);

        cos = Math_Coss((0x4000 / arg3) * arg2);
        displayListHead = NOW_DISP;

        gDPPipeSync(displayListHead++);
        gDPSetFogColor(displayListHead++, color->r, color->g, color->b, color->a);
        gSPFogPosition(displayListHead++, 0, (s16)(2800.0f * ABS(cos)) + 1700);

        SET_NOW_DISP(displayListHead);

        if (1) {} // Necessary to match

        CLOSE_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 153);
    }
}

void func_80026608(GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 159);

    gDPPipeSync(NEXT_DISP);
    SET_NOW_DISP(func_800BC8A0(globalCtx, NOW_DISP));

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 164);
}

void func_80026690(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3) {
    f32 cos;
    Gfx* displayListHead;
    f32 absCos;

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 178);

    displayListHead = NOW_POLY_XLU_DISP;
    cos = Math_Coss((0x8000 / arg3) * arg2);
    absCos = ABS(cos);

    gDPPipeSync(displayListHead++);

    if (color == NULL) {
        gDPSetFogColor(displayListHead++, 255, 0, 0, 0);
    } else {
        gDPSetFogColor(displayListHead++, color->r, color->g, color->b, color->a);
    }

    gSPFogPosition(displayListHead++, 0, (s16)(absCos * 3000.0f) + 1500);

    SET_NOW_POLY_XLU_DISP(displayListHead);

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 194);
}

void func_80026860(GlobalContext* globalCtx, Color_RGBA8* color, s16 arg2, s16 arg3) {
    f32 cos;
    Gfx* displayListHead;

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 201);

    displayListHead = NOW_POLY_XLU_DISP;
    cos = Math_Coss((0x4000 / arg3) * arg2);

    gDPPipeSync(displayListHead++);
    gDPSetFogColor(displayListHead++, color->r, color->g, color->b, color->a);
    gSPFogPosition(displayListHead++, 0, (s16)(2800.0f * ABS(cos)) + 1700);

    SET_NOW_POLY_XLU_DISP(displayListHead);

    if (1) {} // Necessary to match

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 212);
}

void func_80026A6C(GlobalContext* globalCtx) {
    s32 pad;

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 217);

    gDPPipeSync(NEXT_POLY_XLU_DISP);
    SET_NOW_POLY_XLU_DISP(func_800BC8A0(globalCtx, NOW_POLY_XLU_DISP));

    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_eff_ss_dead.c", 222);
}
