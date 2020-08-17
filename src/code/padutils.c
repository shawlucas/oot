#include <global.h>

void PadUtils_Init(Input* input) {
    bzero(input, sizeof(Input));
}

void func_800FCB70() {
}

void PadUtils_ResetPressRel(Input* input) {
    input->press.button = 0;
    input->rel.button = 0;
}

u32 PadUtils_CheckCurExact(Input* input, u16 value) {
    return value == input->cur.button;
}

u32 PadUtils_CheckCur(Input* input, u16 key) {
    return key == (input->cur.button & key);
}

u32 PadUtils_CheckPressed(Input* input, u16 key) {
    return key == (input->press.button & key);
}

u32 PadUtils_CheckReleased(Input* input, u16 key) {
    return key == (input->rel.button & key);
}

u16 PadUtils_GetCurButton(Input* input) {
    return input->cur.button;
}

u16 PadUtils_GetPressButton(Input* input) {
    return input->press.button;
}

s8 PadUtils_GetCurX(Input* input) {
    return input->cur.x;
}

s8 PadUtils_GetCurY(Input* input) {
    return input->cur.y;
}

void PadUtils_SetRelXY(Input* input, s32 x, s32 y) {
    input->rel.x = x;
    input->rel.y = y;
}

s8 PadUtils_GetRelXImpl(Input* input) {
    return input->rel.x;
}

s8 PadUtils_GetRelYImpl(Input* input) {
    return input->rel.y;
}

s8 PadUtils_GetRelX(Input* input) {
    return PadUtils_GetRelXImpl(input);
}

s8 PadUtils_GetRelY(Input* input) {
    return PadUtils_GetRelYImpl(input);
}

void PadUtils_UpdateRelXY(Input* input) {
    s32 curX, curY;
    s32 relX, relY;

    curX = PadUtils_GetCurX(input);
    curY = PadUtils_GetCurY(input);

    if (curX > 7) {
        relX = (curX < 0x43) ? curX - 7 : 0x43 - 7;
    } else if (curX < -7) {
        relX = (curX > -0x43) ? curX + 7 : -0x43 + 7;
    } else {
        relX = 0;
    }

    if (curY > 7) {
        relY = (curY < 0x43) ? curY - 7 : 0x43 - 7;

    } else if (curY < -7) {
        relY = (curY > -0x43) ? curY + 7 : -0x43 + 7;
    } else {
        relY = 0;
    }

    PadUtils_SetRelXY(input, relX, relY);
}
