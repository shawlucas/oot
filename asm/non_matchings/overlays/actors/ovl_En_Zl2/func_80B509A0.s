glabel func_80B509A0
/* 02010 80B509A0 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 02014 80B509A4 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 02018 80B509A8 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 0201C 80B509AC AFA5001C */  sw      $a1, 0x001C($sp)           
/* 02020 80B509B0 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 02024 80B509B4 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 02028 80B509B8 0C2D3B65 */  jal     func_80B4ED94              
/* 0202C 80B509BC AFA60018 */  sw      $a2, 0x0018($sp)           
/* 02030 80B509C0 1040000C */  beq     $v0, $zero, .L80B509F4     
/* 02034 80B509C4 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 02038 80B509C8 8FAE001C */  lw      $t6, 0x001C($sp)           
/* 0203C 80B509CC 94580004 */  lhu     $t8, 0x0004($v0)           ## 00000004
/* 02040 80B509D0 24190018 */  addiu   $t9, $zero, 0x0018         ## $t9 = 00000018
/* 02044 80B509D4 95CF1D74 */  lhu     $t7, 0x1D74($t6)           ## 00001D74
/* 02048 80B509D8 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 0204C 80B509DC 01F8082A */  slt     $at, $t7, $t8              
/* 02050 80B509E0 54200005 */  bnel    $at, $zero, .L80B509F8     
/* 02054 80B509E4 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 02058 80B509E8 ACD9019C */  sw      $t9, 0x019C($a2)           ## 0000019C
/* 0205C 80B509EC 0C2D3F9B */  jal     func_80B4FE6C              
/* 02060 80B509F0 ACC001A0 */  sw      $zero, 0x01A0($a2)         ## 000001A0
.L80B509F4:
/* 02064 80B509F4 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80B509F8:
/* 02068 80B509F8 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 0206C 80B509FC 03E00008 */  jr      $ra                        
/* 02070 80B50A00 00000000 */  nop
