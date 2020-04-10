.late_rodata
glabel D_8088AF90
    .float 1.4
    .balign 4


.text
glabel func_8088A3B0
/* 00390 8088A3B0 27BDFF08 */  addiu   $sp, $sp, 0xFF08           ## $sp = FFFFFF08
/* 00394 8088A3B4 AFB20080 */  sw      $s2, 0x0080($sp)           
/* 00398 8088A3B8 00809025 */  or      $s2, $a0, $zero            ## $s2 = 00000000
/* 0039C 8088A3BC AFBF009C */  sw      $ra, 0x009C($sp)           
/* 003A0 8088A3C0 AFBE0098 */  sw      $s8, 0x0098($sp)           
/* 003A4 8088A3C4 AFB70094 */  sw      $s7, 0x0094($sp)           
/* 003A8 8088A3C8 AFB60090 */  sw      $s6, 0x0090($sp)           
/* 003AC 8088A3CC AFB5008C */  sw      $s5, 0x008C($sp)           
/* 003B0 8088A3D0 AFB40088 */  sw      $s4, 0x0088($sp)           
/* 003B4 8088A3D4 AFB30084 */  sw      $s3, 0x0084($sp)           
/* 003B8 8088A3D8 AFB1007C */  sw      $s1, 0x007C($sp)           
/* 003BC 8088A3DC AFB00078 */  sw      $s0, 0x0078($sp)           
/* 003C0 8088A3E0 F7BE0070 */  sdc1    $f30, 0x0070($sp)          
/* 003C4 8088A3E4 F7BC0068 */  sdc1    $f28, 0x0068($sp)          
/* 003C8 8088A3E8 F7BA0060 */  sdc1    $f26, 0x0060($sp)          
/* 003CC 8088A3EC F7B80058 */  sdc1    $f24, 0x0058($sp)          
/* 003D0 8088A3F0 F7B60050 */  sdc1    $f22, 0x0050($sp)          
/* 003D4 8088A3F4 F7B40048 */  sdc1    $f20, 0x0048($sp)          
/* 003D8 8088A3F8 AFA500FC */  sw      $a1, 0x00FC($sp)           
/* 003DC 8088A3FC 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 003E0 8088A400 848400B6 */  lh      $a0, 0x00B6($a0)           ## 000000B6
/* 003E4 8088A404 46000606 */  mov.s   $f24, $f0                  
/* 003E8 8088A408 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 003EC 8088A40C 864400B6 */  lh      $a0, 0x00B6($s2)           ## 000000B6
/* 003F0 8088A410 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 003F4 8088A414 44813000 */  mtc1    $at, $f6                   ## $f6 = 10.00
/* 003F8 8088A418 C6440028 */  lwc1    $f4, 0x0028($s2)           ## 00000028
/* 003FC 8088A41C 3C014130 */  lui     $at, 0x4130                ## $at = 41300000
/* 00400 8088A420 4481F000 */  mtc1    $at, $f30                  ## $f30 = 11.00
/* 00404 8088A424 46062200 */  add.s   $f8, $f4, $f6              
/* 00408 8088A428 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 0040C 8088A42C 2402FFD0 */  addiu   $v0, $zero, 0xFFD0         ## $v0 = FFFFFFD0
/* 00410 8088A430 264E0024 */  addiu   $t6, $s2, 0x0024           ## $t6 = 00000024
/* 00414 8088A434 3C1E0500 */  lui     $s8, 0x0500                ## $s8 = 05000000
/* 00418 8088A438 4481E000 */  mtc1    $at, $f28                  ## $f28 = 8.00
/* 0041C 8088A43C 46000686 */  mov.s   $f26, $f0                  
/* 00420 8088A440 E7A800DC */  swc1    $f8, 0x00DC($sp)           
/* 00424 8088A444 27DE0530 */  addiu   $s8, $s8, 0x0530           ## $s8 = 05000530
/* 00428 8088A448 AFAE00A4 */  sw      $t6, 0x00A4($sp)           
/* 0042C 8088A44C AFA200B8 */  sw      $v0, 0x00B8($sp)           
/* 00430 8088A450 00009825 */  or      $s3, $zero, $zero          ## $s3 = 00000000
/* 00434 8088A454 27B700E4 */  addiu   $s7, $sp, 0x00E4           ## $s7 = FFFFFFEC
/* 00438 8088A458 27B600D8 */  addiu   $s6, $sp, 0x00D8           ## $s6 = FFFFFFE0
/* 0043C 8088A45C 24150005 */  addiu   $s5, $zero, 0x0005         ## $s5 = 00000005
/* 00440 8088A460 24140004 */  addiu   $s4, $zero, 0x0004         ## $s4 = 00000004
.L8088A464:
/* 00444 8088A464 8FA200B8 */  lw      $v0, 0x00B8($sp)           
/* 00448 8088A468 266FFFFE */  addiu   $t7, $s3, 0xFFFE           ## $t7 = FFFFFFFE
/* 0044C 8088A46C 448F3000 */  mtc1    $t7, $f6                   ## $f6 = NaN
/* 00450 8088A470 44825000 */  mtc1    $v0, $f10                  ## $f10 = NaN
/* 00454 8088A474 44829000 */  mtc1    $v0, $f18                  ## $f18 = NaN
/* 00458 8088A478 46803220 */  cvt.s.w $f8, $f6                   
/* 0045C 8088A47C 00008025 */  or      $s0, $zero, $zero          ## $s0 = 00000000
/* 00460 8088A480 2411FFD0 */  addiu   $s1, $zero, 0xFFD0         ## $s1 = FFFFFFD0
/* 00464 8088A484 46805420 */  cvt.s.w $f16, $f10                 
/* 00468 8088A488 E7A800A8 */  swc1    $f8, 0x00A8($sp)           
/* 0046C 8088A48C 46809120 */  cvt.s.w $f4, $f18                  
/* 00470 8088A490 461A8082 */  mul.s   $f2, $f16, $f26            
/* 00474 8088A494 00000000 */  nop
/* 00478 8088A498 46182302 */  mul.s   $f12, $f4, $f24            
/* 0047C 8088A49C E7A200B0 */  swc1    $f2, 0x00B0($sp)           
/* 00480 8088A4A0 E7AC00AC */  swc1    $f12, 0x00AC($sp)          
.L8088A4A4:
/* 00484 8088A4A4 44915000 */  mtc1    $s1, $f10                  ## $f10 = NaN
/* 00488 8088A4A8 C7A200B0 */  lwc1    $f2, 0x00B0($sp)           
/* 0048C 8088A4AC C6440024 */  lwc1    $f4, 0x0024($s2)           ## 00000024
/* 00490 8088A4B0 46805020 */  cvt.s.w $f0, $f10                  
/* 00494 8088A4B4 C7AC00AC */  lwc1    $f12, 0x00AC($sp)          
/* 00498 8088A4B8 46180402 */  mul.s   $f16, $f0, $f24            
/* 0049C 8088A4BC 46028480 */  add.s   $f18, $f16, $f2            
/* 004A0 8088A4C0 461A0202 */  mul.s   $f8, $f0, $f26             
/* 004A4 8088A4C4 46049180 */  add.s   $f6, $f18, $f4             
/* 004A8 8088A4C8 460C4281 */  sub.s   $f10, $f8, $f12            
/* 004AC 8088A4CC E7A600D8 */  swc1    $f6, 0x00D8($sp)           
/* 004B0 8088A4D0 C650002C */  lwc1    $f16, 0x002C($s2)          ## 0000002C
/* 004B4 8088A4D4 46105480 */  add.s   $f18, $f10, $f16           
/* 004B8 8088A4D8 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 004BC 8088A4DC E7B200E0 */  swc1    $f18, 0x00E0($sp)          
/* 004C0 8088A4E0 461C0102 */  mul.s   $f4, $f0, $f28             
/* 004C4 8088A4E4 C7A600A8 */  lwc1    $f6, 0x00A8($sp)           
/* 004C8 8088A4E8 46062502 */  mul.s   $f20, $f4, $f6             
/* 004CC 8088A4EC 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 004D0 8088A4F0 00000000 */  nop
/* 004D4 8088A4F4 2618FFFE */  addiu   $t8, $s0, 0xFFFE           ## $t8 = FFFFFFFE
/* 004D8 8088A4F8 44985000 */  mtc1    $t8, $f10                  ## $f10 = NaN
/* 004DC 8088A4FC 461C0202 */  mul.s   $f8, $f0, $f28             
/* 004E0 8088A500 46805420 */  cvt.s.w $f16, $f10                 
/* 004E4 8088A504 46104582 */  mul.s   $f22, $f8, $f16            
/* 004E8 8088A508 00000000 */  nop
/* 004EC 8088A50C 4618B482 */  mul.s   $f18, $f22, $f24           
/* 004F0 8088A510 00000000 */  nop
/* 004F4 8088A514 461AA102 */  mul.s   $f4, $f20, $f26            
/* 004F8 8088A518 46049180 */  add.s   $f6, $f18, $f4             
/* 004FC 8088A51C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00500 8088A520 E7A600E4 */  swc1    $f6, 0x00E4($sp)           
/* 00504 8088A524 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 00508 8088A528 44815000 */  mtc1    $at, $f10                  ## $f10 = 30.00
/* 0050C 8088A52C 00000000 */  nop
/* 00510 8088A530 460A0202 */  mul.s   $f8, $f0, $f10             
/* 00514 8088A534 00000000 */  nop
/* 00518 8088A538 461AB402 */  mul.s   $f16, $f22, $f26           
/* 0051C 8088A53C 00000000 */  nop
/* 00520 8088A540 4618A482 */  mul.s   $f18, $f20, $f24           
/* 00524 8088A544 E7A800E8 */  swc1    $f8, 0x00E8($sp)           
/* 00528 8088A548 46128101 */  sub.s   $f4, $f16, $f18            
/* 0052C 8088A54C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00530 8088A550 E7A400EC */  swc1    $f4, 0x00EC($sp)           
/* 00534 8088A554 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 00538 8088A558 44813000 */  mtc1    $at, $f6                   ## $f6 = 0.50
/* 0053C 8088A55C 3C018089 */  lui     $at, %hi(D_8088AF90)       ## $at = 80890000
/* 00540 8088A560 C430AF90 */  lwc1    $f16, %lo(D_8088AF90)($at) 
/* 00544 8088A564 46060281 */  sub.s   $f10, $f0, $f6             
/* 00548 8088A568 8FA400FC */  lw      $a0, 0x00FC($sp)           
/* 0054C 8088A56C 02C02825 */  or      $a1, $s6, $zero            ## $a1 = FFFFFFE0
/* 00550 8088A570 02E03025 */  or      $a2, $s7, $zero            ## $a2 = FFFFFFEC
/* 00554 8088A574 461E5202 */  mul.s   $f8, $f10, $f30            
/* 00558 8088A578 8FA700A4 */  lw      $a3, 0x00A4($sp)           
/* 0055C 8088A57C 2408FDDA */  addiu   $t0, $zero, 0xFDDA         ## $t0 = FFFFFDDA
/* 00560 8088A580 2409000F */  addiu   $t1, $zero, 0x000F         ## $t1 = 0000000F
/* 00564 8088A584 240A000F */  addiu   $t2, $zero, 0x000F         ## $t2 = 0000000F
/* 00568 8088A588 240B0002 */  addiu   $t3, $zero, 0x0002         ## $t3 = 00000002
/* 0056C 8088A58C 240C0010 */  addiu   $t4, $zero, 0x0010         ## $t4 = 00000010
/* 00570 8088A590 46104482 */  mul.s   $f18, $f8, $f16            
/* 00574 8088A594 240D0064 */  addiu   $t5, $zero, 0x0064         ## $t5 = 00000064
/* 00578 8088A598 240EFFFF */  addiu   $t6, $zero, 0xFFFF         ## $t6 = FFFFFFFF
/* 0057C 8088A59C 240F0003 */  addiu   $t7, $zero, 0x0003         ## $t7 = 00000003
/* 00580 8088A5A0 461E9100 */  add.s   $f4, $f18, $f30            
/* 00584 8088A5A4 4600218D */  trunc.w.s $f6, $f4                   
/* 00588 8088A5A8 44033000 */  mfc1    $v1, $f6                   
/* 0058C 8088A5AC 00000000 */  nop
/* 00590 8088A5B0 00031C00 */  sll     $v1, $v1, 16               
/* 00594 8088A5B4 12600003 */  beq     $s3, $zero, .L8088A5C4     
/* 00598 8088A5B8 00031C03 */  sra     $v1, $v1, 16               
/* 0059C 8088A5BC 56740008 */  bnel    $s3, $s4, .L8088A5E0       
/* 005A0 8088A5C0 24020040 */  addiu   $v0, $zero, 0x0040         ## $v0 = 00000040
.L8088A5C4:
/* 005A4 8088A5C4 12000003 */  beq     $s0, $zero, .L8088A5D4     
/* 005A8 8088A5C8 00000000 */  nop
/* 005AC 8088A5CC 56140004 */  bnel    $s0, $s4, .L8088A5E0       
/* 005B0 8088A5D0 24020040 */  addiu   $v0, $zero, 0x0040         ## $v0 = 00000040
.L8088A5D4:
/* 005B4 8088A5D4 10000002 */  beq     $zero, $zero, .L8088A5E0   
/* 005B8 8088A5D8 24020041 */  addiu   $v0, $zero, 0x0041         ## $v0 = 00000041
/* 005BC 8088A5DC 24020040 */  addiu   $v0, $zero, 0x0040         ## $v0 = 00000040
.L8088A5E0:
/* 005C0 8088A5E0 AFA80010 */  sw      $t0, 0x0010($sp)           
/* 005C4 8088A5E4 AFA20014 */  sw      $v0, 0x0014($sp)           
/* 005C8 8088A5E8 AFA90018 */  sw      $t1, 0x0018($sp)           
/* 005CC 8088A5EC AFAA001C */  sw      $t2, 0x001C($sp)           
/* 005D0 8088A5F0 AFA00020 */  sw      $zero, 0x0020($sp)         
/* 005D4 8088A5F4 AFA30024 */  sw      $v1, 0x0024($sp)           
/* 005D8 8088A5F8 AFAB0028 */  sw      $t3, 0x0028($sp)           
/* 005DC 8088A5FC AFAC002C */  sw      $t4, 0x002C($sp)           
/* 005E0 8088A600 AFAD0030 */  sw      $t5, 0x0030($sp)           
/* 005E4 8088A604 AFAE0034 */  sw      $t6, 0x0034($sp)           
/* 005E8 8088A608 AFAF0038 */  sw      $t7, 0x0038($sp)           
/* 005EC 8088A60C 0C00A7A3 */  jal     Effect_SpawnFragment
              
/* 005F0 8088A610 AFBE003C */  sw      $s8, 0x003C($sp)           
/* 005F4 8088A614 26100001 */  addiu   $s0, $s0, 0x0001           ## $s0 = 00000001
/* 005F8 8088A618 1615FFA2 */  bne     $s0, $s5, .L8088A4A4       
/* 005FC 8088A61C 26310018 */  addiu   $s1, $s1, 0x0018           ## $s1 = FFFFFFE8
/* 00600 8088A620 8FB800B8 */  lw      $t8, 0x00B8($sp)           
/* 00604 8088A624 26730001 */  addiu   $s3, $s3, 0x0001           ## $s3 = 00000001
/* 00608 8088A628 27190018 */  addiu   $t9, $t8, 0x0018           ## $t9 = 00000018
/* 0060C 8088A62C 1675FF8D */  bne     $s3, $s5, .L8088A464       
/* 00610 8088A630 AFB900B8 */  sw      $t9, 0x00B8($sp)           
/* 00614 8088A634 8FBF009C */  lw      $ra, 0x009C($sp)           
/* 00618 8088A638 D7B40048 */  ldc1    $f20, 0x0048($sp)          
/* 0061C 8088A63C D7B60050 */  ldc1    $f22, 0x0050($sp)          
/* 00620 8088A640 D7B80058 */  ldc1    $f24, 0x0058($sp)          
/* 00624 8088A644 D7BA0060 */  ldc1    $f26, 0x0060($sp)          
/* 00628 8088A648 D7BC0068 */  ldc1    $f28, 0x0068($sp)          
/* 0062C 8088A64C D7BE0070 */  ldc1    $f30, 0x0070($sp)          
/* 00630 8088A650 8FB00078 */  lw      $s0, 0x0078($sp)           
/* 00634 8088A654 8FB1007C */  lw      $s1, 0x007C($sp)           
/* 00638 8088A658 8FB20080 */  lw      $s2, 0x0080($sp)           
/* 0063C 8088A65C 8FB30084 */  lw      $s3, 0x0084($sp)           
/* 00640 8088A660 8FB40088 */  lw      $s4, 0x0088($sp)           
/* 00644 8088A664 8FB5008C */  lw      $s5, 0x008C($sp)           
/* 00648 8088A668 8FB60090 */  lw      $s6, 0x0090($sp)           
/* 0064C 8088A66C 8FB70094 */  lw      $s7, 0x0094($sp)           
/* 00650 8088A670 8FBE0098 */  lw      $s8, 0x0098($sp)           
/* 00654 8088A674 03E00008 */  jr      $ra                        
/* 00658 8088A678 27BD00F8 */  addiu   $sp, $sp, 0x00F8           ## $sp = 00000000


