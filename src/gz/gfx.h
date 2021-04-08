#ifndef GFX_H
#define GFX_H

#include <ultra64.h>
#include <ultra64/gbi.h>

#define GFX_FILE_DRAM (-1)
#define GFX_TEXT_NORMAL 0
#define GFX_TEXT_FAST   1

#define gfx_disp(x)   {Gfx gfx_disp__[]={x};                      \
                         GZGfx_DispAppend(gfx_disp__,sizeof(gfx_disp__));}

typedef u8 g_ifmt_t;
typedef u8 g_isiz_t;

typedef enum GfxMode 
{
  GFX_MODE_FILTER,
  GFX_MODE_COMBINE,
  GFX_MODE_COLOR,
  GFX_MODE_DROPSHADOW,
  GFX_MODE_TEXT,
  GFX_MODE_ALL
} GfxMode;

typedef struct TexDesc {
    g_ifmt_t im_fmt;
    g_isiz_t im_siz;
    u32 address;
    s16 tileWidth;
    s16 tileHeight;
    s16 tilesX;
    s16 tilesY;
    u32 fileVaddr;
    size_t fileVSize;
} TexDesc;

typedef struct TexLdr {
    u32 fileVaddr;
    void* fileData;
} TexLdr;

typedef struct GfxTexture {
    g_ifmt_t im_fmt;
    g_isiz_t im_siz;
    void* data;
    s16 tileWidth;
    s16 tileHeight;
    s16 tilesX;
    s16 tilesY;
    size_t tileSize;
} GfxTexture;

typedef struct GfxSprite {
    GfxTexture* texture;
    s16 textureTile;
    f32 x;
    f32 y;
    f32 xScale;
    f32 yScale;
} GfxSprite;

typedef struct GfxFont {
    GfxTexture* texture;
    s16 charWidth;
    s16 charHeight;
    s16 charsXTile;
    s16 charsYTile;
    u8 codeStart;
    s16 letterSpacing;
    s16 lineSpacing;
    s16 baseline;
    s16 median;
    s16 x;
} GfxFont;

typedef struct GrcTexture {
    g_ifmt_t im_fmt;
    g_isiz_t im_siz;
    u16 imageWidth;
    u16 imageHeight;
    u16 tileWidth;
    u16 tileHeight;
    u16 tilesX;
    u16 tilesY;
    u16 pad;
    char textureData[];
} GrcTexture;

#define gI(i)                        ((u32)(i))
#define gL(l)                        ((u64)(l))
#define gF(i,n,s)                    ((gI(i)&((gI(1)<<(n))-1))<<(s))
#define gFL(l,n,s)                   ((gL(l)&((gL(1)<<(n))-1))<<(s))
#define G_SIZ_BITS(siz)               (4<<gI(siz))
#define GPACK_RGBA8888(r,g,b,a)       (gF(r,8,24)|gF(g,8,16)|               \
                                       gF(b,8,8)|gF(a,8,0))
#define GPACK_RGB24A8(rgb,a)          (gF(rgb,24,8)|gF(a,8,0))

#define G_CC_LERP(a0,b0,c0,d0,Aa0,  \
                  Ab0,Ac0,Ad0,a1,   \
                  b1,c1,d1,Aa1,     \
                  Ab1,Ac1,Ad1)        (gFL(G_CCMUX_##a0,4,52)|               \
                                       gFL(G_CCMUX_##c0,5,47)|               \
                                       gFL(G_ACMUX_##Aa0,3,44)|              \
                                       gFL(G_ACMUX_##Ac0,3,41)|              \
                                       gFL(G_CCMUX_##a1,4,37)|               \
                                       gFL(G_CCMUX_##c1,5,32)|               \
                                       gFL(G_CCMUX_##b0,4,28)|               \
                                       gFL(G_CCMUX_##b1,4,24)|               \
                                       gFL(G_ACMUX_##Aa1,3,21)|              \
                                       gFL(G_ACMUX_##Ac1,3,18)|              \
                                       gFL(G_CCMUX_##d0,3,15)|               \
                                       gFL(G_ACMUX_##Ab0,3,12)|              \
                                       gFL(G_ACMUX_##Ad0,3,9)|               \
                                       gFL(G_CCMUX_##d1,3,6)|                \
                                       gFL(G_ACMUX_##Ab1,3,3)|               \
                                       gFL(G_ACMUX_##Ad1,3,0))
#define G_CC_MODE(mode1,mode2)        G_CC_LERP(mode1,mode2)

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
typedef u16  g_bgFt;
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

s32 Gfx_FontXHeight(const GfxFont *font);
void GZGfx_ModeSet(GfxMode mode, u64 value);
void GZGfx_SpriteDraw(const GfxSprite *sprite);
void GZGfx_ModeReplace(GfxMode mode, u64 value);
void GZGfx_ModePop(GfxMode mode);
void Gfx_Printf(const GfxFont *font, s32 x, s32 y,
                const char *format, ...);
GfxTexture* GZGfx_TextureLoad(const TexDesc* texDesc, GfxTexture* texture);

#define gO(opc, hi, lo)   ((Gfx){gF(opc, 8, 24) | gI(hi), gI(lo)})

#define gsTexRect(ulx, uly, lrx, lry, tile) \
        gO( \
                G_TEXRECT, \
                gF(lrx, 12, 12) | \
                gF(lry, 12, 0), \
                gF(tile, 3, 24) | \
                gF(ulx, 12, 12) | \
                gF(uly, 12, 0))

#define gsDPHalf1(wordhi) \
        gO(G_RDPHALF_1, 0, wordhi)

#define gsDPHalf2(wordlo) \
        gO(G_RDPHALF_2, 0, wordlo)

#define gScC(c) ((c) < 0 ? 0 : (c))
#define gScD(t, c, d) \
        ( \
                (c) < 0 ? \
                ( \
                        (d) < 0 ? \
                                (t) + (c) * (d) / 0x80 : \
                                (t) - (c) * (d) / 0x80 \
                ) : \
                (t) \
        )

#define gsSPScisTextureRectangle(ulx, uly, lrx, lry, tile, s, t, dsdx, dtdy) \
        gsTexRect(gScC(ulx), gScC(uly), gScC(lrx), gScC(lry), tile), \
        gsDPHalf1( \
                gF(gScD(s, ulx, dsdx), 16, 16) | \
                gF(gScD(t, uly, dtdy), 16, 0)), \
        gsDPHalf2(gF(dsdx, 16, 16) | gF(dtdy, 16, 0))
    
#endif
