#ifndef _Z_EN_BOX_H_
#define _Z_EN_BOX_H_

#include <ultra64.h>
#include <global.h>

struct EnBox;

typedef void (*EnBoxActionFunc)(struct EnBox*, GlobalContext*);

typedef struct EnBox {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ SkelAnime skelAnime;
    /* 0x01A8 */ s32 unk_1A8;
    /* 0x01AC */ char unk_1AC[0x4];
    /* 0x01B0 */ f32 unk_1B0;
    /* 0x01B4 */ EnBoxActionFunc actionFunc;
    /* 0x01B8 */ Vec3s limbDrawTable[5];
    /* 0x01D6 */ Vec3s transitionDrawTable[5];
    /* 0x01F4 */ s16 unk_1F4;
    /* 0x01F6 */ u8 unk_1F6;
    /* 0x01F7 */ char unk_1F7;
    /* 0x01F8 */ u8 switchFlag;
    /* 0x01F9 */ u8 unk_1F9;
    /* 0x01FA */ u8 unk_1FA;
    /* 0x01FB */ char unk_1FB;
} EnBox; // size = 0x01FC

extern const ActorInit En_Box_InitVars;

#endif
