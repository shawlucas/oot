#include <global.h>
#include "gfx.h"
#include "menu.h"
#include "util.h"
#include <alloca.h>

typedef struct ItemData {
    u8 state;
    MenuGeneric callback;
    void* callbackData;
    GfxTexture* textureOn;
    s32 textureTileOn;
    u32 colorOn;
    GfxTexture* textureOff;
    s32 textureTileOff;
    u32 colorOff;
    f32 scale;
    u8 disableShadow;
    s32 animState;
} ItemData;

static s32 entry(MenuItem* item, MenuSwitchReason reason) {
    ItemData* data = item->data;

    data->animState = 0;
    return 0;
}

static s32 think(MenuItem* item) {
    ItemData* data = item->data;

    if (data->callback != NULL) {
        return data->callback(item, MENU_CALLBACK_THINK, data->callbackData);
    }

    return 0;
}

static s32 draw(MenuItem* item, MenuDrawParams* drawParams) {
    GfxTexture* texture;
    s32 textureTile;
    u32 color;
    s32 cw;
    s32 w, h, x, y;
    GfxSprite* sprite;
    ItemData* data = item->data;

    if (data->animState > 0) {
        ++drawParams->x;
        ++drawParams->y;
    }

    if ((data->animState > 0) != data->state) {
        texture = data->textureOn;
        textureTile = data->textureTileOn;
        color = data->colorOn;
    } else {
        texture = data->textureOff;
        textureTile = data->textureTileOff;
        color = data->colorOff;
    }

    cw = Menu_GetCellWidth(item->owner, 1);
    w = texture->tileWidth * data->scale;
    h = texture->tileHeight * data->scale;
    x = drawParams->x + (cw - w) / 2;
    y = drawParams->y - (Gfx_FontXHeight(drawParams->font) + h) / 2;

    if (item->owner->selector == item) {
        Gfx* gfx = alloca(sizeof(Gfx)); // this might not work
    
        GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams->color, drawParams->alpha * 0x80 / 0xFF));
        GZGfx_ModeReplace(GFX_MODE_COMBINE, G_CC_MODE(G_CC_PRIMITIVE, G_CC_PRIMITIVE));

        gSPScisTextureRectangle(gfx++, qs102(x - 1), qs102(y - 1),
                                      qs102(x + w + 1), qs102(y + h + 1),
                                      0, 0, 0, 0, 0);
        GZGfx_DispAppend(gfx, sizeof(gfx));
        GZGfx_ModePop(GFX_MODE_COMBINE);

    }

    GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGBA8888((color >> 16) & 0xFF, (color >> 8) & 0xFF, (color >> 0) & 0xFF, drawParams->alpha));

    if (data->scale != 1.f) {
        GZGfx_ModeReplace(GFX_MODE_FILTER, G_TF_BILERP);
    } else {
        GZGfx_ModeReplace(GFX_MODE_FILTER, G_TF_POINT);
    }

    if (data->disableShadow) {
        GZGfx_ModeReplace(GFX_MODE_DROPSHADOW, 0);
    }

    sprite->texture = texture;
    sprite->textureTile = textureTile;
    sprite->x = x;
    sprite->y = y;
    sprite->xScale = data->scale;
    sprite->yScale = data->scale;

    GZGfx_SpriteDraw(sprite);
    GZGfx_ModePop(GFX_MODE_FILTER);

    if (data->disableShadow) {
        GZGfx_ModePop(GFX_MODE_DROPSHADOW);
    }

    if (data->animState > 0) {
        data->animState = (data->animState + 1) % 3;
    }

    return 1;
}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;

    if (data->callback == NULL || !data->callback(item, data->state ? MENU_CALLBACK_SWITCH_OFF : MENU_CALLBACK_SWITCH_ON, data->callbackData)) {
        data->state = !data->state;
        data->animState = 1;

        if (data->callback != NULL) {
            data->callback(item, MENU_CALLBACK_CHANGED, data->callbackData);
        }
    }

    return 1;
}

MenuItem* Menu_AddSwitch(Menu* menu, s32 x, s32 y, GfxTexture* textureOn, s32 textureTileOn, u32 colorOn, GfxTexture* textureOff, s32 textureTileOff, u32 colorOff, f32 scale, u8 disableShadow, MenuGeneric callback, void* callbackData) {
    MenuItem* item = Menu_ItemAdd(menu, x, y, NULL, 0x808080);
    ItemData* data = alloca(sizeof(*data));

    data->state = 0;
    data->callback = callback;
    data->callbackData = callbackData;
    data->textureOn = textureOn;
    data->textureTileOn = textureTileOn;
    data->colorOn = colorOn;
    data->textureOff = textureOff;
    data->textureTileOff = textureTileOff;
    data->colorOff = colorOff;
    data->scale = scale;
    data->disableShadow = disableShadow;
    data->animState = 0;
    item->data = data;
    item->entry = entry;
    item->think = think;
    item->draw = draw;
    item->activate = activate;
    return item;
}

void Menu_SwitchSet(MenuItem* item, u8 state) {
    ItemData* data = item->data;

    data->state = state;
}

u8 Menu_SwitchGet(MenuItem* item) {
    ItemData* data = item->data;

    return data->state;
}

void Menu_SwitchToggle(MenuItem* item) {
    ItemData* data = item->data;

    data->state = !data->state;
}
