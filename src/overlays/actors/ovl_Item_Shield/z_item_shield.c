/*
 * File: z_item_shield.c
 * Overlay: ovl_Item_Shield
 * Description: Deku Shield
 */

#include "z_item_shield.h"

#define FLAGS 0x00000010

#define THIS ((ItemShield*)thisx)

void ItemShield_Init(Actor* thisx, GlobalContext* globalCtx);
void ItemShield_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ItemShield_Update(Actor* thisx, GlobalContext* globalCtx);
void ItemShield_Draw(Actor* thisx, GlobalContext* globalCtx);

ColliderCylinderInit D_80B871A0 =
{
    { COLTYPE_UNK10, 0x00, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000004, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
    { 15, 15, 0, { 0, 0, 0 } },
};

const ActorInit Item_Shield_InitVars = {
    ACTOR_ITEM_SHIELD,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_LINK_CHILD,
    sizeof(ItemShield),
    (ActorFunc)ItemShield_Init,
    (ActorFunc)ItemShield_Destroy,
    (ActorFunc)ItemShield_Update,
    (ActorFunc)ItemShield_Draw,
};

Color_RGBA8_n D_80B871EC = { 255, 255, 0, 255 };

Color_RGBA8_n D_80B871F0 = { 255, 0, 0, 255 };

Vec3f D_80B871F4 = { 0.0f, 0.0f, 0.0f };

f32 D_80B87200[] = {
    0.3f, 0.6f, 0.9f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.85f, 0.7f, 0.55f, 0.4f, 0.25f, 0.1f, 0.0f,
};

f32 D_80B87240[] = {
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.8f, 0.6f, 0.4f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/func_80B86920.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/ItemShield_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/ItemShield_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/func_80B86AC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/func_80B86BC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/func_80B86CA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/func_80B86F68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/ItemShield_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Item_Shield/ItemShield_Draw.s")
