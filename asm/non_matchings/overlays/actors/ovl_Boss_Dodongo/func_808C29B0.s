glabel func_808C29B0
/* 01820 808C29B0 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 01824 808C29B4 AFB00028 */  sw      $s0, 0x0028($sp)
/* 01828 808C29B8 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0182C 808C29BC AFBF002C */  sw      $ra, 0x002C($sp)
/* 01830 808C29C0 3C040602 */  lui     $a0, 0x0602                ## $a0 = 06020000
/* 01834 808C29C4 0C028800 */  jal     SkelAnime_GetFrameCount

/* 01838 808C29C8 2484D934 */  addiu   $a0, $a0, 0xD934           ## $a0 = 0601D934
/* 0183C 808C29CC 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 01840 808C29D0 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01844 808C29D4 44814000 */  mtc1    $at, $f8                   ## $f8 = -10.00
/* 01848 808C29D8 468021A0 */  cvt.s.w $f6, $f4
/* 0184C 808C29DC 3C050602 */  lui     $a1, 0x0602                ## $a1 = 06020000
/* 01850 808C29E0 240E0002 */  addiu   $t6, $zero, 0x0002         ## $t6 = 00000002
/* 01854 808C29E4 AFAE0014 */  sw      $t6, 0x0014($sp)
/* 01858 808C29E8 24A5D934 */  addiu   $a1, $a1, 0xD934           ## $a1 = 0601D934
/* 0185C 808C29EC 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01860 808C29F0 E7A60010 */  swc1    $f6, 0x0010($sp)
/* 01864 808C29F4 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01868 808C29F8 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 0186C 808C29FC 0C029468 */  jal     SkelAnime_ChangeAnim

/* 01870 808C2A00 E7A80018 */  swc1    $f8, 0x0018($sp)
/* 01874 808C2A04 8E180004 */  lw      $t8, 0x0004($s0)           ## 00000004
/* 01878 808C2A08 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 0187C 808C2A0C 3C0F808C */  lui     $t7, %hi(func_808C32F4)    ## $t7 = 808C0000
/* 01880 808C2A10 25EF32F4 */  addiu   $t7, $t7, %lo(func_808C32F4) ## $t7 = 808C32F4
/* 01884 808C2A14 37190001 */  ori     $t9, $t8, 0x0001           ## $t9 = 00000001
/* 01888 808C2A18 A60001AA */  sh      $zero, 0x01AA($s0)         ## 000001AA
/* 0188C 808C2A1C AE0F0190 */  sw      $t7, 0x0190($s0)           ## 00000190
/* 01890 808C2A20 A60001DA */  sh      $zero, 0x01DA($s0)         ## 000001DA
/* 01894 808C2A24 AE190004 */  sw      $t9, 0x0004($s0)           ## 00000004
/* 01898 808C2A28 E60A01E4 */  swc1    $f10, 0x01E4($s0)          ## 000001E4
/* 0189C 808C2A2C 8FBF002C */  lw      $ra, 0x002C($sp)
/* 018A0 808C2A30 8FB00028 */  lw      $s0, 0x0028($sp)
/* 018A4 808C2A34 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 018A8 808C2A38 03E00008 */  jr      $ra
/* 018AC 808C2A3C 00000000 */  nop
