#include "global.h"
#include "vt.h"
#include "z64environment.h"

u32 D_8012AC90[4] = {
    0x00000000,
    0x00010000,
    0x00020000,
    0x00030000,
};

u16 D_8012ACA0[2][0x20] = {
    { 0x00, 0x02, 0x0A, 0x0C, 0x02, 0x04, 0x0C, 0x0E, 0x0A, 0x0C, 0x14, 0x16, 0x0C, 0x0E, 0x16, 0x18,
      0x01, 0x03, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0B, 0x0D, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x15, 0x17 },
    { 0x14, 0x16, 0x1E, 0x20, 0x16, 0x18, 0x20, 0x22, 0x1E, 0x20, 0x28, 0x2A, 0x20, 0x22, 0x2A, 0x2C,
      0x15, 0x17, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1F, 0x21, 0x23, 0x24, 0x25, 0x26, 0x27, 0x29, 0x2B },
};

s16 D_8012AD20[5] = {
    0x0000, 0x0FC0, 0x1F80, 0x2F40, 0x3F00,
};

s16 D_8012AD2C[9] = {
    0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00, 0x26C0, 0x2E80, 0x3640, 0x3E00,
};

s16 D_8012AD40[0x40] = {
    0x00, 0x10, 0x13, 0x12, 0x10, 0x01, 0x14, 0x13, 0x01, 0x11, 0x15, 0x14, 0x11, 0x05, 0x16, 0x15,
    0x12, 0x13, 0x17, 0x02, 0x13, 0x14, 0x03, 0x17, 0x14, 0x15, 0x18, 0x03, 0x15, 0x16, 0x07, 0x18,
    0x02, 0x17, 0x1A, 0x19, 0x17, 0x03, 0x1B, 0x1A, 0x03, 0x18, 0x1C, 0x1B, 0x18, 0x07, 0x1D, 0x1C,
    0x19, 0x1A, 0x1E, 0x0A, 0x1A, 0x1B, 0x0B, 0x1E, 0x1B, 0x1C, 0x1F, 0x0B, 0x1C, 0x1D, 0x0F, 0x1F,
};

u32 D_8012ADC0[6] = {
    0x00000000, 0x00002000, 0x00004000, 0x00006000, 0x00008000, 0x0000C000,
};

u16 D_8012ADD8[0x20] = {
    0x00, 0x02, 0x0A, 0x0C, 0x02, 0x04, 0x0C, 0x0E, 0x0A, 0x0C, 0x14, 0x16, 0x0C, 0x0E, 0x16, 0x18,
    0x01, 0x03, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0B, 0x0D, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x15, 0x17,
};

s16 D_8012AE18[5] = {
    0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00,
};

s16 D_8012AE24[5] = {
    0x0000, 0x07C0, 0x0F80, 0x1740, 0x1F00,
};

s16 D_8012AE30[5] = {
    0x0000, 0x07C0, 0x0F80, 0x07C0, 0x0000,
};

s16 D_8012AE3C[0x40] = {
    0x00, 0x10, 0x13, 0x12, 0x10, 0x01, 0x14, 0x13, 0x01, 0x11, 0x15, 0x14, 0x11, 0x05, 0x16, 0x15,
    0x12, 0x13, 0x17, 0x02, 0x13, 0x14, 0x03, 0x17, 0x14, 0x15, 0x18, 0x03, 0x15, 0x16, 0x07, 0x18,
    0x02, 0x17, 0x1A, 0x19, 0x17, 0x03, 0x1B, 0x1A, 0x03, 0x18, 0x1C, 0x1B, 0x18, 0x07, 0x1D, 0x1C,
    0x19, 0x1A, 0x1E, 0x0A, 0x1A, 0x1B, 0x0B, 0x1E, 0x1B, 0x1C, 0x1F, 0x0B, 0x1C, 0x1D, 0x0F, 0x1F,
};

typedef struct {
    /* 0x000 */ s32 unk_0;
    /* 0x004 */ s32 unk_4;
    /* 0x008 */ s32 unk_8;
    /* 0x00C */ s32 unk_C;
    /* 0x010 */ s32 unk_10;
} Struct_8012AF0C; // size = 0x14

Struct_8012AF0C D_8012AEBC[4] = {
    { -0x7E, 0x7C, -0x7E, 0x3F, -0x1F },
    { 0x7E, 0x7C, -0x7E, 0x3F, -0x1F },
    { 0x7E, 0x7C, 0x7E, -0x3F, -0x1F },
    { -0x7E, 0x7C, 0x7E, -0x3F, -0x1F },
};

Struct_8012AF0C D_8012AF0C[6] = {
    { -0x40, 0x40, -0x40, 0x20, -0x20 }, { 0x40, 0x40, 0x40, -0x20, -0x20 }, { -0x40, 0x40, 0x40, -0x20, -0x20 },
    { 0x40, 0x40, -0x40, 0x20, -0x20 },  { -0x40, 0x40, 0x40, 0x20, -0x20 }, { -0x40, -0x40, -0x40, 0x20, 0x20 },
};

s32 func_800ADBB0(SkyboxContext* skyboxCtx, Vtx* roomVtx, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                  s32 arg8, s32 arg9) {
    u32 pad42C;
    s32 pad428;
    s32 sp424;
    s32 i;
    s32 j;
    s32 k;
    u16 index;
    s16 phi_t1;
    s16 phi_a2_4;
    s16 phi_a0_4;
    s16 phi_t2_4;
    s16 phi_ra;
    s32 sp358[9 * 5];
    s32 sp2A4[9 * 5];
    s32 sp1F0[9 * 5];
    s32 sp13C[9 * 5];
    s32 sp88[9 * 5];

    switch (arg8) {
        case 0:
        case 2:
            pad428 = arg4;

            for (i = 0, k = 0; k < 45; i++) {
                pad42C = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp1F0[k] = arg5;
                    sp358[k] = pad42C;
                    sp2A4[k] = pad428;
                    sp13C[k] = D_8012AD20[j];
                    sp88[k] = D_8012AD2C[i];
                    pad42C += arg6;
                }
                pad428 += arg7;
            }
            break;

        case 1:
        case 3:
            pad428 = arg4;

            for (i = 0, k = 0; k < 45; i++) {
                pad42C = arg5;
                for (j = 0; j < 5; j++, k++) {
                    sp358[k] = arg3;
                    sp2A4[k] = pad428;
                    sp1F0[k] = pad42C;
                    sp13C[k] = D_8012AD20[j];
                    sp88[k] = D_8012AD2C[i];
                    pad42C += arg6;
                }
                pad428 += arg7;
            }
            break;

        case 4:
        case 5:
            pad428 = arg5;

            for (i = 0, k = 0; k < 45; i++) {
                pad42C = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp2A4[k] = arg4;
                    sp358[k] = pad42C;
                    sp1F0[k] = pad428;
                    sp13C[k] = D_8012AD20[j];
                    sp88[k] = D_8012AD2C[i];
                    pad42C += arg6;
                }
                pad428 += arg7;
            }
            break;
    }

    for (phi_a2_4 = 0, sp424 = 0; sp424 < 2; sp424++) {
        skyboxCtx->unk_138 = skyboxCtx->dListBuf[arg9 + sp424];

        for (i = 0; i < 0x20; i++) {
            index = D_8012ACA0[sp424][i];

            roomVtx[arg2 + i].v.ob[0] = sp358[index];
            roomVtx[arg2 + i].v.ob[1] = sp2A4[index];
            roomVtx[arg2 + i].v.ob[2] = sp1F0[index];
            roomVtx[arg2 + i].v.flag = 0;
            roomVtx[arg2 + i].v.tc[0] = sp13C[index];
            roomVtx[arg2 + i].v.tc[1] = sp88[index];
            roomVtx[arg2 + i].v.cn[1] = 0;
            roomVtx[arg2 + i].v.cn[2] = 0;
            roomVtx[arg2 + i].v.cn[0] = 255;
        }
        gSPVertex(skyboxCtx->unk_138++, &roomVtx[arg2], 32, 0);
        arg2 += i;
        gSPCullDisplayList(skyboxCtx->unk_138++, 0, 15);

        for (phi_t2_4 = 0, phi_ra = 0; phi_ra < 4; phi_ra++, phi_a2_4 += 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x3F, phi_t2_4 += 4) {
                gDPLoadTextureTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[0] + D_8012AC90[arg8],
                                   G_IM_FMT_CI, G_IM_SIZ_8b, 256, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x3F,
                                   phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AD40[phi_t2_4 + 1], D_8012AD40[phi_t2_4 + 2],
                               D_8012AD40[phi_t2_4 + 3], D_8012AD40[phi_t2_4 + 0], 3);
            }
        }
        gSPEndDisplayList(skyboxCtx->unk_138++);
    }
    return arg2;
}

s32 func_800AE2C0(SkyboxContext* skyboxCtx, Vtx* roomVtx, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                  s32 arg8) {
    s32 i;
    s32 j;
    s32 k;
    s16 phi_a0_4;
    s16 phi_t1;
    s32 temp1;
    u16 index;
    s16 phi_a2_4;
    s16 phi_ra;
    s16 phi_t2_4;
    s32 temp2;
    s32 sp2B4[5 * 5];
    s32 sp250[5 * 5];
    s32 sp1EC[5 * 5];
    s32 sp188[5 * 5];
    s32 sp124[5 * 5];

    switch (arg8) {
        case 0:
        case 1:
            temp1 = arg4;

            for (i = 0, k = 0; k < 25; i++) {
                temp2 = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp1EC[k] = arg5;
                    sp2B4[k] = temp2;
                    sp250[k] = temp1;
                    sp188[k] = D_8012AE18[j];
                    sp124[k] = D_8012AE30[i];
                    temp2 += arg6;
                }
                temp1 += arg7;
            }
            break;

        case 2:
        case 3:
            temp1 = arg4;

            for (i = 0, k = 0; k < 25; i++) {
                temp2 = arg5;
                for (j = 0; j < 5; j++, k++) {
                    sp2B4[k] = arg3;
                    sp250[k] = temp1;
                    sp1EC[k] = temp2;
                    sp188[k] = D_8012AE18[j];
                    sp124[k] = D_8012AE30[i];
                    temp2 += arg6;
                }
                temp1 += arg7;
            }
            break;

        case 4:
        case 5:
            temp1 = arg5;

            for (i = 0, k = 0; k < 25; i++) {
                temp2 = arg3;
                for (j = 0; j < 5; j++, k++) {
                    sp250[k] = arg4;
                    sp2B4[k] = temp2;
                    sp1EC[k] = temp1;
                    sp188[k] = D_8012AE18[j];
                    sp124[k] = D_8012AE24[i];
                    temp2 += arg6;
                }
                temp1 += arg7;
            }
            break;
    }
    skyboxCtx->unk_138 = &skyboxCtx->dListBuf[2 * arg8];

    for (i = 0; i < 0x20; i++) {
        index = D_8012ADD8[i];

        roomVtx[arg2 + i].v.ob[0] = sp2B4[index];
        roomVtx[arg2 + i].v.ob[1] = sp250[index];
        roomVtx[arg2 + i].v.ob[2] = sp1EC[index];
        roomVtx[arg2 + i].v.flag = 0;
        roomVtx[arg2 + i].v.tc[0] = sp188[index];
        roomVtx[arg2 + i].v.tc[1] = sp124[index];
        roomVtx[arg2 + i].v.cn[1] = 0;
        roomVtx[arg2 + i].v.cn[2] = 0;
        roomVtx[arg2 + i].v.cn[0] = 255;
    }
    gSPVertex(skyboxCtx->unk_138++, &roomVtx[arg2], 32, 0);
    arg2 += i;
    gSPCullDisplayList(skyboxCtx->unk_138++, 0, 15);

    if ((arg8 == 4) || (arg8 == 5)) {
        phi_a2_4 = 0;
        for (phi_t2_4 = 0, phi_ra = 0; phi_ra < 4; phi_ra++, phi_a2_4 += 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x1F, phi_t2_4 += 4) {
                gDPLoadMultiTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[0] + D_8012ADC0[arg8], 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F,
                                 phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[1] + D_8012ADC0[arg8], 0x80, 1,
                                 G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F, phi_a2_4 + 0x1F,
                                 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AE3C[phi_t2_4 + 1], D_8012AE3C[phi_t2_4 + 2],
                               D_8012AE3C[phi_t2_4 + 3], D_8012AE3C[phi_t2_4 + 0], 3);
            }
        }
    } else {
        phi_a2_4 = 0;
        for (phi_t2_4 = 0, phi_ra = 0; phi_ra < 2; phi_ra++, phi_a2_4 += 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x1F, phi_t2_4 += 4) {
                gDPLoadMultiTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[0] + D_8012ADC0[arg8], 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F,
                                 phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[1] + D_8012ADC0[arg8], 0x80, 1,
                                 G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F, phi_a2_4 + 0x1F,
                                 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AE3C[phi_t2_4 + 1], D_8012AE3C[phi_t2_4 + 2],
                               D_8012AE3C[phi_t2_4 + 3], D_8012AE3C[phi_t2_4 + 0], 3);
            }
        }
        phi_a2_4 -= 0x1F;
        for (phi_ra = 0; phi_ra < 2; phi_ra++, phi_a2_4 -= 0x1F) {
            for (phi_a0_4 = 0, phi_t1 = 0; phi_t1 < 4; phi_t1++, phi_a0_4 += 0x1F, phi_t2_4 += 4) {
                gDPLoadMultiTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[0] + D_8012ADC0[arg8], 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F,
                                 phi_a2_4 + 0x1F, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(skyboxCtx->unk_138++, (u32)skyboxCtx->staticSegments[1] + D_8012ADC0[arg8], 0x80, 1,
                                 G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, phi_a0_4, phi_a2_4, phi_a0_4 + 0x1F, phi_a2_4 + 0x1F,
                                 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->unk_138++, D_8012AE3C[phi_t2_4 + 1], D_8012AE3C[phi_t2_4 + 2],
                               D_8012AE3C[phi_t2_4 + 3], D_8012AE3C[phi_t2_4 + 0], 3);
            }
        }
    }
    gSPEndDisplayList(skyboxCtx->unk_138++);
    return arg2;
}

void func_800AEFC8(SkyboxContext* skyboxCtx, s16 skyboxId) {
    s32 i;
    s32 j;
    s32 phi_s3 = 0;

    if (skyboxId == SKYBOX_BAZAAR || (skyboxId > SKYBOX_HOUSE_KAKARIKO && skyboxId <= SKYBOX_BOMBCHU_SHOP)) {
        for (j = 0, i = 0; i < 2; i++, j += 2) {
            phi_s3 = func_800ADBB0(skyboxCtx, skyboxCtx->roomVtx, phi_s3, D_8012AEBC[i].unk_0, D_8012AEBC[i].unk_4,
                                   D_8012AEBC[i].unk_8, D_8012AEBC[i].unk_C, D_8012AEBC[i].unk_10, i, j);
        }
    } else if (skyboxCtx->unk_140 == 2) {
        for (j = 0, i = 0; i < 3; i++, j += 2) {
            phi_s3 = func_800ADBB0(skyboxCtx, skyboxCtx->roomVtx, phi_s3, D_8012AEBC[i].unk_0, D_8012AEBC[i].unk_4,
                                   D_8012AEBC[i].unk_8, D_8012AEBC[i].unk_C, D_8012AEBC[i].unk_10, i, j);
        }
    } else {
        for (j = 0, i = 0; i < 4; i++, j += 2) {
            phi_s3 = func_800ADBB0(skyboxCtx, skyboxCtx->roomVtx, phi_s3, D_8012AEBC[i].unk_0, D_8012AEBC[i].unk_4,
                                   D_8012AEBC[i].unk_8, D_8012AEBC[i].unk_C, D_8012AEBC[i].unk_10, i, j);
        }
    }
}

void func_800AF178(SkyboxContext* skyboxCtx, s32 arg1) {
    s32 phi_s2 = 0;
    s32 i;

    for (i = 0; i < arg1; i++) {
        phi_s2 = func_800AE2C0(skyboxCtx, skyboxCtx->roomVtx, phi_s2, D_8012AF0C[i].unk_0, D_8012AF0C[i].unk_4,
                               D_8012AF0C[i].unk_8, D_8012AF0C[i].unk_C, D_8012AF0C[i].unk_10, i);
    }
}

void Skybox_Setup(GlobalContext* globalCtx, SkyboxContext* skyboxCtx, s16 skyboxId) {
    u32 size;
    s16 i;
    u8 sp41; // imageIdx
    u8 sp40; // imageIdx2
    u32 start;
    s32 phi_v1;

    switch (skyboxId) {
        case SKYBOX_NORMAL_SKY:
            phi_v1 = 0;
            if (gSaveContext.unk_13C3 != 0 && gSaveContext.sceneSetupIndex < 4 && gWeatherMode > 0 &&
                gWeatherMode < 6) {
                phi_v1 = 1;
            }

            for (i = 0; i < 9; i++) {
                if (gSaveContext.skyboxTime >= D_8011FC1C[phi_v1][i].startTime &&
                    (gSaveContext.skyboxTime < D_8011FC1C[phi_v1][i].endTime ||
                     D_8011FC1C[phi_v1][i].endTime == 0xFFFF)) {
                    globalCtx->envCtx.skybox1Index = sp41 = D_8011FC1C[phi_v1][i].skybox1Index;
                    globalCtx->envCtx.skybox2Index = sp40 = D_8011FC1C[phi_v1][i].skybox2Index;
                    if (D_8011FC1C[phi_v1][i].blend != 0) {
                        globalCtx->envCtx.skyboxBlend =
                            Environment_LerpWeight(D_8011FC1C[phi_v1][i].endTime, D_8011FC1C[phi_v1][i].startTime,
                                                   ((void)0, gSaveContext.skyboxTime)) *
                            255.0f;
                    } else {
                        globalCtx->envCtx.skyboxBlend = 0;
                    }
                    break;
                }
            }

            size = gSkyboxFiles[sp41].file.vromEnd - gSkyboxFiles[sp41].file.vromStart;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], gSkyboxFiles[sp41].file.vromStart, size, "../z_vr_box.c",
                                __LINE__);

            size = gSkyboxFiles[sp40].file.vromEnd - gSkyboxFiles[sp40].file.vromStart;
            skyboxCtx->staticSegments[1] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[1] != NULL, "skyboxCtx->staticSegments[1] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[1], gSkyboxFiles[sp40].file.vromStart, size, "../z_vr_box.c",
                                __LINE__);

            if ((sp41 & 1) ^ ((sp41 & 4) >> 2)) {
                size = gSkyboxFiles[sp41].palette.vromEnd - gSkyboxFiles[sp41].palette.vromStart;

                skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", __LINE__);

                ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

                DmaMgr_SendRequest1(skyboxCtx->palettes, gSkyboxFiles[sp41].palette.vromStart, size, "../z_vr_box.c",
                                    __LINE__);
                DmaMgr_SendRequest1((u32)skyboxCtx->palettes + size, gSkyboxFiles[sp40].palette.vromStart, size,
                                    "../z_vr_box.c", __LINE__);
            } else {
                size = gSkyboxFiles[sp41].palette.vromEnd - gSkyboxFiles[sp41].palette.vromStart;

                skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", __LINE__);

                ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

                DmaMgr_SendRequest1(skyboxCtx->palettes, gSkyboxFiles[sp40].palette.vromStart, size, "../z_vr_box.c",
                                    __LINE__);
                DmaMgr_SendRequest1((u32)skyboxCtx->palettes + size, gSkyboxFiles[sp41].palette.vromStart, size,
                                    "../z_vr_box.c", __LINE__);
            }
            break;

        case SKYBOX_BAZAAR:
            skyboxCtx->unk_140 = 1;

            start = _vr_SP1a_staticSegmentRomStart;
            size = _vr_SP1a_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_SP1a_pal_staticSegmentRomStart;
            size = _vr_SP1a_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_OVERCAST_SUNSET:
            start = _vr_cloud2_staticSegmentRomStart;
            size = _vr_cloud2_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            skyboxCtx->staticSegments[1] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[1] != NULL, "skyboxCtx->staticSegments[1] != NULL", "../z_vr_box.c", 1163);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[1], start, size, "../z_vr_box.c", 1166);

            start = _vr_cloud2_pal_staticSegmentRomStart;
            size = _vr_cloud2_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1173);
            DmaMgr_SendRequest1((u32)skyboxCtx->palettes + size, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_MARKET_ADULT:
            skyboxCtx->unk_140 = 1;

            start = _vr_RUVR_staticSegmentRomStart;
            size = _vr_RUVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_RUVR_pal_staticSegmentRomStart;
            size = _vr_RUVR_pal_staticSegmentRomEnd - start;
            osSyncPrintf("SIZE = %d\n", size);

            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_CUTSCENE_MAP:
            start = _vr_holy0_staticSegmentRomStart;
            size = _vr_holy0_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_holy1_staticSegmentRomStart;
            size = _vr_holy1_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[1] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[1] != NULL, "skyboxCtx->staticSegments[1] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[1], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_holy0_pal_staticSegmentRomStart;
            size = _vr_holy0_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size * 2, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            DmaMgr_SendRequest1((u32)skyboxCtx->palettes + size, _vr_holy1_pal_staticSegmentRomStart, size,
                                "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HOUSE_LINK:
            skyboxCtx->unk_140 = 1;

            start = _vr_LHVR_staticSegmentRomStart;
            size = _vr_LHVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_LHVR_pal_staticSegmentRomStart;
            size = _vr_LHVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_MARKET_CHILD_DAY:
            skyboxCtx->unk_140 = 1;

            start = _vr_MDVR_staticSegmentRomStart;
            size = _vr_MDVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_MDVR_pal_staticSegmentRomStart;
            size = _vr_MDVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_MARKET_CHILD_NIGHT:
            skyboxCtx->unk_140 = 1;

            start = _vr_MNVR_staticSegmentRomStart;
            size = _vr_MNVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_MNVR_pal_staticSegmentRomStart;
            size = _vr_MNVR_pal_staticSegmentRomEnd - start;
            osSyncPrintf("SIZE = %d\n", size);

            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HAPPY_MASK_SHOP:
            skyboxCtx->unk_140 = 1;

            start = _vr_FCVR_staticSegmentRomStart;
            size = _vr_FCVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c", 1287);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_FCVR_pal_staticSegmentRomStart;
            size = _vr_FCVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_HOUSE_KNOW_IT_ALL_BROTHERS:
            skyboxCtx->unk_140 = 1;

            start = _vr_KHVR_staticSegmentRomStart;
            size = _vr_KHVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_KHVR_pal_staticSegmentRomStart;
            size = _vr_KHVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HOUSE_OF_TWINS:
            skyboxCtx->unk_140 = 2;

            start = _vr_K3VR_staticSegmentRomStart;
            size = _vr_K3VR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_K3VR_pal_staticSegmentRomStart;
            size = _vr_K3VR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_STABLES:
            skyboxCtx->unk_140 = 1;

            start = _vr_MLVR_staticSegmentRomStart;
            size = _vr_MLVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_MLVR_pal_staticSegmentRomStart;
            size = _vr_MLVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", 1352);
            break;
        case SKYBOX_HOUSE_KAKARIKO:
            skyboxCtx->unk_140 = 1;

            start = _vr_KKRVR_staticSegmentRomStart;
            size = _vr_KKRVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_KKRVR_pal_staticSegmentRomStart;
            size = _vr_KKRVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_KOKIRI_SHOP:
            skyboxCtx->unk_140 = 1;

            start = _vr_KSVR_staticSegmentRomStart;
            size = _vr_KSVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_KSVR_pal_staticSegmentRomStart;
            size = _vr_KSVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_GORON_SHOP:
            skyboxCtx->unk_140 = 1;

            start = _vr_GLVR_staticSegmentRomStart;
            size = _vr_GLVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_GLVR_pal_staticSegmentRomStart;
            size = _vr_GLVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_ZORA_SHOP:
            skyboxCtx->unk_140 = 1;

            start = _vr_ZRVR_staticSegmentRomStart;
            size = _vr_ZRVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_ZRVR_pal_staticSegmentRomStart;
            size = _vr_ZRVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_POTION_SHOP_KAKARIKO:
            skyboxCtx->unk_140 = 1;

            start = _vr_DGVR_staticSegmentRomStart;
            size = _vr_DGVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_DGVR_pal_staticSegmentRomStart;
            size = _vr_DGVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_POTION_SHOP_MARKET:
            skyboxCtx->unk_140 = 1;

            start = _vr_ALVR_staticSegmentRomStart;
            size = _vr_ALVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_ALVR_pal_staticSegmentRomStart;
            size = _vr_ALVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_BOMBCHU_SHOP:
            skyboxCtx->unk_140 = 1;

            start = _vr_NSVR_staticSegmentRomStart;
            size = _vr_NSVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_NSVR_pal_staticSegmentRomStart;
            size = _vr_NSVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            skyboxCtx->rot.y = 0.8f;
            break;
        case SKYBOX_HOUSE_RICHARD:
            skyboxCtx->unk_140 = 1;

            start = _vr_IPVR_staticSegmentRomStart;
            size = _vr_IPVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_IPVR_pal_staticSegmentRomStart;
            size = _vr_IPVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HOUSE_IMPA:
            skyboxCtx->unk_140 = 1;

            start = _vr_LBVR_staticSegmentRomStart;
            size = _vr_LBVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_LBVR_pal_staticSegmentRomStart;
            size = _vr_LBVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_TENT:
            skyboxCtx->unk_140 = 2;

            start = _vr_TTVR_staticSegmentRomStart;
            size = _vr_TTVR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_TTVR_pal_staticSegmentRomStart;
            size = _vr_TTVR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HOUSE_MIDO:
            skyboxCtx->unk_140 = 2;

            start = _vr_K4VR_staticSegmentRomStart;
            size = _vr_K4VR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_K4VR_pal_staticSegmentRomStart;
            size = _vr_K4VR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HOUSE_SARIA:
            skyboxCtx->unk_140 = 2;

            start = _vr_K5VR_staticSegmentRomStart;
            size = _vr_K5VR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_K5VR_pal_staticSegmentRomStart;
            size = _vr_K5VR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_HOUSE_ALLEY:
            skyboxCtx->unk_140 = 2;

            start = _vr_KR3VR_staticSegmentRomStart;
            size = _vr_KR3VR_staticSegmentRomEnd - start;
            skyboxCtx->staticSegments[0] = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->staticSegments[0] != NULL, "skyboxCtx->staticSegments[0] != NULL", "../z_vr_box.c",
                   __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->staticSegments[0], start, size, "../z_vr_box.c", __LINE__);

            start = _vr_KR3VR_pal_staticSegmentRomStart;
            size = _vr_KR3VR_pal_staticSegmentRomEnd - start;
            skyboxCtx->palettes = GameState_Alloc(&globalCtx->state, size, "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->palettes != NULL, "skyboxCtx->palettes != NULL", "../z_vr_box.c", __LINE__);

            DmaMgr_SendRequest1(skyboxCtx->palettes, start, size, "../z_vr_box.c", __LINE__);
            break;
        case SKYBOX_UNSET_27:
            break;
    }
}

void Skybox_Init(GameState* state, SkyboxContext* skyboxCtx, s16 skyboxId) {
    GlobalContext* globalCtx = (GlobalContext*)state;

    skyboxCtx->unk_140 = 0;
    skyboxCtx->rot.x = skyboxCtx->rot.y = skyboxCtx->rot.z = 0.0f;

    Skybox_Setup(globalCtx, skyboxCtx, skyboxId);
    osSyncPrintf("\n\n\n＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n\n"
                 "SKYBOX ID = %d"
                 "\n\n\n＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n\n",
                 skyboxId);

    if (skyboxId != SKYBOX_NONE) {
        osSyncPrintf(VT_FGCOL(GREEN));

        if (skyboxCtx->unk_140 != 0) {
            skyboxCtx->dListBuf = GameState_Alloc(state, 8 * 150 * sizeof(Gfx), "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->dListBuf != NULL, "skyboxCtx->dListBuf != NULL", "../z_vr_box.c", __LINE__);

            skyboxCtx->roomVtx = GameState_Alloc(state, 256 * sizeof(Vtx), "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->roomVtx != NULL, "skyboxCtx->roomVtx != NULL", "../z_vr_box.c", __LINE__);

            func_800AEFC8(skyboxCtx, skyboxId);
        } else {
            skyboxCtx->dListBuf = GameState_Alloc(state, 12 * 150 * sizeof(Gfx), "../z_vr_box.c", __LINE__);
            ASSERT(skyboxCtx->dListBuf != NULL, "skyboxCtx->dListBuf != NULL", "../z_vr_box.c", __LINE__);

            if (skyboxId == SKYBOX_CUTSCENE_MAP) {
                skyboxCtx->roomVtx = GameState_Alloc(state, 192 * sizeof(Vtx), "../z_vr_box.c", __LINE__);
                ASSERT(skyboxCtx->roomVtx != NULL, "skyboxCtx->roomVtx != NULL", "../z_vr_box.c", __LINE__);

                func_800AF178(skyboxCtx, 6);
            } else {
                skyboxCtx->roomVtx = GameState_Alloc(state, 160 * sizeof(Vtx), "../z_vr_box.c", __LINE__);
                ASSERT(skyboxCtx->roomVtx != NULL, "skyboxCtx->roomVtx != NULL", "../z_vr_box.c", __LINE__);

                func_800AF178(skyboxCtx, 5);
            }
        }
        osSyncPrintf(VT_RST);
    }
}
