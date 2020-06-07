.late_rodata
glabel D_8095C924
    .float 0.3

glabel D_8095C928
    .float 0.01

.text
glabel func_8095B670
/* 0C3B0 8095B670 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 0C3B4 8095B674 3C0F8096 */  lui     $t7, %hi(D_8095C350)       ## $t7 = 80960000
/* 0C3B8 8095B678 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0C3BC 8095B67C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 0C3C0 8095B680 AFA40040 */  sw      $a0, 0x0040($sp)           
/* 0C3C4 8095B684 AFA7004C */  sw      $a3, 0x004C($sp)           
/* 0C3C8 8095B688 25EFC350 */  addiu   $t7, $t7, %lo(D_8095C350)  ## $t7 = 8095C350
/* 0C3CC 8095B68C 8DF90000 */  lw      $t9, 0x0000($t7)           ## 8095C350
/* 0C3D0 8095B690 27AE002C */  addiu   $t6, $sp, 0x002C           ## $t6 = FFFFFFEC
/* 0C3D4 8095B694 8DF80004 */  lw      $t8, 0x0004($t7)           ## 8095C354
/* 0C3D8 8095B698 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFEC
/* 0C3DC 8095B69C 8DF90008 */  lw      $t9, 0x0008($t7)           ## 8095C358
/* 0C3E0 8095B6A0 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 0C3E4 8095B6A4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 0C3E8 8095B6A8 24030190 */  addiu   $v1, $zero, 0x0190         ## $v1 = 00000190
/* 0C3EC 8095B6AC ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFF0
/* 0C3F0 8095B6B0 ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFF4
.L8095B6B4:
/* 0C3F4 8095B6B4 92080024 */  lbu     $t0, 0x0024($s0)           ## 00000024
/* 0C3F8 8095B6B8 24420001 */  addiu   $v0, $v0, 0x0001           ## $v0 = 00000001
/* 0C3FC 8095B6BC 1500004C */  bne     $t0, $zero, .L8095B7F0     
/* 0C400 8095B6C0 24090006 */  addiu   $t1, $zero, 0x0006         ## $t1 = 00000006
/* 0C404 8095B6C4 A2090024 */  sb      $t1, 0x0024($s0)           ## 00000024
/* 0C408 8095B6C8 8CCB0000 */  lw      $t3, 0x0000($a2)           ## 00000000
/* 0C40C 8095B6CC 240C0001 */  addiu   $t4, $zero, 0x0001         ## $t4 = 00000001
/* 0C410 8095B6D0 AE0B0000 */  sw      $t3, 0x0000($s0)           ## 00000000
/* 0C414 8095B6D4 8CCA0004 */  lw      $t2, 0x0004($a2)           ## 00000004
/* 0C418 8095B6D8 AE0A0004 */  sw      $t2, 0x0004($s0)           ## 00000004
/* 0C41C 8095B6DC 8CCB0008 */  lw      $t3, 0x0008($a2)           ## 00000008
/* 0C420 8095B6E0 A60C0028 */  sh      $t4, 0x0028($s0)           ## 00000028
/* 0C424 8095B6E4 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 0C428 8095B6E8 AE0B0008 */  sw      $t3, 0x0008($s0)           ## 00000008
/* 0C42C 8095B6EC 3C0140E0 */  lui     $at, 0x40E0                ## $at = 40E00000
/* 0C430 8095B6F0 44812000 */  mtc1    $at, $f4                   ## $f4 = 7.00
/* 0C434 8095B6F4 87A4004E */  lh      $a0, 0x004E($sp)           
/* 0C438 8095B6F8 46040182 */  mul.s   $f6, $f0, $f4              
/* 0C43C 8095B6FC 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0C440 8095B700 E7A60038 */  swc1    $f6, 0x0038($sp)           
/* 0C444 8095B704 C7A80038 */  lwc1    $f8, 0x0038($sp)           
/* 0C448 8095B708 3C014080 */  lui     $at, 0x4080                ## $at = 40800000
/* 0C44C 8095B70C 44816000 */  mtc1    $at, $f12                  ## $f12 = 4.00
/* 0C450 8095B710 46080282 */  mul.s   $f10, $f0, $f8             
/* 0C454 8095B714 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 0C458 8095B718 E7AA0020 */  swc1    $f10, 0x0020($sp)          
/* 0C45C 8095B71C 3C014080 */  lui     $at, 0x4080                ## $at = 40800000
/* 0C460 8095B720 44818000 */  mtc1    $at, $f16                  ## $f16 = 4.00
/* 0C464 8095B724 87A4004E */  lh      $a0, 0x004E($sp)           
/* 0C468 8095B728 46100480 */  add.s   $f18, $f0, $f16            
/* 0C46C 8095B72C 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 0C470 8095B730 E7B20024 */  swc1    $f18, 0x0024($sp)          
/* 0C474 8095B734 C7A40038 */  lwc1    $f4, 0x0038($sp)           
/* 0C478 8095B738 27AD0020 */  addiu   $t5, $sp, 0x0020           ## $t5 = FFFFFFE0
/* 0C47C 8095B73C 3C018096 */  lui     $at, %hi(D_8095C924)       ## $at = 80960000
/* 0C480 8095B740 46040182 */  mul.s   $f6, $f0, $f4              
/* 0C484 8095B744 E7A60028 */  swc1    $f6, 0x0028($sp)           
/* 0C488 8095B748 8DAF0000 */  lw      $t7, 0x0000($t5)           ## FFFFFFE0
/* 0C48C 8095B74C AE0F000C */  sw      $t7, 0x000C($s0)           ## 0000000C
/* 0C490 8095B750 8DAE0004 */  lw      $t6, 0x0004($t5)           ## FFFFFFE4
/* 0C494 8095B754 AE0E0010 */  sw      $t6, 0x0010($s0)           ## 00000010
/* 0C498 8095B758 8DAF0008 */  lw      $t7, 0x0008($t5)           ## FFFFFFE8
/* 0C49C 8095B75C AE0F0014 */  sw      $t7, 0x0014($s0)           ## 00000014
/* 0C4A0 8095B760 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 0C4A4 8095B764 C42CC924 */  lwc1    $f12, %lo(D_8095C924)($at) 
/* 0C4A8 8095B768 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 0C4AC 8095B76C 44814000 */  mtc1    $at, $f8                   ## $f8 = 1.00
/* 0C4B0 8095B770 27B8002C */  addiu   $t8, $sp, 0x002C           ## $t8 = FFFFFFEC
/* 0C4B4 8095B774 3C098096 */  lui     $t1, %hi(D_809668D2)       ## $t1 = 80960000
/* 0C4B8 8095B778 46080281 */  sub.s   $f10, $f0, $f8             
/* 0C4BC 8095B77C 240A0014 */  addiu   $t2, $zero, 0x0014         ## $t2 = 00000014
/* 0C4C0 8095B780 240B003C */  addiu   $t3, $zero, 0x003C         ## $t3 = 0000003C
/* 0C4C4 8095B784 240C0064 */  addiu   $t4, $zero, 0x0064         ## $t4 = 00000064
/* 0C4C8 8095B788 E7AA0030 */  swc1    $f10, 0x0030($sp)          
/* 0C4CC 8095B78C 8F080000 */  lw      $t0, 0x0000($t8)           ## FFFFFFEC
/* 0C4D0 8095B790 240D00C8 */  addiu   $t5, $zero, 0x00C8         ## $t5 = 000000C8
/* 0C4D4 8095B794 AE080018 */  sw      $t0, 0x0018($s0)           ## 00000018
/* 0C4D8 8095B798 8F190004 */  lw      $t9, 0x0004($t8)           ## FFFFFFF0
/* 0C4DC 8095B79C AE19001C */  sw      $t9, 0x001C($s0)           ## 0000001C
/* 0C4E0 8095B7A0 8F080008 */  lw      $t0, 0x0008($t8)           ## FFFFFFF4
/* 0C4E4 8095B7A4 AE080020 */  sw      $t0, 0x0020($s0)           ## 00000020
/* 0C4E8 8095B7A8 812968D2 */  lb      $t1, %lo(D_809668D2)($t1)  
/* 0C4EC 8095B7AC 29210014 */  slti    $at, $t1, 0x0014           
/* 0C4F0 8095B7B0 50200004 */  beql    $at, $zero, .L8095B7C4     
/* 0C4F4 8095B7B4 A60B0026 */  sh      $t3, 0x0026($s0)           ## 00000026
/* 0C4F8 8095B7B8 10000002 */  beq     $zero, $zero, .L8095B7C4   
/* 0C4FC 8095B7BC A60A0026 */  sh      $t2, 0x0026($s0)           ## 00000026
/* 0C500 8095B7C0 A60B0026 */  sh      $t3, 0x0026($s0)           ## 00000026
.L8095B7C4:
/* 0C504 8095B7C4 A60C003E */  sh      $t4, 0x003E($s0)           ## 0000003E
/* 0C508 8095B7C8 A60D0036 */  sh      $t5, 0x0036($s0)           ## 00000036
/* 0C50C 8095B7CC 87AE0052 */  lh      $t6, 0x0052($sp)           
/* 0C510 8095B7D0 3C018096 */  lui     $at, %hi(D_8095C928)       ## $at = 80960000
/* 0C514 8095B7D4 C424C928 */  lwc1    $f4, %lo(D_8095C928)($at)  
/* 0C518 8095B7D8 448E8000 */  mtc1    $t6, $f16                  ## $f16 = 0.00
/* 0C51C 8095B7DC 00000000 */  nop
/* 0C520 8095B7E0 468084A0 */  cvt.s.w $f18, $f16                 
/* 0C524 8095B7E4 46049182 */  mul.s   $f6, $f18, $f4             
/* 0C528 8095B7E8 10000003 */  beq     $zero, $zero, .L8095B7F8   
/* 0C52C 8095B7EC E6060040 */  swc1    $f6, 0x0040($s0)           ## 00000040
.L8095B7F0:
/* 0C530 8095B7F0 1443FFB0 */  bne     $v0, $v1, .L8095B6B4       
/* 0C534 8095B7F4 26100058 */  addiu   $s0, $s0, 0x0058           ## $s0 = 00000058
.L8095B7F8:
/* 0C538 8095B7F8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 0C53C 8095B7FC 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 0C540 8095B800 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 0C544 8095B804 03E00008 */  jr      $ra                        
/* 0C548 8095B808 00000000 */  nop
