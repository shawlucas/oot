glabel func_80977508
/* 00178 80977508 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 0017C 8097750C 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00180 80977510 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00184 80977514 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 00188 80977518 24050005 */  addiu   $a1, $zero, 0x0005         ## $a1 = 00000005
/* 0018C 8097751C 0C25DD36 */  jal     func_809774D8              
/* 00190 80977520 AFA60018 */  sw      $a2, 0x0018($sp)           
/* 00194 80977524 10400013 */  beq     $v0, $zero, .L80977574     
/* 00198 80977528 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 0019C 8097752C 8C4E000C */  lw      $t6, 0x000C($v0)           ## 0000000C
/* 001A0 80977530 448E2000 */  mtc1    $t6, $f4                   ## $f4 = 0.00
/* 001A4 80977534 00000000 */  nop
/* 001A8 80977538 468021A0 */  cvt.s.w $f6, $f4                   
/* 001AC 8097753C E4C60024 */  swc1    $f6, 0x0024($a2)           ## 00000024
/* 001B0 80977540 8C4F0010 */  lw      $t7, 0x0010($v0)           ## 00000010
/* 001B4 80977544 448F4000 */  mtc1    $t7, $f8                   ## $f8 = 0.00
/* 001B8 80977548 00000000 */  nop
/* 001BC 8097754C 468042A0 */  cvt.s.w $f10, $f8                  
/* 001C0 80977550 E4CA0028 */  swc1    $f10, 0x0028($a2)          ## 00000028
/* 001C4 80977554 8C580014 */  lw      $t8, 0x0014($v0)           ## 00000014
/* 001C8 80977558 44988000 */  mtc1    $t8, $f16                  ## $f16 = 0.00
/* 001CC 8097755C 00000000 */  nop
/* 001D0 80977560 468084A0 */  cvt.s.w $f18, $f16                 
/* 001D4 80977564 E4D2002C */  swc1    $f18, 0x002C($a2)          ## 0000002C
/* 001D8 80977568 84430008 */  lh      $v1, 0x0008($v0)           ## 00000008
/* 001DC 8097756C A4C300B6 */  sh      $v1, 0x00B6($a2)           ## 000000B6
/* 001E0 80977570 A4C30032 */  sh      $v1, 0x0032($a2)           ## 00000032
.L80977574:
/* 001E4 80977574 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 001E8 80977578 ACC2014C */  sw      $v0, 0x014C($a2)           ## 0000014C
/* 001EC 8097757C ACC20150 */  sw      $v0, 0x0150($a2)           ## 00000150
/* 001F0 80977580 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 001F4 80977584 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 001F8 80977588 03E00008 */  jr      $ra                        
/* 001FC 8097758C 00000000 */  nop
