#ifndef _AUDIO_GAME_H
#define _AUDIO_GAME_H

/* ******************************************************************
                            ZELDA64 SOUND FILES
                            AUDIO INCLUDERS
                    Created By Yoji Inagaki (NCL, EAD)
                            1998.10.16(FRI)
   ****************************************************************** */

#include <ultra64.h>

extern u8* NaOcaRecBufPtr;
extern u8* NaOcaRecBuf2Ptr;

/* ********************************************
	    SE Handle
   ******************************************** */
#define SEHD_PLAYER	    0
#define SEHD_ITEM	    1
#define SEHD_ENVIRO	    2
#define SEHD_ENEMY	    3
#define SEHD_SYSTEM	    4
#define SEHD_OCARINA	5
#define SEHD_VOICE	    6

#define NA_SEHD_PLAYER	    SEHD_PLAYER
#define NA_SEHD_ITEM	    SEHD_ITEM
#define NA_SEHD_ENVIRO	    SEHD_ENVIRO
#define NA_SEHD_ENEMY	    SEHD_ENEMY
#define NA_SEHD_SYSTEM	    SEHD_SYSTEM
#define NA_SEHD_OCARINA	    SEHD_OCARINA
#define NA_SEHD_VOICE	    SEHD_VOICE

#define NA_SEHD_PLAYER_BIT  0x0001
#define NA_SEHD_ITEM_BIT    0x0002
#define NA_SEHD_ENVIRO_BIT  0x0004
#define NA_SEHD_ENEMY_BIT   0x0008
#define NA_SEHD_SYSTEM_BIT  0x0010
#define NA_SEHD_OCARINA_BIT 0x0020
#define NA_SEHD_VOICE_BIT   0x0040

#define NA_SEHD_NOT_SYSTEM_BIT   0x006f
#define NA_SEHD_FULL_BIT    0x006f


/* ********************************************
	    Groop Track Handle
   ******************************************** */

#define BGM_GROUP_TRACK		0
#define FAN_GROUP_TRACK		1
#define SE_GROUP_TRACK		2
#define EXTRA_GROUP_TRACK	3
#define DEMO_SE_GROUP_TRACK	EXTRA_GROUP_TRACK

/* ********************************************
	    Sound Output Mode Label
   ******************************************** */
#define NA_SOUT_STEREO		0
#define NA_SOUT_MONO		3
#define NA_SOUT_HEADPHONE	1
#define NA_SOUT_3DWIDE		2

/* ********************************************
	    DEMO SPECIAL SEQUENCE SE
   ******************************************** */

#define NA_DEMO_SE_TIMETRIP	    0x00
#define NA_DEMO_SE_SEEK_TRANSFORM   0x01
#define NA_DEMO_SE_RUN_AROUND	    0x02
#define NA_DEMO_SE_FROL_MAGIC	    0x03
#define NA_DEMO_SE_NALE_MAGIC	    0x04
#define NA_DEMO_SE_RING_GATHER	    0x05
#define NA_DEMO_SE_DARK_CLOWD	    0x06
#define NA_DEMO_SE_KNOCK_DOWN	    0x07
#define NA_DEMO_SE_SHADEST_MOVE	    0x08
#define NA_DEMO_SE_SHADEST_APPEAR   0x09
#define NA_DEMO_SE_HIGH_SPEED_CAMERA   0x0a
#define NA_DEMO_SE_ENERGY_LINE_VANISH   0x0b
#define NA_DEMO_SE_BARRIER_BROKEN   0x0c
#define NA_DEMO_SE_TOWER_SINK	    0x0d
#define NA_DEMO_SE_LINK_NIGHTMARE   0x0e
#define NA_DEMO_SE_FUSHADEMO	    0x0f

/* ********************************************
	    NATURAL SOUND INIT FLAG
   ******************************************** */

#define NA_NS_INIT_SPOT00	    0x00
#define NA_NS_INIT_SPOT01	    0x01
#define NA_NS_INIT_SPOT02	    0x02
#define NA_NS_INIT_SPOT03	    0x03
#define NA_NS_INIT_SPOT04	    0x04
#define NA_NS_INIT_SPOT05	    0x05
#define NA_NS_INIT_SPOT06	    0x06
#define NA_NS_INIT_SPOT07	    0x07
#define NA_NS_INIT_SPOT08	    0x08
#define NA_NS_INIT_SPOT09	    0x09
#define NA_NS_INIT_SPOT10	    0x0a
#define NA_NS_INIT_SPOT11	    0x0b
#define NA_NS_INIT_SPOT12	    0x0c
#define NA_NS_INIT_SPOT13	    0x0d
#define NA_NS_INIT_SPOT14	    0x0e
#define NA_NS_INIT_SPOT15	    0x0f
#define NA_NS_INIT_SPOT16	    0x10
#define NA_NS_INIT_SPOT17	    0x11
#define NA_NS_INIT_SPOT18	    0x12
#define NA_NS_INIT_SPOT19	    0x13


#define NA_NS_INIT_FIELD	    0x00
#define NA_NS_INIT_GERUDO	    0x0a
#define NA_NS_INIT_SAND		    0x0b
#define NA_NS_INIT_MOUNTAIN	    0x0c
#define NA_NS_INIT_TOWN		    0x01
#define NA_NS_INIT_GRAVEYARD	    0x02
#define NA_NS_INIT_FOREST	    0x04
#define NA_NS_INIT_RAINHOUSE	    0x05
#define NA_NS_INIT_FISHING_SPOT	    0x06
#define NA_NS_INIT_LAST_GANON	    0x07

#define NA_NS_INIT_DEMO00	    0x02    /* THUNDER & RAIN */
#define NA_NS_INIT_DEMO01	    0x03    /* THUNDER & RAIN & STORM */

/* ********************************************
	    NATURAL SOUND CONTROL FLAG
   ******************************************** */
#define NA_NS_TRIG_THUNDER	    0x0f01
#define NA_NS_TRIG_LIGHTNING	    0x0f00
#define NA_NS_TRIG_RAIN		    0x0e01
#define NA_NS_TRIG_WIND		    0x0c01
#define NA_NS_TRIG_EVENINGBIRD	    0x0101
#define NA_NS_TRIG_NIGHTCREATURE    0x2401
#define NA_NS_TRIG_MORNINGBIRD	    0x5601

#define NA_NS_TRIG_EVENING	    0x0101
#define NA_NS_TRIG_NIGHTE	    0x2401
#define NA_NS_TRIG_NIGHT	    0x2401
#define NA_NS_TRIG_MORNING	    0x5601




#define NA_NS_VARI_WIND		    0x0c02

#define NA_NS_DIST_THUNDER	    0x0f05

#define NA_NS_POWR_RAIN		    0x0e04
#define NA_NS_POWR_WIND		    0x0c04

#define NA_NS_CTRL_START	    0x01
#define NA_NS_CTRL_STOP		    0x00
#define NA_NS_CTRL_TRIGGER	    0x00

#define NA_NS_CTRL_BREAZE	    0x00
#define NA_NS_CTRL_STORM	    0x01
#define NA_NS_CTRL_SANDSTORM	    0x01

#define NA_NS_CTRL_DIST_NEAR	    0x00
#define NA_NS_CTRL_DIST_MIDDLE	    0x24
#define NA_NS_CTRL_DIST_FAR	    0x38


/* ********************************************
	    BGM PATTERN DEFINE 
   ******************************************** */
#define NA_BGM_PTN_NORMAL	    0x00
#define NA_BGM_PTN_FIGHT	    0x01
#define NA_BGM_PTN_REST		    0x02
#define NA_BGM_PTN_FORCE_NORMAL	    0x03

#define NA_ENM_BGM_DIST_MAX	    500.0f
#define NA_ENM_BGM_DIST_MIN	    150.0f
#define NA_ENM_BGM_DIST_WIDTH	    (NA_ENM_BGM_DIST_MAX-NA_ENM_BGM_DIST_MIN)

#define NA_ENM_BGM_MUTE_VOL	    80
#define NA_ENM_BGM_MUTE_VOL1	    60
#define NA_ENM_BGM_MUTE_VOL2	    40
#define NA_ENM_BGM_MUTE_VOL3	    20
#define NA_ENM_BGM_MUTE_VOL4	    5


/* ********************************************
	    BGM FLAG
   ******************************************** */
   
#define NA_BGM_NO_ENTRY		    0xffff
#define NA_BGM_SE_SEQUENCE	    0x0000
#define NA_BGM_NA_SEQUENCE	    0x0001
#define NA_BGM_FIELD		    0x0002
#define NA_BGM_DUNGEON		    0x0018
#define NA_BGM_KAKARIKO_ADULT	    0x0019
#define NA_BGM_BGM00		    0x0002
#define NA_BGM_BGM01		    0x0019
#define NA_BGM_BGM02		    0x001a
#define NA_BGM_BGM03		    0x001a
#define NA_BGM_ENEMY		    0x081a

#define NA_BGM_BOSS00		    0x001b
#define NA_BGM_FAIRY_DUNGEON	    0x001c
#define NA_BGM_MARKET		    0x001d
#define NA_BGM_TITLE		    0x001e
#define NA_BGM_LINK_HOUSE	    0x001f
#define NA_BGM_GAME_OVER	    0x0020
#define NA_BGM_BOSS_CLEAR	    0x0021
#define NA_BGM_ITEM_GET		    0x0922
#define NA_BGM_OPENING_GANON	    0x0023
#define NA_BGM_HEART_GET	    0x0924
#define NA_BGM_OCA_LIGHT	    0x0025
#define NA_BGM_BUYO_DANGEON 	    0x0026
#define NA_BGM_BUYO_DUNGEON 	    0x0026
#define NA_BGM_KAKARIKO_KID 	    0x0027
#define NA_BGM_GODESS 		    0x0028
#define NA_BGM_HIME 		    0x0029
#define NA_BGM_FIRE_DUNGEON	    0x002a
#define NA_BGM_OPEN_TRE_BOX	    0x092b
#define NA_BGM_FORST_DUNGEON	    0x002c
#define NA_BGM_HIRAL_GARDEN	    0x002d

#define NA_BGM_GANON_TOWER	    0x002e
#define NA_BGM_NARRATION_0	    0x002e

#define NA_BGM_RONRON		    0x002f
#define NA_BGM_GORON		    0x0030
#define NA_BGM_SPIRIT_STONE	    0x0032
#define NA_BGM_OCA_FLAME	    0x0033
#define NA_BGM_OCA_WIND		    0x0034
#define NA_BGM_OCA_WATER	    0x0035
#define NA_BGM_OCA_SOUL		    0x0036
#define NA_BGM_OCA_DARKNESS	    0x0037
#define NA_BGM_MIDDLE_BOSS	    0x0038
#define NA_BGM_S_ITEM_GET	    0x0039
#define NA_BGM_SHRINE_OF_TIME	    0x003a
#define NA_BGM_EVENT_CLEAR	    0x003b
#define NA_BGM_KOKIRI		    0x003c
#define NA_BGM_OCA_YOUSEI	    0x003d
#define NA_BGM_MAYOIMORI	    0x003e
#define NA_BGM_SOUL_DUNGEON	    0x003f
#define NA_BGM_HORSE		    0x0040
#define NA_BGM_HORSE_GOAL	    0x0041
#define NA_BGM_INGO		    0x0042
#define NA_BGM_MEDAL_GET	    0x0043

#define NA_BGM_OCA_SARIA	    0x0044
#define NA_BGM_OCA_EPONA	    0x0045
#define NA_BGM_OCA_ZELDA	    0x0046
#define NA_BGM_OCA_SUNMOON	    0x0047
#define NA_BGM_OCA_TIME		    0x0048
#define NA_BGM_OCA_STORM	    0x0049

#define NA_BGM_NAVI		    0x004a
#define NA_BGM_DEKUNOKI		    0x004b
#define NA_BGM_FUSHA		    0x004c
#define NA_BGM_HIRAL_DEMO	    0x004d
#define NA_BGM_MINI_GAME	    0x004e
#define NA_BGM_SEAK		    0x004f
#define NA_BGM_ZORA		    0x0050
#define NA_BGM_APPEAR		    0x0051
#define NA_BGM_ADULT_LINK	    0x0052
#define NA_BGM_MASTER_SWORD	    0x0053
#define NA_BGM_INTRO_GANON	    0x0054
#define NA_BGM_SHOP		    0x0055
#define NA_BGM_KENJA		    0x0056
#define NA_BGM_FILE_SELECT	    0x0057
#define NA_BGM_ICE_DUNGEON	    0x0058
#define NA_BGM_GATE_OPEN	    0x0059
#define NA_BGM_OWL		    0x005a
#define NA_BGM_DARKNESS_DUNGEON	    0x005b
#define NA_BGM_AQUA_DUNGEON	    0x005c
#define NA_BGM_BRIDGE		    0x005d
#define NA_BGM_SARIA		    0x005e
#define NA_BGM_BYEBYE_SARIA	    0x005e
#define NA_BGM_SHEALED_CEREMONY	    0x005e
#define NA_BGM_GERUDO		    0x005f
#define NA_BGM_DRUGSTORE	    0x0060
#define NA_BGM_KOTAKE_KOUME	    0x0061
#define NA_BGM_ESCAPE		    0x0062
#define NA_BGM_UNDERGROUND	    0x0063
#define NA_BGM_GANON_BATTLE_1	    0x0064
#define NA_BGM_GANON_BATTLE_2	    0x0065
#define NA_BGM_END_DEMO		    0x0066
#define NA_BGM_STAFF_1		    0x0067
#define NA_BGM_STAFF_2		    0x0068
#define NA_BGM_STAFF_3		    0x0069
#define NA_BGM_STAFF_4		    0x006a
#define NA_BGM_BOSS01		    0x006b
#define NA_BGM_MINI_GAME_2	    0x006c
#define NA_BGM_DEMO_SE_SEQ	    0x006d

/* ********************************************
	    CHECK PLAYING BGM
   ******************************************** */

#define NA_BGM_CHK_NOW_PLAYING	    1
#define NA_BGM_CHK_NOT_ENTRY	    0


/* ********************************************
	    SOUND SPEC MODE
   ******************************************** */
   
#define NA_MODE_GROUND_SMALL	    0x00
#define NA_MODE_GROUND_MIDDLE	    0x01
#define NA_MODE_GROUND_LARGE	    0x02
#define NA_MODE_DUNGEON_SMALL	    0x03
#define NA_MODE_DUNGEON_LARGE	    0x04
#define NA_MODE_HOUSE_SMALL	    0x05
#define NA_MODE_HOUSE_LARGE	    0x06
#define NA_MODE_FOREST		    0x07
#define NA_MODE_DESERT		    0x08
#define NA_MODE_GROUND_CANYON	    0x09
#define NA_MODE_TITLE		    0x0a
#define NA_MODE_ENDINGDEMO	    0x0b
#define NA_MODE_STAFFROLL	    0x0c

/* ********************************************
	    NARRATION SEQ DEFINE 
   ******************************************** */
#define NA_BGM_NARRATION_MUTE_VOL   64
#define NA_BGM_NARRATION_MUTE_TIME   25
#define NA_NAR_HIRAL		NA_BGM_NARRATION_0

/* ********************************************
	    OCARINA DEFINE
   ******************************************** */
   
#define NA_OCA_NOT_CHECK	    0xff
#define NA_OCA_NOW_CHECK	    0xfe

#define NA_OCA_MELODY_MAX	    14	/* 12 */
#define NA_OCA_REC_BUF_SIZE	108	/* 250 */
#define NA_OCA_REC_BUF_STC	8	/* 6 */
#define NA_OCA_REC_MEMORY_SIZE	(NA_OCA_REC_BUF_SIZE*NA_OCA_REC_BUF_STC)
#define NA_OCA_REC_BUF_SIZE2	16
#define NA_OCA_REC_MEMORY_SIZE2	(NA_OCA_REC_BUF_SIZE2*NA_OCA_REC_BUF_STC)

#define NA_OCA_BTN_A	    0
#define NA_OCA_BTN_CD	    1
#define NA_OCA_BTN_CR	    2
#define NA_OCA_BTN_CL	    3
#define NA_OCA_BTN_CU	    4

#define NA_OCA_CHK_STOP		0xff
#define NA_OCA_CHK_CHECK	0xfe
#define NA_OCA_CHK_MELO_0	0x00
#define NA_OCA_CHK_MELO_1	0x01

#define NA_OCA_CHK_WIND		0x00
#define NA_OCA_CHK_FLAME	0x01
#define NA_OCA_CHK_WATER	0x02
#define NA_OCA_CHK_SOUL		0x03
#define NA_OCA_CHK_DARKNESS	0x04
#define NA_OCA_CHK_LIGHT	0x05
#define NA_OCA_CHK_SPIRIT	0x06
#define NA_OCA_CHK_EPONA	0x07
#define NA_OCA_CHK_ZELDA	0x08
#define NA_OCA_CHK_SUNMOON	0x09
#define NA_OCA_CHK_TIME		0x0a
#define NA_OCA_CHK_STORM	0x0b

#define NA_OCA_CHK_IMPA		0x09
#define NA_OCA_CHK_MYSTERY	0x0b
#define	NA_OCA_CHK_RECMELODY2	0x0c
#define NA_OCA_CHK_GAME		0x0d
#define	NA_OCA_CHK_RECMELODY	NA_OCA_MELODY_MAX

#define NA_OCA_CHK_LEGEND	0x08


#define NA_OCA_CHK_ZELDA_WARP	NA_OCA_CHK_IMPA

#define NA_OCA_CHK_GRP_EVERY	0x3fff
#define NA_OCA_CHK_GRP_ALL2	0x1fff
#define NA_OCA_CHK_GRP_ALL	0x0fff
#define NA_OCA_CHK_GRP_WARP	0x003f
#define NA_OCA_CHK_GRP_GROUND	0x8480
#define NA_OCA_CHK_GRP_ZELDA	0x0040
#define NA_OCA_CHK_MODE_STOP	0xffff

#define NA_OCA_INST_OCARINA	0x01
#define NA_OCA_INST_MALON	0x02
#define NA_OCA_INST_IMPA	0x03
#define NA_OCA_INST_HARP	0x04
#define NA_OCA_INST_WINDMILL	0x05
#define NA_OCA_INST_PICCOLO	0x06

#define NA_OCA_INST_ORGAN	0x05

#define NA_OCA_SEQ_PLAY		0x01
#define NA_OCA_SEQ_STOP		0x00

#define NA_OCA_REC_RUNNING	0x01
#define NA_OCA_REC_STOP		0x00
#define NA_OCA_REC_BAD		0xff

#define NA_OCA_GAME_MAX		0x01
#define NA_OCA_GAME_SHORTAGE	0x00

#define NA_OCA_FROG_NOTES	14


/* ********************************************
	    CHECK FLAG
   ******************************************** */
   
#define NA_FLAG_NO_ENTRY	    0
#define NA_FLAG_NOW_PLAYING	    1


/* ********************************************
	    SE WATER FLAG
   ******************************************** */
   
#define NA_WATER_MODE_ON	0x20
#define NA_WATER_MODE_OFF	0x00


/* ********************************************
	    SE TIMER LEVEL
   ******************************************** */
   
#define NA_TIMER_COUNT_LOW	0
#define NA_TIMER_COUNT_MIDDLE	1
#define NA_TIMER_COUNT_HIGH	2

#define NA_TIMER_TERM_WARNING	40
#define NA_TIMER_TERM_CAUTION	100


/* ********************************************
	    RIVER STREAM SPEED MACRO
   ******************************************** */
#define NA_RIVER_SPEED_SLOW	0.7f
#define NA_RIVER_SPEED_MIDDLE	1.0f
#define NA_RIVER_SPEED_FAST	1.4f

/* ********************************************
	    WATERFALL SPEED MACRO
   ******************************************** */
#define NA_WATERFALL_SPEED_SLOW	    0.5f
#define NA_WATERFALL_SPEED_NORMAL   1.0f


/* ********************************************
	    FROG SOUND
   ******************************************** */
#define NA_FROG_SOUND_A		2
#define NA_FROG_SOUND_CD	5
#define NA_FROG_SOUND_CR	9
#define NA_FROG_SOUND_CL	11
#define NA_FROG_SOUND_CU	14

#define NA_FROG_BIG_SOUND_A	-10
#define NA_FROG_BIG_SOUND_CD	-7
#define NA_FROG_BIG_SOUND_CR	-3
#define NA_FROG_BIG_SOUND_CL	-1
#define NA_FROG_BIG_SOUND_CU	2

/* ********************************************
	    FIVE LUPY SOUND
   ******************************************** */
#define NA_LUPY_COUNT_1		0
#define NA_LUPY_SOUND_2		2
#define NA_LUPY_SOUND_3		4
#define NA_LUPY_SOUND_4		5
#define NA_LUPY_SOUND_5		7

/* ********************************************
	    LEVEL MUTE VOLUME
   ******************************************** */
#define NA_LV_MUTE_VOL		90

#endif