/* list.c
 * originally developed by glank
 */

#include <ultra64.h>
#include <global.h>
#include "list.h"

#define MAX_ALIGN(N) (((N) + _Alignof(max_align_t) - 1) & \
                      ~(_Alignof(max_align_t) - 1))
#define ELEMENT_HEADER_SIZE (MAX_ALIGN(sizeof(struct ListAlloc)))

void List_Init(List* list, size_t elementSize)
{
    list->elementSize = elementSize;
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

void* List_Prev(const void* element)
{
    const struct ListAlloc* header =(const struct ListAlloc*)((const char*)element - ELEMENT_HEADER_SIZE);

    if (header->prev)
        return (char *)header->prev + ELEMENT_HEADER_SIZE;
    else
        return NULL;
}

void* List_Next(const void* element)
{
    const struct ListAlloc* header = (const struct ListAlloc*)((const char*)element - ELEMENT_HEADER_SIZE);

    if (header->next)
        return (char *)header->next + ELEMENT_HEADER_SIZE;
    else
        return NULL;
}

void* List_PrevIn(const List* list, const void* element)
{
    if (!element)
        return list->last;
    return List_Prev(element);
}

void* List_NextIn(const List* list, const void* element)
{
    if (!element)
        return list->first;
    return List_Next(element);
}

void* List_At(const List* list, size_t position)
{
    size_t i;
    if (list->size == 0)
        return NULL;
    struct ListAlloc* header = (struct ListAlloc*)((char*)list->first - ELEMENT_HEADER_SIZE);

    for (i = 0; i < position; ++i)
    {
        if (header->next)
            header = header->next;
        else
            return NULL;
    }
    return (char*)header + ELEMENT_HEADER_SIZE;
}

void* List_InsertSize(List* list, void* element, size_t size, const void* data)
{
    void* newData;
    struct ListAlloc* header;
    struct ListAlloc* newHeader = (struct ListAlloc*)ZeldaArena_MallocDebug(ELEMENT_HEADER_SIZE + size, "../list.c", 74);
    
    if (!newHeader)
        return NULL;
    newData = (char *)newHeader + ELEMENT_HEADER_SIZE;
    if (data)
        memcpy(newData, data, size);
    if (element)
    {
        header = (struct ListAlloc*)((char *)element - ELEMENT_HEADER_SIZE);
        newHeader->prev = header->prev;
        newHeader->next = header;
        if (header->prev)
            header->prev->next = newHeader;
        header->prev = newHeader;
        if (element == list->first)
            list->first = newData;
    }
    else {
        if (list->size == 0)
        {
            newHeader->prev = NULL;
            list->first = newData;
        } else {
            newHeader->prev = (struct ListAlloc*)((char *)list->last - ELEMENT_HEADER_SIZE);
            newHeader->prev->next = newHeader;
        }
        newHeader->next = NULL;
        list->last = newData;
    }
    ++list->size;
    return newData;

}

void List_Transfer(List* dest, void* position, List* src, void* element)
{
    struct ListAlloc* pHeader;
    struct ListAlloc* eHeader = (struct ListAlloc*)((char *)element - ELEMENT_HEADER_SIZE);

    if (element == src->first)
    {
        if (eHeader->next)
        {
            src->first = (void*)((char *)eHeader->next + ELEMENT_HEADER_SIZE);
        } else {
            src->first = NULL;
        }
    }

    if (element == src->last)
    {
        if (eHeader->prev)
            src->last = (void*)((char*)eHeader->prev + ELEMENT_HEADER_SIZE);
        else
            src->last = NULL;
    }

    if (eHeader->prev)
        eHeader->prev->next = eHeader->next;
    if (eHeader->next)
        eHeader->next->prev = eHeader->prev;
    if (position)
    {
        pHeader = (struct ListAlloc *)((char *)position - ELEMENT_HEADER_SIZE);
        eHeader->prev = pHeader->prev;
        eHeader->next = pHeader;

        if (pHeader->prev)
            pHeader->prev->next = eHeader;
        pHeader->prev = eHeader;
        if (position == dest->first)
            dest->first = element;
    }

    else {
        if (dest->size == 0) {
            eHeader->prev = NULL;
            dest->first = element;
        } else {
            eHeader->prev = (struct ListAlloc*)((char *)dest->last - ELEMENT_HEADER_SIZE);
            eHeader->prev->next = eHeader;
        }
        eHeader->next = NULL;
        dest->last = element;
    }

    --src->size;
    ++dest->size;
}

void List_Splice(List* dest, List* src)
{
    struct ListAlloc* fHeader;
    struct ListAlloc* lHeader;
    if (!src->first)
        return;
    dest->size += src->size;
    if (dest->last)
    {
        fHeader = (struct ListAlloc*)((char *)src->first - ELEMENT_HEADER_SIZE);
        lHeader = (struct ListAlloc*)((char *)dest->last - ELEMENT_HEADER_SIZE);
        fHeader->prev = lHeader;
        lHeader->next = fHeader;
    } else 
        dest->first = src->first;
    dest->last = src->last;
    src->first = NULL;
    src->last = NULL;
    src->size = 0;
}

void* List_Insert(List* list, void* element, const void* data)
{
    return List_InsertSize(list, element, list->elementSize, data);
}

void* List_InsertAfterSize(List* list, void* element, size_t size, const void* data)
{
    return List_InsertSize(list, List_NextIn(list, element), size, data);
}

void* List_InsertAfter(List* list, void* element, const void* data)
{
    return List_InsertSize(list, List_NextIn(list, element), list->elementSize, data);
}

void* List_PushBackSize(List* list, size_t size, const void* data)
{
    return List_InsertSize(list, NULL, size, data);
}

void* List_PushBack(List* list, const void* data)
{
    return List_InsertSize(list, NULL, list->elementSize, data);
}

void List_Erase(List* list, void* element)
{
    struct ListAlloc* header = (struct ListAlloc*)((char *)element - ELEMENT_HEADER_SIZE);

    if (element == list->first)
    {
        if (header->next)
            list->first = (void*)((char*)header->next + ELEMENT_HEADER_SIZE);
        if (element == list->first)
        {
            if (header->next)
                list->first = (void *)((char *)header->next + ELEMENT_HEADER_SIZE);
            else
                list->first = NULL;
        }
    }
        if (header->prev)
            header->prev->next = header->next;
        if (header->next)
            header->next->prev = header->prev;
        ListAlloc_FreeAll(header);
        --list->size;
}

void List_Destroy(List* list)
{
    struct ListAlloc* nextHeader;
    struct ListAlloc* header = NULL;
    if (list->first)
        header = (struct ListAlloc*)((char*)list->first - ELEMENT_HEADER_SIZE);
    
    while (header)
    {
        nextHeader = header->next;
        ListAlloc_FreeAll(header);
        header = nextHeader;
    }
}
