glabel func_80981AA0
/* 04430 80981AA0 27BDFF80 */  addiu   $sp, $sp, 0xFF80           ## $sp = FFFFFF80
/* 04434 80981AA4 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 04438 80981AA8 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 0443C 80981AAC AFA50084 */  sw      $a1, 0x0084($sp)           
/* 04440 80981AB0 84870172 */  lh      $a3, 0x0172($a0)           ## 00000172
/* 04444 80981AB4 3C018098 */  lui     $at, %hi(D_80982B38)       ## $at = 80980000
/* 04448 80981AB8 C4282B38 */  lwc1    $f8, %lo(D_80982B38)($at)  
/* 0444C 80981ABC 44872000 */  mtc1    $a3, $f4                   ## $f4 = 0.00
/* 04450 80981AC0 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 04454 80981AC4 8C42FA90 */  lw      $v0, -0x0570($v0)          ## 8015FA90
/* 04458 80981AC8 468021A0 */  cvt.s.w $f6, $f4                   
/* 0445C 80981ACC 46083002 */  mul.s   $f0, $f6, $f8              
/* 04460 80981AD0 46000005 */  abs.s   $f0, $f0                   
/* 04464 80981AD4 E7A00074 */  swc1    $f0, 0x0074($sp)           
/* 04468 80981AD8 844E14D2 */  lh      $t6, 0x14D2($v0)           ## 801614D2
/* 0446C 80981ADC 448E5000 */  mtc1    $t6, $f10                  ## $f10 = 0.00
/* 04470 80981AE0 00000000 */  nop
/* 04474 80981AE4 46805420 */  cvt.s.w $f16, $f10                 
/* 04478 80981AE8 E7B00070 */  swc1    $f16, 0x0070($sp)          
/* 0447C 80981AEC 844314CC */  lh      $v1, 0x14CC($v0)           ## 801614CC
/* 04480 80981AF0 24784000 */  addiu   $t8, $v1, 0x4000           ## $t8 = 00004000
/* 04484 80981AF4 27194000 */  addiu   $t9, $t8, 0x4000           ## $t9 = 00008000
/* 04488 80981AF8 A7B8006E */  sh      $t8, 0x006E($sp)           
/* 0448C 80981AFC A7B9006C */  sh      $t9, 0x006C($sp)           
/* 04490 80981B00 8CB00000 */  lw      $s0, 0x0000($a1)           ## 00000000
/* 04494 80981B04 24050040 */  addiu   $a1, $zero, 0x0040         ## $a1 = 00000040
/* 04498 80981B08 A7A7007A */  sh      $a3, 0x007A($sp)           
/* 0449C 80981B0C 0C031A73 */  jal     Graph_Alloc
              
/* 044A0 80981B10 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 044A4 80981B14 AFA20064 */  sw      $v0, 0x0064($sp)           
/* 044A8 80981B18 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 044AC 80981B1C 87A4007A */  lh      $a0, 0x007A($sp)           
/* 044B0 80981B20 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 044B4 80981B24 44819000 */  mtc1    $at, $f18                  ## $f18 = 1.00
/* 044B8 80981B28 3C068098 */  lui     $a2, %hi(D_809828E8)       ## $a2 = 80980000
/* 044BC 80981B2C 24C628E8 */  addiu   $a2, $a2, %lo(D_809828E8)  ## $a2 = 809828E8
/* 044C0 80981B30 46009101 */  sub.s   $f4, $f18, $f0             
/* 044C4 80981B34 27A40034 */  addiu   $a0, $sp, 0x0034           ## $a0 = FFFFFFB4
/* 044C8 80981B38 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 044CC 80981B3C 24070114 */  addiu   $a3, $zero, 0x0114         ## $a3 = 00000114
/* 044D0 80981B40 0C031AB1 */  jal     Graph_OpenDisps              
/* 044D4 80981B44 E7A40048 */  swc1    $f4, 0x0048($sp)           
/* 044D8 80981B48 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 044DC 80981B4C 87A4006C */  lh      $a0, 0x006C($sp)           
/* 044E0 80981B50 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 044E4 80981B54 E7A00058 */  swc1    $f0, 0x0058($sp)           
/* 044E8 80981B58 87A4006C */  lh      $a0, 0x006C($sp)           
/* 044EC 80981B5C 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 044F0 80981B60 E7A6005C */  swc1    $f6, 0x005C($sp)           
/* 044F4 80981B64 E7A00060 */  swc1    $f0, 0x0060($sp)           
/* 044F8 80981B68 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 044FC 80981B6C 87A4006E */  lh      $a0, 0x006E($sp)           
/* 04500 80981B70 C7A80070 */  lwc1    $f8, 0x0070($sp)           
/* 04504 80981B74 C7B00048 */  lwc1    $f16, 0x0048($sp)          
/* 04508 80981B78 87A4007A */  lh      $a0, 0x007A($sp)           
/* 0450C 80981B7C 46080282 */  mul.s   $f10, $f0, $f8             
/* 04510 80981B80 00000000 */  nop
/* 04514 80981B84 46105482 */  mul.s   $f18, $f10, $f16           
/* 04518 80981B88 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0451C 80981B8C E7B2004C */  swc1    $f18, 0x004C($sp)          
/* 04520 80981B90 C7A40070 */  lwc1    $f4, 0x0070($sp)           
/* 04524 80981B94 87A4006E */  lh      $a0, 0x006E($sp)           
/* 04528 80981B98 46040182 */  mul.s   $f6, $f0, $f4              
/* 0452C 80981B9C 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 04530 80981BA0 E7A60050 */  swc1    $f6, 0x0050($sp)           
/* 04534 80981BA4 C7A80070 */  lwc1    $f8, 0x0070($sp)           
/* 04538 80981BA8 C7B00048 */  lwc1    $f16, 0x0048($sp)          
/* 0453C 80981BAC 46080282 */  mul.s   $f10, $f0, $f8             
/* 04540 80981BB0 00000000 */  nop
/* 04544 80981BB4 46105482 */  mul.s   $f18, $f10, $f16           
/* 04548 80981BB8 0C034213 */  jal     Matrix_Push              
/* 0454C 80981BBC E7B20054 */  swc1    $f18, 0x0054($sp)          
/* 04550 80981BC0 C7AC0074 */  lwc1    $f12, 0x0074($sp)          
/* 04554 80981BC4 27A50058 */  addiu   $a1, $sp, 0x0058           ## $a1 = FFFFFFD8
/* 04558 80981BC8 0C0348FF */  jal     func_800D23FC              
/* 0455C 80981BCC 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 04560 80981BD0 C7AC004C */  lwc1    $f12, 0x004C($sp)          
/* 04564 80981BD4 C7AE0050 */  lwc1    $f14, 0x0050($sp)          
/* 04568 80981BD8 8FA60054 */  lw      $a2, 0x0054($sp)           
/* 0456C 80981BDC 0C034261 */  jal     Matrix_Translate              
/* 04570 80981BE0 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 04574 80981BE4 3C058098 */  lui     $a1, %hi(D_80982900)       ## $a1 = 80980000
/* 04578 80981BE8 24A52900 */  addiu   $a1, $a1, %lo(D_80982900)  ## $a1 = 80982900
/* 0457C 80981BEC 8FA40064 */  lw      $a0, 0x0064($sp)           
/* 04580 80981BF0 0C034695 */  jal     Matrix_ToMtx              
/* 04584 80981BF4 24060123 */  addiu   $a2, $zero, 0x0123         ## $a2 = 00000123
/* 04588 80981BF8 0C034221 */  jal     Matrix_Pull              
/* 0458C 80981BFC 00000000 */  nop
/* 04590 80981C00 0C024F46 */  jal     func_80093D18              
/* 04594 80981C04 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04598 80981C08 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0459C 80981C0C 3C0ADA38 */  lui     $t2, 0xDA38                ## $t2 = DA380000
/* 045A0 80981C10 354A0002 */  ori     $t2, $t2, 0x0002           ## $t2 = DA380002
/* 045A4 80981C14 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 045A8 80981C18 AE0902C0 */  sw      $t1, 0x02C0($s0)           ## 000002C0
/* 045AC 80981C1C AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 045B0 80981C20 8FAB0064 */  lw      $t3, 0x0064($sp)           
/* 045B4 80981C24 3C0E0601 */  lui     $t6, 0x0601                ## $t6 = 06010000
/* 045B8 80981C28 25CE9610 */  addiu   $t6, $t6, 0x9610           ## $t6 = 06009610
/* 045BC 80981C2C AC4B0004 */  sw      $t3, 0x0004($v0)           ## 00000004
/* 045C0 80981C30 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 045C4 80981C34 3C0DDE00 */  lui     $t5, 0xDE00                ## $t5 = DE000000
/* 045C8 80981C38 3C18D838 */  lui     $t8, 0xD838                ## $t8 = D8380000
/* 045CC 80981C3C 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 045D0 80981C40 AE0C02C0 */  sw      $t4, 0x02C0($s0)           ## 000002C0
/* 045D4 80981C44 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 045D8 80981C48 AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 045DC 80981C4C 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 045E0 80981C50 37180002 */  ori     $t8, $t8, 0x0002           ## $t8 = D8380002
/* 045E4 80981C54 24190040 */  addiu   $t9, $zero, 0x0040         ## $t9 = 00000040
/* 045E8 80981C58 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 045EC 80981C5C AE0F02C0 */  sw      $t7, 0x02C0($s0)           ## 000002C0
/* 045F0 80981C60 3C068098 */  lui     $a2, %hi(D_80982918)       ## $a2 = 80980000
/* 045F4 80981C64 24C62918 */  addiu   $a2, $a2, %lo(D_80982918)  ## $a2 = 80982918
/* 045F8 80981C68 27A40034 */  addiu   $a0, $sp, 0x0034           ## $a0 = FFFFFFB4
/* 045FC 80981C6C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 04600 80981C70 24070133 */  addiu   $a3, $zero, 0x0133         ## $a3 = 00000133
/* 04604 80981C74 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 04608 80981C78 0C031AD5 */  jal     Graph_CloseDisps              
/* 0460C 80981C7C AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 04610 80981C80 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 04614 80981C84 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 04618 80981C88 27BD0080 */  addiu   $sp, $sp, 0x0080           ## $sp = 00000000
/* 0461C 80981C8C 03E00008 */  jr      $ra                        
/* 04620 80981C90 00000000 */  nop


