#include "z_item_b_heart.h"

#define ROOM 0x00
#define FLAGS 0x00000000

void ItemBHeart_Init(ItemBHeart* this, GlobalContext* globalCtx);
void ItemBHeart_Destroy(ItemBHeart* this, GlobalContext* globalCtx);
void ItemBHeart_Update(ItemBHeart* this, GlobalContext* globalCtx);
void ItemBHeart_Draw(ItemBHeart* this, GlobalContext* globalCtx);
void func_80B85264(ItemBHeart* this, GlobalContext* globalCtx);
/*
const ActorInit Item_B_Heart_InitVars = {
    ACTOR_ITEM_B_HEART,
    ACTORTYPE_MISC,
    ROOM,
    FLAGS,
    OBJECT_GI_HEARTS,
    sizeof(ItemBHeart),
    (ActorFunc)ItemBHeart_Init,
    (ActorFunc)ItemBHeart_Destroy,
    (ActorFunc)ItemBHeart_Update,
    (ActorFunc)ItemBHeart_Draw,
};
*/
extern InitChainEntry D_80B85530;
void ItemBHeart_Init(ItemBHeart* this, GlobalContext* globalCtx)
{
    Actor* thisx = &this->actor;

    if (Flags_GetCollectible(globalCtx, 0x1F))
    {
        Actor_Kill(thisx);
    }
    else
    {
        Actor_ProcessInitChain(thisx, &D_80B85530);
        ActorShape_Init(&thisx->shape, 0.0f, NULL, 8.0000001e-1);
    }
}

void ItemBHeart_Destroy(ItemBHeart* this, GlobalContext* globalCtx)
{

}

void ItemBHeart_Update(ItemBHeart* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->actor;
    func_80B85264(this, globalCtx);
    func_8002E4B4(globalCtx, thisx, 0.0f, 0.0f, 0.0f, 4);
    if (func_8002F410(thisx, globalCtx) != 0) {
        Flags_SetCollectible(globalCtx, 0x1F);
        Actor_Kill(thisx);
        
    }
    else
    {
    func_8002F434(thisx, globalCtx, GI_HEART_CONTAINER_2, 30.0f, 40.0f);
    }
}

#ifdef NON_MATCHING
// subtraction instruction needs to be generated
void func_80B85264(ItemBHeart *this, GlobalContext *globalCtx)
{
  PosRot* posRot;
  this->unk_164 += 1;
  posRot = &this->actor.initPosRot;
  Math_SmoothScaleMaxF(&this->actor.posRot.pos.y, ((Math_Sins((this->unk_164 * 83) * 4) * 5.0f) + 20.0f) + (*posRot).pos.y, 1.0000000e-1, this->unk_158);
  Math_SmoothScaleMaxF(&this->unk_158, 2.0f, 1.0f, 1.0000000e-1);
  this->actor.shape.rot.y += 0x400;
  Math_SmoothScaleMaxF(&this->actor.scale, 4.0000001e-1, 1.0000000e-1, 9.9999998e-3);
  this->actor.scale.z = this->actor.scale.x;
  this->actor.scale.y = this->actor.scale.x;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_B_Heart/func_80B85264.s")
#endif


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_B_Heart/ItemBHeart_Draw.s")
