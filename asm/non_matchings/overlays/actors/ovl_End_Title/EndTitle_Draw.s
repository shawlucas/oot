.rdata
glabel D_80B69850
    .asciz "../z_end_title.c"
    .balign 4

glabel D_80B69864
    .asciz "../z_end_title.c"
    .balign 4

glabel D_80B69878
    .asciz "../z_end_title.c"
    .balign 4

glabel D_80B6988C
    .asciz "../z_end_title.c"
    .balign 4

glabel D_80B698A0
    .asciz "../z_end_title.c"
    .balign 4

.late_rodata
glabel D_80B698DC
 .word 0x3E051EB8
glabel D_80B698E0
 .word 0x3E93431D, 0x00000000, 0x00000000, 0x00000000

.text
glabel EndTitle_Draw
/* 00048 80B65768 27BDFF00 */  addiu   $sp, $sp, 0xFF00           ## $sp = FFFFFF00
/* 0004C 80B6576C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00050 80B65770 AFA40100 */  sw      $a0, 0x0100($sp)           
/* 00054 80B65774 AFA50104 */  sw      $a1, 0x0104($sp)           
/* 00058 80B65778 94AF1D74 */  lhu     $t7, 0x1D74($a1)           ## 00001D74
/* 0005C 80B6577C 3C0680B7 */  lui     $a2, %hi(D_80B69850)       ## $a2 = 80B70000
/* 00060 80B65780 24C69850 */  addiu   $a2, $a2, %lo(D_80B69850)  ## $a2 = 80B69850
/* 00064 80B65784 AFAF00F4 */  sw      $t7, 0x00F4($sp)           
/* 00068 80B65788 8CB81C44 */  lw      $t8, 0x1C44($a1)           ## 00001C44
/* 0006C 80B6578C 27A400DC */  addiu   $a0, $sp, 0x00DC           ## $a0 = FFFFFFDC
/* 00070 80B65790 24070193 */  addiu   $a3, $zero, 0x0193         ## $a3 = 00000193
/* 00074 80B65794 AFB800F0 */  sw      $t8, 0x00F0($sp)           
/* 00078 80B65798 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 0007C 80B6579C 0C031AB1 */  jal     Graph_OpenDisps              
/* 00080 80B657A0 AFA500EC */  sw      $a1, 0x00EC($sp)           
/* 00084 80B657A4 8FB90104 */  lw      $t9, 0x0104($sp)           
/* 00088 80B657A8 0C024F61 */  jal     func_80093D84              
/* 0008C 80B657AC 8F240000 */  lw      $a0, 0x0000($t9)           ## 00000000
/* 00090 80B657B0 8FA400F0 */  lw      $a0, 0x00F0($sp)           
/* 00094 80B657B4 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 00098 80B657B8 0C03424C */  jal     Matrix_Mult              
/* 0009C 80B657BC 248409E0 */  addiu   $a0, $a0, 0x09E0           ## $a0 = 000009E0
/* 000A0 80B657C0 3C014316 */  lui     $at, 0x4316                ## $at = 43160000
/* 000A4 80B657C4 44817000 */  mtc1    $at, $f14                  ## $f14 = 150.00
/* 000A8 80B657C8 44806000 */  mtc1    $zero, $f12                ## $f12 = 0.00
/* 000AC 80B657CC 3C06432A */  lui     $a2, 0x432A                ## $a2 = 432A0000
/* 000B0 80B657D0 0C034261 */  jal     Matrix_Translate              
/* 000B4 80B657D4 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 000B8 80B657D8 3C0180B7 */  lui     $at, %hi(D_80B698DC)       ## $at = 80B70000
/* 000BC 80B657DC C42C98DC */  lwc1    $f12, %lo(D_80B698DC)($at) 
/* 000C0 80B657E0 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 000C4 80B657E4 44066000 */  mfc1    $a2, $f12                  
/* 000C8 80B657E8 0C0342A3 */  jal     Matrix_Scale              
/* 000CC 80B657EC 46006386 */  mov.s   $f14, $f12                 
/* 000D0 80B657F0 3C0180B7 */  lui     $at, %hi(D_80B698E0)       ## $at = 80B70000
/* 000D4 80B657F4 C42C98E0 */  lwc1    $f12, %lo(D_80B698E0)($at) 
/* 000D8 80B657F8 0C0342DC */  jal     Matrix_RotateX              
/* 000DC 80B657FC 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 000E0 80B65800 44806000 */  mtc1    $zero, $f12                ## $f12 = 0.00
/* 000E4 80B65804 0C034348 */  jal     Matrix_RotateY              
/* 000E8 80B65808 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 000EC 80B6580C 44806000 */  mtc1    $zero, $f12                ## $f12 = 0.00
/* 000F0 80B65810 0C0343B5 */  jal     Matrix_RotateZ              
/* 000F4 80B65814 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 000F8 80B65818 8FA700EC */  lw      $a3, 0x00EC($sp)           
/* 000FC 80B6581C 3C18DA38 */  lui     $t8, 0xDA38                ## $t8 = DA380000
/* 00100 80B65820 37180003 */  ori     $t8, $t8, 0x0003           ## $t8 = DA380003
/* 00104 80B65824 8CE202D0 */  lw      $v0, 0x02D0($a3)           ## 000002D0
/* 00108 80B65828 3C0580B7 */  lui     $a1, %hi(D_80B69864)       ## $a1 = 80B70000
/* 0010C 80B6582C 24A59864 */  addiu   $a1, $a1, %lo(D_80B69864)  ## $a1 = 80B69864
/* 00110 80B65830 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 00114 80B65834 ACEF02D0 */  sw      $t7, 0x02D0($a3)           ## 000002D0
/* 00118 80B65838 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 0011C 80B6583C 8FAE0104 */  lw      $t6, 0x0104($sp)           
/* 00120 80B65840 2406019C */  addiu   $a2, $zero, 0x019C         ## $a2 = 0000019C
/* 00124 80B65844 8DC40000 */  lw      $a0, 0x0000($t6)           ## 00000000
/* 00128 80B65848 0C0346A2 */  jal     Matrix_NewMtx              
/* 0012C 80B6584C AFA200D8 */  sw      $v0, 0x00D8($sp)           
/* 00130 80B65850 8FA300D8 */  lw      $v1, 0x00D8($sp)           
/* 00134 80B65854 3C0E80B7 */  lui     $t6, %hi(D_80B696C0)       ## $t6 = 80B70000
/* 00138 80B65858 25CE96C0 */  addiu   $t6, $t6, %lo(D_80B696C0)  ## $t6 = 80B696C0
/* 0013C 80B6585C AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 00140 80B65860 8FB900EC */  lw      $t9, 0x00EC($sp)           
/* 00144 80B65864 3C18DE00 */  lui     $t8, 0xDE00                ## $t8 = DE000000
/* 00148 80B65868 3C0680B7 */  lui     $a2, %hi(D_80B69878)       ## $a2 = 80B70000
/* 0014C 80B6586C 8F2202D0 */  lw      $v0, 0x02D0($t9)           ## 000002D0
/* 00150 80B65870 24C69878 */  addiu   $a2, $a2, %lo(D_80B69878)  ## $a2 = 80B69878
/* 00154 80B65874 27A400DC */  addiu   $a0, $sp, 0x00DC           ## $a0 = FFFFFFDC
/* 00158 80B65878 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0015C 80B6587C AF2F02D0 */  sw      $t7, 0x02D0($t9)           ## 000002D0
/* 00160 80B65880 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 00164 80B65884 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 00168 80B65888 8FAF0104 */  lw      $t7, 0x0104($sp)           
/* 0016C 80B6588C 240701A1 */  addiu   $a3, $zero, 0x01A1         ## $a3 = 000001A1
/* 00170 80B65890 0C031AD5 */  jal     Graph_CloseDisps              
/* 00174 80B65894 8DE50000 */  lw      $a1, 0x0000($t7)           ## 00000008
/* 00178 80B65898 8FB90104 */  lw      $t9, 0x0104($sp)           
/* 0017C 80B6589C 3C0680B7 */  lui     $a2, %hi(D_80B6988C)       ## $a2 = 80B70000
/* 00180 80B658A0 24C6988C */  addiu   $a2, $a2, %lo(D_80B6988C)  ## $a2 = 80B6988C
/* 00184 80B658A4 8F250000 */  lw      $a1, 0x0000($t9)           ## 00000000
/* 00188 80B658A8 27A400C0 */  addiu   $a0, $sp, 0x00C0           ## $a0 = FFFFFFC0
/* 0018C 80B658AC 240701A3 */  addiu   $a3, $zero, 0x01A3         ## $a3 = 000001A3
/* 00190 80B658B0 0C031AB1 */  jal     Graph_OpenDisps              
/* 00194 80B658B4 AFA500D0 */  sw      $a1, 0x00D0($sp)           
/* 00198 80B658B8 8FA400F4 */  lw      $a0, 0x00F4($sp)           
/* 0019C 80B658BC 8FA300D0 */  lw      $v1, 0x00D0($sp)           
/* 001A0 80B658C0 8FA50100 */  lw      $a1, 0x0100($sp)           
/* 001A4 80B658C4 2881037B */  slti    $at, $a0, 0x037B           
/* 001A8 80B658C8 54200007 */  bnel    $at, $zero, .L80B658E8     
/* 001AC 80B658CC 2881032B */  slti    $at, $a0, 0x032B           
/* 001B0 80B658D0 90A2014C */  lbu     $v0, 0x014C($a1)           ## 0000014C
/* 001B4 80B658D4 284100C8 */  slti    $at, $v0, 0x00C8           
/* 001B8 80B658D8 10200002 */  beq     $at, $zero, .L80B658E4     
/* 001BC 80B658DC 24580007 */  addiu   $t8, $v0, 0x0007           ## $t8 = 00000007
/* 001C0 80B658E0 A0B8014C */  sb      $t8, 0x014C($a1)           ## 0000014C
.L80B658E4:
/* 001C4 80B658E4 2881032B */  slti    $at, $a0, 0x032B           
.L80B658E8:
/* 001C8 80B658E8 14200006 */  bne     $at, $zero, .L80B65904     
/* 001CC 80B658EC 8FA50100 */  lw      $a1, 0x0100($sp)           
/* 001D0 80B658F0 90A2014D */  lbu     $v0, 0x014D($a1)           ## 0000014D
/* 001D4 80B658F4 284100C8 */  slti    $at, $v0, 0x00C8           
/* 001D8 80B658F8 10200002 */  beq     $at, $zero, .L80B65904     
/* 001DC 80B658FC 244E000F */  addiu   $t6, $v0, 0x000F           ## $t6 = 0000000F
/* 001E0 80B65900 A0AE014D */  sb      $t6, 0x014D($a1)           ## 0000014D
.L80B65904:
/* 001E4 80B65904 28810353 */  slti    $at, $a0, 0x0353           
/* 001E8 80B65908 54200007 */  bnel    $at, $zero, .L80B65928     
/* 001EC 80B6590C 8C6402B0 */  lw      $a0, 0x02B0($v1)           ## 000002B0
/* 001F0 80B65910 90A2014E */  lbu     $v0, 0x014E($a1)           ## 0000014E
/* 001F4 80B65914 284100C8 */  slti    $at, $v0, 0x00C8           
/* 001F8 80B65918 10200002 */  beq     $at, $zero, .L80B65924     
/* 001FC 80B6591C 244F000F */  addiu   $t7, $v0, 0x000F           ## $t7 = 0000000F
/* 00200 80B65920 A0AF014E */  sb      $t7, 0x014E($a1)           ## 0000014E
.L80B65924:
/* 00204 80B65924 8C6402B0 */  lw      $a0, 0x02B0($v1)           ## 000002B0
.L80B65928:
/* 00208 80B65928 0C024FCD */  jal     func_80093F34              
/* 0020C 80B6592C AFA300D0 */  sw      $v1, 0x00D0($sp)           
/* 00210 80B65930 8FA300D0 */  lw      $v1, 0x00D0($sp)           
/* 00214 80B65934 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 00218 80B65938 3C18E300 */  lui     $t8, 0xE300                ## $t8 = E3000000
/* 0021C 80B6593C AC6202B0 */  sw      $v0, 0x02B0($v1)           ## 000002B0
/* 00220 80B65940 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 00224 80B65944 37181001 */  ori     $t8, $t8, 0x1001           ## $t8 = E3001001
/* 00228 80B65948 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 0022C 80B6594C AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 00230 80B65950 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00234 80B65954 3C19FF78 */  lui     $t9, 0xFF78                ## $t9 = FF780000
/* 00238 80B65958 37391E00 */  ori     $t9, $t9, 0x1E00           ## $t9 = FF781E00
/* 0023C 80B6595C 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00240 80B65960 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 00244 80B65964 3C0FFB00 */  lui     $t7, 0xFB00                ## $t7 = FB000000
/* 00248 80B65968 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 0024C 80B6596C AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00250 80B65970 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00254 80B65974 3C0F0C18 */  lui     $t7, 0x0C18                ## $t7 = 0C180000
/* 00258 80B65978 3C0EE200 */  lui     $t6, 0xE200                ## $t6 = E2000000
/* 0025C 80B6597C 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00260 80B65980 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 00264 80B65984 35CE001C */  ori     $t6, $t6, 0x001C           ## $t6 = E200001C
/* 00268 80B65988 35EF4240 */  ori     $t7, $t7, 0x4240           ## $t7 = 0C184240
/* 0026C 80B6598C AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 00270 80B65990 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 00274 80B65994 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00278 80B65998 3C18D9F0 */  lui     $t8, 0xD9F0                ## $t8 = D9F00000
/* 0027C 80B6599C 3718FBFF */  ori     $t8, $t8, 0xFBFF           ## $t8 = D9F0FBFF
/* 00280 80B659A0 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 00284 80B659A4 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 00288 80B659A8 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0028C 80B659AC AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 00290 80B659B0 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00294 80B659B4 3C195FFE */  lui     $t9, 0x5FFE                ## $t9 = 5FFE0000
/* 00298 80B659B8 3C0FFC30 */  lui     $t7, 0xFC30                ## $t7 = FC300000
/* 0029C 80B659BC 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 002A0 80B659C0 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 002A4 80B659C4 35EF97FF */  ori     $t7, $t7, 0x97FF           ## $t7 = FC3097FF
/* 002A8 80B659C8 3739FE38 */  ori     $t9, $t9, 0xFE38           ## $t9 = 5FFEFE38
/* 002AC 80B659CC AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 002B0 80B659D0 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 002B4 80B659D4 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 002B8 80B659D8 3C07FA00 */  lui     $a3, 0xFA00                ## $a3 = FA000000
/* 002BC 80B659DC 34E70080 */  ori     $a3, $a3, 0x0080           ## $a3 = FA000080
/* 002C0 80B659E0 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 002C4 80B659E4 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 002C8 80B659E8 AC470000 */  sw      $a3, 0x0000($v0)           ## 00000000
/* 002CC 80B659EC 8FAE0100 */  lw      $t6, 0x0100($sp)           
/* 002D0 80B659F0 3C0F80B6 */  lui     $t7, %hi(D_80B670E0)       ## $t7 = 80B60000
/* 002D4 80B659F4 25EF70E0 */  addiu   $t7, $t7, %lo(D_80B670E0)  ## $t7 = 80B670E0
/* 002D8 80B659F8 91D9014C */  lbu     $t9, 0x014C($t6)           ## 00000154
/* 002DC 80B659FC 3C0EFD68 */  lui     $t6, 0xFD68                ## $t6 = FD680000
/* 002E0 80B65A00 35CE004F */  ori     $t6, $t6, 0x004F           ## $t6 = FD68004F
/* 002E4 80B65A04 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 002E8 80B65A08 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 002EC 80B65A0C 3C05F568 */  lui     $a1, 0xF568                ## $a1 = F5680000
/* 002F0 80B65A10 34A51600 */  ori     $a1, $a1, 0x1600           ## $a1 = F5681600
/* 002F4 80B65A14 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 002F8 80B65A18 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 002FC 80B65A1C AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 00300 80B65A20 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 00304 80B65A24 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00308 80B65A28 3C080700 */  lui     $t0, 0x0700                ## $t0 = 07000000
/* 0030C 80B65A2C 3C09E600 */  lui     $t1, 0xE600                ## $t1 = E6000000
/* 00310 80B65A30 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 00314 80B65A34 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 00318 80B65A38 AC480004 */  sw      $t0, 0x0004($v0)           ## 00000004
/* 0031C 80B65A3C AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 00320 80B65A40 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00324 80B65A44 3C0F0714 */  lui     $t7, 0x0714                ## $t7 = 07140000
/* 00328 80B65A48 35EF0060 */  ori     $t7, $t7, 0x0060           ## $t7 = 07140060
/* 0032C 80B65A4C 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00330 80B65A50 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 00334 80B65A54 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 00338 80B65A58 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 0033C 80B65A5C 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00340 80B65A60 3C0AF400 */  lui     $t2, 0xF400                ## $t2 = F4000000
/* 00344 80B65A64 3C06E700 */  lui     $a2, 0xE700                ## $a2 = E7000000
/* 00348 80B65A68 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 0034C 80B65A6C AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 00350 80B65A70 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 00354 80B65A74 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 00358 80B65A78 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 0035C 80B65A7C 3C0F0014 */  lui     $t7, 0x0014                ## $t7 = 00140000
/* 00360 80B65A80 35EF0060 */  ori     $t7, $t7, 0x0060           ## $t7 = 00140060
/* 00364 80B65A84 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 00368 80B65A88 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 0036C 80B65A8C AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 00370 80B65A90 AC460000 */  sw      $a2, 0x0000($v0)           ## 00000000
/* 00374 80B65A94 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00378 80B65A98 3C0BF200 */  lui     $t3, 0xF200                ## $t3 = F2000000
/* 0037C 80B65A9C 3C0CE100 */  lui     $t4, 0xE100                ## $t4 = E1000000
/* 00380 80B65AA0 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00384 80B65AA4 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 00388 80B65AA8 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0038C 80B65AAC AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 00390 80B65AB0 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00394 80B65AB4 3C18E432 */  lui     $t8, 0xE432                ## $t8 = E4320000
/* 00398 80B65AB8 371801C4 */  ori     $t8, $t8, 0x01C4           ## $t8 = E43201C4
/* 0039C 80B65ABC 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 003A0 80B65AC0 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 003A4 80B65AC4 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 003A8 80B65AC8 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 003AC 80B65ACC 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 003B0 80B65AD0 3C0E001E */  lui     $t6, 0x001E                ## $t6 = 001E0000
/* 003B4 80B65AD4 35CE0168 */  ori     $t6, $t6, 0x0168           ## $t6 = 001E0168
/* 003B8 80B65AD8 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 003BC 80B65ADC AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 003C0 80B65AE0 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 003C4 80B65AE4 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 003C8 80B65AE8 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 003CC 80B65AEC 3C1F0400 */  lui     $ra, 0x0400                ## $ra = 04000000
/* 003D0 80B65AF0 37FF0400 */  ori     $ra, $ra, 0x0400           ## $ra = 04000400
/* 003D4 80B65AF4 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 003D8 80B65AF8 AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 003DC 80B65AFC AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 003E0 80B65B00 AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 003E4 80B65B04 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 003E8 80B65B08 3C0DF100 */  lui     $t5, 0xF100                ## $t5 = F1000000
/* 003EC 80B65B0C 3C05F568 */  lui     $a1, 0xF568                ## $a1 = F5680000
/* 003F0 80B65B10 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 003F4 80B65B14 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 003F8 80B65B18 AC5F0004 */  sw      $ra, 0x0004($v0)           ## 00000004
/* 003FC 80B65B1C AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 00400 80B65B20 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00404 80B65B24 3C1980B6 */  lui     $t9, %hi(D_80B65EA0)       ## $t9 = 80B60000
/* 00408 80B65B28 27395EA0 */  addiu   $t9, $t9, %lo(D_80B65EA0)  ## $t9 = 80B65EA0
/* 0040C 80B65B2C 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00410 80B65B30 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 00414 80B65B34 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 00418 80B65B38 AC460000 */  sw      $a2, 0x0000($v0)           ## 00000000
/* 0041C 80B65B3C 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00420 80B65B40 34A52000 */  ori     $a1, $a1, 0x2000           ## $a1 = F5682000
/* 00424 80B65B44 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00428 80B65B48 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 0042C 80B65B4C AC470000 */  sw      $a3, 0x0000($v0)           ## 00000000
/* 00430 80B65B50 8FAF0100 */  lw      $t7, 0x0100($sp)           
/* 00434 80B65B54 91F8014D */  lbu     $t8, 0x014D($t7)           ## 00000155
/* 00438 80B65B58 3C0FFD68 */  lui     $t7, 0xFD68                ## $t7 = FD680000
/* 0043C 80B65B5C 35EF0077 */  ori     $t7, $t7, 0x0077           ## $t7 = FD680077
/* 00440 80B65B60 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 00444 80B65B64 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00448 80B65B68 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 0044C 80B65B6C AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 00450 80B65B70 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00454 80B65B74 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 00458 80B65B78 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 0045C 80B65B7C 3C19071E */  lui     $t9, 0x071E                ## $t9 = 071E0000
/* 00460 80B65B80 37390060 */  ori     $t9, $t9, 0x0060           ## $t9 = 071E0060
/* 00464 80B65B84 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00468 80B65B88 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 0046C 80B65B8C AC480004 */  sw      $t0, 0x0004($v0)           ## 00000004
/* 00470 80B65B90 AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 00474 80B65B94 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00478 80B65B98 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 0047C 80B65B9C AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 00480 80B65BA0 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 00484 80B65BA4 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 00488 80B65BA8 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 0048C 80B65BAC 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 00490 80B65BB0 AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 00494 80B65BB4 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00498 80B65BB8 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 0049C 80B65BBC 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 004A0 80B65BC0 3C19001E */  lui     $t9, 0x001E                ## $t9 = 001E0000
/* 004A4 80B65BC4 37390060 */  ori     $t9, $t9, 0x0060           ## $t9 = 001E0060
/* 004A8 80B65BC8 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 004AC 80B65BCC AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 004B0 80B65BD0 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 004B4 80B65BD4 AC460000 */  sw      $a2, 0x0000($v0)           ## 00000000
/* 004B8 80B65BD8 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 004BC 80B65BDC 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 004C0 80B65BE0 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 004C4 80B65BE4 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 004C8 80B65BE8 AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 004CC 80B65BEC 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 004D0 80B65BF0 3C0EE437 */  lui     $t6, 0xE437                ## $t6 = E4370000
/* 004D4 80B65BF4 35CE02DC */  ori     $t6, $t6, 0x02DC           ## $t6 = E43702DC
/* 004D8 80B65BF8 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 004DC 80B65BFC AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 004E0 80B65C00 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 004E4 80B65C04 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 004E8 80B65C08 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 004EC 80B65C0C 3C0F0019 */  lui     $t7, 0x0019                ## $t7 = 00190000
/* 004F0 80B65C10 35EF0280 */  ori     $t7, $t7, 0x0280           ## $t7 = 00190280
/* 004F4 80B65C14 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 004F8 80B65C18 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 004FC 80B65C1C AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 00500 80B65C20 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 00504 80B65C24 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00508 80B65C28 3C05F568 */  lui     $a1, 0xF568                ## $a1 = F5680000
/* 0050C 80B65C2C 34A51E00 */  ori     $a1, $a1, 0x1E00           ## $a1 = F5681E00
/* 00510 80B65C30 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 00514 80B65C34 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 00518 80B65C38 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0051C 80B65C3C AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 00520 80B65C40 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00524 80B65C44 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00528 80B65C48 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 0052C 80B65C4C AC5F0004 */  sw      $ra, 0x0004($v0)           ## 00000004
/* 00530 80B65C50 AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 00534 80B65C54 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00538 80B65C58 3C1880B6 */  lui     $t8, %hi(D_80B669E0)       ## $t8 = 80B60000
/* 0053C 80B65C5C 271869E0 */  addiu   $t8, $t8, %lo(D_80B669E0)  ## $t8 = 80B669E0
/* 00540 80B65C60 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00544 80B65C64 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 00548 80B65C68 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0054C 80B65C6C AC460000 */  sw      $a2, 0x0000($v0)           ## 00000000
/* 00550 80B65C70 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00554 80B65C74 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 00558 80B65C78 AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 0055C 80B65C7C AC470000 */  sw      $a3, 0x0000($v0)           ## 00000000
/* 00560 80B65C80 8FB90100 */  lw      $t9, 0x0100($sp)           
/* 00564 80B65C84 932E014E */  lbu     $t6, 0x014E($t9)           ## 00000156
/* 00568 80B65C88 3C19FD68 */  lui     $t9, 0xFD68                ## $t9 = FD680000
/* 0056C 80B65C8C 3739006F */  ori     $t9, $t9, 0x006F           ## $t9 = FD68006F
/* 00570 80B65C90 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
/* 00574 80B65C94 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00578 80B65C98 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0057C 80B65C9C AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 00580 80B65CA0 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 00584 80B65CA4 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 00588 80B65CA8 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 0058C 80B65CAC 3C18071C */  lui     $t8, 0x071C                ## $t8 = 071C0000
/* 00590 80B65CB0 37180040 */  ori     $t8, $t8, 0x0040           ## $t8 = 071C0040
/* 00594 80B65CB4 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00598 80B65CB8 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 0059C 80B65CBC AC480004 */  sw      $t0, 0x0004($v0)           ## 00000004
/* 005A0 80B65CC0 AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 005A4 80B65CC4 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 005A8 80B65CC8 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 005AC 80B65CCC AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 005B0 80B65CD0 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 005B4 80B65CD4 AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 005B8 80B65CD8 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 005BC 80B65CDC 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 005C0 80B65CE0 AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 005C4 80B65CE4 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 005C8 80B65CE8 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 005CC 80B65CEC 8C6402B0 */  lw      $a0, 0x02B0($v1)           ## 000002B0
/* 005D0 80B65CF0 248E0008 */  addiu   $t6, $a0, 0x0008           ## $t6 = 00000008
/* 005D4 80B65CF4 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 005D8 80B65CF8 AC860000 */  sw      $a2, 0x0000($a0)           ## 00000000
/* 005DC 80B65CFC AC800004 */  sw      $zero, 0x0004($a0)         ## 00000004
/* 005E0 80B65D00 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 005E4 80B65D04 3C18001C */  lui     $t8, 0x001C                ## $t8 = 001C0000
/* 005E8 80B65D08 37180040 */  ori     $t8, $t8, 0x0040           ## $t8 = 001C0040
/* 005EC 80B65D0C 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 005F0 80B65D10 AC6F02B0 */  sw      $t7, 0x02B0($v1)           ## 000002B0
/* 005F4 80B65D14 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 005F8 80B65D18 AC450000 */  sw      $a1, 0x0000($v0)           ## 00000000
/* 005FC 80B65D1C 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00600 80B65D20 3C0FE436 */  lui     $t7, 0xE436                ## $t7 = E4360000
/* 00604 80B65D24 35EF0300 */  ori     $t7, $t7, 0x0300           ## $t7 = E4360300
/* 00608 80B65D28 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 0060C 80B65D2C AC7902B0 */  sw      $t9, 0x02B0($v1)           ## 000002B0
/* 00610 80B65D30 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 00614 80B65D34 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 00618 80B65D38 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 0061C 80B65D3C 3C19001A */  lui     $t9, 0x001A                ## $t9 = 001A0000
/* 00620 80B65D40 373902C4 */  ori     $t9, $t9, 0x02C4           ## $t9 = 001A02C4
/* 00624 80B65D44 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00628 80B65D48 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 0062C 80B65D4C AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00630 80B65D50 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 00634 80B65D54 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00638 80B65D58 3C0680B7 */  lui     $a2, %hi(D_80B698A0)       ## $a2 = 80B70000
/* 0063C 80B65D5C 24C698A0 */  addiu   $a2, $a2, %lo(D_80B698A0)  ## $a2 = 80B698A0
/* 00640 80B65D60 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 00644 80B65D64 AC7802B0 */  sw      $t8, 0x02B0($v1)           ## 000002B0
/* 00648 80B65D68 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0064C 80B65D6C AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000000
/* 00650 80B65D70 8C6202B0 */  lw      $v0, 0x02B0($v1)           ## 000002B0
/* 00654 80B65D74 27A400C0 */  addiu   $a0, $sp, 0x00C0           ## $a0 = FFFFFFC0
/* 00658 80B65D78 24070203 */  addiu   $a3, $zero, 0x0203         ## $a3 = 00000203
/* 0065C 80B65D7C 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 00660 80B65D80 AC6E02B0 */  sw      $t6, 0x02B0($v1)           ## 000002B0
/* 00664 80B65D84 AC5F0004 */  sw      $ra, 0x0004($v0)           ## 00000004
/* 00668 80B65D88 AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 0066C 80B65D8C 8FAF0104 */  lw      $t7, 0x0104($sp)           
/* 00670 80B65D90 0C031AD5 */  jal     Graph_CloseDisps              
/* 00674 80B65D94 8DE50000 */  lw      $a1, 0x0000($t7)           ## E4360300
/* 00678 80B65D98 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 0067C 80B65D9C 27BD0100 */  addiu   $sp, $sp, 0x0100           ## $sp = 00000000
/* 00680 80B65DA0 03E00008 */  jr      $ra                        
/* 00684 80B65DA4 00000000 */  nop
