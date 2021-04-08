#include <global.h>
#include <alloca.h>
#include "../libgz/vector.h"
#include "menu.h"
#include "util.h"

typedef struct ItemData {
    struct vector options;
    MenuGeneric callback;
    void* callbackData;
    s32 value;
    u8 active;
} ItemData;

static s32 think(MenuItem* item) {
    ItemData* data = item->data;

    if (data->callback) {
        s32 r = data->callback(item, MENU_CALLBACK_THINK, data->callbackData);
        if (r) {
            return r;
        }

        if (data->active) {
            r = data->callback(item, MENU_CALLBACK_THINK_ACTIVE, data->callbackData);
        } else {
            r = data->callback(item, MENU_CALLBACK_THINK_INACTIVE, data->callbackData);
        }

        return r;
    }

    return 0;
}

static s32 navigate(MenuItem* item, MenuNavigation nav) {
    s32 value;
    char** option;
    ItemData* data = item->data;

    if (data->callback != NULL && data->callback(item, MENU_CALLBACK_NAV_UP + nav, data->callbackData)) {
        return 1;
    }

    value = data->value;
    switch (nav) {
        case MENU_NAVIGATE_UP:
            value += 1;
            break;
        case MENU_NAVIGATE_DOWN:
            value -= 1;
            break;
        case MENU_NAVIGATE_LEFT:
            value -= 3;
            break;
        case MENU_NAVIGATE_RIGHT:
            value += 3;
            break;
    }

    value %= (s32)data->options.size;

    if (value < 0) {
        value += (s32)data->options.size;
    }

    data->value = value;

    option = vector_at(&data->options, data->value);

    item->text = *option;

    if (data->callback != NULL) {
        data->callback(item, MENU_CALLBACK_CHANGED, data->callbackData);
    }

    return 1;

}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;

    if (data->active) {
        if (data->callback != NULL && data->callback(item, MENU_CALLBACK_DEACTIVATE, data->callbackData)) {
            return 1;
        }
        item->navigate = NULL;
        item->animateHighlight = 0;
    } else {
        if (data->callback != NULL && data->callback(item, MENU_CALLBACK_ACTIVATE, data->callbackData)) {
            return 1;
        }

        item->navigate = navigate;
        item->animateHighlight = 1;
    }

    data->active = !data->active;
    return 1;
}

static s32 destroy(MenuItem* item) {
    size_t i;
    ItemData* data = item->data;

    item->text = NULL;

    for (i = 0; i < data->options.size; ++i) {
        char** option = vector_at(&data->options, i);
        bzero(*option, sizeof(*option)); // CHECK THIS LATEr, DONT KNOW IF THIS WILL WORK
    }

    vector_destroy(&data->options);
    return 0;
}

static MenuItem* Menu_AddOption(Menu* menu, s32 x, s32 y, const char* options, MenuGeneric callback, void* callbackData) {
    const char* option;
    const char** option2;
    MenuItem* item;
    ItemData* data = alloca(sizeof(*data));

    vector_init(&data->options, sizeof(char *));

    for (option = options; *option;) {
        size_t optionLength = strlen(option);
        char* newOption = alloca(optionLength + 1);
        strcpy(newOption, option);
        vector_push_back(&data->options, 1, &newOption);
        option += optionLength + 1;
    }

    data->callback = callback;
    data->callbackData = callbackData;
    data->value = 0;
    data->active = false;
    item = Menu_ItemAdd(menu, x, y, NULL, 0xFFFFFF);
    option2 = vector_at(&data->options, data->value);
    item->text = *option2;
    item->data = data;
    item->think = think;
    item->activate = activate;
    item->destroy = destroy;

    return item;
}

s32 Menu_OptionGet(MenuItem* item) {
    ItemData* data = item->data;

    return data->value;
}

void Menu_OptionSet(MenuItem* item, s32 value) {
    char** option;
    ItemData* data = item->data;

    data->value = value;

    option = vector_at(&data->options, data->value);

    item->text = *option;
}
