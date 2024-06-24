#include "global.h"

typedef struct {
    /* 0x00 */ u16* value;
    /* 0x04 */ const char* name;
} FlagSetEntry; // size = 0x08

void FlagSet_Update(PlayState* play) {
    static s32 entryIdx = 0;
    static u32 curBit = 0;
    static s32 timer = 0;
    static s32 bitIdx; // ? this doesn't need to be static

    FlagSetEntry entries[53] = {
        { &gSaveContext.save.info.eventChkInf[0], "eventChkInf[0]" },
        { &gSaveContext.save.info.eventChkInf[1], "eventChkInf[1]" },
        { &gSaveContext.save.info.eventChkInf[2], "eventChkInf[2]" },
        { &gSaveContext.save.info.eventChkInf[3], "eventChkInf[3]" },
        { &gSaveContext.save.info.eventChkInf[4], "eventChkInf[4]" },
        { &gSaveContext.save.info.eventChkInf[5], "eventChkInf[5]" },
        { &gSaveContext.save.info.eventChkInf[6], "eventChkInf[6]" },
        { &gSaveContext.save.info.eventChkInf[7], "eventChkInf[7]" },
        { &gSaveContext.save.info.eventChkInf[8], "eventChkInf[8]" },
        { &gSaveContext.save.info.eventChkInf[9], "eventChkInf[9]" },
        { &gSaveContext.save.info.eventChkInf[10], "eventChkInf[10]" },
        { &gSaveContext.save.info.eventChkInf[11], "eventChkInf[11]" },
        { &gSaveContext.save.info.eventChkInf[12], "eventChkInf[12]" },
        { &gSaveContext.save.info.eventChkInf[13], "eventChkInf[13]" },
        { &gSaveContext.save.info.itemGetInf[0], "itemGetInf[0]" },
        { &gSaveContext.save.info.itemGetInf[1], "itemGetInf[1]" },
        { &gSaveContext.save.info.itemGetInf[2], "itemGetInf[2]" },
        { &gSaveContext.save.info.itemGetInf[3], "itemGetInf[3]" },
        { &gSaveContext.save.info.infTable[0], "infTable[0]" },
        { &gSaveContext.save.info.infTable[1], "infTable[1]" },
        { &gSaveContext.save.info.infTable[2], "infTable[2]" },
        { &gSaveContext.save.info.infTable[3], "infTable[3]" },
        { &gSaveContext.save.info.infTable[4], "infTable[4]" },
        { &gSaveContext.save.info.infTable[5], "infTable[5]" },
        { &gSaveContext.save.info.infTable[6], "infTable[6]" },
        { &gSaveContext.save.info.infTable[7], "infTable[7]" },
        { &gSaveContext.save.info.infTable[8], "infTable[8]" },
        { &gSaveContext.save.info.infTable[9], "infTable[9]" },
        { &gSaveContext.save.info.infTable[10], "infTable[10]" },
        { &gSaveContext.save.info.infTable[11], "infTable[11]" },
        { &gSaveContext.save.info.infTable[12], "infTable[12]" },
        { &gSaveContext.save.info.infTable[13], "infTable[13]" },
        { &gSaveContext.save.info.infTable[14], "infTable[14]" },
        { &gSaveContext.save.info.infTable[15], "infTable[15]" },
        { &gSaveContext.save.info.infTable[16], "infTable[16]" },
        { &gSaveContext.save.info.infTable[17], "infTable[17]" },
        { &gSaveContext.save.info.infTable[18], "infTable[18]" },
        { &gSaveContext.save.info.infTable[19], "infTable[19]" },
        { &gSaveContext.save.info.infTable[20], "infTable[20]" },
        { &gSaveContext.save.info.infTable[21], "infTable[21]" },
        { &gSaveContext.save.info.infTable[22], "infTable[22]" },
        { &gSaveContext.save.info.infTable[23], "infTable[23]" },
        { &gSaveContext.save.info.infTable[24], "infTable[24]" },
        { &gSaveContext.save.info.infTable[25], "infTable[25]" },
        { &gSaveContext.save.info.infTable[26], "infTable[26]" },
        { &gSaveContext.save.info.infTable[27], "infTable[27]" },
        { &gSaveContext.save.info.infTable[28], "infTable[28]" },
        { &gSaveContext.save.info.infTable[29], "infTable[29]" },
        { &gSaveContext.eventInf[0], "eventInf[0]" },
        { &gSaveContext.eventInf[1], "eventInf[1]" },
        { &gSaveContext.eventInf[2], "eventInf[2]" },
        { &gSaveContext.eventInf[3], "eventInf[3]" },
    };

    GraphicsContext* gfxCtx = play->state.gfxCtx;
    Input* input = &play->state.input[0];
    Gfx* gfx;
    Gfx* polyOpa;

    OPEN_DISPS(gfxCtx, "../flg_set.c", 131);

    {
        GfxPrint printer;
        s32 pad;

        polyOpa = POLY_OPA_DISP;
        gfx = Gfx_Open(polyOpa);
        gSPDisplayList(OVERLAY_DISP++, gfx);

        GfxPrint_Init(&printer);
        GfxPrint_Open(&printer, gfx);
        GfxPrint_SetColor(&printer, 250, 50, 50, 255);
        GfxPrint_SetPos(&printer, 4, 13);
        GfxPrint_Printf(&printer, entries[entryIdx].name);
        GfxPrint_SetPos(&printer, 4, 15);

        for (bitIdx = 15; bitIdx >= 0; bitIdx--) {
            if ((u32)bitIdx == curBit) {
                GfxPrint_SetColor(&printer, 200, 200, 200, 255);
            } else {
                GfxPrint_SetColor(&printer, 100, 100, 100, 255);
            }

            if (*entries[entryIdx].value & (1 << bitIdx)) {
                GfxPrint_Printf(&printer, "1");
            } else {
                GfxPrint_Printf(&printer, "0");
            }

            if ((bitIdx % 4) == 0) {
                GfxPrint_Printf(&printer, " ");
            }
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_DLEFT)) {
            timer = 10;
            curBit++;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_DRIGHT)) {
            curBit--;
            timer = 10;
        }

        if (timer == 0) {
            if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT)) {
                curBit++;
                timer = 2;
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT)) {
                curBit--;
                timer = 2;
            }
        }

        curBit %= 16;
        if (CHECK_BTN_ALL(input->press.button, BTN_DUP)) {
            entryIdx--;
            if (entryIdx < 0) {
                entryIdx = 0;
            }
            timer = 10;
        }
        if (CHECK_BTN_ALL(input->press.button, BTN_DDOWN)) {
            timer = 10;
            entryIdx++;
            if (!entries[entryIdx].value) {
                entryIdx--;
            }
        }

        if (timer == 0) {
            if (CHECK_BTN_ALL(input->cur.button, BTN_DUP)) {
                entryIdx--;
                timer = 2;
                if (entryIdx < 0) {
                    entryIdx = 0;
                }
            }
            if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN)) {
                timer = 2;
                entryIdx++;
                if (!entries[entryIdx].value) {
                    entryIdx--;
                }
            }
        }

        if (CHECK_BTN_ALL(input->press.button, BTN_A)) {
            *entries[entryIdx].value ^= (1 << curBit);
        }

        if (timer != 0) {
            timer--;
        }

        gfx = GfxPrint_Close(&printer);
        GfxPrint_Destroy(&printer);

        gSPEndDisplayList(gfx++);
        Gfx_Close(polyOpa, gfx);
        POLY_OPA_DISP = gfx;
    }

    if (CHECK_BTN_ALL(input->press.button, BTN_L)) {
        play->pauseCtx.debugState = 0;
    }

    CLOSE_DISPS(gfxCtx, "../flg_set.c", 241);
}
