/*
 * File: z_bg_spot12_gate.c
 * Overlay: ovl_Bg_Spot12_Gate
 * Description: Haunted Wasteland Gate
 */

#include "z_bg_spot12_gate.h"
#include "objects/object_spot12_obj/object_spot12_obj.h"

#define FLAGS 0x00000000

#define THIS ((BgSpot12Gate*)thisx)

void BgSpot12Gate_Init(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Gate_Destroy(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Gate_Update(Actor* thisx, GlobalContext* globalCtx);
void BgSpot12Gate_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_808B30C0(BgSpot12Gate* this);
void func_808B30D8(BgSpot12Gate* this, GlobalContext* globalCtx);
void func_808B3134(BgSpot12Gate* this);
void func_808B314C(BgSpot12Gate* this, GlobalContext* globalCtx);
void func_808B317C(BgSpot12Gate* this);
void func_808B318C(BgSpot12Gate* this, GlobalContext* globalCtx);
void func_808B3274(BgSpot12Gate* this);
void func_808B3298(BgSpot12Gate* this, GlobalContext* globalCtx);

const ActorInit Bg_Spot12_Gate_InitVars = {
    ACTOR_BG_SPOT12_GATE,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_SPOT12_OBJ,
    sizeof(BgSpot12Gate),
    (ActorFunc)BgSpot12Gate_Init,
    (ActorFunc)BgSpot12Gate_Destroy,
    (ActorFunc)BgSpot12Gate_Update,
    (ActorFunc)BgSpot12Gate_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneForward, 2500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 1200, ICHAIN_STOP),
};

void BgSpot12Gate_InitDynaPoly(BgSpot12Gate* this, GlobalContext* globalCtx, CollisionHeader* collision,
                               DynaPolyMoveFlag flags) {
    s32 pad;
    CollisionHeader* colHeader = NULL;
    s32 pad2;

    DynaPolyActor_Init(&this->dyna, flags);
    CollisionHeader_GetVirtual(collision, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(globalCtx, &globalCtx->colCtx.dyna, &this->dyna.actor, colHeader);
    if (this->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_spot12_gate.c", 145,
                     this->dyna.actor.id, this->dyna.actor.params);
    }
}

void BgSpot12Gate_Init(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Gate* this = THIS;

    BgSpot12Gate_InitDynaPoly(this, globalCtx, &gSpot12ObjCol0, DPM_UNK);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    if (Flags_GetSwitch(globalCtx, this->dyna.actor.params & 0x3F)) {
        func_808B3274(this);
    } else {
        func_808B30C0(this);
    }
}

void BgSpot12Gate_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Gate* this = THIS;

    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
}

void func_808B30C0(BgSpot12Gate* this) {
    this->actionFunc = func_808B30D8;
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;
}

void func_808B30D8(BgSpot12Gate* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, this->dyna.actor.params & 0x3F)) {
        func_808B3134(this);
        func_800800F8(globalCtx, 0x1040, -0x63, &this->dyna.actor, 0);
    }
}

void func_808B3134(BgSpot12Gate* this) {
    this->actionFunc = func_808B314C;
    this->unk_168 = 40;
}

void func_808B314C(BgSpot12Gate* this, GlobalContext* globalCtx) {
    if (this->unk_168 <= 0) {
        func_808B317C(this);
    }
}

void func_808B317C(BgSpot12Gate* this) {
    this->actionFunc = func_808B318C;
}

void func_808B318C(BgSpot12Gate* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 var;

    Math_StepToF(&this->dyna.actor.velocity.y, 1.6f, 0.03f);
    if (Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y + 200.0f,
                     this->dyna.actor.velocity.y)) {
        func_808B3274(this);
        var = Quake_Add(ACTIVE_CAM, 3);
        Quake_SetSpeed(var, -0x3CB0);
        Quake_SetQuakeValues(var, 3, 0, 0, 0);
        Quake_SetCountdown(var, 0xC);
        Audio_PlayActorSound2(&this->dyna.actor, NA_SE_EV_BRIDGE_OPEN_STOP);
    } else {
        func_8002F974(&this->dyna.actor, NA_SE_EV_METALGATE_OPEN - SFX_FLAG);
    }
}

void func_808B3274(BgSpot12Gate* this) {
    this->actionFunc = func_808B3298;
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 200.0f;
}

void func_808B3298(BgSpot12Gate* this, GlobalContext* globalCtx) {
}

void BgSpot12Gate_Update(Actor* thisx, GlobalContext* globalCtx) {
    BgSpot12Gate* this = THIS;

    if (this->unk_168 > 0) {
        this->unk_168--;
    }
    this->actionFunc(this, globalCtx);
}

void BgSpot12Gate_Draw(Actor* thisx, GlobalContext* globalCtx) {
    Gfx_DrawDListOpa(globalCtx, gSpot12ObjDL0);
}
