#include "z_en_mm2.h"

#define FLAGS 0x00000019

#define THIS ((EnMm2*)thisx)

void EnMm2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnMm2_OverrideLimbDraw(GlobalContext *globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
void EnMm2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx);

/*
const ActorInit En_Mm2_InitVars = {
    ACTOR_EN_MM2,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_MM,
    sizeof(EnMm2),
    (ActorFunc)EnMm2_Init,
    (ActorFunc)EnMm2_Destroy,
    (ActorFunc)EnMm2_Update,
    (ActorFunc)EnMm2_Draw,
};
*/

extern Vec3f D_80AAFB68;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAEE50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAEF70.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/EnMm2_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/EnMm2_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF224.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF2BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF330.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF3C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF57C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF5EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF668.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/EnMm2_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/EnMm2_Draw.s")

s32 EnMm2_OverrideLimbDraw(GlobalContext *globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx)
{
    EnMm2* this = THIS;
    
    if (limbIndex == 8)
    {
        rot->x += this->unk_1EE.y;
        rot->y -= this->unk_1EE.x;
        return 0;
    }

    if (limbIndex != 0xF)
    {
        return 0;
    }

    rot->x += this->unk_1E8.y;
    rot->z += this->unk_1E8.x - 4000;
}

void EnMm2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx)
{
    if (limbIndex == 0xF)
    {
        Matrix_MultVec3f(&D_80AAFB68, &thisx->posRot2);
    }
}
