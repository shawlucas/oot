/*
 * File: z_obj_hamishi.c
 * Overlay: ovl_Obj_Hamishi
 * Description: Bronze Boulder
 */

#include "z_obj_hamishi.h"

#define FLAGS 0x00000000

#define THIS ((ObjHamishi*)thisx)

void ObjHamishi_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjHamishi_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjHamishi_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjHamishi_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80B92FE8(ObjHamishi* this);
void func_80B92F90(Actor* thisx, GlobalContext* globalCtx);

const ActorInit Obj_Hamishi_InitVars = {
    ACTOR_OBJ_HAMISHI,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(ObjHamishi),
    (ActorFunc)ObjHamishi_Init,
    (ActorFunc)ObjHamishi_Destroy,
    (ActorFunc)ObjHamishi_Update,
    (ActorFunc)ObjHamishi_Draw,
};

ColliderCylinderInit D_80B93750 = {
    { COLTYPE_UNK12, 0x00, 0x0D, 0x39, 0x20, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x4FC1FFF6, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
    { 50, 70, 0, { 0, 0, 0 } },
};

CollisionCheckInfoInit D_80B9377C = { 0x00, 0x000C, 0x003C, 0xFF };

s16 D_80B93784[] = { 0x0091, 0x0087, 0x0073, 0x0055, 0x004B, 0x0035, 0x002D, 0x0028, 0x0023 };

InitChainEntry D_80B93798[] = {
    ICHAIN_VEC3F_DIV1000(scale, 400, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 250, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 500, ICHAIN_STOP),
};

void func_80B92F90(Actor* thisx, GlobalContext *globalCtx) {
    ObjHamishi* this = THIS;

    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &D_80B93750);
    Collider_CylinderUpdate(&this->actor,  &this->collider);
}


//
#if 0
void func_80B92FE8(ObjHamishi *this) {
    if (this->vibrationTimer > 0) {
        this->vibrationTimer -= 1;
        this->vibrationAnglePos += 0x1388;
        this->vibrationAngleRot += 0xE10;
        Math_ApproxF(&this->vibrationPowerPos, 0.0f, 0.15f);
        Math_ApproxF(&this->vibrationPowerRot, 0.0f, 40.0f);
        this->actor.posRot.pos.x = (Math_Sins(this->vibrationAnglePos * 4) * this->vibrationPowerPos) + this->actor.initPosRot.pos.x;
        this->actor.posRot.pos.z = (Math_Coss((this->vibrationAnglePos * 8 - this->vibrationAnglePos)) * this->vibrationPowerPos) + this->actor.initPosRot.pos.z;
        this->actor.shape.rot.x  = (s32) (Math_Sins(this->vibrationAngleRot * 4) * this->vibrationPowerRot) + this->actor.initPosRot.rot.x;
        this->actor.shape.rot.z  = (s32) (Math_Coss(this->vibrationAngleRot * 8 - this->vibrationAngleRot) * this->vibrationPowerRot) + this->actor.initPosRot.rot.z;
        return;
    }
    Math_ApproxF(&this->actor.posRot.pos.x, this->actor.initPosRot.pos.x, 1.0f);
    Math_ApproxF(&this->actor.posRot.pos.z, this->actor.initPosRot.pos.z, 1.0f);
    Math_ApproxUpdateScaledS(&this->actor.shape.rot.x, this->actor.initPosRot.rot.x, 3000);
    Math_ApproxUpdateScaledS(&this->actor.shape.rot.z, this->actor.initPosRot.rot.z, 3000);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Obj_Hamishi/func_80B92FE8.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Obj_Hamishi/func_80B93164.s")

void ObjHamishi_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjHamishi* this = THIS;

    Actor_ProcessInitChain(&this->actor, D_80B93798);
    if (globalCtx->csCtx.state) {
        this->actor.uncullZoneForward += 1000.0f;
    }
    if (this->actor.shape.rot.y == 0) {
        this->actor.shape.rot.y = this->actor.posRot.rot.y = this->actor.initPosRot.rot.y =
            Math_Rand_ZeroFloat(65536.0f);
    }
    func_80B92F90(&this->actor, globalCtx);
    func_80061ED4(&this->actor.colChkInfo, NULL, &D_80B9377C);
    if (Flags_GetSwitch(globalCtx, this->actor.params & 0x3F)) {
        Actor_Kill(&this->actor);
    } else {
        this->actor.shape.unk_08 = 80.0f;
    }
}

void ObjHamishi_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    Collider_DestroyCylinder(globalCtx, &THIS->collider);
}

void ObjHamishi_Update(Actor* thisx, GlobalContext* globalCtx) {
    ObjHamishi* this = THIS;
    s32 pad;

    func_80B92FE8(this);
    if ((this->collider.base.acFlags & 2) && (this->collider.body.acHitItem->toucher.flags & 0x40000040)) {
        this->collider.base.acFlags &= ~2;
        this->numOfHammerSwings++;
        if (this->numOfHammerSwings < 2) {
            this->vibrationTimer = 15;
            this->vibrationPowerPos = 2.0f;
            this->vibrationPowerRot = 400.0f;
        } else {
            func_80B93164(this, globalCtx);
            Audio_PlaySoundAtPosition(globalCtx, &this->actor.posRot.pos, 40, NA_SE_EV_WALL_BROKEN);
            Flags_SetSwitch(globalCtx, this->actor.params & 0x3F);
            Actor_Kill(&this->actor);
        }
    } else {
        this->collider.base.acFlags &= ~2;
        if (this->actor.xzDistFromLink < 600.0f) {
            CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
            CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
        }
    }
}

extern Gfx D_0500A3B8[];

void ObjHamishi_Draw(Actor* thisx, GlobalContext *globalCtx) {

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_obj_hamishi.c", 399);

    func_80093D18(globalCtx->state.gfxCtx);
    gSPMatrix(oGfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_obj_hamishi.c", 404), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetPrimColor(oGfxCtx->polyOpa.p++, 0, 0, 255, 170, 130, 255);
    gSPDisplayList(oGfxCtx->polyOpa.p++, D_0500A3B8);

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_obj_hamishi.c", 411);
}

