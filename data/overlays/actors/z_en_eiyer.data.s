.include "macro.inc"

 # assembler directives
 .set noat      # allow manual use of $at
 .set noreorder # don't insert nops after branches
 .set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel En_Eiyer_InitVars
 .word 0x003A0500, 0x00000005, 0x00260000, 0x000002D4
.word EnEiyer_Init
.word EnEiyer_Destroy
.word EnEiyer_Update
.word EnEiyer_Draw
glabel D_80A01970
 .byte 0x00, 0x11, 0x09, 0x39, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xCF, 0xFF, 0xFF, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x09, 0x01, 0x01, 0x00, 0x00, 0x1B
glabel D_80A01992
 .byte 0x00, 0x11, 0xFF, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
glabel D_80A0199C
 .word 0x0200002D, 0x000F6400
glabel D_80A019A4
 .word 0x10020102, 0x10020202, 0x01020402, 0x02020202, 0x02000404, 0x00000104, 0x02020804, 0x00000400
glabel D_80A019C4
 .word 0x89170019, 0xC8500005, 0x304C09C4

