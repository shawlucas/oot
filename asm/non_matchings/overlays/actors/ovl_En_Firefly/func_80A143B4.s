glabel func_80A143B4
/* 01344 80A143B4 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 01348 80A143B8 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0134C 80A143BC AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01350 80A143C0 8CA61C44 */  lw      $a2, 0x1C44($a1)           ## 00001C44
/* 01354 80A143C4 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01358 80A143C8 24840170 */  addiu   $a0, $a0, 0x0170           ## $a0 = 00000170
/* 0135C 80A143CC 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 01360 80A143D0 AFA60034 */  sw      $a2, 0x0034($sp)           
/* 01364 80A143D4 860301BA */  lh      $v1, 0x01BA($s0)           ## 000001BA
/* 01368 80A143D8 8FA60034 */  lw      $a2, 0x0034($sp)           
/* 0136C 80A143DC 260400B4 */  addiu   $a0, $s0, 0x00B4           ## $a0 = 000000B4
/* 01370 80A143E0 10600003 */  beq     $v1, $zero, .L80A143F0     
/* 01374 80A143E4 246EFFFF */  addiu   $t6, $v1, 0xFFFF           ## $t6 = FFFFFFFF
/* 01378 80A143E8 A60E01BA */  sh      $t6, 0x01BA($s0)           ## 000001BA
/* 0137C 80A143EC 860301BA */  lh      $v1, 0x01BA($s0)           ## 000001BA
.L80A143F0:
/* 01380 80A143F0 28610028 */  slti    $at, $v1, 0x0028           
/* 01384 80A143F4 10200005 */  beq     $at, $zero, .L80A1440C     
/* 01388 80A143F8 2405F554 */  addiu   $a1, $zero, 0xF554         ## $a1 = FFFFF554
/* 0138C 80A143FC 0C01DE2B */  jal     Math_ApproxUpdateScaledS
              
/* 01390 80A14400 24060100 */  addiu   $a2, $zero, 0x0100         ## $a2 = 00000100
/* 01394 80A14404 10000018 */  beq     $zero, $zero, .L80A14468   
/* 01398 80A14408 860F01BA */  lh      $t7, 0x01BA($s0)           ## 000001BA
.L80A1440C:
/* 0139C 80A1440C C4C40024 */  lwc1    $f4, 0x0024($a2)           ## 00000024
/* 013A0 80A14410 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 013A4 80A14414 44814000 */  mtc1    $at, $f8                   ## $f8 = 20.00
/* 013A8 80A14418 E7A40028 */  swc1    $f4, 0x0028($sp)           
/* 013AC 80A1441C C4C60028 */  lwc1    $f6, 0x0028($a2)           ## 00000028
/* 013B0 80A14420 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 013B4 80A14424 27A50028 */  addiu   $a1, $sp, 0x0028           ## $a1 = FFFFFFF0
/* 013B8 80A14428 46083280 */  add.s   $f10, $f6, $f8             
/* 013BC 80A1442C E7AA002C */  swc1    $f10, 0x002C($sp)          
/* 013C0 80A14430 C4D0002C */  lwc1    $f16, 0x002C($a2)          ## 0000002C
/* 013C4 80A14434 0C00B6CA */  jal     ActorSearch_PosAngleX              
/* 013C8 80A14438 E7B00030 */  swc1    $f16, 0x0030($sp)          
/* 013CC 80A1443C 24451554 */  addiu   $a1, $v0, 0x1554           ## $a1 = 00001554
/* 013D0 80A14440 00052C00 */  sll     $a1, $a1, 16               
/* 013D4 80A14444 00052C03 */  sra     $a1, $a1, 16               
/* 013D8 80A14448 260400B4 */  addiu   $a0, $s0, 0x00B4           ## $a0 = 000000B4
/* 013DC 80A1444C 0C01DE2B */  jal     Math_ApproxUpdateScaledS
              
/* 013E0 80A14450 24060100 */  addiu   $a2, $zero, 0x0100         ## $a2 = 00000100
/* 013E4 80A14454 260400B6 */  addiu   $a0, $s0, 0x00B6           ## $a0 = 000000B6
/* 013E8 80A14458 8605008A */  lh      $a1, 0x008A($s0)           ## 0000008A
/* 013EC 80A1445C 0C01DE2B */  jal     Math_ApproxUpdateScaledS
              
/* 013F0 80A14460 24060300 */  addiu   $a2, $zero, 0x0300         ## $a2 = 00000300
/* 013F4 80A14464 860F01BA */  lh      $t7, 0x01BA($s0)           ## 000001BA
.L80A14468:
/* 013F8 80A14468 55E00004 */  bnel    $t7, $zero, .L80A1447C     
/* 013FC 80A1446C 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01400 80A14470 0C284CBD */  jal     func_80A132F4              
/* 01404 80A14474 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01408 80A14478 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80A1447C:
/* 0140C 80A1447C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 01410 80A14480 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 01414 80A14484 03E00008 */  jr      $ra                        
/* 01418 80A14488 00000000 */  nop
