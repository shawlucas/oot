#include <global.h>
#include <alloca.h>
#include "gfx.h"
#include "menu.h"

typedef struct {
    MenuAction callbackProc;
    void* callbackData;
    GfxTexture* texture;
    s32 textureTile;
    s32 animState;
} ItemData;

static s32 init(MenuItem* item, MenuSwitchReason reason) {
    ItemData* data = item->data;
    data->animState = 0;
    return 0;
}

static s32 draw(MenuItem* item, MenuDrawParams* drawParams) {
    ItemData* data = item->data;

    if (data->animState > 0) {
        ++drawParams->x;
        ++drawParams->y;
        data->animState = (data->animState + 1) % 3;
    }

    if (data->texture) {
        s32 cw = Menu_GetCellWidth(item->owner, 1);
        GfxSprite* sprite = alloca(sizeof(GfxSprite));

        sprite->texture = data->texture;
        sprite->textureTile = data->textureTile;
        sprite->x = drawParams->x + (cw - data->texture->tileWidth) / 2;
        sprite->y = drawParams->y - (Gfx_FontXHeight(drawParams->font) + data->texture->tileHeight + 1) / 2;
        sprite->xScale = 1.0f;
        sprite->yScale = 1.0f;

        GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams->color, drawParams->alpha));
        GZGfx_SpriteDraw(sprite);
        return 1;
    }

    return 0;
}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;

    data->callbackProc(item, data->callbackData);
    data->animState = 1;
    return 1;
}

MenuItem* Menu_AddButton(Menu* menu, s32 x, s32 y, const char* name, MenuAction callback, void* callbackData) {
    MenuItem* item;
    ItemData* data = alloca(sizeof(*data));

    data->callbackProc = callback;
    data->callbackData = callbackData;
    data->texture = NULL;
    data->animState = 0;

    item = Menu_ItemAdd(menu, x, y, name, 0xFFFFFF);
    item->data = data;
    item->entry = init;
    item->draw = draw;
    item->activate = activate;
    return item;
}

MenuItem* Menu_AddButtonIcon(Menu* menu, s32 x, s32 y, GfxTexture* texture, s32 textureTile, u32 color, MenuAction callback, void* callbackData) {
    MenuItem* item;
    ItemData* data = alloca(sizeof(*data));

    data->callbackProc = callback;
    data->callbackData = callbackData;
    data->texture = texture;
    data->textureTile = textureTile;
    data->animState = 0;

    item = Menu_ItemAdd(menu, x, y, NULL, color);
    item->data = data;
    item->entry = init;
    item->draw = draw;
    item->activate = activate;
    return item;
}

void Menu_ButtonSetTexture(MenuItem* item, GfxTexture* texture, s32 textureTile) {
    ItemData* data = item->data;
    
    data->texture = texture;
    data->textureTile = textureTile;
}
