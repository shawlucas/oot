#include "z_efc_erupc.h"

#define FLAGS 0x00000030

#define THIS ((EfcErupc*)thisx)

void EfcErupc_Init(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Update(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Draw(Actor* thisx, GlobalContext* globalCtx);

extern Gfx D_06001720[];
extern Gfx D_06002570[];
extern Gfx D_06002760[];
extern UNK_TYPE D_060027D8;

void func_8099CD2C(EfcErupc* this, GlobalContext* globalCtx);

const ActorInit Efc_Erupc_InitVars = {
    ACTOR_EFC_ERUPC,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    OBJECT_EFC_ERUPC,
    sizeof(EfcErupc),
    (ActorFunc)EfcErupc_Init,
    (ActorFunc)EfcErupc_Destroy,
    (ActorFunc)EfcErupc_Update,
    (ActorFunc)EfcErupc_Draw,
};

DamageTable D_8099D75C = { 0xFF, 0x80, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00,
                           0x00, 0xFF, 0x80, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64,
                           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

void EfcErupc_SetupAction(EfcErupc* this, EfcErupcActionFunc actionFunc) {
    this->actionFunc = actionFunc;
}

void EfcErupc_Init(Actor* thisx, GlobalContext* globalCtx) {
    EfcErupc* this = THIS;

    EfcErupc_SetupAction(this, func_8099CD2C);
    Actor_SetScale(&this->actor, 1.0f);
    func_8099D71C(this->fdParticle);
    this->unk_150 = 0;
    this->unk_152 = 5;
    this->unk_154 = -0x64;
    this->unk_14C = this->unk_14E = this->unk_150;
}

void EfcErupc_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

void func_8099D650(BossFdParticle* fdParticle, Vec3f* pos, Vec3f* velocity, Vec3f* acceleration, f32 scale);

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099CD2C.s")
void func_8099CD2C(EfcErupc* this, GlobalContext* globalCtx) {
    Vec3f pos;
    Vec3f velocity;
    Vec3f acceleration;
    s32 i;

    if (globalCtx->csCtx.state) {

        if (globalCtx->csCtx.npcActions[1]) {
            if (globalCtx->csCtx.npcActions[1]->action == 2) {
                if (this->unk_150 == 30) {
                    func_800788CC(NA_SE_IT_EARTHQUAKE);
                }
                if (this->unk_150 < 65) {
                    if (this->unk_154 < 200) {
                        this->unk_154 += 10;
                    }
                } else {
                    if (this->unk_154 >= -99) {
                        this->unk_154 -= 10;
                    }
                }
                this->unk_150++;
            } else {
                if (this->unk_154 >= -99) {
                    this->unk_154 -= 10;
                }
            }
        }
    }
    if (globalCtx->csCtx.state) {
        if (globalCtx->csCtx.npcActions[2]) {
            switch (globalCtx->csCtx.npcActions[2]->action) {
                case 2:
                    if (this->unk_14E == 0) {
                        func_800F3F3C(6);
                        gSaveContext.eventChkInf[2] |= 0x8000;
                    }
                    this->unk_14E++;
                    break;
                case 3:
                    this->unk_14E = 30;
                    break;
            }
            this->unk_14C++;
        }
    }

    acceleration.z = 0.0f;
    acceleration.x = 0.0f;
    pos.y = this->actor.posRot.pos.y + 300.0f;

    for (i = 0; i < this->unk_152; i++) {
        pos.x = Math_Rand_CenteredFloat(100.0f) + this->actor.posRot.pos.x;
        pos.z = Math_Rand_CenteredFloat(100.0f) + this->actor.posRot.pos.z;
        velocity.x = Math_Rand_CenteredFloat(100.0f);
        velocity.y = Math_Rand_ZeroFloat(100.0f);
        velocity.z = Math_Rand_CenteredFloat(100.0f);
        acceleration.y = this->unk_154 * 0.1f;
        func_8099D650(this->fdParticle, &pos, &velocity, &acceleration, 80.0f);
    }
}

void EfcErupc_Update(Actor* thisx, GlobalContext* globalCtx) {
    EfcErupc* this = THIS;

    this->actionFunc(this, globalCtx);
    func_8099D52C(this, globalCtx);
}

void func_8099D334(BossFdParticle* particle, GlobalContext* globalCtx);

void EfcErupc_Draw(Actor* thisx, GlobalContext* globalCtx) {
    EfcErupc* this = THIS;
    s32 pad;

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 282);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, this->unk_14C, this->unk_14E * -4, 32, 64, 1,
                                this->unk_14C * 4, this->unk_14E * -20, 64, 64));
    gSPSegment(
        POLY_XLU_DISP++, 0x09,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, this->unk_150 * -4, 16, 128, 1, 0, this->unk_150 * 12, 32, 32));
    gSPSegment(
        POLY_XLU_DISP++, 0x0A,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, this->unk_150 * -4, 16, 128, 1, 0, this->unk_150 * 12, 32, 32));
    Matrix_Push();
    Matrix_Scale(0.8f, 0.8f, 0.8f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 321),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (globalCtx->csCtx.state != 0) {
        if (globalCtx->csCtx.npcActions[1] && (globalCtx->csCtx.npcActions[1]->action == 2)) {
            gSPDisplayList(POLY_XLU_DISP++, D_06002570);
        }
    }
    Matrix_Pull();
    Matrix_Scale(3.4f, 3.4f, 3.4f, MTXMODE_APPLY);
    gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 333),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    if (globalCtx->csCtx.state != 0) {
        CsCmdActorAction* npcAction = globalCtx->csCtx.npcActions[2];
        if (npcAction) {
            u16 action = npcAction->action;
            if (action == 2 || action == 3) {
                gDPSetPrimColor(POLY_XLU_DISP++, 0x80, 0x80, 255, 255, 200, 255);
                gDPSetEnvColor(POLY_XLU_DISP++, 100, 0, 0, 255);
                gSPDisplayList(POLY_XLU_DISP++, D_06001720);
            }
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_efc_erupc.c", 356);
    func_8099D334(this->fdParticle, globalCtx);
}

void func_8099D334(BossFdParticle *particle, GlobalContext *globalCtx) {
    Gfx *sp70;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    Gfx *temp_v0_4;
    Gfx *temp_v0_5;
    Gfx *temp_v0_6;
    MtxF *temp_s4;
    f32 temp_f12;
    s16 temp_s3;
    BossFdParticle *phi_s1;
    s16 i;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    OPEN_DISPS(gfxCtx, "../z_efc_erupc.c", 368);
    phi_s1 = particle;
    i = (u16)0;
loop_1:
    if (phi_s1->type != 0) {
        temp_s4 = &globalCtx->mf_11DA0;
        func_80093D84(globalCtx->state.gfxCtx);
        temp_v0 = gfxCtx->polyXlu.p;
        gfxCtx->polyXlu.p = temp_v0 + 8;
        gSPDisplayList(POLY_XLU_DISP++, D_06002760);
        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x00, particle->color.r, particle->color.g, particle->color.b, particle->alpha);
        gDPSetEnvColor(POLY_XLU_DISP++, 150, 0, 0, 0);
        temp_v0_3 = gfxCtx->polyXlu.p;
        gfxCtx->polyXlu.p = temp_v0_3 + 8;
        temp_v0_3->words.w1 = 0x96000000;
        temp_v0_3->words.w0 = 0xFB000000;
        temp_v0_4 = gfxCtx->polyXlu.p;
        gfxCtx->polyXlu.p = temp_v0_4 + 8;
        temp_v0_4->words.w1 = 0;
        temp_v0_4->words.w0 = 0xE7000000;
        Matrix_Translate(phi_s1->pos.x, phi_s1->pos.y, (bitwise f32) phi_s1->pos.z, MTXMODE_NEW);
        func_800D1FD4(temp_s4);
        temp_f12 = phi_s1->scale;
        Matrix_Scale(temp_f12, temp_f12, 1.0f, MTXMODE_APPLY);
        temp_v0_5 = gfxCtx->polyXlu.p;
        gfxCtx->polyXlu.p = temp_v0_5 + 8;
        temp_v0_5->words.w0 = 0xDA380003;
        temp_v0_5->words.w1 = Matrix_NewMtx(gfxCtx,  "../z_efc_erupc.c", 393);
        temp_v0_6 = gfxCtx->polyXlu.p;
        gfxCtx->polyXlu.p = temp_v0_6 + 8;
        temp_v0_6->words.w1 = 0x60027D8;
        temp_v0_6->words.w0 = 0xDE000000;
    }
    temp_s3 = i + 1;
    phi_s1 = phi_s1 + 0x3C;
    i = temp_s3;
    if ((s32) temp_s3 < 0x64) {
        goto loop_1;
    }
    CLOSE_DISPS(gfxCtx, "../z_efc_erupc.c", 399);
}


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D52C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D650.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D71C.s")
