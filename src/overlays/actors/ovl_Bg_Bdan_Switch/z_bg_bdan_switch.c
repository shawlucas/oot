/*
 * File: z_bg_bdan_switch.c
 * Overlay: Bg_Bdan_Switch
 * Description: Switches (Inside Lord Jabu-Jabu)
 */

#include "z_bg_bdan_switch.h"

#define FLAGS 0x00000010

void BgBdanSwitch_Init(BgBdanSwitch* this, GlobalContext* globalCtx);
void BgBdanSwitch_Destroy(BgBdanSwitch* this, GlobalContext* globalCtx);
void BgBdanSwitch_Update(BgBdanSwitch* this, GlobalContext* globalCtx);
void BgBdanSwitch_Draw(BgBdanSwitch* this, GlobalContext* globalCtx);

void func_8086D5C4(BgBdanSwitch* this);
void func_8086D5E0(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D67C(BgBdanSwitch* this);
void func_8086D694(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D730(BgBdanSwitch* this);
void func_8086D754(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D7FC(BgBdanSwitch* this);
void func_8086D80C(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D86C(BgBdanSwitch* this);
void func_8086D888(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D8BC(BgBdanSwitch* this);
void func_8086D8CC(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D95C(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086D9F8(BgBdanSwitch* this);
void func_8086DA1C(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086DAB4(BgBdanSwitch* this);
void func_8086DAC4(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086DB24(BgBdanSwitch* this);
void func_8086DB40(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086DB4C(BgBdanSwitch* this);
void func_8086DB68(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086DC30(BgBdanSwitch* this);
void func_8086DC48(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086DCCC(BgBdanSwitch* this);
void func_8086DCE8(BgBdanSwitch* this, GlobalContext* globalCtx);
void func_8086DDA8(BgBdanSwitch* this);
void func_8086DDC0(BgBdanSwitch* this, GlobalContext* globalCtx);

const ActorInit Bg_Bdan_Switch_InitVars = {
    ACTOR_BG_BDAN_SWITCH,
    ACTORTYPE_SWITCH,
    FLAGS,
    OBJECT_BDAN_OBJECTS,
    sizeof(BgBdanSwitch),
    (ActorFunc)BgBdanSwitch_Init,
    (ActorFunc)BgBdanSwitch_Destroy,
    (ActorFunc)BgBdanSwitch_Update,
    (ActorFunc)BgBdanSwitch_Draw,
};

extern UNK_PTR D_06005CF8;
extern UNK_PTR D_060061A0;
extern UNK_PTR D_06005A20;

static ColliderJntSphItemInit colliderItemsInit[] = {
    {
        { 0x00, { 0x00000000, 0x00, 0x00 }, { 0xEFC1FFFE, 0x00, 0x00 }, 0x00, 0x01, 0x01 },
        { 0x00, { { 0x0000, 0x0078, 0x0000 }, 370 }, 100 },
    },
};

static ColliderJntSphInit colliderInit = {
    { COLTYPE_UNK10, 0x00, 0x09, 0x39, 0x20, COLSHAPE_JNTSPH },
    1,
    &colliderItemsInit,
};

static InitChainEntry initChain[] = {
    ICHAIN_F32(unk_F4, 1400, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_F8, 500, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_FC, 1200, ICHAIN_STOP),
};

static Vec3f D_8086E0E0 = { 0, 140.0f, 0 };

void func_8086D010(BgBdanSwitch* this, GlobalContext* globalCtx, u32 collision, DynaPolyMoveFlag flag) {
    s16 pad1;
    u32 local_c = 0;
    s16 pad2;

    DynaPolyInfo_SetActorMove(&this->actor, flag);
    DynaPolyInfo_Alloc(collision, &local_c);
    this->dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, &this->actor, local_c);
    if (this->dynaPolyId == 0x32) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", "../z_bg_bdan_switch.c", 325,
                     this->actor.id, this->actor.params);
    }
}

void func_8086D098(BgBdanSwitch* this, GlobalContext* globalCtx) {
    Actor* actor = &this->actor;
    Collider_InitJntSph(globalCtx, &this->collider);
    Collider_SetJntSph(globalCtx, &this->collider, actor, &colliderInit, &this->colliderItems);
}

void func_8086D0EC(BgBdanSwitch* this) {
    if (this->unk_1CC > 0) {
        this->unk_1CC += 0x5DC;
    } else {
        this->unk_1CC += 0xFA0;
    }

    switch (this->actor.params & 0xFF) {
        case BLUE:
        case YELLOW_HEAVY:
        case YELLOW:
            this->unk_1D4 = ((Math_Coss(this->unk_1CC) * 0.5f) + 8.833334f) * 0.012f;
            this->unk_1D0 = ((Math_Coss(this->unk_1CC) * 0.5f) + 20.5f) * (this->unk_1C8 * 0.0050000004f);
            this->actor.scale.y = this->unk_1C8 * 0.1f;
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            this->unk_1D4 = ((Math_Coss(this->unk_1CC) * 0.5f) + (43.0f / 6.0f)) * 0.0075000003f;
            this->unk_1D0 = ((Math_Coss(this->unk_1CC) * 0.5f) + 20.5f) * (this->unk_1C8 * 0.0050000004f);
            this->actor.scale.y = this->unk_1C8 * 0.1f;
    }
    this->actor.shape.unk_08 = 1.2f / this->unk_1D0;
}

void BgBdanSwitch_Init(BgBdanSwitch* this, GlobalContext* globalCtx) {
    s32 pad[2];
    s16 type;
    s32 flag;

    type = this->actor.params & 0xFF;
    Actor_ProcessInitChain(&this->actor, initChain);
    if (type == YELLOW_TALL_1 || type == YELLOW_TALL_2) {
        this->actor.scale.z = 0.05f;
        this->actor.scale.x = 0.05f;
    } else {
        this->actor.scale.z = 0.1f;
        this->actor.scale.x = 0.1f;
    }
    this->actor.scale.y = 0.0f;
    Actor_SetHeight(&this->actor, 10.0f);

    switch (type) {
        case BLUE:
        case YELLOW_HEAVY:
        case YELLOW:
            func_8086D010(this, globalCtx, &D_06005CF8, 1);
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            func_8086D098(this, globalCtx);
            this->actor.flags |= 1;
            this->actor.unk_1F = 4;
    }

    flag = Flags_GetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F);

    switch (type) {
        case BLUE:
        case YELLOW:
            if (flag) {
                func_8086D730(this);
            } else {
                func_8086D5C4(this);
            }
            break;
        case YELLOW_HEAVY:
            if (flag) {
                func_8086DB24(this);
            } else {
                func_8086D86C(this);
            }
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            if (flag) {
                func_8086DCCC(this);
            } else {
                func_8086DB4C(this);
            }
            break;
        default:
            osSyncPrintf("不正な ARG_DATA(arg_data 0x%04x)(%s %d)\n", this->actor.params, "../z_bg_bdan_switch.c", 454);
            Actor_Kill(&this->actor);
            return;
    }
    osSyncPrintf("(巨大魚ダンジョン 専用スイッチ)(arg_data 0x%04x)\n", this->actor.params);
}

void BgBdanSwitch_Destroy(BgBdanSwitch* this, GlobalContext* globalCtx) {
    switch (this->actor.params & 0xFF) {
        case BLUE:
        case YELLOW_HEAVY:
        case YELLOW:
            DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dynaPolyId);
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            Collider_DestroyJntSph(globalCtx, &this->collider);
    }
}

void func_8086D4B4(BgBdanSwitch* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 type;
    if (!Flags_GetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F)) {
        type = this->actor.params & 0xFF;
        Flags_SetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F);
        if (type == BLUE || type == YELLOW_TALL_2) {
            func_800806BC(globalCtx, &this->actor, 0x4807);
        } else {
            func_800806BC(globalCtx, &this->actor, 0x4802);
        }
    }
}

void func_8086D548(BgBdanSwitch* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F)) {
        Flags_UnsetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F);
        if ((this->actor.params & 0xFF) == YELLOW_TALL_2) {
            func_800806BC(globalCtx, &this->actor, 0x4807);
        }
    }
}

void func_8086D5C4(BgBdanSwitch* this) {
    this->updateFunc = &func_8086D5E0;
    this->unk_1C8 = 1.0f;
}

void func_8086D5E0(BgBdanSwitch* this, GlobalContext* globalCtx) {
    switch (this->actor.params & 0xFF) {
        case BLUE:
            if (func_800435B4(&this->actor)) {
                func_8086D67C(this);
                func_8086D4B4(this, globalCtx);
            }
            break;
        case YELLOW:
            if (func_8004356C(&this->actor)) {
                func_8086D67C(this);
                func_8086D4B4(this, globalCtx);
            }
    }
}

void func_8086D67C(BgBdanSwitch* this) {
    this->updateFunc = &func_8086D694;
    this->unk_1DA = 0x64;
}

void func_8086D694(BgBdanSwitch* this, GlobalContext* globalCtx) {
    if ((func_8005B198() == this->actor.type) || (this->unk_1DA <= 0)) {
        this->unk_1C8 -= 0.2f;
        if (this->unk_1C8 <= 0.1f) {
            func_8086D730(this);
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
            func_800AA000(this->actor.waterSurfaceDist, 0x78, 0x14, 0xA);
        }
    }
}

void func_8086D730(BgBdanSwitch* this) {
    this->unk_1C8 = 0.1f;
    this->updateFunc = &func_8086D754;
    this->unk_1D8 = 6;
}

void func_8086D754(BgBdanSwitch* this, GlobalContext* globalCtx) {
    switch (this->actor.params & 0xFF) {
        case BLUE:
            if (!func_800435B4(&this->actor)) {
                if (this->unk_1D8 <= 0) {
                    func_8086D7FC(this);
                    func_8086D548(this, globalCtx);
                }
            } else {
                this->unk_1D8 = 6;
            }
            break;
        case YELLOW:
            if (!Flags_GetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F)) {
                func_8086D7FC(this);
            }
    }
}

void func_8086D7FC(BgBdanSwitch* this) {
    this->updateFunc = &func_8086D80C;
}

void func_8086D80C(BgBdanSwitch* this, GlobalContext* globalCtx) {
    this->unk_1C8 += 0.2f;
    if (this->unk_1C8 >= 1.0f) {
        func_8086D5C4(this);
        Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
    }
}

void func_8086D86C(BgBdanSwitch* this) {
    this->updateFunc = &func_8086D888;
    this->unk_1C8 = 1.0f;
}

void func_8086D888(BgBdanSwitch* this, GlobalContext* globalCtx) {
    if (func_8004356C(&this->actor)) {
        func_8086D8BC(this);
    }
}

void func_8086D8BC(BgBdanSwitch* this) {
    this->updateFunc = &func_8086D8CC;
}

void func_8086D8CC(BgBdanSwitch* this, GlobalContext* globalCtx) {
    this->unk_1C8 -= 0.2f;
    if (this->unk_1C8 <= 0.6f) {
        func_8086D9F8(this);
        Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
        func_800AA000(this->actor.waterSurfaceDist, 0x78, 0x14, 0xA);
    }
}

void func_8086D944(BgBdanSwitch* this) {
    this->updateFunc = &func_8086D95C;
    this->unk_1DA = 0x64;
}

void func_8086D95C(BgBdanSwitch* this, GlobalContext* globalCtx) {
    if ((func_8005B198() == this->actor.type) || (this->unk_1DA <= 0)) {
        this->unk_1C8 -= 0.2f;
        if (this->unk_1C8 <= 0.1f) {
            func_8086DB24(this);
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
            func_800AA000(this->actor.waterSurfaceDist, 0x78, 0x14, 0xA);
        }
    }
}

void func_8086D9F8(BgBdanSwitch* this) {
    this->unk_1C8 = 0.6f;
    this->updateFunc = &func_8086DA1C;
    this->unk_1D8 = 6;
}

void func_8086DA1C(BgBdanSwitch* this, GlobalContext* globalCtx) {
    Actor* heldActor = PLAYER->heldActor;

    if (func_8004356C(&this->actor)) {
        if (heldActor != NULL && heldActor->id == ACTOR_EN_RU1) {
            if (this->unk_1D8 <= 0) {
                func_8086D944(this);
                func_8086D4B4(this, globalCtx);
            }
        } else {
            this->unk_1D8 = 6;
        }
    } else {
        if (this->unk_1D8 <= 0) {
            func_8086DAB4(this);
        }
    }
}

void func_8086DAB4(BgBdanSwitch* this) {
    this->updateFunc = &func_8086DAC4;
}

void func_8086DAC4(BgBdanSwitch* this, GlobalContext* globalCtx) {
    this->unk_1C8 += 0.2f;
    if (this->unk_1C8 >= 1.0f) {
        func_8086D86C(this);
        Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
    }
}

void func_8086DB24(BgBdanSwitch* this) {
    this->unk_1C8 = 0.1f;
    this->updateFunc = &func_8086DB40;
}

void func_8086DB40(BgBdanSwitch* this, GlobalContext* globalCtx) {
}

void func_8086DB4C(BgBdanSwitch* this) {
    this->updateFunc = &func_8086DB68;
    this->unk_1C8 = 2.0f;
}

void func_8086DB68(BgBdanSwitch* this, GlobalContext* globalCtx) {
    switch (this->actor.params & 0xFF) {
        default:
            return;
        case YELLOW_TALL_1:
            if (((this->collider.base.acFlags & 2) != 0) && this->unk_1D8 <= 0) {
                this->unk_1D8 = 0xA;
                func_8086DC30(this);
                func_8086D4B4(this, globalCtx);
            }
            break;
        case YELLOW_TALL_2:
            if (((this->collider.base.acFlags & 2) != 0) && ((this->unk_1DC & 2) == 0) && this->unk_1D8 <= 0) {
                this->unk_1D8 = 0xA;
                func_8086DC30(this);
                func_8086D4B4(this, globalCtx);
            }
    }
}

void func_8086DC30(BgBdanSwitch* this) {
    this->updateFunc = &func_8086DC48;
    this->unk_1DA = 0x64;
}

void func_8086DC48(BgBdanSwitch* this, GlobalContext* globalCtx) {
    if ((func_8005B198() == this->actor.type) || (this->unk_1DA <= 0)) {
        this->unk_1C8 -= 0.3f;
        if (this->unk_1C8 <= 1.0f) {
            func_8086DCCC(this);
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
        }
    }
}

void func_8086DCCC(BgBdanSwitch* this) {
    this->updateFunc = &func_8086DCE8;
    this->unk_1C8 = 1.0f;
}

void func_8086DCE8(BgBdanSwitch* this, GlobalContext* globalCtx) {
    switch (this->actor.params & 0xFF) {
        case YELLOW_TALL_1:
            if (!Flags_GetSwitch(globalCtx, (this->actor.params >> 8) & 0x3F)) {
                func_8086DDA8(this);
            }
            break;
        case YELLOW_TALL_2:
            if (((this->collider.base.acFlags & 2) != 0) && ((this->unk_1DC & 2) == 0) && (this->unk_1D8 <= 0)) {
                this->unk_1D8 = 0xA;
                func_8086DDA8(this);
                func_8086D548(this, globalCtx);
            }
    }
}

void func_8086DDA8(BgBdanSwitch* this) {
    this->updateFunc = &func_8086DDC0;
    this->unk_1DA = 0x64;
}

void func_8086DDC0(BgBdanSwitch* this, GlobalContext* globalCtx) {
    if ((((this->actor.params & 0xFF) != YELLOW_TALL_2) || (func_8005B198() == this->actor.type)) ||
        (this->unk_1DA <= 0)) {
        this->unk_1C8 += 0.3f;
        if (this->unk_1C8 >= 2.0f) {
            func_8086DB4C(this);
            Audio_PlayActorSound2(&this->actor, NA_SE_EV_FOOT_SWITCH);
        }
    }
}

void BgBdanSwitch_Update(BgBdanSwitch* this, GlobalContext* globalCtx) {
    s32 pad;
    s32 type;
    s32 pad2;

    if (this->unk_1DA > 0) {
        this->unk_1DA -= 1;
    }
    this->updateFunc(this, globalCtx);
    func_8086D0EC(this);
    type = this->actor.params & 0xFF;
    if (type != 3 && type != 4) {
        this->unk_1D8 -= 1;
        return;
    }
    if (!func_8008E988(globalCtx) && this->unk_1D8 > 0) {
        this->unk_1D8 -= 1;
    }
    pad = this->collider.base.acFlags;
    this->collider.base.acFlags &= 0xFFFD;
    this->unk_1DC = pad;
    this->collider.list[0].dim.modelSphere.radius = this->unk_1D4 * 370.0f;
    CollisionCheck_SetAC(globalCtx, &globalCtx->colChkCtx, &this->collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, &this->collider);
}

void func_8086DF58(BgBdanSwitch* this, GlobalContext* globalCtx, UNK_TYPE arg2) {
    func_800D1694(this->actor.posRot.pos.x, this->actor.posRot.pos.y + (this->actor.shape.unk_08 * this->unk_1D0),
                  this->actor.posRot.pos.z, &this->actor.shape.rot);
    Matrix_Scale(this->unk_1D4, this->unk_1D0, this->unk_1D4, MTXMODE_APPLY);
    Gfx_DrawDListOpa(globalCtx, arg2);
}

void BgBdanSwitch_Draw(BgBdanSwitch* this, GlobalContext* globalCtx) {
    switch (this->actor.params & 0xFF) {
        case YELLOW_HEAVY:
        case YELLOW:
            func_8086DF58(this, globalCtx, &D_060061A0);
            break;
        case YELLOW_TALL_1:
        case YELLOW_TALL_2:
            func_8086DF58(this, globalCtx, &D_060061A0);
            func_800628A4(0, &this->collider);
            Matrix_MultVec3f(&D_8086E0E0, &this->actor.posRot2);
            break;
        case BLUE:
            func_8086DF58(this, globalCtx, &D_06005A20);
    }
}
