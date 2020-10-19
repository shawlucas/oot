#include <ultra64.h>
#include <global.h>

#include "menu.h"

typedef struct {
    MenuActionCallback callback;
    void* callbackData;
    GfxTexture* texture;
    int textureTile;
    int animState;
} ItemData;

static s32 enter(MenuItem* item, MenuSwitchReason reason) {
    ItemData* data = item->data;

    data->animState = 0;
    return 0;
}

static s32 draw(MenuItem* item, MenuDrawParams* drawParams, GlobalContext* globalCtx) {
    ItemData* data = item->data;

    if (data->animState > 0) {
        ++drawParams->x;
        ++drawParams->y;
        data->animState = (data->animState + 1) % 3;
    }
    if (data->texture) {
        GfxSprite sprite;
        GfxTexture* texture;
        s32 cw = Menu_GetCellWidth(item->owner, 1);
    
        sprite.texture = data->texture;
        sprite.textureTile = data->textureTile;
        sprite.x = drawParams->x + (cw - data->texture->tileWidth) / 2;
        sprite.y = drawParams->y - (gfx_font_xheight(drawParams->printer) + data->texture->tileHeight + 1) / 2;
        sprite.xScale = 1.f;
        sprite.yScale = 1.f;

        OPEN_DISPS(globalCtx->state.gfxCtx, __FILE__, __LINE__);

        texture = sprite.texture;

        gDPSetPrimColor(oGfxCtx->overlay.p++, 0, 0, (drawParams->color >> 24) & 0xFF, (drawParams->color >> 16) & 0xFF,
                        (drawParams->color >> 8) & 0xFF, (drawParams->color >> 0) & 0xFF);

        gDPPipeSync(oGfxCtx->overlay.p++);
        gSPScisTextureRectangle(oGfxCtx->overlay.p++, qs102(sprite.x) & ~3, qs102(sprite.y) & ~3,
                                qs102(sprite.x + texture->tileWidth * sprite.xScale) & ~3,
                                qs102(sprite.y + texture->tileHeight * sprite.yScale) & ~3, G_TX_RENDERTILE, qu105(0),
                                qu105(0), qu510(1.f / sprite.xScale), qu510(1.f / sprite.yScale));

        CLOSE_DISPS(globalCtx->state.gfxCtx, __FILE__, __LINE__);

        return 1;
    }

    return 0;
}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;

    data->callback(item, data->callbackData);
    data->animState = 1;
    return 1;
}

MenuItem* Menu_AddButton(Menu* menu, s32 x, s32 y, const char* name, MenuActionCallback callback, void* callbackData) {
    MenuItem* item;
    ItemData* data = malloc(sizeof(*data));

    data->callback = callback;
    data->callbackData = callbackData;
    data->texture = NULL;
    data->animState = 0;
    item = MenuItem_Add(menu, x, y, name, 0xFFFFFF);
    item->data = data;
    item->enter = enter;
    item->draw = draw;
    item->activate = activate;
    return item;
}

MenuItem* Menu_AddButton_icon(Menu* menu, s32 x, s32 y, GfxTexture* texture, s32 textureTile, u32 color,
                              MenuActionCallback callback, void* callbackData) {
    MenuItem* item;
    ItemData* data = malloc(sizeof(*data));

    data->callback = callback;
    data->callbackData = callbackData;
    data->texture = texture;
    data->textureTile = textureTile;
    data->animState = 0;
    item = MenuItem_Add(menu, x, y, NULL, color);
    item->data = data;
    item->enter = enter;
    item->draw = draw;
    item->activate = activate;
    return item;
}

void MenuButton_SetTexture(MenuItem* item, GfxTexture* texture, s32 textureTile) {
    ItemData* data = item->data;

    data->texture = texture;
    data->textureTile = textureTile;
}
