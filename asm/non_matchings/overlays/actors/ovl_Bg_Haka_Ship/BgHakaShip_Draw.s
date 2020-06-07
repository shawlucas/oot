.rdata
glabel D_8087FAF8
    .asciz "../z_bg_haka_ship.c"
    .balign 4

glabel D_8087FB0C
    .asciz "../z_bg_haka_ship.c"
    .balign 4

glabel D_8087FB20
    .asciz "../z_bg_haka_ship.c"
    .balign 4

glabel D_8087FB34
    .asciz "../z_bg_haka_ship.c"
    .balign 4

glabel D_8087FB48
    .asciz "../z_bg_haka_ship.c"
    .balign 4

glabel D_8087FB5C
    .asciz "../z_bg_haka_ship.c"
    .balign 4

.late_rodata
glabel D_8087FB88
    .float 9.5873802e-5
glabel D_8087FB8C
    .float -3670.0
glabel D_8087FB90
    .float -367.0

.text
glabel BgHakaShip_Draw
/* 006B4 8087F7B4 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 006B8 8087F7B8 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 006BC 8087F7BC AFB00018 */  sw      $s0, 0x0018($sp)           
/* 006C0 8087F7C0 AFA40078 */  sw      $a0, 0x0078($sp)           
/* 006C4 8087F7C4 AFA5007C */  sw      $a1, 0x007C($sp)           
/* 006C8 8087F7C8 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 006CC 8087F7CC 3C068088 */  lui     $a2, %hi(D_8087FAF8)       ## $a2 = 80880000
/* 006D0 8087F7D0 24C6FAF8 */  addiu   $a2, $a2, %lo(D_8087FAF8)  ## $a2 = 8087FAF8
/* 006D4 8087F7D4 27A4005C */  addiu   $a0, $sp, 0x005C           ## $a0 = FFFFFFE4
/* 006D8 8087F7D8 24070210 */  addiu   $a3, $zero, 0x0210         ## $a3 = 00000210
/* 006DC 8087F7DC 0C031AB1 */  jal     Graph_OpenDisps              
/* 006E0 8087F7E0 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 006E4 8087F7E4 8FAF007C */  lw      $t7, 0x007C($sp)           
/* 006E8 8087F7E8 0C024F46 */  jal     func_80093D18              
/* 006EC 8087F7EC 8DE40000 */  lw      $a0, 0x0000($t7)           ## 00000000
/* 006F0 8087F7F0 8FB80078 */  lw      $t8, 0x0078($sp)           
/* 006F4 8087F7F4 3C09DA38 */  lui     $t1, 0xDA38                ## $t1 = DA380000
/* 006F8 8087F7F8 3C08DA38 */  lui     $t0, 0xDA38                ## $t0 = DA380000
/* 006FC 8087F7FC 8719001C */  lh      $t9, 0x001C($t8)           ## 0000001C
/* 00700 8087F800 57200065 */  bnel    $t9, $zero, .L8087F998     
/* 00704 8087F804 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 00708 8087F808 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0070C 8087F80C 35290003 */  ori     $t1, $t1, 0x0003           ## $t1 = DA380003
/* 00710 8087F810 3C058088 */  lui     $a1, %hi(D_8087FB0C)       ## $a1 = 80880000
/* 00714 8087F814 24480008 */  addiu   $t0, $v0, 0x0008           ## $t0 = 00000008
/* 00718 8087F818 AE0802C0 */  sw      $t0, 0x02C0($s0)           ## 000002C0
/* 0071C 8087F81C AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 00720 8087F820 8FAA007C */  lw      $t2, 0x007C($sp)           
/* 00724 8087F824 24A5FB0C */  addiu   $a1, $a1, %lo(D_8087FB0C)  ## $a1 = 8087FB0C
/* 00728 8087F828 24060216 */  addiu   $a2, $zero, 0x0216         ## $a2 = 00000216
/* 0072C 8087F82C 8D440000 */  lw      $a0, 0x0000($t2)           ## 00000000
/* 00730 8087F830 0C0346A2 */  jal     Matrix_NewMtx              
/* 00734 8087F834 AFA20058 */  sw      $v0, 0x0058($sp)           
/* 00738 8087F838 8FA30058 */  lw      $v1, 0x0058($sp)           
/* 0073C 8087F83C 3C0D0601 */  lui     $t5, 0x0601                ## $t5 = 06010000
/* 00740 8087F840 25ADD330 */  addiu   $t5, $t5, 0xD330           ## $t5 = 0600D330
/* 00744 8087F844 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 00748 8087F848 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0074C 8087F84C 3C0CDE00 */  lui     $t4, 0xDE00                ## $t4 = DE000000
/* 00750 8087F850 3C018088 */  lui     $at, %hi(D_8087FB88)       ## $at = 80880000
/* 00754 8087F854 244B0008 */  addiu   $t3, $v0, 0x0008           ## $t3 = 00000008
/* 00758 8087F858 AE0B02C0 */  sw      $t3, 0x02C0($s0)           ## 000002C0
/* 0075C 8087F85C AC4D0004 */  sw      $t5, 0x0004($v0)           ## 00000004
/* 00760 8087F860 AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 00764 8087F864 8FAE0078 */  lw      $t6, 0x0078($sp)           
/* 00768 8087F868 C428FB88 */  lwc1    $f8, %lo(D_8087FB88)($at)  
/* 0076C 8087F86C 3C018088 */  lui     $at, %hi(D_8087FB8C)       ## $at = 80880000
/* 00770 8087F870 85CF016A */  lh      $t7, 0x016A($t6)           ## 0000016A
/* 00774 8087F874 C42CFB8C */  lwc1    $f12, %lo(D_8087FB8C)($at) 
/* 00778 8087F878 3C01441B */  lui     $at, 0x441B                ## $at = 441B0000
/* 0077C 8087F87C 448F2000 */  mtc1    $t7, $f4                   ## $f4 = 0.00
/* 00780 8087F880 44817000 */  mtc1    $at, $f14                  ## $f14 = 620.00
/* 00784 8087F884 3C06448F */  lui     $a2, 0x448F                ## $a2 = 448F0000
/* 00788 8087F888 468021A0 */  cvt.s.w $f6, $f4                   
/* 0078C 8087F88C 34C6C000 */  ori     $a2, $a2, 0xC000           ## $a2 = 448FC000
/* 00790 8087F890 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 00794 8087F894 46083282 */  mul.s   $f10, $f6, $f8             
/* 00798 8087F898 0C034261 */  jal     Matrix_Translate              
/* 0079C 8087F89C E7AA0070 */  swc1    $f10, 0x0070($sp)          
/* 007A0 8087F8A0 C7AC0070 */  lwc1    $f12, 0x0070($sp)          
/* 007A4 8087F8A4 0C0343B5 */  jal     Matrix_RotateZ              
/* 007A8 8087F8A8 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 007AC 8087F8AC 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 007B0 8087F8B0 3C19DA38 */  lui     $t9, 0xDA38                ## $t9 = DA380000
/* 007B4 8087F8B4 37390003 */  ori     $t9, $t9, 0x0003           ## $t9 = DA380003
/* 007B8 8087F8B8 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 007BC 8087F8BC AE1802C0 */  sw      $t8, 0x02C0($s0)           ## 000002C0
/* 007C0 8087F8C0 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 007C4 8087F8C4 8FA8007C */  lw      $t0, 0x007C($sp)           
/* 007C8 8087F8C8 3C058088 */  lui     $a1, %hi(D_8087FB20)       ## $a1 = 80880000
/* 007CC 8087F8CC 24A5FB20 */  addiu   $a1, $a1, %lo(D_8087FB20)  ## $a1 = 8087FB20
/* 007D0 8087F8D0 8D040000 */  lw      $a0, 0x0000($t0)           ## 00000000
/* 007D4 8087F8D4 24060223 */  addiu   $a2, $zero, 0x0223         ## $a2 = 00000223
/* 007D8 8087F8D8 0C0346A2 */  jal     Matrix_NewMtx              
/* 007DC 8087F8DC AFA20050 */  sw      $v0, 0x0050($sp)           
/* 007E0 8087F8E0 8FA30050 */  lw      $v1, 0x0050($sp)           
/* 007E4 8087F8E4 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 007E8 8087F8E8 44806000 */  mtc1    $zero, $f12                ## $f12 = 0.00
/* 007EC 8087F8EC AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 007F0 8087F8F0 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 007F4 8087F8F4 24845A70 */  addiu   $a0, $a0, 0x5A70           ## $a0 = 06005A70
/* 007F8 8087F8F8 3C0ADE00 */  lui     $t2, 0xDE00                ## $t2 = DE000000
/* 007FC 8087F8FC 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 00800 8087F900 AE0902C0 */  sw      $t1, 0x02C0($s0)           ## 000002C0
/* 00804 8087F904 3C06C50F */  lui     $a2, 0xC50F                ## $a2 = C50F0000
/* 00808 8087F908 AC440004 */  sw      $a0, 0x0004($v0)           ## 00000004
/* 0080C 8087F90C AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 00810 8087F910 AFA40028 */  sw      $a0, 0x0028($sp)           
/* 00814 8087F914 34C6C000 */  ori     $a2, $a2, 0xC000           ## $a2 = C50FC000
/* 00818 8087F918 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 0081C 8087F91C 0C034261 */  jal     Matrix_Translate              
/* 00820 8087F920 46006386 */  mov.s   $f14, $f12                 
/* 00824 8087F924 C7A00070 */  lwc1    $f0, 0x0070($sp)           
/* 00828 8087F928 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 0082C 8087F92C 46000300 */  add.s   $f12, $f0, $f0             
/* 00830 8087F930 0C0343B5 */  jal     Matrix_RotateZ              
/* 00834 8087F934 46006307 */  neg.s   $f12, $f12                 
/* 00838 8087F938 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0083C 8087F93C 3C0CDA38 */  lui     $t4, 0xDA38                ## $t4 = DA380000
/* 00840 8087F940 358C0003 */  ori     $t4, $t4, 0x0003           ## $t4 = DA380003
/* 00844 8087F944 244B0008 */  addiu   $t3, $v0, 0x0008           ## $t3 = 00000008
/* 00848 8087F948 AE0B02C0 */  sw      $t3, 0x02C0($s0)           ## 000002C0
/* 0084C 8087F94C AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 00850 8087F950 8FAD007C */  lw      $t5, 0x007C($sp)           
/* 00854 8087F954 3C058088 */  lui     $a1, %hi(D_8087FB34)       ## $a1 = 80880000
/* 00858 8087F958 24A5FB34 */  addiu   $a1, $a1, %lo(D_8087FB34)  ## $a1 = 8087FB34
/* 0085C 8087F95C 8DA40000 */  lw      $a0, 0x0000($t5)           ## 00000000
/* 00860 8087F960 2406022C */  addiu   $a2, $zero, 0x022C         ## $a2 = 0000022C
/* 00864 8087F964 0C0346A2 */  jal     Matrix_NewMtx              
/* 00868 8087F968 AFA20048 */  sw      $v0, 0x0048($sp)           
/* 0086C 8087F96C 8FA30048 */  lw      $v1, 0x0048($sp)           
/* 00870 8087F970 3C0FDE00 */  lui     $t7, 0xDE00                ## $t7 = DE000000
/* 00874 8087F974 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 00878 8087F978 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 0087C 8087F97C 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00880 8087F980 AE0E02C0 */  sw      $t6, 0x02C0($s0)           ## 000002C0
/* 00884 8087F984 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 00888 8087F988 8FB80028 */  lw      $t8, 0x0028($sp)           
/* 0088C 8087F98C 10000017 */  beq     $zero, $zero, .L8087F9EC   
/* 00890 8087F990 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 00894 8087F994 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
.L8087F998:
/* 00898 8087F998 35080003 */  ori     $t0, $t0, 0x0003           ## $t0 = 00000003
/* 0089C 8087F99C 3C058088 */  lui     $a1, %hi(D_8087FB48)       ## $a1 = 80880000
/* 008A0 8087F9A0 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 008A4 8087F9A4 AE1902C0 */  sw      $t9, 0x02C0($s0)           ## 000002C0
/* 008A8 8087F9A8 AC480000 */  sw      $t0, 0x0000($v0)           ## 00000000
/* 008AC 8087F9AC 8FA9007C */  lw      $t1, 0x007C($sp)           
/* 008B0 8087F9B0 24A5FB48 */  addiu   $a1, $a1, %lo(D_8087FB48)  ## $a1 = 8087FB48
/* 008B4 8087F9B4 24060232 */  addiu   $a2, $zero, 0x0232         ## $a2 = 00000232
/* 008B8 8087F9B8 8D240000 */  lw      $a0, 0x0000($t1)           ## 00000000
/* 008BC 8087F9BC 0C0346A2 */  jal     Matrix_NewMtx              
/* 008C0 8087F9C0 AFA20040 */  sw      $v0, 0x0040($sp)           
/* 008C4 8087F9C4 8FA30040 */  lw      $v1, 0x0040($sp)           
/* 008C8 8087F9C8 3C0C0601 */  lui     $t4, 0x0601                ## $t4 = 06010000
/* 008CC 8087F9CC 258CE910 */  addiu   $t4, $t4, 0xE910           ## $t4 = 0600E910
/* 008D0 8087F9D0 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 008D4 8087F9D4 8E0202C0 */  lw      $v0, 0x02C0($s0)           ## 000002C0
/* 008D8 8087F9D8 3C0BDE00 */  lui     $t3, 0xDE00                ## $t3 = DE000000
/* 008DC 8087F9DC 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 008E0 8087F9E0 AE0A02C0 */  sw      $t2, 0x02C0($s0)           ## 000002C0
/* 008E4 8087F9E4 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 008E8 8087F9E8 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
.L8087F9EC:
/* 008EC 8087F9EC 8FAD007C */  lw      $t5, 0x007C($sp)           
/* 008F0 8087F9F0 3C068088 */  lui     $a2, %hi(D_8087FB5C)       ## $a2 = 80880000
/* 008F4 8087F9F4 24C6FB5C */  addiu   $a2, $a2, %lo(D_8087FB5C)  ## $a2 = 8087FB5C
/* 008F8 8087F9F8 27A4005C */  addiu   $a0, $sp, 0x005C           ## $a0 = FFFFFFE4
/* 008FC 8087F9FC 24070238 */  addiu   $a3, $zero, 0x0238         ## $a3 = 00000238
/* 00900 8087FA00 0C031AD5 */  jal     Graph_CloseDisps              
/* 00904 8087FA04 8DA50000 */  lw      $a1, 0x0000($t5)           ## 00000000
/* 00908 8087FA08 8FA30078 */  lw      $v1, 0x0078($sp)           
/* 0090C 8087FA0C 3C0E8088 */  lui     $t6, %hi(func_8087F364)    ## $t6 = 80880000
/* 00910 8087FA10 25CEF364 */  addiu   $t6, $t6, %lo(func_8087F364) ## $t6 = 8087F364
/* 00914 8087FA14 8C620164 */  lw      $v0, 0x0164($v1)           ## 00000164
/* 00918 8087FA18 3C0F8088 */  lui     $t7, %hi(func_8087F400)    ## $t7 = 80880000
/* 0091C 8087FA1C 25EFF400 */  addiu   $t7, $t7, %lo(func_8087F400) ## $t7 = 8087F400
/* 00920 8087FA20 11C20003 */  beq     $t6, $v0, .L8087FA30       
/* 00924 8087FA24 3C018088 */  lui     $at, %hi(D_8087FB90)       ## $at = 80880000
/* 00928 8087FA28 55E20018 */  bnel    $t7, $v0, .L8087FA8C       
/* 0092C 8087FA2C 8FBF001C */  lw      $ra, 0x001C($sp)           
.L8087FA30:
/* 00930 8087FA30 C4700024 */  lwc1    $f16, 0x0024($v1)          ## 00000024
/* 00934 8087FA34 C432FB90 */  lwc1    $f18, %lo(D_8087FB90)($at) 
/* 00938 8087FA38 3C014278 */  lui     $at, 0x4278                ## $at = 42780000
/* 0093C 8087FA3C 44814000 */  mtc1    $at, $f8                   ## $f8 = 62.00
/* 00940 8087FA40 46128100 */  add.s   $f4, $f16, $f18            
/* 00944 8087FA44 8FA4007C */  lw      $a0, 0x007C($sp)           
/* 00948 8087FA48 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 0094C 8087FA4C 34211D60 */  ori     $at, $at, 0x1D60           ## $at = 00011D60
/* 00950 8087FA50 E7A4002C */  swc1    $f4, 0x002C($sp)           
/* 00954 8087FA54 C4660028 */  lwc1    $f6, 0x0028($v1)           ## 00000028
/* 00958 8087FA58 2470016C */  addiu   $s0, $v1, 0x016C           ## $s0 = 0000016C
/* 0095C 8087FA5C 02003025 */  or      $a2, $s0, $zero            ## $a2 = 0000016C
/* 00960 8087FA60 46083280 */  add.s   $f10, $f6, $f8             
/* 00964 8087FA64 27A5002C */  addiu   $a1, $sp, 0x002C           ## $a1 = FFFFFFB4
/* 00968 8087FA68 00812021 */  addu    $a0, $a0, $at              
/* 0096C 8087FA6C E7AA0030 */  swc1    $f10, 0x0030($sp)          
/* 00970 8087FA70 C470002C */  lwc1    $f16, 0x002C($v1)          ## 0000002C
/* 00974 8087FA74 0C029BBD */  jal     func_800A6EF4              
/* 00978 8087FA78 E7B00034 */  swc1    $f16, 0x0034($sp)          
/* 0097C 8087FA7C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 0000016C
/* 00980 8087FA80 0C01E245 */  jal     func_80078914              
/* 00984 8087FA84 2405204F */  addiu   $a1, $zero, 0x204F         ## $a1 = 0000204F
/* 00988 8087FA88 8FBF001C */  lw      $ra, 0x001C($sp)           
.L8087FA8C:
/* 0098C 8087FA8C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00990 8087FA90 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
/* 00994 8087FA94 03E00008 */  jr      $ra                        
/* 00998 8087FA98 00000000 */  nop
/* 0099C 8087FA9C 00000000 */  nop
