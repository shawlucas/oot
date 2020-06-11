#include <ultra64.h>
#include <global.h>
#include <gz/gfx.h>
#include <gz/menu.h>

s32 Gfx_FontXHeight(const Font* font)
{
    return font->baseline - font->median;
}
