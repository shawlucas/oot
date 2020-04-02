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
void ItemBHeart_Init(ItemBHeart* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->actor;

    if (Flags_GetCollectible(globalCtx, 0x1F)) {
        Actor_Kill(thisx);
    } else {
        Actor_ProcessInitChain(thisx, &D_80B85530);
        ActorShape_Init(&thisx->shape, 0.0f, NULL, 8.0000001e-1);
    }
}

void ItemBHeart_Destroy(ItemBHeart* this, GlobalContext* globalCtx) {
}

void ItemBHeart_Update(ItemBHeart* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->actor;
    func_80B85264(this, globalCtx);
    func_8002E4B4(globalCtx, thisx, 0.0f, 0.0f, 0.0f, 4);
    if (func_8002F410(thisx, globalCtx) != 0) {
        Flags_SetCollectible(globalCtx, 0x1F);
        Actor_Kill(thisx);

    } else {
        func_8002F434(thisx, globalCtx, GI_HEART_CONTAINER_2, 30.0f, 40.0f);
    }
}

// subtraction instruction needs to be generated
void func_80B85264(ItemBHeart* this, GlobalContext* globalCtx) {
    PosRot* posRot;
    this->unk_164 += 1;
    posRot = &this->actor.initPosRot; // (*posRot) is required
    Math_SmoothScaleMaxF(&this->actor.posRot.pos.y,
                         ((Math_Sins(this->unk_164 * 0x60C) * 5.0f) + 20.0f) + (*posRot).pos.y, 1.0000000e-1,
                         this->unk_158);
    Math_SmoothScaleMaxF(&this->unk_158, 2.0f, 1.0f, 1.0000000e-1);
    this->actor.shape.rot.y += 0x400;
    Math_SmoothScaleMaxF(&this->actor.scale, 4.0000001e-1, 1.0000000e-1, 9.9999998e-3);
    this->actor.scale.z = this->actor.scale.x;
    this->actor.scale.y = this->actor.scale.x;
}

extern char D_80B85540[];
extern char D_80B85554[];
extern char D_80B85568[];
extern char D_80B8557C[];

extern u32 D_06001290;
extern u32 D_06001470;
#ifdef NON_MATCHING
void ItemBHeart_Draw(ItemBHeart* this, GlobalContext* globalCtx) {
    s16 actorId;
    u8 sp57;
    Actor* itemActor;
    Actor* thisx = &this->actor;
    u8 phi_t0;
    GraphicsContext* gfxCtx;
    Gfx* gfxArr[4];

    gfxCtx = globalCtx->state.gfxCtx;
    sp57 = (u8)0U;  
    phi_t0 = sp57;
    func_800C6AC4(gfxArr, globalCtx->state.gfxCtx, D_80B85540, 506);
    itemActor = globalCtx->actorCtx.actorList[ACTORTYPE_ITEMACTION].first;
    if (itemActor != NULL) {
    do
    {    
            if ((ACTOR_DOOR_WARP1 == itemActor->id) && (thisx->unk_E4.z < itemActor->unk_E4.z)) {
                phi_t0 = 1U;
            }

    } while (itemActor->next != NULL);
    }

    if (phi_t0 != 0) {
        func_80093D84(globalCtx->state.gfxCtx);
        gSPMatrix(gfxCtx->polyXlu.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, D_80B85554, 551), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyXlu.p++, &D_06001290);
        gSPDisplayList(gfxCtx->polyXlu.p++, &D_06001470);
    } else {
        func_80093D18(globalCtx->state.gfxCtx);
        gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, D_80B85568, 557), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyOpa.p++, &D_06001290);
        gSPDisplayList(gfxCtx->polyOpa.p++, &D_06001470);
    }
    func_800C6B54(gfxArr, globalCtx->state.gfxCtx, D_80B8557C, 561);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_B_Heart/ItemBHeart_Draw.s")
#endif