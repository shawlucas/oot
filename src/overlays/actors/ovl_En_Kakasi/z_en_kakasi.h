#ifndef _Z_EN_KAKASI_H_
#define _Z_EN_KAKASI_H_

#include <ultra64.h>
#include <global.h>

struct EnKakasi;

typedef void (*EnKakasiActionFunc)(struct EnKakasi*, GlobalContext*);

typedef struct EnKakasi {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ EnKakasiActionFunc actionFunc;
    /* 0x0150 */ SkelAnime skelAnime;
    /* 0x0194 */ char unk_194[0x8];
    /* 0x019C */ s16 unk_19C[4];
    /* 0x01A4 */ char unk_1A4[0xA];
    /* 0x01AE */ Vec3s unk_1AE;
    /* 0x01B4 */ f32 unk_1B4;
    /* 0x01B8 */ char unk_1B8[0x4];
    /* 0x01BC */ ColliderCylinder collider;
    /* 0x0208 */ s16 camIdx;
    /* 0x020A */ char unk_20A[0x2];
} EnKakasi; // size = 0x020C

extern const ActorInit En_Kakasi_InitVars;

#endif
