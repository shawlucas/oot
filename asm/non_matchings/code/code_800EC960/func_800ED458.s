.rdata
glabel D_80149CB0
    .asciz "Presss NA_KEY_D4 %08x\n"
    .balign 4

glabel D_80149CC8
    .asciz "Presss NA_KEY_F4 %08x\n"
    .balign 4

glabel D_80149CE0
    .asciz "Presss NA_KEY_A4 %08x\n"
    .balign 4

glabel D_80149CF8
    .asciz "Presss NA_KEY_B4 %08x\n"
    .balign 4

glabel D_80149D10
    .asciz "Presss NA_KEY_D5 %08x\n"
    .balign 4

.text
glabel func_800ED458
/* B645F8 800ED458 3C0E8013 */  lui   $t6, %hi(D_80130F3C) # $t6, 0x8013
/* B645FC 800ED45C 8DCE0F3C */  lw    $t6, %lo(D_80130F3C)($t6)
/* B64600 800ED460 27BDFFE0 */  addiu $sp, $sp, -0x20
/* B64604 800ED464 AFBF001C */  sw    $ra, 0x1c($sp)
/* B64608 800ED468 11C00008 */  beqz  $t6, .L800ED48C
/* B6460C 800ED46C AFA40020 */   sw    $a0, 0x20($sp)
/* B64610 800ED470 3C038013 */  lui   $v1, %hi(D_80131880) # $v1, 0x8013
/* B64614 800ED474 24631880 */  addiu $v1, %lo(D_80131880) # addiu $v1, $v1, 0x1880
/* B64618 800ED478 90620000 */  lbu   $v0, ($v1)
/* B6461C 800ED47C 10400003 */  beqz  $v0, .L800ED48C
/* B64620 800ED480 244FFFFF */   addiu $t7, $v0, -1
/* B64624 800ED484 100000EC */  b     .L800ED838
/* B64628 800ED488 A06F0000 */   sb    $t7, ($v1)
.L800ED48C:
/* B6462C 800ED48C 3C048017 */  lui   $a0, %hi(D_8016BA10) # $a0, 0x8017
/* B64630 800ED490 2484BA10 */  addiu $a0, %lo(D_8016BA10) # addiu $a0, $a0, -0x45f0
/* B64634 800ED494 8C830000 */  lw    $v1, ($a0)
/* B64638 800ED498 10600008 */  beqz  $v1, .L800ED4BC
/* B6463C 800ED49C 3C028013 */   lui   $v0, %hi(sOcarinaAllowedBtnMask) # $v0, 0x8013
/* B64640 800ED4A0 8C420EFC */  lw    $v0, %lo(sOcarinaAllowedBtnMask)($v0)
/* B64644 800ED4A4 3C188017 */  lui   $t8, %hi(sCurOcarinaBtnPress) # $t8, 0x8017
/* B64648 800ED4A8 8F18BA0C */  lw    $t8, %lo(sCurOcarinaBtnPress)($t8)
/* B6464C 800ED4AC 00625824 */  and   $t3, $v1, $v0
/* B64650 800ED4B0 0302C824 */  and   $t9, $t8, $v0
/* B64654 800ED4B4 532B00E1 */  beql  $t9, $t3, .L800ED83C
/* B64658 800ED4B8 8FBF001C */   lw    $ra, 0x1c($sp)
.L800ED4BC:
/* B6465C 800ED4BC AC800000 */  sw    $zero, ($a0)
/* B64660 800ED4C0 3C038017 */  lui   $v1, %hi(sCurOcarinaBtnPress) # $v1, 0x8017
/* B64664 800ED4C4 3C028013 */  lui   $v0, %hi(sOcarinaAllowedBtnMask) # $v0, 0x8013
/* B64668 800ED4C8 8C420EFC */  lw    $v0, %lo(sOcarinaAllowedBtnMask)($v0)
/* B6466C 800ED4CC 8C63BA0C */  lw    $v1, %lo(sCurOcarinaBtnPress)($v1)
/* B64670 800ED4D0 3C078013 */  lui   $a3, %hi(sCurOcarinaBtnIdx) # $a3, 0x8013
/* B64674 800ED4D4 240900FF */  li    $t1, 255
/* B64678 800ED4D8 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B6467C 800ED4DC 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B64680 800ED4E0 24E70F1C */  addiu $a3, %lo(sCurOcarinaBtnIdx) # addiu $a3, $a3, 0xf1c
/* B64684 800ED4E4 A1490000 */  sb    $t1, ($t2)
/* B64688 800ED4E8 A0E90000 */  sb    $t1, ($a3)
/* B6468C 800ED4EC 3C0C8017 */  lui   $t4, %hi(sPrevOcarinaBtnPress) # $t4, 0x8017
/* B64690 800ED4F0 8D8CBA14 */  lw    $t4, %lo(sPrevOcarinaBtnPress)($t4)
/* B64694 800ED4F4 3C068017 */  lui   $a2, %hi(D_8016BA18) # $a2, 0x8017
/* B64698 800ED4F8 24C6BA18 */  addiu $a2, %lo(D_8016BA18) # addiu $a2, $a2, -0x45e8
/* B6469C 800ED4FC 8CCE0000 */  lw    $t6, ($a2)
/* B646A0 800ED500 00624024 */  and   $t0, $v1, $v0
/* B646A4 800ED504 010C6824 */  and   $t5, $t0, $t4
/* B646A8 800ED508 01A22024 */  and   $a0, $t5, $v0
/* B646AC 800ED50C 01C42824 */  and   $a1, $t6, $a0
/* B646B0 800ED510 14A00005 */  bnez  $a1, .L800ED528
/* B646B4 800ED514 3C048015 */   lui   $a0, %hi(D_80149CB0) # $a0, 0x8015
/* B646B8 800ED518 50600004 */  beql  $v1, $zero, .L800ED52C
/* B646BC 800ED51C ACC50000 */   sw    $a1, ($a2)
/* B646C0 800ED520 10000002 */  b     .L800ED52C
/* B646C4 800ED524 ACC30000 */   sw    $v1, ($a2)
.L800ED528:
/* B646C8 800ED528 ACC50000 */  sw    $a1, ($a2)
.L800ED52C:
/* B646CC 800ED52C 3C058013 */  lui   $a1, %hi(sOcarinaABtnMap) # $a1, 0x8013
/* B646D0 800ED530 8CA50F00 */  lw    $a1, %lo(sOcarinaABtnMap)($a1)
/* B646D4 800ED534 8CC20000 */  lw    $v0, ($a2)
/* B646D8 800ED538 00457824 */  and   $t7, $v0, $a1
/* B646DC 800ED53C 11E0000B */  beqz  $t7, .L800ED56C
/* B646E0 800ED540 00000000 */   nop   
/* B646E4 800ED544 0C00084C */  jal   osSyncPrintf
/* B646E8 800ED548 24849CB0 */   addiu $a0, %lo(D_80149CB0) # addiu $a0, $a0, -0x6350
/* B646EC 800ED54C 3C078013 */  lui   $a3, %hi(sCurOcarinaBtnIdx) # $a3, 0x8013
/* B646F0 800ED550 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B646F4 800ED554 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B646F8 800ED558 24E70F1C */  addiu $a3, %lo(sCurOcarinaBtnIdx) # addiu $a3, $a3, 0xf1c
/* B646FC 800ED55C 24180002 */  li    $t8, 2
/* B64700 800ED560 A1580000 */  sb    $t8, ($t2)
/* B64704 800ED564 10000040 */  b     .L800ED668
/* B64708 800ED568 A0E00000 */   sb    $zero, ($a3)
.L800ED56C:
/* B6470C 800ED56C 3C058013 */  lui   $a1, %hi(sOcarinaCDownBtnMap) # $a1, 0x8013
/* B64710 800ED570 8CA50F08 */  lw    $a1, %lo(sOcarinaCDownBtnMap)($a1)
/* B64714 800ED574 3C048015 */  lui   $a0, %hi(D_80149CC8) # $a0, 0x8015
/* B64718 800ED578 304D0001 */  andi  $t5, $v0, 1
/* B6471C 800ED57C 0045C824 */  and   $t9, $v0, $a1
/* B64720 800ED580 1320000C */  beqz  $t9, .L800ED5B4
/* B64724 800ED584 00000000 */   nop   
/* B64728 800ED588 0C00084C */  jal   osSyncPrintf
/* B6472C 800ED58C 24849CC8 */   addiu $a0, %lo(D_80149CC8) # addiu $a0, $a0, -0x6338
/* B64730 800ED590 3C078013 */  lui   $a3, %hi(sCurOcarinaBtnIdx) # $a3, 0x8013
/* B64734 800ED594 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B64738 800ED598 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B6473C 800ED59C 24E70F1C */  addiu $a3, %lo(sCurOcarinaBtnIdx) # addiu $a3, $a3, 0xf1c
/* B64740 800ED5A0 240B0005 */  li    $t3, 5
/* B64744 800ED5A4 240C0001 */  li    $t4, 1
/* B64748 800ED5A8 A14B0000 */  sb    $t3, ($t2)
/* B6474C 800ED5AC 1000002E */  b     .L800ED668
/* B64750 800ED5B0 A0EC0000 */   sb    $t4, ($a3)
.L800ED5B4:
/* B64754 800ED5B4 11A0000E */  beqz  $t5, .L800ED5F0
/* B64758 800ED5B8 30580002 */   andi  $t8, $v0, 2
/* B6475C 800ED5BC 3C048015 */  lui   $a0, %hi(D_80149CE0) # $a0, 0x8015
/* B64760 800ED5C0 24849CE0 */  addiu $a0, %lo(D_80149CE0) # addiu $a0, $a0, -0x6320
/* B64764 800ED5C4 0C00084C */  jal   osSyncPrintf
/* B64768 800ED5C8 24050001 */   li    $a1, 1
/* B6476C 800ED5CC 3C078013 */  lui   $a3, %hi(sCurOcarinaBtnIdx) # $a3, 0x8013
/* B64770 800ED5D0 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B64774 800ED5D4 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B64778 800ED5D8 24E70F1C */  addiu $a3, %lo(sCurOcarinaBtnIdx) # addiu $a3, $a3, 0xf1c
/* B6477C 800ED5DC 240E0009 */  li    $t6, 9
/* B64780 800ED5E0 240F0002 */  li    $t7, 2
/* B64784 800ED5E4 A14E0000 */  sb    $t6, ($t2)
/* B64788 800ED5E8 1000001F */  b     .L800ED668
/* B6478C 800ED5EC A0EF0000 */   sb    $t7, ($a3)
.L800ED5F0:
/* B64790 800ED5F0 1300000E */  beqz  $t8, .L800ED62C
/* B64794 800ED5F4 3C058013 */   lui   $a1, %hi(sOcarinaCUPBtnMap) # $a1, 0x8013
/* B64798 800ED5F8 3C048015 */  lui   $a0, %hi(D_80149CF8) # $a0, 0x8015
/* B6479C 800ED5FC 24849CF8 */  addiu $a0, %lo(D_80149CF8) # addiu $a0, $a0, -0x6308
/* B647A0 800ED600 0C00084C */  jal   osSyncPrintf
/* B647A4 800ED604 24050002 */   li    $a1, 2
/* B647A8 800ED608 3C078013 */  lui   $a3, %hi(sCurOcarinaBtnIdx) # $a3, 0x8013
/* B647AC 800ED60C 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B647B0 800ED610 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B647B4 800ED614 24E70F1C */  addiu $a3, %lo(sCurOcarinaBtnIdx) # addiu $a3, $a3, 0xf1c
/* B647B8 800ED618 2419000B */  li    $t9, 11
/* B647BC 800ED61C 240B0003 */  li    $t3, 3
/* B647C0 800ED620 A1590000 */  sb    $t9, ($t2)
/* B647C4 800ED624 10000010 */  b     .L800ED668
/* B647C8 800ED628 A0EB0000 */   sb    $t3, ($a3)
.L800ED62C:
/* B647CC 800ED62C 8CA50F04 */  lw    $a1, %lo(sOcarinaCUPBtnMap)($a1)
/* B647D0 800ED630 3C048015 */  lui   $a0, %hi(D_80149D10) # $a0, 0x8015
/* B647D4 800ED634 00456024 */  and   $t4, $v0, $a1
/* B647D8 800ED638 5180000C */  beql  $t4, $zero, .L800ED66C
/* B647DC 800ED63C 91430000 */   lbu   $v1, ($t2)
/* B647E0 800ED640 0C00084C */  jal   osSyncPrintf
/* B647E4 800ED644 24849D10 */   addiu $a0, %lo(D_80149D10) # addiu $a0, $a0, -0x62f0
/* B647E8 800ED648 3C078013 */  lui   $a3, %hi(sCurOcarinaBtnIdx) # $a3, 0x8013
/* B647EC 800ED64C 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B647F0 800ED650 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B647F4 800ED654 24E70F1C */  addiu $a3, %lo(sCurOcarinaBtnIdx) # addiu $a3, $a3, 0xf1c
/* B647F8 800ED658 240D000E */  li    $t5, 14
/* B647FC 800ED65C 240E0004 */  li    $t6, 4
/* B64800 800ED660 A14D0000 */  sb    $t5, ($t2)
/* B64804 800ED664 A0EE0000 */  sb    $t6, ($a3)
.L800ED668:
/* B64808 800ED668 91430000 */  lbu   $v1, ($t2)
.L800ED66C:
/* B6480C 800ED66C 240600FF */  li    $a2, 255
/* B64810 800ED670 3C048013 */  lui   $a0, %hi(D_80131858) # $a0, 0x8013
/* B64814 800ED674 10C30012 */  beq   $a2, $v1, .L800ED6C0
/* B64818 800ED678 00601025 */   move  $v0, $v1
/* B6481C 800ED67C 3C0F8017 */  lui   $t7, %hi(sCurOcarinaBtnPress) # $t7, 0x8017
/* B64820 800ED680 8DEFBA0C */  lw    $t7, %lo(sCurOcarinaBtnPress)($t7)
/* B64824 800ED684 3C198013 */  lui   $t9, %hi(D_80131858) # $t9, 0x8013
/* B64828 800ED688 31F80010 */  andi  $t8, $t7, 0x10
/* B6482C 800ED68C 5300000D */  beql  $t8, $zero, .L800ED6C4
/* B64830 800ED690 24050002 */   li    $a1, 2
/* B64834 800ED694 93391858 */  lbu   $t9, %lo(D_80131858)($t9)
/* B64838 800ED698 24050002 */  li    $a1, 2
/* B6483C 800ED69C 246D0001 */  addiu $t5, $v1, 1
/* B64840 800ED6A0 50B90008 */  beql  $a1, $t9, .L800ED6C4
/* B64844 800ED6A4 24050002 */   li    $a1, 2
/* B64848 800ED6A8 90EB0000 */  lbu   $t3, ($a3)
/* B6484C 800ED6AC 31A300FF */  andi  $v1, $t5, 0xff
/* B64850 800ED6B0 00601025 */  move  $v0, $v1
/* B64854 800ED6B4 256C0080 */  addiu $t4, $t3, 0x80
/* B64858 800ED6B8 A0EC0000 */  sb    $t4, ($a3)
/* B6485C 800ED6BC A14D0000 */  sb    $t5, ($t2)
.L800ED6C0:
/* B64860 800ED6C0 24050002 */  li    $a1, 2
.L800ED6C4:
/* B64864 800ED6C4 10C2000D */  beq   $a2, $v0, .L800ED6FC
/* B64868 800ED6C8 90841858 */   lbu   $a0, %lo(D_80131858)($a0)
/* B6486C 800ED6CC 3C0E8017 */  lui   $t6, %hi(sCurOcarinaBtnPress) # $t6, 0x8017
/* B64870 800ED6D0 8DCEBA0C */  lw    $t6, %lo(sCurOcarinaBtnPress)($t6)
/* B64874 800ED6D4 31CF2000 */  andi  $t7, $t6, 0x2000
/* B64878 800ED6D8 11E00008 */  beqz  $t7, .L800ED6FC
/* B6487C 800ED6DC 00000000 */   nop   
/* B64880 800ED6E0 10A40006 */  beq   $a1, $a0, .L800ED6FC
/* B64884 800ED6E4 00000000 */   nop   
/* B64888 800ED6E8 90F80000 */  lbu   $t8, ($a3)
/* B6488C 800ED6EC 246BFFFF */  addiu $t3, $v1, -1
/* B64890 800ED6F0 A14B0000 */  sb    $t3, ($t2)
/* B64894 800ED6F4 27190040 */  addiu $t9, $t8, 0x40
/* B64898 800ED6F8 A0F90000 */  sb    $t9, ($a3)
.L800ED6FC:
/* B6489C 800ED6FC 10A4001D */  beq   $a1, $a0, .L800ED774
/* B648A0 800ED700 3C038013 */   lui   $v1, %hi(D_80130F2C)
/* B648A4 800ED704 3C0C8017 */  lui   $t4, %hi(D_8016BA09) # $t4, 0x8017
/* B648A8 800ED708 818CBA09 */  lb    $t4, %lo(D_8016BA09)($t4)
/* B648AC 800ED70C 3C038013 */  lui   $v1, %hi(D_80130F2C) # $v1, 0x8013
/* B648B0 800ED710 24630F2C */  addiu $v1, %lo(D_80130F2C) # addiu $v1, $v1, 0xf2c
/* B648B4 800ED714 A06C0000 */  sb    $t4, ($v1)
/* B648B8 800ED718 0C03B298 */  jal   func_800ECA60
/* B648BC 800ED71C 80640000 */   lb    $a0, ($v1)
/* B648C0 800ED720 3C028017 */  lui   $v0, %hi(D_8016BA08) # $v0, 0x8017
/* B648C4 800ED724 8042BA08 */  lb    $v0, %lo(D_8016BA08)($v0)
/* B648C8 800ED728 3C018013 */  lui   $at, %hi(D_80130F24)
/* B648CC 800ED72C E4200F24 */  swc1  $f0, %lo(D_80130F24)($at)
/* B648D0 800ED730 04410003 */  bgez  $v0, .L800ED740
/* B648D4 800ED734 3C040602 */   lui   $a0, (0x06020D06 >> 16) # lui $a0, 0x602
/* B648D8 800ED738 10000002 */  b     .L800ED744
/* B648DC 800ED73C 00021823 */   negu  $v1, $v0
.L800ED740:
/* B648E0 800ED740 00401825 */  move  $v1, $v0
.L800ED744:
/* B648E4 800ED744 3C028013 */  lui   $v0, %hi(D_80130F34) # $v0, 0x8013
/* B648E8 800ED748 24420F34 */  addiu $v0, %lo(D_80130F34) # addiu $v0, $v0, 0xf34
/* B648EC 800ED74C 00036883 */  sra   $t5, $v1, 2
/* B648F0 800ED750 A04D0000 */  sb    $t5, ($v0)
/* B648F4 800ED754 80450000 */  lb    $a1, ($v0)
/* B648F8 800ED758 0C0396C8 */  jal   func_800E5B20
/* B648FC 800ED75C 34840D06 */   ori   $a0, (0x06020D06 & 0xFFFF) # ori $a0, $a0, 0xd06
/* B64900 800ED760 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B64904 800ED764 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B64908 800ED768 91420000 */  lbu   $v0, ($t2)
/* B6490C 800ED76C 10000008 */  b     .L800ED790
/* B64910 800ED770 240600FF */   li    $a2, 255
.L800ED774:
/* B64914 800ED774 3C013F80 */  li    $at, 0x3F800000 # 0.000000
/* B64918 800ED778 44812000 */  mtc1  $at, $f4
/* B6491C 800ED77C 24630F2C */  addiu $v1, %lo(D_80130F2C)
/* B64920 800ED780 A0600000 */  sb    $zero, ($v1)
/* B64924 800ED784 3C018013 */  lui   $at, %hi(D_80130F24)
/* B64928 800ED788 E4240F24 */  swc1  $f4, %lo(D_80130F24)($at)
/* B6492C 800ED78C 91420000 */  lbu   $v0, ($t2)
.L800ED790:
/* B64930 800ED790 10C20021 */  beq   $a2, $v0, .L800ED818
/* B64934 800ED794 3C0E8013 */   lui   $t6, %hi(sPrevOcarinaNoteVal) # $t6, 0x8013
/* B64938 800ED798 91CE0F18 */  lbu   $t6, %lo(sPrevOcarinaNoteVal)($t6)
/* B6493C 800ED79C 3C058013 */  lui   $a1, %hi(D_80130F10)
/* B64940 800ED7A0 104E001D */  beq   $v0, $t6, .L800ED818
/* B64944 800ED7A4 00000000 */   nop   
/* B64948 800ED7A8 80A50F10 */  lb    $a1, %lo(D_80130F10)($a1)
/* B6494C 800ED7AC 3C040602 */  lui   $a0, (0x06020D07 >> 16) # lui $a0, 0x602
/* B64950 800ED7B0 34840D07 */  ori   $a0, (0x06020D07 & 0xFFFF) # ori $a0, $a0, 0xd07
/* B64954 800ED7B4 24A5FFFF */  addiu $a1, $a1, -1
/* B64958 800ED7B8 00052E00 */  sll   $a1, $a1, 0x18
/* B6495C 800ED7BC 0C0396C8 */  jal   func_800E5B20
/* B64960 800ED7C0 00052E03 */   sra   $a1, $a1, 0x18
/* B64964 800ED7C4 3C0A8013 */  lui   $t2, %hi(sCurOcarinaBtnVal) # $t2, 0x8013
/* B64968 800ED7C8 254A0F14 */  addiu $t2, %lo(sCurOcarinaBtnVal) # addiu $t2, $t2, 0xf14
/* B6496C 800ED7CC 3C040602 */  lui   $a0, (0x06020D05 >> 16) # lui $a0, 0x602
/* B64970 800ED7D0 34840D05 */  ori   $a0, (0x06020D05 & 0xFFFF) # ori $a0, $a0, 0xd05
/* B64974 800ED7D4 0C0396C8 */  jal   func_800E5B20
/* B64978 800ED7D8 81450000 */   lb    $a1, ($t2)
/* B6497C 800ED7DC 3C0F8013 */  lui   $t7, %hi(D_80130F28) # $t7, 0x8013
/* B64980 800ED7E0 3C188013 */  lui   $t8, %hi(D_801333E8) # $t8, 0x8013
/* B64984 800ED7E4 271833E8 */  addiu $t8, %lo(D_801333E8) # addiu $t8, $t8, 0x33e8
/* B64988 800ED7E8 25EF0F28 */  addiu $t7, %lo(D_80130F28) # addiu $t7, $t7, 0xf28
/* B6498C 800ED7EC 3C058013 */  lui   $a1, %hi(D_801333D4) # $a1, 0x8013
/* B64990 800ED7F0 3C078013 */  lui   $a3, %hi(D_80130F24) # $a3, 0x8013
/* B64994 800ED7F4 24E70F24 */  addiu $a3, %lo(D_80130F24) # addiu $a3, $a3, 0xf24
/* B64998 800ED7F8 24A533D4 */  addiu $a1, %lo(D_801333D4) # addiu $a1, $a1, 0x33d4
/* B6499C 800ED7FC AFAF0010 */  sw    $t7, 0x10($sp)
/* B649A0 800ED800 AFB80014 */  sw    $t8, 0x14($sp)
/* B649A4 800ED804 24045800 */  li    $a0, 22528
/* B649A8 800ED808 0C03DCE3 */  jal   Audio_PlaySoundGeneral
/* B649AC 800ED80C 24060004 */   li    $a2, 4
/* B649B0 800ED810 1000000A */  b     .L800ED83C
/* B649B4 800ED814 8FBF001C */   lw    $ra, 0x1c($sp)
.L800ED818:
/* B649B8 800ED818 3C198013 */  lui   $t9, %hi(sPrevOcarinaNoteVal) # $t9, 0x8013
/* B649BC 800ED81C 93390F18 */  lbu   $t9, %lo(sPrevOcarinaNoteVal)($t9)
/* B649C0 800ED820 50D90006 */  beql  $a2, $t9, .L800ED83C
/* B649C4 800ED824 8FBF001C */   lw    $ra, 0x1c($sp)
/* B649C8 800ED828 54C20004 */  bnel  $a2, $v0, .L800ED83C
/* B649CC 800ED82C 8FBF001C */   lw    $ra, 0x1c($sp)
/* B649D0 800ED830 0C03E341 */  jal   func_800F8D04
/* B649D4 800ED834 24045800 */   li    $a0, 22528
.L800ED838:
/* B649D8 800ED838 8FBF001C */  lw    $ra, 0x1c($sp)
.L800ED83C:
/* B649DC 800ED83C 27BD0020 */  addiu $sp, $sp, 0x20
/* B649E0 800ED840 03E00008 */  jr    $ra
/* B649E4 800ED844 00000000 */   nop   

