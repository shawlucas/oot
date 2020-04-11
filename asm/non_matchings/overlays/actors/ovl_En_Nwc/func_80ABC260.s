.late_rodata
glabel D_80ABCB04
 .word 0x47C34FF3

.text
glabel func_80ABC260
/* 00180 80ABC260 27BDFF70 */  addiu   $sp, $sp, 0xFF70           ## $sp = FFFFFF70
/* 00184 80ABC264 3C0180AC */  lui     $at, %hi(D_80ABCB04)       ## $at = 80AC0000
/* 00188 80ABC268 C424CB04 */  lwc1    $f4, %lo(D_80ABCB04)($at)  
/* 0018C 80ABC26C AFBF0054 */  sw      $ra, 0x0054($sp)           
/* 00190 80ABC270 AFB70050 */  sw      $s7, 0x0050($sp)           
/* 00194 80ABC274 AFB6004C */  sw      $s6, 0x004C($sp)           
/* 00198 80ABC278 AFB50048 */  sw      $s5, 0x0048($sp)           
/* 0019C 80ABC27C AFB40044 */  sw      $s4, 0x0044($sp)           
/* 001A0 80ABC280 AFB30040 */  sw      $s3, 0x0040($sp)           
/* 001A4 80ABC284 AFB2003C */  sw      $s2, 0x003C($sp)           
/* 001A8 80ABC288 AFB10038 */  sw      $s1, 0x0038($sp)           
/* 001AC 80ABC28C AFB00034 */  sw      $s0, 0x0034($sp)           
/* 001B0 80ABC290 F7BA0028 */  sdc1    $f26, 0x0028($sp)          
/* 001B4 80ABC294 F7B80020 */  sdc1    $f24, 0x0020($sp)          
/* 001B8 80ABC298 F7B60018 */  sdc1    $f22, 0x0018($sp)          
/* 001BC 80ABC29C F7B40010 */  sdc1    $f20, 0x0010($sp)          
/* 001C0 80ABC2A0 8C910168 */  lw      $s1, 0x0168($a0)           ## 00000168
/* 001C4 80ABC2A4 E7A40080 */  swc1    $f4, 0x0080($sp)           
/* 001C8 80ABC2A8 908E016C */  lbu     $t6, 0x016C($a0)           ## 0000016C
/* 001CC 80ABC2AC 0080A025 */  or      $s4, $a0, $zero            ## $s4 = 00000000
/* 001D0 80ABC2B0 00A0B825 */  or      $s7, $a1, $zero            ## $s7 = 00000000
/* 001D4 80ABC2B4 24900170 */  addiu   $s0, $a0, 0x0170           ## $s0 = 00000170
/* 001D8 80ABC2B8 19C0005A */  blez    $t6, .L80ABC424            
/* 001DC 80ABC2BC 00009825 */  or      $s3, $zero, $zero          ## $s3 = 00000000
/* 001E0 80ABC2C0 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 001E4 80ABC2C4 4481C000 */  mtc1    $at, $f24                  ## $f24 = 100.00
/* 001E8 80ABC2C8 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 001EC 80ABC2CC 4481B000 */  mtc1    $at, $f22                  ## $f22 = 10.00
/* 001F0 80ABC2D0 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 001F4 80ABC2D4 3C1580AC */  lui     $s5, %hi(D_80ABCAB4)       ## $s5 = 80AC0000
/* 001F8 80ABC2D8 4481A000 */  mtc1    $at, $f20                  ## $f20 = 1.00
/* 001FC 80ABC2DC 4480D000 */  mtc1    $zero, $f26                ## $f26 = 0.00
/* 00200 80ABC2E0 26B5CAB4 */  addiu   $s5, $s5, %lo(D_80ABCAB4)  ## $s5 = 80ABCAB4
/* 00204 80ABC2E4 27B6007C */  addiu   $s6, $sp, 0x007C           ## $s6 = FFFFFFEC
/* 00208 80ABC2E8 26120008 */  addiu   $s2, $s0, 0x0008           ## $s2 = 00000178
.L80ABC2EC:
/* 0020C 80ABC2EC 02402825 */  or      $a1, $s2, $zero            ## $a1 = 00000178
/* 00210 80ABC2F0 0C01DF90 */  jal     Math_Vec3f_Copy
              ## Vec3f_Copy
/* 00214 80ABC2F4 2604001C */  addiu   $a0, $s0, 0x001C           ## $a0 = 0000018C
/* 00218 80ABC2F8 820F0000 */  lb      $t7, 0x0000($s0)           ## 00000170
/* 0021C 80ABC2FC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000170
/* 00220 80ABC300 02802825 */  or      $a1, $s4, $zero            ## $a1 = 00000000
/* 00224 80ABC304 000FC080 */  sll     $t8, $t7,  2               
/* 00228 80ABC308 02B8C821 */  addu    $t9, $s5, $t8              
/* 0022C 80ABC30C 8F390000 */  lw      $t9, 0x0000($t9)           ## 00000000
/* 00230 80ABC310 02E03025 */  or      $a2, $s7, $zero            ## $a2 = 00000000
/* 00234 80ABC314 0320F809 */  jalr    $ra, $t9                   
/* 00238 80ABC318 00000000 */  nop
/* 0023C 80ABC31C C6060008 */  lwc1    $f6, 0x0008($s0)           ## 00000178
/* 00240 80ABC320 4600320D */  trunc.w.s $f8, $f6                   
/* 00244 80ABC324 44094000 */  mfc1    $t1, $f8                   
/* 00248 80ABC328 00000000 */  nop
/* 0024C 80ABC32C A6290030 */  sh      $t1, 0x0030($s1)           ## 00000030
/* 00250 80ABC330 C60A000C */  lwc1    $f10, 0x000C($s0)          ## 0000017C
/* 00254 80ABC334 4600510D */  trunc.w.s $f4, $f10                  
/* 00258 80ABC338 440B2000 */  mfc1    $t3, $f4                   
/* 0025C 80ABC33C 00000000 */  nop
/* 00260 80ABC340 A62B0032 */  sh      $t3, 0x0032($s1)           ## 00000032
/* 00264 80ABC344 C6060010 */  lwc1    $f6, 0x0010($s0)           ## 00000180
/* 00268 80ABC348 4600320D */  trunc.w.s $f8, $f6                   
/* 0026C 80ABC34C 440D4000 */  mfc1    $t5, $f8                   
/* 00270 80ABC350 00000000 */  nop
/* 00274 80ABC354 A62D0034 */  sh      $t5, 0x0034($s1)           ## 00000034
/* 00278 80ABC358 C7A40080 */  lwc1    $f4, 0x0080($sp)           
/* 0027C 80ABC35C C60A000C */  lwc1    $f10, 0x000C($s0)          ## 0000017C
/* 00280 80ABC360 C7A6007C */  lwc1    $f6, 0x007C($sp)           
/* 00284 80ABC364 46045081 */  sub.s   $f2, $f10, $f4             
/* 00288 80ABC368 46001005 */  abs.s   $f0, $f2                   
/* 0028C 80ABC36C 4616003C */  c.lt.s  $f0, $f22                  
/* 00290 80ABC370 00000000 */  nop
/* 00294 80ABC374 4502001F */  bc1fl   .L80ABC3F4                 
/* 00298 80ABC378 8E4F0000 */  lw      $t7, 0x0000($s2)           ## 00000178
/* 0029C 80ABC37C C6020008 */  lwc1    $f2, 0x0008($s0)           ## 00000178
/* 002A0 80ABC380 C60C0010 */  lwc1    $f12, 0x0010($s0)          ## 00000180
/* 002A4 80ABC384 C7A80084 */  lwc1    $f8, 0x0084($sp)           
/* 002A8 80ABC388 46061381 */  sub.s   $f14, $f2, $f6             
/* 002AC 80ABC38C 46086401 */  sub.s   $f16, $f12, $f8            
/* 002B0 80ABC390 460E7282 */  mul.s   $f10, $f14, $f14           
/* 002B4 80ABC394 00000000 */  nop
/* 002B8 80ABC398 46108102 */  mul.s   $f4, $f16, $f16            
/* 002BC 80ABC39C 46045480 */  add.s   $f18, $f10, $f4            
/* 002C0 80ABC3A0 4618903C */  c.lt.s  $f18, $f24                 
/* 002C4 80ABC3A4 00000000 */  nop
/* 002C8 80ABC3A8 45000011 */  bc1f    .L80ABC3F0                 
/* 002CC 80ABC3AC 00000000 */  nop
/* 002D0 80ABC3B0 461A9032 */  c.eq.s  $f18, $f26                 
/* 002D4 80ABC3B4 00000000 */  nop
/* 002D8 80ABC3B8 4503000A */  bc1tl   .L80ABC3E4                 
/* 002DC 80ABC3BC 46141180 */  add.s   $f6, $f2, $f20             
/* 002E0 80ABC3C0 46009004 */  sqrt.s  $f0, $f18                  
/* 002E4 80ABC3C4 46007183 */  div.s   $f6, $f14, $f0             
/* 002E8 80ABC3C8 46008283 */  div.s   $f10, $f16, $f0            
/* 002EC 80ABC3CC 46061200 */  add.s   $f8, $f2, $f6              
/* 002F0 80ABC3D0 E6080008 */  swc1    $f8, 0x0008($s0)           ## 00000178
/* 002F4 80ABC3D4 460A6100 */  add.s   $f4, $f12, $f10            
/* 002F8 80ABC3D8 10000005 */  beq     $zero, $zero, .L80ABC3F0   
/* 002FC 80ABC3DC E6040010 */  swc1    $f4, 0x0010($s0)           ## 00000180
/* 00300 80ABC3E0 46141180 */  add.s   $f6, $f2, $f20             
.L80ABC3E4:
/* 00304 80ABC3E4 46146200 */  add.s   $f8, $f12, $f20            
/* 00308 80ABC3E8 E6060008 */  swc1    $f6, 0x0008($s0)           ## 00000178
/* 0030C 80ABC3EC E6080010 */  swc1    $f8, 0x0010($s0)           ## 00000180
.L80ABC3F0:
/* 00310 80ABC3F0 8E4F0000 */  lw      $t7, 0x0000($s2)           ## 00000178
.L80ABC3F4:
/* 00314 80ABC3F4 26730001 */  addiu   $s3, $s3, 0x0001           ## $s3 = 00000001
/* 00318 80ABC3F8 2610005C */  addiu   $s0, $s0, 0x005C           ## $s0 = 000001CC
/* 0031C 80ABC3FC AECF0000 */  sw      $t7, 0x0000($s6)           ## FFFFFFEC
/* 00320 80ABC400 8E4E0004 */  lw      $t6, 0x0004($s2)           ## 0000017C
/* 00324 80ABC404 26310040 */  addiu   $s1, $s1, 0x0040           ## $s1 = 00000040
/* 00328 80ABC408 AECE0004 */  sw      $t6, 0x0004($s6)           ## FFFFFFF0
/* 0032C 80ABC40C 8E4F0008 */  lw      $t7, 0x0008($s2)           ## 00000180
/* 00330 80ABC410 AECF0008 */  sw      $t7, 0x0008($s6)           ## FFFFFFF4
/* 00334 80ABC414 9298016C */  lbu     $t8, 0x016C($s4)           ## 0000016C
/* 00338 80ABC418 0278082A */  slt     $at, $s3, $t8              
/* 0033C 80ABC41C 5420FFB3 */  bnel    $at, $zero, .L80ABC2EC     
/* 00340 80ABC420 26120008 */  addiu   $s2, $s0, 0x0008           ## $s2 = 000001D4
.L80ABC424:
/* 00344 80ABC424 8FBF0054 */  lw      $ra, 0x0054($sp)           
/* 00348 80ABC428 D7B40010 */  ldc1    $f20, 0x0010($sp)          
/* 0034C 80ABC42C D7B60018 */  ldc1    $f22, 0x0018($sp)          
/* 00350 80ABC430 D7B80020 */  ldc1    $f24, 0x0020($sp)          
/* 00354 80ABC434 D7BA0028 */  ldc1    $f26, 0x0028($sp)          
/* 00358 80ABC438 8FB00034 */  lw      $s0, 0x0034($sp)           
/* 0035C 80ABC43C 8FB10038 */  lw      $s1, 0x0038($sp)           
/* 00360 80ABC440 8FB2003C */  lw      $s2, 0x003C($sp)           
/* 00364 80ABC444 8FB30040 */  lw      $s3, 0x0040($sp)           
/* 00368 80ABC448 8FB40044 */  lw      $s4, 0x0044($sp)           
/* 0036C 80ABC44C 8FB50048 */  lw      $s5, 0x0048($sp)           
/* 00370 80ABC450 8FB6004C */  lw      $s6, 0x004C($sp)           
/* 00374 80ABC454 8FB70050 */  lw      $s7, 0x0050($sp)           
/* 00378 80ABC458 03E00008 */  jr      $ra                        
/* 0037C 80ABC45C 27BD0090 */  addiu   $sp, $sp, 0x0090           ## $sp = 00000000


