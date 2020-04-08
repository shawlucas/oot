/*
 * File: z_bg_dy_yoseizo.c
 * Overlay: ovl_Bg_Dy_Yoseizo
 * Description: Great Fairy
 */

#include "z_bg_dy_yoseizo.h"

#define ROOM 0x00
#define FLAGS 0x02000030

void BgDyYoseizo_Init(BgDyYoseizo* this, GlobalContext* globalCtx);
void BgDyYoseizo_Destroy(BgDyYoseizo* this, GlobalContext* globalCtx);
void BgDyYoseizo_Update(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80872960(BgDyYoseizo* this, GlobalContext* globalCtx, s16 arg2);
void func_80872C58(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80872D20(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80872DE4(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_8087328C(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873380(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808734DC(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_8087358C(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808736A4(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873780(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873868(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873B3C(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873C14(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873D14(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873E04(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873EA4(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80873FD8(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_80874304(BgDyYoseizo* this, GlobalContext* globalCtx);
s32 func_80874B7C(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, BgDyYoseizo* this);
void func_80874BE0(BgDyYoseizo* this, GlobalContext* globalCtx);
// func_80874D9C
void func_80874EAC(BgDyYoseizo* this, GlobalContext* globalCtx);
void func_808751A0(BgDyYoseizo* this, GlobalContext* globalCtx);
/*
const ActorInit Bg_Dy_Yoseizo_InitVars = {
    ACTOR_BG_DY_YOSEIZO,
    ACTORTYPE_PROP,
    ROOM,
    FLAGS,
    OBJECT_DY_OBJ,
    sizeof(BgDyYoseizo),
    (ActorFunc)BgDyYoseizo_Init,
    (ActorFunc)BgDyYoseizo_Destroy,
    (ActorFunc)BgDyYoseizo_Update,
    NULL,
};
*/
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/BgDyYoseizo_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/BgDyYoseizo_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80872960.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80872C58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80872D20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80872DE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_8087328C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873380.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_808734DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_8087358C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_808736A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873780.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873868.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873B3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873C14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873D14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873E04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873EA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80873FD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80874304.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/BgDyYoseizo_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80874B7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80874BE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80874D9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_80874EAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Dy_Yoseizo/func_808751A0.s")
