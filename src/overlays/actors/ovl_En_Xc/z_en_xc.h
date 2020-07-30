#ifndef _Z_EN_XC_H_
#define _Z_EN_XC_H_

#include <ultra64.h>
#include <global.h>

struct EnXc;

typedef void (*EnXcActionFunc)(struct EnXc*, GlobalContext*);
typedef void (*EnXcDrawFunc)(struct EnXc*, GlobalContext*);

typedef struct EnXc {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s limbDrawTable[17];
    /* 0x01F6 */ Vec3s transitionDrawTable[17];
    /* 0x025C */ s16 unk_25C; // segment idx
    /* 0x025E */ char unk_25E[0x2];
    /* 0x0260 */ s32 action;
    /* 0x0264 */ s32 drawMode;
    /* 0x0268 */ char unk_268[0x58];
    /* 0x02C0 */ ColliderCylinder collider;
    /* 0x030C */ char unk_30C[0x30];
} EnXc; // size = 0x033C

extern const ActorInit En_Xc_InitVars;

#endif
