#ifndef _Z_EN_NIW_LADY_H_
#define _Z_EN_NIW_LADY_H_

#include <ultra64.h>
#include <global.h>
#include <vt.h>

typedef struct {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s actorDrawTable[16];
    /* 0x01F0 */ Vec3s transitionDrawTable[16];
    /* 0x0250 */ ActorFunc actionFunc;
    /* 0x0254 */ char unk_254[0xE];
    /* 0x0262 */ u16 message_end_code;
    /* 0x0264 */ char unk_264[0x14];
    /* 0x0278 */ s16 drawFlag;
    /* 0x027A */ char unk_27A[0x6];
    /* 0x0280 */ s8 objBankIndex_280;
    /* 0x0281 */ s8 objBankIndex_281;
    /* 0x0282 */ char unk_282[0x2E];
    /* 0x02B0 */ ColliderCylinderMain collider;
} EnNiwLady; // size = 0x02FC

extern const ActorInit En_Niw_Lady_InitVars;

#endif
