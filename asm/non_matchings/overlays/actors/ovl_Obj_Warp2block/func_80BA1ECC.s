glabel func_80BA1ECC
/* 000DC 80BA1ECC 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 000E0 80BA1ED0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 000E4 80BA1ED4 AFA5003C */  sw      $a1, 0x003C($sp)           
/* 000E8 80BA1ED8 0C010D64 */  jal     func_80043590              
/* 000EC 80BA1EDC AFA40038 */  sw      $a0, 0x0038($sp)           
/* 000F0 80BA1EE0 10400003 */  beq     $v0, $zero, .L80BA1EF0     
/* 000F4 80BA1EE4 8FA40038 */  lw      $a0, 0x0038($sp)           
/* 000F8 80BA1EE8 10000053 */  beq     $zero, $zero, .L80BA2038   
/* 000FC 80BA1EEC 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80BA1EF0:
/* 00100 80BA1EF0 848F001C */  lh      $t7, 0x001C($a0)           ## 0000001C
/* 00104 80BA1EF4 3C0380BA */  lui     $v1, %hi(D_80BA2858)       ## $v1 = 80BA0000
/* 00108 80BA1EF8 24632858 */  addiu   $v1, $v1, %lo(D_80BA2858)  ## $v1 = 80BA2858
/* 0010C 80BA1EFC 000FC2C3 */  sra     $t8, $t7, 11               
/* 00110 80BA1F00 33190007 */  andi    $t9, $t8, 0x0007           ## $t9 = 00000000
/* 00114 80BA1F04 00194080 */  sll     $t0, $t9,  2               
/* 00118 80BA1F08 00684821 */  addu    $t1, $v1, $t0              
/* 0011C 80BA1F0C C5240000 */  lwc1    $f4, 0x0000($t1)           ## 00000000
/* 00120 80BA1F10 C4860090 */  lwc1    $f6, 0x0090($a0)           ## 00000090
/* 00124 80BA1F14 8FAE003C */  lw      $t6, 0x003C($sp)           
/* 00128 80BA1F18 8C87011C */  lw      $a3, 0x011C($a0)           ## 0000011C
/* 0012C 80BA1F1C 4604303E */  c.le.s  $f6, $f4                   
/* 00130 80BA1F20 8DC21C44 */  lw      $v0, 0x1C44($t6)           ## 00001C44
/* 00134 80BA1F24 27A50020 */  addiu   $a1, $sp, 0x0020           ## $a1 = FFFFFFE8
/* 00138 80BA1F28 4501000C */  bc1t    .L80BA1F5C                 
/* 0013C 80BA1F2C 24460024 */  addiu   $a2, $v0, 0x0024           ## $a2 = 00000024
/* 00140 80BA1F30 84EA001C */  lh      $t2, 0x001C($a3)           ## 0000001C
/* 00144 80BA1F34 C4EA0090 */  lwc1    $f10, 0x0090($a3)          ## 00000090
/* 00148 80BA1F38 000A5AC3 */  sra     $t3, $t2, 11               
/* 0014C 80BA1F3C 316C0007 */  andi    $t4, $t3, 0x0007           ## $t4 = 00000000
/* 00150 80BA1F40 000C6880 */  sll     $t5, $t4,  2               
/* 00154 80BA1F44 006D7021 */  addu    $t6, $v1, $t5              
/* 00158 80BA1F48 C5C80000 */  lwc1    $f8, 0x0000($t6)           ## 00000000
/* 0015C 80BA1F4C 4608503E */  c.le.s  $f10, $f8                  
/* 00160 80BA1F50 00000000 */  nop
/* 00164 80BA1F54 45000036 */  bc1f    .L80BA2030                 
/* 00168 80BA1F58 00000000 */  nop
.L80BA1F5C:
/* 0016C 80BA1F5C AFA40038 */  sw      $a0, 0x0038($sp)           
/* 00170 80BA1F60 AFA60018 */  sw      $a2, 0x0018($sp)           
/* 00174 80BA1F64 0C00B6F4 */  jal     ActorSearch_PosProjectDistanceXZ              
/* 00178 80BA1F68 AFA70030 */  sw      $a3, 0x0030($sp)           
/* 0017C 80BA1F6C 8FA40038 */  lw      $a0, 0x0038($sp)           
/* 00180 80BA1F70 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 00184 80BA1F74 44819000 */  mtc1    $at, $f18                  ## $f18 = 50.00
/* 00188 80BA1F78 C4900050 */  lwc1    $f16, 0x0050($a0)          ## 00000050
/* 0018C 80BA1F7C 3C0140C0 */  lui     $at, 0x40C0                ## $at = 40C00000
/* 00190 80BA1F80 44813000 */  mtc1    $at, $f6                   ## $f6 = 6.00
/* 00194 80BA1F84 46128102 */  mul.s   $f4, $f16, $f18            
/* 00198 80BA1F88 C7A00020 */  lwc1    $f0, 0x0020($sp)           
/* 0019C 80BA1F8C 8FA70030 */  lw      $a3, 0x0030($sp)           
/* 001A0 80BA1F90 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 001A4 80BA1F94 46000005 */  abs.s   $f0, $f0                   
/* 001A8 80BA1F98 27A50020 */  addiu   $a1, $sp, 0x0020           ## $a1 = FFFFFFE8
/* 001AC 80BA1F9C 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 001B0 80BA1FA0 46062080 */  add.s   $f2, $f4, $f6              
/* 001B4 80BA1FA4 4600103C */  c.lt.s  $f2, $f0                   
/* 001B8 80BA1FA8 C7A00028 */  lwc1    $f0, 0x0028($sp)           
/* 001BC 80BA1FAC 45010008 */  bc1t    .L80BA1FD0                 
/* 001C0 80BA1FB0 00000000 */  nop
/* 001C4 80BA1FB4 46000005 */  abs.s   $f0, $f0                   
/* 001C8 80BA1FB8 4600103C */  c.lt.s  $f2, $f0                   
/* 001CC 80BA1FBC 00000000 */  nop
/* 001D0 80BA1FC0 45010003 */  bc1t    .L80BA1FD0                 
/* 001D4 80BA1FC4 00000000 */  nop
/* 001D8 80BA1FC8 1000001B */  beq     $zero, $zero, .L80BA2038   
/* 001DC 80BA1FCC 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80BA1FD0:
/* 001E0 80BA1FD0 0C00B6F4 */  jal     ActorSearch_PosProjectDistanceXZ              
/* 001E4 80BA1FD4 AFA70030 */  sw      $a3, 0x0030($sp)           
/* 001E8 80BA1FD8 8FA70030 */  lw      $a3, 0x0030($sp)           
/* 001EC 80BA1FDC 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 001F0 80BA1FE0 44815000 */  mtc1    $at, $f10                  ## $f10 = 50.00
/* 001F4 80BA1FE4 C4E80050 */  lwc1    $f8, 0x0050($a3)           ## 00000050
/* 001F8 80BA1FE8 3C0140C0 */  lui     $at, 0x40C0                ## $at = 40C00000
/* 001FC 80BA1FEC 44819000 */  mtc1    $at, $f18                  ## $f18 = 6.00
/* 00200 80BA1FF0 460A4402 */  mul.s   $f16, $f8, $f10            
/* 00204 80BA1FF4 C7A00020 */  lwc1    $f0, 0x0020($sp)           
/* 00208 80BA1FF8 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 0020C 80BA1FFC 46000005 */  abs.s   $f0, $f0                   
/* 00210 80BA2000 46128080 */  add.s   $f2, $f16, $f18            
/* 00214 80BA2004 4600103C */  c.lt.s  $f2, $f0                   
/* 00218 80BA2008 C7A00028 */  lwc1    $f0, 0x0028($sp)           
/* 0021C 80BA200C 4501000A */  bc1t    .L80BA2038                 
/* 00220 80BA2010 00000000 */  nop
/* 00224 80BA2014 46000005 */  abs.s   $f0, $f0                   
/* 00228 80BA2018 4600103C */  c.lt.s  $f2, $f0                   
/* 0022C 80BA201C 00000000 */  nop
/* 00230 80BA2020 45010005 */  bc1t    .L80BA2038                 
/* 00234 80BA2024 00000000 */  nop
/* 00238 80BA2028 10000003 */  beq     $zero, $zero, .L80BA2038   
/* 0023C 80BA202C 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80BA2030:
/* 00240 80BA2030 10000001 */  beq     $zero, $zero, .L80BA2038   
/* 00244 80BA2034 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80BA2038:
/* 00248 80BA2038 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 0024C 80BA203C 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 00250 80BA2040 03E00008 */  jr      $ra                        
/* 00254 80BA2044 00000000 */  nop
