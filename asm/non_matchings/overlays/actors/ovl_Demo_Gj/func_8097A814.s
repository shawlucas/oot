glabel func_8097A814
/* 01EE4 8097A814 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 01EE8 8097A818 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 01EEC 8097A81C AFA5001C */  sw      $a1, 0x001C($sp)           
/* 01EF0 8097A820 0C00B638 */  jal     Actor_MoveForward
              
/* 01EF4 8097A824 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 01EF8 8097A828 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 01EFC 8097A82C 2442FA90 */  addiu   $v0, $v0, 0xFA90           ## $v0 = 8015FA90
/* 01F00 8097A830 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 01F04 8097A834 8C4F0000 */  lw      $t7, 0x0000($v0)           ## 8015FA90
/* 01F08 8097A838 848E016C */  lh      $t6, 0x016C($a0)           ## 0000016C
/* 01F0C 8097A83C 85F814E0 */  lh      $t8, 0x14E0($t7)           ## 000014E0
/* 01F10 8097A840 8488016E */  lh      $t0, 0x016E($a0)           ## 0000016E
/* 01F14 8097A844 01D8C821 */  addu    $t9, $t6, $t8              
/* 01F18 8097A848 A499016C */  sh      $t9, 0x016C($a0)           ## 0000016C
/* 01F1C 8097A84C 8C490000 */  lw      $t1, 0x0000($v0)           ## 8015FA90
/* 01F20 8097A850 848E0170 */  lh      $t6, 0x0170($a0)           ## 00000170
/* 01F24 8097A854 852A14E2 */  lh      $t2, 0x14E2($t1)           ## 000014E2
/* 01F28 8097A858 254D03E8 */  addiu   $t5, $t2, 0x03E8           ## $t5 = 000003E8
/* 01F2C 8097A85C 010D7821 */  addu    $t7, $t0, $t5              
/* 01F30 8097A860 A48F016E */  sh      $t7, 0x016E($a0)           ## 0000016E
/* 01F34 8097A864 8C580000 */  lw      $t8, 0x0000($v0)           ## 8015FA90
/* 01F38 8097A868 871914E4 */  lh      $t9, 0x14E4($t8)           ## 000014E4
/* 01F3C 8097A86C 272B0BB8 */  addiu   $t3, $t9, 0x0BB8           ## $t3 = 00000BB8
/* 01F40 8097A870 01CB6021 */  addu    $t4, $t6, $t3              
/* 01F44 8097A874 A48C0170 */  sh      $t4, 0x0170($a0)           ## 00000170
/* 01F48 8097A878 0C25E48F */  jal     func_8097923C              
/* 01F4C 8097A87C 8FA5001C */  lw      $a1, 0x001C($sp)           
/* 01F50 8097A880 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 01F54 8097A884 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 01F58 8097A888 03E00008 */  jr      $ra                        
/* 01F5C 8097A88C 00000000 */  nop
