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

#endif