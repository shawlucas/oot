#ifndef _MATH_H_
#define _MATH_H_

#include "ultra64/types.h"

#define FVAL_LOG10 2.3025850929940456790f
#define FVAL_LOG2   0.6931471805599453094172321F
#define M_PI 3.14159265358979323846f
#define M_SQRT2 1.41421356237309504880f
#define FLT_MAX 340282346638528859811704183484516925440.0f
#define SHT_MAX 32767.0f
#define SHT_MINV (1.0f / SHT_MAX)
#define DEGTORAD(x) (x * M_PI / 180.0f)

typedef union {
    struct {
        u32 hi;
        u32 lo;
    } word;

    f64 d;
} du;
typedef  union {
        struct {
                unsigned  sign  :1;
                unsigned  exp   :11;
                unsigned  hi    :20;
                unsigned  lo    :32;
        } fparts;
        struct {
                unsigned  sign  :1;
                unsigned  exp   :11;
                unsigned  qnan_bit      :1;
                unsigned  hi    :19;
                unsigned  lo    :32;
        } nparts;
        struct {
                unsigned hi;
                unsigned lo;
        } fwords;
        double  d;
} _dval;

typedef union {
    u32 i;
    f32 f;
} fu;

f32 log10f(f32 x);

extern f32 __libm_qnan_f;

#define SIGNBIT(X) (((_dval *)&(X))->fparts.sign)

#endif
