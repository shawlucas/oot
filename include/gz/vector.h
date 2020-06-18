/* vector.h
 * -glank
 */

#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stddef.h>

typedef struct Vector
{
    size_t elementSize, size, capacity;
    void* begin, *end;
    void* rbegin, *rend;
} Vector;

void Vector_Init(Vector* vector, size_t elementSize);
void* Vector_At(const Vector* vector, size_t position);
s32 Vector_Reserve(Vector* vector, size_t num);
void* Vector_Insert(Vector* vector, size_t position, size_t num, const void* data);
void* Vector_PushBack(Vector* vector, size_t num, const void* data);
s32 Vector_Erase(Vector* vector, size_t position, size_t num);
s32 Vector_ShrinkToFit(Vector* vector);
void* Vector_Release(Vector* vector);
void Vector_Clear(Vector* vector);
void Vector_Destroy(Vector* vector);

#endif