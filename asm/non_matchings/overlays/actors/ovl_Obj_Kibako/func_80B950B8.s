.late_rodata
glabel D_80B958D8
 .word 0x3E3851EC
glabel D_80B958DC
    .float 0.2
    .balign 4

.text
glabel func_80B950B8
/* 00418 80B950B8 27BDFF20 */  addiu   $sp, $sp, 0xFF20           ## $sp = FFFFFF20
/* 0041C 80B950BC AFB1007C */  sw      $s1, 0x007C($sp)           
/* 00420 80B950C0 AFBF009C */  sw      $ra, 0x009C($sp)           
/* 00424 80B950C4 AFBE0098 */  sw      $s8, 0x0098($sp)           
/* 00428 80B950C8 AFB70094 */  sw      $s7, 0x0094($sp)           
/* 0042C 80B950CC AFB60090 */  sw      $s6, 0x0090($sp)           
/* 00430 80B950D0 AFB5008C */  sw      $s5, 0x008C($sp)           
/* 00434 80B950D4 AFB40088 */  sw      $s4, 0x0088($sp)           
/* 00438 80B950D8 AFB30084 */  sw      $s3, 0x0084($sp)           
/* 0043C 80B950DC AFB20080 */  sw      $s2, 0x0080($sp)           
/* 00440 80B950E0 AFB00078 */  sw      $s0, 0x0078($sp)           
/* 00444 80B950E4 F7BE0070 */  sdc1    $f30, 0x0070($sp)          
/* 00448 80B950E8 F7BC0068 */  sdc1    $f28, 0x0068($sp)          
/* 0044C 80B950EC F7BA0060 */  sdc1    $f26, 0x0060($sp)          
/* 00450 80B950F0 F7B80058 */  sdc1    $f24, 0x0058($sp)          
/* 00454 80B950F4 F7B60050 */  sdc1    $f22, 0x0050($sp)          
/* 00458 80B950F8 F7B40048 */  sdc1    $f20, 0x0048($sp)          
/* 0045C 80B950FC 24910024 */  addiu   $s1, $a0, 0x0024           ## $s1 = 00000024
/* 00460 80B95100 8E2F0000 */  lw      $t7, 0x0000($s1)           ## 00000024
/* 00464 80B95104 27B500C8 */  addiu   $s5, $sp, 0x00C8           ## $s5 = FFFFFFE8
/* 00468 80B95108 00A0A025 */  or      $s4, $a1, $zero            ## $s4 = 00000000
/* 0046C 80B9510C AEAF0000 */  sw      $t7, 0x0000($s5)           ## FFFFFFE8
/* 00470 80B95110 8E2E0004 */  lw      $t6, 0x0004($s1)           ## 00000028
/* 00474 80B95114 241801F4 */  addiu   $t8, $zero, 0x01F4         ## $t8 = 000001F4
/* 00478 80B95118 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 0047C 80B9511C AEAE0004 */  sw      $t6, 0x0004($s5)           ## FFFFFFEC
/* 00480 80B95120 8E2F0008 */  lw      $t7, 0x0008($s1)           ## 0000002C
/* 00484 80B95124 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 00488 80B95128 AEAF0008 */  sw      $t7, 0x0008($s5)           ## FFFFFFF0
/* 0048C 80B9512C C7A400CC */  lwc1    $f4, 0x00CC($sp)           
/* 00490 80B95130 C4860084 */  lwc1    $f6, 0x0084($a0)           ## 00000084
/* 00494 80B95134 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00498 80B95138 02A02825 */  or      $a1, $s5, $zero            ## $a1 = FFFFFFE8
/* 0049C 80B9513C 46062200 */  add.s   $f8, $f4, $f6              
/* 004A0 80B95140 AFB80014 */  sw      $t8, 0x0014($sp)           
/* 004A4 80B95144 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 004A8 80B95148 0C00A527 */  jal     func_8002949C              
/* 004AC 80B9514C E7A800CC */  swc1    $f8, 0x00CC($sp)           
/* 004B0 80B95150 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 004B4 80B95154 4481F000 */  mtc1    $at, $f30                  ## $f30 = 5.00
/* 004B8 80B95158 3C0180B9 */  lui     $at, %hi(D_80B958D8)       ## $at = 80B90000
/* 004BC 80B9515C C43C58D8 */  lwc1    $f28, %lo(D_80B958D8)($at) 
/* 004C0 80B95160 3C014000 */  lui     $at, 0x4000                ## $at = 40000000
/* 004C4 80B95164 4481D000 */  mtc1    $at, $f26                  ## $f26 = 2.00
/* 004C8 80B95168 3C014180 */  lui     $at, 0x4180                ## $at = 41800000
/* 004CC 80B9516C 3C170500 */  lui     $s7, 0x0500                ## $s7 = 05000000
/* 004D0 80B95170 4481C000 */  mtc1    $at, $f24                  ## $f24 = 16.00
/* 004D4 80B95174 26F75380 */  addiu   $s7, $s7, 0x5380           ## $s7 = 05005380
/* 004D8 80B95178 00009825 */  or      $s3, $zero, $zero          ## $s3 = 00000000
/* 004DC 80B9517C 00009025 */  or      $s2, $zero, $zero          ## $s2 = 00000000
/* 004E0 80B95180 241E000C */  addiu   $s8, $zero, 0x000C         ## $s8 = 0000000C
/* 004E4 80B95184 27B600BC */  addiu   $s6, $sp, 0x00BC           ## $s6 = FFFFFFDC
.L80B95188:
/* 004E8 80B95188 00122400 */  sll     $a0, $s2, 16               
/* 004EC 80B9518C 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 004F0 80B95190 00042403 */  sra     $a0, $a0, 16               
/* 004F4 80B95194 00122400 */  sll     $a0, $s2, 16               
/* 004F8 80B95198 46000506 */  mov.s   $f20, $f0                  
/* 004FC 80B9519C 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 00500 80B951A0 00042403 */  sra     $a0, $a0, 16               
/* 00504 80B951A4 4618A282 */  mul.s   $f10, $f20, $f24           
/* 00508 80B951A8 46000586 */  mov.s   $f22, $f0                  
/* 0050C 80B951AC 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00510 80B951B0 E7AA00C8 */  swc1    $f10, 0x00C8($sp)          
/* 00514 80B951B4 461E0402 */  mul.s   $f16, $f0, $f30            
/* 00518 80B951B8 C7A600C8 */  lwc1    $f6, 0x00C8($sp)           
/* 0051C 80B951BC 4618B102 */  mul.s   $f4, $f22, $f24            
/* 00520 80B951C0 00000000 */  nop
/* 00524 80B951C4 461C3202 */  mul.s   $f8, $f6, $f28             
/* 00528 80B951C8 461A8480 */  add.s   $f18, $f16, $f26           
/* 0052C 80B951CC E7A400D0 */  swc1    $f4, 0x00D0($sp)           
/* 00530 80B951D0 E7B200CC */  swc1    $f18, 0x00CC($sp)          
/* 00534 80B951D4 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00538 80B951D8 E7A800BC */  swc1    $f8, 0x00BC($sp)           
/* 0053C 80B951DC 3C014080 */  lui     $at, 0x4080                ## $at = 40800000
/* 00540 80B951E0 44815000 */  mtc1    $at, $f10                  ## $f10 = 4.00
/* 00544 80B951E4 C7A400D0 */  lwc1    $f4, 0x00D0($sp)           
/* 00548 80B951E8 C7A800C8 */  lwc1    $f8, 0x00C8($sp)           
/* 0054C 80B951EC 460A0402 */  mul.s   $f16, $f0, $f10            
/* 00550 80B951F0 461A8480 */  add.s   $f18, $f16, $f26           
/* 00554 80B951F4 461C2182 */  mul.s   $f6, $f4, $f28             
/* 00558 80B951F8 E7B200C0 */  swc1    $f18, 0x00C0($sp)          
/* 0055C 80B951FC C7B200CC */  lwc1    $f18, 0x00CC($sp)          
/* 00560 80B95200 E7A600C4 */  swc1    $f6, 0x00C4($sp)           
/* 00564 80B95204 C62A0000 */  lwc1    $f10, 0x0000($s1)          ## 00000024
/* 00568 80B95208 460A4400 */  add.s   $f16, $f8, $f10            
/* 0056C 80B9520C E7B000C8 */  swc1    $f16, 0x00C8($sp)          
/* 00570 80B95210 C6260004 */  lwc1    $f6, 0x0004($s1)           ## 00000028
/* 00574 80B95214 46069200 */  add.s   $f8, $f18, $f6             
/* 00578 80B95218 E7A800CC */  swc1    $f8, 0x00CC($sp)           
/* 0057C 80B9521C C62A0008 */  lwc1    $f10, 0x0008($s1)          ## 0000002C
/* 00580 80B95220 460A2400 */  add.s   $f16, $f4, $f10            
/* 00584 80B95224 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00588 80B95228 E7B000D0 */  swc1    $f16, 0x00D0($sp)          
/* 0058C 80B9522C 3C0180B9 */  lui     $at, %hi(D_80B958DC)       ## $at = 80B90000
/* 00590 80B95230 C43258DC */  lwc1    $f18, %lo(D_80B958DC)($at) 
/* 00594 80B95234 24100020 */  addiu   $s0, $zero, 0x0020         ## $s0 = 00000020
/* 00598 80B95238 4612003C */  c.lt.s  $f0, $f18                  
/* 0059C 80B9523C 00000000 */  nop
/* 005A0 80B95240 45000003 */  bc1f    .L80B95250                 
/* 005A4 80B95244 00000000 */  nop
/* 005A8 80B95248 10000001 */  beq     $zero, $zero, .L80B95250   
/* 005AC 80B9524C 24100040 */  addiu   $s0, $zero, 0x0040         ## $s0 = 00000040
.L80B95250:
/* 005B0 80B95250 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 005B4 80B95254 00000000 */  nop
/* 005B8 80B95258 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 005BC 80B9525C 44813000 */  mtc1    $at, $f6                   ## $f6 = 30.00
/* 005C0 80B95260 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 005C4 80B95264 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 005C8 80B95268 46060202 */  mul.s   $f8, $f0, $f6              
/* 005CC 80B9526C 2419FF4C */  addiu   $t9, $zero, 0xFF4C         ## $t9 = FFFFFF4C
/* 005D0 80B95270 2408001E */  addiu   $t0, $zero, 0x001E         ## $t0 = 0000001E
/* 005D4 80B95274 2409001E */  addiu   $t1, $zero, 0x001E         ## $t1 = 0000001E
/* 005D8 80B95278 240C0020 */  addiu   $t4, $zero, 0x0020         ## $t4 = 00000020
/* 005DC 80B9527C 240D0046 */  addiu   $t5, $zero, 0x0046         ## $t5 = 00000046
/* 005E0 80B95280 240EFFFF */  addiu   $t6, $zero, 0xFFFF         ## $t6 = FFFFFFFF
/* 005E4 80B95284 46044280 */  add.s   $f10, $f8, $f4             
/* 005E8 80B95288 240F0003 */  addiu   $t7, $zero, 0x0003         ## $t7 = 00000003
/* 005EC 80B9528C AFAF0038 */  sw      $t7, 0x0038($sp)           
/* 005F0 80B95290 AFAE0034 */  sw      $t6, 0x0034($sp)           
/* 005F4 80B95294 4600540D */  trunc.w.s $f16, $f10                 
/* 005F8 80B95298 AFAD0030 */  sw      $t5, 0x0030($sp)           
/* 005FC 80B9529C AFAC002C */  sw      $t4, 0x002C($sp)           
/* 00600 80B952A0 AFA9001C */  sw      $t1, 0x001C($sp)           
/* 00604 80B952A4 440B8000 */  mfc1    $t3, $f16                  
/* 00608 80B952A8 AFA80018 */  sw      $t0, 0x0018($sp)           
/* 0060C 80B952AC AFB90010 */  sw      $t9, 0x0010($sp)           
/* 00610 80B952B0 02802025 */  or      $a0, $s4, $zero            ## $a0 = 00000000
/* 00614 80B952B4 02A02825 */  or      $a1, $s5, $zero            ## $a1 = FFFFFFE8
/* 00618 80B952B8 02C03025 */  or      $a2, $s6, $zero            ## $a2 = FFFFFFDC
/* 0061C 80B952BC 02203825 */  or      $a3, $s1, $zero            ## $a3 = 00000024
/* 00620 80B952C0 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 00624 80B952C4 AFA00020 */  sw      $zero, 0x0020($sp)         
/* 00628 80B952C8 AFA00028 */  sw      $zero, 0x0028($sp)         
/* 0062C 80B952CC AFB7003C */  sw      $s7, 0x003C($sp)           
/* 00630 80B952D0 0C00A7A3 */  jal     Effect_SpawnFragment
              
/* 00634 80B952D4 AFAB0024 */  sw      $t3, 0x0024($sp)           
/* 00638 80B952D8 26524E20 */  addiu   $s2, $s2, 0x4E20           ## $s2 = 00004E20
/* 0063C 80B952DC 00129400 */  sll     $s2, $s2, 16               
/* 00640 80B952E0 26730001 */  addiu   $s3, $s3, 0x0001           ## $s3 = 00000001
/* 00644 80B952E4 167EFFA8 */  bne     $s3, $s8, .L80B95188       
/* 00648 80B952E8 00129403 */  sra     $s2, $s2, 16               
/* 0064C 80B952EC 8FBF009C */  lw      $ra, 0x009C($sp)           
/* 00650 80B952F0 D7B40048 */  ldc1    $f20, 0x0048($sp)          
/* 00654 80B952F4 D7B60050 */  ldc1    $f22, 0x0050($sp)          
/* 00658 80B952F8 D7B80058 */  ldc1    $f24, 0x0058($sp)          
/* 0065C 80B952FC D7BA0060 */  ldc1    $f26, 0x0060($sp)          
/* 00660 80B95300 D7BC0068 */  ldc1    $f28, 0x0068($sp)          
/* 00664 80B95304 D7BE0070 */  ldc1    $f30, 0x0070($sp)          
/* 00668 80B95308 8FB00078 */  lw      $s0, 0x0078($sp)           
/* 0066C 80B9530C 8FB1007C */  lw      $s1, 0x007C($sp)           
/* 00670 80B95310 8FB20080 */  lw      $s2, 0x0080($sp)           
/* 00674 80B95314 8FB30084 */  lw      $s3, 0x0084($sp)           
/* 00678 80B95318 8FB40088 */  lw      $s4, 0x0088($sp)           
/* 0067C 80B9531C 8FB5008C */  lw      $s5, 0x008C($sp)           
/* 00680 80B95320 8FB60090 */  lw      $s6, 0x0090($sp)           
/* 00684 80B95324 8FB70094 */  lw      $s7, 0x0094($sp)           
/* 00688 80B95328 8FBE0098 */  lw      $s8, 0x0098($sp)           
/* 0068C 80B9532C 03E00008 */  jr      $ra                        
/* 00690 80B95330 27BD00E0 */  addiu   $sp, $sp, 0x00E0           ## $sp = 00000000


