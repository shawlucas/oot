glabel func_80A56328
/* 00258 80A56328 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 0025C 80A5632C AFA40028 */  sw      $a0, 0x0028($sp)
/* 00260 80A56330 AFBF0024 */  sw      $ra, 0x0024($sp)
/* 00264 80A56334 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 00268 80A56338 AFA5002C */  sw      $a1, 0x002C($sp)
/* 0026C 80A5633C 0C028800 */  jal     SkelAnime_GetFrameCount

/* 00270 80A56340 24845C30 */  addiu   $a0, $a0, 0x5C30           ## $a0 = 06005C30
/* 00274 80A56344 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 00278 80A56348 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 0027C 80A5634C 44819000 */  mtc1    $at, $f18                  ## $f18 = -10.00
/* 00280 80A56350 468021A0 */  cvt.s.w $f6, $f4
/* 00284 80A56354 8FA40028 */  lw      $a0, 0x0028($sp)
/* 00288 80A56358 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 0028C 80A5635C 24A55C30 */  addiu   $a1, $a1, 0x5C30           ## $a1 = 06005C30
/* 00290 80A56360 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00294 80A56364 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 00298 80A56368 4600320D */  trunc.w.s $f8, $f6
/* 0029C 80A5636C AFA00014 */  sw      $zero, 0x0014($sp)
/* 002A0 80A56370 E7B20018 */  swc1    $f18, 0x0018($sp)
/* 002A4 80A56374 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 002A8 80A56378 440F4000 */  mfc1    $t7, $f8
/* 002AC 80A5637C 00000000 */  nop
/* 002B0 80A56380 000FC400 */  sll     $t8, $t7, 16
/* 002B4 80A56384 0018CC03 */  sra     $t9, $t8, 16
/* 002B8 80A56388 44995000 */  mtc1    $t9, $f10                  ## $f10 = 0.00
/* 002BC 80A5638C 00000000 */  nop
/* 002C0 80A56390 46805420 */  cvt.s.w $f16, $f10
/* 002C4 80A56394 0C029468 */  jal     SkelAnime_ChangeAnim

/* 002C8 80A56398 E7B00010 */  swc1    $f16, 0x0010($sp)
/* 002CC 80A5639C 8FA90028 */  lw      $t1, 0x0028($sp)
/* 002D0 80A563A0 3C0880A5 */  lui     $t0, %hi(func_80A563BC)    ## $t0 = 80A50000
/* 002D4 80A563A4 250863BC */  addiu   $t0, $t0, %lo(func_80A563BC) ## $t0 = 80A563BC
/* 002D8 80A563A8 AD28025C */  sw      $t0, 0x025C($t1)           ## 0000025C
/* 002DC 80A563AC 8FBF0024 */  lw      $ra, 0x0024($sp)
/* 002E0 80A563B0 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 002E4 80A563B4 03E00008 */  jr      $ra
/* 002E8 80A563B8 00000000 */  nop
