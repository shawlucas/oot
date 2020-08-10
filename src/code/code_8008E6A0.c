#include <global.h>

void func_8008E6A0(Pause* this) {
    this->counter = 0;
    this->toggle = false;
}

u32 func_8008E6AC(Pause* this, Input* input) {
    if (CHECK_PAD(input->cur, R_TRIG) && CHECK_PAD(input->press, D_JPAD)) {
        this->toggle = !this->toggle;
    }
    if (!this->toggle) {
        goto ret_true;
    }

    if (CHECK_PAD(input->cur, Z_TRIG)) {

        if (CHECK_PAD(input->press, R_TRIG)) {
            goto ret_true;
        }

        if (CHECK_PAD(input->cur, R_TRIG)) {
            this->counter++;
            if (this->counter >= 9) {
                goto ret_true;
            }
        }
    }

    goto ret_false;

ret_true:
    this->counter = 0;
    return true;

ret_false:
    return false;
}
