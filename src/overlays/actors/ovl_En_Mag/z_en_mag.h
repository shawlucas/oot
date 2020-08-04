#ifndef _Z_EN_MAG_H_
#define _Z_EN_MAG_H_

#include <ultra64.h>
#include <global.h>
#include <z64kanfont.h>

struct EnMag;

typedef struct EnMag {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ Sram sram;         
    /* 0x0150 */ Kanfont kanfont;
    /* 0xE2D8 */ s16 effect_rgb_fg;
    /* 0xE2DA */ s16 effect_rgb_ct;
    /* 0xE2DC */ s16 title_mode;
    /* 0xE2E0 */ f32 effect_prim_f;
    /* 0xE2E4 */ f32 effect_prim[3];
    /* 0xE2F0 */ f32 effect_env[3];
    /* 0xE2FC */ f32 effect_alpha;
    /* 0xE300 */ f32 title_alpha;
    /* 0xE304 */ f32 sub_alpha;
    /* 0xE308 */ f32 copy_alpha;
    /* 0xE30C */ s16 scroll_x;
    /* 0xE30E */ s16 scroll_y;
    /* 0xE310 */ s16 alpha_ct;
    /* 0xE312 */ s16 alpha_fdin;
    /* 0xE314 */ s16 alpha_fdout;
    /* 0xE316 */ s16 key_point;
    /* 0xE318 */ s16 key_frame;
    /* 0xE31C */ s32 old_key;
    /* 0xE320 */ s32 key_wait;
} EnMag; // size = 0xE328

extern const ActorInit En_Mag_InitVars;

#endif
