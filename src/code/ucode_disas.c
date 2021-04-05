#include "global.h"

#define F3DZEX_CONST(name) \
    { name, #name }
#define F3DZEX_FLAG(set, unset) \
    { set, #set, #unset }
#define F3DZEX_RENDERMODE(name, mask) \
    { #name, name, mask }
#define F3DZEX_SETRENDERMACRO(name, shift, len, value0, value1, value2, value3)                 \
    {                                                                                           \
        name, shift, len, {                                                                     \
            { #value0, value0 }, { #value1, value1 }, { #value2, value2 }, { #value3, value3 }, \
        }                                                                                       \
    }

#define DISAS_LOG        \
    if (this->enableLog) \
    osSyncPrintf

u32 UCodeDisas_TranslateAddr(UCodeDisas* this, u32 addr) {
    u32 physical = this->segments[SEGMENT_NUMBER(addr)] + SEGMENT_OFFSET(addr);
    return PHYSICAL_TO_VIRTUAL(physical);
}

F3dzexConst sUCodeDisasGeometryModes[] = {
    F3DZEX_CONST(G_ZBUFFER),     F3DZEX_CONST(G_TEXTURE_ENABLE),
    F3DZEX_CONST(G_SHADE),       F3DZEX_CONST(G_SHADING_SMOOTH),
    F3DZEX_CONST(G_CULL_FRONT),  F3DZEX_CONST(G_CULL_BACK),
    F3DZEX_CONST(G_FOG),         F3DZEX_CONST(G_LIGHTING),
    F3DZEX_CONST(G_TEXTURE_GEN), F3DZEX_CONST(G_TEXTURE_GEN_LINEAR),
    F3DZEX_CONST(G_LOD),
};

F3dzexFlag sUCodeDisasMtxFlags[] = {
    F3DZEX_FLAG(G_MTX_PROJECTION, G_MTX_MODELVIEW),
    F3DZEX_FLAG(G_MTX_LOAD, G_MTX_MUL),
    F3DZEX_FLAG(G_MTX_PUSH, G_MTX_NOPUSH),
};

const char* UCodeDisas_ParseCombineColor(u32 value, u32 idx) {
    const char* ret = "?";

    switch (value) {
        case G_CCMUX_COMBINED:
            ret = "COMBINED";
            break;
        case G_CCMUX_TEXEL0:
            ret = "TEXEL0";
            break;
        case G_CCMUX_TEXEL1:
            ret = "TEXEL1";
            break;
        case G_CCMUX_PRIMITIVE:
            ret = "PRIMITIVE";
            break;
        case G_CCMUX_SHADE:
            ret = "SHADE";
            break;
        case G_CCMUX_ENVIRONMENT:
            ret = "ENVIRONMENT";
            break;
        case 6:
            ret = (idx == 2) ? "CENTER" : (idx == 3) ? "SCALE" : "1";
            break;
        case 7:
            ret = (idx == 1) ? "NOISE" : (idx == 2) ? "K4" : (idx == 3) ? "COMBINED_ALPHA" : "0";
            break;
        default:
            if (idx == 3) {
                switch (value) {
                    case G_CCMUX_TEXEL0_ALPHA:
                        ret = "TEXEL0_ALPHA";
                        break;
                    case G_CCMUX_TEXEL1_ALPHA:
                        ret = "TEXEL1_ALPHA";
                        break;
                    case G_CCMUX_PRIMITIVE_ALPHA:
                        ret = "PRIMITIVE_ALPHA";
                        break;
                    case G_CCMUX_SHADE_ALPHA:
                        ret = "SHADE_ALPHA";
                        break;
                    case G_CCMUX_ENV_ALPHA:
                        ret = "ENV_ALPHA";
                        break;
                    case G_CCMUX_LOD_FRACTION:
                        ret = "LOD_FRACTION";
                        break;
                    case G_CCMUX_PRIM_LOD_FRAC:
                        ret = "PRIM_LOD_FRAC";
                        break;
                    case G_CCMUX_K5:
                        ret = "K5";
                        break;
                    default:
                        ret = "0";
                        break;
                }
            } else {
                ret = "0";
            }
    }
    return ret;
}

const char* UCodeDisas_ParseCombineAlpha(u32 value, u32 idx) {
    const char* ret = "?";
    switch (value) {
        case 0:
            ret = (idx == 3) ? "LOD_FRACTION" : "COMBINED";
            break;
        case G_ACMUX_TEXEL0:
            ret = "TEXEL0";
            break;
        case G_ACMUX_TEXEL1:
            ret = "TEXEL1";
            break;
        case G_ACMUX_PRIMITIVE:
            ret = "PRIMITIVE";
            break;
        case G_ACMUX_SHADE:
            ret = "SHADE";
            break;
        case G_ACMUX_ENVIRONMENT:
            ret = "ENVIRONMENT";
            break;
        case 6:
            ret = (idx == 3) ? "PRIM_LOD_FRAC" : "1";
            break;
        case G_ACMUX_0:
            ret = "0";
            break;
    }
    return ret;
}

void UCodeDisas_Init(UCodeDisas* this) {
    u32 i;
    bzero(this, sizeof(UCodeDisas));
    for (i = 0; i < NUM_SEGMENTS; i++) {
        this->segments[i] = gSegments[i];
    }
}

void UCodeDisas_Destroy(UCodeDisas* this) {
}

void UCodeDisas_SetCurUCodeImpl(UCodeDisas* this, void* ptr) {
    s32 i;

    for (i = 0; i < this->ucodeInfoCount; i++) {
        if (ptr == this->ucodeInfo[i].ptr) {
            this->ucodeType = this->ucodeInfo[i].type;
            break;
        }
    }
    if (i >= this->ucodeInfoCount) {
        // Microcode did not match
        DISAS_LOG("マイクロコードが一致しなかった\n");
        this->ucodeType = UCODE_NULL;
    }
}

void UCodeDisas_ParseGeometryMode(UCodeDisas* this, u32 mode) {
    u32 first = true;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sUCodeDisasGeometryModes); i++) {
        if ((sUCodeDisasGeometryModes[i].value & mode) == 0) {
            continue;
        }

        if (first) {
        } else {
            DISAS_LOG("|");
        }
        first = false;

        DISAS_LOG("%s", sUCodeDisasGeometryModes[i].name);
    }
}

void UCodeDisas_ParseRenderMode(UCodeDisas* this, u32 mode) {
    static F3dzexRenderMode sUCodeDisasRenderModeFlags[] = {
        F3DZEX_RENDERMODE(AA_EN, 0x8),
        F3DZEX_RENDERMODE(Z_CMP, 0x10),
        F3DZEX_RENDERMODE(Z_UPD, 0x20),
        F3DZEX_RENDERMODE(IM_RD, 0x40),
        F3DZEX_RENDERMODE(CLR_ON_CVG, 0x80),
        F3DZEX_RENDERMODE(CVG_DST_CLAMP, 0x300),
        F3DZEX_RENDERMODE(CVG_DST_WRAP, 0x300),
        F3DZEX_RENDERMODE(CVG_DST_FULL, 0x300),
        F3DZEX_RENDERMODE(CVG_DST_SAVE, 0x300),
        F3DZEX_RENDERMODE(ZMODE_OPA, 0xC00),
        F3DZEX_RENDERMODE(ZMODE_INTER, 0xC00),
        F3DZEX_RENDERMODE(ZMODE_XLU, 0xC00),
        F3DZEX_RENDERMODE(ZMODE_DEC, 0xC00),
        F3DZEX_RENDERMODE(CVG_X_ALPHA, 0x1000),
        F3DZEX_RENDERMODE(ALPHA_CVG_SEL, 0x2000),
        F3DZEX_RENDERMODE(FORCE_BL, 0x4000),
    };
    static const char* D_8012DDDC[4][4] = {
        { "G_BL_CLR_IN", "G_BL_CLR_MEM", "G_BL_CLR_BL", "G_BL_CLR_FOG" },
        { "G_BL_A_IN", "G_BL_A_FOG", "G_BL_A_SHADE", "G_BL_0" },
        { "G_BL_CLR_IN", "G_BL_CLR_MEM", "G_BL_CLR_BL", "G_BL_CLR_FOG" },
        { "G_BL_1MA", "G_BL_A_MEM", "G_BL_1", "G_BL_0" },
    };

    s32 i;
    s32 a;
    s32 b;

    for (i = 0; i < ARRAY_COUNT(sUCodeDisasRenderModeFlags); i++) {
        if ((mode & sUCodeDisasRenderModeFlags[i].mask) != sUCodeDisasRenderModeFlags[i].value) {
            continue;
        }

        DISAS_LOG("%s|", sUCodeDisasRenderModeFlags[i].name);
    }

    a = (mode >> 18) & 0x3333;
    b = (mode >> 16) & 0x3333;

    // clang-format off
    if (this->enableLog == 0) {} else { osSyncPrintf("\nGBL_c1(%s, %s, %s, %s)|",
        D_8012DDDC[0][a >> 12 & 3], D_8012DDDC[1][a >> 8 & 3], D_8012DDDC[2][a >> 4 & 3], D_8012DDDC[3][a >> 0 & 3]); }
    // clang-format on

    if (this->enableLog) {
        osSyncPrintf("\nGBL_c2(%s, %s, %s, %s)", D_8012DDDC[0][b >> 12 & 3], D_8012DDDC[1][b >> 8 & 3],
                     D_8012DDDC[2][b >> 4 & 3], D_8012DDDC[3][b >> 0 & 3]);
    }
}

void UCodeDisas_PrintVertices(UCodeDisas* this, Vtx* vtx, s32 count, s32 start) {
    s32 i;
    for (i = 0; i < count; i++) {
        if (this->geometryMode & G_LIGHTING) {
            DISAS_LOG("\n{{%6d, %6d, %6d, %d, %6d, %6d, %3d, %3d, %3d, %3d}}, /* vc%d */", vtx->n.ob[0], vtx->n.ob[1],
                      vtx->n.ob[2], vtx->n.flag, vtx->n.tc[0], vtx->n.tc[1], vtx->n.n[0], vtx->n.n[1], vtx->n.n[2],
                      vtx->n.a, start + i);
        } else {
            DISAS_LOG("\n{{%6d, %6d, %6d, %d, %6d, %6d, %3d, %3d, %3d, %3d}}, /* vn%d */", vtx->v.ob[0], vtx->v.ob[1],
                      vtx->v.ob[2], vtx->v.flag, vtx->v.tc[0], vtx->v.tc[1], vtx->v.cn[0], vtx->v.cn[1], vtx->v.cn[2],
                      vtx->v.cn[3], start + i);
        }
        vtx++;

        if (1) {}
    }
}

void UCodeDisas_Disassemble(UCodeDisas* this, Gfx* gfx0);
#pragma GLOBAL_ASM("asm/non_matchings/code/ucode_disas/UCodeDisas_Disassemble.rodata.s")
F3dzexSetModeMacro sUCodeDisasModeHMacros[] = {
    F3DZEX_SETRENDERMACRO("SetAlphaDither", G_MDSFT_ALPHADITHER, 2, G_AD_PATTERN, G_AD_NOTPATTERN, G_AD_NOISE,
                          G_AD_DISABLE),
    F3DZEX_SETRENDERMACRO("SetColorDither", G_MDSFT_RGBDITHER, 2, G_CD_MAGICSQ, G_CD_BAYER, G_CD_NOISE, -1),
    F3DZEX_SETRENDERMACRO("SetCombineKey", G_MDSFT_COMBKEY, 1, G_CK_NONE, G_CK_KEY, -1, -1),
    F3DZEX_SETRENDERMACRO("SetTextureConvert", G_MDSFT_TEXTCONV, 3, G_TC_CONV, G_TC_FILTCONV, G_TC_FILT, -1),
    F3DZEX_SETRENDERMACRO("SetTextureFilter", G_MDSFT_TEXTFILT, 2, G_TF_POINT, G_TF_AVERAGE, G_TF_BILERP, -1),
    F3DZEX_SETRENDERMACRO("SetTextureLUT", G_MDSFT_TEXTLUT, 2, G_TT_NONE, G_TT_RGBA16, G_TT_IA16, -1),
    F3DZEX_SETRENDERMACRO("SetTextureLOD", G_MDSFT_TEXTLOD, 1, G_TL_TILE, G_TL_LOD, -1, -1),
    F3DZEX_SETRENDERMACRO("SetTextureDetail", G_MDSFT_TEXTDETAIL, 2, G_TD_CLAMP, G_TD_SHARPEN, G_TD_DETAIL, -1),
    F3DZEX_SETRENDERMACRO("SetTexturePersp", G_MDSFT_TEXTPERSP, 1, G_TP_PERSP, G_TP_NONE, -1, -1),
    F3DZEX_SETRENDERMACRO("SetCycleType", G_MDSFT_CYCLETYPE, 2, G_CYC_1CYCLE, G_CYC_2CYCLE, G_CYC_COPY, G_CYC_FILL),
    F3DZEX_SETRENDERMACRO("SetColorDither", G_MDSFT_COLORDITHER, 2, G_CD_MAGICSQ, G_CD_BAYER, G_CD_NOISE, -1),
    F3DZEX_SETRENDERMACRO("PipelineMode", G_MDSFT_PIPELINE, 1, G_PM_1PRIMITIVE, G_PM_NPRIMITIVE, -1, -1),
};

#pragma GLOBAL_ASM("asm/non_matchings/code/ucode_disas/UCodeDisas_Disassemble.rodata2.s")
F3dzexSetModeMacro sUCodeDisasModeLMacros[] = {
    F3DZEX_SETRENDERMACRO("gsDPSetAlphaCompare", G_MDSFT_ALPHACOMPARE, 2, G_AC_NONE, G_AC_THRESHOLD, G_AC_DITHER, -1),
    F3DZEX_SETRENDERMACRO("gsDPSetDepthSource", G_MDSFT_ZSRCSEL, 1, G_ZS_PIXEL, G_ZS_PRIM, -1, -1),
};
//#pragma GLOBAL_ASM("asm/non_matchings/code/ucode_disas/UCodeDisas_Disassemble.s")
void UCodeDisas_Disassemble(UCodeDisas *this, Gfx *gfx0) {
    u32 sp384;
    u16 sp382;
    u8 sp381;
    s32 sp378;
    Gfx sp370;
    ? sp368;
    s32 sp358;
    s32 sp350;
    s32 sp348;
    s32 sp340;
    s32 sp338;
    ? sp330;
    s32 sp328;
    s32 sp2F8;
    s32 sp2EC;
    ? sp2D4;
    f32 sp290;
    ? sp27C;
    ?32 sp278;
    ? sp270;
    ? sp250;
    s32 sp238;
    ? sp230;
    ? sp21C;
    s32 sp218;
    u8 sp217;
    u32 sp214;
    ? sp20C;
    ? sp200;
    ? sp1F8;
    ? sp1F0;
    ? sp1E8;
    ? sp1E0;
    ? sp1D8;
    ? sp1D0;
    ? sp1C8;
    ? sp1C0;
    ? sp1B8;
    ? sp1B0;
    ? sp198;
    ? sp18C;
    const char *sp178;
    const char *sp174;
    const char *sp16C;
    const char *sp164;
    const char *sp160;
    const char *sp15C;
    const char *sp158;
    const char *sp154;
    const char *sp150;
    const char *sp14C;
    Gfx *temp_v0;
    const char *temp_s0_2;
    const char *temp_s1_2;
    const char *temp_s2;
    const char *temp_s4_2;
    const char *temp_s5;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s1;
    s32 temp_s1_3;
    s32 temp_s1_4;
    s32 temp_s1_5;
    s32 temp_s1_7;
    s32 temp_t0;
    s32 temp_t0_10;
    s32 temp_t0_11;
    s32 temp_t0_12;
    s32 temp_t0_13;
    s32 temp_t0_14;
    s32 temp_t0_15;
    s32 temp_t0_16;
    s32 temp_t0_17;
    s32 temp_t0_18;
    s32 temp_t0_19;
    s32 temp_t0_20;
    s32 temp_t0_21;
    s32 temp_t0_22;
    s32 temp_t0_23;
    s32 temp_t0_24;
    s32 temp_t0_25;
    s32 temp_t0_26;
    s32 temp_t0_27;
    s32 temp_t0_28;
    s32 temp_t0_29;
    s32 temp_t0_2;
    s32 temp_t0_30;
    s32 temp_t0_31;
    s32 temp_t0_32;
    s32 temp_t0_33;
    s32 temp_t0_34;
    s32 temp_t0_35;
    s32 temp_t0_36;
    s32 temp_t0_37;
    s32 temp_t0_38;
    s32 temp_t0_39;
    s32 temp_t0_3;
    s32 temp_t0_40;
    s32 temp_t0_4;
    s32 temp_t0_5;
    s32 temp_t0_6;
    s32 temp_t0_7;
    s32 temp_t0_8;
    s32 temp_t0_9;
    s32 temp_t1;
    s32 temp_t2_2;
    s32 temp_t4;
    s32 temp_t9_2;
    s32 temp_t9_3;
    s32 temp_v0_11;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    u16 temp_v0_12;
    u16 temp_v0_4;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u32 temp_a1_4;
    u32 temp_a1_5;
    u32 temp_s0_5;
    u32 temp_s1_6;
    u32 temp_s4;
    u32 temp_t2;
    u32 temp_t6;
    u32 temp_t6_2;
    u32 temp_t7;
    u32 temp_t7_2;
    u32 temp_t7_3;
    u32 temp_t7_4;
    u32 temp_t9;
    u32 temp_v0_13;
    u32 temp_v0_3;
    u32 temp_v0_7;
    u32 temp_v0_8;
    u32 temp_v0_9;
    u32 temp_v1;
    u8 temp_a1;
    u8 temp_a3;
    void *temp_v0_10;
    s32 phi_s0;
    s32 phi_v0;
    s32 phi_v0_2;
    F3dzexSetModeMacro *phi_a3;
    void *phi_v1;
    s32 phi_v0_3;
    u32 phi_a1;
    F3dzexSetModeMacro *phi_a3_2;
    void *phi_v1_2;
    s32 phi_v0_4;
    u32 phi_a1_2;
    s8 *phi_a1_3;
    s8 *phi_s5;
    s8 *phi_s1;
    s8 *phi_s5_2;
    s8 *phi_s1_2;
    s32 phi_t0;
    s32 phi_s0_2;
    s32 phi_s1_3;
    s32 phi_t0_2;
    s32 phi_t0_3;
    s8 *phi_s1_4;
    s8 *phi_s1_5;
    s32 phi_s1_6;
    s32 phi_t0_4;
    s8 *phi_s1_7;
    s32 phi_t0_5;
    s8 *phi_s1_8;
    s8 *phi_t0_6;
    s8 *phi_s0_3;
    s8 *phi_t0_7;
    s8 *phi_s0_4;
    s8 *phi_s0_5;
    s8 *phi_s0_6;
    s8 *phi_v1_3;
    s8 *phi_s1_9;
    s8 *phi_v1_4;
    s8 *phi_s1_10;
    s8 *phi_s1_11;
    s8 *phi_s2;
    s8 *phi_s2_2;
    s8 *phi_s5_3;

    sp378 = 0;
loop_1:
    this->dlCnt++;
    temp_v0 = UCodeDisas_TranslateAddr(this, (u32) gfx0);
    gfx0 = temp_v0;
    DISAS_LOG("%08x:", temp_v0);

    sp370.words.w0 = (u32) gfx0->words.w0;
    sp370.words.w1 = (u32) gfx0->words.w1;
    temp_s4 = UCodeDisas_TranslateAddr(this, sp370.words.w1);
    DISAS_LOG("%08x-%08x:", sp370.words.w0, sp370.words.w1);

    temp_v0_2 = this->dlDepth;
    phi_s0 = 0;
    phi_v0 = temp_v0_2;
    phi_v0_2 = temp_v0_2;
    if (temp_v0_2 > 0) {
loop_6:
        DISAS_LOG(" ");
        phi_v0 = this->dlDepth;
        temp_s0 = phi_s0 + 1;
        phi_s0 = temp_s0;
        phi_v0_2 = phi_v0;
        if (temp_s0 < phi_v0) {
            goto loop_6;
        }
    }
    if ((s32) sp370 > 0) {
        if (temp_t6 < 0x23U) {
            goto **(&jtbl_8014927C + (temp_t6 * 4)); // switch 1
block_12:
            if (sp370 != 0) {
                goto block_260;
            case 3: // switch 1
                temp_t0 = this->enableLog;
                phi_t0_5 = temp_t0;
                DISAS_LOG("gsSPNoOp(),");
                    goto block_472;
                case 1: // switch 1
                    Gfx gfx;
                    gfx.words.w0 = gfx0->words.w0;
                    gfx.words.w1 = gfx0->words.w1;

                    switch (gfx.dma.cmd) {
                        case G_LOAD_UCODE:
                        case G_DL:
                        case G_RDPHALF_1:
                            DISAS_LOG("RDPHALF_1(0x%08x),", gfx.words.w1);
                            goto block_473;
                        case G_TEXRECT:
                            Gfx gfx;
                            gfx.words.w0 = gfx0->words.w0;
                            gfx.words.w1 = gfx0->words.w1;
                    }
                    if (sp369 != 0) {
                        if (sp369 != 1) {
block_472:
                        } else {
                            DISAS_LOG("gsSPBranchList(0x%08x),", sp36C);
                            gfx0 = temp_s4 - 8;
                            goto block_473;
                        case G_RDPHALF_1: // switch 1
                            DISAS_LOG("RDPHALF_1(0x%08x),", sp374);
                            sp384 = sp374;
                            goto block_473;
                        case 7: // switch 1
                            sp358.unk0 = (u32) gfx0->words.w0;
                            sp358.unk4 = (u32) gfx0->words.w1;
                            sp358.unk8 = (s32) gfx0->unk8;
                            sp358.unkC = (s32) gfx0->unkC;
                            DISAS_LOG("gsSPTextureRectangle(%d,%d,%d,%d,%d,%d,%d,%d,%d),", (u32) (sp358 << 8) >> 0x14, sp358 & 0xFFF, (u32) (sp35C << 8) >> 0x14, sp35C & 0xFFF, (u8) sp35C & 7, temp_v0_3 >> 0x10, temp_v0_3 & 0xFFFF, temp_v1 >> 0x10, temp_v1 & 0xFFFF);
                            gfx0 = gfx0 + 0x10;
                            this->pipeSyncRequired = 1;
                            goto block_472;
                        case 0: // switch 1
                            temp_v0_4 = sp370.unk2;
                            if (temp_v0_4 == 0x7FF) {
                                DISAS_LOG("gsSPLoadUcode(0x%08x, 0x%08x),", sp374, sp384);
                            } else {
                                DISAS_LOG("gsSPLoadUcodeEx(0x%08x, 0x%08x, 0x%05x),", sp374, sp384, temp_v0_4 + 1);
                            }
                            UCodeDisas_SetCurUCodeImpl(this, UCodeDisas_TranslateAddr(this, sp374));
                            this->loaducodeCnt = this->loaducodeCnt + 1;
                            phi_t0_5 = this->enableLog;
                            goto block_473;
                        case 2: // switch 1
                            DISAS_LOG("gsSPEndDisplayList(),");
                            phi_v0_2 = this->dlDepth;
                            if (phi_v0_2 <= 0) {
                                sp378 = 1;
                            } else {
                                temp_s1 = phi_v0_2 - 1;
                                this->dlDepth = temp_s1;
                                gfx0 = (&this->segments[temp_s1])[0x10] - 8;
                                goto block_472;
                            case 24: // switch 1
                                sp350.unk0 = (u32) gfx0->words.w0;
                                sp350.unk4 = (u32) gfx0->words.w1;
                                temp_t9_2 = (s32) sp354;
                                DISAS_LOG("gsDPSetTile(%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d),", (u32) sp351 >> 5, (u32) (sp350 << 0xB) >> 0x1E, (u32) (sp350 << 0xE) >> 0x17, sp350 & 0x1FF, sp354 & 7, (u32) sp355 >> 4, (((u32) (temp_t9_2 << 0xC) >> 0x1F) * 2) + ((u32) (temp_t9_2 << 0xD) >> 0x1F), (u32) (temp_t9_2 << 0xE) >> 0x1C, (u32) (temp_t9_2 << 0x12) >> 0x1C, (((u32) (temp_t9_2 << 0x16) >> 0x1F) * 2) + (sp356 & 1), (u32) sp357 >> 4, temp_t9_2 & 0xF);
                                phi_t0_5 = this->enableLog;
                                if (this->tileSyncRequired != 0) {
                                    DISAS_LOG("### TileSyncが必要です。\n");
                                    this->syncErr = this->syncErr + 1;
                                    phi_t0_5 = this->enableLog;
                                    goto block_473;
                                case 23: // switch 1
                                    sp348.unk0 = (u32) gfx0->words.w0;
                                    sp348.unk4 = (u32) gfx0->words.w1;
                                    temp_t0_3 = this->enableLog;
                                    phi_t0_5 = temp_t0_3;
                                    DISAS_LOG("gsDPLoadTile(%d,%d,%d,%d,%d),", (u8) sp34C & 7, (u32) (sp348 << 8) >> 0x14, sp348 & 0xFFF, (u32) (sp34C << 8) >> 0x14, sp34C & 0xFFF);
                                    goto block_473;
                                    case 22: // switch 1
                                        sp340.unk0 = (u32) gfx0->words.w0;
                                        sp340.unk4 = (u32) gfx0->words.w1;
                                        DISAS_LOG("gsDPLoadBlock(%d,%d,%d,%d,%d),", (u8) sp344 & 7, (u32) (sp340 << 8) >> 0x14, sp340 & 0xFFF, (u32) (sp344 << 8) >> 0x14, sp344 & 0xFFF);
                                
                                        if (this->loadSyncRequired != 0) {
                                                DISAS_LOG("### LoadSyncが必要です。\n");
                        
                                            this->syncErr = this->syncErr + 1;
                                        }
                                        this->pipeSyncRequired = 1;
                                        goto block_472;
                                    case 21: // switch 1
                                        sp338.unk0 = (u32) gfx0->words.w0;
                                        sp338.unk4 = (u32) gfx0->words.w1;
                                        DISAS_LOG("gsDPSetTileSize(%d,%d,%d,%d,%d),", (u8) sp33C & 7, (u32) (sp338 << 8) >> 0x14, sp338 & 0xFFF, (u32) (sp33C << 8) >> 0x14, sp33C & 0xFFF);
                                        goto block_473;
                                    case 19: // switch 1
                                        sp330.unk0 = (u32) gfx0->words.w0;
                                        sp330.unk4 = (u32) gfx0->words.w1;
                                        DISAS_LOG("gsDPLoadTLUTCmd(%d,%d),", (u8) sp334 & 7, (u32) ((u32) (sp334 << 8) >> 0x14) >> 2);
                                        goto block_473;
                                    case 31: // switch 1
                                        sp328.unk0 = (u32) gfx0->words.w0;
                                        sp328.unk4 = (u32) gfx0->words.w1;
                                        DISAS_LOG("gsDPSetCombineLERP(%s,%s,%s,%s, %s,%s,%s,%s, %s,%s,%s,%s, %s,%s,%s,%s),", 
                                            UCodeDisas_ParseCombineColor((u32) sp329 >> 4, 1U), 
                                            UCodeDisas_ParseCombineColor(sp32C >> 0x1C, 2U), UCodeDisas_ParseCombineColor((u32) (sp328 << 0xC) >> 0x1B, 3U), 
                                            UCodeDisas_ParseCombineColor((u32) (sp32C << 0xE) >> 0x1D, 4U), 
                                            UCodeDisas_ParseCombineAlpha((u32) (sp328 << 0x11) >> 0x1D, 1U), 
                                            UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0x11) >> 0x1D, 2U), 
                                            UCodeDisas_ParseCombineAlpha((u32) (sp328 << 0x14) >> 0x1D, 3U), 
                                            UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0x14) >> 0x1D, 4U), 
                                            UCodeDisas_ParseCombineColor((u32) (sp328 << 0x17) >> 0x1C, 1U), 
                                            UCodeDisas_ParseCombineColor((u8) sp32C & 0xF, 2U), 
                                            UCodeDisas_ParseCombineColor(sp328 & 0x1F, 3U), 
                                            UCodeDisas_ParseCombineColor((u32) (sp32C << 0x17) >> 0x1D, 4U), 
                                            UCodeDisas_ParseCombineAlpha((u32) sp32D >> 5, 1U), 
                                            UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0x1A) >> 0x1D, 2U), 
                                            UCodeDisas_ParseCombineAlpha((u32) (sp32C << 0xB) >> 0x1D, 3U), 
                                            UCodeDisas_ParseCombineAlpha(sp32C & 7, 4U));

                                        if (this->pipeSyncRequired != 0) {
                                            DISAS_LOG("### PipeSyncが必要です。\n");
                                            this->syncErr++;
                                            goto block_473;
                                    case 6: // switch 1
                                        temp_s1_3 = (&sp370)[3] + 1;
                                        temp_s0_3 = (-(s32) (&sp370)[2] - temp_s1_3) + 0x20;
                                        phi_a3 = sUCodeDisasModeHMacros;
                                        phi_a1 = 0U;
loop_68:
                                        if (temp_s0_3 == phi_a3->shift) {
                                            phi_v1 = (((((phi_a1 * 4) - phi_a1) * 4) - phi_a1) * 4) + sUCodeDisasModeHMacros;
                                            phi_v0_3 = 0;
loop_70:
                                        if (sp374 == phi_v1->unk10) {
                                            DISAS_LOG("gsDP%s(%s),", phi_a3->name, (phi_a3 + phi_v0_3)->unkC, phi_a3);
                                        } else {
                                            temp_v0_5 = phi_v0_3 + 8;
                                            phi_v1 = phi_v1 + 8;
                                            phi_v0_3 = temp_v0_5;
                                            if (temp_v0_5 != 0x20) {
                                                goto loop_70;
                                            }
block_74:
                                            temp_a1_2 = phi_a1 + 1;
                                            phi_a3 = phi_a3 + 0x2C;
                                            phi_a1 = temp_a1_2;
                                            if (temp_a1_2 < 0xCU) {
                                                goto loop_68;
                                        }
                                            DISAS_LOG("gsSPSetOtherModeH(%d, %d, 0x%08x),", temp_s0_3, temp_s1_3, sp374);
                                                    }
                                                    } else {
                                                        goto block_74;
                                                    }
                                                    temp_t7_3 = this->modeH & (((1 - (1 << temp_s1_3)) << temp_s0_3) - 1);
                                                    this->modeH = temp_t7_3;
                                                    this->modeH = temp_t7_3 | sp374;
                                                    if (this->pipeSyncRequired != 0) {
                                                        DISAS_LOG("### PipeSyncが必要です。\n");
                                                        this->syncErr++;
                                                    }
                                                    goto block_472;
                                    case 5: // switch 1
                                        temp_s1_4 = (&sp370)[3] + 1;
                                        temp_s0_4 = (-(s32) (&sp370)[2] - temp_s1_4) + 0x20;
                                        if (temp_s0_4 == 3) {
                                            DISAS_LOG("\ngsDPSetRenderBlender(");
                                            UCodeDisas_ParseRenderMode(this, sp374);
                                            DISAS_LOG("\n),");
                                        } else {
                                            phi_a3_2 = sUCodeDisasModeLMacros;
                                            phi_a1_2 = 0U;
loop_88:
                                            if (temp_s0_4 == phi_a3_2->shift) {
                                                phi_v1_2 = (((((phi_a1_2 * 4) - phi_a1_2) * 4) - phi_a1_2) * 4) + sUCodeDisasModeLMacros;
                                                phi_v0_4 = 0;
loop_90:
                                                if (sp374 == phi_v1_2->unk10) {
                                                    DISAS_LOG((const char *) "gsDP%s(%s),", phi_a3_2->name, (phi_a3_2 + phi_v0_4)->unkC, phi_a3_2);
                                                } else {
                                                    temp_v0_6 = phi_v0_4 + 8;
                                                    phi_v1_2 = phi_v1_2 + 8;
                                                    phi_v0_4 = temp_v0_6;
                                                    if (temp_v0_6 != 0x20) {
                                                        goto loop_90;
                                                    }
block_94:
                                                temp_a1_3 = phi_a1_2 + 1;
                                                phi_a3_2 = phi_a3_2 + 0x2C;
                                                phi_a1_2 = temp_a1_3;
                                                if (temp_a1_3 < 2U) {
                                                    goto loop_88;
                                                }

                                                DISAS_LOG("gsSPSetOtherModeL(%d, %d, 0x%08x),", temp_s0_4, temp_s1_4, sp374);
                                            }
                                                        } else {
                                                            goto block_94;
                                                        }
                                                    }
                                                    temp_t6_2 = this->modeL & (((1 - (1 << temp_s1_4)) << temp_s0_4) - 1);
                                                    this->modeL = temp_t6_2;
                                                    this->modeL = temp_t6_2 | sp374;
                                                    if (this->pipeSyncRequired != 0) {
                                                        DISAS_LOG( "### PipeSyncが必要です。\n");
                                                        this->syncErr++;
                                                    }
                                                    goto block_472;
                                        case 18: // switch 1
                                            DISAS_LOG("gsDPSetOtherMode(0x%08x, 0x%08x),", sp370.unk0 & 0xFFFFFF, sp374);
                                            this->modeH = sp370.unk0 & 0xFFF;
                                            this->modeL = sp374;
                                            if (this->pipeSyncRequired != 0) {
                                                DISAS_LOG("### PipeSyncが必要です。\n");
                                                this->syncErr++;
                                            }
                                            goto block_472;
                                        case 16: // switch 1
                                            sp2F8.unk0 = (u32) gfx0->words.w0;
                                            sp2F8.unk4 = (u32) gfx0->words.w1;
                                            if (sp2FC == 0) {
                                                phi_a1_3 = "G_SC_NON_INTERLACE";
                                            } else {
                                                if (sp2FC == 3) {
                                                    phi_s1_8 = "G_SC_ODD_INTERLACE";
                                                 } else {
                                                    if (sp2FC == 2) {
                                                        phi_s0_6 = "G_SC_EVEN_INTERLACE";
                                                    } else {
                                                        phi_s0_6 = "???";
                                                    }
                                                        phi_s1_8 = phi_s0_6;
                                                    }
                                                    phi_a1_3 = phi_s1_8;
                                            }
                                            temp_t9_3 = (s32) sp2FC;
                                            temp_t1 = (s32) (sp2F8 << 0x1E) >> 0x1E;
                                            temp_v1_2 = (s32) (sp2F8 << 0x12) >> 0x1E;
                                            if ((temp_v1_2 | temp_t1 | ((s32) (temp_t9_3 << 0x12) >> 0x1E) | ((s32) (temp_t9_3 << 0x1E) >> 0x1E)) != 0) {
                                                        phi_t0_5 = temp_t0_8;
                                                        temp_t2_2 = (s32) sp2FC;
                                                        DISAS_LOG("gsDPSetScissorFrac(%s, %d, %d, %d, %d),", phi_a1_3, (((s32) (sp2F8 << 8) >> 0x16) * 4) + temp_v1_2, (((s32) (sp2F8 << 0x14) >> 0x16) * 4) + temp_t1, (((s32) (temp_t2_2 << 8) >> 0x16) * 4) + ((s32) (temp_t2_2 << 0x12) >> 0x1E), (((s32) (temp_t2_2 << 0x14) >> 0x16) * 4) + ((s32) (temp_t2_2 << 0x1E) >> 0x1E));
                                                        goto block_472;
                                                    } else {
                                                        temp_t0_9 = this->enableLog;
                                                        phi_t0_5 = temp_t0_9;
                                                        temp_t4 = (s32) sp2FC;
                                                        DISAS_LOG("gsDPSetScissor(%s, %d, %d, %d, %d),", phi_a1_3, (s32) (sp2F8 << 8) >> 0x16, (s32) (sp2F8 << 0x14) >> 0x16, (s32) (temp_t4 << 8) >> 0x16, (s32) (temp_t4 << 0x14) >> 0x16);
                                                        goto block_473;
                                            case 25: // switch 1
                                                sp2EC.unk0 = (u32) gfx0->words.w0;
                                                sp2EC.unk4 = (u32) gfx0->words.w1;
                                                DISAS_LOG("gsDPFillRectangle(%d, %d, %d, %d),", (s32) (sp2F0 << 8) >> 0x16, (s32) (sp2F0 << 0x14) >> 0x16, (s32) (sp2EC << 8) >> 0x16, (s32) (sp2EC << 0x14) >> 0x16);
                                                this->pipeSyncRequired = 1;
                                                goto block_472;
                                            case 34: // switch 1
                                                temp_v0_7 = sp370.unk0;
                                                temp_v1_3 = ((u32) (temp_v0_7 & 0xE00000) >> 0x15) & 0xFF;
                                                temp_a0 = ((u32) (temp_v0_7 & 0x180000) >> 0x13) & 0xFF;
                                                if (this->enableLog != 0) {
                                                    if (temp_v1_3 == 0) {
                                                            phi_s5 = "RGBA";
                                                    } else {
                                                        if (temp_v1_3 == 1) {
                                                            phi_t0_6 = "YUV";
                                                        } else {
                                                            if (temp_v1_3 == 2) {
                                                                    phi_v1_3 = "CI";
                                                            } else {
                                                                if (temp_v1_3 == 3) {
                                                                    phi_s2 = "IA";
                                                                } else {
                                                                    phi_s2 = "I";
                                                                }
                                                                    phi_v1_3 = phi_s2;
                                                                }
                                                                    phi_t0_6 = phi_v1_3;
                                                                }
                                                                    phi_s5 = phi_t0_6;
                                                                }
                                                                if (temp_a0 == 0) {
                                                                    phi_s1 = "4b";
                                                                } else {
                                                                    if (temp_a0 == 1) {
                                                                        phi_s0_3 = "8b";
                                                                    } else {
                                                                        if (temp_a0 == 2) {
                                                                            phi_s1_9 = "16b";
                                                                        } else {
                                                                            phi_s1_9 = "32b";
                                                                        }
                                                                        phi_s0_3 = phi_s1_9;
                                                                    }
                                                                    phi_s1 = phi_s0_3;
                                                                }
                                                                osSyncPrintf((const char *) "gsDPSetColorImage(G_IM_FMT_%s, G_IM_SIZ_%s, %d, 0x%08x(0x%08x) ),", phi_s5, phi_s1, (sp370.unk2 & 0xFFF) + 1, sp374, temp_s4);
                                                            }
                                                            if (this->pipeSyncRequired != 0) {
                                                                DISAS_LOG("### PipeSyncが必要です。\n");
                                                                this->syncErr++;
                                                            }
                                                            goto block_473;
                                            case 33: // switch 1
                                                DISAS_LOG("gsDPSetDepthImage(0x%08x(0x%08x)),", sp374, temp_s4);
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 32: // switch 1
                                                temp_v0_8 = sp370.unk0;
                                                temp_t0_10 = this->enableLog;
                                                temp_v1_4 = ((u32) (temp_v0_8 & 0xE00000) >> 0x15) & 0xFF;
                                                temp_a0_2 = ((u32) (temp_v0_8 & 0x180000) >> 0x13) & 0xFF;
                                                phi_t0_5 = temp_t0_10;
                                                if (temp_t0_10 != 0) {
                                                    if (temp_v1_4 == 0) {
                                                        phi_s5_2 = "RGBA";
                                                    } else {
                                                        if (temp_v1_4 == 1) {
                                                            phi_t0_7 = "YUV";
                                                        } else {
                                                            if (temp_v1_4 == 2) {
                                                            phi_v1_4 = "CI";
                                                            } else {
                                                                if (temp_v1_4 == 3) {
                                                                    phi_s2_2 = "IA";
                                                                } else {
                                                                    phi_s2_2 = "I";
                                                                }
                                                                phi_v1_4 = phi_s2_2;
                                                            }
                                                                phi_t0_7 = phi_v1_4;
                                                            }
                                                            phi_s5_2 = phi_t0_7;
                                                        }
                                                    if (temp_a0_2 == 0) {
                                                        phi_s1_2 = "4b";
                                                    } else {
                                                        if (temp_a0_2 == 1) {
                                                            phi_s0_4 = "8b";
                                                        } else {
                                                            if (temp_a0_2 == 2) {
                                                                phi_s1_10 = "16b";
                                                            } else {
                                                                phi_s1_10 = "32b";
                                                            }
                                                                phi_s0_4 = phi_s1_10;
                                                            }
                                                            phi_s1_2 = phi_s0_4;
                                                    }
                                                osSyncPrintf("gsDPSetTextureImage(G_IM_FMT_%s, G_IM_SIZ_%s, %d, 0x%08x(0x%08x)),", phi_s5_2, phi_s1_2, (sp370.unk2 & 0xFFF) + 1, sp374, temp_s4);
                                                goto block_473;
                                            case 30: // switch 1
                                                DISAS_LOG("gsDPSetEnvColor(%d, %d, %d, %d),", (&sp370)[4], (&sp370)[5], (&sp370)[6], (?32) (&sp370)[7]);
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 28: // switch 1
                                                DISAS_LOG("gsDPSetBlendColor(%d, %d, %d, %d),", (&sp370)[4], (&sp370)[5], (&sp370)[6], (?32) (&sp370)[7]);
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 27: // switch 1
                                                DISAS_LOG("gsDPSetFogColor(%d, %d, %d, %d),", (&sp370)[4], (&sp370)[5], (&sp370)[6], (?32) (&sp370)[7]);
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 26: // switch 1
                                                DISAS_LOG("gsDPSetFillColor(0x%08x),", sp370.unk4);
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 17: // switch 1
                                                DISAS_LOG("gsDPSetPrimDepth(%d, %d),", (u16) sp370.unk4, sp370.unk6);
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 29: // switch 1
                                                DISAS_LOG("gsDPSetPrimColor(%d, %d, %d, %d, %d, %d),", (&sp370)[2], (&sp370)[3], (&sp370)[4], (?32) (&sp370)[5], (?32) (&sp370)[6], (?32) (&sp370)[7]);
                                                goto block_472;
                                            case 12: // switch 1
                                                DISAS_LOG("gsDPFullSync(),");
                                                if (this->pipeSyncRequired != 0) {
                                                    DISAS_LOG("### PipeSyncが必要です。\n");
                                                    this->syncErr++;
                                                }
                                                goto block_473;
                                            case 11:
                                                DISAS_LOG("gsDPTileSync(),");
                                                this->tileSyncRequired = 0;
                                                goto block_472;
                                            case 10:
                                                DISAS_LOG("gsDPPipeSync(),");
                                                this->pipeSyncRequired = 0;
                                                goto block_472;
                                            case 9:
                                                DISAS_LOG("gsDPLoadSync(),");
                                                this->loadSyncRequired = 0;
                                                goto block_472;


                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
block_473:
                                if (phi_t0_5 != 0) {
                                    osSyncPrintf((const char *) "\n");
                                }
                                gfx0 = gfx0 + 8;
                                if (sp378 == 0) {
                                    goto loop_1;
                                }
                                return;
                            }
                            goto block_472;
                        }
                    } else {
                        if (this->enableLog != 0) {
                            osSyncPrintf(&D_80147E7C, sp36C);
                        }
                        (&this->segments[this->dlDepth])[0x10] = (u32) (gfx0 + 8);
                        this->dlDepth = this->dlDepth + 1;
                        gfx0 = temp_s4 - 8;
                        goto block_472;
                    }
                }
            } else {
                temp_a1 = (&sp370)[1];
                temp_t0_12 = this->enableLog;
                if ((u32) temp_a1 < 9U) {
                    goto **(&jtbl_80149308 + (temp_a1 * 4)); // switch 2
                case 0: // switch 2
                    temp_a1_4 = sp370.unk4;
                    if (temp_a1_4 == 0) {
                        phi_t0_5 = temp_t0_12;
                        if (temp_t0_12 != 0) {
                            osSyncPrintf((const char *) "gsDPNoOp(),", temp_a1_4);
                            goto block_472;
                        }
                    } else {
                        phi_t0_5 = temp_t0_12;
                        if (temp_t0_12 != 0) {
                            osSyncPrintf((const char *) "gsDPNoOpTag(%08x),", temp_a1_4);
                            goto block_472;
                        case 1: // switch 2
                            phi_t0_5 = temp_t0_12;
                            if (temp_t0_12 != 0) {
                                osSyncPrintf((const char *) "count_gsDPNoOpHere([%s:%d]),", sp370.unk4, sp370.unk2);
                                goto block_472;
                            case 7: // switch 2
                                phi_t0_5 = temp_t0_12;
                                if (temp_t0_12 != 0) {
                                    osSyncPrintf((const char *) "count_gsDPNoOpOpenDisp([%s:%d]),", sp370.unk4, sp370.unk2);
                                    goto block_472;
                                case 8: // switch 2
                                    phi_t0_5 = temp_t0_12;
                                    if (temp_t0_12 != 0) {
                                        osSyncPrintf((const char *) "count_gsDPNoOpCloseDisp([%s:%d]),", sp370.unk4, sp370.unk2);
                                        goto block_472;
                                    case 2: // switch 2
                                        phi_t0_5 = temp_t0_12;
                                        if (temp_t0_12 != 0) {
                                            osSyncPrintf((const char *) "count_gsDPNoOpString(%c%s%c, %d),", 0x22, sp370.unk4, 0x22, (?32) sp370.unk2);
                                            goto block_472;
                                        case 3: // switch 2
                                            phi_t0_5 = temp_t0_12;
                                            if (temp_t0_12 != 0) {
                                                osSyncPrintf((const char *) "count_gsDPNoOpWord(0x%08x, %d),", sp370.unk4, sp370.unk2);
                                                goto block_472;
                                            case 4: // switch 2
                                                phi_t0_5 = temp_t0_12;
                                                if (temp_t0_12 != 0) {
                                                    osSyncPrintf((const char *) "count_gsDPNoOpFloat(%8.3f, %d),", temp_a1, second half of f64, (f64) (bitwise f32) sp370.unk4, (?32) sp370.unk2);
                                                    goto block_472;
                                                case 5: // switch 2
                                                    if (sp370.unk2 == 0) {
                                                        if (temp_t0_12 != 0) {
                                                            osSyncPrintf((const char *) "count_gsDPNoOpQuiet(),", temp_a1);
block_253:
                                                        }
                                                    } else if (temp_t0_12 != 0) {
                                                        osSyncPrintf((const char *) "count_gsDPNoOpVerbose(),", temp_a1);
                                                        goto block_253;
                                                    }
                                                    this->enableLog = (s32) sp370.unk2;
                                                    phi_t0_5 = (s32) sp370.unk2;
                                                    goto block_473;
                                                case 6: // switch 2
                                                    if (temp_t0_12 != 0) {
                                                        osSyncPrintf((const char *) "count_gsDPNoOpCallBack(%08x,%d),", temp_a1);
                                                    }
                                                    (void *) sp370.unk4(this, sp370.unk2);
                                                    goto block_472;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    phi_t0_5 = temp_t0_12;
                    if (temp_t0_12 != 0) {
                        osSyncPrintf((const char *) "gsDPNoOpTag3(%02x, %08x, %04x),", temp_a1, sp370.unk4, sp370.unk2);
                        goto block_472;
                    }
                }
            }
        } else {
        default: // switch 1
block_260:
            temp_s1_5 = this->ucodeType;
            if ((temp_s1_5 != 1) && (temp_s1_5 != 2)) {
                if (temp_s1_5 != 3) {
                    goto block_472;
                } else if ((s32) sp370 >= 0xDC) {
                    if (sp370 != 0xDC) {
                        if (sp370 != 0xE4) {
                        case 2: // switch 6
block_470:
                            temp_t0_24 = this->enableLog;
                            phi_t0_5 = temp_t0_24;
                            if (temp_t0_24 != 0) {
                                osSyncPrintf((const char *) "AnyDisplayList(),");
                                goto block_472;
                            }
                        } else {
                            if (this->enableLog != 0) {
                                osSyncPrintf((const char *) "RDPHALF_0(0x%02x, 0x%08x, 0x%04x),", (&sp370)[1], sp370.unk4, sp370.unk2);
                            }
                            sp381 = (&sp370)[1];
                            sp384 = sp370.unk4;
                            sp382 = sp370.unk2;
                        }
                    } else {
                        sp1D8.unk0 = (u32) gfx0->words.w0;
                        sp1D8.unk4 = (u32) gfx0->words.w1;
                        if (sp1D9 == 0x17) {
                            temp_t0_13 = this->enableLog;
                            phi_t0_5 = temp_t0_13;
                            if (temp_t0_13 != 0) {
                                osSyncPrintf((const char *) "gsSPObjMatrix(0x%08x(0x%08x)),", sp1DC, temp_s4);
                                goto block_472;
                            }
                        } else {
                            temp_t0_14 = this->enableLog;
                            phi_t0_5 = temp_t0_14;
                            if (temp_t0_14 != 0) {
                                osSyncPrintf((const char *) "gsSPObjSubMatrix(0x%08x(0x%08x)),", sp1DC, temp_s4);
                                phi_t0_5 = this->enableLog;
                                goto block_473;
                            case 4: // switch 6
                                sp1D0.unk0 = (u32) gfx0->words.w0;
                                sp1D0.unk4 = (u32) gfx0->words.w1;
                                temp_t0_17 = this->enableLog;
                                phi_t0_5 = temp_t0_17;
                                if (temp_t0_17 != 0) {
                                    osSyncPrintf((const char *) "gsSPObjLoadTxtr(0x%08x(0x%08x)),", sp1D4, temp_s4);
                                    phi_t0_5 = this->enableLog;
                                    goto block_473;
                                case 5: // switch 6
                                    sp1C8.unk0 = (u32) gfx0->words.w0;
                                    sp1C8.unk4 = (u32) gfx0->words.w1;
                                    temp_t0_18 = this->enableLog;
                                    phi_t0_5 = temp_t0_18;
                                    if (temp_t0_18 != 0) {
                                        osSyncPrintf((const char *) "gsSPObjLoadTxSprite(0x%08x(0x%08x)),", sp1CC, temp_s4);
                                        phi_t0_5 = this->enableLog;
                                        goto block_473;
                                    case 6: // switch 6
                                        sp1C0.unk0 = (u32) gfx0->words.w0;
                                        sp1C0.unk4 = (u32) gfx0->words.w1;
                                        temp_t0_19 = this->enableLog;
                                        phi_t0_5 = temp_t0_19;
                                        if (temp_t0_19 != 0) {
                                            osSyncPrintf((const char *) "gsSPObjLoadTxRect(0x%08x(0x%08x)),", sp1C4, temp_s4);
                                            phi_t0_5 = this->enableLog;
                                            goto block_473;
                                        case 7: // switch 6
                                            sp1B8.unk0 = (u32) gfx0->words.w0;
                                            sp1B8.unk4 = (u32) gfx0->words.w1;
                                            temp_t0_20 = this->enableLog;
                                            phi_t0_5 = temp_t0_20;
                                            if (temp_t0_20 != 0) {
                                                osSyncPrintf((const char *) "gsSPObjLoadTxRectR(0x%08x(0x%08x)),", sp1BC, temp_s4);
                                                phi_t0_5 = this->enableLog;
                                                goto block_473;
                                            case 3: // switch 6
                                                sp1B0.unk0 = (u32) gfx0->words.w0;
                                                sp1B0.unk4 = (u32) gfx0->words.w1;
                                                temp_v0_9 = UCodeDisas_TranslateAddr(this, (sp1B2 << 0x10) | sp382);
                                                if (sp1B1 == 0) {
                                                    temp_t0_21 = this->enableLog;
                                                    phi_t0_5 = temp_t0_21;
                                                    if (temp_t0_21 != 0) {
                                                        osSyncPrintf((const char *) "gsSPSelectDL(0x%08x, %d, 0x%08x, 0x%08x),", temp_v0_9, sp381, sp384, sp1B4);
                                                        goto block_472;
                                                    }
                                                } else {
                                                    temp_t0_22 = this->enableLog;
                                                    phi_t0_5 = temp_t0_22;
                                                    if (temp_t0_22 != 0) {
                                                        osSyncPrintf((const char *) "gsSPSelectBranchDL(0x%08x, %d, 0x%08x, 0x%08x),", temp_v0_9, sp381, sp384, sp1B4);
                                                        phi_t0_5 = this->enableLog;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((s32) sp370 >= 0xDB) {
                    if (sp370 != 0xDB) {
                        goto block_470;
                    } else {
                        sp198.unk0 = (u32) gfx0->words.w0;
                        sp198.unk4 = (u32) gfx0->words.w1;
                        if (sp19B != 6) {
                            if (sp19B != 8) {
                                temp_t0_15 = this->enableLog;
                                phi_t0_5 = temp_t0_15;
                                if (temp_t0_15 != 0) {
                                    osSyncPrintf((const char *) "gsMoveWd(%d, %d, %d), ", sp19B, (u32) (unaligned s32) sp199 >> 0x10, sp19C);
                                    phi_t0_5 = this->enableLog;
                                    goto block_473;
                                case 10: // switch 6
                                    sp18C.unk0 = (u32) gfx0->words.w0;
                                    sp18C.unk4 = (u32) gfx0->words.w1;
                                    temp_t0_23 = this->enableLog;
                                    phi_t0_5 = temp_t0_23;
                                    if (temp_t0_23 != 0) {
                                        osSyncPrintf((const char *) "gsSPObjRenderMode(0x%08x),", sp190);
                                        phi_t0_5 = this->enableLog;
                                    }
                                }
                            } else {
                                temp_t0_16 = this->enableLog;
                                phi_t0_5 = temp_t0_16;
                                if (temp_t0_16 != 0) {
                                    osSyncPrintf((const char *) "gsSPSetStatus(0x%08x, 0x%08x),", (u32) (unaligned s32) sp199 >> 0x10, sp19C);
                                    goto block_472;
                                }
                            }
                        } else {
                            temp_s0_5 = (u32) ((u32) (unaligned s32) sp199 >> 0x10) >> 2;
                            if (this->enableLog != 0) {
                                osSyncPrintf((const char *) "gsSPSegment(%d, 0x%08x),", temp_s0_5, sp19C);
                            }
                            this->segments[temp_s0_5] = (u32) (sp19C & 0xFFFFFF);
                            goto block_472;
                        }
                    }
                } else if ((s32) sp370 >= 0xC) {
                    if (sp370 != 0xDA) {
                        goto block_470;
                    } else {
                        sp1E0.unk0 = (u32) gfx0->words.w0;
                        sp1E0.unk4 = (u32) gfx0->words.w1;
                        if (this->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPObjRectangleR(0x%08x(0x%08x)),", sp1E4, temp_s4);
                        }
                        this->pipeSyncRequired = 1;
                        goto block_472;
                    }
                } else {
                    temp_t7 = sp370 - 1;
                    if (temp_t7 < 0xBU) {
                        goto **(&jtbl_80149398 + (temp_t7 * 4)); // switch 6
                    case 9: // switch 6
                        sp200.unk0 = (u32) gfx0->words.w0;
                        sp200.unk4 = (u32) gfx0->words.w1;
                        if (this->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPBgRectCopy(0x%08x(0x%08x)),", sp204, temp_s4);
                        }
                        this->pipeSyncRequired = 1;
                        goto block_472;
                    case 8: // switch 6
                        sp1F8.unk0 = (u32) gfx0->words.w0;
                        sp1F8.unk4 = (u32) gfx0->words.w1;
                        if (this->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPBgRect1Cyc(0x%08x(0x%08x)),", sp1FC, temp_s4);
                        }
                        this->pipeSyncRequired = 1;
                        goto block_472;
                    case 1: // switch 6
                        sp1F0.unk0 = (u32) gfx0->words.w0;
                        sp1F0.unk4 = (u32) gfx0->words.w1;
                        if (this->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPObjSprite(0x%08x(0x%08x)),", sp1F4, temp_s4);
                        }
                        this->pipeSyncRequired = 1;
                        goto block_472;
                    case 0: // switch 6
                        sp1E8.unk0 = (u32) gfx0->words.w0;
                        sp1E8.unk4 = (u32) gfx0->words.w1;
                        if (this->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPObjRectangle(0x%08x(0x%08x)),", sp1EC, temp_s4);
                        }
                        this->pipeSyncRequired = 1;
                        goto block_472;
                    } else {
                        goto block_470;
                    }
                }
            } else if ((s32) sp370 >= 9) {
                temp_t2 = sp370 - 0xD7;
                if (temp_t2 < 6U) {
                    goto **(&jtbl_8014932C + (temp_t2 * 4)); // switch 3
block_267:
                    temp_t7_2 = sp370 - 1;
                    if (temp_t7_2 < 8U) {
                        goto **(&jtbl_80149344 + (temp_t7_2 * 4)); // switch 4
                    case 3: // switch 3
                        sp2D4.unk0 = (u32) gfx0->words.w0;
                        sp2D4.unk4 = (u32) gfx0->words.w1;
                        if (this->enableLog != 0) {
                            osSyncPrintf((const char *) "gsSPMatrix(0x%08x(%08x), 0", sp2D8, temp_s4);
                        }
                        phi_s0_2 = 0;
loop_272:
                        phi_t0_2 = phi_t0;
                        if (phi_t0 != 0) {
                            temp_v0_10 = (((phi_s0_2 * 4) - phi_s0_2) * 4) + sUCodeDisasMtxFlags;
                            if ((temp_v0_10->unk0 & (sp2D7 ^ 1)) != 0) {
                                phi_s1_3 = temp_v0_10->unk4;
                            } else {
                                phi_s1_3 = temp_v0_10->unk8;
                            }
                            osSyncPrintf((const char *) "|%s", phi_s1_3);
                            phi_t0_2 = this->enableLog;
                        }
                        temp_s0_6 = phi_s0_2 + 1;
                        phi_t0 = phi_t0_2;
                        phi_s0_2 = temp_s0_6;
                        if (temp_s0_6 != 3) {
                            goto loop_272;
                        }
                        phi_t0_3 = phi_t0_2;
                        if (phi_t0_2 != 0) {
                            osSyncPrintf((const char *) "),", sp2D8);
                            phi_t0_3 = this->enableLog;
                        }
                        phi_t0_5 = phi_t0_3;
                        if (phi_t0_3 >= 2) {
                            MtxConv_L2F((MtxF *) &sp290, (MatrixInternal *) temp_s4);
                            if (this->enableLog != 0) {
                                osSyncPrintf((const char *) "\n");
                            }
                            phi_t0_5 = this->enableLog;
                            if (this->enableLog != 0) {
                                osSyncPrintf((const char *) "/ %04x.%04x %04x.%04x %04x.%04x %.04x.%04x \\/ %12.6f %12.6f %12.6f %12.6f \\\n| %04x.%04x %04x.%04x %04x.%04x %.04x.%04x || %12.6f %12.6f %12.6f %12.6f |\n| %04x.%04x %04x.%04x %04x.%04x %.04x.%04x || %12.6f %12.6f %12.6f %12.6f |\n\\ %04x.%04x %04x.%04x %04x.%04x %.04x.%04x /\\ %12.6f %12.6f %12.6f %12.6f /\n", temp_s4->unk0, temp_s4->unk20, temp_s4->unk8, (?32) temp_s4->unk28, (?32) temp_s4->unk10, (?32) temp_s4->unk30, (?32) temp_s4->unk18, (?32) temp_s4->unk38, (f64) sp290, (f64) sp2A0, (f64) sp2B0, (f64) sp2C0, (?32) temp_s4->unk2, (?32) temp_s4->unk22, (?32) temp_s4->unkA, (?32) temp_s4->unk2A, (?32) temp_s4->unk12, (?32) temp_s4->unk32, (?32) temp_s4->unk1A, (?32) temp_s4->unk3A, (f64) sp294, (f64) sp2A4, (f64) sp2B4, (f64) sp2C4, (?32) temp_s4->unk4, (?32) temp_s4->unk24, (?32) temp_s4->unkC, (?32) temp_s4->unk2C, (?32) temp_s4->unk14, (?32) temp_s4->unk34, (?32) temp_s4->unk1C, (?32) temp_s4->unk3C, (f64) sp298, (f64) sp2A8, (f64) sp2B8, (f64) sp2C8, (?32) temp_s4->unk6, (?32) temp_s4->unk26, (?32) temp_s4->unkE, (?32) temp_s4->unk2E, (?32) temp_s4->unk16, (?32) temp_s4->unk36, (?32) temp_s4->unk1E, (?32) temp_s4->unk3E, (f64) sp29C, (f64) sp2AC, (f64) sp2BC, (f64) sp2CC);
                                phi_t0_5 = this->enableLog;
                                goto block_473;
                            case 0: // switch 4
                                temp_s0_8 = ((u32) sp370.unk0 >> 0xC) & 0xFF;
                                temp_s1_7 = ((s32) (&sp370)[3] >> 1) - temp_s0_8;
                                if (this->enableLog != 0) {
                                    osSyncPrintf((const char *) "gsSPVertex(0x%08x(0x%08x), %d, %d),", sp370.unk4, temp_s4, temp_s0_8, temp_s1_7);
                                }
                                this->vtxCnt = this->vtxCnt + temp_s0_8;
                                this->spvtxCnt = this->spvtxCnt + 1;
                                phi_t0_5 = this->enableLog;
                                if (this->enableLog >= 2) {
                                    UCodeDisas_PrintVertices(this, (Vtx *) temp_s4, temp_s0_8, temp_s1_7);
                                    phi_t0_5 = this->enableLog;
                                    goto block_473;
                                case 1: // switch 4
                                    if (this->enableLog != 0) {
                                        temp_v0_12 = sp370.unk2;
                                        if (temp_v0_12 == 0x10) {
                                            phi_s1_7 = "G_MWO_POINT_RGBA";
                                        } else {
                                            if (temp_v0_12 == 0x14) {
                                                phi_s0_5 = "G_MWO_POINT_ST";
                                            } else {
                                                if (temp_v0_12 == 0x18) {
                                                    phi_s1_11 = "G_MWO_POINT_XYSCREEN";
                                                } else {
                                                    if (temp_v0_12 == 0x1C) {
                                                        phi_s5_3 = "G_MWO_POINT_ZSCREEN";
                                                    } else {
                                                        phi_s5_3 = "G_MWO_POINT_????";
                                                    }
                                                    phi_s1_11 = phi_s5_3;
                                                }
                                                phi_s0_5 = phi_s1_11;
                                            }
                                            phi_s1_7 = phi_s0_5;
                                        }
                                        osSyncPrintf((const char *) "gsSPModifyVertex(%d, %s, %08x),", (&sp370)[1], phi_s1_7, sp370.unk4);
                                    }
                                    this->vtxCnt = this->vtxCnt + (&sp370)[1];
                                    this->spvtxCnt = this->spvtxCnt + 1;
                                    phi_t0_5 = this->enableLog;
                                    goto block_473;
                                case 4: // switch 4
                                    sp27C.unk0 = (u32) gfx0->words.w0;
                                    sp27C.unk4 = (u32) gfx0->words.w1;
                                    sp278 = (unaligned s32) sp280;
                                    if (this->enableLog != 0) {
                                        osSyncPrintf((const char *) "gsSP1Triangle(%d, %d, %d),", (s32) sp279 / 2, (s32) sp27A / 2, (s32) sp27B / 2);
                                    }
                                    this->pipeSyncRequired = 1;
                                    this->tri1Cnt = this->tri1Cnt + 1;
                                    goto block_472;
                                case 7: // switch 4
                                    temp_a3 = (&sp370)[3];
                                    temp_t0_38 = this->enableLog;
                                    if (temp_a3 == 0) {
                                        if (temp_t0_38 != 0) {
                                            osSyncPrintf((const char *) "gsSPLine3D(%d, %d),", (&sp370)[1], (&sp370)[2], temp_a3);
                                        }
                                    } else if (temp_t0_38 != 0) {
                                        osSyncPrintf((const char *) "gsSPLineW3D(%d, %d, %d),", (&sp370)[1], (&sp370)[2], temp_a3);
                                    }
                                    this->pipeSyncRequired = 1;
                                    this->lineCnt = this->lineCnt + 1;
                                    goto block_472;
                                case 5: // switch 4
                                    sp270.unk0 = (?32) (unaligned s32) gfx0->texture.cmd;
                                    sp270.unk4 = (?32) (unaligned s32) gfx0->words.w1;
                                    if (this->enableLog != 0) {
                                        osSyncPrintf((const char *) "gsSP2Triangles(%d, %d, %d, 0, %d, %d, %d, 0),", (s32) sp271 / 2, (s32) sp272 / 2, (s32) sp273 / 2, (s32) sp275 / 2, (s32) sp276 / 2, (s32) sp277 / 2);
                                    }
                                    this->pipeSyncRequired = 1;
                                    this->tri2Cnt = this->tri2Cnt + 1;
                                    goto block_472;
                                case 6: // switch 4
                                    sp250.unk0 = (?32) (unaligned s32) gfx0->texture.cmd;
                                    sp250.unk4 = (?32) (unaligned s32) gfx0->words.w1;
                                    if (this->enableLog != 0) {
                                        osSyncPrintf((const char *) "gsSP1Quadrangle(%d, %d, %d, %d, 0),", (s32) sp251 / 2, (s32) sp252 / 2, (s32) sp253 / 2, (s32) sp257 / 2);
                                    }
                                    this->pipeSyncRequired = 1;
                                    this->quadCnt = this->quadCnt + 1;
                                    goto block_472;
                                case 2: // switch 4
                                    temp_t0_39 = this->enableLog;
                                    phi_t0_5 = temp_t0_39;
                                    if (temp_t0_39 != 0) {
                                        osSyncPrintf((const char *) "gsSPCullDisplayList(%d, %d),", (s32) sp370.unk2 / 2, (s32) sp370.unk6 / 2);
                                        goto block_472;
                                    case 3: // switch 4
                                        temp_v0_13 = UCodeDisas_TranslateAddr(this, sp384);
                                        if (this->enableLog != 0) {
                                            osSyncPrintf((const char *) "gsSPBranchLessZraw(0x%08x(0x%08x), %d, 0x%08x),", sp384, temp_v0_13, (u32) (sp370.unk0 & 0xFFF) >> 1, sp370.unk4);
                                        }
                                        gfx0 = temp_v0_13 - 8;
                                        goto block_473;
                                    case 0: // switch 3
                                        sp238.unk0 = (?32) (unaligned s32) gfx0->texture.cmd;
                                        sp238.unk4 = (?32) (unaligned s32) gfx0->words.w1;
                                        if (sp239 == 0) {
                                            temp_t0_25 = this->enableLog;
                                            phi_t0_5 = temp_t0_25;
                                            if (temp_t0_25 != 0) {
                                                if (sp23B != 0) {
                                                    phi_s1_4 = "G_ON";
                                                } else {
                                                    phi_s1_4 = "G_OFF";
                                                }
                                                osSyncPrintf((const char *) "gsSPTexture(%d, %d, %d, %d, %s),", sp23C, sp23E, (u32) (sp238 << 0x12) >> 0x1D, sp23A & 7, phi_s1_4);
                                                goto block_472;
                                            }
                                        } else {
                                            temp_t0_26 = this->enableLog;
                                            phi_t0_5 = temp_t0_26;
                                            if (temp_t0_26 != 0) {
                                                if (sp23B != 0) {
                                                    phi_s1_5 = "G_ON";
                                                } else {
                                                    phi_s1_5 = "G_OFF";
                                                }
                                                osSyncPrintf((const char *) "gsSPTextureL(%d, %d, %d, %d, %d, %s),", sp23C, sp23E, (u32) (sp238 << 0x12) >> 0x1D, (?32) sp239, sp23A & 7, phi_s1_5);
                                                phi_t0_5 = this->enableLog;
                                                goto block_473;
                                            case 1: // switch 3
                                                sp230.unk0 = (u32) gfx0->words.w0;
                                                sp230.unk4 = (u32) gfx0->words.w1;
                                                temp_a1_5 = sp234 >> 6;
                                                if (temp_a1_5 == 1) {
                                                    temp_t0_27 = this->enableLog;
                                                    phi_t0_5 = temp_t0_27;
                                                    if (temp_t0_27 != 0) {
                                                        osSyncPrintf((const char *) "gsSPPopMatrix(G_MTX_MODELVIEW),", temp_a1_5);
                                                        goto block_472;
                                                    }
                                                } else {
                                                    temp_t0_28 = this->enableLog;
                                                    phi_t0_5 = temp_t0_28;
                                                    if (temp_t0_28 != 0) {
                                                        osSyncPrintf((const char *) "gsSPPopMatrixN(G_MTX_MODELVIEW, %d),", temp_a1_5);
                                                        phi_t0_5 = this->enableLog;
                                                        goto block_473;
                                                    case 2: // switch 3
                                                        temp_t0_29 = this->enableLog;
                                                        temp_s0_7 = sp370.unk0 & 0xFFFFFF;
                                                        temp_s1_6 = sp370.unk4 & 0xFFFFFF;
                                                        if (temp_s0_7 == 0) {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPLoadGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(this, temp_s1_6);
                                                            if (this->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        } else if (temp_s1_6 == 0) {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPClearGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(this, ~temp_s0_7);
                                                            if (this->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        } else if (temp_s0_7 == 0xFFFFFF) {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPSetGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(this, temp_s1_6);
                                                            if (this->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        } else {
                                                            if (temp_t0_29 != 0) {
                                                                osSyncPrintf((const char *) "gsSPGeometryMode(");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(this, ~temp_s0_7);
                                                            if (this->enableLog != 0) {
                                                                osSyncPrintf((const char *) ", ");
                                                            }
                                                            UCodeDisas_ParseGeometryMode(this, temp_s1_6);
                                                            if (this->enableLog != 0) {
                                                                osSyncPrintf((const char *) "),");
                                                            }
                                                        }
                                                        temp_t7_4 = this->geometryMode & temp_s0_7;
                                                        this->geometryMode = temp_t7_4;
                                                        this->geometryMode = temp_t7_4 | temp_s1_6;
                                                        phi_t0_5 = this->enableLog;
                                                        goto block_473;
                                                    case 4: // switch 3
                                                        sp21C.unk0 = (u32) gfx0->words.w0;
                                                        sp21C.unk4 = (u32) gfx0->words.w1;
                                                        sp214.unk0 = (u32) gfx0->words.w0;
                                                        sp214.unk4 = (u32) gfx0->words.w1;
                                                        sp217 = sp21D;
                                                        sp214 = ((u32) ((sp21E ^ (sp214 >> 8)) << 0x10) >> 8) ^ sp214;
                                                        sp218 = sp220;
                                                        temp_t9 = sp217 - 2;
                                                        if (temp_t9 < 0xDU) {
                                                            goto **(&jtbl_80149364 + (temp_t9 * 4)); // switch 5
                                                        case 4: // switch 5
                                                            if (this->enableLog != 0) {
                                                                osSyncPrintf((const char *) "gsSPSegment(%d, 0x%08x),", (u32) ((u32) (unaligned s32) sp215 >> 0x10) >> 2, sp218);
                                                            }
                                                            this->segments[(u32) ((u32) (unaligned s32) sp215 >> 0x10) >> 2] = (u32) (sp218 & 0xFFFFFF);
                                                            goto block_472;
                                                        case 2: // switch 5
                                                            if (this->enableLog != 0) {
                                                                if (sp218 != 0) {
                                                                    phi_s1_6 = sp218;
                                                                } else {
                                                                    phi_s1_6 = -sp218;
                                                                }
                                                                osSyncPrintf((const char *) "gsSPClipRatio(FRUSTRATIO_%d), ", phi_s1_6);
                                                            }
                                                            gfx0 = gfx0 + 0x18;
                                                            goto block_473;
                                                        case 0: // switch 5
                                                            temp_t0_30 = this->enableLog;
                                                            phi_t0_5 = temp_t0_30;
                                                            if (temp_t0_30 != 0) {
                                                                osSyncPrintf((const char *) "gsSPNumLights(%d), ", (u32) sp218 / 0x18U);
                                                                goto block_472;
                                                            case 8: // switch 5
                                                                if (this->enableLog != 0) {
                                                                    osSyncPrintf((const char *) "gsSPLightColor(%d, %d), ", ((u32) (((u32) (unaligned s32) sp215 >> 0x10) & 0xF0) >> 5) + 1, sp218);
                                                                }
                                                                gfx0 = gfx0 + 8;
                                                                goto block_473;
                                                            case 6: // switch 5
                                                                temp_t0_31 = this->enableLog;
                                                                phi_t0_5 = temp_t0_31;
                                                                if (temp_t0_31 != 0) {
                                                                    osSyncPrintf((const char *) "gsSPFogFactor(%d, %d),", (u32) sp218 >> 0x10, sp218 & 0xFFFF);
                                                                    goto block_472;
                                                                case 12: // switch 5
                                                                    temp_t0_32 = this->enableLog;
                                                                    phi_t0_5 = temp_t0_32;
                                                                    if (temp_t0_32 != 0) {
                                                                        osSyncPrintf((const char *) "gsSPPerspNormalize(%d),", sp218);
                                                                        goto block_472;
                                                                    }
                                                                }
                                                            }
                                                        } else {
                                                        default: // switch 5
                                                            temp_t0_33 = this->enableLog;
                                                            phi_t0_5 = temp_t0_33;
                                                            if (temp_t0_33 != 0) {
                                                                osSyncPrintf((const char *) "gsMoveWd(%d, %d, %d), ", sp217, (u32) (unaligned s32) sp215 >> 0x10, sp218);
                                                                phi_t0_5 = this->enableLog;
                                                                goto block_473;
                                                            case 5: // switch 3
                                                                sp20C.unk0 = (u32) gfx0->words.w0;
                                                                sp20C.unk4 = (u32) gfx0->words.w1;
                                                                if (sp20F != 8) {
                                                                    if (sp20F != 0xA) {
                                                                        if (sp20F != 0xE) {
                                                                            temp_t0_34 = this->enableLog;
                                                                            phi_t0_5 = temp_t0_34;
                                                                            if (temp_t0_34 != 0) {
                                                                                osSyncPrintf((const char *) "gsMoveMem(0x%08x, %d, %d, %d),", sp210, (((u32) sp20D >> 3) * 8) + 8, sp20F, sp20E * 8);
                                                                                phi_t0_5 = this->enableLog;
                                                                            }
                                                                        } else {
                                                                            if (this->enableLog != 0) {
                                                                                osSyncPrintf((const char *) "gsSPForceMatrix(0x%08x),", sp210);
                                                                            }
                                                                            gfx0 = gfx0 + 8;
                                                                        }
                                                                    } else {
                                                                        temp_v0_11 = sp20E * 8;
                                                                        if (temp_v0_11 != 0) {
                                                                            if (temp_v0_11 != 0x18) {
                                                                                temp_t0_35 = this->enableLog;
                                                                                phi_t0_5 = temp_t0_35;
                                                                                if (temp_t0_35 != 0) {
                                                                                    osSyncPrintf((const char *) "gsSPLight(0x%08x,%d),", sp210, (u32) (temp_v0_11 - 0x18) / 0x18U);
                                                                                    goto block_472;
                                                                                }
                                                                            } else {
                                                                                temp_t0_36 = this->enableLog;
                                                                                phi_t0_5 = temp_t0_36;
                                                                                if (temp_t0_36 != 0) {
                                                                                    osSyncPrintf((const char *) "gsSPLookAtY(0x%08x),", sp210);
                                                                                    goto block_472;
                                                                                }
                                                                            }
                                                                        } else {
                                                                            temp_t0_37 = this->enableLog;
                                                                            phi_t0_5 = temp_t0_37;
                                                                            if (temp_t0_37 != 0) {
                                                                                osSyncPrintf((const char *) "gsSPLookAtX(0x%08x),", sp210);
                                                                                goto block_472;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (this->enableLog != 0) {
                                                                        osSyncPrintf((const char *) "gsSPViewport(0x%08x(0x%08x)),", sp210, temp_s4);
                                                                    }
                                                                    phi_t0_4 = this->enableLog;
                                                                    if (this->enableLog != 0) {
                                                                        osSyncPrintf((const char *) "\t# vscale=[%d %d %d %d], ", (s16) temp_s4->unk0, (s16) temp_s4->unk2, (s16) temp_s4->unk4, (?32) (s16) temp_s4->unk6);
                                                                        phi_t0_4 = this->enableLog;
                                                                    }
                                                                    phi_t0_5 = phi_t0_4;
                                                                    if (phi_t0_4 != 0) {
                                                                        osSyncPrintf((const char *) "vtrans=[%d %d %d %d] ", (s16) temp_s4->unk8, (s16) temp_s4->unkA, (s16) temp_s4->unkC, (?32) (s16) temp_s4->unkE);
                                                                        goto block_472;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
block_408:
                        temp_t0_40 = this->enableLog;
                        phi_t0_5 = temp_t0_40;
                        if (temp_t0_40 != 0) {
                            osSyncPrintf((const char *) "AnyDisplayList(),");
                            phi_t0_5 = this->enableLog;
                        }
                    }
                } else {
                    goto block_408;
                }
            } else {
                goto block_267;
            }
        }
    } else {
        goto block_12;
    }
    goto block_473;
}


void UCodeDisas_RegisterUCode(UCodeDisas* this, s32 count, UCodeInfo* ucodeArray) {
    this->ucodeInfoCount = count;
    this->ucodeInfo = ucodeArray;
}

void UCodeDisas_SetCurUCode(UCodeDisas* this, void* ptr) {
    UCodeDisas_SetCurUCodeImpl(this, ptr);
}
