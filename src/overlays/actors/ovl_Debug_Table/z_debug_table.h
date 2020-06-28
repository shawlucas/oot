#ifndef _Z_DEBUG_TABLE_H_
#define _Z_DEBUG_TABLE_H_

#include <ultra64.h>
#include <global.h>

struct DebugTable;

typedef struct DebugTable {
    /* 0x0000 */ Actor actor;
} DebugTable; // size =

extern const ActorInit Debug_Table_InitVars;

#endif