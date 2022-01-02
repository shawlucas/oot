#ifndef _Z64MENU_H_
#define _Z64MENU_H_

#include "ultra64.h"

typedef enum {
    /* -1 */ POS_NULL = -1,
    /* 0 */  POS_RET
} CursorPos;

#define MENU_MAX 2
#define ENTRYCNT_TOP 1
#define ENTRYCNT_WARPS 1

typedef struct Menu {
    const char* name;
    s32 submenuCnt;
    s32 entryCnt;
} Menu;

typedef struct MenuSystem {
    s32 cursorPos;
    s32 curEntryCnt;
} MenuSystem;


#endif
