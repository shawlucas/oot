glabel func_80B221E8
/* 01408 80B221E8 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 0140C 80B221EC AFBF0034 */  sw      $ra, 0x0034($sp)           
/* 01410 80B221F0 AFB50030 */  sw      $s5, 0x0030($sp)           
/* 01414 80B221F4 AFB4002C */  sw      $s4, 0x002C($sp)           
/* 01418 80B221F8 AFB30028 */  sw      $s3, 0x0028($sp)           
/* 0141C 80B221FC AFB20024 */  sw      $s2, 0x0024($sp)           
/* 01420 80B22200 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 01424 80B22204 AFB0001C */  sw      $s0, 0x001C($sp)           
/* 01428 80B22208 AFA5003C */  sw      $a1, 0x003C($sp)           
/* 0142C 80B2220C 90820185 */  lbu     $v0, 0x0185($a0)           ## 00000185
/* 01430 80B22210 00808825 */  or      $s1, $a0, $zero            ## $s1 = 00000000
/* 01434 80B22214 304E0002 */  andi    $t6, $v0, 0x0002           ## $t6 = 00000000
/* 01438 80B22218 51C00081 */  beql    $t6, $zero, .L80B22420     
/* 0143C 80B2221C 8FBF0034 */  lw      $ra, 0x0034($sp)           
/* 01440 80B22220 8C8F014C */  lw      $t7, 0x014C($a0)           ## 0000014C
/* 01444 80B22224 2415FFFD */  addiu   $s5, $zero, 0xFFFD         ## $s5 = FFFFFFFD
/* 01448 80B22228 3059FFFD */  andi    $t9, $v0, 0xFFFD           ## $t9 = 00000000
/* 0144C 80B2222C 29E10002 */  slti    $at, $t7, 0x0002           
/* 01450 80B22230 1420007A */  bne     $at, $zero, .L80B2241C     
/* 01454 80B22234 26250174 */  addiu   $a1, $s1, 0x0174           ## $a1 = 00000174
/* 01458 80B22238 8498001C */  lh      $t8, 0x001C($a0)           ## 0000001C
/* 0145C 80B2223C 00009025 */  or      $s2, $zero, $zero          ## $s2 = 00000000
/* 01460 80B22240 0000A025 */  or      $s4, $zero, $zero          ## $s4 = 00000000
/* 01464 80B22244 07010002 */  bgez    $t8, .L80B22250            
/* 01468 80B22248 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0146C 80B2224C 24120001 */  addiu   $s2, $zero, 0x0001         ## $s2 = 00000001
.L80B22250:
/* 01470 80B22250 A2390185 */  sb      $t9, 0x0185($s1)           ## 00000185
/* 01474 80B22254 0C00D5CF */  jal     func_8003573C              
/* 01478 80B22258 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 0147C 80B2225C 922200B1 */  lbu     $v0, 0x00B1($s1)           ## 000000B1
/* 01480 80B22260 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 01484 80B22264 1040006D */  beq     $v0, $zero, .L80B2241C     
/* 01488 80B22268 A2220158 */  sb      $v0, 0x0158($s1)           ## 00000158
/* 0148C 80B2226C 14410002 */  bne     $v0, $at, .L80B22278       
/* 01490 80B22270 00000000 */  nop
/* 01494 80B22274 24140001 */  addiu   $s4, $zero, 0x0001         ## $s4 = 00000001
.L80B22278:
/* 01498 80B22278 56400004 */  bnel    $s2, $zero, .L80B2228C     
/* 0149C 80B2227C 922800AF */  lbu     $t0, 0x00AF($s1)           ## 000000AF
/* 014A0 80B22280 0C00D58A */  jal     Actor_ApplyDamage
              
/* 014A4 80B22284 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 014A8 80B22288 922800AF */  lbu     $t0, 0x00AF($s1)           ## 000000AF
.L80B2228C:
/* 014AC 80B2228C 15000010 */  bne     $t0, $zero, .L80B222D0     
/* 014B0 80B22290 00000000 */  nop
/* 014B4 80B22294 8E290004 */  lw      $t1, 0x0004($s1)           ## 00000004
/* 014B8 80B22298 8E3001D4 */  lw      $s0, 0x01D4($s1)           ## 000001D4
/* 014BC 80B2229C 2401FFFE */  addiu   $at, $zero, 0xFFFE         ## $at = FFFFFFFE
/* 014C0 80B222A0 01215024 */  and     $t2, $t1, $at              
/* 014C4 80B222A4 AE2A0004 */  sw      $t2, 0x0004($s1)           ## 00000004
/* 014C8 80B222A8 860B001C */  lh      $t3, 0x001C($s0)           ## 0000001C
/* 014CC 80B222AC 0563005C */  bgezl   $t3, .L80B22420            
/* 014D0 80B222B0 8FBF0034 */  lw      $ra, 0x0034($sp)           
/* 014D4 80B222B4 0C2C8515 */  jal     func_80B21454              
/* 014D8 80B222B8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 014DC 80B222BC 922C00B1 */  lbu     $t4, 0x00B1($s1)           ## 000000B1
/* 014E0 80B222C0 240D000C */  addiu   $t5, $zero, 0x000C         ## $t5 = 0000000C
/* 014E4 80B222C4 A60D001C */  sh      $t5, 0x001C($s0)           ## 0000001C
/* 014E8 80B222C8 10000054 */  beq     $zero, $zero, .L80B2241C   
/* 014EC 80B222CC A20C0158 */  sb      $t4, 0x0158($s0)           ## 00000158
.L80B222D0:
/* 014F0 80B222D0 12800016 */  beq     $s4, $zero, .L80B2232C     
/* 014F4 80B222D4 24130050 */  addiu   $s3, $zero, 0x0050         ## $s3 = 00000050
/* 014F8 80B222D8 A6330110 */  sh      $s3, 0x0110($s1)           ## 00000110
/* 014FC 80B222DC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01500 80B222E0 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01504 80B222E4 2405389E */  addiu   $a1, $zero, 0x389E         ## $a1 = 0000389E
/* 01508 80B222E8 1240000A */  beq     $s2, $zero, .L80B22314     
/* 0150C 80B222EC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01510 80B222F0 240E0050 */  addiu   $t6, $zero, 0x0050         ## $t6 = 00000050
/* 01514 80B222F4 AFAE0010 */  sw      $t6, 0x0010($sp)           
/* 01518 80B222F8 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0151C 80B222FC 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 01520 80B22300 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 01524 80B22304 0C00D09B */  jal     func_8003426C              
/* 01528 80B22308 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 0152C 80B2230C 10000008 */  beq     $zero, $zero, .L80B22330   
/* 01530 80B22310 8E300118 */  lw      $s0, 0x0118($s1)           ## 00000118
.L80B22314:
/* 01534 80B22314 240F0050 */  addiu   $t7, $zero, 0x0050         ## $t7 = 00000050
/* 01538 80B22318 AFAF0010 */  sw      $t7, 0x0010($sp)           
/* 0153C 80B2231C 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 01540 80B22320 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 01544 80B22324 0C00D09B */  jal     func_8003426C              
/* 01548 80B22328 24072000 */  addiu   $a3, $zero, 0x2000         ## $a3 = 00002000
.L80B2232C:
/* 0154C 80B2232C 8E300118 */  lw      $s0, 0x0118($s1)           ## 00000118
.L80B22330:
/* 01550 80B22330 24130050 */  addiu   $s3, $zero, 0x0050         ## $s3 = 00000050
/* 01554 80B22334 5200001E */  beql    $s0, $zero, .L80B223B0     
/* 01558 80B22338 8E30011C */  lw      $s0, 0x011C($s1)           ## 0000011C
/* 0155C 80B2233C 92180185 */  lbu     $t8, 0x0185($s0)           ## 00000185
.L80B22340:
/* 01560 80B22340 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01564 80B22344 2405389E */  addiu   $a1, $zero, 0x389E         ## $a1 = 0000389E
/* 01568 80B22348 0315C824 */  and     $t9, $t8, $s5              
/* 0156C 80B2234C 12800014 */  beq     $s4, $zero, .L80B223A0     
/* 01570 80B22350 A2190185 */  sb      $t9, 0x0185($s0)           ## 00000185
/* 01574 80B22354 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01578 80B22358 A6130110 */  sh      $s3, 0x0110($s0)           ## 00000110
/* 0157C 80B2235C 1240000A */  beq     $s2, $zero, .L80B22388     
/* 01580 80B22360 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01584 80B22364 24080050 */  addiu   $t0, $zero, 0x0050         ## $t0 = 00000050
/* 01588 80B22368 AFA80010 */  sw      $t0, 0x0010($sp)           
/* 0158C 80B2236C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01590 80B22370 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 01594 80B22374 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 01598 80B22378 0C00D09B */  jal     func_8003426C              
/* 0159C 80B2237C 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 015A0 80B22380 10000008 */  beq     $zero, $zero, .L80B223A4   
/* 015A4 80B22384 8E100118 */  lw      $s0, 0x0118($s0)           ## 00000118
.L80B22388:
/* 015A8 80B22388 24090050 */  addiu   $t1, $zero, 0x0050         ## $t1 = 00000050
/* 015AC 80B2238C AFA90010 */  sw      $t1, 0x0010($sp)           
/* 015B0 80B22390 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 015B4 80B22394 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 015B8 80B22398 0C00D09B */  jal     func_8003426C              
/* 015BC 80B2239C 24072000 */  addiu   $a3, $zero, 0x2000         ## $a3 = 00002000
.L80B223A0:
/* 015C0 80B223A0 8E100118 */  lw      $s0, 0x0118($s0)           ## 00000118
.L80B223A4:
/* 015C4 80B223A4 5600FFE6 */  bnel    $s0, $zero, .L80B22340     
/* 015C8 80B223A8 92180185 */  lbu     $t8, 0x0185($s0)           ## 00000185
/* 015CC 80B223AC 8E30011C */  lw      $s0, 0x011C($s1)           ## 0000011C
.L80B223B0:
/* 015D0 80B223B0 5200001B */  beql    $s0, $zero, .L80B22420     
/* 015D4 80B223B4 8FBF0034 */  lw      $ra, 0x0034($sp)           
/* 015D8 80B223B8 920A0185 */  lbu     $t2, 0x0185($s0)           ## 00000185
.L80B223BC:
/* 015DC 80B223BC 01555824 */  and     $t3, $t2, $s5              
/* 015E0 80B223C0 12800013 */  beq     $s4, $zero, .L80B22410     
/* 015E4 80B223C4 A20B0185 */  sb      $t3, 0x0185($s0)           ## 00000185
/* 015E8 80B223C8 1240000A */  beq     $s2, $zero, .L80B223F4     
/* 015EC 80B223CC A6130110 */  sh      $s3, 0x0110($s0)           ## 00000110
/* 015F0 80B223D0 240C0050 */  addiu   $t4, $zero, 0x0050         ## $t4 = 00000050
/* 015F4 80B223D4 AFAC0010 */  sw      $t4, 0x0010($sp)           
/* 015F8 80B223D8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 015FC 80B223DC 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 01600 80B223E0 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 01604 80B223E4 0C00D09B */  jal     func_8003426C              
/* 01608 80B223E8 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 0160C 80B223EC 10000009 */  beq     $zero, $zero, .L80B22414   
/* 01610 80B223F0 8E10011C */  lw      $s0, 0x011C($s0)           ## 0000011C
.L80B223F4:
/* 01614 80B223F4 240D0050 */  addiu   $t5, $zero, 0x0050         ## $t5 = 00000050
/* 01618 80B223F8 AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 0161C 80B223FC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01620 80B22400 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 01624 80B22404 240600FF */  addiu   $a2, $zero, 0x00FF         ## $a2 = 000000FF
/* 01628 80B22408 0C00D09B */  jal     func_8003426C              
/* 0162C 80B2240C 24072000 */  addiu   $a3, $zero, 0x2000         ## $a3 = 00002000
.L80B22410:
/* 01630 80B22410 8E10011C */  lw      $s0, 0x011C($s0)           ## 0000011C
.L80B22414:
/* 01634 80B22414 5600FFE9 */  bnel    $s0, $zero, .L80B223BC     
/* 01638 80B22418 920A0185 */  lbu     $t2, 0x0185($s0)           ## 00000185
.L80B2241C:
/* 0163C 80B2241C 8FBF0034 */  lw      $ra, 0x0034($sp)           
.L80B22420:
/* 01640 80B22420 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 01644 80B22424 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 01648 80B22428 8FB20024 */  lw      $s2, 0x0024($sp)           
/* 0164C 80B2242C 8FB30028 */  lw      $s3, 0x0028($sp)           
/* 01650 80B22430 8FB4002C */  lw      $s4, 0x002C($sp)           
/* 01654 80B22434 8FB50030 */  lw      $s5, 0x0030($sp)           
/* 01658 80B22438 03E00008 */  jr      $ra                        
/* 0165C 80B2243C 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
