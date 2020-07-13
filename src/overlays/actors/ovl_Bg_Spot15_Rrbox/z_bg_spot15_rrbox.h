#ifndef _Z_BG_SPOT15_RRBOX_H_
#define _Z_BG_SPOT15_RRBOX_H_

#include <ultra64.h>
#include <global.h>

struct BgSpot15Rrbox;

typedef void (*BgSpot15RrboxActionFunc)(struct BgSpot15Rrbox*, GlobalContext*);

typedef struct BgSpot15Rrbox {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ BgSpot15RrboxActionFunc actionFunc;
    /* 0x0168 */ s16 unk_168;
    /* 0x016A */ char unk_16A[0x2];
    /* 0x016C */ s16 unk_16C;
    /* 0x016E */ char unk_16E[0x2];
    /* 0x0170 */ s16 unk_170;
    /* 0x0172 */ char unk_172[0x2];
    /* 0x0174 */ f32 unk_174;
    /* 0x0178 */ f32 unk_178;
    /* 0x017C */ f32 unk_17C;
    /* 0x0180 */ s32 unk_180;
} BgSpot15Rrbox; // size = 0x0184

extern const ActorInit Bg_Spot15_Rrbox_InitVars;

#endif
