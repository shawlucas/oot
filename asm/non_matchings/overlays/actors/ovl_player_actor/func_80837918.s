glabel func_80837918
/* 05708 80837918 000571C0 */  sll     $t6, $a1,  7               
/* 0570C 8083791C 008E1021 */  addu    $v0, $a0, $t6              
/* 05710 80837920 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 05714 80837924 14C10004 */  bne     $a2, $at, .L80837938       
/* 05718 80837928 AC4604FC */  sw      $a2, 0x04FC($v0)           ## 000004FC
/* 0571C 8083792C 240F0015 */  addiu   $t7, $zero, 0x0015         ## $t7 = 00000015
/* 05720 80837930 03E00008 */  jr      $ra                        
/* 05724 80837934 A04F0511 */  sb      $t7, 0x0511($v0)           ## 00000511
.L80837938:
/* 05728 80837938 24180005 */  addiu   $t8, $zero, 0x0005         ## $t8 = 00000005
/* 0572C 8083793C A0580511 */  sb      $t8, 0x0511($v0)           ## 00000511
/* 05730 80837940 03E00008 */  jr      $ra                        
/* 05734 80837944 00000000 */  nop
