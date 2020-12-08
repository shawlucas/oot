#ifndef _Z_EFC_ERUPC_H_
#define _Z_EFC_ERUPC_H_

#include "ultra64.h"
#include "global.h"
#include "overlays/actors/ovl_Boss_Fd/z_boss_fd.h"

#define NUM_OF_FD_PARTICLES 100

struct EfcErupc;

typedef void (*EfcErupcActionFunc)(struct EfcErupc*, GlobalContext*);

typedef struct EfcErupc {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ s16 unk_14C;
    /* 0x014E */ s16 unk_14E;
    /* 0x0150 */ s16 unk_150;
    /* 0x0152 */ s16 unk_152;
    /* 0x0154 */ s16 unk_154;
    /* 0x0158 */ BossFdParticle fdParticle[100];
    /* 0x18C8 */ EfcErupcActionFunc actionFunc;
} EfcErupc; // size = 0x18CC

extern const ActorInit Efc_Erupc_InitVars;

#endif
