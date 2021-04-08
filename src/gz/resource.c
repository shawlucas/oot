#include <global.h>
#include <alloca.h>
#include "resource.h"

static void* sResData[RES_MAX] = { NULL };

static void* rc_font_generic(TexDesc* texDesc, s32 charWidth, s32 charHeight, s32 codeStart, s32 letterSpacing, s32 lineSpacing, s32 baseline, s32 median, s32 x) {
    GfxTexture* texture;
    GfxFont* font = alloca(sizeof(*font));

    if (font == NULL) {
        return font;
    }

    texture = GZGfx_TextureLoad(texDesc, NULL);

    if (texture == NULL) {
        return NULL;
    }

    font->texture = texture;
    font->charWidth = charWidth;
    font->charHeight = charHeight;
    font->charsXTile = texture->tileWidth / font->charWidth;
    font->charsYTile = texture->tileHeight / font->charHeight;
    font->codeStart = codeStart;
    font->letterSpacing = letterSpacing;
    font->lineSpacing = lineSpacing;
    font->baseline = baseline;
    font->median = median;
    font->x = x;

    return font;
}

static void* rc_grc_font_generic(const char* grc_resource_name, s32 charWidth, s32 charHeight, s32 codeStart, s32 letterSpacing, s32 lineSpacing, s32 baseline, s32 median, s32 x) {
    void* p;
    GrcTexture* t;
    
}
