#include <global.h>
#include <alloca.h>
#include "gfx.h"
#include "menu.h"

typedef struct StaticIconData {
    GfxTexture* texture;
    s32 textureTile;
    f32 scale;
} StaticIconData;

MenuItem* Menu_AddStatic(Menu* menu, s32 x, s32 y, const char* text, u32 color) {
    MenuItem* item = Menu_ItemAdd(menu, x, y, text, color);

    item->selectable = false;
    return item;
}

static s32 static_icon_draw_proc(MenuItem* item, MenuDrawParams* drawParams) {
    StaticIconData* data = item->data;
    s32 cw = Menu_GetCellWidth(item->owner, 1);
    s32 w = data->texture->tileWidth * data->scale;
    s32 h = data->texture->tileHeight * data->scale;
    GfxSprite* sprite = alloca(sizeof(GfxSprite));

    sprite->texture = data->texture;
    sprite->textureTile = data->textureTile;
    sprite->x = drawParams->x + (cw - w) / 2;
    sprite->y = drawParams->y - (Gfx_FontXHeight(drawParams->font) + h + 1) / 2;
    sprite->xScale = data->scale;
    sprite->yScale = data->scale;

    GZGfx_ModeReplace(GFX_MODE_FILTER, G_TF_BILERP);
    GZGfx_ModeReplace(GFX_MODE_DROPSHADOW, 0);
    GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams->color, drawParams->alpha));
    GZGfx_SpriteDraw(sprite);
    GZGfx_ModePop(GFX_MODE_FILTER);
    GZGfx_ModePop(GFX_MODE_DROPSHADOW);

    return 1;
}

MenuItem* Menu_AddStaticIcon(Menu* menu, s32 x, s32 y, GfxTexture* texture, s32 textureTile, u32 color, f32 scale) {
    MenuItem* item;
    StaticIconData* data = alloca(sizeof(*data));

    data->texture = texture;
    data->textureTile = textureTile;
    data->scale = scale;

    item = Menu_ItemAdd(menu, x, y, NULL, color);
    item->data = data;
    item->selectable = false;
    item->draw = static_icon_draw_proc;
    return item;
}

MenuItem* Menu_AddStaticCustom(Menu* menu, s32 x, s32 y, s32 (*draw)(MenuItem* item, MenuDrawParams* drawParams), const char* text, u32 color) {
    MenuItem* item = Menu_ItemAdd(menu, x, y, text, color);
    
    item->selectable = false;
    item->draw = draw;

    return item;
}

static s32 tooltip_draw_proc(MenuItem* item, MenuDrawParams* drawParams) {
    Menu* toolMenu = item->data;

    while (toolMenu->child != NULL) {
        toolMenu = toolMenu->child;
    }

    if (toolMenu->selector != NULL && toolMenu->selector->tooltip != NULL) {
        GZGfx_ModeSet(GFX_MODE_COLOR, GPACK_RGB24A8(drawParams->color, drawParams->alpha));
        Gfx_Printf(drawParams->font, drawParams->x, drawParams->y, "%s", toolMenu->selector->tooltip);
    }

    return 1;
}

static s32 tooltip_destroy_proc(MenuItem* item) {
    item->data = NULL;
    return 0;
}

MenuItem* Menu_AddTooltip(Menu* menu, s32 x, s32 y, Menu* toolMenu, u32 color) {
    MenuItem* item = Menu_ItemAdd(menu, x, y, NULL, color);
    
    item->data = toolMenu;
    item->selectable = false;
    item->draw = tooltip_draw_proc;
    item->destroy = tooltip_destroy_proc;
    return item;
}

static s32 imenu_think_proc(MenuItem* item) {
    if (item->imenu != NULL) {
        item->imenu->cxOfffset = item->x;
        item->imenu->cyOffset = item->y;
        item->imenu->pxOffset = item->pxOffset;
        item->imenu->pyOffset = item->pyOffset;
    }

    return 0;
}

static s32 imenu_navigate_proc(MenuItem* item, MenuNavigation nav) {
    if (item->imenu != NULL) {
        Menu_Navigate(item->imenu, nav);
        return 1;
    }

    return 0;
}

static s32 imenu_activate_proc(MenuItem* item) {
    if (item->imenu != NULL) {
        Menu_Activate(item->imenu);
        return 1;
    }

    return 0;
}

MenuItem* Menu_AddIMenu(Menu* menu, s32 x, s32 y, Menu** pIMenu) {
    Menu* imenu = alloca(sizeof(*imenu));
    MenuItem* item = Menu_ItemAdd(menu, x, y, NULL, 0);

    item->selectable = false;
    item->think = imenu_think_proc;
    item->navigate = imenu_navigate_proc;
    item->activate = imenu_activate_proc;

    Menu_Init(imenu, MENU_NOVALUE, MENU_NOVALUE, MENU_NOVALUE);

    imenu->parent = menu;
    item->imenu = imenu;

    if (pIMenu != NULL) {
        *pIMenu = imenu;
    }

    return item;
}

typedef struct TabData {
    Menu* tabs;
    s32 numTabs;
    s32 currentTab;
} TabData;

static s32 tab_destroy_proc(MenuItem* item) {
    item->imenu = NULL;
    return 0;
}

MenuItem* Menu_AddTab(Menu* menu, s32 x, s32 y, Menu* tabs, s32 numTabs) {
    MenuItem* item;
    TabData* data = alloca(sizeof(*data));

    data->tabs = tabs;
    data->numTabs = numTabs;
    data->currentTab = -1;

    item = Menu_ItemAdd(menu, x, y, NULL, 0);
    item->data = data;
    item->selectable = false;
    item->think = imenu_think_proc;
    item->navigate = imenu_navigate_proc;
    item->activate = imenu_activate_proc;
    item->destroy = tab_destroy_proc;
    return item;
}

void Menu_TabGoto(MenuItem* item, s32 tabIndex) {
    TabData* data = item->data;

    if (data->tabs != NULL) {
        if (data->currentTab >= 0) {
            Menu* tab = &data->tabs[data->currentTab];
            MenuItem* selector = Menu_GetSelector(tab);

            if (selector != NULL) {
                Menu_SelectTop(item->owner, NULL);
            }

            tab->parent = NULL;
            item->imenu = NULL;
        }

        data->currentTab = tabIndex;
        if (data->currentTab >= 0) {
            Menu* tab = &data->tabs[data->currentTab];
            tab->parent = item->owner;
            item->imenu = tab;
        }
    }
}

void Menu_TabPrevious(MenuItem* item) {
    TabData* data = item->data;

    if (data->numTabs >= 0) {
        s32 tabIndex = (data->currentTab + data->numTabs - 1) % data->numTabs;
        Menu_TabGoto(item, tabIndex);
    }
}

void Menu_TabNext(MenuItem* item) {
    TabData* data = item->data;

    if (data->numTabs >= 0) {
        s32 tabIndex = (data->currentTab + 1) % data->numTabs;
        Menu_TabGoto(item, tabIndex);
    }
}
