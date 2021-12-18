#include "global.h"
#include "vt.h"
#include "textures/parameter_static/parameter_static.h"

typedef struct {
    /* 0x00 */ void* texture;
    /* 0x04 */ u32 imageFormat;
    /* 0x08 */ u32 imageSize;
    /* 0x0C */ u32 textureWidth;
    /* 0x10 */ u32 textureHeight;
    /* 0x14 */ u32 rectWidth;
    /* 0x18 */ u32 rectHeight;
    /* 0x1C */ u32 dsdx;
    /* 0x20 */ u32 dtdy;
} MapMarkInfo; // size = 0x24

typedef struct {
    /* 0x00 */ void* loadedRamAddr; // original name: "allocp"
    /* 0x04 */ u32 vromStart;
    /* 0x08 */ u32 vromEnd;
    /* 0x0C */ void* vramStart;
    /* 0x10 */ void* vramEnd;
    /* 0x14 */ void* vramTable;
} MapMarkDataOverlay; // size = 0x18

static u32 sBaseImageSizes[] = { 0, 1, 2, 3 };
static u32 sLoadBlockImageSizes[] = { 2, 2, 2, 3 };
static u32 sIncrImageSizes[] = { 3, 1, 0, 0 };
static u32 sShiftImageSizes[] = { 2, 1, 0, 0 };
static u32 sBytesImageSizes[] = { 0, 1, 2, 4 };
static u32 sLineBytesImageSizes[] = { 0, 1, 2, 2 };

#define G_IM_SIZ_MARK sBaseImageSizes[markInfo->imageSize]
#define G_IM_SIZ_MARK_LOAD_BLOCK sLoadBlockImageSizes[markInfo->imageSize]
#define G_IM_SIZ_MARK_INCR sIncrImageSizes[markInfo->imageSize]
#define G_IM_SIZ_MARK_SHIFT sShiftImageSizes[markInfo->imageSize]
#define G_IM_SIZ_MARK_BYTES sBytesImageSizes[markInfo->imageSize]
#define G_IM_SIZ_MARK_LINE_BYTES sLineBytesImageSizes[markInfo->imageSize]

static MapMarkInfo sMapMarkInfoTable[] = {
    { gMapChestIconTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 32, 32, 1 << 10, 1 << 10 }, // Chest Icon
    { gMapBossIconTex, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 32, 32, 1 << 10, 1 << 10 },     // Boss Skull Icon
};

static MapMarkDataOverlay sMapMarkDataOvl = {
    NULL,
    (u32)_ovl_map_mark_dataSegmentRomStart,
    (u32)_ovl_map_mark_dataSegmentRomEnd,
    _ovl_map_mark_dataSegmentStart,
    _ovl_map_mark_dataSegmentEnd,
    gMapMarkDataTable,
};

static MapMarkData** sLoadedMarkDataTable;

void MapMark_Init(GlobalContext* globalCtx) {
    MapMarkDataOverlay* overlay = &sMapMarkDataOvl;
    u32 overlaySize = (u32)overlay->vramEnd - (u32)overlay->vramStart;

    overlay->loadedRamAddr = GameState_Alloc(&globalCtx->state, overlaySize, "../z_map_mark.c", __LINE__);
    LogUtils_CheckNullPointer("overlay->loadedRamAddr", overlay->loadedRamAddr, "../z_map_mark.c", __LINE__);

    Overlay_Load(overlay->vromStart, overlay->vromEnd, overlay->vramStart, overlay->vramEnd, overlay->loadedRamAddr);

    sLoadedMarkDataTable = gMapMarkDataTable;
    sLoadedMarkDataTable = (void*)(u32)(
        (overlay->vramTable != NULL)
            ? (void*)((u32)overlay->vramTable - (s32)((u32)overlay->vramStart - (u32)overlay->loadedRamAddr))
            : NULL);
}

void MapMark_ClearPointers(GlobalContext* globalCtx) {
    sMapMarkDataOvl.loadedRamAddr = NULL;
    sLoadedMarkDataTable = NULL;
}

void MapMark_DrawForDungeon(GlobalContext* globalCtx) {
    InterfaceContext* interfaceCtx;
    MapMarkIconData* mapMarkIconData;
    MapMarkPoint* markPoint;
    MapMarkInfo* markInfo;
    u16 dungeon = gSaveContext.mapIndex;
    s32 i;
    s32 rectLeft;
    s32 rectTop;

    interfaceCtx = &globalCtx->interfaceCtx;

    if ((gMapData != NULL) && (globalCtx->interfaceCtx.mapRoomNum >= gMapData->dgnMinimapCount[dungeon])) {
        osSyncPrintf(VT_COL(RED, WHITE) "Room number exceeded, yikes %d/%d  \nMapMarkDraw processing interrupted\n",
                     VT_RST, globalCtx->interfaceCtx.mapRoomNum, gMapData->dgnMinimapCount[dungeon]);
        return;
    }

    mapMarkIconData = &sLoadedMarkDataTable[dungeon][interfaceCtx->mapRoomNum][0];

    OPEN_DISPS(globalCtx->state.gfxCtx, "../z_map_mark.c", __LINE__);

    while (true) {
        if (mapMarkIconData->markType == MAP_MARK_NONE) {
            break;
        }

        gDPPipeSync(OVERLAY_DISP++);
        gDPSetTextureLUT(OVERLAY_DISP++, G_TT_NONE);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 255, 255, 255, interfaceCtx->minimapAlpha);
        gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, interfaceCtx->minimapAlpha);

        markPoint = &mapMarkIconData->points[0];
        for (i = 0; i < mapMarkIconData->count; i++) {
            if ((mapMarkIconData->markType != MAP_MARK_CHEST) || !Flags_GetTreasure(globalCtx, markPoint->chestFlag)) {
                markInfo = &sMapMarkInfoTable[mapMarkIconData->markType];

                gDPPipeSync(OVERLAY_DISP++);
                gDPLoadTextureBlock(OVERLAY_DISP++, markInfo->texture, markInfo->imageFormat, G_IM_SIZ_MARK,
                                    markInfo->textureWidth, markInfo->textureHeight, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                rectLeft = (GREG(94) + markPoint->x + 204) << 2;
                rectTop = (GREG(95) + markPoint->y + 140) << 2;
                gSPTextureRectangle(OVERLAY_DISP++, rectLeft, rectTop, markInfo->rectWidth + rectLeft,
                                    rectTop + markInfo->rectHeight, G_TX_RENDERTILE, 0, 0, markInfo->dsdx,
                                    markInfo->dtdy);
            }
            markPoint++;
        }
        mapMarkIconData++;
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx, "../z_map_mark.c", __LINE__);
}

void MapMark_Draw(GlobalContext* globalCtx) {
    switch (globalCtx->sceneNum) {
        case SCENE_YDAN:
        case SCENE_DDAN:
        case SCENE_BDAN:
        case SCENE_BMORI1:
        case SCENE_HIDAN:
        case SCENE_MIZUSIN:
        case SCENE_JYASINZOU:
        case SCENE_HAKADAN:
        case SCENE_HAKADANCH:
        case SCENE_ICE_DOUKUTO:
        case SCENE_YDAN_BOSS:
        case SCENE_DDAN_BOSS:
        case SCENE_BDAN_BOSS:
        case SCENE_MORIBOSSROOM:
        case SCENE_FIRE_BS:
            MapMark_DrawForDungeon(globalCtx);
            break;
    }
}
