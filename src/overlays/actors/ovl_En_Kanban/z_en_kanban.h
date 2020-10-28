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
    /* 0x0168 */ char unk_168[0xB];
    /* 0x0173 */ s8 angleRotX;
    /* 0x0174 */ s8 angleRotZ;
    /* 0x0176 */ s16 angleSpeedX;
    /* 0x0178 */ s16 angleSpeedZ;
    /* 0x017A */ u8 boundCount;
    /* 0x017C */ f32 boundOffsetH;
    /* 0x0180 */ f32 boundOffsetV;
    /* 0x0184 */ s16 axWay;
    /* 0x0188 */ Vec3f groundAngle;
    /* 0x0194 */ u8 cutPattern;
    /* 0x0195 */ u8 cutNo;
    /* 0x0196 */ s16 cutEffTime;
    /* 0x0198 */ s16 cutEffA;
    /* 0x019A */ s16 stickTime;
    /* 0x019C */ u8 messageMode;
    /* 0x019D */ u8 messageWait;
    /* 0x019E */ u8 ocarinaCheck;
    /* 0x01A0 */ ColliderCylinder collider;
} EnKanban; // size = 0x01EC

extern const ActorInit En_Kanban_InitVars;

#endif
