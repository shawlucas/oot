#ifndef _Z_EN_KANBAN_H_
#define _Z_EN_KANBAN_H_

#include "ultra64.h"
#include "global.h"

struct EnKanban;

typedef void (*EnKanbanActionFunc)(struct EnKanban*, GlobalContext*);

typedef struct EnKanban {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnKanbanActionFunc actionFunc;
    /* 0x0150 */ u8 timer;
    /* 0x0152 */ s16 moveTimer;
    /* 0x0154 */ u8 moveMode;
    /* 0x0156 */ u16 breakBit;
    /* 0x0158 */ u8 breakSize;
    /* 0x015A */ s16 hitTimer;
    /* 0x015C */ Vec3f offset;
    /* 0x0168 */ char unk_168[0x38];
    /* 0x01A0 */ ColliderCylinder collider;
} EnKanban; // size = 0x01EC

extern const ActorInit En_Kanban_InitVars;

#endif
