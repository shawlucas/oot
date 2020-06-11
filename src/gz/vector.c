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
}