#ifndef _Z_BG_BOMBWALL_H_
#define _Z_BG_BOMBWALL_H_

#include <ultra64.h>
#include <global.h>

struct BgBombwall;

typedef void (*BgBombwallActionFunc)(struct BgBombwall*, GlobalContext*);

typedef struct BgBombwall {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x0164 */ ColliderTris trisCollider;
    /* 0x0184 */ ColliderTrisItem trisItem;
    /* 0x01E0 */ char unk_1E0[0xB8];
    /* 0x0298 */ BgBombwallActionFunc actionFunc;
    /* 0x029C */ Gfx* dlist;
    /* 0x02A0 */ s16 unk_2A0;
    /* 0x02A2 */ u8 unk_2A2;
    /* 0x02A3 */ u8 unk_2A3;
} BgBombwall; // size = 0x02A4

extern const ActorInit Bg_Bombwall_InitVars;

#endif
