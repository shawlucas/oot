#ifndef __U64TYPES_H_
#define __U64TYPES_H_

#include <ultra64.h>

typedef u32 segptr_t;

typedef struct rgba_s {
    unsigned char r, g, b, a;	/* 赤、緑、青、α */
} rgba_t;

#pragma pack(4)
typedef struct rgba8888_s {
    /*
     * メトロワークスのコンパイラでは
     * なぜか unsigned int :8 が
     * unsigned char になってしまう。
     */
//    unsigned int r:8, g:8, b:8, a:8;	/* 赤、緑、青、α */
    u8 r, g, b, a;	/* 赤、緑、青、α */
} rgba8888_t;

typedef union rgba8888_u {
    u32 	rgba8888;
    rgba8888_t  c;
} rgba8888_u_t;

typedef rgba8888_u_t rgba8888;
/* ＲＧＢＡ値をそれぞれ設定 */
#define rgba8888_setColorRGBA(p1, r1, g1, b1, a1) \
((p1)->rgba8888 = (u32)(((u8)(r1) << 24) | \
			((u8)(g1) << 16) | \
			((u8)(b1) << 8) | \
			((u8)(a1) << 0)))
    /* Ｒ値を設定 */
#define rgba8888_setColorR(p1, r1) \
    ((p1)->c.r = (r1))
    /* Ｇ値を設定 */
#define rgba8888_setColorG(p1, g1) \
    ((p1)->c.g = (g1))
    /* Ｂ値を設定 */
#define rgba8888_setColorB(p1, b1) \
    ((p1)->c.b = (b1))
    /* Ａ値を設定 */
#define rgba8888_setColorA(p1, a1) \
    ((p1)->c.a = (a1))
    /* RGBA8888形式で値を設定 */
#define rgba8888_setColor32(p1, c1) \
    ((p1)->rgba8888 = (c1))

    /* Ｒ値を取得 */
#define rgba8888_getColorR(p1) \
    ((p1)->c.r)
    /* Ｇ値を取得 */
#define rgba8888_getColorG(p1) \
    ((p1)->c.g)
    /* Ｂ値を取得 */
#define rgba8888_getColorB(p1) \
    ((p1)->c.b)
    /* Ａ値を取得 */
#define rgba8888_getColorA(p1) \
    ((p1)->c.a)
    /* RGBA8888形式で値を取得 */
#define rgba8888_getColor32(p1) \
    ((p1)->rgba8888)

#pragma pack(2)
typedef struct rgba5551_s {
    unsigned int r:5, g:5, b:5, a:1;	/* 赤、緑、青、α */
} rgba5551_t;

typedef union rgba5551_u {
    u16 	rgba5551;
    rgba5551_t  c;
} rgba5551_u_t;

#pragma pack(2)
typedef struct ia88_s {
    unsigned int i:8, a:8;	/* 輝度、α */
} ia88_t;
typedef union ia88_u {
    u16 		ia88;
    ia88_t  	c;
} ia88_u_t;

#pragma pack(1)
typedef struct ia44_s {
    unsigned int i:4, a:4;	/* 輝度、α */
} ia44_t;
typedef union ia44_u {
    u8 		ia44;
    ia44_t  	c;
} ia44_u_t;
#pragma pack(0)

#endif
