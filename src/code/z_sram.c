#include <ultra64.h>
#include <global.h>

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
    { ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    0x0000 },
    { ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    ITEM_NONE,
    0x0000 },

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
    48,  /* magic_max, magic_now */
    150, /* lupy_count */
    8,   /* long_sword_hp */
    0,   /* navi_timer */
    1,   /* magic_mode */
    0,   /* sword_ability */
    0,   /* magic_ability */
    0,   /* life_ability */
    0,   /* last_sword */
    0,   /* ocarina_round */
    {0xff,
    0xff,
    0xff,
    0xff, /* child_register_item[4] */
    0xff,
    0xff,
    0xff,   /* child_register_item_pt[3] */
    0x0000 },/* child_equip_item */
    { 0xff,
    0xff,
    0xff,
    0xff, /* adult_register_item[4] */
    0xff,
    0xff,
    0xff,   /* adult_register_item_pt[3] */
    0x0000 }, /* adult_equip_item */

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
    0x0000,
	0x0004,
	0x0028,
	0x0169,
	0x0165,
	0x0010,
	0x0082,
	0x0037,
	0x0098,
	0x0088,
	0x041B,
	0x0008,
	0x0486,
	0x0467,
	0x0179,
	0x056C,
};

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A81A0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A82C8.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A8484.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A88D4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A8A20.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9258.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A96D0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A97F0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9A9C.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9AD0.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9CD4.s")

#pragma GLOBAL_ASM("asm/non_matchings/code/z_sram/func_800A9D28.s")
