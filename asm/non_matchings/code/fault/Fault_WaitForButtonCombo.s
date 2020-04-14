.late_rodata
glabel jtbl_8014753C
    .word L800D54D0
    .word L800D54F0
    .word L800D550C
    .word L800D5528
    .word L800D5544
    .word L800D5560
    .word L800D557C
    .word L800D5598
    .word L800D55B0
    .word L800D55CC
    .word L800D5648


.rdata
glabel D_801471F8
    .asciz "\x1B[37mKeyWaitB (ＬＲＺ \x1B[37m上\x1B[33m下 \x1B[33m上\x1B[37m下 \x1B[37m左\x1B[33m左 \x1B[33m右\x1B[37m右 \x1B[32mＢ\x1B[34mＡ\x1B[31mSTART\x1B[37m)\x1B[m\n"
    .balign 4
glabel D_80147270
    .asciz "\x1B[37mKeyWaitB'(ＬＲ左\x1B[33m右 +\x1B[31mSTART\x1B[37m)\x1B[m\n"
    .balign 4

.text
glabel Fault_WaitForButtonCombo
/* B4C55C 800D53BC 3C19FFFA */  lui   $t9, (0xFFFA5A5A >> 16) # lui $t9, 0xfffa
/* B4C560 800D53C0 03A04025 */  move  $t0, $sp
/* B4C564 800D53C4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* B4C568 800D53C8 37395A5A */  ori   $t9, (0xFFFA5A5A & 0xFFFF) # ori $t9, $t9, 0x5a5a
.L800D53CC:
/* B4C56C 800D53CC 2508FFF8 */  addiu $t0, $t0, -8
/* B4C570 800D53D0 AD190000 */  sw    $t9, ($t0)
/* B4C574 800D53D4 151DFFFD */  bne   $t0, $sp, .L800D53CC
/* B4C578 800D53D8 AD190004 */   sw    $t9, 4($t0)
/* B4C57C 800D53DC AFBF0024 */  sw    $ra, 0x24($sp)
/* B4C580 800D53E0 AFB20020 */  sw    $s2, 0x20($sp)
/* B4C584 800D53E4 AFB1001C */  sw    $s1, 0x1c($sp)
/* B4C588 800D53E8 AFB00018 */  sw    $s0, 0x18($sp)
/* B4C58C 800D53EC 3C0E8017 */  lui   $t6, %hi(sFaultStructPtr) # $t6, 0x8017
/* B4C590 800D53F0 8DCEA800 */  lw    $t6, %lo(sFaultStructPtr)($t6)
/* B4C594 800D53F4 3C048014 */  lui   $a0, %hi(D_801471F8) # $a0, 0x8014
/* B4C598 800D53F8 248471F8 */  addiu $a0, %lo(D_801471F8) # addiu $a0, $a0, 0x71f8
/* B4C59C 800D53FC 25CF07E4 */  addiu $t7, $t6, 0x7e4
/* B4C5A0 800D5400 0C00084C */  jal   osSyncPrintf
/* B4C5A4 800D5404 AFAF002C */   sw    $t7, 0x2c($sp)
/* B4C5A8 800D5408 3C048014 */  lui   $a0, %hi(D_80147270) # $a0, 0x8014
/* B4C5AC 800D540C 0C00084C */  jal   osSyncPrintf
/* B4C5B0 800D5410 24847270 */   addiu $a0, %lo(D_80147270) # addiu $a0, $a0, 0x7270
/* B4C5B4 800D5414 0C035AD7 */  jal   FaultDrawer_SetForeColor
/* B4C5B8 800D5418 3404FFFF */   li    $a0, 65535
/* B4C5BC 800D541C 0C035AE9 */  jal   FaultDrawer_SetBackColor
/* B4C5C0 800D5420 24040001 */   li    $a0, 1
/* B4C5C4 800D5424 00008025 */  move  $s0, $zero
/* B4C5C8 800D5428 00008825 */  move  $s1, $zero
/* B4C5CC 800D542C 24120001 */  li    $s2, 1
.L800D5430:
/* B4C5D0 800D5430 0C03518F */  jal   Fault_Sleep
/* B4C5D4 800D5434 24040010 */   li    $a0, 16
/* B4C5D8 800D5438 0C0351AD */  jal   Fault_UpdatePadImpl
/* B4C5DC 800D543C 00000000 */   nop   
/* B4C5E0 800D5440 8FA4002C */  lw    $a0, 0x2c($sp)
/* B4C5E4 800D5444 94830000 */  lhu   $v1, ($a0)
/* B4C5E8 800D5448 9482000C */  lhu   $v0, 0xc($a0)
/* B4C5EC 800D544C 14600005 */  bnez  $v1, .L800D5464
/* B4C5F0 800D5450 00000000 */   nop   
/* B4C5F4 800D5454 16320003 */  bne   $s1, $s2, .L800D5464
/* B4C5F8 800D5458 00000000 */   nop   
/* B4C5FC 800D545C 1000007F */  b     .L800D565C
/* B4C600 800D5460 00008825 */   move  $s1, $zero
.L800D5464:
/* B4C604 800D5464 1040007D */  beqz  $v0, .L800D565C
/* B4C608 800D5468 00000000 */   nop   
/* B4C60C 800D546C 56320003 */  bnel  $s1, $s2, .L800D547C
/* B4C610 800D5470 2A01005C */   slti  $at, $s0, 0x5c
/* B4C614 800D5474 00008025 */  move  $s0, $zero
/* B4C618 800D5478 2A01005C */  slti  $at, $s0, 0x5c
.L800D547C:
/* B4C61C 800D547C 14200005 */  bnez  $at, .L800D5494
/* B4C620 800D5480 2401005C */   li    $at, 92
/* B4C624 800D5484 5201006A */  beql  $s0, $at, .L800D5630
/* B4C628 800D5488 34018000 */   li    $at, 32768
/* B4C62C 800D548C 10000073 */  b     .L800D565C
/* B4C630 800D5490 00000000 */   nop   
.L800D5494:
/* B4C634 800D5494 2A01000B */  slti  $at, $s0, 0xb
/* B4C638 800D5498 14200005 */  bnez  $at, .L800D54B0
/* B4C63C 800D549C 2401005B */   li    $at, 91
/* B4C640 800D54A0 5201005C */  beql  $s0, $at, .L800D5614
/* B4C644 800D54A4 24014000 */   li    $at, 16384
/* B4C648 800D54A8 1000006C */  b     .L800D565C
/* B4C64C 800D54AC 00000000 */   nop   
.L800D54B0:
/* B4C650 800D54B0 2E01000B */  sltiu $at, $s0, 0xb
/* B4C654 800D54B4 10200069 */  beqz  $at, .L800D565C
/* B4C658 800D54B8 0010C080 */   sll   $t8, $s0, 2
/* B4C65C 800D54BC 3C018014 */  lui   $at, %hi(jtbl_8014753C)
/* B4C660 800D54C0 00380821 */  addu  $at, $at, $t8
/* B4C664 800D54C4 8C38753C */  lw    $t8, %lo(jtbl_8014753C)($at)
/* B4C668 800D54C8 03000008 */  jr    $t8
/* B4C66C 800D54CC 00000000 */   nop   
glabel L800D54D0
/* B4C670 800D54D0 24012030 */  li    $at, 8240
/* B4C674 800D54D4 14610061 */  bne   $v1, $at, .L800D565C
/* B4C678 800D54D8 24012000 */   li    $at, 8192
/* B4C67C 800D54DC 1441005F */  bne   $v0, $at, .L800D565C
/* B4C680 800D54E0 00000000 */   nop   
/* B4C684 800D54E4 02408025 */  move  $s0, $s2
/* B4C688 800D54E8 1000005C */  b     .L800D565C
/* B4C68C 800D54EC 02408825 */   move  $s1, $s2
glabel L800D54F0
/* B4C690 800D54F0 24010800 */  li    $at, 2048
/* B4C694 800D54F4 14410003 */  bne   $v0, $at, .L800D5504
/* B4C698 800D54F8 00000000 */   nop   
/* B4C69C 800D54FC 10000057 */  b     .L800D565C
/* B4C6A0 800D5500 24100002 */   li    $s0, 2
.L800D5504:
/* B4C6A4 800D5504 10000055 */  b     .L800D565C
/* B4C6A8 800D5508 00008025 */   move  $s0, $zero
glabel L800D550C
/* B4C6AC 800D550C 24010004 */  li    $at, 4
/* B4C6B0 800D5510 14410003 */  bne   $v0, $at, .L800D5520
/* B4C6B4 800D5514 24100003 */   li    $s0, 3
/* B4C6B8 800D5518 10000050 */  b     .L800D565C
/* B4C6BC 800D551C 02408825 */   move  $s1, $s2
.L800D5520:
/* B4C6C0 800D5520 1000004E */  b     .L800D565C
/* B4C6C4 800D5524 00008025 */   move  $s0, $zero
glabel L800D5528
/* B4C6C8 800D5528 24010008 */  li    $at, 8
/* B4C6CC 800D552C 14410003 */  bne   $v0, $at, .L800D553C
/* B4C6D0 800D5530 00000000 */   nop   
/* B4C6D4 800D5534 10000049 */  b     .L800D565C
/* B4C6D8 800D5538 24100004 */   li    $s0, 4
.L800D553C:
/* B4C6DC 800D553C 10000047 */  b     .L800D565C
/* B4C6E0 800D5540 00008025 */   move  $s0, $zero
glabel L800D5544
/* B4C6E4 800D5544 24010400 */  li    $at, 1024
/* B4C6E8 800D5548 14410003 */  bne   $v0, $at, .L800D5558
/* B4C6EC 800D554C 24100005 */   li    $s0, 5
/* B4C6F0 800D5550 10000042 */  b     .L800D565C
/* B4C6F4 800D5554 02408825 */   move  $s1, $s2
.L800D5558:
/* B4C6F8 800D5558 10000040 */  b     .L800D565C
/* B4C6FC 800D555C 00008025 */   move  $s0, $zero
glabel L800D5560
/* B4C700 800D5560 24010200 */  li    $at, 512
/* B4C704 800D5564 14410003 */  bne   $v0, $at, .L800D5574
/* B4C708 800D5568 00000000 */   nop   
/* B4C70C 800D556C 1000003B */  b     .L800D565C
/* B4C710 800D5570 24100006 */   li    $s0, 6
.L800D5574:
/* B4C714 800D5574 10000039 */  b     .L800D565C
/* B4C718 800D5578 00008025 */   move  $s0, $zero
glabel L800D557C
/* B4C71C 800D557C 24010002 */  li    $at, 2
/* B4C720 800D5580 14410003 */  bne   $v0, $at, .L800D5590
/* B4C724 800D5584 24100007 */   li    $s0, 7
/* B4C728 800D5588 10000034 */  b     .L800D565C
/* B4C72C 800D558C 02408825 */   move  $s1, $s2
.L800D5590:
/* B4C730 800D5590 10000032 */  b     .L800D565C
/* B4C734 800D5594 00008025 */   move  $s0, $zero
glabel L800D5598
/* B4C738 800D5598 14520003 */  bne   $v0, $s2, .L800D55A8
/* B4C73C 800D559C 00000000 */   nop   
/* B4C740 800D55A0 1000002E */  b     .L800D565C
/* B4C744 800D55A4 24100008 */   li    $s0, 8
.L800D55A8:
/* B4C748 800D55A8 1000002C */  b     .L800D565C
/* B4C74C 800D55AC 00008025 */   move  $s0, $zero
glabel L800D55B0
/* B4C750 800D55B0 24010100 */  li    $at, 256
/* B4C754 800D55B4 14410003 */  bne   $v0, $at, .L800D55C4
/* B4C758 800D55B8 24100009 */   li    $s0, 9
/* B4C75C 800D55BC 10000027 */  b     .L800D565C
/* B4C760 800D55C0 02408825 */   move  $s1, $s2
.L800D55C4:
/* B4C764 800D55C4 10000025 */  b     .L800D565C
/* B4C768 800D55C8 00008025 */   move  $s0, $zero
glabel L800D55CC
/* B4C76C 800D55CC 3401C000 */  li    $at, 49152
/* B4C770 800D55D0 54410004 */  bnel  $v0, $at, .L800D55E4
/* B4C774 800D55D4 34018000 */   li    $at, 32768
/* B4C778 800D55D8 10000020 */  b     .L800D565C
/* B4C77C 800D55DC 2410000A */   li    $s0, 10
/* B4C780 800D55E0 34018000 */  li    $at, 32768
.L800D55E4:
/* B4C784 800D55E4 54410004 */  bnel  $v0, $at, .L800D55F8
/* B4C788 800D55E8 24014000 */   li    $at, 16384
/* B4C78C 800D55EC 1000001B */  b     .L800D565C
/* B4C790 800D55F0 2410005B */   li    $s0, 91
/* B4C794 800D55F4 24014000 */  li    $at, 16384
.L800D55F8:
/* B4C798 800D55F8 14410003 */  bne   $v0, $at, .L800D5608
/* B4C79C 800D55FC 00000000 */   nop   
/* B4C7A0 800D5600 10000016 */  b     .L800D565C
/* B4C7A4 800D5604 2410005C */   li    $s0, 92
.L800D5608:
/* B4C7A8 800D5608 10000014 */  b     .L800D565C
/* B4C7AC 800D560C 00008025 */   move  $s0, $zero
/* B4C7B0 800D5610 24014000 */  li    $at, 16384
.L800D5614:
/* B4C7B4 800D5614 14410003 */  bne   $v0, $at, .L800D5624
/* B4C7B8 800D5618 00000000 */   nop   
/* B4C7BC 800D561C 1000000F */  b     .L800D565C
/* B4C7C0 800D5620 2410000A */   li    $s0, 10
.L800D5624:
/* B4C7C4 800D5624 1000000D */  b     .L800D565C
/* B4C7C8 800D5628 00008025 */   move  $s0, $zero
/* B4C7CC 800D562C 34018000 */  li    $at, 32768
.L800D5630:
/* B4C7D0 800D5630 14410003 */  bne   $v0, $at, .L800D5640
/* B4C7D4 800D5634 00000000 */   nop   
/* B4C7D8 800D5638 10000008 */  b     .L800D565C
/* B4C7DC 800D563C 2410000A */   li    $s0, 10
.L800D5640:
/* B4C7E0 800D5640 10000006 */  b     .L800D565C
/* B4C7E4 800D5644 00008025 */   move  $s0, $zero
glabel L800D5648
/* B4C7E8 800D5648 24011000 */  li    $at, 4096
/* B4C7EC 800D564C 14410003 */  bne   $v0, $at, .L800D565C
/* B4C7F0 800D5650 00008025 */   move  $s0, $zero
/* B4C7F4 800D5654 10000001 */  b     .L800D565C
/* B4C7F8 800D5658 2410000B */   li    $s0, 11
.L800D565C:
/* B4C7FC 800D565C 0C041924 */  jal   osWritebackDCacheAll
/* B4C800 800D5660 00000000 */   nop   
/* B4C804 800D5664 2401000B */  li    $at, 11
/* B4C808 800D5668 1601FF71 */  bne   $s0, $at, .L800D5430
/* B4C80C 800D566C 00000000 */   nop   
/* B4C810 800D5670 8FBF0024 */  lw    $ra, 0x24($sp)
/* B4C814 800D5674 8FB00018 */  lw    $s0, 0x18($sp)
/* B4C818 800D5678 8FB1001C */  lw    $s1, 0x1c($sp)
/* B4C81C 800D567C 8FB20020 */  lw    $s2, 0x20($sp)
/* B4C820 800D5680 03E00008 */  jr    $ra
/* B4C824 800D5684 27BD0030 */   addiu $sp, $sp, 0x30

