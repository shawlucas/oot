#include <global.h>
#include <alloca.h>
#include "gfx.h"
#include "menu.h"

typedef struct ItemData {
    MenuGeneric callback;
    void* callbackData;
    u8 state;
    s32 animState;
} ItemData;

static s32 init(MenuItem* item, MenuSwitchReason reason) {
    ItemData* data = item->data;
    data->animState = 0;
    return 0;
}

static s32 think(MenuItem* item) {
    ItemData* data = item->data;

    if (data->callback) {
        return data->callback(item, MENU_CALLBACK_THINK, data->callbackData);
    }

    return 0;
}

static s32 draw(MenuItem* item, MenuDrawParams* drawParams) {
    s32 cw;
    GfxSprite* sprite;
    static GfxTexture* texture = NULL;
    ItemData* data = item->data;


    GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams->color, drawParams->alpha));

    if (texture == NULL) {
        texture = resource_load_grc_texture("checkbox");
    }

    cw = Menu_GetCellWidth(item->owner, 1);

    sprite = alloca(sizeof(GfxSprite));

    sprite->texture = texture;
    sprite->textureTile = (data->animState == 0 ? 0 : 1);
    sprite->x = drawParams->x + (cw - texture->tileWidth) / 2;
    sprite->y = drawParams->y - (Gfx_FontXHeight(drawParams->font) + texture->tileHeight + 1) / 2;
    sprite->xScale = 1.0f;
    sprite->yScale = 1.0f;

    GZGfx_SpriteDraw(sprite);

    if ((data->animState > 0) != data->state) {
        GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGBA8888(255, 255, 255, drawParams->alpha));
        sprite->textureTile = 2;
        GZGfx_SpriteDraw(sprite);
    }

    if (data->animState > 0) {
        data->animState = (data->animState + 1) % 3;
    }

    return 1;
}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;
    if (data->callback == NULL || data->callback(item, data->state ? MENU_CALLBACK_SWITCH_OFF : MENU_CALLBACK_SWITCH_ON, data->callbackData) == 0) {
        data->state = !data->state;
        data->animState = 1;
        if (data->callback != NULL) {
            data->callback(item, MENU_CALLBACK_CHANGED, data->callbackData);
        }

        return 1;
    }
}

MenuItem* Menu_AddCheckbox(Menu* menu, s32 x, s32 y, MenuGeneric callback, void* callbackData) {
    MenuItem* item;
    ItemData* data = alloca(sizeof(*data));

    data->callback = callback;
    data->callbackData = callbackData;
    data->animState = 0;

    item = Menu_ItemAdd(menu, x, y, NULL, 0xFFFFFF);
    item->data = data;
    item->entry = init;
    item->think = think;
    item->draw = draw;
    item->activate = activate;
    return item;

}

u8 Menu_CheckboxGet(MenuItem* item) {
    ItemData* data = item->data;

    return data->state;
}

void Menu_CheckboxSet(MenuItem* item, u8 state) {
    ItemData* data = item->data;

    data->state = state;
}
