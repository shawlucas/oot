glabel func_8003A5B8
/* AB1758 8003A5B8 27BDFF68 */  addiu $sp, $sp, -0x98
/* AB175C 8003A5BC AFBF0054 */  sw    $ra, 0x54($sp)
/* AB1760 8003A5C0 AFBE0050 */  sw    $fp, 0x50($sp)
/* AB1764 8003A5C4 AFB7004C */  sw    $s7, 0x4c($sp)
/* AB1768 8003A5C8 AFB60048 */  sw    $s6, 0x48($sp)
/* AB176C 8003A5CC AFB50044 */  sw    $s5, 0x44($sp)
/* AB1770 8003A5D0 AFB40040 */  sw    $s4, 0x40($sp)
/* AB1774 8003A5D4 AFB3003C */  sw    $s3, 0x3c($sp)
/* AB1778 8003A5D8 AFB20038 */  sw    $s2, 0x38($sp)
/* AB177C 8003A5DC AFB10034 */  sw    $s1, 0x34($sp)
/* AB1780 8003A5E0 AFB00030 */  sw    $s0, 0x30($sp)
/* AB1784 8003A5E4 F7B40028 */  sdc1  $f20, 0x28($sp)
/* AB1788 8003A5E8 AFA600A0 */  sw    $a2, 0xa0($sp)
/* AB178C 8003A5EC AFA700A4 */  sw    $a3, 0xa4($sp)
/* AB1790 8003A5F0 AFA00078 */  sw    $zero, 0x78($sp)
/* AB1794 8003A5F4 94820000 */  lhu   $v0, ($a0)
/* AB1798 8003A5F8 8CAE0000 */  lw    $t6, ($a1)
/* AB179C 8003A5FC 341EFFFF */  li    $fp, 65535
/* AB17A0 8003A600 00A09025 */  move  $s2, $a1
/* AB17A4 8003A604 17C20003 */  bne   $fp, $v0, .L8003A614
/* AB17A8 8003A608 8DD60018 */   lw    $s6, 0x18($t6)
/* AB17AC 8003A60C 10000065 */  b     .L8003A7A4
/* AB17B0 8003A610 00001025 */   move  $v0, $zero
.L8003A614:
/* AB17B4 8003A614 8E450048 */  lw    $a1, 0x48($s2)
/* AB17B8 8003A618 00027880 */  sll   $t7, $v0, 2
/* AB17BC 8003A61C 8E47004C */  lw    $a3, 0x4c($s2)
/* AB17C0 8003A620 C7B400BC */  lwc1  $f20, 0xbc($sp)
/* AB17C4 8003A624 8FB700B8 */  lw    $s7, 0xb8($sp)
/* AB17C8 8003A628 8FB500AC */  lw    $s5, 0xac($sp)
/* AB17CC 8003A62C 8FB400A8 */  lw    $s4, 0xa8($sp)
/* AB17D0 8003A630 27B30084 */  addiu $s3, $sp, 0x84
/* AB17D4 8003A634 00AF8821 */  addu  $s1, $a1, $t7
.L8003A638:
/* AB17D8 8003A638 86220000 */  lh    $v0, ($s1)
/* AB17DC 8003A63C 24010001 */  li    $at, 1
/* AB17E0 8003A640 97A800A2 */  lhu   $t0, 0xa2($sp)
/* AB17E4 8003A644 00E21821 */  addu  $v1, $a3, $v0
/* AB17E8 8003A648 90780000 */  lbu   $t8, ($v1)
/* AB17EC 8003A64C 00023100 */  sll   $a2, $v0, 4
/* AB17F0 8003A650 1301000D */  beq   $t8, $at, .L8003A688
/* AB17F4 8003A654 02C6C821 */   addu  $t9, $s6, $a2
/* AB17F8 8003A658 97240002 */  lhu   $a0, 2($t9)
/* AB17FC 8003A65C 31090007 */  andi  $t1, $t0, 7
/* AB1800 8003A660 00095340 */  sll   $t2, $t1, 0xd
/* AB1804 8003A664 008A5824 */  and   $t3, $a0, $t2
/* AB1808 8003A668 15600007 */  bnez  $t3, .L8003A688
/* AB180C 8003A66C 97A200A6 */   lhu   $v0, 0xa6($sp)
/* AB1810 8003A670 1040000A */  beqz  $v0, .L8003A69C
/* AB1814 8003A674 304C0007 */   andi  $t4, $v0, 7
/* AB1818 8003A678 000C6B40 */  sll   $t5, $t4, 0xd
/* AB181C 8003A67C 008D7024 */  and   $t6, $a0, $t5
/* AB1820 8003A680 55C00007 */  bnezl $t6, .L8003A6A0
/* AB1824 8003A684 24180001 */   li    $t8, 1
.L8003A688:
/* AB1828 8003A688 96220002 */  lhu   $v0, 2($s1)
/* AB182C 8003A68C 13C20044 */  beq   $fp, $v0, .L8003A7A0
/* AB1830 8003A690 00027880 */   sll   $t7, $v0, 2
/* AB1834 8003A694 1000FFE8 */  b     .L8003A638
/* AB1838 8003A698 00AF8821 */   addu  $s1, $a1, $t7
.L8003A69C:
/* AB183C 8003A69C 24180001 */  li    $t8, 1
.L8003A6A0:
/* AB1840 8003A6A0 A0780000 */  sb    $t8, ($v1)
/* AB1844 8003A6A4 8E590000 */  lw    $t9, ($s2)
/* AB1848 8003A6A8 00D68021 */  addu  $s0, $a2, $s6
/* AB184C 8003A6AC 02002025 */  move  $a0, $s0
/* AB1850 8003A6B0 0C00E249 */  jal   func_80038924
/* AB1854 8003A6B4 8F250010 */   lw    $a1, 0x10($t9)
/* AB1858 8003A6B8 44822000 */  mtc1  $v0, $f4
/* AB185C 8003A6BC C6860004 */  lwc1  $f6, 4($s4)
/* AB1860 8003A6C0 02002025 */  move  $a0, $s0
/* AB1864 8003A6C4 46802020 */  cvt.s.w $f0, $f4
/* AB1868 8003A6C8 02803025 */  move  $a2, $s4
/* AB186C 8003A6CC 4600303C */  c.lt.s $f6, $f0
/* AB1870 8003A6D0 00000000 */  nop   
/* AB1874 8003A6D4 45020007 */  bc1fl .L8003A6F4
/* AB1878 8003A6D8 8E480000 */   lw    $t0, ($s2)
/* AB187C 8003A6DC C6A80004 */  lwc1  $f8, 4($s5)
/* AB1880 8003A6E0 4600403C */  c.lt.s $f8, $f0
/* AB1884 8003A6E4 00000000 */  nop   
/* AB1888 8003A6E8 4503002E */  bc1tl .L8003A7A4
/* AB188C 8003A6EC 8FA20078 */   lw    $v0, 0x78($sp)
/* AB1890 8003A6F0 8E480000 */  lw    $t0, ($s2)
.L8003A6F4:
/* AB1894 8003A6F4 8FA900C0 */  lw    $t1, 0xc0($sp)
/* AB1898 8003A6F8 02A03825 */  move  $a3, $s5
/* AB189C 8003A6FC 8D050010 */  lw    $a1, 0x10($t0)
/* AB18A0 8003A700 312A0008 */  andi  $t2, $t1, 8
/* AB18A4 8003A704 000A582B */  sltu  $t3, $zero, $t2
/* AB18A8 8003A708 AFAB0014 */  sw    $t3, 0x14($sp)
/* AB18AC 8003A70C E7B40018 */  swc1  $f20, 0x18($sp)
/* AB18B0 8003A710 0C00E428 */  jal   func_800390A0
/* AB18B4 8003A714 AFB30010 */   sw    $s3, 0x10($sp)
/* AB18B8 8003A718 1040001A */  beqz  $v0, .L8003A784
/* AB18BC 8003A71C 02802025 */   move  $a0, $s4
/* AB18C0 8003A720 0C032D94 */  jal   func_800CB650
/* AB18C4 8003A724 02602825 */   move  $a1, $s3
/* AB18C8 8003A728 C6EA0000 */  lwc1  $f10, ($s7)
/* AB18CC 8003A72C 460A003C */  c.lt.s $f0, $f10
/* AB18D0 8003A730 00000000 */  nop   
/* AB18D4 8003A734 45020014 */  bc1fl .L8003A788
/* AB18D8 8003A738 96220002 */   lhu   $v0, 2($s1)
/* AB18DC 8003A73C E6E00000 */  swc1  $f0, ($s7)
/* AB18E0 8003A740 8E6E0000 */  lw    $t6, ($s3)
/* AB18E4 8003A744 8FAC00B0 */  lw    $t4, 0xb0($sp)
/* AB18E8 8003A748 24080001 */  li    $t0, 1
/* AB18EC 8003A74C AD8E0000 */  sw    $t6, ($t4)
/* AB18F0 8003A750 8E6D0004 */  lw    $t5, 4($s3)
/* AB18F4 8003A754 AD8D0004 */  sw    $t5, 4($t4)
/* AB18F8 8003A758 8E6E0008 */  lw    $t6, 8($s3)
/* AB18FC 8003A75C AD8E0008 */  sw    $t6, 8($t4)
/* AB1900 8003A760 8E780000 */  lw    $t8, ($s3)
/* AB1904 8003A764 AEB80000 */  sw    $t8, ($s5)
/* AB1908 8003A768 8E6F0004 */  lw    $t7, 4($s3)
/* AB190C 8003A76C AEAF0004 */  sw    $t7, 4($s5)
/* AB1910 8003A770 8E780008 */  lw    $t8, 8($s3)
/* AB1914 8003A774 AEB80008 */  sw    $t8, 8($s5)
/* AB1918 8003A778 8FB900B4 */  lw    $t9, 0xb4($sp)
/* AB191C 8003A77C AF300000 */  sw    $s0, ($t9)
/* AB1920 8003A780 AFA80078 */  sw    $t0, 0x78($sp)
.L8003A784:
/* AB1924 8003A784 96220002 */  lhu   $v0, 2($s1)
.L8003A788:
/* AB1928 8003A788 13C20005 */  beq   $fp, $v0, .L8003A7A0
/* AB192C 8003A78C 00024880 */   sll   $t1, $v0, 2
/* AB1930 8003A790 8E450048 */  lw    $a1, 0x48($s2)
/* AB1934 8003A794 8E47004C */  lw    $a3, 0x4c($s2)
/* AB1938 8003A798 1000FFA7 */  b     .L8003A638
/* AB193C 8003A79C 00A98821 */   addu  $s1, $a1, $t1
.L8003A7A0:
/* AB1940 8003A7A0 8FA20078 */  lw    $v0, 0x78($sp)
.L8003A7A4:
/* AB1944 8003A7A4 8FBF0054 */  lw    $ra, 0x54($sp)
/* AB1948 8003A7A8 D7B40028 */  ldc1  $f20, 0x28($sp)
/* AB194C 8003A7AC 8FB00030 */  lw    $s0, 0x30($sp)
/* AB1950 8003A7B0 8FB10034 */  lw    $s1, 0x34($sp)
/* AB1954 8003A7B4 8FB20038 */  lw    $s2, 0x38($sp)
/* AB1958 8003A7B8 8FB3003C */  lw    $s3, 0x3c($sp)
/* AB195C 8003A7BC 8FB40040 */  lw    $s4, 0x40($sp)
/* AB1960 8003A7C0 8FB50044 */  lw    $s5, 0x44($sp)
/* AB1964 8003A7C4 8FB60048 */  lw    $s6, 0x48($sp)
/* AB1968 8003A7C8 8FB7004C */  lw    $s7, 0x4c($sp)
/* AB196C 8003A7CC 8FBE0050 */  lw    $fp, 0x50($sp)
/* AB1970 8003A7D0 03E00008 */  jr    $ra
/* AB1974 8003A7D4 27BD0098 */   addiu $sp, $sp, 0x98

