glabel func_8097E69C
/* 0102C 8097E69C 908E1D6C */  lbu     $t6, 0x1D6C($a0)           ## 00001D6C
/* 01030 8097E6A0 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 01034 8097E6A4 15C00003 */  bne     $t6, $zero, .L8097E6B4     
/* 01038 8097E6A8 00000000 */  nop
/* 0103C 8097E6AC 03E00008 */  jr      $ra                        
/* 01040 8097E6B0 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L8097E6B4:
/* 01044 8097E6B4 03E00008 */  jr      $ra                        
/* 01048 8097E6B8 00000000 */  nop
