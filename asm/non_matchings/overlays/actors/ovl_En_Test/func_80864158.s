glabel func_80864158
/* 04B08 80864158 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 04B0C 8086415C AFA5001C */  sw      $a1, 0x001C($sp)
/* 04B10 80864160 AFBF0014 */  sw      $ra, 0x0014($sp)
/* 04B14 80864164 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 04B18 80864168 3C050601 */  lui     $a1, 0x0601                ## $a1 = 06010000
/* 04B1C 8086416C 24A5E2B0 */  addiu   $a1, $a1, 0xE2B0           ## $a1 = 0600E2B0
/* 04B20 80864170 AFA70018 */  sw      $a3, 0x0018($sp)
/* 04B24 80864174 24840188 */  addiu   $a0, $a0, 0x0188           ## $a0 = 00000188
/* 04B28 80864178 0C0294D3 */  jal     SkelAnime_ChangeAnimTransitionRepeat
/* 04B2C 8086417C 3C06C000 */  lui     $a2, 0xC000                ## $a2 = C0000000
/* 04B30 80864180 8FA70018 */  lw      $a3, 0x0018($sp)
/* 04B34 80864184 C7A4001C */  lwc1    $f4, 0x001C($sp)
/* 04B38 80864188 84EE00B6 */  lh      $t6, 0x00B6($a3)           ## 000000B6
/* 04B3C 8086418C E4E40068 */  swc1    $f4, 0x0068($a3)           ## 00000068
/* 04B40 80864190 25CF3FFF */  addiu   $t7, $t6, 0x3FFF           ## $t7 = 00003FFF
/* 04B44 80864194 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 04B48 80864198 A4EF0032 */  sh      $t7, 0x0032($a3)           ## 00000032
/* 04B4C 8086419C 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 04B50 808641A0 44813000 */  mtc1    $at, $f6                   ## $f6 = 20.00
/* 04B54 808641A4 3C014170 */  lui     $at, 0x4170                ## $at = 41700000
/* 04B58 808641A8 44815000 */  mtc1    $at, $f10                  ## $f10 = 15.00
/* 04B5C 808641AC 46060202 */  mul.s   $f8, $f0, $f6
/* 04B60 808641B0 8FA40018 */  lw      $a0, 0x0018($sp)
/* 04B64 808641B4 24080018 */  addiu   $t0, $zero, 0x0018         ## $t0 = 00000018
/* 04B68 808641B8 3C058086 */  lui     $a1, %hi(func_808628C8)    ## $a1 = 80860000
/* 04B6C 808641BC 24A528C8 */  addiu   $a1, $a1, %lo(func_808628C8) ## $a1 = 808628C8
/* 04B70 808641C0 A08807C8 */  sb      $t0, 0x07C8($a0)           ## 000007C8
/* 04B74 808641C4 460A4400 */  add.s   $f16, $f8, $f10
/* 04B78 808641C8 4600848D */  trunc.w.s $f18, $f16
/* 04B7C 808641CC 44199000 */  mfc1    $t9, $f18
/* 04B80 808641D0 0C217D94 */  jal     EnTest_SetupAction
/* 04B84 808641D4 AC9907E8 */  sw      $t9, 0x07E8($a0)           ## 000007E8
/* 04B88 808641D8 8FBF0014 */  lw      $ra, 0x0014($sp)
/* 04B8C 808641DC 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 04B90 808641E0 03E00008 */  jr      $ra
/* 04B94 808641E4 00000000 */  nop
