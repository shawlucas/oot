glabel func_808604FC
/* 00EAC 808604FC 27BDFF90 */  addiu   $sp, $sp, 0xFF90           ## $sp = FFFFFF90
/* 00EB0 80860500 AFBF002C */  sw      $ra, 0x002C($sp)
/* 00EB4 80860504 AFB00028 */  sw      $s0, 0x0028($sp)
/* 00EB8 80860508 8CAE1C44 */  lw      $t6, 0x1C44($a1)           ## 00001C44
/* 00EBC 8086050C 44801000 */  mtc1    $zero, $f2                 ## $f2 = 0.00
/* 00EC0 80860510 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00EC4 80860514 00A03025 */  or      $a2, $a1, $zero            ## $a2 = 00000000
/* 00EC8 80860518 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00ECC 8086051C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00ED0 80860520 AFA60074 */  sw      $a2, 0x0074($sp)
/* 00ED4 80860524 AFAE0054 */  sw      $t6, 0x0054($sp)
/* 00ED8 80860528 0C21907A */  jal     func_808641E8
/* 00EDC 8086052C E7A20068 */  swc1    $f2, 0x0068($sp)
/* 00EE0 80860530 144001A5 */  bne     $v0, $zero, .L80860BC8
/* 00EE4 80860534 C7A20068 */  lwc1    $f2, 0x0068($sp)
/* 00EE8 80860538 8E0F07E8 */  lw      $t7, 0x07E8($s0)           ## 000007E8
/* 00EEC 8086053C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00EF0 80860540 25F80001 */  addiu   $t8, $t7, 0x0001           ## $t8 = 00000001
/* 00EF4 80860544 AE1807E8 */  sw      $t8, 0x07E8($s0)           ## 000007E8
/* 00EF8 80860548 E7A20068 */  swc1    $f2, 0x0068($sp)
/* 00EFC 8086054C 0C00CEAE */  jal     func_80033AB8
/* 00F00 80860550 8FA40074 */  lw      $a0, 0x0074($sp)
/* 00F04 80860554 10400004 */  beq     $v0, $zero, .L80860568
/* 00F08 80860558 C7A20068 */  lwc1    $f2, 0x0068($sp)
/* 00F0C 8086055C 3C014316 */  lui     $at, 0x4316                ## $at = 43160000
/* 00F10 80860560 44811000 */  mtc1    $at, $f2                   ## $f2 = 150.00
/* 00F14 80860564 00000000 */  nop
.L80860568:
/* 00F18 80860568 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 00F1C 8086056C 44812000 */  mtc1    $at, $f4                   ## $f4 = 80.00
/* 00F20 80860570 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 00F24 80860574 26040068 */  addiu   $a0, $s0, 0x0068           ## $a0 = 00000068
/* 00F28 80860578 46022180 */  add.s   $f6, $f4, $f2
/* 00F2C 8086057C 3C05C0A0 */  lui     $a1, 0xC0A0                ## $a1 = C0A00000
/* 00F30 80860580 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00F34 80860584 3C073F4C */  lui     $a3, 0x3F4C                ## $a3 = 3F4C0000
/* 00F38 80860588 4606003E */  c.le.s  $f0, $f6
/* 00F3C 8086058C 3C0142DC */  lui     $at, 0x42DC                ## $at = 42DC0000
/* 00F40 80860590 45020008 */  bc1fl   .L808605B4
/* 00F44 80860594 44815000 */  mtc1    $at, $f10                  ## $f10 = 110.00
/* 00F48 80860598 44804000 */  mtc1    $zero, $f8                 ## $f8 = 0.00
/* 00F4C 8086059C 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 3F4CCCCD
/* 00F50 808605A0 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF

/* 00F54 808605A4 E7A80010 */  swc1    $f8, 0x0010($sp)
/* 00F58 808605A8 10000010 */  beq     $zero, $zero, .L808605EC
/* 00F5C 808605AC 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00F60 808605B0 44815000 */  mtc1    $at, $f10                  ## $f10 = 5.00
.L808605B4:
/* 00F64 808605B4 26040068 */  addiu   $a0, $s0, 0x0068           ## $a0 = 00000068
/* 00F68 808605B8 3C0540A0 */  lui     $a1, 0x40A0                ## $a1 = 40A00000
/* 00F6C 808605BC 46025400 */  add.s   $f16, $f10, $f2
/* 00F70 808605C0 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00F74 808605C4 3C073F4C */  lui     $a3, 0x3F4C                ## $a3 = 3F4C0000
/* 00F78 808605C8 4600803C */  c.lt.s  $f16, $f0
/* 00F7C 808605CC 00000000 */  nop
/* 00F80 808605D0 45020006 */  bc1fl   .L808605EC
/* 00F84 808605D4 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00F88 808605D8 44809000 */  mtc1    $zero, $f18                ## $f18 = 0.00
/* 00F8C 808605DC 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 3F4CCCCD
/* 00F90 808605E0 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF

/* 00F94 808605E4 E7B20010 */  swc1    $f18, 0x0010($sp)
/* 00F98 808605E8 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
.L808605EC:
/* 00F9C 808605EC 44812000 */  mtc1    $at, $f4                   ## $f4 = 5.00
/* 00FA0 808605F0 C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
/* 00FA4 808605F4 3C01C0A0 */  lui     $at, 0xC0A0                ## $at = C0A00000
/* 00FA8 808605F8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00FAC 808605FC 4600203E */  c.le.s  $f4, $f0
/* 00FB0 80860600 00000000 */  nop
/* 00FB4 80860604 45020006 */  bc1fl   .L80860620
/* 00FB8 80860608 44814000 */  mtc1    $at, $f8                   ## $f8 = -5.00
/* 00FBC 8086060C 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00FC0 80860610 44813000 */  mtc1    $at, $f6                   ## $f6 = 5.00
/* 00FC4 80860614 1000000A */  beq     $zero, $zero, .L80860640
/* 00FC8 80860618 E6060068 */  swc1    $f6, 0x0068($s0)           ## 00000068
/* 00FCC 8086061C 44814000 */  mtc1    $at, $f8                   ## $f8 = 5.00
.L80860620:
/* 00FD0 80860620 3C01C0A0 */  lui     $at, 0xC0A0                ## $at = C0A00000
/* 00FD4 80860624 4608003C */  c.lt.s  $f0, $f8
/* 00FD8 80860628 00000000 */  nop
/* 00FDC 8086062C 45020005 */  bc1fl   .L80860644
/* 00FE0 80860630 8619001C */  lh      $t9, 0x001C($s0)           ## 0000001C
/* 00FE4 80860634 44815000 */  mtc1    $at, $f10                  ## $f10 = -5.00
/* 00FE8 80860638 00000000 */  nop
/* 00FEC 8086063C E60A0068 */  swc1    $f10, 0x0068($s0)          ## 00000068
.L80860640:
/* 00FF0 80860640 8619001C */  lh      $t9, 0x001C($s0)           ## 0000001C
.L80860644:
/* 00FF4 80860644 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 00FF8 80860648 8FA50074 */  lw      $a1, 0x0074($sp)
/* 00FFC 8086064C 5721000C */  bnel    $t9, $at, .L80860680
/* 01000 80860650 C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
/* 01004 80860654 8E060068 */  lw      $a2, 0x0068($s0)           ## 00000068
/* 01008 80860658 0C00CE6E */  jal     func_800339B8
/* 0100C 8086065C 86070032 */  lh      $a3, 0x0032($s0)           ## 00000032
/* 01010 80860660 14400006 */  bne     $v0, $zero, .L8086067C
/* 01014 80860664 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 01018 80860668 C6100068 */  lwc1    $f16, 0x0068($s0)          ## 00000068
/* 0101C 8086066C 44819000 */  mtc1    $at, $f18                  ## $f18 = -1.00
/* 01020 80860670 00000000 */  nop
/* 01024 80860674 46128102 */  mul.s   $f4, $f16, $f18
/* 01028 80860678 E6040068 */  swc1    $f4, 0x0068($s0)           ## 00000068
.L8086067C:
/* 0102C 8086067C C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
.L80860680:
/* 01030 80860680 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 01034 80860684 3C014040 */  lui     $at, 0x4040                ## $at = 40400000
/* 01038 80860688 44814000 */  mtc1    $at, $f8                   ## $f8 = 3.00
/* 0103C 8086068C 4600303E */  c.le.s  $f6, $f0
/* 01040 80860690 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 01044 80860694 45020004 */  bc1fl   .L808606A8
/* 01048 80860698 46000087 */  neg.s   $f2, $f0
/* 0104C 8086069C 10000002 */  beq     $zero, $zero, .L808606A8
/* 01050 808606A0 46000086 */  mov.s   $f2, $f0
/* 01054 808606A4 46000087 */  neg.s   $f2, $f0
.L808606A8:
/* 01058 808606A8 4608103C */  c.lt.s  $f2, $f8
/* 0105C 808606AC 00000000 */  nop
/* 01060 808606B0 45000019 */  bc1f    .L80860718
/* 01064 808606B4 00000000 */  nop
/* 01068 808606B8 3C040601 */  lui     $a0, 0x0601                ## $a0 = 06010000
/* 0106C 808606BC 0C028800 */  jal     SkelAnime_GetFrameCount

/* 01070 808606C0 248481B4 */  addiu   $a0, $a0, 0x81B4           ## $a0 = 060081B4
/* 01074 808606C4 44825000 */  mtc1    $v0, $f10                  ## $f10 = 0.00
/* 01078 808606C8 8E0701A0 */  lw      $a3, 0x01A0($s0)           ## 000001A0
/* 0107C 808606CC 3C01C0C0 */  lui     $at, 0xC0C0                ## $at = C0C00000
/* 01080 808606D0 46805420 */  cvt.s.w $f16, $f10
/* 01084 808606D4 44819000 */  mtc1    $at, $f18                  ## $f18 = -6.00
/* 01088 808606D8 26040188 */  addiu   $a0, $s0, 0x0188           ## $a0 = 00000188
/* 0108C 808606DC 3C050601 */  lui     $a1, 0x0601                ## $a1 = 06010000
/* 01090 808606E0 24A581B4 */  addiu   $a1, $a1, 0x81B4           ## $a1 = 060081B4
/* 01094 808606E4 AFA40034 */  sw      $a0, 0x0034($sp)
/* 01098 808606E8 E7B00010 */  swc1    $f16, 0x0010($sp)
/* 0109C 808606EC AFA00014 */  sw      $zero, 0x0014($sp)
/* 010A0 808606F0 24060000 */  addiu   $a2, $zero, 0x0000         ## $a2 = 00000000
/* 010A4 808606F4 0C029468 */  jal     SkelAnime_ChangeAnim

/* 010A8 808606F8 E7B20018 */  swc1    $f18, 0x0018($sp)
/* 010AC 808606FC 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 010B0 80860700 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 010B4 80860704 C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
/* 010B8 80860708 8FA40034 */  lw      $a0, 0x0034($sp)
/* 010BC 8086070C 46040082 */  mul.s   $f2, $f0, $f4
/* 010C0 80860710 1000001B */  beq     $zero, $zero, .L80860780
/* 010C4 80860714 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
.L80860718:
/* 010C8 80860718 0C028800 */  jal     SkelAnime_GetFrameCount

/* 010CC 8086071C 248426D4 */  addiu   $a0, $a0, 0x26D4           ## $a0 = 000026D4
/* 010D0 80860720 44823000 */  mtc1    $v0, $f6                   ## $f6 = 0.00
/* 010D4 80860724 8E0701A0 */  lw      $a3, 0x01A0($s0)           ## 000001A0
/* 010D8 80860728 3C01C080 */  lui     $at, 0xC080                ## $at = C0800000
/* 010DC 8086072C 46803220 */  cvt.s.w $f8, $f6
/* 010E0 80860730 44815000 */  mtc1    $at, $f10                  ## $f10 = -4.00
/* 010E4 80860734 26040188 */  addiu   $a0, $s0, 0x0188           ## $a0 = 00000188
/* 010E8 80860738 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 010EC 8086073C 24A526D4 */  addiu   $a1, $a1, 0x26D4           ## $a1 = 060026D4
/* 010F0 80860740 AFA40034 */  sw      $a0, 0x0034($sp)
/* 010F4 80860744 E7A80010 */  swc1    $f8, 0x0010($sp)
/* 010F8 80860748 AFA00014 */  sw      $zero, 0x0014($sp)
/* 010FC 8086074C 24060000 */  addiu   $a2, $zero, 0x0000         ## $a2 = 00000000
/* 01100 80860750 0C029468 */  jal     SkelAnime_ChangeAnim

/* 01104 80860754 E7AA0018 */  swc1    $f10, 0x0018($sp)
/* 01108 80860758 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 0110C 8086075C 44818000 */  mtc1    $at, $f16                  ## $f16 = 10.00
/* 01110 80860760 C6000068 */  lwc1    $f0, 0x0068($s0)           ## 00000068
/* 01114 80860764 3C018086 */  lui     $at, %hi(D_8086478C)       ## $at = 80860000
/* 01118 80860768 C424478C */  lwc1    $f4, %lo(D_8086478C)($at)
/* 0111C 8086076C 46100482 */  mul.s   $f18, $f0, $f16
/* 01120 80860770 8FA40034 */  lw      $a0, 0x0034($sp)
/* 01124 80860774 46049082 */  mul.s   $f2, $f18, $f4
/* 01128 80860778 00000000 */  nop
/* 0112C 8086077C 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
.L80860780:
/* 01130 80860780 3C01C020 */  lui     $at, 0xC020                ## $at = C0200000
/* 01134 80860784 4600303E */  c.le.s  $f6, $f0
/* 01138 80860788 00000000 */  nop
/* 0113C 8086078C 4502000F */  bc1fl   .L808607CC
/* 01140 80860790 44810000 */  mtc1    $at, $f0                   ## $f0 = -2.50
/* 01144 80860794 920207DE */  lbu     $v0, 0x07DE($s0)           ## 000007DE
/* 01148 80860798 3C014020 */  lui     $at, 0x4020                ## $at = 40200000
/* 0114C 8086079C 44810000 */  mtc1    $at, $f0                   ## $f0 = 2.50
/* 01150 808607A0 14400002 */  bne     $v0, $zero, .L808607AC
/* 01154 808607A4 24480001 */  addiu   $t0, $v0, 0x0001           ## $t0 = 00000001
/* 01158 808607A8 A20807DE */  sb      $t0, 0x07DE($s0)           ## 000007DE
.L808607AC:
/* 0115C 808607AC 4602003C */  c.lt.s  $f0, $f2
/* 01160 808607B0 00000000 */  nop
/* 01164 808607B4 45000002 */  bc1f    .L808607C0
/* 01168 808607B8 00000000 */  nop
/* 0116C 808607BC 46000086 */  mov.s   $f2, $f0
.L808607C0:
/* 01170 808607C0 10000009 */  beq     $zero, $zero, .L808607E8
/* 01174 808607C4 E60201A4 */  swc1    $f2, 0x01A4($s0)           ## 000001A4
/* 01178 808607C8 44810000 */  mtc1    $at, $f0                   ## $f0 = 2.50
.L808607CC:
/* 0117C 808607CC 00000000 */  nop
/* 01180 808607D0 4600103C */  c.lt.s  $f2, $f0
/* 01184 808607D4 00000000 */  nop
/* 01188 808607D8 45020003 */  bc1fl   .L808607E8
/* 0118C 808607DC E60201A4 */  swc1    $f2, 0x01A4($s0)           ## 000001A4
/* 01190 808607E0 46000086 */  mov.s   $f2, $f0
/* 01194 808607E4 E60201A4 */  swc1    $f2, 0x01A4($s0)           ## 000001A4
.L808607E8:
/* 01198 808607E8 8FA50054 */  lw      $a1, 0x0054($sp)
/* 0119C 808607EC 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 011A0 808607F0 44815000 */  mtc1    $at, $f10                  ## $f10 = 100.00
/* 011A4 808607F4 C6080090 */  lwc1    $f8, 0x0090($s0)           ## 00000090
/* 011A8 808607F8 860A00B6 */  lh      $t2, 0x00B6($s0)           ## 000000B6
/* 011AC 808607FC 84A900B6 */  lh      $t1, 0x00B6($a1)           ## 000000B6
/* 011B0 80860800 460A403C */  c.lt.s  $f8, $f10
/* 011B4 80860804 012A1023 */  subu    $v0, $t1, $t2
/* 011B8 80860808 00021400 */  sll     $v0, $v0, 16
/* 011BC 8086080C 45000022 */  bc1f    .L80860898
/* 011C0 80860810 00021403 */  sra     $v0, $v0, 16
/* 011C4 80860814 80AB0843 */  lb      $t3, 0x0843($a1)           ## 00000843
/* 011C8 80860818 51600020 */  beql    $t3, $zero, .L8086089C
/* 011CC 8086081C C61201A0 */  lwc1    $f18, 0x01A0($s0)          ## 000001A0
/* 011D0 80860820 04400003 */  bltz    $v0, .L80860830
/* 011D4 80860824 00021823 */  subu    $v1, $zero, $v0
/* 011D8 80860828 10000001 */  beq     $zero, $zero, .L80860830
/* 011DC 8086082C 00401825 */  or      $v1, $v0, $zero            ## $v1 = 00000000
.L80860830:
/* 011E0 80860830 28611F40 */  slti    $at, $v1, 0x1F40
/* 011E4 80860834 54200019 */  bnel    $at, $zero, .L8086089C
/* 011E8 80860838 C61201A0 */  lwc1    $f18, 0x01A0($s0)          ## 000001A0
/* 011EC 8086083C 8602008A */  lh      $v0, 0x008A($s0)           ## 0000008A
/* 011F0 80860840 A6020032 */  sh      $v0, 0x0032($s0)           ## 00000032
/* 011F4 80860844 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 011F8 80860848 A60200B6 */  sh      $v0, 0x00B6($s0)           ## 000000B6
/* 011FC 8086084C 3C018086 */  lui     $at, %hi(D_80864790)       ## $at = 80860000
/* 01200 80860850 C4304790 */  lwc1    $f16, %lo(D_80864790)($at)
/* 01204 80860854 8FAC0054 */  lw      $t4, 0x0054($sp)
/* 01208 80860858 4600803C */  c.lt.s  $f16, $f0
/* 0120C 8086085C 00000000 */  nop
/* 01210 80860860 45000009 */  bc1f    .L80860888
/* 01214 80860864 00000000 */  nop
/* 01218 80860868 818D0842 */  lb      $t5, 0x0842($t4)           ## 00000842
/* 0121C 8086086C 24010011 */  addiu   $at, $zero, 0x0011         ## $at = 00000011
/* 01220 80860870 11A10005 */  beq     $t5, $at, .L80860888
/* 01224 80860874 00000000 */  nop
/* 01228 80860878 0C218653 */  jal     func_8086194C
/* 0122C 8086087C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01230 80860880 100000D2 */  beq     $zero, $zero, .L80860BCC
/* 01234 80860884 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860888:
/* 01238 80860888 0C2187B0 */  jal     func_80861EC0
/* 0123C 8086088C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01240 80860890 100000CE */  beq     $zero, $zero, .L80860BCC
/* 01244 80860894 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860898:
/* 01248 80860898 C61201A0 */  lwc1    $f18, 0x01A0($s0)          ## 000001A0
.L8086089C:
/* 0124C 8086089C 4600910D */  trunc.w.s $f4, $f18
/* 01250 808608A0 44032000 */  mfc1    $v1, $f4
/* 01254 808608A4 0C02927F */  jal     SkelAnime_FrameUpdateMatrix

/* 01258 808608A8 AFA30060 */  sw      $v1, 0x0060($sp)
/* 0125C 808608AC C60001A4 */  lwc1    $f0, 0x01A4($s0)           ## 000001A4
/* 01260 808608B0 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 01264 808608B4 44808000 */  mtc1    $zero, $f16                ## $f16 = 0.00
/* 01268 808608B8 8FA30060 */  lw      $v1, 0x0060($sp)
/* 0126C 808608BC 4600303E */  c.le.s  $f6, $f0
/* 01270 808608C0 00000000 */  nop
/* 01274 808608C4 45020004 */  bc1fl   .L808608D8
/* 01278 808608C8 46000087 */  neg.s   $f2, $f0
/* 0127C 808608CC 10000002 */  beq     $zero, $zero, .L808608D8
/* 01280 808608D0 46000086 */  mov.s   $f2, $f0
/* 01284 808608D4 46000087 */  neg.s   $f2, $f0
.L808608D8:
/* 01288 808608D8 C60C01A0 */  lwc1    $f12, 0x01A0($s0)          ## 000001A0
/* 0128C 808608DC 4600803E */  c.le.s  $f16, $f0
/* 01290 808608E0 46026201 */  sub.s   $f8, $f12, $f2
/* 01294 808608E4 4600648D */  trunc.w.s $f18, $f12
/* 01298 808608E8 4600428D */  trunc.w.s $f10, $f8
/* 0129C 808608EC 44199000 */  mfc1    $t9, $f18
/* 012A0 808608F0 44045000 */  mfc1    $a0, $f10
/* 012A4 808608F4 45020004 */  bc1fl   .L80860908
/* 012A8 808608F8 46000087 */  neg.s   $f2, $f0
/* 012AC 808608FC 10000002 */  beq     $zero, $zero, .L80860908
/* 012B0 80860900 46000086 */  mov.s   $f2, $f0
/* 012B4 80860904 46000087 */  neg.s   $f2, $f0
.L80860908:
/* 012B8 80860908 50790011 */  beql    $v1, $t9, .L80860950
/* 012BC 8086090C 8E0A07E8 */  lw      $t2, 0x07E8($s0)           ## 000007E8
/* 012C0 80860910 4600110D */  trunc.w.s $f4, $f2
/* 012C4 80860914 44092000 */  mfc1    $t1, $f4
/* 012C8 80860918 00000000 */  nop
/* 012CC 8086091C 01231021 */  addu    $v0, $t1, $v1
/* 012D0 80860920 28410002 */  slti    $at, $v0, 0x0002
/* 012D4 80860924 54200003 */  bnel    $at, $zero, .L80860934
/* 012D8 80860928 28810007 */  slti    $at, $a0, 0x0007
/* 012DC 8086092C 18800004 */  blez    $a0, .L80860940
/* 012E0 80860930 28810007 */  slti    $at, $a0, 0x0007
.L80860934:
/* 012E4 80860934 10200005 */  beq     $at, $zero, .L8086094C
/* 012E8 80860938 28410008 */  slti    $at, $v0, 0x0008
/* 012EC 8086093C 14200003 */  bne     $at, $zero, .L8086094C
.L80860940:
/* 012F0 80860940 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 012F4 80860944 0C00BE0A */  jal     Audio_PlayActorSound2

/* 012F8 80860948 2405383D */  addiu   $a1, $zero, 0x383D         ## $a1 = 0000383D
.L8086094C:
/* 012FC 8086094C 8E0A07E8 */  lw      $t2, 0x07E8($s0)           ## 000007E8
.L80860950:
/* 01300 80860950 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01304 80860954 314B001F */  andi    $t3, $t2, 0x001F           ## $t3 = 00000000
/* 01308 80860958 55600011 */  bnel    $t3, $zero, .L808609A0
/* 0130C 8086095C 3C01435C */  lui     $at, 0x435C                ## $at = 435C0000
/* 01310 80860960 0C00BE0A */  jal     Audio_PlayActorSound2

/* 01314 80860964 24053838 */  addiu   $a1, $zero, 0x3838         ## $a1 = 00003838
/* 01318 80860968 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 0131C 8086096C 00000000 */  nop
/* 01320 80860970 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 01324 80860974 44813000 */  mtc1    $at, $f6                   ## $f6 = 5.00
/* 01328 80860978 8E0C07E8 */  lw      $t4, 0x07E8($s0)           ## 000007E8
/* 0132C 8086097C 46060202 */  mul.s   $f8, $f0, $f6
/* 01330 80860980 4600428D */  trunc.w.s $f10, $f8
/* 01334 80860984 440E5000 */  mfc1    $t6, $f10
/* 01338 80860988 00000000 */  nop
/* 0133C 8086098C 000E7C00 */  sll     $t7, $t6, 16
/* 01340 80860990 000FC403 */  sra     $t8, $t7, 16
/* 01344 80860994 0198C821 */  addu    $t9, $t4, $t8
/* 01348 80860998 AE1907E8 */  sw      $t9, 0x07E8($s0)           ## 000007E8
/* 0134C 8086099C 3C01435C */  lui     $at, 0x435C                ## $at = 435C0000
.L808609A0:
/* 01350 808609A0 44818000 */  mtc1    $at, $f16                  ## $f16 = 220.00
/* 01354 808609A4 C6000090 */  lwc1    $f0, 0x0090($s0)           ## 00000090
/* 01358 808609A8 3C014320 */  lui     $at, 0x4320                ## $at = 43200000
/* 0135C 808609AC 4610003C */  c.lt.s  $f0, $f16
/* 01360 808609B0 00000000 */  nop
/* 01364 808609B4 45000033 */  bc1f    .L80860A84
/* 01368 808609B8 00000000 */  nop
/* 0136C 808609BC 44819000 */  mtc1    $at, $f18                  ## $f18 = 160.00
/* 01370 808609C0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01374 808609C4 4600903C */  c.lt.s  $f18, $f0
/* 01378 808609C8 00000000 */  nop
/* 0137C 808609CC 4500002D */  bc1f    .L80860A84
/* 01380 808609D0 00000000 */  nop
/* 01384 808609D4 0C00B821 */  jal     func_8002E084
/* 01388 808609D8 2405071C */  addiu   $a1, $zero, 0x071C         ## $a1 = 0000071C
/* 0138C 808609DC 10400029 */  beq     $v0, $zero, .L80860A84
/* 01390 808609E0 8FA40074 */  lw      $a0, 0x0074($sp)
/* 01394 808609E4 0C00CEA1 */  jal     func_80033A84
/* 01398 808609E8 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 0139C 808609EC 1040000D */  beq     $v0, $zero, .L80860A24
/* 013A0 808609F0 8FA80054 */  lw      $t0, 0x0054($sp)
/* 013A4 808609F4 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 013A8 808609F8 00000000 */  nop
/* 013AC 808609FC 3C018086 */  lui     $at, %hi(D_80864794)       ## $at = 80860000
/* 013B0 80860A00 C4244794 */  lwc1    $f4, %lo(D_80864794)($at)
/* 013B4 80860A04 4604003C */  c.lt.s  $f0, $f4
/* 013B8 80860A08 00000000 */  nop
/* 013BC 80860A0C 4500001D */  bc1f    .L80860A84
/* 013C0 80860A10 00000000 */  nop
/* 013C4 80860A14 0C2186E5 */  jal     func_80861B94
/* 013C8 80860A18 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 013CC 80860A1C 1000006B */  beq     $zero, $zero, .L80860BCC
/* 013D0 80860A20 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860A24:
/* 013D4 80860A24 81090151 */  lb      $t1, 0x0151($t0)           ## 00000151
/* 013D8 80860A28 11200016 */  beq     $t1, $zero, .L80860A84
/* 013DC 80860A2C 00000000 */  nop
/* 013E0 80860A30 920A010C */  lbu     $t2, 0x010C($s0)           ## 0000010C
/* 013E4 80860A34 8FAB0074 */  lw      $t3, 0x0074($sp)
/* 013E8 80860A38 3C0D0001 */  lui     $t5, 0x0001                ## $t5 = 00010000
/* 013EC 80860A3C 1140000F */  beq     $t2, $zero, .L80860A7C
/* 013F0 80860A40 01AB6821 */  addu    $t5, $t5, $t3
/* 013F4 80860A44 8DAD1DE4 */  lw      $t5, 0x1DE4($t5)           ## 00011DE4
/* 013F8 80860A48 01602825 */  or      $a1, $t3, $zero            ## $a1 = 00000000
/* 013FC 80860A4C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01400 80860A50 31AE0001 */  andi    $t6, $t5, 0x0001           ## $t6 = 00000000
/* 01404 80860A54 11C00005 */  beq     $t6, $zero, .L80860A6C
/* 01408 80860A58 00000000 */  nop
/* 0140C 80860A5C 0C2189F1 */  jal     func_808627C4
/* 01410 80860A60 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01414 80860A64 10000059 */  beq     $zero, $zero, .L80860BCC
/* 01418 80860A68 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860A6C:
/* 0141C 80860A6C 0C217EAC */  jal     func_8085FAB0
/* 01420 80860A70 8FA50074 */  lw      $a1, 0x0074($sp)
/* 01424 80860A74 10000003 */  beq     $zero, $zero, .L80860A84
/* 01428 80860A78 00000000 */  nop
.L80860A7C:
/* 0142C 80860A7C 0C2183B0 */  jal     func_80860EC0
/* 01430 80860A80 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80860A84:
/* 01434 80860A84 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 01438 80860A88 00000000 */  nop
/* 0143C 80860A8C 3C018086 */  lui     $at, %hi(D_80864798)       ## $at = 80860000
/* 01440 80860A90 C4264798 */  lwc1    $f6, %lo(D_80864798)($at)
/* 01444 80860A94 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01448 80860A98 4606003C */  c.lt.s  $f0, $f6
/* 0144C 80860A9C 00000000 */  nop
/* 01450 80860AA0 45000004 */  bc1f    .L80860AB4
/* 01454 80860AA4 00000000 */  nop
/* 01458 80860AA8 8602008A */  lh      $v0, 0x008A($s0)           ## 0000008A
/* 0145C 80860AAC A6020032 */  sh      $v0, 0x0032($s0)           ## 00000032
/* 01460 80860AB0 A60200B6 */  sh      $v0, 0x00B6($s0)           ## 000000B6
.L80860AB4:
/* 01464 80860AB4 0C00B821 */  jal     func_8002E084
/* 01468 80860AB8 240511C7 */  addiu   $a1, $zero, 0x11C7         ## $a1 = 000011C7
/* 0146C 80860ABC 1440000E */  bne     $v0, $zero, .L80860AF8
/* 01470 80860AC0 3C0142DC */  lui     $at, 0x42DC                ## $at = 42DC0000
/* 01474 80860AC4 0C21801A */  jal     func_80860068
/* 01478 80860AC8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0147C 80860ACC 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 01480 80860AD0 00000000 */  nop
/* 01484 80860AD4 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 01488 80860AD8 44811000 */  mtc1    $at, $f2                   ## $f2 = 10.00
/* 0148C 80860ADC 00000000 */  nop
/* 01490 80860AE0 46020202 */  mul.s   $f8, $f0, $f2
/* 01494 80860AE4 46024280 */  add.s   $f10, $f8, $f2
/* 01498 80860AE8 4600540D */  trunc.w.s $f16, $f10
/* 0149C 80860AEC 440C8000 */  mfc1    $t4, $f16
/* 014A0 80860AF0 10000035 */  beq     $zero, $zero, .L80860BC8
/* 014A4 80860AF4 AE0C07E8 */  sw      $t4, 0x07E8($s0)           ## 000007E8
.L80860AF8:
/* 014A8 80860AF8 C6120090 */  lwc1    $f18, 0x0090($s0)          ## 00000090
/* 014AC 80860AFC 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 014B0 80860B00 00000000 */  nop
/* 014B4 80860B04 4604903C */  c.lt.s  $f18, $f4
/* 014B8 80860B08 00000000 */  nop
/* 014BC 80860B0C 45000022 */  bc1f    .L80860B98
/* 014C0 80860B10 00000000 */  nop
/* 014C4 80860B14 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 014C8 80860B18 00000000 */  nop
/* 014CC 80860B1C 3C018086 */  lui     $at, %hi(D_8086479C)       ## $at = 80860000
/* 014D0 80860B20 C426479C */  lwc1    $f6, %lo(D_8086479C)($at)
/* 014D4 80860B24 8FB80054 */  lw      $t8, 0x0054($sp)
/* 014D8 80860B28 4600303C */  c.lt.s  $f6, $f0
/* 014DC 80860B2C 00000000 */  nop
/* 014E0 80860B30 45000015 */  bc1f    .L80860B88
/* 014E4 80860B34 00000000 */  nop
/* 014E8 80860B38 8F19067C */  lw      $t9, 0x067C($t8)           ## 0000067C
/* 014EC 80860B3C 33280010 */  andi    $t0, $t9, 0x0010           ## $t0 = 00000000
/* 014F0 80860B40 1100000D */  beq     $t0, $zero, .L80860B78
/* 014F4 80860B44 00000000 */  nop
/* 014F8 80860B48 9209010C */  lbu     $t1, 0x010C($s0)           ## 0000010C
/* 014FC 80860B4C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01500 80860B50 11200005 */  beq     $t1, $zero, .L80860B68
/* 01504 80860B54 00000000 */  nop
/* 01508 80860B58 0C218506 */  jal     func_80861418
/* 0150C 80860B5C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01510 80860B60 1000001A */  beq     $zero, $zero, .L80860BCC
/* 01514 80860B64 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860B68:
/* 01518 80860B68 0C2189F1 */  jal     func_808627C4
/* 0151C 80860B6C 8FA50074 */  lw      $a1, 0x0074($sp)
/* 01520 80860B70 10000016 */  beq     $zero, $zero, .L80860BCC
/* 01524 80860B74 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860B78:
/* 01528 80860B78 0C218506 */  jal     func_80861418
/* 0152C 80860B7C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01530 80860B80 10000012 */  beq     $zero, $zero, .L80860BCC
/* 01534 80860B84 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860B88:
/* 01538 80860B88 0C2187B0 */  jal     func_80861EC0
/* 0153C 80860B8C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01540 80860B90 1000000E */  beq     $zero, $zero, .L80860BCC
/* 01544 80860B94 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860B98:
/* 01548 80860B98 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 0154C 80860B9C 00000000 */  nop
/* 01550 80860BA0 3C018086 */  lui     $at, %hi(D_808647A0)       ## $at = 80860000
/* 01554 80860BA4 C42847A0 */  lwc1    $f8, %lo(D_808647A0)($at)
/* 01558 80860BA8 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 0155C 80860BAC 4608003C */  c.lt.s  $f0, $f8
/* 01560 80860BB0 00000000 */  nop
/* 01564 80860BB4 45020005 */  bc1fl   .L80860BCC
/* 01568 80860BB8 8FBF002C */  lw      $ra, 0x002C($sp)
/* 0156C 80860BBC 44815000 */  mtc1    $at, $f10                  ## $f10 = 5.00
/* 01570 80860BC0 00000000 */  nop
/* 01574 80860BC4 E60A0068 */  swc1    $f10, 0x0068($s0)          ## 00000068
.L80860BC8:
/* 01578 80860BC8 8FBF002C */  lw      $ra, 0x002C($sp)
.L80860BCC:
/* 0157C 80860BCC 8FB00028 */  lw      $s0, 0x0028($sp)
/* 01580 80860BD0 27BD0070 */  addiu   $sp, $sp, 0x0070           ## $sp = 00000000
/* 01584 80860BD4 03E00008 */  jr      $ra
/* 01588 80860BD8 00000000 */  nop


