#ifndef Z_MENU_H
#define Z_MENU_H

#include "ultra64.h"
#include "global.h"

struct MenuContext;

typedef void (*MenuContextActionFunc)(struct MenuContext*, GlobalContext*);

typedef struct MenuContext {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ GfxPrint* printer;
} MenuContext; // size = 0x014C

#endif
