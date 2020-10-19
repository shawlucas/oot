#include <ultra64.h>
#include <global.h>
#include "gz.h"
#include "settings.h"
#include "menu.h"

GZ gz;

void GZ_Init(GameState* game) {
    s32 i;
    Input* input = &game->input;
    GlobalContext* globalCtx = (GlobalContext *)game;
    Player* player = PLAYER;
    
    {  
        /* handle emergency settings reset */
        u16 curButton = input[0].cur.button;
        if (CHECK_BTN_ANY(curButton, BTN_CRIGHT | BTN_CLEFT | BTN_CDOWN | BTN_CUP | BTN_R |BTN_L | BTN_DRIGHT | BTN_DLEFT | 
                                                BTN_DDOWN | BTN_DUP | BTN_START | BTN_Z | BTN_B | BTN_A)) {
            static const u16 inputList[] = {
                BTN_DUP,
                BTN_DUP,
                BTN_DDOWN,
                BTN_DDOWN,
                BTN_DLEFT,
                BTN_DRIGHT,
                BTN_DLEFT,
                BTN_DRIGHT,
                BTN_B,
                BTN_A,
            };
            static s32 inputPos = 0;
            size_t inputListLength = sizeof(inputList) / sizeof(*inputList);
            if (CHECK_BTN_ANY(curButton, BTN_CRIGHT | BTN_CLEFT | BTN_CDOWN | BTN_CUP | BTN_R |BTN_L | BTN_DRIGHT | BTN_DLEFT | 
                                                BTN_DDOWN | BTN_DUP | BTN_START | BTN_Z | BTN_B | BTN_A) == inputList[inputPos]) {
                ++inputPos;
                if (inputPos == inputListLength) {
                    inputPos = 0;
                    Settings_LoadDefault();
                    gz_apply_settings();
                }
            } else {
                inputPos = 0;
            }
        }
    }

    if (gz.menuActive) {
        if (Input_BindPressedRaw(COMMAND_MENU))
            gz_hide_menu();
        else if (Input_BindPressed(COMMAND_RETURN))
            Menu_Return(gz.menuMain);
        else {
            Input* input = &game->input[0];
            if (CHECK_BTN_ALL(input->cur.button, BTN_DUP)) 
                Menu_Navigate(gz.menuMain, MENU_NAVIGATE_UP);
            if (CHECK_BTN_ALL(input->cur.button, BTN_DDOWN))
                Menu_Navigate(gz.menuMain, MENU_NAVIGATE_DOWN);
            if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT))
                Menu_Navigate(gz.menuMain, MENU_NAVIGATE_LEFT);
            if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT))
                Menu_Navigate(gz.menuMain, MENU_NAVIGATE_RIGHT);
            if (CHECK_BTN_ALL(input->cur.button, BTN_L))
                Menu_Activate(gz.menuMain);
        }
    } else if (!Input_BindPressedRaw(COMMAND_MENU))
        gz_show_menu();
    
    /* apply cheats */
    if (settings->cheats & (1 << CHEAT_ENERGY))
        gSaveContext.health = gSaveContext.healthCapacity;
    if (settings->cheats & (1 << CHEAT_MAGIC))
        gSaveContext.magic = (gSaveContext.magicLevel + 1) * 0x30;
    if (settings->cheats & (1 << CHEAT_STICKS)) {
        AMMO(ITEM_STICK) = CAPACITY(UPG_STICKS, 3);
    }
    if (settings->cheats & (1 << CHEAT_NUTS)) {
        AMMO(ITEM_NUT) = CAPACITY(UPG_NUTS, 3);
    }
    if (settings->cheats & (1 << CHEAT_BOMBS)) {
        AMMO(ITEM_BOMB) = CAPACITY(UPG_BOMB_BAG, 3);
    }
    if (settings->cheats & (1 << CHEAT_ARROWS)) {
        AMMO(ITEM_BOW) = CAPACITY(UPG_QUIVER, 3);
    }
    if (settings->cheats & (1 << CHEAT_SEEDS)) {
        AMMO(ITEM_SLINGSHOT) = CAPACITY(UPG_BULLET_BAG, 3);
    }
    if (settings->cheats & (1 << CHEAT_BOMBCHUS))
        AMMO(ITEM_BOMBCHU) = 50;
    if (settings->cheats & (1 << CHEAT_BEANS))
        AMMO(ITEM_BEAN) = 1;
    if (settings->cheats & (1 << CHEAT_KEYS)) {
        if (globalCtx->sceneNum >= 0x0000 && globalCtx->sceneNum <= 0x0010)
            gSaveContext.inventory.dungeonKeys[globalCtx->sceneNum] = 1;
    }
    if (settings->cheats & (1 << CHEAT_RUPEES)) {
        gSaveContext.rupees = CAPACITY(UPG_WALLET, 3);
    }

    if (settings->cheats & (1 << CHEAT_NL))
        gSaveContext.nayrusLoveTimer = 0x044B;
    if (settings->cheats & (1 << CHEAT_FREEZETIME)) {
        u16 timeAdvance1 = gz.dayTimePrev + gDaySpeed;
        u16 timeAdvance2 = gz.dayTimePrev + gDaySpeed * 2;
        if (gz.targetDayTime == -1 && gDaySpeed < 0x0190 && (gSaveContext.dayTime == timeAdvance1 || gSaveContext.dayTime == timeAdvance2)) {
            gSaveContext.dayTime = gz.dayTimePrev;
        }
    }
    if (settings->cheats & (1 << CHEAT_NOMUSIC)) {
        Audio_SetBGM(0x100000FF);
        Audio_SetBGM(0x110000FF);
        Audio_SetBGM(0x130000FF);
        gSaveContext.seqIndex = -1;
        gSaveContext.nightSeqIndex = -1;
    }
    if (settings->cheats & (1 << CHEAT_USEITEMS)) {
        memset(&globalCtx->interfaceCtx.restrictions, 0, sizeof(globalCtx->interfaceCtx.restrictions));
    }
    if (settings->cheats & (1 << CHEAT_NOMAP))
        WREG(31) = 1; // minimap_disabled
    if (settings->cheats & (1 << CHEAT_ISG))
        player->swordState = 1;
    if (settings->cheats & (1 << CHEAT_QUICKTEXT))
        osSyncPrintf("NOT IMPLEMENTED\n");

    /* handle commands */
    for (i = 0; i < COMMAND_MAX; ++i) {
        u8 active = 0;
        switch (gGZCommandInfo[i].activationType) {
            case CMDACT_HOLD:
                active = Input_BindHeld(i);
                break;
            case CMDACT_PRESS:
                active = Input_BindPressed(i);
                break;
            case CMDACT_PRESS_ONCE:
                active = Input_BindPressedRaw(i);
                break;
        }

        if (gGZCommandInfo[i].update && active)
            gGZCommandInfo[i].update();
    }

    if (Input_BindPressed(COMMAND_PREVROOM))
        Explorer_RoomPrev(gz.menuExplorer);
    if (Input_BindPressed(COMMAND_NEXTROOM))
        Explorer_RoomNext(gz.menuExplorer);
    
    /* animate menus */
    while (gz.menuActive && Menu_Think(gz.menuMain))
        ;
    while (Menu_Think(gz.menuGlobal))
        ;
    
    /* update daytime after menu processing to avoid desync */
    if (gz.targetDayTime != -1) {
        const u16 speed = 0x0800;
        if (gSaveContext.dayTime < gz.targetDayTime && gz.targetDayTime - gSaveContext.dayTime <= speed) {
            gSaveContext.dayTime = gz.targetDayTime;
            gz.targetDayTime = -1;
        } else 
            gSaveContext.dayTime += speed;
    }

    gz.dayTimePrev = gSaveContext.dayTime;

    /* save gfx pointer offsets for frame advance display list copy */

    /* zu_save_disp_p(&gz.z_disp_p); */

    /* get menu appearance */

    {
        GfxPrint* printer = Menu_GetPrinter(gz.menuMain, 1);
        u8 alpha = Menu_GetAlpha_i(gz.menuMain, 1);
        s32 cw = Menu_GetCellWidth(gz.menuMain, 1);
        s32 ch = Menu_GetCellHeight(gz.menuMain, 1);
    }
    
}