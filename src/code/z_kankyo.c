#include <ultra64.h>
#include <global.h>

extern s16 D_8011FB44;
extern s16 D_8015FD7E;
extern s16 D_8015FD80;

void func_8006F0FC(GraphicsContext* gfxCtx, GlobalContext* globalCtx);

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006F0A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/Kankyo_GetPixel.s")

void func_8006F0FC(GraphicsContext* gfxCtx, GlobalContext* globalCtx) {
    D_8011FB44 = Kankyo_GetPixel(D_8015FD7E, D_8015FD80);
    func_8007A9B4(globalCtx);
}

//#pragma GLOBAL_ASM("asm/non_matchings/code/z_kankyo/func_8006F140.s")
void func_8006F140(GlobalContext *globalCtx, EnvironmentContext *envCtx, s32 arg2) {
    LightInfoDirectional *sp38;
    LightingContext *sp34;
    LightingContext *temp_a2;
    f32 temp_f18;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 temp_t5;
    s32 phi_v0;
    s32 phi_v0_2;

    gSaveContext.unk_1422 = (u16)0;
    if (((s32) gSaveContext.dayTime >= 0xC001) || ((s32) gSaveContext.dayTime < 0x4555)) {
        gSaveContext.nightFlag = 1;
    } else {
        gSaveContext.nightFlag = 0;
    }
    globalCtx->state.gfxCtx->callback = (void (*)(struct GraphicsContext *, u32)) &func_8006F0FC;
    globalCtx->state.gfxCtx->callbackParam = (u32) globalCtx;
    sp38 = &envCtx->lightInfo_28;
    Lights_InitDirectional(&envCtx->lightInfo_28, (u8)0x50, (u8)0x50, (u8)0x50, 0x50, 0x50, 0x50);
    sp34 = &globalCtx->lightCtx;
    Lights_Insert(globalCtx, &globalCtx->lightCtx, (void *) sp38);
    sp38 = &envCtx->lightInfo_36;
    Lights_InitDirectional(&envCtx->lightInfo_36, (u8)0x50, (u8)0x50, (u8)0x50, 0x50, 0x50, 0x50);
    Lights_Insert(globalCtx, &globalCtx->lightCtx, (void *) sp38);
    envCtx->skyboxId = (u8)0x63U;
    envCtx->skyboxId2 = (u8)0x63U;
    envCtx->unk_19 = (u8)0U;
    envCtx->unk_1A = (u16)0U;
    envCtx->unk_21 = (u8)0U;
    envCtx->unk_22 = (u16)0U;
    envCtx->unk_44 = (u8)0U;
    envCtx->unk_1F = (u8)0U;
    envCtx->unk_20 = (u8)0U;
    envCtx->unk_BD = (u8)0U;
    envCtx->unk_BE = (u8)0U;
    envCtx->unk_DC = (u8)0U;
    envCtx->gloomySkyEvent = (u8)0U;
    envCtx->unk_DE = (u8)0U;
    envCtx->lightning = (u8)0U;
    envCtx->unk_E0 = (u8)0U;
    envCtx->unk_E1 = (u8)0U;
    envCtx->unk_E2 = (u8)0U;
    envCtx->unk_E3 = (u8)0U;
    envCtx->unk_E4 = (u8)0U;
    envCtx->unk_E5 = (u8)0U;
    envCtx->unk_E9 = (u8)0U;
    envCtx->unk_EA = (u8)0U;
    envCtx->unk_EB = (u8)0U;
    envCtx->unk_EC = (u8)0U;
    envCtx->unk_ED = (u8)0U;
    envCtx->unk_E6 = (u8)0U;
    envCtx->unk_E7 = (u8)0U;
    envCtx->unk_E8 = (u8)0U;
    envCtx->unk_84 = 0.0f;
    envCtx->unk_88 = 0.0f;
    envCtx->unk_D8 = 1.0f;
    D_8015FD70.unk0 = (u8)0U;
    (&D_8015FD70)[1] = (u8)0U;
    (&D_8015FD70)[2] = (u8)0U;
    (&D_8015FD70)[3] = (u8)0U;
    D_8015FD7C = (u16)0;
    gSaveContext.unk_1410 = (u8)0U;
    envCtx->unk_A0 = (u16)0;
    envCtx->unk_9E = (s16) envCtx->unk_A0;
    envCtx->vec_98.z = (s16) envCtx->unk_A0;
    envCtx->vec_98.y = (s16) envCtx->unk_A0;
    envCtx->vec_98.x = (s16) envCtx->unk_A0;
    envCtx->unk_96 = (s16) envCtx->unk_A0;
    envCtx->unk_94 = (s16) envCtx->unk_A0;
    envCtx->unk_92 = (s16) envCtx->unk_A0;
    envCtx->unk_90 = (s16) envCtx->unk_A0;
    envCtx->unk_8E = (s16) envCtx->unk_A0;
    envCtx->unk_8C = (s16) envCtx->unk_A0;
    envCtx->sunMoonPos.x = (f32) (-(Math_Sins((s16) ((s32) (((s16) gSaveContext.dayTime - 0x8000) << 0x10) >> 0x10)) * 120.0f) * 25.0f);
    envCtx->sunMoonPos.y = (f32) ((Math_Coss((s16) ((s32) ((gSaveContext.dayTime - 0x8000) << 0x10) >> 0x10)) * 120.0f) * 25.0f);
    temp_f18 = Math_Coss((s16) ((s32) ((gSaveContext.dayTime - 0x8000) << 0x10) >> 0x10)) * 20.0f;
    envCtx->unk_A8 = (u16)0x50;
    envCtx->unk_AA = (u16)0x50;
    envCtx->unk_AC = (u16)0x50;
    envCtx->unk_BC = (u8)0;
    envCtx->unk_BF = (u8)0xFFU;
    envCtx->unkD6 = (u16)0xFFFF;
    envCtx->timeSpeed = (u16)0U;
    envCtx->sunMoonPos.z = (f32) (temp_f18 * 25.0f);
    D_8011FB40 = (u16)0U;
    gGameInfo->unk32 = (u16)0;
    gGameInfo->unk26 = (u16)1;
    temp_a2 = globalCtx + 0x10000;
    if (gGameInfo->unk85A != 0) {
        gSaveContext.chamberCutsceneNum = (u8) (gGameInfo->unk85A - 1);
    }
    globalCtx->envCtx.unk_EE = (u8)0;
    globalCtx->unk10B13 = (u8)0;
    globalCtx->unk10B14 = (u8)0;
    globalCtx->unk10B15 = (u8)0;
    globalCtx->envCtx.unk_F2 = (u8)0;
    if (gSaveContext.unk13C3 != 0) {
        if ((gSaveContext.sceneSetupIndex < 4) && (temp_t5 = D_8011FB30 - 1, ((temp_t5 < 5U) != 0))) {
            goto **(&jtbl_8013C790 + (temp_t5 * 4));
        case 0:
            envCtx->gloomySky = (u8)1U;
            envCtx->unk_18 = (u8)1U;
            envCtx->unk_1F = (u8)3U;
            envCtx->unk_20 = (u8)3U;
            globalCtx->unk10B15 = (u8)0;
            goto block_13;
        default:
            envCtx->gloomySky = (u8)1U;
            envCtx->unk_18 = (u8)1U;
            envCtx->unk_1F = (u8)2U;
            envCtx->unk_20 = (u8)2U;
            globalCtx->unk10B15 = (u8)0;
            goto block_13;
        case 4:
            envCtx->gloomySky = (u8)1U;
            envCtx->unk_18 = (u8)1U;
            envCtx->unk_1F = (u8)4U;
            envCtx->unk_20 = (u8)4U;
            globalCtx->unk10B15 = (u8)0;
            globalCtx->unk10B14 = (u8)0;
            goto block_14;
block_13:
            globalCtx->unk10B14 = (u8)0;
block_14:
            if (((u16)1 == globalCtx->skyboxId) && (D_8011FB30 == 3)) {
                globalCtx->unk10B15 = (u8)0x40;
                globalCtx->unk10B14 = (u8)0x40;
            } else {
block_21:
            }
        } else {
            goto block_21;
        }
    } else {
        D_8011FB30 = (u8)0U;
    }
    D_8011FB38 = (u8)0U;
    D_8011FB34 = (u8)0;
    D_8011FB3C = (u8)0;
    gSaveContext.unk13C3 = (u8)0U;
    gGameInfo->unkB5A = (u16)0x50;
    gGameInfo->unkB5C = (u16)0x50;
    gGameInfo->unkB5E = (u16)0x50;
    gGameInfo->unkB60 = (u16)-0x50;
    gGameInfo->unkB62 = (u16)-0x50;
    gGameInfo->unkB64 = (u16)-0x50;
    gGameInfo->unkB66 = (u16)0xA;
    gGameInfo->unkB68 = (u16)0;
    gGameInfo->unkB6A = (u16)0;
    gGameInfo->unkB6C = (u16)0;
    gGameInfo->unkB6E = (u16)0;
    gGameInfo->unkB70 = (u16)0;
    D_8015FCC8 = (u8)1;
    phi_v0 = 0;
loop_24:
    temp_v0 = (phi_v0 + 1) & 0xFF;
    *(&D_8015FD10 + (phi_v0 << 5)) = (u8)0xFFU;
    phi_v0 = temp_v0;
    if (temp_v0 < 3) {
        goto loop_24;
    }
    globalCtx->unk_11D30 = (u16)0;
    globalCtx->unk11D32 = (u16)0;
    phi_v0_2 = 0;
loop_26:
    temp_v0_2 = (phi_v0_2 + 1) & 0xFF;
    globalCtx->csCtx.npcActions[phi_v0_2] = NULL;
    phi_v0_2 = temp_v0_2;
    if (temp_v0_2 < 0xA) {
        goto loop_26;
    }
    sp34 = temp_a2;
    if (Object_GetIndex(&globalCtx->objectCtx, (u16)2) < 0) {
        if (globalCtx->envCtx.sunMoonDisabled == 0) {
            globalCtx->envCtx.sunMoonDisabled = (u8)1U;
            osSyncPrintf((const char *) "\x1b[43;30m\n\nフィールド常駐以外、太陽設定！よって強制解除！\n\x1b[m", temp_a2);
        }
    }
    D_8015FCF0 = (u8)0U;
    func_800AA15C();
}
lucas@DES
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
