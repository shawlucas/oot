.late_rodata

glabel D_808756AC
 .word 0x3D0B4396

 .text
glabel func_80873FD8
/* 017A8 80873FD8 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 017AC 80873FDC AFBF002C */  sw      $ra, 0x002C($sp)
/* 017B0 80873FE0 AFB00028 */  sw      $s0, 0x0028($sp)
/* 017B4 80873FE4 AFA5003C */  sw      $a1, 0x003C($sp)
/* 017B8 80873FE8 848E02FE */  lh      $t6, 0x02FE($a0)           ## 000002FE
/* 017BC 80873FEC 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 017C0 80873FF0 C4800168 */  lwc1    $f0, 0x0168($a0)           ## 00000168
/* 017C4 80873FF4 15C00044 */  bne     $t6, $zero, .L80874108
/* 017C8 80873FF8 24840028 */  addiu   $a0, $a0, 0x0028           ## $a0 = 00000028
/* 017CC 80873FFC 8E05030C */  lw      $a1, 0x030C($s0)           ## 0000030C
/* 017D0 80874000 8E060314 */  lw      $a2, 0x0314($s0)           ## 00000314
/* 017D4 80874004 0C01E107 */  jal     Math_SmoothScaleMaxF

/* 017D8 80874008 3C0742C8 */  lui     $a3, 0x42C8                ## $a3 = 42C80000
/* 017DC 8087400C 3C053D0F */  lui     $a1, 0x3D0F                ## $a1 = 3D0F0000
/* 017E0 80874010 3C073BA3 */  lui     $a3, 0x3BA3                ## $a3 = 3BA30000
/* 017E4 80874014 34E7D70A */  ori     $a3, $a3, 0xD70A           ## $a3 = 3BA3D70A
/* 017E8 80874018 34A55C29 */  ori     $a1, $a1, 0x5C29           ## $a1 = 3D0F5C29
/* 017EC 8087401C 26040308 */  addiu   $a0, $s0, 0x0308           ## $a0 = 00000308
/* 017F0 80874020 0C01E107 */  jal     Math_SmoothScaleMaxF

/* 017F4 80874024 8E060318 */  lw      $a2, 0x0318($s0)           ## 00000318
/* 017F8 80874028 3C053F4C */  lui     $a1, 0x3F4C                ## $a1 = 3F4C0000
/* 017FC 8087402C 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 01800 80874030 3C073CA3 */  lui     $a3, 0x3CA3                ## $a3 = 3CA30000
/* 01804 80874034 34E7D70A */  ori     $a3, $a3, 0xD70A           ## $a3 = 3CA3D70A
/* 01808 80874038 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 0180C 8087403C 34A5CCCD */  ori     $a1, $a1, 0xCCCD           ## $a1 = 3F4CCCCD
/* 01810 80874040 0C01E107 */  jal     Math_SmoothScaleMaxF

/* 01814 80874044 26040314 */  addiu   $a0, $s0, 0x0314           ## $a0 = 00000314
/* 01818 80874048 3C053E4C */  lui     $a1, 0x3E4C                ## $a1 = 3E4C0000
/* 0181C 8087404C 3C063CF5 */  lui     $a2, 0x3CF5                ## $a2 = 3CF50000
/* 01820 80874050 3C073D4C */  lui     $a3, 0x3D4C                ## $a3 = 3D4C0000
/* 01824 80874054 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 3D4CCCCD
/* 01828 80874058 34C6C28F */  ori     $a2, $a2, 0xC28F           ## $a2 = 3CF5C28F
/* 0182C 8087405C 34A5CCCD */  ori     $a1, $a1, 0xCCCD           ## $a1 = 3E4CCCCD
/* 01830 80874060 0C01E107 */  jal     Math_SmoothScaleMaxF

/* 01834 80874064 26040318 */  addiu   $a0, $s0, 0x0318           ## $a0 = 00000318
/* 01838 80874068 3C018087 */  lui     $at, %hi(D_808756AC)       ## $at = 80870000
/* 0183C 8087406C C42656AC */  lwc1    $f6, %lo(D_808756AC)($at)
/* 01840 80874070 C6040308 */  lwc1    $f4, 0x0308($s0)           ## 00000308
/* 01844 80874074 4604303E */  c.le.s  $f6, $f4
/* 01848 80874078 00000000 */  nop
/* 0184C 8087407C 4502001F */  bc1fl   .L808740FC
/* 01850 80874080 860800B6 */  lh      $t0, 0x00B6($s0)           ## 000000B6
/* 01854 80874084 860200B6 */  lh      $v0, 0x00B6($s0)           ## 000000B6
/* 01858 80874088 2841E0C1 */  slti    $at, $v0, 0xE0C1
/* 0185C 8087408C 14200018 */  bne     $at, $zero, .L808740F0
/* 01860 80874090 24590BB8 */  addiu   $t9, $v0, 0x0BB8           ## $t9 = 00000BB8
/* 01864 80874094 284103E8 */  slti    $at, $v0, 0x03E8
/* 01868 80874098 10200015 */  beq     $at, $zero, .L808740F0
/* 0186C 8087409C 00000000 */  nop
/* 01870 808740A0 0C02927F */  jal     SkelAnime_FrameUpdateMatrix

/* 01874 808740A4 26040150 */  addiu   $a0, $s0, 0x0150           ## $a0 = 00000150
/* 01878 808740A8 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
/* 0187C 808740AC 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 01880 808740B0 24060005 */  addiu   $a2, $zero, 0x0005         ## $a2 = 00000005
/* 01884 808740B4 0C01E1EF */  jal     Math_SmoothScaleMaxS

/* 01888 808740B8 240703E8 */  addiu   $a3, $zero, 0x03E8         ## $a3 = 000003E8
/* 0188C 808740BC 860F00B6 */  lh      $t7, 0x00B6($s0)           ## 000000B6
/* 01890 808740C0 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 01894 808740C4 44815000 */  mtc1    $at, $f10                  ## $f10 = 50.00
/* 01898 808740C8 448F4000 */  mtc1    $t7, $f8                   ## $f8 = 0.00
/* 0189C 808740CC 24180001 */  addiu   $t8, $zero, 0x0001         ## $t8 = 00000001
/* 018A0 808740D0 46804020 */  cvt.s.w $f0, $f8
/* 018A4 808740D4 46000005 */  abs.s   $f0, $f0
/* 018A8 808740D8 460A003C */  c.lt.s  $f0, $f10
/* 018AC 808740DC 00000000 */  nop
/* 018B0 808740E0 45020080 */  bc1fl   .L808742E4
/* 018B4 808740E4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 018B8 808740E8 1000007D */  beq     $zero, $zero, .L808742E0
/* 018BC 808740EC A61802FE */  sh      $t8, 0x02FE($s0)           ## 000002FE
.L808740F0:
/* 018C0 808740F0 1000007B */  beq     $zero, $zero, .L808742E0
/* 018C4 808740F4 A61900B6 */  sh      $t9, 0x00B6($s0)           ## 000000B6
/* 018C8 808740F8 860800B6 */  lh      $t0, 0x00B6($s0)           ## 000000B6
.L808740FC:
/* 018CC 808740FC 25090BB8 */  addiu   $t1, $t0, 0x0BB8           ## $t1 = 00000BB8
/* 018D0 80874100 10000077 */  beq     $zero, $zero, .L808742E0
/* 018D4 80874104 A60900B6 */  sh      $t1, 0x00B6($s0)           ## 000000B6
.L80874108:
/* 018D8 80874108 26040150 */  addiu   $a0, $s0, 0x0150           ## $a0 = 00000150
/* 018DC 8087410C AFA40030 */  sw      $a0, 0x0030($sp)
/* 018E0 80874110 0C02927F */  jal     SkelAnime_FrameUpdateMatrix

/* 018E4 80874114 E7A00034 */  swc1    $f0, 0x0034($sp)
/* 018E8 80874118 C7A00034 */  lwc1    $f0, 0x0034($sp)
/* 018EC 8087411C C610032C */  lwc1    $f16, 0x032C($s0)          ## 0000032C
/* 018F0 80874120 4600803E */  c.le.s  $f16, $f0
/* 018F4 80874124 00000000 */  nop
/* 018F8 80874128 45020030 */  bc1fl   .L808741EC
/* 018FC 8087412C 8FAE003C */  lw      $t6, 0x003C($sp)
/* 01900 80874130 860A02FC */  lh      $t2, 0x02FC($s0)           ## 000002FC
/* 01904 80874134 8FAB003C */  lw      $t3, 0x003C($sp)
/* 01908 80874138 5540002C */  bnel    $t2, $zero, .L808741EC
/* 0190C 8087413C 8FAE003C */  lw      $t6, 0x003C($sp)
/* 01910 80874140 856C00A4 */  lh      $t4, 0x00A4($t3)           ## 000000A4
/* 01914 80874144 2401003B */  addiu   $at, $zero, 0x003B         ## $at = 0000003B
/* 01918 80874148 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 0191C 8087414C 15810014 */  bne     $t4, $at, .L808741A0
/* 01920 80874150 00000000 */  nop
/* 01924 80874154 3C040602 */  lui     $a0, 0x0602                ## $a0 = 06020000
/* 01928 80874158 0C028800 */  jal     SkelAnime_GetFrameCount

/* 0192C 8087415C 2484D514 */  addiu   $a0, $a0, 0xD514           ## $a0 = 0601D514
/* 01930 80874160 44829000 */  mtc1    $v0, $f18                  ## $f18 = 0.00
/* 01934 80874164 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01938 80874168 44812000 */  mtc1    $at, $f4                   ## $f4 = -10.00
/* 0193C 8087416C 46809020 */  cvt.s.w $f0, $f18
/* 01940 80874170 3C050602 */  lui     $a1, 0x0602                ## $a1 = 06020000
/* 01944 80874174 24A5D514 */  addiu   $a1, $a1, 0xD514           ## $a1 = 0601D514
/* 01948 80874178 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 0194C 8087417C 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 01950 80874180 E600032C */  swc1    $f0, 0x032C($s0)           ## 0000032C
/* 01954 80874184 AFA00014 */  sw      $zero, 0x0014($sp)
/* 01958 80874188 E7A00010 */  swc1    $f0, 0x0010($sp)
/* 0195C 8087418C 8FA40030 */  lw      $a0, 0x0030($sp)
/* 01960 80874190 0C029468 */  jal     SkelAnime_ChangeAnim

/* 01964 80874194 E7A40018 */  swc1    $f4, 0x0018($sp)
/* 01968 80874198 10000012 */  beq     $zero, $zero, .L808741E4
/* 0196C 8087419C 240D0001 */  addiu   $t5, $zero, 0x0001         ## $t5 = 00000001
.L808741A0:
/* 01970 808741A0 0C028800 */  jal     SkelAnime_GetFrameCount

/* 01974 808741A4 24841DF0 */  addiu   $a0, $a0, 0x1DF0           ## $a0 = 00001DF0
/* 01978 808741A8 44823000 */  mtc1    $v0, $f6                   ## $f6 = 0.00
/* 0197C 808741AC 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01980 808741B0 44814000 */  mtc1    $at, $f8                   ## $f8 = -10.00
/* 01984 808741B4 46803020 */  cvt.s.w $f0, $f6
/* 01988 808741B8 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 0198C 808741BC 24A51DF0 */  addiu   $a1, $a1, 0x1DF0           ## $a1 = 06001DF0
/* 01990 808741C0 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01994 808741C4 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 01998 808741C8 E600032C */  swc1    $f0, 0x032C($s0)           ## 0000032C
/* 0199C 808741CC AFA00014 */  sw      $zero, 0x0014($sp)
/* 019A0 808741D0 E7A00010 */  swc1    $f0, 0x0010($sp)
/* 019A4 808741D4 8FA40030 */  lw      $a0, 0x0030($sp)
/* 019A8 808741D8 0C029468 */  jal     SkelAnime_ChangeAnim

/* 019AC 808741DC E7A80018 */  swc1    $f8, 0x0018($sp)
/* 019B0 808741E0 240D0001 */  addiu   $t5, $zero, 0x0001         ## $t5 = 00000001
.L808741E4:
/* 019B4 808741E4 A60D02FC */  sh      $t5, 0x02FC($s0)           ## 000002FC
/* 019B8 808741E8 8FAE003C */  lw      $t6, 0x003C($sp)
.L808741EC:
/* 019BC 808741EC 91CF1D6C */  lbu     $t7, 0x1D6C($t6)           ## 00001D6C
/* 019C0 808741F0 51E0003C */  beql    $t7, $zero, .L808742E4
/* 019C4 808741F4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 019C8 808741F8 8DC21D8C */  lw      $v0, 0x1D8C($t6)           ## 00001D8C
/* 019CC 808741FC 50400039 */  beql    $v0, $zero, .L808742E4
/* 019D0 80874200 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 019D4 80874204 94580000 */  lhu     $t8, 0x0000($v0)           ## 00000000
/* 019D8 80874208 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 019DC 8087420C 57010035 */  bnel    $t8, $at, .L808742E4
/* 019E0 80874210 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 019E4 80874214 A60002FC */  sh      $zero, 0x02FC($s0)         ## 000002FC
/* 019E8 80874218 861902FC */  lh      $t9, 0x02FC($s0)           ## 000002FC
/* 019EC 8087421C 2401003B */  addiu   $at, $zero, 0x003B         ## $at = 0000003B
/* 019F0 80874220 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 019F4 80874224 A61902FE */  sh      $t9, 0x02FE($s0)           ## 000002FE
/* 019F8 80874228 8FA8003C */  lw      $t0, 0x003C($sp)
/* 019FC 8087422C 850900A4 */  lh      $t1, 0x00A4($t0)           ## 000000A4
/* 01A00 80874230 15210015 */  bne     $t1, $at, .L80874288
/* 01A04 80874234 00000000 */  nop
/* 01A08 80874238 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 01A0C 8087423C 0C028800 */  jal     SkelAnime_GetFrameCount

/* 01A10 80874240 248469E8 */  addiu   $a0, $a0, 0x69E8           ## $a0 = 060069E8
/* 01A14 80874244 44825000 */  mtc1    $v0, $f10                  ## $f10 = 0.00
/* 01A18 80874248 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01A1C 8087424C 44818000 */  mtc1    $at, $f16                  ## $f16 = -10.00
/* 01A20 80874250 46805020 */  cvt.s.w $f0, $f10
/* 01A24 80874254 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 01A28 80874258 240A0002 */  addiu   $t2, $zero, 0x0002         ## $t2 = 00000002
/* 01A2C 8087425C 24A569E8 */  addiu   $a1, $a1, 0x69E8           ## $a1 = 060069E8
/* 01A30 80874260 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01A34 80874264 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 01A38 80874268 E600032C */  swc1    $f0, 0x032C($s0)           ## 0000032C
/* 01A3C 8087426C AFAA0014 */  sw      $t2, 0x0014($sp)
/* 01A40 80874270 E7A00010 */  swc1    $f0, 0x0010($sp)
/* 01A44 80874274 8FA40030 */  lw      $a0, 0x0030($sp)
/* 01A48 80874278 0C029468 */  jal     SkelAnime_ChangeAnim

/* 01A4C 8087427C E7B00018 */  swc1    $f16, 0x0018($sp)
/* 01A50 80874280 10000012 */  beq     $zero, $zero, .L808742CC
/* 01A54 80874284 00000000 */  nop
.L80874288:
/* 01A58 80874288 0C028800 */  jal     SkelAnime_GetFrameCount

/* 01A5C 8087428C 24845810 */  addiu   $a0, $a0, 0x5810           ## $a0 = 00005810
/* 01A60 80874290 44829000 */  mtc1    $v0, $f18                  ## $f18 = 0.00
/* 01A64 80874294 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01A68 80874298 44812000 */  mtc1    $at, $f4                   ## $f4 = -10.00
/* 01A6C 8087429C 46809020 */  cvt.s.w $f0, $f18
/* 01A70 808742A0 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 01A74 808742A4 240B0002 */  addiu   $t3, $zero, 0x0002         ## $t3 = 00000002
/* 01A78 808742A8 24A55810 */  addiu   $a1, $a1, 0x5810           ## $a1 = 06005810
/* 01A7C 808742AC 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 01A80 808742B0 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 01A84 808742B4 E600032C */  swc1    $f0, 0x032C($s0)           ## 0000032C
/* 01A88 808742B8 AFAB0014 */  sw      $t3, 0x0014($sp)
/* 01A8C 808742BC E7A00010 */  swc1    $f0, 0x0010($sp)
/* 01A90 808742C0 8FA40030 */  lw      $a0, 0x0030($sp)
/* 01A94 808742C4 0C029468 */  jal     SkelAnime_ChangeAnim

/* 01A98 808742C8 E7A40018 */  swc1    $f4, 0x0018($sp)
.L808742CC:
/* 01A9C 808742CC 3C0D8087 */  lui     $t5, %hi(func_80874304)    ## $t5 = 80870000
/* 01AA0 808742D0 240C0001 */  addiu   $t4, $zero, 0x0001         ## $t4 = 00000001
/* 01AA4 808742D4 25AD4304 */  addiu   $t5, $t5, %lo(func_80874304) ## $t5 = 80874304
/* 01AA8 808742D8 A60C02F6 */  sh      $t4, 0x02F6($s0)           ## 000002F6
/* 01AAC 808742DC AE0D014C */  sw      $t5, 0x014C($s0)           ## 0000014C
.L808742E0:
/* 01AB0 808742E0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L808742E4:
/* 01AB4 808742E4 8FA5003C */  lw      $a1, 0x003C($sp)
/* 01AB8 808742E8 0C21CA58 */  jal     func_80872960
/* 01ABC 808742EC 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 01AC0 808742F0 8FBF002C */  lw      $ra, 0x002C($sp)
/* 01AC4 808742F4 8FB00028 */  lw      $s0, 0x0028($sp)
/* 01AC8 808742F8 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 01ACC 808742FC 03E00008 */  jr      $ra
/* 01AD0 80874300 00000000 */  nop


