glabel BgHakaGate_Update
/* 00A24 8087C814 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00A28 8087C818 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00A2C 8087C81C AFA40018 */  sw      $a0, 0x0018($sp)           
/* 00A30 8087C820 8C990164 */  lw      $t9, 0x0164($a0)           ## 00000164
/* 00A34 8087C824 0320F809 */  jalr    $ra, $t9                   
/* 00A38 8087C828 00000000 */  nop
/* 00A3C 8087C82C 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 00A40 8087C830 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 00A44 8087C834 848E001C */  lh      $t6, 0x001C($a0)           ## 0000001C
/* 00A48 8087C838 55C10005 */  bnel    $t6, $at, .L8087C850       
/* 00A4C 8087C83C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00A50 8087C840 848F0172 */  lh      $t7, 0x0172($a0)           ## 00000172
/* 00A54 8087C844 25F80001 */  addiu   $t8, $t7, 0x0001           ## $t8 = 00000001
/* 00A58 8087C848 A4980172 */  sh      $t8, 0x0172($a0)           ## 00000172
/* 00A5C 8087C84C 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8087C850:
/* 00A60 8087C850 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00A64 8087C854 03E00008 */  jr      $ra                        
/* 00A68 8087C858 00000000 */  nop
