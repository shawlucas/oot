.late_rodata

glabel D_808647D0
 .float -0.8
glabel D_808647D4
 .float -0.8

.text
glabel func_808628C8
/* 03278 808628C8 27BDFFB0 */  addiu   $sp, $sp, 0xFFB0           ## $sp = FFFFFFB0
/* 0327C 808628CC AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 03280 808628D0 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 03284 808628D4 AFA50054 */  sw      $a1, 0x0054($sp)           
/* 03288 808628D8 8CAF1C44 */  lw      $t7, 0x1C44($a1)           ## 00001C44
/* 0328C 808628DC 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 03290 808628E0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 03294 808628E4 AFAF0048 */  sw      $t7, 0x0048($sp)           
/* 03298 808628E8 E7A40034 */  swc1    $f4, 0x0034($sp)           
/* 0329C 808628EC 8605008A */  lh      $a1, 0x008A($s0)           ## 0000008A
/* 032A0 808628F0 24180001 */  addiu   $t8, $zero, 0x0001         ## $t8 = 00000001
/* 032A4 808628F4 AFB80010 */  sw      $t8, 0x0010($sp)           
/* 032A8 808628F8 248400B6 */  addiu   $a0, $a0, 0x00B6           ## $a0 = 000000B6
/* 032AC 808628FC 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 032B0 80862900 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 032B4 80862904 24070FA0 */  addiu   $a3, $zero, 0x0FA0         ## $a3 = 00000FA0
/* 032B8 80862908 920307DE */  lbu     $v1, 0x07DE($s0)           ## 000007DE
/* 032BC 8086290C 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 032C0 80862910 14600002 */  bne     $v1, $zero, .L8086291C     
/* 032C4 80862914 24790001 */  addiu   $t9, $v1, 0x0001           ## $t9 = 00000001
/* 032C8 80862918 A21907DE */  sb      $t9, 0x07DE($s0)           ## 000007DE
.L8086291C:
/* 032CC 8086291C C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
/* 032D0 80862920 4600303E */  c.le.s  $f6, $f0                   
/* 032D4 80862924 00000000 */  nop
/* 032D8 80862928 4500000E */  bc1f    .L80862964                 
/* 032DC 8086292C 3C0140C0 */  lui     $at, 0x40C0                ## $at = 40C00000
/* 032E0 80862930 44811000 */  mtc1    $at, $f2                   ## $f2 = 6.00
/* 032E4 80862934 3C013E00 */  lui     $at, 0x3E00                ## $at = 3E000000
/* 032E8 80862938 4602003C */  c.lt.s  $f0, $f2                   
/* 032EC 8086293C 00000000 */  nop
/* 032F0 80862940 45000006 */  bc1f    .L8086295C                 
/* 032F4 80862944 00000000 */  nop
/* 032F8 80862948 44814000 */  mtc1    $at, $f8                   ## $f8 = 0.12
/* 032FC 8086294C 00000000 */  nop
/* 03300 80862950 46080280 */  add.s   $f10, $f0, $f8             
/* 03304 80862954 10000010 */  beq     $zero, $zero, .L80862998   
/* 03308 80862958 E60A0068 */  swc1    $f10, 0x0068($s0)          ## 00000068
.L8086295C:
/* 0330C 8086295C 1000000E */  beq     $zero, $zero, .L80862998   
/* 03310 80862960 E6020068 */  swc1    $f2, 0x0068($s0)           ## 00000068
.L80862964:
/* 03314 80862964 3C01C0C0 */  lui     $at, 0xC0C0                ## $at = C0C00000
/* 03318 80862968 44811000 */  mtc1    $at, $f2                   ## $f2 = -6.00
/* 0331C 8086296C 3C013E00 */  lui     $at, 0x3E00                ## $at = 3E000000
/* 03320 80862970 4600103C */  c.lt.s  $f2, $f0                   
/* 03324 80862974 00000000 */  nop
/* 03328 80862978 45020007 */  bc1fl   .L80862998                 
/* 0332C 8086297C E6020068 */  swc1    $f2, 0x0068($s0)           ## 00000068
/* 03330 80862980 44818000 */  mtc1    $at, $f16                  ## $f16 = 0.12
/* 03334 80862984 00000000 */  nop
/* 03338 80862988 46100481 */  sub.s   $f18, $f0, $f16            
/* 0333C 8086298C 10000002 */  beq     $zero, $zero, .L80862998   
/* 03340 80862990 E6120068 */  swc1    $f18, 0x0068($s0)          ## 00000068
/* 03344 80862994 E6020068 */  swc1    $f2, 0x0068($s0)           ## 00000068
.L80862998:
/* 03348 80862998 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 0334C 8086299C 30420008 */  andi    $v0, $v0, 0x0008           ## $v0 = 00000000
/* 03350 808629A0 14400011 */  bne     $v0, $zero, .L808629E8     
/* 03354 808629A4 00000000 */  nop
/* 03358 808629A8 8608001C */  lh      $t0, 0x001C($s0)           ## 0000001C
/* 0335C 808629AC 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 03360 808629B0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 03364 808629B4 55010045 */  bnel    $t0, $at, .L80862ACC       
/* 03368 808629B8 860A00B6 */  lh      $t2, 0x00B6($s0)           ## 000000B6
/* 0336C 808629BC 860700B6 */  lh      $a3, 0x00B6($s0)           ## 000000B6
/* 03370 808629C0 8FA50054 */  lw      $a1, 0x0054($sp)           
/* 03374 808629C4 8E060068 */  lw      $a2, 0x0068($s0)           ## 00000068
/* 03378 808629C8 24E73FFF */  addiu   $a3, $a3, 0x3FFF           ## $a3 = 00003FFF
/* 0337C 808629CC 00073C00 */  sll     $a3, $a3, 16               
/* 03380 808629D0 0C00CE6E */  jal     func_800339B8              
/* 03384 808629D4 00073C03 */  sra     $a3, $a3, 16               
/* 03388 808629D8 5440003C */  bnel    $v0, $zero, .L80862ACC     
/* 0338C 808629DC 860A00B6 */  lh      $t2, 0x00B6($s0)           ## 000000B6
/* 03390 808629E0 96020088 */  lhu     $v0, 0x0088($s0)           ## 00000088
/* 03394 808629E4 30420008 */  andi    $v0, $v0, 0x0008           ## $v0 = 00000000
.L808629E8:
/* 03398 808629E8 10400016 */  beq     $v0, $zero, .L80862A44     
/* 0339C 808629EC 3C018086 */  lui     $at, %hi(D_808647D0)       ## $at = 80860000
/* 033A0 808629F0 C6040068 */  lwc1    $f4, 0x0068($s0)           ## 00000068
/* 033A4 808629F4 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 033A8 808629F8 00000000 */  nop
/* 033AC 808629FC 4604303E */  c.le.s  $f6, $f4                   
/* 033B0 80862A00 00000000 */  nop
/* 033B4 80862A04 45020007 */  bc1fl   .L80862A24                 
/* 033B8 80862A08 860200B6 */  lh      $v0, 0x00B6($s0)           ## 000000B6
/* 033BC 80862A0C 860200B6 */  lh      $v0, 0x00B6($s0)           ## 000000B6
/* 033C0 80862A10 24423FFF */  addiu   $v0, $v0, 0x3FFF           ## $v0 = 00003FFF
/* 033C4 80862A14 00021400 */  sll     $v0, $v0, 16               
/* 033C8 80862A18 10000005 */  beq     $zero, $zero, .L80862A30   
/* 033CC 80862A1C 00021403 */  sra     $v0, $v0, 16               
/* 033D0 80862A20 860200B6 */  lh      $v0, 0x00B6($s0)           ## 000000B6
.L80862A24:
/* 033D4 80862A24 2442C001 */  addiu   $v0, $v0, 0xC001           ## $v0 = 00000000
/* 033D8 80862A28 00021400 */  sll     $v0, $v0, 16               
/* 033DC 80862A2C 00021403 */  sra     $v0, $v0, 16               
.L80862A30:
/* 033E0 80862A30 8609007E */  lh      $t1, 0x007E($s0)           ## 0000007E
/* 033E4 80862A34 01221023 */  subu    $v0, $t1, $v0              
/* 033E8 80862A38 00021400 */  sll     $v0, $v0, 16               
/* 033EC 80862A3C 10000006 */  beq     $zero, $zero, .L80862A58   
/* 033F0 80862A40 00021403 */  sra     $v0, $v0, 16               
.L80862A44:
/* 033F4 80862A44 C6080068 */  lwc1    $f8, 0x0068($s0)           ## 00000068
/* 033F8 80862A48 C42A47D0 */  lwc1    $f10, %lo(D_808647D0)($at) 
/* 033FC 80862A4C 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 03400 80862A50 460A4402 */  mul.s   $f16, $f8, $f10            
/* 03404 80862A54 E6100068 */  swc1    $f16, 0x0068($s0)          ## 00000068
.L80862A58:
/* 03408 80862A58 04400003 */  bltz    $v0, .L80862A68            
/* 0340C 80862A5C 00021823 */  subu    $v1, $zero, $v0            
/* 03410 80862A60 10000001 */  beq     $zero, $zero, .L80862A68   
/* 03414 80862A64 00401825 */  or      $v1, $v0, $zero            ## $v1 = 00000000
.L80862A68:
/* 03418 80862A68 28614001 */  slti    $at, $v1, 0x4001           
/* 0341C 80862A6C 14200016 */  bne     $at, $zero, .L80862AC8     
/* 03420 80862A70 3C018086 */  lui     $at, %hi(D_808647D4)       ## $at = 80860000
/* 03424 80862A74 C42447D4 */  lwc1    $f4, %lo(D_808647D4)($at)  
/* 03428 80862A78 C6120068 */  lwc1    $f18, 0x0068($s0)          ## 00000068
/* 0342C 80862A7C 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 03430 80862A80 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 03434 80862A84 46049182 */  mul.s   $f6, $f18, $f4             
/* 03438 80862A88 E6060068 */  swc1    $f6, 0x0068($s0)           ## 00000068
/* 0343C 80862A8C C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
/* 03440 80862A90 4608003C */  c.lt.s  $f0, $f8                   
/* 03444 80862A94 00000000 */  nop
/* 03448 80862A98 45020008 */  bc1fl   .L80862ABC                 
/* 0344C 80862A9C 44819000 */  mtc1    $at, $f18                  ## $f18 = 0.50
/* 03450 80862AA0 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 03454 80862AA4 44815000 */  mtc1    $at, $f10                  ## $f10 = 0.50
/* 03458 80862AA8 00000000 */  nop
/* 0345C 80862AAC 460A0401 */  sub.s   $f16, $f0, $f10            
/* 03460 80862AB0 10000005 */  beq     $zero, $zero, .L80862AC8   
/* 03464 80862AB4 E6100068 */  swc1    $f16, 0x0068($s0)          ## 00000068
/* 03468 80862AB8 44819000 */  mtc1    $at, $f18                  ## $f18 = 0.50
.L80862ABC:
/* 0346C 80862ABC 00000000 */  nop
/* 03470 80862AC0 46120100 */  add.s   $f4, $f0, $f18             
/* 03474 80862AC4 E6040068 */  swc1    $f4, 0x0068($s0)           ## 00000068
.L80862AC8:
/* 03478 80862AC8 860A00B6 */  lh      $t2, 0x00B6($s0)           ## 000000B6
.L80862ACC:
/* 0347C 80862ACC 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 03480 80862AD0 254B3FFF */  addiu   $t3, $t2, 0x3FFF           ## $t3 = 00003FFF
/* 03484 80862AD4 A60B0032 */  sh      $t3, 0x0032($s0)           ## 00000032
/* 03488 80862AD8 0C00CEAE */  jal     func_80033AB8              
/* 0348C 80862ADC 8FA40054 */  lw      $a0, 0x0054($sp)           
/* 03490 80862AE0 10400004 */  beq     $v0, $zero, .L80862AF4     
/* 03494 80862AE4 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 03498 80862AE8 44811000 */  mtc1    $at, $f2                   ## $f2 = 200.00
/* 0349C 80862AEC 00000000 */  nop
/* 034A0 80862AF0 E7A20034 */  swc1    $f2, 0x0034($sp)           
.L80862AF4:
/* 034A4 80862AF4 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 034A8 80862AF8 C7A20034 */  lwc1    $f2, 0x0034($sp)           
/* 034AC 80862AFC 44813000 */  mtc1    $at, $f6                   ## $f6 = 80.00
/* 034B0 80862B00 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 034B4 80862B04 260407EC */  addiu   $a0, $s0, 0x07EC           ## $a0 = 000007EC
/* 034B8 80862B08 46023200 */  add.s   $f8, $f6, $f2              
/* 034BC 80862B0C 3C05C020 */  lui     $a1, 0xC020                ## $a1 = C0200000
/* 034C0 80862B10 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 034C4 80862B14 3C073F4C */  lui     $a3, 0x3F4C                ## $a3 = 3F4C0000
/* 034C8 80862B18 4608003E */  c.le.s  $f0, $f8                   
/* 034CC 80862B1C 3C0142DC */  lui     $at, 0x42DC                ## $at = 42DC0000
/* 034D0 80862B20 45020008 */  bc1fl   .L80862B44                 
/* 034D4 80862B24 44818000 */  mtc1    $at, $f16                  ## $f16 = 110.00
/* 034D8 80862B28 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 034DC 80862B2C 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 3F4CCCCD
/* 034E0 80862B30 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 034E4 80862B34 E7AA0010 */  swc1    $f10, 0x0010($sp)          
/* 034E8 80862B38 1000001A */  beq     $zero, $zero, .L80862BA4   
/* 034EC 80862B3C 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 034F0 80862B40 44818000 */  mtc1    $at, $f16                  ## $f16 = 0.00
.L80862B44:
/* 034F4 80862B44 260407EC */  addiu   $a0, $s0, 0x07EC           ## $a0 = 000007EC
/* 034F8 80862B48 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 034FC 80862B4C 46028480 */  add.s   $f18, $f16, $f2            
/* 03500 80862B50 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 03504 80862B54 3C0740D4 */  lui     $a3, 0x40D4                ## $a3 = 40D40000
/* 03508 80862B58 4600903C */  c.lt.s  $f18, $f0                  
/* 0350C 80862B5C 00000000 */  nop
/* 03510 80862B60 4502000C */  bc1fl   .L80862B94                 
/* 03514 80862B64 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 03518 80862B68 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 0351C 80862B6C 3C073F4C */  lui     $a3, 0x3F4C                ## $a3 = 3F4C0000
/* 03520 80862B70 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 3F4CCCCD
/* 03524 80862B74 260407EC */  addiu   $a0, $s0, 0x07EC           ## $a0 = 000007EC
/* 03528 80862B78 3C054020 */  lui     $a1, 0x4020                ## $a1 = 40200000
/* 0352C 80862B7C 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 03530 80862B80 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 03534 80862B84 E7A40010 */  swc1    $f4, 0x0010($sp)           
/* 03538 80862B88 10000006 */  beq     $zero, $zero, .L80862BA4   
/* 0353C 80862B8C 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 03540 80862B90 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
.L80862B94:
/* 03544 80862B94 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 0000CCCD
/* 03548 80862B98 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 0354C 80862B9C E7A60010 */  swc1    $f6, 0x0010($sp)           
/* 03550 80862BA0 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
.L80862BA4:
/* 03554 80862BA4 C60A07EC */  lwc1    $f10, 0x07EC($s0)          ## 000007EC
/* 03558 80862BA8 460A4032 */  c.eq.s  $f8, $f10                  
/* 0355C 80862BAC 00000000 */  nop
/* 03560 80862BB0 45030010 */  bc1tl   .L80862BF4                 
/* 03564 80862BB4 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 03568 80862BB8 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0356C 80862BBC 860400B6 */  lh      $a0, 0x00B6($s0)           ## 000000B6
/* 03570 80862BC0 C61207EC */  lwc1    $f18, 0x07EC($s0)          ## 000007EC
/* 03574 80862BC4 C6100024 */  lwc1    $f16, 0x0024($s0)          ## 00000024
/* 03578 80862BC8 860400B6 */  lh      $a0, 0x00B6($s0)           ## 000000B6
/* 0357C 80862BCC 46120102 */  mul.s   $f4, $f0, $f18             
/* 03580 80862BD0 46048180 */  add.s   $f6, $f16, $f4             
/* 03584 80862BD4 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 03588 80862BD8 E6060024 */  swc1    $f6, 0x0024($s0)           ## 00000024
/* 0358C 80862BDC C60A07EC */  lwc1    $f10, 0x07EC($s0)          ## 000007EC
/* 03590 80862BE0 C608002C */  lwc1    $f8, 0x002C($s0)           ## 0000002C
/* 03594 80862BE4 460A0482 */  mul.s   $f18, $f0, $f10            
/* 03598 80862BE8 46124400 */  add.s   $f16, $f8, $f18            
/* 0359C 80862BEC E610002C */  swc1    $f16, 0x002C($s0)          ## 0000002C
/* 035A0 80862BF0 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
.L80862BF4:
/* 035A4 80862BF4 44813000 */  mtc1    $at, $f6                   ## $f6 = 0.50
/* 035A8 80862BF8 C6040068 */  lwc1    $f4, 0x0068($s0)           ## 00000068
/* 035AC 80862BFC C60801A0 */  lwc1    $f8, 0x01A0($s0)           ## 000001A0
/* 035B0 80862C00 26040188 */  addiu   $a0, $s0, 0x0188           ## $a0 = 00000188
/* 035B4 80862C04 46062282 */  mul.s   $f10, $f4, $f6             
/* 035B8 80862C08 4600448D */  trunc.w.s $f18, $f8                  
/* 035BC 80862C0C 440D9000 */  mfc1    $t5, $f18                  
/* 035C0 80862C10 E60A01A4 */  swc1    $f10, 0x01A4($s0)          ## 000001A4
/* 035C4 80862C14 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 035C8 80862C18 AFAD0040 */  sw      $t5, 0x0040($sp)           
/* 035CC 80862C1C 44807000 */  mtc1    $zero, $f14                ## $f14 = 0.00
/* 035D0 80862C20 C60001A4 */  lwc1    $f0, 0x01A4($s0)           ## 000001A4
/* 035D4 80862C24 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 035D8 80862C28 24053838 */  addiu   $a1, $zero, 0x3838         ## $a1 = 00003838
/* 035DC 80862C2C 4600703E */  c.le.s  $f14, $f0                  
/* 035E0 80862C30 00000000 */  nop
/* 035E4 80862C34 45020004 */  bc1fl   .L80862C48                 
/* 035E8 80862C38 46000087 */  neg.s   $f2, $f0                   
/* 035EC 80862C3C 10000002 */  beq     $zero, $zero, .L80862C48   
/* 035F0 80862C40 46000086 */  mov.s   $f2, $f0                   
/* 035F4 80862C44 46000087 */  neg.s   $f2, $f0                   
.L80862C48:
/* 035F8 80862C48 C60C01A0 */  lwc1    $f12, 0x01A0($s0)          ## 000001A0
/* 035FC 80862C4C 4600703E */  c.le.s  $f14, $f0                  
/* 03600 80862C50 46026401 */  sub.s   $f16, $f12, $f2            
/* 03604 80862C54 4600810D */  trunc.w.s $f4, $f16                  
/* 03608 80862C58 44032000 */  mfc1    $v1, $f4                   
/* 0360C 80862C5C 45020004 */  bc1fl   .L80862C70                 
/* 03610 80862C60 46000087 */  neg.s   $f2, $f0                   
/* 03614 80862C64 10000002 */  beq     $zero, $zero, .L80862C70   
/* 03618 80862C68 46000086 */  mov.s   $f2, $f0                   
/* 0361C 80862C6C 46000087 */  neg.s   $f2, $f0                   
.L80862C70:
/* 03620 80862C70 8E0F07E8 */  lw      $t7, 0x07E8($s0)           ## 000007E8
/* 03624 80862C74 31F8001F */  andi    $t8, $t7, 0x001F           ## $t8 = 00000000
/* 03628 80862C78 57000008 */  bnel    $t8, $zero, .L80862C9C     
/* 0362C 80862C7C 4600618D */  trunc.w.s $f6, $f12                  
/* 03630 80862C80 AFA3003C */  sw      $v1, 0x003C($sp)           
/* 03634 80862C84 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 03638 80862C88 E7A2002C */  swc1    $f2, 0x002C($sp)           
/* 0363C 80862C8C 8FA3003C */  lw      $v1, 0x003C($sp)           
/* 03640 80862C90 C7A2002C */  lwc1    $f2, 0x002C($sp)           
/* 03644 80862C94 C60C01A0 */  lwc1    $f12, 0x01A0($s0)          ## 000001A0
/* 03648 80862C98 4600618D */  trunc.w.s $f6, $f12                  
.L80862C9C:
/* 0364C 80862C9C 8FA40040 */  lw      $a0, 0x0040($sp)           
/* 03650 80862CA0 44083000 */  mfc1    $t0, $f6                   
/* 03654 80862CA4 00000000 */  nop
/* 03658 80862CA8 50880011 */  beql    $a0, $t0, .L80862CF0       
/* 0365C 80862CAC 8E0207E8 */  lw      $v0, 0x07E8($s0)           ## 000007E8
/* 03660 80862CB0 4600128D */  trunc.w.s $f10, $f2                  
/* 03664 80862CB4 440A5000 */  mfc1    $t2, $f10                  
/* 03668 80862CB8 00000000 */  nop
/* 0366C 80862CBC 01441021 */  addu    $v0, $t2, $a0              
/* 03670 80862CC0 28410002 */  slti    $at, $v0, 0x0002           
/* 03674 80862CC4 54200003 */  bnel    $at, $zero, .L80862CD4     
/* 03678 80862CC8 28610007 */  slti    $at, $v1, 0x0007           
/* 0367C 80862CCC 18600004 */  blez    $v1, .L80862CE0            
/* 03680 80862CD0 28610007 */  slti    $at, $v1, 0x0007           
.L80862CD4:
/* 03684 80862CD4 10200005 */  beq     $at, $zero, .L80862CEC     
/* 03688 80862CD8 28410008 */  slti    $at, $v0, 0x0008           
/* 0368C 80862CDC 14200003 */  bne     $at, $zero, .L80862CEC     
.L80862CE0:
/* 03690 80862CE0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 03694 80862CE4 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 03698 80862CE8 2405383D */  addiu   $a1, $zero, 0x383D         ## $a1 = 0000383D
.L80862CEC:
/* 0369C 80862CEC 8E0207E8 */  lw      $v0, 0x07E8($s0)           ## 000007E8
.L80862CF0:
/* 036A0 80862CF0 8FA40054 */  lw      $a0, 0x0054($sp)           
/* 036A4 80862CF4 1440002B */  bne     $v0, $zero, .L80862DA4     
/* 036A8 80862CF8 2458FFFF */  addiu   $t8, $v0, 0xFFFF           ## $t8 = FFFFFFFF
/* 036AC 80862CFC 0C00CEAE */  jal     func_80033AB8              
/* 036B0 80862D00 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 036B4 80862D04 10400005 */  beq     $v0, $zero, .L80862D1C     
/* 036B8 80862D08 8FA40054 */  lw      $a0, 0x0054($sp)           
/* 036BC 80862D0C 0C21801A */  jal     func_80860068              
/* 036C0 80862D10 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 036C4 80862D14 10000025 */  beq     $zero, $zero, .L80862DAC   
/* 036C8 80862D18 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80862D1C:
/* 036CC 80862D1C 0C00CEA1 */  jal     func_80033A84              
/* 036D0 80862D20 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 036D4 80862D24 1040000A */  beq     $v0, $zero, .L80862D50     
/* 036D8 80862D28 8FAB0048 */  lw      $t3, 0x0048($sp)           
/* 036DC 80862D2C 8FA40054 */  lw      $a0, 0x0054($sp)           
/* 036E0 80862D30 0C21907A */  jal     func_808641E8              
/* 036E4 80862D34 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 036E8 80862D38 1440001B */  bne     $v0, $zero, .L80862DA8     
/* 036EC 80862D3C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 036F0 80862D40 0C217EAC */  jal     func_8085FAB0              
/* 036F4 80862D44 8FA50054 */  lw      $a1, 0x0054($sp)           
/* 036F8 80862D48 10000018 */  beq     $zero, $zero, .L80862DAC   
/* 036FC 80862D4C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80862D50:
/* 03700 80862D50 816C0151 */  lb      $t4, 0x0151($t3)           ## 00000151
/* 03704 80862D54 8FAD0054 */  lw      $t5, 0x0054($sp)           
/* 03708 80862D58 3C0E0001 */  lui     $t6, 0x0001                ## $t6 = 00010000
/* 0370C 80862D5C 1180000D */  beq     $t4, $zero, .L80862D94     
/* 03710 80862D60 01CD7021 */  addu    $t6, $t6, $t5              
/* 03714 80862D64 8DCE1DE4 */  lw      $t6, 0x1DE4($t6)           ## 00011DE4
/* 03718 80862D68 31CF0001 */  andi    $t7, $t6, 0x0001           ## $t7 = 00000000
/* 0371C 80862D6C 11E00005 */  beq     $t7, $zero, .L80862D84     
/* 03720 80862D70 00000000 */  nop
/* 03724 80862D74 0C21801A */  jal     func_80860068              
/* 03728 80862D78 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0372C 80862D7C 1000000B */  beq     $zero, $zero, .L80862DAC   
/* 03730 80862D80 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80862D84:
/* 03734 80862D84 0C21810E */  jal     func_80860438              
/* 03738 80862D88 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0373C 80862D8C 10000007 */  beq     $zero, $zero, .L80862DAC   
/* 03740 80862D90 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80862D94:
/* 03744 80862D94 0C21810E */  jal     func_80860438              
/* 03748 80862D98 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0374C 80862D9C 10000003 */  beq     $zero, $zero, .L80862DAC   
/* 03750 80862DA0 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80862DA4:
/* 03754 80862DA4 AE1807E8 */  sw      $t8, 0x07E8($s0)           ## 000007E8
.L80862DA8:
/* 03758 80862DA8 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80862DAC:
/* 0375C 80862DAC 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 03760 80862DB0 27BD0050 */  addiu   $sp, $sp, 0x0050           ## $sp = 00000000
/* 03764 80862DB4 03E00008 */  jr      $ra                        
/* 03768 80862DB8 00000000 */  nop


