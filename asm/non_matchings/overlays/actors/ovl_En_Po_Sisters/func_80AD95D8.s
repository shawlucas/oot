glabel func_80AD95D8
/* 00648 80AD95D8 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 0064C 80AD95DC AFB00020 */  sw      $s0, 0x0020($sp)
/* 00650 80AD95E0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00654 80AD95E4 AFBF0024 */  sw      $ra, 0x0024($sp)
/* 00658 80AD95E8 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 0065C 80AD95EC 24A508C0 */  addiu   $a1, $a1, 0x08C0           ## $a1 = 060008C0
/* 00660 80AD95F0 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 00664 80AD95F4 0C029490 */  jal     SkelAnime_ChangeAnimTransitionStop
/* 00668 80AD95F8 3C06C040 */  lui     $a2, 0xC040                ## $a2 = C0400000
/* 0066C 80AD95FC 8E0502B4 */  lw      $a1, 0x02B4($s0)           ## 000002B4
/* 00670 80AD9600 50A00011 */  beql    $a1, $zero, .L80AD9648
/* 00674 80AD9604 92090194 */  lbu     $t1, 0x0194($s0)           ## 00000194
/* 00678 80AD9608 8E0E02E8 */  lw      $t6, 0x02E8($s0)           ## 000002E8
/* 0067C 80AD960C 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 00680 80AD9610 3421F824 */  ori     $at, $at, 0xF824           ## $at = 0001F824
/* 00684 80AD9614 8DCF0000 */  lw      $t7, 0x0000($t6)           ## 00000000
/* 00688 80AD9618 01E1C024 */  and     $t8, $t7, $at
/* 0068C 80AD961C 13000004 */  beq     $t8, $zero, .L80AD9630
/* 00690 80AD9620 00000000 */  nop
/* 00694 80AD9624 84B90032 */  lh      $t9, 0x0032($a1)           ## 00000032
/* 00698 80AD9628 10000006 */  beq     $zero, $zero, .L80AD9644
/* 0069C 80AD962C A6190032 */  sh      $t9, 0x0032($s0)           ## 00000032
.L80AD9630:
/* 006A0 80AD9630 0C00B69E */  jal     ActorSearch_AngleY
/* 006A4 80AD9634 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 006A8 80AD9638 34018000 */  ori     $at, $zero, 0x8000         ## $at = 00008000
/* 006AC 80AD963C 00414021 */  addu    $t0, $v0, $at
/* 006B0 80AD9640 A6080032 */  sh      $t0, 0x0032($s0)           ## 00000032
.L80AD9644:
/* 006B4 80AD9644 92090194 */  lbu     $t1, 0x0194($s0)           ## 00000194
.L80AD9648:
/* 006B8 80AD9648 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 006BC 80AD964C 24054000 */  addiu   $a1, $zero, 0x4000         ## $a1 = 00004000
/* 006C0 80AD9650 11200005 */  beq     $t1, $zero, .L80AD9668
/* 006C4 80AD9654 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 006C8 80AD9658 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 006CC 80AD965C 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 006D0 80AD9660 00000000 */  nop
/* 006D4 80AD9664 E6040068 */  swc1    $f4, 0x0068($s0)           ## 00000068
.L80AD9668:
/* 006D8 80AD9668 920A0199 */  lbu     $t2, 0x0199($s0)           ## 00000199
/* 006DC 80AD966C 240C0010 */  addiu   $t4, $zero, 0x0010         ## $t4 = 00000010
/* 006E0 80AD9670 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 006E4 80AD9674 314BFFF4 */  andi    $t3, $t2, 0xFFF4           ## $t3 = 00000000
/* 006E8 80AD9678 A20B0199 */  sb      $t3, 0x0199($s0)           ## 00000199
/* 006EC 80AD967C 0C00D09B */  jal     func_8003426C
/* 006F0 80AD9680 AFAC0010 */  sw      $t4, 0x0010($sp)
/* 006F4 80AD9684 3C0D80AE */  lui     $t5, %hi(func_80ADAAA4)    ## $t5 = 80AE0000
/* 006F8 80AD9688 25ADAAA4 */  addiu   $t5, $t5, %lo(func_80ADAAA4) ## $t5 = 80ADAAA4
/* 006FC 80AD968C AE0D0190 */  sw      $t5, 0x0190($s0)           ## 00000190
/* 00700 80AD9690 8FBF0024 */  lw      $ra, 0x0024($sp)
/* 00704 80AD9694 8FB00020 */  lw      $s0, 0x0020($sp)
/* 00708 80AD9698 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 0070C 80AD969C 03E00008 */  jr      $ra
/* 00710 80AD96A0 00000000 */  nop
