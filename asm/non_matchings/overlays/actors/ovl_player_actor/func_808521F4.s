glabel func_808521F4
/* 1FFE4 808521F4 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 1FFE8 808521F8 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 1FFEC 808521FC AFA60020 */  sw      $a2, 0x0020($sp)           
/* 1FFF0 80852200 90AE015B */  lbu     $t6, 0x015B($a1)           ## 0000015B
/* 1FFF4 80852204 3C068085 */  lui     $a2, %hi(D_80853D34)       ## $a2 = 80850000
/* 1FFF8 80852208 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 1FFFC 8085220C 000E7880 */  sll     $t7, $t6,  2               
/* 20000 80852210 00CF3021 */  addu    $a2, $a2, $t7              
/* 20004 80852214 0C20CAC3 */  jal     func_80832B0C              
/* 20008 80852218 8CC63D34 */  lw      $a2, %lo(D_80853D34)($a2)  
/* 2000C 8085221C 0C20C884 */  jal     Player_SetSpeedToZero              
/* 20010 80852220 8FA4001C */  lw      $a0, 0x001C($sp)           
/* 20014 80852224 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 20018 80852228 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 2001C 8085222C 03E00008 */  jr      $ra                        
/* 20020 80852230 00000000 */  nop


