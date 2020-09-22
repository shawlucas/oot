.late_rodata
glabel D_808A54B0
    .float 0.001

glabel D_808A54B4
    .float 0.001

.text
glabel func_808A4FA4
/* 001E4 808A4FA4 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 001E8 808A4FA8 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 001EC 808A4FAC AFB10018 */  sw      $s1, 0x0018($sp)           
/* 001F0 808A4FB0 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 001F4 808A4FB4 3C01808A */  lui     $at, %hi(D_808A54B0)       ## $at = 808A0000
/* 001F8 808A4FB8 C42454B0 */  lwc1    $f4, %lo(D_808A54B0)($at)  
/* 001FC 808A4FBC C4860150 */  lwc1    $f6, 0x0150($a0)           ## 00000150
/* 00200 808A4FC0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00204 808A4FC4 8CB11C44 */  lw      $s1, 0x1C44($a1)           ## 00001C44
/* 00208 808A4FC8 4606203C */  c.lt.s  $f4, $f6                   
/* 0020C 808A4FCC 00000000 */  nop
/* 00210 808A4FD0 45020039 */  bc1fl   .L808A50B8                 
/* 00214 808A4FD4 AE000168 */  sw      $zero, 0x0168($s0)         ## 00000168
/* 00218 808A4FD8 8C8E0168 */  lw      $t6, 0x0168($a0)           ## 00000168
/* 0021C 808A4FDC 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 00220 808A4FE0 29E1001D */  slti    $at, $t7, 0x001D           
/* 00224 808A4FE4 14200034 */  bne     $at, $zero, .L808A50B8     
/* 00228 808A4FE8 AC8F0168 */  sw      $t7, 0x0168($a0)           ## 00000168
/* 0022C 808A4FEC 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00230 808A4FF0 0C023A62 */  jal     Player_InCsMode              
/* 00234 808A4FF4 AFA5004C */  sw      $a1, 0x004C($sp)           
/* 00238 808A4FF8 54400030 */  bnel    $v0, $zero, .L808A50BC     
/* 0023C 808A4FFC C6000150 */  lwc1    $f0, 0x0150($s0)           ## 00000150
/* 00240 808A5000 0C229441 */  jal     func_808A5104              
/* 00244 808A5004 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00248 808A5008 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 0024C 808A500C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00250 808A5010 0C00B7D5 */  jal     func_8002DF54              
/* 00254 808A5014 24060008 */  addiu   $a2, $zero, 0x0008         ## $a2 = 00000008
/* 00258 808A5018 26040178 */  addiu   $a0, $s0, 0x0178           ## $a0 = 00000178
/* 0025C 808A501C 0C01DF90 */  jal     Math_Vec3f_Copy
              ## Vec3f_Copy
/* 00260 808A5020 26250024 */  addiu   $a1, $s1, 0x0024           ## $a1 = 00000024
/* 00264 808A5024 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00268 808A5028 86040158 */  lh      $a0, 0x0158($s0)           ## 00000158
/* 0026C 808A502C 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 00270 808A5030 E7A0003C */  swc1    $f0, 0x003C($sp)           
/* 00274 808A5034 E7A80040 */  swc1    $f8, 0x0040($sp)           
/* 00278 808A5038 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 0027C 808A503C 86040158 */  lh      $a0, 0x0158($s0)           ## 00000158
/* 00280 808A5040 E7A00044 */  swc1    $f0, 0x0044($sp)           
/* 00284 808A5044 C6300024 */  lwc1    $f16, 0x0024($s1)          ## 00000024
/* 00288 808A5048 C60A0024 */  lwc1    $f10, 0x0024($s0)          ## 00000024
/* 0028C 808A504C 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 00290 808A5050 27A40024 */  addiu   $a0, $sp, 0x0024           ## $a0 = FFFFFFDC
/* 00294 808A5054 46105481 */  sub.s   $f18, $f10, $f16           
/* 00298 808A5058 E7A40034 */  swc1    $f4, 0x0034($sp)           
/* 0029C 808A505C 27A5003C */  addiu   $a1, $sp, 0x003C           ## $a1 = FFFFFFF4
/* 002A0 808A5060 27A60030 */  addiu   $a2, $sp, 0x0030           ## $a2 = FFFFFFE8
/* 002A4 808A5064 E7B20030 */  swc1    $f18, 0x0030($sp)          
/* 002A8 808A5068 C628002C */  lwc1    $f8, 0x002C($s1)           ## 0000002C
/* 002AC 808A506C C606002C */  lwc1    $f6, 0x002C($s0)           ## 0000002C
/* 002B0 808A5070 46083281 */  sub.s   $f10, $f6, $f8             
/* 002B4 808A5074 0C229370 */  jal     func_808A4DC0              
/* 002B8 808A5078 E7AA0038 */  swc1    $f10, 0x0038($sp)          
/* 002BC 808A507C 44808000 */  mtc1    $zero, $f16                ## $f16 = 0.00
/* 002C0 808A5080 C7B20028 */  lwc1    $f18, 0x0028($sp)          
/* 002C4 808A5084 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 002C8 808A5088 4612803C */  c.lt.s  $f16, $f18                 
/* 002CC 808A508C 00000000 */  nop
/* 002D0 808A5090 45020006 */  bc1fl   .L808A50AC                 
/* 002D4 808A5094 44813000 */  mtc1    $at, $f6                   ## $f6 = -1.00
/* 002D8 808A5098 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 002DC 808A509C 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.00
/* 002E0 808A50A0 10000005 */  beq     $zero, $zero, .L808A50B8   
/* 002E4 808A50A4 E604016C */  swc1    $f4, 0x016C($s0)           ## 0000016C
/* 002E8 808A50A8 44813000 */  mtc1    $at, $f6                   ## $f6 = 1.00
.L808A50AC:
/* 002EC 808A50AC 10000002 */  beq     $zero, $zero, .L808A50B8   
/* 002F0 808A50B0 E606016C */  swc1    $f6, 0x016C($s0)           ## 0000016C
/* 002F4 808A50B4 AE000168 */  sw      $zero, 0x0168($s0)         ## 00000168
.L808A50B8:
/* 002F8 808A50B8 C6000150 */  lwc1    $f0, 0x0150($s0)           ## 00000150
.L808A50BC:
/* 002FC 808A50BC 3C01808A */  lui     $at, %hi(D_808A54B4)       ## $at = 808A0000
/* 00300 808A50C0 C42854B4 */  lwc1    $f8, %lo(D_808A54B4)($at)  
/* 00304 808A50C4 46000005 */  abs.s   $f0, $f0                   
/* 00308 808A50C8 4600403C */  c.lt.s  $f8, $f0                   
/* 0030C 808A50CC 00000000 */  nop
/* 00310 808A50D0 45020008 */  bc1fl   .L808A50F4                 
/* 00314 808A50D4 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00318 808A50D8 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 0031C 808A50DC 2401FFEF */  addiu   $at, $zero, 0xFFEF         ## $at = FFFFFFEF
/* 00320 808A50E0 E60A0150 */  swc1    $f10, 0x0150($s0)          ## 00000150
/* 00324 808A50E4 8E390680 */  lw      $t9, 0x0680($s1)           ## 00000680
/* 00328 808A50E8 03214024 */  and     $t0, $t9, $at              
/* 0032C 808A50EC AE280680 */  sw      $t0, 0x0680($s1)           ## 00000680
/* 00330 808A50F0 8FBF001C */  lw      $ra, 0x001C($sp)           
.L808A50F4:
/* 00334 808A50F4 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 00338 808A50F8 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 0033C 808A50FC 03E00008 */  jr      $ra                        
/* 00340 808A5100 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000
