#ifndef __SYS_SEGMENT_H_
#define __SYS_SEGMENT_H_

#define xSetSegment(segtbl, number, base) \
        ((void)((segtbl)[number] = (u32)(base)))
#define SetSegment(number, base) \
        xSetSegment(gSegments, number, base)

#define xSetSegmentK0(segtbl, number, base) \
        xSetSegment(segtbl, number, OS_K0_TO_PHYSICAL(base))
#define SetSegmentK0(number, base) \
        SetSegment(number, OS_K0_TO_PHYSICAL(base))

#define xGetSegment(segtbl, number) \
        ((u32)((segtbl)[number]))
#define GetSegment(number) \
        xGetSegment(gSegments, number)

#define xGetSegment(segtbl, number) \
        ((u32)((segtbl)[number]))
#define GetSegment(number) \
        xGetSegment(gSegments, number)

/*
 *	スタック サイズ
 */
#define	BOOT_STACK_SIZE		1024
#define	DISK_BOOT_STACK_SIZE	1024

/*
 *	各 セグメント の 番号
 */
#define PHYSICAL_SEGMENT		0
#define STATIC_SEGMENT			1
#define AUDIO_SEGMENT 			STATIC_SEGMENT /* 別に何番でもいい */
#define DYNAMIC_SEGMENT			2

/*
 * ------------	ゲーム用 ---------------
 */
#define SOFTSPRITE_MATRIX_SEGMENT		1

#define GAMEPLAY_SCENE_SEGMENT			2
#define GAMEPLAY_ROOM_SEGMENT			3
#define GAMEPLAY_KEEP_SEGMENT			4
#define GAMEPLAY_EXCHANGE_KEEP_SEGMENT		5

#define GAMEPLAY_OBJECT_EXCHANGE_SEGMENT	6

/*
 * 汎用
 */
/*- 	ただのダミーセグメント	-*/
#define GAMEPLAY_ELF_MESSAGE_SEGMENT		7

/*----------------------------------------------*/
#define	READ_ROM_DATA_SEGMENT		7

/*----------------------------------------------*/
/* ＶＲ＿ＢＯＸ */
#define VR_BOX0_SEGMENT			7
#define VR_BOX1_SEGMENT			8
#define VR_BOX_TLUT_SEGMENT		9

/*----------------------------------------------*/
/* メッセージ吹き出し */
#define MESSAGE0_SEGMENT		7
#define MESSAGE1_SEGMENT		8
#define MESSAGE2_SEGMENT		9

/*----------------------------------------------*/
#define KANROM_SEGMENT          	10

/*----------------------------------------------*/
/* パラメーター */
#define PARAMETER0_SEGMENT		7
#define MAP_SEGMENT			11

/*----------------------------------------------*/
/* カレイド・スコープ */
#define ICON_ITEM_SEGMENT		8
#define ICON_ITEM_24_SEGMENT		9
#define ITEM_NAME_SEGMENT		10
#define ICON_ITEM_MAP_SEGMENT		12
#define ICON_ITEM_JPN_NES_SEGMENT	13


/*----------------------------------------------*/
/* 太陽と月 */
#define	SUN_MOON_SEGMENT		7

/*----------------------------------------------*/
#define HILITE_SEGMENT			7

#define BUMP_TEXTURE_SEGMENT		8

#define ANIME_TEXTURE_1_SEGMENT		8
#define ANIME_TEXTURE_2_SEGMENT		9
#define ANIME_TEXTURE_3_SEGMENT		10
#define ANIME_TEXTURE_4_SEGMENT		11
#define ANIME_TEXTURE_5_SEGMENT		12
#define ANIME_TEXTURE_6_SEGMENT		13

#define ANIME_MODEL_1_SEGMENT		8
#define ANIME_MODEL_2_SEGMENT		9
#define ANIME_MODEL_3_SEGMENT		10
#define ANIME_MODEL_4_SEGMENT		11
#define ANIME_MODEL_5_SEGMENT		12
#define ANIME_MODEL_6_SEGMENT		13

#define ZB_SEGMENT			14
#define CFB_SEGMENT			15

#define DISKSEGMENT_START 0x80600000

#endif /* __SYS_SEGMENT_H_ */
