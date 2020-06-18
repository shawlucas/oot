#include "gfx.h"
#include "gz_gfx.h"
#include "gz/vector.h"
#include <ultra64.h>
#include <global.h>
#include <math.h>

#define GFX_DISP_SIZE 0x10000
static Gfx* gfxDisp;
static Gfx* gfxDispWork;
static Gfx* gfxDispPoly;
static Gfx* gfxDispD;

#define GFX_STACK_LENGTH 8
static u64 sGfxModes[GFX_MODE_ALL];
static u64 sGfxModeStack[GFX_MODE_ALL][GFX_STACK_LENGTH];
static s32 sGfxModeStackPos[GFX_MODE_ALL];

#define CHAR_TILE_MAX 8

typedef struct
{
    s32 tileChar;
    u32 color;
    s32 x;
    s32 y;
} GfxChar;
static u8 sGfxSynced;

static const Font* sGfxCharFont;
static Vector sGfxChars[CHAR_TILE_MAX];

static void Gfx_Sync(void)
{
    if (!sGfxSynced)
    {
        gDPPipeSync(gfxDispPoly++);
        sGfxSynced = 1;
    }
}

const MtxF sGfxCmDesaturate = 
{
    0.3086f, 0.6094f, 0.0820f, 0.f,
    0.3086f, 0.6094f, 0.0820f, 0.f,
    0.3086f, 0.6094f, 0.0820f, 0.f,
    0.0f,    0.0f,    0.0f,    1.0f,
};

void Gfx_Start(void)
{
    s32 i;
    for (i = 0; i < CHAR_TILE_MAX; ++i)
        Vector_Init(&sGfxChars[i], sizeof(GfxChar));
    gfxDisp = ZeldaArena_MallocDebug(GFX_DISP_SIZE, "../gfx.c", 55);
    gfxDispWork = ZeldaArena_MallocDebug(GFX_DISP_SIZE, "../gfx.c", 56);
    gfxDispPoly = gfxDisp;
    gfxDispD = gfxDisp + (GFX_DISP_SIZE + sizeof(*gfxDisp) - 1) /
               sizeof(*gfxDisp);
}

void Gfx_ModeInit(void)
{
    Gfx_Sync();
    static Gfx modeInit[] = {
        gsSPLoadGeometryMode(0),
        gsDPSetCycleType(G_CYC_1CYCLE),
        gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
        gsDPSetScissor(G_SC_NON_INTERLACE,
                       0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
        gsDPSetAlphaDither(G_AD_DISABLE),
        gsDPSetColorDither(G_CD_DISABLE),
        gsDPSetAlphaCompare(G_AC_NONE),
        gsDPSetDepthSource(G_ZS_PRIM),
        gsDPSetCombineKey(G_CK_NONE),
        gsDPSetTextureConvert(G_TC_FILT),
        gsDPSetTextureDetail(G_TD_CLAMP),
        gsDPSetTexturePersp(G_TP_NONE),
        gsDPSetTextureLOD(G_TL_TILE),
        gsDPSetTextureLUT(G_TT_NONE),
        gsDPPipelineMode(G_PM_NPRIMITIVE),
        gsSPEndDisplayList(),
    };
    gSPDisplayList(gfxDispPoly++, modeInit);
    Gfx_ModeApply(GFX_MODE_ALL);
}

void Gfx_ModeConfigure(GfxMode mode, u64 value)
{
    sGfxModes[mode] = value;
}

void Gfx_ModeApply(GfxMode mode)
{
    size_t s;
    Gfx dl[GFX_MODE_ALL];
    Gfx* pdl = dl;
    switch (mode) {
        case GFX_MODE_ALL:
        case GFX_MODE_FILTER: {
            gDPSetTextureFilter(pdl++, sGfxModes[GFX_MODE_FILTER]);
            if (mode != GFX_MODE_ALL)
                break;
        }
        case GFX_MODE_COMBINE: {
          //  gDPSetCombine(pdl++, sGfxModes[GFX_MODE_COMBINE]);
            if (mode != GFX_MODE_ALL)
                break;
        }

        case GFX_MODE_COLOR: {
            u32 c = sGfxModes[GFX_MODE_COLOR];
            gDPSetPrimColor(pdl++, 0, 0, (c >> 24) & 0xFF, (c >> 16) & 0xFF,
                                   (c >> 8)  & 0xFF, (c >> 0)  & 0xFF);
            if (mode != GFX_MODE_ALL)
                break;
        }
        default:
            break;
    }
    s = pdl - dl;
    if (s > 0)
    {
        Gfx_Sync();
        memcpy(gfxDispPoly, dl, s * sizeof(*dl));
        gfxDispPoly += s;
    }
}

void Gfx_ModeSet(GfxMode mode, u64 value)
{
    Gfx_ModeConfigure(mode, value);
    Gfx_ModeApply(mode);
}

void Gfx_ModePush(GfxMode mode)
{
    s32 i;
    if (mode == GFX_MODE_ALL)
    {
        for (i = 0; i < GFX_MODE_ALL; ++i)
        {
            s32* p = &sGfxModeStackPos[i];
            sGfxModeStackPos[i][*p] = sGfxModes[i];
            *p = (*p + 1) % GFX_STACK_LENGTH;
        }
    }
    else {
        s32* p = &sGfxModeStackPos[mode];
        sGfxModeStack[mode][*p] = sGfxModes[mode];
        *p = (*p + 1) % GFX_STACK_LENGTH;
    }
}

void Gfx_ModePop(GfxMode mode)
{
    s32 i;
    if (mode == GFX_MODE_ALL)
    {
        for (i = 0; i < GFX_MODE_ALL; ++i)
        {
            s32* p = &sGfxModeStackPos[i];
            *p = (*p + GFX_STACK_LENGTH - 1) % GFX_STACK_LENGTH;
            Gfx_ModeSet(i, sGfxModeStack[i][*p]);
        }
    } else {
        s32* p = &sGfxModeStackPos[mode];
        *p = (*p + GFX_STACK_LENGTH - 1) % GFX_STACK_LENGTH;
        Gfx_ModeSet(mode, sGfxModeStack[mode][*p]);
    }
}

void Gfx_ModeReplace(GfxMode mode, u64 value)
{
    Gfx_ModePush(mode);
    Gfx_ModeConfigure(mode, value);
    Gfx_ModeApply(mode);
}

Gfx* Gfx_DispAppend(Gfx* disp, size_t size)
{
    Gfx* p = gfxDispPoly;
    memcpy(gfxDispPoly, disp, size);
    gfxDispPoly += (size + sizeof(*gfxDispPoly) - 1) / sizeof(*gfxDispPoly);
    sGfxSynced = 0;
    return p;
}

void* Gfx_DataAppend(void* data, size_t size)
{
    gfxDispD -= (size + sizeof(*gfxDispD) - 1) / sizeof(*gfxDispD);
    memcpy(gfxDispD, data, size);
    return gfxDispD;
}

void Gfx_Flush(GlobalContext* globalCtx)
{
    Gfx* dispW;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    gSPEndDisplayList(gfxDispPoly++);
    Cache_WritebackData(gfxDisp, GFX_DISP_SIZE);
    gSPDisplayList(gfxCtx->overlay.p++, gfxDisp);
    dispW = gfxDispWork;
    gfxDisp = dispW;
    gfxDispPoly = gfxDisp;
    gfxDispD = gfxDisp + (GFX_DISP_SIZE + sizeof(*gfxDisp) - 1) /
                sizeof(*gfxDisp);
    sGfxSynced = 0;
}

void Gfx_TexldrInit(Texldr* texldr)
{
    texldr->vaddr = GFX_FILE_DRAM;
    texldr->data = NULL;
}

Texture* Gfx_TexldrLoad(Texldr* texldr, const Texdesc* texdesc, Texture* texture)
{
    size_t textureSize;
    void* textureData;
    void* fileStart;
    Texture* newTexture = NULL;
    if (!texture)
    {
        newTexture = ZeldaArena_MallocDebug(sizeof(*newTexture), "../gfx.c", 222);
        if (!newTexture)
            return newTexture;
        texture = newTexture;
    }
    texture->imageFormat = texdesc->imageFormat;
    texture->imageSize = texdesc->imageSize;
    texture->width = texdesc->width;
    texture->height = texdesc->height;
    texture->x = texdesc->x;
    texture->y = texdesc->y;
    texture->tsize = (texture->width * texture->height *
                    G_SIZ_BITS(texture->imageSize) + 63) / 64 * 8;
    textureSize = texture->tsize * texture->x * texture->y;
    textureData = NULL;
    fileStart = NULL;
    if (texdesc->vaddr != GFX_FILE_DRAM)
    {
        if (texldr->vaddr != texdesc->vaddr)
        {
            if (texldr->data)
            {
                ZeldaArena_FreeDebug(texldr->data, "../gfx.c", 247);
            }
            texldr->data = ZeldaArena_MallocDebug(texdesc->size, "../gfx.c", 249);
            if (!texldr->data)
            {
                texldr->vaddr = GFX_FILE_DRAM;
                if (newTexture)
                    ZeldaArena_FreeDebug(newTexture, "../gfx.c", 254);
                return NULL;
            }
            texldr->vaddr = texdesc->vaddr;
            Utils_GetFile(texldr->vaddr, texldr->data, texdesc->size);
        }
        if (texdesc->size == textureSize)
        {
            textureData = texldr->data;
            texldr->vaddr = GFX_FILE_DRAM;
            texldr->data = NULL;
        } else 
            fileStart = texldr->data;
    }
    if (!textureData)
    {
        textureData = ZeldaArena_MallocDebug(textureSize, "../gfx.c", 270);
        if (!textureData)
        {
            if (newTexture)
                ZeldaArena_FreeDebug(newTexture, "../gfx.c", 274);
            return NULL;
        }
        memcpy(textureData, (char*)fileStart + texdesc->address, textureSize);
    }
    texture->data = textureData;
    return texture;
}

void Gfx_TexldrDestroy(Texldr* texldr)
{
    if (texldr->data)
    {
        ZeldaArena_FreeDebug(texldr->data, "../gfx.c", 287);
    }
}

Texture* Gfx_TextureCreate(u8 format, u8 size, s32 width, s32 height,
                          s32 x, s32 y)
{
    Texture* texture = ZeldaArena_MallocDebug(sizeof(*texture), "../gfx.c", 294);
    if (!texture)
        return texture;
    texture->tsize = (width * height * G_SIZ_BITS(size) + 63) / 64 * 8;
    texture->data = ZeldaArena_MallocDebug(x * y * texture->tsize, "../gfx.c", 298);
    if (!texture->data) {
        ZeldaArena_FreeDebug(texture, "../gfx.c", 300);
        return NULL;
    }
    texture->imageFormat = format;
    texture->imageSize = size;
    texture->width = width;
    texture->height = height;
    texture->x = x;
    texture->y = y;
    return texture;
}

Texture* Gfx_TextureLoad(const Texdesc* texdesc, Texture* texture)
{
    Texldr texldr;
    Gfx_TexldrInit(&texldr);
    texture = Gfx_TexldrLoad(&texldr, texdesc, texture);
    Gfx_TexldrDestroy(&texldr);
    return texture;
}

void Gfx_TextureDestroy(Texture* texture)
{
    if (texture->data)
        ZeldaArena_FreeDebug(texture->data, "../gfx.c", 324);
}

void Gfx_TextureFree(Texture* texture)
{
    Gfx_TextureDestroy(texture);
    ZeldaArena_FreeDebug(texture, "../gfx.c", 330);
}

void* Gfx_TextureData(Texture* texture, s16 tile)
{
    return (char*)texture->data + texture->tsize * tile;
}

Texture* Gfx_TextureCopy(const Texture* src, Texture* dest)
{
    void* textureData;
    size_t textureSize;
    Texture* newTexture = NULL;

    if (!dest)
    {
        newTexture = ZeldaArena_MallocDebug(sizeof(*newTexture), "../gfx.c", 346);
        if (!textureData)
        {
            if (newTexture)
                ZeldaArena_FreeDebug(newTexture, "../gfx.c", 350);
            return NULL;
        }
        *dest = *src;
        dest->data = textureData;
        memcpy(dest->data, src->data, textureSize);
        return dest;
    }
}

void Gfx_TextureCopyTile(Texture* dest, s32 destTile, const Texture* src,
                        s32 srcTile, u8 blend)
{
    size_t tilePixels;
    Color_RGBA8_n* pDest;
    Color_RGBA8_n* pSrc;
    size_t i;
    if (src->imageFormat != G_IM_FMT_RGBA || src->imageSize != G_IM_SIZ_32b ||
        dest->imageFormat != src->imageFormat || dest->imageSize != src->imageSize ||
        dest->width != src->width ||
        dest->height != src->height)
    {
        return;
    }

    tilePixels = src->width * src->height;
    pDest = Gfx_TextureData(dest, destTile);
    pSrc = Gfx_TextureData(src, srcTile);

    for (i = 0; i < tilePixels; ++i)
    {
        if (blend)
        {
            pDest->r = pDest->r + (pSrc->r - pDest->r) * pSrc->a / 0xFF;
            pDest->g = pDest->g + (pSrc->g - pDest->g) * pSrc->a / 0xFF;
            pDest->b = pDest->b + (pSrc->b - pDest->b) * pSrc->a / 0xFF;
            pDest->a = pSrc->a + (0xFF - pSrc->a) * pDest->a / 0xFF;
        }
        else
        {
            *pDest = *pSrc;
        }
        ++pDest;
        ++pSrc;
    }

}

void Gfx_TextureColorTransform(Texture* texture, MtxF* mf)
{
    size_t texturePixels;
    Color_RGBA8_n* pixelData;
    MtxF m;
    size_t i;
    if (texture->imageFormat != G_IM_FMT_RGBA || texture->imageSize != G_IM_SIZ_32b)
        return;
    pixelData = texture->data;
    m = *mf;
    for (i = 0; i < texturePixels; ++i)
    {
        Color_RGBA8_n p = pixelData[i];
        f32 r = p.r * m.xx + p.g * m.xy + p.b * m.xz + p.a * m.xw;
        f32 g = p.r * m.yx + p.g * m.yy + p.b * m.yz + p.a * m.yw;
        f32 b = p.r * m.zx + p.g * m.zy + p.b * m.zz + p.a * m.zw;
        f32 a = p.r * m.wx + p.g * m.wy + p.b * m.wz + p.a * m.ww;
        Color_RGBA8_n n = {
                r < 0x00 ? 0x00 : r > 0xFF ? 0xFF : r,
                g < 0x00 ? 0x00 : g > 0xFF ? 0xFF : g,
                b < 0x00 ? 0x00 : b > 0xFF ? 0xFF : b,
                a < 0x00 ? 0x00 : a > 0xFF ? 0xFF : a,
            };
        pixelData[i] = n;
    }
    
}

void Gfx_DispRDPLoadTile(Gfx** dlist, Texture* texture, s16 textureTile)
{
    if (texture->imageSize == G_IM_SIZ_4b)
    {
        gDPLoadTextureTile_4b((*dlist)++,
                              Gfx_TextureData(texture, textureTile),
                              texture->imageFormat,
                              texture->width, texture->height,
                              0, 0,
                              texture->width - 1, texture->height - 1,
                              0,
                              G_TX_NOMIRROR | G_TX_WRAP,
                              G_TX_NOMIRROR | G_TX_WRAP,
                              G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPLoadTextureTile((*dlist)++,
                            Gfx_TextureData(texture, textureTile),
                            texture->imageFormat, texture->imageSize, 
                            texture->width, texture->height,
                            0, 0,
                            texture->width - 1, texture->height - 1,
                            0,
                            G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
    }
}

void Gfx_RDPLoadTile(const Texture* texture, s16 textureTile)
{
    Gfx_DispRDPLoadTile(&gfxDispPoly, texture, textureTile);
    sGfxSynced = 1;
}

void Gfx_SpriteDraw(const Sprite* sprite)
{
    u8 a;
    Texture* texture = sprite->texture;
    Gfx_RDPLoadTile(texture, sprite->textureTile);
    if (sGfxModes[GFX_MODE_DROPSHADOW])
    {
        a = sGfxModes[GFX_MODE_COLOR] & 0xFF;
        a = a * a / 0xFF;
        Gfx_ModeReplace(GFX_MODE_COLOR, GPACK_RGBA8888(0x00, 0x00, 0x00, a));
        gSPScisTextureRectangle(gfxDispPoly++,
                            qs102(sprite->x + 1) & ~3,
                            qs102(sprite->y + 1) & ~3,
                            qs102(sprite->x + texture->width *
                                  sprite->xScale + 1) & ~3,
                            qs102(sprite->y + texture->height *
                                  sprite->yScale + 1) & ~3,
                            G_TX_RENDERTILE,
                            qu105(0), qu105(0),
                            qu510(1.f / sprite->xScale),
                            qu510(1.f / sprite->yScale));
        Gfx_ModePop(GFX_MODE_COLOR);
    }
    Gfx_Sync();
    gSPScisTextureRectangle(gfxDispPoly++,
                          qs102(sprite->x) & ~3,
                          qs102(sprite->y) & ~3,
                          qs102(sprite->x + texture->width *
                                sprite->xScale) & ~3,
                          qs102(sprite->y + texture->height *
                                sprite->yScale) & ~3,
                          G_TX_RENDERTILE,
                          qu105(0), qu105(0),
                          qu510(1.f / sprite->xScale),
                          qu510(1.f / sprite->yScale));
    sGfxSynced = 0;
}

s32 Gfx_FontXHeight(const Font* font)
{
    return font->baseline - font->median;
}

void Gfx_Printf(const Font* font, s32 x, s32 y, const char* format, ...)
{
    if (sGfxModes[GFX_MODE_TEXT] == GFX_TEXT_NORMAL)
    {
        va_list args;
        va_start(args, format);
        Gfx_PrintfNVa(font, x, y, format, args);
        va_end(args);
    } else if (sGfxModes[GFX_MODE_TEXT] == GFX_TEXT_FAST) {
        va_list args;
        va_start(args, format);
        Gfx_PrintfFVa(font, x, y, format, args);
        va_end(args);
    }
}

void Gfx_PrintfN(const Font* font, s32 x, s32 y, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    Gfx_PrintfFVa(font, x, y, format, args);
    va_end(args);
}

static void DrawChars(const Font* font, s32 x, s32 y, const char* buf, size_t l)
{
    Texture* texture;
    s32 charsPerTile;
    s32 nTiles;
    s32 nChars;
    s32 i;
    s32 j;
    x -= font->x;
    y -= font->baseline;
    texture = font->texture;
    charsPerTile = font->charXtile * font->charYtile;
    nTiles = texture->x * texture->y;
    nChars = charsPerTile * nTiles;
    for (i = 0; i < nTiles; ++i)
    {
        s32 tileBegin = charsPerTile * i;
        s32 tileEnd = tileBegin + charsPerTile;
        u8 tileLoaded = 0;
        s32 cx = 0;
        s32 cy = 0;
        for (j = 0; j < l; ++j, cx += font->charWidth + font->letterSpacing)
        {
            u8 c = buf[j];
            if (c < font->codeStart || c >= font->codeStart + nChars)
                continue;
            c -= font->codeStart;
            if (c < tileBegin || c >= tileEnd)
                continue;
            c -= tileBegin;
            if (!tileLoaded)
            {
                tileLoaded = 1;
                Gfx_RDPLoadTile(texture, i);
            }
            gSPScisTextureRectangle(gfxDispPoly++,
                              qs102(x + cx),
                              qs102(y + cy),
                              qs102(x + cx + font->charWidth),
                              qs102(y + cy + font->charHeight),
                              G_TX_RENDERTILE,
                              qu105(c % font->charXtile *
                                    font->charWidth),
                              qu105(c / font->charXtile *
                                    font->charHeight),
                              qu510(1), qu510(1));

        }
    }
    sGfxSynced = 0;
}

static void FlushChars(void)
{
    s32 i;
    s32 j;
    const Font* font = sGfxCharFont;
    u32 color = 0;
    u8 first = 1;

    for (i = 0; i < CHAR_TILE_MAX; ++i)
    {
        Vector* tileVect = &sGfxChars[i];
        for (j = 0; j < tileVect->size; ++j)
        {
            GfxChar* gc = Vector_At(tileVect, j);
            if (j == 0)
                Gfx_RDPLoadTile(font->texture, i);
            if (first || color != gc->color) {
                color = gc->color;
                Gfx_Sync();
                gDPSetPrimColor(gfxDispPoly++, 0, 0,
                                (color >> 24) & 0xFF,
                                (color >> 16) & 0xFF,
                                (color >> 8) & 0xFF,
                                (color >> 0) & 0xFF);
            }
            first = 0;
            gSPScisTextureRectangle(gfxDispPoly++,
                              qs102(gc->x),
                              qs102(gc->y),
                              qs102(gc->x + font->charWidth),
                              qs102(gc->y + font->charHeight),
                              G_TX_RENDERTILE,
                              qu105(gc->tileChar % font->charXtile *
                                    font->charWidth),
                              qu105(gc->tileChar / font->charXtile *
                                    font->charHeight),
                              qu510(1), qu510(1));
            sGfxSynced = 0;
        }
        Vector_Clear(tileVect);
    }

}

static void Gfx_PrintfNVa(const Font* font, s32 x, s32 y,
                          const char* format, va_list args)
{
    char buf[1024];
    const size_t bufsize = 1024;
    
}