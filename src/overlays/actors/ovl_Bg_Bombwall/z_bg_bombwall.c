/*
 * File: z_bg_bombwall.c
 * Overlay: ovl_Bg_Bombwall
 * Description: 2D Bombable Wall
 */

#include "z_bg_bombwall.h"

#define FLAGS 0x00400000

#define THIS ((BgBombwall*)thisx)

void BgBombwall_Init(Actor* thisx, GlobalContext* globalCtx);
void BgBombwall_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgBombwall_Update(Actor* thisx, GlobalContext* globalCtx);
void BgBombwall_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_8086E7D0(BgBombwall* this, GlobalContext* globalCtx);
void func_8086EAC0(BgBombwall* this, GlobalContext* globalCtx);
void func_8086EB5C(BgBombwall* this, GlobalContext* globalCtx);
void func_8086ED50(BgBombwall* this, GlobalContext* globalCtx);
void func_8086ED70(BgBombwall* this, GlobalContext* globalCtx);
void func_8086EDFC(BgBombwall* this, GlobalContext* globalCtx);
void func_8086EE40(BgBombwall* this, GlobalContext* globalCtx);
void func_8086EE94(BgBombwall* this, GlobalContext* globalCtx);

/*
const ActorInit Bg_Bombwall_InitVars = {
    ACTOR_BG_BOMBWALL,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_GAMEPLAY_FIELD_KEEP,
    sizeof(BgBombwall),
    (ActorFunc)BgBombwall_Init,
    (ActorFunc)BgBombwall_Destroy,
    (ActorFunc)BgBombwall_Update,
    (ActorFunc)BgBombwall_Draw,
};
*/
extern UNK_TYPE D_050041B0;
extern Gfx* D_05003FC0;
extern Gfx* D_05004088;
extern InitChainEntry D_8086F004;

void func_8086E7D0(BgBombwall* this, GlobalContext* globalCtx) {
    s32 pad[2];
    s32 sp1C;
    Actor* thisx = &this->dyna.actor;

    sp1C = 0;
    DynaPolyInfo_SetActorMove(thisx, DPM_UNK);
    DynaPolyInfo_Alloc(&D_050041B0, &sp1C);
    this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, thisx, sp1C);
    if (this->dyna.dynaPolyId == 0x32) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(arg_data 0x%04x)\n", "../z_bg_bombwall.c", 243, thisx->params);
    }
}

void func_8086E850(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3)
{
    arg0->x = (arg1->z * arg2) + (arg1->x * arg3);
    arg0->y = arg1->y;
    arg0->z = (arg1->z * arg3) - (arg1->x * arg2);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Bombwall/BgBombwall_Init.s")

void func_8086EAC0(BgBombwall* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->dyna.actor;

    if ((this->unk_2A2 & 2) != 0) {
        DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
        this->unk_2A2 &= 0xFFFD;
    }
    if ((this->unk_2A2 & 1) != 0) {
        Collider_DestroyTris(globalCtx, &this->trisCollider);
        this->unk_2A2 &= 0xFFFE;
    }
}

void BgBombwall_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgBombwall* this = THIS;
    func_8086EAC0(this, globalCtx);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Bombwall/func_8086EB5C.s")

void func_8086ED50(BgBombwall* this, GlobalContext* globalCtx) {
    this->dlist = &D_05003FC0;
    this->actionFunc = func_8086ED70;
}

void func_8086ED70(BgBombwall* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->dyna.actor;

    if ((this->trisCollider.base.acFlags & 2) != 0) {
        this->trisCollider.base.acFlags &= 0xFFFD;
        func_8086EDFC(this, globalCtx);
        Flags_SetSwitch(globalCtx, thisx->params & 0x3F);
    } else if (this->dyna.actor.xzDistanceFromLink < 600.0f) {
        CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->trisCollider);
    }
}

void func_8086EDFC(BgBombwall* this, GlobalContext* globalCtx) {
    this->dlist = &D_05003FC0;
    this->unk_2A0 = 1;
    func_8086EB5C(this, globalCtx);
    this->actionFunc = func_8086EE40;
}

void func_8086EE40(BgBombwall* this, GlobalContext* globalCtx) {
    Actor* thisx = &this->dyna.actor;

    if (this->unk_2A0 > 0) {
        this->unk_2A0 -= 1;
    } else {
        func_8086EE94(this, globalCtx);
        if (((thisx->params >> 0xF) & 1) != 0) {
            func_80078884(NA_SE_SY_CORRECT_CHIME);
        }
    }
}

void func_8086EE94(BgBombwall* this, GlobalContext* globalCtx) {
    this->dlist = &D_05004088;
    func_8086EAC0(this, globalCtx);
    this->actionFunc = NULL;
}

void BgBombwall_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgBombwall* this = THIS;

    if (this->actionFunc) {
        this->actionFunc(this, globalCtx);
    }
}

void BgBombwall_Draw(Actor* thisx, GlobalContext* globalCtx) {
    BgBombwall* this = THIS;
    Gfx_DrawDListOpa(globalCtx, this->dlist);
}
