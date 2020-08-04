/*
 * File: z_en_mag.c
 * Overlay: ovl_En_Mag
 * Description: Title Screen Actor
 */

#include "z_en_mag.h"

#define FLAGS 0x00000030

#define THIS ((EnMag*)thisx)

#define EFFECT_CT 40.0f
#define EFFECT_ALPHA 160
#define TITLE_ALPHA 210
#define SUB_ALPHA 200
#define NO_ALPHA 26
#define YPOS 171

void EnMag_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMag_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMag_Update(Actor* thisx, GameState* game);
void EnMag_Draw(Actor* thisx, GlobalContext* globalCtx);

#define NO_CONTROLLER (gSaveContext.fileNum == 0xFEDC)

Gfx* EnMag_DrawTexRecI8(Gfx** glistp, void* timg, s16 width, s16 height, s16 xpos, s16 ypos, s16 xsize, s16 ysize,
                        u16 xscale, u16 yscale); // texture_rectangleI8
Gfx* func_80AA46A0(Gfx** glistp, void* timg1, void* timg2, s16 width1, s16 height1, s16 width2, s16 height2, s16 xpos,
                   s16 ypos, s16 xsize, s16 ysize, u16 xscale, u16 yscale, u16 xscale2, u16 yscale2, u16 flag,
                   EnMag* this); // texture_multi_rectangle

void EnMag_DisplayRGBA32B(Gfx** glistp, s16 cx, s16 cy, u8* addr, u32 sizex, u32 sizey); // EnMag_DisplayRGBA32B

void EnMag_DisplayMoji(Gfx** glistp, u8* data, s32 xpos, s32 ypos); // moji_display

void EnMag_DrawSub(Actor* thisx, GameState* state, Gfx** glistp); // EnMag_DrawSub

extern u8 g_title_efc_1_txt[];
extern u8 g_title_efc_2_txt[];
extern u8 g_title_efc_3_txt[];
extern u8 g_title_efc_4_txt[];
extern u8 g_title_efc_5_txt[];
extern u8 g_title_efc_6_txt[];
extern u8 g_title_efc_7_txt[];
extern u8 g_title_efc_8_txt[];
extern u8 g_title_efc_9_txt[];
extern u8 g_title_mable_txt[];
extern u8 g_title_txt[];
extern u8 g_title_sub_1_txt[];
extern u8 g_title_sub_2_txt[];
extern u8 g_title_cpr_txt[];
extern u8 D_0601A400[];

const ActorInit En_Mag_InitVars = {
    ACTOR_EN_MAG,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_MAG,
    sizeof(EnMag),
    (ActorFunc)EnMag_Init,
    (ActorFunc)EnMag_Destroy,
    (ActorFunc)EnMag_Update,
    (ActorFunc)EnMag_Draw,
};
s16 check_time = 0;

void EnMag_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMag* this = THIS;
    Kanfont* kanfont = &this->kanfont;

    YREG(1) = 63;
    YREG(3) = 80;
    YREG(4) = 255;
    YREG(5) = 30;
    YREG(6) = 30;
    YREG(7) = 119;
    YREG(8) = 7;
    YREG(9) = 5;
    YREG(10) = 3;

    VREG(4) = 1;
    VREG(5) = 6;
    VREG(6) = 2;
    this->alpha_fdin = 6;
    this->alpha_fdout = 10;

    VREG(19) = 99;
    VREG(21) = 9;
    VREG(23) = 10;
    VREG(24) = 8;

    this->scroll_y = 0;
    this->scroll_x = 0;

    this->effect_prim[0] = 0;
    this->effect_prim[1] = 100;
    this->effect_prim[2] = 170;
    this->effect_env[0] = 0;
    this->effect_env[1] = 100;
    this->effect_env[2] = 0;
    this->effect_rgb_ct = (s16)EFFECT_CT;
    this->effect_rgb_fg = this->effect_prim_f = this->title_mode = this->effect_alpha = this->title_alpha =
        this->sub_alpha = this->copy_alpha = 0;

    if (gSaveContext.unk_13E7) {
        this->title_alpha = 210;
        this->sub_alpha = 255;
        this->copy_alpha = 255;

        this->effect_prim_f = 128.0f;
        this->effect_alpha = 255.0f;

        this->effect_prim[1] = 255.0f;
        this->effect_prim[2] = 255.0f;
        this->effect_env[1] = 255.0f;
        this->effect_prim[0] = 170.0f;
        this->effect_env[0] = 200.0f;
        this->effect_env[2] = 0.0f;

        gSaveContext.unk_13E7 = 0;
        this->title_mode = 2;
        check_time = 20;
        gSaveContext.fadeDuration = 1;
        gSaveContext.unk_1419 = 255;
    }
    func_8006EF10(kanfont);
    this->key_point = 0;
    this->key_frame = 0;
    this->old_key = 0;
    this->key_wait = 0;
}

void EnMag_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void EnMag_Update(Actor* thisx, GameState* state) {
    EnMag* this = THIS;
    GlobalContext* globalCtx = (GlobalContext*)state;
    Input* input = &globalCtx->state.input[0];

    if (!NO_CONTROLLER) {
        if (this->title_mode <= 1) {
            if (CHECK_PAD(input->press, START_BUTTON) || CHECK_PAD(input->press, A_BUTTON) ||
                CHECK_PAD(input->press, B_BUTTON)) {
                Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0, &D_801333E8);
                this->title_alpha = 210;
                this->sub_alpha = 255;
                this->copy_alpha = 255;

                this->effect_prim_f = 128.0f;
                this->effect_alpha = 255.0f;

                this->effect_prim[1] = 255.0f;
                this->effect_prim[2] = 255.0f;
                this->effect_env[1] = 255.0f;
                this->effect_prim[0] = 170.0f;
                this->effect_env[0] = 200.0f;
                this->effect_env[2] = 0.0f;

                this->title_mode = 2;
                check_time = 20;
                gSaveContext.fadeDuration = 1;
                gSaveContext.unk_1419 = 255;
            }
        } else if (this->title_mode >= 2) {
            if (!check_time) {
                if (CHECK_PAD(input->press, START_BUTTON) || CHECK_PAD(input->press, A_BUTTON) ||
                    CHECK_PAD(input->press, B_BUTTON)) {
                    // globalCtx->sceneLoadFlag != globalCtx_FADE_OUT
                    if (globalCtx->sceneLoadFlag != 20) {
                        func_800F68BC(0);
                        Audio_PlaySoundGeneral(NA_SE_SY_PIECE_OF_HEART, &D_801333D4, 4, &D_801333E0, &D_801333E0,
                                               &D_801333E8);
                        gSaveContext.gameMode = 2;     // GAME_INFO_OPENING_SELECT
                        globalCtx->sceneLoadFlag = 20; // globalCtx_FADE_OUT
                        globalCtx->fadeTransition = 2;
                    }
                    this->alpha_fdin = 15;
                    this->alpha_fdout = 25;
                    this->title_mode = 3;
                }
            } else {
                check_time--;
            }
        }
    }
    if (this->title_mode == 1) {
        if (!this->effect_rgb_fg) {
            this->effect_alpha += (255.0f / EFFECT_CT);
            this->effect_prim_f += (32.0f / EFFECT_CT);
            this->effect_prim[0] += (255.0f / EFFECT_CT);
            this->effect_prim[1] += ((255.0f - 100.0f) / EFFECT_CT);
            this->effect_prim[2] += ((255.0f - 170.0f) / EFFECT_CT);
            this->effect_env[0] += (255.0f / EFFECT_CT);
            this->effect_env[1] += ((255.0f - 100.0f) / EFFECT_CT);
            if (!(--this->effect_rgb_ct)) {
                this->effect_prim_f = 32.0f;
                this->effect_alpha = 255.0f;
                this->effect_prim[0] = 255.0f;
                this->effect_prim[1] = 255.0f;
                this->effect_prim[2] = 255.0f;
                this->effect_env[0] = 255.0f;
                this->effect_env[1] = 255.0f;
                this->effect_rgb_ct = (s16)EFFECT_CT;
                this->effect_rgb_fg = 1;
            }
        } else if (this->effect_rgb_fg == 1) {
            this->effect_prim[0] += ((170.0f - 255.0f) / EFFECT_CT);
            this->effect_env[0] += -1.375f;
            this->effect_prim_f += ((128.0f - 32.0f) / EFFECT_CT);
            if (!(--this->effect_rgb_ct)) {
                this->effect_prim_f = 128.0f;
                this->effect_prim[0] = 170.0f;
                this->effect_env[0] = 200.0f;
                this->effect_rgb_ct = 32.0f;
                this->effect_rgb_fg = 2.0f;
            }
        }
        if (this->effect_alpha > EFFECT_ALPHA) {
            if ((this->title_alpha += VREG(5)) >= 210.0f) {
                this->title_alpha = 210.0f;
            }
            if (this->title_alpha >= TITLE_ALPHA) {
                if ((this->sub_alpha += VREG(6)) >= 255.0f) {
                    this->sub_alpha = 255.0f;
                }
                if (this->sub_alpha >= SUB_ALPHA) {
                    if ((this->copy_alpha += this->alpha_fdin) >= 255.0f) {
                        this->copy_alpha = 255.0f;
                        this->title_mode = 2;
                        check_time = 20;
                    }
                }
            }
        }

    } else if (this->title_mode == 3) {
        if ((this->effect_alpha -= this->alpha_fdout) < 0) {
            this->effect_alpha = 0;
        }
        if ((this->title_alpha -= this->alpha_fdout) < 0) {
            this->title_alpha = 0;
        }
        if ((this->sub_alpha -= this->alpha_fdout) < 0) {
            this->sub_alpha = 0;
        }
        if ((this->copy_alpha -= this->alpha_fdin) < 0) {
            this->copy_alpha = 0;
            this->title_mode = 4;
        }
    }

    if (!this->title_mode) {
        if (Flags_GetEnv(globalCtx, 3)) {
            this->effect_rgb_ct = 40.0f;
            this->title_mode = 1;
        }
    } else if (this->title_mode == 2) {
        if (Flags_GetEnv(globalCtx, 4)) {
            this->title_mode = 3;
        }
    }
}

Gfx* EnMag_DrawTexRecI8(Gfx** glistp, void* timg, s16 width, s16 height, s16 xpos, s16 ypos, s16 xsize, s16 ysize,
                        u16 xscale, u16 yscale) {
    Gfx* gp = *glistp;

    gDPLoadTextureBlock(gp++, timg, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR, G_TX_NOMIRROR,
                        G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gp++, ((xpos)*0x4), ((ypos)*0x4), ((xpos + xsize) * 0x4), ((ypos + ysize) * 0x4),
                        G_TX_RENDERTILE, 0, 0, xscale, yscale);

    *glistp = gp;
}

Gfx* func_80AA46A0(Gfx** glistp, void* timg1, void* timg2, s16 width1, s16 height1, s16 width2, s16 height2, s16 xpos,
                   s16 ypos, s16 xsize, s16 ysize, u16 xscale, u16 yscale, u16 xscale2, u16 yscale2, u16 flag,
                   EnMag* this) {
    Gfx* gp = *glistp;

    gDPLoadMultiBlock_4b(gp++, timg1, 0, G_TX_RENDERTILE, G_IM_FMT_I, width1, height1, 0, G_TX_WRAP | G_TX_NOMIRROR,
                         G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    if (!flag) {
        gDPLoadMultiBlock(gp++, timg2, 256, G_TX_RENDERTILE + 1, G_IM_FMT_I, G_IM_SIZ_8b, width2, height2, 0,
                          G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, 5, xscale2, yscale2);
        gDPSetTileSize(gp++, G_TX_RENDERTILE + 1, 0, this->scroll_y & 0x7f, 31 << 2,
                       (this->scroll_y & 0x7f) + (31 << 2));
    }
    gSPTextureRectangle(gp++, ((xpos)*0x4), ((ypos)*0x4), ((xpos + xsize) * 0x4), ((ypos + ysize) * 0x4),
                        G_TX_RENDERTILE, 0, 0, xscale, yscale);

    *glistp = gp;
}

void EnMag_DisplayRGBA32B(Gfx** glistp, s16 cx, s16 cy, u8* addr, u32 sizex, u32 sizey) {
    Gfx* gp = *glistp;

    s32 i, cnt, sx, sy;
    s32 cuty, size, amari, texsize;
    u8* imageaddr;

    func_80094D28(&gp);

    imageaddr = addr;
    size = (s32)(sizex * sizey * 4);
    sx = cx - (s32)(sizex / 2);
    sy = cy - (s32)(sizey / 2);
    cuty = (s32)(4096 / (sizex * 4));
    texsize = (s32)sizex * cuty * 4;

    cnt = (s32)size / texsize;
    amari = size % texsize;
    if (amari) {
        cnt++;
    }

    gDPSetImageTile(gp++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 0, 0, (sizex - 1), (cuty - 1), 0, G_TX_NOMIRROR | G_TX_CLAMP,
                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    size -= texsize;

    for (i = 0; i < cnt; i++) {
        gDPSetTextureImage(gp++, G_IM_FMT_RGBA, G_IM_SIZ_32b, sizex, imageaddr);
        gDPLoadSync(gp++);
        gDPLoadTile(gp++, G_TX_LOADTILE, 0, 0, (sizex - 1) << G_TEXTURE_IMAGE_FRAC, (cuty - 1) << G_TEXTURE_IMAGE_FRAC);

        gSPTextureRectangle(gp++, sx << 2, sy << 2, (sx + (s32)sizex) << 2, (sy + (s32)cuty) << 2, 0, 0 << 5, 0 << 5,
                            1 << 10, 1 << 10);

        imageaddr += texsize;
        sy += cuty;
        if (size - texsize < 0) {
            if (size > 0) {
                cuty = size / (s32)(sizex * 4);
                size -= texsize;
                gDPSetImageTile(gp++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 0, 0, (sizex - 1), (cuty - 1), 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            }
        } else {
            size -= texsize;
        }
    }
    *glistp = gp;
}

void EnMag_DisplayMoji(Gfx** glistp, u8* data, s32 xpos, s32 ypos) {
    Gfx* gp = *glistp;

    YREG(0) = ((s32)(1024.0f / ((f32)YREG(1) / 100.0f)));
    YREG(2) = ((s32)(16.0f * ((f32)YREG(1) / 100.0f)));

    gDPLoadTextureBlock_4b(gp++, data, G_IM_FMT_I, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gp++, xpos << 2, ypos << 2, (xpos + YREG(2)) << 2, (ypos + YREG(2)) << 2, G_TX_RENDERTILE, 0, 0,
                        YREG(0), YREG(0));
    *glistp = gp;
}

void EnMag_DrawSub(Actor* thisx, GameState* state, Gfx** glistp) {
    EnMag* this = THIS;
    GlobalContext* globalCtx = (GlobalContext*)state;
    Kanfont* kanfont = (Kanfont*)&this->kanfont;

    Gfx* gp = *glistp;

    u16 i, j, k, xpos, ypos;

    static s16 no_alpha = 0;      // no_alpha
    static s16 no_alpha_mode = 0; // no_alpha_mode
    static s16 no_alpha_ct = 0;   // no_alpha_ct
    static u8 no_controller[] = {
        AAN, AAO, AAC, AAO, AAN, AAT, AAR, AAO, AAL, AAL, AAE, AAR,
    }; // no_controller

    static u8 press_start[] = {
        AAP, AAR, AAE, AAS, AAS, AAS, AAT, AAA, AAR, AAT,
    }; // press_start

    static u8* g_title_efc_txt_data[] = {
        g_title_efc_1_txt, g_title_efc_2_txt, g_title_efc_3_txt, g_title_efc_4_txt, g_title_efc_5_txt,
        g_title_efc_6_txt, g_title_efc_7_txt, g_title_efc_8_txt, g_title_efc_9_txt,
    }; // g_title_efc_txt_data

    gSPSegment(gp++, 0x06, globalCtx->objectCtx.status[thisx->objBankIndex].segment);

    func_8009457C(&gp);
    this->scroll_y -= 2;
    gDPSetCycleType(gp++, G_CYC_2CYCLE);
    gDPSetAlphaCompare(gp++, G_AC_THRESHOLD);
    gDPSetRenderMode(gp++, G_RM_PASS, G_RM_CLD_SURF2);
    gDPSetCombineLERP(gp++, TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, 1, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                      ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gp++, 0, (s16)this->effect_prim_f, (s16)this->effect_prim[0], (s16)this->effect_prim[1],
                    (s16)this->effect_prim[2], (s16)this->effect_alpha);
    gDPSetEnvColor(gp++, (s16)this->effect_env[0], (s16)this->effect_env[1], (s16)this->effect_env[2], 255);
    ypos = 0;
    if ((s16)this->effect_prim_f != 0) {
        for (i = k = 0, ypos; i < 3; i++) {
            for (j = 0, xpos = 56; j < 3; j++, k++, xpos += 64) {
                func_80AA46A0(&gp, g_title_efc_txt_data[k], g_title_mable_txt, 64, 64, 32, 32, xpos, ypos, 64, 64,
                              1 << 10, 1 << 10, 1, 1, k, this);
            }
            ypos += 64;
        }
    }
    gDPSetPrimColor(gp++, 0, 0, 255, 255, 255, (s16)this->title_alpha);
    if ((s16)this->title_alpha) {
        EnMag_DisplayRGBA32B(&gp, 152, 100, g_title_txt, 160, 160);
    }

    func_8009457C(&gp);
    gDPPipeSync(gp++);
    gDPSetAlphaCompare(gp++, G_AC_NONE);
    gDPSetCombineLERP(gp++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    if ((s16)this->title_alpha < 100) {
        gDPSetRenderMode(gp++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    } else {
        gDPSetRenderMode(gp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    }
    gDPSetPrimColor(gp++, 0, 0, 0, 0, 0, (s16)this->title_alpha);
    gDPSetEnvColor(gp++, 0, 0, 100, 255);
    if ((s16)this->title_alpha) {
        EnMag_DrawTexRecI8(&gp, g_title_sub_1_txt, 72, 8, 146, 73, 72, 8, 1 << 10, 1 << 10);
        EnMag_DrawTexRecI8(&gp, g_title_sub_2_txt, 96, 8, 144, 127, 96, 8, 1 << 10, 1 << 10);
        gDPPipeSync(gp++);
        gDPSetPrimColor(gp++, 0, 0, 100, 150, 255, (s16)this->title_alpha);
        gDPSetEnvColor(gp++, 20, 80, 160, 255);
        EnMag_DrawTexRecI8(&gp, g_title_sub_1_txt, 72, 8, 145, 73 - 1, 72, 8, 1 << 10, 1 << 10);
        EnMag_DrawTexRecI8(&gp, g_title_sub_2_txt, 96, 8, 143, 127 - 1, 96, 8, 1 << 10, 1 << 10);
        gDPPipeSync(gp++);
        gDPSetPrimColor(gp++, 0, 0, 255, 255, 255, (s16)this->sub_alpha);
        EnMag_DisplayRGBA32B(&gp, 174, 145, D_0601A400, 128, 32);
    }
    func_8009457C(&gp);
    gDPSetAlphaCompare(gp++, G_AC_NONE);
    gDPSetCombineMode(gp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(gp++, 0, 0, (s16)this->copy_alpha, (s16)this->copy_alpha, (s16)this->copy_alpha,
                    (s16)this->copy_alpha);
    if ((s16)this->copy_alpha) {
        gDPSetTextureImage(gp++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, g_title_cpr_txt);
        gDPSetTile(gp++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(gp++);
        gDPLoadBlock(gp++, G_TX_LOADTILE, 0, 0, 1279, 103);
        gDPPipeSync(gp++);
        gDPSetTile(gp++, G_IM_FMT_IA, G_IM_SIZ_8b, 20, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(gp++, G_TX_RENDERTILE, 0, 0, 0x027C, 0x003C);
        gSPTextureRectangle(gp++, (78 << 2), (198 << 2), (238 << 2), (214 << 2), G_TX_RENDERTILE, 0, 0, (32 << 5),
                            (32 << 5));
    }

    if (NO_CONTROLLER) {
        no_alpha = (260 / NO_ALPHA) * no_alpha_ct;
        if (no_alpha >= 255) {
            no_alpha = 255;
        }
        gDPPipeSync(gp++);
        gDPSetCombineLERP(gp++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE,
                          0);
        gDPSetPrimColor(gp++, 0, 0, 0, 0, 0, no_alpha);
        xpos = VREG(19) + 1;
        for (i = 0; i < 12; i++) {
            EnMag_DisplayMoji(&gp, ((u8*)kanfont->kbuffer4) + (BUF_CT * no_controller[i]), xpos, YPOS + 1 + YREG(10));
            xpos += VREG(21);
            if (i == 1) {
                xpos += VREG(23);
            }
        }
        gDPPipeSync(gp++);
        gDPSetPrimColor(gp++, 0, 0, 100, 255, 255, no_alpha);
        xpos = VREG(19);
        for (i = 0; i < 12; i++) {
            EnMag_DisplayMoji(&gp, ((u8*)kanfont->kbuffer4) + (BUF_CT * no_controller[i]), xpos, YPOS + YREG(10));
            xpos += VREG(21);
            if (i == 1) {
                xpos += VREG(23);
            }
        }
    } else {
        if (this->copy_alpha >= 200) {
            no_alpha = (260 / NO_ALPHA) * no_alpha_ct;
            if (no_alpha >= 255) {
                no_alpha = 255;
            }
            gDPPipeSync(gp++);
            gDPSetCombineLERP(gp++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                              PRIMITIVE, 0);
            gDPSetPrimColor(gp++, 0, 0, 0, 0, 0, no_alpha);
            xpos = YREG(7) + 1;
            for (i = 0; i < 10; i++) {
                EnMag_DisplayMoji(&gp, ((u8*)kanfont->kbuffer4) + (BUF_CT * press_start[i]), xpos, YPOS + 1 + YREG(10));
                xpos += YREG(8);
                if (i == 4) {
                    xpos += YREG(9);
                }
            }
            gDPPipeSync(gp++);
            gDPSetPrimColor(gp++, 0, 0, YREG(4), YREG(5), YREG(6), no_alpha);
            xpos = YREG(7);
            for (i = 0; i < 10; i++) {
                EnMag_DisplayMoji(&gp, ((u8*)kanfont->kbuffer4) + (BUF_CT * press_start[i]), xpos, YPOS + YREG(10));
                xpos += YREG(8);
                if (i == 4) {
                    xpos += YREG(9);
                }
            }
        }
    }
    if (no_alpha_mode) {
        if (!(--no_alpha_ct)) {
            no_alpha_mode = 0;
        }
    } else {
        if ((++no_alpha_ct) >= NO_ALPHA) {
            no_alpha_mode = 1;
        }
    }

    *glistp = gp;
}

void EnMag_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnMag* this = THIS;
    Gfx *glistp, *glistp_save;

    OPEN_DISP(globalCtx->state.gfxCtx, "../z_en_mag.c", 1151);

    glistp = Graph_GfxPlusOne(glistp_save = gfxCtx->polyOpa.p);
    gSPDisplayList(gfxCtx->overlay.p++, glistp);
    EnMag_DrawSub(this, globalCtx, &glistp);

    gSPEndDisplayList(glistp++);
    Graph_BranchDlist(glistp_save, glistp);
    gfxCtx->polyOpa.p = glistp;
    CLOSE_DISP(globalCtx->state.gfxCtx, "../z_en_mag.c", 1161);
}
