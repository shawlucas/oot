.rdata
glabel D_808B6ABC
    .asciz "../z_bg_spot16_doughnut.c"
    .balign 4

glabel D_808B6AD8
    .asciz "../z_bg_spot16_doughnut.c"
    .balign 4

glabel D_808B6AF4
    .asciz "../z_bg_spot16_doughnut.c"
    .balign 4

.text
glabel func_808B68D8
/* 00498 808B68D8 27BDFFB0 */  addiu   $sp, $sp, 0xFFB0           ## $sp = FFFFFFB0
/* 0049C 808B68DC AFBF001C */  sw      $ra, 0x001C($sp)           
/* 004A0 808B68E0 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 004A4 808B68E4 AFA40050 */  sw      $a0, 0x0050($sp)           
/* 004A8 808B68E8 AFA50054 */  sw      $a1, 0x0054($sp)           
/* 004AC 808B68EC 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 004B0 808B68F0 3C06808B */  lui     $a2, %hi(D_808B6ABC)       ## $a2 = 808B0000
/* 004B4 808B68F4 24C66ABC */  addiu   $a2, $a2, %lo(D_808B6ABC)  ## $a2 = 808B6ABC
/* 004B8 808B68F8 27A40038 */  addiu   $a0, $sp, 0x0038           ## $a0 = FFFFFFE8
/* 004BC 808B68FC 240700F5 */  addiu   $a3, $zero, 0x00F5         ## $a3 = 000000F5
/* 004C0 808B6900 0C031AB1 */  jal     Graph_OpenDisps              
/* 004C4 808B6904 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 004C8 808B6908 8FAF0054 */  lw      $t7, 0x0054($sp)           
/* 004CC 808B690C 0C024F61 */  jal     func_80093D84              
/* 004D0 808B6910 8DE40000 */  lw      $a0, 0x0000($t7)           ## 00000000
/* 004D4 808B6914 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 004D8 808B6918 3C19DA38 */  lui     $t9, 0xDA38                ## $t9 = DA380000
/* 004DC 808B691C 37390003 */  ori     $t9, $t9, 0x0003           ## $t9 = DA380003
/* 004E0 808B6920 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 004E4 808B6924 AE1802D0 */  sw      $t8, 0x02D0($s0)           ## 000002D0
/* 004E8 808B6928 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 004EC 808B692C 8FA80054 */  lw      $t0, 0x0054($sp)           
/* 004F0 808B6930 3C05808B */  lui     $a1, %hi(D_808B6AD8)       ## $a1 = 808B0000
/* 004F4 808B6934 24A56AD8 */  addiu   $a1, $a1, %lo(D_808B6AD8)  ## $a1 = 808B6AD8
/* 004F8 808B6938 8D040000 */  lw      $a0, 0x0000($t0)           ## 00000000
/* 004FC 808B693C 240600F8 */  addiu   $a2, $zero, 0x00F8         ## $a2 = 000000F8
/* 00500 808B6940 0C0346A2 */  jal     Matrix_NewMtx              
/* 00504 808B6944 AFA20034 */  sw      $v0, 0x0034($sp)           
/* 00508 808B6948 8FA30034 */  lw      $v1, 0x0034($sp)           
/* 0050C 808B694C 3C0AFB00 */  lui     $t2, 0xFB00                ## $t2 = FB000000
/* 00510 808B6950 2401FF00 */  addiu   $at, $zero, 0xFF00         ## $at = FFFFFF00
/* 00514 808B6954 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 00518 808B6958 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 0051C 808B695C 3C18FA00 */  lui     $t8, 0xFA00                ## $t8 = FA000000
/* 00520 808B6960 2419FFFF */  addiu   $t9, $zero, 0xFFFF         ## $t9 = FFFFFFFF
/* 00524 808B6964 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 00528 808B6968 AE0902D0 */  sw      $t1, 0x02D0($s0)           ## 000002D0
/* 0052C 808B696C AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 00530 808B6970 8FAB0050 */  lw      $t3, 0x0050($sp)           
/* 00534 808B6974 3C0A0600 */  lui     $t2, 0x0600                ## $t2 = 06000000
/* 00538 808B6978 254A0FC0 */  addiu   $t2, $t2, 0x0FC0           ## $t2 = 06000FC0
/* 0053C 808B697C 916D0150 */  lbu     $t5, 0x0150($t3)           ## 00000150
/* 00540 808B6980 3C09DE00 */  lui     $t1, 0xDE00                ## $t1 = DE000000
/* 00544 808B6984 3C06808B */  lui     $a2, %hi(D_808B6AF4)       ## $a2 = 808B0000
/* 00548 808B6988 01A17025 */  or      $t6, $t5, $at              ## $t6 = FFFFFF00
/* 0054C 808B698C AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 00550 808B6990 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 00554 808B6994 24C66AF4 */  addiu   $a2, $a2, %lo(D_808B6AF4)  ## $a2 = 808B6AF4
/* 00558 808B6998 27A40038 */  addiu   $a0, $sp, 0x0038           ## $a0 = FFFFFFE8
/* 0055C 808B699C 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 00560 808B69A0 AE0F02D0 */  sw      $t7, 0x02D0($s0)           ## 000002D0
/* 00564 808B69A4 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00568 808B69A8 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 0056C 808B69AC 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 00570 808B69B0 24070100 */  addiu   $a3, $zero, 0x0100         ## $a3 = 00000100
/* 00574 808B69B4 24480008 */  addiu   $t0, $v0, 0x0008           ## $t0 = 00000008
/* 00578 808B69B8 AE0802D0 */  sw      $t0, 0x02D0($s0)           ## 000002D0
/* 0057C 808B69BC AC4A0004 */  sw      $t2, 0x0004($v0)           ## 00000004
/* 00580 808B69C0 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 00584 808B69C4 8FAB0054 */  lw      $t3, 0x0054($sp)           
/* 00588 808B69C8 0C031AD5 */  jal     Graph_CloseDisps              
/* 0058C 808B69CC 8D650000 */  lw      $a1, 0x0000($t3)           ## 00000000
/* 00590 808B69D0 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00594 808B69D4 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00598 808B69D8 27BD0050 */  addiu   $sp, $sp, 0x0050           ## $sp = 00000000
/* 0059C 808B69DC 03E00008 */  jr      $ra                        
/* 005A0 808B69E0 00000000 */  nop
/* 005A4 808B69E4 00000000 */  nop
/* 005A8 808B69E8 00000000 */  nop
/* 005AC 808B69EC 00000000 */  nop

