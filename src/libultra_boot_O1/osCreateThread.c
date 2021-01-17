#include "global.h"

OSThread* __osThreadTail[2] = { NULL, (OSThread*)-1 };
OSThread* __osRunQueue = (OSThread *)__osThreadTail;
OSThread* __osActiveQueue = (OSThread *)__osThreadTail;
OSThread* __osRunningThread = NULL;
OSThread* __osFaultedThread = NULL;

void osCreateThread(OSThread* thread, OSId id, void (*entry)(void*), void* arg, void* sp, OSPri pri) {
    register u32 saveMask;
    OSIntMask mask;

    thread->id = id;
    thread->priority = pri;
    thread->next = NULL;
    thread->queue = NULL;
    thread->context.pc = entry;
    thread->context.a0 = arg;
    thread->context.sp = (u64)sp - 16;
    thread->context.ra = __osCleanupThread;
    mask = OS_IM_ALL;
    thread->context.sr = (mask & OS_IM_CPU) | SR_EXL;
    thread->context.rcp = (mask & RCP_IMASK) >> RCP_IMASKSHIFT;
    thread->context.fpcsr = FPCSR_FS | FPCSR_EV;
    thread->fp = 0;
    thread->state = OS_STATE_STOPPED;
    thread->flags = 0;

    saveMask = __osDisableInt();
    thread->tlnext = __osActiveQueue;
    __osActiveQueue = thread;
    __osRestoreInt(saveMask);
}
