glabel func_80949530
/* 10860 80949530 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 10864 80949534 AFA5001C */  sw      $a1, 0x001C($sp)
/* 10868 80949538 3C0E8095 */  lui     $t6, %hi(func_809495A4)    ## $t6 = 80950000
/* 1086C 8094953C AFBF0014 */  sw      $ra, 0x0014($sp)
/* 10870 80949540 25CE95A4 */  addiu   $t6, $t6, %lo(func_809495A4) ## $t6 = 809495A4
/* 10874 80949544 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 10878 80949548 AC8E014C */  sw      $t6, 0x014C($a0)           ## 0000014C
/* 1087C 8094954C 3C050603 */  lui     $a1, 0x0603                ## $a1 = 06030000
/* 10880 80949550 24A52BF8 */  addiu   $a1, $a1, 0x2BF8           ## $a1 = 06032BF8
/* 10884 80949554 AFA70018 */  sw      $a3, 0x0018($sp)
/* 10888 80949558 24840568 */  addiu   $a0, $a0, 0x0568           ## $a0 = 00000568
/* 1088C 8094955C 0C0294D3 */  jal     SkelAnime_ChangeAnimTransitionRepeat
/* 10890 80949560 3C06C040 */  lui     $a2, 0xC040                ## $a2 = C0400000
/* 10894 80949564 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 10898 80949568 44816000 */  mtc1    $at, $f12                  ## $f12 = 100.00
/* 1089C 8094956C 0C00CFBE */  jal     Math_Rand_ZeroFloat

/* 108A0 80949570 00000000 */  nop
/* 108A4 80949574 4600010D */  trunc.w.s $f4, $f0
/* 108A8 80949578 8FA70018 */  lw      $a3, 0x0018($sp)
/* 108AC 8094957C 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 108B0 80949580 24190019 */  addiu   $t9, $zero, 0x0019         ## $t9 = 00000019
/* 108B4 80949584 44182000 */  mfc1    $t8, $f4
/* 108B8 80949588 A4F9017A */  sh      $t9, 0x017A($a3)           ## 0000017A
/* 108BC 8094958C E4E604C8 */  swc1    $f6, 0x04C8($a3)           ## 000004C8
/* 108C0 80949590 A4F80150 */  sh      $t8, 0x0150($a3)           ## 00000150
/* 108C4 80949594 8FBF0014 */  lw      $ra, 0x0014($sp)
/* 108C8 80949598 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 108CC 8094959C 03E00008 */  jr      $ra
/* 108D0 809495A0 00000000 */  nop


