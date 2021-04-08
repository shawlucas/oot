#include <global.h>
#include <alloca.h>
#include "gfx.h"
#include "zu.h"
#include "../libgz/vector.h"

#define GFX_DISP_SIZE 0x10000

static Gfx* sGfxDisp;
static Gfx* sGfxDispW;
static Gfx* sGfxDispP;
static Gfx* sGfxDispD;

#define GFX_STACK_LENGTH 8

static u64 sGfxModes[GFX_MODE_ALL];
static u64 sGfxModeStack[GFX_MODE_ALL][GFX_STACK_LENGTH];
static s32 sGfxModeStackPos[GFX_MODE_ALL];
static u8 sGfxSynced;

#define CHAR_TILE_MAX 8

typedef struct GfxChar {
    s32 tileChar;
    u32 color;
    s32 x;
    s32 y;
} GfxChar;

static const GfxFont* sGfxCharFont;
static struct vector sGfxChars[CHAR_TILE_MAX];

static void draw_chars(const GfxFont* font, s32 x, s32 y, const char* buf, size_t l);
static void flush_chars(void);
static void Gfx_PrintFNVa(const GfxFont* font, s32 x, s32 y, const char* format, va_list args);
static void Gfx_PrintFFVa(const GfxFont* font, s32 x, s32 y, const char* format, va_list args);

s32 vsnprintf(char* dst, size_t size, const char* fmt, va_list args) {
    char* buf = NULL;

    s32 ret = _Printf(proutSprintf, &buf, fmt, args);

    if (buf == NULL) {
        return -1;
    }

    ret = strlen(buf);
    if (size > 0) {
        if ((long)size > ret) {
            memcpy(dst, buf, ret + 1);
        } else {
            memcpy(dst, buf, size - 1);
            dst[size - 1] = 0;
        }
    }
    if (ret > -1) {
        dst[ret] = 0;
    }
    return ret;
}


static void gfx_sync(void) {
    if (!sGfxSynced) {
        gDPPipeSync(sGfxDispP++);
        sGfxSynced = true;
    }
}

const MtxF gGfxCmDesaturate = { 0.3086f, 0.6094f, 0.820f, 0.0f,
                                0.3086f, 0.6094f, 0.820f, 0.0f,
                                0.3086f, 0.6094f, 0.820f, 0.0f,
                                0.0f,    0.0f,    0.0f,   1.0f,
};

void GZGfx_Start(void) {
    s32 i;

    for (i = 0; i < CHAR_TILE_MAX; ++i) {
        vector_init(&sGfxChars[i], sizeof(GfxChar));
    }

    sGfxDisp = DebugArena_MallocDebug(GFX_DISP_SIZE, __FILE__, __LINE__);
    sGfxDispW = DebugArena_MallocDebug(GFX_DISP_SIZE, __FILE__, __LINE__);
    sGfxDispP = sGfxDisp;
    sGfxDispD = sGfxDisp + (GFX_DISP_SIZE + sizeof(*sGfxDisp) - 1) / sizeof(*sGfxDisp);
}

void GZGfx_ModeApply(GfxMode mode);

void GZGfx_Mode_Init(void) {
        
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
    gfx_sync();
    gSPDisplayList(sGfxDispP++, modeInit);
    GZGfx_ModeApply(GFX_MODE_ALL);
}

void GZGfx_ModeConfigure(GfxMode mode, u64 value) {
    sGfxModes[mode] = value;
}


void GZGfx_ModeApply(GfxMode mode) {
    size_t s;
    Gfx dList[GFX_MODE_ALL];
    Gfx* gfxP = dList;
    
    switch (mode) {
        case GFX_MODE_ALL:
        case GFX_MODE_FILTER:
        {
            gDPSetTextureFilter(gfxP++, sGfxModes[GFX_MODE_FILTER]);
            if (mode != GFX_MODE_ALL) {
                break;
            }
        }
        
        case GFX_MODE_COMBINE:
        {
            gDPSetCombine(gfxP++, sGfxModes[GFX_MODE_COMBINE] << 0x20, sGfxModes[GFX_MODE_COMBINE] & 0xFFFFFFFF);
            if (mode != GFX_MODE_ALL) {
                break;
            }
        }
        
       case GFX_MODE_COLOR:
       {
           u32 c = sGfxModes[GFX_MODE_COLOR];
           gDPSetPrimColor(gfxP++, 0, 0, (c >> 24) & 0xFF, (c >> 16) & 0xFF, (c >> 8) & 0xFF, (c >> 0) & 0xFF);
           if (mode != GFX_MODE_ALL) {
               break;
           }
       }
       default:
        break;
    }

    s = gfxP - dList;

    if (s > 0) {
        gfx_sync();
        memcpy(sGfxDispP, dList, s * sizeof(*dList));
        sGfxDispP += s;
    }
}

void GZGfx_ModeSet(GfxMode mode, u64 value) {
    GZGfx_ModeConfigure(mode, value);
    GZGfx_ModeApply(mode);
}

void GZGfx_ModePush(GfxMode mode) {
    s32 i;

    if (mode == GFX_MODE_ALL) {
        for (i = 0; i < GFX_MODE_ALL; ++i) {
            s32* p = &sGfxModeStackPos[i];
            sGfxModeStack[i][*p] = sGfxModes[i];
            *p = (*p + 1) % GFX_STACK_LENGTH;
        }
    } else {
        s32* p = &sGfxModeStackPos[mode];
        sGfxModeStack[mode][*p] = sGfxModes[mode];
        *p = (*p + 1) % GFX_STACK_LENGTH;
    }
}

void GZGfx_ModePop(GfxMode mode) {
    s32 i;

    if (mode == GFX_MODE_ALL) {
        for (i = 0; i < GFX_MODE_ALL; ++i) {
            s32* p = &sGfxModeStackPos[i];
            *p = (*p + GFX_STACK_LENGTH - 1) % GFX_STACK_LENGTH;
            GZGfx_ModeSet(i, sGfxModeStack[i][*p]);
        }
    } else {
        s32* p = &sGfxModeStackPos[mode];
        *p = (*p + GFX_STACK_LENGTH - 1) % GFX_STACK_LENGTH;
        GZGfx_ModeSet(mode, sGfxModeStack[mode][*p]);
    }
}

void GZGfx_ModeReplace(GfxMode mode, u64 value) {
    GZGfx_ModePush(mode);
    GZGfx_ModeConfigure(mode, value);
    GZGfx_ModeApply(mode);
}

Gfx* GZGfx_DispAppend(Gfx* gfx, size_t size) {
    Gfx* gfxP = sGfxDispP;
    
    memcpy(sGfxDispP, gfx, size);
    sGfxDispP += (size + sizeof(*sGfxDispP) - 1) / sizeof(*sGfxDispP);
    sGfxSynced = 0;
    return gfxP;
}

void* GZGfx_DataAppend(void* data, size_t size) {
    sGfxDispD -= (size + sizeof(*sGfxDispD) - 1) / sizeof(*sGfxDispD);
    memcpy(sGfxDispD, data, size);
    return sGfxDispD;
}

void GZGfx_Flush(GlobalContext* globalCtx) {

    Gfx* dispW;

    OPEN_DISPS(globalCtx->state.gfxCtx, __FILE__, __LINE__);
    flush_chars();
    gSPEndDisplayList(sGfxDispP++);
    dcache_wb(sGfxDisp, GFX_DISP_SIZE);
    gSPDisplayList(OVERLAY_DISP++, sGfxDisp);

    dispW = sGfxDispW;
    sGfxDispW = sGfxDisp;
    sGfxDisp = dispW;
    sGfxDispP = sGfxDisp;
    sGfxDispD = sGfxDisp + (GFX_DISP_SIZE + sizeof(*sGfxDisp) - 1) / sizeof(*sGfxDisp);

    sGfxSynced = false;

    CLOSE_DISPS(globalCtx->state.gfxCtx, __FILE__, __LINE__);
}

void GZGfx_TexLdrInit(TexLdr* texLdr) {
    texLdr->fileVaddr = GFX_FILE_DRAM;
    texLdr->fileData = NULL;
}

GfxTexture* GZGfx_TexLdrLoad(TexLdr* texLdr, const TexDesc* texDesc, GfxTexture* texture) {
    GfxTexture* newTexture;
    size_t textureSize;
    void* textureData;
    void* fileStart;

    newTexture = NULL;

    if (texture == NULL) {
        newTexture = DebugArena_MallocDebug(sizeof(*newTexture), __FILE__, __LINE__);
        if (newTexture == NULL) {
            return newTexture;
        }
        texture = newTexture;
    }

    texture->im_fmt = texDesc->im_fmt;
    texture->im_siz = texDesc->im_siz;
    texture->tileWidth = texDesc->tileWidth;
    texture->tileHeight = texDesc->tileHeight;
    texture->tilesX = texDesc->tilesX;
    texture->tilesY = texDesc->tilesY;
    texture->tileSize = (texture->tileWidth * texture->tileHeight * G_SIZ_BITS(texture->im_siz) + 63) / 64 * 8;

    textureSize = texture->tileSize * texture->tilesX * texture->tilesY;

    textureData = NULL;
    fileStart = NULL;

    if (texDesc->fileVaddr != GFX_FILE_DRAM) {
        if (texLdr->fileVaddr != texDesc->fileVaddr) {
            if (texLdr->fileData != NULL) {
                DebugArena_FreeDebug(texLdr->fileData, __FILE__, __LINE__);
            }
            texLdr->fileData = DebugArena_MallocDebug(texDesc->fileVSize, __FILE__, __LINE__);
            if (texLdr->fileData == NULL) {
                texLdr->fileVaddr = GFX_FILE_DRAM;
                if (newTexture != NULL) {
                    DebugArena_FreeDebug(newTexture, __FILE__, __LINE__);
                }
                return NULL;
            }
            texLdr->fileVaddr = texDesc->fileVaddr;
            DmaMgr_SendRequest0(texLdr->fileVaddr, texLdr->fileData, texDesc->fileVSize);
        }

        if (texDesc->fileVSize == textureSize) {
            textureData = texLdr->fileData;
            texLdr->fileVaddr = GFX_FILE_DRAM;
            texLdr->fileData = NULL;
        } else {
            fileStart = texLdr->fileData;
        }
    }

    if (textureData == NULL) {
        textureData = DebugArena_MallocDebug(textureSize, __FILE__, __LINE__);
        if (textureData == NULL) {
            if (newTexture != NULL) {
                DebugArena_FreeDebug(newTexture, __FILE__, __LINE__);
            }
            return NULL;
        }

        memcpy(textureData, (char *)fileStart + texDesc->address, textureSize);
    }

    texture->data = textureData;
    return texture;
}

void GZGfx_TexLdrDestroy(TexLdr* texLdr) {
    if (texLdr->fileData) {
        DebugArena_FreeDebug(texLdr->fileData, __FILE__, __LINE__);
    }
}

GfxTexture* GZGfx_TextureCreate(g_ifmt_t im_fmt, g_isiz_t im_siz, s32 tileWidth, s32 tileHeight, s32 tilesX, s32 tilesY) {
    GfxTexture* texture = DebugArena_MallocDebug(sizeof(*texture), __FILE__, __LINE__);
    
    if (texture == NULL) {
        return texture;
    }

    texture->tileSize = (tileWidth * tileHeight * G_SIZ_BITS(im_siz) + 63) / 64 * 8;
    texture->data = DebugArena_MallocDebug(tilesX * tilesY * texture->tileSize, __FILE__, __LINE__);

    if (texture->data == NULL) {
        DebugArena_FreeDebug(texture, __FILE__, __LINE__);
        return NULL;
    }

    texture->im_fmt = im_fmt;
    texture->im_siz = im_siz;
    texture->tileWidth = tileWidth;
    texture->tileHeight = tileHeight;
    texture->tilesX = tilesX;
    texture->tilesY = tilesY;
    return texture;
}

GfxTexture* GZGfx_TextureLoad(const TexDesc* texDesc, GfxTexture* texture) {
    TexLdr texLdr;

    GZGfx_TexLdrInit(&texLdr);
    texture = GZGfx_TexLdrLoad(&texLdr, texDesc, texture);
    GZGfx_TexLdrDestroy(&texLdr);
    return texture;
}

void GZGfx_TextureDestroy(GfxTexture* texture) {
    if (texture->data != NULL) {
        DebugArena_FreeDebug(texture->data, __FILE__, __LINE__);
    }
}

void GZGfx_TextureFree(GfxTexture *texture)
{
  GZGfx_TextureDestroy(texture);
  DebugArena_Free(texture);
}

void *GZGfx_TextureData(const GfxTexture *texture, s16 tile)
{
  return (char*)texture->data + texture->tileSize * tile;
}

GfxTexture *GZGfx_TextureCopy(const GfxTexture *src,
                                     GfxTexture *dest)
{
    size_t texture_size;
    void* texture_data;
  GfxTexture *new_texture = NULL;
  if (!dest) {
    new_texture = DebugArena_Malloc(sizeof(*new_texture));
    if (!new_texture)
      return new_texture;
    dest = new_texture;
  }
  texture_size = src->tileSize * src->tilesX * src->tilesY;
  texture_data = DebugArena_Malloc(texture_size);
  if (!texture_data) {
    if (new_texture)
      DebugArena_Free(new_texture);
    return NULL;
  }
  *dest = *src;
  dest->data = texture_data;
  memcpy(dest->data, src->data, texture_size);
  return dest;
}

void GZGfx_TextureCopyTile(GfxTexture *dest, s32 dest_tile,
                           const GfxTexture *src, s32 src_tile,
                           u8 blend)
{
    size_t tile_pixels;
    Color_RGBA8* p_dest;
    Color_RGBA8* p_src;
    size_t i;
  if (src->im_fmt != G_IM_FMT_RGBA || src->im_siz != G_IM_SIZ_32b ||
      dest->im_fmt != src->im_fmt || dest->im_siz != src->im_siz ||
      dest->tileWidth != src->tileWidth ||
      dest->tileHeight != src->tileHeight)
    return;

  tile_pixels = src->tileWidth * src->tileHeight;
  p_dest = GZGfx_TextureData(dest, dest_tile);
  p_src = GZGfx_TextureData(src, src_tile);
  for (i = 0; i < tile_pixels; ++i) {
    if (blend) {
      p_dest->r = p_dest->r + (p_src->r - p_dest->r) * p_src->a / 0xFF;
      p_dest->g = p_dest->g + (p_src->g - p_dest->g) * p_src->a / 0xFF;
      p_dest->b = p_dest->b + (p_src->b - p_dest->b) * p_src->a / 0xFF;
      p_dest->a = p_src->a + (0xFF - p_src->a) * p_dest->a / 0xFF;
    }
    else
      *p_dest = *p_src;
    ++p_dest;
    ++p_src;
  }
}

void GZGfx_TextureColorTransform(GfxTexture *texture,
                                const MtxF *matrix)
{
    size_t texture_pixels;
    Color_RGBA8* pixel_data;
    MtxF m;
    size_t i;
  if (texture->im_fmt != G_IM_FMT_RGBA || texture->im_siz != G_IM_SIZ_32b)
    return;

  texture_pixels = texture->tileWidth * texture->tileHeight *
                          texture->tilesX * texture->tilesY;
  pixel_data = texture->data;
   m = *matrix;
  for (i = 0; i < texture_pixels; ++i)
  {
    Color_RGBA8* n = alloca(sizeof(Color_RGBA8));
    Color_RGBA8 p = pixel_data[i];
    f32 r = p.r * m.xx + p.g * m.xy + p.b * m.xz + p.a * m.xw;
    f32 g = p.r * m.yx + p.g * m.yy + p.b * m.yz + p.a * m.yw;
    f32 b = p.r * m.zx + p.g * m.zy + p.b * m.zz + p.a * m.zw;
    f32 a = p.r * m.wx + p.g * m.wy + p.b * m.wz + p.a * m.ww;

    n->r = r < 0x00 ? 0x00 : r > 0xFF ? 0xFF : r;
    n->g = g < 0x00 ? 0x00 : g > 0xFF ? 0xFF : g;
    n->b = b < 0x00 ? 0x00 : b > 0xFF ? 0xFF : b;
    n->a = a < 0x00 ? 0x00 : a > 0xFF ? 0xFF : a;

    pixel_data[i] = *n;
  }
}

void GZGfx_DispRDPLoadTile(Gfx **disp,
                            const GfxTexture *texture,
                            s16 textureTile)
{
  if (texture->im_siz == G_IM_SIZ_4b) {
    gDPLoadTextureTile_4b((*disp)++,
                          GZGfx_TextureData(texture, textureTile),
                          texture->im_fmt,
                          texture->tileWidth, texture->tileHeight,
                          0, 0,
                          texture->tileWidth - 1, texture->tileHeight - 1,
                          0,
                          G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMASK, G_TX_NOMASK,
                          G_TX_NOLOD, G_TX_NOLOD);
  }
  else {
      // this is stupid but there is some sort of error with the gDPLoadTextureTile macro that doesnt let you put variable
      // names for the im_siz argument...
    switch (texture->im_siz) {
        case G_IM_SIZ_8b:
            gDPLoadTextureTile((*disp)++,
                       GZGfx_TextureData(texture, textureTile),
                       texture->im_fmt, G_IM_SIZ_8b,
                       texture->tileWidth, texture->tileHeight,
                       0, 0,
                       texture->tileWidth - 1, texture->tileHeight - 1,
                       0,
                       G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOMASK,
                       G_TX_NOLOD, G_TX_NOLOD);
        case G_IM_SIZ_16b:
            gDPLoadTextureTile((*disp)++,
                       GZGfx_TextureData(texture, textureTile),
                       texture->im_fmt, G_IM_SIZ_16b,
                       texture->tileWidth, texture->tileHeight,
                       0, 0,
                       texture->tileWidth - 1, texture->tileHeight - 1,
                       0,
                       G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOMASK,
                       G_TX_NOLOD, G_TX_NOLOD);
        case G_IM_SIZ_32b:
            gDPLoadTextureTile((*disp)++,
                       GZGfx_TextureData(texture, textureTile),
                       texture->im_fmt, G_IM_SIZ_32b,
                       texture->tileWidth, texture->tileHeight,
                       0, 0,
                       texture->tileWidth - 1, texture->tileHeight - 1,
                       0,
                       G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOMASK,
                       G_TX_NOLOD, G_TX_NOLOD);
    }
    
  }
}

void GZGfx_RDPLoadTile(const GfxTexture *texture, s16 textureTile)
{
  GZGfx_DispRDPLoadTile(&sGfxDispP, texture, textureTile);
  sGfxSynced = 1;
}

void GZGfx_SpriteDraw(const GfxSprite *sprite)
{
  GfxTexture *texture = sprite->texture;
  GZGfx_RDPLoadTile(texture, sprite->textureTile);
  if (sGfxModes[GFX_MODE_DROPSHADOW]) {
    u8 a = sGfxModes[GFX_MODE_COLOR] & 0xFF;
    a = a * a / 0xFF;
    GZGfx_ModeReplace(GFX_MODE_COLOR, GPACK_RGBA8888(0x00, 0x00, 0x00, a));
    gSPScisTextureRectangle(sGfxDispP++,
                            qs102(sprite->x + 1) & ~3,
                            qs102(sprite->y + 1) & ~3,
                            qs102(sprite->x + texture->tileWidth *
                                  sprite->xScale + 1) & ~3,
                            qs102(sprite->y + texture->tileHeight *
                                  sprite->yScale + 1) & ~3,
                            G_TX_RENDERTILE,
                            qu105(0), qu105(0),
                            qu510(1.f / sprite->xScale),
                            qu510(1.f / sprite->yScale));
    GZGfx_ModePop(GFX_MODE_COLOR);
  }
  gfx_sync();
  gSPScisTextureRectangle(sGfxDispP++,
                          qs102(sprite->x) & ~3,
                          qs102(sprite->y) & ~3,
                          qs102(sprite->x + texture->tileWidth *
                                sprite->xScale) & ~3,
                          qs102(sprite->y + texture->tileHeight *
                                sprite->yScale) & ~3,
                          G_TX_RENDERTILE,
                          qu105(0), qu105(0),
                          qu510(1.f / sprite->xScale),
                          qu510(1.f / sprite->yScale));
  sGfxSynced = 0;
}

s32 Gfx_FontXHeight(const GfxFont *font)
{
  return font->baseline - font->median;
}

void Gfx_Printf(const GfxFont *font, s32 x, s32 y,
                const char *format, ...)
{
  if (sGfxModes[GFX_MODE_TEXT] == GFX_TEXT_NORMAL) {
    va_list args;
    va_start(args, format);
    Gfx_PrintFNVa(font, x, y, format, args);
    va_end(args);
  }
  else if (sGfxModes[GFX_MODE_TEXT] == GFX_TEXT_FAST) {
    va_list args;
    va_start(args, format);
    Gfx_PrintFFVa(font, x, y, format, args);
    va_end(args);
  }
}

void Gfx_PrintF_N(const GfxFont *font, s32 x, s32 y,
                  const char *format, ...)
{
  va_list args;
  va_start(args, format);
  Gfx_PrintFNVa(font, x, y, format, args);
  va_end(args);
}

void Gfx_Printf_F(const GfxFont *font, s32 x, s32 y,
                  const char *format, ...)
{
  va_list args;
  va_start(args, format);
  Gfx_PrintFFVa(font, x, y, format, args);
  va_end(args);
}

static void draw_chars(const GfxFont *font, s32 x, s32 y,
                       const char *buf, size_t l)
{
  GfxTexture *texture = font->texture;
  s32 chars_per_tile = font->charsXTile * font->charsYTile;
  s32 n_tiles = texture->tilesX * texture->tilesY;
  s32 n_chars = chars_per_tile * n_tiles;
  s32 i;

  x -= font->x;
  y -= font->baseline;

  for (i = 0; i < n_tiles; ++i) {
    s32 tile_begin = chars_per_tile * i;
    s32 tile_end = tile_begin + chars_per_tile;
    u8 tile_loaded = 0;
    s32 cx = 0;
    s32 cy = 0;
    s32 j = 0;
    for (j; j < l; ++j, cx += font->charWidth + font->letterSpacing) {
      u8 c = buf[j];
      if (c < font->codeStart || c >= font->codeStart + n_chars)
        continue;
      c -= font->codeStart;
      if (c < tile_begin || c >= tile_end)
        continue;
      c -= tile_begin;
      if (!tile_loaded) {
        tile_loaded = 1;
        GZGfx_RDPLoadTile(texture, i);
      }
      gSPScisTextureRectangle(sGfxDispP++,
                              qs102(x + cx),
                              qs102(y + cy),
                              qs102(x + cx + font->charWidth),
                              qs102(y + cy + font->charHeight),
                              G_TX_RENDERTILE,
                              qu105(c % font->charsXTile *
                                    font->charWidth),
                              qu105(c / font->charsXTile *
                                    font->charHeight),
                              qu510(1), qu510(1));
    }
  }
  sGfxSynced = 0;
}

static void flush_chars(void)
{
  const GfxFont *font = sGfxCharFont;
  u32 color = 0;
  u8 first = 1;
  s32 i;
  s32 j;
  for (i = 0; i < CHAR_TILE_MAX; ++i) {
    struct vector *tile_vect = &sGfxChars[i];
    for (j = 0; j < tile_vect->size; ++j) {
      GfxChar *gc = vector_at(tile_vect, j);
      if (j == 0)
        GZGfx_RDPLoadTile(font->texture, i);
      if (first || color != gc->color) {
        color = gc->color;
        gfx_sync();
        gDPSetPrimColor(sGfxDispP++, 0, 0,
                        (color >> 24) & 0xFF,
                        (color >> 16) & 0xFF,
                        (color >> 8)  & 0xFF,
                        (color >> 0)  & 0xFF);
      }
      first = 0;
      gSPScisTextureRectangle(sGfxDispP++,
                              qs102(gc->x),
                              qs102(gc->y),
                              qs102(gc->x + font->charWidth),
                              qs102(gc->y + font->charHeight),
                              G_TX_RENDERTILE,
                              qu105(gc->tileChar % font->charsXTile *
                                    font->charWidth),
                              qu105(gc->tileChar / font->charsXTile *
                                    font->charHeight),
                              qu510(1), qu510(1));
      sGfxSynced = 0;
    }
    vector_clear(tile_vect);
  }
}

static void Gfx_PrintFNVa(const GfxFont *font, s32 x, s32 y,
                            const char *format, va_list args)
{
    char buf[1024];
  const size_t bufsize = 1024;
  
  s32 l = vsnprintf(buf, bufsize, format, args);
  if (l > bufsize - 1)
    l = bufsize - 1;
  if (sGfxModes[GFX_MODE_DROPSHADOW]) {
    u8 a = sGfxModes[GFX_MODE_COLOR] & 0xFF;
    a = a * a / 0xFF;
    GZGfx_ModeReplace(GFX_MODE_COLOR, GPACK_RGBA8888(0x00, 0x00, 0x00, a));
    draw_chars(font, x + 1, y + 1, buf, l);
    GZGfx_ModePop(GFX_MODE_COLOR);
  }
  draw_chars(font, x, y, buf, l);
}

static void Gfx_PrintFFVa(const GfxFont *font, s32 x, s32 y,
                            const char *format, va_list args)
{
    char buf[1024];
  const size_t bufsize = 1024;
  
  s32 cx, cy, i;
  s32 l = vsnprintf(buf, bufsize, format, args);
  GfxTexture *texture = font->texture;
  s32 chars_per_tile = font->charsXTile * font->charsYTile;
  s32 n_tiles = texture->tilesX * texture->tilesY;
  s32 n_chars = chars_per_tile * n_tiles;

  if (l > bufsize - 1)
    l = bufsize - 1;
  x -= font->x;
  y -= font->baseline;
  
  if (sGfxModes[GFX_MODE_DROPSHADOW]) {
    u32 color;
    u8 a = sGfxModes[GFX_MODE_COLOR] & 0xFF;
    a = a * a / 0xFF;
    color = GPACK_RGBA8888(0x00, 0x00, 0x00, a);
    cx = x + 1;
    cy = y + 1;
    for (i = 0; i < l; ++i, cx += font->charWidth + font->letterSpacing) {
     s32 tile_idx;
     s32 tileChar;
      u8 c = buf[i];
      GfxChar* gc = alloca(sizeof(GfxChar));
      if (c < font->codeStart || c >= font->codeStart + n_chars)
        continue;
      c -= font->codeStart;
      tile_idx = c / chars_per_tile;
      tileChar = c % chars_per_tile;
      gc->tileChar = tileChar;
      gc->color = color;
      gc->x = cx;
      gc->y = cy;

      vector_push_back(&sGfxChars[tile_idx], 1, gc);
    }
  }
  cx = x;
  cy = y;
  for (i = 0; i < l; ++i, cx += font->charWidth + font->letterSpacing) {
      s32 tile_idx;
      s32 tileChar;
      GfxChar* gc;
    u8 c = buf[i];
    if (c < font->codeStart || c >= font->codeStart + n_chars)
      continue;
    c -= font->codeStart;
    tile_idx = c / chars_per_tile;
    tileChar = c % chars_per_tile;
    gc = alloca(sizeof(GfxChar));
    gc->tileChar = tileChar;
    gc->color = sGfxModes[GFX_MODE_COLOR];
    gc->x = cx;
    gc->y = cy;

    vector_push_back(&sGfxChars[tile_idx], 1, gc);
  }

  sGfxCharFont = font;
}
