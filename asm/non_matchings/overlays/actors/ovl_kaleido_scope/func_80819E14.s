glabel func_80819E14
/* 065F4 80819E14 AFA50004 */  sw      $a1, 0x0004($sp)           
/* 065F8 80819E18 30A5FFFF */  andi    $a1, $a1, 0xFFFF           ## $a1 = 00000000
/* 065FC 80819E1C 00057100 */  sll     $t6, $a1,  4               
/* 06600 80819E20 00CE1021 */  addu    $v0, $a2, $t6              
/* 06604 80819E24 844F0000 */  lh      $t7, 0x0000($v0)           ## 00000000
/* 06608 80819E28 8C980168 */  lw      $t8, 0x0168($a0)           ## 00000168
/* 0660C 80819E2C A70F0000 */  sh      $t7, 0x0000($t8)           ## 00000000
/* 06610 80819E30 8C880168 */  lw      $t0, 0x0168($a0)           ## 00000168
/* 06614 80819E34 84590002 */  lh      $t9, 0x0002($v0)           ## 00000002
/* 06618 80819E38 03E00008 */  jr      $ra                        
/* 0661C 80819E3C A5190002 */  sh      $t9, 0x0002($t0)           ## 00000002
