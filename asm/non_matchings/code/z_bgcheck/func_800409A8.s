glabel func_800409A8
/* AB7B48 800409A8 27BDFF60 */  addiu $sp, $sp, -0xa0
/* AB7B4C 800409AC 8FAF00B0 */  lw    $t7, 0xb0($sp)
/* AB7B50 800409B0 AFBF0064 */  sw    $ra, 0x64($sp)
/* AB7B54 800409B4 AFBE0060 */  sw    $fp, 0x60($sp)
/* AB7B58 800409B8 AFB7005C */  sw    $s7, 0x5c($sp)
/* AB7B5C 800409BC AFB60058 */  sw    $s6, 0x58($sp)
/* AB7B60 800409C0 AFB50054 */  sw    $s5, 0x54($sp)
/* AB7B64 800409C4 AFB40050 */  sw    $s4, 0x50($sp)
/* AB7B68 800409C8 AFB3004C */  sw    $s3, 0x4c($sp)
/* AB7B6C 800409CC AFB20048 */  sw    $s2, 0x48($sp)
/* AB7B70 800409D0 AFB10044 */  sw    $s1, 0x44($sp)
/* AB7B74 800409D4 AFB00040 */  sw    $s0, 0x40($sp)
/* AB7B78 800409D8 F7B40038 */  sdc1  $f20, 0x38($sp)
/* AB7B7C 800409DC AFA500A4 */  sw    $a1, 0xa4($sp)
/* AB7B80 800409E0 AFA00090 */  sw    $zero, 0x90($sp)
/* AB7B84 800409E4 8DF90000 */  lw    $t9, ($t7)
/* AB7B88 800409E8 27AE0094 */  addiu $t6, $sp, 0x94
/* AB7B8C 800409EC 0080A825 */  move  $s5, $a0
/* AB7B90 800409F0 ADD90000 */  sw    $t9, ($t6)
/* AB7B94 800409F4 8DF80004 */  lw    $t8, 4($t7)
/* AB7B98 800409F8 00C0B825 */  move  $s7, $a2
/* AB7B9C 800409FC 00E0F025 */  move  $fp, $a3
/* AB7BA0 80040A00 ADD80004 */  sw    $t8, 4($t6)
/* AB7BA4 80040A04 8DF90008 */  lw    $t9, 8($t7)
/* AB7BA8 80040A08 0000A025 */  move  $s4, $zero
/* AB7BAC 80040A0C 0080B025 */  move  $s6, $a0
/* AB7BB0 80040A10 ADD90008 */  sw    $t9, 8($t6)
/* AB7BB4 80040A14 C7B400B4 */  lwc1  $f20, 0xb4($sp)
.L80040A18:
/* AB7BB8 80040A18 96C813DC */  lhu   $t0, 0x13dc($s6)
/* AB7BBC 80040A1C 00141080 */  sll   $v0, $s4, 2
/* AB7BC0 80040A20 00541023 */  subu  $v0, $v0, $s4
/* AB7BC4 80040A24 31090001 */  andi  $t1, $t0, 1
/* AB7BC8 80040A28 1120005C */  beqz  $t1, .L80040B9C
/* AB7BCC 80040A2C 000210C0 */   sll   $v0, $v0, 3
/* AB7BD0 80040A30 00541021 */  addu  $v0, $v0, $s4
/* AB7BD4 80040A34 00021080 */  sll   $v0, $v0, 2
/* AB7BD8 80040A38 02A29821 */  addu  $s3, $s5, $v0
/* AB7BDC 80040A3C 8E6B0054 */  lw    $t3, 0x54($s3)
/* AB7BE0 80040A40 8FAA00C0 */  lw    $t2, 0xc0($sp)
/* AB7BE4 80040A44 02A21821 */  addu  $v1, $s5, $v0
/* AB7BE8 80040A48 C7A40098 */  lwc1  $f4, 0x98($sp)
/* AB7BEC 80040A4C 514B0054 */  beql  $t2, $t3, .L80040BA0
/* AB7BF0 80040A50 26940001 */   addiu $s4, $s4, 1
/* AB7BF4 80040A54 C46600B0 */  lwc1  $f6, 0xb0($v1)
/* AB7BF8 80040A58 24700054 */  addiu $s0, $v1, 0x54
/* AB7BFC 80040A5C 4606203C */  c.lt.s $f4, $f6
/* AB7C00 80040A60 00000000 */  nop   
/* AB7C04 80040A64 4503004E */  bc1tl .L80040BA0
/* AB7C08 80040A68 26940001 */   addiu $s4, $s4, 1
/* AB7C0C 80040A6C C6080060 */  lwc1  $f8, 0x60($s0)
/* AB7C10 80040A70 4604403C */  c.lt.s $f8, $f4
/* AB7C14 80040A74 00000000 */  nop   
/* AB7C18 80040A78 45030049 */  bc1tl .L80040BA0
/* AB7C1C 80040A7C 26940001 */   addiu $s4, $s4, 1
/* AB7C20 80040A80 4600A28D */  trunc.w.s $f10, $f20
/* AB7C24 80040A84 860D005A */  lh    $t5, 0x5a($s0)
/* AB7C28 80040A88 860F0054 */  lh    $t7, 0x54($s0)
/* AB7C2C 80040A8C 86180058 */  lh    $t8, 0x58($s0)
/* AB7C30 80040A90 44125000 */  mfc1  $s2, $f10
/* AB7C34 80040A94 448F9000 */  mtc1  $t7, $f18
/* AB7C38 80040A98 44982000 */  mtc1  $t8, $f4
/* AB7C3C 80040A9C 00129400 */  sll   $s2, $s2, 0x10
/* AB7C40 80040AA0 00129403 */  sra   $s2, $s2, 0x10
/* AB7C44 80040AA4 01B27021 */  addu  $t6, $t5, $s2
/* AB7C48 80040AA8 A60E005A */  sh    $t6, 0x5a($s0)
/* AB7C4C 80040AAC 8602005A */  lh    $v0, 0x5a($s0)
/* AB7C50 80040AB0 468091A0 */  cvt.s.w $f6, $f18
/* AB7C54 80040AB4 C7A80094 */  lwc1  $f8, 0x94($sp)
/* AB7C58 80040AB8 44828000 */  mtc1  $v0, $f16
/* AB7C5C 80040ABC 26110054 */  addiu $s1, $s0, 0x54
/* AB7C60 80040AC0 02202025 */  move  $a0, $s1
/* AB7C64 80040AC4 46808020 */  cvt.s.w $f0, $f16
/* AB7C68 80040AC8 C7B0009C */  lwc1  $f16, 0x9c($sp)
/* AB7C6C 80040ACC 468022A0 */  cvt.s.w $f10, $f4
/* AB7C70 80040AD0 46000482 */  mul.s $f18, $f0, $f0
/* AB7C74 80040AD4 46083081 */  sub.s $f2, $f6, $f8
/* AB7C78 80040AD8 46105301 */  sub.s $f12, $f10, $f16
/* AB7C7C 80040ADC 46021182 */  mul.s $f6, $f2, $f2
/* AB7C80 80040AE0 00000000 */  nop   
/* AB7C84 80040AE4 460C6102 */  mul.s $f4, $f12, $f12
/* AB7C88 80040AE8 46043280 */  add.s $f10, $f6, $f4
/* AB7C8C 80040AEC 460A903C */  c.lt.s $f18, $f10
/* AB7C90 80040AF0 00000000 */  nop   
/* AB7C94 80040AF4 4501000C */  bc1t  .L80040B28
/* AB7C98 80040AF8 00000000 */   nop   
/* AB7C9C 80040AFC 44054000 */  mfc1  $a1, $f8
/* AB7CA0 80040B00 0C03413C */  jal   Math3D_XYInSphere
/* AB7CA4 80040B04 8FA60098 */   lw    $a2, 0x98($sp)
/* AB7CA8 80040B08 1440000A */  bnez  $v0, .L80040B34
/* AB7CAC 80040B0C 02202025 */   move  $a0, $s1
/* AB7CB0 80040B10 8FA50098 */  lw    $a1, 0x98($sp)
/* AB7CB4 80040B14 0C034158 */  jal   Math3D_YZInSphere
/* AB7CB8 80040B18 8FA6009C */   lw    $a2, 0x9c($sp)
/* AB7CBC 80040B1C 54400006 */  bnezl $v0, .L80040B38
/* AB7CC0 80040B20 8608005A */   lh    $t0, 0x5a($s0)
/* AB7CC4 80040B24 8602005A */  lh    $v0, 0x5a($s0)
.L80040B28:
/* AB7CC8 80040B28 0052C823 */  subu  $t9, $v0, $s2
/* AB7CCC 80040B2C 1000001B */  b     .L80040B9C
/* AB7CD0 80040B30 A619005A */   sh    $t9, 0x5a($s0)
.L80040B34:
/* AB7CD4 80040B34 8608005A */  lh    $t0, 0x5a($s0)
.L80040B38:
/* AB7CD8 80040B38 27AC0094 */  addiu $t4, $sp, 0x94
/* AB7CDC 80040B3C 02A02025 */  move  $a0, $s5
/* AB7CE0 80040B40 01124823 */  subu  $t1, $t0, $s2
/* AB7CE4 80040B44 A609005A */  sh    $t1, 0x5a($s0)
/* AB7CE8 80040B48 8FAB00BC */  lw    $t3, 0xbc($sp)
/* AB7CEC 80040B4C 8FAA00B8 */  lw    $t2, 0xb8($sp)
/* AB7CF0 80040B50 AFB40028 */  sw    $s4, 0x28($sp)
/* AB7CF4 80040B54 E7B40024 */  swc1  $f20, 0x24($sp)
/* AB7CF8 80040B58 AFAC0020 */  sw    $t4, 0x20($sp)
/* AB7CFC 80040B5C AFBE0014 */  sw    $fp, 0x14($sp)
/* AB7D00 80040B60 AFB70010 */  sw    $s7, 0x10($sp)
/* AB7D04 80040B64 97A500A6 */  lhu   $a1, 0xa6($sp)
/* AB7D08 80040B68 26A60050 */  addiu $a2, $s5, 0x50
/* AB7D0C 80040B6C 26670060 */  addiu $a3, $s3, 0x60
/* AB7D10 80040B70 AFAB001C */  sw    $t3, 0x1c($sp)
/* AB7D14 80040B74 0C0100A1 */  jal   func_80040284
/* AB7D18 80040B78 AFAA0018 */   sw    $t2, 0x18($sp)
/* AB7D1C 80040B7C 50400008 */  beql  $v0, $zero, .L80040BA0
/* AB7D20 80040B80 26940001 */   addiu $s4, $s4, 1
/* AB7D24 80040B84 C6F00000 */  lwc1  $f16, ($s7)
/* AB7D28 80040B88 240D0001 */  li    $t5, 1
/* AB7D2C 80040B8C E7B00094 */  swc1  $f16, 0x94($sp)
/* AB7D30 80040B90 C7C60000 */  lwc1  $f6, ($fp)
/* AB7D34 80040B94 AFAD0090 */  sw    $t5, 0x90($sp)
/* AB7D38 80040B98 E7A6009C */  swc1  $f6, 0x9c($sp)
.L80040B9C:
/* AB7D3C 80040B9C 26940001 */  addiu $s4, $s4, 1
.L80040BA0:
/* AB7D40 80040BA0 24010032 */  li    $at, 50
/* AB7D44 80040BA4 1681FF9C */  bne   $s4, $at, .L80040A18
/* AB7D48 80040BA8 26D60002 */   addiu $s6, $s6, 2
/* AB7D4C 80040BAC 8FBF0064 */  lw    $ra, 0x64($sp)
/* AB7D50 80040BB0 8FA20090 */  lw    $v0, 0x90($sp)
/* AB7D54 80040BB4 D7B40038 */  ldc1  $f20, 0x38($sp)
/* AB7D58 80040BB8 8FB00040 */  lw    $s0, 0x40($sp)
/* AB7D5C 80040BBC 8FB10044 */  lw    $s1, 0x44($sp)
/* AB7D60 80040BC0 8FB20048 */  lw    $s2, 0x48($sp)
/* AB7D64 80040BC4 8FB3004C */  lw    $s3, 0x4c($sp)
/* AB7D68 80040BC8 8FB40050 */  lw    $s4, 0x50($sp)
/* AB7D6C 80040BCC 8FB50054 */  lw    $s5, 0x54($sp)
/* AB7D70 80040BD0 8FB60058 */  lw    $s6, 0x58($sp)
/* AB7D74 80040BD4 8FB7005C */  lw    $s7, 0x5c($sp)
/* AB7D78 80040BD8 8FBE0060 */  lw    $fp, 0x60($sp)
/* AB7D7C 80040BDC 03E00008 */  jr    $ra
/* AB7D80 80040BE0 27BD00A0 */   addiu $sp, $sp, 0xa0

