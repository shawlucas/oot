glabel BgMoriBigst_Update
/* 00784 808A1344 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 00788 808A1348 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0078C 808A134C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00790 808A1350 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 00794 808A1354 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00798 808A1358 0C00B56E */  jal     Actor_SetHeight
              
/* 0079C 808A135C 3C054248 */  lui     $a1, 0x4248                ## $a1 = 42480000
/* 007A0 808A1360 86020168 */  lh      $v0, 0x0168($s0)           ## 00000168
/* 007A4 808A1364 18400002 */  blez    $v0, .L808A1370            
/* 007A8 808A1368 244EFFFF */  addiu   $t6, $v0, 0xFFFF           ## $t6 = FFFFFFFF
/* 007AC 808A136C A60E0168 */  sh      $t6, 0x0168($s0)           ## 00000168
.L808A1370:
/* 007B0 808A1370 0C010D64 */  jal     func_80043590              
/* 007B4 808A1374 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 007B8 808A1378 10400003 */  beq     $v0, $zero, .L808A1388     
/* 007BC 808A137C 8FA40024 */  lw      $a0, 0x0024($sp)           
/* 007C0 808A1380 0C01D33A */  jal     func_80074CE8              
/* 007C4 808A1384 24050006 */  addiu   $a1, $zero, 0x0006         ## $a1 = 00000006
.L808A1388:
/* 007C8 808A1388 8E020164 */  lw      $v0, 0x0164($s0)           ## 00000164
/* 007CC 808A138C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 007D0 808A1390 50400004 */  beql    $v0, $zero, .L808A13A4     
/* 007D4 808A1394 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 007D8 808A1398 0040F809 */  jalr    $ra, $v0                   
/* 007DC 808A139C 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 007E0 808A13A0 8FBF001C */  lw      $ra, 0x001C($sp)           
.L808A13A4:
/* 007E4 808A13A4 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 007E8 808A13A8 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 007EC 808A13AC 03E00008 */  jr      $ra                        
/* 007F0 808A13B0 00000000 */  nop
