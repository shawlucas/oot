#ifndef _Z_OBJ_HAMISHI_H_
#define _Z_OBJ_HAMISHI_H_

#include "ultra64.h"
#include "global.h"

struct ObjHamishi;

typedef struct ObjHamishi {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
    /* 0x0198 */ f32 vibrationPowerPos;
    /* 0x019C */ f32 vibrationPowerRot;
    /* 0x01A0 */ s16 vibrationTimer;
    /* 0x01A2 */ s16 vibrationAnglePos;
    /* 0x01A4 */ s16 vibrationAngleRot;
    /* 0x01A6 */ s16 numOfHammerSwings;
} ObjHamishi; // size = 0x01A8

extern const ActorInit Obj_Hamishi_InitVars;

#endif
