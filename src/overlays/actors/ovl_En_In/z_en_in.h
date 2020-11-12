#ifndef _Z_EN_IN_H_
#define _Z_EN_IN_H_

#include "ultra64.h"
#include "global.h"

struct EnIn;

typedef void (*EnInActionFunc)(struct EnIn*, GlobalContext*);

typedef struct EnInAnimation {
    /* 0x0000 */ AnimationHeader* anim;
    /* 0x0004 */ f32 animPlaybackSpeed;
    /* 0x0008 */ u8 flags;
    /* 0x000C */ f32 transition;
} EnInAnimation; // size = 0x0010

typedef struct EnIn {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnInActionFunc actionFunc;
    /* 0x0194 */ ColliderCylinder collider;
    /* 0x01E0 */ f32 unk_1E0;
    /* 0x01E4 */ s8 objBankIdx;
    /* 0x01E5 */ char unk_1E5[0x19];
    /* 0x01FE */ Vec3s limbDrawTable[20];
    /* 0x0276 */ Vec3s transitionDrawTable[20];
    /* 0x02EE */ char unk_307[0xBA];
} EnIn; // size = 0x03A8

extern const ActorInit En_In_InitVars;

#endif
