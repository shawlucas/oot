.rdata

glabel D_809B4EF0
    .asciz "../z_en_arrow.c"
    .balign 4

glabel D_809B4F00
    .asciz "../z_en_arrow.c"
    .balign 4

glabel D_809B4F10
    .asciz "../z_en_arrow.c"
    .balign 4

.late_rodata

glabel D_809B4F5C
 .float 0.0000958738
glabel D_809B4F60
 .float 0.0000958738

.text
glabel EnArrow_Draw
/* 01048 809B4968 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 0104C 809B496C AFBF002C */  sw      $ra, 0x002C($sp)
/* 01050 809B4970 AFB00028 */  sw      $s0, 0x0028($sp)
/* 01054 809B4974 AFA5007C */  sw      $a1, 0x007C($sp)
/* 01058 809B4978 848E001C */  lh      $t6, 0x001C($a0)           ## 0000001C
/* 0105C 809B497C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01060 809B4980 29C10009 */  slti    $at, $t6, 0x0009
/* 01064 809B4984 5020001C */  beql    $at, $zero, .L809B49F8
/* 01068 809B4988 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 0106C 809B498C 0C024F46 */  jal     func_80093D18
/* 01070 809B4990 8CA40000 */  lw      $a0, 0x0000($a1)           ## 00000000
/* 01074 809B4994 3C188016 */  lui     $t8, 0x8016                ## $t8 = 80160000
/* 01078 809B4998 8F18FA90 */  lw      $t8, -0x0570($t8)          ## 8015FA90
/* 0107C 809B499C C60400EC */  lwc1    $f4, 0x00EC($s0)           ## 000000EC
/* 01080 809B49A0 8FA4007C */  lw      $a0, 0x007C($sp)
/* 01084 809B49A4 87190492 */  lh      $t9, 0x0492($t8)           ## 80160492
/* 01088 809B49A8 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 0108C 809B49AC 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 01090 809B49B0 44993000 */  mtc1    $t9, $f6                   ## $f6 = 0.00
/* 01094 809B49B4 00000000 */  nop
/* 01098 809B49B8 46803220 */  cvt.s.w $f8, $f6
/* 0109C 809B49BC 4608203C */  c.lt.s  $f4, $f8
/* 010A0 809B49C0 00000000 */  nop
/* 010A4 809B49C4 45000003 */  bc1f    .L809B49D4
/* 010A8 809B49C8 00000000 */  nop
/* 010AC 809B49CC 10000001 */  beq     $zero, $zero, .L809B49D4
/* 010B0 809B49D0 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L809B49D4:
/* 010B4 809B49D4 8E050150 */  lw      $a1, 0x0150($s0)           ## 00000150
/* 010B8 809B49D8 8E06016C */  lw      $a2, 0x016C($s0)           ## 0000016C
/* 010BC 809B49DC AFA20018 */  sw      $v0, 0x0018($sp)
/* 010C0 809B49E0 AFB00014 */  sw      $s0, 0x0014($sp)
/* 010C4 809B49E4 0C0282D0 */  jal     SkelAnime_LodDraw
/* 010C8 809B49E8 AFA00010 */  sw      $zero, 0x0010($sp)
/* 010CC 809B49EC 100000C9 */  beq     $zero, $zero, .L809B4D14
/* 010D0 809B49F0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 010D4 809B49F4 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
.L809B49F8:
/* 010D8 809B49F8 C6100068 */  lwc1    $f16, 0x0068($s0)          ## 00000068
/* 010DC 809B49FC 46105032 */  c.eq.s  $f10, $f16
/* 010E0 809B4A00 00000000 */  nop
/* 010E4 809B4A04 450300C3 */  bc1tl   .L809B4D14
/* 010E8 809B4A08 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 010EC 809B4A0C 92040248 */  lbu     $a0, 0x0248($s0)           ## 00000248
/* 010F0 809B4A10 00800821 */  addu    $at, $a0, $zero
/* 010F4 809B4A14 00042080 */  sll     $a0, $a0,  2
/* 010F8 809B4A18 00812021 */  addu    $a0, $a0, $at
/* 010FC 809B4A1C 000420C0 */  sll     $a0, $a0,  3
/* 01100 809B4A20 00812023 */  subu    $a0, $a0, $at
/* 01104 809B4A24 00042100 */  sll     $a0, $a0,  4
/* 01108 809B4A28 00812021 */  addu    $a0, $a0, $at
/* 0110C 809B4A2C 000420C0 */  sll     $a0, $a0,  3
/* 01110 809B4A30 00042400 */  sll     $a0, $a0, 16
/* 01114 809B4A34 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 01118 809B4A38 00042403 */  sra     $a0, $a0, 16
/* 0111C 809B4A3C 3C0142FF */  lui     $at, 0x42FF                ## $at = 42FF0000
/* 01120 809B4A40 44811000 */  mtc1    $at, $f2                   ## $f2 = 127.50
/* 01124 809B4A44 240A0001 */  addiu   $t2, $zero, 0x0001         ## $t2 = 00000001
/* 01128 809B4A48 3C06809B */  lui     $a2, %hi(D_809B4EF0)       ## $a2 = 809B0000
/* 0112C 809B4A4C 46020482 */  mul.s   $f18, $f0, $f2
/* 01130 809B4A50 24C64EF0 */  addiu   $a2, $a2, %lo(D_809B4EF0)  ## $a2 = 809B4EF0
/* 01134 809B4A54 27A40054 */  addiu   $a0, $sp, 0x0054           ## $a0 = FFFFFFDC
/* 01138 809B4A58 46029180 */  add.s   $f6, $f18, $f2
/* 0113C 809B4A5C 4449F800 */  cfc1    $t1, $31
/* 01140 809B4A60 44CAF800 */  ctc1    $t2, $31
/* 01144 809B4A64 00000000 */  nop
/* 01148 809B4A68 46003124 */  cvt.w.s $f4, $f6
/* 0114C 809B4A6C 444AF800 */  cfc1    $t2, $31
/* 01150 809B4A70 00000000 */  nop
/* 01154 809B4A74 314A0078 */  andi    $t2, $t2, 0x0078           ## $t2 = 00000000
/* 01158 809B4A78 11400012 */  beq     $t2, $zero, .L809B4AC4
/* 0115C 809B4A7C 3C014F00 */  lui     $at, 0x4F00                ## $at = 4F000000
/* 01160 809B4A80 44812000 */  mtc1    $at, $f4                   ## $f4 = 2147483648.00
/* 01164 809B4A84 240A0001 */  addiu   $t2, $zero, 0x0001         ## $t2 = 00000001
/* 01168 809B4A88 46043101 */  sub.s   $f4, $f6, $f4
/* 0116C 809B4A8C 44CAF800 */  ctc1    $t2, $31
/* 01170 809B4A90 00000000 */  nop
/* 01174 809B4A94 46002124 */  cvt.w.s $f4, $f4
/* 01178 809B4A98 444AF800 */  cfc1    $t2, $31
/* 0117C 809B4A9C 00000000 */  nop
/* 01180 809B4AA0 314A0078 */  andi    $t2, $t2, 0x0078           ## $t2 = 00000000
/* 01184 809B4AA4 15400005 */  bne     $t2, $zero, .L809B4ABC
/* 01188 809B4AA8 00000000 */  nop
/* 0118C 809B4AAC 440A2000 */  mfc1    $t2, $f4
/* 01190 809B4AB0 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 01194 809B4AB4 10000007 */  beq     $zero, $zero, .L809B4AD4
/* 01198 809B4AB8 01415025 */  or      $t2, $t2, $at              ## $t2 = 80000000
.L809B4ABC:
/* 0119C 809B4ABC 10000005 */  beq     $zero, $zero, .L809B4AD4
/* 011A0 809B4AC0 240AFFFF */  addiu   $t2, $zero, 0xFFFF         ## $t2 = FFFFFFFF
.L809B4AC4:
/* 011A4 809B4AC4 440A2000 */  mfc1    $t2, $f4
/* 011A8 809B4AC8 00000000 */  nop
/* 011AC 809B4ACC 0540FFFB */  bltz    $t2, .L809B4ABC
/* 011B0 809B4AD0 00000000 */  nop
.L809B4AD4:
/* 011B4 809B4AD4 8FAB007C */  lw      $t3, 0x007C($sp)
/* 011B8 809B4AD8 A3AA006F */  sb      $t2, 0x006F($sp)
/* 011BC 809B4ADC 44C9F800 */  ctc1    $t1, $31
/* 011C0 809B4AE0 8D650000 */  lw      $a1, 0x0000($t3)           ## 00000000
/* 011C4 809B4AE4 24070542 */  addiu   $a3, $zero, 0x0542         ## $a3 = 00000542
/* 011C8 809B4AE8 0C031AB1 */  jal     Graph_OpenDisps
/* 011CC 809B4AEC AFA50064 */  sw      $a1, 0x0064($sp)
/* 011D0 809B4AF0 8FAC007C */  lw      $t4, 0x007C($sp)
/* 011D4 809B4AF4 0C024F05 */  jal     func_80093C14
/* 011D8 809B4AF8 8D840000 */  lw      $a0, 0x0000($t4)           ## 00000000
/* 011DC 809B4AFC 860D001C */  lh      $t5, 0x001C($s0)           ## 0000001C
/* 011E0 809B4B00 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 011E4 809B4B04 8FA80064 */  lw      $t0, 0x0064($sp)
/* 011E8 809B4B08 15A10016 */  bne     $t5, $at, .L809B4B64
/* 011EC 809B4B0C 3C0EFA00 */  lui     $t6, 0xFA00                ## $t6 = FA000000
/* 011F0 809B4B10 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 011F4 809B4B14 3C0FFA00 */  lui     $t7, 0xFA00                ## $t7 = FA000000
/* 011F8 809B4B18 2418FFFF */  addiu   $t8, $zero, 0xFFFF         ## $t8 = FFFFFFFF
/* 011FC 809B4B1C 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 01200 809B4B20 AD0E02D0 */  sw      $t6, 0x02D0($t0)           ## 000002D0
/* 01204 809B4B24 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 01208 809B4B28 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 0120C 809B4B2C 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 01210 809B4B30 3C09FB00 */  lui     $t1, 0xFB00                ## $t1 = FB000000
/* 01214 809B4B34 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 01218 809B4B38 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 0121C 809B4B3C AD1902D0 */  sw      $t9, 0x02D0($t0)           ## 000002D0
/* 01220 809B4B40 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 01224 809B4B44 93AB006F */  lbu     $t3, 0x006F($sp)
/* 01228 809B4B48 3421FF00 */  ori     $at, $at, 0xFF00           ## $at = 00FFFF00
/* 0122C 809B4B4C 01616025 */  or      $t4, $t3, $at              ## $t4 = 00FFFF00
/* 01230 809B4B50 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 01234 809B4B54 44814000 */  mtc1    $at, $f8                   ## $f8 = 50.00
/* 01238 809B4B58 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 0123C 809B4B5C 10000014 */  beq     $zero, $zero, .L809B4BB0
/* 01240 809B4B60 E7A80068 */  swc1    $f8, 0x0068($sp)
.L809B4B64:
/* 01244 809B4B64 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 01248 809B4B68 3C0F0C00 */  lui     $t7, 0x0C00                ## $t7 = 0C000000
/* 0124C 809B4B6C 35EF00FF */  ori     $t7, $t7, 0x00FF           ## $t7 = 0C0000FF
/* 01250 809B4B70 244D0008 */  addiu   $t5, $v0, 0x0008           ## $t5 = 00000008
/* 01254 809B4B74 AD0D02D0 */  sw      $t5, 0x02D0($t0)           ## 000002D0
/* 01258 809B4B78 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 0125C 809B4B7C AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 01260 809B4B80 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 01264 809B4B84 3C19FB00 */  lui     $t9, 0xFB00                ## $t9 = FB000000
/* 01268 809B4B88 3C01FAFA */  lui     $at, 0xFAFA                ## $at = FAFA0000
/* 0126C 809B4B8C 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 01270 809B4B90 AD1802D0 */  sw      $t8, 0x02D0($t0)           ## 000002D0
/* 01274 809B4B94 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 01278 809B4B98 93AA006F */  lbu     $t2, 0x006F($sp)
/* 0127C 809B4B9C 01415825 */  or      $t3, $t2, $at              ## $t3 = FAFA0000
/* 01280 809B4BA0 3C014316 */  lui     $at, 0x4316                ## $at = 43160000
/* 01284 809B4BA4 44815000 */  mtc1    $at, $f10                  ## $f10 = 150.00
/* 01288 809B4BA8 AC4B0004 */  sw      $t3, 0x0004($v0)           ## 00000004
/* 0128C 809B4BAC E7AA0068 */  swc1    $f10, 0x0068($sp)
.L809B4BB0:
/* 01290 809B4BB0 0C034213 */  jal     Matrix_Push
/* 01294 809B4BB4 AFA80064 */  sw      $t0, 0x0064($sp)
/* 01298 809B4BB8 8FA4007C */  lw      $a0, 0x007C($sp)
/* 0129C 809B4BBC 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 012A0 809B4BC0 34211DA0 */  ori     $at, $at, 0x1DA0           ## $at = 00011DA0
/* 012A4 809B4BC4 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 012A8 809B4BC8 0C03424C */  jal     Matrix_Mult
/* 012AC 809B4BCC 00812021 */  addu    $a0, $a0, $at
/* 012B0 809B4BD0 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 012B4 809B4BD4 C6100068 */  lwc1    $f16, 0x0068($s0)          ## 00000068
/* 012B8 809B4BD8 8FAC007C */  lw      $t4, 0x007C($sp)
/* 012BC 809B4BDC 3C0D0001 */  lui     $t5, 0x0001                ## $t5 = 00010000
/* 012C0 809B4BE0 46100032 */  c.eq.s  $f0, $f16
/* 012C4 809B4BE4 8FA80064 */  lw      $t0, 0x0064($sp)
/* 012C8 809B4BE8 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 012CC 809B4BEC 01AC6821 */  addu    $t5, $t5, $t4
/* 012D0 809B4BF0 45020004 */  bc1fl   .L809B4C04
/* 012D4 809B4BF4 8DAD1DE4 */  lw      $t5, 0x1DE4($t5)           ## 00011DE4
/* 012D8 809B4BF8 10000013 */  beq     $zero, $zero, .L809B4C48
/* 012DC 809B4BFC 46000306 */  mov.s   $f12, $f0
/* 012E0 809B4C00 8DAD1DE4 */  lw      $t5, 0x1DE4($t5)           ## 00011DE4
.L809B4C04:
/* 012E4 809B4C04 3C014F80 */  lui     $at, 0x4F80                ## $at = 4F800000
/* 012E8 809B4C08 31AE00FF */  andi    $t6, $t5, 0x00FF           ## $t6 = 00000000
/* 012EC 809B4C0C 000E7940 */  sll     $t7, $t6,  5
/* 012F0 809B4C10 01EE7823 */  subu    $t7, $t7, $t6
/* 012F4 809B4C14 000F7880 */  sll     $t7, $t7,  2
/* 012F8 809B4C18 01EE7821 */  addu    $t7, $t7, $t6
/* 012FC 809B4C1C 000F7940 */  sll     $t7, $t7,  5
/* 01300 809B4C20 448F9000 */  mtc1    $t7, $f18                  ## $f18 = 0.00
/* 01304 809B4C24 05E10004 */  bgez    $t7, .L809B4C38
/* 01308 809B4C28 468091A0 */  cvt.s.w $f6, $f18
/* 0130C 809B4C2C 44812000 */  mtc1    $at, $f4                   ## $f4 = 4294967296.00
/* 01310 809B4C30 00000000 */  nop
/* 01314 809B4C34 46043180 */  add.s   $f6, $f6, $f4
.L809B4C38:
/* 01318 809B4C38 3C01809B */  lui     $at, %hi(D_809B4F5C)       ## $at = 809B0000
/* 0131C 809B4C3C C4284F5C */  lwc1    $f8, %lo(D_809B4F5C)($at)
/* 01320 809B4C40 46083302 */  mul.s   $f12, $f6, $f8
/* 01324 809B4C44 00000000 */  nop
.L809B4C48:
/* 01328 809B4C48 0C0343B5 */  jal     Matrix_RotateZ
/* 0132C 809B4C4C AFA80064 */  sw      $t0, 0x0064($sp)
/* 01330 809B4C50 C7AC0068 */  lwc1    $f12, 0x0068($sp)
/* 01334 809B4C54 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 01338 809B4C58 44066000 */  mfc1    $a2, $f12
/* 0133C 809B4C5C 0C0342A3 */  jal     Matrix_Scale
/* 01340 809B4C60 46006386 */  mov.s   $f14, $f12
/* 01344 809B4C64 8FA80064 */  lw      $t0, 0x0064($sp)
/* 01348 809B4C68 3C19DA38 */  lui     $t9, 0xDA38                ## $t9 = DA380000
/* 0134C 809B4C6C 37390003 */  ori     $t9, $t9, 0x0003           ## $t9 = DA380003
/* 01350 809B4C70 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 01354 809B4C74 3C05809B */  lui     $a1, %hi(D_809B4F00)       ## $a1 = 809B0000
/* 01358 809B4C78 24A54F00 */  addiu   $a1, $a1, %lo(D_809B4F00)  ## $a1 = 809B4F00
/* 0135C 809B4C7C 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 01360 809B4C80 AD1802D0 */  sw      $t8, 0x02D0($t0)           ## 000002D0
/* 01364 809B4C84 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 01368 809B4C88 8FA9007C */  lw      $t1, 0x007C($sp)
/* 0136C 809B4C8C 2406055E */  addiu   $a2, $zero, 0x055E         ## $a2 = 0000055E
/* 01370 809B4C90 8D240000 */  lw      $a0, 0x0000($t1)           ## 00000000
/* 01374 809B4C94 AFA80064 */  sw      $t0, 0x0064($sp)
/* 01378 809B4C98 0C0346A2 */  jal     Matrix_NewMtx
/* 0137C 809B4C9C AFA20040 */  sw      $v0, 0x0040($sp)
/* 01380 809B4CA0 8FA30040 */  lw      $v1, 0x0040($sp)
/* 01384 809B4CA4 8FA80064 */  lw      $t0, 0x0064($sp)
/* 01388 809B4CA8 3C0C0403 */  lui     $t4, 0x0403                ## $t4 = 04030000
/* 0138C 809B4CAC AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 01390 809B4CB0 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 01394 809B4CB4 258C7880 */  addiu   $t4, $t4, 0x7880           ## $t4 = 04037880
/* 01398 809B4CB8 3C0BDE00 */  lui     $t3, 0xDE00                ## $t3 = DE000000
/* 0139C 809B4CBC 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 013A0 809B4CC0 AD0A02D0 */  sw      $t2, 0x02D0($t0)           ## 000002D0
/* 013A4 809B4CC4 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 013A8 809B4CC8 0C034221 */  jal     Matrix_Pull
/* 013AC 809B4CCC AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 013B0 809B4CD0 860D0032 */  lh      $t5, 0x0032($s0)           ## 00000032
/* 013B4 809B4CD4 3C01809B */  lui     $at, %hi(D_809B4F60)       ## $at = 809B0000
/* 013B8 809B4CD8 C4324F60 */  lwc1    $f18, %lo(D_809B4F60)($at)
/* 013BC 809B4CDC 448D5000 */  mtc1    $t5, $f10                  ## $f10 = 0.00
/* 013C0 809B4CE0 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 013C4 809B4CE4 46805420 */  cvt.s.w $f16, $f10
/* 013C8 809B4CE8 46128302 */  mul.s   $f12, $f16, $f18
/* 013CC 809B4CEC 0C034348 */  jal     Matrix_RotateY
/* 013D0 809B4CF0 00000000 */  nop
/* 013D4 809B4CF4 8FAE007C */  lw      $t6, 0x007C($sp)
/* 013D8 809B4CF8 3C06809B */  lui     $a2, %hi(D_809B4F10)       ## $a2 = 809B0000
/* 013DC 809B4CFC 24C64F10 */  addiu   $a2, $a2, %lo(D_809B4F10)  ## $a2 = 809B4F10
/* 013E0 809B4D00 27A40054 */  addiu   $a0, $sp, 0x0054           ## $a0 = FFFFFFDC
/* 013E4 809B4D04 24070565 */  addiu   $a3, $zero, 0x0565         ## $a3 = 00000565
/* 013E8 809B4D08 0C031AD5 */  jal     Graph_CloseDisps
/* 013EC 809B4D0C 8DC50000 */  lw      $a1, 0x0000($t6)           ## 00000000
/* 013F0 809B4D10 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L809B4D14:
/* 013F4 809B4D14 0C26D200 */  jal     func_809B4800
/* 013F8 809B4D18 8FA5007C */  lw      $a1, 0x007C($sp)
/* 013FC 809B4D1C 8FBF002C */  lw      $ra, 0x002C($sp)
/* 01400 809B4D20 8FB00028 */  lw      $s0, 0x0028($sp)
/* 01404 809B4D24 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
/* 01408 809B4D28 03E00008 */  jr      $ra
/* 0140C 809B4D2C 00000000 */  nop

