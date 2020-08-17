.late_rodata
glabel D_809E16FC
    .float 0.1

glabel D_809E1700
    .float 0.1

.text
glabel func_809E0864
/* 00624 809E0864 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 00628 809E0868 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 0062C 809E086C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00630 809E0870 AFA50044 */  sw      $a1, 0x0044($sp)           
/* 00634 809E0874 8CAF1C44 */  lw      $t7, 0x1C44($a1)           ## 00001C44
/* 00638 809E0878 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0063C 809E087C 2484017C */  addiu   $a0, $a0, 0x017C           ## $a0 = 0000017C
/* 00640 809E0880 AFA40028 */  sw      $a0, 0x0028($sp)           
/* 00644 809E0884 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00648 809E0888 AFAF003C */  sw      $t7, 0x003C($sp)           
/* 0064C 809E088C 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 00650 809E0890 0C0295B2 */  jal     func_800A56C8              
/* 00654 809E0894 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 00658 809E0898 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 0065C 809E089C AFA20038 */  sw      $v0, 0x0038($sp)           
/* 00660 809E08A0 3C013FC0 */  lui     $at, 0x3FC0                ## $at = 3FC00000
/* 00664 809E08A4 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.50
/* 00668 809E08A8 3C014040 */  lui     $at, 0x4040                ## $at = 40400000
/* 0066C 809E08AC 44814000 */  mtc1    $at, $f8                   ## $f8 = 3.00
/* 00670 809E08B0 46040182 */  mul.s   $f6, $f0, $f4              
/* 00674 809E08B4 96180088 */  lhu     $t8, 0x0088($s0)           ## 00000088
/* 00678 809E08B8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0067C 809E08BC 26050008 */  addiu   $a1, $s0, 0x0008           ## $a1 = 00000008
/* 00680 809E08C0 33190008 */  andi    $t9, $t8, 0x0008           ## $t9 = 00000000
/* 00684 809E08C4 46083280 */  add.s   $f10, $f6, $f8             
/* 00688 809E08C8 13200004 */  beq     $t9, $zero, .L809E08DC     
/* 0068C 809E08CC E60A0068 */  swc1    $f10, 0x0068($s0)          ## 00000068
/* 00690 809E08D0 8608007E */  lh      $t0, 0x007E($s0)           ## 0000007E
/* 00694 809E08D4 1000000D */  beq     $zero, $zero, .L809E090C   
/* 00698 809E08D8 A60801C8 */  sh      $t0, 0x01C8($s0)           ## 000001C8
.L809E08DC:
/* 0069C 809E08DC 0C00B6EC */  jal     ActorSearch_PosDistanceXZ              
/* 006A0 809E08E0 AFA50028 */  sw      $a1, 0x0028($sp)           
/* 006A4 809E08E4 3C014396 */  lui     $at, 0x4396                ## $at = 43960000
/* 006A8 809E08E8 44818000 */  mtc1    $at, $f16                  ## $f16 = 300.00
/* 006AC 809E08EC 8FA50028 */  lw      $a1, 0x0028($sp)           
/* 006B0 809E08F0 4600803C */  c.lt.s  $f16, $f0                  
/* 006B4 809E08F4 00000000 */  nop
/* 006B8 809E08F8 45020005 */  bc1fl   .L809E0910                 
/* 006BC 809E08FC 860501C8 */  lh      $a1, 0x01C8($s0)           ## 000001C8
/* 006C0 809E0900 0C00B6B0 */  jal     ActorSearch_PosAngleY              
/* 006C4 809E0904 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 006C8 809E0908 A60201C8 */  sh      $v0, 0x01C8($s0)           ## 000001C8
.L809E090C:
/* 006CC 809E090C 860501C8 */  lh      $a1, 0x01C8($s0)           ## 000001C8
.L809E0910:
/* 006D0 809E0910 24090010 */  addiu   $t1, $zero, 0x0010         ## $t1 = 00000010
/* 006D4 809E0914 AFA90010 */  sw      $t1, 0x0010($sp)           
/* 006D8 809E0918 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
/* 006DC 809E091C 24060005 */  addiu   $a2, $zero, 0x0005         ## $a2 = 00000005
/* 006E0 809E0920 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 006E4 809E0924 24070300 */  addiu   $a3, $zero, 0x0300         ## $a3 = 00000300
/* 006E8 809E0928 14400035 */  bne     $v0, $zero, .L809E0A00     
/* 006EC 809E092C 8FAA0038 */  lw      $t2, 0x0038($sp)           
/* 006F0 809E0930 51400034 */  beql    $t2, $zero, .L809E0A04     
/* 006F4 809E0934 3C01C220 */  lui     $at, 0xC220                ## $at = C2200000
/* 006F8 809E0938 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 006FC 809E093C 00000000 */  nop
/* 00700 809E0940 3C01809E */  lui     $at, %hi(D_809E16FC)       ## $at = 809E0000
/* 00704 809E0944 C43216FC */  lwc1    $f18, %lo(D_809E16FC)($at) 
/* 00708 809E0948 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0070C 809E094C 4612003C */  c.lt.s  $f0, $f18                  
/* 00710 809E0950 00000000 */  nop
/* 00714 809E0954 4502002B */  bc1fl   .L809E0A04                 
/* 00718 809E0958 3C01C220 */  lui     $at, 0xC220                ## $at = C2200000
/* 0071C 809E095C 0C00B6B0 */  jal     ActorSearch_PosAngleY              
/* 00720 809E0960 26050008 */  addiu   $a1, $s0, 0x0008           ## $a1 = 00000008
/* 00724 809E0964 860B00B6 */  lh      $t3, 0x00B6($s0)           ## 000000B6
/* 00728 809E0968 004B1823 */  subu    $v1, $v0, $t3              
/* 0072C 809E096C 00031C00 */  sll     $v1, $v1, 16               
/* 00730 809E0970 00031C03 */  sra     $v1, $v1, 16               
/* 00734 809E0974 18600010 */  blez    $v1, .L809E09B8            
/* 00738 809E0978 00000000 */  nop
/* 0073C 809E097C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00740 809E0980 00000000 */  nop
/* 00744 809E0984 3C014580 */  lui     $at, 0x4580                ## $at = 45800000
/* 00748 809E0988 44811000 */  mtc1    $at, $f2                   ## $f2 = 4096.00
/* 0074C 809E098C 860C01C8 */  lh      $t4, 0x01C8($s0)           ## 000001C8
/* 00750 809E0990 46001202 */  mul.s   $f8, $f2, $f0              
/* 00754 809E0994 448C2000 */  mtc1    $t4, $f4                   ## $f4 = 0.00
/* 00758 809E0998 00000000 */  nop
/* 0075C 809E099C 468021A0 */  cvt.s.w $f6, $f4                   
/* 00760 809E09A0 46081280 */  add.s   $f10, $f2, $f8             
/* 00764 809E09A4 460A3400 */  add.s   $f16, $f6, $f10            
/* 00768 809E09A8 4600848D */  trunc.w.s $f18, $f16                 
/* 0076C 809E09AC 440E9000 */  mfc1    $t6, $f18                  
/* 00770 809E09B0 10000010 */  beq     $zero, $zero, .L809E09F4   
/* 00774 809E09B4 A60E01C8 */  sh      $t6, 0x01C8($s0)           ## 000001C8
.L809E09B8:
/* 00778 809E09B8 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 0077C 809E09BC 00000000 */  nop
/* 00780 809E09C0 3C014580 */  lui     $at, 0x4580                ## $at = 45800000
/* 00784 809E09C4 44811000 */  mtc1    $at, $f2                   ## $f2 = 4096.00
/* 00788 809E09C8 860F01C8 */  lh      $t7, 0x01C8($s0)           ## 000001C8
/* 0078C 809E09CC 46001182 */  mul.s   $f6, $f2, $f0              
/* 00790 809E09D0 448F2000 */  mtc1    $t7, $f4                   ## $f4 = 0.00
/* 00794 809E09D4 00000000 */  nop
/* 00798 809E09D8 46802220 */  cvt.s.w $f8, $f4                   
/* 0079C 809E09DC 46061280 */  add.s   $f10, $f2, $f6             
/* 007A0 809E09E0 460A4401 */  sub.s   $f16, $f8, $f10            
/* 007A4 809E09E4 4600848D */  trunc.w.s $f18, $f16                 
/* 007A8 809E09E8 44199000 */  mfc1    $t9, $f18                  
/* 007AC 809E09EC 00000000 */  nop
/* 007B0 809E09F0 A61901C8 */  sh      $t9, 0x01C8($s0)           ## 000001C8
.L809E09F4:
/* 007B4 809E09F4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 007B8 809E09F8 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 007BC 809E09FC 240538B6 */  addiu   $a1, $zero, 0x38B6         ## $a1 = 000038B6
.L809E0A00:
/* 007C0 809E0A00 3C01C220 */  lui     $at, 0xC220                ## $at = C2200000
.L809E0A04:
/* 007C4 809E0A04 44812000 */  mtc1    $at, $f4                   ## $f4 = -40.00
/* 007C8 809E0A08 C6060084 */  lwc1    $f6, 0x0084($s0)           ## 00000084
/* 007CC 809E0A0C 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 007D0 809E0A10 2408F000 */  addiu   $t0, $zero, 0xF000         ## $t0 = FFFFF000
/* 007D4 809E0A14 4606203C */  c.lt.s  $f4, $f6                   
/* 007D8 809E0A18 00000000 */  nop
/* 007DC 809E0A1C 45020004 */  bc1fl   .L809E0A30                 
/* 007E0 809E0A20 44816000 */  mtc1    $at, $f12                  ## $f12 = 50.00
/* 007E4 809E0A24 10000025 */  beq     $zero, $zero, .L809E0ABC   
/* 007E8 809E0A28 A60801C6 */  sh      $t0, 0x01C6($s0)           ## 000001C6
/* 007EC 809E0A2C 44816000 */  mtc1    $at, $f12                  ## $f12 = 50.00
.L809E0A30:
/* 007F0 809E0A30 C602000C */  lwc1    $f2, 0x000C($s0)           ## 0000000C
/* 007F4 809E0A34 C6000028 */  lwc1    $f0, 0x0028($s0)           ## 00000028
/* 007F8 809E0A38 460C1201 */  sub.s   $f8, $f2, $f12             
/* 007FC 809E0A3C 4608003C */  c.lt.s  $f0, $f8                   
/* 00800 809E0A40 00000000 */  nop
/* 00804 809E0A44 4502000E */  bc1fl   .L809E0A80                 
/* 00808 809E0A48 460C1180 */  add.s   $f6, $f2, $f12             
/* 0080C 809E0A4C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00810 809E0A50 00000000 */  nop
/* 00814 809E0A54 3C014500 */  lui     $at, 0x4500                ## $at = 45000000
/* 00818 809E0A58 44811000 */  mtc1    $at, $f2                   ## $f2 = 2048.00
/* 0081C 809E0A5C 3C01C500 */  lui     $at, 0xC500                ## $at = C5000000
/* 00820 809E0A60 44815000 */  mtc1    $at, $f10                  ## $f10 = -2048.00
/* 00824 809E0A64 46020402 */  mul.s   $f16, $f0, $f2             
/* 00828 809E0A68 46105481 */  sub.s   $f18, $f10, $f16           
/* 0082C 809E0A6C 4600910D */  trunc.w.s $f4, $f18                  
/* 00830 809E0A70 440A2000 */  mfc1    $t2, $f4                   
/* 00834 809E0A74 10000011 */  beq     $zero, $zero, .L809E0ABC   
/* 00838 809E0A78 A60A01C6 */  sh      $t2, 0x01C6($s0)           ## 000001C6
/* 0083C 809E0A7C 460C1180 */  add.s   $f6, $f2, $f12             
.L809E0A80:
/* 00840 809E0A80 4600303C */  c.lt.s  $f6, $f0                   
/* 00844 809E0A84 00000000 */  nop
/* 00848 809E0A88 4502000D */  bc1fl   .L809E0AC0                 
/* 0084C 809E0A8C 260400B4 */  addiu   $a0, $s0, 0x00B4           ## $a0 = 000000B4
/* 00850 809E0A90 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00854 809E0A94 00000000 */  nop
/* 00858 809E0A98 3C014500 */  lui     $at, 0x4500                ## $at = 45000000
/* 0085C 809E0A9C 44811000 */  mtc1    $at, $f2                   ## $f2 = 2048.00
/* 00860 809E0AA0 00000000 */  nop
/* 00864 809E0AA4 46020202 */  mul.s   $f8, $f0, $f2              
/* 00868 809E0AA8 46024280 */  add.s   $f10, $f8, $f2             
/* 0086C 809E0AAC 4600540D */  trunc.w.s $f16, $f10                 
/* 00870 809E0AB0 440C8000 */  mfc1    $t4, $f16                  
/* 00874 809E0AB4 00000000 */  nop
/* 00878 809E0AB8 A60C01C6 */  sh      $t4, 0x01C6($s0)           ## 000001C6
.L809E0ABC:
/* 0087C 809E0ABC 260400B4 */  addiu   $a0, $s0, 0x00B4           ## $a0 = 000000B4
.L809E0AC0:
/* 00880 809E0AC0 860501C6 */  lh      $a1, 0x01C6($s0)           ## 000001C6
/* 00884 809E0AC4 240D0008 */  addiu   $t5, $zero, 0x0008         ## $t5 = 00000008
/* 00888 809E0AC8 AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 0088C 809E0ACC AFA40028 */  sw      $a0, 0x0028($sp)           
/* 00890 809E0AD0 2406000A */  addiu   $a2, $zero, 0x000A         ## $a2 = 0000000A
/* 00894 809E0AD4 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 00898 809E0AD8 24070100 */  addiu   $a3, $zero, 0x0100         ## $a3 = 00000100
/* 0089C 809E0ADC 1440003C */  bne     $v0, $zero, .L809E0BD0     
/* 008A0 809E0AE0 8FAE0038 */  lw      $t6, 0x0038($sp)           
/* 008A4 809E0AE4 51C0003B */  beql    $t6, $zero, .L809E0BD4     
/* 008A8 809E0AE8 960C0088 */  lhu     $t4, 0x0088($s0)           ## 00000088
/* 008AC 809E0AEC 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 008B0 809E0AF0 00000000 */  nop
/* 008B4 809E0AF4 3C01809E */  lui     $at, %hi(D_809E1700)       ## $at = 809E0000
/* 008B8 809E0AF8 C4321700 */  lwc1    $f18, %lo(D_809E1700)($at) 
/* 008BC 809E0AFC 4612003C */  c.lt.s  $f0, $f18                  
/* 008C0 809E0B00 00000000 */  nop
/* 008C4 809E0B04 45020033 */  bc1fl   .L809E0BD4                 
/* 008C8 809E0B08 960C0088 */  lhu     $t4, 0x0088($s0)           ## 00000088
/* 008CC 809E0B0C C604000C */  lwc1    $f4, 0x000C($s0)           ## 0000000C
/* 008D0 809E0B10 C6060028 */  lwc1    $f6, 0x0028($s0)           ## 00000028
/* 008D4 809E0B14 4606203C */  c.lt.s  $f4, $f6                   
/* 008D8 809E0B18 00000000 */  nop
/* 008DC 809E0B1C 45000010 */  bc1f    .L809E0B60                 
/* 008E0 809E0B20 00000000 */  nop
/* 008E4 809E0B24 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 008E8 809E0B28 00000000 */  nop
/* 008EC 809E0B2C 3C014480 */  lui     $at, 0x4480                ## $at = 44800000
/* 008F0 809E0B30 44811000 */  mtc1    $at, $f2                   ## $f2 = 1024.00
/* 008F4 809E0B34 860F01C6 */  lh      $t7, 0x01C6($s0)           ## 000001C6
/* 008F8 809E0B38 46001402 */  mul.s   $f16, $f2, $f0             
/* 008FC 809E0B3C 448F4000 */  mtc1    $t7, $f8                   ## $f8 = 0.00
/* 00900 809E0B40 00000000 */  nop
/* 00904 809E0B44 468042A0 */  cvt.s.w $f10, $f8                  
/* 00908 809E0B48 46028480 */  add.s   $f18, $f16, $f2            
/* 0090C 809E0B4C 46125101 */  sub.s   $f4, $f10, $f18            
/* 00910 809E0B50 4600218D */  trunc.w.s $f6, $f4                   
/* 00914 809E0B54 44193000 */  mfc1    $t9, $f6                   
/* 00918 809E0B58 10000010 */  beq     $zero, $zero, .L809E0B9C   
/* 0091C 809E0B5C A61901C6 */  sh      $t9, 0x01C6($s0)           ## 000001C6
.L809E0B60:
/* 00920 809E0B60 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00924 809E0B64 00000000 */  nop
/* 00928 809E0B68 3C014480 */  lui     $at, 0x4480                ## $at = 44800000
/* 0092C 809E0B6C 44811000 */  mtc1    $at, $f2                   ## $f2 = 1024.00
/* 00930 809E0B70 860801C6 */  lh      $t0, 0x01C6($s0)           ## 000001C6
/* 00934 809E0B74 46001282 */  mul.s   $f10, $f2, $f0             
/* 00938 809E0B78 44884000 */  mtc1    $t0, $f8                   ## $f8 = 0.00
/* 0093C 809E0B7C 00000000 */  nop
/* 00940 809E0B80 46804420 */  cvt.s.w $f16, $f8                  
/* 00944 809E0B84 46025480 */  add.s   $f18, $f10, $f2            
/* 00948 809E0B88 46128100 */  add.s   $f4, $f16, $f18            
/* 0094C 809E0B8C 4600218D */  trunc.w.s $f6, $f4                   
/* 00950 809E0B90 440A3000 */  mfc1    $t2, $f6                   
/* 00954 809E0B94 00000000 */  nop
/* 00958 809E0B98 A60A01C6 */  sh      $t2, 0x01C6($s0)           ## 000001C6
.L809E0B9C:
/* 0095C 809E0B9C 860201C6 */  lh      $v0, 0x01C6($s0)           ## 000001C6
/* 00960 809E0BA0 240BF000 */  addiu   $t3, $zero, 0xF000         ## $t3 = FFFFF000
/* 00964 809E0BA4 2841F000 */  slti    $at, $v0, 0xF000           
/* 00968 809E0BA8 50200004 */  beql    $at, $zero, .L809E0BBC     
/* 0096C 809E0BAC 28411001 */  slti    $at, $v0, 0x1001           
/* 00970 809E0BB0 10000007 */  beq     $zero, $zero, .L809E0BD0   
/* 00974 809E0BB4 A60B01C6 */  sh      $t3, 0x01C6($s0)           ## 000001C6
/* 00978 809E0BB8 28411001 */  slti    $at, $v0, 0x1001           
.L809E0BBC:
/* 0097C 809E0BBC 14200003 */  bne     $at, $zero, .L809E0BCC     
/* 00980 809E0BC0 00401825 */  or      $v1, $v0, $zero            ## $v1 = 00000000
/* 00984 809E0BC4 10000001 */  beq     $zero, $zero, .L809E0BCC   
/* 00988 809E0BC8 24031000 */  addiu   $v1, $zero, 0x1000         ## $v1 = 00001000
.L809E0BCC:
/* 0098C 809E0BCC A60301C6 */  sh      $v1, 0x01C6($s0)           ## 000001C6
.L809E0BD0:
/* 00990 809E0BD0 960C0088 */  lhu     $t4, 0x0088($s0)           ## 00000088
.L809E0BD4:
/* 00994 809E0BD4 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 00998 809E0BD8 2405FF00 */  addiu   $a1, $zero, 0xFF00         ## $a1 = FFFFFF00
/* 0099C 809E0BDC 318D0001 */  andi    $t5, $t4, 0x0001           ## $t5 = 00000000
/* 009A0 809E0BE0 51A00004 */  beql    $t5, $zero, .L809E0BF4     
/* 009A4 809E0BE4 860201C4 */  lh      $v0, 0x01C4($s0)           ## 000001C4
/* 009A8 809E0BE8 0C01DE2B */  jal     Math_ApproxUpdateScaledS
              
/* 009AC 809E0BEC 24060400 */  addiu   $a2, $zero, 0x0400         ## $a2 = 00000400
/* 009B0 809E0BF0 860201C4 */  lh      $v0, 0x01C4($s0)           ## 000001C4
.L809E0BF4:
/* 009B4 809E0BF4 3C014396 */  lui     $at, 0x4396                ## $at = 43960000
/* 009B8 809E0BF8 10400003 */  beq     $v0, $zero, .L809E0C08     
/* 009BC 809E0BFC 244EFFFF */  addiu   $t6, $v0, 0xFFFF           ## $t6 = FFFFFFFF
/* 009C0 809E0C00 A60E01C4 */  sh      $t6, 0x01C4($s0)           ## 000001C4
/* 009C4 809E0C04 860201C4 */  lh      $v0, 0x01C4($s0)           ## 000001C4
.L809E0C08:
/* 009C8 809E0C08 5440001C */  bnel    $v0, $zero, .L809E0C7C     
/* 009CC 809E0C0C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 009D0 809E0C10 C6080090 */  lwc1    $f8, 0x0090($s0)           ## 00000090
/* 009D4 809E0C14 44815000 */  mtc1    $at, $f10                  ## $f10 = 300.00
/* 009D8 809E0C18 8FAF003C */  lw      $t7, 0x003C($sp)           
/* 009DC 809E0C1C 460A403C */  c.lt.s  $f8, $f10                  
/* 009E0 809E0C20 00000000 */  nop
/* 009E4 809E0C24 45020015 */  bc1fl   .L809E0C7C                 
/* 009E8 809E0C28 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 009EC 809E0C2C 8DF8067C */  lw      $t8, 0x067C($t7)           ## 0000067C
/* 009F0 809E0C30 3C01C220 */  lui     $at, 0xC220                ## $at = C2200000
/* 009F4 809E0C34 0018CA00 */  sll     $t9, $t8,  8               
/* 009F8 809E0C38 07220010 */  bltzl   $t9, .L809E0C7C            
/* 009FC 809E0C3C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00A00 809E0C40 C6100084 */  lwc1    $f16, 0x0084($s0)          ## 00000084
/* 00A04 809E0C44 44819000 */  mtc1    $at, $f18                  ## $f18 = -40.00
/* 00A08 809E0C48 00000000 */  nop
/* 00A0C 809E0C4C 4612803C */  c.lt.s  $f16, $f18                 
/* 00A10 809E0C50 00000000 */  nop
/* 00A14 809E0C54 45020009 */  bc1fl   .L809E0C7C                 
/* 00A18 809E0C58 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00A1C 809E0C5C 0C023C20 */  jal     func_8008F080              
/* 00A20 809E0C60 8FA40044 */  lw      $a0, 0x0044($sp)           
/* 00A24 809E0C64 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 00A28 809E0C68 50410004 */  beql    $v0, $at, .L809E0C7C       
/* 00A2C 809E0C6C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00A30 809E0C70 0C2780E1 */  jal     func_809E0384              
/* 00A34 809E0C74 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00A38 809E0C78 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L809E0C7C:
/* 00A3C 809E0C7C 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00A40 809E0C80 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 00A44 809E0C84 03E00008 */  jr      $ra                        
/* 00A48 809E0C88 00000000 */  nop
