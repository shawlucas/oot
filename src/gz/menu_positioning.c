#include <global.h>
#include <alloca.h>
#include "gfx.h"
#include "menu.h"


typedef struct ItemData {
    MenuGeneric callback;
    void* callbackData;
    u8 active;
} ItemData;

static s32 draw(MenuItem* item, MenuDrawParams* drawParams) {
    s32 cw;
    GfxSprite* sprite;
    static GfxTexture* texture = NULL;

    if (texture == NULL) {
        texture = resource_load_grc_texture("move_icon");
    }

    sprite = alloca(sizeof(GfxSprite));

    sprite->texture = texture;
    sprite->textureTile = 0;
    sprite->x = drawParams->x + (cw - texture->tileWidth) / 2;
    sprite->y = drawParams->y - (Gfx_FontXHeight(drawParams->font) + texture->tileHeight + 1) / 2;
    sprite->xScale = 1.f;
    sprite->yScale = 1.f;

    GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams->color, drawParams->alpha));

    GZGfx_SpriteDraw(sprite);
    return 1;
}

static s32 navigate(MenuItem* item, MenuNavigation nav) {
    ItemData* data = item->data;

    if (data->active && data->callback != NULL) {
        data->callback(item, MENU_CALLBACK_NAV_UP + nav, data->callbackData);
    }

    return data->active;
}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;

    if (data->callback == NULL || !data->callback(item, data->active ? MENU_CALLBACK_DEACTIVATE : MENU_CALLBACK_ACTIVATE, data->callbackData)) {
        data->active = !data->active;
        item->animateHighlight = data->active;
    }

    return 1;
}

MenuItem* Menu_AddPositioning(Menu* menu, s32 x, s32 y, MenuGeneric callback, void* callbackData) {
    MenuItem* item;
    ItemData* data = alloca(sizeof(*data));

    data->callback = callback;
    data->callbackData = callbackData;
    data->active = false;

    item = Menu_ItemAdd(menu, x, y, NULL, 0xFFFFFF);
    item->data = data;
    item->draw = draw;
    item->navigate = navigate;
    item->activate = activate;

    return item;
}
