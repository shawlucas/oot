glabel func_809A3988
/* 00658 809A3988 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 0065C 809A398C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00660 809A3990 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 00664 809A3994 F7B40018 */  sdc1    $f20, 0x0018($sp)          
/* 00668 809A3998 AFA40030 */  sw      $a0, 0x0030($sp)           
/* 0066C 809A399C AFA50034 */  sw      $a1, 0x0034($sp)           
/* 00670 809A39A0 8CC2003C */  lw      $v0, 0x003C($a2)           ## 0000003C
/* 00674 809A39A4 00C08025 */  or      $s0, $a2, $zero            ## $s0 = 00000000
/* 00678 809A39A8 50400043 */  beql    $v0, $zero, .L809A3AB8     
/* 0067C 809A39AC 8609005C */  lh      $t1, 0x005C($s0)           ## 0000005C
/* 00680 809A39B0 8C4E0130 */  lw      $t6, 0x0130($v0)           ## 00000130
/* 00684 809A39B4 51C00040 */  beql    $t6, $zero, .L809A3AB8     
/* 00688 809A39B8 8609005C */  lh      $t1, 0x005C($s0)           ## 0000005C
/* 0068C 809A39BC 84C3005C */  lh      $v1, 0x005C($a2)           ## 0000005C
/* 00690 809A39C0 28610009 */  slti    $at, $v1, 0x0009           
/* 00694 809A39C4 54200018 */  bnel    $at, $zero, .L809A3A28     
/* 00698 809A39C8 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 0069C 809A39CC 904F0114 */  lbu     $t7, 0x0114($v0)           ## 00000114
/* 006A0 809A39D0 51E00015 */  beql    $t7, $zero, .L809A3A28     
/* 006A4 809A39D4 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 006A8 809A39D8 94580112 */  lhu     $t8, 0x0112($v0)           ## 00000112
/* 006AC 809A39DC 3319C000 */  andi    $t9, $t8, 0xC000           ## $t9 = 00000000
/* 006B0 809A39E0 57200011 */  bnel    $t9, $zero, .L809A3A28     
/* 006B4 809A39E4 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 006B8 809A39E8 C4440024 */  lwc1    $f4, 0x0024($v0)           ## 00000024
/* 006BC 809A39EC C4C6002C */  lwc1    $f6, 0x002C($a2)           ## 0000002C
/* 006C0 809A39F0 C4D00030 */  lwc1    $f16, 0x0030($a2)          ## 00000030
/* 006C4 809A39F4 24680001 */  addiu   $t0, $v1, 0x0001           ## $t0 = 00000001
/* 006C8 809A39F8 46062200 */  add.s   $f8, $f4, $f6              
/* 006CC 809A39FC C4C60034 */  lwc1    $f6, 0x0034($a2)           ## 00000034
/* 006D0 809A3A00 E4C80000 */  swc1    $f8, 0x0000($a2)           ## 00000000
/* 006D4 809A3A04 C44A0028 */  lwc1    $f10, 0x0028($v0)          ## 00000028
/* 006D8 809A3A08 46105480 */  add.s   $f18, $f10, $f16           
/* 006DC 809A3A0C E4D20004 */  swc1    $f18, 0x0004($a2)          ## 00000004
/* 006E0 809A3A10 C444002C */  lwc1    $f4, 0x002C($v0)           ## 0000002C
/* 006E4 809A3A14 A4C8005C */  sh      $t0, 0x005C($a2)           ## 0000005C
/* 006E8 809A3A18 46062200 */  add.s   $f8, $f4, $f6              
/* 006EC 809A3A1C 1000004B */  beq     $zero, $zero, .L809A3B4C   
/* 006F0 809A3A20 E4C80008 */  swc1    $f8, 0x0008($a2)           ## 00000008
/* 006F4 809A3A24 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
.L809A3A28:
/* 006F8 809A3A28 14610048 */  bne     $v1, $at, .L809A3B4C       
/* 006FC 809A3A2C 24440024 */  addiu   $a0, $v0, 0x0024           ## $a0 = 00000024
/* 00700 809A3A30 0C01E01A */  jal     Math_Vec3f_Yaw
              
/* 00704 809A3A34 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00708 809A3A38 00022400 */  sll     $a0, $v0, 16               
/* 0070C 809A3A3C 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00710 809A3A40 00042403 */  sra     $a0, $a0, 16               
/* 00714 809A3A44 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00718 809A3A48 46000506 */  mov.s   $f20, $f0                  
/* 0071C 809A3A4C 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 00720 809A3A50 44815000 */  mtc1    $at, $f10                  ## $f10 = 1.00
/* 00724 809A3A54 8E04003C */  lw      $a0, 0x003C($s0)           ## 0000003C
/* 00728 809A3A58 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 0072C 809A3A5C 460A0400 */  add.s   $f16, $f0, $f10            
/* 00730 809A3A60 24840024 */  addiu   $a0, $a0, 0x0024           ## $a0 = 00000024
/* 00734 809A3A64 46148482 */  mul.s   $f18, $f16, $f20           
/* 00738 809A3A68 0C01E01A */  jal     Math_Vec3f_Yaw
              
/* 0073C 809A3A6C E6120018 */  swc1    $f18, 0x0018($s0)          ## 00000018
/* 00740 809A3A70 00022400 */  sll     $a0, $v0, 16               
/* 00744 809A3A74 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 00748 809A3A78 00042403 */  sra     $a0, $a0, 16               
/* 0074C 809A3A7C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00750 809A3A80 46000506 */  mov.s   $f20, $f0                  
/* 00754 809A3A84 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 00758 809A3A88 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.00
/* 0075C 809A3A8C 3C01BFC0 */  lui     $at, 0xBFC0                ## $at = BFC00000
/* 00760 809A3A90 44815000 */  mtc1    $at, $f10                  ## $f10 = -1.50
/* 00764 809A3A94 46040180 */  add.s   $f6, $f0, $f4              
/* 00768 809A3A98 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 0076C 809A3A9C 44818000 */  mtc1    $at, $f16                  ## $f16 = 5.00
/* 00770 809A3AA0 E60A001C */  swc1    $f10, 0x001C($s0)          ## 0000001C
/* 00774 809A3AA4 46143202 */  mul.s   $f8, $f6, $f20             
/* 00778 809A3AA8 E6100010 */  swc1    $f16, 0x0010($s0)          ## 00000010
/* 0077C 809A3AAC 10000027 */  beq     $zero, $zero, .L809A3B4C   
/* 00780 809A3AB0 E6080020 */  swc1    $f8, 0x0020($s0)           ## 00000020
/* 00784 809A3AB4 8609005C */  lh      $t1, 0x005C($s0)           ## 0000005C
.L809A3AB8:
/* 00788 809A3AB8 29210009 */  slti    $at, $t1, 0x0009           
/* 0078C 809A3ABC 14200023 */  bne     $at, $zero, .L809A3B4C     
/* 00790 809A3AC0 3C01809A */  lui     $at, %hi(D_809A3C20)       ## $at = 809A0000
/* 00794 809A3AC4 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 00798 809A3AC8 C42C3C20 */  lwc1    $f12, %lo(D_809A3C20)($at) 
/* 0079C 809A3ACC 4600048D */  trunc.w.s $f18, $f0                  
/* 007A0 809A3AD0 44029000 */  mfc1    $v0, $f18                  
/* 007A4 809A3AD4 00000000 */  nop
/* 007A8 809A3AD8 00022400 */  sll     $a0, $v0, 16               
/* 007AC 809A3ADC 00042403 */  sra     $a0, $a0, 16               
/* 007B0 809A3AE0 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 007B4 809A3AE4 A7A2002E */  sh      $v0, 0x002E($sp)           
/* 007B8 809A3AE8 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 007BC 809A3AEC 46000506 */  mov.s   $f20, $f0                  
/* 007C0 809A3AF0 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 007C4 809A3AF4 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.00
/* 007C8 809A3AF8 00000000 */  nop
/* 007CC 809A3AFC 46040180 */  add.s   $f6, $f0, $f4              
/* 007D0 809A3B00 46143202 */  mul.s   $f8, $f6, $f20             
/* 007D4 809A3B04 E6080018 */  swc1    $f8, 0x0018($s0)           ## 00000018
/* 007D8 809A3B08 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 007DC 809A3B0C 87A4002E */  lh      $a0, 0x002E($sp)           
/* 007E0 809A3B10 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 007E4 809A3B14 46000506 */  mov.s   $f20, $f0                  
/* 007E8 809A3B18 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 007EC 809A3B1C 44815000 */  mtc1    $at, $f10                  ## $f10 = 1.00
/* 007F0 809A3B20 3C01BFC0 */  lui     $at, 0xBFC0                ## $at = BFC00000
/* 007F4 809A3B24 44812000 */  mtc1    $at, $f4                   ## $f4 = -1.50
/* 007F8 809A3B28 460A0400 */  add.s   $f16, $f0, $f10            
/* 007FC 809A3B2C 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00800 809A3B30 44813000 */  mtc1    $at, $f6                   ## $f6 = 5.00
/* 00804 809A3B34 240B0008 */  addiu   $t3, $zero, 0x0008         ## $t3 = 00000008
/* 00808 809A3B38 46148482 */  mul.s   $f18, $f16, $f20           
/* 0080C 809A3B3C A60B005C */  sh      $t3, 0x005C($s0)           ## 0000005C
/* 00810 809A3B40 E604001C */  swc1    $f4, 0x001C($s0)           ## 0000001C
/* 00814 809A3B44 E6060010 */  swc1    $f6, 0x0010($s0)           ## 00000010
/* 00818 809A3B48 E6120020 */  swc1    $f18, 0x0020($s0)          ## 00000020
.L809A3B4C:
/* 0081C 809A3B4C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00820 809A3B50 D7B40018 */  ldc1    $f20, 0x0018($sp)          
/* 00824 809A3B54 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00828 809A3B58 03E00008 */  jr      $ra                        
/* 0082C 809A3B5C 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
