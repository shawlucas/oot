glabel func_809B1984
/* 00864 809B1984 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 00868 809B1988 AFB00028 */  sw      $s0, 0x0028($sp)
/* 0086C 809B198C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00870 809B1990 AFBF002C */  sw      $ra, 0x002C($sp)
/* 00874 809B1994 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 00878 809B1998 AFA50034 */  sw      $a1, 0x0034($sp)
/* 0087C 809B199C 0C028800 */  jal     SkelAnime_GetFrameCount

/* 00880 809B19A0 24840348 */  addiu   $a0, $a0, 0x0348           ## $a0 = 06000348
/* 00884 809B19A4 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 00888 809B19A8 3C01C1A0 */  lui     $at, 0xC1A0                ## $at = C1A00000
/* 0088C 809B19AC 44813000 */  mtc1    $at, $f6                   ## $f6 = -20.00
/* 00890 809B19B0 46802020 */  cvt.s.w $f0, $f4
/* 00894 809B19B4 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 00898 809B19B8 240E0002 */  addiu   $t6, $zero, 0x0002         ## $t6 = 00000002
/* 0089C 809B19BC 24A50348 */  addiu   $a1, $a1, 0x0348           ## $a1 = 06000348
/* 008A0 809B19C0 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 008A4 809B19C4 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 008A8 809B19C8 E600026C */  swc1    $f0, 0x026C($s0)           ## 0000026C
/* 008AC 809B19CC AFAE0014 */  sw      $t6, 0x0014($sp)
/* 008B0 809B19D0 E7A00010 */  swc1    $f0, 0x0010($sp)
/* 008B4 809B19D4 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 008B8 809B19D8 0C029468 */  jal     SkelAnime_ChangeAnim

/* 008BC 809B19DC E7A60018 */  swc1    $f6, 0x0018($sp)
/* 008C0 809B19E0 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 008C4 809B19E4 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 008C8 809B19E8 44814000 */  mtc1    $at, $f8                   ## $f8 = -1.00
/* 008CC 809B19EC 240F0014 */  addiu   $t7, $zero, 0x0014         ## $t7 = 00000014
/* 008D0 809B19F0 A6000256 */  sh      $zero, 0x0256($s0)         ## 00000256
/* 008D4 809B19F4 A6000258 */  sh      $zero, 0x0258($s0)         ## 00000258
/* 008D8 809B19F8 A60F025A */  sh      $t7, 0x025A($s0)           ## 0000025A
/* 008DC 809B19FC E6000064 */  swc1    $f0, 0x0064($s0)           ## 00000064
/* 008E0 809B1A00 E600005C */  swc1    $f0, 0x005C($s0)           ## 0000005C
/* 008E4 809B1A04 E608006C */  swc1    $f8, 0x006C($s0)           ## 0000006C
/* 008E8 809B1A08 8FA40034 */  lw      $a0, 0x0034($sp)
/* 008EC 809B1A0C 26050280 */  addiu   $a1, $s0, 0x0280           ## $a1 = 00000280
/* 008F0 809B1A10 3C06428C */  lui     $a2, 0x428C                ## $a2 = 428C0000
/* 008F4 809B1A14 0C00F8C3 */  jal     func_8003E30C
/* 008F8 809B1A18 248407C0 */  addiu   $a0, $a0, 0x07C0           ## $a0 = 000007C0
/* 008FC 809B1A1C 10400006 */  beq     $v0, $zero, .L809B1A38
/* 00900 809B1A20 3C09809B */  lui     $t1, %hi(func_809B1A54)    ## $t1 = 809B0000
/* 00904 809B1A24 861900B4 */  lh      $t9, 0x00B4($s0)           ## 000000B4
/* 00908 809B1A28 24180001 */  addiu   $t8, $zero, 0x0001         ## $t8 = 00000001
/* 0090C 809B1A2C A6180256 */  sh      $t8, 0x0256($s0)           ## 00000256
/* 00910 809B1A30 27288100 */  addiu   $t0, $t9, 0x8100           ## $t0 = FFFF8100
/* 00914 809B1A34 A6080258 */  sh      $t0, 0x0258($s0)           ## 00000258
.L809B1A38:
/* 00918 809B1A38 25291A54 */  addiu   $t1, $t1, %lo(func_809B1A54) ## $t1 = 809B1A54
/* 0091C 809B1A3C AE090250 */  sw      $t1, 0x0250($s0)           ## 00000250
/* 00920 809B1A40 8FBF002C */  lw      $ra, 0x002C($sp)
/* 00924 809B1A44 8FB00028 */  lw      $s0, 0x0028($sp)
/* 00928 809B1A48 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 0092C 809B1A4C 03E00008 */  jr      $ra
/* 00930 809B1A50 00000000 */  nop


