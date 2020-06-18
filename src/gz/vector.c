/* vector.c
 * -glank
 */

#include <ultra64.h>
#include <global.h>
#include <gz/vector.h>

void Vector_Init(Vector* vector, size_t elementSize)
{
    vector->elementSize = elementSize;
    vector->size = 0;
    vector->capacity = 0;
    vector->begin = 0;
    vector->end = 0;
    vector->rbegin = 0;
    vector->rend = 0;
}

void* Vector_At(const Vector* vector, size_t position)
{
    if (!vector->begin || position >= vector->size)
        return 0;
    return (char*)vector->begin + vector->elementSize * position;
}

s32 Vector_Reserve(Vector* vector, size_t num)
{
    char* newData;
    size_t newCap = vector->size + num;
    if (newCap <= vector->capacity)
        return 1;
    newData = (char *)ZeldaArena_ReallocDebug(vector->begin, vector->elementSize * newCap, "../vector.c", 34);
    if (!newData)
        return 0;
    vector->begin = newData;
    vector->rend = newData - vector->elementSize;
    vector->end = (char *)vector->begin + vector->elementSize * vector->size;
    vector->rbegin = (char *)vector->end - vector->elementSize;
    vector->capacity = newCap;
    return 1;
}

void* Vector_Insert(Vector* vector, size_t position, size_t num, const void* data)
{
    size_t newCap;
    char* newData;
    if (num == 0)
    {
        if (vector->begin)
            return vector->begin;
        else
            return (void *)1;
    }

    if (position > vector->size)
        return 0;
    newCap = vector->capacity;
    if (newCap == 0)
        newCap = num;
    else {
        if (newCap < vector->size + num)
            newCap *= 2;
        if (newCap < vector->size + num)
            newCap = vector->size + num;
    }
    if (newCap != vector->capacity) {
        newData = ZeldaArena_ReallocDebug(vector->begin, 
                                        vector->elementSize * newCap, "../vector.c", 69);
        if (!newData)
            return 0;
        vector->begin = newData;
        vector->rend = newData - vector->elementSize;
        vector->capacity = newCap;
    }
    memcpy((char*)vector->begin + vector->elementSize * (position + num),
           (char*)vector->begin + vector->elementSize * position,
            vector->elementSize * (vector->size - position));
    if (data)
        memcpy((char*)vector->begin + vector->elementSize * position, data,
                vector->elementSize * num);
    vector->size += num;
    vector->end = (char*)vector->begin + vector->elementSize * vector->size;
    vector->rbegin = (char*)vector->end - vector->elementSize;
    return (char*)vector->begin + vector->elementSize * position;   
}

void* Vector_PushBack(Vector* vector, size_t num, const void* data)
{
    return Vector_Insert(vector, vector->size, num, data);
}

s32 Vector_Erase(Vector* vector, size_t position, size_t num)
{
    if (!vector->begin || num > vector->size || position >= vector->size)
        return 0;
    if (num == vector->size) {
        Vector_Clear(vector);
        return 1;
    }

    memcpy((char*)vector->begin + vector->elementSize * position, 
            (char*)vector->begin + vector->elementSize * (position + num),
            vector->elementSize * (vector->size - position - num));
    vector->size -= num;
    vector->end = (char*)vector->begin + vector->elementSize * vector->size;
    vector->rbegin = (char*)vector->end - vector->elementSize;
    return 1;
}

s32 Vector_ShrinkToFit(Vector* vector)
{
    size_t newCap = vector->size;
    char* newData = (char*)ZeldaArena_ReallocDebug(vector->begin, vector->elementSize * newCap,
                          "../vector.c", 115);
    return 1;
}

void* Vector_Release(Vector* vector)
{
    void* data = vector->begin;
    vector->size = 0;
    vector->capacity = 0;
    vector->begin = 0;
    vector->end = 0;
    vector->rbegin = 0;
    vector->rend = 0;
    return data;
}

void Vector_Clear(Vector* vector)
{
    vector->size = 0;
    vector->end = vector->begin;
    vector->rbegin = vector->begin;
    vector->rend = vector->begin;
}

void Vector_Destroy(Vector* vector)
{
    if (vector->begin)
    {
        ZeldaArena_FreeDebug(vector->begin, "../vector.c", 144);
    }
}
