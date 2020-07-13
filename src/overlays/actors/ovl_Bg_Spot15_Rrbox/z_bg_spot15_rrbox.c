#include "z_bg_spot15_rrbox.h"

#define FLAGS 0x00000000

#define THIS ((BgSpot15Rrbox*)thisx)

void BgSpot15Rrbox_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Rrbox_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Rrbox_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot15Rrbox_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B3A34(BgSpot15Rrbox* this);
UNK_TYPE func_808B3A40(BgSpot15Rrbox* this, GlobalContext* globalCtx);
UNK_TYPE func_808B3CA0(BgSpot15Rrbox* this, GlobalContext* globalCtx, UNK_TYPE arg2);
void func_808B40AC(BgSpot15Rrbox* this, GlobalContext* globalCtx);
void func_808B4178(BgSpot15Rrbox* this, GlobalContext* globalCtx);
void func_808B4194(BgSpot15Rrbox* this, GlobalContext* globalCtx);
void func_808B4380(BgSpot15Rrbox* this, GlobalContext* globalCtx);
void func_808B43D0(BgSpot15Rrbox* this, GlobalContext* globalCtx);
void func_808B44B8(BgSpot15Rrbox* this, GlobalContext* globalCtx);
void func_808B44CC(BgSpot15Rrbox* this, GlobalContext* globalCtx);

s16 D_808B4590 = 0x0000;

const ActorInit Bg_Spot15_Rrbox_InitVars = {
    ACTOR_BG_SPOT15_RRBOX,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_SPOT15_OBJ,
    sizeof(BgSpot15Rrbox),
    (ActorFunc)BgSpot15Rrbox_Init,
    (ActorFunc)BgSpot15Rrbox_Destroy,
    (ActorFunc)BgSpot15Rrbox_Update,
    (ActorFunc)BgSpot15Rrbox_Draw,
};

InitChainEntry D_808B45B4[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 1000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1000, ICHAIN_STOP),
};

Vec3f D_808B45C4[] = { { 770.0f, 1490.0f, -299.0f }, { 770.0f, 1550.0f, -299.0f }, };

Vec3f D_808B45DC[] = { { 29.99f, 0.01f, -29.99f }, { -29.99f, 0.01f, -29.99f }, { -29.99f, 0.01f, 29.99f, },
					   { 29.99f, 0.01f, 29.99f }, { 0.0f, 0.01f, 0.0f }, };

UNK_TYPE D_808B4618[] = { 0x00000000, 0x00000000 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3960.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B39E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3A34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3A40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3AAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/BgSpot15Rrbox_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/BgSpot15Rrbox_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3CA0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3DDC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B3F58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B4010.s")

void func_808B4084(BgSpot15Rrbox* this, GlobalContext* globalCtx)
{
	this->actionFunc = func_808B40AC;
	this->dyna.actor.gravity = 0.0f;
	this->dyna.actor.velocity.x = 0.0f;
	this->dyna.actor.velocity.y = 0.0f;
	this->dyna.actor.velocity.z = 0.0f;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B40AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B4178.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B4194.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B4380.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B43D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B44B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/func_808B44CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/BgSpot15Rrbox_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Spot15_Rrbox/BgSpot15Rrbox_Draw.s")
