.late_rodata

glabel D_80881054
 .float 0.06
glabel D_80881058
 .float 6.734914E-5
glabel D_8088105C
 .float 0.6666667

.text
glabel func_808809E4
/* 00D44 808809E4 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 00D48 808809E8 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00D4C 808809EC AFA40028 */  sw      $a0, 0x0028($sp)           
/* 00D50 808809F0 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 00D54 808809F4 AFA60030 */  sw      $a2, 0x0030($sp)           
/* 00D58 808809F8 8CA21C44 */  lw      $v0, 0x1C44($a1)           ## 00001C44
/* 00D5C 808809FC 27A50018 */  addiu   $a1, $sp, 0x0018           ## $a1 = FFFFFFF0
/* 00D60 80880A00 24460024 */  addiu   $a2, $v0, 0x0024           ## $a2 = 00000024
/* 00D64 80880A04 0C00B6F4 */  jal     func_8002DBD0              
/* 00D68 80880A08 AFA20024 */  sw      $v0, 0x0024($sp)           
/* 00D6C 80880A0C C7A00018 */  lwc1    $f0, 0x0018($sp)           
/* 00D70 80880A10 3C01428C */  lui     $at, 0x428C                ## $at = 428C0000
/* 00D74 80880A14 44812000 */  mtc1    $at, $f4                   ## $f4 = 70.00
/* 00D78 80880A18 46000005 */  abs.s   $f0, $f0                   
/* 00D7C 80880A1C 8FA20024 */  lw      $v0, 0x0024($sp)           
/* 00D80 80880A20 4604003C */  c.lt.s  $f0, $f4                   
/* 00D84 80880A24 C7A0001C */  lwc1    $f0, 0x001C($sp)           
/* 00D88 80880A28 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 00D8C 80880A2C 4502002B */  bc1fl   .L80880ADC                 
/* 00D90 80880A30 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00D94 80880A34 44813000 */  mtc1    $at, $f6                   ## $f6 = 100.00
/* 00D98 80880A38 46000005 */  abs.s   $f0, $f0                   
/* 00D9C 80880A3C 3C0143FA */  lui     $at, 0x43FA                ## $at = 43FA0000
/* 00DA0 80880A40 4606003C */  c.lt.s  $f0, $f6                   
/* 00DA4 80880A44 C7A80020 */  lwc1    $f8, 0x0020($sp)           
/* 00DA8 80880A48 45020024 */  bc1fl   .L80880ADC                 
/* 00DAC 80880A4C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00DB0 80880A50 44810000 */  mtc1    $at, $f0                   ## $f0 = 500.00
/* 00DB4 80880A54 8FAF002C */  lw      $t7, 0x002C($sp)           
/* 00DB8 80880A58 4600403C */  c.lt.s  $f8, $f0                   
/* 00DBC 80880A5C 00000000 */  nop
/* 00DC0 80880A60 4502001E */  bc1fl   .L80880ADC                 
/* 00DC4 80880A64 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00DC8 80880A68 8DF81C44 */  lw      $t8, 0x1C44($t7)           ## 00001C44
/* 00DCC 80880A6C 24010001 */  addiu   $at, $zero, 0x0001         ## $at = 00000001
/* 00DD0 80880A70 8319014F */  lb      $t9, 0x014F($t8)           ## 0000014F
/* 00DD4 80880A74 53210019 */  beql    $t9, $at, .L80880ADC       
/* 00DD8 80880A78 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00DDC 80880A7C 46080281 */  sub.s   $f10, $f0, $f8             
/* 00DE0 80880A80 3C018088 */  lui     $at, %hi(D_80881054)       ## $at = 80880000
/* 00DE4 80880A84 C4301054 */  lwc1    $f16, %lo(D_80881054)($at) 
/* 00DE8 80880A88 87A80032 */  lh      $t0, 0x0032($sp)           
/* 00DEC 80880A8C 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00DF0 80880A90 46105482 */  mul.s   $f18, $f10, $f16           
/* 00DF4 80880A94 44884000 */  mtc1    $t0, $f8                   ## $f8 = 0.00
/* 00DF8 80880A98 44812000 */  mtc1    $at, $f4                   ## $f4 = 5.00
/* 00DFC 80880A9C 3C018088 */  lui     $at, %hi(D_80881058)       ## $at = 80880000
/* 00E00 80880AA0 468042A0 */  cvt.s.w $f10, $f8                  
/* 00E04 80880AA4 46049180 */  add.s   $f6, $f18, $f4             
/* 00E08 80880AA8 C4321058 */  lwc1    $f18, %lo(D_80881058)($at) 
/* 00E0C 80880AAC 3C018088 */  lui     $at, %hi(D_8088105C)       ## $at = 80880000
/* 00E10 80880AB0 C428105C */  lwc1    $f8, %lo(D_8088105C)($at)  
/* 00E14 80880AB4 460A3402 */  mul.s   $f16, $f6, $f10            
/* 00E18 80880AB8 00000000 */  nop
/* 00E1C 80880ABC 46128102 */  mul.s   $f4, $f16, $f18            
/* 00E20 80880AC0 00000000 */  nop
/* 00E24 80880AC4 46082182 */  mul.s   $f6, $f4, $f8              
/* 00E28 80880AC8 E44608AC */  swc1    $f6, 0x08AC($v0)           ## 000008AC
/* 00E2C 80880ACC 8FA90028 */  lw      $t1, 0x0028($sp)           
/* 00E30 80880AD0 852A00B6 */  lh      $t2, 0x00B6($t1)           ## 000000B6
/* 00E34 80880AD4 A44A08B0 */  sh      $t2, 0x08B0($v0)           ## 000008B0
/* 00E38 80880AD8 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80880ADC:
/* 00E3C 80880ADC 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00E40 80880AE0 03E00008 */  jr      $ra                        
/* 00E44 80880AE4 00000000 */  nop


