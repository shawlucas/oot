#include <ultra64.h>
#include <global.h>

//#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3840.s")
extern char D_80143100[];
extern s32 D_8012CED4;
extern char D_8014311C[];
extern s32 D_8012CED8;
extern char D_8014313C[];
extern s32 D_8012CED0;
extern char D_80143154[];
void func_800B3840(s32 arg0)
{
    if ((HREG(80)== 0x13) && ((HREG(81) == 1)))
    {
        // "shrink_window_setval(%d)\n"
        osSyncPrintf(D_80143100, arg0);
    }
    D_8012CED4 = arg0;
}

s32 func_800B3898(void)
{
    return D_8012CED4;
}

void func_800B38A4(s32 arg0)
{
    if ((HREG(80) == 0x13) && (HREG(81) == 1))
    {
        // "shrink_window_setnowval(%d)\n"
        osSyncPrintf(D_8014311C, arg0);
    }

    D_8012CED8 = arg0;
}

s32 func_800B38FC(void)
{
    return D_8012CED8;
}

void func_800B3908(void)
{
    if ((HREG(80) == 0x13) && (HREG(81) == 1))
    {
        // "shrink_window_init()\n"
        osSyncPrintf(D_8014313C);
    }
    D_8012CED0 = 0;
    D_8012CED4 = 0;
    D_8012CED8 = 0;
}

void func_800B3968(void)
{
    if ((HREG(80) == 0x13) && (HREG(81) == 1))
    {
        // "shrink_window_cleanup()\n"
        osSyncPrintf(D_80143154);
    }
    D_8012CED8 = 0;
}

void func_800B39B8(s32 arg0) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 phi_v0;

    if (arg0 == 3) {
        phi_v0 = 0xA;
    } else {
        phi_v0 = (0x1E / arg0);
    }
    if (D_8012CED8 < D_8012CED4) {
        if (D_8012CED0 != 1) {
            D_8012CED0 = 1;
        }
        temp_a1 = D_8012CED8 + phi_v0;
        if (temp_a1 < D_8012CED4) {
            D_8012CED8 = temp_a1;
        } else {
            D_8012CED8 = D_8012CED4;
        }
    } else {
        if (D_8012CED4 < D_8012CED8) {
            if (D_8012CED0 != 2) {
                D_8012CED0 = 2;
            }
            temp_a1_2 = D_8012CED8 - phi_v0;
            if (D_8012CED4 < temp_a1_2) {
                D_8012CED8 = temp_a1_2;
            } else {
                D_8012CED8 = D_8012CED4;
            }
        } else {
            D_8012CED0 = 0;
        }
    }
    if (HREG(80) == 0x13) {
        if (HREG(94) != 0x13) {
            HREG(94) = 0x13;
            HREG(81) = 0;
            HREG(82) = 0;
            HREG(83) = 0;
            HREG(84) = 0;
            HREG(85) = 0;
            HREG(86) = 0;
            HREG(87) = 0;
            HREG(88) = 0;
            HREG(89) = 0;
        }
        HREG(83) = D_8012CED0;
        HREG(84) = D_8012CED8;
        HREG(85) = D_8012CED4;
        HREG(86) = phi_v0;
    }
}


#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3B50.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3BD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3DF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3EBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3EFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3F38.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3F54.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3F94.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B3FF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B404C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4088.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B41DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B42C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4370.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B44E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4920.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4A68.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4AA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4AE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4B20.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4D58.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4DE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B4E7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B8730.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B87D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B8978.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B8A0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B8BA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B8F58.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B9060.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B91B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B958C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/db_camera/func_800B9638.s")
