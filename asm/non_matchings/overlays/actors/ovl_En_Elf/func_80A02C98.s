glabel func_80A02C98
/* 01068 80A02C98 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 0106C 80A02C9C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 01070 80A02CA0 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01074 80A02CA4 AFA60040 */  sw      $a2, 0x0040($sp)           
/* 01078 80A02CA8 C486028C */  lwc1    $f6, 0x028C($a0)           ## 0000028C
/* 0107C 80A02CAC C4A40000 */  lwc1    $f4, 0x0000($a1)           ## 00000000
/* 01080 80A02CB0 C48A0024 */  lwc1    $f10, 0x0024($a0)          ## 00000024
/* 01084 80A02CB4 44808000 */  mtc1    $zero, $f16                ## $f16 = 0.00
/* 01088 80A02CB8 46062200 */  add.s   $f8, $f4, $f6              
/* 0108C 80A02CBC C7A60040 */  lwc1    $f6, 0x0040($sp)           
/* 01090 80A02CC0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01094 80A02CC4 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 01098 80A02CC8 460A4101 */  sub.s   $f4, $f8, $f10             
/* 0109C 80A02CCC C48A0294 */  lwc1    $f10, 0x0294($a0)          ## 00000294
/* 010A0 80A02CD0 C4A80008 */  lwc1    $f8, 0x0008($a1)           ## 00000008
/* 010A4 80A02CD4 46062382 */  mul.s   $f14, $f4, $f6             
/* 010A8 80A02CD8 460A4100 */  add.s   $f4, $f8, $f10             
/* 010AC 80A02CDC C488002C */  lwc1    $f8, 0x002C($a0)           ## 0000002C
/* 010B0 80A02CE0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 010B4 80A02CE4 46082281 */  sub.s   $f10, $f4, $f8             
/* 010B8 80A02CE8 460E803E */  c.le.s  $f16, $f14                 
/* 010BC 80A02CEC 46065082 */  mul.s   $f2, $f10, $f6             
/* 010C0 80A02CF0 46007005 */  abs.s   $f0, $f14                  
/* 010C4 80A02CF4 45000005 */  bc1f    .L80A02D0C                 
/* 010C8 80A02CF8 46000386 */  mov.s   $f14, $f0                  
/* 010CC 80A02CFC 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 010D0 80A02D00 44819000 */  mtc1    $at, $f18                  ## $f18 = 1.00
/* 010D4 80A02D04 10000004 */  beq     $zero, $zero, .L80A02D18   
/* 010D8 80A02D08 4602803E */  c.le.s  $f16, $f2                  
.L80A02D0C:
/* 010DC 80A02D0C 44819000 */  mtc1    $at, $f18                  ## $f18 = 1.00
/* 010E0 80A02D10 00000000 */  nop
/* 010E4 80A02D14 4602803E */  c.le.s  $f16, $f2                  
.L80A02D18:
/* 010E8 80A02D18 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 010EC 80A02D1C 45020006 */  bc1fl   .L80A02D38                 
/* 010F0 80A02D20 44814000 */  mtc1    $at, $f8                   ## $f8 = -1.00
/* 010F4 80A02D24 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 010F8 80A02D28 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.00
/* 010FC 80A02D2C 10000004 */  beq     $zero, $zero, .L80A02D40   
/* 01100 80A02D30 E7A40028 */  swc1    $f4, 0x0028($sp)           
/* 01104 80A02D34 44814000 */  mtc1    $at, $f8                   ## $f8 = 1.00
.L80A02D38:
/* 01108 80A02D38 00000000 */  nop
/* 0110C 80A02D3C E7A80028 */  swc1    $f8, 0x0028($sp)           
.L80A02D40:
/* 01110 80A02D40 4610703C */  c.lt.s  $f14, $f16                 
/* 01114 80A02D44 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 01118 80A02D48 46001005 */  abs.s   $f0, $f2                   
/* 0111C 80A02D4C 8FA60040 */  lw      $a2, 0x0040($sp)           
/* 01120 80A02D50 45020004 */  bc1fl   .L80A02D64                 
/* 01124 80A02D54 44815000 */  mtc1    $at, $f10                  ## $f10 = 20.00
/* 01128 80A02D58 1000000C */  beq     $zero, $zero, .L80A02D8C   
/* 0112C 80A02D5C 46008086 */  mov.s   $f2, $f16                  
/* 01130 80A02D60 44815000 */  mtc1    $at, $f10                  ## $f10 = 20.00
.L80A02D64:
/* 01134 80A02D64 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 01138 80A02D68 460E503C */  c.lt.s  $f10, $f14                 
/* 0113C 80A02D6C 00000000 */  nop
/* 01140 80A02D70 45020005 */  bc1fl   .L80A02D88                 
/* 01144 80A02D74 46007306 */  mov.s   $f12, $f14                 
/* 01148 80A02D78 44816000 */  mtc1    $at, $f12                  ## $f12 = 20.00
/* 0114C 80A02D7C 10000003 */  beq     $zero, $zero, .L80A02D8C   
/* 01150 80A02D80 46006086 */  mov.s   $f2, $f12                  
/* 01154 80A02D84 46007306 */  mov.s   $f12, $f14                 
.L80A02D88:
/* 01158 80A02D88 46006086 */  mov.s   $f2, $f12                  
.L80A02D8C:
/* 0115C 80A02D8C 4610003C */  c.lt.s  $f0, $f16                  
/* 01160 80A02D90 46121382 */  mul.s   $f14, $f2, $f18            
/* 01164 80A02D94 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 01168 80A02D98 45020004 */  bc1fl   .L80A02DAC                 
/* 0116C 80A02D9C 44811000 */  mtc1    $at, $f2                   ## $f2 = 20.00
/* 01170 80A02DA0 1000000B */  beq     $zero, $zero, .L80A02DD0   
/* 01174 80A02DA4 46008086 */  mov.s   $f2, $f16                  
/* 01178 80A02DA8 44811000 */  mtc1    $at, $f2                   ## $f2 = 20.00
.L80A02DAC:
/* 0117C 80A02DAC 00000000 */  nop
/* 01180 80A02DB0 4600103C */  c.lt.s  $f2, $f0                   
/* 01184 80A02DB4 00000000 */  nop
/* 01188 80A02DB8 45020004 */  bc1fl   .L80A02DCC                 
/* 0118C 80A02DBC 46000306 */  mov.s   $f12, $f0                  
/* 01190 80A02DC0 10000002 */  beq     $zero, $zero, .L80A02DCC   
/* 01194 80A02DC4 46001306 */  mov.s   $f12, $f2                  
/* 01198 80A02DC8 46000306 */  mov.s   $f12, $f0                  
.L80A02DCC:
/* 0119C 80A02DCC 46006086 */  mov.s   $f2, $f12                  
.L80A02DD0:
/* 011A0 80A02DD0 E7A20024 */  swc1    $f2, 0x0024($sp)           
/* 011A4 80A02DD4 0C280AF6 */  jal     func_80A02BD8              
/* 011A8 80A02DD8 E7AE0034 */  swc1    $f14, 0x0034($sp)          
/* 011AC 80A02DDC C7AE0034 */  lwc1    $f14, 0x0034($sp)          
/* 011B0 80A02DE0 2604005C */  addiu   $a0, $s0, 0x005C           ## $a0 = 0000005C
/* 011B4 80A02DE4 3C063FC0 */  lui     $a2, 0x3FC0                ## $a2 = 3FC00000
/* 011B8 80A02DE8 44057000 */  mfc1    $a1, $f14                  
/* 011BC 80A02DEC 0C01DE80 */  jal     Math_ApproxF
              
/* 011C0 80A02DF0 00000000 */  nop
/* 011C4 80A02DF4 C7A20024 */  lwc1    $f2, 0x0024($sp)           
/* 011C8 80A02DF8 C7A60028 */  lwc1    $f6, 0x0028($sp)           
/* 011CC 80A02DFC 26040064 */  addiu   $a0, $s0, 0x0064           ## $a0 = 00000064
/* 011D0 80A02E00 3C063FC0 */  lui     $a2, 0x3FC0                ## $a2 = 3FC00000
/* 011D4 80A02E04 46061102 */  mul.s   $f4, $f2, $f6              
/* 011D8 80A02E08 44052000 */  mfc1    $a1, $f4                   
/* 011DC 80A02E0C 0C01DE80 */  jal     Math_ApproxF
              
/* 011E0 80A02E10 00000000 */  nop
/* 011E4 80A02E14 0C00B5FB */  jal     ActorPosition_Move              
/* 011E8 80A02E18 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 011EC 80A02E1C 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 011F0 80A02E20 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 011F4 80A02E24 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 011F8 80A02E28 03E00008 */  jr      $ra                        
/* 011FC 80A02E2C 00000000 */  nop
