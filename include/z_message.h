#ifndef INCLUDE_Z_MESSAGE_H
#define INCLUDE_Z_MESSAGE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <ultra64/types.h>

typedef struct {
    u16 msgNum;
    u8 msgTp;
    u16* msgAdd;
} MSG_T;

typedef struct {
    u16 msgNum;
    u8 msgTp;
    u8* msgAdd;
} MSG_NT;

typedef struct {
    u8* msgAdd;
} MSG_PT;

/* Message Return value */
enum {
    MSG_NULL,    /* 0: Message Null */
    MSG_NEXT,    /* 1: There is the following message */
    MSG_END,     /* 2: End of message */
    MSG_DRAW,    /* 3: Message output */
    MSG_SELECT,  /* 4: Select */
    MSG_ENEMY,   /* 5: Enemy control */
    MSG_DPEND,   /* 6: Message output end */
    MSG_OCA00,   /* 7: Ocarina automatic performance end */
    MSG_OCA10,   /* 8: Ocarina playing correct answer */
    MSG_OCA20,   /* 9: Ocarina playing error */
    MSG_KEYWAIT, /*10: Wait for line feed */
    MSG_POINT
};





#endif
