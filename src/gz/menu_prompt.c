#include <global.h>
#include <alloca.h>
#include "menu.h"
#include "util.h"

static Menu sPromptMenu;
static MenuPrompt sPromptCallback;
static void* sPromptCallbackData;

static s32 doCallback(s32 index) {
    if (sPromptCallback != NULL) {
        MenuPrompt proc = sPromptCallback;
        sPromptCallback = NULL;
        return proc(index, sPromptCallbackData);
    } else {
        return 0;
    }
}

static s32 leave(MenuItem* item, MenuSwitchReason reason) {
    if (reason == MENU_SWITCH_RETURN) {
        doCallback(-1);
    }

    return 0;
}

static s32 activate(MenuItem* item) {
    s32 index = (s32)item->data;

    if (!doCallback(index)) {
        Menu_Return(&sPromptMenu);
    }

    return 0;
}

static s32 destroy(MenuItem* item) {
    item->data = NULL;
    return 0;
}

void Menu_Prompt(Menu* menu, const char* prompt, const char* options, s32 defaultOption, MenuPrompt callback, void* callbackData) {
    MenuItem* item;
    s32 i;
    const char* option;
    static u8 ready = 0;

    if (ready) {
        if (menu == &sPromptMenu) {
            menu = sPromptMenu.parent;
            Menu_Return(&sPromptMenu);
        }

        Menu_Destroy(&sPromptMenu);
    } else {
        ready = 1;
    }

    Menu_Init(&sPromptMenu, MENU_NOVALUE, MENU_NOVALUE, MENU_NOVALUE);

    item = Menu_AddStatic(&sPromptMenu, 0, 0, prompt, 0xC0C0C0);

    item->leave = leave;

    option = options;

    for (i = 0; *option; ++i) {
        size_t optionLength;
        char* newOption;
        item = Menu_ItemAdd(&sPromptMenu, option - options, 1, NULL, 0xFFFFFF);
        item->data = (void *)i;
        optionLength = strlen(option);
        newOption = alloca(optionLength + 1);
        strcpy(newOption, option);
        item->text = newOption;
        item->activate = activate;
        item->destroy = destroy;
        option += optionLength + 1;

        if (i == defaultOption) {
            sPromptMenu.selector = item;
        }
    }

    sPromptCallback = callback;
    sPromptCallbackData = callbackData;
    Menu_Enter(menu, &sPromptMenu);
}
