glabel func_80B534CC
/* 0011C 80B534CC 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 00120 80B534D0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00124 80B534D4 848E0246 */  lh      $t6, 0x0246($a0)           ## 00000246
/* 00128 80B534D8 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 0012C 80B534DC 24C30246 */  addiu   $v1, $a2, 0x0246           ## $v1 = 00000246
/* 00130 80B534E0 15C00003 */  bne     $t6, $zero, .L80B534F0     
/* 00134 80B534E4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 00138 80B534E8 10000005 */  beq     $zero, $zero, .L80B53500   
/* 0013C 80B534EC 24830246 */  addiu   $v1, $a0, 0x0246           ## $v1 = 00000246
.L80B534F0:
/* 00140 80B534F0 846F0000 */  lh      $t7, 0x0000($v1)           ## 00000246
/* 00144 80B534F4 25F8FFFF */  addiu   $t8, $t7, 0xFFFF           ## $t8 = FFFFFFFF
/* 00148 80B534F8 A4780000 */  sh      $t8, 0x0000($v1)           ## 00000246
/* 0014C 80B534FC 84620000 */  lh      $v0, 0x0000($v1)           ## 00000246
.L80B53500:
/* 00150 80B53500 14400008 */  bne     $v0, $zero, .L80B53524     
/* 00154 80B53504 2404003C */  addiu   $a0, $zero, 0x003C         ## $a0 = 0000003C
/* 00158 80B53508 2405003C */  addiu   $a1, $zero, 0x003C         ## $a1 = 0000003C
/* 0015C 80B5350C AFA3001C */  sw      $v1, 0x001C($sp)           
/* 00160 80B53510 0C01DF64 */  jal     Math_Rand_S16Offset
              
/* 00164 80B53514 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 00168 80B53518 8FA3001C */  lw      $v1, 0x001C($sp)           
/* 0016C 80B5351C 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 00170 80B53520 A4620000 */  sh      $v0, 0x0000($v1)           ## 00000000
.L80B53524:
/* 00174 80B53524 84790000 */  lh      $t9, 0x0000($v1)           ## 00000000
/* 00178 80B53528 24C20244 */  addiu   $v0, $a2, 0x0244           ## $v0 = 00000244
/* 0017C 80B5352C A4590000 */  sh      $t9, 0x0000($v0)           ## 00000244
/* 00180 80B53530 84480000 */  lh      $t0, 0x0000($v0)           ## 00000244
/* 00184 80B53534 29010003 */  slti    $at, $t0, 0x0003           
/* 00188 80B53538 54200003 */  bnel    $at, $zero, .L80B53548     
/* 0018C 80B5353C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00190 80B53540 A4400000 */  sh      $zero, 0x0000($v0)         ## 00000244
/* 00194 80B53544 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80B53548:
/* 00198 80B53548 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 0019C 80B5354C 03E00008 */  jr      $ra                        
/* 001A0 80B53550 00000000 */  nop
