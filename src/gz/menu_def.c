#include <ultra64.h>
#include <global.h>
#include "gfx.h"
#include "menu.h"

typedef struct 
{
    Texture* texture;
    s32 textureTile;
    f32 scale;
} StaticIconData;

MenuItem* Menu_AddStatic(Menu* menu, s32 x, s32 y,
                        const char* text, Color_RGB8 color)
{
    MenuItem* item = Menu_ItemAdd(menu, x, y, text, color);
    item->selectable = 0;
    return item;
}

static s32 StaticIcon_DrawProc(MenuItem* item, MenuDrawParams* drawParams)
{
    s32 cw;
    s32 w;
    s32 h;
    Sprite sprite;
    StaticIconData* data = item->data;
    cw = Menu_GetCellWidth(item->owner, 1);
    w = data->texture->width * data->scale;
    h = data->texture->height * data->scale;

    sprite.texture = data->texture;
    sprite.textureTile = data->textureTile;
    sprite.x = (drawParams->x + (cw - w) / 2);
    sprite.y = (drawParams->y - (Gfx_FontXHeight(drawParams->font) + h + 1) / 2);
    sprite.xScale = data->scale;
    sprite.yScale = data->scale;

    
}
