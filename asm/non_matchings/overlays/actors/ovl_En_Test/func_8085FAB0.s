.late_rodata

glabel jtbl_8086474C
.word L8085FBBC
.word L8085FBCC
.word L8085FBE0
.word L8085FBBC
.word L8085FBE0
.word L8085FBCC
.word L8085FBCC
.word L8085FBBC
.word L8085FBCC
.word L8085FBE0

glabel D_80864774
 .float 0.2

.text
glabel func_8085FAB0
/* 00460 8085FAB0 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 00464 8085FAB4 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00468 8085FAB8 8CA81C44 */  lw      $t0, 0x1C44($a1)           ## 00001C44
/* 0046C 8085FABC 848300B6 */  lh      $v1, 0x00B6($a0)           ## 000000B6
/* 00470 8085FAC0 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00474 8085FAC4 850E00B6 */  lh      $t6, 0x00B6($t0)           ## 000000B6
/* 00478 8085FAC8 00A03825 */  or      $a3, $a1, $zero            ## $a3 = 00000000
/* 0047C 8085FACC 01C31023 */  subu    $v0, $t6, $v1              
/* 00480 8085FAD0 00021400 */  sll     $v0, $v0, 16               
/* 00484 8085FAD4 00021403 */  sra     $v0, $v0, 16               
/* 00488 8085FAD8 04430005 */  bgezl   $v0, .L8085FAF0            
/* 0048C 8085FADC 284161A8 */  slti    $at, $v0, 0x61A8           
/* 00490 8085FAE0 00021023 */  subu    $v0, $zero, $v0            
/* 00494 8085FAE4 00021400 */  sll     $v0, $v0, 16               
/* 00498 8085FAE8 00021403 */  sra     $v0, $v0, 16               
/* 0049C 8085FAEC 284161A8 */  slti    $at, $v0, 0x61A8           
.L8085FAF0:
/* 004A0 8085FAF0 54200046 */  bnel    $at, $zero, .L8085FC0C     
/* 004A4 8085FAF4 28413E81 */  slti    $at, $v0, 0x3E81           
/* 004A8 8085FAF8 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 004AC 8085FAFC 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 004B0 8085FB00 AFA70024 */  sw      $a3, 0x0024($sp)           
/* 004B4 8085FB04 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 004B8 8085FB08 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 004BC 8085FB0C 24180001 */  addiu   $t8, $zero, 0x0001         ## $t8 = 00000001
/* 004C0 8085FB10 3C014F00 */  lui     $at, 0x4F00                ## $at = 4F000000
/* 004C4 8085FB14 46040182 */  mul.s   $f6, $f0, $f4              
/* 004C8 8085FB18 8FA60020 */  lw      $a2, 0x0020($sp)           
/* 004CC 8085FB1C 8FA70024 */  lw      $a3, 0x0024($sp)           
/* 004D0 8085FB20 444FF800 */  cfc1    $t7, $f31                  
/* 004D4 8085FB24 44D8F800 */  ctc1    $t8, $f31                  
/* 004D8 8085FB28 00000000 */  nop
/* 004DC 8085FB2C 46003224 */  cvt.w.s $f8, $f6                   
/* 004E0 8085FB30 4458F800 */  cfc1    $t8, $f31                  
/* 004E4 8085FB34 00000000 */  nop
/* 004E8 8085FB38 33180078 */  andi    $t8, $t8, 0x0078           ## $t8 = 00000000
/* 004EC 8085FB3C 53000013 */  beql    $t8, $zero, .L8085FB8C     
/* 004F0 8085FB40 44184000 */  mfc1    $t8, $f8                   
/* 004F4 8085FB44 44814000 */  mtc1    $at, $f8                   ## $f8 = 2147483648.00
/* 004F8 8085FB48 24180001 */  addiu   $t8, $zero, 0x0001         ## $t8 = 00000001
/* 004FC 8085FB4C 46083201 */  sub.s   $f8, $f6, $f8              
/* 00500 8085FB50 44D8F800 */  ctc1    $t8, $f31                  
/* 00504 8085FB54 00000000 */  nop
/* 00508 8085FB58 46004224 */  cvt.w.s $f8, $f8                   
/* 0050C 8085FB5C 4458F800 */  cfc1    $t8, $f31                  
/* 00510 8085FB60 00000000 */  nop
/* 00514 8085FB64 33180078 */  andi    $t8, $t8, 0x0078           ## $t8 = 00000000
/* 00518 8085FB68 17000005 */  bne     $t8, $zero, .L8085FB80     
/* 0051C 8085FB6C 00000000 */  nop
/* 00520 8085FB70 44184000 */  mfc1    $t8, $f8                   
/* 00524 8085FB74 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 00528 8085FB78 10000007 */  beq     $zero, $zero, .L8085FB98   
/* 0052C 8085FB7C 0301C025 */  or      $t8, $t8, $at              ## $t8 = 80000000
.L8085FB80:
/* 00530 8085FB80 10000005 */  beq     $zero, $zero, .L8085FB98   
/* 00534 8085FB84 2418FFFF */  addiu   $t8, $zero, 0xFFFF         ## $t8 = FFFFFFFF
/* 00538 8085FB88 44184000 */  mfc1    $t8, $f8                   
.L8085FB8C:
/* 0053C 8085FB8C 00000000 */  nop
/* 00540 8085FB90 0700FFFB */  bltz    $t8, .L8085FB80            
/* 00544 8085FB94 00000000 */  nop
.L8085FB98:
/* 00548 8085FB98 44CFF800 */  ctc1    $t7, $f31                  
/* 0054C 8085FB9C 2F01000A */  sltiu   $at, $t8, 0x000A           
/* 00550 8085FBA0 10200087 */  beq     $at, $zero, .L8085FDC0     
/* 00554 8085FBA4 0018C080 */  sll     $t8, $t8,  2               
/* 00558 8085FBA8 3C018086 */  lui     $at, %hi(jtbl_8086474C)       ## $at = 80860000
/* 0055C 8085FBAC 00380821 */  addu    $at, $at, $t8              
/* 00560 8085FBB0 8C38474C */  lw      $t8, %lo(jtbl_8086474C)($at)  
/* 00564 8085FBB4 03000008 */  jr      $t8                        
/* 00568 8085FBB8 00000000 */  nop
glabel L8085FBBC
/* 0056C 8085FBBC 0C2187B0 */  jal     func_80861EC0              
/* 00570 8085FBC0 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00574 8085FBC4 1000007F */  beq     $zero, $zero, .L8085FDC4   
/* 00578 8085FBC8 8FBF0014 */  lw      $ra, 0x0014($sp)           
glabel L8085FBCC
/* 0057C 8085FBCC 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00580 8085FBD0 0C2189F1 */  jal     func_808627C4              
/* 00584 8085FBD4 00E02825 */  or      $a1, $a3, $zero            ## $a1 = 00000000
/* 00588 8085FBD8 1000007A */  beq     $zero, $zero, .L8085FDC4   
/* 0058C 8085FBDC 8FBF0014 */  lw      $ra, 0x0014($sp)           
glabel L8085FBE0
/* 00590 8085FBE0 84D9001C */  lh      $t9, 0x001C($a2)           ## 0000001C
/* 00594 8085FBE4 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 00598 8085FBE8 53210076 */  beql    $t9, $at, .L8085FDC4       
/* 0059C 8085FBEC 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 005A0 8085FBF0 84C9008A */  lh      $t1, 0x008A($a2)           ## 0000008A
/* 005A4 8085FBF4 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 005A8 8085FBF8 0C218653 */  jal     func_8086194C              
/* 005AC 8085FBFC A4C90032 */  sh      $t1, 0x0032($a2)           ## 00000032
/* 005B0 8085FC00 10000070 */  beq     $zero, $zero, .L8085FDC4   
/* 005B4 8085FC04 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 005B8 8085FC08 28413E81 */  slti    $at, $v0, 0x3E81           
.L8085FC0C:
/* 005BC 8085FC0C 1020006A */  beq     $at, $zero, .L8085FDB8     
/* 005C0 8085FC10 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 005C4 8085FC14 84C5008A */  lh      $a1, 0x008A($a2)           ## 0000008A
/* 005C8 8085FC18 3C0A0001 */  lui     $t2, 0x0001                ## $t2 = 00010000
/* 005CC 8085FC1C 01475021 */  addu    $t2, $t2, $a3              
/* 005D0 8085FC20 00A31023 */  subu    $v0, $a1, $v1              
/* 005D4 8085FC24 00021400 */  sll     $v0, $v0, 16               
/* 005D8 8085FC28 00021403 */  sra     $v0, $v0, 16               
/* 005DC 8085FC2C 04400003 */  bltz    $v0, .L8085FC3C            
/* 005E0 8085FC30 00021823 */  subu    $v1, $zero, $v0            
/* 005E4 8085FC34 10000001 */  beq     $zero, $zero, .L8085FC3C   
/* 005E8 8085FC38 00401825 */  or      $v1, $v0, $zero            ## $v1 = 00000000
.L8085FC3C:
/* 005EC 8085FC3C 28613E81 */  slti    $at, $v1, 0x3E81           
/* 005F0 8085FC40 54200032 */  bnel    $at, $zero, .L8085FD0C     
/* 005F4 8085FC44 3C0142DC */  lui     $at, 0x42DC                ## $at = 42DC0000
/* 005F8 8085FC48 8D4A1DE4 */  lw      $t2, 0x1DE4($t2)           ## 00011DE4
/* 005FC 8085FC4C 314B0001 */  andi    $t3, $t2, 0x0001           ## $t3 = 00000000
/* 00600 8085FC50 5160000B */  beql    $t3, $zero, .L8085FC80     
/* 00604 8085FC54 3C01435C */  lui     $at, 0x435C                ## $at = 435C0000
/* 00608 8085FC58 84CC001C */  lh      $t4, 0x001C($a2)           ## 0000001C
/* 0060C 8085FC5C 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 00610 8085FC60 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00614 8085FC64 51810006 */  beql    $t4, $at, .L8085FC80       
/* 00618 8085FC68 3C01435C */  lui     $at, 0x435C                ## $at = 435C0000
/* 0061C 8085FC6C 0C218653 */  jal     func_8086194C              
/* 00620 8085FC70 A4C50032 */  sh      $a1, 0x0032($a2)           ## 00000032
/* 00624 8085FC74 10000053 */  beq     $zero, $zero, .L8085FDC4   
/* 00628 8085FC78 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 0062C 8085FC7C 3C01435C */  lui     $at, 0x435C                ## $at = 435C0000
.L8085FC80:
/* 00630 8085FC80 44815000 */  mtc1    $at, $f10                  ## $f10 = 220.00
/* 00634 8085FC84 C4C00090 */  lwc1    $f0, 0x0090($a2)           ## 00000090
/* 00638 8085FC88 3C01432A */  lui     $at, 0x432A                ## $at = 432A0000
/* 0063C 8085FC8C 460A003C */  c.lt.s  $f0, $f10                  
/* 00640 8085FC90 00000000 */  nop
/* 00644 8085FC94 45000018 */  bc1f    .L8085FCF8                 
/* 00648 8085FC98 00000000 */  nop
/* 0064C 8085FC9C 44818000 */  mtc1    $at, $f16                  ## $f16 = 170.00
/* 00650 8085FCA0 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00654 8085FCA4 2405071C */  addiu   $a1, $zero, 0x071C         ## $a1 = 0000071C
/* 00658 8085FCA8 4600803C */  c.lt.s  $f16, $f0                  
/* 0065C 8085FCAC 00000000 */  nop
/* 00660 8085FCB0 45000011 */  bc1f    .L8085FCF8                 
/* 00664 8085FCB4 00000000 */  nop
/* 00668 8085FCB8 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 0066C 8085FCBC 0C00B821 */  jal     func_8002E084              
/* 00670 8085FCC0 AFA70024 */  sw      $a3, 0x0024($sp)           
/* 00674 8085FCC4 8FA60020 */  lw      $a2, 0x0020($sp)           
/* 00678 8085FCC8 1040003D */  beq     $v0, $zero, .L8085FDC0     
/* 0067C 8085FCCC 8FA70024 */  lw      $a3, 0x0024($sp)           
/* 00680 8085FCD0 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 00684 8085FCD4 00C02825 */  or      $a1, $a2, $zero            ## $a1 = 00000000
/* 00688 8085FCD8 0C00CEA1 */  jal     func_80033A84              
/* 0068C 8085FCDC AFA60020 */  sw      $a2, 0x0020($sp)           
/* 00690 8085FCE0 14400037 */  bne     $v0, $zero, .L8085FDC0     
/* 00694 8085FCE4 8FA60020 */  lw      $a2, 0x0020($sp)           
/* 00698 8085FCE8 0C2186E5 */  jal     func_80861B94              
/* 0069C 8085FCEC 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 006A0 8085FCF0 10000034 */  beq     $zero, $zero, .L8085FDC4   
/* 006A4 8085FCF4 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FCF8:
/* 006A8 8085FCF8 0C21810E */  jal     func_80860438              
/* 006AC 8085FCFC 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 006B0 8085FD00 10000030 */  beq     $zero, $zero, .L8085FDC4   
/* 006B4 8085FD04 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 006B8 8085FD08 3C0142DC */  lui     $at, 0x42DC                ## $at = 42DC0000
.L8085FD0C:
/* 006BC 8085FD0C 44812000 */  mtc1    $at, $f4                   ## $f4 = 110.00
/* 006C0 8085FD10 C4D20090 */  lwc1    $f18, 0x0090($a2)          ## 00000090
/* 006C4 8085FD14 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 006C8 8085FD18 4604903C */  c.lt.s  $f18, $f4                  
/* 006CC 8085FD1C 00000000 */  nop
/* 006D0 8085FD20 45000021 */  bc1f    .L8085FDA8                 
/* 006D4 8085FD24 00000000 */  nop
/* 006D8 8085FD28 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 006DC 8085FD2C AFA70024 */  sw      $a3, 0x0024($sp)           
/* 006E0 8085FD30 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 006E4 8085FD34 AFA80018 */  sw      $t0, 0x0018($sp)           
/* 006E8 8085FD38 3C018086 */  lui     $at, %hi(D_80864774)       ## $at = 80860000
/* 006EC 8085FD3C C4264774 */  lwc1    $f6, %lo(D_80864774)($at)  
/* 006F0 8085FD40 8FA60020 */  lw      $a2, 0x0020($sp)           
/* 006F4 8085FD44 8FA70024 */  lw      $a3, 0x0024($sp)           
/* 006F8 8085FD48 4600303C */  c.lt.s  $f6, $f0                   
/* 006FC 8085FD4C 8FA80018 */  lw      $t0, 0x0018($sp)           
/* 00700 8085FD50 4502001C */  bc1fl   .L8085FDC4                 
/* 00704 8085FD54 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00708 8085FD58 8D0D067C */  lw      $t5, 0x067C($t0)           ## 0000067C
/* 0070C 8085FD5C 31AE0010 */  andi    $t6, $t5, 0x0010           ## $t6 = 00000000
/* 00710 8085FD60 11C0000D */  beq     $t6, $zero, .L8085FD98     
/* 00714 8085FD64 00000000 */  nop
/* 00718 8085FD68 90CF010C */  lbu     $t7, 0x010C($a2)           ## 0000010C
/* 0071C 8085FD6C 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00720 8085FD70 11E00005 */  beq     $t7, $zero, .L8085FD88     
/* 00724 8085FD74 00000000 */  nop
/* 00728 8085FD78 0C218506 */  jal     func_80861418              
/* 0072C 8085FD7C 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00730 8085FD80 10000010 */  beq     $zero, $zero, .L8085FDC4   
/* 00734 8085FD84 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FD88:
/* 00738 8085FD88 0C2189F1 */  jal     func_808627C4              
/* 0073C 8085FD8C 00E02825 */  or      $a1, $a3, $zero            ## $a1 = 00000000
/* 00740 8085FD90 1000000C */  beq     $zero, $zero, .L8085FDC4   
/* 00744 8085FD94 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FD98:
/* 00748 8085FD98 0C218506 */  jal     func_80861418              
/* 0074C 8085FD9C 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00750 8085FDA0 10000008 */  beq     $zero, $zero, .L8085FDC4   
/* 00754 8085FDA4 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FDA8:
/* 00758 8085FDA8 0C217E4E */  jal     func_8085F938              
/* 0075C 8085FDAC 00E02825 */  or      $a1, $a3, $zero            ## $a1 = 00000000
/* 00760 8085FDB0 10000004 */  beq     $zero, $zero, .L8085FDC4   
/* 00764 8085FDB4 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FDB8:
/* 00768 8085FDB8 0C217E4E */  jal     func_8085F938              
/* 0076C 8085FDBC 00E02825 */  or      $a1, $a3, $zero            ## $a1 = 00000000
.L8085FDC0:
/* 00770 8085FDC0 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FDC4:
/* 00774 8085FDC4 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 00778 8085FDC8 03E00008 */  jr      $ra                        
/* 0077C 8085FDCC 00000000 */  nop


