#include "z_debug_table.h"
#include <alloca.h>

#define FLAGS 0x00000030

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

static char* sDungeonList[] = {
    "Deku Tree",    "Dodongo's Cavern", "Jabu Jabu's Belly", "Forest Temple",         "Fire Temple",
    "Water Temple", "Shadow Temple",    "Spirit Temple",     "Inside Ganon's Castle",
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

    this->mainMenu[MENU_DEBUG].pos.x = 2;
    this->mainMenu[MENU_DEBUG].pos.y = 2;
    this->mainMenu[MENU_DEBUG].name = "Debug";

    this->mainMenu[MENU_WARPS].pos.x = 2;
    this->mainMenu[MENU_WARPS].pos.y = 4;
    this->mainMenu[MENU_WARPS].name = "Warps";

    this->warpMenu[WARPS_DUNGEONS].pos.x = 2;
    this->warpMenu[WARPS_DUNGEONS].pos.y = 2;
    this->warpMenu[WARPS_DUNGEONS].name = "Dungeons";

    for (i = 0; i < NUM_OF_DUNGEONS; i++)
    {
        this->dungeonMenu[i].pos.x = 2;
        this->dungeonMenu[i].pos.y = i + 2;
        this->dungeonMenu[i].name = sDungeonList[i];
    }
}

void DebugTable_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    DebugTable* this = THIS;
    Actor_Kill(thisx);
}

void DebugTable_Update(Actor* thisx, GlobalContext* globalCtx) {
    DebugTable* this = THIS;
    Input* input = &globalCtx->state.input;

    if ((CHECK_PAD(input[0].press, D_JPAD) && (this->cursorPos < NUM_OF_ITEMS))) {
        this->cursorPos++;
    }

    if (CHECK_PAD(input[0].press, U_JPAD) && (this->cursorPos > 0)) {
        this->cursorPos--;
    }

    if (CHECK_PAD(globalCtx->state.input[0].press, L_TRIG)) {
        switch (this->cursorPos) {
            case MENU_DEBUG:
                this->cursorPos = 0;
                this->activeMenu = DEBUG_MENU;
                this->actor.draw = DebugTable_DrawDebug;
                break;
            case MENU_WARPS:
                this->cursorPos = 0;
                this->activeMenu = WARP_CATEGORY_MENU;
                this->actor.update = DebugTable_WarpListUpdate;
                this->actor.draw = DebugTable_DrawWarpList;
                break;
        }
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

    if (this->actionTimer != 0) {
        this->actionTimer--;
    }

    if ((CHECK_PAD(input[0].press, D_JPAD) && (this->cursorPos < NUM_OF_WARP_CATEGORIES))) {
        this->cursorPos++;
    }

    if (CHECK_PAD(input[0].press, U_JPAD) && (this->cursorPos > 0)) {
        this->cursorPos--;
    }

    if ((CHECK_PAD(globalCtx->state.input[0].press, L_TRIG)) && (this->activeMenu == WARP_CATEGORY_MENU) &&
        (this->actionTimer == 0)) {
        switch (this->cursorPos) {
            case WARPS_DUNGEONS:
                this->activeMenu = WARP_DUNGEON_MENU;
                this->cursorPos = 0;
                this->actor.update = DebugTable_DungeonListUpdate;
                this->actor.draw = DebugTable_DrawDungeonList;
                break;
        }
    }
}

void DebugTable_DungeonListUpdate(DebugTable* this, GlobalContext* globalCtx) {
    Input* input = &globalCtx->state.input;

    SceneSelectEntry* selectedScene;

    if (this->actionTimer != 0) {
        this->actionTimer--;
    }

    if ((CHECK_PAD(input[0].press, D_JPAD) && (this->cursorPos < NUM_OF_DUNGEONS)))
    {
        this->cursorPos++;
    }

    if (CHECK_PAD(input[0].press, U_JPAD) && (this->cursorPos > 0)) {
        this->cursorPos--;
    }

    if ((CHECK_PAD(globalCtx->state.input[0].press, L_TRIG)) && (this->activeMenu == WARP_DUNGEON_MENU) &&
        (this->actionTimer == 0)) {
        switch (this->cursorPos) {
            case DUNGEON_DEKU:
                globalCtx->nextEntranceIndex = 0x00; // Hyrule Castle from Guard Capture (outside)
                break;
            case DUNGEON_DODONGO:
                globalCtx->nextEntranceIndex = 0x04;
                break;
            case DUNGEON_JABU:
                globalCtx->nextEntranceIndex = 0x28;
                break;
            case DUNGEON_FOREST:
                globalCtx->nextEntranceIndex = 0x169;
                break;
            case DUNGEON_FIRE:
                globalCtx->nextEntranceIndex = 0x165;
                break;
            case DUNGEON_WATER:
                globalCtx->nextEntranceIndex = 0x10;
                break;
            case DUNGEON_SHADOW:
                globalCtx->nextEntranceIndex = 0x37;
                break;
            case DUNGEON_SPIRIT:
                globalCtx->nextEntranceIndex = 0x82;
                break;
            case DUNGEON_GANON:
                globalCtx->nextEntranceIndex = 0x467;
                break;
            default:
                break;  
        }

        globalCtx->sceneLoadFlag = 0x14;
        globalCtx->fadeTransition = 5;
        gSaveContext.nextTransition = 5;
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
    for (i = 0; i < NUM_OF_DUNGEONS; i++) {
        GfxPrint_SetPos(printer, this->dungeonMenu[i].pos.x, this->dungeonMenu[i].pos.y);
        if (this->cursorPos == i) {
            GfxPrint_SetColor(printer, 255, 20, 20, 255);
        } else {
            GfxPrint_SetColor(printer, 255, 255, 255, 255);
        }
        GfxPrint_Printf(printer, this->dungeonMenu[i].name);
    }

    gfxCtx->polyOpa.p = GfxPrint_Close(printer);
    GfxPrint_Destroy(printer);
}
