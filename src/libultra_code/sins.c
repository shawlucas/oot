#include "sintable.h"

s16 sins(u16 angle) {
    s16 value;
    angle >>= 4;
    
    value = (angle & 0x400) ? sintable[0x3FF - (angle & 0x3FF)] : sintable[angle & 0x3FF];
    
    if (angle & 0x800) {
        return -value;
    }
    return value;
}
