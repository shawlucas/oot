glabel func_80B0699C
/* 0210C 80B0699C 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 02110 80B069A0 3C0E80B0 */  lui     $t6, %hi(D_80B071E4)       ## $t6 = 80B00000
/* 02114 80B069A4 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 02118 80B069A8 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 0211C 80B069AC AFA50044 */  sw      $a1, 0x0044($sp)           
/* 02120 80B069B0 25CE71E4 */  addiu   $t6, $t6, %lo(D_80B071E4)  ## $t6 = 80B071E4
/* 02124 80B069B4 8DD80000 */  lw      $t8, 0x0000($t6)           ## 80B071E4
/* 02128 80B069B8 27A60034 */  addiu   $a2, $sp, 0x0034           ## $a2 = FFFFFFF4
/* 0212C 80B069BC 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 02130 80B069C0 ACD80000 */  sw      $t8, 0x0000($a2)           ## FFFFFFF4
/* 02134 80B069C4 8DCF0004 */  lw      $t7, 0x0004($t6)           ## 80B071E8
/* 02138 80B069C8 ACCF0004 */  sw      $t7, 0x0004($a2)           ## FFFFFFF8
/* 0213C 80B069CC 8DD80008 */  lw      $t8, 0x0008($t6)           ## 80B071EC
/* 02140 80B069D0 ACD80008 */  sw      $t8, 0x0008($a2)           ## FFFFFFFC
/* 02144 80B069D4 848303D8 */  lh      $v1, 0x03D8($a0)           ## 000003D8
/* 02148 80B069D8 14600003 */  bne     $v1, $zero, .L80B069E8     
/* 0214C 80B069DC 2479FFFF */  addiu   $t9, $v1, 0xFFFF           ## $t9 = FFFFFFFF
/* 02150 80B069E0 10000003 */  beq     $zero, $zero, .L80B069F0   
/* 02154 80B069E4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80B069E8:
/* 02158 80B069E8 A61903D8 */  sh      $t9, 0x03D8($s0)           ## 000003D8
/* 0215C 80B069EC 860203D8 */  lh      $v0, 0x03D8($s0)           ## 000003D8
.L80B069F0:
/* 02160 80B069F0 54400010 */  bnel    $v0, $zero, .L80B06A34     
/* 02164 80B069F4 860303C6 */  lh      $v1, 0x03C6($s0)           ## 000003C6
/* 02168 80B069F8 8CC90000 */  lw      $t1, 0x0000($a2)           ## FFFFFFF4
/* 0216C 80B069FC 240A0008 */  addiu   $t2, $zero, 0x0008         ## $t2 = 00000008
/* 02170 80B06A00 3C0580B0 */  lui     $a1, %hi(func_80B06B10)    ## $a1 = 80B00000
/* 02174 80B06A04 AE09005C */  sw      $t1, 0x005C($s0)           ## 0000005C
/* 02178 80B06A08 8CC80004 */  lw      $t0, 0x0004($a2)           ## FFFFFFF8
/* 0217C 80B06A0C 24A56B10 */  addiu   $a1, $a1, %lo(func_80B06B10) ## $a1 = 80B06B10
/* 02180 80B06A10 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02184 80B06A14 AE080060 */  sw      $t0, 0x0060($s0)           ## 00000060
/* 02188 80B06A18 8CC90008 */  lw      $t1, 0x0008($a2)           ## FFFFFFFC
/* 0218C 80B06A1C A60A03D6 */  sh      $t2, 0x03D6($s0)           ## 000003D6
/* 02190 80B06A20 0C2C1224 */  jal     func_80B04890              
/* 02194 80B06A24 AE090064 */  sw      $t1, 0x0064($s0)           ## 00000064
/* 02198 80B06A28 10000035 */  beq     $zero, $zero, .L80B06B00   
/* 0219C 80B06A2C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 021A0 80B06A30 860303C6 */  lh      $v1, 0x03C6($s0)           ## 000003C6
.L80B06A34:
/* 021A4 80B06A34 26040024 */  addiu   $a0, $s0, 0x0024           ## $a0 = 00000024
/* 021A8 80B06A38 14600003 */  bne     $v1, $zero, .L80B06A48     
/* 021AC 80B06A3C 246BFFFF */  addiu   $t3, $v1, 0xFFFF           ## $t3 = FFFFFFFF
/* 021B0 80B06A40 10000003 */  beq     $zero, $zero, .L80B06A50   
/* 021B4 80B06A44 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80B06A48:
/* 021B8 80B06A48 A60B03C6 */  sh      $t3, 0x03C6($s0)           ## 000003C6
/* 021BC 80B06A4C 860203C6 */  lh      $v0, 0x03C6($s0)           ## 000003C6
.L80B06A50:
/* 021C0 80B06A50 54400007 */  bnel    $v0, $zero, .L80B06A70     
/* 021C4 80B06A54 26040030 */  addiu   $a0, $s0, 0x0030           ## $a0 = 00000030
/* 021C8 80B06A58 0C01E01A */  jal     Math_Vec3f_Yaw
              
/* 021CC 80B06A5C 26050008 */  addiu   $a1, $s0, 0x0008           ## $a1 = 00000008
/* 021D0 80B06A60 240C0008 */  addiu   $t4, $zero, 0x0008         ## $t4 = 00000008
/* 021D4 80B06A64 A60203BE */  sh      $v0, 0x03BE($s0)           ## 000003BE
/* 021D8 80B06A68 A60C03C6 */  sh      $t4, 0x03C6($s0)           ## 000003C6
/* 021DC 80B06A6C 26040030 */  addiu   $a0, $s0, 0x0030           ## $a0 = 00000030
.L80B06A70:
/* 021E0 80B06A70 240D0001 */  addiu   $t5, $zero, 0x0001         ## $t5 = 00000001
/* 021E4 80B06A74 AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 021E8 80B06A78 AFA4002C */  sw      $a0, 0x002C($sp)           
/* 021EC 80B06A7C 24053FFC */  addiu   $a1, $zero, 0x3FFC         ## $a1 = 00003FFC
/* 021F0 80B06A80 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 021F4 80B06A84 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 021F8 80B06A88 24072710 */  addiu   $a3, $zero, 0x2710         ## $a3 = 00002710
/* 021FC 80B06A8C 240E0001 */  addiu   $t6, $zero, 0x0001         ## $t6 = 00000001
/* 02200 80B06A90 AFAE0010 */  sw      $t6, 0x0010($sp)           
/* 02204 80B06A94 26040034 */  addiu   $a0, $s0, 0x0034           ## $a0 = 00000034
/* 02208 80B06A98 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 0220C 80B06A9C 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 02210 80B06AA0 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 02214 80B06AA4 24072710 */  addiu   $a3, $zero, 0x2710         ## $a3 = 00002710
/* 02218 80B06AA8 860503BE */  lh      $a1, 0x03BE($s0)           ## 000003BE
/* 0221C 80B06AAC 240F0001 */  addiu   $t7, $zero, 0x0001         ## $t7 = 00000001
/* 02220 80B06AB0 AFAF0010 */  sw      $t7, 0x0010($sp)           
/* 02224 80B06AB4 26040032 */  addiu   $a0, $s0, 0x0032           ## $a0 = 00000032
/* 02228 80B06AB8 2406000A */  addiu   $a2, $zero, 0x000A         ## $a2 = 0000000A
/* 0222C 80B06ABC 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 02230 80B06AC0 24072710 */  addiu   $a3, $zero, 0x2710         ## $a3 = 00002710
/* 02234 80B06AC4 8FB8002C */  lw      $t8, 0x002C($sp)           
/* 02238 80B06AC8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0223C 80B06ACC 8B080000 */  lwl     $t0, 0x0000($t8)           ## 00000000
/* 02240 80B06AD0 9B080003 */  lwr     $t0, 0x0003($t8)           ## 00000003
/* 02244 80B06AD4 AA0800B4 */  swl     $t0, 0x00B4($s0)           ## 000000B4
/* 02248 80B06AD8 BA0800B7 */  swr     $t0, 0x00B7($s0)           ## 000000B7
/* 0224C 80B06ADC 97080004 */  lhu     $t0, 0x0004($t8)           ## 00000004
/* 02250 80B06AE0 0C00B61A */  jal     func_8002D868              
/* 02254 80B06AE4 A60800B8 */  sh      $t0, 0x00B8($s0)           ## 000000B8
/* 02258 80B06AE8 24090002 */  addiu   $t1, $zero, 0x0002         ## $t1 = 00000002
/* 0225C 80B06AEC A60903C0 */  sh      $t1, 0x03C0($s0)           ## 000003C0
/* 02260 80B06AF0 8FA50044 */  lw      $a1, 0x0044($sp)           
/* 02264 80B06AF4 0C2C17B9 */  jal     func_80B05EE4              
/* 02268 80B06AF8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0226C 80B06AFC 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B06B00:
/* 02270 80B06B00 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 02274 80B06B04 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 02278 80B06B08 03E00008 */  jr      $ra                        
/* 0227C 80B06B0C 00000000 */  nop
