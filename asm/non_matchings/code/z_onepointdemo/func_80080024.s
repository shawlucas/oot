glabel func_80080024
/* AF71C4 80080024 27BDFFE0 */  addiu $sp, $sp, -0x20
/* AF71C8 80080028 AFA50024 */  sw    $a1, 0x24($sp)
/* AF71CC 8008002C 00052C00 */  sll   $a1, $a1, 0x10
/* AF71D0 80080030 00052C03 */  sra   $a1, $a1, 0x10
/* AF71D4 80080034 00057080 */  sll   $t6, $a1, 2
/* AF71D8 80080038 AFBF0014 */  sw    $ra, 0x14($sp)
/* AF71DC 8008003C 008E7821 */  addu  $t7, $a0, $t6
/* AF71E0 80080040 8DE20790 */  lw    $v0, 0x790($t7)
/* AF71E4 80080044 8458014E */  lh    $t8, 0x14e($v0)
/* AF71E8 80080048 8C47008C */  lw    $a3, 0x8c($v0)
/* AF71EC 8008004C 84460164 */  lh    $a2, 0x164($v0)
/* AF71F0 80080050 0018C880 */  sll   $t9, $t8, 2
/* AF71F4 80080054 00F94021 */  addu  $t0, $a3, $t9
/* AF71F8 80080058 8D030790 */  lw    $v1, 0x790($t0)
/* AF71FC 8008005C 2408FFFF */  li    $t0, -1
/* AF7200 80080060 84690162 */  lh    $t1, 0x162($v1)
/* AF7204 80080064 54C90006 */  bnel  $a2, $t1, .L80080080
/* AF7208 80080068 844B0162 */   lh    $t3, 0x162($v0)
/* AF720C 8008006C 844A0162 */  lh    $t2, 0x162($v0)
/* AF7210 80080070 A46A0162 */  sh    $t2, 0x162($v1)
/* AF7214 80080074 8C47008C */  lw    $a3, 0x8c($v0)
/* AF7218 80080078 84460164 */  lh    $a2, 0x164($v0)
/* AF721C 8008007C 844B0162 */  lh    $t3, 0x162($v0)
.L80080080:
/* AF7220 80080080 000B6080 */  sll   $t4, $t3, 2
/* AF7224 80080084 00EC6821 */  addu  $t5, $a3, $t4
/* AF7228 80080088 8DA30790 */  lw    $v1, 0x790($t5)
/* AF722C 8008008C 846E014E */  lh    $t6, 0x14e($v1)
/* AF7230 80080090 54CE0006 */  bnel  $a2, $t6, .L800800AC
/* AF7234 80080094 849807A0 */   lh    $t8, 0x7a0($a0)
/* AF7238 80080098 844F014E */  lh    $t7, 0x14e($v0)
/* AF723C 8008009C A46F014E */  sh    $t7, 0x14e($v1)
/* AF7240 800800A0 8C47008C */  lw    $a3, 0x8c($v0)
/* AF7244 800800A4 84460164 */  lh    $a2, 0x164($v0)
/* AF7248 800800A8 849807A0 */  lh    $t8, 0x7a0($a0)
.L800800AC:
/* AF724C 800800AC 2403FFFF */  li    $v1, -1
/* AF7250 800800B0 00E02025 */  move  $a0, $a3
/* AF7254 800800B4 14B80003 */  bne   $a1, $t8, .L800800C4
/* AF7258 800800B8 00000000 */   nop   
/* AF725C 800800BC 10000001 */  b     .L800800C4
/* AF7260 800800C0 84430162 */   lh    $v1, 0x162($v0)
.L800800C4:
/* AF7264 800800C4 A4400162 */  sh    $zero, 0x162($v0)
/* AF7268 800800C8 84590162 */  lh    $t9, 0x162($v0)
/* AF726C 800800CC A4480160 */  sh    $t0, 0x160($v0)
/* AF7270 800800D0 00062C00 */  sll   $a1, $a2, 0x10
/* AF7274 800800D4 A459014E */  sh    $t9, 0x14e($v0)
/* AF7278 800800D8 AFA30018 */  sw    $v1, 0x18($sp)
/* AF727C 800800DC 0C0300E1 */  jal   Gameplay_ClearCamera
/* AF7280 800800E0 00052C03 */   sra   $a1, $a1, 0x10
/* AF7284 800800E4 8FBF0014 */  lw    $ra, 0x14($sp)
/* AF7288 800800E8 8FA20018 */  lw    $v0, 0x18($sp)
/* AF728C 800800EC 27BD0020 */  addiu $sp, $sp, 0x20
/* AF7290 800800F0 03E00008 */  jr    $ra
/* AF7294 800800F4 00000000 */   nop   

