#include "z_en_dnt_demo.h"
#include <vt.h>

#define FLAGS 0x00000000

#define THIS ((EnDntDemo*)thisx)

void EnDntDemo_Init(Actor* thisx, GlobalContext* globalCtx);
void EnDntDemo_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnDntDemo_Update(Actor* thisx, GlobalContext* globalCtx);

void func_809F0AA4(EnDntDemo* this, GlobalContext* globalCtx);
void func_809F1100(EnDntDemo* this, GlobalContext* globalCtx);

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
    { 0, 1, 0, 1, 2, 0, 1 }, { 1, 0, 1, 0, 1, 1, 2 }, { 2, 1, 1, 1, 0, 0, 0 }, { 1, 2, 1, 1, 1, 1, 0 },
    { 0, 0, 2, 0, 0, 0, 1 }, { 0, 0, 0, 2, 1, 2, 0 }, { 1, 1, 1, 1, 1, 1, 1 }, { 2, 2, 2, 2, 2, 2, 2 },
};

s16 D_809F1630[][2] = {
    { 4, 3 },
    { 4, 2 },
    { 3, 1 },
};

Vec3f D_809F163C[] = {
    { 3810.0f, -20.0f, 1010.0f }, { 3890.0f, -20.0f, 990.0f }, { 3730.0f, -20.0f, 950.0f },
    { 3840.0f, -20.0f, 930.0f },  { 3910.0f, -20.0f, 870.0f }, { 3780.0f, -20.0f, 860.0f },
    { 3710.0f, -20.0f, 840.0f },  { 3860.0f, -20.0f, 790.0f }, { 3750.0f, -20.0f, 750.0f },
};

void EnDntDemo_Destroy(Actor* thisx, GlobalContext* globalCtx) {
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/EnDntDemo_Init.s")
void EnDntDemo_Init(Actor* thisx, GlobalContext* globalCtx) {
    EnDntDemo* this = THIS;
    GlobalContext* globalCtx2 = globalCtx;
    s32 i;
    s32 pad;

    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ デグナッツお面品評会開始 ☆☆☆☆☆ \n" VT_RST);

    for (i = 0; i < ARRAY_COUNT(D_809F163C); i++) {
        this->vecArray_160[i] = D_809F163C[i];
        this->actorArray_1D8[i] =
            Actor_SpawnAsChild(&globalCtx2->actorCtx, thisx, globalCtx2, ACTOR_EN_DNT_NOMAL, this->vecArray_160[i].x,
                               this->vecArray_160[i].y, this->vecArray_160[i].z, 0, 0, 0, i + 1);
        if (this->actorArray_1D8[i] != NULL) {
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ザコザコ ☆☆☆☆☆ %x\n" VT_RST, this->actorArray_1D8[i]);
        }
    }

    this->vec_1CC.x = 4050.0f;
    this->vec_1CC.y = -20.0f;
    this->vec_1CC.z = 1000.0f;
    this->actor_1FC = Actor_SpawnAsChild(&globalCtx2->actorCtx, thisx, globalCtx2, ACTOR_EN_DNT_JIJI, 4050.0f, -20.0f,
                                         1000.0f, 0, 0, 0, 0);
    if (this->actor_1FC != NULL) {
        osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ じじじじじじじじじじい ☆☆☆☆☆ %x\n" VT_RST, this->actor_1FC);
    }
    this->unk_15E = 0;
    thisx->flags &= -2;
    this->actionFunc = func_809F0AA4;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/func_809F0AA4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/func_809F1100.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/func_809F1374.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Dnt_Demo/EnDntDemo_Update.s")
