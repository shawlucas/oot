#include <ultra64.h>
#include <global.h>
#include "gz_gfx.h"
#include <gz/menu.h>
#include "gfx.h"
// #include <gz/resource.h>

typedef struct 
{
    Menu_GenericCallback callbackProc;
    void* callbackData;
    u8 state;
    s32 animState;
} ItemData;

static s32 EntryProc(MenuItem* item, MenuSwitchReason reason)
{
    ItemData* data = item->data;
    data->animState = 0;
    return 0;
}

static s32 ThinkProc(MenuItem* item)
{
    ItemData* data = item->data;
    if (data->callbackProc)
        return data->callbackProc(item, MENU_CALLBACK_THINK, data->callbackData);
    return 0;
}

static s32 DrawProc(MenuItem* item, MenuDrawParams* drawParams, GraphicsContext* gfxCtx)
{
    Texture* texture;
    Texture* texture2;
    s32 cw;
    Sprite sprite;
    ItemData* data = item->data;
    gDPSetPrimColor(gfxCtx->polyOpa.p++, 0, 0, drawParams->color.r, drawParams->color.g, drawParams->color.b, drawParams->alpha);
    texture = NULL;
    if (!texture)
        texture = Resource_LoadGRCTexture("checkbox");
    cw = Menu_GetCellWidth(item->owner, 1);

    sprite.texture = texture;
    sprite.textureTile = (data->animState == 0 ? 0 : 1);
    sprite.x = (drawParams->x + (cw - texture->width) / 2);
    sprite.y = (drawParams->y - (Gfx_FontXHeight(drawParams->font) + texture->height + 1) / 2);
    sprite.xScale = 1.0f;
    sprite.yScale = 1.0f;
    texture = sprite.texture;
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
    if ((data->animState > 0) != data->state) {
        gDPSetPrimColor(gfxCtx->polyOpa.p++, 0, 0, 0xFF, 0xFF, 0xFF, drawParams->alpha);
        sprite.textureTile = 2;
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
    }
    if (data->animState > 0)
        data->animState = (data->animState + 1) % 3;
    return 1;
}

static s32 ActivateProc(MenuItem* item)
{
    ItemData* data = item->data;
    if (!data->callbackProc || 
        !data->callbackProc(item, data->state ? MENU_CALLBACK_SWITCH_OFF :
                            MENU_CALLBACK_SWITCH_ON, data->callbackData))
    {
        data->state = !data->state;
        data->animState = 1;
        if (data->callbackProc)
            data->callbackProc(item, MENU_CALLBACK_CHANGED, data->callbackData);
    }

    return 1;
}

MenuItem* Menu_AddCheckbox(Menu* menu, s32 x, s32 y,
                          Menu_GenericCallback callbackProc,
                          void* callbackData)
{
    MenuItem* item;
    ItemData* data = ZeldaArena_MallocDebug(sizeof(*data), "../menu_checkbox.c", 104);
    data->callbackProc = callbackProc;
    data->callbackData = callbackData;
    data->animState = 0;
    item = Menu_ItemAdd(menu, x, y, NULL, 0xFFFFFF);
    item->data = data;
    item->EntryProc = EntryProc;
    item->ThinkProc = ThinkProc;
    item->DrawProc = DrawProc;
    item->ActivateProc = ActivateProc;
    return item;
}

u8 Menu_CheckboxGet(MenuItem* item)
{
    ItemData* data = item->data;
    return data->state;
}

void Menu_CheckboxSet(MenuItem* item, u8 state)
{
    ItemData* data = item->data;
    data->state = state;
}
