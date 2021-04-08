#include <global.h>

u8 is_nan(f32 f) {
    u32 expMask = 0x7F800000;
    u32 sigMask = 0x7FFFFF;

    union {
        u32 w;
        f32 f;
    } pun;

    pun.f = f;

    return (pun.w & expMask) == expMask && (pun.w & sigMask) != 0;
}

u8 isInteger(f32 val) {
    s32 truncated = (s32)val;
    return (val == truncated);
}
