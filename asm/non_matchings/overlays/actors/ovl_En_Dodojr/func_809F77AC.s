.late_rodata
glabel D_809F7F90
    .float 1.2

.text
glabel func_809F77AC
/* 013EC 809F77AC 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 013F0 809F77B0 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 013F4 809F77B4 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 013F8 809F77B8 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 013FC 809F77BC 908E0114 */  lbu     $t6, 0x0114($a0)           ## 00000114
/* 01400 809F77C0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01404 809F77C4 3C014F80 */  lui     $at, 0x4F80                ## $at = 4F800000
/* 01408 809F77C8 448E2000 */  mtc1    $t6, $f4                   ## $f4 = 0.00
/* 0140C 809F77CC 05C10004 */  bgez    $t6, .L809F77E0            
/* 01410 809F77D0 468021A0 */  cvt.s.w $f6, $f4                   
/* 01414 809F77D4 44814000 */  mtc1    $at, $f8                   ## $f8 = 4294967296.00
/* 01418 809F77D8 00000000 */  nop
/* 0141C 809F77DC 46083180 */  add.s   $f6, $f6, $f8              
.L809F77E0:
/* 01420 809F77E0 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 01424 809F77E4 44815000 */  mtc1    $at, $f10                  ## $f10 = 8.00
/* 01428 809F77E8 3C01809F */  lui     $at, %hi(D_809F7F90)       ## $at = 809F0000
/* 0142C 809F77EC C4327F90 */  lwc1    $f18, %lo(D_809F7F90)($at) 
/* 01430 809F77F0 460A3403 */  div.s   $f16, $f6, $f10            
/* 01434 809F77F4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01438 809F77F8 46109102 */  mul.s   $f4, $f18, $f16            
/* 0143C 809F77FC 0C00B61A */  jal     func_8002D868              
/* 01440 809F7800 E6040208 */  swc1    $f4, 0x0208($s0)           ## 00000208
/* 01444 809F7804 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01448 809F7808 0C27DA2C */  jal     func_809F68B0              
/* 0144C 809F780C 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 01450 809F7810 10400009 */  beq     $v0, $zero, .L809F7838     
/* 01454 809F7814 240F003C */  addiu   $t7, $zero, 0x003C         ## $t7 = 0000003C
/* 01458 809F7818 A60F0202 */  sh      $t7, 0x0202($s0)           ## 00000202
/* 0145C 809F781C 0C27DAB1 */  jal     func_809F6AC4              
/* 01460 809F7820 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01464 809F7824 3C19809F */  lui     $t9, %hi(func_809F784C)    ## $t9 = 809F0000
/* 01468 809F7828 24180007 */  addiu   $t8, $zero, 0x0007         ## $t8 = 00000007
/* 0146C 809F782C 2739784C */  addiu   $t9, $t9, %lo(func_809F784C) ## $t9 = 809F784C
/* 01470 809F7830 A61801FC */  sh      $t8, 0x01FC($s0)           ## 000001FC
/* 01474 809F7834 AE190190 */  sw      $t9, 0x0190($s0)           ## 00000190
.L809F7838:
/* 01478 809F7838 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 0147C 809F783C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 01480 809F7840 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 01484 809F7844 03E00008 */  jr      $ra                        
/* 01488 809F7848 00000000 */  nop
