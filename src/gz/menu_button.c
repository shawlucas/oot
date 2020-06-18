#include <ultra64.h>
#include <global.h>
#include "menu.h"
#include <gz/gfx.h>
#include "gz_gfx.h"

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
    GfxPrint gfxPrint;
    s32 cw;
    Sprite sprite;
    Texture* texture;
    ItemData* data = item->data;

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

        GfxPrint_Ctor(&gfxPrint);
        polyOpaP = gfxCtx->polyOpa.p;
        newDList = Graph_GfxPlusOne(gfxCtx->polyOpa.p);
        gSPDisplayList(gfxCtx->overlay.p++, newDList);
        GfxPrint_Open(&gfxPrint, newDList);
        GfxPrint_SetColor(&gfxPrint, drawParams->color.r, drawParams->color.g, drawParams->color.b, drawParams->alpha);
        texture = sprite.texture;
        Gfx_RDPLoadTile(&gfxCtx->polyOpa.p, texture, sprite.textureTile);
        gDPPipeSync(gfxCtx->polyOpa.p++);
        gSPScisTextureRectangle(gfxCtx->polyOpa.p++,
                          qs102(sprite.x) & ~3,
                          qs102(sprite.y) & ~3,
                          qs102(sprite.x + texture->width *
                                sprite.xScale) & ~3,
                          qs102(sprite.y + texture->height *
                                sprite.yScale) & ~3,
                          G_TX_RENDERTILE,
                          qu105(0), qu105(0),
                          qu510(1.f / sprite.xScale),
                          qu510(1.f / sprite.yScale));
        return 1;
    }   
    return 0;
}

static s32 ActivateProc(MenuItem* item)
{
    ItemData* data = item->data;
    data->callbackProc(item, data->callbackData);
    data->animState = 1;
    return 1;
}

MenuItem* Menu_AddButton(Menu* menu, s32 x, s32 y,
                        const char* name,
                        Menu_ActionCallback callbackProc,
                        void* callbackData)
{
    ItemData* data = ZeldaArena_MallocDebug(sizeof(*data), "../menu_button.c", 90);
    data->callbackProc = callbackProc;
    data->callbackData = callbackData;
    data->texture = NULL;
    data->animState = 0;
    MenuItem* item = Menu_ItemAdd(menu, x, y, name, 0xFFFFFF);
    item->data = data;
    item->EntryProc = EntryProc;
    item->DrawProc = DrawProc;
    item->ActivateProc = ActivateProc;
    return item;
}

MenuItem* Menu_AddButtonIcon(Menu* menu, s32 x, s32 y,
                            Texture* texture, s32 textureTile, 
                            Color_RGB8 color, Menu_ActionCallback callbackProc,
                            void* callbackData)
{
    ItemData* data = ZeldaArena_MallocDebug(sizeof(*data), "../menu_button.c", 108);
    data->callbackProc = callbackProc;
    data->callbackData = callbackData;
    data->texture = texture;
    data->textureTile = textureTile;
    data->animState = 0;
    MenuItem* item = Menu_ItemAdd(menu, x, y, NULL, color);
    item->data = data;
    item->EntryProc = EntryProc;
    item->DrawProc = DrawProc;
    item->ActivateProc = ActivateProc;
    return item;
}

void Menu_SetButtonTexture(MenuItem* item, Texture* texture, s32 textureTile)
{
    ItemData* data = item->data;
    data->texture = texture;
    data->textureTile = textureTile;
}
