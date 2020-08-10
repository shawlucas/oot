#ifndef __TWOHEADARENA_H_
#define __TWOHEADARENA_H_

#include <ultra64.h>

typedef struct {
    /* 0x0000 */ u32    size;
    /* 0x0004 */ u8*    bufp;
    /* 0x0008 */ u8*    head;
    /* 0x000C */ u8*    tail;
} TwoHeadArena; // size = 0x10

#endif
