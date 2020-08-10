#ifndef _THA_GA_H
#define _THA_GA_H

#include <ultra64.h>
#include <ultra64/gbi.h>
#include <TwoHeadArena.h>

typedef struct TwoHeadGfxArena_s {
    /* 0x0000 */ u32    size;
    /* 0x0004 */ Gfx*   bufp;
    /* 0x0008 */ Gfx*   p;
    /* 0x000C */ Gfx*   d;
} TwoHeadGfxArena_t; // size = 0x10

typedef TwoHeadGfxArena_t TwoHeadGfxArena;

typedef union THA_GA_s {
    TwoHeadArena tha;
    TwoHeadGfxArena thaGfx;
} THA_GA_t;

typedef THA_GA_t THA_GA;

#define THA_GA_NEXT_DISP(thaga)             ((thaga)->thaGfx.p++)
#define THA_GA_getHeadPtr(thaga)            ((thaga)->tha.head)
#define THA_GA_setHeadPtr(thaga, ptr)       (void)((thaga)->tha.head = (char *)(ptr))

#endif
