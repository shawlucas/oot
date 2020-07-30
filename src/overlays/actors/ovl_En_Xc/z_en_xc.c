/*
 * File: z_en_xc.c
 * Overlay: ovl_En_Xc
 * Description: Sheik
 */

#include "z_en_xc.h"

#define FLAGS 0x00000010

#define THIS ((EnXc*)thisx)

void EnXc_Init(Actor* thisx, GlobalContext* globalCtx);
void EnXc_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnXc_Update(Actor* thisx, GlobalContext* globalCtx);
void EnXc_Draw(Actor* thisx, GlobalContext* globalCtx);
s32 func_80B3E8AC(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx);


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
    func_80B41B98,
    func_80B41BA4,
    func_80B3E908,
    func_80B3EA7C,
    func_80B402C4,
    func_80B414AC,
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

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C1E0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C22C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/EnXc_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C298.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C31C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C3A4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C468.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C4B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C4D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C4F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C53C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3C588.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CA38.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CA84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CB58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CBA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CD00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CD98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CE78.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CE84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CF04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3CF90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D014.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D118.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D158.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D298.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D338.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D3B0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D3F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D48C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D4D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D56C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D644.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D664.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D6F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D710.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D730.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3D750.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E224.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E25C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E294.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E30C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E368.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E3C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E420.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E4AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E4F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E53C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E580.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E5C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E610.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E668.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E6D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E738.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E7A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E804.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E85C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E87C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E8AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E8E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3E908.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EA7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EBF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EC00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EC0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EC90.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ECD8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ED48.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ED68.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3ED88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EDCC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE28.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE40.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE4C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3EE64.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F3C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B3F3D8.s")

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

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/EnXc_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/EnXc_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41A88.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41B0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41B98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/func_80B41BA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Xc/EnXc_Draw.s")
