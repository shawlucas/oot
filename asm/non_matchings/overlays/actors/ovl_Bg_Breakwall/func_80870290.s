glabel func_80870290
/* 006B0 80870290 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 006B4 80870294 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 006B8 80870298 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 006BC 8087029C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 006C0 808702A0 342117A4 */  ori     $at, $at, 0x17A4           ## $at = 000117A4
/* 006C4 808702A4 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 006C8 808702A8 AFA50034 */  sw      $a1, 0x0034($sp)           
/* 006CC 808702AC 00A12021 */  addu    $a0, $a1, $at              
/* 006D0 808702B0 0C026062 */  jal     Object_IsLoaded
              
/* 006D4 808702B4 82050169 */  lb      $a1, 0x0169($s0)           ## 00000169
/* 006D8 808702B8 50400032 */  beql    $v0, $zero, .L80870384     
/* 006DC 808702BC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 006E0 808702C0 AFA0002C */  sw      $zero, 0x002C($sp)         
/* 006E4 808702C4 860E001C */  lh      $t6, 0x001C($s0)           ## 0000001C
/* 006E8 808702C8 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 006EC 808702CC 000EC343 */  sra     $t8, $t6, 13               
/* 006F0 808702D0 33190003 */  andi    $t9, $t8, 0x0003           ## $t9 = 00000000
/* 006F4 808702D4 AFB90028 */  sw      $t9, 0x0028($sp)           
/* 006F8 808702D8 82080169 */  lb      $t0, 0x0169($s0)           ## 00000169
/* 006FC 808702DC A208001E */  sb      $t0, 0x001E($s0)           ## 0000001E
/* 00700 808702E0 0C00B591 */  jal     Actor_SetObjectDependency
              
/* 00704 808702E4 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 00708 808702E8 8E090004 */  lw      $t1, 0x0004($s0)           ## 00000004
/* 0070C 808702EC 2401FFEF */  addiu   $at, $zero, 0xFFEF         ## $at = FFFFFFEF
/* 00710 808702F0 3C0B8087 */  lui     $t3, %hi(func_808705D8)    ## $t3 = 80870000
/* 00714 808702F4 256B05D8 */  addiu   $t3, $t3, %lo(func_808705D8) ## $t3 = 808705D8
/* 00718 808702F8 01215024 */  and     $t2, $t1, $at              
/* 0071C 808702FC AE0A0004 */  sw      $t2, 0x0004($s0)           ## 00000004
/* 00720 80870300 AE0B0134 */  sw      $t3, 0x0134($s0)           ## 00000134
/* 00724 80870304 8FAC0028 */  lw      $t4, 0x0028($sp)           
/* 00728 80870308 3C0E8087 */  lui     $t6, %hi(D_808707B0)       ## $t6 = 80870000
/* 0072C 8087030C 25CE07B0 */  addiu   $t6, $t6, %lo(D_808707B0)  ## $t6 = 808707B0
/* 00730 80870310 000C6880 */  sll     $t5, $t4,  2               
/* 00734 80870314 01AC6823 */  subu    $t5, $t5, $t4              
/* 00738 80870318 000D6880 */  sll     $t5, $t5,  2               
/* 0073C 8087031C 01AE1021 */  addu    $v0, $t5, $t6              
/* 00740 80870320 8C440000 */  lw      $a0, 0x0000($v0)           ## 00000000
/* 00744 80870324 AFA20024 */  sw      $v0, 0x0024($sp)           
/* 00748 80870328 0C010620 */  jal     DynaPolyInfo_Alloc
              
/* 0074C 8087032C 27A5002C */  addiu   $a1, $sp, 0x002C           ## $a1 = FFFFFFFC
/* 00750 80870330 8FA40034 */  lw      $a0, 0x0034($sp)           
/* 00754 80870334 02003025 */  or      $a2, $s0, $zero            ## $a2 = 00000000
/* 00758 80870338 8FA7002C */  lw      $a3, 0x002C($sp)           
/* 0075C 8087033C 0C00FA9D */  jal     DynaPolyInfo_RegisterActor
              ## DynaPolyInfo_setActor
/* 00760 80870340 24850810 */  addiu   $a1, $a0, 0x0810           ## $a1 = 00000810
/* 00764 80870344 AE02014C */  sw      $v0, 0x014C($s0)           ## 0000014C
/* 00768 80870348 8FB80024 */  lw      $t8, 0x0024($sp)           
/* 0076C 8087034C 3C198087 */  lui     $t9, %hi(D_808707D4)       ## $t9 = 80870000
/* 00770 80870350 273907D4 */  addiu   $t9, $t9, %lo(D_808707D4)  ## $t9 = 808707D4
/* 00774 80870354 17190007 */  bne     $t8, $t9, .L80870374       
/* 00778 80870358 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0077C 8087035C 3C058087 */  lui     $a1, %hi(func_80870564)    ## $a1 = 80870000
/* 00780 80870360 24A50564 */  addiu   $a1, $a1, %lo(func_80870564) ## $a1 = 80870564
/* 00784 80870364 0C21BEF8 */  jal     BgBreakwall_SetupAction              
/* 00788 80870368 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0078C 8087036C 10000005 */  beq     $zero, $zero, .L80870384   
/* 00790 80870370 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80870374:
/* 00794 80870374 3C058087 */  lui     $a1, %hi(func_80870394)    ## $a1 = 80870000
/* 00798 80870378 0C21BEF8 */  jal     BgBreakwall_SetupAction              
/* 0079C 8087037C 24A50394 */  addiu   $a1, $a1, %lo(func_80870394) ## $a1 = 80870394
/* 007A0 80870380 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80870384:
/* 007A4 80870384 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 007A8 80870388 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 007AC 8087038C 03E00008 */  jr      $ra                        
/* 007B0 80870390 00000000 */  nop


