#include <ultra64.h>
#include <global.h>
#include "z_sram.h"
#include <vt.h>

u16 sramSaveAddress[] = {
    0x0020, 0x1470, 0x28C0, 0x3D10, 0x5160, 0x65B0,
};

// sram_check_data
u8 sramCheckData[] = {
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

void Sram_StartLoad(FileChooseContext* this, Sram* sram) {
    u16 i, j, s, t, m, mmm;
    u16* k;
    u16 keepTime;

    osSyncPrintf("ＳＲＡＭ ＳＴＡＲＴ─ＬＯＡＤ\n");

    bzero(sram->read_buff, SRAM_SIZE);
    ssSRAMRead(sram->read_buff, (void*)SRAM_START_ADDR, SRAM_SIZE);

    keepTime = ZCommonGet(zeldaTime);
    for (s = 0; s < 3; s++) {
        t = sramSaveAddress[s];
        osSyncPrintf("ぽいんと＝%x(%d)    SAVE_MAX=%d\n", t, gSaveContext.fileNum, SAVE_MAX);
        MemCopy(&gSaveContext.entranceIndex, sram->read_buff + t, SAVE_MAX);

        mmm = CHECK_SUM;
        CHECK_SUM = 0;
        k = (u16*)&gSaveContext.entranceIndex;
        osSyncPrintf("\n＝＝＝＝＝＝＝＝＝＝＝＝＝  Ｓ（%d） ＝＝＝＝＝＝＝＝＝＝＝＝＝\n", s);
        for (i = j = m = 0; i < (SAVE_MAX) / 2; i++, t += 2) {
            j += *k++;
        }
        osSyncPrintf("\nＳＡＶＥチェックサム計算  j=%x  mmm=%x  ", j, mmm);
        if (j != mmm) {
            osSyncPrintf("ＥＲＲＯＲ！！！ ＝ %x(%d)\n", sramSaveAddress[s], s);
            t = sramSaveAddress[s + 3];
            MemCopy(&gSaveContext.entranceIndex, sram->read_buff + t, SAVE_MAX);

            mmm = CHECK_SUM;
            CHECK_SUM = 0;
            k = (u16*)&gSaveContext.entranceIndex;
            osSyncPrintf("================= ＢＡＣＫ─ＵＰ ========================\n");
            for (i = j = m = 0; i < (SAVE_MAX) / 2; i++, t += 2) {
                j += *k++;
            }
            osSyncPrintf("\n（Ｂ）ＳＡＶＥチェックサム計算  j=%x  mmm=%x  ", j, mmm);
            if (j != mmm) {
                osSyncPrintf("ＥＲＲＯＲ！！！ ＝ %x(%d+3)\n", sramSaveAddress[s + 3], s);

                bzero(&gSaveContext.entranceIndex, sizeof(s32));
                bzero(&gSaveContext.linkAge, sizeof(s32));
                bzero(&gSaveContext.cutsceneIndex, sizeof(s32));
                bzero(&gSaveContext.zeldaTime, sizeof(s32));
                bzero(&gSaveContext.nightFlag, sizeof(s32));
                bzero(&gSaveContext.totalDay, sizeof(s32));
                bzero(&gSaveContext.eventDay, sizeof(s32));
#if !defined(ROM_F)
                if (!s) {
                    Save_Initialize999();
                    S_Private.newf[0] = REG0;
                    S_Private.newf[1] = REG1;
                    S_Private.newf[2] = REG2;
                    S_Private.newf[3] = REG3;
                    S_Private.newf[4] = REG4;
                    S_Private.newf[5] = REG5;
                    osSyncPrintf("newf=%x,%x,%x,%x,%x,%x\n", S_Private.newf[0], S_Private.newf[1], S_Private.newf[2],
                                 S_Private.newf[3], S_Private.newf[4], S_Private.newf[5]);
                } else {
                    Save_Initialize();
                }
#else
                Save_Initialize();
#endif
                k = (u16*)&gSaveContext.entranceIndex;
                /* Checksum calculation */
                osSyncPrintf("\n--------------------------------------------------------------\n");
                for (i = j = m = 0; i < (SAVE_MAX) / 2; i++) {
                    osSyncPrintf("%x ", *k);
                    if ((++m) == 0x20) {
                        osSyncPrintf("\n");
                        m = 0;
                    }

                    j += *k++;
                }

                CHECK_SUM = j;
                osSyncPrintf("\nCheck_Sum=%x(%x)\n", CHECK_SUM, j);
                i = sramSaveAddress[s + 3];
                ssSRAMWrite((void*)((s32)SRAM_START_ADDR + i), &gSaveContext.entranceIndex, SAVE_SIZE);
                osSyncPrintf("??????=%x,%x,%x,%x,%x,%x\n", S_Private.newf[0], S_Private.newf[1], S_Private.newf[2],
                             S_Private.newf[3], S_Private.newf[4], S_Private.newf[5]);
                osSyncPrintf("\nぽいんと＝%x(%d+3)  check_sum=%x(%x)\n", i, s, CHECK_SUM, j);
            }
            i = sramSaveAddress[s];
            ssSRAMWrite((void*)((s32)SRAM_START_ADDR + i), &gSaveContext.entranceIndex, SAVE_SIZE);
            osSyncPrintf("ぽいんと＝%x(%d)  check_sum=%x(%x)\n", i, s, CHECK_SUM, j);
        } else {
            osSyncPrintf("\nＳＡＶＥデータ ＯＫ！！！！\n");
        }
    }

    bzero(sram->read_buff, SRAM_SIZE);
    ssSRAMRead(sram->read_buff, (void*)SRAM_START_ADDR, SRAM_SIZE);
    ZCommonSet(zeldaTime, keepTime);
    osSyncPrintf("SAVECT=%x, NAME=%x, LIFE=%x, ITEM=%x,  64DD=%x,  HEART=%x\n", 0x22, 0x24, 0x2e, 0xa4, 0x2c, 0xcf);

    MemCopy(&this->save[0], sram->read_buff + 0x42, 2);
    MemCopy(&this->save[1], sram->read_buff + 0x1492, 2);
    MemCopy(&this->save[2], sram->read_buff + 0x28E2, 2);

    MemCopy(&this->name[0], sram->read_buff + 0x44, 8);
    MemCopy(&this->name[1], sram->read_buff + 0x1494, 8);
    MemCopy(&this->name[2], sram->read_buff + 0x28E4, 8);

    MemCopy(&this->health[0], sram->read_buff + 0x4E, 2);
    MemCopy(&this->health[1], sram->read_buff + 0x149E, 2);
    MemCopy(&this->health[2], sram->read_buff + 0x28EE, 2);

    MemCopy(&this->item[0], sram->read_buff + 0xC4, 4);
    MemCopy(&this->item[1], sram->read_buff + 0x1514, 4);
    MemCopy(&this->item[2], sram->read_buff + 0x2964, 4);

    MemCopy(&this->f_64dd[0], sram->read_buff + 0x4C, 2);
    MemCopy(&this->f_64dd[1], sram->read_buff + 0x149C, 2);
    MemCopy(&this->f_64dd[2], sram->read_buff + 0x28EC, 2);

    MemCopy(&this->heartStatus[0], sram->read_buff + 0xEF, 1);
    MemCopy(&this->heartStatus[1], sram->read_buff + 0x153F, 1);
    MemCopy(&this->heartStatus[2], sram->read_buff + 0x298F, 1);

#if defined(PAL_VERSION)
    MemCopy(&this->nowLife[0], sram->read_buff + SRAM_Point00 + SAVE_LIFE_NOW, 2);
    MemCopy(&this->nowLife[1], sram->read_buff + SRAM_Point01 + SAVE_LIFE_NOW, 2);
    MemCopy(&this->nowLife[2], sram->read_buff + SRAM_Point02 + SAVE_LIFE_NOW, 2);
#endif

    osSyncPrintf("f_64dd=%d, %d, %d\n", this->f_64dd[0], this->f_64dd[1], this->f_64dd[2]);
    osSyncPrintf("heart_status=%d, %d, %d\n", this->heartStatus[0], this->heartStatus[1], this->heartStatus[2]);

#if defined(PAL_VERSION)
    osSyncPrintf("now_life=%d, %d, %d\n", this->nowLife[0], this->nowLife[1], this->nowLife[2]);
#endif
}
void Sram_StartSave(FileChooseContext* this, Sram* sram) {
    u16 i, j, m;
    u16* k;

#if !defined(ROM_F)
    if (this->no) {
        Save_Initialize();
    } else {
        Save_Initialize999();
    }
#else
    Save_Initialize();
#endif
    /* Link START place [LINK-HOME] */
    ZCommon_SceneNoSet(LINK_HOME_0);
    ZCommon_LinkAgeBeChild();

    /* Zelda time setting [AM 10:00] */
    ZCommonSet(zeldaTime, 0x6AAB);
    ZCommonSet(cutsceneIndex, 0xFFF1);

#if !defined(ROM_F)
    if (!this->no)
        ZCommonSet(cutsceneIndex, 0x0000);
#endif
    for (i = 0; i < 8; i++) {
        PLAYER_NAME[i] = this->name[this->no][i];
    }
    S_Private.newf[0] = REG0;
    S_Private.newf[1] = REG1;
    S_Private.newf[2] = REG2;
    S_Private.newf[3] = REG3;
    S_Private.newf[4] = REG4;
    S_Private.newf[5] = REG5;
    S_Private.n64ddFlag = this->n64ddFlag;
    osSyncPrintf("６４ＤＤフラグ=%d\n", this->n64ddFlag); /* 64DD flag=%d */
    osSyncPrintf("newf=%x,%x,%x,%x,%x,%x\n", S_Private.newf[0], S_Private.newf[1], S_Private.newf[2], S_Private.newf[3],
                 S_Private.newf[4], S_Private.newf[5]);

    osSyncPrintf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    k = (u16*)&gSaveContext.entranceIndex;

    /* Checksum calculation */
    for (i = j = m = 0; i < (SAVE_MAX) / 2; i++) {
        osSyncPrintf("%x ", *k);
        j += *k++;
        if ((++m) == 0x20) {
            osSyncPrintf("\n");
            m = 0;
        }
    }
    CHECK_SUM = j;
    osSyncPrintf("\nチェックサム＝%x\n", CHECK_SUM);

    i = sramSaveAddress[gSaveContext.fileNum];
    osSyncPrintf("I=%x no=%d\n", i, gSaveContext.fileNum);
    MemCopy(sram->read_buff + i, &gSaveContext.entranceIndex, SAVE_MAX);

    i = sramSaveAddress[gSaveContext.fileNum + 3];
    osSyncPrintf("I=%x no=%d\n", i, gSaveContext.fileNum + 3);
    MemCopy(sram->read_buff + i, &gSaveContext.entranceIndex, SAVE_MAX);

    ssSRAMWrite((void*)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
    osSyncPrintf("ＳＡＶＥ終了\n");

    osSyncPrintf("z_common_data.file_no = %d\n", gSaveContext.fileNum);
    osSyncPrintf("SAVECT=%x, NAME=%x, LIFE=%x, ITEM=%x,  SAVE_64DD=%x\n", SAVE_SAVECT, SAVE_NAME, SAVE_LIFE, 0xA4,
                 SAVE_64DD);
    m = sramSaveAddress[gSaveContext.fileNum];
    MemCopy(&this->save[gSaveContext.fileNum], sram->read_buff + m + SAVE_SAVECT, 2);
    MemCopy(&this->name[gSaveContext.fileNum], sram->read_buff + m + SAVE_NAME, 8);
    MemCopy(&this->health[gSaveContext.fileNum], sram->read_buff + m + SAVE_LIFE, 2);
    MemCopy(&this->item[gSaveContext.fileNum], sram->read_buff + m + 0xA4, 4);
    MemCopy(&this->f_64dd[gSaveContext.fileNum], sram->read_buff + m + SAVE_64DD, 2);
    MemCopy(&this->heartStatus[gSaveContext.fileNum], sram->read_buff + m + 0xCF, 1);
#if defined(PAL_VERSION)
    MemCopy(&this->nowLife[gSaveContext.fileNum], sram->read_buff + m + SAVE_LIFE_NOW, 2);
#endif
    osSyncPrintf("f_64dd[%d]=%d\n", gSaveContext.fileNum, this->f_64dd[gSaveContext.fileNum]);
    osSyncPrintf("heart_status[%d]=%d\n", gSaveContext.fileNum, this->heartStatus[gSaveContext.fileNum]);
#if defined(PAL_VERSION)
    osSyncPrintf("now_life[%d]=%d\n", gSaveContext.fileNum, this->nowLife[gSaveContext.fileNum]);
#endif
}

void Sram_StartClear(FileChooseContext* this, Sram* sram) {
    u16 i;

    Save_Initialize();

    i = sramSaveAddress[this->decisionNo];
    MemCopy(sram->read_buff + i, &gSaveContext.entranceIndex, SAVE_MAX);
    ssSRAMWrite((void *)((s32)SRAM_START_ADDR + i), &gSaveContext.entranceIndex, SAVE_SIZE);
    MemCopy(&this->f_64dd[this->decisionNo], sram->read_buff + i + SAVE_64DD, 2);

    i = sramSaveAddress[this->decisionNo + 3];
    MemCopy(sram->read_buff + i, &gSaveContext.entranceIndex, SAVE_MAX);
    ssSRAMWrite((void *)((s32)SRAM_START_ADDR + i), &gSaveContext.entranceIndex, SAVE_SIZE);

    osSyncPrintf("ＣＬＥＡＲ終了\n");
}

void func_800F6700(s8 arg);
void Sram_StartCopy(FileChooseContext* this, Sram *sram )
{
    u16	i;
    
    osSyncPrintf("ＲＥＡＤ=%d(%x)  ＣＯＰＹ=%d(%x)\n",this->decisionNo,sramSaveAddress[this->decisionNo], this->copyNo, sramSaveAddress[this->copyNo]);
    /* ＲＥＡＤ */
    i = sramSaveAddress[this->decisionNo];
    MemCopy(&gSaveContext.entranceIndex, sram->read_buff+i, SAVE_MAX );
    /* ＣＯＰＹ */
    i = sramSaveAddress[this->copyNo];
    MemCopy( sram->read_buff+i, &gSaveContext.entranceIndex, SAVE_MAX );
    i = sramSaveAddress[this->copyNo+3];
    MemCopy( sram->read_buff+i, &gSaveContext.entranceIndex, SAVE_MAX );
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);

    i = sramSaveAddress[this->copyNo];
    MemCopy( &this->save[this->copyNo], sram->read_buff+i + 0x22, 2 );
    MemCopy( &this->name[this->copyNo], sram->read_buff+i + 0x24, 8 );
    MemCopy( &this->health[this->copyNo], sram->read_buff+i+SAVE_LIFE, 2 );
    MemCopy( &this->item[this->copyNo], sram->read_buff+i + 0xA4, 4 );
    MemCopy( &this->f_64dd[this->copyNo], sram->read_buff+i+SAVE_64DD, 2 );
    MemCopy( &this->heartStatus[this->copyNo], sram->read_buff + i + 0xCF, 1);
#if defined(PAL_VERSION)
    MemCopy( &this->nowLife[this->copyNo], sram->read_buff+i+SAVE_LIFE_NOW, 2 );
#endif
    osSyncPrintf("f_64dd[%d]=%d\n", gSaveContext.fileNum,this->f_64dd[gSaveContext.fileNum]);
    osSyncPrintf("heart_status[%d]=%d\n", gSaveContext.fileNum,this->heartStatus[gSaveContext.fileNum]);
    osSyncPrintf("ＣＯＰＹ終了\n");
}


void Sram_SaveSound(Sram* sram) {
    ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, 0x10);
}

void Sram_Initialize(GameState* game, Sram* sram) {
    Input* input = &game->input[2];
    u16 i, j;
    u16* k;

    osSyncPrintf("sram_initialize( Game *game, Sram *sram )\n");

    ssSRAMRead(sram->read_buff, (void *)SRAM_START_ADDR, SRAM_SIZE);
    for (i = 0; i < (sizeof(sramCheckData) / sizeof(u8) - 3); i++) {
        if (sramCheckData[i+3] != sram->read_buff[i+3]) {
            /* Memory Transfer */
            osSyncPrintf("ＳＲＡＭ破壊！！！！！！\n"); /* "SRAM destruction! ! ! ! ! !" */
            J_N = sram->read_buff[2];
            MemCopy(sram->read_buff, &sramCheckData, sizeof(sramCheckData)/sizeof(u8));
            sram->read_buff[2] = J_N;
            Sram_SaveSound(sram);
         }
    }

    S_SOUND = sram->read_buff[0] & 0x3; /* SOUND stereo/monaural/headphones/3D */
    Z_TARGET = sram->read_buff[1] & 0x1;

#if defined(PAL_VERSION)
    J_N = sram->read_buff[2]; /* 0: English / 1: German / 2: French */
    if (J_N > 2) {
        J_N = 0;
        sram->read_buff[2] = J_N;
        Sram_SaveSound(sram);
    }
#endif

#if !defined(ROM_F)
    if (PAD_BUTTON() & R_JPAD) {
        bzero(sram->read_buff, SRAM_SIZE);
        for (i = 0; i < (SAVE_MAX) / 2; i++) {
            sram->read_buff[i] = i;
        }
        ssSRAMWrite((void *)SRAM_START_ADDR, sram->read_buff, SRAM_SIZE);
        osSyncPrintf("ＳＲＡＭ破壊！！！！！！\n");
    }
#endif
    osSyncPrintf("ＧＯＯＤ！ＧＯＯＤ！ サイズ＝%d + %d ＝ %d\n", sizeof(Memory), 4, sizeof(Memory) + sizeof(SAVE_BASE));
    osSyncPrintf(VT_FGCOL(BLUE));
    osSyncPrintf("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
    osSyncPrintf("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
    osSyncPrintf("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
    osSyncPrintf(VT_RST);
    func_800F6700(NA_SOUT_STEREO + S_SOUND); /* Sound output set */
}

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9CD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9D28.s")
