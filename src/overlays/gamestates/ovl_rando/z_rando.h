#ifndef __Z_RANDO_H_
#define __Z_RANDO_H_

#include "global.h"


typedef struct RandoContext {
    GameState state;
    View view;
} RandoContext;

extern void RandoContext_Init(GameState* thisx);
extern void RandoContext_Destroy(GameState* thisx);
extern void RandoContext_DrawTest(GameState* thisx);

#endif
