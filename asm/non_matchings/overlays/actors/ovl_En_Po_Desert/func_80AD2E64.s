glabel func_80AD2E64
/* 001B4 80AD2E64 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 001B8 80AD2E68 AFBF0014 */  sw      $ra, 0x0014($sp)
/* 001BC 80AD2E6C AFA50024 */  sw      $a1, 0x0024($sp)
/* 001C0 80AD2E70 3C0F0001 */  lui     $t7, 0x0001                ## $t7 = 00010000
/* 001C4 80AD2E74 8498001C */  lh      $t8, 0x001C($a0)           ## 0000001C
/* 001C8 80AD2E78 01E57821 */  addu    $t7, $t7, $a1
/* 001CC 80AD2E7C 8DEF1E08 */  lw      $t7, 0x1E08($t7)           ## 00011E08
/* 001D0 80AD2E80 0018C8C0 */  sll     $t9, $t8,  3
/* 001D4 80AD2E84 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 001D8 80AD2E88 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 001DC 80AD2E8C 01F94021 */  addu    $t0, $t7, $t9
/* 001E0 80AD2E90 AFA8001C */  sw      $t0, 0x001C($sp)
/* 001E4 80AD2E94 24A51360 */  addiu   $a1, $a1, 0x1360           ## $a1 = 06001360
/* 001E8 80AD2E98 AFA70020 */  sw      $a3, 0x0020($sp)
/* 001EC 80AD2E9C 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 001F0 80AD2EA0 0C0294D3 */  jal     SkelAnime_ChangeAnimTransitionRepeat
/* 001F4 80AD2EA4 3C06C0C0 */  lui     $a2, 0xC0C0                ## $a2 = C0C00000
/* 001F8 80AD2EA8 8FA9001C */  lw      $t1, 0x001C($sp)
/* 001FC 80AD2EAC 8FA40020 */  lw      $a0, 0x0020($sp)
/* 00200 80AD2EB0 3C0D8016 */  lui     $t5, %hi(gSegments)
/* 00204 80AD2EB4 8D230004 */  lw      $v1, 0x0004($t1)           ## 00000004
/* 00208 80AD2EB8 8C8F0198 */  lw      $t7, 0x0198($a0)           ## 00000198
/* 0020C 80AD2EBC 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 00210 80AD2EC0 00035100 */  sll     $t2, $v1,  4
/* 00214 80AD2EC4 000A5F02 */  srl     $t3, $t2, 28
/* 00218 80AD2EC8 000B6080 */  sll     $t4, $t3,  2
/* 0021C 80AD2ECC 01AC6821 */  addu    $t5, $t5, $t4
/* 00220 80AD2ED0 8DAD6FA8 */  lw      $t5, %lo(gSegments)($t5)
/* 00224 80AD2ED4 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 00228 80AD2ED8 000FC880 */  sll     $t9, $t7,  2
/* 0022C 80AD2EDC 00617024 */  and     $t6, $v1, $at
/* 00230 80AD2EE0 032FC823 */  subu    $t9, $t9, $t7
/* 00234 80AD2EE4 0019C840 */  sll     $t9, $t9,  1
/* 00238 80AD2EE8 01AEC021 */  addu    $t8, $t5, $t6
/* 0023C 80AD2EEC 03191021 */  addu    $v0, $t8, $t9
/* 00240 80AD2EF0 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 00244 80AD2EF4 00411021 */  addu    $v0, $v0, $at
/* 00248 80AD2EF8 84480000 */  lh      $t0, 0x0000($v0)           ## 00000000
/* 0024C 80AD2EFC 24850008 */  addiu   $a1, $a0, 0x0008           ## $a1 = 00000008
/* 00250 80AD2F00 44882000 */  mtc1    $t0, $f4                   ## $f4 = 0.00
/* 00254 80AD2F04 00000000 */  nop
/* 00258 80AD2F08 468021A0 */  cvt.s.w $f6, $f4
/* 0025C 80AD2F0C E4860008 */  swc1    $f6, 0x0008($a0)           ## 00000008
/* 00260 80AD2F10 84490002 */  lh      $t1, 0x0002($v0)           ## 00000002
/* 00264 80AD2F14 44894000 */  mtc1    $t1, $f8                   ## $f8 = 0.00
/* 00268 80AD2F18 00000000 */  nop
/* 0026C 80AD2F1C 468042A0 */  cvt.s.w $f10, $f8
/* 00270 80AD2F20 E48A000C */  swc1    $f10, 0x000C($a0)          ## 0000000C
/* 00274 80AD2F24 844A0004 */  lh      $t2, 0x0004($v0)           ## 00000004
/* 00278 80AD2F28 448A8000 */  mtc1    $t2, $f16                  ## $f16 = 0.00
/* 0027C 80AD2F2C 00000000 */  nop
/* 00280 80AD2F30 468084A0 */  cvt.s.w $f18, $f16
/* 00284 80AD2F34 0C00B6EC */  jal     ActorSearch_PosDistanceXZ
/* 00288 80AD2F38 E4920010 */  swc1    $f18, 0x0010($a0)          ## 00000010
/* 0028C 80AD2F3C 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 00290 80AD2F40 44811000 */  mtc1    $at, $f2                   ## $f2 = 1.00
/* 00294 80AD2F44 8FA70020 */  lw      $a3, 0x0020($sp)
/* 00298 80AD2F48 3C1880AD */  lui     $t8, %hi(func_80AD30D0)    ## $t8 = 80AD0000
/* 0029C 80AD2F4C 4602003C */  c.lt.s  $f0, $f2
/* 002A0 80AD2F50 271830D0 */  addiu   $t8, $t8, %lo(func_80AD30D0) ## $t8 = 80AD30D0
/* 002A4 80AD2F54 E4E0019C */  swc1    $f0, 0x019C($a3)           ## 0000019C
/* 002A8 80AD2F58 45020004 */  bc1fl   .L80AD2F6C
/* 002AC 80AD2F5C C4E4019C */  lwc1    $f4, 0x019C($a3)           ## 0000019C
/* 002B0 80AD2F60 10000003 */  beq     $zero, $zero, .L80AD2F70
/* 002B4 80AD2F64 E4E2019C */  swc1    $f2, 0x019C($a3)           ## 0000019C
/* 002B8 80AD2F68 C4E4019C */  lwc1    $f4, 0x019C($a3)           ## 0000019C
.L80AD2F6C:
/* 002BC 80AD2F6C E4E4019C */  swc1    $f4, 0x019C($a3)           ## 0000019C
.L80AD2F70:
/* 002C0 80AD2F70 C4E6000C */  lwc1    $f6, 0x000C($a3)           ## 0000000C
/* 002C4 80AD2F74 C4E80028 */  lwc1    $f8, 0x0028($a3)           ## 00000028
/* 002C8 80AD2F78 8CEB0198 */  lw      $t3, 0x0198($a3)           ## 00000198
/* 002CC 80AD2F7C 44808000 */  mtc1    $zero, $f16                ## $f16 = 0.00
/* 002D0 80AD2F80 46083281 */  sub.s   $f10, $f6, $f8
/* 002D4 80AD2F84 256C0001 */  addiu   $t4, $t3, 0x0001           ## $t4 = 00000001
/* 002D8 80AD2F88 ACEC0198 */  sw      $t4, 0x0198($a3)           ## 00000198
/* 002DC 80AD2F8C E4F00068 */  swc1    $f16, 0x0068($a3)          ## 00000068
/* 002E0 80AD2F90 E4EA01A0 */  swc1    $f10, 0x01A0($a3)          ## 000001A0
/* 002E4 80AD2F94 8FAE001C */  lw      $t6, 0x001C($sp)
/* 002E8 80AD2F98 91CF0000 */  lbu     $t7, 0x0000($t6)           ## 00000000
/* 002EC 80AD2F9C 558F0003 */  bnel    $t4, $t7, .L80AD2FAC
/* 002F0 80AD2FA0 ACF80190 */  sw      $t8, 0x0190($a3)           ## 00000190
/* 002F4 80AD2FA4 ACE00198 */  sw      $zero, 0x0198($a3)         ## 00000198
/* 002F8 80AD2FA8 ACF80190 */  sw      $t8, 0x0190($a3)           ## 00000190
.L80AD2FAC:
/* 002FC 80AD2FAC 8FBF0014 */  lw      $ra, 0x0014($sp)
/* 00300 80AD2FB0 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 00304 80AD2FB4 03E00008 */  jr      $ra
/* 00308 80AD2FB8 00000000 */  nop
