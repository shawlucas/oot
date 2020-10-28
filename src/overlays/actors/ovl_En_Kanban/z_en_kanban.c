#include "z_en_kanban.h"

#define FLAGS 0x00000019

#define THIS ((EnKanban*)thisx)

void EnKanban_Init(Actor* thisx, GlobalContext* globalCtx);
void EnKanban_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnKanban_Update(Actor* thisx, GlobalContext* globalCtx);
void EnKanban_Draw(Actor* thisx, GlobalContext* globalCtx);

void func_80A91FA0(EnKanban* this);

const ActorInit En_Kanban_InitVars = {
    ACTOR_EN_KANBAN,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_KANBAN,
    sizeof(EnKanban),
    (ActorFunc)EnKanban_Init,
    (ActorFunc)EnKanban_Destroy,
    (ActorFunc)EnKanban_Update,
    (ActorFunc)EnKanban_Draw,
};

ColliderCylinderInit D_80A94490 = {
    { COLTYPE_UNK10, 0x11, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x00, { 0xFFCFFFFF, 0x00, 0x00 }, { 0xFFCFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 20, 50, 5, { 0, 0, 0 } },
};

u16 D_80A944BC[] = {
    0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400,
};

Vec3f D_80A944D4[] = {
    { 0.0f, 44.0f, 0.0f },   { 0.0f, 50.0f, 0.0f },   { 0.0f, 38.0f, 0.0f },   { 10.0f, 44.0f, 0.0f },
    { -10.0f, 44.0f, 0.0f }, { -10.0f, 50.0f, 0.0f }, { 10.0f, 50.0f, 0.0f },  { -10.0f, 38.0f, 0.0f },
    { 10.0f, 38.0f, 0.0f },  { -7.5f, 51.0f, 0.0f },  { -12.5f, 48.0f, 0.0f }, { -12.5f, 40.0f, 0.0f },
    { -7.5f, 37.0f, 0.0f },  { 7.5f, 51.0f, 0.0f },   { 12.5f, 48.0f, 0.0f },  { 12.5f, 40.0f, 0.0f },
    { 7.5f, 37.0f, 0.0f },   { 0.0f, 50.0f, 0.0f },   { 0.0f, 38.0f, 0.0f },
};

Vec3f D_80A945B8[] = {
    { 1500.0f, 1000.0f, 0.0f }, { 1500.0f, 500.0f, 0.0f }, { 1500.0f, 500.0f, 0.0f }, { 700.0f, 1000.0f, 0.0f },
    { 700.0f, 1000.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },
    { 700.0f, 500.0f, 0.0f },   { 700.0f, 500.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },
    { 700.0f, 500.0f, 0.0f },   { 700.0f, 500.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },  { 700.0f, 500.0f, 0.0f },
    { 700.0f, 500.0f, 0.0f },   { 200.0f, 500.0f, 0.0f },  { 200.0f, 500.0f, 0.0f },
};

u8 D_80A9469C[] = {
    0x01, 0x01, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_80A946B8[] = {
    0x03FF, 0x0027, 0x014B, 0x0147, 0x0159, 0x00D8,
};

s32 D_80A946C4[] = { 0, 0, 0 };

Gfx* D_80A946D0[] = {
    0x06000CB0, 0x06000DB8, 0x06000E78, 0x06000F38, 0x06000FF8, 0x060010B8,
    0x060011C0, 0x060012C8, 0x060013D0, 0x06001488, 0x06001540,
};

#include "z_en_kanban_texture.c" EARLY

void func_80A91FA0(EnKanban* this) {
    f32 a, b, c, y;
    CollisionPoly* colPoly = this->actor.floorPoly;

    if (colPoly != NULL) {
        a = colPoly->norm.x *  0.00003051851f;
    }
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Kanban/EnKanban_Init.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Kanban/EnKanban_Destroy.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Kanban/func_80A921C0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Kanban/EnKanban_Update.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/actors/ovl_En_Kanban/EnKanban_Draw.s")
