glabel EnBili_Update
/* 01398 809C0C38 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 0139C 809C0C3C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 013A0 809C0C40 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 013A4 809C0C44 AFB0001C */  sw      $s0, 0x001C($sp)           
/* 013A8 809C0C48 908201E4 */  lbu     $v0, 0x01E4($a0)           ## 000001E4
/* 013AC 809C0C4C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 013B0 809C0C50 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 013B4 809C0C54 304E0002 */  andi    $t6, $v0, 0x0002           ## $t6 = 00000000
/* 013B8 809C0C58 11C00003 */  beq     $t6, $zero, .L809C0C68     
/* 013BC 809C0C5C 304FFFFD */  andi    $t7, $v0, 0xFFFD           ## $t7 = 00000000
/* 013C0 809C0C60 0C26FEA3 */  jal     func_809BFA8C              
/* 013C4 809C0C64 A08F01E4 */  sb      $t7, 0x01E4($a0)           ## 000001E4
.L809C0C68:
/* 013C8 809C0C68 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 013CC 809C0C6C 0C27029C */  jal     func_809C0A70              
/* 013D0 809C0C70 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 013D4 809C0C74 8E190190 */  lw      $t9, 0x0190($s0)           ## 00000190
/* 013D8 809C0C78 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 013DC 809C0C7C 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 013E0 809C0C80 0320F809 */  jalr    $ra, $t9                   
/* 013E4 809C0C84 00000000 */  nop
/* 013E8 809C0C88 8E080190 */  lw      $t0, 0x0190($s0)           ## 00000190
/* 013EC 809C0C8C 3C18809C */  lui     $t8, %hi(func_809C0754)    ## $t8 = 809C0000
/* 013F0 809C0C90 27180754 */  addiu   $t8, $t8, %lo(func_809C0754) ## $t8 = 809C0754
/* 013F4 809C0C94 53080058 */  beql    $t8, $t0, .L809C0DF8       
/* 013F8 809C0C98 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 013FC 809C0C9C 0C26FFDB */  jal     func_809BFF6C              
/* 01400 809C0CA0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01404 809C0CA4 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 01408 809C0CA8 0C0295B2 */  jal     func_800A56C8              
/* 0140C 809C0CAC 3C054110 */  lui     $a1, 0x4110                ## $a1 = 41100000
/* 01410 809C0CB0 5040001A */  beql    $v0, $zero, .L809C0D1C     
/* 01414 809C0CB4 8E190190 */  lw      $t9, 0x0190($s0)           ## 00000190
/* 01418 809C0CB8 8E020190 */  lw      $v0, 0x0190($s0)           ## 00000190
/* 0141C 809C0CBC 3C09809C */  lui     $t1, %hi(func_809C0174)    ## $t1 = 809C0000
/* 01420 809C0CC0 25290174 */  addiu   $t1, $t1, %lo(func_809C0174) ## $t1 = 809C0174
/* 01424 809C0CC4 1122000A */  beq     $t1, $v0, .L809C0CF0       
/* 01428 809C0CC8 3C0A809C */  lui     $t2, %hi(func_809C0600)    ## $t2 = 809C0000
/* 0142C 809C0CCC 254A0600 */  addiu   $t2, $t2, %lo(func_809C0600) ## $t2 = 809C0600
/* 01430 809C0CD0 11420007 */  beq     $t2, $v0, .L809C0CF0       
/* 01434 809C0CD4 3C0B809C */  lui     $t3, %hi(func_809C0570)    ## $t3 = 809C0000
/* 01438 809C0CD8 256B0570 */  addiu   $t3, $t3, %lo(func_809C0570) ## $t3 = 809C0570
/* 0143C 809C0CDC 11620004 */  beq     $t3, $v0, .L809C0CF0       
/* 01440 809C0CE0 3C0C809C */  lui     $t4, %hi(func_809C067C)    ## $t4 = 809C0000
/* 01444 809C0CE4 258C067C */  addiu   $t4, $t4, %lo(func_809C067C) ## $t4 = 809C067C
/* 01448 809C0CE8 5582000C */  bnel    $t4, $v0, .L809C0D1C       
/* 0144C 809C0CEC 8E190190 */  lw      $t9, 0x0190($s0)           ## 00000190
.L809C0CF0:
/* 01450 809C0CF0 920D0195 */  lbu     $t5, 0x0195($s0)           ## 00000195
/* 01454 809C0CF4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01458 809C0CF8 240E0001 */  addiu   $t6, $zero, 0x0001         ## $t6 = 00000001
/* 0145C 809C0CFC 51A00006 */  beql    $t5, $zero, .L809C0D18     
/* 01460 809C0D00 A20E0195 */  sb      $t6, 0x0195($s0)           ## 00000195
/* 01464 809C0D04 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01468 809C0D08 24053898 */  addiu   $a1, $zero, 0x3898         ## $a1 = 00003898
/* 0146C 809C0D0C 10000002 */  beq     $zero, $zero, .L809C0D18   
/* 01470 809C0D10 A2000195 */  sb      $zero, 0x0195($s0)         ## 00000195
/* 01474 809C0D14 A20E0195 */  sb      $t6, 0x0195($s0)           ## 00000195
.L809C0D18:
/* 01478 809C0D18 8E190190 */  lw      $t9, 0x0190($s0)           ## 00000190
.L809C0D1C:
/* 0147C 809C0D1C 3C0F809C */  lui     $t7, %hi(func_809C067C)    ## $t7 = 809C0000
/* 01480 809C0D20 25EF067C */  addiu   $t7, $t7, %lo(func_809C067C) ## $t7 = 809C067C
/* 01484 809C0D24 15F90005 */  bne     $t7, $t9, .L809C0D3C       
/* 01488 809C0D28 00000000 */  nop
/* 0148C 809C0D2C 0C00B65F */  jal     ActorPosition_MoveForwardXY              
/* 01490 809C0D30 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01494 809C0D34 10000004 */  beq     $zero, $zero, .L809C0D48   
/* 01498 809C0D38 86180214 */  lh      $t8, 0x0214($s0)           ## 00000214
.L809C0D3C:
/* 0149C 809C0D3C 0C00B638 */  jal     Actor_MoveForward
              
/* 014A0 809C0D40 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 014A4 809C0D44 86180214 */  lh      $t8, 0x0214($s0)           ## 00000214
.L809C0D48:
/* 014A8 809C0D48 86080216 */  lh      $t0, 0x0216($s0)           ## 00000216
/* 014AC 809C0D4C 24090007 */  addiu   $t1, $zero, 0x0007         ## $t1 = 00000007
/* 014B0 809C0D50 44982000 */  mtc1    $t8, $f4                   ## $f4 = 0.00
/* 014B4 809C0D54 44883000 */  mtc1    $t0, $f6                   ## $f6 = 0.00
/* 014B8 809C0D58 AFA90014 */  sw      $t1, 0x0014($sp)           
/* 014BC 809C0D5C 46802120 */  cvt.s.w $f4, $f4                   
/* 014C0 809C0D60 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 014C4 809C0D64 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 014C8 809C0D68 3C0640A0 */  lui     $a2, 0x40A0                ## $a2 = 40A00000
/* 014CC 809C0D6C 46803220 */  cvt.s.w $f8, $f6                   
/* 014D0 809C0D70 44072000 */  mfc1    $a3, $f4                   
/* 014D4 809C0D74 0C00B92D */  jal     func_8002E4B4              
/* 014D8 809C0D78 E7A80010 */  swc1    $f8, 0x0010($sp)           
/* 014DC 809C0D7C 260501D4 */  addiu   $a1, $s0, 0x01D4           ## $a1 = 000001D4
/* 014E0 809C0D80 AFA50028 */  sw      $a1, 0x0028($sp)           
/* 014E4 809C0D84 0C0189B7 */  jal     Collider_CylinderUpdate
              
/* 014E8 809C0D88 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 014EC 809C0D8C 920A01E4 */  lbu     $t2, 0x01E4($s0)           ## 000001E4
/* 014F0 809C0D90 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 014F4 809C0D94 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 014F8 809C0D98 314B0001 */  andi    $t3, $t2, 0x0001           ## $t3 = 00000000
/* 014FC 809C0D9C 11600004 */  beq     $t3, $zero, .L809C0DB0     
/* 01500 809C0DA0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01504 809C0DA4 02212821 */  addu    $a1, $s1, $at              
/* 01508 809C0DA8 0C0175E7 */  jal     CollisionCheck_SetAT
              ## CollisionCheck_setAT
/* 0150C 809C0DAC 8FA60028 */  lw      $a2, 0x0028($sp)           
.L809C0DB0:
/* 01510 809C0DB0 920C01E5 */  lbu     $t4, 0x01E5($s0)           ## 000001E5
/* 01514 809C0DB4 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 01518 809C0DB8 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 0151C 809C0DBC 318D0001 */  andi    $t5, $t4, 0x0001           ## $t5 = 00000000
/* 01520 809C0DC0 11A00006 */  beq     $t5, $zero, .L809C0DDC     
/* 01524 809C0DC4 02212821 */  addu    $a1, $s1, $at              
/* 01528 809C0DC8 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 0152C 809C0DCC 8FA60028 */  lw      $a2, 0x0028($sp)           
/* 01530 809C0DD0 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 01534 809C0DD4 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 01538 809C0DD8 8FA5002C */  lw      $a1, 0x002C($sp)           
.L809C0DDC:
/* 0153C 809C0DDC 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01540 809C0DE0 0C017713 */  jal     CollisionCheck_SetOC
              ## CollisionCheck_setOT
/* 01544 809C0DE4 8FA60028 */  lw      $a2, 0x0028($sp)           
/* 01548 809C0DE8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0154C 809C0DEC 0C00B56E */  jal     Actor_SetHeight
              
/* 01550 809C0DF0 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 01554 809C0DF4 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L809C0DF8:
/* 01558 809C0DF8 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 0155C 809C0DFC 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 01560 809C0E00 03E00008 */  jr      $ra                        
/* 01564 809C0E04 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
