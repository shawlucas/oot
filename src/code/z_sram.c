#include <ultra64.h>
#include <global.h>

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A81A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A82C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A8484.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A88D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A8A20.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9258.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A96D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A97F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9A9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9AD0.s")
typedef struct {
    /* 0x0000 */ u8 audio_settings;
    /* 0x0001 */ u8 language;
    /* 0x0002 */ char zeldaString[0x0009]; // "\x98\x09\x10\x21ZELDA"
    /* 0x000C */ char pad[0x5];
} SaveHeader; // size = 0x11

typedef struct {

    /* 0x0000 */ u16 fileOffsets[16];
    /* 0x000C */ SaveHeader defaultData;
    /* 0x0018 ?? */
} DefaultFileCreation;

/*
extern char D_80140E98[];
void func_800A9AD0(GameState* state, Sram* sram) {
    u32 temp_s0;
    u32 temp_s0_2;
    u32 phi_v0;
    void *phi_v1;
    u32 phi_s0;
    void *phi_v1_2;
    s8 phi_s0_2;

    osSyncPrintf(D_80140E98);
    Sram_ReadWrite(0x8000000, sram->read_buff, 0x8000, OS_READ);
    phi_v0 = 0U;
    phi_v1 = *arg1;
    phi_s0 = 0U;
loop_1:
    phi_v1_2 = phi_v1;
    if ((&D_8012A4EC + phi_v0)->unk3 != (phi_v1 + phi_v0)->unk3) {
        osSyncPrintf(&D_80140EC4);
        gSaveContext.unk1409 = (u8) (*arg1)->unk2;
        MemCopy(*arg1, &D_8012A4EC, 0xC);
        (*arg1)->unk2 = (u8) gSaveContext.unk1409;
        func_800A9A9C(arg1);
        phi_v1_2 = *arg1;
    }
    temp_s0 = (phi_s0 + 1) & 0xFFFF;
    phi_v0 = temp_s0;
    phi_v1 = phi_v1_2;
    phi_s0 = temp_s0;
    if (temp_s0 < 9U) {
        goto loop_1;
    }
    gSaveContext.unk140A = (u8) (*phi_v1_2 & 3);
    gSaveContext.unk140C = (s8) ((*arg1)->unk1 & 1);
    gSaveContext.unk1409 = (u8) (*arg1)->unk2;
    if (((*arg1)->unk2 & 0xFF) >= 3) {
        gSaveContext.unk1409 = (u8)0U;
        (*arg1)->unk2 = (u8)0;
        func_800A9A9C(arg1);
    }
    if ((arg0->unk44 & 0x100) != 0) {
        bzero(*arg1, 0x8000);
        phi_s0_2 = (u8)0;
loop_8:
        *(*arg1 + phi_s0_2) = (s8) phi_s0_2;
        temp_s0_2 = (phi_s0_2 + 1) & 0xFFFF;
        phi_s0_2 = temp_s0_2;
        if (temp_s0_2 < 0x9AAU) {
            goto loop_8;
        }
        Sram_ReadWrite(0x8000000, *arg1, 0x8000, 1);
        osSyncPrintf(&D_80140EE0);
    }
    osSyncPrintf(&D_80140EFC, 0x1338, 4, 0x133C);
    osSyncPrintf(&D_80140F28);
    osSyncPrintf(&D_80140F30, gSaveContext.unk140A);
    osSyncPrintf(&D_80140F4C, gSaveContext.unk140A);
    osSyncPrintf(&D_80140F68, gSaveContext.unk140A);
    osSyncPrintf(&D_80140F84);
    func_800F6700((s8) gSaveContext.unk140A);
}
*/
extern char D_80140F88[];
extern char D_80140F94[];
extern char D_80140FAC[];
void func_800A9CD4(GameState* state, Sram* sram)
{
    sram->read_buff = Game_Alloc(state, 0x8000, D_80140F88, 1294);
    if (sram->read_buff == NULL)
    {
        __assert(D_80140F94, D_80140FAC, 1295);
    }
}
//#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9D28.s")
void func_800A9D28(GameState* state, UNK_TYPE arg1)
{

}