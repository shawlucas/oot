#include "global.h"

#define LOG_SEVERITY_NOLOG 0
#define LOG_SEVERITY_ERROR 2
#define LOG_SEVERITY_VERBOSE 3

Arena sDebugArena;

#if OOT_DEBUG
s32 gDebugArenaLogSeverity = LOG_SEVERITY_ERROR;

void DebugArena_CheckPointer(void* ptr, u32 size, const char* name, const char* action) {
    if (ptr == NULL) {
        if (gDebugArenaLogSeverity >= LOG_SEVERITY_ERROR) {
            // "%s: %u bytes %s failed\n"
            PRINTF("%s: %u bytes %s failed\n", name, size, action);
            __osDisplayArena(&sDebugArena);
            return;
        }
    } else if (gDebugArenaLogSeverity >= LOG_SEVERITY_VERBOSE) {
        // "%s: %u bytes %s succeeded\n"
        PRINTF("%s: %u bytes %s succeeded\n", name, size, action);
    }
}

#define DEBUG_ARENA_CHECK_POINTER(ptr, size, name, action) DebugArena_CheckPointer(ptr, size, name, action)
#else
#define DEBUG_ARENA_CHECK_POINTER(ptr, size, name, action) (void)0
#endif

void* DebugArena_Malloc(u32 size) {
    void* ptr = __osMalloc(&sDebugArena, size);

    DEBUG_ARENA_CHECK_POINTER(ptr, size, "DebugArena_Malloc", "Secure"); // "Secure"
    return ptr;
}

#if OOT_DEBUG
void* DebugArena_MallocDebug(u32 size, const char* file, int line) {
    void* ptr = __osMallocDebug(&sDebugArena, size, file, line);

    DEBUG_ARENA_CHECK_POINTER(ptr, size, "DebugArena_MallocDebug", "Secure"); // "Secure"
    return ptr;
}
#endif

void* DebugArena_MallocR(u32 size) {
    void* ptr = __osMallocR(&sDebugArena, size);

    DEBUG_ARENA_CHECK_POINTER(ptr, size, "DebugArena_MallocR", "Secure"); // "Secure"
    return ptr;
}

#if OOT_DEBUG
void* DebugArena_MallocRDebug(u32 size, const char* file, int line) {
    void* ptr = __osMallocRDebug(&sDebugArena, size, file, line);

    DEBUG_ARENA_CHECK_POINTER(ptr, size, "DebugArena_MallocRDebug", "Secure"); // "Secure"
    return ptr;
}
#endif

void* DebugArena_Realloc(void* ptr, u32 newSize) {
    ptr = __osRealloc(&sDebugArena, ptr, newSize);
    DEBUG_ARENA_CHECK_POINTER(ptr, newSize, "DebugArena_Realloc", "Re-securing"); // "Re-securing"
    return ptr;
}

#if OOT_DEBUG
void* DebugArena_ReallocDebug(void* ptr, u32 newSize, const char* file, int line) {
    ptr = __osReallocDebug(&sDebugArena, ptr, newSize, file, line);
    DEBUG_ARENA_CHECK_POINTER(ptr, newSize, "DebugArena_ReallocDebug", "Re-securing"); // "Re-securing"
    return ptr;
}
#endif

void DebugArena_Free(void* ptr) {
    __osFree(&sDebugArena, ptr);
}

#if OOT_DEBUG
void DebugArena_FreeDebug(void* ptr, const char* file, int line) {
    __osFreeDebug(&sDebugArena, ptr, file, line);
}
#endif

void* DebugArena_Calloc(u32 num, u32 size) {
    void* ret;
    u32 n = num * size;

    ret = __osMalloc(&sDebugArena, n);
    if (ret != NULL) {
        bzero(ret, n);
    }

    DEBUG_ARENA_CHECK_POINTER(ret, n, "DebugArena_Calloc", "Secure");
    return ret;
}

#if OOT_DEBUG
void DebugArena_Display(void) {
    // "Zelda heap display" ("Zelda" should probably have been changed to "Debug")
    PRINTF("Debug heap display\n");
    __osDisplayArena(&sDebugArena);
}
#endif

void DebugArena_GetSizes(u32* outMaxFree, u32* outFree, u32* outAlloc) {
    ArenaImpl_GetSizes(&sDebugArena, outMaxFree, outFree, outAlloc);
}

void DebugArena_Check(void) {
    __osCheckArena(&sDebugArena);
}

void DebugArena_Init(void* start, u32 size) {
#if OOT_DEBUG
    gDebugArenaLogSeverity = LOG_SEVERITY_NOLOG;
#endif
    __osMallocInit(&sDebugArena, start, size);
}

void DebugArena_Cleanup(void) {
#if OOT_DEBUG
    gDebugArenaLogSeverity = LOG_SEVERITY_NOLOG;
#endif
    __osMallocCleanup(&sDebugArena);
}

u8 DebugArena_IsInitialized(void) {
    return __osMallocIsInitialized(&sDebugArena);
}
