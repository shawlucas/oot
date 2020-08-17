#ifndef _Z64SCENE_H_
#define _Z64SCENE_H_

typedef struct {
    /* 0x00 */ u32 vromStart;
    /* 0x04 */ u32 vromEnd;
} RomFile; // size = 0x8

typedef struct {
    /* 0x00 */ RomFile sceneFile;
    /* 0x08 */ RomFile titleFile;
    /* 0x10 */ u8  unk_10;
    /* 0x11 */ u8  config;
    /* 0x12 */ u8  unk_12;
    /* 0x13 */ u8  unk_13;
} Scene; // size = 0x14

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 data2;
} SCmdBase;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdSpawnList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ u32 segment;
} SCmdActorList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdCsCameraList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdColHeader;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ u32 segment;
} SCmdRoomList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ s8  unk_04;
    /* 0x05 */ s8  unk_05;
    /* 0x06 */ s8  unk_06;
    /* 0x07 */ u8  unk_07;
} SCmdWindSettings;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdEntranceList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  cUpElfMsgNum;
    /* 0x04 */ u32 keepObjectId;
} SCmdSpecialFiles;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  gpFlag1;
    /* 0x04 */ u32 gpFlag2;
} SCmdRoomBehavior;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdMesh;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ u32 segment;
} SCmdObjectList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ u32 segment;
} SCmdLightList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdPathList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ u32 segment;
} SCmdTransiActorList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  num;
    /* 0x04 */ u32 segment;
} SCmdLightSettingList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  hour;
    /* 0x05 */ u8  min;
    /* 0x06 */ u8  unk_06;
} SCmdTimeSettings;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  skyboxId;
    /* 0x05 */ u8  unk_05;
    /* 0x06 */ u8  unk_06;
} SCmdSkyboxSettings;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[2];
    /* 0x04 */ u8  unk_04;
    /* 0x05 */ u8  unk_05;
} SCmdSkyboxDisables;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 data2;
} SCmdEndMarker;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdExitList;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  bgmId;
    /* 0x02 */ char pad[4];
    /* 0x06 */ u8  nightSeqIndex;
    /* 0x07 */ u8  seqIndex;
} SCmdSoundSettings;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x02 */ char pad[5];
    /* 0x07 */ u8  echo;
} SCmdEchoSettings;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdCutsceneData;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  data1;
    /* 0x04 */ u32 segment;
} SCmdAltHeaders;

typedef struct {
    /* 0x00 */ u8  code;
    /* 0x01 */ u8  cameraMovement;
    /* 0x04 */ u32 area;
} SCmdMiscSettings;

typedef struct {
    u8 headerType;
} MeshHeaderBase;

typedef struct {
    MeshHeaderBase base;

    u8 numEntries;
    u32 dListStart;
    u32 dListEnd;
} MeshHeader0;

typedef struct {
    u32 opaqueDList;
    u32 translucentDList;
} MeshEntry0;

typedef struct {
    MeshHeaderBase base;
    u8 format;
    u32 entryRecord;
} MeshHeader1Base;

typedef struct {
    MeshHeader1Base base;
    u32 imagePtr; // 0x08
    u32 unknown; // 0x0C
    u32 unknown2; // 0x10
    u16 bgWidth; // 0x14
    u16 bgHeight; // 0x16
    u8 imageFormat; // 0x18
    u8 imageSize; // 0x19
    u16 imagePal; // 0x1A
    u16 imageFlip; // 0x1C
} MeshHeader1Single;

typedef struct {
    MeshHeader1Base base;
    u8 bgCnt;
    u32 bgRecordPtr;
} MeshHeader1Multi;

typedef struct {
    u16 unknown; // 0x00
    s8 bgID; // 0x02
    u32 imagePtr; // 0x04
    u32 unknown2; // 0x08
    u32 unknown3; // 0x0C
    u16 bgWidth; // 0x10
    u16 bgHeight; // 0x12
    u8 imageFmt; // 0x14
    u8 imageSize; // 0x15
    u16 imagePal; // 0x16
    u16 imageFlip; // 0x18
} BackgroundRecord;

typedef struct {
    s16 playerXMax, playerZMax;
    s16 playerXMin, playerZMin;
    u32 opaqueDList;
    u32 translucentDList;
} MeshEntry2;

typedef struct {
    MeshHeaderBase base;
    u8 numEntries;
    u32 dListStart;
    u32 dListEnd;
} MeshHeader2;


typedef struct {
    u8 ambientClrR, ambientClrG, ambientClrB;
    u8 diffuseClrA_R, diffuseClrA_G, diffuseClrA_B;
    u8 diffuseDirA_X, diffuseDirA_Y, diffuseDirA_Z;
    u8 diffuseClrB_R, diffuseClrB_G, diffuseClrB_B;
    u8 diffuseDirB_X, diffuseDirB_Y, diffuseDirB_Z;
    u8 fogClrR, fogClrG, fogClrB;
    u16 unk;
    u16 drawDistance;
} LightSettings;

typedef struct {
    s16 absMinX, absMinY, absMinZ;
    s16 absMaxX, absMaxY, absMaxZ;
    s16 numVerts;
    s32 vtxSegmentOffset;
    s16 numPolygons;
    s32 polySegmentOffset;
    s32 polyTypeDefSegmentOffset;
    s32 camDataSegmentOffset;
    s16 numWaterBoxes;
    s32 waterBoxSegmentOffset;
} ColHeader;

typedef struct {
    s16 cameraSType;            // 0x00
    s16 numCameras;             // 0x02
    s32 camPosDataSeg;  // 0x04
} CamData;

typedef struct {
    u32 unknown;
    u32 camPosDataSeg;
} CamPosDataEntry;


/*
typedef union {
    _CamData data;
    long long int forceStructAlignment;
} CamData;
*/

typedef struct {
    s16 posX, posY, posZ;
    s16 rotX, rotY, rotZ;
    s16 fov;
    s16 jfifId;
    s16 unk;
} CamPosData;

/*
typedef union {
    _CamPosData data;
    long long int forceStructAlignment;
} CamPosData;
*/

typedef struct {
    s16 type;
    s16 vtxA, vtxB, vtxC;
    s16 a, b, c, d;
} RoomPoly;

typedef struct {
    s16 xMin;
    s16 ySurface;
    s16 zMin;
    s16 xLength;
    s16 zLength;
    s32 properties;
} WaterBoxHeader;

typedef struct {
    /* 0x00 */ u8 count; // number of points in the path
    /* 0x04 */ Vec3s* points; // Segment Address to the array of points
} Path; // size = 0x8

typedef union {
    SCmdBase              base;
    SCmdSpawnList         spawnList;
    SCmdActorList         actorList;
    SCmdCsCameraList      csCameraList;
    SCmdRoomList          roomList;
    SCmdEntranceList      entranceList;
    SCmdObjectList        objectList;
    SCmdLightList         lightList;
    SCmdPathList          pathList;
    SCmdTransiActorList   transiActorList;
    SCmdLightSettingList  lightSettingList;
    SCmdExitList          exitList;
    SCmdColHeader         colHeader;
    SCmdMesh              mesh;
    SCmdSpecialFiles      specialFiles;
    SCmdCutsceneData      cutsceneData;
    SCmdRoomBehavior      roomBehavior;
    SCmdWindSettings      windSettings;
    SCmdTimeSettings      timeSettings;
    SCmdSkyboxSettings    skyboxSettings;
    SCmdSkyboxDisables    skyboxDisables;
    SCmdEndMarker         endMarker;
    SCmdSoundSettings     soundSettings;
    SCmdEchoSettings      echoSettings;
    SCmdMiscSettings      miscSettings;
    SCmdAltHeaders        altHeaders;
} SceneCmd; // size = 0x8

typedef enum {
    /* 0x00 */ SCENE_YDAN,
    /* 0x01 */ SCENE_DDAN,
    /* 0x02 */ SCENE_BDAN,
    /* 0x03 */ SCENE_BMORI1,
    /* 0x04 */ SCENE_HIDAN,
    /* 0x05 */ SCENE_MIZUSIN,
    /* 0x06 */ SCENE_JYASINZOU,
    /* 0x07 */ SCENE_HAKADAN,
    /* 0x08 */ SCENE_HAKADANCH,
    /* 0x09 */ SCENE_ICE_DOUKUTO,
    /* 0x0A */ SCENE_GANON,
    /* 0x0B */ SCENE_MEN,
    /* 0x0C */ SCENE_GERUDOWAY,
    /* 0x0D */ SCENE_GANONTIKA,
    /* 0x0E */ SCENE_GANON_SONOGO,
    /* 0x0F */ SCENE_GANONTIKA_SONOGO,
    /* 0x10 */ SCENE_TAKARAYA,
    /* 0x11 */ SCENE_YDAN_BOSS,
    /* 0x12 */ SCENE_DDAN_BOSS,
    /* 0x13 */ SCENE_BDAN_BOSS,
    /* 0x14 */ SCENE_MORIBOSSROOM,
    /* 0x15 */ SCENE_FIRE_BS,
    /* 0x16 */ SCENE_MIZUSIN_BS,
    /* 0x17 */ SCENE_JYASINBOSS,
    /* 0x18 */ SCENE_HAKADAN_BS,
    /* 0x19 */ SCENE_GANON_BOSS,
    /* 0x1A */ SCENE_GANON_FINAL,
    /* 0x1B */ SCENE_ENTRA,
    /* 0x1C */ SCENE_ENTRA_N,
    /* 0x1D */ SCENE_ENRUI,
    /* 0x1E */ SCENE_MARKET_ALLEY,
    /* 0x1F */ SCENE_MARKET_ALLEY_N,
    /* 0x20 */ SCENE_MARKET_DAY,
    /* 0x21 */ SCENE_MARKET_NIGHT,
    /* 0x22 */ SCENE_MARKET_RUINS,
    /* 0x23 */ SCENE_SHRINE,
    /* 0x24 */ SCENE_SHRINE_N,
    /* 0x25 */ SCENE_SHRINE_R,
    /* 0x26 */ SCENE_KOKIRI_HOME,
    /* 0x27 */ SCENE_KOKIRI_HOME3,
    /* 0x28 */ SCENE_KOKIRI_HOME4,
    /* 0x29 */ SCENE_KOKIRI_HOME5,
    /* 0x2A */ SCENE_KAKARIKO,
    /* 0x2B */ SCENE_KAKARIKO3,
    /* 0x2C */ SCENE_SHOP1,
    /* 0x2D */ SCENE_KOKIRI_SHOP,
    /* 0x2E */ SCENE_GOLON,
    /* 0x2F */ SCENE_ZOORA,
    /* 0x30 */ SCENE_DRAG,
    /* 0x31 */ SCENE_ALLEY_SHOP,
    /* 0x32 */ SCENE_NIGHT_SHOP,
    /* 0x33 */ SCENE_FACE_SHOP,
    /* 0x34 */ SCENE_LINK_HOME,
    /* 0x35 */ SCENE_IMPA,
    /* 0x36 */ SCENE_MALON_STABLE,
    /* 0x37 */ SCENE_LABO,
    /* 0x38 */ SCENE_HYLIA_LABO,
    /* 0x39 */ SCENE_TENT,
    /* 0x3A */ SCENE_HUT,
    /* 0x3B */ SCENE_DAIYOUSEI_IZUMI,
    /* 0x3C */ SCENE_YOUSEI_IZUMI_TATE,
    /* 0x3D */ SCENE_YOUSEI_IZUMI_YOKO,
    /* 0x3E */ SCENE_KAKUSIANA,
    /* 0x3F */ SCENE_HAKAANA,
    /* 0x40 */ SCENE_HAKAANA2,
    /* 0x41 */ SCENE_HAKAANA_OUKE,
    /* 0x42 */ SCENE_SYATEKIJYOU,
    /* 0x43 */ SCENE_TOKINOMA,
    /* 0x44 */ SCENE_KENJYANOMA,
    /* 0x45 */ SCENE_HAIRAL_NIWA,
    /* 0x46 */ SCENE_HAIRAL_NIWA_N,
    /* 0x47 */ SCENE_HIRAL_DEMO,
    /* 0x48 */ SCENE_HAKASITARELAY,
    /* 0x49 */ SCENE_TURIBORI,
    /* 0x4A */ SCENE_NAKANIWA,
    /* 0x4B */ SCENE_BOWLING,
    /* 0x4C */ SCENE_SOUKO,
    /* 0x4D */ SCENE_MIHARIGOYA,
    /* 0x4E */ SCENE_MAHOUYA,
    /* 0x4F */ SCENE_GANON_DEMO,
    /* 0x50 */ SCENE_KINSUTA,
    /* 0x51 */ SCENE_SPOT00,
    /* 0x52 */ SCENE_SPOT01,
    /* 0x53 */ SCENE_SPOT02,
    /* 0x54 */ SCENE_SPOT03,
    /* 0x55 */ SCENE_SPOT04,
    /* 0x56 */ SCENE_SPOT05,
    /* 0x57 */ SCENE_SPOT06,
    /* 0x58 */ SCENE_SPOT07,
    /* 0x59 */ SCENE_SPOT08,
    /* 0x5A */ SCENE_SPOT09,
    /* 0x5B */ SCENE_SPOT10,
    /* 0x5C */ SCENE_SPOT11,
    /* 0x5D */ SCENE_SPOT12,
    /* 0x5E */ SCENE_SPOT13,
    /* 0x5F */ SCENE_SPOT15,
    /* 0x60 */ SCENE_SPOT16,
    /* 0x61 */ SCENE_SPOT17,
    /* 0x62 */ SCENE_SPOT18,
    /* 0x63 */ SCENE_SPOT20,
    /* 0x64 */ SCENE_GANON_TOU,
    // Debug only scenes
    /* 0x65 */ SCENE_TEST01,
    /* 0x66 */ SCENE_BESITU,
    /* 0x67 */ SCENE_DEPTH_TEST,
    /* 0x68 */ SCENE_SYOTES,
    /* 0x69 */ SCENE_SYOTES2,
    /* 0x6A */ SCENE_SUTARU,
    /* 0x6B */ SCENE_HAIRAL_NIWA2,
    /* 0x6C */ SCENE_SASATEST,
    /* 0x6D */ SCENE_TESTROOM
} SceneID;

enum {
    YDAN_0,
    YDAN_0_1,
    YDAN_0_2,
    YDAN_0_3,

    DDAN_0,
    DDAN_0_1,
    DDAN_0_2,
    DDAN_0_3,

    MEN_0,
    MEN_0_1,
    MEN_0_2,
    MEN_0_3,

    MORIBOSS_0,
    MORIBOSS_0_1,
    MORIBOSS_0_2,
    MORIBOSS_0_3,

    MIZUSIN_0,
    MIZUSIN_0_1,
    MIZUSIN_0_2,
    MIZUSIN_0_3,

    FSTDAN_0,			/* 削除 */
    FSTDAN_0_1,			/* 削除 */
    FSTDAN_0_2,			/* 削除 */
    FSTDAN_0_3,			/* 削除 */

    SASATEST_0,
    SASATEST_1,
    SASATEST_2,
    SASATEST_3,

    SYOTES_0,
    SYOTES_1,
    SYOTES_2,
    SYOTES_3,

    SYOTES2_0,
    SYOTES2_1,
    SYOTES2_2,
    SYOTES2_3,

    TESTROOM_0,
    TESTROOM_1,
    TESTROOM_2,
    TESTROOM_3,

    BDAN_0,
    BDAN_0_1,
    BDAN_0_2,
    BDAN_0_3,
    BDAN_0_4,

    HAKAANA_OUKE_0,
    HAKAANA_OUKE_0_1,
    HAKAANA_OUKE_0_2,
    HAKAANA_OUKE_0_3,
    HAKAANA_OUKE_0_4,		/* SASA	*/
    HAKAANA_OUKE_0_5,		/* SASA	*/

    ENTRA_0,
    ENTRA_NIGHT_0,
    ENTRA_RUINS_0,
    ENTRA_RUINS_0_1,

    HAKADAN_0,
    HAKADAN_0_1,
    HAKADAN_0_2,
    HAKADAN_0_3,

    SYATEKI_0,
    SYATEKI_0_1,
    SYATEKI_0_2,
    SYATEKI_0_3,

    KAKUSIANA_0,
    KAKUSIANA_0_1,
    KAKUSIANA_0_2,
    KAKUSIANA_0_3,

    HYLIA_LABO_0,
    HYLIA_LABO_0_1,
    HYLIA_LABO_0_2,
    HYLIA_LABO_0_3,

    SUTARU_0,
    SUTARU_0_1,
    SUTARU_0_2,
    SUTARU_0_3,

    HAKAANA2_0,
    HAKAANA2_0_1,
    HAKAANA2_0_2,
    HAKAANA2_0_3,

    SOUKO_0,
    SOUKO_0_1,
    SOUKO_0_2,
    SOUKO_0_3,

    TOKINOMA_0,
    TOKINOMA_0_1,
    TOKINOMA_0_2,
    TOKINOMA_0_3,
    TOKINOMA_0_4,
    TOKINOMA_0_5,
    TOKINOMA_0_6,
    TOKINOMA_0_7,
    TOKINOMA_0_8,
    TOKINOMA_0_9,
    TOKINOMA_0_10,
    TOKINOMA_0_11,
    TOKINOMA_0_12,
    TOKINOMA_0_13,
    TOKINOMA_0_14,
    TOKINOMA_0_15,

    TAKARAYA_0,
    TAKARAYA_0_1,
    TAKARAYA_0_2,
    TAKARAYA_0_3,

    MARKET_ALLEY_3,
    MARKET_ALLEY_N_3,
    MARKET_ALLEY_3_1,
    MARKET_ALLEY_N_3_1,

    KENJYANOMA_0,
    KENJYANOMA_0_1,
    KENJYANOMA_0_2,
    KENJYANOMA_0_3,
    KENJYANOMA_0_4,
    KENJYANOMA_0_5,
    KENJYANOMA_0_6,

    MAHOUYA_0,
    MAHOUYA_0_1,
    MAHOUYA_0_2,
    MAHOUYA_0_3,

    HAIRARUNIWA2_0,
    HAIRARUNIWA2_0_1,
    HAIRARUNIWA2_0_2,
    HAIRARUNIWA2_0_3,

    HAIRARUNIWA_0,
    HAIRARUNIWA_N_0,
    HAIRARUNIWA_0_1,
    HAIRARUNIWA_N_0_1,

    MIHARIGOYA_0,
    MIHARIGOYA_0_1,
    MIHARIGOYA_0_2,
    MIHARIGOYA_0_3,

    JYASINZOU_0,
    JYASINZOU_0_1,
    JYASINZOU_0_2,
    JYASINZOU_0_3,
    JYASINZOU_0_4,
    JYASINZOU_0_5,

    ICE_DOUKUTU_0,
    ICE_DOUKUTU_0_1,
    ICE_DOUKUTU_0_2,
    ICE_DOUKUTU_0_3,
    ICE_DOUKUTU_0_4,

    JYASINZOU_BOSS_0,
    JYASINZOU_BOSS_0_1,
    JYASINZOU_BOSS_0_2,
    JYASINZOU_BOSS_0_3,
    JYASINZOU_BOSS_0_4,
    JYASINZOU_BOSS_0_5,
    JYASINZOU_BOSS_0_6,

    TEST01_0,
    TEST01_0_1,
    TEST01_0_2,
    TEST01_0_3,

    HAKADAN_CH_0,
    HAKADAN_CH_0_1,
    HAKADAN_CH_0_2,
    HAKADAN_CH_0_3,

    KOKIRI_HOME3_0,
    KOKIRI_HOME3_0_1,
    KOKIRI_HOME3_0_2,
    KOKIRI_HOME3_0_3,

    HIRAL_DEMO_0,
    HIRAL_DEMO_0_1,
    HIRAL_DEMO_0_2,
    HIRAL_DEMO_0_3,
    HIRAL_DEMO_0_4,
    HIRAL_DEMO_0_5,
    HIRAL_DEMO_0_6,
    HIRAL_DEMO_0_7,
    HIRAL_DEMO_0_8,
    HIRAL_DEMO_0_9,
    HIRAL_DEMO_0_10,
    HIRAL_DEMO_0_11,
    HIRAL_DEMO_0_12,

    MARKET_ALLEY_0,
    MARKET_ALLEY_N_0,
    MARKET_ALLEY_0_1,
    MARKET_ALLEY_N_0_1,

    MARKET_DAY_0,
    MARKET_NIGHT_0,
    MARKET_RUINS_0,
    MARKET_RUINS_0_1,
    MARKET_DAY_0_1,

    DEPTH_TEST_0,

    SHIELD_SHOP_0,
    SHIELD_SHOP_0_1,
    SHIELD_SHOP_0_2,
    SHIELD_SHOP_0_3,

    LINK_HOME_0,
    LINK_HOME_0_1,
    LINK_HOME_0_2,
    LINK_HOME_0_3,
    LINK_HOME_0_4,
    LINK_HOME_0_5,

    KOKIRI_SHOP_0,
    KOKIRI_SHOP_0_1,
    KOKIRI_SHOP_0_2,
    KOKIRI_SHOP_0_3,

    DDAN_1,
    DDAN_1_1,
    DDAN_1_2,
    DDAN_1_3,

    KOKIRI_HOME_0,
    KOKIRI_HOME_0_1,
    KOKIRI_HOME_0_2,
    KOKIRI_HOME_0_3,

    SPOT00_0,		
    SPOT00_0_1,
    SPOT00_0_2,
    SPOT00_0_3,
    SPOT00_0_4,
    SPOT00_0_5,
    SPOT00_0_6,
    SPOT00_0_7,
    SPOT00_0_8,
    SPOT00_0_9,
    SPOT00_0_10,
    SPOT00_0_11,
    SPOT00_0_12,
    SPOT00_0_13,

    SPOT01_0,
    SPOT01_0_1,
    SPOT01_0_2,
    SPOT01_0_3,
    SPOT01_0_4,
    SPOT01_0_5,
    SPOT01_0_6,
    SPOT01_0_7,
    SPOT01_0_8,

    SPOT02_0,
    SPOT02_0_1,
    SPOT02_0_2,
    SPOT02_0_3,
    SPOT02_0_4,
    SPOT02_0_5,

    SPOT03_0,
    SPOT03_0_1,
    SPOT03_0_2,
    SPOT03_0_3,

    SPOT04_0,
    SPOT04_0_1,
    SPOT04_0_2,
    SPOT04_0_3,
    SPOT04_0_4,
    SPOT04_0_5,
    SPOT04_0_6,
    SPOT04_0_7,
    SPOT04_0_8,
    SPOT04_0_9,
    SPOT04_0_10,
    SPOT04_0_11,
    SPOT04_0_12,
    SPOT04_0_13,

    SPOT05_0,
    SPOT05_0_1,
    SPOT05_0_2,
    SPOT05_0_3,
    SPOT05_0_4,
    SPOT05_0_5,

    SPOT06_0,
    SPOT06_0_1,
    SPOT06_0_2,
    SPOT06_0_3,
    SPOT06_0_4,
    SPOT06_0_5,

    SPOT07_0,
    SPOT07_0_1,
    SPOT07_0_2,
    SPOT07_0_3,
    SPOT07_0_4,
    SPOT07_0_5,

    SPOT08_0,
    SPOT08_0_1,
    SPOT08_0_2,
    SPOT08_0_3,
    SPOT08_0_4,
    SPOT08_0_5,
    SPOT08_0_6,
    SPOT08_0_7,
    SPOT08_0_8,

    SPOT09_0,
    SPOT09_0_1,
    SPOT09_0_2,
    SPOT09_0_3,
    SPOT09_0_4,					/* demo 00 fog hare	*/
    SPOT09_0_5,					/* demo 01 rock		*/
    SPOT09_0_6,					/* 			*/

    SPOT10_0,
    SPOT10_0_1,
    SPOT10_0_2,
    SPOT10_0_3,
    SPOT10_0_4,

    SPOT11_0,
    SPOT11_0_1,
    SPOT11_0_2,
    SPOT11_0_3,
    SPOT11_0_4,
    SPOT11_0_5,

    SPOT12_0,
    SPOT12_0_1,
    SPOT12_0_2,
    SPOT12_0_3,
    SPOT12_0_4,
    SPOT12_0_5,
    SPOT12_0_6,

    SPOT13_0,
    SPOT13_0_1,
    SPOT13_0_2,
    SPOT13_0_3,

    GANON_SONOGO_1,
    GANON_SONOGO_1_1,
    GANON_SONOGO_1_2,
    GANON_SONOGO_1_3,

    SPOT15_0,
    SPOT15_0_1,
    GANONTOU_0,
    GANONTOU_0_1,
    SPOT15_0_2,

    SPOT16_0,
    SPOT16_0_1,
    SPOT16_0_2,
    SPOT16_0_3,
    SPOT16_0_4,	/* ハイラル伝説 	*/
    SPOT16_0_5,	/* ルピー		*/
    SPOT16_0_6,	/* スタッフテロップ	*/
    SPOT16_0_7,	/* ステージ紹介		*/
    SPOT16_0_8,
    SPOT16_0_9,

    SPOT17_0,
    SPOT17_0_1,
    SPOT17_0_2,
    SPOT17_0_3,
    SPOT17_0_4,
    SPOT17_0_5,

    SPOT18_0,
    SPOT18_0_1,
    SPOT18_0_2,
    SPOT18_0_3,
    SPOT18_0_4,
    SPOT18_0_5,

    SPOT07_3,
    SPOT07_3_1,
    SPOT07_3_2,
    SPOT07_3_3,

    SPOT20_0,
    SPOT20_0_1,
    SPOT20_0_2,
    SPOT20_0_3,
    SPOT20_0_4,
    SPOT20_0_5,
    SPOT20_0_6,
    SPOT20_0_7,
    SPOT20_0_8,
    SPOT20_0_9,
    SPOT20_0_10,
    SPOT20_0_11,
    SPOT20_0_12,
    SPOT20_0_13,

    HIDAN_0,
    HIDAN_0_1,
    HIDAN_0_2,
    HIDAN_0_3,

    MORI1_0,
    MORI1_0_1,
    MORI1_0_2,
    MORI1_0_3,

    SYATEKI_1,
    SYATEKI_1_1,
    SYATEKI_1_2,
    SYATEKI_1_3,

    SHRINE_0,
    SHRINE_N_0,
    SHRINE_R_0,
    SHRINE_R_0_1,

    HIDAN_1,
    HIDAN_1_1,
    HIDAN_1_2,
    HIDAN_1_3,

    GANON_SONOGO_0,
    GANON_SONOGO_0_1,
    GANON_SONOGO_0_2,
    GANON_SONOGO_0_3,

    SPOT00_1,
    SPOT00_1_1,
    SPOT00_1_2,
    SPOT00_1_3,

    SPOT00_2,
    SPOT00_2_1,
    SPOT00_2_2,
    SPOT00_2_3,

    SPOT00_3,
    SPOT00_3_1,
    SPOT00_3_2,
    SPOT00_3_3,

    SPOT00_4,
    SPOT00_4_1,
    SPOT00_4_2,
    SPOT00_4_3,

    SPOT00_5,
    SPOT00_5_1,
    SPOT00_5_2,
    SPOT00_5_3,

    SPOT01_1,
    SPOT01_1_1,
    SPOT01_1_2,
    SPOT01_1_3,

    SPOT01_2,
    SPOT01_2_1,
    SPOT01_2_2,
    SPOT01_2_3,

    SPOT03_1,
    SPOT03_1_1,
    SPOT03_1_2,
    SPOT03_1_3,

    SPOT03_2,
    SPOT03_2_1,
    SPOT03_2_2,
    SPOT03_2_3,

    SPOT07_1,
    SPOT07_1_1,
    SPOT07_1_2,
    SPOT07_1_3,

    SPOT09_1,
    SPOT09_1_1,
    SPOT09_1_2,
    SPOT09_1_3,

    SPOT10_1,
    SPOT10_1_1,
    SPOT10_1_2,
    SPOT10_1_3,

    SPOT10_2,
    SPOT10_2_1,
    SPOT10_2_2,
    SPOT10_2_3,

    SPOT10_3,
    SPOT10_3_1,
    SPOT10_3_2,
    SPOT10_3_3,

    GANON_SONOGO_2,
    GANON_SONOGO_2_1,
    GANON_SONOGO_2_2,
    GANON_SONOGO_2_3,

    SPOT16_1,
    SPOT16_1_1,
    SPOT16_1_2,
    SPOT16_1_3,

    SPOT16_2,
    SPOT16_2_1,
    SPOT16_2_2,
    SPOT16_2_3,

    SPOT18_1,
    SPOT18_1_1,
    SPOT18_1_2,
    SPOT18_1_3,

    HYLIA_LABO_1,
    HYLIA_LABO_1_1,
    HYLIA_LABO_1_2,
    HYLIA_LABO_1_3,
    
    GANON_FINAL_5,
    GANON_FINAL_5_1,
    GANON_FINAL_5_2,
    GANON_FINAL_5_3,

    MARKET_DAY_8,
    MARKET_NIGHT_8,
    MARKET_RUINS_8,
    MARKET_RUINS_8_1,

    MARKET_DAY_9,
    MARKET_NIGHT_9,
    MARKET_RUINS_9,
    MARKET_RUINS_9_1,

    MARKET_DAY_10,
    MARKET_NIGHT_10,
    MARKET_RUINS_10,
    MARKET_RUINS_10_1,

    SPOT03_3,
    SPOT03_3_1,
    SPOT03_3_2,
    SPOT03_3_3,

    SPOT03_4,
    SPOT03_4_1,
    SPOT03_4_2,
    SPOT03_4_3,

    SPOT11_1,
    SPOT11_1_1,
    SPOT11_1_2,
    SPOT11_1_3,

    SPOT11_2,
    SPOT11_2_1,
    SPOT11_2_2,
    SPOT11_2_3,

    SPOT11_3,
    SPOT11_3_1,
    SPOT11_3_2,
    SPOT11_3_3,

    SPOT11_4,
    SPOT11_4_1,
    SPOT11_4_2,
    SPOT11_4_3,

    SPOT11_5,
    SPOT11_5_1,
    SPOT11_5_2,
    SPOT11_5_3,

    SPOT11_6,
    SPOT11_6_1,
    SPOT11_6_2,
    SPOT11_6_3,

    SPOT00_6,
    SPOT00_6_1,
    SPOT00_6_2,
    SPOT00_6_3,

    SPOT00_7,
    SPOT00_7_1,
    SPOT00_7_2,
    SPOT00_7_3,

    SPOT01_3,
    SPOT01_3_1,
    SPOT01_3_2,
    SPOT01_3_3,

    SPOT02_1,
    SPOT02_1_1,
    SPOT02_1_2,
    SPOT02_1_3,

    SPOT04_1,
    SPOT04_1_1,
    SPOT04_1_2,
    SPOT04_1_3,

    SPOT04_2,
    SPOT04_2_1,
    SPOT04_2_2,
    SPOT04_2_3,

    SPOT04_3,
    SPOT04_3_1,
    SPOT04_3_2,
    SPOT04_3_3,

    SPOT05_1,
    SPOT05_1_1,
    SPOT05_1_2,
    SPOT05_1_3,

    SPOT06_1,
    SPOT06_1_1,
    SPOT06_1_2,
    SPOT06_1_3,

    SPOT06_2,
    SPOT06_2_1,
    SPOT06_2_2,
    SPOT06_2_3,

    SPOT08_1,
    SPOT08_1_1,
    SPOT08_1_2,
    SPOT08_1_3,

    SPOT08_2,
    SPOT08_2_1,
    SPOT08_2_2,
    SPOT08_2_3,

    SPOT09_2,
    SPOT09_2_1,
    SPOT09_2_2,
    SPOT09_2_3,

    SPOT09_3,
    SPOT09_3_1,
    SPOT09_3_2,
    SPOT09_3_3,

    SPOT12_1,
    SPOT12_1_1,
    SPOT12_1_2,
    SPOT12_1_3,

    SPOT12_2,
    SPOT12_2_1,
    SPOT12_2_2,
    SPOT12_2_3,

    SPOT12_3,
    SPOT12_3_1,
    SPOT12_3_2,
    SPOT12_3_3,

    SPOT15_1,
    SPOT15_1_1,
    GANONTOU_1,
    GANONTOU_1_1,
    SPOT15_1_2,

    SPOT16_3,
    SPOT16_3_1,
    SPOT16_3_2,
    SPOT16_3_3,

    SPOT17_1,
    SPOT17_1_1,
    SPOT17_1_2,
    SPOT17_1_3,

    SPOT17_2,
    SPOT17_2_1,
    SPOT17_2_2,
    SPOT17_2_3,

    MORI1_1,
    MORI1_1_1,
    MORI1_1_2,
    MORI1_1_3,

    YDAN_1,
    YDAN_1_1,
    YDAN_1_2,
    YDAN_1_3,

    GANON_SONOGO_3,
    GANON_SONOGO_3_1,
    GANON_SONOGO_3_2,
    GANON_SONOGO_3_3,

    MARKET_DAY_1,
    MARKET_NIGHT_1,
    MARKET_RUINS_1,
    MARKET_RUINS_1_1,

    MARKET_DAY_2,
    MARKET_NIGHT_2,
    MARKET_RUINS_2,
    MARKET_RUINS_2_1,

    MARKET_DAY_3,
    MARKET_NIGHT_3,
    MARKET_RUINS_3,
    MARKET_RUINS_3_1,

    SPOT04_4,
    SPOT04_4_1,
    SPOT04_4_2,
    SPOT04_4_3,

    SPOT04_5,
    SPOT04_5_1,
    SPOT04_5_2,
    SPOT04_5_3,

    ENTRA_2,
    ENTRA_NIGHT_2,
    ENTRA_RUINS_2,
    ENTRA_RUINS_2_1,

    LINK_HOME_1,
    LINK_HOME_1_1,
    LINK_HOME_1_2,
    LINK_HOME_1_3,

    ENTRA_1,
    ENTRA_NIGHT_1,
    ENTRA_RUINS_1,
    ENTRA_RUINS_1_1,

    SPOT00_8,
    SPOT00_8_1,
    SPOT00_8_2,
    SPOT00_8_3,

    SPOT00_9,
    SPOT00_9_1,
    SPOT00_9_2,
    SPOT00_9_3,

    SPOT00_10,
    SPOT00_10_1,
    SPOT00_10_2,
    SPOT00_10_3,

    SPOT04_6,
    SPOT04_6_1,
    SPOT04_6_2,
    SPOT04_6_3,

    SPOT00_11,
    SPOT00_11_1,
    SPOT00_11_2,
    SPOT00_11_3,

    SPOT00_12,
    SPOT00_12_1,
    SPOT00_12_2,
    SPOT00_12_3,

    SPOT00_13,
    SPOT00_13_1,
    SPOT00_13_2,
    SPOT00_13_3,

    HAIRARUNIWA_1,
    HAIRARUNIWA_N_1,
    HAIRARUNIWA_1_1,
    HAIRARUNIWA_N_1_1,

    MARKET_ALLEY_1,
    MARKET_ALLEY_N_1,
    MARKET_ALLEY_1_1,
    MARKET_ALLEY_N_1_1,

    MARKET_DAY_4,
    MARKET_NIGHT_4,
    MARKET_RUINS_4,
    MARKET_RUINS_4_1,

    MARKET_DAY_5,
    MARKET_NIGHT_5,
    MARKET_RUINS_5,
    MARKET_RUINS_5_1,

    SPOT01_4,
    SPOT01_4_1,
    SPOT01_4_2,
    SPOT01_4_3,

    SPOT12_4,
    SPOT12_4_1,
    SPOT12_4_2,
    SPOT12_4_3,

    SPOT20_1,
    SPOT20_1_1,
    SPOT20_1_2,
    SPOT20_1_3,

    HAKADAN_1,
    HAKADAN_1_1,
    HAKADAN_1_2,
    HAKADAN_1_3,

    HAKADAN_2,
    HAKADAN_2_1,
    HAKADAN_2_2,
    HAKADAN_2_3,

    SPOT12_5,
    SPOT12_5_1,
    SPOT12_5_2,
    SPOT12_5_3,

    SPOT12_6,
    SPOT12_6_1,
    SPOT12_6_2,
    SPOT12_6_3,

    SPOT12_7,
    SPOT12_7_1,
    SPOT12_7_2,
    SPOT12_7_3,

    SPOT12_8,
    SPOT12_8_1,
    SPOT12_8_2,
    SPOT12_8_3,

    TOKINOMA_1,
    TOKINOMA_1_1,
    TOKINOMA_1_2,
    TOKINOMA_1_3,

    KENJYANOMA_1,
    KENJYANOMA_1_1,
    KENJYANOMA_1_2,
    KENJYANOMA_1_3,

    SPOT12_9,
    SPOT12_9_1,
    SPOT12_9_2,
    SPOT12_9_3,

    SPOT12_10,
    SPOT12_10_1,
    SPOT12_10_2,
    SPOT12_10_3,

    SPOT12_11,
    SPOT12_11_1,
    SPOT12_11_2,
    SPOT12_11_3,

    SPOT12_12,
    SPOT12_12_1,
    SPOT12_12_2,
    SPOT12_12_3,

    SPOT20_2,
    SPOT20_2_1,
    SPOT20_2_2,
    SPOT20_2_3,

    SPOT20_3,
    SPOT20_3_1,
    SPOT20_3_2,
    SPOT20_3_3,

/* sasaki demotest you		*/
    SASADEMO_0,
    SASADEMO_1,
    SASADEMO_2,
    SASADEMO_3,
    SASADEMO_4,
    SASADEMO_5,
    SASADEMO_6,
    SASADEMO_7,
    SASADEMO_8,
    SASADEMO_9,
    SASADEMO_10,
/*------------------------------------------------------*/

    JYASINZOU_1,
    JYASINZOU_1_1,
    JYASINZOU_1_2,
    JYASINZOU_1_3,

    LONRON_0,
    LONRON_0_1,
    LONRON_0_2,
    LONRON_0_3,

    KAKARIKO_0,
    KAKARIKO_0_1,
    KAKARIKO_0_2,
    KAKARIKO_0_3,

    BDAN_BOSS_0,
    BDAN_BOSS_0_1,
    BDAN_BOSS_0_2,
    BDAN_BOSS_0_3,

    FIRE_BOSS_0,
    FIRE_BOSS_0_1,
    FIRE_BOSS_0_2,
    FIRE_BOSS_0_3,

    SPOT06_6,
    SPOT06_6_1,
    SPOT06_6_2,
    SPOT06_6_3,

    HAKAMORI_HOUSE_0,
    HAKAMORI_HOUSE_0_1,
    HAKAMORI_HOUSE_0_2,
    HAKAMORI_HOUSE_0_3,

    SPOT00_14,
    SPOT00_14_1,
    SPOT00_14_2,
    SPOT00_14_3,

    DAIYOUSEI_IZUMI_0,
    DAIYOUSEI_IZUMI_0_1,
    DAIYOUSEI_IZUMI_0_2,
    DAIYOUSEI_IZUMI_0_3,
    DAIYOUSEI_IZUMI_0_4,
    DAIYOUSEI_IZUMI_0_5,
    DAIYOUSEI_IZUMI_0_6,

    HAKAANA_0,
    HAKAANA_0_1,
    HAKAANA_0_2,
    HAKAANA_0_3,

    TOKINOMA_3,
    TOKINOMA_3_1,
    TOKINOMA_3_2,
    TOKINOMA_3_3,

    TOKINOMA_4,
    TOKINOMA_4_1,
    TOKINOMA_4_2,
    TOKINOMA_4_3,

    SPOT07_4,
    SPOT07_4_1,
    SPOT07_4_2,
    SPOT07_4_3,

    GANON_FINAL_2,
    GANON_FINAL_2_1,
    GANON_FINAL_2_2,
    GANON_FINAL_2_3,

    GANON_FINAL_3,
    GANON_FINAL_3_1,
    GANON_FINAL_3_2,
    GANON_FINAL_3_3,

    GANON_FINAL_4,
    GANON_FINAL_4_1,
    GANON_FINAL_4_2,
    GANON_FINAL_4_3,

    SPOT04_7,
    SPOT04_7_1,
    SPOT04_7_2,
    SPOT04_7_3,

    SPOT04_8,
    SPOT04_8_1,
    SPOT04_8_2,
    SPOT04_8_3,

    SPOT15_2,
    SPOT15_2_1,
    GANONTOU_2,
    GANONTOU_2_1,
    SPOT15_2_2,

    SPOT01_5,
    SPOT01_5_1,
    SPOT01_5_2,
    SPOT01_5_3,

    SPOT01_6,
    SPOT01_6_1,
    SPOT01_6_2,
    SPOT01_6_3,

    SPOT01_7,
    SPOT01_7_1,
    SPOT01_7_2,
    SPOT01_7_3,

    SPOT01_8,
    SPOT01_8_1,
    SPOT01_8_2,
    SPOT01_8_3,

    SPOT02_2,
    SPOT02_2_1,
    SPOT02_2_2,
    SPOT02_2_3,

    SPOT02_3,
    SPOT02_3_1,
    SPOT02_3_2,
    SPOT02_3_3,

    SPOT02_4,
    SPOT02_4_1,
    SPOT02_4_2,
    SPOT02_4_3,

    SPOT02_5,
    SPOT02_5_1,
    SPOT02_5_2,
    SPOT02_5_3,

    SPOT13_1,
    SPOT13_1_1,
    SPOT13_1_2,
    SPOT13_1_3,

    SPOT13_2,
    SPOT13_2_1,
    SPOT13_2_2,
    SPOT13_2_3,

    YIZUMI_TATE_0,
    YIZUMI_TATE_0_1,
    YIZUMI_TATE_0_2,
    YIZUMI_TATE_0_3,

    YIZUMI_YOKO_0,
    YIZUMI_YOKO_0_1,
    YIZUMI_YOKO_0_2,
    YIZUMI_YOKO_0_3,
    YIZUMI_YOKO_0_4,
    YIZUMI_YOKO_0_5,
    YIZUMI_YOKO_0_6,

    SPOT20_4,
    SPOT20_4_1,
    SPOT20_4_2,
    SPOT20_4_3,

    GORON_SHOP_N_0,
    GORON_SHOP_N_0_1,
    GORON_SHOP_N_0_2,
    GORON_SHOP_N_0_3,

    ZOORA_SHOP_0,
    ZOORA_SHOP_0_1,
    ZOORA_SHOP_0_2,
    ZOORA_SHOP_0_3,

    DRAG_SHOP_0,
    DRAG_SHOP_0_1,
    DRAG_SHOP_0_2,
    DRAG_SHOP_0_3,

    ALLEY_SHOP_0,
    ALLEY_SHOP_0_1,
    ALLEY_SHOP_0_2,
    ALLEY_SHOP_0_3,

    MARKET_ALLEY_4,
    MARKET_ALLEY_N_4,
    MARKET_ALLEY_4_1,
    MARKET_ALLEY_N_4_1,

    NIGHT_SHOP_0,
    NIGHT_SHOP_0_1,
    NIGHT_SHOP_0_2,
    NIGHT_SHOP_0_3,

    SPOT08_5,
    SPOT08_5_1,
    SPOT08_5_2,
    SPOT08_5_3,

    IMPA_HOME_0,
    IMPA_HOME_0_1,
    IMPA_HOME_0_2,
    IMPA_HOME_0_3,

    LABO_0,
    LABO_0_1,
    LABO_0_2,
    LABO_0_3,

    TENTO_0,
    TENTO_0_1,
    TENTO_0_2,
    TENTO_0_3,

    SPOT12_13,
    SPOT12_13_1,
    SPOT12_13_2,
    SPOT12_13_3,

    SPOT12_14,
    SPOT12_14_1,
    SPOT12_14_2,
    SPOT12_14_3,

    SPOT12_15,
    SPOT12_15_1,
    SPOT12_15_2,
    SPOT12_15_3,

    SPOT12_16,
    SPOT12_16_1,
    SPOT12_16_2,
    SPOT12_16_3,

    SPOT12_17,
    SPOT12_17_1,
    SPOT12_17_2,
    SPOT12_17_3,

    MARKET_DAY_6,
    MARKET_NIGHT_6,
    MARKET_RUINS_6,
    MARKET_RUINS_6_1,

    MARKET_DAY_7,
    MARKET_NIGHT_7,
    MARKET_RUINS_7,
    MARKET_RUINS_7_1,

    MARKET_ALLEY_2,
    MARKET_ALLEY_N_2,
    MARKET_ALLEY_2_1,
    MARKET_ALLEY_N_2_1,

    SPOT07_2,
    SPOT07_2_1,
    SPOT07_2_2,
    SPOT07_2_3,

    SPOT06_3,
    SPOT06_3_1,
    SPOT06_3_2,
    SPOT06_3_3,

    SPOT06_4,
    SPOT06_4_1,
    SPOT06_4_2,
    SPOT06_4_3,

    SPOT09_4,
    SPOT09_4_1,
    SPOT09_4_2,
    SPOT09_4_3,

    SPOT08_3,
    SPOT08_3_1,
    SPOT08_3_2,
    SPOT08_3_3,

    SPOT08_4,
    SPOT08_4_1,
    SPOT08_4_2,
    SPOT08_4_3,

    GANON_SONOGO_4,
    GANON_SONOGO_4_1,
    GANON_SONOGO_4_2,
    GANON_SONOGO_4_3,

    GANON_SONOGO_5,
    GANON_SONOGO_5_1,
    GANON_SONOGO_5_2,
    GANON_SONOGO_5_3,

    GANON_SONOGO_6,
    GANON_SONOGO_6_1,
    GANON_SONOGO_6_2,
    GANON_SONOGO_6_3,

    DRAG_SHOP_1,
    DRAG_SHOP_1_1,
    DRAG_SHOP_1_2,
    DRAG_SHOP_1_3,

    DRAG_SHOP_2,
    DRAG_SHOP_2_1,
    DRAG_SHOP_2_2,
    DRAG_SHOP_2_3,

    JYASINZOU_2,
    JYASINZOU_2_1,
    JYASINZOU_2_2,
    JYASINZOU_2_3,

    JYASINZOU_3,
    JYASINZOU_3_1,
    JYASINZOU_3_2,
    JYASINZOU_3_3,

    JYASINZOU_4,
    JYASINZOU_4_1,
    JYASINZOU_4_2,
    JYASINZOU_4_3,

    SPOT18_2,
    SPOT18_2_1,
    SPOT18_2_2,
    SPOT18_2_3,

    NAKANIWA_0,
    NAKANIWA_0_1,
    NAKANIWA_0_2,
    NAKANIWA_0_3,
    NAKANIWA_0_4,
    NAKANIWA_0_5,
    NAKANIWA_0_6,

    BDAN_1,
    BDAN_1_1,
    BDAN_1_2,
    BDAN_1_3,

    DDAN_BOSS_0,
    DDAN_BOSS_0_1,
    DDAN_BOSS_0_2,
    DDAN_BOSS_0_3,

    YDAN_BOSS_0,
    YDAN_BOSS_0_1,
    YDAN_BOSS_0_2,
    YDAN_BOSS_0_3,

    HAKADAN_BOSS_0,
    HAKADAN_BOSS_0_1,
    HAKADAN_BOSS_0_2,
    HAKADAN_BOSS_0_3,

    MIZUSIN_BOSS_0,
    MIZUSIN_BOSS_0_1,
    MIZUSIN_BOSS_0_2,
    MIZUSIN_BOSS_0_3,

    GANON_0,
    GANON_0_1,
    GANON_0_2,
    GANON_0_3,

    GANON_BOSS_0,
    GANON_BOSS_0_1,
    GANON_BOSS_0_2,
    GANON_BOSS_0_3,

    MIZUSIN_1,
    MIZUSIN_1_1,
    MIZUSIN_1_2,
    MIZUSIN_1_3,

    GANON_1,
    GANON_1_1,
    GANON_1_2,
    GANON_1_3,

    GANON_2,
    GANON_2_1,
    GANON_2_2,
    GANON_2_3,

    SPOT20_5,
    SPOT20_5_1,
    SPOT20_5_2,
    SPOT20_5_3,

    KOKIRI_HOME4_0,
    KOKIRI_HOME4_0_1,
    KOKIRI_HOME4_0_2,
    KOKIRI_HOME4_0_3,

    KOKIRI_HOME5_0,
    KOKIRI_HOME5_0_1,
    KOKIRI_HOME5_0_2,
    KOKIRI_HOME5_0_3,

    KAKARIKO_HOME3_0,
    KAKARIKO_HOME3_0_1,
    KAKARIKO_HOME3_0_2,
    KAKARIKO_HOME3_0_3,

    GANON_FINAL_0,
    GANON_FINAL_0_1,
    GANON_FINAL_0_2,
    GANON_FINAL_0_3,

    SPOT04_9,
    SPOT04_9_1,
    SPOT04_9_2,
    SPOT04_9_3,

    SPOT04_10,
    SPOT04_10_1,
    SPOT04_10_2,
    SPOT04_10_3,

    SPOT01_9,
    SPOT01_9_1,
    SPOT01_9_2,
    SPOT01_9_3,

    HAKASITARELAY_0,
    HAKASITARELAY_0_1,
    HAKASITARELAY_0_2,
    HAKASITARELAY_0_3,

    HAKASITARELAY_1,
    HAKASITARELAY_1_1,
    HAKASITARELAY_1_2,
    HAKASITARELAY_1_3,

    SPOT04_11,
    SPOT04_11_1,
    SPOT04_11_2,
    SPOT04_11_3,

    SPOT16_4,
    SPOT16_4_1,
    SPOT16_4_2,
    SPOT16_4_3,

    TURIBORI_0,
    TURIBORI_0_1,
    TURIBORI_0_2,
    TURIBORI_0_3,

    SPOT01_10,
    SPOT01_10_1,
    SPOT01_10_2,
    SPOT01_10_3,

    GANONTIKA_0,
    GANONTIKA_0_1,
    GANONTIKA_0_2,
    GANONTIKA_0_3,
    GANONTIKA_0_4,
    GANONTIKA_0_5,
    GANONTIKA_0_6,
    GANONTIKA_0_7,
    GANONTIKA_0_8,
    GANONTIKA_0_9,
    GANONTIKA_0_10,

    SHRINE_1,
    SHRINE_N_1,
    SHRINE_R_1,
    SHRINE_R_1_1,

    SPOT00_15,
    SPOT00_15_1,
    SPOT00_15_2,
    SPOT00_15_3,

    SPOT16_5,
    SPOT16_5_1,
    SPOT16_5_2,
    SPOT16_5_3,

    SPOT15_4,
    SPOT15_4_1,
    GANONTOU_4,
    GANONTOU_4_1,

    SPOT17_3,
    SPOT17_3_1,
    SPOT17_3_2,
    SPOT17_3_3,

    GERUDOWAY_0,
    GERUDOWAY_0_1,
    GERUDOWAY_0_2,
    GERUDOWAY_0_3,

    GERUDOWAY_1,
    GERUDOWAY_1_1,
    GERUDOWAY_1_2,
    GERUDOWAY_1_3,

    GERUDOWAY_2,
    GERUDOWAY_2_1,
    GERUDOWAY_2_2,
    GERUDOWAY_2_3,

    GERUDOWAY_3,
    GERUDOWAY_3_1,
    GERUDOWAY_3_2,
    GERUDOWAY_3_3,

    GERUDOWAY_4,
    GERUDOWAY_4_1,
    GERUDOWAY_4_2,
    GERUDOWAY_4_3,

    GERUDOWAY_5,
    GERUDOWAY_5_1,
    GERUDOWAY_5_2,
    GERUDOWAY_5_3,

    GERUDOWAY_6,
    GERUDOWAY_6_1,
    GERUDOWAY_6_2,
    GERUDOWAY_6_3,

    GERUDOWAY_7,
    GERUDOWAY_7_1,
    GERUDOWAY_7_2,
    GERUDOWAY_7_3,

    GERUDOWAY_8,
    GERUDOWAY_8_1,
    GERUDOWAY_8_2,
    GERUDOWAY_8_3,

    GERUDOWAY_9,
    GERUDOWAY_9_1,
    GERUDOWAY_9_2,
    GERUDOWAY_9_3,

    GERUDOWAY_10,
    GERUDOWAY_10_1,
    GERUDOWAY_10_2,
    GERUDOWAY_10_3,

    GERUDOWAY_11,
    GERUDOWAY_11_1,
    GERUDOWAY_11_2,
    GERUDOWAY_11_3,

    GANON_SONOGO_7,
    GANON_SONOGO_7_1,
    GANON_SONOGO_7_2,
    GANON_SONOGO_7_3,

    GANON_FINAL_1,
    GANON_FINAL_1_1,
    GANON_FINAL_1_2,
    GANON_FINAL_1_3,

    DAIYOUSEI_IZUMI_1,
    DAIYOUSEI_IZUMI_1_1,
    DAIYOUSEI_IZUMI_1_2,
    DAIYOUSEI_IZUMI_1_3,

    DAIYOUSEI_IZUMI_2,
    DAIYOUSEI_IZUMI_2_1,
    DAIYOUSEI_IZUMI_2_2,
    DAIYOUSEI_IZUMI_2_3,

    SPOT10_4,
    SPOT10_4_1,
    SPOT10_4_2,
    SPOT10_4_3,

    SPOT20_6,
    SPOT20_6_1,
    SPOT20_6_2,
    SPOT20_6_3,

    SPOT20_7,
    SPOT20_7_1,
    SPOT20_7_2,
    SPOT20_7_3,

    SPOT10_5,
    SPOT10_5_1,
    SPOT10_5_2,
    SPOT10_5_3,

    SPOT10_6,
    SPOT10_6_1,
    SPOT10_6_2,
    SPOT10_6_3,

    SPOT10_7,
    SPOT10_7_1,
    SPOT10_7_2,
    SPOT10_7_3,

    SPOT10_8,
    SPOT10_8_1,
    SPOT10_8_2,
    SPOT10_8_3,

    SPOT18_3,
    SPOT18_3_1,
    SPOT18_3_2,
    SPOT18_3_3,

    SPOT06_5,
    SPOT06_5_1,
    SPOT06_5_2,
    SPOT06_5_3,

    HAKADAN_3,
    HAKADAN_3_1,
    HAKADAN_3_2,
    HAKADAN_3_3,

    SPOT01_11,
    SPOT01_11_1,
    SPOT01_11_2,
    SPOT01_11_3,

    DAIYOUSEI_IZUMI_3,
    DAIYOUSEI_IZUMI_3_1,
    DAIYOUSEI_IZUMI_3_2,
    DAIYOUSEI_IZUMI_3_3,

    SPOT17_4,
    SPOT17_4_1,
    SPOT17_4_2,
    SPOT17_4_3,

    SPOT15_3,
    SPOT15_3_1,
    GANONTOU_3,
    GANONTOU_3_1,
    SPOT15_3_2,

    SPOT01_12,
    SPOT01_12_1,
    SPOT01_12_2,
    SPOT01_12_3,

    HAKASITARELAY_2,
    HAKASITARELAY_2_1,
    HAKASITARELAY_2_2,
    HAKASITARELAY_2_3,

    BOWLING_0,
    BOWLING_0_1,
    BOWLING_0_2,
    BOWLING_0_3,

    SPOT02_6,
    SPOT02_6_1,
    SPOT02_6_2,
    SPOT02_6_3,

    SPOT00_16,
    SPOT00_16_1,
    SPOT00_16_2,
    SPOT00_16_3,

    SPOT01_13,
    SPOT01_13_1,
    SPOT01_13_2,
    SPOT01_13_3,

    GANON_DEMO_0,
    GANON_DEMO_0_1,
    GANON_DEMO_0_2,
    GANON_DEMO_0_3,
    GANON_DEMO_0_4,

    GANON_FINAL_6,
    GANON_FINAL_6_1,
    GANON_FINAL_6_2,
    GANON_FINAL_6_3,

    BESITU_0,
    BESITU_0_1,
    BESITU_0_2,
    BESITU_0_3,

    GANON_FINAL_7,
    GANON_FINAL_7_1,
    GANON_FINAL_7_2,
    GANON_FINAL_7_3,

    NIGHT_SHOP_1,
    NIGHT_SHOP_1_1,
    NIGHT_SHOP_1_2,
    NIGHT_SHOP_1_3,

    SHIELD_SHOP_1,
    SHIELD_SHOP_1_1,
    SHIELD_SHOP_1_2,
    SHIELD_SHOP_1_3,

    FACE_SHOP_0,
    FACE_SHOP_0_1,
    FACE_SHOP_0_2,
    FACE_SHOP_0_3,

    GANONTIKA_1,
    GANONTIKA_1_1,
    GANONTIKA_1_2,
    GANONTIKA_1_3,

    GANONTIKA_2,
    GANONTIKA_2_1,
    GANONTIKA_2_2,
    GANONTIKA_2_3,

    GANONTIKA_3,
    GANONTIKA_3_1,
    GANONTIKA_3_2,
    GANONTIKA_3_3,

    GANONTIKA_4,
    GANONTIKA_4_1,
    GANONTIKA_4_2,
    GANONTIKA_4_3,

    GANONTIKA_5,
    GANONTIKA_5_1,
    GANONTIKA_5_2,
    GANONTIKA_5_3,

    GANONTIKA_6,
    GANONTIKA_6_1,
    GANONTIKA_6_2,
    GANONTIKA_6_3,

    GANONTIKA_7,
    GANONTIKA_7_1,
    GANONTIKA_7_2,
    GANONTIKA_7_3,

    KINSUTA_0,
    KINSUTA_0_1,
    KINSUTA_0_2,
    KINSUTA_0_3,

    SPOT01_14,
    SPOT01_14_1,
    SPOT01_14_2,
    SPOT01_14_3,

    SPOT20_8,
    SPOT20_8_1,
    SPOT20_8_2,
    SPOT20_8_3,

    SPOT20_9,
    SPOT20_9_1,
    SPOT20_9_2,
    SPOT20_9_3,

    SPOT06_7,
    SPOT06_7_1,
    SPOT06_7_2,
    SPOT06_7_3,

    SPOT17_5,
    SPOT17_5_1,
    SPOT17_5_2,
    SPOT17_5_3,

    SPOT02_7,
    SPOT02_7_1,
    SPOT02_7_2,
    SPOT02_7_3,

    GANONTIKA_SONOGO_0,
    GANONTIKA_SONOGO_0_1,
    GANONTIKA_SONOGO_0_2,
    GANONTIKA_SONOGO_0_3,

    GERUDOWAY_12,
    GERUDOWAY_12_1,
    GERUDOWAY_12_2,
    GERUDOWAY_12_3,

    HAKAANA_OUKE_1,
    HAKAANA_OUKE_1_1,
    HAKAANA_OUKE_1_2,
    HAKAANA_OUKE_1_3,

    YIZUMI_YOKO_1,
    YIZUMI_YOKO_1_1,
    YIZUMI_YOKO_1_2,
    YIZUMI_YOKO_1_3,

    SPOT11_7,
    SPOT11_7_1,
    SPOT11_7_2,
    SPOT11_7_3,

    SPOT02_8,
    SPOT02_8_1,
    SPOT02_8_2,
    SPOT02_8_3,

    MORI1_2,
    MORI1_2_1,
    MORI1_2_2,
    MORI1_2_3,

    YIZUMI_YOKO_2,
    YIZUMI_YOKO_2_1,
    YIZUMI_YOKO_2_2,
    YIZUMI_YOKO_2_3,

    TOKINOMA_5,
    TOKINOMA_5_1,
    TOKINOMA_5_2,
    TOKINOMA_5_3,

    TOKINOMA_6,
    TOKINOMA_6_1,
    TOKINOMA_6_2,
    TOKINOMA_6_3,

    SPOT00_17,
    SPOT00_17_1,
    SPOT00_17_2,
    SPOT00_17_3,

    KAKUSIANA_1,
    KAKUSIANA_1_1,
    KAKUSIANA_1_2,
    KAKUSIANA_1_3,

    KAKUSIANA_2,
    KAKUSIANA_2_1,
    KAKUSIANA_2_2,
    KAKUSIANA_2_3,

    KAKUSIANA_3,
    KAKUSIANA_3_1,
    KAKUSIANA_3_2,
    KAKUSIANA_3_3,

    KAKUSIANA_4,
    KAKUSIANA_4_1,
    KAKUSIANA_4_2,
    KAKUSIANA_4_3,

    KAKUSIANA_5,
    KAKUSIANA_5_1,
    KAKUSIANA_5_2,
    KAKUSIANA_5_3,

    KAKUSIANA_6,
    KAKUSIANA_6_1,
    KAKUSIANA_6_2,
    KAKUSIANA_6_3,

    KAKUSIANA_7,
    KAKUSIANA_7_1,
    KAKUSIANA_7_2,
    KAKUSIANA_7_3,

    KAKUSIANA_8,
    KAKUSIANA_8_1,
    KAKUSIANA_8_2,
    KAKUSIANA_8_3,

    KAKUSIANA_9,
    KAKUSIANA_9_1,
    KAKUSIANA_9_2,
    KAKUSIANA_9_3,

    KAKUSIANA_10,
    KAKUSIANA_10_1,
    KAKUSIANA_10_2,
    KAKUSIANA_10_3,

    KAKUSIANA_11,
    KAKUSIANA_11_1,
    KAKUSIANA_11_2,
    KAKUSIANA_11_3,

    KAKUSIANA_12,
    KAKUSIANA_12_1,
    KAKUSIANA_12_2,
    KAKUSIANA_12_3,

    LABO_1,
    LABO_1_1,
    LABO_1_2,
    LABO_1_3,

    HAKADAN_CH_1,
    HAKADAN_CH_1_1,
    HAKADAN_CH_1_2,
    HAKADAN_CH_1_3,

    SOUKO_1,
    SOUKO_1_1,
    SOUKO_1_2,
    SOUKO_1_3,

    SPOT20_10,
    SPOT20_10_1,
    SPOT20_10_2,
    SPOT20_10_3,

    ICE_DOUKUTU_1,
    ICE_DOUKUTU_1_1,
    ICE_DOUKUTU_1_2,
    ICE_DOUKUTU_1_3,

    SPOT01_15,
    SPOT01_15_1,
    SPOT01_15_2,
    SPOT01_15_3,

    SPOT10_9,
    SPOT10_9_1,
    SPOT10_9_2,
    SPOT10_9_3,

    SOUKO_2,
    SOUKO_2_1,
    SOUKO_2_2,
    SOUKO_2_3,

    SPOT04_12,
    SPOT04_12_1,
    SPOT04_12_2,
    SPOT04_12_3,

    JYASINZOU_BOSS_2,
    JYASINZOU_BOSS_2_1,
    JYASINZOU_BOSS_2_2,
    JYASINZOU_BOSS_2_3,

    NAKANIWA_1,
    NAKANIWA_1_1,
    NAKANIWA_1_2,
    NAKANIWA_1_3,

    TOKINOMA_7,
    TOKINOMA_7_1,
    TOKINOMA_7_2,
    TOKINOMA_7_3,

    SPOT12_18,
    SPOT12_18_1,
    SPOT12_18_2,
    SPOT12_18_3,

    KAKUSIANA_13,
    KAKUSIANA_13_1,
    KAKUSIANA_13_2,
    KAKUSIANA_13_3,

    SPOT05_2,
    SPOT05_2_1,
    SPOT05_2_2,
    SPOT05_2_3,

    SPOT06_8,
    SPOT06_8_1,
    SPOT06_8_2,
    SPOT06_8_3,

    SPOT05_3,
    SPOT05_3_1,
    SPOT05_3_2,
    SPOT05_3_3,

    SPOT06_9,
    SPOT06_9_1,
    SPOT06_9_2,
    SPOT06_9_3,

    SPOT11_8,
    SPOT11_8_1,
    SPOT11_8_2,
    SPOT11_8_3
};

#endif
