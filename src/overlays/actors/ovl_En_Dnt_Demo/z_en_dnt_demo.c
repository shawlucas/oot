#include "z_en_dnt_demo.h"

#define FLAGS 0x00000000

#define THIS ((EnDntDemo*)thisx)

void EnDntDemo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDntDemo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDntDemo_Update(Actor* thisx, GlobalContext* globalCtx);


const ActorInit En_Dnt_Demo_InitVars = {
    ACTOR_EN_DNT_DEMO,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(EnDntDemo),
    (ActorFunc)EnDntDemo_Init,
    (ActorFunc)EnDntDemo_Destroy,
    (ActorFunc)EnDntDemo_Update,
    NULL,
};

s16 D_809F15C0[][7] = {
    { 0, 1, 0, 1, 2, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 2 },
    { 2, 1, 1, 1, 0, 0, 0 },
    { 1, 2, 1, 1, 1, 1, 0 },
    { 0, 0, 2, 0, 0, 0, 1 },
    { 0, 0, 0, 2, 1, 2, 0 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 2, 2, 2, 2, 2, 2, 2 },
};

s16 D_809F1630[][2] = {
    { 4, 3 },
    { 4, 2 },
    { 3, 1 },
};

Vec3f D_809F163C[] = {
    { 3810.0f, -20.0f, 1010.0f },
    { 3890.0f, -20.0f, 990.0f },
    { 3730.0f, -20.0f, 950.0f },
    { 3840.0f, -20.0f, 930.0f },
    { 3910.0f, -20.0f, 870.0f },
    { 3780.0f, -20.0f, 860.0f },
    { 3710.0f, -20.0f, 840.0f },
    { 3860.0f, -20.0f, 790.0f },
    { 3750.0f, -20.0f, 750.0f },
};

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/EnDntDemo_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/EnDntDemo_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/func_809F0AA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/func_809F1100.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/func_809F1374.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/EnDntDemo_Update.s")
