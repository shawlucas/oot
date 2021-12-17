#include "global.h"

void GameAlloc_Log(GameAlloc* this) {
    GameAllocEntry* iter;

    osSyncPrintf("this = %08X\n", this);

    iter = this->base.next;
    while (iter != &this->base) {
        osSyncPrintf("ptr = %08X size = %d\n", iter, iter->size);
        iter = iter->next;
    }
}

void* GameAlloc_MallocDebug(GameAlloc* this, u32 size, const char* file, s32 line) {
    GameAllocEntry* ptr = SystemArena_MallocDebug(size + sizeof(GameAllocEntry), file, line);

    if (ptr != NULL) {
        ptr->size = size;
        ptr->prev = this->head;
        this->head->next = ptr;
        this->head = ptr;
        ptr->next = &this->base;
        this->base.prev = this->head;
        return ptr + 1;
    } else {
        return NULL;
    }
}

void* GameAlloc_Malloc(GameAlloc* this, u32 size) {
    GameAllocEntry* ptr = SystemArena_MallocDebug(size + sizeof(GameAllocEntry), "../gamealloc.c", __LINE__);

    if (ptr != NULL) {
        ptr->size = size;
        ptr->prev = this->head;
        this->head->next = ptr;
        this->head = ptr;
        ptr->next = &this->base;
        this->base.prev = this->head;
        return ptr + 1;
    } else {
        return NULL;
    }
}

void GameAlloc_Free(GameAlloc* this, void* data) {
    GameAllocEntry* ptr;

    if (data != NULL) {
        ptr = &((GameAllocEntry*)data)[-1];
        LogUtils_CheckNullPointer("ptr->prev", ptr->prev, "../gamealloc.c", __LINE__);
        LogUtils_CheckNullPointer("ptr->next", ptr->next, "../gamealloc.c", __LINE__);
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        this->head = this->base.prev;
        SystemArena_FreeDebug(ptr, "../gamealloc.c", __LINE__);
    }
}

void GameAlloc_Cleanup(GameAlloc* this) {
    GameAllocEntry* next = this->base.next;
    GameAllocEntry* cur;

    while (&this->base != next) {
        cur = next;
        next = next->next;
        SystemArena_FreeDebug(cur, "../gamealloc.c", __LINE__);
    }

    this->head = &this->base;
    this->base.next = &this->base;
    this->base.prev = &this->base;
}

void GameAlloc_Init(GameAlloc* this) {
    this->head = &this->base;
    this->base.next = &this->base;
    this->base.prev = &this->base;
}
