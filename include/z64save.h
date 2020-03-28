#include <ultra64.h>
#include <global.h>

typedef struct {
    char unk_00[0xC0];
} NewFileSaveData;

typedef struct {
    char unk_00[0xC];
} InitialSaveData;

typedef struct {
    char unk_00[0xB8];
} TitleSaveData;

typedef struct {

    /* 0x0000 */ u16 fileOffsets[0x0006];
    /* 0x000C */ InitialSaveData initial;
    /* 0x0018 */ NewFileSaveData nf;
    /* 0x00D8 */ TitleSaveData tf;
    /* 0x0190 */ u16 unk_190[16]; // something to do with savwarp or death;
} DefaultFileCreation;