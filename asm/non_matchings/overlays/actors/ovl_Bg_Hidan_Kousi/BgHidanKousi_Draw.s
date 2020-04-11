.rdata
glabel D_80889EEC
    .asciz "../z_bg_hidan_kousi.c"
    .balign 4

glabel D_80889F04
    .asciz "../z_bg_hidan_kousi.c"
    .balign 4

glabel D_80889F1C
    .asciz "../z_bg_hidan_kousi.c"
    .balign 4

.text
glabel BgHidanKousi_Draw
/* 003F8 80889D58 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 003FC 80889D5C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00400 80889D60 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00404 80889D64 AFA40040 */  sw      $a0, 0x0040($sp)           
/* 00408 80889D68 AFA50044 */  sw      $a1, 0x0044($sp)           
/* 0040C 80889D6C 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 00410 80889D70 3C068089 */  lui     $a2, %hi(D_80889EEC)       ## $a2 = 80890000
/* 00414 80889D74 24C69EEC */  addiu   $a2, $a2, %lo(D_80889EEC)  ## $a2 = 80889EEC
/* 00418 80889D78 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFEC
/* 0041C 80889D7C 2407015E */  addiu   $a3, $zero, 0x015E         ## $a3 = 0000015E
/* 00420 80889D80 0C031AB1 */  jal     Graph_OpenDisps              
/* 00424 80889D84 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 00428 80889D88 8FAF0044 */  lw      $t7, 0x0044($sp)           
/* 0042C 80889D8C 0C024F46 */  jal     func_80093D18              
/* 00430 80889D90 8DE40000 */  lw      $a0, 0x0000($t7)           ## 00000000
/* 00434 80889D94 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 00438 80889D98 3C19DA38 */  lui     $t9, 0xDA38                ## $t9 = DA380000
/* 0043C 80889D9C 37390003 */  ori     $t9, $t9, 0x0003           ## $t9 = DA380003
/* 00440 80889DA0 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00444 80889DA4 AE1802C0 */  sw      $t8, 0x02C0($s0)           ## 000002C0
/* 00448 80889DA8 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 0044C 80889DAC 8FA80044 */  lw      $t0, 0x0044($sp)           
/* 00450 80889DB0 3C058089 */  lui     $a1, %hi(D_80889F04)       ## $a1 = 80890000
/* 00454 80889DB4 24A59F04 */  addiu   $a1, $a1, %lo(D_80889F04)  ## $a1 = 80889F04
/* 00458 80889DB8 8D040000 */  lw      $a0, 0x0000($t0)           ## 00000000
/* 0045C 80889DBC 24060162 */  addiu   $a2, $zero, 0x0162         ## $a2 = 00000162
/* 00460 80889DC0 0C0346A2 */  jal     Matrix_NewMtx              
/* 00464 80889DC4 AFA20028 */  sw      $v0, 0x0028($sp)           
/* 00468 80889DC8 8FA30028 */  lw      $v1, 0x0028($sp)           
/* 0046C 80889DCC 3C0ADE00 */  lui     $t2, 0xDE00                ## $t2 = DE000000
/* 00470 80889DD0 3C0F8089 */  lui     $t7, %hi(D_80889E84)       ## $t7 = 80890000
/* 00474 80889DD4 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 00478 80889DD8 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0047C 80889DDC 3C068089 */  lui     $a2, %hi(D_80889F1C)       ## $a2 = 80890000
/* 00480 80889DE0 24C69F1C */  addiu   $a2, $a2, %lo(D_80889F1C)  ## $a2 = 80889F1C
/* 00484 80889DE4 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 00488 80889DE8 AE0902C0 */  sw      $t1, 0x02C0($s0)           ## 000002C0
/* 0048C 80889DEC AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 00490 80889DF0 8FAB0040 */  lw      $t3, 0x0040($sp)           
/* 00494 80889DF4 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFEC
/* 00498 80889DF8 24070167 */  addiu   $a3, $zero, 0x0167         ## $a3 = 00000167
/* 0049C 80889DFC 856C001C */  lh      $t4, 0x001C($t3)           ## 0000001C
/* 004A0 80889E00 318D00FF */  andi    $t5, $t4, 0x00FF           ## $t5 = 00000000
/* 004A4 80889E04 000D7080 */  sll     $t6, $t5,  2               
/* 004A8 80889E08 01EE7821 */  addu    $t7, $t7, $t6              
/* 004AC 80889E0C 8DEF9E84 */  lw      $t7, %lo(D_80889E84)($t7)  
/* 004B0 80889E10 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 004B4 80889E14 8FB80044 */  lw      $t8, 0x0044($sp)           
/* 004B8 80889E18 0C031AD5 */  jal     Graph_CloseDisps              
/* 004BC 80889E1C 8F050000 */  lw      $a1, 0x0000($t8)           ## 00000000
/* 004C0 80889E20 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 004C4 80889E24 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 004C8 80889E28 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 004CC 80889E2C 03E00008 */  jr      $ra                        
/* 004D0 80889E30 00000000 */  nop
/* 004D4 80889E34 00000000 */  nop
/* 004D8 80889E38 00000000 */  nop
/* 004DC 80889E3C 00000000 */  nop

