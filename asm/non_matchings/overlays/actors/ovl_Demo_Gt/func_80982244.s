.rdata
glabel D_80982978
    .asciz "../z_demo_gt_part6.c"
    .balign 4

glabel D_80982990
    .asciz "../z_demo_gt_part6.c"
    .balign 4

glabel D_809829A8
    .asciz "../z_demo_gt_part6.c"
    .balign 4

.late_rodata
glabel D_80982B50
    .float 9.58738019108e-05

.text
glabel func_80982244
/* 04BD4 80982244 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 04BD8 80982248 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 04BDC 8098224C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 04BE0 80982250 84880172 */  lh      $t0, 0x0172($a0)           ## 00000172
/* 04BE4 80982254 3C018098 */  lui     $at, %hi(D_80982B50)       ## $at = 80980000
/* 04BE8 80982258 C4282B50 */  lwc1    $f8, %lo(D_80982B50)($at)  
/* 04BEC 8098225C 44882000 */  mtc1    $t0, $f4                   ## $f4 = 0.00
/* 04BF0 80982260 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 04BF4 80982264 8C42FA90 */  lw      $v0, -0x0570($v0)          ## 8015FA90
/* 04BF8 80982268 468021A0 */  cvt.s.w $f6, $f4                   
/* 04BFC 8098226C 8CB00000 */  lw      $s0, 0x0000($a1)           ## 00000000
/* 04C00 80982270 3401BE80 */  ori     $at, $zero, 0xBE80         ## $at = 0000BE80
/* 04C04 80982274 24050040 */  addiu   $a1, $zero, 0x0040         ## $a1 = 00000040
/* 04C08 80982278 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04C0C 8098227C 46083002 */  mul.s   $f0, $f6, $f8              
/* 04C10 80982280 46000005 */  abs.s   $f0, $f0                   
/* 04C14 80982284 E7A00068 */  swc1    $f0, 0x0068($sp)           
/* 04C18 80982288 844E14F0 */  lh      $t6, 0x14F0($v0)           ## 801614F0
/* 04C1C 8098228C 448E5000 */  mtc1    $t6, $f10                  ## $f10 = 0.00
/* 04C20 80982290 00000000 */  nop
/* 04C24 80982294 46805420 */  cvt.s.w $f16, $f10                 
/* 04C28 80982298 E7B00064 */  swc1    $f16, 0x0064($sp)          
/* 04C2C 8098229C 844314EE */  lh      $v1, 0x14EE($v0)           ## 801614EE
/* 04C30 809822A0 A7A8006E */  sh      $t0, 0x006E($sp)           
/* 04C34 809822A4 0061C021 */  addu    $t8, $v1, $at              
/* 04C38 809822A8 27194000 */  addiu   $t9, $t8, 0x4000           ## $t9 = 00004000
/* 04C3C 809822AC A7B80062 */  sh      $t8, 0x0062($sp)           
/* 04C40 809822B0 0C031A73 */  jal     Graph_Alloc
              
/* 04C44 809822B4 A7B90060 */  sh      $t9, 0x0060($sp)           
/* 04C48 809822B8 AFA2005C */  sw      $v0, 0x005C($sp)           
/* 04C4C 809822BC 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 04C50 809822C0 87A4006E */  lh      $a0, 0x006E($sp)           
/* 04C54 809822C4 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 04C58 809822C8 44819000 */  mtc1    $at, $f18                  ## $f18 = 1.00
/* 04C5C 809822CC 3C068098 */  lui     $a2, %hi(D_80982978)       ## $a2 = 80980000
/* 04C60 809822D0 24C62978 */  addiu   $a2, $a2, %lo(D_80982978)  ## $a2 = 80982978
/* 04C64 809822D4 46009101 */  sub.s   $f4, $f18, $f0             
/* 04C68 809822D8 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFB4
/* 04C6C 809822DC 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 04C70 809822E0 24070089 */  addiu   $a3, $zero, 0x0089         ## $a3 = 00000089
/* 04C74 809822E4 0C031AB1 */  jal     Graph_OpenDisps              
/* 04C78 809822E8 E7A40040 */  swc1    $f4, 0x0040($sp)           
/* 04C7C 809822EC 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 04C80 809822F0 87A40060 */  lh      $a0, 0x0060($sp)           
/* 04C84 809822F4 44803000 */  mtc1    $zero, $f6                 ## $f6 = 0.00
/* 04C88 809822F8 E7A00050 */  swc1    $f0, 0x0050($sp)           
/* 04C8C 809822FC 87A40060 */  lh      $a0, 0x0060($sp)           
/* 04C90 80982300 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 04C94 80982304 E7A60054 */  swc1    $f6, 0x0054($sp)           
/* 04C98 80982308 E7A00058 */  swc1    $f0, 0x0058($sp)           
/* 04C9C 8098230C 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 04CA0 80982310 87A40062 */  lh      $a0, 0x0062($sp)           
/* 04CA4 80982314 C7A80064 */  lwc1    $f8, 0x0064($sp)           
/* 04CA8 80982318 C7B00040 */  lwc1    $f16, 0x0040($sp)          
/* 04CAC 8098231C 87A4006E */  lh      $a0, 0x006E($sp)           
/* 04CB0 80982320 46080282 */  mul.s   $f10, $f0, $f8             
/* 04CB4 80982324 00000000 */  nop
/* 04CB8 80982328 46105482 */  mul.s   $f18, $f10, $f16           
/* 04CBC 8098232C 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 04CC0 80982330 E7B20044 */  swc1    $f18, 0x0044($sp)          
/* 04CC4 80982334 C7A40064 */  lwc1    $f4, 0x0064($sp)           
/* 04CC8 80982338 87A40062 */  lh      $a0, 0x0062($sp)           
/* 04CCC 8098233C 46040182 */  mul.s   $f6, $f0, $f4              
/* 04CD0 80982340 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 04CD4 80982344 E7A60048 */  swc1    $f6, 0x0048($sp)           
/* 04CD8 80982348 C7A80064 */  lwc1    $f8, 0x0064($sp)           
/* 04CDC 8098234C C7B00040 */  lwc1    $f16, 0x0040($sp)          
/* 04CE0 80982350 46080282 */  mul.s   $f10, $f0, $f8             
/* 04CE4 80982354 00000000 */  nop
/* 04CE8 80982358 46105482 */  mul.s   $f18, $f10, $f16           
/* 04CEC 8098235C 0C034213 */  jal     Matrix_Push              
/* 04CF0 80982360 E7B2004C */  swc1    $f18, 0x004C($sp)          
/* 04CF4 80982364 C7AC0068 */  lwc1    $f12, 0x0068($sp)          
/* 04CF8 80982368 27A50050 */  addiu   $a1, $sp, 0x0050           ## $a1 = FFFFFFD8
/* 04CFC 8098236C 0C0348FF */  jal     func_800D23FC              
/* 04D00 80982370 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 04D04 80982374 C7AC0044 */  lwc1    $f12, 0x0044($sp)          
/* 04D08 80982378 C7AE0048 */  lwc1    $f14, 0x0048($sp)          
/* 04D0C 8098237C 8FA6004C */  lw      $a2, 0x004C($sp)           
/* 04D10 80982380 0C034261 */  jal     Matrix_Translate              
/* 04D14 80982384 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 04D18 80982388 3C058098 */  lui     $a1, %hi(D_80982990)       ## $a1 = 80980000
/* 04D1C 8098238C 24A52990 */  addiu   $a1, $a1, %lo(D_80982990)  ## $a1 = 80982990
/* 04D20 80982390 8FA4005C */  lw      $a0, 0x005C($sp)           
/* 04D24 80982394 0C034695 */  jal     Matrix_ToMtx              
/* 04D28 80982398 24060099 */  addiu   $a2, $zero, 0x0099         ## $a2 = 00000099
/* 04D2C 8098239C 0C034221 */  jal     Matrix_Pull              
/* 04D30 809823A0 00000000 */  nop
/* 04D34 809823A4 0C024F46 */  jal     func_80093D18              
/* 04D38 809823A8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 04D3C 809823AC 8E0302C0 */  lw      $v1, 0x02C0($s0)           ## 000002C0
/* 04D40 809823B0 3C0ADA38 */  lui     $t2, 0xDA38                ## $t2 = DA380000
/* 04D44 809823B4 354A0003 */  ori     $t2, $t2, 0x0003           ## $t2 = DA380003
/* 04D48 809823B8 24690008 */  addiu   $t1, $v1, 0x0008           ## $t1 = 00000008
/* 04D4C 809823BC AE0902C0 */  sw      $t1, 0x02C0($s0)           ## 000002C0
/* 04D50 809823C0 AC6A0000 */  sw      $t2, 0x0000($v1)           ## 00000000
/* 04D54 809823C4 8FAB005C */  lw      $t3, 0x005C($sp)           
/* 04D58 809823C8 3C0E0601 */  lui     $t6, 0x0601                ## $t6 = 06010000
/* 04D5C 809823CC 25CE9B80 */  addiu   $t6, $t6, 0x9B80           ## $t6 = 06009B80
/* 04D60 809823D0 AC6B0004 */  sw      $t3, 0x0004($v1)           ## 00000004
/* 04D64 809823D4 8E0302C0 */  lw      $v1, 0x02C0($s0)           ## 000002C0
/* 04D68 809823D8 3C0DDE00 */  lui     $t5, 0xDE00                ## $t5 = DE000000
/* 04D6C 809823DC 3C068098 */  lui     $a2, %hi(D_809829A8)       ## $a2 = 80980000
/* 04D70 809823E0 246C0008 */  addiu   $t4, $v1, 0x0008           ## $t4 = 00000008
/* 04D74 809823E4 AE0C02C0 */  sw      $t4, 0x02C0($s0)           ## 000002C0
/* 04D78 809823E8 24C629A8 */  addiu   $a2, $a2, %lo(D_809829A8)  ## $a2 = 809829A8
/* 04D7C 809823EC 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFB4
/* 04D80 809823F0 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 04D84 809823F4 240700A3 */  addiu   $a3, $zero, 0x00A3         ## $a3 = 000000A3
/* 04D88 809823F8 AC6E0004 */  sw      $t6, 0x0004($v1)           ## 00000004
/* 04D8C 809823FC 0C031AD5 */  jal     Graph_CloseDisps              
/* 04D90 80982400 AC6D0000 */  sw      $t5, 0x0000($v1)           ## 00000000
/* 04D94 80982404 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 04D98 80982408 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 04D9C 8098240C 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
/* 04DA0 80982410 03E00008 */  jr      $ra                        
/* 04DA4 80982414 00000000 */  nop
