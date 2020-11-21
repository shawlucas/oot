#include "z_en_fr.h"

#define FLAGS 0x02000019

#define THIS ((EnFr*)thisx)

void EnFr_Init(Actor* thisx, GlobalContext* globalCtx);
void EnFr_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnFr_Update(Actor* thisx, GlobalContext* globalCtx);
void func_80A1CB58(Actor* thisx, GlobalContext* globalCtx);

void func_80A1BCB4(EnFr* this, GlobalContext* globalCtx);
void func_80A1BD94(EnFr* this, GlobalContext* globalCtx);
void func_80A1BDFC(EnFr* this, GlobalContext* globalCtx);
void func_80A1C1E4(EnFr* this, GlobalContext* globalCtx);
void func_80A1C400(EnFr* this, GlobalContext* globalCtx);
void func_80A1C580(EnFr* this, GlobalContext* globalCtx);

FrogInfo D_80A1CFF0 = { 0, NULL, NULL, NULL, NULL, NULL };

u16 D_80A1D008[] = { 2, 4, 16, 8, 32, 64, 1 };

u8 D_80A1D018[] = { 2, 3, 4, 0, 1 };

s32 D_80A1D020[] = { 3, 4, 0, 1, 2 };

const ActorInit En_Fr_InitVars = {
    ACTOR_EN_FR,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_FR,
    sizeof(EnFr),
    (ActorFunc)EnFr_Init,
    (ActorFunc)EnFr_Destroy,
    (ActorFunc)EnFr_Update,
    NULL,
};

Color_RGBA8 D_80A1D054[] = {
    { 200, 170, 0, 255 },
    { 0, 170, 200, 255 },
    { 210, 120, 100, 255 },
    { 120, 130, 230, 255 },
    { 190, 190, 190, 255 },
};

FrogData D_80A1D068[] = {
    { 0.0f, 0.0f, 0.0f },
    { 80.0f, -1.1780972f, -80.0f },
    { 80.0f, -1.5707964f, -80.0f },
    { 80.0f, -0.7853982f, -80.0f },
    { 80.0f, 2.7488937f, -80.0f },
    { 80.0f, 1.5707964, -80.0f },
};

s16 D_80A1D0B0[] = { 40, 20, 15, 12, 12 };

InitChainEntry D_80A1D0BC[] = {
    ICHAIN_U8(unk_1F, 2, ICHAIN_CONTINUE),
    ICHAIN_F32(unk_4C, 30, ICHAIN_STOP),
};

u8 D_80A1D0C4[] = { 5, 1, 7, 3, 9 };

f32 D_80A1D0CC[] = { 180.0f, 210.0f, 240.0f, 270.0f };

u8 D_80A1D0DC[] = { 5, 2, 9, 11, 14 };

u8 D_80A1D0E4[] = { 0xF9, 0xF6, 0xFD, 0xFF, 0x02 };

u8 D_80A1D0EC[] = { 1, 0, 2, 3, 4, 1, 0, 2 };

u8 D_80A1D0F4[] = { 0, 1, 2, 3, 4 };

// eye textyres
u16* D_80A1D0FC[] = { 0x060059A0, 0x06005BA0 };

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1A9A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/EnFr_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1AC0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1AC34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/EnFr_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/EnFr_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1AF6C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1AFF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B09C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B0F8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B174.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B19C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B22C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B2C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B464.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B524.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B638.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B778.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B8D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1B9D8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BB34.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BC14.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BCB4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BD94.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BDFC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BE98.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1BF10.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C05C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C18C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C1E4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C248.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C344.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C388.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C400.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C474.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C524.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C580.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C718.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C790.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C7CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C830.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1C944.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1CAAC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1CB08.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1CB58.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1CC04.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1CC2C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Fr/func_80A1CD24.s")
