glabel func_809F799C
/* 015DC 809F799C 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 015E0 809F79A0 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 015E4 809F79A4 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 015E8 809F79A8 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 015EC 809F79AC 8C8E0004 */  lw      $t6, 0x0004($a0)           ## 00000004
/* 015F0 809F79B0 3C010100 */  lui     $at, 0x0100                ## $at = 01000000
/* 015F4 809F79B4 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 015F8 809F79B8 01C17825 */  or      $t7, $t6, $at              ## $t7 = 01000000
/* 015FC 809F79BC 0C00B61A */  jal     ActorPosition_SpeedSet              
/* 01600 809F79C0 AC8F0004 */  sw      $t7, 0x0004($a0)           ## 00000004
/* 01604 809F79C4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01608 809F79C8 0C27DA2C */  jal     func_809F68B0              
/* 0160C 809F79CC 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 01610 809F79D0 50400007 */  beql    $v0, $zero, .L809F79F0     
/* 01614 809F79D4 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01618 809F79D8 0C27DA65 */  jal     func_809F6994              
/* 0161C 809F79DC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01620 809F79E0 3C18809F */  lui     $t8, %hi(func_809F758C)    ## $t8 = 809F0000
/* 01624 809F79E4 2718758C */  addiu   $t8, $t8, %lo(func_809F758C) ## $t8 = 809F758C
/* 01628 809F79E8 AE180190 */  sw      $t8, 0x0190($s0)           ## 00000190
/* 0162C 809F79EC 8FBF001C */  lw      $ra, 0x001C($sp)           
.L809F79F0:
/* 01630 809F79F0 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 01634 809F79F4 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 01638 809F79F8 03E00008 */  jr      $ra                        
/* 0163C 809F79FC 00000000 */  nop
