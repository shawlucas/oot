.rdata
glabel D_80139714
    .asciz "\x1B[43;30mcamera: warning: circle: target is not valid, stop!\n\x1B[m"
    .balign 4

.late_rodata
glabel D_8013A388
    .float 0.01

glabel D_8013A38C
    .float 0.1

.text
glabel func_80056450
/* ACD5F0 80056450 27BDFFC0 */  addiu $sp, $sp, -0x40
/* ACD5F4 80056454 AFBF0024 */  sw    $ra, 0x24($sp)
/* ACD5F8 80056458 AFB00020 */  sw    $s0, 0x20($sp)
/* ACD5FC 8005645C 8482015E */  lh    $v0, 0x15e($a0)
/* ACD600 80056460 00808025 */  move  $s0, $a0
/* ACD604 80056464 2401000A */  li    $at, 10
/* ACD608 80056468 5040000A */  beql  $v0, $zero, .L80056494
/* ACD60C 8005646C 860F0142 */   lh    $t7, 0x142($s0)
/* ACD610 80056470 10410007 */  beq   $v0, $at, .L80056490
/* ACD614 80056474 24010014 */   li    $at, 20
/* ACD618 80056478 10410005 */  beq   $v0, $at, .L80056490
/* ACD61C 8005647C 3C0E8016 */   lui   $t6, %hi(gGameInfo) # $t6, 0x8016
/* ACD620 80056480 8DCEFA90 */  lw    $t6, %lo(gGameInfo)($t6)
/* ACD624 80056484 85C30314 */  lh    $v1, 0x314($t6)
/* ACD628 80056488 10600018 */  beqz  $v1, .L800564EC
/* ACD62C 8005648C 00000000 */   nop   
.L80056490:
/* ACD630 80056490 860F0142 */  lh    $t7, 0x142($s0)
.L80056494:
/* ACD634 80056494 3C198012 */  lui   $t9, %hi(D_8011D068)
/* ACD638 80056498 86080144 */  lh    $t0, 0x144($s0)
/* ACD63C 8005649C 000FC0C0 */  sll   $t8, $t7, 3
/* ACD640 800564A0 0338C821 */  addu  $t9, $t9, $t8
/* ACD644 800564A4 8F39D068 */  lw    $t9, %lo(D_8011D068)($t9)
/* ACD648 800564A8 000848C0 */  sll   $t1, $t0, 3
/* ACD64C 800564AC 3C018014 */  lui   $at, %hi(D_8013A388)
/* ACD650 800564B0 03295021 */  addu  $t2, $t9, $t1
/* ACD654 800564B4 8D420004 */  lw    $v0, 4($t2)
/* ACD658 800564B8 C428A388 */  lwc1  $f8, %lo(D_8013A388)($at)
/* ACD65C 800564BC 3C0D8016 */  lui   $t5, %hi(gGameInfo) # $t5, 0x8016
/* ACD660 800564C0 844B0000 */  lh    $t3, ($v0)
/* ACD664 800564C4 24420004 */  addiu $v0, $v0, 4
/* ACD668 800564C8 448B2000 */  mtc1  $t3, $f4
/* ACD66C 800564CC 00000000 */  nop   
/* ACD670 800564D0 468021A0 */  cvt.s.w $f6, $f4
/* ACD674 800564D4 46083282 */  mul.s $f10, $f6, $f8
/* ACD678 800564D8 E60A0000 */  swc1  $f10, ($s0)
/* ACD67C 800564DC 844C0000 */  lh    $t4, ($v0)
/* ACD680 800564E0 A60C0004 */  sh    $t4, 4($s0)
/* ACD684 800564E4 8DADFA90 */  lw    $t5, %lo(gGameInfo)($t5)
/* ACD688 800564E8 85A30314 */  lh    $v1, 0x314($t5)
.L800564EC:
/* ACD68C 800564EC 50600004 */  beql  $v1, $zero, .L80056500
/* ACD690 800564F0 860E0004 */   lh    $t6, 4($s0)
/* ACD694 800564F4 0C011495 */  jal   func_80045254
/* ACD698 800564F8 02002025 */   move  $a0, $s0
/* ACD69C 800564FC 860E0004 */  lh    $t6, 4($s0)
.L80056500:
/* ACD6A0 80056500 3C018012 */  lui   $at, %hi(D_8011D3A0) # $at, 0x8012
/* ACD6A4 80056504 AC2ED3A0 */  sw    $t6, %lo(D_8011D3A0)($at)
/* ACD6A8 80056508 8602015E */  lh    $v0, 0x15e($s0)
/* ACD6AC 8005650C 14400002 */  bnez  $v0, .L80056518
/* ACD6B0 80056510 244F0001 */   addiu $t7, $v0, 1
/* ACD6B4 80056514 A60F015E */  sh    $t7, 0x15e($s0)
.L80056518:
/* ACD6B8 80056518 8E0500A8 */  lw    $a1, 0xa8($s0)
/* ACD6BC 8005651C 10A00005 */  beqz  $a1, .L80056534
/* ACD6C0 80056520 00000000 */   nop   
/* ACD6C4 80056524 8CB80130 */  lw    $t8, 0x130($a1)
/* ACD6C8 80056528 260400AC */  addiu $a0, $s0, 0xac
/* ACD6CC 8005652C 17000008 */  bnez  $t8, .L80056550
/* ACD6D0 80056530 00000000 */   nop   
.L80056534:
/* ACD6D4 80056534 14A00003 */  bnez  $a1, .L80056544
/* ACD6D8 80056538 3C048014 */   lui   $a0, %hi(D_80139714) # $a0, 0x8014
/* ACD6DC 8005653C 0C00084C */  jal   osSyncPrintf
/* ACD6E0 80056540 24849714 */   addiu $a0, %lo(D_80139714) # addiu $a0, $a0, -0x68ec
.L80056544:
/* ACD6E4 80056544 AE0000A8 */  sw    $zero, 0xa8($s0)
/* ACD6E8 80056548 10000025 */  b     .L800565E0
/* ACD6EC 8005654C 24020001 */   li    $v0, 1
.L80056550:
/* ACD6F0 80056550 0C00BBB9 */  jal   func_8002EEE4
/* ACD6F4 80056554 AFA4002C */   sw    $a0, 0x2c($sp)
/* ACD6F8 80056558 C6000000 */  lwc1  $f0, ($s0)
/* ACD6FC 8005655C 3C018014 */  lui   $at, %hi(D_8013A38C)
/* ACD700 80056560 C430A38C */  lwc1  $f16, %lo(D_8013A38C)($at)
/* ACD704 80056564 26050050 */  addiu $a1, $s0, 0x50
/* ACD708 80056568 44060000 */  mfc1  $a2, $f0
/* ACD70C 8005656C 44070000 */  mfc1  $a3, $f0
/* ACD710 80056570 8FA4002C */  lw    $a0, 0x2c($sp)
/* ACD714 80056574 AFA50030 */  sw    $a1, 0x30($sp)
/* ACD718 80056578 0C010E8F */  jal   func_80043A3C
/* ACD71C 8005657C E7B00010 */   swc1  $f16, 0x10($sp)
/* ACD720 80056580 26020094 */  addiu $v0, $s0, 0x94
/* ACD724 80056584 C4440000 */  lwc1  $f4, ($v0)
/* ACD728 80056588 C6120050 */  lwc1  $f18, 0x50($s0)
/* ACD72C 8005658C C6080054 */  lwc1  $f8, 0x54($s0)
/* ACD730 80056590 2605005C */  addiu $a1, $s0, 0x5c
/* ACD734 80056594 46049181 */  sub.s $f6, $f18, $f4
/* ACD738 80056598 C6120058 */  lwc1  $f18, 0x58($s0)
/* ACD73C 8005659C E60600E4 */  swc1  $f6, 0xe4($s0)
/* ACD740 800565A0 C44A0004 */  lwc1  $f10, 4($v0)
/* ACD744 800565A4 460A4401 */  sub.s $f16, $f8, $f10
/* ACD748 800565A8 E61000E8 */  swc1  $f16, 0xe8($s0)
/* ACD74C 800565AC C4440008 */  lwc1  $f4, 8($v0)
/* ACD750 800565B0 46049181 */  sub.s $f6, $f18, $f4
/* ACD754 800565B4 E60600EC */  swc1  $f6, 0xec($s0)
/* ACD758 800565B8 0C01EFE4 */  jal   func_8007BF90
/* ACD75C 800565BC 8FA40030 */   lw    $a0, 0x30($sp)
/* ACD760 800565C0 86020160 */  lh    $v0, 0x160($s0)
/* ACD764 800565C4 44804000 */  mtc1  $zero, $f8
/* ACD768 800565C8 E60000DC */  swc1  $f0, 0xdc($s0)
/* ACD76C 800565CC 18400003 */  blez  $v0, .L800565DC
/* ACD770 800565D0 E60800D8 */   swc1  $f8, 0xd8($s0)
/* ACD774 800565D4 2448FFFF */  addiu $t0, $v0, -1
/* ACD778 800565D8 A6080160 */  sh    $t0, 0x160($s0)
.L800565DC:
/* ACD77C 800565DC 24020001 */  li    $v0, 1
.L800565E0:
/* ACD780 800565E0 8FBF0024 */  lw    $ra, 0x24($sp)
/* ACD784 800565E4 8FB00020 */  lw    $s0, 0x20($sp)
/* ACD788 800565E8 27BD0040 */  addiu $sp, $sp, 0x40
/* ACD78C 800565EC 03E00008 */  jr    $ra
/* ACD790 800565F0 00000000 */   nop   
