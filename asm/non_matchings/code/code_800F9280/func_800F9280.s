glabel func_800F9280
/* B70420 800F9280 27BDFFC8 */  addiu $sp, $sp, -0x38
/* B70424 800F9284 3C0E8013 */  lui   $t6, %hi(D_80133408) # $t6, 0x8013
/* B70428 800F9288 91CE3408 */  lbu   $t6, %lo(D_80133408)($t6)
/* B7042C 800F928C AFB00018 */  sw    $s0, 0x18($sp)
/* B70430 800F9290 AFA60040 */  sw    $a2, 0x40($sp)
/* B70434 800F9294 30C600FF */  andi  $a2, $a2, 0xff
/* B70438 800F9298 309000FF */  andi  $s0, $a0, 0xff
/* B7043C 800F929C AFBF001C */  sw    $ra, 0x1c($sp)
/* B70440 800F92A0 AFA40038 */  sw    $a0, 0x38($sp)
/* B70444 800F92A4 AFA5003C */  sw    $a1, 0x3c($sp)
/* B70448 800F92A8 11C00003 */  beqz  $t6, .L800F92B8
/* B7044C 800F92AC AFA70044 */   sw    $a3, 0x44($sp)
/* B70450 800F92B0 24010002 */  li    $at, 2
/* B70454 800F92B4 1601006A */  bne   $s0, $at, .L800F9460
.L800F92B8:
nop
/* B70458 800F92B8 30C6007F */   andi  $a2, $a2, 0x7f
/* B7045C 800F92BC 30C600FF */  andi  $a2, $a2, 0xff
/* B70460 800F92C0 2401007F */  li    $at, 127
/* B70464 800F92C4 14C10019 */  bne   $a2, $at, .L800F932C
/* B70468 800F92C8 00C03825 */   move  $a3, $a2
/* B7046C 800F92CC 97AF0046 */  lhu   $t7, 0x46($sp)
/* B70470 800F92D0 3C088017 */  lui   $t0, %hi(gAudioContext+0x2854) # $t0, 0x8017
/* B70474 800F92D4 850819D4 */  lh    $t0, %lo(gAudioContext+0x2854)($t0)
/* B70478 800F92D8 000FC0C3 */  sra   $t8, $t7, 3
/* B7047C 800F92DC 0018C900 */  sll   $t9, $t8, 4
/* B70480 800F92E0 0338C823 */  subu  $t9, $t9, $t8
/* B70484 800F92E4 0019C880 */  sll   $t9, $t9, 2
/* B70488 800F92E8 03280019 */  multu $t9, $t0
/* B7048C 800F92EC 93AB003F */  lbu   $t3, 0x3f($sp)
/* B70490 800F92F0 320300FF */  andi  $v1, $s0, 0xff
/* B70494 800F92F4 00031C00 */  sll   $v1, $v1, 0x10
/* B70498 800F92F8 3C018500 */  lui   $at, 0x8500
/* B7049C 800F92FC 00614825 */  or    $t1, $v1, $at
/* B704A0 800F9300 000B6200 */  sll   $t4, $t3, 8
/* B704A4 800F9304 012C2025 */  or    $a0, $t1, $t4
/* B704A8 800F9308 AFA30028 */  sw    $v1, 0x28($sp)
/* B704AC 800F930C AFA6002C */  sw    $a2, 0x2c($sp)
/* B704B0 800F9310 00001012 */  mflo  $v0
/* B704B4 800F9314 3045FFFF */  andi  $a1, $v0, 0xffff
/* B704B8 800F9318 0C0396BF */  jal   func_800E5AFC
/* B704BC 800F931C 00000000 */   nop   
/* B704C0 800F9320 8FA30028 */  lw    $v1, 0x28($sp)
/* B704C4 800F9324 10000018 */  b     .L800F9388
/* B704C8 800F9328 8FA7002C */   lw    $a3, 0x2c($sp)
.L800F932C:
/* B704CC 800F932C 3C088017 */  lui   $t0, %hi(gAudioContext+0x2854) # $t0, 0x8017
/* B704D0 800F9330 950819D4 */  lhu   $t0, %lo(gAudioContext+0x2854)($t0)
/* B704D4 800F9334 97B90046 */  lhu   $t9, 0x46($sp)
/* B704D8 800F9338 320300FF */  andi  $v1, $s0, 0xff
/* B704DC 800F933C 93AE003F */  lbu   $t6, 0x3f($sp)
/* B704E0 800F9340 03280019 */  multu $t9, $t0
/* B704E4 800F9344 00031C00 */  sll   $v1, $v1, 0x10
/* B704E8 800F9348 3C018200 */  lui   $at, 0x8200
/* B704EC 800F934C 00616825 */  or    $t5, $v1, $at
/* B704F0 800F9350 01C07825 */  move  $t7, $t6
/* B704F4 800F9354 000FC200 */  sll   $t8, $t7, 8
/* B704F8 800F9358 01B82025 */  or    $a0, $t5, $t8
/* B704FC 800F935C AFA30028 */  sw    $v1, 0x28($sp)
/* B70500 800F9360 AFA7002C */  sw    $a3, 0x2c($sp)
/* B70504 800F9364 00002812 */  mflo  $a1
/* B70508 800F9368 04A10002 */  bgez  $a1, .L800F9374
/* B7050C 800F936C 00A00821 */   addu  $at, $a1, $zero
/* B70510 800F9370 24A10003 */  addiu $at, $a1, 3
.L800F9374:
/* B70514 800F9374 00012883 */  sra   $a1, $at, 2
/* B70518 800F9378 0C0396BF */  jal   func_800E5AFC
/* B7051C 800F937C 00000000 */   nop   
/* B70520 800F9380 8FA30028 */  lw    $v1, 0x28($sp)
/* B70524 800F9384 8FA7002C */  lw    $a3, 0x2c($sp)
.L800F9388:
/* B70528 800F9388 00105080 */  sll   $t2, $s0, 2
/* B7052C 800F938C 01505021 */  addu  $t2, $t2, $s0
/* B70530 800F9390 000A5080 */  sll   $t2, $t2, 2
/* B70534 800F9394 01505023 */  subu  $t2, $t2, $s0
/* B70538 800F9398 000A50C0 */  sll   $t2, $t2, 3
/* B7053C 800F939C 01505021 */  addu  $t2, $t2, $s0
/* B70540 800F93A0 3C0B8017 */  lui   $t3, %hi(D_8016E750) # $t3, 0x8017
/* B70544 800F93A4 256BE750 */  addiu $t3, %lo(D_8016E750) # addiu $t3, $t3, -0x18b0
/* B70548 800F93A8 000A5080 */  sll   $t2, $t2, 2
/* B7054C 800F93AC 3C013F80 */  li    $at, 0x3F800000 # 0.000000
/* B70550 800F93B0 014B3021 */  addu  $a2, $t2, $t3
/* B70554 800F93B4 44810000 */  mtc1  $at, $f0
/* B70558 800F93B8 C4C20000 */  lwc1  $f2, ($a2)
/* B7055C 800F93BC 93A9003F */  lbu   $t1, 0x3f($sp)
/* B70560 800F93C0 00076200 */  sll   $t4, $a3, 8
/* B70564 800F93C4 46020032 */  c.eq.s $f0, $f2
/* B70568 800F93C8 012C1025 */  or    $v0, $t1, $t4
/* B7056C 800F93CC A4C20254 */  sh    $v0, 0x254($a2)
/* B70570 800F93D0 A4C20256 */  sh    $v0, 0x256($a2)
/* B70574 800F93D4 45010008 */  bc1t  .L800F93F8
/* B70578 800F93D8 3C014100 */   lui   $at, 0x4100
/* B7057C 800F93DC 44051000 */  mfc1  $a1, $f2
/* B70580 800F93E0 00612025 */  or    $a0, $v1, $at
/* B70584 800F93E4 0C0396B6 */  jal   func_800E5AD8
/* B70588 800F93E8 AFA60024 */   sw    $a2, 0x24($sp)
/* B7058C 800F93EC 3C013F80 */  li    $at, 0x3F800000 # 0.000000
/* B70590 800F93F0 44810000 */  mtc1  $at, $f0
/* B70594 800F93F4 8FA60024 */  lw    $a2, 0x24($sp)
.L800F93F8:
/* B70598 800F93F8 00107080 */  sll   $t6, $s0, 2
/* B7059C 800F93FC 01D07021 */  addu  $t6, $t6, $s0
/* B705A0 800F9400 000E7080 */  sll   $t6, $t6, 2
/* B705A4 800F9404 01D07023 */  subu  $t6, $t6, $s0
/* B705A8 800F9408 000E70C0 */  sll   $t6, $t6, 3
/* B705AC 800F940C 01D07021 */  addu  $t6, $t6, $s0
/* B705B0 800F9410 3C0F8017 */  lui   $t7, %hi(D_8016E750) # $t7, 0x8017
/* B705B4 800F9414 25EFE750 */  addiu $t7, %lo(D_8016E750) # addiu $t7, $t7, -0x18b0
/* B705B8 800F9418 000E7080 */  sll   $t6, $t6, 2
/* B705BC 800F941C A4C00028 */  sh    $zero, 0x28($a2)
/* B705C0 800F9420 A4C00018 */  sh    $zero, 0x18($a2)
/* B705C4 800F9424 ACC00014 */  sw    $zero, 0x14($a2)
/* B705C8 800F9428 01CF2021 */  addu  $a0, $t6, $t7
/* B705CC 800F942C 00001825 */  move  $v1, $zero
.L800F9430:
/* B705D0 800F9430 00036940 */  sll   $t5, $v1, 5
/* B705D4 800F9434 24630001 */  addiu $v1, $v1, 1
/* B705D8 800F9438 008D1021 */  addu  $v0, $a0, $t5
/* B705DC 800F943C 306300FF */  andi  $v1, $v1, 0xff
/* B705E0 800F9440 28610010 */  slti  $at, $v1, 0x10
/* B705E4 800F9444 E4400050 */  swc1  $f0, 0x50($v0)
/* B705E8 800F9448 A440005C */  sh    $zero, 0x5c($v0)
/* B705EC 800F944C E4400060 */  swc1  $f0, 0x60($v0)
/* B705F0 800F9450 1420FFF7 */  bnez  $at, .L800F9430
/* B705F4 800F9454 A440006C */   sh    $zero, 0x6c($v0)
/* B705F8 800F9458 A4C00250 */  sh    $zero, 0x250($a2)
/* B705FC 800F945C A4C00252 */  sh    $zero, 0x252($a2)
.L800F9460:
/* B70600 800F9460 8FBF001C */  lw    $ra, 0x1c($sp)
/* B70604 800F9464 8FB00018 */  lw    $s0, 0x18($sp)
/* B70608 800F9468 27BD0038 */  addiu $sp, $sp, 0x38
/* B7060C 800F946C 03E00008 */  jr    $ra
/* B70610 800F9470 00000000 */   nop   

