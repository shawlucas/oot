glabel func_80983374
/* 00074 80983374 908E1D6C */  lbu     $t6, 0x1D6C($a0)           ## 00001D6C
/* 00078 80983378 00057880 */  sll     $t7, $a1,  2               
/* 0007C 8098337C 008FC021 */  addu    $t8, $a0, $t7              
/* 00080 80983380 11C00003 */  beq     $t6, $zero, .L80983390     
/* 00084 80983384 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 00088 80983388 03E00008 */  jr      $ra                        
/* 0008C 8098338C 8F021D8C */  lw      $v0, 0x1D8C($t8)           ## 00001D8C
.L80983390:
/* 00090 80983390 03E00008 */  jr      $ra                        
/* 00094 80983394 00000000 */  nop
