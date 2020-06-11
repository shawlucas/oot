#include <ultra64.h>
#include <global.h>
#include "menu.h"
#include <gz/gfx.h>

typedef struct ItemData
{
    Menu_ActionCallback callbackProc;
    void* callbackData;
    Texture* texture;
    s32 textureTile;
    s32 animState;
} ItemData;

static s32 EntryProc(MenuItem* item, MenuSwitchReason reason)
{
    ItemData* data = item->data;
    data->animState = 0;
    return 0;
}

static s32 DrawProc(MenuItem* item, MenuDrawParams* drawParams, GraphicsContext* gfxCtx)
{
    Gfx* newDList;
    Gfx* polyOpaP;
    GfxPrint printer;
    s32 cw;
    Sprite sprite;
    ItemData* data = item->data;

    newDList = Graph_GfxPlusOne(polyOpaP = gfxCtx->polyOpa.p);
    gSPDisplayList(gfxCtx->polyOpa.p++, newDList);

    if (data->animState > 0)
    {
        ++drawParams->x;
        ++drawParams->y;
        data->animState = (data->animState + 1) % 3;
    }

    if (data->texture)
    {
        cw = Menu_GetCellWidth(item->owner, 1);
        sprite.texture = data->texture;
        sprite.textureTile = data->textureTile;
        sprite.x = drawParams->x + (cw - data->texture->width) / 2;
        sprite.y = drawParams->y - (Gfx_FontXHeight(drawParams->font) +
                        data->texture->height + 1) /2;
        sprite.xScale = 1.0f;
        sprite.yScale = 1.0f;

        GfxPrint_SetColor(printer, 
    }
}