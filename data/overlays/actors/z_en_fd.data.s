.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel En_Fd_InitVars
 .word 0x00990500, 0x00000215, 0x009E0000, 0x000031E0
.word EnFd_Init
.word EnFd_Destroy
.word EnFd_Update
.word EnFd_Draw
glabel D_80A0DE20
 .word 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040088, 0x00000000, 0x01050100, 0x15000640, 0x00000000, 0x0005012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x0C000640, 0x00000000, 0x00050190, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x0E000320, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x0F000640, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x100007D0, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x11000320, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x12000640, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x130007D0, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x04000898, 0x00000000, 0x00040190, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x04001388, 0x00000000, 0x0004012C, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x08000898, 0x00000000, 0x00040190, 0x00000000, 0xFFCFFFFF, 0x01040000, 0x00040008, 0x00000000, 0x01010100, 0x08001388, 0x00000000, 0x0004012C
glabel D_80A0DFD0
 .word 0x0A110939, 0x10000000, 0x0000000C
.word D_80A0DE20
glabel D_80A0DFE0
 .word 0x18000002, 0x00190019, 0xFF000000
glabel D_80A0DFEC
 .word 0x060010B4, 0x3F800000, 0x00000000, 0xBF800000, 0x03000000, 0x00000000, 0x06005C64, 0x3F800000, 0x00000000, 0xBF800000, 0x03000000, 0xC1200000, 0x06006044, 0x00000000, 0x00000000, 0xBF800000, 0x03000000, 0xC1200000, 0x06006A18, 0x3F800000, 0x00000000, 0xBF800000, 0x01000000, 0xC1200000, 0x06006B64, 0x00000000, 0x00000000, 0xBF800000, 0x03000000, 0xC1200000
glabel D_80A0E064
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E070
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E07C
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E088
 .word 0x45D48000, 0x00000000, 0x00000000
glabel D_80A0E094
 .word 0x45D48000, 0x00000000, 0x00000000
glabel D_80A0E0A0
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E0AC
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E0B8
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E0C4
 .word 0x00000000, 0x00000000, 0x00000000
glabel D_80A0E0D0
 .word 0xFFFFC8FF, 0xC8C8C8FF, 0xFFFF00FF
glabel D_80A0E0DC
 .word 0x00FF00FF, 0x0000FFFF, 0xFF0000FF
glabel D_80A0E0E8
 .word 0xFF800000, 0xFF000000, 0xFFFF0000, 0xFF000000
glabel D_80A0E0F8
 .word 0x040539B0, 0x040535B0, 0x040531B0, 0x04052DB0, 0x040529B0, 0x040525B0, 0x040521B0, 0x04051DB0, 0x00000000, 0x00000000

