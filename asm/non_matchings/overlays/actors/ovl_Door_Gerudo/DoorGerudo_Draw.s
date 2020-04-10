.rdata

glabel D_80994B80

    .asciz "../z_door_gerudo.c"
    .balign 4

glabel D_80994B94

    .asciz "../z_door_gerudo.c"
    .balign 4

glabel D_80994BA8

    .asciz "../z_door_gerudo.c"
    .balign 4

.late_rodata

glabel D_80994BC0
 .float 0.01

.text
glabel DoorGerudo_Draw
/* 00468 80994A48 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 0046C 80994A4C AFB10018 */  sw      $s1, 0x0018($sp)           
/* 00470 80994A50 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 00474 80994A54 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00478 80994A58 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 0047C 80994A5C AFA40048 */  sw      $a0, 0x0048($sp)           
/* 00480 80994A60 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 00484 80994A64 3C068099 */  lui     $a2, %hi(D_80994B80)       ## $a2 = 80990000
/* 00488 80994A68 24C64B80 */  addiu   $a2, $a2, %lo(D_80994B80)  ## $a2 = 80994B80
/* 0048C 80994A6C 27A40030 */  addiu   $a0, $sp, 0x0030           ## $a0 = FFFFFFE8
/* 00490 80994A70 24070169 */  addiu   $a3, $zero, 0x0169         ## $a3 = 00000169
/* 00494 80994A74 0C031AB1 */  jal     Graph_OpenDisps              
/* 00498 80994A78 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 0049C 80994A7C 0C024F46 */  jal     func_80093D18              
/* 004A0 80994A80 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 004A4 80994A84 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 004A8 80994A88 3C0FDA38 */  lui     $t7, 0xDA38                ## $t7 = DA380000
/* 004AC 80994A8C 35EF0003 */  ori     $t7, $t7, 0x0003           ## $t7 = DA380003
/* 004B0 80994A90 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 004B4 80994A94 AE0E02C0 */  sw      $t6, 0x02C0($s0)           ## 000002C0
/* 004B8 80994A98 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 004BC 80994A9C 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 004C0 80994AA0 3C058099 */  lui     $a1, %hi(D_80994B94)       ## $a1 = 80990000
/* 004C4 80994AA4 24A54B94 */  addiu   $a1, $a1, %lo(D_80994B94)  ## $a1 = 80994B94
/* 004C8 80994AA8 2406016D */  addiu   $a2, $zero, 0x016D         ## $a2 = 0000016D
/* 004CC 80994AAC 0C0346A2 */  jal     Matrix_NewMtx              
/* 004D0 80994AB0 AFA2002C */  sw      $v0, 0x002C($sp)           
/* 004D4 80994AB4 8FA3002C */  lw      $v1, 0x002C($sp)           
/* 004D8 80994AB8 3C080600 */  lui     $t0, 0x0600                ## $t0 = 06000000
/* 004DC 80994ABC 25080040 */  addiu   $t0, $t0, 0x0040           ## $t0 = 06000040
/* 004E0 80994AC0 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 004E4 80994AC4 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 004E8 80994AC8 3C19DE00 */  lui     $t9, 0xDE00                ## $t9 = DE000000
/* 004EC 80994ACC 3C063CCC */  lui     $a2, 0x3CCC                ## $a2 = 3CCC0000
/* 004F0 80994AD0 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 004F4 80994AD4 AE1802C0 */  sw      $t8, 0x02C0($s0)           ## 000002C0
/* 004F8 80994AD8 AC480004 */  sw      $t0, 0x0004($v0)           ## 00000004
/* 004FC 80994ADC AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 00500 80994AE0 8FA90048 */  lw      $t1, 0x0048($sp)           
/* 00504 80994AE4 3C018099 */  lui     $at, %hi(D_80994BC0)       ## $at = 80990000
/* 00508 80994AE8 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3CCCCCCD
/* 0050C 80994AEC 912A0166 */  lbu     $t2, 0x0166($t1)           ## 00000166
/* 00510 80994AF0 1140000A */  beq     $t2, $zero, .L80994B1C     
/* 00514 80994AF4 00000000 */  nop
/* 00518 80994AF8 C42C4BC0 */  lwc1    $f12, %lo(D_80994BC0)($at) 
/* 0051C 80994AFC 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 00520 80994B00 0C0342A3 */  jal     Matrix_Scale              
/* 00524 80994B04 46006386 */  mov.s   $f14, $f12                 
/* 00528 80994B08 8FAB0048 */  lw      $t3, 0x0048($sp)           
/* 0052C 80994B0C 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00530 80994B10 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00534 80994B14 0C00CFD5 */  jal     func_80033F54              
/* 00538 80994B18 91650166 */  lbu     $a1, 0x0166($t3)           ## 00000166
.L80994B1C:
/* 0053C 80994B1C 3C068099 */  lui     $a2, %hi(D_80994BA8)       ## $a2 = 80990000
/* 00540 80994B20 24C64BA8 */  addiu   $a2, $a2, %lo(D_80994BA8)  ## $a2 = 80994BA8
/* 00544 80994B24 27A40030 */  addiu   $a0, $sp, 0x0030           ## $a0 = FFFFFFE8
/* 00548 80994B28 8E250000 */  lw      $a1, 0x0000($s1)           ## 00000000
/* 0054C 80994B2C 0C031AD5 */  jal     Graph_CloseDisps              
/* 00550 80994B30 24070179 */  addiu   $a3, $zero, 0x0179         ## $a3 = 00000179
/* 00554 80994B34 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00558 80994B38 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 0055C 80994B3C 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 00560 80994B40 03E00008 */  jr      $ra                        
/* 00564 80994B44 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000
/* 00568 80994B48 00000000 */  nop
/* 0056C 80994B4C 00000000 */  nop

