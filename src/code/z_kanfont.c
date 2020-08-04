#include <ultra64.h>
#include <global.h>

extern u8 D_070380D4[];
extern u8 link_animetion_segment[];
extern u8 D_0703811C[];

void Kanfont_GetNES(Kanfont* kanfont, u8 code, u16 addr) {
    DmaMgr_SendRequest1(&kanfont->kbuffer[addr], (code << 7) + _nes_font_staticSegmentRomStart, 128, "../z_kanfont.c", 93);
}

void Kanfont_Get2(Kanfont* kanfont, u16 code) {
    DmaMgr_SendRequest1(&kanfont->kbuffer2[0], (u32)_message_staticSegmentRomStart+(((128*64)/2)*4)+(((16*16)/2)*code), 128, "../z_kanfont.c", 100);
}

void Kscope_KanfontGet(Kanfont* kanfont) {
    s32 i, j, jj, m;
    u8 *msg_data1, *msg_data2, *msg_data3;
    u16* mb;

    msg_data2 = (u8 *)link_animetion_segment;
    msg_data1 = (u8 *)D_070380D4;
    msg_data3 = (u8 *)D_0703811C;
    
    kanfont->msg_data = (u8 *)(msg_data1 - msg_data2);
    kanfont->msg_data0 = (u8 *)(msg_data3 - msg_data1);

    jj = (u32)kanfont->msg_data0;

    DmaMgr_SendRequest1(&kanfont->mbuff.nes_mes_buf[0], (u32)_nes_message_data_staticSegmentRomStart+(u32)kanfont->msg_data, (u32)kanfont->msg_data0, "../z_kanfont.c", 122);
    osSyncPrintf("msg_data=%x,  msg_data0=%x   jj=%x\n",kanfont->msg_data, kanfont->msg_data0, jj);
    i = j = 0;
    while (kanfont->mbuff.nes_mes_buf[i] != 2) {
        if (i > jj) {
            osSyncPrintf("ＥＲＲＯＲ！！  エラー！！！  error───！！！！\n");
            break;
        }
        if (kanfont->mbuff.nes_mes_buf[i] != 1) {
            osSyncPrintf("nes_mes_buf[%d]=%d\n",i,kanfont->mbuff.nes_mes_buf[i]);
            m = ((s32)kanfont->mbuff.nes_mes_buf[i] - 0x20) * 128;
            DmaMgr_SendRequest1(&kanfont->kbuffer4[j], (u32)_nes_font_staticSegmentRomStart+(u32)m, 128, "../z_kanfont.c", 134);
            j += Buf_Ct;
        }
        i++;
    }
}
