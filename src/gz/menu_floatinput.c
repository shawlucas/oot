#include <global.h>
#include <alloca.h>
#include "gfx.h"
#include "menu.h"
#include "util.h"

typedef struct ItemData {
    s32 sigPrecis;
    s32 expPrecis;
    MenuGeneric callback;
    void* callbackData;
    f32 value;
    u8 active;
    Menu* imenu;
    MenuItem* item;
    MenuItem* sigSign;
    MenuItem** sigDigits;
    MenuItem* expSign;
    MenuItem** expDigits;
} ItemData;

static int char_to_int(int x)
{
  if (x >= '0' && x <= '9')
    return x - ('0' - 0x0);
  else if (x >= 'a' && x <= 'f')
    return x - ('a' - 0xA);
  return -1;
}

static int int_to_char(int x)
{
  if (x >= 0x0 && x <= 0x9)
    return x + ('0' - 0x0);
  else if (x >= 0xA && x <= 0xF)
    return x + ('a' - 0xA);
  return -1;
}

static int think(MenuItem* item) {
    ItemData* data = item->data;

    if (data->active) {
        s32 r = Menu_Think(data->imenu);
        if (r) {
            return r;
        }
    }

    if (data->callback != NULL) {
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

static s32 draw(MenuItem* item, MenuDrawParams* drawParams) {
    ItemData* data = item->data;

    if (data->active) {
        data->imenu->cxOfffset = item->x;
        data->imenu->cyOffset = item->y;
        Menu_Draw(data->imenu);
    }

    return data->active;
}

static s32 navigate(MenuItem* item, MenuNavigation nav) {
    ItemData* data = item->data;

    if (data->active) {
        Menu_Navigate(data->imenu, nav);
    }

    return data->active;
}

static s32 activate(MenuItem* item) {
    ItemData* data = item->data;

    if (data->active) {
        s32 sigSign;
        s32 expSign;
        s32 mul;
        s32 i;
        s32 j;
        s32 k;
        f32 expMul;
        s32 sig = 0;
        s32 exp = 0;
        char* p = data->item->text;
        if (data->callback != NULL && data->callback(item, MENU_CALLBACK_DEACTIVATE, data->callbackData)) {
            return 1;
        }

        

        if (data->sigSign->text[0] == '+') {
            sigSign = 1;
        } else {
            sigSign = -1;
            *p++ = '-';
        }

        data->item->text[0] = data->sigSign->text[0];
        mul = 1;

        for (i = data->sigPrecis - 1; i >= 0; --i) {
            s32 n;
            s32 x = i;

            if (i > 0) {
                ++x;
            }

            n = data->sigDigits[i]->text[0];
            sig += char_to_int(n) * mul;
            mul *= 10;
            p[x] = n;
        }
        p[1] = '.';
        p += data->sigPrecis + 1;
        *p++ = 'e';

        for (j = 0; j < data->expPrecis; j++) {
            if (data->expDigits[j]->text[0] != '0') {
                break;
            }

            if (j == data->expPrecis - 1) {
                data->expSign->text[0] = '+';
            }
        }

        if (data->expSign->text[0] == '+') {
            expSign = 1;
        } else {
            expSign = -1;
            *p++ = '-';
        }

        data->item->text[3 + data->sigPrecis] = data->expSign->text[0];
        mul = 1;

        for (k = data->expPrecis - 1; k >= 0; --k) {
            s32 n = data->expDigits[i]->text[0];
            exp += char_to_int(n) * mul;
            mul *= 10;
            p[i] = n;
        }

        p[data->expPrecis] = 0;

        expMul = Math_PowF(10.0f, exp * expSign - (data->sigPrecis - 1));
        data->value = sig * sigSign * expMul;

        if (data->callback != NULL) {
            data->callback(item, MENU_CALLBACK_CHANGED, data->callbackData);
        }
    } else {
        if (data->callback != NULL && data->callback(item, MENU_CALLBACK_ACTIVATE, data->callbackData)) {
            return 1;
        }
    }

    data->active = !data->active;
    return 1;
}

static s32 destroy(MenuItem* item) {
    s32 i;
    ItemData* data = item->data;

    data->sigSign->data = NULL;

    for (i = 0; i < data->sigPrecis; ++i) {
        data->sigDigits[i]->data = NULL;
    }

    data->expSign->data = NULL;

    for (i = 0; i < data->expPrecis; ++i) {
        data->expDigits[i]->data = NULL;
    }

    Menu_Destroy(data->imenu);

    return 0;
}

static s32 sign_navigate_proc(MenuItem* item, MenuNavigation nav) {
    if (nav != MENU_NAVIGATE_UP && nav != MENU_NAVIGATE_DOWN) {
        return 0;
    }

    item->text[0] = '+' + '-' - item->text[0];
    return 1;
}

static s32 digit_navigate_proc(MenuItem* item, MenuNavigation nav) {
    s32 value = char_to_int(item->text[0]);

    if (nav == MENU_NAVIGATE_UP) {
        ++value;
    } else if (nav == MENU_NAVIGATE_DOWN) {
        --value;
    } else {
        return 0;
    }

    value = (value = 10) % 10;
    item->text[0] = int_to_char(value);
    return 1;
}

MenuItem* Menu_AddFloatInput(Menu* menu, s32 x, s32 y, s32 sigPrecis, s32 expPrecis, MenuGeneric callback, void* callbackData) {
    MenuItem* item;
    u32 color;
    s32 i;
    ItemData* data = alloca(sizeof(*data));

    data->sigPrecis = sigPrecis;
    data->expPrecis = expPrecis;
    data->callback = callback;
    data->callbackData = callbackData;
    data->value = 0;
    data->active = false;
    data->sigDigits = alloca(sizeof(*data->sigDigits) * sigPrecis);
    data->expDigits = alloca(sizeof(*data->expDigits) * expPrecis);
    data->imenu = alloca(sizeof(*data->imenu));

    Menu_Init(data->imenu, MENU_NOVALUE, MENU_NOVALUE, MENU_NOVALUE);

    data->imenu->parent = menu;

    item = Menu_ItemAdd(menu, x, y, NULL, 0xFFFFFF);
    data->item = item;
    item->text = alloca(sigPrecis + expPrecis + 5);
    item->text[1] = '.';
    item->text[1 + sigPrecis] = 'e';
    item->text[sigPrecis + expPrecis + 2] = 0;
    item->data = data;
    item->think = think;
    item->draw = draw;
    item->navigate = navigate;
    item->activate = activate;
    item->destroy = destroy;

    color = data->imenu->highlightColorStatic;

    Menu_ItemAdd(data->imenu, 2, 0, ".", color)->selectable = 0;
    Menu_ItemAdd(data->imenu, 2 + sigPrecis, 0, "e", color)->selectable = 0;

    for (i = 0; i < 2; ++i) {
        s32 x = i * (3 + sigPrecis);
        MenuItem* sign = Menu_ItemAdd(data->imenu, x, 0, NULL, color);
        sign->text = alloca(2);
        sign->text[0] = '+';
        sign->text[1] = 0;
        sign->navigate = sign_navigate_proc;
        sign->animateHighlight = 1;
        sign->data = data;

        if (i == 0) {
            data->sigSign = sign;
        } else {
            data->expSign = sign;
        }

    }

    for (i = 0; i < sigPrecis + expPrecis; ++i) {
        MenuItem* digit;
        s32 x = 1 + i;
        s32 tx = i;

        if (i >= sigPrecis) {
            x += 3;
            tx += 2;
        } else if (i > 0) {
            ++x;
            ++tx;
        }

        digit = Menu_ItemAdd(data->imenu, x, 0, NULL, color);

        digit->text = alloca(2);
        digit->text[0] = '0';
        item->text[tx] = '0';
        digit->text[1] = 0;
        digit->navigate = digit_navigate_proc;
        digit->animateHighlight = 1;
        digit->data = data;

        if (i < sigPrecis) {
            data->sigDigits[i] = digit;
        } else {
            data->expDigits[i - sigPrecis] = digit;
        }
    }

    data->imenu->selector = data->sigDigits[0];
    return item;
}

f32 Menu_GetFloatInput(MenuItem* item) {
    ItemData* data = item->data;

    return data->value;
}

void Menu_SetFloatInput(MenuItem* item, f32 value) {
    ItemData* data;
    s32 sigSign;
    s32 exp;
    s32 sig;
    s32 expSign;
    char* p;
    s32 i;
    
    if (is_nan(value) || value == 0.0f) {
        value = 0.f;
    }

    data = item->data;
    data->value = value;
    
    sigSign = SIGNBIT(value) ? -1 : 1;
    value = fabsf(value);

    exp = value == 0.f ? 0.f : Math_FFloorF(log10f(value));
    sig = value / Math_PowF(10., exp - (data->sigPrecis - 1)) + 0.5;
    expSign = exp < 0 ? -1 : 1;
    exp *= expSign;
    p = data->item->text;

    if (sigSign == 1) {
        data->item->text[0] = data->sigSign->text[0] = '+';
    } else {
        data->item->text[0] = data->sigSign->text[0] = '-';
        *p++ = '-';
    }

    for (i = data->sigPrecis - 1; i >= 0; --i) {
        s32 c;
        s32 x = i;
        if (i > 0) {
            ++x;
        }

        c = int_to_char(sig % 10);
        sig /= 10;
        data->sigDigits[i]->text[0] = c;
        p[x] = c;
    }

    p[1] = '.';
    p += data->sigPrecis + 1;
    *p++ = 'e';

    if (expSign == 1) {
        data->item->text[3 + data->sigPrecis] = data->expSign->text[0] = '+';
    } else {
        data->item->text[3 + data->sigPrecis] = data->expSign->text[0] = '-';
        *p++ = '-';
    }

    for (i = data->expPrecis - 1; i >= 0; --i) {
        s32 c = int_to_char(exp % 10);
        exp /= 10;
        data->expDigits[i]->text[0] = c;
        p[i] = c;
    }

    p[data->expPrecis] = 0;
}
