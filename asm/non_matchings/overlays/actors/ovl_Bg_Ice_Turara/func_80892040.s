.late_rodata

glabel D_80892690
 .float 0.1
glabel D_80892694
 .float 0.2

.text
glabel func_80892040
/* 00120 80892040 27BDFF58 */  addiu   $sp, $sp, 0xFF58           ## $sp = FFFFFF58
/* 00124 80892044 AFB1005C */  sw      $s1, 0x005C($sp)           
/* 00128 80892048 00808825 */  or      $s1, $a0, $zero            ## $s1 = 00000000
/* 0012C 8089204C AFBE0078 */  sw      $s8, 0x0078($sp)           
/* 00130 80892050 00A0F025 */  or      $s8, $a1, $zero            ## $s8 = 00000000
/* 00134 80892054 AFBF007C */  sw      $ra, 0x007C($sp)           
/* 00138 80892058 AFA600B0 */  sw      $a2, 0x00B0($sp)           
/* 0013C 8089205C 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00140 80892060 AFB70074 */  sw      $s7, 0x0074($sp)           
/* 00144 80892064 AFB60070 */  sw      $s6, 0x0070($sp)           
/* 00148 80892068 AFB5006C */  sw      $s5, 0x006C($sp)           
/* 0014C 8089206C AFB40068 */  sw      $s4, 0x0068($sp)           
/* 00150 80892070 AFB30064 */  sw      $s3, 0x0064($sp)           
/* 00154 80892074 AFB20060 */  sw      $s2, 0x0060($sp)           
/* 00158 80892078 AFB00058 */  sw      $s0, 0x0058($sp)           
/* 0015C 8089207C F7BE0050 */  sdc1    $f30, 0x0050($sp)          
/* 00160 80892080 F7BC0048 */  sdc1    $f28, 0x0048($sp)          
/* 00164 80892084 F7BA0040 */  sdc1    $f26, 0x0040($sp)          
/* 00168 80892088 F7B80038 */  sdc1    $f24, 0x0038($sp)          
/* 0016C 8089208C F7B60030 */  sdc1    $f22, 0x0030($sp)          
/* 00170 80892090 F7B40028 */  sdc1    $f20, 0x0028($sp)          
/* 00174 80892094 26250024 */  addiu   $a1, $s1, 0x0024           ## $a1 = 00000024
/* 00178 80892098 2406001E */  addiu   $a2, $zero, 0x001E         ## $a2 = 0000001E
/* 0017C 8089209C 0C01AEB6 */  jal     Audio_PlaySoundAtPosition
              
/* 00180 808920A0 240728CB */  addiu   $a3, $zero, 0x28CB         ## $a3 = 000028CB
/* 00184 808920A4 3C018089 */  lui     $at, %hi(D_80892690)       ## $at = 80890000
/* 00188 808920A8 C43E2690 */  lwc1    $f30, %lo(D_80892690)($at) 
/* 0018C 808920AC 3C018089 */  lui     $at, %hi(D_80892694)       ## $at = 80890000
/* 00190 808920B0 C43C2694 */  lwc1    $f28, %lo(D_80892694)($at) 
/* 00194 808920B4 3C014080 */  lui     $at, 0x4080                ## $at = 40800000
/* 00198 808920B8 4481D000 */  mtc1    $at, $f26                  ## $f26 = 4.00
/* 0019C 808920BC 3C0140E0 */  lui     $at, 0x40E0                ## $at = 40E00000
/* 001A0 808920C0 4481B000 */  mtc1    $at, $f22                  ## $f22 = 7.00
/* 001A4 808920C4 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 001A8 808920C8 3C168089 */  lui     $s6, %hi(D_8089268C)       ## $s6 = 80890000
/* 001AC 808920CC 3C158089 */  lui     $s5, %hi(D_80892688)       ## $s5 = 80890000
/* 001B0 808920D0 3C148089 */  lui     $s4, %hi(D_8089267C)       ## $s4 = 80890000
/* 001B4 808920D4 4481A000 */  mtc1    $at, $f20                  ## $f20 = 8.00
/* 001B8 808920D8 2694267C */  addiu   $s4, $s4, %lo(D_8089267C)  ## $s4 = 8089267C
/* 001BC 808920DC 26B52688 */  addiu   $s5, $s5, %lo(D_80892688)  ## $s5 = 80892688
/* 001C0 808920E0 26D6268C */  addiu   $s6, $s6, %lo(D_8089268C)  ## $s6 = 8089268C
/* 001C4 808920E4 AFA00088 */  sw      $zero, 0x0088($sp)         
/* 001C8 808920E8 2417000A */  addiu   $s7, $zero, 0x000A         ## $s7 = 0000000A
/* 001CC 808920EC 27B3009C */  addiu   $s3, $sp, 0x009C           ## $s3 = FFFFFFF4
/* 001D0 808920F0 27B20090 */  addiu   $s2, $sp, 0x0090           ## $s2 = FFFFFFE8
.L808920F4:
/* 001D4 808920F4 8FA20088 */  lw      $v0, 0x0088($sp)           
/* 001D8 808920F8 C7A800B0 */  lwc1    $f8, 0x00B0($sp)           
/* 001DC 808920FC 00008025 */  or      $s0, $zero, $zero          ## $s0 = 00000000
/* 001E0 80892100 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 001E4 80892104 00000000 */  nop
/* 001E8 80892108 468021A0 */  cvt.s.w $f6, $f4                   
/* 001EC 8089210C 46083602 */  mul.s   $f24, $f6, $f8             
/* 001F0 80892110 00000000 */  nop
.L80892114:
/* 001F4 80892114 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 001F8 80892118 4600A306 */  mov.s   $f12, $f20                 
/* 001FC 8089211C C62A0024 */  lwc1    $f10, 0x0024($s1)          ## 00000024
/* 00200 80892120 460A0400 */  add.s   $f16, $f0, $f10            
/* 00204 80892124 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00208 80892128 E7B00090 */  swc1    $f16, 0x0090($sp)          
/* 0020C 8089212C C7B200B0 */  lwc1    $f18, 0x00B0($sp)          
/* 00210 80892130 C6260028 */  lwc1    $f6, 0x0028($s1)           ## 00000028
/* 00214 80892134 4600A306 */  mov.s   $f12, $f20                 
/* 00218 80892138 46120102 */  mul.s   $f4, $f0, $f18             
/* 0021C 8089213C 46062200 */  add.s   $f8, $f4, $f6              
/* 00220 80892140 46184280 */  add.s   $f10, $f8, $f24            
/* 00224 80892144 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 00228 80892148 E7AA0094 */  swc1    $f10, 0x0094($sp)          
/* 0022C 8089214C C630002C */  lwc1    $f16, 0x002C($s1)          ## 0000002C
/* 00230 80892150 4600B306 */  mov.s   $f12, $f22                 
/* 00234 80892154 46100480 */  add.s   $f18, $f0, $f16            
/* 00238 80892158 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 0023C 8089215C E7B20098 */  swc1    $f18, 0x0098($sp)          
/* 00240 80892160 E7A0009C */  swc1    $f0, 0x009C($sp)           
/* 00244 80892164 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 00248 80892168 4600B306 */  mov.s   $f12, $f22                 
/* 0024C 8089216C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00250 80892170 E7A000A4 */  swc1    $f0, 0x00A4($sp)           
/* 00254 80892174 461A0102 */  mul.s   $f4, $f0, $f26             
/* 00258 80892178 46142180 */  add.s   $f6, $f4, $f20             
/* 0025C 8089217C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00260 80892180 E7A600A0 */  swc1    $f6, 0x00A0($sp)           
/* 00264 80892184 461C0202 */  mul.s   $f8, $f0, $f28             
/* 00268 80892188 240E001E */  addiu   $t6, $zero, 0x001E         ## $t6 = 0000001E
/* 0026C 8089218C AFAE001C */  sw      $t6, 0x001C($sp)           
/* 00270 80892190 03C02025 */  or      $a0, $s8, $zero            ## $a0 = 00000000
/* 00274 80892194 02402825 */  or      $a1, $s2, $zero            ## $a1 = FFFFFFE8
/* 00278 80892198 02603825 */  or      $a3, $s3, $zero            ## $a3 = FFFFFFF4
/* 0027C 8089219C AFB40010 */  sw      $s4, 0x0010($sp)           
/* 00280 808921A0 461E4280 */  add.s   $f10, $f8, $f30            
/* 00284 808921A4 AFB50014 */  sw      $s5, 0x0014($sp)           
/* 00288 808921A8 AFB60018 */  sw      $s6, 0x0018($sp)           
/* 0028C 808921AC 44065000 */  mfc1    $a2, $f10                  
/* 00290 808921B0 0C00A8A9 */  jal     func_8002A2A4              
/* 00294 808921B4 00000000 */  nop
/* 00298 808921B8 26100001 */  addiu   $s0, $s0, 0x0001           ## $s0 = 00000001
/* 0029C 808921BC 1617FFD5 */  bne     $s0, $s7, .L80892114       
/* 002A0 808921C0 00000000 */  nop
/* 002A4 808921C4 8FAF0088 */  lw      $t7, 0x0088($sp)           
/* 002A8 808921C8 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 002AC 808921CC 25F80001 */  addiu   $t8, $t7, 0x0001           ## $t8 = 00000001
/* 002B0 808921D0 1701FFC8 */  bne     $t8, $at, .L808920F4       
/* 002B4 808921D4 AFB80088 */  sw      $t8, 0x0088($sp)           
/* 002B8 808921D8 8FBF007C */  lw      $ra, 0x007C($sp)           
/* 002BC 808921DC D7B40028 */  ldc1    $f20, 0x0028($sp)          
/* 002C0 808921E0 D7B60030 */  ldc1    $f22, 0x0030($sp)          
/* 002C4 808921E4 D7B80038 */  ldc1    $f24, 0x0038($sp)          
/* 002C8 808921E8 D7BA0040 */  ldc1    $f26, 0x0040($sp)          
/* 002CC 808921EC D7BC0048 */  ldc1    $f28, 0x0048($sp)          
/* 002D0 808921F0 D7BE0050 */  ldc1    $f30, 0x0050($sp)          
/* 002D4 808921F4 8FB00058 */  lw      $s0, 0x0058($sp)           
/* 002D8 808921F8 8FB1005C */  lw      $s1, 0x005C($sp)           
/* 002DC 808921FC 8FB20060 */  lw      $s2, 0x0060($sp)           
/* 002E0 80892200 8FB30064 */  lw      $s3, 0x0064($sp)           
/* 002E4 80892204 8FB40068 */  lw      $s4, 0x0068($sp)           
/* 002E8 80892208 8FB5006C */  lw      $s5, 0x006C($sp)           
/* 002EC 8089220C 8FB60070 */  lw      $s6, 0x0070($sp)           
/* 002F0 80892210 8FB70074 */  lw      $s7, 0x0074($sp)           
/* 002F4 80892214 8FBE0078 */  lw      $s8, 0x0078($sp)           
/* 002F8 80892218 03E00008 */  jr      $ra                        
/* 002FC 8089221C 27BD00A8 */  addiu   $sp, $sp, 0x00A8           ## $sp = 00000000


