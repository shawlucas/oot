#include "global.h"
#include "vt.h"

s32 sMapSize[] = { 0, 0x10000, 0x20000, 0x30000 };

u16 sIndexData0[2][32] = {
    {
        0x0000, 0x0002, 0x000A, 0x000C, 0x0002, 0x0004, 0x000C, 0x000E, 0x000A, 0x000C, 0x0014,
        0x0016, 0x000C, 0x000E, 0x0016, 0x0018, 0x0001, 0x0003, 0x0005, 0x0006, 0x0007, 0x0008,
        0x0009, 0x000B, 0x000D, 0x000F, 0x0010, 0x0011, 0x0012, 0x0013, 0x0015, 0x0017,
    },

    {
        0x0014, 0x0016, 0x001E, 0x0020, 0x0016, 0x0018, 0x0020, 0x0022, 0x001E, 0x0020, 0x0028,
        0x002A, 0x0020, 0x0022, 0x002A, 0x002C, 0x0015, 0x0017, 0x0019, 0x001A, 0x001B, 0x001C,
        0x001D, 0x001F, 0x0021, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0029, 0x002B,
    },
};

s16 D_8012AD20[] = { 0x0000, 0x0FC0, 0x1F80, 0x2F40, 0x3F00 };

s16 D_8012AD2C[] = { 0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00, 0x26C0, 0x2E80, 0x3640, 0x3E00 };

s16 D_8012AD40[] = {
    0x0000, 0x0010, 0x0013, 0x0012, 0x0010, 0x0001, 0x0014, 0x0013, 0x0001, 0x0011, 0x0015, 0x0014, 0x0011,
    0x0005, 0x0016, 0x0015, 0x0012, 0x0013, 0x0017, 0x0002, 0x0013, 0x0014, 0x0003, 0x0017, 0x0014, 0x0015,
    0x0018, 0x0003, 0x0015, 0x0016, 0x0007, 0x0018, 0x0002, 0x0017, 0x001A, 0x0019, 0x0017, 0x0003, 0x001B,
    0x001A, 0x0003, 0x0018, 0x001C, 0x001B, 0x0018, 0x0007, 0x001D, 0x001C, 0x0019, 0x001A, 0x001E, 0x000A,
    0x001A, 0x001B, 0x000B, 0x001E, 0x001B, 0x001C, 0x001F, 0x000B, 0x001C, 0x001D, 0x000F, 0x001F,
};

s32 D_8012ADC0[] = { 0, 0x2000, 0x4000, 0x6000, 0x8000, 0xC000 };

u16 D_8012ADD8[] = {
    0x0000, 0x0002, 0x000A, 0x000C, 0x0002, 0x0004, 0x000C, 0x000E, 0x000A, 0x000C, 0x0014,
    0x0016, 0x000C, 0x000E, 0x0016, 0x0018, 0x0001, 0x0003, 0x0005, 0x0006, 0x0007, 0x0008,
    0x0009, 0x000B, 0x000D, 0x000F, 0x0010, 0x0011, 0x0012, 0x0013, 0x0015, 0x0017,

};

s16 D_8012AE18[] = { 0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00 };

s16 D_8012AE24[] = { 0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00 };

s16 D_8012AE30[] = { 0x0000, 0x07C0, 0x0F80, 0x07C0, 0x0000 };

s16 D_8012AE3C[] = {
    0x0000, 0x0010, 0x0013, 0x0012, 0x0010, 0x0001, 0x0014, 0x0013, 0x0001, 0x0011, 0x0015, 0x0014, 0x0011,
    0x0005, 0x0016, 0x0015, 0x0012, 0x0013, 0x0017, 0x0002, 0x0013, 0x0014, 0x0003, 0x0017, 0x0014, 0x0015,
    0x0018, 0x0003, 0x0015, 0x0016, 0x0007, 0x0018, 0x0002, 0x0017, 0x001A, 0x0019, 0x0017, 0x0003, 0x001B,
    0x001A, 0x0003, 0x0018, 0x001C, 0x001B, 0x0018, 0x0007, 0x001D, 0x001C, 0x0019, 0x001A, 0x001E, 0x000A,
    0x001A, 0x001B, 0x000B, 0x001E, 0x001B, 0x001C, 0x001F, 0x000B, 0x001C, 0x001D, 0x000F, 0x001F,
};

RoomDef D_8012AEBC[] = {
    { 0xFFFFFF82, 0x0000007C, 0xFFFFFF82, 0x0000003F, 0xFFFFFFE1 },
    { 0x0000007E, 0x0000007C, 0xFFFFFF82, 0x0000003F, 0xFFFFFFE1 },
    { 0x0000007E, 0x0000007C, 0x0000007E, 0xFFFFFFC1, 0xFFFFFFE1 },
    { 0xFFFFFF82, 0x0000007C, 0x0000007E, 0xFFFFFFC1, 0xFFFFFFE1 },
};

RoomDef D_8012AF0C[] = {
    { 0xFFFFFFC0, 0x00000040, 0xFFFFFFC0, 0x00000020, 0xFFFFFFE0 },
    { 0x00000040, 0x00000040, 0x00000040, 0xFFFFFFE0, 0xFFFFFFE0 },
    { 0xFFFFFFC0, 0x00000040, 0x00000040, 0xFFFFFFE0, 0xFFFFFFE0 },
    { 0x00000040, 0x00000040, 0xFFFFFFC0, 0x00000020, 0xFFFFFFE0 },
    { 0xFFFFFFC0, 0x00000040, 0x00000040, 0x00000020, 0xFFFFFFE0 },
    { 0xFFFFFFC0, 0xFFFFFFC0, 0xFFFFFFC0, 0x00000020, 0x00000020 },
};

s32 func_800ADBB0(SkyboxContext* this, Vtx_t* vtx, s32 vi, s32 x, s32 y, s32 z, s32 width, s32 height);
s32 func_800AE2C0(SkyboxContext* this, Vtx_t* vtx, s32 vi, s32 x, s32 y, s32 z, s32 width, s32 height, s32 arg8);
s32 func_800AF178(SkyboxContext* this, s32 arg1);
void func_800AF218(GameState* game, SkyboxContext* this, s16 skyboxId);
void func_800B0E50(GameState* game, SkyboxContext* skyboxCtx, s16 skyboxId); // VrBox_Init

#pragma GLOBAL_ASM("asm/non_matchings/code/z_vr_box/func_800ADBB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_vr_box/func_800AE2C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_vr_box/func_800AEFC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_vr_box/func_800AF178.s")

//
#if 0
void func_800AF218(GameState* game, SkyboxContext *this, s16 skyboxId) {
    u32 sp44;
    u8 sp41;
    u8 sp40;
    u8 *sp30;
    void *sp2C;
    s16 temp_v0_2;
    s32 temp_t0;
    s32 temp_t0_2;
    u16 temp_a0;
    u16 temp_v1;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_t6;
    u32 temp_v0_6;
    u32 temp_v0_8;
    u8 *temp_v0_3;
    u8 temp_t5;
    u8 temp_t8;
    u8 temp_v0;
    void **temp_v0_10;
    void **temp_v0_12;
    void **temp_v0_15;
    void **temp_v0_17;
    void **temp_v0_20;
    void **temp_v0_22;
    void **temp_v0_24;
    void **temp_v0_26;
    void **temp_v0_28;
    void **temp_v0_30;
    void **temp_v0_32;
    void **temp_v0_34;
    void **temp_v0_36;
    void **temp_v0_38;
    void **temp_v0_40;
    void **temp_v0_42;
    void **temp_v0_44;
    void **temp_v0_46;
    void **temp_v0_48;
    void **temp_v0_4;
    void **temp_v0_50;
    void **temp_v0_52;
    void **temp_v0_54;
    void **temp_v0_56;
    void **temp_v0_58;
    void *temp_a1_10;
    void *temp_a1_11;
    void *temp_a1_12;
    void *temp_a1_13;
    void *temp_a1_14;
    void *temp_a1_15;
    void *temp_a1_16;
    void *temp_a1_17;
    void *temp_a1_18;
    void *temp_a1_19;
    void *temp_a1_20;
    void *temp_a1_21;
    void *temp_a1_22;
    void *temp_a1_23;
    void *temp_a1_24;
    void *temp_a1_25;
    void *temp_a1_26;
    void *temp_a1_27;
    void *temp_a1_28;
    void *temp_a1_29;
    void *temp_a1_30;
    void *temp_a1_31;
    void *temp_a1_32;
    void *temp_a1_33;
    void *temp_a1_34;
    void *temp_a1_35;
    void *temp_a1_36;
    void *temp_a1_37;
    void *temp_a1_38;
    void *temp_a1_39;
    void *temp_a1_3;
    void *temp_a1_40;
    void *temp_a1_41;
    void *temp_a1_42;
    void *temp_a1_43;
    void *temp_a1_44;
    void *temp_a1_45;
    void *temp_a1_46;
    void *temp_a1_47;
    void *temp_a1_48;
    void *temp_a1_49;
    void *temp_a1_4;
    void *temp_a1_5;
    void *temp_a1_6;
    void *temp_a1_7;
    void *temp_a1_8;
    void *temp_a1_9;
    void *temp_a3;
    void *temp_v0_11;
    void *temp_v0_13;
    void *temp_v0_14;
    void *temp_v0_16;
    void *temp_v0_18;
    void *temp_v0_19;
    void *temp_v0_21;
    void *temp_v0_23;
    void *temp_v0_25;
    void *temp_v0_27;
    void *temp_v0_29;
    void *temp_v0_31;
    void *temp_v0_33;
    void *temp_v0_35;
    void *temp_v0_37;
    void *temp_v0_39;
    void *temp_v0_41;
    void *temp_v0_43;
    void *temp_v0_45;
    void *temp_v0_47;
    void *temp_v0_49;
    void *temp_v0_51;
    void *temp_v0_53;
    void *temp_v0_55;
    void *temp_v0_57;
    void *temp_v0_59;
    void *temp_v0_5;
    void *temp_v0_7;
    void *temp_v0_9;
    void *temp_v1_2;
    s32 phi_v1;
    s16 phi_v0;

    u32 size;
    s16 i;
    u8 vrBox0;
    u8 vrBox1;
    u8 vrBoxPat;
    GlobalContext* globalCtx = (GlobalContext *)game;

    switch (skyboxId - 1) {
    case 0:
        phi_v1 = 0;
        if (gSaveContext.unk_13C3 != 0) {
            phi_v1 = 0;
            if (gSaveContext.sceneSetupIndex < 4) {
                temp_v0 = D_8011FB30;
                phi_v1 = 0;
                if (D_8011FB30 > 0) {
                    phi_v1 = 0;
                    if (D_8011FB30 < 6) {
                        phi_v1 = 1;
                    }
                }
            }
        }
        temp_a0 = gSaveContext.environmentTime;
        phi_v0 = 0;
loop_8:
        temp_a3 = (((phi_v1 * 8) + phi_v1) * 8) + &D_8011FC1C + (phi_v0 * 8);
        temp_v0_2 = phi_v0 + 1;
        if ((s32) temp_a0 >= (s32) temp_a3->unk0) {
            temp_v1 = temp_a3->unk2;
            if (((s32) temp_a0 < (s32) temp_v1) || (0xFFFF == temp_v1)) {
                temp_t5 = temp_a3->unk5;
                sp41 = temp_t5;
                globalCtx->envCtx.unk_10 = temp_t5;
                temp_t8 = temp_a3->unk6;
                sp40 = temp_t8;
                globalCtx->unk10A35 = temp_t8;
                if (temp_a3->unk4 != 0) {
                    globalCtx->envCtx.unk_13 = (u8) (u32) (func_8006F93C(temp_a3->unk2, temp_a3->unk0, gSaveContext.environmentTime) * 255.0f);
                } else {
                    globalCtx->envCtx.unk_13 = 0;
                }
            } else {
block_14:
                phi_v0 = temp_v0_2;
                if ((s32) temp_v0_2 < 9) {
                    goto loop_8;
                }
            }
        } else {
            goto block_14;
        }
        temp_v0_3 = (sp41 * 0x10) + &D_8011FD3C;
        temp_a1 = temp_v0_3->unk4 - temp_v0_3->unk0;
        sp44 = temp_a1;
        sp30 = temp_v0_3;
        temp_v0_4 = GameState_Alloc((GameState *) globalCtx, temp_a1, "../z_vr_box.c", 0x41E);
        this->staticSegments = temp_v0_4;
        if (temp_v0_4 == 0) {
            __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x41F);
        }
        DmaMgr_SendRequest1((void *) this->staticSegments, sp30->unk0, sp44, "../z_vr_box.c", 0x422);
        temp_v1_2 = (sp40 * 0x10) + &D_8011FD3C;
        temp_a1_2 = temp_v1_2->unk4 - temp_v1_2->unk0;
        sp44 = temp_a1_2;
        sp2C = temp_v1_2;
        temp_v0_5 = GameState_Alloc((GameState *) globalCtx, temp_a1_2, "../z_vr_box.c", 0x424);
        this->unk12C = temp_v0_5;
        if (temp_v0_5 == 0) {
            __assert("vr_box->vr_box_staticSegment[1] != NULL", "../z_vr_box.c", 0x425);
        }
        DmaMgr_SendRequest1(this->unk12C, sp2C->unk0, sp44, "../z_vr_box.c", 0x428);
        if ((sp41 & 1) == ((s32) (sp41 & 4) >> 2)) {
            temp_v0_8 = sp30->unkC - sp30->unk8;
            sp44 = temp_v0_8;
            temp_v0_9 = GameState_Alloc((GameState *) globalCtx, temp_v0_8 * 2, "../z_vr_box.c", 0x43D);
            this->unk130 = temp_v0_9;
            if (temp_v0_9 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x43E);
            }
            DmaMgr_SendRequest1(this->unk130, sp2C->unk8, sp44, "../z_vr_box.c", 0x440);
            DmaMgr_SendRequest1(this->unk130 + sp44, sp30->unk8, sp44, "../z_vr_box.c", 0x442);
            return;
        case 1:
            this->unk_140 = 1;
            temp_a1_3 = _vr_SP1a_staticSegmentRomEnd - _vr_SP1a_staticSegmentRomStart;
            sp2C = temp_a1_3;
            sp30 = _vr_SP1a_staticSegmentRomStart;
            temp_v0_10 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_3, "../z_vr_box.c", 0x467);
            this->staticSegments = temp_v0_10;
            if (temp_v0_10 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x468);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x469);
            temp_a1_4 = &_vr_SP1a_pal_staticSegmentRomEnd - &_vr_SP1a_pal_staticSegmentRomStart;
            sp2C = temp_a1_4;
            sp30 = &_vr_SP1a_pal_staticSegmentRomStart;
            temp_v0_11 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_4, "../z_vr_box.c", 0x46C);
            this->unk130 = temp_v0_11;
            if (temp_v0_11 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x46D);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x46E);
            this->rot.y = 0.8f;
            return;
        case 2:
            temp_a1_5 = _vr_cloud2_staticSegmentRomEnd - _vr_cloud2_staticSegmentRomStart;
            sp2C = temp_a1_5;
            sp30 = _vr_cloud2_staticSegmentRomStart;
            temp_v0_12 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_5, "../z_vr_box.c", 0x483);
            this->staticSegments = temp_v0_12;
            if (temp_v0_12 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x484);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x487);
            temp_v0_13 = GameState_Alloc((GameState *) globalCtx, (u32) sp2C, "../z_vr_box.c", 0x48A);
            this->unk12C = temp_v0_13;
            if (temp_v0_13 == 0) {
                __assert("vr_box->vr_box_staticSegment[1] != NULL", "../z_vr_box.c", 0x48B);
            }
            DmaMgr_SendRequest1(this->unk12C, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x48E);
            temp_t0 = _vr_cloud2_pal_staticSegmentRomEnd - _vr_cloud2_pal_staticSegmentRomStart;
            sp2C = (void *) temp_t0;
            sp30 = _vr_cloud2_pal_staticSegmentRomStart;
            temp_v0_14 = GameState_Alloc((GameState *) globalCtx, temp_t0 * 2, "../z_vr_box.c", 0x492);
            this->unk130 = temp_v0_14;
            if (temp_v0_14 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x493);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x495);
            DmaMgr_SendRequest1(this->unk130 + sp2C, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x497);
            return;
        case 3:
            this->unk_140 = 1;
            temp_a1_6 = _vr_RUVR_staticSegmentRomEnd - _vr_RUVR_staticSegmentRomStart;
            sp2C = temp_a1_6;
            sp30 = _vr_RUVR_staticSegmentRomStart;
            temp_v0_15 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_6, "../z_vr_box.c", 0x49E);
            this->staticSegments = temp_v0_15;
            if (temp_v0_15 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x49F);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4A0);
            temp_a1_7 = _vr_RUVR_pal_staticSegmentRomEnd - _vr_RUVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_7;
            sp30 = _vr_RUVR_pal_staticSegmentRomStart;
            osSyncPrintf("ＳＩＺＥ = %d\n", temp_a1_7);
            temp_v0_16 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_7, "../z_vr_box.c", 0x4A4);
            this->unk130 = temp_v0_16;
            if (temp_v0_16 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x4A5);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4A6);
            return;
        case 4:
            temp_a1_8 = _vr_holy0_staticSegmentRomEnd - _vr_holy0_staticSegmentRomStart;
            sp2C = temp_a1_8;
            sp30 = _vr_holy0_staticSegmentRomStart;
            temp_v0_17 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_8, "../z_vr_box.c", 0x4AC);
            this->staticSegments = temp_v0_17;
            if (temp_v0_17 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x4AD);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4B0);
            temp_a1_9 = _vr_holy1_staticSegmentRomEnd - _vr_holy1_staticSegmentRomStart;
            sp2C = temp_a1_9;
            sp30 = _vr_holy1_staticSegmentRomStart;
            temp_v0_18 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_9, "../z_vr_box.c", 0x4B3);
            this->unk12C = temp_v0_18;
            if (temp_v0_18 == 0) {
                __assert("vr_box->vr_box_staticSegment[1] != NULL", "../z_vr_box.c", 0x4B4);
            }
            DmaMgr_SendRequest1(this->unk12C, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4B7);
            temp_t0_2 = _vr_holy0_pal_staticSegmentRomEnd - _vr_holy0_pal_staticSegmentRomStart;
            sp2C = (void *) temp_t0_2;
            sp30 = _vr_holy0_pal_staticSegmentRomStart;
            temp_v0_19 = GameState_Alloc((GameState *) globalCtx, temp_t0_2 * 2, "../z_vr_box.c", 0x4BB);
            this->unk130 = temp_v0_19;
            if (temp_v0_19 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x4BC);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4BE);
            DmaMgr_SendRequest1(this->unk130 + sp2C, (u32) _vr_holy1_pal_staticSegmentRomStart, (u32) sp2C, "../z_vr_box.c", 0x4C0);
            return;
        case 6:
            this->unk_140 = 1;
            temp_a1_10 = _vr_LHVR_staticSegmentRomEnd - _vr_LHVR_staticSegmentRomStart;
            sp2C = temp_a1_10;
            sp30 = _vr_LHVR_staticSegmentRomStart;
            temp_v0_20 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_10, "../z_vr_box.c", 0x4CA);
            this->staticSegments = temp_v0_20;
            if (temp_v0_20 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x4CB);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4CC);
            temp_a1_11 = &_vr_LHVR_pal_staticSegmentRomEnd - &_vr_LHVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_11;
            sp30 = &_vr_LHVR_pal_staticSegmentRomStart;
            temp_v0_21 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_11, "../z_vr_box.c", 0x4CF);
            this->unk130 = temp_v0_21;
            if (temp_v0_21 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x4D0);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4D1);
            return;
        case 8:
            this->unk_140 = 1;
            temp_a1_12 = _vr_MDVR_staticSegmentRomEnd - _vr_MDVR_staticSegmentRomStart;
            sp2C = temp_a1_12;
            sp30 = _vr_MDVR_staticSegmentRomStart;
            temp_v0_22 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_12, "../z_vr_box.c", 0x4E9);
            this->staticSegments = temp_v0_22;
            if (temp_v0_22 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x4EA);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4EB);
            temp_a1_13 = _vr_MDVR_pal_staticSegmentRomEnd - _vr_MDVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_13;
            sp30 = _vr_MDVR_pal_staticSegmentRomStart;
            temp_v0_23 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_13, "../z_vr_box.c", 0x4EE);
            this->unk130 = temp_v0_23;
            if (temp_v0_23 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x4EF);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4F0);
            return;
        case 9:
            this->unk_140 = 1;
            temp_a1_14 = _vr_MNVR_staticSegmentRomEnd - _vr_MNVR_staticSegmentRomStart;
            sp2C = temp_a1_14;
            sp30 = _vr_MNVR_staticSegmentRomStart;
            temp_v0_24 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_14, "../z_vr_box.c", 0x4F7);
            this->staticSegments = temp_v0_24;
            if (temp_v0_24 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x4F8);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4F9);
            temp_a1_15 = _vr_MNVR_pal_staticSegmentRomEnd - _vr_MNVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_15;
            sp30 = _vr_MNVR_pal_staticSegmentRomStart;
            osSyncPrintf("ＳＩＺＥ = %d\n", temp_a1_15);
            temp_v0_25 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_15, "../z_vr_box.c", 0x4FD);
            this->unk130 = temp_v0_25;
            if (temp_v0_25 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x4FE);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x4FF);
            return;
        case 10:
            this->unk_140 = 1;
            temp_a1_16 = _vr_FCVR_staticSegmentRomEnd - _vr_FCVR_staticSegmentRomStart;
            sp2C = temp_a1_16;
            sp30 = _vr_FCVR_staticSegmentRomStart;
            temp_v0_26 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_16, "../z_vr_box.c", 0x506);
            this->staticSegments = temp_v0_26;
            if (temp_v0_26 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x507);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x508);
            temp_a1_17 = &_vr_FCVR_pal_staticSegmentRomEnd - &_vr_FCVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_17;
            sp30 = &_vr_FCVR_pal_staticSegmentRomStart;
            temp_v0_27 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_17, "../z_vr_box.c", 0x50B);
            this->unk130 = temp_v0_27;
            if (temp_v0_27 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x50C);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x50D);
            this->rot.y = 0.8f;
            return;
        case 11:
            this->unk_140 = 1;
            temp_a1_18 = _vr_KHVR_staticSegmentRomEnd - _vr_KHVR_staticSegmentRomStart;
            sp2C = temp_a1_18;
            sp30 = _vr_KHVR_staticSegmentRomStart;
            temp_v0_28 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_18, "../z_vr_box.c", 0x515);
            this->staticSegments = temp_v0_28;
            if (temp_v0_28 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x516);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x517);
            temp_a1_19 = &_vr_KHVR_pal_staticSegmentRomEnd - &_vr_KHVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_19;
            sp30 = &_vr_KHVR_pal_staticSegmentRomStart;
            temp_v0_29 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_19, "../z_vr_box.c", 0x51A);
            this->unk130 = temp_v0_29;
            if (temp_v0_29 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x51B);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x51C);
            return;
        case 13:
            this->unk_140 = 2;
            temp_a1_20 = _vr_K3VR_staticSegmentRomEnd - _vr_K3VR_staticSegmentRomStart;
            sp2C = temp_a1_20;
            sp30 = _vr_K3VR_staticSegmentRomStart;
            temp_v0_30 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_20, "../z_vr_box.c", 0x533);
            this->staticSegments = temp_v0_30;
            if (temp_v0_30 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x534);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x535);
            temp_a1_21 = &_vr_K3VR_pal_staticSegmentRomEnd - &_vr_K3VR_pal_staticSegmentRomStart;
            sp2C = temp_a1_21;
            sp30 = &_vr_K3VR_pal_staticSegmentRomStart;
            temp_v0_31 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_21, "../z_vr_box.c", 0x538);
            this->unk130 = temp_v0_31;
            if (temp_v0_31 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x539);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x53A);
            return;
        case 14:
            this->unk_140 = 1;
            temp_a1_22 = _vr_MLVR_staticSegmentRomEnd - _vr_MLVR_staticSegmentRomStart;
            sp2C = temp_a1_22;
            sp30 = _vr_MLVR_staticSegmentRomStart;
            temp_v0_32 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_22, "../z_vr_box.c", 0x541);
            this->staticSegments = temp_v0_32;
            if (temp_v0_32 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x542);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x543);
            temp_a1_23 = &_vr_MLVR_pal_staticSegmentRomEnd - &_vr_MLVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_23;
            sp30 = &_vr_MLVR_pal_staticSegmentRomStart;
            temp_v0_33 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_23, "../z_vr_box.c", 0x546);
            this->unk130 = temp_v0_33;
            if (temp_v0_33 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x547);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x548);
            return;
        case 15:
            this->unk_140 = 1;
            temp_a1_24 = _vr_KKRVR_staticSegmentRomEnd - _vr_KKRVR_staticSegmentRomStart;
            sp2C = temp_a1_24;
            sp30 = _vr_KKRVR_staticSegmentRomStart;
            temp_v0_34 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_24, "../z_vr_box.c", 0x54F);
            this->staticSegments = temp_v0_34;
            if (temp_v0_34 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x550);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x551);
            temp_a1_25 = &_vr_KKRVR_pal_staticSegmentRomEnd - &_vr_KKRVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_25;
            sp30 = &_vr_KKRVR_pal_staticSegmentRomStart;
            temp_v0_35 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_25, "../z_vr_box.c", 0x554);
            this->unk130 = temp_v0_35;
            if (temp_v0_35 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x555);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x556);
            return;
        case 16:
            this->unk_140 = 1;
            temp_a1_26 = _vr_KSVR_staticSegmentRomEnd - _vr_KSVR_staticSegmentRomStart;
            sp2C = temp_a1_26;
            sp30 = _vr_KSVR_staticSegmentRomStart;
            temp_v0_36 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_26, "../z_vr_box.c", 0x55D);
            this->staticSegments = temp_v0_36;
            if (temp_v0_36 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x55E);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x55F);
            temp_a1_27 = &_vr_KSVR_pal_staticSegmentRomEnd - &_vr_KSVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_27;
            sp30 = &_vr_KSVR_pal_staticSegmentRomStart;
            temp_v0_37 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_27, "../z_vr_box.c", 0x562);
            this->unk130 = temp_v0_37;
            if (temp_v0_37 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x563);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x564);
            this->rot.y = 0.8f;
            return;
        case 18:
            this->unk_140 = 1;
            temp_a1_28 = _vr_GLVR_staticSegmentRomEnd - _vr_GLVR_staticSegmentRomStart;
            sp2C = temp_a1_28;
            sp30 = _vr_GLVR_staticSegmentRomStart;
            temp_v0_38 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_28, "../z_vr_box.c", 0x57D);
            this->staticSegments = temp_v0_38;
            if (temp_v0_38 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x57E);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x57F);
            temp_a1_29 = &_vr_GLVR_pal_staticSegmentRomEnd - &_vr_GLVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_29;
            sp30 = &_vr_GLVR_pal_staticSegmentRomStart;
            temp_v0_39 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_29, "../z_vr_box.c", 0x582);
            this->unk130 = temp_v0_39;
            if (temp_v0_39 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x583);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x584);
            this->rot.y = 0.8f;
            return;
        case 19:
            this->unk_140 = 1;
            temp_a1_30 = _vr_ZRVR_staticSegmentRomEnd - _vr_ZRVR_staticSegmentRomStart;
            sp2C = temp_a1_30;
            sp30 = _vr_ZRVR_staticSegmentRomStart;
            temp_v0_40 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_30, "../z_vr_box.c", 0x58C);
            this->staticSegments = temp_v0_40;
            if (temp_v0_40 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x58D);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x58E);
            temp_a1_31 = &_vr_ZRVR_pal_staticSegmentRomEnd - &_vr_ZRVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_31;
            sp30 = &_vr_ZRVR_pal_staticSegmentRomStart;
            temp_v0_41 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_31, "../z_vr_box.c", 0x591);
            this->unk130 = temp_v0_41;
            if (temp_v0_41 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x592);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x593);
            this->rot.y = 0.8f;
            return;
        case 21:
            this->unk_140 = 1;
            temp_a1_32 = _vr_DGVR_staticSegmentRomEnd - _vr_DGVR_staticSegmentRomStart;
            sp2C = temp_a1_32;
            sp30 = _vr_DGVR_staticSegmentRomStart;
            temp_v0_42 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_32, "../z_vr_box.c", 0x5AB);
            this->staticSegments = temp_v0_42;
            if (temp_v0_42 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x5AC);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5AD);
            temp_a1_33 = &_vr_DGVR_pal_staticSegmentRomEnd - &_vr_DGVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_33;
            sp30 = &_vr_DGVR_pal_staticSegmentRomStart;
            temp_v0_43 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_33, "../z_vr_box.c", 0x5B0);
            this->unk130 = temp_v0_43;
            if (temp_v0_43 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x5B1);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5B2);
            this->rot.y = 0.8f;
            return;
        case 22:
            this->unk_140 = 1;
            temp_a1_34 = _vr_ALVR_staticSegmentRomEnd - _vr_ALVR_staticSegmentRomStart;
            sp2C = temp_a1_34;
            sp30 = _vr_ALVR_staticSegmentRomStart;
            temp_v0_44 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_34, "../z_vr_box.c", 0x5BA);
            this->staticSegments = temp_v0_44;
            if (temp_v0_44 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x5BB);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5BC);
            temp_a1_35 = &_vr_ALVR_pal_staticSegmentRomEnd - &_vr_ALVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_35;
            sp30 = &_vr_ALVR_pal_staticSegmentRomStart;
            temp_v0_45 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_35, "../z_vr_box.c", 0x5BF);
            this->unk130 = temp_v0_45;
            if (temp_v0_45 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x5C0);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5C1);
            this->rot.y = 0.8f;
            return;
        case 23:
            this->unk_140 = 1;
            temp_a1_36 = _vr_NSVR_staticSegmentRomEnd - _vr_NSVR_staticSegmentRomStart;
            sp2C = temp_a1_36;
            sp30 = _vr_NSVR_staticSegmentRomStart;
            temp_v0_46 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_36, "../z_vr_box.c", 0x5C9);
            this->staticSegments = temp_v0_46;
            if (temp_v0_46 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x5CA);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5CB);
            temp_a1_37 = &_vr_NSVR_pal_staticSegmentRomEnd - &_vr_NSVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_37;
            sp30 = &_vr_NSVR_pal_staticSegmentRomStart;
            temp_v0_47 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_37, "../z_vr_box.c", 0x5CE);
            this->unk130 = temp_v0_47;
            if (temp_v0_47 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x5CF);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5D0);
            this->rot.y = 0.8f;
            return;
        case 25:
            this->unk_140 = 1;
            temp_a1_38 = _vr_IPVR_staticSegmentRomEnd - _vr_IPVR_staticSegmentRomStart;
            sp2C = temp_a1_38;
            sp30 = _vr_IPVR_staticSegmentRomStart;
            temp_v0_48 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_38, "../z_vr_box.c", 0x5E8);
            this->staticSegments = temp_v0_48;
            if (temp_v0_48 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x5E9);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5EA);
            temp_a1_39 = &_vr_IPVR_pal_staticSegmentRomEnd - &_vr_IPVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_39;
            sp30 = &_vr_IPVR_pal_staticSegmentRomStart;
            temp_v0_49 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_39, "../z_vr_box.c", 0x5ED);
            this->unk130 = temp_v0_49;
            if (temp_v0_49 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x5EE);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5EF);
            return;
        case 26:
            this->unk_140 = 1;
            temp_a1_40 = _vr_LBVR_staticSegmentRomEnd - _vr_LBVR_staticSegmentRomStart;
            sp2C = temp_a1_40;
            sp30 = _vr_LBVR_staticSegmentRomStart;
            temp_v0_50 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_40, "../z_vr_box.c", 0x5F6);
            this->staticSegments = temp_v0_50;
            if (temp_v0_50 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x5F7);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5F8);
            temp_a1_41 = &_vr_LBVR_pal_staticSegmentRomEnd - &_vr_LBVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_41;
            sp30 = &_vr_LBVR_pal_staticSegmentRomStart;
            temp_v0_51 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_41, "../z_vr_box.c", 0x5FB);
            this->unk130 = temp_v0_51;
            if (temp_v0_51 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x5FC);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x5FD);
            return;
        case 27:
            this->unk_140 = 2;
            temp_a1_42 = _vr_TTVR_staticSegmentRomEnd - _vr_TTVR_staticSegmentRomStart;
            sp2C = temp_a1_42;
            sp30 = _vr_TTVR_staticSegmentRomStart;
            temp_v0_52 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_42, "../z_vr_box.c", 0x604);
            this->staticSegments = temp_v0_52;
            if (temp_v0_52 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x605);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x606);
            temp_a1_43 = &_vr_TTVR_pal_staticSegmentRomEnd - &_vr_TTVR_pal_staticSegmentRomStart;
            sp2C = temp_a1_43;
            sp30 = &_vr_TTVR_pal_staticSegmentRomStart;
            temp_v0_53 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_43, "../z_vr_box.c", 0x609);
            this->unk130 = temp_v0_53;
            if (temp_v0_53 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x60A);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x60B);
            return;
        case 31:
            this->unk_140 = 2;
            temp_a1_44 = _vr_K4VR_staticSegmentRomEnd - _vr_K4VR_staticSegmentRomStart;
            sp2C = temp_a1_44;
            sp30 = _vr_K4VR_staticSegmentRomStart;
            temp_v0_54 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_44, "../z_vr_box.c", 0x618);
            this->staticSegments = temp_v0_54;
            if (temp_v0_54 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x619);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x61A);
            temp_a1_45 = &_vr_K4VR_pal_staticSegmentRomEnd - &_vr_K4VR_pal_staticSegmentRomStart;
            sp2C = temp_a1_45;
            sp30 = &_vr_K4VR_pal_staticSegmentRomStart;
            temp_v0_55 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_45, "../z_vr_box.c", 0x61D);
            this->unk130 = temp_v0_55;
            if (temp_v0_55 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x61E);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x61F);
            return;
        case 32:
            this->unk_140 = 2;
            temp_a1_46 = _vr_K5VR_staticSegmentRomEnd - _vr_K5VR_staticSegmentRomStart;
            sp2C = temp_a1_46;
            sp30 = _vr_K5VR_staticSegmentRomStart;
            temp_v0_56 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_46, "../z_vr_box.c", 0x626);
            this->staticSegments = temp_v0_56;
            if (temp_v0_56 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x627);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x628);
            temp_a1_47 = &_vr_K5VR_pal_staticSegmentRomEnd - &_vr_K5VR_pal_staticSegmentRomStart;
            sp2C = temp_a1_47;
            sp30 = &_vr_K5VR_pal_staticSegmentRomStart;
            temp_v0_57 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_47, "../z_vr_box.c", 0x62B);
            this->unk130 = temp_v0_57;
            if (temp_v0_57 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x62C);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x62D);
            return;
        case 33:
            this->unk_140 = 2;
            temp_a1_48 = _vr_KR3VR_staticSegmentRomEnd - _vr_KR3VR_staticSegmentRomStart;
            sp2C = temp_a1_48;
            sp30 = _vr_KR3VR_staticSegmentRomStart;
            temp_v0_58 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_48, "../z_vr_box.c", 0x634);
            this->staticSegments = temp_v0_58;
            if (temp_v0_58 == 0) {
                __assert("vr_box->vr_box_staticSegment[0] != NULL", "../z_vr_box.c", 0x635);
            }
            DmaMgr_SendRequest1((void *) this->staticSegments, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x636);
            temp_a1_49 = &_vr_KR3VR_pal_staticSegmentRomEnd - &_vr_KR3VR_pal_staticSegmentRomStart;
            sp2C = temp_a1_49;
            sp30 = &_vr_KR3VR_pal_staticSegmentRomStart;
            temp_v0_59 = GameState_Alloc((GameState *) globalCtx, (u32) temp_a1_49, "../z_vr_box.c", 0x639);
            this->unk130 = temp_v0_59;
            if (temp_v0_59 == 0) {
                __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x63A);
            }
            DmaMgr_SendRequest1(this->unk130, (u32) sp30, (u32) sp2C, "../z_vr_box.c", 0x63B);
        default:
            return;
        }
        temp_v0_6 = sp30->unkC - sp30->unk8;
        sp44 = temp_v0_6;
        temp_v0_7 = GameState_Alloc((GameState *) globalCtx, temp_v0_6 * 2, "../z_vr_box.c", 0x430);
        this->unk130 = temp_v0_7;
        if (temp_v0_7 == 0) {
            __assert("vr_box->vr_box_staticSegment[2] != NULL", "../z_vr_box.c", 0x431);
        }
        DmaMgr_SendRequest1(this->unk130, sp30->unk8, sp44, "../z_vr_box.c", 0x433);
        DmaMgr_SendRequest1(this->unk130 + sp44, sp2C->unk8, sp44, "../z_vr_box.c", 0x435);
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
        return;
    }
default:
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_vr_box/func_800AF218.s")
#endif
//#pragma GLOBAL_ASM("asm/non_matchings/code/z_vr_box/func_800B0E50.s")

void func_800B0E50(GameState *game, SkyboxContext *skyboxCtx, s16 skyboxId) {
    skyboxCtx->unk_140 = 0;
    skyboxCtx->rot.x = 0.0f;
    skyboxCtx->rot.y = 0.0f;
    skyboxCtx->rot.z = 0.0f;
    func_800AF218(game, skyboxCtx, skyboxId);
    osSyncPrintf("\n\n\n＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n\nＴＹＰＥ＝%d\n\n\n＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n\n", skyboxId);
    if (skyboxId != 0) {
        osSyncPrintf(VT_FGCOL(GREEN));
        if (skyboxCtx->unk_140 != 0) {
            skyboxCtx->dpList = GameState_Alloc(game, 0x2580, "../z_vr_box.c", 1636);
            if (skyboxCtx->dpList == NULL) {
                __assert("vr_box->dpList != NULL", "../z_vr_box.c", 1637);
            }
            skyboxCtx->roomVtx = GameState_Alloc(game, 0x1000, "../z_vr_box.c", 1639);
            if (skyboxCtx->roomVtx == NULL) {
                __assert("vr_box->roomVtx != NULL", "../z_vr_box.c", 1640);
            }
            func_800AEFC8(skyboxCtx, skyboxId);
        } else {
            skyboxCtx->dpList = GameState_Alloc(game, 0x3840, "../z_vr_box.c", 1643);
            if (skyboxCtx->dpList == NULL) {
                __assert("vr_box->dpList != NULL", "../z_vr_box.c", 1644);
            }
            if (skyboxId == 5) {
                skyboxCtx->roomVtx = GameState_Alloc(game, 0xC00, "../z_vr_box.c", 1648);
                if (skyboxCtx->roomVtx == NULL) {
                    __assert("vr_box->roomVtx != NULL", "../z_vr_box.c", 1649);
                }
                func_800AF178(skyboxCtx, 6);
            } else {
                skyboxCtx->roomVtx = GameState_Alloc(game, 0xA00, "../z_vr_box.c", 1653);
                if (skyboxCtx->roomVtx == NULL) {
                    __assert("vr_box->roomVtx != NULL", "../z_vr_box.c", 1654);
                }
                func_800AF178(skyboxCtx, 5);
            }
        }
        osSyncPrintf(VT_RST);
    }
}
