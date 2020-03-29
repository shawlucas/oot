#ifndef _Z_EN_SA_H_
#define _Z_EN_SA_H_

#include <ultra64.h>
#include <global.h>

typedef struct {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ ActorFunc actionFunc;
    /* 0x0194 */ ColliderCylinderMain collider;
    /* 0x01E0 */ struct_80034A14_arg1 unk_1E0;
    /* 0x0204 */ char unk_204[0x4];
    /* 0x0208 */ u8 unk_208;
    /* 0x0209 */ u8 unk_209;
    /* 0x020A */ u8 unk_20A;
    /* 0x020B */ char unk_20B[0xF];
    /* 0x021A */ Vec3s unk_21A;
    /* 0x0220 */ Vec3s actorDrawTbl;
    /* 0x0226 */ char unk_226[0x60];
    /* 0x0286 */ Vec3s unk_286;
    /* 0x028C */ char unk_28C[0x60];
} EnSa; // size = 0x02EC

extern const ActorInit En_Sa_InitVars;

#endif
