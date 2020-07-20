#include "z_bg_mori_hineri.h"

#define FLAGS 0x00000030

#define THIS ((BgMoriHineri*)thisx)

void BgMoriHineri_Init(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHineri_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgMoriHineri_Update(Actor* thisx, GlobalContext* globalCtx);

void func_808A39FC(BgMoriHineri* this, GlobalContext* globalCtx);
void func_808A3F58(BgMoriHineri* this, GlobalContext* globalCtx);
void func_808A3E54(BgMoriHineri* this, GlobalContext* globalCtx);
void func_808A3C8C(BgMoriHineri* this, GlobalContext* globalCtx);
void func_808A3BFC(BgMoriHineri* this, GlobalContext* globalCtx);
void func_808A3BF0(BgMoriHineri* this, GlobalContext* globalCtx);
void func_808A3D58(BgMoriHineri* this, GlobalContext* globalCtx);

static s16 D_808A43E0 = 0xFFFF;

const ActorInit Bg_Mori_Hineri_InitVars = {
    ACTOR_BG_MORI_HINERI,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(BgMoriHineri),
    (ActorFunc)BgMoriHineri_Init,
    (ActorFunc)BgMoriHineri_Destroy,
    (ActorFunc)BgMoriHineri_Update,
    NULL,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 1000, ICHAIN_STOP),
};

static Gfx* sDLists[] = {
    0x060024E0,
    0x06001980,
    0x060020F0,
    0x06002B70,
};

extern UNK_TYPE D_060054B8;
extern UNK_TYPE D_06003490;
extern UNK_TYPE D_060043D0;
extern UNK_TYPE D_06006078;
extern Gfx D_04049FE0[]; // display list for studded dungeon door
extern Gfx D_06000AE8[];
extern Gfx D_06001678[];

void BgMoriHineri_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgMoriHineri* this = THIS;
    s8 objBankIndex;
    u32 paramTemp;
    s32 t6;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyInfo_SetActorMove(&this->dyna.actor, DPM_PLAYER);

    paramTemp = this->dyna.actor.params & 0x3F;
    t6 = this->dyna.actor.params & 0x4000;

    if (t6 != 0) {
        this->switchFlag = paramTemp;
    } else {
        this->switchFlag = ((this->dyna.actor.params >> 8) & 0x3F);
        this->switchFlag = (Flags_GetSwitch(globalCtx, this->switchFlag)) ? 1 : 0;
    }
    this->dyna.actor.params = ((this->dyna.actor.params & 0x8000) >> 0xE);
    if (Flags_GetSwitch(globalCtx, paramTemp)) {
        if (this->dyna.actor.params == 0) {
            this->dyna.actor.params = 1;
        } else if (this->dyna.actor.params == 2) {
            this->dyna.actor.params = 3;
        }
    }
    this->objBoxIndex = -1;
    if (this->dyna.actor.params == 0) {
        this->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI1);
        if (t6 == 0) {
            this->objBoxIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_BOX);
        }
    } else {
        if (this->dyna.actor.params == 1) {
            objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI1A);
        } else {
            objBankIndex = (this->dyna.actor.params == 2)
                               ? Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI2)
                               : Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI2A);
        }
        this->objBankIndex = objBankIndex;
    }
    this->textureIdx = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_TEX);
    if (t6 != 0) {
        this->dyna.actor.params += 4;
    }
    if ((this->objBankIndex < 0) || (this->textureIdx < 0)) {
        Actor_Kill(&this->dyna.actor);
    } else {
        this->actionFunc = func_808A39FC;
    }
}

void BgMoriHineri_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgMoriHineri* this = THIS;
    DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
}

void func_808A39FC(BgMoriHineri* this, GlobalContext* globalCtx) {
    s32 sp2C;

    if ((Object_IsLoaded(&globalCtx->objectCtx, this->objBankIndex)) &&
        (Object_IsLoaded(&globalCtx->objectCtx, this->textureIdx)) &&
        ((this->objBoxIndex < 0) || (Object_IsLoaded(&globalCtx->objectCtx, this->objBoxIndex)))) {
        this->dyna.actor.objBankIndex = this->objBankIndex;
        if (this->dyna.actor.params >= 4) {
            this->dyna.actor.params -= 4;
            if (this->dyna.actor.params == 0) {
                this->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI1A);
            } else if (this->dyna.actor.params == 1) {
                this->objBankIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI1);
            } else {
                this->objBankIndex = (this->dyna.actor.params == 2)
                                         ? Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI2A)
                                         : Object_GetIndex(&globalCtx->objectCtx, OBJECT_MORI_HINERI2);
            }
            if (this->objBankIndex < 0) {
                Actor_Kill(&this->dyna.actor);
            } else {
                this->actionFunc = func_808A3D58;
            }
        } else {
            Actor_SetObjectDependency(globalCtx, &this->dyna.actor);
            sp2C = 0;
            this->dyna.actor.draw = func_808A3F58;
            if (this->dyna.actor.params == 0) {
                this->actionFunc = func_808A3C8C;
                DynaPolyInfo_Alloc(&D_060054B8, &sp2C);
            } else if (this->dyna.actor.params == 1) {
                this->actionFunc = func_808A3BFC;
                DynaPolyInfo_Alloc(&D_06003490, &sp2C);
            } else if (this->dyna.actor.params == 2) {
                this->actionFunc = func_808A3BF0;
                DynaPolyInfo_Alloc(&D_060043D0, &sp2C);
            } else {
                this->actionFunc = func_808A3C8C;
                DynaPolyInfo_Alloc(&D_06006078, &sp2C);
            }
            this->dyna.dynaPolyId =
                DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, sp2C);
        }
    }
}

void func_808A3BF0(BgMoriHineri* this, GlobalContext* globalCtx) {
}

void func_808A3BFC(BgMoriHineri* this, GlobalContext* globalCtx) {
    Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_BOX, this->dyna.actor.posRot.pos.x + 147.0f,
                this->dyna.actor.posRot.pos.y + -245.0f, this->dyna.actor.posRot.pos.z + -453.0f, 0, 0x4000, 0, 0x27EE);
    this->actionFunc = func_808A3BF0;
}

void func_808A3C8C(BgMoriHineri* this, GlobalContext* globalCtx) {
    f32 f0;
    Player* player = PLAYER;

    f0 = 1100.0f - (player->actor.posRot.pos.z - this->dyna.actor.posRot.pos.z);
    this->dyna.actor.shape.rot.z = CLAMP(f0, 0.0f, 1000.0f) * 16.384f;
    func_8005A77C(globalCtx->cameraPtrs[0], 4);
    if (this->dyna.actor.params != 0) {
        this->dyna.actor.shape.rot.z = -this->dyna.actor.shape.rot.z;
    }
}

void func_808A3D58(BgMoriHineri* this, GlobalContext* globalCtx) {
    s16 unk_14E;

    if ((Flags_GetSwitch(globalCtx, this->switchFlag) &&
         (this->dyna.actor.params == 0 || this->dyna.actor.params == 2)) ||
        (!Flags_GetSwitch(globalCtx, this->switchFlag) &&
         (this->dyna.actor.params == 1 || (this->dyna.actor.params == 3)))) {
        this->dyna.actor.draw = func_808A3F58;
        this->actionFunc = func_808A3E54;

        unk_14E = globalCtx->cameraPtrs[0]->unk_14E;
        if ((unk_14E != 0) && (globalCtx->cameraPtrs[unk_14E]->setting == 0x26)) {
            func_800803F0(globalCtx, unk_14E);
        }
        func_800800F8(globalCtx, 0xCBC, 0x28, &this->dyna.actor, 0);
        D_808A43E0 = func_800800F8(globalCtx, 0xCBD, 0x28, &this->dyna.actor, 0);
    }
}

void func_808A3E54(BgMoriHineri* this, GlobalContext* globalCtx) {
    s8 objBankIndex;

    if (globalCtx->activeCamera == D_808A43E0) {
        if (D_808A43E0 != 0) {
            objBankIndex = this->dyna.actor.objBankIndex;
            this->dyna.actor.objBankIndex = this->objBankIndex;
            this->objBankIndex = objBankIndex;
            this->dyna.actor.params ^= 1;
            D_808A43E0 = 0;
            func_80078884(NA_SE_SY_TRE_BOX_APPEAR);
        } else {
            this->dyna.actor.draw = NULL;
            this->actionFunc = func_808A3D58;
            D_808A43E0 = -1;
        }
    }
    if ((D_808A43E0 > 0) &&
        (((globalCtx->cameraPtrs[globalCtx->activeCamera]->eye.z - this->dyna.actor.posRot.pos.z) < 1100.0f))) {
        func_8002F948(&this->dyna.actor, NA_SE_EV_FLOOR_ROLLING - SFX_FLAG);
    }
}

void BgMoriHineri_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgMoriHineri* this = THIS;

    this->actionFunc(this, globalCtx);
}

void func_808A3F58(BgMoriHineri* this, GlobalContext* globalCtx) {

    GraphicsContext* gfxCtx;
    s8 objIndex;
    MtxF mtx;
    Gfx* dispRefs[5];

    gfxCtx = globalCtx->state.gfxCtx;
    Graph_OpenDisps(&dispRefs, globalCtx->state.gfxCtx, "../z_bg_mori_hineri.c", 611);
    func_80093D18(globalCtx->state.gfxCtx);
    gSPSegment(gfxCtx->polyOpa.p++, 0x08, globalCtx->objectCtx.status[this->textureIdx].segment);
    gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_hineri.c", 618),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxCtx->polyOpa.p++, sDLists[this->dyna.actor.params]);
    if (this->objBoxIndex > 0) {
        Matrix_Get(&mtx);
    }
    if ((this->actionFunc == func_808A3C8C) && (this->dyna.actor.shape.rot.z != 0)) {
        func_80093D18(globalCtx->state.gfxCtx);
        if (this->dyna.actor.params == 0) {
            Matrix_Translate(-1761.0f, 1278.0f, -1821.0f, 0);
        } else {
            Matrix_Translate(1999.0f, 1278.0f, -1821.0f, 0);
        }
        Matrix_RotateRPY(0, -0x8000, this->dyna.actor.shape.rot.z, 1);
        Matrix_Translate(0.0f, -50.0f, 0.0f, 1);
        gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_hineri.c", 652),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyOpa.p++, D_04049FE0);
    }
    if ((this->objBoxIndex > 0) && ((this->objBoxIndex = Object_GetIndex(&globalCtx->objectCtx, OBJECT_BOX)) > 0) &&
        (Object_IsLoaded(&globalCtx->objectCtx, this->objBoxIndex))) {
        gSPSegment(gfxCtx->polyOpa.p++, 0x06, globalCtx->objectCtx.status[this->objBoxIndex].segment);
        gSPSegment(gfxCtx->polyOpa.p++, 0x08, &D_80116280[2]);
        Matrix_Put(&mtx);
        Matrix_Translate(147.0f, -245.0f, -453.0f, 1);
        Matrix_RotateY(1.5707964f, 1);
        Matrix_Scale(0.01f, 0.01f, 0.01f, 1);
        gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_hineri.c", 689),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyOpa.p++, D_06000AE8);
        Matrix_Put(&mtx);
        Matrix_Translate(167.0f, -218.0f, -453.0f, 1);
        if (Flags_GetTreasure(globalCtx, 0xE)) {
            Matrix_RotateZ(1.3008157f, 1);
        } else {
            Matrix_RotateZ(M_PI, 1);
        }
        Matrix_Scale(0.01f, 0.01f, 0.01f, 1);
        gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_bg_mori_hineri.c", 703),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyOpa.p++, D_06001678);
    }
    Graph_CloseDisps(dispRefs, globalCtx->state.gfxCtx, "../z_bg_mori_hineri.c", 709);
}
