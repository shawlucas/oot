#ifndef _GZ_GFX_H
#define _GZ_GFX_H_

#include <ultra64.h>

#define GFX_FILE_DRAM (-1)

#define GFX_TEXT_NORMAL 0
#define GFX_TEXT_FAST   1

typedef enum
{
  GFX_MODE_FILTER,
  GFX_MODE_COMBINE,
  GFX_MODE_COLOR,
  GFX_MODE_DROPSHADOW,
  GFX_MODE_TEXT,
  GFX_MODE_ALL,
} GfxMode;

typedef struct
{
    u32 vaddr;
    void* data;
} Texldr;

typedef struct
{
    u8 imageFormat;
    u8 imageSize;
    u32 address;
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    u32 vaddr;
    size_t size;
} Texdesc;

/* data types and structures */
typedef u8   qu08_t;
typedef u16  qu016_t;
typedef s16   qs48_t;
typedef s16   qs510_t;
typedef u16  qu510_t;
typedef s16   qs102_t;
typedef u16  qu102_t;
typedef s16   qs105_t;
typedef u16  qu105_t;
typedef s16   qs132_t;
typedef s16   qs142_t;
typedef s32   qs1516_t;
typedef s32   qs1616_t;
typedef s32   qs205_t;

typedef u16  g_bglt_t;
typedef u8   g_ifmt_t;
typedef u8   g_isiz_t;
typedef u16  g_bgf_t;
typedef u8   g_objf_t;
typedef u32  g_objlt_t;

/* fixed-point conversion macros */
#define qu08(n)                       ((qu08_t)((n)*0x100))
#define qu016(n)                      ((qu016_t)((n)*0x10000))
#define qs48(n)                       ((qs48_t)((n)*0x0100))
#define qs510(n)                      ((qs510_t)((n)*0x0400))
#define qu510(n)                      ((qu510_t)((n)*0x0400))
#define qs102(n)                      ((qs102_t)((n)*0x0004))
#define qu102(n)                      ((qu102_t)((n)*0x0004))
#define qs105(n)                      ((qs105_t)((n)*0x0020))
#define qu105(n)                      ((qu105_t)((n)*0x0020))
#define qs132(n)                      ((qs132_t)((n)*0x0004))
#define qs142(n)                      ((qs142_t)((n)*0x0004))
#define qs1516(n)                     ((qs1516_t)((n)*0x00010000))
#define qs1616(n)                     ((qs1616_t)((n)*0x00010000))
#define qs205(n)                      ((qs205_t)((n)*0x00000020))

/* private helper macros */
#define gI_(i)                        ((u32)(i))
#define gL_(l)                        ((u64)(l))
#define gF_(i,n,s)                    ((gI_(i)&((gI_(1)<<(n))-1))<<(s))
#define gFL_(l,n,s)                   ((gL_(l)&((gL_(1)<<(n))-1))<<(s))
#define gO_(opc,hi,lo)                ((Gfx){gF_(opc,8,24)|gI_(hi),gI_(lo)})
#define gD_(gdl,m,...)                gDisplayListPut(gdl,m(__VA_ARGS__))

#define GPACK_RGBA8888(r,g,b,a)       (gF_(r,8,24)|gF_(g,8,16)|               \
                                       gF_(b,8,8)|gF_(a,8,0))
#define G_SIZ_BITS(siz)               (4<<gI_(siz))                                  
#endif
