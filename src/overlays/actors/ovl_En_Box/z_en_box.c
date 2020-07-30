#include "z_en_box.h"

#define FLAGS 0x00000000

#define THIS ((EnBox*)thisx)

void EnBox_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBox_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBox_Draw(Actor* thisx, GlobalContext* globalCtx);

void EnBox_SetupAction(EnBox* this, EnBoxActionFunc actionFunc);
void func_809C990C(EnBox* this, GlobalContext* globalCtx);
void func_809C99C4(EnBox* this, GlobalContext* globalCtx);
void func_809C9A7C(EnBox* this, GlobalContext* globalCtx);
void func_809C9B28(EnBox* this, GlobalContext* globalCtx);
void func_809C9D70(EnBox* this, GlobalContext* globalCtx);
void func_809C9EF8(EnBox* this, GlobalContext* globalCtx);


const ActorInit En_Box_InitVars = {
    ACTOR_EN_BOX,
    ACTORTYPE_CHEST,
    FLAGS,
    OBJECT_BOX,
    sizeof(EnBox),
    (ActorFunc)EnBox_Init,
    (ActorFunc)EnBox_Destroy,
    (ActorFunc)EnBox_Update,
    (ActorFunc)EnBox_Draw,
};


AnimationHeader* D_809CA800[] = {
    0x0600024C,
    0x06000128,
    0x0600043C,
    0x0600043C,
};

InitChainEntry D_809CA810[] = {
    ICHAIN_U8(unk_1F, 0, ICHAIN_STOP),
};

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/EnBox_SetupAction.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C8DC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/EnBox_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/EnBox_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C92F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C93F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C94AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C9630.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C9700.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C988C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C990C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C99C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C9A7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C9B28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C9D70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809C9EF8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/EnBox_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809CA2D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809CA448.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809CA4A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/func_809CA518.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Box/EnBox_Draw.s")
