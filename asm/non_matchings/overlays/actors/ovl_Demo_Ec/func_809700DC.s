.rdata
glabel D_8097071C
    .asciz "\x1B[31m Demo_Ec_main_init:初期化処理がおかしいarg_data = %d!\n\x1B[m"
    .balign 4

.text
glabel func_809700DC
/* 02C2C 809700DC 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 02C30 809700E0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02C34 809700E4 8486001C */  lh      $a2, 0x001C($a0)           ## 0000001C
/* 02C38 809700E8 3C028097 */  lui     $v0, %hi(D_809704B0)       ## $v0 = 80970000
/* 02C3C 809700EC 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 02C40 809700F0 00067080 */  sll     $t6, $a2,  2               
/* 02C44 809700F4 004E1021 */  addu    $v0, $v0, $t6              
/* 02C48 809700F8 8C4204B0 */  lw      $v0, %lo(D_809704B0)($v0)  
/* 02C4C 809700FC 3C048097 */  lui     $a0, %hi(D_8097071C)       ## $a0 = 80970000
/* 02C50 80970100 2484071C */  addiu   $a0, $a0, %lo(D_8097071C)  ## $a0 = 8097071C
/* 02C54 80970104 14400008 */  bne     $v0, $zero, .L80970128     
/* 02C58 80970108 00000000 */  nop
/* 02C5C 8097010C 00C02825 */  or      $a1, $a2, $zero            ## $a1 = 00000000
/* 02C60 80970110 0C00084C */  jal     osSyncPrintf
              
/* 02C64 80970114 AFA70018 */  sw      $a3, 0x0018($sp)           
/* 02C68 80970118 0C00B55C */  jal     Actor_Kill
              
/* 02C6C 8097011C 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 02C70 80970120 10000004 */  beq     $zero, $zero, .L80970134   
/* 02C74 80970124 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80970128:
/* 02C78 80970128 0040F809 */  jalr    $ra, $v0                   
/* 02C7C 8097012C 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 02C80 80970130 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80970134:
/* 02C84 80970134 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 02C88 80970138 03E00008 */  jr      $ra                        
/* 02C8C 8097013C 00000000 */  nop


