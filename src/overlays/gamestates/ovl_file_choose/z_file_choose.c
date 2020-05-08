#include <ultra64.h>
#include <global.h>

typedef struct
{
    /* 0x0000 */ GameState state;
    /* 0x00A4 */ Gfx* gfx_A4;
    /* 0x00A8 */ void* title_staticSegment;
    /* 0x00AC */ void* parameter_staticSegment;
    /* 0x00B0 */ SCmdAltHeaders* sceneHeader;
    /* 0x00B4 */ char unk_B4[0x4]; // view->viewport.bottomY from previous context
    /* 0x00B8 */ View view;
    /* 0x01E0 */ Sram* sram;
    /* 0x01E4 */ Camera camera_1E4;
    /* 0x0350 */ Camera camer_350;
} FileContext; // size = 0x1CAE0

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80803D40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80803ED8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804248.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808043D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808044A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804858.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804924.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804A50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804C74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804CD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80804ED8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080510C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808051C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805318.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805434.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805524.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805824.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080595C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805B2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80805EB8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806180.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080625C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806444.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808064F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806710.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808068F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808069B4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806C20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806DB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80806F34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080723C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80807DCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80808000.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80808F84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80809038.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080960C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080969C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808099C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080AF30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080AF50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080AFD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080B1A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080B22C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080B394.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080B40C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080B494.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080B52C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080BE30.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080BE84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080BEF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080BF6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080BFE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080C2F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080C330.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080C60C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080D8CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080E074.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080F560.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080FE2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8080FF98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8081009C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8081017C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80810354.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80810440.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80810698.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808106F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_8081097C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808109B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80810DAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_808113A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80811A18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/gamestates/ovl_file_choose/func_80811A20.s")
