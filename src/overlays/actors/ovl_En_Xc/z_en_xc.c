/*
 * File: z_en_xc.c
 * Overlay: ovl_En_Xc
 * Description: Sheik
 */

#include "z_en_xc.h"
#include "vt.h"

#define FLAGS 0x00000010

#define THIS ((EnXc*)thisx)

void EnXc_Init(Actor* thisx, GlobalContext* globalCtx);
void EnXc_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnXc_Update(Actor* thisx, GlobalContext* globalCtx);
void EnXc_Draw(Actor* thisx, GlobalContext* globalCtx);
s32 func_80B3E8AC(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);

void func_80B3C298(EnXc* this, GlobalContext* globalCtx);
void func_80B3C31C(EnXc* this);
void func_80B3C468(EnXc* this, GlobalContext* globalCtx);
s32 func_80B3C4B0(EnXc* this);
CsCmdActorAction* func_80B3C4D0(GlobalContext* globalCtx, s32 npcActionIdx);
s32 func_80B3C4F0(EnXc* this, GlobalContext* globalCtx, u16 arg2, s32 npcActionIdx);
s32 func_80B3C53C(EnXc* this, GlobalContext* globalCtx, u16 arg2, s32 npcActionIdx);
void func_80B3C588(EnXc* this, GlobalContext* globalCtx, u32 npcActionIdx);
s32 func_80B3CA84(EnXc* this, GlobalContext* globalCtx);
void func_80B3CB58(EnXc* this, GlobalContext* globalCtx);
s32 func_80B3CBA4(EnXc* this, GlobalContext* globalCtx);
void func_80B3CD00(EnXc* this, GlobalContext* globalCtx);
s32 func_80B3CD98(EnXc* this, GlobalContext* globalCtx);
void func_80B3CE78(EnXc* this, GlobalContext* globalCtx);
void func_80B3CE84(EnXc* this, GlobalContext* globalCtx);
void func_80B3CF04(EnXc* this, GlobalContext* globalCtx);
void func_80B3CF90(EnXc* this, GlobalContext* globalCtx);
void func_80B3D014(EnXc* this, GlobalContext* globalCtx);
void func_80B3D118(GlobalContext* globalCtx);
void func_80B3D644(EnXc* this);
void func_80B3D664(EnXc* this);
void func_80B3D6F0(EnXc* this);
void func_80B3D710(EnXc* this);
void func_80B3D730(EnXc* this);
void func_80B3D750(EnXc* this, GlobalContext* globalCtx);
void func_80B3D794(EnXc* this, GlobalContext* globalCtx);
void func_80B3D8A4(EnXc* this, GlobalContext* globalCtx, s32 arg2);
void func_80B3DEF4(EnXc* this, GlobalContext* globalCtx);
void func_80B3E224(EnXc* this, GlobalContext* globalCtx);
void func_80B3E25C(EnXc* this, GlobalContext* globalCtx);
void func_80B3E294(EnXc* this, GlobalContext* globalCtx);
void func_80B3E30C(EnXc* this, GlobalContext* globalCtx);
void func_80B3E368(EnXc* this, GlobalContext* globalCtx);
void func_80B3E3C4(EnXc* this, GlobalContext* globalCtx);
void func_80B3E420(EnXc* this, GlobalContext* globalCtx);
void func_80B3E464(EnXc* this, GlobalContext* globalCtx);
void func_80B3E4AC(EnXc* this, GlobalContext* globalCtx);
void func_80B3E4F8(EnXc* this, GlobalContext* globalCtx);
void func_80B3E53C(EnXc* this, GlobalContext* globalCtx);
void func_80B3E580(EnXc* this, GlobalContext* globalCtx);
void func_80B3E5C8(EnXc* this, GlobalContext* globalCtx);
void func_80B3E610(EnXc* this, GlobalContext* globalCtx);
void func_80B3E668(EnXc* this, GlobalContext* globalCtx);
void func_80B3E6D0(EnXc* this, GlobalContext* globalCtx);
void func_80B3E738(EnXc* this, GlobalContext* globalCtx);
void func_80B3E7A0(EnXc* this, GlobalContext* globalCtx);
void func_80B3E804(EnXc* this, GlobalContext* globalCtx);
void func_80B3E85C(EnXc* this, GlobalContext* globalCtx);
void func_80B3ED48(EnXc* this, GlobalContext* globalCtx);
void func_80B3ED68(EnXc* this, GlobalContext* globalCtx);
void func_80B3ED88(EnXc* this, GlobalContext* globalCtx);
void func_80B3EDCC(EnXc* this, GlobalContext* globalCtx);
void func_80B3EE28(EnXc* this, GlobalContext* globalCtx);
void func_80B3EE34(EnXc* this, GlobalContext* globalCtx);
void func_80B3EE40(EnXc* this, GlobalContext* globalCtx);
void func_80B3EE4C(EnXc* this, GlobalContext* globalCtx);
void func_80B3EE58(EnXc* this, GlobalContext* globalCtx);
void func_80B3EE64(EnXc* this, GlobalContext* globalCtx);
void func_80B3F124(EnXc* this, GlobalContext* globalCtx);
void func_80B3F144(EnXc* this, GlobalContext* globalCtx);
void func_80B3F16C(EnXc* this, GlobalContext* globalCtx);
void func_80B3F1A8(EnXc* this, GlobalContext* globalCtx);
void func_80B3F1D0(EnXc* this, GlobalContext* globalCtx);
void func_80B3F1F8(EnXc* this, GlobalContext* globalCtx);
void func_80B3F220(EnXc* this, GlobalContext* globalCtx);
void func_80B3F248(EnXc* this, GlobalContext* globalCtx);
void func_80B3F270(EnXc* this, GlobalContext* globalCtx);
void func_80B3F298(EnXc* this, GlobalContext* globalCtx);
void func_80B3F2C0(EnXc* this, GlobalContext* globalCtx);
void func_80B3F2E8(EnXc* this, GlobalContext* globalCtx);
void func_80B3F344(EnXc* this, GlobalContext* globalCtx);
void func_80B3F36C(EnXc* this, GlobalContext* globalCtx);
void func_80B3F394(EnXc* this, GlobalContext* globalCtx);
void func_80B3F3BC(EnXc* this, GlobalContext* globalCtx);
void func_80B3F3C8(EnXc* this, GlobalContext* globalCtx);
void func_80B3F3D8();
void func_80B3F7F8(EnXc* this, GlobalContext* globalCtx);
void func_80B3F820(EnXc* this, GlobalContext* globalCtx);
void func_80B3F848(EnXc* this, GlobalContext* globalCtx);
void func_80B3F8A0(EnXc* this, GlobalContext* globalCtx);
void func_80B3F8C8(EnXc* this, GlobalContext* globalCtx);
void func_80B3F928(EnXc* this, GlobalContext* globalCtx);
void func_80B3F988(EnXc* this, GlobalContext* globalCtx);
void func_80B3F9E8(EnXc* this, GlobalContext* globalCtx);
void func_80B400E4(EnXc* this, GlobalContext* globalCtx);
void func_80B40104(EnXc* this, GlobalContext* globalCtx);
void func_80B4015C(EnXc* this, GlobalContext* globalCtx);
void func_80B401CC(EnXc* this, GlobalContext* globalCtx);
void func_80B41000(EnXc* this, GlobalContext* globalCtx);
void func_80B41020(EnXc* this, GlobalContext* globalCtx);
void func_80B41068(EnXc* this, GlobalContext* globalCtx);
void func_80B410AC(EnXc* this, GlobalContext* globalCtx);
void func_80B41110(EnXc* this, GlobalContext* globalCtx);
void func_80B41174(EnXc* this, GlobalContext* globalCtx);
void func_80B411AC(EnXc* this, GlobalContext* globalCtx);
void func_80B41204(EnXc* this, GlobalContext* globalCtx);
void func_80B41248(EnXc* this, GlobalContext* globalCtx);
void func_80B41284(EnXc* this, GlobalContext* globalCtx);
void func_80B412AC(EnXc* this, GlobalContext* globalCtx);
void func_80B412D4(EnXc* this, GlobalContext* globalCtx);
void func_80B412FC(EnXc* this, GlobalContext* globalCtx);
void func_80B41324(EnXc* this, GlobalContext* globalCtx);
void func_80B4134C(EnXc* this, GlobalContext* globalCtx);
void func_80B41374(EnXc* this, GlobalContext* globalCtx);
void func_80B4139C(EnXc* this, GlobalContext* globalCtx);
void func_80B413C4(EnXc* this, GlobalContext* globalCtx);
void func_80B41414(EnXc* this, GlobalContext* globalCtx);
void func_80B4143C(EnXc* this, GlobalContext* globalCtx);
void func_80B41464(EnXc* this, GlobalContext* globalCtx);
void func_80B4148C(EnXc* this, GlobalContext* globalCtx);
void func_80B417E4(EnXc* this, GlobalContext* globalCtx);
void func_80B41844(EnXc* this, GlobalContext* globalCtx);

void func_80B41B98(EnXc* this, GlobalContext* globalCtx);
void func_80B3E908(EnXc* this, GlobalContext* globalCtx);
void func_80B41BA4(EnXc* this, GlobalContext* globalCtx);
void func_80B3EA7C(EnXc* this, GlobalContext* globalCtx);
void func_80B402C4(EnXc* this, GlobalContext* globalCtx);
void func_80B414AC(EnXc* this, GlobalContext* globalCtx);

void func_80B3EBF0(EnXc* this, GlobalContext* globalCtx);
void func_80B3EC00(EnXc* this);

s32 func_80B3E8E4(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);
void func_80B3E87C(Gfx** dList, EnXc* this);

extern SkeletonHeader D_06012AF0;
extern AnimationHeader D_06004828;
extern Gfx D_06011150[];
extern CutsceneCmd D_02003F80[];
extern CutsceneCmd D_020045D0[];
extern CutsceneCmd D_02000330[];
extern AnimationHeader D_0601C0E8;

ColliderCylinderInit_Set3 D_80B41D40 = {
    { COLTYPE_UNK0, 0x00, 0x00, 0x09, COLSHAPE_CYLINDER },
    { 0x00, { 0x00000000, 0x00, 0x00 }, { 0x00000000, 0x00, 0x00 }, 0x00, 0x00, 0x01 },
    { 25, 80, 0, { 0, 0, 0 } },
};

UNK_PTR D_80B41D6C[] = {
    0x06004CC0,
    0x060050C0,
    0x060054C0,
};

Vec3f D_80B41D78 = { -611.0f, 728.0f, -2.0f };

Vec3f D_80B41D84 = { -1069.0f, 38.0f, 0.0f };

s32 D_80B41D90 = 0x00000000;

Vec3f D_80B41D94 = { 0.0f, 0.0f, 0.0f };

f32 D_80B41DA0 = 0.0f;

s32 D_80B41DA4 = 0x00000000;

s32 D_80B41DA8 = 0x00000001;

s32 D_80B41DAC = 0x00000001;

Vec3f D_80B41DB0 = { 0.0f, 0.0f, 0.0f };

Vec3f D_80B41DBC = { 0.0f, 0.0f, 0.0f };

EnXcActionFunc D_80B41DC8[] = {
    func_80B3E224, func_80B3E25C, func_80B3E294, func_80B3E30C, func_80B3E368, func_80B3E3C4, func_80B3E420,
    func_80B3E464, func_80B3E4AC, func_80B3E4F8, func_80B3E53C, func_80B3E580, func_80B3E5C8, func_80B3E610,
    func_80B3E668, func_80B3E6D0, func_80B3E738, func_80B3E7A0, func_80B3E804, func_80B3E85C, func_80B3ED48,
    func_80B3ED68, func_80B3ED88, func_80B3EDCC, func_80B3EE28, func_80B3EE34, func_80B3EE40, func_80B3EE4C,
    func_80B3EE58, func_80B3F124, func_80B3F144, func_80B3F16C, func_80B3F1A8, func_80B3F1D0, func_80B3F1F8,
    func_80B3F220, func_80B3F248, func_80B3F270, func_80B3F298, func_80B3F2C0, func_80B3F2E8, func_80B3F344,
    func_80B3F36C, func_80B3F394, func_80B3F3BC, func_80B3F7F8, func_80B3F820, func_80B3F848, func_80B3F8A0,
    func_80B3F8C8, func_80B3F928, func_80B3F988, func_80B3F9E8, func_80B400E4, func_80B40104, func_80B4015C,
    func_80B401CC, func_80B41000, func_80B41020, func_80B41068, func_80B410AC, func_80B41110, func_80B41174,
    func_80B411AC, func_80B41204, func_80B41248, func_80B41284, func_80B412AC, func_80B412D4, func_80B412FC,
    func_80B41324, func_80B4134C, func_80B41374, func_80B4139C, func_80B413C4, func_80B41414, func_80B4143C,
    func_80B41464, func_80B4148C, func_80B417E4, func_80B41844,
};

Vec3f D_80B41F0C = { 0.0f, 10.0f, 0.0f };

EnXcDrawFunc D_80B41F18[] = {
    func_80B41B98, func_80B41BA4, func_80B3E908, func_80B3EA7C, func_80B402C4, func_80B414AC,
};

const ActorInit En_Xc_InitVars = {
    ACTOR_EN_XC,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_XC,
    sizeof(EnXc),
    (ActorFunc)EnXc_Init,
    (ActorFunc)EnXc_Destroy,
    (ActorFunc)EnXc_Update,
    (ActorFunc)EnXc_Draw,
};

Vec3f D_80B42D90;

Vec3f D_80B42DA0;

Vec3f D_80B42DB0;

void func_80B3C1E0(Actor* thisx, GlobalContext* globalCtx) {
    EnXc* this = THIS;
    Collider_InitCylinder(globalCtx, &this->collider);
    Collider_SetCylinder_Set3(globalCtx, &this->collider, &this->actor, &D_80B41D40);
}

void func_80B3C22C(EnXc* this, GlobalContext* globalCtx) {
    s32 pad;
    ColliderCylinder* collider = &this->collider;
    Actor* thisx = &this->actor;
    s32 pad2[2];

    Collider_CylinderUpdate(thisx, collider);
    CollisionCheck_SetOC(globalCtx, &globalCtx->colChkCtx, collider);
}

void EnXc_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    EnXc* this = THIS;

    Collider_DestroyCylinder(globalCtx, &this->collider);
}

void func_80B3C298(EnXc* this, GlobalContext* globalCtx) {
    Player* player = PLAYER;

    this->struct_314.unk_18 = player->actor.posRot.pos;
    this->struct_314.unk_14 = kREG(16) - 3.0f;
    func_80034A14(&this->actor, &this->struct_314, kREG(17) + 0xC, 2);
}

void func_80B3C31C(EnXc* this) {
    s32 pad[3];
    s16* unk_25E = &this->unk_25E;
    s16* unk_25C = &this->unk_25C;

    if (!DECR(*unk_25E)) {
        *unk_25E = Math_Rand_S16Offset(60, 60);
    }

    *unk_25C = *unk_25E;
    if (*unk_25C >= 3) {
        *unk_25C = 0;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C3A4.s")

void func_80B3C468(EnXc* this, GlobalContext* globalCtx) {
    func_8002E4B4(globalCtx, &this->actor, 75.0f, 30.0f, 30.0f, 4);
}

s32 func_80B3C4B0(EnXc* this) {
    return SkelAnime_FrameUpdateMatrix(&this->skelAnime);
}

CsCmdActorAction* func_80B3C4D0(GlobalContext* globalCtx, s32 npcActionIdx) {
    CsCmdActorAction* action = NULL;
    if (globalCtx->csCtx.state != 0) {
        action = globalCtx->csCtx.npcActions[npcActionIdx];
    }
    return action;
}

s32 func_80B3C4F0(EnXc* this, GlobalContext* globalCtx, u16 arg2, s32 npcActionIdx) {
    CsCmdActorAction* csCmdActorAction = func_80B3C4D0(globalCtx, npcActionIdx);

    if (csCmdActorAction && csCmdActorAction->action == arg2) {
        return 1;
    }
    return 0;
}

s32 func_80B3C53C(EnXc* this, GlobalContext* globalCtx, u16 arg2, s32 npcActionIdx) {
    CsCmdActorAction* csCmdNPCAction = func_80B3C4D0(globalCtx, npcActionIdx);

    if (csCmdNPCAction && csCmdNPCAction->action != arg2) {
        return 1;
    }
    return 0;
}

void func_80B3C588(EnXc* this, GlobalContext* globalCtx, u32 npcActionIdx) {
    CsCmdActorAction* csCmdNPCAction = func_80B3C4D0(globalCtx, npcActionIdx);
    Actor* thisx = &this->actor;

    if (csCmdNPCAction) {
        thisx->posRot.pos.x = csCmdNPCAction->startPos.x;
        thisx->posRot.pos.y = csCmdNPCAction->startPos.y;
        thisx->posRot.pos.z = csCmdNPCAction->startPos.z;
        thisx->posRot.rot.x = thisx->shape.rot.x = csCmdNPCAction->rot.x;
        thisx->posRot.rot.y = thisx->shape.rot.y = csCmdNPCAction->rot.y;
        thisx->posRot.rot.z = thisx->shape.rot.z = csCmdNPCAction->rot.z;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C620.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C700.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C7BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C7D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C800.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C820.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C888.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C8CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C924.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C964.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C9DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C9EC.s")

void func_80B3CA38(EnXc* this, GlobalContext* globalCtx) {
    if (!(gSaveContext.eventChkInf[5] & 1) && LINK_IS_ADULT) {
        this->action = 0;
    } else {
        Actor_Kill(&this->actor);
    }
}

s32 func_80B3CA84(EnXc* this, GlobalContext* globalCtx) {

    if (this->actor.params == 6) {
        Player* player = PLAYER;
        f32 z = player->actor.posRot.pos.z;
        if (z < -2225.0f) {
            if (Gameplay_InCsMode(globalCtx) == 0) {
                globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(&D_02003F80);
                gSaveContext.cutsceneTrigger = 1;
                gSaveContext.eventChkInf[5] |= 1;
                Item_Give(globalCtx, ITEM_SONG_MINUET);
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

void func_80B3CB58(EnXc* this, GlobalContext* globalCtx) {
    if (!(gSaveContext.eventChkInf[5] & 2) && LINK_IS_ADULT) {
        this->action = 0;
    } else {
        Actor_Kill(&this->actor);
    }
}

s32 func_80B3CBA4(EnXc* this, GlobalContext* globalCtx) {
    Player* player;
    PosRot* posRot;

    if (this->actor.params == 7) {
        player = PLAYER;
        posRot = &player->actor.posRot;
        if ((posRot->pos.x > -784.0f) && (posRot->pos.x < -584.0f) && (posRot->pos.y > 447.0f) &&
            (posRot->pos.y < 647.0f) && (posRot->pos.z > -446.0f) && (posRot->pos.z < -246.0f) &&
            (Gameplay_InCsMode(globalCtx) == 0)) {
            globalCtx->csCtx.segment = SEGMENTED_TO_VIRTUAL(&D_020045D0);
            gSaveContext.cutsceneTrigger = 1;
            gSaveContext.eventChkInf[5] |= 2;
            Item_Give(globalCtx, ITEM_SONG_BOLERO);
            return 1;
        }
        return 0;
    }
    return 1;
}

void func_80B3CD00(EnXc* this, GlobalContext* globalCtx) {
    if (!CHECK_OWNED_EQUIP(EQUIP_BOOTS, 1)) {
        if (!(gSaveContext.eventChkInf[5] & 4)) {
            if (LINK_IS_ADULT) {
                this->action = 29;
                osSyncPrintf("水のセレナーデ シーク誕生!!!!!!!!!!!!!!!!!!\n");
                return;
            }
        }
    }
    Actor_Kill(&this->actor);
    osSyncPrintf("水のセレナーデ シーク消滅!!!!!!!!!!!!!!!!!!\n");
}

s32 func_80B3CD98(EnXc* this, GlobalContext* globalCtx) {
    if (this->actor.params == 8) {
        Player* player = PLAYER;
        s32 stateFlags = player->stateFlags1;
        if (CHECK_OWNED_EQUIP(EQUIP_BOOTS, 1)) {
            if (!(gSaveContext.eventChkInf[5] & 4)) {
                if ((stateFlags << 2) >= 0) {
                    if (Gameplay_InCsMode(globalCtx) == 0) {
                        Cutscene_SetSegment(globalCtx, &D_02000330);
                        gSaveContext.cutsceneTrigger = 1;
                        gSaveContext.eventChkInf[5] |= 4;
                        Item_Give(globalCtx, ITEM_SONG_SERENADE);
                        osSyncPrintf("ブーツを取った!!!!!!!!!!!!!!!!!!\n");
                        return 1;
                    }
                }
            }
        }
        osSyncPrintf("はやくブーツを取るべし!!!!!!!!!!!!!!!!!!\n");
        return 0;
    }
    return 1;
}

void func_80B3CE78(EnXc* this, GlobalContext* globalCtx) {
}

void func_80B3CE84(EnXc* this, GlobalContext* globalCtx) {

    s32 pad[2];
    u32 sfxId;
    s32 pad2;
    if ((func_800A56C8(&this->skelAnime, 11.0f) != 0) || (func_800A56C8(&this->skelAnime, 23.0f) != 0)) {
        if (this->actor.bgCheckFlags & 1) {
            sfxId = SFX_FLAG;
            sfxId += func_80041F34(&globalCtx->colCtx, this->actor.floorPoly, this->actor.floorPolySource);
            func_80078914(&this->actor.projectedPos, sfxId);
        }
    }
}

void func_80B3CF04(EnXc* this, GlobalContext* globalCtx) {
    s32 pad[2];
    u32 sfxId;
    s32 pad2;
    if (func_800A56C8(&this->skelAnime, 7.0f) != 0) {
        if (this->actor.bgCheckFlags & 1) {
            sfxId = SFX_FLAG;
            sfxId += func_80041F34(&globalCtx->colCtx, this->actor.floorPoly, this->actor.floorPolySource);
            func_80078914(&this->actor.projectedPos, sfxId);
        }
    }
    if (func_800A56C8(&this->skelAnime, 20.0f) != 0) {
        func_80078914(&this->actor.projectedPos, NA_SE_VO_SK_SHOUT);
    }
}

void func_80B3CF90(EnXc* this, GlobalContext* globalCtx) {
    u32 sfxId;
    s16 sceneNum = globalCtx->sceneNum;
    if ((gSaveContext.sceneSetupIndex != 4) || (sceneNum != SCENE_SPOT11)) {
        if (func_800A56C8(&this->skelAnime, 11.0f) != 0) {
            sfxId = SFX_FLAG;
            sfxId += func_80041F34(&globalCtx->colCtx, this->actor.floorPoly, this->actor.floorPolySource);
            func_80078914(&this->actor.projectedPos, sfxId);
        }
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D014.s")

void func_80B3D118(GlobalContext* globalCtx) {
    s16 sceneNum;
    if ((gSaveContext.sceneSetupIndex != 4) || (sceneNum = globalCtx->sceneNum, sceneNum != SCENE_SPOT11)) {
        func_800788CC(NA_SE_PL_SKIP);
    }
}

#ifdef NON_EQUIVALENT
void func_80B3D158(GlobalContext* globalCtx) {
    f32 dist;
    f32 clampMin;
    f32 clampMax;
    Vec3f* eye = &globalCtx->view.eye;
    s16 sceneNum = globalCtx->sceneNum;
    if (gSaveContext.sceneSetupIndex == 4) {
        if (sceneNum == SCENE_SPOT11) {
            if (globalCtx->csCtx.frames >= 120) {
                if (globalCtx->csCtx.frames < 164) {
                    if (D_80B41D90 != 0) {
                        dist = Math3D_Vec3f_DistXYZ(&D_80B42DB0, eye) / 7.058922f;
                        clampMin = CLAMP_MIN(D_80B41DA0, dist);
                        osSyncPrintf("MAX speed = %f\n", clampMin);
                        clampMax = CLAMP_MAX(dist, 2.0f);
                        func_800F436C(&D_80B41D94, NA_SE_EV_FLYING_AIR - SFX_FLAG, (0.4f * clampMax) + 0.6f);
                    }
                    D_80B42DB0.x = eye->x;
                    D_80B42DB0.y = eye->y;
                    D_80B42DB0.z = eye->z;
                    D_80B41D90 = 1;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D158.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D298.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D338.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D3B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D3F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D48C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D4D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D56C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D644.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D664.s")

void func_80B3D6F0(EnXc* this) {
    func_80B3D56C(this);
}

void func_80B3D710(EnXc* this) {
    Actor_MoveForward(&this->actor);
}

void func_80B3D730(EnXc* this) {
    func_80B3D664(this);
}

void func_80B3D750(EnXc* this, GlobalContext* globalCtx) {
    if (func_80B3CA84(this, globalCtx) != 0 && func_80B3CBA4(this, globalCtx) != 0) {
        this->action = 1;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D794.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D8A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D990.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DA00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DAA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DAF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DBAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DC24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DCA8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DD3C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DE00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DE78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DEF4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3DFA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E014.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E0BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E164.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E1B8.s")

void func_80B3E224(EnXc* this, GlobalContext* globalCtx) {
    func_80B3D014(this, globalCtx);
    func_80B3D158(globalCtx);
    func_80B3D750(this, globalCtx);
}

void func_80B3E25C(EnXc* this, GlobalContext* globalCtx) {
    func_80B3D014(this, globalCtx);
    func_80B3D158(globalCtx);
    func_80B3D794(this, globalCtx);
}

void func_80B3E294(EnXc* this, GlobalContext* globalCtx) {
    s32 unk = func_80B3C4B0(this);

    func_80B3C468(this, globalCtx);
    func_80B3C31C(this);
    func_80B3CF90(this, globalCtx);
    func_80B3D014(this, globalCtx);
    func_80B3D158(globalCtx);
    func_80B3D8A4(this, globalCtx, unk);
}

void func_80B3E30C(EnXc* this, GlobalContext* globalCtx) {
    func_80B3D56C(this);
    func_80B3C4B0(this);
    func_80B3C468(this, globalCtx);
    func_80B3C31C(this);
    func_80B3CE84(this, globalCtx);
    func_80B3D990(this);
}

void func_80B3E368(EnXc* this, GlobalContext* globalCtx) {
    func_80B3D644(this);
    func_80B3C4B0(this);
    func_80B3C468(this, globalCtx);
    func_80B3C31C(this);
    func_80B3CE84(this, globalCtx);
    func_80B3DA00(this);
}
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E3C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E420.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E4AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E4F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E53C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E580.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E5C8.s")

void func_80B3E610(EnXc* this, GlobalContext* globalCtx) {
    func_80B3C4B0(this);
    func_80B3C468(this, globalCtx);
    func_80B3C31C(this);
    func_80B3D3F0(this, globalCtx);
    func_80B3DEF4(this, globalCtx);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E668.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E6D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E738.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E7A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E804.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E85C.s")

void func_80B3E87C(Gfx** dList, EnXc* this) {
    f32 currentFrame = this->skelAnime.animCurrentFrame;

    if (currentFrame >= 34.0f) {
        *dList = &D_06011150;
    }
}
s32 func_80B3E8AC(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    EnXc* this = THIS;

    if (limbIndex == 12) {
        func_80B3E87C(dList, this);
    }

    return 0;
}

s32 func_80B3E8E4(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    EnXc* this = THIS;

    if (limbIndex == 12) {
        *dList = &D_06011150;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E908.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EA7C.s")

void func_80B3EBF0(EnXc* this, GlobalContext* globalCtx) {
    this->action = 20;
}

void func_80B3EC00(EnXc* this) {
    this->action = 21;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EC0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EC90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ECD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ED48.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ED68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ED88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EDCC.s")

void func_80B3EE28(EnXc* this, GlobalContext* globalCtx) {
}

void func_80B3EE34(EnXc* this, GlobalContext* globalCtx) {
}

void func_80B3EE40(EnXc* this, GlobalContext* globalCtx) {
}

void func_80B3EE4C(EnXc* this, GlobalContext* globalCtx) {
}

void func_80B3EE58(EnXc* this, GlobalContext* globalCtx) {
}

void func_80B3EE64(EnXc* this, GlobalContext* globalCtx) {
    this->action = 29;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EEA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EEC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EEEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EF10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EF34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EF58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EF80.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EFA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EFC8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EFEC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F010.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F0B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F0DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F100.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F124.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F144.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F16C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F1A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F1D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F1F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F220.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F248.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F270.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F298.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F2C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F2E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F344.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F36C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F394.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F3BC.s")

void func_80B3F3C8(EnXc* this, GlobalContext* globalCtx) {
    this->action = 45;
}

void func_80B3F3D8() {
    func_800788CC(NA_SE_PL_SKIP);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F3F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F44C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F534.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F59C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F620.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F644.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F668.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F6DC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F700.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F754.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F7BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F7F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F820.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F848.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F8A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F8C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F928.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F988.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F9E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FA08.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FA2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FA4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FAE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FB24.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FF0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3FFB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40040.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B400AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B400E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40104.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4015C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B401CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40224.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40248.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B402C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40590.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B405A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4066C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B406A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B406F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4070C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B407A8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40820.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B408FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B409D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40A78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40B18.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40BB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40C50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40C74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40C98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40CBC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40CE0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40D08.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40D2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40D50.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40D74.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40D98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40E40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40E64.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40E88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B40EAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41000.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41020.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41068.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B410AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41110.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41174.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B411AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41204.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41248.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41284.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B412AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B412D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B412FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41324.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4134C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41374.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4139C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B413C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41414.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4143C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B4148C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B414AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B415B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41718.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41798.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B417E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41844.s")

void EnXc_Update(Actor* thisx, GlobalContext* globalCtx) {
    EnXc* this = THIS;
    s32 action = this->action;
    if ((action < 0) || (action >= 0x51) || (D_80B41DC8[action] == NULL)) {
        osSyncPrintf(VT_FGCOL(RED) "メインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
    } else {
        D_80B41DC8[action](this, globalCtx);
    }
}

void EnXc_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnXc* this = THIS;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawFunc_Circle, 30.0f);
    SkelAnime_InitSV(globalCtx, &this->skelAnime, &D_06012AF0, &D_06004828, &this->limbDrawTable,
                     &this->transitionDrawTable, 17);
    func_80B3C1E0(this, globalCtx);
    switch (this->actor.params) {
        case 1:
            func_80B3EBF0(this, globalCtx);
            break;
        case 2:
            func_80B3EE64(this, globalCtx);
            break;
        case 3:
            func_80B3F3C8(this, globalCtx);
            break;
        case 4:
            func_80B3FA08(this, globalCtx);
            break;
        case 5:
            func_80B40590(this, globalCtx);
            break;
        case 6:
            func_80B3CA38(this, globalCtx);
            break;
        case 7:
            func_80B3CB58(this, globalCtx);
            break;
        case 8:
            func_80B3CD00(this, globalCtx);
            break;
        case 9:
            func_80B415B8(this, globalCtx);
            break;
        case 0:
            func_80B3CE78(this, globalCtx);
            break;
        default:
            osSyncPrintf(VT_FGCOL(RED) " En_Oa2 の arg_data がおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n" VT_RST);
            func_80B3CE78(this, globalCtx);
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41A88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41B0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41B98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41BA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/EnXc_Draw.s")
