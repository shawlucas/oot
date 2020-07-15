#ifndef _Z_EN_DH_H_
#define _Z_EN_DH_H_

#include <ultra64.h>
#include <global.h>

struct EnDh;

typedef void (*EnDhActionFunc)(struct EnDh*, GlobalContext*);

typedef struct EnDh {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s limbDrawTable[16];
    /* 0x01F0 */ Vec3s transitionDrawTable[16];
    /* 0x0250 */ u8 unk_250;
    /* 0x0251 */ char unk_251;
    /* 0x0252 */ u8 unk_252;
    /* 0x0253 */ char unk_253;
    /* 0x0254 */ EnDhActionFunc actionFunc;
    /* 0x0258 */ u8 unk_258;
    /* 0x0259 */ char unk_259;
    /* 0x025A */ u8 unk_25A;
    /* 0x025B */ char unk_25B;
    /* 0x025C */ s16 unk_25C;
    /* 0x025E */ s16 unk_25E;
    /* 0x0260 */ ColliderCylinder collider;
    /* 0x02AC */ ColliderJntSph colliderJntSph;
    /* 0x02CC */ ColliderJntSphItem colliderJntSphItem;
    /* 0x030C */ Vec3f vec_30C;
    /* 0x0318 */ Vec3f vec_318;
} EnDh; // size = 0x0324

extern const ActorInit En_Dh_InitVars;

#endif
