glabel func_800E5EDC
/* B5D07C 800E5EDC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* B5D080 800E5EE0 AFBF0014 */  sw    $ra, 0x14($sp)
/* B5D084 800E5EE4 3C048017 */  lui   $a0, %hi(gAudioContext) # $a0, 0x8017
/* B5D088 800E5EE8 8C844D64 */  lw    $a0, %lo(gAudioContext+0x5BE4)($a0)
/* B5D08C 800E5EEC 27A50018 */  addiu $a1, $sp, 0x18
/* B5D090 800E5EF0 0C000CA0 */  jal   osRecvMesg
/* B5D094 800E5EF4 00003025 */   move  $a2, $zero
/* B5D098 800E5EF8 2401FFFF */  li    $at, -1
/* B5D09C 800E5EFC 14410003 */  bne   $v0, $at, .L800E5F0C
/* B5D0A0 800E5F00 8FBF0014 */   lw    $ra, 0x14($sp)
/* B5D0A4 800E5F04 10000009 */  b     .L800E5F2C
/* B5D0A8 800E5F08 00001025 */   move  $v0, $zero
.L800E5F0C:
/* B5D0AC 800E5F0C 3C0F8017 */  lui   $t7, %hi(gAudioContext+0x3519) # $t7, 0x8017
/* B5D0B0 800E5F10 91EF2699 */  lbu   $t7, %lo(gAudioContext+0x3519)($t7)
/* B5D0B4 800E5F14 8FAE0018 */  lw    $t6, 0x18($sp)
/* B5D0B8 800E5F18 24020001 */  li    $v0, 1
/* B5D0BC 800E5F1C 11CF0003 */  beq   $t6, $t7, .L800E5F2C
/* B5D0C0 800E5F20 00000000 */   nop
/* B5D0C4 800E5F24 10000001 */  b     .L800E5F2C
/* B5D0C8 800E5F28 2402FFFF */   li    $v0, -1
.L800E5F2C:
/* B5D0CC 800E5F2C 03E00008 */  jr    $ra
/* B5D0D0 800E5F30 27BD0020 */   addiu $sp, $sp, 0x20

