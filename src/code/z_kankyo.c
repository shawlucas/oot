#include <ultra64.h>
#include <global.h>

extern s16 D_8011FB44;
extern s16 D_8015FD7E;
extern s16 D_8015FD80;

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006F0A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/Kankyo_GetPixel.s")

void func_8006F0FC(GraphicsContext* gfxCtx, GlobalContext* globalCtx) {
    D_8011FB44 = Kankyo_GetPixel(D_8015FD7E, D_8015FD80);
    func_8007A9B4(globalCtx);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006F140.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006F93C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006F9BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006FB94.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006FC88.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80070600.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800706A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80070718.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80070C24.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800730DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80073988.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80073A5C.s")

f32 func_800746DC() {
    return Math_Rand_ZeroOne() - 0.5f;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80074704.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80074CE8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80074D6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80074FF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800750C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800753C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8007542C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800758AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80075B44.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80075E68.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80075F14.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800760F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800763A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800766C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8007672C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_80076934.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_800773A8.s")

s32 func_800775CC() {
    return gSaveContext.unk_18;
}

void func_800775D8() {
    gSaveContext.unk_18 = 0;
}

s32 func_800775E4() {
    return gSaveContext.unk_14;
}

void func_800775F0(u16 arg0) {
    gSaveContext.unk_140E = arg0;
}

s32 func_80077600(void) {
    s32 ret = 0;
    if (gSaveContext.unk_140E == 0xFFFF) {
        ret = 1;
    }
    return ret;
}

void func_80077624(GlobalContext* globalCtx) {
    if (globalCtx->soundCtx.nighttimeSFX == 0x13) {
        func_800F6FB4(5, globalCtx->soundCtx.nighttimeSFX);
    } else {
        func_800F6FB4(globalCtx->soundCtx.nighttimeSFX & 0xFF, globalCtx->soundCtx.nighttimeSFX);
    }
    func_800F6D58(0xE, 1, 1);
    func_800F6D58(0xF, 1, 1);
}

void func_80077684(GlobalContext* globalCtx) {
    func_800F6D58(0xE, 1, 0);
    func_800F6D58(0xF, 1, 0);
    if (func_800FA0B4(0) == 1) {
        gSaveContext.seqIndex = 0x80;
        func_800758AC(globalCtx);
    }
}

void func_800776E4(GlobalContext* globalCtx) {
    D_8011FB30 = 0;
    gSaveContext.cutsceneIndex = 0;
    gSaveContext.respawnFlag = -3;
    globalCtx->nextEntranceIndex = gSaveContext.respawn[1].entranceIndex;
    globalCtx->sceneLoadFlag = 0x14;
    globalCtx->fadeTransition = 3;
    gSaveContext.nextTransition = 3;
    switch (globalCtx->nextEntranceIndex) {
        case 0x147: // Death Mountain Crater (From Death Mountain Trail)
            Flags_SetEventChkInf(0xB9);
            return;
        case 0x102: // Lake Hylia (From Hyrule Field)
            Flags_SetEventChkInf(0xB1);
            return;
        case 0xFC: // Sacred Forest Meadow (From Lost Woods)
            return;
        case 0x123: // Desert Colossus (From Haunted Wasteland)
            Flags_SetEventChkInf(0xB8);
            return;
        case 0xE4: // Kakariko Graveyard (From Kakariko Village)
            Flags_SetEventChkInf(0xB6);
            return;
        case 0x53: // Temple of Time (From outside Temple of Time)
            Flags_SetEventChkInf(0xA7);
    }
}
