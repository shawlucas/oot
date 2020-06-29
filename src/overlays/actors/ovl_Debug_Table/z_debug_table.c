#include "z_debug_table.h"
#include <alloca.h>

#define FLAGS 0x00000030

#define RETURN -1

#define THIS ((DebugTable*)thisx)

void DebugTable_Init(Actor* thisx, GlobalContext* globalCtx);
void DebugTable_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DebugTable_Update(Actor* thisx, GlobalContext* globalCtx);
void DebugTable_Draw(Actor* thisx, GlobalContext* globalCtx);

void DebugTable_DrawDebug(DebugTable* this, GlobalContext* globalCtx);
void DebugTable_DrawWarpList(DebugTable* this, GlobalContext* globalCtx);
void DebugTable_WarpListUpdate(DebugTable* this, GlobalContext* globalCtx);
void DebugTable_DrawDungeonList(DebugTable* this, GlobalContext* globalCtx);
void DebugTable_DungeonListUpdate(DebugTable* this, GlobalContext* globalCtx);
void DebugTable_BossesListUpdate(DebugTable* this, GlobalContext* globalCtx);
void DebugTable_DrawBossesList(DebugTable* this, GlobalContext* globalCtx);
s32 DebugTable_CheckPad(DebugTable* this, Input* input, u8 button, u8 activeMenu, u8 numOf);

static char* sDungeonList[] = {
    "Deku Tree",    "Dodongo's Cavern", "Jabu Jabu's Belly", "Forest Temple",         "Fire Temple",
    "Water Temple", "Shadow Temple",    "Spirit Temple",     "Inside Ganon's Castle",
};

static char* sBossList[] = {
    "Gohma",  "King Dodongo", "Barinade", "Phantom Ganon", "Volvagia",
    "Morpha", "Bongo Bongo",  "Twinrova", "Ganondorf",     "Ganon",
};

const ActorInit Debug_Table_InitVars = {
    ACTOR_DEBUG_TABLE,
    ACTORTYPE_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(DebugTable),
    (ActorFunc)DebugTable_Init,
    (ActorFunc)DebugTable_Destroy,
    (ActorFunc)DebugTable_Update,
    (ActorFunc)DebugTable_Draw,
};

void DebugTable_Init(Actor* thisx, GlobalContext* globalCtx) {
    s32 i;

    DebugTable* this = THIS;
    this->cursorPos = MENU_DEBUG;
    this->activeMenu = MAIN_MENU;
    this->actionTimer = 10;
    this->menuDepth = 0;

    this->mainMenu[MENU_DEBUG].pos.x = 2;
    this->mainMenu[MENU_DEBUG].pos.y = 4;
    this->mainMenu[MENU_DEBUG].name = "Debug";

    this->mainMenu[MENU_WARPS].pos.x = 2;
    this->mainMenu[MENU_WARPS].pos.y = 6;
    this->mainMenu[MENU_WARPS].name = "Warps";

    this->warpMenu[WARPS_DUNGEONS].pos.x = 2;
    this->warpMenu[WARPS_DUNGEONS].pos.y = 4;
    this->warpMenu[WARPS_DUNGEONS].name = "Dungeons";

    this->warpMenu[WARPS_BOSSES].pos.x = 2;
    this->warpMenu[WARPS_BOSSES].pos.y = 6;
    this->warpMenu[WARPS_BOSSES].name = "Bosses";

    for (i = 0; i < NUM_OF_DUNGEONS; i++) {
        this->dungeonMenu[i].pos.x = 2;
        this->dungeonMenu[i].pos.y = i + 4;
        this->dungeonMenu[i].name = sDungeonList[i];
    }

    for (i = 0; i < NUM_OF_BOSSES; i++) {
        this->bossMenu[i].pos.x = 2;
        this->bossMenu[i].pos.y = i + 4;
        this->bossMenu[i].name = sBossList[i];
    }
}

void DebugTable_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DebugTable* this = THIS;
    Actor_Kill(thisx);
}

void DebugTable_Update(Actor* thisx, GlobalContext* globalCtx) {
    DebugTable* this = THIS;
    Input* input = &globalCtx->state.input;

    this->pressed = DebugTable_CheckPad(this, input, L_TRIG, MAIN_MENU, NUM_OF_ITEMS);

    if (this->pressed == 1) {
        switch (this->cursorPos) {
            case MENU_DEBUG:
                this->activeMenu = DEBUG_MENU;
                this->actor.draw = DebugTable_DrawDebug;
                break;
            case MENU_WARPS:
                this->activeMenu = WARP_CATEGORY_MENU;
                this->actor.update = DebugTable_WarpListUpdate;
                this->actor.draw = DebugTable_DrawWarpList;
                break;
        }
        this->cursorPos = 0;
        this->pressed = 0;
        this->menuDepth = 1;
        this->actionTimer = 10;
    }
}

void DebugTable_Draw(Actor* thisx, GlobalContext* globalCtx) {
    DebugTable* this = THIS;
    s32 i;
    GfxPrint* printer = alloca(sizeof(GfxPrint));
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    for (i = 0; i < NUM_OF_ITEMS; i++) {
        GfxPrint_SetPos(printer, this->mainMenu[i].pos.x, this->mainMenu[i].pos.y);
        if (this->cursorPos == i) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 255, 255, 255, 255);
        }

        GfxPrint_Printf(printer, this->mainMenu[i].name);
    }
    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}

void DebugTable_WarpListUpdate(DebugTable* this, GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input;

    this->pressed = DebugTable_CheckPad(this, input, L_TRIG, WARP_CATEGORY_MENU, NUM_OF_WARP_CATEGORIES);

    if (this->pressed == 1) {
        switch (this->cursorPos) {
            case WARPS_DUNGEONS:
                this->menuDepth = 2;
                this->activeMenu = WARP_DUNGEON_MENU;
                this->actor.update = DebugTable_DungeonListUpdate;
                this->actor.draw = DebugTable_DrawDungeonList;
                break;
            case WARPS_BOSSES:
                this->menuDepth = 2;
                this->activeMenu = WARP_BOSSES_MENU;
                this->actor.update = DebugTable_BossesListUpdate;
                this->actor.draw = DebugTable_DrawBossesList;
                break;
            case RETURN:
                this->activeMenu = MAIN_MENU;
                this->actor.update = DebugTable_Update;
                this->actor.draw = DebugTable_Draw;
                break;
        }
        this->cursorPos = 0;
        this->pressed = 0;
        this->actionTimer = 10;
    }
}

void DebugTable_DungeonListUpdate(DebugTable* this, GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input;

    this->pressed = DebugTable_CheckPad(this, input, L_TRIG, WARP_DUNGEON_MENU, NUM_OF_DUNGEONS);

    if (this->pressed == 1) {
        if (this->cursorPos != RETURN) {
            this->submenuActive = 1;
            this->activeSubmenu = this->cursorPos;
        } else {
            this->activeMenu = WARP_CATEGORY_MENU;
            this->actor.update = DebugTable_WarpListUpdate;
            this->actor.draw = DebugTable_DrawWarpList;
        }

        this->cursorPos = 0;
        this->pressed = 0;
        this->actionTimer = 10;
    }
    
}

void DebugTable_DrawDebug(DebugTable* this, GlobalContext* globalCtx) {
    GfxPrint* printer = alloca(sizeof(GfxPrint));
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);
    GfxPrint_SetColor(printer, 255, 255, 255, 255);
    GfxPrint_SetPos(printer, 2, 2);
    GfxPrint_Printf(printer, "DEBUG");
    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}

void DebugTable_DrawWarpList(DebugTable* this, GlobalContext* globalCtx) {
    s32 i;

    GfxPrint* printer = alloca(sizeof(GfxPrint));
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);

    GfxPrint_SetPos(printer, 2, 2);
    if (this->cursorPos == -1) {
        GfxPrint_SetColor(printer, 255, 20, 20, 255);
    } else {
        GfxPrint_SetColor(printer, 255, 255, 255, 255);
    }

    GfxPrint_Printf(printer, "return");

    for (i = 0; i < NUM_OF_WARP_CATEGORIES; i++) {
        GfxPrint_SetPos(printer, this->warpMenu[i].pos.x, this->warpMenu[i].pos.y);

        if (this->cursorPos == i) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255); // Selected
        } else {
            GfxPrint_SetColor(printer, 255, 255, 255, 255);
        }

        GfxPrint_Printf(printer, this->warpMenu[i].name);
    }

    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}

void DebugTable_DrawDungeonList(DebugTable* this, GlobalContext* globalCtx) {
    s32 i;

    GfxPrint* printer = alloca(sizeof(GfxPrint));
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);

    GfxPrint_SetPos(printer, 2, 2);
    if (this->cursorPos == -1) {
        GfxPrint_SetColor(printer, 255, 20, 20, 255);
    } else {
        GfxPrint_SetColor(printer, 255, 255, 255, 255);
    }

    GfxPrint_Printf(printer, "return");

    if (this->submenuActive == 1)
    {
        
        switch (this->activeSubmenu)
        {
            case DUNGEON_DEKU:

        }
    }

    if (this->dungeonMenu != 1) {
        for (i = 0; i < NUM_OF_DUNGEONS; i++) {
            GfxPrint_SetPos(printer, this->dungeonMenu[i].pos.x, this->dungeonMenu[i].pos.y);
            if (this->cursorPos == i) {
                GfxPrint_SetColor(printer, 255, 20, 20, 255);
            } else {
                GfxPrint_SetColor(printer, 255, 255, 255, 255);
            }
            GfxPrint_Printf(printer, this->dungeonMenu[i].name);
        }
    }

    else if (this->dungeonMenu == 1) {
    }
    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}

void DebugTable_BossesListUpdate(DebugTable* this, GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input;

    this->pressed = DebugTable_CheckPad(this, input, L_TRIG, WARP_BOSSES_MENU, NUM_OF_BOSSES);

    if (this->pressed == 1) {
        switch (this->cursorPos) {
            case BOSS_GOMA:
                PLAYER_WARP(0x40F);
                break;
            case BOSS_DODONGO:
                PLAYER_WARP(0x40B);
                break;
            case BOSS_BARINADE:
                PLAYER_WARP(0x301);
                break;
            case BOSS_PHANTOM_GANON:
                PLAYER_WARP(0xC);
                break;
            case BOSS_VOLVAGIA:
                PLAYER_WARP(0x305);
                break;
            case BOSS_MORPHA:
                PLAYER_WARP(0x417);
                break;
            case BOSS_BONGO:
                PLAYER_WARP(0x413);
                break;
            case BOSS_TWINROVA:
                PLAYER_WARP(0x5EC);
                break;
            case BOSS_GANONDORF:
                PLAYER_WARP(0x41F);
                break;
            case BOSS_GANON:
                PLAYER_WARP(0x517);
                break;
            default:
                break;
        }

        this->pressed = 0;
        this->actionTimer = 10;
    }
}

void DebugTable_DrawBossesList(DebugTable* this, GlobalContext* globalCtx) {
    s32 i;

    GfxPrint* printer = alloca(sizeof(GfxPrint));
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    GfxPrint_Init(printer);
    GfxPrint_Open(printer, gfxCtx->polyOpa.p);

    GfxPrint_SetPos(printer, 2, 2);
    if (this->cursorPos == -1) {
        GfxPrint_SetColor(printer, 255, 20, 20, 255);
    } else {
        GfxPrint_SetColor(printer, 255, 255, 255, 255);
    }

    GfxPrint_Printf(printer, "return");

    for (i = 0; i < NUM_OF_BOSSES; i++) {
        GfxPrint_SetPos(printer, this->bossMenu[i].pos.x, this->bossMenu[i].pos.y);
        if (this->cursorPos == i) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 255, 255, 255, 255);
        }
        GfxPrint_Printf(printer, this->bossMenu[i].name);
    }
    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}
s32 DebugTable_CheckPad(DebugTable* this, Input* input, u8 button, u8 activeMenu, u8 numOf) {

    s16 timer;

    if ((CHECK_PAD(input->press, D_JPAD) && (this->cursorPos < numOf))) {
        this->cursorPos++;
    }

    if (CHECK_PAD(input->press, U_JPAD) && (this->cursorPos > RETURN)) {
        this->cursorPos--;
    }

    if (this->actionTimer > 0) {
        this->actionTimer--;
    }

    return (CHECK_PAD(input->press, button)) && (this->activeMenu == activeMenu) &&
           !(CHECK_PAD(input->cur, R_TRIG) && (this->actionTimer == 0));
}
