glabel EnSt_Update
/* 02378 80B06C08 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 0237C 80B06C0C 3C0E80B0 */  lui     $t6, %hi(D_80B071F0)       ## $t6 = 80B00000
/* 02380 80B06C10 8DCE71F0 */  lw      $t6, %lo(D_80B071F0)($t6)  
/* 02384 80B06C14 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 02388 80B06C18 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 0238C 80B06C1C AFA5003C */  sw      $a1, 0x003C($sp)           
/* 02390 80B06C20 AFAE002C */  sw      $t6, 0x002C($sp)           
/* 02394 80B06C24 8C8F0004 */  lw      $t7, 0x0004($a0)           ## 00000004
/* 02398 80B06C28 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0239C 80B06C2C 8FA5003C */  lw      $a1, 0x003C($sp)           
/* 023A0 80B06C30 31F88000 */  andi    $t8, $t7, 0x8000           ## $t8 = 00000000
/* 023A4 80B06C34 13000005 */  beq     $t8, $zero, .L80B06C4C     
/* 023A8 80B06C38 00000000 */  nop
/* 023AC 80B06C3C 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 023B0 80B06C40 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 023B4 80B06C44 1000004C */  beq     $zero, $zero, .L80B06D78   
/* 023B8 80B06C48 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B06C4C:
/* 023BC 80B06C4C 0C2C1640 */  jal     func_80B05900              
/* 023C0 80B06C50 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 023C4 80B06C54 54400048 */  bnel    $v0, $zero, .L80B06D78     
/* 023C8 80B06C58 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 023CC 80B06C5C 861903CE */  lh      $t9, 0x03CE($s0)           ## 000003CE
/* 023D0 80B06C60 57200004 */  bnel    $t9, $zero, .L80B06C74     
/* 023D4 80B06C64 860803C4 */  lh      $t0, 0x03C4($s0)           ## 000003C4
/* 023D8 80B06C68 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 023DC 80B06C6C 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 023E0 80B06C70 860803C4 */  lh      $t0, 0x03C4($s0)           ## 000003C4
.L80B06C74:
/* 023E4 80B06C74 55000007 */  bnel    $t0, $zero, .L80B06C94     
/* 023E8 80B06C78 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 023EC 80B06C7C 860903CE */  lh      $t1, 0x03CE($s0)           ## 000003CE
/* 023F0 80B06C80 55200004 */  bnel    $t1, $zero, .L80B06C94     
/* 023F4 80B06C84 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 023F8 80B06C88 0C00B5FB */  jal     ActorPosition_Move              
/* 023FC 80B06C8C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02400 80B06C90 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
.L80B06C94:
/* 02404 80B06C94 240A0004 */  addiu   $t2, $zero, 0x0004         ## $t2 = 00000004
/* 02408 80B06C98 AFAA0014 */  sw      $t2, 0x0014($sp)           
/* 0240C 80B06C9C 44060000 */  mfc1    $a2, $f0                   
/* 02410 80B06CA0 44070000 */  mfc1    $a3, $f0                   
/* 02414 80B06CA4 8FA4003C */  lw      $a0, 0x003C($sp)           
/* 02418 80B06CA8 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 0241C 80B06CAC 0C00B92D */  jal     func_8002E4B4              
/* 02420 80B06CB0 E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 02424 80B06CB4 860203CE */  lh      $v0, 0x03CE($s0)           ## 000003CE
/* 02428 80B06CB8 1440000B */  bne     $v0, $zero, .L80B06CE8     
/* 0242C 80B06CBC 00000000 */  nop
/* 02430 80B06CC0 860B03C4 */  lh      $t3, 0x03C4($s0)           ## 000003C4
/* 02434 80B06CC4 15600008 */  bne     $t3, $zero, .L80B06CE8     
/* 02438 80B06CC8 00000000 */  nop
/* 0243C 80B06CCC 8E190190 */  lw      $t9, 0x0190($s0)           ## 00000190
/* 02440 80B06CD0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02444 80B06CD4 8FA5003C */  lw      $a1, 0x003C($sp)           
/* 02448 80B06CD8 0320F809 */  jalr    $ra, $t9                   
/* 0244C 80B06CDC 00000000 */  nop
/* 02450 80B06CE0 1000000A */  beq     $zero, $zero, .L80B06D0C   
/* 02454 80B06CE4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B06CE8:
/* 02458 80B06CE8 10400005 */  beq     $v0, $zero, .L80B06D00     
/* 0245C 80B06CEC 00000000 */  nop
/* 02460 80B06CF0 0C2C1709 */  jal     func_80B05C24              
/* 02464 80B06CF4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02468 80B06CF8 10000004 */  beq     $zero, $zero, .L80B06D0C   
/* 0246C 80B06CFC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B06D00:
/* 02470 80B06D00 0C2C184F */  jal     func_80B0613C              
/* 02474 80B06D04 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02478 80B06D08 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B06D0C:
/* 0247C 80B06D0C 0C2C1711 */  jal     func_80B05C44              
/* 02480 80B06D10 8FA5003C */  lw      $a1, 0x003C($sp)           
/* 02484 80B06D14 8E0D0190 */  lw      $t5, 0x0190($s0)           ## 00000190
/* 02488 80B06D18 3C0C80B0 */  lui     $t4, %hi(func_80B06504)    ## $t4 = 80B00000
/* 0248C 80B06D1C 258C6504 */  addiu   $t4, $t4, %lo(func_80B06504) ## $t4 = 80B06504
/* 02490 80B06D20 158D0008 */  bne     $t4, $t5, .L80B06D44       
/* 02494 80B06D24 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02498 80B06D28 8FAE003C */  lw      $t6, 0x003C($sp)           
/* 0249C 80B06D2C 240800FF */  addiu   $t0, $zero, 0x00FF         ## $t0 = 000000FF
/* 024A0 80B06D30 8DCF009C */  lw      $t7, 0x009C($t6)           ## 0000009C
/* 024A4 80B06D34 31F80010 */  andi    $t8, $t7, 0x0010           ## $t8 = 00000000
/* 024A8 80B06D38 53000003 */  beql    $t8, $zero, .L80B06D48     
/* 024AC 80B06D3C 24090008 */  addiu   $t1, $zero, 0x0008         ## $t1 = 00000008
/* 024B0 80B06D40 A3A8002C */  sb      $t0, 0x002C($sp)           
.L80B06D44:
/* 024B4 80B06D44 24090008 */  addiu   $t1, $zero, 0x0008         ## $t1 = 00000008
.L80B06D48:
/* 024B8 80B06D48 AFA90010 */  sw      $t1, 0x0010($sp)           
/* 024BC 80B06D4C 93A5002C */  lbu     $a1, 0x002C($sp)           
/* 024C0 80B06D50 93A6002D */  lbu     $a2, 0x002D($sp)           
/* 024C4 80B06D54 0C2C16BE */  jal     func_80B05AF8              
/* 024C8 80B06D58 93A7002E */  lbu     $a3, 0x002E($sp)           
/* 024CC 80B06D5C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 024D0 80B06D60 0C2C1549 */  jal     func_80B05524              
/* 024D4 80B06D64 8FA5003C */  lw      $a1, 0x003C($sp)           
/* 024D8 80B06D68 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 024DC 80B06D6C 0C00B56E */  jal     Actor_SetHeight
              
/* 024E0 80B06D70 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 024E4 80B06D74 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80B06D78:
/* 024E8 80B06D78 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 024EC 80B06D7C 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 024F0 80B06D80 03E00008 */  jr      $ra                        
/* 024F4 80B06D84 00000000 */  nop
