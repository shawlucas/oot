glabel func_809AEC1C
/* 00CFC 809AEC1C 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 00D00 809AEC20 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00D04 809AEC24 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 00D08 809AEC28 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 00D0C 809AEC2C 44812000 */  mtc1    $at, $f4                   ## $f4 = 8.00
/* 00D10 809AEC30 C480017C */  lwc1    $f0, 0x017C($a0)           ## 0000017C
/* 00D14 809AEC34 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00D18 809AEC38 3C014130 */  lui     $at, 0x4130                ## $at = 41300000
/* 00D1C 809AEC3C 46002032 */  c.eq.s  $f4, $f0                   
/* 00D20 809AEC40 00000000 */  nop
/* 00D24 809AEC44 45020019 */  bc1fl   .L809AECAC                 
/* 00D28 809AEC48 44812000 */  mtc1    $at, $f4                   ## $f4 = 11.00
/* 00D2C 809AEC4C C4860008 */  lwc1    $f6, 0x0008($a0)           ## 00000008
/* 00D30 809AEC50 C4880024 */  lwc1    $f8, 0x0024($a0)           ## 00000024
/* 00D34 809AEC54 46083032 */  c.eq.s  $f6, $f8                   
/* 00D38 809AEC58 00000000 */  nop
/* 00D3C 809AEC5C 4502000D */  bc1fl   .L809AEC94                 
/* 00D40 809AEC60 3C014140 */  lui     $at, 0x4140                ## $at = 41400000
/* 00D44 809AEC64 C48A0010 */  lwc1    $f10, 0x0010($a0)          ## 00000010
/* 00D48 809AEC68 C490002C */  lwc1    $f16, 0x002C($a0)          ## 0000002C
/* 00D4C 809AEC6C 24840032 */  addiu   $a0, $a0, 0x0032           ## $a0 = 00000032
/* 00D50 809AEC70 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 00D54 809AEC74 46105032 */  c.eq.s  $f10, $f16                 
/* 00D58 809AEC78 24071F40 */  addiu   $a3, $zero, 0x1F40         ## $a3 = 00001F40
/* 00D5C 809AEC7C 45020005 */  bc1fl   .L809AEC94                 
/* 00D60 809AEC80 3C014140 */  lui     $at, 0x4140                ## $at = 41400000
/* 00D64 809AEC84 86050016 */  lh      $a1, 0x0016($s0)           ## 00000016
/* 00D68 809AEC88 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 00D6C 809AEC8C AFA00010 */  sw      $zero, 0x0010($sp)         
/* 00D70 809AEC90 3C014140 */  lui     $at, 0x4140                ## $at = 41400000
.L809AEC94:
/* 00D74 809AEC94 44819000 */  mtc1    $at, $f18                  ## $f18 = 12.00
/* 00D78 809AEC98 240E0002 */  addiu   $t6, $zero, 0x0002         ## $t6 = 00000002
/* 00D7C 809AEC9C A60E0258 */  sh      $t6, 0x0258($s0)           ## 00000258
/* 00D80 809AECA0 1000001B */  beq     $zero, $zero, .L809AED10   
/* 00D84 809AECA4 E6120060 */  swc1    $f18, 0x0060($s0)          ## 00000060
/* 00D88 809AECA8 44812000 */  mtc1    $at, $f4                   ## $f4 = 12.00
.L809AECAC:
/* 00D8C 809AECAC 00000000 */  nop
/* 00D90 809AECB0 4600203C */  c.lt.s  $f4, $f0                   
/* 00D94 809AECB4 00000000 */  nop
/* 00D98 809AECB8 45020016 */  bc1fl   .L809AED14                 
/* 00D9C 809AECBC 860A0258 */  lh      $t2, 0x0258($s0)           ## 00000258
/* 00DA0 809AECC0 960F0088 */  lhu     $t7, 0x0088($s0)           ## 00000088
/* 00DA4 809AECC4 3C014130 */  lui     $at, 0x4130                ## $at = 41300000
/* 00DA8 809AECC8 24190001 */  addiu   $t9, $zero, 0x0001         ## $t9 = 00000001
/* 00DAC 809AECCC 31F80001 */  andi    $t8, $t7, 0x0001           ## $t8 = 00000000
/* 00DB0 809AECD0 17000004 */  bne     $t8, $zero, .L809AECE4     
/* 00DB4 809AECD4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00DB8 809AECD8 44813000 */  mtc1    $at, $f6                   ## $f6 = 11.00
/* 00DBC 809AECDC 1000000C */  beq     $zero, $zero, .L809AED10   
/* 00DC0 809AECE0 E606017C */  swc1    $f6, 0x017C($s0)           ## 0000017C
.L809AECE4:
/* 00DC4 809AECE4 0C26B89C */  jal     func_809AE270              
/* 00DC8 809AECE8 A6190258 */  sh      $t9, 0x0258($s0)           ## 00000258
/* 00DCC 809AECEC 86080032 */  lh      $t0, 0x0032($s0)           ## 00000032
/* 00DD0 809AECF0 86090016 */  lh      $t1, 0x0016($s0)           ## 00000016
/* 00DD4 809AECF4 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 00DD8 809AECF8 55090003 */  bnel    $t0, $t1, .L809AED08       
/* 00DDC 809AECFC C60A0080 */  lwc1    $f10, 0x0080($s0)          ## 00000080
/* 00DE0 809AED00 A6000258 */  sh      $zero, 0x0258($s0)         ## 00000258
/* 00DE4 809AED04 C60A0080 */  lwc1    $f10, 0x0080($s0)          ## 00000080
.L809AED08:
/* 00DE8 809AED08 E6080060 */  swc1    $f8, 0x0060($s0)           ## 00000060
/* 00DEC 809AED0C E60A0028 */  swc1    $f10, 0x0028($s0)          ## 00000028
.L809AED10:
/* 00DF0 809AED10 860A0258 */  lh      $t2, 0x0258($s0)           ## 00000258
.L809AED14:
/* 00DF4 809AED14 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 00DF8 809AED18 26040024 */  addiu   $a0, $s0, 0x0024           ## $a0 = 00000024
/* 00DFC 809AED1C 1541000D */  bne     $t2, $at, .L809AED54       
/* 00E00 809AED20 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00E04 809AED24 44808000 */  mtc1    $zero, $f16                ## $f16 = 0.00
/* 00E08 809AED28 8E050008 */  lw      $a1, 0x0008($s0)           ## 00000008
/* 00E0C 809AED2C 3C074100 */  lui     $a3, 0x4100                ## $a3 = 41000000
/* 00E10 809AED30 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 00E14 809AED34 E7B00010 */  swc1    $f16, 0x0010($sp)          
/* 00E18 809AED38 44809000 */  mtc1    $zero, $f18                ## $f18 = 0.00
/* 00E1C 809AED3C 8E050010 */  lw      $a1, 0x0010($s0)           ## 00000010
/* 00E20 809AED40 2604002C */  addiu   $a0, $s0, 0x002C           ## $a0 = 0000002C
/* 00E24 809AED44 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00E28 809AED48 3C074100 */  lui     $a3, 0x4100                ## $a3 = 41000000
/* 00E2C 809AED4C 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 00E30 809AED50 E7B20010 */  swc1    $f18, 0x0010($sp)          
.L809AED54:
/* 00E34 809AED54 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00E38 809AED58 26040164 */  addiu   $a0, $s0, 0x0164           ## $a0 = 00000164
/* 00E3C 809AED5C 860B0258 */  lh      $t3, 0x0258($s0)           ## 00000258
/* 00E40 809AED60 55600004 */  bnel    $t3, $zero, .L809AED74     
/* 00E44 809AED64 860C0032 */  lh      $t4, 0x0032($s0)           ## 00000032
/* 00E48 809AED68 0C26B903 */  jal     func_809AE40C              
/* 00E4C 809AED6C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00E50 809AED70 860C0032 */  lh      $t4, 0x0032($s0)           ## 00000032
.L809AED74:
/* 00E54 809AED74 A60C00B6 */  sh      $t4, 0x00B6($s0)           ## 000000B6
/* 00E58 809AED78 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00E5C 809AED7C 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00E60 809AED80 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00E64 809AED84 03E00008 */  jr      $ra                        
/* 00E68 809AED88 00000000 */  nop
