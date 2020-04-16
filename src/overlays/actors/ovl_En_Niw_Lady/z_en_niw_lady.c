#include "z_en_niw_lady.h"

#define FLAGS 0x00000019

void EnNiwLady_Init(EnNiwLady* this, GlobalContext* globalCtx);
void EnNiwLady_Destroy(EnNiwLady* this, GlobalContext* globalCtx);
void EnNiwLady_Update(EnNiwLady* this, GlobalContext* globalCtx);
void func_80AB9F24(EnNiwLady* this, GlobalContext* globalCtx);
void func_80ABA244(EnNiwLady* this, GlobalContext* globalCtx);

/*
const ActorInit En_Niw_Lady_InitVars = {
    ACTOR_EN_NIW_LADY,
    ACTORTYPE_NPC,
    FLAGS,
    OBJECT_ANE,
    sizeof(EnNiwLady),
    (ActorFunc)EnNiwLady_Init,
    (ActorFunc)EnNiwLady_Destroy,
    (ActorFunc)EnNiwLady_Update,
    NULL,
};
*/
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/EnNiwLady_Init.s")

void EnNiwLady_Init(EnNiwLady* this, GlobalContext* globalCtx) {
    s32 drawFlag;
    Actor* thisx = &this->actor;

    this->objBankIndex_280 = Object_GetIndex(&globalCtx->objectCtx, OBJECT_ANE);
    this->objBankIndex_281 = Object_GetIndex(&globalCtx->objectCtx, OBJECT_OS_ANIME);
    if ((this->objBankIndex_281 < 0) || (this->objBankIndex_280 < 0)) {

        Actor_Kill(thisx);
    }

    else
    {
        this->drawFlag = 0;
        if (globalCtx->sceneNum == SCENE_LABO)
        {
            this->drawFlag = 1;
        }

        drawFlag = this->drawFlag;
        if ((drawFlag != 0) && (gSaveContext.night_flag == 0)) 
        {
            Actor_Kill(thisx);
        }
        
        else
        {
            osSyncPrintf(VT_FGCOL(GREEN) "☆☆☆☆☆ ねぇちゃんうっふん ☆☆☆☆☆ %d\n" VT_RST, this->drawFlag);
            osSyncPrintf("\n\n");
            this->actionFunc = func_80AB9F24;
            thisx->unk_F4 = 600.0f;
        }
    }
}

void EnNiwLady_Destroy(EnNiwLady* this, GlobalContext* globalCtx)
{
    ColliderCylinderMain* collider = &this->collider;
    ActorCollider_FreeCylinder(globalCtx, collider);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80AB9D60.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80AB9F24.s")

extern s16 D_80ABB3A0[];
#ifdef NON_MATCHING
// regalloc
void func_80ABA21C(EnNiwLady* this, GlobalContext* globalCtx)
{
    u16 textId = D_80ABB3A0[0] & 0xFFFF;
    this->unk_262 = 6;
    this->actionFunc = func_80ABA244;
    this->actor.textId = textId;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABA21C.s")
#endif

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABA244.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABA654.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABA778.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABA878.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABA9B8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABAA9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABAB08.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABAC00.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABAC84.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABAD38.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABAD7C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/EnNiwLady_Update.s")

void func_80ABB0A0(GraphicsContext* gfxCtx)
{
    Gfx* displayList = Graph_Alloc(gfxCtx, 8);
    gSPEndDisplayList(displayList);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABB0CC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Niw_Lady/func_80ABB228.s")
