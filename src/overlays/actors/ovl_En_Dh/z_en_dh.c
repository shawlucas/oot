#include "z_en_dh.h"

#define FLAGS 0x00000415

#define THIS ((EnDh*)thisx)

void EnDh_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDh_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDh_Update(Actor* thisx, GlobalContext* globalCtx);
void EnDh_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_809EB110(EnDh* this, GlobalContext* globalCtx);
void func_809EB3D0(EnDh* this, GlobalContext* globalCtx);
void func_809EB53C(EnDh* this, GlobalContext* globalCtx);
void func_809EB624(EnDh* this, GlobalContext* globalCtx);
void func_809EB9B8(EnDh* this, GlobalContext* globalCtx);
void func_809EBBC8(EnDh* this, GlobalContext* globalCtx);
void func_809EBD78(EnDh* this, GlobalContext* globalCtx);
void func_809EBEA8(EnDh* this, GlobalContext* globalCtx);
void func_809EC1A0(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, EnDh* this, Gfx** gfx);

const ActorInit En_Dh_InitVars = {
    ACTOR_EN_DH,
    ACTORTYPE_ENEMY,
    FLAGS,
    OBJECT_DH,
    sizeof(EnDh),
    (ActorFunc)EnDh_Init,
    (ActorFunc)EnDh_Destroy,
    (ActorFunc)EnDh_Update,
    (ActorFunc)EnDh_Draw,
};

ColliderCylinderInit D_809EC5C0 = 
{
    { COLTYPE_UNK0, 0x00, 0x0D, 0x09, 0x10, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000008, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
    { 35, 70, 0, { 0, 0, 0 } },
};

ColliderJntSphItemInit D_809EC5EC[1] = {
    {
        { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x00, 0x01, 0x09 },
        { 1, { { 0, 0, 0 }, 20 }, 100 },
    },
};

ColliderJntSphInit D_809EC610 = 
{
    { COLTYPE_UNK6, 0x00, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    1, D_809EC5EC,
};

DamageTable D_809EC620 = {
	0x00, 0xF2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xF2, 0xF2, 0xF4, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF2, 0xF4,
	0xF2, 0xF4, 0xF8, 0xF4, 0x00, 0x00, 0xF4, 0x00,
};

InitChainEntry D_809EC640[] = {
    ICHAIN_S8(naviEnemyId, 47, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_4C, 2000, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 10, ICHAIN_CONTINUE),
    ICHAIN_F32_DIV1000(gravity, 62036, ICHAIN_STOP),
};

Vec3f D_809EC650 = { 0.0f, 8.0f, 0.0f };

Vec3f D_809EC65C = { 0.0f, -1.5, 0.0f };

Vec3f D_809EC668 = { 2000.0f, 1000.0f, 0.0f };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EAD40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/EnDh_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/EnDh_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EAEC4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB05C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB110.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB334.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB3D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB4D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB53C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB5C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB624.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB934.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EB9B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EBB48.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EBBC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EBCF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EBD78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EBEA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/EnDh_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/func_809EC1A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dh/EnDh_Draw.s")
