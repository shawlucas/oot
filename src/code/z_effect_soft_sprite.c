#include "global.h"
#include "vt.h"

EffectSsInfo sEffectSsInfo = { 0 }; // "EffectSS2Info"

void EffectSs_InitInfo(GlobalContext* globalCtx, s32 tableSize) {
    u32 i;
    EffectSs* effectSs;
    EffectSsOverlay* overlay;

    for (i = 0; i < ARRAY_COUNT(gEffectSsOverlayTable); i++) {
        overlay = &gEffectSsOverlayTable[i];
        osSyncPrintf("effect index %3d:size=%6dbyte romsize=%6dbyte\n", i,
                     (u32)overlay->vramEnd - (u32)overlay->vramStart, overlay->vromEnd - overlay->vromStart);
    }

    sEffectSsInfo.table =
        GameState_Alloc(&globalCtx->state, tableSize * sizeof(EffectSs), "../z_effect_soft_sprite.c", __LINE__);
    ASSERT(sEffectSsInfo.table != NULL, "sEffectSsInfo.table != NULL", "../z_effect_soft_sprite.c", __LINE__);

    sEffectSsInfo.searchStartIndex = 0;
    sEffectSsInfo.tableSize = tableSize;

    for (effectSs = &sEffectSsInfo.table[0]; effectSs < &sEffectSsInfo.table[sEffectSsInfo.tableSize]; effectSs++) {
        EffectSs_Reset(effectSs);
    }

    overlay = &gEffectSsOverlayTable[0];
    for (i = 0; i < ARRAY_COUNT(gEffectSsOverlayTable); i++) {
        overlay->loadedRamAddr = NULL;
        overlay++;
    }
}

void EffectSs_ClearAll(GlobalContext* globalCtx) {
    u32 i;
    EffectSs* effectSs;
    EffectSsOverlay* overlay;
    void* addr;

    sEffectSsInfo.table = NULL;
    sEffectSsInfo.searchStartIndex = 0;
    sEffectSsInfo.tableSize = 0;

    // This code doesn't actually work, since table was just set to NULL and tableSize to 0
    for (effectSs = &sEffectSsInfo.table[0]; effectSs < &sEffectSsInfo.table[sEffectSsInfo.tableSize]; effectSs++) {
        EffectSs_Delete(effectSs);
    }

    overlay = &gEffectSsOverlayTable[0];
    for (i = 0; i < ARRAY_COUNT(gEffectSsOverlayTable); i++) {
        addr = overlay->loadedRamAddr;

        if (addr != NULL) {
            ZeldaArena_FreeDebug(addr, "../z_effect_soft_sprite.c", __LINE__);
        }

        overlay->loadedRamAddr = NULL;
        overlay++;
    }
}

void EffectSs_Delete(EffectSs* effectSs) {
    if (effectSs->flags & 2) {
        Audio_StopSfxByPos(&effectSs->pos);
    }

    if (effectSs->flags & 4) {
        Audio_StopSfxByPos(&effectSs->vec);
    }

    EffectSs_Reset(effectSs);
}

void EffectSs_Reset(EffectSs* effectSs) {
    u32 i;

    effectSs->type = EFFECT_SS_TYPE_MAX;
    effectSs->accel.x = effectSs->accel.y = effectSs->accel.z = 0;
    effectSs->velocity.x = effectSs->velocity.y = effectSs->velocity.z = 0;
    effectSs->vec.x = effectSs->vec.y = effectSs->vec.z = 0;
    effectSs->pos.x = effectSs->pos.y = effectSs->pos.z = 0;
    effectSs->life = -1;
    effectSs->flags = 0;
    effectSs->priority = 128;
    effectSs->draw = NULL;
    effectSs->update = NULL;
    effectSs->gfx = NULL;
    effectSs->actor = NULL;

    for (i = 0; i < ARRAY_COUNT(effectSs->regs); i++) {
        effectSs->regs[i] = 0;
    }
}

s32 EffectSs_FindSlot(s32 priority, s32* pIndex) {
    s32 foundFree;
    s32 i;

    if (sEffectSsInfo.searchStartIndex >= sEffectSsInfo.tableSize) {
        sEffectSsInfo.searchStartIndex = 0;
    }

    // Search for a free slot
    i = sEffectSsInfo.searchStartIndex;
    foundFree = false;
    while (true) {
        if (sEffectSsInfo.table[i].life == -1) {
            foundFree = true;
            break;
        }

        i++;

        if (i >= sEffectSsInfo.tableSize) {
            i = 0; // Loop around the whole table
        }

        // After a full loop, break out
        if (i == sEffectSsInfo.searchStartIndex) {
            break;
        }
    }

    if (foundFree == true) {
        *pIndex = i;
        return 0;
    }

    // If all slots are in use, search for a slot with a lower priority
    // Note that a lower priority is representend by a higher value
    i = sEffectSsInfo.searchStartIndex;
    while (true) {
        // Equal priority should only be considered "lower" if flag 0 is set
        if ((priority <= sEffectSsInfo.table[i].priority) &&
            !((priority == sEffectSsInfo.table[i].priority) && (sEffectSsInfo.table[i].flags & 1))) {
            break;
        }

        i++;

        if (i >= sEffectSsInfo.tableSize) {
            i = 0; // Loop around the whole table
        }

        // After a full loop, return 1 to indicate that we failed to find a suitable slot
        if (i == sEffectSsInfo.searchStartIndex) {
            return 1;
        }
    }

    *pIndex = i;
    return 0;
}

void EffectSs_Insert(GlobalContext* globalCtx, EffectSs* effectSs) {
    s32 index;

    if (FrameAdvance_IsEnabled(globalCtx) != true) {
        if (EffectSs_FindSlot(effectSs->priority, &index) == 0) {
            sEffectSsInfo.searchStartIndex = index + 1;
            sEffectSsInfo.table[index] = *effectSs;
        }
    }
}

// original name: "EffectSoftSprite2_makeEffect"
void EffectSs_Spawn(GlobalContext* globalCtx, s32 type, s32 priority, void* initParams) {
    s32 index;
    u32 overlaySize;
    EffectSsOverlay* overlayEntry;
    EffectSsInit* initInfo;

    overlayEntry = &gEffectSsOverlayTable[type];

    ASSERT(type < EFFECT_SS_TYPE_MAX, "type < EFFECT_SS_TYPE_MAX", "../z_effect_soft_sprite.c", __LINE__);

    if (EffectSs_FindSlot(priority, &index) != 0) {
        // Abort because we couldn't find a suitable slot to add this effect in
        return;
    }

    sEffectSsInfo.searchStartIndex = index + 1;
    overlaySize = (u32)overlayEntry->vramEnd - (u32)overlayEntry->vramStart;

    if (overlayEntry->vramStart == NULL) {
        // "Not an overlay"
        osSyncPrintf("EffectSs_Spawn():Not an overlay\n");
        initInfo = overlayEntry->initInfo;
    } else {
        if (overlayEntry->loadedRamAddr == NULL) {
            overlayEntry->loadedRamAddr = ZeldaArena_MallocRDebug(overlaySize, "../z_effect_soft_sprite.c", __LINE__);

            if (overlayEntry->loadedRamAddr == NULL) {
                osSyncPrintf(VT_FGCOL(RED));
                // "The memory of %d byte cannot be secured. Therefore, the program cannot be loaded.
                // What a dangerous situation! Naturally, effects will not produced either."
                osSyncPrintf(
                    "EffectSs_Spawn():ZeldaArena_MallocRDebug()\nThe memory of,%"
                    "d byte cannot be secured.\nTherefore, the program cannot be loaded.\nWhat a dangerous situation!"
                    "Naturally, effects will not produced either.\n",
                    overlaySize);
                osSyncPrintf(VT_RST);
                return;
            }

            Overlay_Load(overlayEntry->vromStart, overlayEntry->vromEnd, overlayEntry->vramStart, overlayEntry->vramEnd,
                         overlayEntry->loadedRamAddr);

            osSyncPrintf(VT_FGCOL(GREEN));
            osSyncPrintf("EFFECT SS OVL:SegRom %08X %08X, Seg %08X %08X, RamStart %08X, type: %d\n",
                         overlayEntry->vromStart, overlayEntry->vromEnd, overlayEntry->vramStart, overlayEntry->vramEnd,
                         overlayEntry->loadedRamAddr, type);
            osSyncPrintf(VT_RST);
        }

        initInfo = (void*)(u32)((overlayEntry->initInfo != NULL)
                                    ? (void*)((u32)overlayEntry->initInfo -
                                              (s32)((u32)overlayEntry->vramStart - (u32)overlayEntry->loadedRamAddr))
                                    : NULL);
    }

    if (initInfo->init == NULL) {
        // "Effects have already been loaded, but the constructor is NULL so the addition will not occur.
        // Please fix this. (Waste of memory) %08X %d"
        osSyncPrintf("EffectSs_Spawn():Effects have already been loaded,\nbut the constructor is NULL so the addition "
                     "will not occur.\n"
                     "Please fix this. (Waste of memory) %08X %d\n",
                     initInfo, type);
        return;
    }

    // Delete the previous effect in the slot, in case the slot wasn't free
    EffectSs_Delete(&sEffectSsInfo.table[index]);

    sEffectSsInfo.table[index].type = type;
    sEffectSsInfo.table[index].priority = priority;

    if (initInfo->init(globalCtx, index, &sEffectSsInfo.table[index], initParams) == 0) {
        osSyncPrintf(VT_FGCOL(GREEN));
        // "Construction failed for some reason. The constructor returned an error.
        // Ceasing effect addition."
        osSyncPrintf("EffectSs_Spawn():"
                     "Construction failed for some reason. The constructor returned an error."
                     "Ceasing effect addition.\n");
        osSyncPrintf(VT_RST);
        EffectSs_Reset(&sEffectSsInfo.table[index]);
    }
}

void EffectSs_Update(GlobalContext* globalCtx, s32 index) {
    EffectSs* effectSs = &sEffectSsInfo.table[index];

    if (effectSs->update != NULL) {
        effectSs->velocity.x += effectSs->accel.x;
        effectSs->velocity.y += effectSs->accel.y;
        effectSs->velocity.z += effectSs->accel.z;

        effectSs->pos.x += effectSs->velocity.x;
        effectSs->pos.y += effectSs->velocity.y;
        effectSs->pos.z += effectSs->velocity.z;

        effectSs->update(globalCtx, index, effectSs);
    }
}

void EffectSs_UpdateAll(GlobalContext* globalCtx) {
    s32 i;

    for (i = 0; i < sEffectSsInfo.tableSize; i++) {
        if (sEffectSsInfo.table[i].life > -1) {
            sEffectSsInfo.table[i].life--;

            if (sEffectSsInfo.table[i].life < 0) {
                EffectSs_Delete(&sEffectSsInfo.table[i]);
            }
        }

        if (sEffectSsInfo.table[i].life > -1) {
            EffectSs_Update(globalCtx, i);
        }
    }
}

void EffectSs_Draw(GlobalContext* globalCtx, s32 index) {
    EffectSs* effectSs = &sEffectSsInfo.table[index];

    if (effectSs->draw != NULL) {
        effectSs->draw(globalCtx, index, effectSs);
    }
}

// original name: "EffectSoftSprite2_disp"
void EffectSs_DrawAll(GlobalContext* globalCtx) {
    Lights* lights = LightContext_NewLights(&globalCtx->lightCtx, globalCtx->state.gfxCtx);
    s32 i;

    Lights_BindAll(lights, globalCtx->lightCtx.listHead, NULL);
    Lights_Draw(lights, globalCtx->state.gfxCtx);

    for (i = 0; i < sEffectSsInfo.tableSize; i++) {
        if (sEffectSsInfo.table[i].life > -1) {
            if ((sEffectSsInfo.table[i].pos.x > 32000.0f) || (sEffectSsInfo.table[i].pos.x < -32000.0f) ||
                (sEffectSsInfo.table[i].pos.y > 32000.0f) || (sEffectSsInfo.table[i].pos.y < -32000.0f) ||
                (sEffectSsInfo.table[i].pos.z > 32000.0f) || (sEffectSsInfo.table[i].pos.z < -32000.0f)) {
                osSyncPrintf(VT_FGCOL(RED));
                // "Since the position is outside the area, delete it.
                // Effect label No. %d: Please respond by the program.
                // Here is ==> pos (%f, %f, %f) and the label is in z_effect_soft_sprite_dlftbls.decl."
                osSyncPrintf("EffectSs_DrawAll():Since the position is outside the area, delete it. "
                             "Effect label No. %d: Please respond by the program. Here is ==> "
                             "pos(%f, %f, %f) and the label is in z_effect_soft_sprite_dlftbls.decl.\n",
                             sEffectSsInfo.table[i].type, sEffectSsInfo.table[i].pos.x, sEffectSsInfo.table[i].pos.y,
                             sEffectSsInfo.table[i].pos.z);
                osSyncPrintf(VT_FGCOL(GREEN));
                osSyncPrintf("If you are using pos for something else, consult me.\n");
                osSyncPrintf(VT_RST);

                EffectSs_Delete(&sEffectSsInfo.table[i]);
            } else {
                EffectSs_Draw(globalCtx, i);
            }
        }
    }
}

s16 func_80027DD4(s16 arg0, s16 arg1, s32 arg2) {
    s16 ret = (arg2 == 0) ? arg1 : (arg0 + (s32)((arg1 - arg0) / (f32)arg2));

    return ret;
}

s16 func_80027E34(s16 arg0, s16 arg1, f32 arg2) {
    return (arg1 - arg0) * arg2 + arg0;
}

u8 func_80027E84(u8 arg0, u8 arg1, f32 arg2) {
    return arg2 * ((f32)arg1 - (f32)arg0) + arg0;
}
