.rdata
glabel D_809B23D4
    .asciz "../z_en_anubice.c"
    .balign 4

glabel D_809B23E8
    .asciz "../z_en_anubice.c"
    .balign 4

glabel D_809B23FC
    .asciz "../z_en_anubice.c"
    .balign 4

.text
glabel func_809B2150
/* 01030 809B2150 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 01034 809B2154 3C0F809B */  lui     $t7, %hi(D_809B2334)       ## $t7 = 809B0000
/* 01038 809B2158 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 0103C 809B215C AFA40048 */  sw      $a0, 0x0048($sp)           
/* 01040 809B2160 AFA60050 */  sw      $a2, 0x0050($sp)           
/* 01044 809B2164 AFA70054 */  sw      $a3, 0x0054($sp)           
/* 01048 809B2168 25EF2334 */  addiu   $t7, $t7, %lo(D_809B2334)  ## $t7 = 809B2334
/* 0104C 809B216C 8DF90000 */  lw      $t9, 0x0000($t7)           ## 809B2334
/* 01050 809B2170 27AE0038 */  addiu   $t6, $sp, 0x0038           ## $t6 = FFFFFFF0
/* 01054 809B2174 8DF80004 */  lw      $t8, 0x0004($t7)           ## 809B2338
/* 01058 809B2178 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFF0
/* 0105C 809B217C 8DF90008 */  lw      $t9, 0x0008($t7)           ## 809B233C
/* 01060 809B2180 2401000D */  addiu   $at, $zero, 0x000D         ## $at = 0000000D
/* 01064 809B2184 ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFF4
/* 01068 809B2188 14A1002E */  bne     $a1, $at, .L809B2244       
/* 0106C 809B218C ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFF8
/* 01070 809B2190 8FA90048 */  lw      $t1, 0x0048($sp)           
/* 01074 809B2194 3C06809B */  lui     $a2, %hi(D_809B23D4)       ## $a2 = 809B0000
/* 01078 809B2198 24C623D4 */  addiu   $a2, $a2, %lo(D_809B23D4)  ## $a2 = 809B23D4
/* 0107C 809B219C 8D250000 */  lw      $a1, 0x0000($t1)           ## 00000000
/* 01080 809B21A0 27A40024 */  addiu   $a0, $sp, 0x0024           ## $a0 = FFFFFFDC
/* 01084 809B21A4 24070355 */  addiu   $a3, $zero, 0x0355         ## $a3 = 00000355
/* 01088 809B21A8 0C031AB1 */  jal     Graph_OpenDisps              
/* 0108C 809B21AC AFA50034 */  sw      $a1, 0x0034($sp)           
/* 01090 809B21B0 8FA80034 */  lw      $t0, 0x0034($sp)           
/* 01094 809B21B4 3C0BDA38 */  lui     $t3, 0xDA38                ## $t3 = DA380000
/* 01098 809B21B8 356B0003 */  ori     $t3, $t3, 0x0003           ## $t3 = DA380003
/* 0109C 809B21BC 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 010A0 809B21C0 3C05809B */  lui     $a1, %hi(D_809B23E8)       ## $a1 = 809B0000
/* 010A4 809B21C4 24A523E8 */  addiu   $a1, $a1, %lo(D_809B23E8)  ## $a1 = 809B23E8
/* 010A8 809B21C8 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 010AC 809B21CC AD0A02D0 */  sw      $t2, 0x02D0($t0)           ## 000002D0
/* 010B0 809B21D0 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 010B4 809B21D4 8FAC0048 */  lw      $t4, 0x0048($sp)           
/* 010B8 809B21D8 24060358 */  addiu   $a2, $zero, 0x0358         ## $a2 = 00000358
/* 010BC 809B21DC 8D840000 */  lw      $a0, 0x0000($t4)           ## 00000000
/* 010C0 809B21E0 AFA80034 */  sw      $t0, 0x0034($sp)           
/* 010C4 809B21E4 0C0346A2 */  jal     Matrix_NewMtx              
/* 010C8 809B21E8 AFA20020 */  sw      $v0, 0x0020($sp)           
/* 010CC 809B21EC 8FA30020 */  lw      $v1, 0x0020($sp)           
/* 010D0 809B21F0 8FA80034 */  lw      $t0, 0x0034($sp)           
/* 010D4 809B21F4 3C0F0600 */  lui     $t7, 0x0600                ## $t7 = 06000000
/* 010D8 809B21F8 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 010DC 809B21FC 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 010E0 809B2200 25EF3468 */  addiu   $t7, $t7, 0x3468           ## $t7 = 06003468
/* 010E4 809B2204 3C0EDE00 */  lui     $t6, 0xDE00                ## $t6 = DE000000
/* 010E8 809B2208 244D0008 */  addiu   $t5, $v0, 0x0008           ## $t5 = 00000008
/* 010EC 809B220C AD0D02D0 */  sw      $t5, 0x02D0($t0)           ## 000002D0
/* 010F0 809B2210 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 010F4 809B2214 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 010F8 809B2218 8FA50058 */  lw      $a1, 0x0058($sp)           
/* 010FC 809B221C 27A40038 */  addiu   $a0, $sp, 0x0038           ## $a0 = FFFFFFF0
/* 01100 809B2220 0C0346BD */  jal     Matrix_MultVec3f              
/* 01104 809B2224 24A50280 */  addiu   $a1, $a1, 0x0280           ## $a1 = 00000280
/* 01108 809B2228 8FB80048 */  lw      $t8, 0x0048($sp)           
/* 0110C 809B222C 3C06809B */  lui     $a2, %hi(D_809B23FC)       ## $a2 = 809B0000
/* 01110 809B2230 24C623FC */  addiu   $a2, $a2, %lo(D_809B23FC)  ## $a2 = 809B23FC
/* 01114 809B2234 27A40024 */  addiu   $a0, $sp, 0x0024           ## $a0 = FFFFFFDC
/* 01118 809B2238 24070364 */  addiu   $a3, $zero, 0x0364         ## $a3 = 00000364
/* 0111C 809B223C 0C031AD5 */  jal     Graph_CloseDisps              
/* 01120 809B2240 8F050000 */  lw      $a1, 0x0000($t8)           ## 00000000
.L809B2244:
/* 01124 809B2244 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 01128 809B2248 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000
/* 0112C 809B224C 03E00008 */  jr      $ra                        
/* 01130 809B2250 00000000 */  nop


