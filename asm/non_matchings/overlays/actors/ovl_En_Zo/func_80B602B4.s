.late_rodata
glabel D_80B62694
    .float 0.02

glabel D_80B62698
    .float 0.12

.text
glabel func_80B602B4
/* 00094 80B602B4 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 00098 80B602B8 3C0F80B6 */  lui     $t7, %hi(D_80B6245C)       ## $t7 = 80B60000
/* 0009C 80B602BC AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 000A0 80B602C0 25EF245C */  addiu   $t7, $t7, %lo(D_80B6245C)  ## $t7 = 80B6245C
/* 000A4 80B602C4 8DF90000 */  lw      $t9, 0x0000($t7)           ## 80B6245C
/* 000A8 80B602C8 27AE0030 */  addiu   $t6, $sp, 0x0030           ## $t6 = FFFFFFF0
/* 000AC 80B602CC 8DF80004 */  lw      $t8, 0x0004($t7)           ## 80B62460
/* 000B0 80B602D0 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFF0
/* 000B4 80B602D4 8DF90008 */  lw      $t9, 0x0008($t7)           ## 80B62464
/* 000B8 80B602D8 3C0880B6 */  lui     $t0, %hi(D_80B62468)       ## $t0 = 80B60000
/* 000BC 80B602DC 25082468 */  addiu   $t0, $t0, %lo(D_80B62468)  ## $t0 = 80B62468
/* 000C0 80B602E0 ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFF4
/* 000C4 80B602E4 ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFF8
/* 000C8 80B602E8 8D0A0000 */  lw      $t2, 0x0000($t0)           ## 80B62468
/* 000CC 80B602EC 27A60024 */  addiu   $a2, $sp, 0x0024           ## $a2 = FFFFFFE4
/* 000D0 80B602F0 248202FC */  addiu   $v0, $a0, 0x02FC           ## $v0 = 000002FC
/* 000D4 80B602F4 ACCA0000 */  sw      $t2, 0x0000($a2)           ## FFFFFFE4
/* 000D8 80B602F8 8D090004 */  lw      $t1, 0x0004($t0)           ## 80B6246C
/* 000DC 80B602FC 00001825 */  or      $v1, $zero, $zero          ## $v1 = 00000000
/* 000E0 80B60300 240C0003 */  addiu   $t4, $zero, 0x0003         ## $t4 = 00000003
/* 000E4 80B60304 ACC90004 */  sw      $t1, 0x0004($a2)           ## FFFFFFE8
/* 000E8 80B60308 8D0A0008 */  lw      $t2, 0x0008($t0)           ## 80B62470
/* 000EC 80B6030C ACCA0008 */  sw      $t2, 0x0008($a2)           ## FFFFFFEC
.L80B60310:
/* 000F0 80B60310 904B0000 */  lbu     $t3, 0x0000($v0)           ## 000002FC
/* 000F4 80B60314 24630001 */  addiu   $v1, $v1, 0x0001           ## $v1 = 00000001
/* 000F8 80B60318 00031C00 */  sll     $v1, $v1, 16               
/* 000FC 80B6031C 1560002A */  bne     $t3, $zero, .L80B603C8     
/* 00100 80B60320 00031C03 */  sra     $v1, $v1, 16               
/* 00104 80B60324 C4840028 */  lwc1    $f4, 0x0028($a0)           ## 00000028
/* 00108 80B60328 C4860084 */  lwc1    $f6, 0x0084($a0)           ## 00000084
/* 0010C 80B6032C C4A80004 */  lwc1    $f8, 0x0004($a1)           ## 00000004
/* 00110 80B60330 46062000 */  add.s   $f0, $f4, $f6              
/* 00114 80B60334 4608003E */  c.le.s  $f0, $f8                   
/* 00118 80B60338 00000000 */  nop
/* 0011C 80B6033C 45030023 */  bc1tl   .L80B603CC                 
/* 00120 80B60340 2861000F */  slti    $at, $v1, 0x000F           
/* 00124 80B60344 A04C0000 */  sb      $t4, 0x0000($v0)           ## 000002FC
/* 00128 80B60348 8CAE0000 */  lw      $t6, 0x0000($a1)           ## 00000000
/* 0012C 80B6034C AC4E0014 */  sw      $t6, 0x0014($v0)           ## 00000310
/* 00130 80B60350 8CAD0004 */  lw      $t5, 0x0004($a1)           ## 00000004
/* 00134 80B60354 AC4D0018 */  sw      $t5, 0x0018($v0)           ## 00000314
/* 00138 80B60358 8CAE0008 */  lw      $t6, 0x0008($a1)           ## 00000008
/* 0013C 80B6035C AC4E001C */  sw      $t6, 0x001C($v0)           ## 00000318
/* 00140 80B60360 8CB80000 */  lw      $t8, 0x0000($a1)           ## 00000000
/* 00144 80B60364 AC58002C */  sw      $t8, 0x002C($v0)           ## 00000328
/* 00148 80B60368 8CAF0004 */  lw      $t7, 0x0004($a1)           ## 00000004
/* 0014C 80B6036C AC4F0030 */  sw      $t7, 0x0030($v0)           ## 0000032C
/* 00150 80B60370 8CB80008 */  lw      $t8, 0x0008($a1)           ## 00000008
/* 00154 80B60374 AC580034 */  sw      $t8, 0x0034($v0)           ## 00000330
/* 00158 80B60378 8CC80000 */  lw      $t0, 0x0000($a2)           ## FFFFFFE4
/* 0015C 80B6037C AC480020 */  sw      $t0, 0x0020($v0)           ## 0000031C
/* 00160 80B60380 8CD90004 */  lw      $t9, 0x0004($a2)           ## FFFFFFE8
/* 00164 80B60384 AC590024 */  sw      $t9, 0x0024($v0)           ## 00000320
/* 00168 80B60388 8CC80008 */  lw      $t0, 0x0008($a2)           ## FFFFFFEC
/* 0016C 80B6038C AC480028 */  sw      $t0, 0x0028($v0)           ## 00000324
/* 00170 80B60390 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00174 80B60394 AFA2003C */  sw      $v0, 0x003C($sp)           
/* 00178 80B60398 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 0017C 80B6039C 44815000 */  mtc1    $at, $f10                  ## $f10 = 0.50
/* 00180 80B603A0 3C0180B6 */  lui     $at, %hi(D_80B62694)       ## $at = 80B60000
/* 00184 80B603A4 C4322694 */  lwc1    $f18, %lo(D_80B62694)($at) 
/* 00188 80B603A8 460A0401 */  sub.s   $f16, $f0, $f10            
/* 0018C 80B603AC 3C0180B6 */  lui     $at, %hi(D_80B62698)       ## $at = 80B60000
/* 00190 80B603B0 C4262698 */  lwc1    $f6, %lo(D_80B62698)($at)  
/* 00194 80B603B4 8FA2003C */  lw      $v0, 0x003C($sp)           
/* 00198 80B603B8 46128102 */  mul.s   $f4, $f16, $f18            
/* 0019C 80B603BC 46062200 */  add.s   $f8, $f4, $f6              
/* 001A0 80B603C0 10000004 */  beq     $zero, $zero, .L80B603D4   
/* 001A4 80B603C4 E4480004 */  swc1    $f8, 0x0004($v0)           ## 00000004
.L80B603C8:
/* 001A8 80B603C8 2861000F */  slti    $at, $v1, 0x000F           
.L80B603CC:
/* 001AC 80B603CC 1420FFD0 */  bne     $at, $zero, .L80B60310     
/* 001B0 80B603D0 24420038 */  addiu   $v0, $v0, 0x0038           ## $v0 = 00000038
.L80B603D4:
/* 001B4 80B603D4 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 001B8 80B603D8 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 001BC 80B603DC 03E00008 */  jr      $ra                        
/* 001C0 80B603E0 00000000 */  nop
