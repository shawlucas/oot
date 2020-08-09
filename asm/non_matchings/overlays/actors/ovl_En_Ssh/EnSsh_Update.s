glabel EnSsh_Update
/* 01E04 80B04074 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 01E08 80B04078 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 01E0C 80B0407C AFB00020 */  sw      $s0, 0x0020($sp)           
/* 01E10 80B04080 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01E14 80B04084 0C2C0FD2 */  jal     func_80B03F48              
/* 01E18 80B04088 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 01E1C 80B0408C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01E20 80B04090 0C2C0CC3 */  jal     func_80B0330C              
/* 01E24 80B04094 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01E28 80B04098 54400039 */  bnel    $v0, $zero, .L80B04180     
/* 01E2C 80B0409C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 01E30 80B040A0 860E0532 */  lh      $t6, 0x0532($s0)           ## 00000532
/* 01E34 80B040A4 11C00005 */  beq     $t6, $zero, .L80B040BC     
/* 01E38 80B040A8 00000000 */  nop
/* 01E3C 80B040AC 0C2C0AB1 */  jal     func_80B02AC4              
/* 01E40 80B040B0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01E44 80B040B4 10000014 */  beq     $zero, $zero, .L80B04108   
/* 01E48 80B040B8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B040BC:
/* 01E4C 80B040BC 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 01E50 80B040C0 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01E54 80B040C4 0C00B5FB */  jal     ActorPosition_Move              
/* 01E58 80B040C8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01E5C 80B040CC 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 01E60 80B040D0 240F0004 */  addiu   $t7, $zero, 0x0004         ## $t7 = 00000004
/* 01E64 80B040D4 AFAF0014 */  sw      $t7, 0x0014($sp)           
/* 01E68 80B040D8 44060000 */  mfc1    $a2, $f0                   
/* 01E6C 80B040DC 44070000 */  mfc1    $a3, $f0                   
/* 01E70 80B040E0 8FA4002C */  lw      $a0, 0x002C($sp)           
/* 01E74 80B040E4 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 01E78 80B040E8 0C00B92D */  jal     func_8002E4B4              
/* 01E7C 80B040EC E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 01E80 80B040F0 8E1902F8 */  lw      $t9, 0x02F8($s0)           ## 000002F8
/* 01E84 80B040F4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01E88 80B040F8 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01E8C 80B040FC 0320F809 */  jalr    $ra, $t9                   
/* 01E90 80B04100 00000000 */  nop
/* 01E94 80B04104 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B04108:
/* 01E98 80B04108 0C2C0B45 */  jal     func_80B02D14              
/* 01E9C 80B0410C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01EA0 80B04110 860305D0 */  lh      $v1, 0x05D0($s0)           ## 000005D0
/* 01EA4 80B04114 2404003C */  addiu   $a0, $zero, 0x003C         ## $a0 = 0000003C
/* 01EA8 80B04118 14600003 */  bne     $v1, $zero, .L80B04128     
/* 01EAC 80B0411C 2478FFFF */  addiu   $t8, $v1, 0xFFFF           ## $t8 = FFFFFFFF
/* 01EB0 80B04120 10000004 */  beq     $zero, $zero, .L80B04134   
/* 01EB4 80B04124 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80B04128:
/* 01EB8 80B04128 A61805D0 */  sh      $t8, 0x05D0($s0)           ## 000005D0
/* 01EBC 80B0412C 860305D0 */  lh      $v1, 0x05D0($s0)           ## 000005D0
/* 01EC0 80B04130 00601025 */  or      $v0, $v1, $zero            ## $v0 = 00000000
.L80B04134:
/* 01EC4 80B04134 54400006 */  bnel    $v0, $zero, .L80B04150     
/* 01EC8 80B04138 A60305CE */  sh      $v1, 0x05CE($s0)           ## 000005CE
/* 01ECC 80B0413C 0C01DF64 */  jal     Math_Rand_S16Offset
              
/* 01ED0 80B04140 2405003C */  addiu   $a1, $zero, 0x003C         ## $a1 = 0000003C
/* 01ED4 80B04144 A60205D0 */  sh      $v0, 0x05D0($s0)           ## 000005D0
/* 01ED8 80B04148 860305D0 */  lh      $v1, 0x05D0($s0)           ## 000005D0
/* 01EDC 80B0414C A60305CE */  sh      $v1, 0x05CE($s0)           ## 000005CE
.L80B04150:
/* 01EE0 80B04150 860805CE */  lh      $t0, 0x05CE($s0)           ## 000005CE
/* 01EE4 80B04154 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01EE8 80B04158 29010003 */  slti    $at, $t0, 0x0003           
/* 01EEC 80B0415C 14200002 */  bne     $at, $zero, .L80B04168     
/* 01EF0 80B04160 00000000 */  nop
/* 01EF4 80B04164 A60005CE */  sh      $zero, 0x05CE($s0)         ## 000005CE
.L80B04168:
/* 01EF8 80B04168 0C2C0DA3 */  jal     func_80B0368C              
/* 01EFC 80B0416C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 01F00 80B04170 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01F04 80B04174 0C00B56E */  jal     Actor_SetHeight
              
/* 01F08 80B04178 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 01F0C 80B0417C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B04180:
/* 01F10 80B04180 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 01F14 80B04184 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 01F18 80B04188 03E00008 */  jr      $ra                        
/* 01F1C 80B0418C 00000000 */  nop
