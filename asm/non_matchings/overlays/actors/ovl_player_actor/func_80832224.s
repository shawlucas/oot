glabel func_80832224
/* 00014 80832224 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00018 80832228 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 0001C 8083222C 0C20C884 */  jal     Player_SetSpeedToZero              
/* 00020 80832230 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 00024 80832234 8FAE0018 */  lw      $t6, 0x0018($sp)           
/* 00028 80832238 A1C006AD */  sb      $zero, 0x06AD($t6)         ## 000006AD
/* 0002C 8083223C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00030 80832240 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00034 80832244 03E00008 */  jr      $ra                        
/* 00038 80832248 00000000 */  nop


