#include "z_bg_gnd_firemeiro.h"

#define ROOM 0x00
#define FLAGS 0x00000030

void BgGndFiremeiro_Init(BgGndFiremeiro* this, GlobalContext* globalCtx);
void BgGndFiremeiro_Destroy(BgGndFiremeiro* this, GlobalContext* globalCtx);
void BgGndFiremeiro_Update(BgGndFiremeiro* this, GlobalContext* globalCtx);
void BgGndFiremeiro_Draw(BgGndFiremeiro* this, GlobalContext* globalCtx);

/*
const ActorInit Bg_Gnd_Firemeiro_InitVars = {
    ACTOR_BG_GND_FIREMEIRO,
    ACTORTYPE_PROP,
    ROOM,
    FLAGS,
    OBJECT_DEMO_KEKKAI,
    sizeof(BgGndFiremeiro),
    (ActorFunc)BgGndFiremeiro_Init,
    (ActorFunc)BgGndFiremeiro_Destroy,
    (ActorFunc)BgGndFiremeiro_Update,
    (ActorFunc)BgGndFiremeiro_Draw,
};
*/

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/BgGndFiremeiro_Init.s")
/*
void BgGndFiremeiro_Init(BgGndFiremeiro* this, GlobalContext* globalCtx) 
{
    Actor* thisx = &this->dyna.actor;
    s32 sp24;

    sp24 = 0;
    ActorShape_Init(&thisx->shape, 0.0f, NULL, 0.0f);
    Actor_SetScale(thisx, 1.0000000e-1);
    this->unk_164 = thisx->posRot.pos;

    if (thisx->params == 0) {
        DynaPolyInfo_SetActorMove(thisx, DPM_UNK);
        DynaPolyInfo_Alloc(0x6010000 + 0xECD8, &sp24);
        arg0->unk14C = DynaPolyInfo_RegisterActor(sp34, sp34 + 0x810, arg0, sp24);
        arg0->unk174 = &func_80879808;
    }
}
*/

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/BgGndFiremeiro_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/func_808795AC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/func_80879668.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/func_80879808.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/BgGndFiremeiro_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/BgGndFiremeiro_Draw.s")
