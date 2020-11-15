#ifndef _Z_EN_DNT_JIJI_H_
#define _Z_EN_DNT_JIJI_H_

#include "ultra64.h"
#include "global.h"

struct EnDntJiji;

typedef void (*EnDntJijiActionFunc)(struct EnDntJiji*, GlobalContext*);

typedef struct EnDntJiji {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s limbDrawTable[13];
    /* 0x01DE */ Vec3s transitionDrawTable[13];
    /* 0x022C */ EnDntJijiActionFunc actionFunc;
    /* 0x0230 */ Vec3f pos;
    /* 0x023C */ u8 unk_23C;
    /* 0x023E */ s16 action;
    /* 0x0240 */ s16 csTimer;
    /* 0x0242 */ s16 sfxTimer;
    /* 0x0244 */ s16 blinkTimer;
    /* 0x0246 */ s16 limbTimer;
    /* 0x0248 */ s16 unk_248;
    /* 0x024A */ s16 unk_24A;
    /* 0x024C */ s16 unk_24C;
    /* 0x024E */ s16 mode;
    /* 0x0250 */ s16 messageEndCode;
    /* 0x0252 */ s16 damageFlag;
    /* 0x0254 */ s32 itemIndex;
    /* 0x0258 */ Actor* actor_258;
    /* 0x025C */ ColliderCylinder collider;
} EnDntJiji; // size = 0x02A8

extern const ActorInit En_Dnt_Jiji_InitVars;

#endif
