#ifndef _MACROS_H_
#define _MACROS_H_

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define PHYSICAL_TO_VIRTUAL(addr) ((u32)(addr) + 0x80000000)
#define PHYSICAL_TO_VIRTUAL2(addr) ((u32)(addr) - 0x80000000)
#define SEGMENTED_TO_VIRTUAL(addr) (void*)(PHYSICAL_TO_VIRTUAL(gSegments[SEGMENT_NUMBER(addr)]) + SEGMENT_OFFSET(addr))

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

#if defined(__STDC__)
    #define assert(EX, FILE, LINE) ((EX) ? ((void)0) : __assert( # EX , FILE, LINE))
#else
    #define assert(EX, FILE, LINE) ((EX) ? ((void)0) : __assert("EX", FILE, LINE))
#endif

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
#define LINK_AGE_IS_CHILD (LINK_AGE_IN_YEARS == YEARS_CHILD)
#define LINK_AGE_IS_ADULT (LINK_AGE_IN_YEARS == YEARS_ADULT)

#define GET_PAD_PATTERN(padmgr) (u8)((padmgr)->validCtrlrsMask)

#define SLOT(item) gItemSlots[item]
#define INV_CONTENT(item) gSaveContext.memory.table.items[SLOT(item)]
#define AMMO(item) gSaveContext.memory.table.ammo[SLOT(item)]
#define BEANS_BOUGHT AMMO(ITEM_BEAN + 1)

#define ALL_EQUIP_VALUE(equip) ((s32)(gSaveContext.memory.table.equipment & gEquipMasks[equip]) >> gEquipShifts[equip])
#define CUR_EQUIP_VALUE(equip) ((s32)(gSaveContext.memory.equips.equipment & gEquipMasks[equip]) >> gEquipShifts[equip])
#define CHECK_OWNED_EQUIP(equip, value) ((gBitFlags[value] << gEquipShifts[equip]) & gSaveContext.memory.table.equipment)
#define SETEQUIP_REGISTER(no, pt) (EQUIP_REGISTER |= (pt << gEquipShifts[no]))
#define ITEM_REGISTER_SET(item) (S_Table.items[SLOT(item)] = item)

#define CUR_UPG_VALUE(upg) ((s32)(gSaveContext.memory.table.upgrades & gUpgradeMasks[upg]) >> gUpgradeShifts[upg])
#define CAPACITY(upg, value) gUpgradeCapacities[upg][value]
#define CUR_CAPACITY(upg) CAPACITY(upg, CUR_UPG_VALUE(upg))

#define CHECK_QUEST_ITEM(item) (gBitFlags[item] & gSaveContext.memory.table.questItems) 

#define EQUIP_SWORD_CHK(itemNo) (S_Table.equipment & ( gBitFlags[itemNo - ITEM_SWORD_KOKIRI] << gEquipShifts[EQUIP_SWORD]))

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

#define CHECK_PAD(state, combo) (~(state.button | ~(combo)) == 0)
#define pad_button(pad) (int)((pad)->cur.button)
#define PAD_BUTTON() pad_button(input)

#define S_Private gSaveContext.memory.privatef
#define S_Information gSaveContext.memory.information
#define S_Equips  gSaveContext.memory.equips
#define S_Table   gSaveContext.memory.table
#define S_Save    gSaveContext.memory.save
#define HORSE_SCENE gSaveContext.memory.horseData.scene
#define HORSE_POS gSaveContext.memory.horseData.pos
#define HORSE_ANGLE gSaveContext.memory.horseData.angle

#define EQUIP_REGISTER S_Table.equipment
#define EVENT_CHK_INF(no) (S_Information.eventChkInf[no])
#define INF_TABLE(no) (S_Information.infTable[no])

#define GET_EVENT_CHK_INF(no, data) (EVENT_CHK_INF(no) & data)
#define GETQUESTITEM_MELODY(no) (S_Table.questItems & gBitFlags[C_SEAL + (no - ITEM_SONG_MINUET)])

#define MAGIC_LEVEL S_Private.magicLevel
#define CURRENT_MAGIC S_Private.magic
#define HOLD_SWORD INF_TABLE(29)
#define ROOM_INF S_Information.sceneFlags

#define SET_INF_TABLE(no, data) (INF_TABLE(no) |= data)
#define SET_EVENT_CHK_INF(no, data) (EVENT_CHK_INF(no) |= data)

#define REGISTER_ITEM(no) S_Equips.buttonItems[no]
#define REGISTER_ITEM_PT(no) S_Equips.cButtonSlots[no]

#define SCENE_DATA_ID S_Private.sceneDataId

#define OCA_REC_FLAG S_Information.ocaRecFlag
#define OCA_REC_FLAG8 S_Information.ocaRecFlag8

#define EQUIP_ITEM S_Equips.equipment

#define ZCommonGet(member) (0, gSaveContext.member)
#define ZCommon_SceneNoGet() ZCommonGet(entranceIndex)
#define ZCommonSet(member, value) (gSaveContext.member = (value))
#define ZCommon_SceneNoSet(no) ZCommonSet(entranceIndex, no)

#define ZCommon_LinkAgeSet(year) ZCommonSet(linkAge, ((year) == 5))
#define ZCommon_LinkAgeBeAdult() ZCommon_LinkAgeSet(YEARS_ADULT)
#define ZCommon_LinkAgeBeChild() ZCommon_LinkAgeSet(YEARS_CHILD)

#define PLAYER_NAME S_Private.playerName

#define S_SOUND gSaveContext.audioSetting
#define Z_TARGET gSaveContext.zTargetingSetting

#endif
