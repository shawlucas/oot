#ifndef _Z_DEMO_SA_H_
#define _Z_DEMO_SA_H_

#include <ultra64.h>
#include <global.h>

struct DemoSa;

typedef void (*DemoSaActionFunc)(struct DemoSa*, GlobalContext*);

typedef struct DemoSa {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ s16 unk_190;
    /* 0x0192 */ s16 unk_192;
    /* 0x0194 */ s16 unk_194;
    /* 0x0196 */ char unk_196[0x2];
    /* 0x0198 */ s32 action;
    /* 0x019C */ s32 drawConfig;
    /* 0x01A0 */ char unk_1A0[0x14];
} DemoSa; // size = 0x01B4

extern const ActorInit Demo_Sa_InitVars;

#endif
