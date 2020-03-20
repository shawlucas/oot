#include "z_bg_treemouth.h"

#define ROOM  0x00
#define FLAGS 0x00000030

void BgTreemouth_Init(BgTreemouth* this, GlobalContext* globalCtx);
void BgTreemouth_Destroy(BgTreemouth* this, GlobalContext* globalCtx);
void BgTreemouth_Update(BgTreemouth* this, GlobalContext* globalCtx);
void BgTreemouth_Draw(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BC6F8(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BC80C(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BC864(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BC8B8(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BC9EC(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BCAF0(BgTreemouth* this, GlobalContext* globalCtx);
void func_808BCB8C(BgTreemouth* this, GlobalContext* globalCtx);

/*
const ActorInit Bg_Treemouth_InitVars =
{
    ACTOR_BG_TREEMOUTH,
    ACTORTYPE_BG,
    ROOM,
    FLAGS,
    OBJECT_SPOT04_OBJECTS,
    sizeof(BgTreemouth),
    (ActorFunc)BgTreemouth_Init,
    (ActorFunc)BgTreemouth_Destroy,
    (ActorFunc)BgTreemouth_Update,
    (ActorFunc)BgTreemouth_Draw,
};
*/
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC500.s")

void func_808BC500(BgTreemouth* this, ActorFunc actionFunc)
{
    this->actionFunc = actionFunc;
}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/BgTreemouth_Init.s")

extern InitChainEntry D_808BD9B0;
extern u32 D_06000E94;
void BgTreemouth_Init(BgTreemouth* this, GlobalContext* globalCtx) {
    
   Actor* thisx = &this->dyna.actor;
   u32 sp24[2];
   sp24[0] = 0;
   Actor_ProcessInitChain(thisx, &D_808BD9B0);
   DynaPolyInfo_SetActorMove(thisx, DPM_UNK);
   DynaPolyInfo_Alloc(&D_06000E94, &sp24);
   this->dyna.dynaPolyId = DynaPolyInfo_RegisterActor(globalCtx, &globalCtx->colCtx.dyna, thisx, sp24[0]);
   ActorShape_Init(&this->dyna.actor.shape, 0.0f, 0, 0.0f);
   Actor_SetHeight(thisx, 50.0f);
   if ((gSaveContext.scene_setup_index < 4) && LINK_IS_CHILD) 
   {
       func_808BC500(thisx, &func_808BC8B8);
   } 
   else 
   {
       if (LINK_IS_ADULT || (gSaveContext.scene_setup_index == 7)) 
       {
           this->unk_168 = 0.0f;
           func_808BC500(thisx, &func_808BCB8C);
       } 
       else 
       {
           this->unk_168 = 1.0f;
           func_808BC500(thisx, &func_808BC6F8);
       }
    }
   thisx->textId = (s16) (u16)0x905;
}

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/BgTreemouth_Destroy.s")
void BgTreemouth_Destroy(BgTreemouth* this, GlobalContext* globalCtx)
{
   DynaPolyInfo_Free(globalCtx, &globalCtx->colCtx.dyna, this->dyna.dynaPolyId);
}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC65C.s")
extern Vec3f D_801333D4;
void func_808BC65C(BgTreemouth* this, GlobalContext* globalCtx) 
{
   CsCmdActorAction* csAction;
   csAction = globalCtx->csCtx.actorActions[0]; // why is this set if it's not used??
   if ((globalCtx->csCtx.state != 0) && globalCtx->csCtx.actorActions[0] != 0)
   {
       if (globalCtx->csCtx.actorActions[0]->action == 2) 
       {
           func_808BC500(&this->dyna.actor, &func_808BC80C);
           return;
       }
       else
       {
           if (globalCtx->csCtx.actorActions[0]->action == 3) 
           {
               Audio_PlaySoundGeneral(NA_SE_EV_WOODDOOR_OPEN, &D_801333D4, 4, &D_801333E0,
                                     &D_801333E0, &D_801333E8);
               func_808BC500(&this->dyna.actor, &func_808BC6F8);
           }
       }
   }

}


#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC6F8.s")

//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC80C.s")
extern f32 D_808BDA34;
extern f32 D_808BDA38;
void func_808BC80C(BgTreemouth* this, GlobalContext* globalCtx)
{
   this->unk_168 = this->unk_168 + D_808BDA34;
   if (D_808BDA38 <= this->unk_168)
   {
       func_808BC500(&this->dyna.actor, &func_808BC864);
   }
}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC864.s")
extern f32 D_808BDA3C;
void func_808BC864(BgTreemouth* this, GlobalContext* globalCtx)
{
    this->unk_168 = this->unk_168 - D_808BDA3C;
    if (this->unk_168 <= 0.0f)
    {
       func_808BC500(&this->dyna.actor, &func_808BC65C);
    }
}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC8B8.s")
extern void* D_808BD2A0;
extern void* D_808BCE20;
void func_808BC8B8(BgTreemouth* this, GlobalContext* globalCtx)
{
   if ((Flags_GetEventChkInf(5) == 0) || (gSaveContext.link_age == 0))
   {
       if (gSaveContext.link_age != 0)
       {
           if (Flags_GetEventChkInf(0xC) != 0) // this sequence doesn't match when using && and ||
           {
               if (func_8002E12C(&this->dyna.actor, 1658.0f, 0x7530) != 0)
               {
                   this->dyna.actor.flags = this->dyna.actor.flags | 1;
                   if (this->dyna.actor.unk_10C != 0)
                   {
                       this->dyna.actor.flags = this->dyna.actor.flags & -2;
                       globalCtx->csCtx.segment = &D_808BD2A0;
                       gSaveContext.cutscene_trigger = 1;
                       func_808BC500(&this->dyna.actor, &func_808BC9EC);
                   }
               }
           }   
       else
       {
           if (func_8002E12C(&this->dyna.actor, 1658.0f, 0x4E20) != 0)
           {
               Flags_SetEventChkInf(0xC);
               globalCtx->csCtx.segment = &D_808BCE20;
               gSaveContext.cutscene_trigger = 1;
               func_808BC500(&this->dyna.actor, &func_808BC9EC);
           }
       }
   }
}
   else
   {
       this->unk_168 = 1.0f;
   }
}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BC9EC.s")
extern f32 D_808BDA40;
extern f32 D_808BDA44;
extern u16 D_8015FCC0;
extern u16 D_8015FCC2;
extern u16 D_8015FCC4;
extern D_808BD520;
extern D_808BD790;
void func_808BC9EC(BgTreemouth* this, GlobalContext* globalCtx) {

    Player * player = PLAYER;

    if (globalCtx->csCtx.state == 3) {
        if (func_8002E12C(&this->dyna.actor, 350.0f, 0x7530) != 0) {
            player->actor.posRot.pos.x = D_808BDA40;
            player->actor.posRot.pos.y = -161.0f;
            player->actor.posRot.pos.z = D_808BDA44;
        }
        globalCtx->csCtx.frames = 0;
        globalCtx->csCtx.unk_18 = (u16)0xFFFF;
        D_8015FCC0 = (u16)0xFFFF;
        D_8015FCC2 = (u16)0xFFFF;
        D_8015FCC4 = (u16)0xFFFF;
        globalCtx->csCtx.unk_1A = 0;
        globalCtx->csCtx.unk_1B = 0;
        globalCtx->csCtx.state = 2;
        if (globalCtx->msgCtx.choiceIndex == 0) {
            globalCtx->csCtx.segment = &D_808BD520;
            Flags_SetEventChkInf(5);
            func_808BC500(&this->dyna.actor, &func_808BCAF0);
            return;
        }
        globalCtx->csCtx.segment = &D_808BD790;
        globalCtx->csCtx.frames = 0;
        func_808BC500(&this->dyna.actor, &func_808BC8B8);
    }
}


//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BCAF0.s")

// this function is literally the same as func_808BC65C
void func_808BCAF0(BgTreemouth* this, GlobalContext* globalCtx) 
{
   CsCmdActorAction* csAction;
   csAction = globalCtx->csCtx.actorActions[0]; 
   if ((globalCtx->csCtx.state != 0) && globalCtx->csCtx.actorActions[0] != 0)
   {
       if (globalCtx->csCtx.actorActions[0]->action == 2) 
       {
           func_808BC500(&this->dyna.actor, &func_808BC80C);
           return;
       }
       else
       {
           if (globalCtx->csCtx.actorActions[0]->action == 3) 
           {
               Audio_PlaySoundGeneral(NA_SE_EV_WOODDOOR_OPEN, &D_801333D4, 4, &D_801333E0,
                                     &D_801333E0, &D_801333E8);
               func_808BC500(&this->dyna.actor, &func_808BC6F8);
           }
       }
   }

}


//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/func_808BCB8C.s")

void func_808BCB8C(BgTreemouth* this, GlobalContext* globalCtx)
{

}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/BgTreemouth_Update.s")
extern f32 D_808BDA48;
extern f32 D_808BDA4C;
extern f32 D_808BDA50;
void BgTreemouth_Update(BgTreemouth* this, GlobalContext* globalCtx)
{
    this->actionFunc(&this->dyna.actor, globalCtx);
    this->dyna.actor.posRot.pos.x = (this->unk_168 * -160.0f) + D_808BDA48;
    this->dyna.actor.posRot.pos.y = (this->unk_168 * D_808BDA4C) + 136.0f;
    this->dyna.actor.posRot.pos.z = (this->unk_168 * 92.0f) + D_808BDA50;
}
//#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_Bg_Treemouth/BgTreemouth_Draw.s")
extern char D_808BD9E0[];
void BgTreemouth_Draw(BgTreemouth* this, GlobalContext* globalCtx) {

    u32 uVar5;
    Gfx* gfxArr[4];
    GraphicsContext* gfxCtx;

    gfxCtx = globalCtx->state.gfxCtx;

    func_800C6AC4(gfxArr, globalCtx->state.gfxCtx, &D_808BD9E0, 0x37D);
    func_80093D18(globalCtx->state.gfxCtx);
    if (((gSaveContext.scene_setup_index < 4) || (gSaveContext.link_age == 0)) && 
            (gSaveContext.event_chk_inf[0] & 0x80) != 0) {

            uVar5 = 2150;
    } 
    if (gSaveContext.scene_setup_index == 6) {
        uVar5 = (globalCtx->unk_11D30[0] + 500U) & 0xFFFF;
    }
    temp_v1_2 = sp3C->unk2C0;
    sp3C->unk2C0 = (void *) (temp_v1_2 + 8);
    temp_v1_2->unk0 = 0xFB000000;
    temp_v1_2->unk4 = (s32) (((u32) ((f32) (u32) uVar5 * D_808BDA54) & 0xFF) | 0x80808000);
    temp_v0 = sp3C->unk2C0;
    sp3C->unk2C0 = (void *) (temp_v0 + 8);
    temp_v0->unk0 = 0xDA380003;
    sp3C = sp3C;
    sp24 = temp_v0;
    sp24->unk4 = Matrix_NewMtx(*sp4C, &D_808BD9F4, 0x3A4);
    temp_v0_2 = sp3C->unk2C0;
    sp3C->unk2C0 = (void *) (temp_v0_2 + 8);
    temp_v0_2->unk4 = (s32) (0x6000000 + 0x9D0);
    temp_v0_2->unk0 = 0xDE000000;
    func_800C6B54(&sp2C, *sp4C, &D_808BDA08, 0x3A9);
}
