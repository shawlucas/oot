glabel func_8097009C
/* 02BEC 8097009C 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 02BF0 809700A0 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 02BF4 809700A4 84820190 */  lh      $v0, 0x0190($a0)           ## 00000190
/* 02BF8 809700A8 3C068097 */  lui     $a2, %hi(D_809704A4)       ## $a2 = 80970000
/* 02BFC 809700AC 3C070600 */  lui     $a3, 0x0600                ## $a3 = 06000000
/* 02C00 809700B0 00027080 */  sll     $t6, $v0,  2               
/* 02C04 809700B4 00CE3021 */  addu    $a2, $a2, $t6              
/* 02C08 809700B8 8CC604A4 */  lw      $a2, %lo(D_809704A4)($a2)  
/* 02C0C 809700BC 24E73770 */  addiu   $a3, $a3, 0x3770           ## $a3 = 06003770
/* 02C10 809700C0 AFA00014 */  sw      $zero, 0x0014($sp)         
/* 02C14 809700C4 0C25B631 */  jal     func_8096D8C4              
/* 02C18 809700C8 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 02C1C 809700CC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 02C20 809700D0 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 02C24 809700D4 03E00008 */  jr      $ra                        
/* 02C28 809700D8 00000000 */  nop
