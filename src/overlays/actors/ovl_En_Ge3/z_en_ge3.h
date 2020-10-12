#ifndef _Z_EN_GE3_H_
#define _Z_EN_GE3_H_

#include "ultra64.h"
#include "global.h"

struct EnGe3;

typedef void (*EnGe3ActionFunc)(struct EnGe3*, GlobalContext*);

typedef struct EnGe3 {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ ColliderCylinder collider;
    /* 0x0198 */ SkelAnime skelAnime;
    /* 0x01DC */ Vec3s limbDrawTable[24];
    /* 0x026C */ Vec3s transitionDrawTable[24];
    /* 0x02FC */ s16 eyeIdx;
    /* 0x02FE */ s16 winkTimer;
    /* 0x0300 */ Vec3s neckRot;
    /* 0x0306 */ Vec3s bodyRot;
    /* 0x030C */ u16 flag;
    /* 0x0310 */ EnGe3ActionFunc actionFunc;
} EnGe3; // size = 0x0314

extern const ActorInit En_Ge3_InitVars;

#endif
