#include "z_en_mm2.h"

#define FLAGS 0x00000019

#define THIS ((EnMm2*)thisx)

void EnMm2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMm2_Draw(Actor* thisx, GlobalContext* globalCtx);

s32 EnMm2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
void EnMm2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx);
void func_80AAEF70(EnMm2* this, GlobalContext* globalCtx);
void func_80AAF668(EnMm2* this, GlobalContext* globalCtx);
void func_80AAF57C(EnMm2* this, GlobalContext* globalCtx);
void func_80AAF2BC(EnMm2* this, GlobalContext* globalCtx);
void func_80AAF330(EnMm2* this, GlobalContext* globalCtx);
void func_80AAF57C(EnMm2* this, GlobalContext* globalCtx);
void func_80AAF3C0(EnMm2* this, GlobalContext* globalCtx);
s32 func_80AAF224(EnMm2* this, GlobalContext* globalCtx, EnMm2ActionFunc actionFunc);

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

extern struct_D_80AA1678 D_80AAFAEC[];
extern Vec3f D_80AAFB68;
extern InitChainEntry D_80AAFB5C;
extern SkeletonHeader D_06005E18;
extern ColliderCylinderInit D_80AAFAC0;
extern UNK_PTR D_80AAFB60[];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAEE50.s")

void func_80AAEF70(EnMm2* this, GlobalContext* globalCtx) {
    if ((gSaveContext.eventChkInf[9] & 0xF) != 0xF) {
        this->actor.textId = 0x6086;
    } else if ((gSaveContext.infTable[23] & 0x8000) != 0) {
        if ((gSaveContext.eventInf[1] & 1) != 0) {
            this->actor.textId = 0x6082;
        } else if (gSaveContext.timer2State != 0) {
            this->actor.textId = 0x6076;
        } else if (gSaveContext.unk_EC8 == 0x9E) {
            this->actor.textId = 0x607E;
        } else {
            this->actor.textId = 0x6081;
        }
    } else if (gSaveContext.timer2State != 0) {
        this->actor.textId = 0x6076;
    } else {
        this->actor.textId = 0x607D;
        gSaveContext.eventInf[1] &= ~1;
        gSaveContext.unk_EC8 = 0x9E;
    }
}

void EnMm2_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnMm2* this = THIS;
    SkelAnime* skelAnime = &this->skelAnime;
    Actor_ProcessInitChain(&this->actor, &D_80AAFB5C);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 21.0f);
    SkelAnime_InitSV(globalCtx, skelAnime, &D_06005E18, NULL, this->limbDrawTable, this->transitionDrawTable, 16);
    SkelAnime_ChangeAnim(skelAnime, D_80AAFAEC[2].animation, 1.0f, 0.0f,
                         (f32)SkelAnime_GetFrameCount(D_80AAFAEC[2].animation), D_80AAFAEC[2].unk_08,
                         D_80AAFAEC[2].transitionRate);
    this->unk_1F8 = 2;
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder(globalCtx, &this->collider, &this->actor, &D_80AAFAC0);
    this->actor.colChkInfo.mass = 0xFF;
    this->unk_1E0 = 0;
    this->actor.unk_1F = 6;
    this->unk_1F4 |= 1;
    this->actor.gravity = -1.0f;
    if (this->actor.params == 1) {
        this->actionFunc = func_80AAF668;
    } else {
        func_80AAEF70(this, globalCtx);
        this->actionFunc = func_80AAF57C;
    }
    if (LINK_IS_CHILD) {
        Actor_Kill(&this->actor);
    }
    if ((this->actor.params == 1) &&
        (((gSaveContext.infTable[23] & 0x8000) == 0) || ((gSaveContext.eventInf[1] & 1) == 0))) {
        osSyncPrintf("\x1b[36m マラソン 開始されていない \n\x1b[m\n");
        Actor_Kill(&this->actor);
    }
}

void EnMm2_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnMm2* this = THIS;
    Collider_DestroyCylinder(globalCtx, &this->collider);
}

s32 func_80AAF224(EnMm2* this, GlobalContext* globalCtx, EnMm2ActionFunc actionFunc) {
    s16 yawDiff;

    if (func_8002F194(&this->actor, globalCtx) != 0) {
        this->actionFunc = actionFunc;
        return 1;
    }
    yawDiff = this->actor.yawTowardsLink - this->actor.shape.rot.y;
    if ((ABS(yawDiff) < 0x4301) && (this->actor.xzDistFromLink < 100.0f)) {
        func_8002F2CC(&this->actor, globalCtx, 100.0f);
    }
    return 0;
}

void func_80AAF2BC(EnMm2* this, GlobalContext* globalCtx) {
    if (this->unk_1F6 >= 0x3D) {
        Actor_Kill(&this->actor);
    }
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    this->unk_1F6++;
    Math_SmoothScaleMaxMinF(&this->actor.speedXZ, 10.0f, 0.6f, 2.0f, 0.0f);
}

void func_80AAF330(EnMm2* this, GlobalContext* globalCtx) {
    if (SkelAnime_FrameUpdateMatrix(&this->skelAnime) != 0) {
        this->actionFunc = func_80AAF2BC;
        func_80AAEE50(this, 0, &this->unk_1F8);
        this->unk_1E0 = 1;
        if ((this->unk_1F4 & 2) == 0) {
            func_80106CCC(globalCtx);
        }
        gSaveContext.timer2State = 0;
        gSaveContext.eventInf[1] &= 0xFFFE;
    }
}

#if 0
void func_80AAF3C0(EnMm2 *this, GlobalContext *globalCtx) {
    s32 textId;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    textId = this->actor.textId;
    switch (textId)
    {
        case 0x607D:
        case 0x607E:
        case 0x6081:
            if ((func_8010BDBC(&globalCtx->msgCtx) == 5) && (func_80106BC8(globalCtx) != 0))
            {
                this->unk_1F4 |= 4;
                gSaveContext.unk_EC8--;
                func_8010B720(globalCtx, 0x607E);
                this->actor.textId = 0x607E;
            }
        default:
            if (func_8002F334(&this->actor, globalCtx) != 0)
            {
                if (this->actor.textId == 0x607F) {
                    func_80088AA0(0);
                    this->actionFunc = func_80AAF57C;
                } else {
                    this->actionFunc = func_80AAF57C;
                }
                func_80AAEF70(this, globalCtx);
            }
            if ((func_8010BDBC(&globalCtx->msgCtx) == 4) && (func_80106BC8(globalCtx) != 0)) {
                switch (globalCtx->msgCtx.choiceIndex)
                {
                    case 0:
                        func_8010B720(globalCtx, 0x607F); // "Excellent! Then...You go first. I'll give you a headstart..."
                        this->actor.textId = 0x607F;
                        gSaveContext.eventInf[1] |= 1;
                    case 1:
                        func_8010B720(globalCtx, 0x6080); // "Heh heh heh. You'll never discover your killer instinct with that kind of attitude.."
                        this->actor.textId = 0x6080;
                    default:
                        break;
                }
                if ((this->unk_1F4 & 4) != 0) {
                    this->unk_1F4 &= 0xFFFB;
                    gSaveContext.unk_EC8++;
                    return;
                }
        }
    }
            
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Mm2/func_80AAF3C0.s")
#endif

void func_80AAF57C(EnMm2* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    func_80AAEF70(this, globalCtx);
    if ((func_80AAF224(this, globalCtx, func_80AAF3C0) != 0) && (this->actor.textId == 0x607D)) {
        gSaveContext.infTable[23] |= 0x8000;
    }
}

void func_80AAF5EC(EnMm2* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((func_8010BDBC(&globalCtx->msgCtx) == 5) && (func_80106BC8(globalCtx) != 0)) {
        this->unk_1F4 &= 0xFFFE;
        func_80AAEE50(this, 3, &this->unk_1F8);
        this->actionFunc = func_80AAF330;
    }
}

void func_80AAF668(EnMm2* this, GlobalContext* globalCtx) {
    s16 timer2Value;

    this->actor.posRot.rot.y = -16000;
    this->actor.shape.rot.y = this->actor.posRot.rot.y;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    timer2Value = gSaveContext.timer2Value;
    if (timer2Value < gSaveContext.unk_EC8) {
        this->actor.textId = 0x6085;
    } else {
        this->actor.textId = 0x6084;
    }

    if (func_80AAF224(this, globalCtx, func_80AAF5EC) != 0) {
        this->unk_1F6 = 0;
        timer2Value = gSaveContext.timer2Value;
        if (timer2Value < gSaveContext.unk_EC8) {
            gSaveContext.unk_EC8 = gSaveContext.timer2Value;
        }
    } else {
        LogUtils_LogThreadId("../z_en_mm2.c", 0x21D);
        osSyncPrintf("((z_common_data.event_inf[1]) & (0x0001)) = %x\n", gSaveContext.eventInf[1] & 1);
        if ((gSaveContext.eventInf[1] & 1) == 0) {
            this->unk_1F4 |= 2;
            this->unk_1F4 &= ~1;
            func_80AAEE50(this, 3, &this->unk_1F8);
            this->actionFunc = func_80AAF330;
        }
    }
}

void EnMm2_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnMm2* this = THIS;
    s32 pad;

    if ((this->unk_1F4 & 1) != 0) {
        func_80038290(globalCtx, &this->actor, &this->unk_1E8, &this->unk_1EE, this->actor.posRot2.pos);
    } else {
        Math_SmoothScaleMaxMinS(&this->unk_1E8.x, 0, 6, 0x1838, 0x64);
        Math_SmoothScaleMaxMinS(&this->unk_1E8.y, 0, 6, 0x1838, 0x64);
        Math_SmoothScaleMaxMinS(&this->unk_1EE.x, 0, 6, 0x1838, 0x64);
        Math_SmoothScaleMaxMinS(&this->unk_1EE.y, 0, 6, 0x1838, 0x64);
    }
    this->actionFunc(this, globalCtx);
    Collider_CylinderUpdate(&this->actor, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider.base);
    Actor_MoveForward(&this->actor);
    func_8002E4B4(globalCtx, &this->actor, 0.0f, 0.0f, 0.0f, 4);
}

void EnMm2_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EnMm2* this = THIS;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    Gfx* dispRefs[4];

    Graph_OpenDisps(dispRefs, globalCtx->state.gfxCtx, "../z_en_mm2.c", 0x27A);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(gfxCtx->polyOpa.p++, 0x08, SEGMENTED_TO_VIRTUAL(D_80AAFB60[this->unk_1E0]));
    SkelAnime_DrawSV(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount,
                     EnMm2_OverrideLimbDraw, EnMm2_PostLimbDraw, &this->actor);
    Graph_CloseDisps(dispRefs, globalCtx->state.gfxCtx, "../z_en_mm2.c", 0x28E);
}

s32 EnMm2_OverrideLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    EnMm2* this = THIS;

    switch (limbIndex) {
        case 8:
            rot->x += this->unk_1EE.y;
            rot->y -= this->unk_1EE.x;
            break;

        case 0xF:
            rot->x += this->unk_1E8.y;
            rot->z += this->unk_1E8.x + 4000;
            break;
    }
    return 0;
}

void EnMm2_PostLimbDraw(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    if (limbIndex == 0xF) {
        Matrix_MultVec3f(&D_80AAFB68, &thisx->posRot2);
    }
}
