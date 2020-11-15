#ifndef _Z_EN_DNT_NOMAL_H_
#define _Z_EN_DNT_NOMAL_H_

#include "ultra64.h"
#include "global.h"

struct EnDntNomal;

typedef void (*EnDntNomalActionFunc)(struct EnDntNomal*, GlobalContext*);

typedef struct EnDntNomal {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s limbDrawTable[11];
    /* 0x01D2 */ Vec3s transitionDrawTable[11];
    /* 0x0214 */ EnDntNomalActionFunc actionFunc;
    /* 0x0218 */ u8 unk_218;
    /* 0x021C */ Vec3f pos;
    /* 0x0228 */ Vec3f upLeftTranslation;
    /* 0x0234 */ Vec3f downLeftTranslation;
    /* 0x0240 */ Vec3f downRightTranslation;
    /* 0x024C */ Vec3f upRightTranslation;
    /* 0x0258 */ s16 csTimer;
    /* 0x025A */ s16 idleTimer;
    /* 0x025C */ s16 timer;
    /* 0x025E */ s16 sfxTimer;
    /* 0x0260 */ s16 blinkTimer;
    /* 0x0262 */ s16 limbTimer;
    /* 0x0264 */ s16 randomTimer;
    /* 0x0266 */ s16 objBankIndex;
    /* 0x0268 */ s16 unk_268;
    /* 0x026A */ s16 index;
    /* 0x026C */ s16 unk_26C;
    /* 0x026E */ s16 unk_26E;
    /* 0x0270 */ s16 mode;
    /* 0x0272 */ s16 unk_272;
    /* 0x0274 */ s16 unk_274;
    /* 0x0278 */ u8 sfxFlag;
    /* 0x0279 */ u8 unk_270;
    /* 0x027A */ u8 headDekuSearchFlag;
    /* 0x027B */ s8 changeBankId;
    /* 0x027C */ Vec3f shapePos;
    /* 0x0288 */ Vec3f vec_288;
    /* 0x0294 */ char unk_294[0xCC];
} EnDntNomal; // size = 0x0360

extern const ActorInit En_Dnt_Nomal_InitVars;

#endif
