.rdata
glabel D_80AC945C
    .asciz "../z_en_oB1.c"
    .balign 4

glabel D_80AC946C
    .asciz "../z_en_oB1.c"
    .balign 4

.text
glabel func_80AC8244
/* 055A4 80AC8244 27BDFFA8 */  addiu   $sp, $sp, 0xFFA8           ## $sp = FFFFFFA8
/* 055A8 80AC8248 AFB10028 */  sw      $s1, 0x0028($sp)
/* 055AC 80AC824C 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 055B0 80AC8250 AFBF002C */  sw      $ra, 0x002C($sp)
/* 055B4 80AC8254 AFB00024 */  sw      $s0, 0x0024($sp)
/* 055B8 80AC8258 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 055BC 80AC825C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 055C0 80AC8260 3C0680AD */  lui     $a2, %hi(D_80AC945C)       ## $a2 = 80AD0000
/* 055C4 80AC8264 24C6945C */  addiu   $a2, $a2, %lo(D_80AC945C)  ## $a2 = 80AC945C
/* 055C8 80AC8268 27A4003C */  addiu   $a0, $sp, 0x003C           ## $a0 = FFFFFFE4
/* 055CC 80AC826C 24071167 */  addiu   $a3, $zero, 0x1167         ## $a3 = 00001167
/* 055D0 80AC8270 0C031AB1 */  jal     Graph_OpenDisps
/* 055D4 80AC8274 AFA5004C */  sw      $a1, 0x004C($sp)
/* 055D8 80AC8278 0C024F46 */  jal     func_80093D18
/* 055DC 80AC827C 8E240000 */  lw      $a0, 0x0000($s1)           ## 00000000
/* 055E0 80AC8280 8FA8004C */  lw      $t0, 0x004C($sp)
/* 055E4 80AC8284 3C0FDB06 */  lui     $t7, 0xDB06                ## $t7 = DB060000
/* 055E8 80AC8288 35EF0020 */  ori     $t7, $t7, 0x0020           ## $t7 = DB060020
/* 055EC 80AC828C 8D0302C0 */  lw      $v1, 0x02C0($t0)           ## 000002C0
/* 055F0 80AC8290 3C0480AD */  lui     $a0, %hi(D_80AC8EB8)       ## $a0 = 80AD0000
/* 055F4 80AC8294 3C068016 */  lui     $a2, %hi(gSegments)
/* 055F8 80AC8298 246E0008 */  addiu   $t6, $v1, 0x0008           ## $t6 = 00000008
/* 055FC 80AC829C AD0E02C0 */  sw      $t6, 0x02C0($t0)           ## 000002C0
/* 05600 80AC82A0 AC6F0000 */  sw      $t7, 0x0000($v1)           ## 00000000
/* 05604 80AC82A4 861801F2 */  lh      $t8, 0x01F2($s0)           ## 000001F2
/* 05608 80AC82A8 24C66FA8 */  addiu   $a2, %lo(gSegments)
/* 0560C 80AC82AC 3C0500FF */  lui     $a1, 0x00FF                ## $a1 = 00FF0000
/* 05610 80AC82B0 0018C880 */  sll     $t9, $t8,  2
/* 05614 80AC82B4 00992021 */  addu    $a0, $a0, $t9
/* 05618 80AC82B8 8C848EB8 */  lw      $a0, %lo(D_80AC8EB8)($a0)
/* 0561C 80AC82BC 34A5FFFF */  ori     $a1, $a1, 0xFFFF           ## $a1 = 00FFFFFF
/* 05620 80AC82C0 3C078000 */  lui     $a3, 0x8000                ## $a3 = 80000000
/* 05624 80AC82C4 00045100 */  sll     $t2, $a0,  4
/* 05628 80AC82C8 000A5F02 */  srl     $t3, $t2, 28
/* 0562C 80AC82CC 000B6080 */  sll     $t4, $t3,  2
/* 05630 80AC82D0 00CC6821 */  addu    $t5, $a2, $t4
/* 05634 80AC82D4 8DAE0000 */  lw      $t6, 0x0000($t5)           ## 00000000
/* 05638 80AC82D8 00854824 */  and     $t1, $a0, $a1
/* 0563C 80AC82DC 3C040601 */  lui     $a0, 0x0601                ## $a0 = 06010000
/* 05640 80AC82E0 012E7821 */  addu    $t7, $t1, $t6
/* 05644 80AC82E4 01E7C021 */  addu    $t8, $t7, $a3
/* 05648 80AC82E8 AC780004 */  sw      $t8, 0x0004($v1)           ## 00000004
/* 0564C 80AC82EC 8D0302C0 */  lw      $v1, 0x02C0($t0)           ## 000002C0
/* 05650 80AC82F0 2484DE80 */  addiu   $a0, $a0, 0xDE80           ## $a0 = 0600DE80
/* 05654 80AC82F4 00045900 */  sll     $t3, $a0,  4
/* 05658 80AC82F8 000B6702 */  srl     $t4, $t3, 28
/* 0565C 80AC82FC 3C0ADB06 */  lui     $t2, 0xDB06                ## $t2 = DB060000
/* 05660 80AC8300 24790008 */  addiu   $t9, $v1, 0x0008           ## $t9 = 00000008
/* 05664 80AC8304 354A0024 */  ori     $t2, $t2, 0x0024           ## $t2 = DB060024
/* 05668 80AC8308 000C6880 */  sll     $t5, $t4,  2
/* 0566C 80AC830C AD1902C0 */  sw      $t9, 0x02C0($t0)           ## 000002C0
/* 05670 80AC8310 00CD4821 */  addu    $t1, $a2, $t5
/* 05674 80AC8314 AC6A0000 */  sw      $t2, 0x0000($v1)           ## 00000000
/* 05678 80AC8318 8D2E0000 */  lw      $t6, 0x0000($t1)           ## 00000000
/* 0567C 80AC831C 00857824 */  and     $t7, $a0, $a1
/* 05680 80AC8320 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 05684 80AC8324 01CFC021 */  addu    $t8, $t6, $t7
/* 05688 80AC8328 0307C821 */  addu    $t9, $t8, $a3
/* 0568C 80AC832C AC790004 */  sw      $t9, 0x0004($v1)           ## 00000004
/* 05690 80AC8330 9207014E */  lbu     $a3, 0x014E($s0)           ## 0000014E
/* 05694 80AC8334 8E06016C */  lw      $a2, 0x016C($s0)           ## 0000016C
/* 05698 80AC8338 8E050150 */  lw      $a1, 0x0150($s0)           ## 00000150
/* 0569C 80AC833C AFB00018 */  sw      $s0, 0x0018($sp)
/* 056A0 80AC8340 AFA00014 */  sw      $zero, 0x0014($sp)
/* 056A4 80AC8344 0C0286B2 */  jal     SkelAnime_DrawSV
/* 056A8 80AC8348 AFA00010 */  sw      $zero, 0x0010($sp)
/* 056AC 80AC834C C6040238 */  lwc1    $f4, 0x0238($s0)           ## 00000238
/* 056B0 80AC8350 8E060230 */  lw      $a2, 0x0230($s0)           ## 00000230
/* 056B4 80AC8354 8E070234 */  lw      $a3, 0x0234($s0)           ## 00000234
/* 056B8 80AC8358 E7A40010 */  swc1    $f4, 0x0010($sp)
/* 056BC 80AC835C 920A0251 */  lbu     $t2, 0x0251($s0)           ## 00000251
/* 056C0 80AC8360 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 056C4 80AC8364 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 056C8 80AC8368 0C2B1D4A */  jal     func_80AC7528
/* 056CC 80AC836C AFAA0014 */  sw      $t2, 0x0014($sp)
/* 056D0 80AC8370 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 056D4 80AC8374 0C2B1E72 */  jal     func_80AC79C8
/* 056D8 80AC8378 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 056DC 80AC837C 3C0680AD */  lui     $a2, %hi(D_80AC946C)       ## $a2 = 80AD0000
/* 056E0 80AC8380 24C6946C */  addiu   $a2, $a2, %lo(D_80AC946C)  ## $a2 = 80AC946C
/* 056E4 80AC8384 27A4003C */  addiu   $a0, $sp, 0x003C           ## $a0 = FFFFFFE4
/* 056E8 80AC8388 8E250000 */  lw      $a1, 0x0000($s1)           ## 00000000
/* 056EC 80AC838C 0C031AD5 */  jal     Graph_CloseDisps
/* 056F0 80AC8390 2407117C */  addiu   $a3, $zero, 0x117C         ## $a3 = 0000117C
/* 056F4 80AC8394 8FBF002C */  lw      $ra, 0x002C($sp)
/* 056F8 80AC8398 8FB00024 */  lw      $s0, 0x0024($sp)
/* 056FC 80AC839C 8FB10028 */  lw      $s1, 0x0028($sp)
/* 05700 80AC83A0 03E00008 */  jr      $ra
/* 05704 80AC83A4 27BD0058 */  addiu   $sp, $sp, 0x0058           ## $sp = 00000000
