.late_rodata
glabel D_8014B280
    .incbin "baserom.z64", 0xBC2420, 0x28 

glabel D_8014B2A8
    .incbin "baserom.z64", 0xBC2448, 0x8 # .double 0.318309886183791

glabel D_8014B2B0
    .incbin "baserom.z64", 0xBC2450, 0x8 # Pi

glabel D_8014B2B8
    .incbin "baserom.z64", 0xBC2458, 0x8 # 3.17865095470564E-8

glabel D_8014B2C0
    .incbin "baserom.z64", 0xBC2460, 0x10 # Nothing?

glabel __libm_qnan_f
    .incbin "baserom.z64", 0xBC2470, 0x10 # Called as a float, but contains a invalid number?

.text
glabel cosf
/* B7B7B0 80104610 E7AC0000 */  swc1  $f12, ($sp)
/* B7B7B4 80104614 8FA20000 */  lw    $v0, ($sp)
/* B7B7B8 80104618 C7A60000 */  lwc1  $f6, ($sp)
/* B7B7BC 8010461C C7AA0000 */  lwc1  $f10, ($sp)
/* B7B7C0 80104620 00027583 */  sra   $t6, $v0, 0x16
/* B7B7C4 80104624 31CF01FF */  andi  $t7, $t6, 0x1ff
/* B7B7C8 80104628 29E10136 */  slti  $at, $t7, 0x136
/* B7B7CC 8010462C 50200049 */  beql  $at, $zero, .L80104754
/* B7B7D0 80104630 460A5032 */   c.eq.s $f10, $f10
/* B7B7D4 80104634 44802000 */  mtc1  $zero, $f4
/* B7B7D8 80104638 3C013FE0 */  li    $at, 0x3FE00000 # 0.000000
/* B7B7DC 8010463C 44819800 */  mtc1  $at, $f19
/* B7B7E0 80104640 4606203C */  c.lt.s $f4, $f6
/* B7B7E4 80104644 C7A00000 */  lwc1  $f0, ($sp)
/* B7B7E8 80104648 3C018015 */  lui   $at, %hi(D_8014B2A8)
/* B7B7EC 8010464C 45020004 */  bc1fl .L80104660
/* B7B7F0 80104650 46000007 */   neg.s $f0, $f0
/* B7B7F4 80104654 10000002 */  b     .L80104660
/* B7B7F8 80104658 46003006 */   mov.s $f0, $f6
/* B7B7FC 8010465C 46000007 */  neg.s $f0, $f0
.L80104660:
/* B7B800 80104660 D428B2A8 */  ldc1  $f8, %lo(D_8014B2A8)($at)
/* B7B804 80104664 46000321 */  cvt.d.s $f12, $f0
/* B7B808 80104668 44809000 */  mtc1  $zero, $f18
/* B7B80C 8010466C 46286282 */  mul.d $f10, $f12, $f8
/* B7B810 80104670 44802800 */  mtc1  $zero, $f5
/* B7B814 80104674 44802000 */  mtc1  $zero, $f4
/* B7B818 80104678 46325380 */  add.d $f14, $f10, $f18
/* B7B81C 8010467C 462E203E */  c.le.d $f4, $f14
/* B7B820 80104680 00000000 */  nop   
/* B7B824 80104684 45020007 */  bc1fl .L801046A4
/* B7B828 80104688 46327281 */   sub.d $f10, $f14, $f18
/* B7B82C 8010468C 46327180 */  add.d $f6, $f14, $f18
/* B7B830 80104690 4620320D */  trunc.w.d $f8, $f6
/* B7B834 80104694 44024000 */  mfc1  $v0, $f8
/* B7B838 80104698 10000006 */  b     .L801046B4
/* B7B83C 8010469C 44823000 */   mtc1  $v0, $f6
/* B7B840 801046A0 46327281 */  sub.d $f10, $f14, $f18
.L801046A4:
/* B7B844 801046A4 4620510D */  trunc.w.d $f4, $f10
/* B7B848 801046A8 44022000 */  mfc1  $v0, $f4
/* B7B84C 801046AC 00000000 */  nop   
/* B7B850 801046B0 44823000 */  mtc1  $v0, $f6
.L801046B4:
/* B7B854 801046B4 3C018015 */  lui   $at, %hi(D_8014B2B0)
/* B7B858 801046B8 D42AB2B0 */  ldc1  $f10, %lo(D_8014B2B0)($at)
/* B7B85C 801046BC 46803221 */  cvt.d.w $f8, $f6
/* B7B860 801046C0 3C018015 */  lui   $at, %hi(D_8014B2B8)
/* B7B864 801046C4 D426B2B8 */  ldc1  $f6, %lo(D_8014B2B8)($at)
/* B7B868 801046C8 3C038015 */  lui   $v1, %hi(D_8014B280) # $v1, 0x8015
/* B7B86C 801046CC 2463B280 */  addiu $v1, %lo(D_8014B280) # addiu $v1, $v1, -0x4d80
/* B7B870 801046D0 46324001 */  sub.d $f0, $f8, $f18
/* B7B874 801046D4 30480001 */  andi  $t0, $v0, 1
/* B7B878 801046D8 462A0102 */  mul.d $f4, $f0, $f10
/* B7B87C 801046DC D46A0020 */  ldc1  $f10, 0x20($v1)
/* B7B880 801046E0 46260202 */  mul.d $f8, $f0, $f6
/* B7B884 801046E4 D4660018 */  ldc1  $f6, 0x18($v1)
/* B7B888 801046E8 46246081 */  sub.d $f2, $f12, $f4
/* B7B88C 801046EC 46281081 */  sub.d $f2, $f2, $f8
/* B7B890 801046F0 46221382 */  mul.d $f14, $f2, $f2
/* B7B894 801046F4 00000000 */  nop   
/* B7B898 801046F8 462E5102 */  mul.d $f4, $f10, $f14
/* B7B89C 801046FC 46262200 */  add.d $f8, $f4, $f6
/* B7B8A0 80104700 D4640010 */  ldc1  $f4, 0x10($v1)
/* B7B8A4 80104704 462E4282 */  mul.d $f10, $f8, $f14
/* B7B8A8 80104708 46245180 */  add.d $f6, $f10, $f4
/* B7B8AC 8010470C D46A0008 */  ldc1  $f10, 8($v1)
/* B7B8B0 80104710 462E3202 */  mul.d $f8, $f6, $f14
/* B7B8B4 80104714 15000007 */  bnez  $t0, .L80104734
/* B7B8B8 80104718 46285400 */   add.d $f16, $f10, $f8
/* B7B8BC 8010471C 462E1102 */  mul.d $f4, $f2, $f14
/* B7B8C0 80104720 00000000 */  nop   
/* B7B8C4 80104724 46302182 */  mul.d $f6, $f4, $f16
/* B7B8C8 80104728 46223280 */  add.d $f10, $f6, $f2
/* B7B8CC 8010472C 03E00008 */  jr    $ra
/* B7B8D0 80104730 46205020 */   cvt.s.d $f0, $f10
.L80104734:
/* B7B8D4 80104734 462E1202 */  mul.d $f8, $f2, $f14
/* B7B8D8 80104738 00000000 */  nop   
/* B7B8DC 8010473C 46304102 */  mul.d $f4, $f8, $f16
/* B7B8E0 80104740 46222180 */  add.d $f6, $f4, $f2
/* B7B8E4 80104744 46203020 */  cvt.s.d $f0, $f6
/* B7B8E8 80104748 03E00008 */  jr    $ra
/* B7B8EC 8010474C 46000007 */   neg.s $f0, $f0
/* B7B8F0 80104750 460A5032 */  c.eq.s $f10, $f10
.L80104754:
/* B7B8F4 80104754 3C018015 */  lui   $at, %hi(D_8014B2C0)
/* B7B8F8 80104758 45010004 */  bc1t  .L8010476C
/* B7B8FC 8010475C 00000000 */   nop   
/* B7B900 80104760 3C018015 */  lui   $at, %hi(__libm_qnan_f)
/* B7B904 80104764 03E00008 */  jr    $ra
/* B7B908 80104768 C420B2D0 */   lwc1  $f0, %lo(__libm_qnan_f)($at)
.L8010476C:
/* B7B90C 8010476C C420B2C0 */  lwc1  $f0, %lo(D_8014B2C0)($at)
/* B7B910 80104770 03E00008 */  jr    $ra
/* B7B914 80104774 00000000 */   nop