#ifndef _Z_ITEM_B_HEART_H_
#define _Z_ITEM_B_HEART_H_

#include <ultra64.h>
#include <global.h>

typedef struct {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ s16 unk_14C;
    /* 0x014E */ char unk_14E[0xA];
    /* 0x0158 */ f32  unk_158; 
    /* 0x015C */ char unk_15C[0x8];
    /* 0x0164 */ s16 unk_164;
} ItemBHeart; // size = 0x016C

extern const ActorInit Item_B_Heart_InitVars;
#endif
