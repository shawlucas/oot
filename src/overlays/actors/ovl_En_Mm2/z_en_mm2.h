#ifndef _Z_EN_MM2_H_
#define _Z_EN_MM2_H_

#include <ultra64.h>
#include <global.h>

struct EnMm2;

typedef void (*EnMm2ActionFunc)(struct EnMm2*, GlobalContext*);

typedef struct EnMm2 {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ EnMm2ActionFunc actionFunc;
    /* 0x0194 */ ColliderCylinder collider;
    /* 0x01E0 */ char unk_1E0[0x8];
    /* 0x01E8 */ Vec3s unk_1E8;
    /* 0x01EE */ Vec3s unk_1EE;
    /* 0x01F4 */ char unk_1F4[0x8];
    /* 0x01FC */ Vec3s limbDrawTable[16];
    /* 0x025C */ Vec3s transitionDrawTable[16];
} EnMm2; // size = 0x02BC

extern const ActorInit En_Mm2_InitVars;

#endif
