.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purposee registers

.section .rodata

glabel D_80A060B0
 .word 0x30000000
glabel D_80A060B4
    .asciz "../z_en_elf.c"
    .balign 4

glabel D_80A060C4
 .word 0x30000000
glabel D_80A060C8
    .asciz "../z_en_elf.c"
    .balign 4

glabel D_80A060D8
    .asciz "../z_en_elf.c"
    .balign 4

glabel D_80A060E8
    .asciz "z_common_data.memory.information.room_inf[127][ 0 ] = %d\n"
    .balign 4

glabel D_80A06124
    .asciz "../z_en_elf.c"
    .balign 4

glabel D_80A06134
    .asciz "../z_en_elf.c"
    .balign 4

glabel jtbl_80A06144
.word L80A01C60
.word func_80A01DE0
.word func_80A01E24
.word func_80A01E68
.word func_80A01E94
.word func_80A01ED0
.word func_80A01F04
.word func_80A01D70
.word func_80A01DA8
.word func_80A01D2C
.word func_80A01CF0
.word func_80A01F48
.word func_80A01CAC
glabel D_80A06178
 .word 0x46FFFE00
glabel D_80A0617C
 .word 0x46FFFE00
glabel D_80A06180
    .float 0.2
    .balign 4

glabel D_80A06184
 .word 0x3F733333
glabel D_80A06188
    .float 0.05
    .balign 4

glabel D_80A0618C
    .float 0.1
    .balign 4

glabel D_80A06190
 .word 0x46FFFE00
glabel jtbl_80A06194
.word L80A025C0
.word L80A02630
.word L80A02700
.word L80A027BC
.word L80A02804
.word L80A02694
.word L80A0270C
.word L80A026E8
glabel D_80A061B4
 .word 0x46FFFE00
glabel D_80A061B8
 .word 0x413FD70A
glabel D_80A061BC
    .float 0.2
    .balign 4

glabel D_80A061C0
    .float 0.01
    .balign 4

glabel D_80A061C4
    .float 0.3
    .balign 4

glabel D_80A061C8
    .float 0.05
    .balign 4

glabel D_80A061CC
    .float 0.008
    .balign 4

glabel D_80A061D0
    .float 0.1
    .balign 4

glabel D_80A061D4
    .float 1500.0
    .balign 4

glabel D_80A061D8
    .float 0.1
    .balign 4

glabel D_80A061DC
    .float 0.2
    .balign 4

glabel D_80A061E0
    .float 0.008
    .balign 4

glabel D_80A061E4
    .float 0.05
    .balign 4

glabel D_80A061E8
    .float 0.1
    .balign 4

glabel D_80A061EC
    .float 0.7
    .balign 4

glabel D_80A061F0
 .word 0x3EB33333
glabel D_80A061F4
 .word 0x3C4A4588
glabel D_80A061F8
    .float 0.008
    .balign 4

glabel D_80A061FC
 .word 0x3D088889
glabel D_80A06200
    .float 0.05
    .balign 4

glabel D_80A06204
    .float 0.008
    .balign 4

glabel D_80A06208
    .float 0.008
    .balign 4

glabel D_80A0620C
    .float 1500.0
    .balign 4

glabel D_80A06210
    .float 0.2
    .balign 4

glabel D_80A06214
    .float 1500.0
    .balign 4

glabel D_80A06218
    .float 0.2
    .balign 4

glabel D_80A0621C
    .float 0.2
    .balign 4

glabel D_80A06220
    .float 0.2
    .balign 4

glabel D_80A06224
 .word 0x38A7C5AD
glabel D_80A06228
    .float 0.2
    .balign 4

glabel D_80A0622C
 .word 0x38A7C5AD
glabel D_80A06230
    .float 0.1
    .balign 4

glabel D_80A06234
 .word 0x3C449BA6
glabel D_80A06238
 .word 0x42F9FFFF
glabel D_80A0623C
 .word 0x3A98EAD6


