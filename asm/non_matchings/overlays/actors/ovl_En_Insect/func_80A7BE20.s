glabel func_80A7BE20
/* 00000 80A7BE20 848E001C */  lh      $t6, 0x001C($a0)           ## 0000001C
/* 00004 80A7BE24 3C1980A8 */  lui     $t9, %hi(D_80A7DF10)       ## $t9 = 80A80000
/* 00008 80A7BE28 31CF0003 */  andi    $t7, $t6, 0x0003           ## $t7 = 00000000
/* 0000C 80A7BE2C 000FC040 */  sll     $t8, $t7,  1               
/* 00010 80A7BE30 0338C821 */  addu    $t9, $t9, $t8              
/* 00014 80A7BE34 9739DF10 */  lhu     $t9, %lo(D_80A7DF10)($t9)  
/* 00018 80A7BE38 03E00008 */  jr      $ra                        
/* 0001C 80A7BE3C A4990314 */  sh      $t9, 0x0314($a0)           ## 00000314
