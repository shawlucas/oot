/*
 * File: z_en_ge3.c
 * Overlay: ovl_En_Ge3
 * Description: Gerudo giving you membership card
 */

#include "z_en_ge3.h"

#define FLAGS 0x00000019

#define THIS ((EnGe3*)thisx)

void EnGe3_Init(Actor* thisx, GlobalContext* globalCtx);
void EnGe3_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnGe3_Update(Actor* thisx, GlobalContext* globalCtx);
void EnGe3_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80A34D68(Actor* thisx, GlobalContext* globalCtx);
s32 EnGe3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
             Vec3f* pos, Vec3s* rot, Actor* thisx);
void EnGe3_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
                                          Vec3s* rot, Actor* thisx);

void func_80A34A80(EnGe3* this, GlobalContext* globalCtx);
void func_80A34B90(EnGe3* this, GlobalContext* globalCtx);
void func_80A34B00(EnGe3* this, GlobalContext* globalCtx);
void func_80A34AA0(EnGe3* this, GlobalContext* globalCtx);
void func_80A34A20(EnGe3* this, GlobalContext* globalCtx);


const ActorInit En_Ge3_InitVars = {
    ACTOR_EN_GE3,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_GELDB,
    sizeof(EnGe3),
    (ActorFunc)EnGe3_Init,
    (ActorFunc)EnGe3_Destroy,
    (ActorFunc)EnGe3_Update,
    (ActorFunc)EnGe3_Draw,
};

ColliderCylinderInit D_80A35190 =
{
    { COLTYPE_UNK10, 0x00, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000722, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
    { 20, 50, 0, { 0, 0, 0 } },
};

EnGe3ActionFunc D_80A351BC[] = { func_80A34A80 };

AnimationHeader* D_80A351C0[] = { 0x0600B07C };

u8 D_80A351C4[] = { 0, 0, 0, 0 };

Vec3f D_80A351C8 = { 600.0f, 700.0f, 0.0f };

UNK_PTR D_80A351D4[] = {
    0x06005FE8,
    0x060065A8,
    0x06006D28,
};

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34620.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A347F4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A3490C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34A20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34A80.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34AA0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34B00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34B90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34C40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34CE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_OverrideLimbDraw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_PostLimbDraw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_Draw.s")
