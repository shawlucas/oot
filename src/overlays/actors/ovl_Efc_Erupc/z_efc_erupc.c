#include "z_efc_erupc.h"

#define FLAGS 0x00000030

#define THIS ((EfcErupc*)thisx)

void EfcErupc_Init(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Update(Actor* thisx, GlobalContext* globalCtx);
void EfcErupc_Draw(Actor* thisx, GlobalContext* globalCtx);

extern UNK_TYPE D_06001720;
extern UNK_TYPE D_06002570;
extern UNK_TYPE D_06002760;
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

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/EfcErupc_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/EfcErupc_Draw.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D334.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D52C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D650.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Efc_Erupc/func_8099D71C.s")
