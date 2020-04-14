glabel func_80B57D80
/* 049D0 80B57D80 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 049D4 80B57D84 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 049D8 80B57D88 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 049DC 80B57D8C 8CAE1C44 */  lw      $t6, 0x1C44($a1)           ## 00001C44
/* 049E0 80B57D90 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 049E4 80B57D94 AFAE0038 */  sw      $t6, 0x0038($sp)           
/* 049E8 80B57D98 0C2D5C41 */  jal     func_80B57104              
/* 049EC 80B57D9C 8C850314 */  lw      $a1, 0x0314($a0)           ## 00000314
/* 049F0 80B57DA0 8FAF0038 */  lw      $t7, 0x0038($sp)           
/* 049F4 80B57DA4 A7A20032 */  sh      $v0, 0x0032($sp)           
/* 049F8 80B57DA8 260503F8 */  addiu   $a1, $s0, 0x03F8           ## $a1 = 000003F8
/* 049FC 80B57DAC C5E40028 */  lwc1    $f4, 0x0028($t7)           ## 00000028
/* 04A00 80B57DB0 00022400 */  sll     $a0, $v0, 16               
/* 04A04 80B57DB4 00042403 */  sra     $a0, $a0, 16               
/* 04A08 80B57DB8 E4A4001C */  swc1    $f4, 0x001C($a1)           ## 00000414
/* 04A0C 80B57DBC 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 04A10 80B57DC0 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 04A14 80B57DC4 C6060090 */  lwc1    $f6, 0x0090($s0)           ## 00000090
/* 04A18 80B57DC8 C60A0024 */  lwc1    $f10, 0x0024($s0)          ## 00000024
/* 04A1C 80B57DCC 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 04A20 80B57DD0 46060202 */  mul.s   $f8, $f0, $f6              
/* 04A24 80B57DD4 460A4400 */  add.s   $f16, $f8, $f10            
/* 04A28 80B57DD8 E4B00018 */  swc1    $f16, 0x0018($a1)          ## 00000018
/* 04A2C 80B57DDC 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 04A30 80B57DE0 87A40032 */  lh      $a0, 0x0032($sp)           
/* 04A34 80B57DE4 C6120090 */  lwc1    $f18, 0x0090($s0)          ## 00000090
/* 04A38 80B57DE8 C606002C */  lwc1    $f6, 0x002C($s0)           ## 0000002C
/* 04A3C 80B57DEC 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 04A40 80B57DF0 46120102 */  mul.s   $f4, $f0, $f18             
/* 04A44 80B57DF4 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 04A48 80B57DF8 2442FA90 */  addiu   $v0, $v0, 0xFA90           ## $v0 = 8015FA90
/* 04A4C 80B57DFC 3C014180 */  lui     $at, 0x4180                ## $at = 41800000
/* 04A50 80B57E00 44819000 */  mtc1    $at, $f18                  ## $f18 = 16.00
/* 04A54 80B57E04 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04A58 80B57E08 24070004 */  addiu   $a3, $zero, 0x0004         ## $a3 = 00000004
/* 04A5C 80B57E0C 46062200 */  add.s   $f8, $f4, $f6              
/* 04A60 80B57E10 E4A80020 */  swc1    $f8, 0x0020($a1)           ## 00000020
/* 04A64 80B57E14 8C580000 */  lw      $t8, 0x0000($v0)           ## 8015FA90
/* 04A68 80B57E18 87191474 */  lh      $t9, 0x1474($t8)           ## 00001474
/* 04A6C 80B57E1C 44995000 */  mtc1    $t9, $f10                  ## $f10 = 0.00
/* 04A70 80B57E20 00000000 */  nop
/* 04A74 80B57E24 46805420 */  cvt.s.w $f16, $f10                 
/* 04A78 80B57E28 46128101 */  sub.s   $f4, $f16, $f18            
/* 04A7C 80B57E2C E4A40014 */  swc1    $f4, 0x0014($a1)           ## 00000014
/* 04A80 80B57E30 8C480000 */  lw      $t0, 0x0000($v0)           ## 8015FA90
/* 04A84 80B57E34 85061476 */  lh      $a2, 0x1476($t0)           ## 00001476
/* 04A88 80B57E38 24C6000C */  addiu   $a2, $a2, 0x000C           ## $a2 = 0000000C
/* 04A8C 80B57E3C 00063400 */  sll     $a2, $a2, 16               
/* 04A90 80B57E40 0C00D285 */  jal     func_80034A14              
/* 04A94 80B57E44 00063403 */  sra     $a2, $a2, 16               
/* 04A98 80B57E48 260200B6 */  addiu   $v0, $s0, 0x00B6           ## $v0 = 000000B6
/* 04A9C 80B57E4C 87A60032 */  lh      $a2, 0x0032($sp)           
/* 04AA0 80B57E50 84450000 */  lh      $a1, 0x0000($v0)           ## 000000B6
/* 04AA4 80B57E54 00C52023 */  subu    $a0, $a2, $a1              
/* 04AA8 80B57E58 04800004 */  bltz    $a0, .L80B57E6C            
/* 04AAC 80B57E5C 00041823 */  subu    $v1, $zero, $a0            
/* 04AB0 80B57E60 00041C00 */  sll     $v1, $a0, 16               
/* 04AB4 80B57E64 10000003 */  beq     $zero, $zero, .L80B57E74   
/* 04AB8 80B57E68 00031C03 */  sra     $v1, $v1, 16               
.L80B57E6C:
/* 04ABC 80B57E6C 00031C00 */  sll     $v1, $v1, 16               
/* 04AC0 80B57E70 00031C03 */  sra     $v1, $v1, 16               
.L80B57E74:
/* 04AC4 80B57E74 28610321 */  slti    $at, $v1, 0x0321           
/* 04AC8 80B57E78 50200007 */  beql    $at, $zero, .L80B57E98     
/* 04ACC 80B57E7C A6050032 */  sh      $a1, 0x0032($s0)           ## 00000032
/* 04AD0 80B57E80 A4460000 */  sh      $a2, 0x0000($v0)           ## 000000B6
/* 04AD4 80B57E84 84490000 */  lh      $t1, 0x0000($v0)           ## 000000B6
/* 04AD8 80B57E88 00001825 */  or      $v1, $zero, $zero          ## $v1 = 00000000
/* 04ADC 80B57E8C A6090032 */  sh      $t1, 0x0032($s0)           ## 00000032
/* 04AE0 80B57E90 84450000 */  lh      $a1, 0x0000($v0)           ## 000000B6
/* 04AE4 80B57E94 A6050032 */  sh      $a1, 0x0032($s0)           ## 00000032
.L80B57E98:
/* 04AE8 80B57E98 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 04AEC 80B57E9C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 04AF0 80B57EA0 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000
/* 04AF4 80B57EA4 03E00008 */  jr      $ra                        
/* 04AF8 80B57EA8 00601025 */  or      $v0, $v1, $zero            ## $v0 = 00000000
