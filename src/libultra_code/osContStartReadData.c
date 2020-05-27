#include <ultra64.h>
#include <global.h>

#include <ultra64/controller.h>

s32 osContStartReadData(OSMesgQueue* mq) {
    s32 ret;
    __osSiGetAccess(); // __osSiGetAccess
    if (__osContLastPollType != 1) {
        __osPackReadData();
        __osSiRawStartDma(OS_WRITE, &_osPifInternalBuff);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    }
    ret = __osSiRawStartDma(OS_READ, &_osPifInternalBuff);
    __osContLastPollType = 1;
    __osSiRelAccess();
    return ret;
}

void osContGetReadData(OSContPad* pad) {
    PIF_IO_slot_t* slot_ptr;
    PIF_IO_slot_t slot;
    s32 i;
    slot_ptr = _osPifInternalBuff.slots;
    for (i = 0; i < __osMaxControllers; i++, slot_ptr++, pad++) {
        slot = *slot_ptr;
        pad->errno = (slot.hdr.status_hi_bytes_rec_lo & 0xc0) >> 4;
        if (pad->errno == 0) {
            pad->button = slot.input.button;
            pad->stick_x = slot.input.x;
            pad->stick_y = slot.input.y;
        }
    };
}

void __osPackReadData() {
    PIF_IO_slot_t* slot_ptr;
    PIF_IO_slot_t slot;
    s32 i;
    slot_ptr = _osPifInternalBuff.slots;
    for (i = 0; i < 0xF; i++) {
        _osPifInternalBuff.words[i] = 0;
    }
    _osPifInternalBuff.status_control = 1;
    slot.hdr.slot_type = 0xFF;
    slot.hdr.bytes_send = 1;
    slot.hdr.status_hi_bytes_rec_lo = 4;
    slot.hdr.command = 1;
    slot.input.button = 0xFFFF;
    slot.input.x = 0xFF;
    slot.input.y = 0xFF;
    for (i = 0; i < __osMaxControllers; i++) {
        *slot_ptr++ = slot;
    }
    slot_ptr->hdr.slot_type = 0xFE;
}
