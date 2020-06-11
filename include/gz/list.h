/* list.h
 * originally developed by glank
 * /
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <ultra64.h>
#include <global.h>

typedef struct {
    long long __ll;
    long double __ld;
} max_align_t;

typedef struct List
{
    size_t elementSize;
    size_t size;
    void* first;
    void* last;
} List;

void List_Init(List* list, size_t elementSize);
void* List_Prev(const void* element);
void* List_Next(const void* element);
void* List_PrevIn(const List* list, const void* element);
void* List_NextIn(const List* list, const void* element);
void* List_At(const List* list, size_t position);
void* List_InsertSize(List* list, void* element, size_t size, const void* data);
void List_Transfer(List* dest, void* position, List* src, void* element);
void List_Splice(List* dest, List* src);
void* List_Insert(List* list, void* element, const void* data);
void* List_InsertAfterSize(List* list, void* element, size_t size, const void* data);
void* List_InsertAfter(List* list, void* element, const void* data);
void* List_PushBackSize(List* list, size_t size, const void* data);
void* List_PushBack(List* list, const void* data);
void List_Erase(List* list, void* element);
void List_Destroy(List* list);
#endif