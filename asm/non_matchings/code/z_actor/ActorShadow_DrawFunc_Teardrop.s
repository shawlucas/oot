.rdata
glabel D_801360F0
    .asciz "../z_actor.c"
    .balign 4

glabel D_80136100
    .asciz "../z_actor.c"
    .balign 4

.late_rodata
glabel D_80136ADC
    .float 0.3

glabel D_80136AE0
    .float 0.02

glabel D_80136AE4
    .float 0.033333335

glabel D_80136AE8
    .float 0.014285714

.text
glabel ActorShadow_DrawFoot
/* AA2A64 8002B8C4 27BDFEC8 */  addiu $sp, $sp, -0x138
/* AA2A68 8002B8C8 AFBF007C */  sw    $ra, 0x7c($sp)
/* AA2A6C 8002B8CC AFBE0078 */  sw    $fp, 0x78($sp)
/* AA2A70 8002B8D0 AFB70074 */  sw    $s7, 0x74($sp)
/* AA2A74 8002B8D4 AFB60070 */  sw    $s6, 0x70($sp)
/* AA2A78 8002B8D8 AFB5006C */  sw    $s5, 0x6c($sp)
/* AA2A7C 8002B8DC AFB40068 */  sw    $s4, 0x68($sp)
/* AA2A80 8002B8E0 AFB30064 */  sw    $s3, 0x64($sp)
/* AA2A84 8002B8E4 AFB20060 */  sw    $s2, 0x60($sp)
/* AA2A88 8002B8E8 AFB1005C */  sw    $s1, 0x5c($sp)
/* AA2A8C 8002B8EC AFB00058 */  sw    $s0, 0x58($sp)
/* AA2A90 8002B8F0 F7BE0050 */  sdc1  $f30, 0x50($sp)
/* AA2A94 8002B8F4 F7BC0048 */  sdc1  $f28, 0x48($sp)
/* AA2A98 8002B8F8 F7BA0040 */  sdc1  $f26, 0x40($sp)
/* AA2A9C 8002B8FC F7B80038 */  sdc1  $f24, 0x38($sp)
/* AA2AA0 8002B900 F7B60030 */  sdc1  $f22, 0x30($sp)
/* AA2AA4 8002B904 F7B40028 */  sdc1  $f20, 0x28($sp)
/* AA2AA8 8002B908 AFA5013C */  sw    $a1, 0x13c($sp)
/* AA2AAC 8002B90C C4860080 */  lwc1  $f6, 0x80($a0)
/* AA2AB0 8002B910 C4840028 */  lwc1  $f4, 0x28($a0)
/* AA2AB4 8002B914 3C0141A0 */  li    $at, 0x41A00000 # 0.000000
/* AA2AB8 8002B918 44816000 */  mtc1  $at, $f12
/* AA2ABC 8002B91C 46062501 */  sub.s $f20, $f4, $f6
/* AA2AC0 8002B920 00C0A025 */  move  $s4, $a2
/* AA2AC4 8002B924 0080F025 */  move  $fp, $a0
/* AA2AC8 8002B928 3C013F80 */  lui   $at, 0x3f80
/* AA2ACC 8002B92C 4614603C */  c.lt.s $f12, $f20
/* AA2AD0 8002B930 02803025 */  move  $a2, $s4
/* AA2AD4 8002B934 45020044 */  bc1fl .L8002BA48
/* AA2AD8 8002B938 3C013F80 */   li    $at, 0x3F800000 # 0.000000
/* AA2ADC 8002B93C 4481F000 */  mtc1  $at, $f30
/* AA2AE0 8002B940 3C018013 */  lui   $at, %hi(D_80136ADC)
/* AA2AE4 8002B944 C49600C4 */  lwc1  $f22, 0xc4($a0)
/* AA2AE8 8002B948 C4286ADC */  lwc1  $f8, %lo(D_80136ADC)($at)
/* AA2AEC 8002B94C 460CA401 */  sub.s $f16, $f20, $f12
/* AA2AF0 8002B950 3C018013 */  lui   $at, %hi(D_80136AE0)
/* AA2AF4 8002B954 4608B282 */  mul.s $f10, $f22, $f8
/* AA2AF8 8002B958 908200C8 */  lbu   $v0, 0xc8($a0)
/* AA2AFC 8002B95C 44822000 */  mtc1  $v0, $f4
/* AA2B00 8002B960 00408025 */  move  $s0, $v0
/* AA2B04 8002B964 E48A00C4 */  swc1  $f10, 0xc4($a0)
/* AA2B08 8002B968 C4326AE0 */  lwc1  $f18, %lo(D_80136AE0)($at)
/* AA2B0C 8002B96C 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AA2B10 8002B970 03C02025 */  move  $a0, $fp
/* AA2B14 8002B974 46128082 */  mul.s $f2, $f16, $f18
/* AA2B18 8002B978 4602F03C */  c.lt.s $f30, $f2
/* AA2B1C 8002B97C 00000000 */  nop   
/* AA2B20 8002B980 45020004 */  bc1fl .L8002B994
/* AA2B24 8002B984 46001006 */   mov.s $f0, $f2
/* AA2B28 8002B988 10000002 */  b     .L8002B994
/* AA2B2C 8002B98C 4600F006 */   mov.s $f0, $f30
/* AA2B30 8002B990 46001006 */  mov.s $f0, $f2
.L8002B994:
/* AA2B34 8002B994 04410004 */  bgez  $v0, .L8002B9A8
/* AA2B38 8002B998 468021A0 */   cvt.s.w $f6, $f4
/* AA2B3C 8002B99C 44814000 */  mtc1  $at, $f8
/* AA2B40 8002B9A0 00000000 */  nop   
/* AA2B44 8002B9A4 46083180 */  add.s $f6, $f6, $f8
.L8002B9A8:
/* AA2B48 8002B9A8 46060282 */  mul.s $f10, $f0, $f6
/* AA2B4C 8002B9AC 240F0001 */  li    $t7, 1
/* AA2B50 8002B9B0 3C014F00 */  li    $at, 0x4F000000 # 0.000000
/* AA2B54 8002B9B4 444EF800 */  cfc1  $t6, $31
/* AA2B58 8002B9B8 44CFF800 */  ctc1  $t7, $31
/* AA2B5C 8002B9BC 00000000 */  nop   
/* AA2B60 8002B9C0 46005424 */  cvt.w.s $f16, $f10
/* AA2B64 8002B9C4 444FF800 */  cfc1  $t7, $31
/* AA2B68 8002B9C8 00000000 */  nop   
/* AA2B6C 8002B9CC 31EF0078 */  andi  $t7, $t7, 0x78
/* AA2B70 8002B9D0 51E00013 */  beql  $t7, $zero, .L8002BA20
/* AA2B74 8002B9D4 440F8000 */   mfc1  $t7, $f16
/* AA2B78 8002B9D8 44818000 */  mtc1  $at, $f16
/* AA2B7C 8002B9DC 240F0001 */  li    $t7, 1
/* AA2B80 8002B9E0 46105401 */  sub.s $f16, $f10, $f16
/* AA2B84 8002B9E4 44CFF800 */  ctc1  $t7, $31
/* AA2B88 8002B9E8 00000000 */  nop   
/* AA2B8C 8002B9EC 46008424 */  cvt.w.s $f16, $f16
/* AA2B90 8002B9F0 444FF800 */  cfc1  $t7, $31
/* AA2B94 8002B9F4 00000000 */  nop   
/* AA2B98 8002B9F8 31EF0078 */  andi  $t7, $t7, 0x78
/* AA2B9C 8002B9FC 15E00005 */  bnez  $t7, .L8002BA14
/* AA2BA0 8002BA00 00000000 */   nop   
/* AA2BA4 8002BA04 440F8000 */  mfc1  $t7, $f16
/* AA2BA8 8002BA08 3C018000 */  lui   $at, 0x8000
/* AA2BAC 8002BA0C 10000007 */  b     .L8002BA2C
/* AA2BB0 8002BA10 01E17825 */   or    $t7, $t7, $at
.L8002BA14:
/* AA2BB4 8002BA14 10000005 */  b     .L8002BA2C
/* AA2BB8 8002BA18 240FFFFF */   li    $t7, -1
/* AA2BBC 8002BA1C 440F8000 */  mfc1  $t7, $f16
.L8002BA20:
/* AA2BC0 8002BA20 00000000 */  nop   
/* AA2BC4 8002BA24 05E0FFFB */  bltz  $t7, .L8002BA14
/* AA2BC8 8002BA28 00000000 */   nop   
.L8002BA2C:
/* AA2BCC 8002BA2C 44CEF800 */  ctc1  $t6, $31
/* AA2BD0 8002BA30 A3CF00C8 */  sb    $t7, 0xc8($fp)
/* AA2BD4 8002BA34 0C00AD7B */  jal   ActorShadow_DrawFunc_Circle
/* AA2BD8 8002BA38 8FA5013C */   lw    $a1, 0x13c($sp)
/* AA2BDC 8002BA3C E7D600C4 */  swc1  $f22, 0xc4($fp)
/* AA2BE0 8002BA40 A3D000C8 */  sb    $s0, 0xc8($fp)
/* AA2BE4 8002BA44 3C013F80 */  li    $at, 0x3F800000 # 0.000000
.L8002BA48:
/* AA2BE8 8002BA48 4481F000 */  mtc1  $at, $f30
/* AA2BEC 8002BA4C 3C014348 */  li    $at, 0x43480000 # 0.000000
/* AA2BF0 8002BA50 44819000 */  mtc1  $at, $f18
/* AA2BF4 8002BA54 3C068013 */  lui   $a2, %hi(D_801360F0)
/* AA2BF8 8002BA58 8FB8013C */  lw    $t8, 0x13c($sp)
/* AA2BFC 8002BA5C 4612A03C */  c.lt.s $f20, $f18
/* AA2C00 8002BA60 27D700CC */  addiu $s7, $fp, 0xcc
/* AA2C04 8002BA64 27B900E0 */  addiu $t9, $sp, 0xe0
/* AA2C08 8002BA68 24C660F0 */  addiu $a2, %lo(D_801360F0) # addiu $a2, $a2, 0x60f0
/* AA2C0C 8002BA6C 450000BE */  bc1f  .L8002BD68
/* AA2C10 8002BA70 27A40098 */   addiu $a0, $sp, 0x98
/* AA2C14 8002BA74 93160000 */  lbu   $s6, ($t8)
/* AA2C18 8002BA78 AFB900AC */  sw    $t9, 0xac($sp)
/* AA2C1C 8002BA7C 8E850000 */  lw    $a1, ($s4)
/* AA2C20 8002BA80 240706CD */  li    $a3, 1741
/* AA2C24 8002BA84 26D6FFFE */  addiu $s6, $s6, -2
/* AA2C28 8002BA88 0C031AB1 */  jal   Graph_OpenDisps
/* AA2C2C 8002BA8C 00A08025 */   move  $s0, $a1
/* AA2C30 8002BA90 8E0402C0 */  lw    $a0, 0x2c0($s0)
/* AA2C34 8002BA94 0C024DDD */  jal   Gfx_CallSetupDL
/* AA2C38 8002BA98 2405002C */   li    $a1, 44
/* AA2C3C 8002BA9C 3C014248 */  li    $at, 0x42480000 # 0.000000
/* AA2C40 8002BAA0 4481E000 */  mtc1  $at, $f28
/* AA2C44 8002BAA4 AE0202C0 */  sw    $v0, 0x2c0($s0)
/* AA2C48 8002BAA8 3C0141F0 */  li    $at, 0x41F00000 # 0.000000
/* AA2C4C 8002BAAC A3C000C9 */  sb    $zero, 0xc9($fp)
/* AA2C50 8002BAB0 4481D000 */  mtc1  $at, $f26
/* AA2C54 8002BAB4 AFA000C0 */  sw    $zero, 0xc0($sp)
/* AA2C58 8002BAB8 24150002 */  li    $s5, 2
/* AA2C5C 8002BABC 27B300E8 */  addiu $s3, $sp, 0xe8
.L8002BAC0:
/* AA2C60 8002BAC0 C6E40004 */  lwc1  $f4, 4($s7)
/* AA2C64 8002BAC4 02802025 */  move  $a0, $s4
/* AA2C68 8002BAC8 02602825 */  move  $a1, $s3
/* AA2C6C 8002BACC 461C2200 */  add.s $f8, $f4, $f28
/* AA2C70 8002BAD0 02E03025 */  move  $a2, $s7
/* AA2C74 8002BAD4 0C02FF2E */  jal   func_800BFCB8
/* AA2C78 8002BAD8 E6E80004 */   swc1  $f8, 4($s7)
/* AA2C7C 8002BADC 8FA800AC */  lw    $t0, 0xac($sp)
/* AA2C80 8002BAE0 3C01BF80 */  li    $at, 0xBF800000 # 0.000000
/* AA2C84 8002BAE4 44812000 */  mtc1  $at, $f4
/* AA2C88 8002BAE8 E5000000 */  swc1  $f0, ($t0)
/* AA2C8C 8002BAEC C6E60004 */  lwc1  $f6, 4($s7)
/* AA2C90 8002BAF0 3C0143FA */  li    $at, 0x43FA0000 # 0.000000
/* AA2C94 8002BAF4 461C3281 */  sub.s $f10, $f6, $f28
/* AA2C98 8002BAF8 E6EA0004 */  swc1  $f10, 4($s7)
/* AA2C9C 8002BAFC 93C900C9 */  lbu   $t1, 0xc9($fp)
/* AA2CA0 8002BB00 00095040 */  sll   $t2, $t1, 1
/* AA2CA4 8002BB04 A3CA00C9 */  sb    $t2, 0xc9($fp)
/* AA2CA8 8002BB08 8FAB00AC */  lw    $t3, 0xac($sp)
/* AA2CAC 8002BB0C C6F00004 */  lwc1  $f16, 4($s7)
/* AA2CB0 8002BB10 C5720000 */  lwc1  $f18, ($t3)
/* AA2CB4 8002BB14 46128081 */  sub.s $f2, $f16, $f18
/* AA2CB8 8002BB18 4602203E */  c.le.s $f4, $f2
/* AA2CBC 8002BB1C 00000000 */  nop   
/* AA2CC0 8002BB20 4502006B */  bc1fl .L8002BCD0
/* AA2CC4 8002BB24 8FA200C0 */   lw    $v0, 0xc0($sp)
/* AA2CC8 8002BB28 44814000 */  mtc1  $at, $f8
/* AA2CCC 8002BB2C 00000000 */  nop   
/* AA2CD0 8002BB30 4608103C */  c.lt.s $f2, $f8
/* AA2CD4 8002BB34 00000000 */  nop   
/* AA2CD8 8002BB38 45020065 */  bc1fl .L8002BCD0
/* AA2CDC 8002BB3C 8FA200C0 */   lw    $v0, 0xc0($sp)
/* AA2CE0 8002BB40 44803000 */  mtc1  $zero, $f6
/* AA2CE4 8002BB44 8FA2013C */  lw    $v0, 0x13c($sp)
/* AA2CE8 8002BB48 00009025 */  move  $s2, $zero
/* AA2CEC 8002BB4C 4606103E */  c.le.s $f2, $f6
/* AA2CF0 8002BB50 254D0001 */  addiu $t5, $t2, 1
/* AA2CF4 8002BB54 3C014F80 */  li    $at, 0x4F800000 # 0.000000
/* AA2CF8 8002BB58 24420010 */  addiu $v0, $v0, 0x10
/* AA2CFC 8002BB5C 45020003 */  bc1fl .L8002BB6C
/* AA2D00 8002BB60 4602D03C */   c.lt.s $f26, $f2
/* AA2D04 8002BB64 A3CD00C9 */  sb    $t5, 0xc9($fp)
/* AA2D08 8002BB68 4602D03C */  c.lt.s $f26, $f2
.L8002BB6C:
/* AA2D0C 8002BB6C 00000000 */  nop   
/* AA2D10 8002BB70 45020003 */  bc1fl .L8002BB80
/* AA2D14 8002BB74 93CE00C8 */   lbu   $t6, 0xc8($fp)
/* AA2D18 8002BB78 4600D086 */  mov.s $f2, $f26
/* AA2D1C 8002BB7C 93CE00C8 */  lbu   $t6, 0xc8($fp)
.L8002BB80:
/* AA2D20 8002BB80 448E5000 */  mtc1  $t6, $f10
/* AA2D24 8002BB84 05C10004 */  bgez  $t6, .L8002BB98
/* AA2D28 8002BB88 46805420 */   cvt.s.w $f16, $f10
/* AA2D2C 8002BB8C 44819000 */  mtc1  $at, $f18
/* AA2D30 8002BB90 00000000 */  nop   
/* AA2D34 8002BB94 46128400 */  add.s $f16, $f16, $f18
.L8002BB98:
/* AA2D38 8002BB98 3C018013 */  lui   $at, %hi(D_80136AE4)
/* AA2D3C 8002BB9C C4246AE4 */  lwc1  $f4, %lo(D_80136AE4)($at)
/* AA2D40 8002BBA0 4602D03C */  c.lt.s $f26, $f2
/* AA2D44 8002BBA4 3C018013 */  lui   $at, %hi(D_80136AE8)
/* AA2D48 8002BBA8 46041202 */  mul.s $f8, $f2, $f4
/* AA2D4C 8002BBAC 4608F181 */  sub.s $f6, $f30, $f8
/* AA2D50 8002BBB0 46068602 */  mul.s $f24, $f16, $f6
/* AA2D54 8002BBB4 45000002 */  bc1f  .L8002BBC0
/* AA2D58 8002BBB8 00000000 */   nop   
/* AA2D5C 8002BBBC 4600D086 */  mov.s $f2, $f26
.L8002BBC0:
/* AA2D60 8002BBC0 C42A6AE8 */  lwc1  $f10, %lo(D_80136AE8)($at)
/* AA2D64 8002BBC4 C7C400C4 */  lwc1  $f4, 0xc4($fp)
/* AA2D68 8002BBC8 C7D00050 */  lwc1  $f16, 0x50($fp)
/* AA2D6C 8002BBCC 460A1482 */  mul.s $f18, $f2, $f10
/* AA2D70 8002BBD0 00408025 */  move  $s0, $v0
/* AA2D74 8002BBD4 00008825 */  move  $s1, $zero
/* AA2D78 8002BBD8 4612F501 */  sub.s $f20, $f30, $f18
/* AA2D7C 8002BBDC 46142202 */  mul.s $f8, $f4, $f20
/* AA2D80 8002BBE0 00000000 */  nop   
/* AA2D84 8002BBE4 46104582 */  mul.s $f22, $f8, $f16
/* AA2D88 8002BBE8 1AC0001D */  blez  $s6, .L8002BC60
/* AA2D8C 8002BBEC 00000000 */   nop   
.L8002BBF0:
/* AA2D90 8002BBF0 82020009 */  lb    $v0, 9($s0)
/* AA2D94 8002BBF4 58400017 */  blezl $v0, .L8002BC54
/* AA2D98 8002BBF8 26310001 */   addiu $s1, $s1, 1
/* AA2D9C 8002BBFC 04400003 */  bltz  $v0, .L8002BC0C
/* AA2DA0 8002BC00 00021823 */   negu  $v1, $v0
/* AA2DA4 8002BC04 10000001 */  b     .L8002BC0C
/* AA2DA8 8002BC08 00401825 */   move  $v1, $v0
.L8002BC0C:
/* AA2DAC 8002BC0C 920F0000 */  lbu   $t7, ($s0)
/* AA2DB0 8002BC10 92180001 */  lbu   $t8, 1($s0)
/* AA2DB4 8002BC14 92080002 */  lbu   $t0, 2($s0)
/* AA2DB8 8002BC18 02802025 */  move  $a0, $s4
/* AA2DBC 8002BC1C 01F8C821 */  addu  $t9, $t7, $t8
/* AA2DC0 8002BC20 03284821 */  addu  $t1, $t9, $t0
/* AA2DC4 8002BC24 00690019 */  multu $v1, $t1
/* AA2DC8 8002BC28 02002825 */  move  $a1, $s0
/* AA2DCC 8002BC2C 02603025 */  move  $a2, $s3
/* AA2DD0 8002BC30 00003812 */  mflo  $a3
/* AA2DD4 8002BC34 58E00007 */  blezl $a3, .L8002BC54
/* AA2DD8 8002BC38 26310001 */   addiu $s1, $s1, 1
/* AA2DDC 8002BC3C 02479021 */  addu  $s2, $s2, $a3
/* AA2DE0 8002BC40 E7B80010 */  swc1  $f24, 0x10($sp)
/* AA2DE4 8002BC44 E7B60014 */  swc1  $f22, 0x14($sp)
/* AA2DE8 8002BC48 0C00AD9B */  jal   shadow_foot_draw
/* AA2DEC 8002BC4C E7B40018 */   swc1  $f20, 0x18($sp)
/* AA2DF0 8002BC50 26310001 */  addiu $s1, $s1, 1
.L8002BC54:
/* AA2DF4 8002BC54 1636FFE6 */  bne   $s1, $s6, .L8002BBF0
/* AA2DF8 8002BC58 26100010 */   addiu $s0, $s0, 0x10
/* AA2DFC 8002BC5C 00008825 */  move  $s1, $zero
.L8002BC60:
/* AA2E00 8002BC60 82020009 */  lb    $v0, 9($s0)
/* AA2E04 8002BC64 58400017 */  blezl $v0, .L8002BCC4
/* AA2E08 8002BC68 26310001 */   addiu $s1, $s1, 1
/* AA2E0C 8002BC6C 04400003 */  bltz  $v0, .L8002BC7C
/* AA2E10 8002BC70 001220C0 */   sll   $a0, $s2, 3
/* AA2E14 8002BC74 10000002 */  b     .L8002BC80
/* AA2E18 8002BC78 00401825 */   move  $v1, $v0
.L8002BC7C:
/* AA2E1C 8002BC7C 00021823 */  negu  $v1, $v0
.L8002BC80:
/* AA2E20 8002BC80 920A0000 */  lbu   $t2, ($s0)
/* AA2E24 8002BC84 920B0001 */  lbu   $t3, 1($s0)
/* AA2E28 8002BC88 920D0002 */  lbu   $t5, 2($s0)
/* AA2E2C 8002BC8C 02002825 */  move  $a1, $s0
/* AA2E30 8002BC90 014B6021 */  addu  $t4, $t2, $t3
/* AA2E34 8002BC94 018D7021 */  addu  $t6, $t4, $t5
/* AA2E38 8002BC98 006E0019 */  multu $v1, $t6
/* AA2E3C 8002BC9C 02603025 */  move  $a2, $s3
/* AA2E40 8002BCA0 00007812 */  mflo  $t7
/* AA2E44 8002BCA4 01E43823 */  subu  $a3, $t7, $a0
/* AA2E48 8002BCA8 18E00005 */  blez  $a3, .L8002BCC0
/* AA2E4C 8002BCAC 02802025 */   move  $a0, $s4
/* AA2E50 8002BCB0 E7B80010 */  swc1  $f24, 0x10($sp)
/* AA2E54 8002BCB4 E7B60014 */  swc1  $f22, 0x14($sp)
/* AA2E58 8002BCB8 0C00AD9B */  jal   shadow_foot_draw
/* AA2E5C 8002BCBC E7B40018 */   swc1  $f20, 0x18($sp)
.L8002BCC0:
/* AA2E60 8002BCC0 26310001 */  addiu $s1, $s1, 1
.L8002BCC4:
/* AA2E64 8002BCC4 1635FFE6 */  bne   $s1, $s5, .L8002BC60
/* AA2E68 8002BCC8 26100010 */   addiu $s0, $s0, 0x10
/* AA2E6C 8002BCCC 8FA200C0 */  lw    $v0, 0xc0($sp)
.L8002BCD0:
/* AA2E70 8002BCD0 8FB800AC */  lw    $t8, 0xac($sp)
/* AA2E74 8002BCD4 26F7000C */  addiu $s7, $s7, 0xc
/* AA2E78 8002BCD8 24420001 */  addiu $v0, $v0, 1
/* AA2E7C 8002BCDC 27190004 */  addiu $t9, $t8, 4
/* AA2E80 8002BCE0 AFA200C0 */  sw    $v0, 0xc0($sp)
/* AA2E84 8002BCE4 1455FF76 */  bne   $v0, $s5, .L8002BAC0
/* AA2E88 8002BCE8 AFB900AC */   sw    $t9, 0xac($sp)
/* AA2E8C 8002BCEC 97C80088 */  lhu   $t0, 0x88($fp)
/* AA2E90 8002BCF0 3C068013 */  lui   $a2, %hi(D_80136100) # $a2, 0x8013
/* AA2E94 8002BCF4 24C66100 */  addiu $a2, %lo(D_80136100) # addiu $a2, $a2, 0x6100
/* AA2E98 8002BCF8 31090001 */  andi  $t1, $t0, 1
/* AA2E9C 8002BCFC 15200003 */  bnez  $t1, .L8002BD0C
/* AA2EA0 8002BD00 27A40098 */   addiu $a0, $sp, 0x98
/* AA2EA4 8002BD04 10000015 */  b     .L8002BD5C
/* AA2EA8 8002BD08 A3C000C9 */   sb    $zero, 0xc9($fp)
.L8002BD0C:
/* AA2EAC 8002BD0C 93CA00C9 */  lbu   $t2, 0xc9($fp)
/* AA2EB0 8002BD10 24010003 */  li    $at, 3
/* AA2EB4 8002BD14 55410012 */  bnel  $t2, $at, .L8002BD60
/* AA2EB8 8002BD18 8E850000 */   lw    $a1, ($s4)
/* AA2EBC 8002BD1C C7C600D0 */  lwc1  $f6, 0xd0($fp)
/* AA2EC0 8002BD20 C7CA00DC */  lwc1  $f10, 0xdc($fp)
/* AA2EC4 8002BD24 C7B200E0 */  lwc1  $f18, 0xe0($sp)
/* AA2EC8 8002BD28 C7A800E4 */  lwc1  $f8, 0xe4($sp)
/* AA2ECC 8002BD2C 460A3001 */  sub.s $f0, $f6, $f10
/* AA2ED0 8002BD30 240B0002 */  li    $t3, 2
/* AA2ED4 8002BD34 240C0001 */  li    $t4, 1
/* AA2ED8 8002BD38 46009100 */  add.s $f4, $f18, $f0
/* AA2EDC 8002BD3C 46004401 */  sub.s $f16, $f8, $f0
/* AA2EE0 8002BD40 4610203C */  c.lt.s $f4, $f16
/* AA2EE4 8002BD44 00000000 */  nop   
/* AA2EE8 8002BD48 45020004 */  bc1fl .L8002BD5C
/* AA2EEC 8002BD4C A3CC00C9 */   sb    $t4, 0xc9($fp)
/* AA2EF0 8002BD50 10000002 */  b     .L8002BD5C
/* AA2EF4 8002BD54 A3CB00C9 */   sb    $t3, 0xc9($fp)
/* AA2EF8 8002BD58 A3CC00C9 */  sb    $t4, 0xc9($fp)
.L8002BD5C:
/* AA2EFC 8002BD5C 8E850000 */  lw    $a1, ($s4)
.L8002BD60:
/* AA2F00 8002BD60 0C031AD5 */  jal   Graph_CloseDisps
/* AA2F04 8002BD64 24070727 */   li    $a3, 1831
.L8002BD68:
/* AA2F08 8002BD68 8FBF007C */  lw    $ra, 0x7c($sp)
/* AA2F0C 8002BD6C D7B40028 */  ldc1  $f20, 0x28($sp)
/* AA2F10 8002BD70 D7B60030 */  ldc1  $f22, 0x30($sp)
/* AA2F14 8002BD74 D7B80038 */  ldc1  $f24, 0x38($sp)
/* AA2F18 8002BD78 D7BA0040 */  ldc1  $f26, 0x40($sp)
/* AA2F1C 8002BD7C D7BC0048 */  ldc1  $f28, 0x48($sp)
/* AA2F20 8002BD80 D7BE0050 */  ldc1  $f30, 0x50($sp)
/* AA2F24 8002BD84 8FB00058 */  lw    $s0, 0x58($sp)
/* AA2F28 8002BD88 8FB1005C */  lw    $s1, 0x5c($sp)
/* AA2F2C 8002BD8C 8FB20060 */  lw    $s2, 0x60($sp)
/* AA2F30 8002BD90 8FB30064 */  lw    $s3, 0x64($sp)
/* AA2F34 8002BD94 8FB40068 */  lw    $s4, 0x68($sp)
/* AA2F38 8002BD98 8FB5006C */  lw    $s5, 0x6c($sp)
/* AA2F3C 8002BD9C 8FB60070 */  lw    $s6, 0x70($sp)
/* AA2F40 8002BDA0 8FB70074 */  lw    $s7, 0x74($sp)
/* AA2F44 8002BDA4 8FBE0078 */  lw    $fp, 0x78($sp)
/* AA2F48 8002BDA8 03E00008 */  jr    $ra
/* AA2F4C 8002BDAC 27BD0138 */   addiu $sp, $sp, 0x138

