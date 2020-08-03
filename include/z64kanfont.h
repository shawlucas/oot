#ifndef _Z64_KANFONT_H
#define _Z64_KANFONT_H

#include <ultra64.h>

#define BUF_CT 128
#define BUF_TOTAL BUF_CT * 30 * 4
#define Buf_Ct (128 / 8)

typedef struct zelda_kanfont_struct {
    unsigned char* msg_data;
    unsigned char* msg_data0;
    unsigned char kbuffer[BUF_TOTAL];
    unsigned char kbuffer2[BUF_CT];
    long long kbuffer4[Buf_Ct * 16 * 20];
    union buff {
        u16 message_buf[16 * 40];
        unsigned char nes_mes_buf[16 * 40];
    } mbuff;
} Kanfont;

#endif
