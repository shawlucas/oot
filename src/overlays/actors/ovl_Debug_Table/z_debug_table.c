#include "z_debug_table.h"

#define FLAGS 0x00000000

#define THIS ((DebugTable*)thisx)

void DebugTable_Init(Actor* thisx, GlobalContext* globalCtx);
void DebugTable_Destroy(Actor* thisx, GlobalContext* globalCtx);
void DebugTable_Update(Actor* thisx, GlobalContext* globalCtx);
void DebugTable_Draw(Actor* thisx, GlobalContext* globalCtx);

const ActorInit Debug_Table_InitVars = {
    ACTOR_DEBUG_TABLE,
    ACTORTYPE_MISC,
    FLAGS,
    0,
    sizeof(DebugTable),
    (ActorFunc)DebugTable_Init,
    (ActorFunc)DebugTable_Destroy,
    (ActorFunc)DebugTable_Update,
    (ActorFunc)DebugTable_Draw,
};

void DebugTable_Init(Actor* thisx, GlobalContext* globalCtx)
{
    DebugTable* this = THIS;
}

void DebugTable_Destroy(Actor* thisx, GlobalContext* globalCtx)
{
    DebugTable* this = THIS;
}

void DebugTable_Update(Actor* thisx, GlobalContext* globalCtx)
{
    DebugTable* this = THIS;
}

void DebugTable_Draw(Actor* thisx, GlobalContext* globalCtx)
{
    DebugTable* this = THIS;
}
