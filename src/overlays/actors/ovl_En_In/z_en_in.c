#include "z_en_in.h"

#define FLAGS 0x00000019

#define THIS ((EnIn*)thisx)

void EnIn_Init(Actor* thisx, GlobalContext* globalCtx);
void EnIn_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnIn_Update(Actor* thisx, GlobalContext* globalCtx);
void EnIn_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A79FB0(EnIn* this, GlobalContext* globalCtx);

const ActorInit En_In_InitVars = {
    ACTOR_EN_IN,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_IN,
    sizeof(EnIn),
    (ActorFunc)EnIn_Init,
    (ActorFunc)EnIn_Destroy,
    (ActorFunc)EnIn_Update,
    (ActorFunc)EnIn_Draw,
};

ColliderCylinderInit D_80A7B840 = {
    { COLTYPE_UNK10, 0x00, 0x00, 0x39, 0x20, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 18, 46, 0, { 0, 0, 0 } },
};

CollisionCheckInfoInit2 D_80A7B86C = { 0x00, 0x0000, 0x0000, 0x0000, 0xFF };

EnInAnimation D_80A7B878[] = {
    { 0x06001CC0, 1.0f, 0x00, 0.0f },   { 0x06001CC0, 1.0f, 0x00, -10.0f }, { 0x06013C6C, 1.0f, 0x00, 0.0f },
    { 0x06013C6C, 1.0f, 0x00, -10.0f }, { 0x06000CB0, 1.0f, 0x00, 0.0f },   { 0x060003B4, 1.0f, 0x00, -10.0f },
    { 0x06001BE0, 1.0f, 0x00, 0.0f },   { 0x06013D60, 1.0f, 0x00, 0.0f },   { 0x0601431C, 1.0f, 0x00, 0.0f },
    { 0x06014CA8, 1.0f, 0x00, 0.0f },
};

AnimationHeader* D_80A7B918[] = { 0x060151C8, 0x06015DF0, 0x06016B3C, 0x06015814,
                                  0x0601646C, 0x060175D0, 0x06017B58, 0x06018C38 };

Gfx* D_80A7B938[] = {
    NULL,       NULL,       0x06013688, 0x060137c0, 0x06013910, 0x060132b8, 0x060133f0,
    0x06013540, 0x06013100, 0x06011758, 0x06012ac0, 0x06012bf0, 0x06012d20, 0x06012480,
    0x060125b0, 0x060126e0, 0x06011ad8, 0x06012350, 0x06012220, 0x06012120,
};

s32 D_80A7B988[] = { 0x55804CA, 0x01570000 };

s32 D_80A7B990[] = { 0, 0 };

s32 D_80A7B998 = 0;

s32 D_80A7B99C[] = { 0, 0, 0 };

Vec3f D_80A7B9A8 = { 1600.0f, 0.0f, 0.0f };

UNK_PTR D_80A7B9B4[] = { 0x06003590, 0x060047D0, 0x06004BD0, 0x06004390 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A78FB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79010.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79168.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A791CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7924C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7949C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79500.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A795C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79690.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A796EC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7975C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79830.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79A2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79AB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79BAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79C78.s")

void EnIn_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 pad;
    EnIn* this = THIS;
    Vec3f pos;

    this->objBankIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_IN);
    if (this->objBankIdx < 0 && this->actor.params > 0) {
        this->actionFunc = NULL;
        Actor_Kill(&this->actor);
        return;
    }

    pos = gSaveContext.respawn[0].pos;

    if (D_80A7B998 == 0 && pos.x == 1107.0f && pos.y == 0.0f && pos.z == -3740.0f) {
        gSaveContext.eventInf[0] = 0;
        D_80A7B998 = 1;
    }
    this->actionFunc = func_80A79FB0;
}

void EnIn_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnIn* this = THIS;

    if (this->actionFunc != NULL && this->actionFunc != func_80A79FB0) {
        Collider_DestroyCylinder(globalCtx, &this->collider);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A79FB0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A304.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A4BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A4C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A568.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A770.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A848.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7A940.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7AA40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7ABD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7AE84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7AEF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7B018.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7B024.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/EnIn_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7B320.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/func_80A7B570.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_In/EnIn_Draw.s")
