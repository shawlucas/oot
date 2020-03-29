#include "z_en_sa.h"

#define ROOM 0x00
#define FLAGS 0x02000019

void EnSa_Init(EnSa* this, GlobalContext* globalCtx);
void EnSa_Destroy(EnSa* this, GlobalContext* globalCtx);
void EnSa_Update(EnSa* this, GlobalContext* globalCtx);
void EnSa_Draw(EnSa* this, GlobalContext* globalCtx);

/*
const ActorInit En_Sa_InitVars = {
    ACTOR_EN_SA,
    ACTORTYPE_NPC,
    ROOM,
    FLAGS,
    OBJECT_SA,
    sizeof(EnSa),x
    (ActorFunc)EnSa_Init,
    (ActorFunc)EnSa_Destroy,
    (ActorFunc)EnSa_Update,
    (ActorFunc)EnSa_Draw,
};
*/

s32 func_80AF5560(EnSa *this, GlobalContext *globalCtx)
{
  s16 localVar = func_8010BDBC(&globalCtx->msgCtx);
  s16 unk_209 = this->unk_209;
  if ((((unk_209 == 10) || (unk_209 == 5)) || (unk_209 == 2)) || (unk_209 == 1))
  {
    if (localVar != unk_209)
    {
      this->unk_208++;
    }
  }
  this->unk_209 = localVar;
  return localVar;
}

s32 func_80AF55E0(GlobalContext* globalCtx, EnSa* this) {

    u16 faceReaction;
    faceReaction = Text_GetFaceReaction(globalCtx, 0x10);
    if (faceReaction != 0) {
        return faceReaction;
    }

    if ((gBitFlags[14] & gSaveContext.quest_items) != 0) {
        return 0x10AD;
    }
    if ((gBitFlags[18] & gSaveContext.quest_items) != 0) {
        this->unk_208 = 0;
        this->unk_209 = 0;
        if ((gSaveContext.inf_table[0] & 0x20) != 0) {
            return 0x1048;
        }
        return 0x1047;
    }
    if ((gSaveContext.event_chk_inf[0] & 4) != 0) {
        this->unk_208 = 0;
        this->unk_209 = 0;
        if ((gSaveContext.inf_table[0]& 8) != 0) {
            return 0x1032;
        }
        return 0x1031;
    }
    if ((gSaveContext.inf_table[0] & 1) != 0) {
        this->unk_208 = 0;
        this->unk_209 = 0;
        if ((gSaveContext.inf_table[0] & 2) != 0) {
            return 0x1003;
        }
        return 0x1002;
    }
    return 0x1001;
}
//
#ifdef NON_MATCHING
s16 func_80AF56F4(GlobalContext* globalCtx, EnSa* this) {
    
   s16 textId;
   textId = 1;
    

   switch (func_80AF5560(this, globalCtx))
   { 
       case 1:
       case 2:
        if (this->actor.textId != 0x1002) 
        {
            if (this->actor.textId != 0x1031) 
            {
                if (this->actor.textId != 0x1047) 
                {
                    textId = 0;
                } 
                else 
                {
                    gSaveContext.inf_table[0] = gSaveContext.inf_table[0] | 0x20;
                    textId = 0;
                }
            } 
            else 
            {
                gSaveContext.event_chk_inf[0] = gSaveContext.event_chk_inf[0] | 8;
                gSaveContext.inf_table[0] = gSaveContext.inf_table[0] | 8;
                textId = 0;
            }
        } 
        else 
        {
            gSaveContext.inf_table[0] = gSaveContext.inf_table[0] | 2;
            textId = 0;
        }
      default:
        return textId;
    }
    return 0;
   
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF56F4.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF57D8.s")

void func_80AF5894(EnSa* this)
{
  f32 fVar2 = this->skelAnime.unk_0C;

  this->skelAnime.unk_0C = this->skelAnime.animFrameCount;
  this->skelAnime.animCurrentFrame = this->skelAnime.animFrameCount;
  this->skelAnime.animFrameCount = fVar2;
  this->skelAnime.animPlaybackSpeed = -1.0f;
}

#ifdef NON_MATCHING
extern struct_80034EC0_Entry D_80AF7358;
// very close to matching, small ordering issues
void func_80AF58B8(EnSa *this)
{
  SkelAnime *skelAnime;
  s32 sp20;
  if (this->unk_20A != 0)
  {
    if (this->unk_20A != 1)
    {
      return;
    }

  }
  else
  {
    func_80034EC0(&this->skelAnime, &D_80AF7358, 3);
    this->unk_20A++;
  }

  sp20 = skelAnime;
  if (func_800A56C8(skelAnime, (*skelAnime).animFrameCount) != 0)
  {
    skelAnime = &this->skelAnime;
    func_80034EC0(skelAnime, &D_80AF7358, 2);
    this->unk_20A++;
  }

  return;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF58B8.s")
#endif


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF594C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF59E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5A74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5B10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5BA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5C40.s")

void func_80AF5CD4(EnSa* this, u8 arg1)
{
    this->unk_204[7] = arg1;
    this->unk_204[6] = 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5CE4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5D8C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5DFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF5F34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF603C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF609C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF6130.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF6170.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/EnSa_Init.s")
/*extern SkeletonHeader D_0600B1A0;
extern ColliderCylinderMain D_80AF7260;
extern UNK_TYPE D_80AF728C;
extern ActorFunc func_80AF6448;
extern ActorFunc func_80AF683C;
extern u32 func_80AF5DFC(EnSa* this, GlobalContext* globalCtx);
extern u32 D_02010E20;
extern ActorFunc func_80AF68E4;
void EnSa_Init(EnSa* this, GlobalContext* globalCtx) {

    Actor* thisx = &this->actor;

    ActorShape_Init(thisx, 0.0f, ActorShadow_DrawFunc_Circle, 12.0f);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_0600B1A0, NULL, &this->actorDrawTbl, &this->unk_286, 0x11);
    ActorCollider_AllocCylinder(globalCtx, &this->collider);
    ActorCollider_InitCylinder(globalCtx, &this->collider, thisx, &D_80AF7260);
    func_80061EFC(&thisx->sub_98, 0, &D_80AF728C);
    switch (func_80AF5DFC(this, globalCtx))
    {
    case 2:
        func_80AF5D8C(this, 0xB);
        this->actionFunc = &func_80AF6448;
        break;
    case 5:
        func_80AF5D8C(this, 0xB);
        this->actionFunc = &func_80AF683C;
        break;
    case 1:
        thisx->gravity = -1.0f;
        func_80AF5D8C(this, 0);
        this->actionFunc = &func_80AF6448;
        break;
    case 4:
        *(s16*)(this->unk_1E0 + 0x30) = 0;
        thisx->gravity = -1.0f;
        globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(&D_02010E20);
        gSaveContext.cutscene_trigger = 1;
        func_80AF5D8C(this, 4);
        this->actionFunc = &func_80AF68E4;
        break;
    case 3:
        *(s16*)(this->unk_1E0 + 0x30) = 0;
        thisx->gravity = -1.0f;
        func_80AF5D8C(this, 0);
        this->actionFunc = &func_80AF68E4;
        break;
    default:
        Actor_Kill(thisx);
        return;
    }
    Actor_SetScale(thisx, 9.9999998e-3);
    thisx->unk_1F = 6;
    *(u16*)this->unk_1E0 = 0;
    *(u16*)(this->unk_1E0 + 0x38)= 0xFF;
    this->unk_21A = thisx->shape.rot;
    this->unk_21A.z = thisx->shape.rot.z;
    Actor_SpawnAttached(&globalCtx->actorCtx, thisx, globalCtx, 0x18, thisx->posRot.pos.x, thisx->posRot.pos.y, thisx->posRot.pos.z, 0, 0, 0, 3);
}*/

void EnSa_Destroy(EnSa* this, GlobalContext* globalCtx)
{
    ColliderCylinderMain* collider = &this->collider;
    ActorCollider_FreeCylinder(globalCtx, collider);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF6448.s")

extern AnimationHeader* D_0600C500;
extern ActorFunc func_80AF6448;
void func_80AF67D0(EnSa* this, GlobalContext* globalCtx)
{
    if (this->unk_1E0.unk_00 == 0)
    {
        SkelAnime_ChangeAnimation(&this->skelAnime, &D_0600C500, 0.0f, 10.0f, 0.0f, 2, -10.0f);
        this->actionFunc = &func_80AF6448;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF683C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF68E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF6B20.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/EnSa_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/func_80AF6D6C.s")

extern Vec3f D_80AF7454;
void func_80AF6F0C(GlobalContext *globalCtx, s32 limbIndex, Gfx **dList, Vec3s *rot, EnSa* this, Gfx **gfx)
{
    Actor* thisx = &this->actor;
    Vec3f sp18 = D_80AF7454;

    if (limbIndex ==  0x10)
    {
        Matrix_MultVec3f(&sp18, &thisx->posRot2);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Sa/EnSa_Draw.s")
