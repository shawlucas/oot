glabel func_808A3400
/* 003A0 808A3400 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 003A4 808A3404 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 003A8 808A3408 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 003AC 808A340C 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 003B0 808A3410 3C0142F0 */  lui     $at, 0x42F0                ## $at = 42F00000
/* 003B4 808A3414 44813000 */  mtc1    $at, $f6                   ## $f6 = 120.00
/* 003B8 808A3418 C4E4000C */  lwc1    $f4, 0x000C($a3)           ## 0000000C
/* 003BC 808A341C AFA70018 */  sw      $a3, 0x0018($sp)           
/* 003C0 808A3420 24840028 */  addiu   $a0, $a0, 0x0028           ## $a0 = 00000028
/* 003C4 808A3424 46062200 */  add.s   $f8, $f4, $f6              
/* 003C8 808A3428 3C064120 */  lui     $a2, 0x4120                ## $a2 = 41200000
/* 003CC 808A342C 44054000 */  mfc1    $a1, $f8                   
/* 003D0 808A3430 0C01DE80 */  jal     Math_ApproxF
              
/* 003D4 808A3434 00000000 */  nop
/* 003D8 808A3438 10400003 */  beq     $v0, $zero, .L808A3448     
/* 003DC 808A343C 8FA70018 */  lw      $a3, 0x0018($sp)           
/* 003E0 808A3440 0C00B55C */  jal     Actor_Kill
              
/* 003E4 808A3444 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
.L808A3448:
/* 003E8 808A3448 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 003EC 808A344C 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 003F0 808A3450 03E00008 */  jr      $ra                        
/* 003F4 808A3454 00000000 */  nop
