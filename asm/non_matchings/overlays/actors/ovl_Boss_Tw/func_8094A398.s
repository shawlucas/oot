.late_rodata
glabel D_8094B224
 .word 0x4622F983
glabel D_8094B228
 .word 0x4622F983, 0x00000000

.text
glabel func_8094A398
/* 116C8 8094A398 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 116CC 8094A39C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 116D0 8094A3A0 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 116D4 8094A3A4 AFA50044 */  sw      $a1, 0x0044($sp)           
/* 116D8 8094A3A8 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 116DC 8094A3AC 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 116E0 8094A3B0 2405311F */  addiu   $a1, $zero, 0x311F         ## $a1 = 0000311F
/* 116E4 8094A3B4 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 116E8 8094A3B8 26040568 */  addiu   $a0, $s0, 0x0568           ## $a0 = 00000568
/* 116EC 8094A3BC C60804B4 */  lwc1    $f8, 0x04B4($s0)           ## 000004B4
/* 116F0 8094A3C0 C60A0028 */  lwc1    $f10, 0x0028($s0)          ## 00000028
/* 116F4 8094A3C4 C60404B0 */  lwc1    $f4, 0x04B0($s0)           ## 000004B0
/* 116F8 8094A3C8 C6060024 */  lwc1    $f6, 0x0024($s0)           ## 00000024
/* 116FC 8094A3CC 460A4481 */  sub.s   $f18, $f8, $f10            
/* 11700 8094A3D0 46062301 */  sub.s   $f12, $f4, $f6             
/* 11704 8094A3D4 E7B20038 */  swc1    $f18, 0x0038($sp)          
/* 11708 8094A3D8 C606002C */  lwc1    $f6, 0x002C($s0)           ## 0000002C
/* 1170C 8094A3DC C60404B8 */  lwc1    $f4, 0x04B8($s0)           ## 000004B8
/* 11710 8094A3E0 E7AC003C */  swc1    $f12, 0x003C($sp)          
/* 11714 8094A3E4 46062381 */  sub.s   $f14, $f4, $f6             
/* 11718 8094A3E8 0C03F494 */  jal     Math_atan2f              
/* 1171C 8094A3EC E7AE0034 */  swc1    $f14, 0x0034($sp)          
/* 11720 8094A3F0 3C018095 */  lui     $at, %hi(D_8094B224)       ## $at = 80950000
/* 11724 8094A3F4 C428B224 */  lwc1    $f8, %lo(D_8094B224)($at)  
/* 11728 8094A3F8 C7A2003C */  lwc1    $f2, 0x003C($sp)           
/* 1172C 8094A3FC C7B00034 */  lwc1    $f16, 0x0034($sp)          
/* 11730 8094A400 46080282 */  mul.s   $f10, $f0, $f8             
/* 11734 8094A404 C7AC0038 */  lwc1    $f12, 0x0038($sp)          
/* 11738 8094A408 46021202 */  mul.s   $f8, $f2, $f2              
/* 1173C 8094A40C 4600548D */  trunc.w.s $f18, $f10                 
/* 11740 8094A410 46108282 */  mul.s   $f10, $f16, $f16           
/* 11744 8094A414 440F9000 */  mfc1    $t7, $f18                  
/* 11748 8094A418 00000000 */  nop
/* 1174C 8094A41C 000FC400 */  sll     $t8, $t7, 16               
/* 11750 8094A420 460A4000 */  add.s   $f0, $f8, $f10             
/* 11754 8094A424 0018CC03 */  sra     $t9, $t8, 16               
/* 11758 8094A428 44992000 */  mtc1    $t9, $f4                   ## $f4 = 0.00
/* 1175C 8094A42C 46000384 */  sqrt.s  $f14, $f0                  
/* 11760 8094A430 468021A0 */  cvt.s.w $f6, $f4                   
/* 11764 8094A434 E7AE0028 */  swc1    $f14, 0x0028($sp)          
/* 11768 8094A438 0C03F494 */  jal     Math_atan2f              
/* 1176C 8094A43C E7A6002C */  swc1    $f6, 0x002C($sp)           
/* 11770 8094A440 3C018095 */  lui     $at, %hi(D_8094B228)       ## $at = 80950000
/* 11774 8094A444 C432B228 */  lwc1    $f18, %lo(D_8094B228)($at) 
/* 11778 8094A448 26040030 */  addiu   $a0, $s0, 0x0030           ## $a0 = 00000030
/* 1177C 8094A44C 2406000A */  addiu   $a2, $zero, 0x000A         ## $a2 = 0000000A
/* 11780 8094A450 46120102 */  mul.s   $f4, $f0, $f18             
/* 11784 8094A454 4600218D */  trunc.w.s $f6, $f4                   
/* 11788 8094A458 C60404C8 */  lwc1    $f4, 0x04C8($s0)           ## 000004C8
/* 1178C 8094A45C 44093000 */  mfc1    $t1, $f6                   
/* 11790 8094A460 4600218D */  trunc.w.s $f6, $f4                   
/* 11794 8094A464 00095400 */  sll     $t2, $t1, 16               
/* 11798 8094A468 000A5C03 */  sra     $t3, $t2, 16               
/* 1179C 8094A46C 448B4000 */  mtc1    $t3, $f8                   ## $f8 = 0.00
/* 117A0 8094A470 44073000 */  mfc1    $a3, $f6                   
/* 117A4 8094A474 468042A0 */  cvt.s.w $f10, $f8                  
/* 117A8 8094A478 00073C00 */  sll     $a3, $a3, 16               
/* 117AC 8094A47C 00073C03 */  sra     $a3, $a3, 16               
/* 117B0 8094A480 4600548D */  trunc.w.s $f18, $f10                 
/* 117B4 8094A484 44059000 */  mfc1    $a1, $f18                  
/* 117B8 8094A488 00000000 */  nop
/* 117BC 8094A48C 00052C00 */  sll     $a1, $a1, 16               
/* 117C0 8094A490 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 117C4 8094A494 00052C03 */  sra     $a1, $a1, 16               
/* 117C8 8094A498 C7A8002C */  lwc1    $f8, 0x002C($sp)           
/* 117CC 8094A49C C61204C8 */  lwc1    $f18, 0x04C8($s0)          ## 000004C8
/* 117D0 8094A4A0 26040032 */  addiu   $a0, $s0, 0x0032           ## $a0 = 00000032
/* 117D4 8094A4A4 4600428D */  trunc.w.s $f10, $f8                  
/* 117D8 8094A4A8 2406000A */  addiu   $a2, $zero, 0x000A         ## $a2 = 0000000A
/* 117DC 8094A4AC 4600910D */  trunc.w.s $f4, $f18                  
/* 117E0 8094A4B0 44055000 */  mfc1    $a1, $f10                  
/* 117E4 8094A4B4 44072000 */  mfc1    $a3, $f4                   
/* 117E8 8094A4B8 00052C00 */  sll     $a1, $a1, 16               
/* 117EC 8094A4BC 00052C03 */  sra     $a1, $a1, 16               
/* 117F0 8094A4C0 00073C00 */  sll     $a3, $a3, 16               
/* 117F4 8094A4C4 00073C03 */  sra     $a3, $a3, 16               
/* 117F8 8094A4C8 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 117FC 8094A4CC AFA50020 */  sw      $a1, 0x0020($sp)           
/* 11800 8094A4D0 C60604C8 */  lwc1    $f6, 0x04C8($s0)           ## 000004C8
/* 11804 8094A4D4 8FA50020 */  lw      $a1, 0x0020($sp)           
/* 11808 8094A4D8 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
/* 1180C 8094A4DC 4600320D */  trunc.w.s $f8, $f6                   
/* 11810 8094A4E0 2406000A */  addiu   $a2, $zero, 0x000A         ## $a2 = 0000000A
/* 11814 8094A4E4 44074000 */  mfc1    $a3, $f8                   
/* 11818 8094A4E8 00000000 */  nop
/* 1181C 8094A4EC 00073C00 */  sll     $a3, $a3, 16               
/* 11820 8094A4F0 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 11824 8094A4F4 00073C03 */  sra     $a3, $a3, 16               
/* 11828 8094A4F8 260404C8 */  addiu   $a0, $s0, 0x04C8           ## $a0 = 000004C8
/* 1182C 8094A4FC 3C0544FA */  lui     $a1, 0x44FA                ## $a1 = 44FA0000
/* 11830 8094A500 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 11834 8094A504 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 11838 8094A508 3C0742C8 */  lui     $a3, 0x42C8                ## $a3 = 42C80000
/* 1183C 8094A50C 26040068 */  addiu   $a0, $s0, 0x0068           ## $a0 = 00000068
/* 11840 8094A510 3C0541F0 */  lui     $a1, 0x41F0                ## $a1 = 41F00000
/* 11844 8094A514 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 11848 8094A518 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 1184C 8094A51C 3C074000 */  lui     $a3, 0x4000                ## $a3 = 40000000
/* 11850 8094A520 0C00B642 */  jal     ActorPosition_SpeedSetXY              
/* 11854 8094A524 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 11858 8094A528 C600005C */  lwc1    $f0, 0x005C($s0)           ## 0000005C
/* 1185C 8094A52C 3C013FC0 */  lui     $at, 0x3FC0                ## $at = 3FC00000
/* 11860 8094A530 44815000 */  mtc1    $at, $f10                  ## $f10 = 1.50
/* 11864 8094A534 46000005 */  abs.s   $f0, $f0                   
/* 11868 8094A538 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 1186C 8094A53C 460A0482 */  mul.s   $f18, $f0, $f10            
/* 11870 8094A540 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 11874 8094A544 26040024 */  addiu   $a0, $s0, 0x0024           ## $a0 = 00000024
/* 11878 8094A548 8E0504B0 */  lw      $a1, 0x04B0($s0)           ## 000004B0
/* 1187C 8094A54C 44079000 */  mfc1    $a3, $f18                  
/* 11880 8094A550 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 11884 8094A554 00000000 */  nop
/* 11888 8094A558 C6000060 */  lwc1    $f0, 0x0060($s0)           ## 00000060
/* 1188C 8094A55C 3C013FC0 */  lui     $at, 0x3FC0                ## $at = 3FC00000
/* 11890 8094A560 44812000 */  mtc1    $at, $f4                   ## $f4 = 1.50
/* 11894 8094A564 46000005 */  abs.s   $f0, $f0                   
/* 11898 8094A568 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 1189C 8094A56C 46040182 */  mul.s   $f6, $f0, $f4              
/* 118A0 8094A570 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 118A4 8094A574 26040028 */  addiu   $a0, $s0, 0x0028           ## $a0 = 00000028
/* 118A8 8094A578 8E0504B4 */  lw      $a1, 0x04B4($s0)           ## 000004B4
/* 118AC 8094A57C 44073000 */  mfc1    $a3, $f6                   
/* 118B0 8094A580 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 118B4 8094A584 00000000 */  nop
/* 118B8 8094A588 260404B4 */  addiu   $a0, $s0, 0x04B4           ## $a0 = 000004B4
/* 118BC 8094A58C 3C0543BE */  lui     $a1, 0x43BE                ## $a1 = 43BE0000
/* 118C0 8094A590 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 118C4 8094A594 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 118C8 8094A598 3C074000 */  lui     $a3, 0x4000                ## $a3 = 40000000
/* 118CC 8094A59C C6000064 */  lwc1    $f0, 0x0064($s0)           ## 00000064
/* 118D0 8094A5A0 3C013FC0 */  lui     $at, 0x3FC0                ## $at = 3FC00000
/* 118D4 8094A5A4 44814000 */  mtc1    $at, $f8                   ## $f8 = 1.50
/* 118D8 8094A5A8 46000005 */  abs.s   $f0, $f0                   
/* 118DC 8094A5AC 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 118E0 8094A5B0 46080282 */  mul.s   $f10, $f0, $f8             
/* 118E4 8094A5B4 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 118E8 8094A5B8 2604002C */  addiu   $a0, $s0, 0x002C           ## $a0 = 0000002C
/* 118EC 8094A5BC 8E0504B8 */  lw      $a1, 0x04B8($s0)           ## 000004B8
/* 118F0 8094A5C0 44075000 */  mfc1    $a3, $f10                  
/* 118F4 8094A5C4 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 118F8 8094A5C8 00000000 */  nop
/* 118FC 8094A5CC 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 11900 8094A5D0 44812000 */  mtc1    $at, $f4                   ## $f4 = 200.00
/* 11904 8094A5D4 C7B20028 */  lwc1    $f18, 0x0028($sp)          
/* 11908 8094A5D8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 1190C 8094A5DC 4604903C */  c.lt.s  $f18, $f4                  
/* 11910 8094A5E0 00000000 */  nop
/* 11914 8094A5E4 45020004 */  bc1fl   .L8094A5F8                 
/* 11918 8094A5E8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 1191C 8094A5EC 0C25254C */  jal     func_80949530              
/* 11920 8094A5F0 8FA50044 */  lw      $a1, 0x0044($sp)           
/* 11924 8094A5F4 8FBF001C */  lw      $ra, 0x001C($sp)           
.L8094A5F8:
/* 11928 8094A5F8 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 1192C 8094A5FC 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 11930 8094A600 03E00008 */  jr      $ra                        
/* 11934 8094A604 00000000 */  nop
