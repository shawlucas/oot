glabel func_80801E44
/* 012B4 80801E44 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 012B8 80801E48 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 012BC 80801E4C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 012C0 80801E50 3C0E8080 */  lui     $t6, %hi(func_80801DE4)    ## $t6 = 80800000
/* 012C4 80801E54 3C0F8080 */  lui     $t7, %hi(func_80801E0C)    ## $t7 = 80800000
/* 012C8 80801E58 3C188080 */  lui     $t8, %hi(D_80801FC0)       ## $t8 = 80800000
/* 012CC 80801E5C 25CE1DE4 */  addiu   $t6, $t6, %lo(func_80801DE4) ## $t6 = 80801DE4
/* 012D0 80801E60 25EF1E0C */  addiu   $t7, $t7, %lo(func_80801E0C) ## $t7 = 80801E0C
/* 012D4 80801E64 27181FC0 */  addiu   $t8, $t8, %lo(D_80801FC0)  ## $t8 = 80801FC0
/* 012D8 80801E68 24190013 */  addiu   $t9, $zero, 0x0013         ## $t9 = 00000013
/* 012DC 80801E6C 24080025 */  addiu   $t0, $zero, 0x0025         ## $t0 = 00000025
/* 012E0 80801E70 24090033 */  addiu   $t1, $zero, 0x0033         ## $t1 = 00000033
/* 012E4 80801E74 240A003B */  addiu   $t2, $zero, 0x003B         ## $t2 = 0000003B
/* 012E8 80801E78 240B0049 */  addiu   $t3, $zero, 0x0049         ## $t3 = 00000049
/* 012EC 80801E7C 240C005B */  addiu   $t4, $zero, 0x005B         ## $t4 = 0000005B
/* 012F0 80801E80 240D007E */  addiu   $t5, $zero, 0x007E         ## $t5 = 0000007E
/* 012F4 80801E84 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 012F8 80801E88 AC8E0004 */  sw      $t6, 0x0004($a0)           ## 00000004
/* 012FC 80801E8C AC8F0008 */  sw      $t7, 0x0008($a0)           ## 00000008
/* 01300 80801E90 AC9801D4 */  sw      $t8, 0x01D4($a0)           ## 000001D4
/* 01304 80801E94 AC80020C */  sw      $zero, 0x020C($a0)         ## 0000020C
/* 01308 80801E98 AC8001D8 */  sw      $zero, 0x01D8($a0)         ## 000001D8
/* 0130C 80801E9C AC8001E0 */  sw      $zero, 0x01E0($a0)         ## 000001E0
/* 01310 80801EA0 AC9901E4 */  sw      $t9, 0x01E4($a0)           ## 000001E4
/* 01314 80801EA4 AC8801E8 */  sw      $t0, 0x01E8($a0)           ## 000001E8
/* 01318 80801EA8 AC8901EC */  sw      $t1, 0x01EC($a0)           ## 000001EC
/* 0131C 80801EAC AC8A01F0 */  sw      $t2, 0x01F0($a0)           ## 000001F0
/* 01320 80801EB0 AC8B01F4 */  sw      $t3, 0x01F4($a0)           ## 000001F4
/* 01324 80801EB4 AC8C01F8 */  sw      $t4, 0x01F8($a0)           ## 000001F8
/* 01328 80801EB8 AC8001DC */  sw      $zero, 0x01DC($a0)         ## 000001DC
/* 0132C 80801EBC AC800208 */  sw      $zero, 0x0208($a0)         ## 00000208
/* 01330 80801EC0 AC8D01D0 */  sw      $t5, 0x01D0($a0)           ## 000001D0
/* 01334 80801EC4 8E050000 */  lw      $a1, 0x0000($s0)           ## 00000000
/* 01338 80801EC8 0C02A89E */  jal     func_800AA278              
/* 0133C 80801ECC 248400A8 */  addiu   $a0, $a0, 0x00A8           ## $a0 = 000000A8
/* 01340 80801ED0 3C048016 */  lui     $a0, 0x8016                ## $a0 = 80160000
/* 01344 80801ED4 240E000A */  addiu   $t6, $zero, 0x000A         ## $t6 = 0000000A
/* 01348 80801ED8 2484FA90 */  addiu   $a0, $a0, 0xFA90           ## $a0 = 8015FA90
/* 0134C 80801EDC AE0E01C8 */  sw      $t6, 0x01C8($s0)           ## 000001C8
/* 01350 80801EE0 AE00021C */  sw      $zero, 0x021C($s0)         ## 0000021C
/* 01354 80801EE4 AE000220 */  sw      $zero, 0x0220($s0)         ## 00000220
/* 01358 80801EE8 AE000224 */  sw      $zero, 0x0224($s0)         ## 00000224
/* 0135C 80801EEC AE000228 */  sw      $zero, 0x0228($s0)         ## 00000228
/* 01360 80801EF0 AE00022C */  sw      $zero, 0x022C($s0)         ## 0000022C
/* 01364 80801EF4 AE000230 */  sw      $zero, 0x0230($s0)         ## 00000230
/* 01368 80801EF8 AE000234 */  sw      $zero, 0x0234($s0)         ## 00000234
/* 0136C 80801EFC 8C820000 */  lw      $v0, 0x0000($a0)           ## 8015FA90
/* 01370 80801F00 3C0B01AA */  lui     $t3, 0x01AA                ## $t3 = 01AA0000
/* 01374 80801F04 3C068080 */  lui     $a2, %hi(D_808035CC)       ## $a2 = 80800000
/* 01378 80801F08 84431434 */  lh      $v1, 0x1434($v0)           ## 00001434
/* 0137C 80801F0C 240A0001 */  addiu   $t2, $zero, 0x0001         ## $t2 = 00000001
/* 01380 80801F10 24C635CC */  addiu   $a2, $a2, %lo(D_808035CC)  ## $a2 = 808035CC
/* 01384 80801F14 0460000D */  bltz    $v1, .L80801F4C            
/* 01388 80801F18 256B0200 */  addiu   $t3, $t3, 0x0200           ## $t3 = 01AA0200
/* 0138C 80801F1C 8E0F01D0 */  lw      $t7, 0x01D0($s0)           ## 000001D0
/* 01390 80801F20 006F082A */  slt     $at, $v1, $t7              
/* 01394 80801F24 10200009 */  beq     $at, $zero, .L80801F4C     
/* 01398 80801F28 00000000 */  nop
/* 0139C 80801F2C AE0301D8 */  sw      $v1, 0x01D8($s0)           ## 000001D8
/* 013A0 80801F30 8C980000 */  lw      $t8, 0x0000($a0)           ## 8015FA90
/* 013A4 80801F34 87191436 */  lh      $t9, 0x1436($t8)           ## 00001436
/* 013A8 80801F38 AE19020C */  sw      $t9, 0x020C($s0)           ## 0000020C
/* 013AC 80801F3C 8C880000 */  lw      $t0, 0x0000($a0)           ## 8015FA90
/* 013B0 80801F40 85091438 */  lh      $t1, 0x1438($t0)           ## 00001438
/* 013B4 80801F44 AE0901DC */  sw      $t1, 0x01DC($s0)           ## 000001DC
/* 013B8 80801F48 8C820000 */  lw      $v0, 0x0000($a0)           ## 8015FA90
.L80801F4C:
/* 013BC 80801F4C 3C0301AA */  lui     $v1, 0x01AA                ## $v1 = 01AA0000
/* 013C0 80801F50 2463E000 */  addiu   $v1, $v1, 0xE000           ## $v1 = 01A9E000
/* 013C4 80801F54 A44A0110 */  sh      $t2, 0x0110($v0)           ## 00000110
/* 013C8 80801F58 01632823 */  subu    $a1, $t3, $v1              
/* 013CC 80801F5C AFA5002C */  sw      $a1, 0x002C($sp)           
/* 013D0 80801F60 AFA30030 */  sw      $v1, 0x0030($sp)           
/* 013D4 80801F64 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 013D8 80801F68 0C031521 */  jal     Game_Alloc              
/* 013DC 80801F6C 2407045A */  addiu   $a3, $zero, 0x045A         ## $a3 = 0000045A
/* 013E0 80801F70 AE020238 */  sw      $v0, 0x0238($s0)           ## 00000238
/* 013E4 80801F74 3C078080 */  lui     $a3, %hi(D_808035DC)       ## $a3 = 80800000
/* 013E8 80801F78 240C045B */  addiu   $t4, $zero, 0x045B         ## $t4 = 0000045B
/* 013EC 80801F7C AFAC0010 */  sw      $t4, 0x0010($sp)           
/* 013F0 80801F80 24E735DC */  addiu   $a3, $a3, %lo(D_808035DC)  ## $a3 = 808035DC
/* 013F4 80801F84 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 013F8 80801F88 8FA50030 */  lw      $a1, 0x0030($sp)           
/* 013FC 80801F8C 0C0006A8 */  jal     DmaMgr_SendRequest1              
/* 01400 80801F90 00402025 */  or      $a0, $v0, $zero            ## $a0 = 00000000
/* 01404 80801F94 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 01408 80801F98 3C038016 */  lui     $v1, 0x8016                ## $v1 = 80160000
/* 0140C 80801F9C 2463E660 */  addiu   $v1, $v1, 0xE660           ## $v1 = 8015E660
/* 01410 80801FA0 340D8000 */  ori     $t5, $zero, 0x8000         ## $t5 = 00008000
/* 01414 80801FA4 240E0001 */  addiu   $t6, $zero, 0x0001         ## $t6 = 00000001
/* 01418 80801FA8 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 0141C 80801FAC AC6D0008 */  sw      $t5, 0x0008($v1)           ## 8015E668
/* 01420 80801FB0 AC6E0004 */  sw      $t6, 0x0004($v1)           ## 8015E664
/* 01424 80801FB4 03E00008 */  jr      $ra                        
/* 01428 80801FB8 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 0142C 80801FBC 00000000 */  nop
