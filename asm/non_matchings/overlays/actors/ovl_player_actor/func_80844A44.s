glabel func_80844A44
/* 12834 80844A44 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 12838 80844A48 AFBF002C */  sw      $ra, 0x002C($sp)           
/* 1283C 80844A4C AFB00028 */  sw      $s0, 0x0028($sp)           
/* 12840 80844A50 AFA50034 */  sw      $a1, 0x0034($sp)           
/* 12844 80844A54 8C8E0680 */  lw      $t6, 0x0680($a0)           ## 00000680
/* 12848 80844A58 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 1284C 80844A5C 260501B4 */  addiu   $a1, $s0, 0x01B4           ## $a1 = 000001B4
/* 12850 80844A60 35CF0020 */  ori     $t7, $t6, 0x0020           ## $t7 = 00000020
/* 12854 80844A64 AC8F0680 */  sw      $t7, 0x0680($a0)           ## 00000680
/* 12858 80844A68 0C028EF0 */  jal     func_800A3BC0              
/* 1285C 80844A6C 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 12860 80844A70 10400005 */  beq     $v0, $zero, .L80844A88     
/* 12864 80844A74 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 12868 80844A78 3C060400 */  lui     $a2, 0x0400                ## $a2 = 04000000
/* 1286C 80844A7C 24C63160 */  addiu   $a2, $a2, 0x3160           ## $a2 = 04003160
/* 12870 80844A80 0C20C8A1 */  jal     func_80832284              
/* 12874 80844A84 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
.L80844A88:
/* 12878 80844A88 3C063D4C */  lui     $a2, 0x3D4C                ## $a2 = 3D4C0000
/* 1287C 80844A8C 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3D4CCCCD
/* 12880 80844A90 26040838 */  addiu   $a0, $s0, 0x0838           ## $a0 = 00000838
/* 12884 80844A94 0C01DE80 */  jal     Math_ApproxF
              
/* 12888 80844A98 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 1288C 80844A9C 96180088 */  lhu     $t8, 0x0088($s0)           ## 00000088
/* 12890 80844AA0 24080010 */  addiu   $t0, $zero, 0x0010         ## $t0 = 00000010
/* 12894 80844AA4 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 12898 80844AA8 33190001 */  andi    $t9, $t8, 0x0001           ## $t9 = 00000000
/* 1289C 80844AAC 1320000C */  beq     $t9, $zero, .L80844AE0     
/* 128A0 80844AB0 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 128A4 80844AB4 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 128A8 80844AB8 44812000 */  mtc1    $at, $f4                   ## $f4 = 5.00
/* 128AC 80844ABC A20800B0 */  sb      $t0, 0x00B0($s0)           ## 000000B0
/* 128B0 80844AC0 240A0014 */  addiu   $t2, $zero, 0x0014         ## $t2 = 00000014
/* 128B4 80844AC4 E7A40010 */  swc1    $f4, 0x0010($sp)           
/* 128B8 80844AC8 860900B6 */  lh      $t1, 0x00B6($s0)           ## 000000B6
/* 128BC 80844ACC AFAA0018 */  sw      $t2, 0x0018($sp)           
/* 128C0 80844AD0 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 128C4 80844AD4 3C074080 */  lui     $a3, 0x4080                ## $a3 = 40800000
/* 128C8 80844AD8 0C20DF03 */  jal     func_80837C0C              
/* 128CC 80844ADC AFA90014 */  sw      $t1, 0x0014($sp)           
.L80844AE0:
/* 128D0 80844AE0 8FBF002C */  lw      $ra, 0x002C($sp)           
/* 128D4 80844AE4 8FB00028 */  lw      $s0, 0x0028($sp)           
/* 128D8 80844AE8 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 128DC 80844AEC 03E00008 */  jr      $ra                        
/* 128E0 80844AF0 00000000 */  nop
