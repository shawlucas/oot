glabel func_80832F54
/* 00D44 80832F54 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00D48 80832F58 30CE0200 */  andi    $t6, $a2, 0x0200           ## $t6 = 00000000
/* 00D4C 80832F5C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00D50 80832F60 11C00008 */  beq     $t6, $zero, .L80832F84     
/* 00D54 80832F64 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 00D58 80832F68 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00D5C 80832F6C AFA5001C */  sw      $a1, 0x001C($sp)           
/* 00D60 80832F70 0C20CB48 */  jal     func_80832D20              
/* 00D64 80832F74 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 00D68 80832F78 8FA5001C */  lw      $a1, 0x001C($sp)           
/* 00D6C 80832F7C 10000016 */  beq     $zero, $zero, .L80832FD8   
/* 00D70 80832F80 8FA60020 */  lw      $a2, 0x0020($sp)           
.L80832F84:
/* 00D74 80832F84 30CF0100 */  andi    $t7, $a2, 0x0100           ## $t7 = 00000000
/* 00D78 80832F88 15E00004 */  bne     $t7, $zero, .L80832F9C     
/* 00D7C 80832F8C 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00D80 80832F90 90B801E9 */  lbu     $t8, 0x01E9($a1)           ## 000001E9
/* 00D84 80832F94 53000008 */  beql    $t8, $zero, .L80832FB8     
/* 00D88 80832F98 8CB901D4 */  lw      $t9, 0x01D4($a1)           ## 000001D4
.L80832F9C:
/* 00D8C 80832F9C AFA5001C */  sw      $a1, 0x001C($sp)           
/* 00D90 80832FA0 0C20CB3F */  jal     func_80832CFC              
/* 00D94 80832FA4 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 00D98 80832FA8 8FA5001C */  lw      $a1, 0x001C($sp)           
/* 00D9C 80832FAC 1000000A */  beq     $zero, $zero, .L80832FD8   
/* 00DA0 80832FB0 8FA60020 */  lw      $a2, 0x0020($sp)           
/* 00DA4 80832FB4 8CB901D4 */  lw      $t9, 0x01D4($a1)           ## 000001D4
.L80832FB8:
/* 00DA8 80832FB8 84AA00B6 */  lh      $t2, 0x00B6($a1)           ## 000000B6
/* 00DAC 80832FBC 8B290000 */  lwl     $t1, 0x0000($t9)           ## 00000000
/* 00DB0 80832FC0 9B290003 */  lwr     $t1, 0x0003($t9)           ## 00000003
/* 00DB4 80832FC4 A8A901EC */  swl     $t1, 0x01EC($a1)           ## 000001EC
/* 00DB8 80832FC8 B8A901EF */  swr     $t1, 0x01EF($a1)           ## 000001EF
/* 00DBC 80832FCC 97290004 */  lhu     $t1, 0x0004($t9)           ## 00000004
/* 00DC0 80832FD0 A4AA01EA */  sh      $t2, 0x01EA($a1)           ## 000001EA
/* 00DC4 80832FD4 A4A901F0 */  sh      $t1, 0x01F0($a1)           ## 000001F0
.L80832FD8:
/* 00DC8 80832FD8 A0A601E9 */  sb      $a2, 0x01E9($a1)           ## 000001E9
/* 00DCC 80832FDC 0C20C884 */  jal     Player_SetSpeedToZero              
/* 00DD0 80832FE0 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00DD4 80832FE4 0C028CC4 */  jal     func_800A3310              
/* 00DD8 80832FE8 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 00DDC 80832FEC 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00DE0 80832FF0 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00DE4 80832FF4 03E00008 */  jr      $ra                        
/* 00DE8 80832FF8 00000000 */  nop


