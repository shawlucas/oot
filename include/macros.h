#ifndef _MACROS_H_
#define _MACROS_H_

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define PHYSICAL_TO_VIRTUAL(addr) ((u32)(addr) + 0x80000000)
#define PHYSICAL_TO_VIRTUAL2(addr) ((u32)(addr) - 0x80000000)
#define SEGMENTED_TO_VIRTUAL(addr) (void*)(PHYSICAL_TO_VIRTUAL(gSegments[SEGMENT_NUMBER(addr)]) + SEGMENT_OFFSET(addr))

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

#define concat(a, b) a##b 
#define bitcheck(xx, yy) ((xx) & (yy))
#define bitset(xx, yy) ((xx) |= (yy))
#define bitclr(xx, yy) ((xx) &= ~(yy))

#define SQ(x) ((x)*(x))
#define ABS(x) (((x) >= 0) ? (x) : -(x))
#define	ULTRA_ABS(x) ((x) > 0) ? (x) : -(x)
#define DECR(x) ((x) == 0 ? 0 : ((x) -= 1))
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
#define CLAMP_MAX(x, max) ((x) > (max) ? (max) : (x))
#define CLAMP_MIN(x, min) ((x) < (min) ? (min) : (x))

#define RGBA8(r, g, b, a) (((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | ((a & 0xFF) << 0))

#define PLAYER ((Player*)globalCtx->actorCtx.actorList[ACTORTYPE_PLAYER].first)

#define ACTIVE_CAM globalCtx->cameraPtrs[globalCtx->activeCamera]

#define YEARS_CHILD 5
#define YEARS_ADULT 17
#define LINK_IS_CHILD (gSaveContext.linkAge != 0)
#define LINK_IS_ADULT (gSaveContext.linkAge == 0)
#define LINK_AGE_IN_YEARS (LINK_IS_CHILD ? YEARS_CHILD : YEARS_ADULT)

#define GET_PAD_PATTERN(padmgr) (u8)((padmgr)->validCtrlrsMask)

#define SLOT(item) gItemSlots[item]
#define INV_CONTENT(item) gSaveContext.items[SLOT(item)]
#define AMMO(item) gSaveContext.ammo[SLOT(item)]
#define BEANS_BOUGHT AMMO(ITEM_BEAN + 1)

#define ALL_EQUIP_VALUE(equip) ((s32)(gSaveContext.equipment & gEquipMasks[equip]) >> gEquipShifts[equip])
#define CUR_EQUIP_VALUE(equip) ((s32)(gSaveContext.equips.equipment & gEquipMasks[equip]) >> gEquipShifts[equip])
#define CHECK_OWNED_EQUIP(equip, value) ((gBitFlags[value] << gEquipShifts[equip]) & gSaveContext.equipment)

#define CUR_UPG_VALUE(upg) ((s32)(gSaveContext.upgrades & gUpgradeMasks[upg]) >> gUpgradeShifts[upg])
#define CAPACITY(upg, value) gUpgradeCapacities[upg][value]
#define CUR_CAPACITY(upg) CAPACITY(upg, CUR_UPG_VALUE(upg))

#define CHECK_QUEST_ITEM(item) (gBitFlags[item] & gSaveContext.questItems)    

#ifndef HAYAKAWA_TESTdx
#define SET_NEXT_GAMESTATE(game, func, name) \
if (1) { \
    GameState* _g = game; \
    (_g)->init = func;                          \
    (_g)->size = sizeof(name); \
} else
#define SET_NEXT_GAMESTATE_NULL(game) \
if (1) {  \
    GameState* _g = game; \
    (_g)->init = NULL; \
    (_g)->size = 0; \
} else
#else
#define game_set_next_game_name(game, name) \
    ((game)->next_game_dlf_no = GAME_DLF_##name)
#define game_set_next_game_null(game) \
    ((game)->next_game_dlf_no = -1)
#endif
#define SET_NEXT_GAME_NAME(name) \
    game_set_next_game_name(game, name)
#define SET_NEXT_GAME_NULL() \
    game_set_next_game_null(game)

#define LOG(exp, value, format, file, line)         \
    do {                                            \
        LogUtils_LogThreadId(file, line);           \
        osSyncPrintf(exp " = " format "\n", value); \
    } while (0)

#define LOG_STRING(string, file, line) LOG(#string, string, "%s", file, line)
#define LOG_ADDRESS(exp, value, file, line) LOG(exp, value, "%08x", file, line)
#define LOG_TIME(exp, value, file, line) LOG(exp, value, "%lld", file, line)
#define LOG_NUM(exp, value, file, line) LOG(exp, value, "%d", file, line)
#define LOG_HEX(exp, value, file, line) LOG(exp, value, "%x", file, line)

#define GAME_PLAY (GlobalContext *)state

#define J_N gSaveContext.j_n

/*
 * `x` vertex x
 * `y` vertex y
 * `z` vertex z
 * `s` texture s coordinate
 * `t` texture t coordinate
 * `crnx` red component of color vertex, or x component of normal vertex
 * `cgny` green component of color vertex, or y component of normal vertex
 * `cbnz` blue component of color vertex, or z component of normal vertex
 * `a` alpha
 */
#define VTX(x,y,z,s,t,crnx,cgny,cbnz,a) { { { x, y, z }, 0, { s, t }, { crnx, cgny, cbnz, a } } }

#define VTX_T(x,y,z,s,t,cr,cg,cb,a) { { x, y, z }, 0, { s, t }, { cr, cg, cb, a } }

#define SET_FULLSCREEN_VIEWPORT(view)     \
    {                                      \
        Viewport viewport;                 \
        viewport.bottomY = SCREEN_HEIGHT;  \
        viewport.rightX = SCREEN_WIDTH;    \
        viewport.topY = 0;                 \
        viewport.leftX = 0;                \
        View_SetViewport(view, &viewport); \
    }

#define CHECK_PAD(state, combo) (~(state.in.button | ~(combo)) == 0)

#endif
