glabel func_80919278
/* 03868 80919278 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 0386C 8091927C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 03870 80919280 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 03874 80919284 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 03878 80919288 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 0387C 8091928C 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 03880 80919290 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 03884 80919294 260400B4 */  addiu   $a0, $s0, 0x00B4           ## $a0 = 000000B4
/* 03888 80919298 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 0388C 8091929C 24060002 */  addiu   $a2, $zero, 0x0002         ## $a2 = 00000002
/* 03890 809192A0 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 03894 809192A4 24070BB8 */  addiu   $a3, $zero, 0x0BB8         ## $a3 = 00000BB8
/* 03898 809192A8 8FAE0024 */  lw      $t6, 0x0024($sp)           
/* 0389C 809192AC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 038A0 809192B0 0C00B69E */  jal     ActorSearch_AngleY              
/* 038A4 809192B4 8DC51C44 */  lw      $a1, 0x1C44($t6)           ## 00001C44
/* 038A8 809192B8 00022C00 */  sll     $a1, $v0, 16               
/* 038AC 809192BC 00052C03 */  sra     $a1, $a1, 16               
/* 038B0 809192C0 26040032 */  addiu   $a0, $s0, 0x0032           ## $a0 = 00000032
/* 038B4 809192C4 24060002 */  addiu   $a2, $zero, 0x0002         ## $a2 = 00000002
/* 038B8 809192C8 0C01E1EF */  jal     Math_SmoothScaleMaxS
              
/* 038BC 809192CC 240707D0 */  addiu   $a3, $zero, 0x07D0         ## $a3 = 000007D0
/* 038C0 809192D0 960F0088 */  lhu     $t7, 0x0088($s0)           ## 00000088
/* 038C4 809192D4 31F80001 */  andi    $t8, $t7, 0x0001           ## $t8 = 00000000
/* 038C8 809192D8 53000010 */  beql    $t8, $zero, .L8091931C     
/* 038CC 809192DC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 038D0 809192E0 0C24594C */  jal     func_80916530              
/* 038D4 809192E4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 038D8 809192E8 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 038DC 809192EC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 038E0 809192F0 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 038E4 809192F4 E6040060 */  swc1    $f4, 0x0060($s0)           ## 00000060
/* 038E8 809192F8 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 038EC 809192FC 0C24577E */  jal     func_80915DF8              
/* 038F0 80919300 24070008 */  addiu   $a3, $zero, 0x0008         ## $a3 = 00000008
/* 038F4 80919304 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 038F8 80919308 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 038FC 8091930C 24060005 */  addiu   $a2, $zero, 0x0005         ## $a2 = 00000005
/* 03900 80919310 0C00CFA2 */  jal     func_80033E88              
/* 03904 80919314 2407000F */  addiu   $a3, $zero, 0x000F         ## $a3 = 0000000F
/* 03908 80919318 8FBF001C */  lw      $ra, 0x001C($sp)           
.L8091931C:
/* 0390C 8091931C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 03910 80919320 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 03914 80919324 03E00008 */  jr      $ra                        
/* 03918 80919328 00000000 */  nop
