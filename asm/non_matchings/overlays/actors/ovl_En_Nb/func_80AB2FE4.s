glabel func_80AB2FE4
/* 02254 80AB2FE4 27BDFF90 */  addiu   $sp, $sp, 0xFF90           ## $sp = FFFFFF90
/* 02258 80AB2FE8 AFBF0024 */  sw      $ra, 0x0024($sp)
/* 0225C 80AB2FEC AFA40070 */  sw      $a0, 0x0070($sp)
/* 02260 80AB2FF0 AFA50074 */  sw      $a1, 0x0074($sp)
/* 02264 80AB2FF4 84820274 */  lh      $v0, 0x0274($a0)           ## 00000274
/* 02268 80AB2FF8 3C1880AB */  lui     $t8, %hi(D_80AB430C)       ## $t8 = 80AB0000
/* 0226C 80AB2FFC 3C0680AB */  lui     $a2, %hi(D_80AB50FC)       ## $a2 = 80AB0000
/* 02270 80AB3000 00027880 */  sll     $t7, $v0,  2
/* 02274 80AB3004 030FC021 */  addu    $t8, $t8, $t7
/* 02278 80AB3008 8F18430C */  lw      $t8, %lo(D_80AB430C)($t8)
/* 0227C 80AB300C 24C650FC */  addiu   $a2, $a2, %lo(D_80AB50FC)  ## $a2 = 80AB50FC
/* 02280 80AB3010 27A40048 */  addiu   $a0, $sp, 0x0048           ## $a0 = FFFFFFD8
/* 02284 80AB3014 AFB80060 */  sw      $t8, 0x0060($sp)
/* 02288 80AB3018 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 0228C 80AB301C 2407026F */  addiu   $a3, $zero, 0x026F         ## $a3 = 0000026F
/* 02290 80AB3020 0C031AB1 */  jal     Graph_OpenDisps
/* 02294 80AB3024 AFA50058 */  sw      $a1, 0x0058($sp)
/* 02298 80AB3028 8FA90074 */  lw      $t1, 0x0074($sp)
/* 0229C 80AB302C 0C024F46 */  jal     func_80093D18
/* 022A0 80AB3030 8D240000 */  lw      $a0, 0x0000($t1)           ## 00000000
/* 022A4 80AB3034 8FA80058 */  lw      $t0, 0x0058($sp)
/* 022A8 80AB3038 8FA70060 */  lw      $a3, 0x0060($sp)
/* 022AC 80AB303C 3C0BDB06 */  lui     $t3, 0xDB06                ## $t3 = DB060000
/* 022B0 80AB3040 8D0202C0 */  lw      $v0, 0x02C0($t0)           ## 000002C0
/* 022B4 80AB3044 00076100 */  sll     $t4, $a3,  4
/* 022B8 80AB3048 000C6F02 */  srl     $t5, $t4, 28
/* 022BC 80AB304C 3C0F8016 */  lui     $t7, 0x8016                ## $t7 = 80160000
/* 022C0 80AB3050 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 022C4 80AB3054 25EF6FA8 */  addiu   $t7, $t7, 0x6FA8           ## $t7 = 80166FA8
/* 022C8 80AB3058 000D7080 */  sll     $t6, $t5,  2
/* 022CC 80AB305C 356B0020 */  ori     $t3, $t3, 0x0020           ## $t3 = DB060020
/* 022D0 80AB3060 AD0A02C0 */  sw      $t2, 0x02C0($t0)           ## 000002C0
/* 022D4 80AB3064 01CF2021 */  addu    $a0, $t6, $t7
/* 022D8 80AB3068 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 022DC 80AB306C 8C980000 */  lw      $t8, 0x0000($a0)           ## 00000000
/* 022E0 80AB3070 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 022E4 80AB3074 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 022E8 80AB3078 00E12824 */  and     $a1, $a3, $at
/* 022EC 80AB307C 3C068000 */  lui     $a2, 0x8000                ## $a2 = 80000000
/* 022F0 80AB3080 0305C821 */  addu    $t9, $t8, $a1
/* 022F4 80AB3084 03264821 */  addu    $t1, $t9, $a2
/* 022F8 80AB3088 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 022FC 80AB308C 8D0202C0 */  lw      $v0, 0x02C0($t0)           ## 000002C0
/* 02300 80AB3090 3C0BDB06 */  lui     $t3, 0xDB06                ## $t3 = DB060000
/* 02304 80AB3094 356B0024 */  ori     $t3, $t3, 0x0024           ## $t3 = DB060024
/* 02308 80AB3098 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 0230C 80AB309C AD0A02C0 */  sw      $t2, 0x02C0($t0)           ## 000002C0
/* 02310 80AB30A0 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 02314 80AB30A4 8C8C0000 */  lw      $t4, 0x0000($a0)           ## 00000000
/* 02318 80AB30A8 241900FF */  addiu   $t9, $zero, 0x00FF         ## $t9 = 000000FF
/* 0231C 80AB30AC 3C18FB00 */  lui     $t8, 0xFB00                ## $t8 = FB000000
/* 02320 80AB30B0 01856821 */  addu    $t5, $t4, $a1
/* 02324 80AB30B4 01A67021 */  addu    $t6, $t5, $a2
/* 02328 80AB30B8 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 0232C 80AB30BC 8D0202C0 */  lw      $v0, 0x02C0($t0)           ## 000002C0
/* 02330 80AB30C0 3C0B8011 */  lui     $t3, 0x8011                ## $t3 = 80110000
/* 02334 80AB30C4 3C0ADB06 */  lui     $t2, 0xDB06                ## $t2 = DB060000
/* 02338 80AB30C8 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0233C 80AB30CC AD0F02C0 */  sw      $t7, 0x02C0($t0)           ## 000002C0
/* 02340 80AB30D0 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 02344 80AB30D4 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 02348 80AB30D8 8D0202C0 */  lw      $v0, 0x02C0($t0)           ## 000002C0
/* 0234C 80AB30DC 354A0030 */  ori     $t2, $t2, 0x0030           ## $t2 = DB060030
/* 02350 80AB30E0 256B6290 */  addiu   $t3, $t3, 0x6290           ## $t3 = 80116290
/* 02354 80AB30E4 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 02358 80AB30E8 AD0902C0 */  sw      $t1, 0x02C0($t0)           ## 000002C0
/* 0235C 80AB30EC AC4B0004 */  sw      $t3, 0x0004($v0)           ## 00000004
/* 02360 80AB30F0 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 02364 80AB30F4 8FA30070 */  lw      $v1, 0x0070($sp)
/* 02368 80AB30F8 3C0C80AB */  lui     $t4, %hi(func_80AB2FC0)    ## $t4 = 80AB0000
/* 0236C 80AB30FC 258C2FC0 */  addiu   $t4, $t4, %lo(func_80AB2FC0) ## $t4 = 80AB2FC0
/* 02370 80AB3100 2462014C */  addiu   $v0, $v1, 0x014C           ## $v0 = 0000014C
/* 02374 80AB3104 8C450004 */  lw      $a1, 0x0004($v0)           ## 00000150
/* 02378 80AB3108 8C460020 */  lw      $a2, 0x0020($v0)           ## 0000016C
/* 0237C 80AB310C 90470002 */  lbu     $a3, 0x0002($v0)           ## 0000014E
/* 02380 80AB3110 AFA00014 */  sw      $zero, 0x0014($sp)
/* 02384 80AB3114 AFAC0010 */  sw      $t4, 0x0010($sp)
/* 02388 80AB3118 8FA40074 */  lw      $a0, 0x0074($sp)
/* 0238C 80AB311C 0C0286B2 */  jal     SkelAnime_DrawSV
/* 02390 80AB3120 AFA30018 */  sw      $v1, 0x0018($sp)
/* 02394 80AB3124 8FAD0074 */  lw      $t5, 0x0074($sp)
/* 02398 80AB3128 3C0680AB */  lui     $a2, %hi(D_80AB5118)       ## $a2 = 80AB0000
/* 0239C 80AB312C 24C65118 */  addiu   $a2, $a2, %lo(D_80AB5118)  ## $a2 = 80AB5118
/* 023A0 80AB3130 27A40048 */  addiu   $a0, $sp, 0x0048           ## $a0 = FFFFFFD8
/* 023A4 80AB3134 24070284 */  addiu   $a3, $zero, 0x0284         ## $a3 = 00000284
/* 023A8 80AB3138 0C031AD5 */  jal     Graph_CloseDisps
/* 023AC 80AB313C 8DA50000 */  lw      $a1, 0x0000($t5)           ## 00000000
/* 023B0 80AB3140 8FBF0024 */  lw      $ra, 0x0024($sp)
/* 023B4 80AB3144 27BD0070 */  addiu   $sp, $sp, 0x0070           ## $sp = 00000000
/* 023B8 80AB3148 03E00008 */  jr      $ra
/* 023BC 80AB314C 00000000 */  nop


