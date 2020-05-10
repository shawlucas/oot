#ifndef _Z64_FILE_CHOOSE_H_
#define _Z64_FILE_CHOOSE_H_

#include <ultra64.h>
#include <global.h>

typedef struct
{
    /* 0x00000 */ GameState state;
    /* 0x000A4 */ Gfx* gfx_A4;
    /* 0x000A8 */ void* title_staticSegment;
    /* 0x000AC */ void* parameter_staticSegment;
    /* 0x000B0 */ SCmdAltHeaders* sceneHeader;
    /* 0x000B4 */ char unk_B4[0x4]; // view->viewport.bottomY from previous context
    /* 0x000B8 */ View view;
    /* 0x001E0 */ Sram* sram;
    /* 0x001E4 */ char unk_1E4[0x1C854];
    /* 0x1CA38 */ s16 cursorIndex;
    /* 0x1CA3A */ char unk_1CA3A[0x16];
    /* 0x1CA50 */ s16 unk_1CA50; // some sort of frame counter;
    /* 0x1CA52 */ char unk_1CA52[0x8E];
} FileContext; // size = 0x1CAE0

#endif
