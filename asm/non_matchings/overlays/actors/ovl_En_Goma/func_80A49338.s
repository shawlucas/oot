glabel func_80A49338
/* 00478 80A49338 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 0047C 80A4933C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00480 80A49340 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00484 80A49344 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00488 80A49348 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 0048C 80A4934C 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00490 80A49350 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 00494 80A49354 3C0540D5 */  lui     $a1, 0x40D5                ## $a1 = 40D50000
/* 00498 80A49358 34A55555 */  ori     $a1, $a1, 0x5555           ## $a1 = 40D55555
/* 0049C 80A4935C 26040068 */  addiu   $a0, $s0, 0x0068           ## $a0 = 00000068
/* 004A0 80A49360 3C063F00 */  lui     $a2, 0x3F00                ## $a2 = 3F000000
/* 004A4 80A49364 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 004A8 80A49368 3C074000 */  lui     $a3, 0x4000                ## $a3 = 40000000
/* 004AC 80A4936C 8FAE0024 */  lw      $t6, 0x0024($sp)           
/* 004B0 80A49370 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 004B4 80A49374 0C00B69E */  jal     ActorSearch_AngleY              
/* 004B8 80A49378 8DC51C44 */  lw      $a1, 0x1C44($t6)           ## 00001C44
/* 004BC 80A4937C 34018000 */  ori     $at, $zero, 0x8000         ## $at = 00008000
/* 004C0 80A49380 00412821 */  addu    $a1, $v0, $at              
/* 004C4 80A49384 00052C00 */  sll     $a1, $a1, 16               
/* 004C8 80A49388 00052C03 */  sra     $a1, $a1, 16               
/* 004CC 80A4938C 26040032 */  addiu   $a0, $s0, 0x0032           ## $a0 = 00000032
/* 004D0 80A49390 24060003 */  addiu   $a2, $zero, 0x0003         ## $a2 = 00000003
/* 004D4 80A49394 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 004D8 80A49398 240707D0 */  addiu   $a3, $zero, 0x07D0         ## $a3 = 000007D0
/* 004DC 80A4939C 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
/* 004E0 80A493A0 86050032 */  lh      $a1, 0x0032($s0)           ## 00000032
/* 004E4 80A493A4 24060002 */  addiu   $a2, $zero, 0x0002         ## $a2 = 00000002
/* 004E8 80A493A8 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 004EC 80A493AC 24070BB8 */  addiu   $a3, $zero, 0x0BB8         ## $a3 = 00000BB8
/* 004F0 80A493B0 860F02CC */  lh      $t7, 0x02CC($s0)           ## 000002CC
/* 004F4 80A493B4 55E00004 */  bnel    $t7, $zero, .L80A493C8     
/* 004F8 80A493B8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 004FC 80A493BC 0C2927A0 */  jal     func_80A49E80              
/* 00500 80A493C0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00504 80A493C4 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80A493C8:
/* 00508 80A493C8 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 0050C 80A493CC 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 00510 80A493D0 03E00008 */  jr      $ra                        
/* 00514 80A493D4 00000000 */  nop
