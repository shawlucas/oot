#ifndef _GFX_H_
#define _GFX_H_

#include <ultra64.h>

typedef struct 
{
    u8 imageFormat;
    u8 imageSize;
    void* data;
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    s32 tsize;
} Texture;

typedef struct 
{
    Texture* texture;
    s16 charWidth;
    s16 charHeight;
    s16 charXtile;
    s16 charYtile;
    u8 codeStart;
    s16 letterSpacing;
    s16 lineSpacing;
    s16 baseline;
    s16 median;
    s16 x;
} Font;

#endif