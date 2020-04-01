#include "z_bg_gnd_firemeiro.h"

#define ROOM 0x00
#define FLAGS 0x00000030

void BgGndFiremeiro_Init(BgGndFiremeiro* this, GlobalContext* globalCtx);
void BgGndFiremeiro_Destroy(BgGndFiremeiro* this, GlobalContext* globalCtx);
void BgGndFiremeiro_Update(BgGndFiremeiro* this, GlobalContext* globalCtx);
void BgGndFiremeiro_Draw(BgGndFiremeiro* this, GlobalContext* globalCtx);
void func_80879808(BgGndFiremeiro* this, GlobalContext* globalCtx);
void func_80879668(BgGndFiremeiro* this, GlobalContext* globalCtx);
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

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/BgGndFiremeiro_Init.s")
extern u32 D_0600ECD8;
void BgGndFiremeiro_Init(BgGndFiremeiro* this, GlobalContext* globalCtx) 
{
    
    s32 pad;
    Actor* thisx = &this->dyna.actor;
    s32 sp24;

    sp24 = 0;
    ActorShape_Init(&thisx->shape, 0.0f, NULL, 0.0f);
    Actor_SetScale(thisx, 1.0000000e-1);
    this->unk_164 = thisx->posRot.pos;

    if (thisx->params == 0) {
        DynaPolyInfo_SetActorMove(thisx, DPM_UNK);
        DynaPolyInfo_Alloc(&D_0600ECD8, &sp24);
        this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, thisx, sp24);
        this->actionFunc = &func_80879808;
    }
}


void BgGndFiremeiro_Destroy(BgGndFiremeiro *this, GlobalContext *globalCtx)
{
    DynaCollisionContext *colCtx = &globalCtx->colCtx.dyna;
    if (this->dyna.actor.params == 0)
    {
        if (1) {} // Required to match
        DynaPolyInfo_Free(globalCtx, colCtx, this->dyna.dynaPolyId);
    }
}


void func_808795AC(BgGndFiremeiro* this, GlobalContext* globalCtx)
{
    f32 temp_f2 = this->unk_164.y - 150.0f;
    Actor* thisx = &this->dyna.actor;

    if (func_8004356C(thisx) != 0)
    {
        this->unk_170 = 10;
    }

    if (temp_f2 < thisx->posRot.pos.y)
    {
        thisx->posRot.pos.y -= 0.5f;
        if (thisx->posRot.pos.y < temp_f2)
        {
            thisx->posRot.pos.y = temp_f2;
        }
        func_8002F948(thisx, 0x2082); // unknown sfx id
    }
    if (this->unk_170 > 0)
    {
        this->unk_170 += -1;
    }

    else
    {
        this->actionFunc = &func_80879808;
    }
    
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Gnd_Firemeiro/func_80879668.s")

void func_80879808(BgGndFiremeiro* this, GlobalContext* globalCtx) {

    Actor* thisx = &this->dyna.actor;
    Actor* tempActor = globalCtx->actorCtx.actorList[2].first;

    if ((tempActor[1].room != 2) && (func_8004356C(thisx) != 0)) {
            if (thisx->posRot.pos.y < this->unk_164.y) {
                this->actionFunc = &func_808795AC;
                this->unk_170 = 0x14;
            }
            else
            {
                this->actionFunc = &func_80879668;
                this->unk_170 = 0x14;
            }
    }
    else 
    {
        if (thisx->posRot.pos.y < this->unk_164.y) 
        {
            thisx->posRot.pos.y += 2.0f;
            if (this->unk_164.y < thisx->posRot.pos.y) 
            {
                thisx->posRot.pos.y = this->unk_164.y;
            }
        }
    }
}

void BgGndFiremeiro_Update(BgGndFiremeiro* this, GlobalContext* globalCtx)
{
    this->actionFunc(&this->dyna.actor, globalCtx);
}

extern char D_808799E0[];
extern char D_808799F8[];
extern u32 D_0600E210;
extern char D_80879A10[];
void BgGndFiremeiro_Draw(BgGndFiremeiro* this, GlobalContext* globalCtx) {
    
    GraphicsContext* gfxCtx;
    Gfx* gfxArr[4];
    
    gfxCtx = globalCtx->state.gfxCtx;
    func_800C6AC4(gfxArr, globalCtx->state.gfxCtx, D_808799E0, 280);
    func_800943C8(globalCtx->state.gfxCtx);
    gSPMatrix(gfxCtx->polyOpa.p++, Matrix_NewMtx(globalCtx->state.gfxCtx, D_808799F8, 282), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxCtx->polyOpa.p++, &D_0600E210);
    func_800C6B54(gfxArr, globalCtx->state.gfxCtx, D_80879A10, 0x11D);
}