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
s32 EnGe3_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
void EnGe3_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx);

void func_80A347F4(EnGe3* this, GlobalContext* globalCtx);
void func_80A3490C(EnGe3* this, GlobalContext* globalCtx);
void func_80A34A80(EnGe3* this, GlobalContext* globalCtx);
void func_80A34B90(EnGe3* this, GlobalContext* globalCtx);
void func_80A34B00(EnGe3* this, GlobalContext* globalCtx);
void func_80A34AA0(EnGe3* this, GlobalContext* globalCtx);
void func_80A34A20(EnGe3* this, GlobalContext* globalCtx);
void func_80A34C40(EnGe3* this, GlobalContext* globalCtx);
void func_80A34CE4(Actor* thisx, GlobalContext* globalCtx);

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

ColliderCylinderInit D_80A35190 = {
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

extern SkeletonHeader D_0600A458;
extern AnimationHeader D_0600B07C;

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34620.s")

void EnGe3_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnGe3* this = THIS;
    s32 pad;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 36.0f);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_0600A458, NULL, this->limbDrawTable, this->transitionDrawTable,
                     24);
    SkelAnime_ChangeAnimDefaultRepeat(&this->skelAnime, &D_0600B07C);
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &D_80A35190);
    this->actor.colChkInfo.mass = 0xFF;
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.posRot.rot.z = 0;
    this->actor.shape.rot.z = 0;
    func_80A34620(this, 0);
    this->actionFunc = func_80A34B90;
    this->flag = 0;
    this->actor.unk_1F = 6;
    this->actor.minVelocityY = -4.0f;
    this->actor.gravity = -1.0f;
}

void EnGe3_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnGe3* this = THIS;

    Collider_DestroyCylinder(globalCtx, &this->collider);
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A347F4.s")
void func_80A347F4(EnGe3* this, GlobalContext* globalCtx) {
    s16 yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;
    s32 pad;

    if (ABS(yawDiff) <= 0x4000) {
        Math_SmoothScaleMaxMinS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 6, 4000, 100);
        this->actor.posRot.rot.y = this->actor.shape.rot.y;
        func_80038290(globalCtx, &this->actor, &this->neckRot, &this->bodyRot, this->actor.posRot2.pos);
    } else {
        if (yawDiff < 0) {
            Math_SmoothScaleMaxMinS(&this->neckRot.y, -0x2000, 6, 6200, 256);
        } else {
            Math_SmoothScaleMaxMinS(&this->neckRot.y, 0x2000, 6, 6200, 256);
        }
        Math_SmoothScaleMaxMinS(&this->actor.shape.rot.y, this->actor.yawTowardsLink, 0xC, 1000, 100);
        this->actor.posRot.rot.y = this->actor.shape.rot.y;
    }
}

void func_80A3490C(EnGe3* this, GlobalContext* globalCtx) {
    s16 yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;
    s32 pad;

    if ((ABS(yawDiff) <= 0x2300) && (this->actor.xzDistFromLink < 100.0f)) {
        func_80038290(globalCtx, &this->actor, &this->neckRot, &this->bodyRot, this->actor.posRot2.pos);
    } else {
        Math_SmoothScaleMaxMinS(&this->neckRot.x, 0, 6, 6200, 100);
        Math_SmoothScaleMaxMinS(&this->neckRot.y, 0, 6, 6200, 100);
        Math_SmoothScaleMaxMinS(&this->bodyRot.x, 0, 6, 6200, 100);
        Math_SmoothScaleMaxMinS(&this->bodyRot.y, 0, 6, 6200, 100);
    }
}

void func_80A34A20(EnGe3* this, GlobalContext* globalCtx) {
    if (func_8002F334(&this->actor, globalCtx)) {
        this->actionFunc = func_80A34A80;
        this->actor.update = func_80A34D68;
        this->actor.flags &= ~0x10000;
    }
    func_80A347F4(this, globalCtx);
}

void func_80A34A80(EnGe3* this, GlobalContext* globalCtx) {
    func_80A3490C(this, globalCtx);
}

void func_80A34AA0(EnGe3* this, GlobalContext* globalCtx) {
    if (Actor_HasParent(&this->actor, globalCtx)) {
        this->actor.parent = NULL;
        this->actionFunc = func_80A34A20;
    } else {
        func_8002F434(&this->actor, globalCtx, GI_GERUDO_CARD, 10000.0f, 50.0f);
    }
}

void func_80A34B00(EnGe3* this, GlobalContext* globalCtx) {
    if (func_8010BDBC(&globalCtx->msgCtx) == 5 && func_80106BC8(globalCtx)) {
        func_80106CCC(globalCtx);
        this->actor.flags &= ~0x10000;
        this->actionFunc = func_80A34AA0;
        func_8002F434(&this->actor, globalCtx, GI_GERUDO_CARD, 10000.0f, 50.0f);
    }
}

void func_80A34B90(EnGe3* this, GlobalContext* globalCtx) {
    if (func_8002F194(&this->actor, globalCtx)) {
        this->actionFunc = func_80A34B00;
    } else {
        if (!(this->flag & 4)) {
            func_8002DF54(globalCtx, &this->actor, 7);
            this->flag |= 4;
        }
        this->actor.textId = 0x6004;
        this->actor.flags |= 0x10000;
        func_8002F1C4(&this->actor, globalCtx, 300.0f, 300.0f, 0);
    }

    func_80A3490C(this, globalCtx);
}

void func_80A34C40(EnGe3 *this, GlobalContext *globalCtx) {
    s32 pad[2];

    Collider_CylinderUpdate(&this->actor, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
    func_8002E4B4(globalCtx, &this->actor, 40.0f, 25.0f, 40.0f, 5);
    if (!(this->flag & 2) && (SkelAnime_FrameUpdateMatrix(&this->skelAnime))) {
        this->flag |= 2;
    }
}

#ifdef NON_EQUIVALENT
void func_80A34CE4(Actor* thisx, GlobalContext *globalCtx) {
    EnGe3* this = THIS;

    Actor_MoveForward(&this->actor);

    if (this->winkTimer == 0) {
        this->eyeIdx = 0;
    } else {
        this->winkTimer--;
    }
    if (this->eyeIdx == 0) {
        this->winkTimer = Math_Rand_S16Offset(60, 60);
    }
    this->eyeIdx = this->winkTimer;
    if ((s32) this->eyeIdx >= 3) {
        this->eyeIdx = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34CE4.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/func_80A34D68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_OverrideLimbDraw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_PostLimbDraw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Ge3/EnGe3_Draw.s")
