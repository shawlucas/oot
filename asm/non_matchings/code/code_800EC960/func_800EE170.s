glabel func_800EE170
/* B65310 800EE170 3C028013 */  lui   $v0, %hi(D_80131858) # $v0, 0x8013
/* B65314 800EE174 90421858 */  lbu   $v0, %lo(D_80131858)($v0)
/* B65318 800EE178 27BDFFE8 */  addiu $sp, $sp, -0x18
/* B6531C 800EE17C 308500FF */  andi  $a1, $a0, 0xff
/* B65320 800EE180 AFBF0014 */  sw    $ra, 0x14($sp)
/* B65324 800EE184 10A20041 */  beq   $a1, $v0, .L800EE28C
/* B65328 800EE188 AFA40018 */   sw    $a0, 0x18($sp)
/* B6532C 800EE18C 10A00023 */  beqz  $a1, .L800EE21C
/* B65330 800EE190 3C0C8013 */   lui   $t4, %hi(D_8013185C) # $t4, 0x8013
/* B65334 800EE194 3C0E8017 */  lui   $t6, %hi(D_8016BA04) # $t6, 0x8017
/* B65338 800EE198 8DCEBA04 */  lw    $t6, %lo(D_8016BA04)($t6)
/* B6533C 800EE19C 3C018013 */  lui   $at, %hi(D_80131860) # $at, 0x8013
/* B65340 800EE1A0 240F00FF */  li    $t7, 255
/* B65344 800EE1A4 AC2E1860 */  sw    $t6, %lo(D_80131860)($at)
/* B65348 800EE1A8 3C018013 */  lui   $at, %hi(D_80131864) # $at, 0x8013
/* B6534C 800EE1AC A02F1864 */  sb    $t7, %lo(D_80131864)($at)
/* B65350 800EE1B0 3C018013 */  lui   $at, %hi(D_80131868) # $at, 0x8013
/* B65354 800EE1B4 24180057 */  li    $t8, 87
/* B65358 800EE1B8 A0381868 */  sb    $t8, %lo(D_80131868)($at)
/* B6535C 800EE1BC 3C018013 */  lui   $at, %hi(D_8013186C) # $at, 0x8013
/* B65360 800EE1C0 A020186C */  sb    $zero, %lo(D_8013186C)($at)
/* B65364 800EE1C4 3C018013 */  lui   $at, %hi(D_80131870) # $at, 0x8013
/* B65368 800EE1C8 A0201870 */  sb    $zero, %lo(D_80131870)($at)
/* B6536C 800EE1CC 3C018013 */  lui   $at, %hi(D_80131874) # $at, 0x8013
/* B65370 800EE1D0 A0201874 */  sb    $zero, %lo(D_80131874)($at)
/* B65374 800EE1D4 3C018013 */  lui   $at, %hi(D_8013185C) # $at, 0x8013
/* B65378 800EE1D8 A020185C */  sb    $zero, %lo(D_8013185C)($at)
/* B6537C 800EE1DC 3C018013 */  lui   $at, %hi(sOcarinaInpEnabled) # $at, 0x8013
/* B65380 800EE1E0 24190001 */  li    $t9, 1
/* B65384 800EE1E4 A0390F0C */  sb    $t9, %lo(sOcarinaInpEnabled)($at)
/* B65388 800EE1E8 3C018017 */  lui   $at, %hi(D_8016BA2E) # $at, 0x8017
/* B6538C 800EE1EC 3C098013 */  lui   $t1, %hi(D_8013188C) # $t1, 0x8013
/* B65390 800EE1F0 A020BA2E */  sb    $zero, %lo(D_8016BA2E)($at)
/* B65394 800EE1F4 2529188C */  addiu $t1, %lo(D_8013188C) # addiu $t1, $t1, 0x188c
/* B65398 800EE1F8 892B0000 */  lwl   $t3, ($t1)
/* B6539C 800EE1FC 892A0004 */  lwl   $t2, 4($t1)
/* B653A0 800EE200 992B0003 */  lwr   $t3, 3($t1)
/* B653A4 800EE204 992A0007 */  lwr   $t2, 7($t1)
/* B653A8 800EE208 3C088017 */  lui   $t0, %hi(D_8016BAA0) # $t0, 0x8017
/* B653AC 800EE20C 2508BAA0 */  addiu $t0, %lo(D_8016BAA0) # addiu $t0, $t0, -0x4560
/* B653B0 800EE210 AD0B0000 */  sw    $t3, ($t0)
/* B653B4 800EE214 1000001B */  b     .L800EE284
/* B653B8 800EE218 AD0A0004 */   sw    $t2, 4($t0)
.L800EE21C:
/* B653BC 800EE21C 918C185C */  lbu   $t4, %lo(D_8013185C)($t4)
/* B653C0 800EE220 3C0D8013 */  lui   $t5, %hi(D_8013188C) # $t5, 0x8013
/* B653C4 800EE224 24010002 */  li    $at, 2
/* B653C8 800EE228 1580000B */  bnez  $t4, .L800EE258
/* B653CC 800EE22C 24040001 */   li    $a0, 1
/* B653D0 800EE230 3C0E8017 */  lui   $t6, %hi(D_8016BAA0) # $t6, 0x8017
/* B653D4 800EE234 25CEBAA0 */  addiu $t6, %lo(D_8016BAA0) # addiu $t6, $t6, -0x4560
/* B653D8 800EE238 8DD80000 */  lw    $t8, ($t6)
/* B653DC 800EE23C 8DCF0004 */  lw    $t7, 4($t6)
/* B653E0 800EE240 25AD188C */  addiu $t5, %lo(D_8013188C) # addiu $t5, $t5, 0x188c
/* B653E4 800EE244 A9B80000 */  swl   $t8, ($t5)
/* B653E8 800EE248 A9AF0004 */  swl   $t7, 4($t5)
/* B653EC 800EE24C B9B80003 */  swr   $t8, 3($t5)
/* B653F0 800EE250 10000008 */  b     .L800EE274
/* B653F4 800EE254 B9AF0007 */   swr   $t7, 7($t5)
.L800EE258:
/* B653F8 800EE258 14410003 */  bne   $v0, $at, .L800EE268
/* B653FC 800EE25C 24190001 */   li    $t9, 1
/* B65400 800EE260 3C018017 */  lui   $at, %hi(D_8016BA2E) # $at, 0x8017
/* B65404 800EE264 A039BA2E */  sb    $t9, %lo(D_8016BA2E)($at)
.L800EE268:
/* B65408 800EE268 0C03B75A */  jal   func_800EDD68
/* B6540C 800EE26C A3A5001B */   sb    $a1, 0x1b($sp)
/* B65410 800EE270 93A5001B */  lbu   $a1, 0x1b($sp)
.L800EE274:
/* B65414 800EE274 3C018013 */  lui   $at, %hi(sOcarinaInpEnabled) # $at, 0x8013
/* B65418 800EE278 A0200F0C */  sb    $zero, %lo(sOcarinaInpEnabled)($at)
/* B6541C 800EE27C 3C018017 */  lui   $at, %hi(D_8016BA2E) # $at, 0x8017
/* B65420 800EE280 A020BA2E */  sb    $zero, %lo(D_8016BA2E)($at)
.L800EE284:
/* B65424 800EE284 3C018013 */  lui   $at, %hi(D_80131858) # $at, 0x8013
/* B65428 800EE288 A0251858 */  sb    $a1, %lo(D_80131858)($at)
.L800EE28C:
/* B6542C 800EE28C 8FBF0014 */  lw    $ra, 0x14($sp)
/* B65430 800EE290 27BD0018 */  addiu $sp, $sp, 0x18
/* B65434 800EE294 03E00008 */  jr    $ra
/* B65438 800EE298 00000000 */   nop   

