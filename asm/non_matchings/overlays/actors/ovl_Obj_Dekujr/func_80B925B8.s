glabel func_80B925B8
/* 00198 80B925B8 27BDFFB0 */  addiu   $sp, $sp, 0xFFB0           ## $sp = FFFFFFB0
/* 0019C 80B925BC 3C0F80B9 */  lui     $t7, %hi(D_80B92A2C)       ## $t7 = 80B90000
/* 001A0 80B925C0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 001A4 80B925C4 25EF2A2C */  addiu   $t7, $t7, %lo(D_80B92A2C)  ## $t7 = 80B92A2C
/* 001A8 80B925C8 8DF90000 */  lw      $t9, 0x0000($t7)           ## 80B92A2C
/* 001AC 80B925CC 27AE0028 */  addiu   $t6, $sp, 0x0028           ## $t6 = FFFFFFD8
/* 001B0 80B925D0 8DF80004 */  lw      $t8, 0x0004($t7)           ## 80B92A30
/* 001B4 80B925D4 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFD8
/* 001B8 80B925D8 8DF90008 */  lw      $t9, 0x0008($t7)           ## 80B92A34
/* 001BC 80B925DC ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFDC
/* 001C0 80B925E0 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 001C4 80B925E4 ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFE0
/* 001C8 80B925E8 90A81D6C */  lbu     $t0, 0x1D6C($a1)           ## 00001D6C
/* 001CC 80B925EC 00A03825 */  or      $a3, $a1, $zero            ## $a3 = 00000000
/* 001D0 80B925F0 24090002 */  addiu   $t1, $zero, 0x0002         ## $t1 = 00000002
/* 001D4 80B925F4 55000005 */  bnel    $t0, $zero, .L80B9260C     
/* 001D8 80B925F8 94EA1D74 */  lhu     $t2, 0x1D74($a3)           ## 00001D74
/* 001DC 80B925FC A089019C */  sb      $t1, 0x019C($a0)           ## 0000019C
/* 001E0 80B92600 10000055 */  beq     $zero, $zero, .L80B92758   
/* 001E4 80B92604 A080019B */  sb      $zero, 0x019B($a0)         ## 0000019B
/* 001E8 80B92608 94EA1D74 */  lhu     $t2, 0x1D74($a3)           ## 00001D74
.L80B9260C:
/* 001EC 80B9260C 2401015F */  addiu   $at, $zero, 0x015F         ## $at = 0000015F
/* 001F0 80B92610 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 001F4 80B92614 15410006 */  bne     $t2, $at, .L80B92630       
/* 001F8 80B92618 240528BF */  addiu   $a1, $zero, 0x28BF         ## $a1 = 000028BF
/* 001FC 80B9261C AFA60050 */  sw      $a2, 0x0050($sp)           
/* 00200 80B92620 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 00204 80B92624 AFA70054 */  sw      $a3, 0x0054($sp)           
/* 00208 80B92628 8FA60050 */  lw      $a2, 0x0050($sp)           
/* 0020C 80B9262C 8FA70054 */  lw      $a3, 0x0054($sp)           
.L80B92630:
/* 00210 80B92630 8CE41D90 */  lw      $a0, 0x1D90($a3)           ## 00001D90
/* 00214 80B92634 27A50040 */  addiu   $a1, $sp, 0x0040           ## $a1 = FFFFFFF0
/* 00218 80B92638 50800048 */  beql    $a0, $zero, .L80B9275C     
/* 0021C 80B9263C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00220 80B92640 AFA4004C */  sw      $a0, 0x004C($sp)           
/* 00224 80B92644 AFA60050 */  sw      $a2, 0x0050($sp)           
/* 00228 80B92648 0C2E494E */  jal     func_80B92538              
/* 0022C 80B9264C AFA70054 */  sw      $a3, 0x0054($sp)           
/* 00230 80B92650 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 00234 80B92654 0C2E495E */  jal     func_80B92578              
/* 00238 80B92658 27A50034 */  addiu   $a1, $sp, 0x0034           ## $a1 = FFFFFFE4
/* 0023C 80B9265C 8FA60050 */  lw      $a2, 0x0050($sp)           
/* 00240 80B92660 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 00244 80B92664 8FA70054 */  lw      $a3, 0x0054($sp)           
/* 00248 80B92668 90CB019C */  lbu     $t3, 0x019C($a2)           ## 0000019C
/* 0024C 80B9266C 27AC0040 */  addiu   $t4, $sp, 0x0040           ## $t4 = FFFFFFF0
/* 00250 80B92670 5560000A */  bnel    $t3, $zero, .L80B9269C     
/* 00254 80B92674 94980006 */  lhu     $t8, 0x0006($a0)           ## 00000006
/* 00258 80B92678 8D8E0000 */  lw      $t6, 0x0000($t4)           ## FFFFFFF0
/* 0025C 80B9267C 240F0001 */  addiu   $t7, $zero, 0x0001         ## $t7 = 00000001
/* 00260 80B92680 ACCE0024 */  sw      $t6, 0x0024($a2)           ## 00000024
/* 00264 80B92684 8D8D0004 */  lw      $t5, 0x0004($t4)           ## FFFFFFF4
/* 00268 80B92688 ACCD0028 */  sw      $t5, 0x0028($a2)           ## 00000028
/* 0026C 80B9268C 8D8E0008 */  lw      $t6, 0x0008($t4)           ## FFFFFFF8
/* 00270 80B92690 A0CF019C */  sb      $t7, 0x019C($a2)           ## 0000019C
/* 00274 80B92694 ACCE002C */  sw      $t6, 0x002C($a2)           ## 0000002C
/* 00278 80B92698 94980006 */  lhu     $t8, 0x0006($a0)           ## 00000006
.L80B9269C:
/* 0027C 80B9269C 27A90028 */  addiu   $t1, $sp, 0x0028           ## $t1 = FFFFFFD8
/* 00280 80B926A0 A4D800B4 */  sh      $t8, 0x00B4($a2)           ## 000000B4
/* 00284 80B926A4 94990008 */  lhu     $t9, 0x0008($a0)           ## 00000008
/* 00288 80B926A8 A4D900B6 */  sh      $t9, 0x00B6($a2)           ## 000000B6
/* 0028C 80B926AC 9488000A */  lhu     $t0, 0x000A($a0)           ## 0000000A
/* 00290 80B926B0 A4C800B8 */  sh      $t0, 0x00B8($a2)           ## 000000B8
/* 00294 80B926B4 8D2B0000 */  lw      $t3, 0x0000($t1)           ## FFFFFFD8
/* 00298 80B926B8 ACCB005C */  sw      $t3, 0x005C($a2)           ## 0000005C
/* 0029C 80B926BC 8D2A0004 */  lw      $t2, 0x0004($t1)           ## FFFFFFDC
/* 002A0 80B926C0 ACCA0060 */  sw      $t2, 0x0060($a2)           ## 00000060
/* 002A4 80B926C4 8D2B0008 */  lw      $t3, 0x0008($t1)           ## FFFFFFE0
/* 002A8 80B926C8 ACCB0064 */  sw      $t3, 0x0064($a2)           ## 00000064
/* 002AC 80B926CC 94EC1D74 */  lhu     $t4, 0x1D74($a3)           ## 00001D74
/* 002B0 80B926D0 94820004 */  lhu     $v0, 0x0004($a0)           ## 00000004
/* 002B4 80B926D4 004C082A */  slt     $at, $v0, $t4              
/* 002B8 80B926D8 54200020 */  bnel    $at, $zero, .L80B9275C     
/* 002BC 80B926DC 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 002C0 80B926E0 948D0002 */  lhu     $t5, 0x0002($a0)           ## 00000002
/* 002C4 80B926E4 C7A60034 */  lwc1    $f6, 0x0034($sp)           
/* 002C8 80B926E8 C7A80040 */  lwc1    $f8, 0x0040($sp)           
/* 002CC 80B926EC 004D7023 */  subu    $t6, $v0, $t5              
/* 002D0 80B926F0 448E2000 */  mtc1    $t6, $f4                   ## $f4 = 0.00
/* 002D4 80B926F4 46083281 */  sub.s   $f10, $f6, $f8             
/* 002D8 80B926F8 C4C2006C */  lwc1    $f2, 0x006C($a2)           ## 0000006C
/* 002DC 80B926FC C4CC0070 */  lwc1    $f12, 0x0070($a2)          ## 00000070
/* 002E0 80B92700 46802020 */  cvt.s.w $f0, $f4                   
/* 002E4 80B92704 46005403 */  div.s   $f16, $f10, $f0            
/* 002E8 80B92708 E4D0005C */  swc1    $f16, 0x005C($a2)          ## 0000005C
/* 002EC 80B9270C C7A40044 */  lwc1    $f4, 0x0044($sp)           
/* 002F0 80B92710 C7B20038 */  lwc1    $f18, 0x0038($sp)          
/* 002F4 80B92714 46049181 */  sub.s   $f6, $f18, $f4             
/* 002F8 80B92718 46003203 */  div.s   $f8, $f6, $f0              
/* 002FC 80B9271C E4C80060 */  swc1    $f8, 0x0060($a2)           ## 00000060
/* 00300 80B92720 C4CA0060 */  lwc1    $f10, 0x0060($a2)          ## 00000060
/* 00304 80B92724 46025400 */  add.s   $f16, $f10, $f2            
/* 00308 80B92728 E4D00060 */  swc1    $f16, 0x0060($a2)          ## 00000060
/* 0030C 80B9272C C4D20060 */  lwc1    $f18, 0x0060($a2)          ## 00000060
/* 00310 80B92730 460C903C */  c.lt.s  $f18, $f12                 
/* 00314 80B92734 00000000 */  nop
/* 00318 80B92738 45020003 */  bc1fl   .L80B92748                 
/* 0031C 80B9273C C7A4003C */  lwc1    $f4, 0x003C($sp)           
/* 00320 80B92740 E4CC0060 */  swc1    $f12, 0x0060($a2)          ## 00000060
/* 00324 80B92744 C7A4003C */  lwc1    $f4, 0x003C($sp)           
.L80B92748:
/* 00328 80B92748 C7A60048 */  lwc1    $f6, 0x0048($sp)           
/* 0032C 80B9274C 46062201 */  sub.s   $f8, $f4, $f6              
/* 00330 80B92750 46004283 */  div.s   $f10, $f8, $f0             
/* 00334 80B92754 E4CA0064 */  swc1    $f10, 0x0064($a2)          ## 00000064
.L80B92758:
/* 00338 80B92758 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80B9275C:
/* 0033C 80B9275C 27BD0050 */  addiu   $sp, $sp, 0x0050           ## $sp = 00000000
/* 00340 80B92760 03E00008 */  jr      $ra                        
/* 00344 80B92764 00000000 */  nop