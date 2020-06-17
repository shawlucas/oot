#include <ultra64.h>
#include <global.h>
#include <math.h>

#define ABS_ALT(d) ((d) > 0) ? (d) : -(d)

static const du P[] = {
    { 0x3FF00000, 0x00000000 }, { 0xBFC55554, 0xBC83656D }, { 0x3F8110ED, 0x3804C2A0 },
    { 0xBF29F6FF, 0xEEA56814 }, { 0x3EC5DBDF, 0x0E314BFE },
};

static const du rpi = { 0x3FD45F30, 0x6DC9C883 };

static const du pihi = { 0x400921FB, 0x50000000 };

static const du pilo = { 0x3E6110B4, 0x611A6263 };

static const fu zero = { 0x00000000 };

extern const f32 __libm_qnan_f;

f32 cosf(f32 angle) {
    f32 absx;
    f64 dx, xSquared, polyApprox;
    f64 dn;
    s32 n;
    f64 result;
    s32 ix, xpt;

    ix = *(s32*)&angle;
    xpt = (ix >> 22);
    xpt &= 0x1FF;

    if (xpt < 0x136) {
        absx = ABS_ALT(angle);
        dx = absx;
        dn = dx * rpi.d + 0.5;
        n = ROUND(dn);
        dn = n;

        dn -= 0.5;

        dx -= dn * pihi.d;
        dx -= dn * pilo.d;

        xSquared = SQ(dx);
        polyApprox = ((P[4].d * xSquared + P[3].d) * xSquared + P[2].d) * xSquared + P[1].d;
        result = dx + (dx * xSquared) * polyApprox;

        if (!(n & 1)) {
            return (f32)result;
        }
        return -(f32)result;
    }

    if (angle != angle) {
        return __libm_qnan_f;
    }

    return zero.f;
}