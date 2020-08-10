#ifndef _SCHED_H
#define _SCHED_H

#include <ultra64.h>

typedef struct {
    /* 0x00 */ s16 type;
    /* 0x02 */ char  misc[0x1E];
} OSScMsg; // size = 0x20

#endif
