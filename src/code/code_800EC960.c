#include <ultra64.h>
#include <global.h>

extern s32 D_80130EFC;
extern s32 D_80130F00;
extern s32 D_80130F04;
extern s32 D_80130F08;

void func_800EC960(u8 arg0) {
    if (!arg0) {
        osSyncPrintf("AUDIO : Ocarina Control Assign Normal\n");
        D_80130EFC = 0x800F;
        D_80130F00 = 0x8000;
        D_80130F04 = 8;
        D_80130F08 = 4;
    } else {
        osSyncPrintf("AUDIO : Ocarina Control Assign Custom\n");
        D_80130EFC = 0xC007;
        D_80130F00 = 0x4000;
        D_80130F04 = 4;
        D_80130F08 = 0x8000;
    }
}

extern s8 D_8016BA08;
extern s8 D_8016BA09;
extern s32 D_8016BA0C;
extern s32 D_8016BA14;

void PadMgr_RequestPadData(PadMgr* padmgr, Input* inputs, s32 mode);
//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ECA00.s")
// need to know more about D_8016BA08
void func_800ECA00(void) {
    Input sp20[4];
    s32 pad;
    s32 sp18;

    sp18 = D_8016BA0C;
    PadMgr_RequestPadData(&gPadMgr, &sp20, 0);
    D_8016BA0C = sp20[0].cur.in.button;
    D_8016BA14 = sp18;
    D_8016BA08 = sp20[0].rel.in.x;
    D_8016BA09 = sp20[0].rel.in.y;
}

// stick float vals
extern f32 D_8012F6B4[];
// adju stick input f32
f32 func_800ECA60(s8 inp) {
    s8 inpAdj;
    f32 ret;

    if (inp > 0x40) {
        inpAdj = 127;
    } else if (inp < -0x40) {
        inpAdj = -128;
    } else if (inp >= 0) {
        inpAdj = (inp * 127) / 64;
    } else {
        inpAdj = (inp * 128) / 64;
    }
    ret = D_8012F6B4[inpAdj];
    return ret;
}

extern u8 D_80131878;
extern s32 D_80130F3C;

s32 func_800ECAF0(void) {
    u8 ret;

    if (D_80131878 != 0) {
        ret = D_80131878 - 1;
        D_80131878 = 0;
    } else if (D_80130F3C != 0) {
        ret = 0xFE;
    } else {
        ret = 0xFF;
    }

    return ret;
}
extern u8 D_80131BF0[];
u8 func_800ECB34(u8 arg0) {
    u8 temp_v1;

    temp_v1 = D_80131BF0[arg0 & 0x3F];
    if (temp_v1 == 5) {
        if (arg0 & 0x80) {
            return 2;
        }
        return 3;
    }
    return temp_v1;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ECB7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ECC04.s")

extern u8 D_80130F14;
extern u8 D_8016BA29;
extern u8 D_80130F20;

void func_800ECDBC(void) {
    if (D_80130F14 != 0xFF) {
        if (D_8016BA29 == 0) {
            D_8016BA29 = 1;
            D_80130F20 = 0xFF;
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ECDF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ED200.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ED458.s")

extern u8 D_80130F0C;
void func_800ED848(u8 arg0) {
    D_80130F0C = arg0;
}

extern s32 D_8016BA10;
extern s32 D_8016BA18;
extern u8 D_80130F38;
extern u16 D_80130F48;
extern s8 D_80130F10;

void func_800ED858(u8 arg0) {
    if (D_80130F10 != arg0) {
        Audio_SetBGM(arg0 | 0x82010D00);
        D_80130F10 = arg0;
        if (arg0 == 0) {
            D_8016BA0C = 0;
            D_8016BA14 = 0;
            D_8016BA18 = 0;
            D_8016BA10 = 0xFFFF;
            func_800ED458(0);
            func_800F8D04(0x5800);
            func_800F7260(0);
            D_80130F38 = 0;
            D_80130F48 = 0;
            D_80130F0C = 0;
            D_80130F3C = 0;
            func_800F731C(0xD);
            return;
        }
        D_8016BA0C = 0;
        func_800ECA00();
        D_8016BA10 = D_8016BA0C;
        func_800F72B8(0xD);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800ED93C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EDA3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EDD68.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE170.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE29C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE2D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE318.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE3C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE3D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE3F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE404.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE57C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE5EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE6F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE824.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE930.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE97C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EE9D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800EEA50.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F1BDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2150.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F227C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2464.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F27A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F28AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F28B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F29FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2A04.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2D6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F2E28.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3054.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3138.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3140.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F314C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3188.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F32F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3468.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F35EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F37B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3990.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3A08.s")

typedef struct {
    f32 unk_00;
    f32 unk_04;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
} unk_D_8016B8B8;

extern unk_D_8016B8B8 D_8016B8B8[];
extern u8 D_80130618;
extern u8 D_8013061C;
extern f32 D_8016B7A8;
extern f32 D_8016B7B0;
extern u8 D_8013063C;
extern u8 D_80130640;
extern u8 D_80130644;
extern u8 D_80130648;
typedef struct {
    f32 unk_00;
    char unk_04[8];
    s32 unk_0C;
} unk_D_8016B7C8;
extern unk_D_8016B7C8 D_8016B7C8;
extern unk_D_8016B7C8 D_8016B7B8;
extern s8 D_801306C8[];
extern u8 D_80133414;
extern u8 D_80130610;
extern u8 D_8016B9D8;
extern u8 D_8016B8B4;
extern f32 D_8016B7D8;
extern u8 D_8016B9F3;
extern u8 D_8016B9F2;

void func_800F3ED4(void) {
    u8 i;
    unk_D_8016B8B8* t;

    for(i = 0; i < 16; i++){
        t = &D_8016B8B8[i];
        t->unk_00 = 1.0f;
        t->unk_04 = 1.0f;
        t->unk_08 = 0;
        t->unk_09 = 0x40;
        t->unk_0A = 0;
        t->unk_0B = 0xFF;
        t->unk_0C = 0xFF;
    }

    D_8016B8B8[0xD].unk_0C = 0;
    D_8013061C = 0;
    D_80130618 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3F3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F3F84.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4010.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4138.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4190.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F41E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4254.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F436C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4414.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F44EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4524.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4578.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F45D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4634.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F46E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4784.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F47BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F47FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F483C.s")

void func_800E5B20(s32,s8);
//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4870.s")
extern u8 D_80130600;
extern u8 D_801305F8[];
void func_800F4870(u8 arg0) {
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0;
    u8 phi_s0;
    s8 phi_s1;

    phi_s1 = 0;
    if(arg0 == 0){
        phi_s1 = 0x7F;
    }
    phi_s0 = 0;
    while(phi_s0 < 16){
        func_800E5B20(0x7000000 | ((phi_s0 & 0xFF) << 8), phi_s1);
        phi_s0++;
    }

    if (arg0 == 7) {
        D_80130600 = 2;
    } else {
        func_800F491C(D_801305F8[arg0 & 7]);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F491C.s")

extern u8 D_8016B8B0;
extern u8 D_8016B8B1;
extern u8 D_8016B8B2;
extern u8 D_8016B8B3;
extern s8 D_80130608;
extern u8 D_801305FF;

void func_800F4A54(u8 arg0) {
    D_8016B8B0 = arg0;
    D_8016B8B2 = 1;
}

void func_800F4A70(void) {
    if (D_8016B8B2 == 1) {
        if (D_8016B8B1 != D_8016B8B0) {
            func_800FA240(0, 0, D_8016B8B0, 0xA);
            D_8016B8B1 = D_8016B8B0;
            D_8016B8B3 = 1;
        }
        D_8016B8B2 = 0;
    } else if (D_8016B8B3 == 1 && D_80130608 == 0) {
        func_800FA240(0, 0, 0x7F, 0xA);
        D_8016B8B1 = 0x7F;
        D_8016B8B3 = 0;
    }
    
    if(D_80130600 != 0)
    {
        D_80130600--;
        if(D_80130600 == 0){
            func_800F491C(D_801305FF);
        }
    }
}
extern u8 D_801305CC;
void func_800F4B58(Vec3f *arg0, u16 arg1, u8* arg2) {
    Audio_PlaySoundGeneral(arg1, arg0, 4, &gNoteFrequencies[arg2[D_801305CC] + 39], &D_801333E0, &D_801333E8);
    
    if (D_801305CC < 15) {
        D_801305CC++;
    }
}

void func_800F4BE8(void) {
    D_801305CC = 0;
}

void func_800F4BF4(Vec3f *arg0, u16 arg1, s8 arg2) {
    Audio_PlaySoundGeneral(arg1, arg0, 4, &gNoteFrequencies[arg2 + 39], &D_801333E0, &D_801333E8);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4C58.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F4E30.s")

extern s32 D_8013064C;
void func_800F50CC(void) {
    if (D_8013064C != 0) {
        D_8013064C = 0;
    }
}

void *func_800F50EC(s32 arg0) {
    if (D_8013064C == arg0) {
        D_8013064C = 0;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F510C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F52A0.s")

void func_800F5504(void) {
    D_8013064C = 0;
}
void func_800F5550(u16);
void func_800F5E18(u8 arg0, u16 arg1, u8 arg2, s8 arg3, s8 arg4);
void func_800F5510(u16 arg0) {
    func_800F5550(arg0);
    func_800F5E18(0, arg0, 0, 0, 1);
}

extern u8 D_8013062C;
extern u8 D_80130630;
extern u8 D_80130658[];
//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F5550.s")
void func_800F5550(u16 arg0) {
    u8 sp27;
    s32 sp20;
    s32 temp_v1;
    s32 temp_v1_2;
    u8 temp_v0;
    u8 phi_v0;
    s8 phi_v1;

    sp27 = 0;
    if (func_800FA0B4(0) != 0x4C) {
        if (func_800FA0B4(3) == 0x2F) {
            func_800F9474(3, 0);
            func_800E5AFC(0xF8000000, 0);
        }
        if ((D_80130658[D_80130630] & 0x20) && (D_80130658[arg0] & 0x10)) {

            if ((D_8013062C & 0x3F) != 0) {
                sp27 = 0x1E;
            }
            func_800F5E18(0, arg0, sp27, 7, arg0);
            D_8013062C = 0;
        } else {
            func_800F5E18(0, arg0, 0, 7, D_80130658[arg0] & 0x40 ? 1 : 0xFF);
            if (!(D_80130658[arg0] & 0x20)) {
                D_8013062C = 0xC0;
            }
        }
        D_80130630 = arg0;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F56A8.s")

void func_800F5718(void) {
    if (func_800FA0B4(0) != 0x4C) {
        Audio_SetBGM(0x4C);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F574C.s")

void func_800F5918(void) {
    if (func_800FA0B4(0) == 0x6C) {
        if (func_800FA11C(0, 0xF0000000) != 0) {
            Audio_SetBGM(0xB00500D2);
        }
    }
}

//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F595C.s")
void func_800F595C(u16 arg0) {
    if (D_80130658[(u8)arg0] & 2) {
        func_800F5C64(arg0);
    } else if (D_80130658[(u8)arg0] & 4) {
        Audio_SetBGM(0x1000000 | arg0);
        
    } else {
        func_800F5E18(0, arg0, 0, 7, -1);
        Audio_SetBGM(0x110000FF);
    }
}

//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F59E8.s")
void func_800F59E8(u16 arg0x) {
    u8 arg0 = arg0x;
    if (D_80130658[arg0] & 2) {
        Audio_SetBGM(0x110000FF);
    } else if (D_80130658[arg0] & 4) {
        Audio_SetBGM(0x110000FF);
    } else {
        Audio_SetBGM(0x100000FF);
    }
}

//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F5A58.s")
s32 func_800F5A58(u8 arg0) {
    s32 sp18;
    s32 temp_v1;
    u8 temp_v0;
    u8 phi_a1;
    u8 phi_return;

    phi_a1 = !(D_80130658[arg0] & 2) || D_80130658[arg0] & 4 ? 1 : 0;

    phi_return = 0;
    if (func_800FA0B4(phi_a1) == arg0) {
        phi_return = 1;
    }
    
    return phi_return;
}

extern u16 D_80130628;
//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F5ACC.s")
void func_800F5ACC(u16 arg0) {
    u8 temp_a0;
    u16 temp_v0;

    temp_a0 = temp_v0 = func_800FA0B4(0);
    if (temp_a0 != 0x2E && temp_a0 != 0x62 && arg0 != temp_v0) {
        func_800F5E90(3);
        if (temp_v0 != 0xFFFF) {
            D_80130628 = temp_v0;
        } else {
            osSyncPrintf("Middle Boss BGM Start not stack \n");
        }
        Audio_SetBGM(arg0 & 0xFFFFFFFF);
    }
}

void func_800F5B58(void) {
    if (func_800FA0B4(0) != 0xFFFF) {
        if (D_80130628 != 0xFFFF) {
            if (D_80130658[func_800FA0B4(0) & 0xFF] & 8) {
                if (D_80130628 == 0xFFFF) {
                    Audio_SetBGM(0x100000FF);
                } else {
                    Audio_SetBGM(D_80130628 & 0xFFFFFFFF);
                }
                D_80130628 = 0xFFFF;
            }
        }
    }
}

void func_800F5BF0(u8 arg0) {
    u16 temp_v0;

    temp_v0 = func_800FA0B4(0);
    if (temp_v0 != 1) {
        D_80130628 = temp_v0;
    }
    func_800F6FB4(arg0);
}

void func_800F5C2C(void) {
    if (D_80130628 != 0xFFFF) {
        u32 t = D_80130628;
        Audio_SetBGM(t);
    }
    D_80130628 = 0xFFFF;
}

extern u8 D_8016B9F4;
extern u16 D_8016B9F6;
u8 *func_800E5E84(s32 arg0, u8 *arg1);
void func_800F5C64(u16 arg0) {
    u16 sp26;
    s32 sp20;
    u8 *sp1C;
    u8 *sp18;

    sp26 = func_800FA0B4(1);
    sp1C = func_800E5E84(sp26 & 0xFF, &sp20);
    sp18 = func_800E5E84(arg0 & 0xFF, &sp20);
    if ((sp26 == 0xFFFF) || (*sp1C == *sp18)) {
        D_8016B9F4 = 1;
    } else {
        D_8016B9F4 = 5;
        Audio_SetBGM(0x110000FF);
    }
    D_8016B9F6 = arg0;
}

//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F5CF8.s")
void func_800F5CF8(void) {
    u16 sp26;
    u16 sp24;
    u16 sp22;
    s32 sp1C;

    if (D_8016B9F4 != 0) {
        D_8016B9F4--;
        if (D_8016B9F4 == 0) {
            func_800E5AFC(0xE3000000U, 0U);
            func_800E5AFC(0xE3000000U, 1U);
            func_800FA0B4(0);
            sp26 = func_800FA0B4(1);
            sp22 = func_800FA0B4(3);
            if (sp26 == 0xFFFF) {
                func_800FA240(0, 1, 0, 5);
                func_800FA240(3, 1, 0, 5);
                Audio_SetBGM(0xC180010AU);
                Audio_SetBGM(0xC183010AU);
                Audio_SetBGM(0xC1900000U);
                if (sp22 != 0x2F) {
                    Audio_SetBGM(0xC1930000U);
                }
            }
            Audio_SetBGM(D_8016B9F6 | 0x1010000);
            Audio_SetBGM(0xA000FFFF);
            if (sp22 != 0x2F) {
                Audio_SetBGM(0xA300FFFF);
            }
        }
    }
}

void func_800F5E18(u8 arg0, u16 arg1, u8 arg2, s8 arg3, s8 arg4) {
    Audio_SetBGM(0x70000000 | (arg0 << 0x18) | ((arg3 & 0xFF) << 0x10) | (u8)arg4);
    Audio_SetBGM((arg0 << 0x18) | (arg2 << 0x10) | arg1);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F5E90.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6114.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6268.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F64E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6584.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F66C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F66DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6700.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F67A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6828.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F68BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F68D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F691C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6964.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6AB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6B3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6B68.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6BB8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6BDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6C14.s")

// probably some kind of init ?
void func_800F6C34(void) {
    D_8013061C = 0;
    D_8016B7A8 = 1.0f;
    D_8016B7B0 = 1.0f;
    D_8013063C = 0;
    D_80130640 = 0;
    D_80130644 = 0;
    D_80130648 = 0;
    func_800ED858(0);
    D_8016B7B8.unk_0C = 0;
    D_8016B7C8.unk_0C = 0;
    D_8016B7B8.unk_00 = 1.0f;
    D_8016B7C8.unk_00 = 1.0f;
    D_8016B7D8 = 1.0f;
    D_8016B8B0 = 0x7F;
    D_8016B8B1 = 0x7F;
    D_8016B8B2 = 0;
    D_8016B8B3 = 0;
    D_8016B8B4 = 0xFF;
    D_8016B9D8 = 0;
    D_80130610 = D_801306C8[D_80133414];
    D_80130608 = 0;
    D_80130628 = 0xFFFF;
    func_800E5B20(0x46000000, -1);
    D_8013064C = 0;
    D_8016B9F4 = 0;
    D_8016B9F3 = 1;
    D_8016B9F2 = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6D58.s")

extern u8 D_80133408;
//#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6E7C.s")
void func_800F6E7C(u16 arg0, u16 arg1) {
    u8 phi_s0;
    u8 t;
    u8 i;

    if (func_800FA0B4(0) == 0x4C) {
        func_800F3F3C(0xF);
        return;
    }

    Audio_SetBGM(0x70000001);
    Audio_SetBGM(0x70040000 | ((arg0 >> 8) & 0xFF));
    t = arg0 & 0x00FF;
    Audio_SetBGM(0x70050000 | t);
    func_800FA240(0, 0, 0x7F, 1);

    i = 0;
    if (D_80133408 != 0) {
        Audio_SetBGM(0xE0000100);
        i = 1;
    }

    Audio_SetBGM(1);
    
    if (i != 0) {
        Audio_SetBGM(0xE0000101);
    }

    for(i = 0; i < 16; i++){
        if(!(arg1 & (1 << i)) && (arg0 & (1 << i))){
            Audio_SetBGM((i << 8) | 0x80010000 | 1);
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_800EC960/func_800F6FB4.s")

void func_800F70F8(void) {
    func_800E3094(0, 0);
}

void func_800F711C(void) {
    func_800F6C34();
    func_800EE930();
    func_800F3ED4();
    func_800FAEB4();
    func_800F905C();
    func_800F9280(2, 0, 0x70, 0xA);
}

void func_800F7170(void) {
    func_800F9280(2, 0, 0x70, 1);
    func_800E5AFC(0xF2000000, 1);
    func_800E5B80();
    func_800E5AFC(0xF8000000, 0);
}

extern u8 D_80133418;
void func_800F71BC(s32 arg0) {
    D_80133418 = 1;
    func_800F6C34();
    func_800EE930();
    func_800F3ED4();
    func_800FADF8();
    func_800F905C();
}

void func_800F7208(void) {
    func_800FADF8();
    func_800E5AFC(0xF2000000U, 1);
    func_800F6C34();
    func_800F3ED4();
    func_800F9280(2, 0, 0x70, 1);
}
