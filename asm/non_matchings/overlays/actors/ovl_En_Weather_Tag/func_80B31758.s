glabel func_80B31758
/* 00738 80B31758 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 0073C 80B3175C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00740 80B31760 240E0002 */  addiu   $t6, $zero, 0x0002         ## $t6 = 00000002
/* 00744 80B31764 240F0064 */  addiu   $t7, $zero, 0x0064         ## $t7 = 00000064
/* 00748 80B31768 AFA40028 */  sw      $a0, 0x0028($sp)           
/* 0074C 80B3176C AFAF0018 */  sw      $t7, 0x0018($sp)           
/* 00750 80B31770 AFAE0010 */  sw      $t6, 0x0010($sp)           
/* 00754 80B31774 AFA00014 */  sw      $zero, 0x0014($sp)         
/* 00758 80B31778 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 0075C 80B3177C 0C2CC527 */  jal     func_80B3149C              
/* 00760 80B31780 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 00764 80B31784 10400004 */  beq     $v0, $zero, .L80B31798     
/* 00768 80B31788 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 0076C 80B3178C 3C0580B3 */  lui     $a1, %hi(func_80B31700)    ## $a1 = 80B30000
/* 00770 80B31790 0C2CC408 */  jal     func_80B31020              
/* 00774 80B31794 24A51700 */  addiu   $a1, $a1, %lo(func_80B31700) ## $a1 = 80B31700
.L80B31798:
/* 00778 80B31798 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 0077C 80B3179C 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00780 80B317A0 03E00008 */  jr      $ra                        
/* 00784 80B317A4 00000000 */  nop
