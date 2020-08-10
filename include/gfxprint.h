#ifndef __GFXPRINT_H
#define __GFXPRINT_H

#include <ultra64.h>
#include <ultra64/gbi.h>
#include <color.h>
#include <stdarg.h>

typedef struct GfxPrint {
    /* 0x00 */ struct GfxPrint*(*callback)(struct GfxPrint*, const char*, size_t);
    /* 0x04 */ Gfx* dlist;
    /* 0x08 */ u16 posX;
    /* 0x0A */ u16 posY;
    /* 0x0C */ u16 baseX;
    /* 0x0E */ u8 baseY;
    /* 0x0F */ u8 flag;
    /* 0x10 */ Color_RGBA8 color;
    /* 0x14 */ char unk_14[0x1C]; // unused
} GfxPrint; // size = 0x30

#define GfxPrint_Color(r, g, b, a) GfxPrint_SetColor(gfxprint, r, g, b, a)


#define GfxPrint_InitPrint()                    GfxPrint_Init(gfxprint)
#define GfxPrint_Cleanup()                      GfxPrint_Destroy(gfxprint)
#define GfxPrint_OpenPrint(glistp)              GfxPrint_Open(gfxprint, glistp)
#define GfxPrint_ClosePrint()                   GfxPrint_Close(gfxprint)
#define GfxPrint_SetColorPrint(r, g, b, a)      GfxPrint_SetColor(gfxprint, r, g, b, a)
#define GfxPrint_SetPosPrint(x, y)              GfxPrint_SetPos(gfxprint, x, y)
#define GfxPrint_Print(c)                       GfxPrint_Printf(gfxprint, c)
#endif
