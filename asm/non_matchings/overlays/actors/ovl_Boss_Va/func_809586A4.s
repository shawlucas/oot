glabel func_809586A4
/* 093E4 809586A4 AFA40000 */  sw      $a0, 0x0000($sp)           
/* 093E8 809586A8 8FA40014 */  lw      $a0, 0x0014($sp)           
/* 093EC 809586AC AFA60008 */  sw      $a2, 0x0008($sp)           
/* 093F0 809586B0 AFA7000C */  sw      $a3, 0x000C($sp)           
/* 093F4 809586B4 908E0194 */  lbu     $t6, 0x0194($a0)           ## 00000194
/* 093F8 809586B8 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 093FC 809586BC 15C00007 */  bne     $t6, $zero, .L809586DC     
/* 09400 809586C0 00000000 */  nop
/* 09404 809586C4 14A10005 */  bne     $a1, $at, .L809586DC       
/* 09408 809586C8 8FA20010 */  lw      $v0, 0x0010($sp)           
/* 0940C 809586CC 844F0004 */  lh      $t7, 0x0004($v0)           ## 00000004
/* 09410 809586D0 849801F6 */  lh      $t8, 0x01F6($a0)           ## 000001F6
/* 09414 809586D4 01F8C821 */  addu    $t9, $t7, $t8              
/* 09418 809586D8 A4590004 */  sh      $t9, 0x0004($v0)           ## 00000004
.L809586DC:
/* 0941C 809586DC 03E00008 */  jr      $ra                        
/* 09420 809586E0 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
