.rdata
glabel D_808995B0
    .asciz "Error 攻撃方法が分からない(%s %d)\n"
    .balign 4

glabel D_808995D4
    .asciz "../z_bg_jya_ironobj.c"
    .balign 4

glabel D_808995EC
    .asciz "¢ attack_type(%d)\n"
    .balign 4

.late_rodata
glabel D_80899610
    .float 0.1

glabel D_80899614
    .float 0.8

glabel D_80899618
 .word 0x3D042108
glabel D_8089961C
 .word 0x3E851EB8

.text
glabel func_80898DB4
/* 00514 80898DB4 27BDFF10 */  addiu   $sp, $sp, 0xFF10           ## $sp = FFFFFF10
/* 00518 80898DB8 AFBF0094 */  sw      $ra, 0x0094($sp)           
/* 0051C 80898DBC AFB60090 */  sw      $s6, 0x0090($sp)           
/* 00520 80898DC0 AFB5008C */  sw      $s5, 0x008C($sp)           
/* 00524 80898DC4 AFB40088 */  sw      $s4, 0x0088($sp)           
/* 00528 80898DC8 AFB30084 */  sw      $s3, 0x0084($sp)           
/* 0052C 80898DCC AFB20080 */  sw      $s2, 0x0080($sp)           
/* 00530 80898DD0 AFB1007C */  sw      $s1, 0x007C($sp)           
/* 00534 80898DD4 AFB00078 */  sw      $s0, 0x0078($sp)           
/* 00538 80898DD8 F7BE0070 */  sdc1    $f30, 0x0070($sp)          
/* 0053C 80898DDC F7BC0068 */  sdc1    $f28, 0x0068($sp)          
/* 00540 80898DE0 F7BA0060 */  sdc1    $f26, 0x0060($sp)          
/* 00544 80898DE4 F7B80058 */  sdc1    $f24, 0x0058($sp)          
/* 00548 80898DE8 F7B60050 */  sdc1    $f22, 0x0050($sp)          
/* 0054C 80898DEC F7B40048 */  sdc1    $f20, 0x0048($sp)          
/* 00550 80898DF0 80C702FF */  lb      $a3, 0x02FF($a2)           ## 000002FF
/* 00554 80898DF4 00C08025 */  or      $s0, $a2, $zero            ## $s0 = 00000000
/* 00558 80898DF8 00809825 */  or      $s3, $a0, $zero            ## $s3 = 00000000
/* 0055C 80898DFC 18E00004 */  blez    $a3, .L80898E10            
/* 00560 80898E00 00A0B025 */  or      $s6, $a1, $zero            ## $s6 = 00000000
/* 00564 80898E04 28E10004 */  slti    $at, $a3, 0x0004           
/* 00568 80898E08 14200009 */  bne     $at, $zero, .L80898E30     
/* 0056C 80898E0C 3C04808A */  lui     $a0, %hi(D_808995EC)       ## $a0 = 808A0000
.L80898E10:
/* 00570 80898E10 3C04808A */  lui     $a0, %hi(D_808995B0)       ## $a0 = 808A0000
/* 00574 80898E14 3C05808A */  lui     $a1, %hi(D_808995D4)       ## $a1 = 808A0000
/* 00578 80898E18 24A595D4 */  addiu   $a1, $a1, %lo(D_808995D4)  ## $a1 = 808995D4
/* 0057C 80898E1C 248495B0 */  addiu   $a0, $a0, %lo(D_808995B0)  ## $a0 = 808995B0
/* 00580 80898E20 0C00084C */  jal     osSyncPrintf
              
/* 00584 80898E24 2406016A */  addiu   $a2, $zero, 0x016A         ## $a2 = 0000016A
/* 00588 80898E28 100000E6 */  beq     $zero, $zero, .L808991C4   
/* 0058C 80898E2C 8FBF0094 */  lw      $ra, 0x0094($sp)           
.L80898E30:
/* 00590 80898E30 248495EC */  addiu   $a0, $a0, %lo(D_808995EC)  ## $a0 = FFFF95EC
/* 00594 80898E34 0C00084C */  jal     osSyncPrintf
              
/* 00598 80898E38 00E02825 */  or      $a1, $a3, $zero            ## $a1 = 00000000
/* 0059C 80898E3C 02602025 */  or      $a0, $s3, $zero            ## $a0 = 00000000
/* 005A0 80898E40 0C00B69E */  jal     func_8002DA78              
/* 005A4 80898E44 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 005A8 80898E48 820E02FF */  lb      $t6, 0x02FF($s0)           ## 000002FF
/* 005AC 80898E4C 3C0140C0 */  lui     $at, 0x40C0                ## $at = 40C00000
/* 005B0 80898E50 3C18808A */  lui     $t8, %hi(D_808994D6)       ## $t8 = 808A0000
/* 005B4 80898E54 4481E000 */  mtc1    $at, $f28                  ## $f28 = 6.00
/* 005B8 80898E58 000E7840 */  sll     $t7, $t6,  1               
/* 005BC 80898E5C 030FC021 */  addu    $t8, $t8, $t7              
/* 005C0 80898E60 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 005C4 80898E64 871894D6 */  lh      $t8, %lo(D_808994D6)($t8)  
/* 005C8 80898E68 4481D000 */  mtc1    $at, $f26                  ## $f26 = 8.00
/* 005CC 80898E6C 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 005D0 80898E70 4481C000 */  mtc1    $at, $f24                  ## $f24 = 80.00
/* 005D4 80898E74 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 005D8 80898E78 0302A821 */  addu    $s5, $t8, $v0              
/* 005DC 80898E7C 0015AC00 */  sll     $s5, $s5, 16               
/* 005E0 80898E80 4481B000 */  mtc1    $at, $f22                  ## $f22 = 10.00
/* 005E4 80898E84 0015AC03 */  sra     $s5, $s5, 16               
/* 005E8 80898E88 00008825 */  or      $s1, $zero, $zero          ## $s1 = 00000000
/* 005EC 80898E8C 26D21C24 */  addiu   $s2, $s6, 0x1C24           ## $s2 = 00001C24
/* 005F0 80898E90 24140008 */  addiu   $s4, $zero, 0x0008         ## $s4 = 00000008
.L80898E94:
/* 005F4 80898E94 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 005F8 80898E98 00000000 */  nop
/* 005FC 80898E9C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00600 80898EA0 46000506 */  mov.s   $f20, $f0                  
/* 00604 80898EA4 4618A102 */  mul.s   $f4, $f20, $f24            
/* 00608 80898EA8 C6660028 */  lwc1    $f6, 0x0028($s3)           ## 00000028
/* 0060C 80898EAC 3C014680 */  lui     $at, 0x4680                ## $at = 46800000
/* 00610 80898EB0 44819000 */  mtc1    $at, $f18                  ## $f18 = 16384.00
/* 00614 80898EB4 8E670024 */  lw      $a3, 0x0024($s3)           ## 00000024
/* 00618 80898EB8 02402025 */  or      $a0, $s2, $zero            ## $a0 = 00001C24
/* 0061C 80898EBC 02C02825 */  or      $a1, $s6, $zero            ## $a1 = 00000000
/* 00620 80898EC0 46062200 */  add.s   $f8, $f4, $f6              
/* 00624 80898EC4 46120102 */  mul.s   $f4, $f0, $f18             
/* 00628 80898EC8 2406018F */  addiu   $a2, $zero, 0x018F         ## $a2 = 0000018F
/* 0062C 80898ECC 46164280 */  add.s   $f10, $f8, $f22            
/* 00630 80898ED0 4600218D */  trunc.w.s $f6, $f4                   
/* 00634 80898ED4 E7AA0010 */  swc1    $f10, 0x0010($sp)          
/* 00638 80898ED8 C670002C */  lwc1    $f16, 0x002C($s3)          ## 0000002C
/* 0063C 80898EDC AFA00024 */  sw      $zero, 0x0024($sp)         
/* 00640 80898EE0 44083000 */  mfc1    $t0, $f6                   
/* 00644 80898EE4 AFA00020 */  sw      $zero, 0x0020($sp)         
/* 00648 80898EE8 AFA00018 */  sw      $zero, 0x0018($sp)         
/* 0064C 80898EEC 00084C00 */  sll     $t1, $t0, 16               
/* 00650 80898EF0 00095403 */  sra     $t2, $t1, 16               
/* 00654 80898EF4 01555821 */  addu    $t3, $t2, $s5              
/* 00658 80898EF8 256CE000 */  addiu   $t4, $t3, 0xE000           ## $t4 = FFFFE000
/* 0065C 80898EFC AFAC001C */  sw      $t4, 0x001C($sp)           
/* 00660 80898F00 0C00C7D4 */  jal     Actor_Spawn
              ## ActorSpawn
/* 00664 80898F04 E7B00014 */  swc1    $f16, 0x0014($sp)          
/* 00668 80898F08 1040000D */  beq     $v0, $zero, .L80898F40     
/* 0066C 80898F0C 00408025 */  or      $s0, $v0, $zero            ## $s0 = 00000000
/* 00670 80898F10 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00674 80898F14 00000000 */  nop
/* 00678 80898F18 461A0202 */  mul.s   $f8, $f0, $f26             
/* 0067C 80898F1C 3C014110 */  lui     $at, 0x4110                ## $at = 41100000
/* 00680 80898F20 44815000 */  mtc1    $at, $f10                  ## $f10 = 9.00
/* 00684 80898F24 00000000 */  nop
/* 00688 80898F28 460A4400 */  add.s   $f16, $f8, $f10            
/* 0068C 80898F2C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00690 80898F30 E6100068 */  swc1    $f16, 0x0068($s0)          ## 00000068
/* 00694 80898F34 46160482 */  mul.s   $f18, $f0, $f22            
/* 00698 80898F38 461C9100 */  add.s   $f4, $f18, $f28            
/* 0069C 80898F3C E6040060 */  swc1    $f4, 0x0060($s0)           ## 00000060
.L80898F40:
/* 006A0 80898F40 26310001 */  addiu   $s1, $s1, 0x0001           ## $s1 = 00000001
/* 006A4 80898F44 1634FFD3 */  bne     $s1, $s4, .L80898E94       
/* 006A8 80898F48 00000000 */  nop
/* 006AC 80898F4C 00152400 */  sll     $a0, $s5, 16               
/* 006B0 80898F50 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 006B4 80898F54 00042403 */  sra     $a0, $a0, 16               
/* 006B8 80898F58 00152400 */  sll     $a0, $s5, 16               
/* 006BC 80898F5C E7A000BC */  swc1    $f0, 0x00BC($sp)           
/* 006C0 80898F60 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 006C4 80898F64 00042403 */  sra     $a0, $a0, 16               
/* 006C8 80898F68 3C014220 */  lui     $at, 0x4220                ## $at = 42200000
/* 006CC 80898F6C 4481F000 */  mtc1    $at, $f30                  ## $f30 = 40.00
/* 006D0 80898F70 3C014040 */  lui     $at, 0x4040                ## $at = 40400000
/* 006D4 80898F74 4481C000 */  mtc1    $at, $f24                  ## $f24 = 3.00
/* 006D8 80898F78 E7A000C4 */  swc1    $f0, 0x00C4($sp)           
/* 006DC 80898F7C 00009025 */  or      $s2, $zero, $zero          ## $s2 = 00000000
/* 006E0 80898F80 27B500C8 */  addiu   $s5, $sp, 0x00C8           ## $s5 = FFFFFFD8
/* 006E4 80898F84 27B400D4 */  addiu   $s4, $sp, 0x00D4           ## $s4 = FFFFFFE4
.L80898F88:
/* 006E8 80898F88 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 006EC 80898F8C 00000000 */  nop
/* 006F0 80898F90 3C01808A */  lui     $at, %hi(D_80899610)       ## $at = 808A0000
/* 006F4 80898F94 C4269610 */  lwc1    $f6, %lo(D_80899610)($at)  
/* 006F8 80898F98 3C01808A */  lui     $at, %hi(D_80899614)       ## $at = 808A0000
/* 006FC 80898F9C 4606003C */  c.lt.s  $f0, $f6                   
/* 00700 80898FA0 00000000 */  nop
/* 00704 80898FA4 45000003 */  bc1f    .L80898FB4                 
/* 00708 80898FA8 00000000 */  nop
/* 0070C 80898FAC 10000009 */  beq     $zero, $zero, .L80898FD4   
/* 00710 80898FB0 24110060 */  addiu   $s1, $zero, 0x0060         ## $s1 = 00000060
.L80898FB4:
/* 00714 80898FB4 C4289614 */  lwc1    $f8, %lo(D_80899614)($at)  
/* 00718 80898FB8 24110020 */  addiu   $s1, $zero, 0x0020         ## $s1 = 00000020
/* 0071C 80898FBC 4608003C */  c.lt.s  $f0, $f8                   
/* 00720 80898FC0 00000000 */  nop
/* 00724 80898FC4 45000003 */  bc1f    .L80898FD4                 
/* 00728 80898FC8 00000000 */  nop
/* 0072C 80898FCC 10000001 */  beq     $zero, $zero, .L80898FD4   
/* 00730 80898FD0 24110040 */  addiu   $s1, $zero, 0x0040         ## $s1 = 00000040
.L80898FD4:
/* 00734 80898FD4 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00738 80898FD8 00000000 */  nop
/* 0073C 80898FDC 461E0282 */  mul.s   $f10, $f0, $f30            
/* 00740 80898FE0 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 00744 80898FE4 44818000 */  mtc1    $at, $f16                  ## $f16 = 20.00
/* 00748 80898FE8 44924000 */  mtc1    $s2, $f8                   ## $f8 = 0.00
/* 0074C 80898FEC C6640024 */  lwc1    $f4, 0x0024($s3)           ## 00000024
/* 00750 80898FF0 3C014070 */  lui     $at, 0x4070                ## $at = 40700000
/* 00754 80898FF4 46804520 */  cvt.s.w $f20, $f8                  
/* 00758 80898FF8 46105481 */  sub.s   $f18, $f10, $f16           
/* 0075C 80898FFC 44818000 */  mtc1    $at, $f16                  ## $f16 = 3.75
/* 00760 80899000 46049180 */  add.s   $f6, $f18, $f4             
/* 00764 80899004 46148482 */  mul.s   $f18, $f16, $f20           
/* 00768 80899008 E7A600D4 */  swc1    $f6, 0x00D4($sp)           
/* 0076C 8089900C C66A0028 */  lwc1    $f10, 0x0028($s3)          ## 00000028
/* 00770 80899010 46125100 */  add.s   $f4, $f10, $f18            
/* 00774 80899014 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00778 80899018 E7A400D8 */  swc1    $f4, 0x00D8($sp)           
/* 0077C 8089901C 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 00780 80899020 461E0182 */  mul.s   $f6, $f0, $f30             
/* 00784 80899024 44814000 */  mtc1    $at, $f8                   ## $f8 = 20.00
/* 00788 80899028 3C014178 */  lui     $at, 0x4178                ## $at = 41780000
/* 0078C 8089902C 44812000 */  mtc1    $at, $f4                   ## $f4 = 15.50
/* 00790 80899030 3C01808A */  lui     $at, %hi(D_80899618)       ## $at = 808A0000
/* 00794 80899034 C66A002C */  lwc1    $f10, 0x002C($s3)          ## 0000002C
/* 00798 80899038 4604A001 */  sub.s   $f0, $f20, $f4             
/* 0079C 8089903C 46083401 */  sub.s   $f16, $f6, $f8             
/* 007A0 80899040 C4269618 */  lwc1    $f6, %lo(D_80899618)($at)  
/* 007A4 80899044 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 007A8 80899048 46000005 */  abs.s   $f0, $f0                   
/* 007AC 8089904C 460A8480 */  add.s   $f18, $f16, $f10           
/* 007B0 80899050 46060202 */  mul.s   $f8, $f0, $f6              
/* 007B4 80899054 44818000 */  mtc1    $at, $f16                  ## $f16 = 0.50
/* 007B8 80899058 E7B200DC */  swc1    $f18, 0x00DC($sp)          
/* 007BC 8089905C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 007C0 80899060 46104580 */  add.s   $f22, $f8, $f16            
/* 007C4 80899064 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 007C8 80899068 46000506 */  mov.s   $f20, $f0                  
/* 007CC 8089906C 461CA282 */  mul.s   $f10, $f20, $f28           
/* 007D0 80899070 C7B200BC */  lwc1    $f18, 0x00BC($sp)          
/* 007D4 80899074 46120102 */  mul.s   $f4, $f0, $f18             
/* 007D8 80899078 46185081 */  sub.s   $f2, $f10, $f24            
/* 007DC 8089907C 461A2182 */  mul.s   $f6, $f4, $f26             
/* 007E0 80899080 46021400 */  add.s   $f16, $f2, $f2             
/* 007E4 80899084 46163202 */  mul.s   $f8, $f6, $f22             
/* 007E8 80899088 46104280 */  add.s   $f10, $f8, $f16            
/* 007EC 8089908C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 007F0 80899090 E7AA00C8 */  swc1    $f10, 0x00C8($sp)          
/* 007F4 80899094 461A0482 */  mul.s   $f18, $f0, $f26            
/* 007F8 80899098 46189101 */  sub.s   $f4, $f18, $f24            
/* 007FC 8089909C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00800 808990A0 E7A400CC */  swc1    $f4, 0x00CC($sp)           
/* 00804 808990A4 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00808 808990A8 46000506 */  mov.s   $f20, $f0                  
/* 0080C 808990AC 461CA182 */  mul.s   $f6, $f20, $f28            
/* 00810 808990B0 C7A800C4 */  lwc1    $f8, 0x00C4($sp)           
/* 00814 808990B4 32420007 */  andi    $v0, $s2, 0x0007           ## $v0 = 00000000
/* 00818 808990B8 00021040 */  sll     $v0, $v0,  1               
/* 0081C 808990BC 46080402 */  mul.s   $f16, $f0, $f8             
/* 00820 808990C0 3C18808A */  lui     $t8, %hi(D_80899510)       ## $t8 = 808A0000
/* 00824 808990C4 27189510 */  addiu   $t8, $t8, %lo(D_80899510)  ## $t8 = 80899510
/* 00828 808990C8 3C0E808A */  lui     $t6, %hi(D_80899530)       ## $t6 = 808A0000
/* 0082C 808990CC 3C09808A */  lui     $t1, %hi(D_80899520)       ## $t1 = 808A0000
/* 00830 808990D0 46183081 */  sub.s   $f2, $f6, $f24             
/* 00834 808990D4 01224821 */  addu    $t1, $t1, $v0              
/* 00838 808990D8 461A8282 */  mul.s   $f10, $f16, $f26           
/* 0083C 808990DC 01C27021 */  addu    $t6, $t6, $v0              
/* 00840 808990E0 46021100 */  add.s   $f4, $f2, $f2              
/* 00844 808990E4 00588021 */  addu    $s0, $v0, $t8              
/* 00848 808990E8 86190000 */  lh      $t9, 0x0000($s0)           ## 00000000
/* 0084C 808990EC 85CE9530 */  lh      $t6, %lo(D_80899530)($t6)  
/* 00850 808990F0 85299520 */  lh      $t1, %lo(D_80899520)($t1)  
/* 00854 808990F4 46165482 */  mul.s   $f18, $f10, $f22           
/* 00858 808990F8 3C0C0600 */  lui     $t4, 0x0600                ## $t4 = 06000000
/* 0085C 808990FC 258C0880 */  addiu   $t4, $t4, 0x0880           ## $t4 = 06000880
/* 00860 80899100 240DFEA2 */  addiu   $t5, $zero, 0xFEA2         ## $t5 = FFFFFEA2
/* 00864 80899104 240F0004 */  addiu   $t7, $zero, 0x0004         ## $t7 = 00000004
/* 00868 80899108 24080005 */  addiu   $t0, $zero, 0x0005         ## $t0 = 00000005
/* 0086C 8089910C 240AFFFF */  addiu   $t2, $zero, 0xFFFF         ## $t2 = FFFFFFFF
/* 00870 80899110 46049180 */  add.s   $f6, $f18, $f4             
/* 00874 80899114 240B016C */  addiu   $t3, $zero, 0x016C         ## $t3 = 0000016C
/* 00878 80899118 AFAB0038 */  sw      $t3, 0x0038($sp)           
/* 0087C 8089911C AFAA0034 */  sw      $t2, 0x0034($sp)           
/* 00880 80899120 E7A600D0 */  swc1    $f6, 0x00D0($sp)           
/* 00884 80899124 AFA8002C */  sw      $t0, 0x002C($sp)           
/* 00888 80899128 AFAF001C */  sw      $t7, 0x001C($sp)           
/* 0088C 8089912C AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 00890 80899130 AFAC003C */  sw      $t4, 0x003C($sp)           
/* 00894 80899134 02C02025 */  or      $a0, $s6, $zero            ## $a0 = 00000000
/* 00898 80899138 02802825 */  or      $a1, $s4, $zero            ## $a1 = FFFFFFE4
/* 0089C 8089913C 02A03025 */  or      $a2, $s5, $zero            ## $a2 = FFFFFFD8
/* 008A0 80899140 02803825 */  or      $a3, $s4, $zero            ## $a3 = FFFFFFE4
/* 008A4 80899144 AFB10014 */  sw      $s1, 0x0014($sp)           
/* 008A8 80899148 AFA00020 */  sw      $zero, 0x0020($sp)         
/* 008AC 8089914C AFA00028 */  sw      $zero, 0x0028($sp)         
/* 008B0 80899150 AFB90024 */  sw      $t9, 0x0024($sp)           
/* 008B4 80899154 AFAE0018 */  sw      $t6, 0x0018($sp)           
/* 008B8 80899158 0C00A7A3 */  jal     func_80029E8C
              
/* 008BC 8089915C AFA90030 */  sw      $t1, 0x0030($sp)           
/* 008C0 80899160 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 008C4 80899164 00000000 */  nop
/* 008C8 80899168 3C01808A */  lui     $at, %hi(D_8089961C)       ## $at = 808A0000
/* 008CC 8089916C C428961C */  lwc1    $f8, %lo(D_8089961C)($at)  
/* 008D0 80899170 02C02025 */  or      $a0, $s6, $zero            ## $a0 = 00000000
/* 008D4 80899174 02802825 */  or      $a1, $s4, $zero            ## $a1 = FFFFFFE4
/* 008D8 80899178 4608003C */  c.lt.s  $f0, $f8                   
/* 008DC 8089917C 3C064348 */  lui     $a2, 0x4348                ## $a2 = 43480000
/* 008E0 80899180 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 008E4 80899184 4502000B */  bc1fl   .L808991B4                 
/* 008E8 80899188 26520001 */  addiu   $s2, $s2, 0x0001           ## $s2 = 00000001
/* 008EC 8089918C 86020000 */  lh      $v0, 0x0000($s0)           ## 00000000
/* 008F0 80899190 240F0001 */  addiu   $t7, $zero, 0x0001         ## $t7 = 00000001
/* 008F4 80899194 AFAF0018 */  sw      $t7, 0x0018($sp)           
/* 008F8 80899198 00021080 */  sll     $v0, $v0,  2               
/* 008FC 8089919C 244D003C */  addiu   $t5, $v0, 0x003C           ## $t5 = 0000003C
/* 00900 808991A0 244E0050 */  addiu   $t6, $v0, 0x0050           ## $t6 = 00000050
/* 00904 808991A4 AFAE0014 */  sw      $t6, 0x0014($sp)           
/* 00908 808991A8 0C00CD20 */  jal     func_80033480              
/* 0090C 808991AC AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 00910 808991B0 26520001 */  addiu   $s2, $s2, 0x0001           ## $s2 = 00000002
.L808991B4:
/* 00914 808991B4 24010020 */  addiu   $at, $zero, 0x0020         ## $at = 00000020
/* 00918 808991B8 1641FF73 */  bne     $s2, $at, .L80898F88       
/* 0091C 808991BC 00000000 */  nop
/* 00920 808991C0 8FBF0094 */  lw      $ra, 0x0094($sp)           
.L808991C4:
/* 00924 808991C4 D7B40048 */  ldc1    $f20, 0x0048($sp)          
/* 00928 808991C8 D7B60050 */  ldc1    $f22, 0x0050($sp)          
/* 0092C 808991CC D7B80058 */  ldc1    $f24, 0x0058($sp)          
/* 00930 808991D0 D7BA0060 */  ldc1    $f26, 0x0060($sp)          
/* 00934 808991D4 D7BC0068 */  ldc1    $f28, 0x0068($sp)          
/* 00938 808991D8 D7BE0070 */  ldc1    $f30, 0x0070($sp)          
/* 0093C 808991DC 8FB00078 */  lw      $s0, 0x0078($sp)           
/* 00940 808991E0 8FB1007C */  lw      $s1, 0x007C($sp)           
/* 00944 808991E4 8FB20080 */  lw      $s2, 0x0080($sp)           
/* 00948 808991E8 8FB30084 */  lw      $s3, 0x0084($sp)           
/* 0094C 808991EC 8FB40088 */  lw      $s4, 0x0088($sp)           
/* 00950 808991F0 8FB5008C */  lw      $s5, 0x008C($sp)           
/* 00954 808991F4 8FB60090 */  lw      $s6, 0x0090($sp)           
/* 00958 808991F8 03E00008 */  jr      $ra                        
/* 0095C 808991FC 27BD00F0 */  addiu   $sp, $sp, 0x00F0           ## $sp = 00000000
