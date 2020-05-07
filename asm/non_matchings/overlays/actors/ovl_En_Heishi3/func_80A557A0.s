glabel EnHeishi3_SetupGuardType
/* 00160 80A557A0 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 00164 80A557A4 AFA40028 */  sw      $a0, 0x0028($sp)
/* 00168 80A557A8 AFBF0024 */  sw      $ra, 0x0024($sp)
/* 0016C 80A557AC 3C040600 */  lui     $a0, 0x0600                ## $a0 = 06000000
/* 00170 80A557B0 AFA5002C */  sw      $a1, 0x002C($sp)
/* 00174 80A557B4 0C028800 */  jal     SkelAnime_GetFrameCount

/* 00178 80A557B8 24845C30 */  addiu   $a0, $a0, 0x5C30           ## $a0 = 06005C30
/* 0017C 80A557BC 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 00180 80A557C0 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 00184 80A557C4 8FA30028 */  lw      $v1, 0x0028($sp)
/* 00188 80A557C8 468021A0 */  cvt.s.w $f6, $f4
/* 0018C 80A557CC 44819000 */  mtc1    $at, $f18                  ## $f18 = -10.00
/* 00190 80A557D0 3C050600 */  lui     $a1, 0x0600                ## $a1 = 06000000
/* 00194 80A557D4 24A55C30 */  addiu   $a1, $a1, 0x5C30           ## $a1 = 06005C30
/* 00198 80A557D8 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 0019C 80A557DC 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 001A0 80A557E0 4600320D */  trunc.w.s $f8, $f6
/* 001A4 80A557E4 AFA00014 */  sw      $zero, 0x0014($sp)
/* 001A8 80A557E8 2464014C */  addiu   $a0, $v1, 0x014C           ## $a0 = 0000014C
/* 001AC 80A557EC E7B20018 */  swc1    $f18, 0x0018($sp)
/* 001B0 80A557F0 440F4000 */  mfc1    $t7, $f8
/* 001B4 80A557F4 00000000 */  nop
/* 001B8 80A557F8 000FC400 */  sll     $t8, $t7, 16
/* 001BC 80A557FC 0018CC03 */  sra     $t9, $t8, 16
/* 001C0 80A55800 44995000 */  mtc1    $t9, $f10                  ## $f10 = 0.00
/* 001C4 80A55804 00000000 */  nop
/* 001C8 80A55808 46805420 */  cvt.s.w $f16, $f10
/* 001CC 80A5580C 0C029468 */  jal     SkelAnime_ChangeAnim

/* 001D0 80A55810 E7B00010 */  swc1    $f16, 0x0010($sp)
/* 001D4 80A55814 8FA30028 */  lw      $v1, 0x0028($sp)
/* 001D8 80A55818 3C0980A5 */  lui     $t1, %hi(EnHeishi3_GroundsHandler)    ## $t1 = 80A50000
/* 001DC 80A5581C 3C0A80A5 */  lui     $t2, %hi(EnHeishi3_CastleHandler)    ## $t2 = 80A50000
/* 001E0 80A55820 84680278 */  lh      $t0, 0x0278($v1)           ## 00000278
/* 001E4 80A55824 25295850 */  addiu   $t1, $t1, %lo(EnHeishi3_GroundsHandler) ## $t1 = 80A55850
/* 001E8 80A55828 254A59B4 */  addiu   $t2, $t2, %lo(EnHeishi3_CastleHandler) ## $t2 = 80A559B4
/* 001EC 80A5582C 55000004 */  bnel    $t0, $zero, .L80A55840
/* 001F0 80A55830 AC6A025C */  sw      $t2, 0x025C($v1)           ## 0000025C
/* 001F4 80A55834 10000002 */  beq     $zero, $zero, .L80A55840
/* 001F8 80A55838 AC69025C */  sw      $t1, 0x025C($v1)           ## 0000025C
/* 001FC 80A5583C AC6A025C */  sw      $t2, 0x025C($v1)           ## 0000025C
.L80A55840:
/* 00200 80A55840 8FBF0024 */  lw      $ra, 0x0024($sp)
/* 00204 80A55844 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00208 80A55848 03E00008 */  jr      $ra
/* 0020C 80A5584C 00000000 */  nop
