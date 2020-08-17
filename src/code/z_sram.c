#include <ultra64.h>
#include <global.h>
#include "z_sram.h"
#include <vt.h>

u16 sramSaveAddress[] = {
    0x0020, 0x1470, 0x28C0, 0x3D10, 0x5160, 0x65B0,
};

u8 D_8012A4EC[] = {
    0x00, 0x00, 0x00, 0x98, 0x09, 0x10, 0x21, 'Z', 'E', 'L', 'D', 'A',
};

PrivateF D_8012A4F8 = {
    0,
    0,
    0,
    0,
    0,
    0,
    0x0000,
    SSS,
    SSS,
    SSS,
    SSS,
    SSS,
    SSS,
    SSS,
    SSS,
    0,
    0x0030,
    0x0030,
    0,
    0x0030,
    0x0000,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    { ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, 0x0000 },
    { ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, 0x0000 },

    { 0.0f, 0.0f, 0.0f },
    0,
    0,
    0,
    0,
    SCENE_LINK_HOME,
};

ItemEquips D_8012A544 = {
    ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_NONE, 0x1100,
};

Table_t D_8012A550 = {
    /*-------------------- table --------------------*/
    /*---------- ＩＴＥＭ ----------*/
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, /* item_register[6*4] */

    0, 0, 0, 0, 0, 0, /* item_count[16] */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

    /*---------- ＥＱＵＩＰＭＥＮＴ ----------*/
    0x1100, /* equip_register */

    0x00000000, /* non_equip_register */

    /*---------- ＣＯＬＬＥＣＴ ----------*/
    0x00000000, /* collect_register */

    /*---------- ＭＡＰ ----------*/
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* key_compass_map[20] */

    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, /* key_register[20] */
};

Save_t D_8012A5B0 = { 0x0000 };

PrivateF D_8012A5B4 = {
    'Z',
    'E',
    'L',
    'D',
    'A',
    'Z',    /* newf[6] */
    0x0000, /* savect */
    AAL,
    AAI,
    AAN,
    AAK,
    SSS,
    SSS,
    SSS,
    SSS, /* player_name[8] */
    0,   /* f_64dd */
    224,
    224, /* max_life, now_life */
    0,
    48,                       /* magic_max, magic_now */
    150,                      /* lupy_count */
    8,                        /* long_sword_hp */
    0,                        /* navi_timer */
    1,                        /* magic_mode */
    0,                        /* sword_ability */
    0,                        /* magic_ability */
    0,                        /* life_ability */
    0,                        /* last_sword */
    0,                        /* ocarina_round */
    { 0xff, 0xff, 0xff, 0xff, /* child_register_item[4] */
      0xff, 0xff, 0xff,       /* child_register_item_pt[3] */
      0x0000 },               /* child_equip_item */
    { 0xff, 0xff, 0xff, 0xff, /* adult_register_item[4] */
      0xff, 0xff, 0xff,       /* adult_register_item_pt[3] */
      0x0000 },               /* adult_equip_item */

    { 0.0f, 0.0f, 0.0f }, /* position */
    0,                    /* angle_y */
    0,                    /* scene */
    0,                    /* room_ID */
    0,                    /* flag */
    SCENE_SPOT00,         /* scene_data_ID */
};

ItemEquips D_8012A600 = {
    ITEM_SWORD_MASTER, ITEM_BOW, ITEM_BOMB, ITEM_OCARINA_FAIRY, ITEM_BOW, ITEM_BOMB, ITEM_OCARINA_FAIRY, 0x1122,
};

Table_t D_8012A60C = {
    ITEM_STICK, ITEM_NUT, ITEM_BOMB, ITEM_BOW, ITEM_ARROW_FIRE, ITEM_DINS_FIRE, ITEM_SLINGSHOT, ITEM_OCARINA_FAIRY,
    ITEM_BOMBCHU, ITEM_HOOKSHOT, ITEM_ARROW_ICE, ITEM_FARORES_WIND, ITEM_BOOMERANG, ITEM_LENS, ITEM_BEAN, ITEM_HAMMER,
    ITEM_ARROW_LIGHT, ITEM_NAYRUS_LOVE, ITEM_BOTTLE, ITEM_POTION_RED, ITEM_POTION_GREEN, ITEM_POTION_BLUE,
    ITEM_POCKET_EGG, ITEM_WEIRD_EGG,

    50, 50, 10, 30, 1, 1, 30, 1, 50, 1, 1, 1, 1, 1, 1, 1,

    /*---------- ＥＱＵＩＰＭＥＮＴ ----------*/
    0x7777, /* equip_register */

    0x00125249, /* non_equip_register */

    /*---------- ＣＯＬＬＥＣＴ ----------*/
    0x01e3ffff, /* collect_register */

    /*---------- ＭＡＰ ----------*/
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* key_compass_map[20] */

    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, /* key_register[20] */

};

Save_t D_8012A66C = {
    0x0000,
};

s16 D_8012A670[] = {
    YDAN_0,       DDAN_0,        BDAN_0,  MORI1_0, HIDAN_0,     MIZUSIN_0,   JYASINZOU_0,    HAKADAN_0,
    HAKADAN_CH_0, ICE_DOUKUTU_0, GANON_0, MEN_0,   GERUDOWAY_0, GANONTIKA_0, GANON_SONOGO_0, GANONTIKA_SONOGO_0,
};

// save_initialize
void Save_Initialize(void) {
    bzero(&gSaveContext.memory, sizeof(gSaveContext.memory));

    gSaveContext.totalDay = 0;
    gSaveContext.eventDay = 0;

    S_Private = D_8012A4F8; // zelda_save_privateF
    S_Equips = D_8012A544;  // zelda_save_Used
    S_Table = D_8012A550;   // zelda_save_Table
    S_Save = D_8012A5B0;    // zelda_save_Save

    HORSE_SCENE = SCENE_SPOT00;
    HORSE_POS.x = -1840;
    HORSE_POS.y = 72;
    HORSE_POS.z = 5497;
    HORSE_ANGLE = -27353;

    MAGIC_LEVEL = 0;
    HOLD_SWORD = 1;

    ROOM_INF[SCENE_MIZUSIN].swch = 0x40000000;
}

void Save_Initialize999(void) {
    bzero(&gSaveContext.memory, sizeof(gSaveContext.memory));

    gSaveContext.totalDay = 0;
    gSaveContext.eventDay = 0;

    S_Private = D_8012A5B4; // "zelda_save_privatef999"
    S_Equips = D_8012A600;  // "zelda_save_equips999"
    S_Table = D_8012A60C;   // "zelda_save_Table999"
    S_Save = D_8012A66C;    // "zelda_save_Save999"

    HORSE_SCENE = SCENE_SPOT00;
    HORSE_POS.x = -1840;
    HORSE_POS.y = 72;
    HORSE_POS.z = 5497;
    HORSE_ANGLE = -27353;

    SET_INF_TABLE(0, 0x5009);      // Introducing Saria
    SET_EVENT_CHK_INF(0, 0x123F);  /* Opening demo of Deku Tree */
    SET_EVENT_CHK_INF(8, 0x0001);  /* Ocarina Throwing Demo */
    SET_EVENT_CHK_INF(12, 0x0010); /* Seek -> Zelda Reveals demo */

    if (LINK_AGE_IS_CHILD) {
        REGISTER_ITEM(0) = ITEM_SWORD_KOKIRI;
        Inventory_ChangeEquipment(EQUIP_SWORD, 1);
        if (gSaveContext.fileNum == 0xFF) {
            REGISTER_ITEM(1) = ITEM_SLINGSHOT;
            REGISTER_ITEM_PT(0) = 6;
            Inventory_ChangeEquipment(EQUIP_SHIELD, 1);
        }
    }

    ZCommon_SceneNoSet(SPOT00_0); /* リンクＳＴＡＲＴ場所【ＬＩＮＫ─ＨＯＭＥ】 */
    MAGIC_LEVEL = 0;
    ROOM_INF[SCENE_MIZUSIN].swch = 0x40000000;
}

void Sram_LoadCheck(Sram* sram) {
    u16 i, j, m, mmm;
    u16* k;
    u8* nnn;

    osSyncPrintf("個人Ｆｉｌｅ作成\n"); // "Personal file creation"
    i = sramSaveAddress[gSaveContext.fileNum];
    osSyncPrintf("ぽいんと＝%x(%d)\n", i, gSaveContext.fileNum); // "Point = %x(%d)\n"
    MemCopy(&gSaveContext.entranceIndex, sram->read_buff + i, SAVE_MAX);
    osSyncPrintf(VT_FGCOL(YELLOW));
    osSyncPrintf("SCENE_DATA_ID = %d   SceneNo = %d\n", SCENE_DATA_ID, ZCommon_SceneNoGet());

    switch (SCENE_DATA_ID) {
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
        case SCENE_GANON:
        case SCENE_MEN:
        case SCENE_GERUDOWAY:
        case SCENE_GANONTIKA:
            ZCommon_SceneNoSet(D_8012A670[SCENE_DATA_ID]);
            break;
        case SCENE_YDAN_BOSS:
            ZCommon_SceneNoSet(YDAN_0);
            break;
        case SCENE_DDAN_BOSS:
            ZCommon_SceneNoSet(DDAN_0);
            break;
        case SCENE_BDAN_BOSS:
            ZCommon_SceneNoSet(BDAN_0);
            break;
        case SCENE_MORIBOSSROOM:
            ZCommon_SceneNoSet(MORI1_0);
            break;
        case SCENE_FIRE_BS:
            ZCommon_SceneNoSet(HIDAN_0);
            break;
        case SCENE_MIZUSIN_BS:
            ZCommon_SceneNoSet(MIZUSIN_0);
            break;
        case SCENE_JYASINBOSS:
            ZCommon_SceneNoSet(JYASINZOU_0);
            break;
        case SCENE_HAKADAN_BS:
            ZCommon_SceneNoSet(HAKADAN_0);
            break;
        case SCENE_GANON_BOSS:
        case SCENE_GANON_SONOGO:
        case SCENE_GANON_FINAL:
        case SCENE_GANONTIKA_SONOGO:
        case SCENE_GANON_DEMO:
            ZCommon_SceneNoSet(GANON_0);
            break;
        default:
            if (SCENE_DATA_ID != SCENE_LINK_HOME) {
                if (LINK_AGE_IS_CHILD) {
                    ZCommon_SceneNoSet(LINK_HOME_0);
                } else {
                    ZCommon_SceneNoSet(TOKINOMA_7);
                }
            } else {
                ZCommon_SceneNoSet(LINK_HOME_0);
            }
            break;
    }

    osSyncPrintf("scene_no = %d\n", ZCommon_SceneNoGet());
    osSyncPrintf(VT_RST);

    if (S_Private.health < 48) {
        S_Private.health = 48;
    }

    if (OCA_REC_FLAG) {
        osSyncPrintf(VT_FGCOL(BLUE));
        osSyncPrintf("\n====================================================================\n");
        MemCopy(NaOcaRecBufPtr, &S_Information.ocaRecBuff, NA_OCA_REC_MEMORY_SIZE);
        nnn = NaOcaRecBufPtr;
        for (i = 0; i < NA_OCA_REC_MEMORY_SIZE; i++, nnn++) {
            osSyncPrintf("%d, ", *nnn);
        }
        osSyncPrintf("\n====================================================================\n");
        osSyncPrintf(VT_RST);
    }

    if (OCA_REC_FLAG8) {
        osSyncPrintf(VT_FGCOL(GREEN));
        osSyncPrintf("\n====================================================================\n");
        MemCopy(NaOcaRecBuf2Ptr, &S_Information.ocaRecBuff8, NA_OCA_REC_MEMORY_SIZE2);
        nnn = NaOcaRecBuf2Ptr;
        for (i = 0; i < NA_OCA_REC_MEMORY_SIZE2; i++, nnn++) {
            osSyncPrintf("%d, ", *nnn);
        }
        osSyncPrintf("\n====================================================================\n");
        osSyncPrintf(VT_RST);
    }
    // "If you have the letter of Princess Zelda, but you are not playing "Zelda's Lullaby"
    if (GET_EVENT_CHK_INF(4, 0x0001)) {
        if (!GETQUESTITEM_MELODY(ITEM_SONG_LULLABY)) {
            i = EVENT_CHK_INF(4);
            i &= 0xFFFE;
            EVENT_CHK_INF(4) = i;
            INV_CONTENT(ITEM_LETTER_ZELDA) = ITEM_CHICKEN;
            for (j = 1; j < 4; j++) {
                if (REGISTER_ITEM(j) == ITEM_LETTER_ZELDA) {
                    REGISTER_ITEM(j) = ITEM_CHICKEN;
                }
            }
        }
    }

    /* If you are an adult but do not have a "master sword" */
    if (LINK_AGE_IS_ADULT) {
        if (!EQUIP_SWORD_CHK(ITEM_SWORD_MASTER)) {
            SETEQUIP_REGISTER(EQUIP_SWORD, gBitFlags[ITEM_SWORD_MASTER - ITEM_SWORD_KOKIRI]);
            REGISTER_ITEM(0) = ITEM_SWORD_MASTER;
            EQUIP_ITEM &= 0xFFF0;
            EQUIP_ITEM |= 0x0002;
        }
    }

    /* BGS Item Check */
    for (i = 0; i < 3; i++) {
        if (INV_CONTENT(ITEM_POCKET_EGG) == gSpoilingItems[i]) {
            ITEM_REGISTER_SET(gSpoilingItemReverts[i]);
            for (j = 1; j < 4; j++) {
                if (REGISTER_ITEM(j) == gSpoilingItems[i]) {
                    REGISTER_ITEM(j) = gSpoilingItemReverts[i];
                }
            }
        }
    }

    MAGIC_LEVEL = 0;
}

void Sram_Save(Sram* sram) {

    u16 i, j, m;
    u16* k;

    CHECK_SUM = 0;
    k = (u16*)&gSaveContext.entranceIndex;
    for (i = j = m = 0; i < (SAVE_MAX) / 2; i++) {
        if ((++m) == 0x20) {
            m = 0;
        }
        j += *k++;
    }
    CHECK_SUM = j;
    k = (u16*)&gSaveContext.entranceIndex;
    for (i = j = 0; i < (SAVE_MAX) / 2; i++) {
        if ((++m) == 0x20) {
            m = 0;
        }
        j += *k++;
    }

    i = sramSaveAddress[gSaveContext.fileNum];
    ssSRAMWrite((void*)((int)SRAM_START_ADDR + i), &gSaveContext.entranceIndex, SAVE_SIZE);
    k = (u16*)&gSaveContext.entranceIndex;
    for (i = j = 0; i < (SAVE_MAX) / 2; i++) {
        if ((++m) == 0x20) {
            m = 0;
        }
        j += *k++;
    }
    i = sramSaveAddress[gSaveContext.fileNum + 3];
    ssSRAMWrite((void*)((int)SRAM_START_ADDR + i), &gSaveContext.entranceIndex, SAVE_SIZE);
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A8A20.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9258.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A96D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A97F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9A9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9AD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9CD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9D28.s")
