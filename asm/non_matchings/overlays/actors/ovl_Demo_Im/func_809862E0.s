.rdata
glabel D_80988894
    .asciz "Demo_Im_Ocarina_Check_DemoMode:そんな動作は無い!!!!!!!!\n"
    .balign 4

.late_rodata
glabel jtbl_809889E0
.word L80986340
.word L80986350
.word L80986394
.word L80986394
.word L80986394
.word L80986394
.word L80986364
.word L80986374
.word L80986384

.text
glabel func_809862E0
/* 01700 809862E0 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 01704 809862E4 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01708 809862E8 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0170C 809862EC AFBF001C */  sw      $ra, 0x001C($sp)           
/* 01710 809862F0 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 01714 809862F4 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 01718 809862F8 0C261428 */  jal     func_809850A0              
/* 0171C 809862FC 24050005 */  addiu   $a1, $zero, 0x0005         ## $a1 = 00000005
/* 01720 80986300 5040002A */  beql    $v0, $zero, .L809863AC     
/* 01724 80986304 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01728 80986308 944E0000 */  lhu     $t6, 0x0000($v0)           ## 00000000
/* 0172C 8098630C AFAE0020 */  sw      $t6, 0x0020($sp)           
/* 01730 80986310 8E030274 */  lw      $v1, 0x0274($s0)           ## 00000274
/* 01734 80986314 25D8FFFF */  addiu   $t8, $t6, 0xFFFF           ## $t8 = FFFFFFFF
/* 01738 80986318 2F010009 */  sltiu   $at, $t8, 0x0009           
/* 0173C 8098631C 51C30023 */  beql    $t6, $v1, .L809863AC       
/* 01740 80986320 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 01744 80986324 1020001B */  beq     $at, $zero, .L80986394     
/* 01748 80986328 0018C080 */  sll     $t8, $t8,  2               
/* 0174C 8098632C 3C018099 */  lui     $at, %hi(jtbl_809889E0)       ## $at = 80990000
/* 01750 80986330 00380821 */  addu    $at, $at, $t8              
/* 01754 80986334 8C3889E0 */  lw      $t8, %lo(jtbl_809889E0)($at)  
/* 01758 80986338 03000008 */  jr      $t8                        
/* 0175C 8098633C 00000000 */  nop
glabel L80986340
/* 01760 80986340 0C2617D5 */  jal     func_80985F54              
/* 01764 80986344 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01768 80986348 10000016 */  beq     $zero, $zero, .L809863A4   
/* 0176C 8098634C 8FB90020 */  lw      $t9, 0x0020($sp)           
glabel L80986350
/* 01770 80986350 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01774 80986354 0C2617D9 */  jal     func_80985F64              
/* 01778 80986358 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 0177C 8098635C 10000011 */  beq     $zero, $zero, .L809863A4   
/* 01780 80986360 8FB90020 */  lw      $t9, 0x0020($sp)           
glabel L80986364
/* 01784 80986364 0C261813 */  jal     func_8098604C              
/* 01788 80986368 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0178C 8098636C 1000000D */  beq     $zero, $zero, .L809863A4   
/* 01790 80986370 8FB90020 */  lw      $t9, 0x0020($sp)           
glabel L80986374
/* 01794 80986374 0C261832 */  jal     func_809860C8              
/* 01798 80986378 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0179C 8098637C 10000009 */  beq     $zero, $zero, .L809863A4   
/* 017A0 80986380 8FB90020 */  lw      $t9, 0x0020($sp)           
glabel L80986384
/* 017A4 80986384 0C261852 */  jal     func_80986148              
/* 017A8 80986388 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 017AC 8098638C 10000005 */  beq     $zero, $zero, .L809863A4   
/* 017B0 80986390 8FB90020 */  lw      $t9, 0x0020($sp)           
glabel L80986394
.L80986394:
/* 017B4 80986394 3C048099 */  lui     $a0, %hi(D_80988894)       ## $a0 = 80990000
/* 017B8 80986398 0C00084C */  jal     osSyncPrintf
              
/* 017BC 8098639C 24848894 */  addiu   $a0, $a0, %lo(D_80988894)  ## $a0 = 80988894
/* 017C0 809863A0 8FB90020 */  lw      $t9, 0x0020($sp)           
.L809863A4:
/* 017C4 809863A4 AE190274 */  sw      $t9, 0x0274($s0)           ## 00000274
/* 017C8 809863A8 8FBF001C */  lw      $ra, 0x001C($sp)           
.L809863AC:
/* 017CC 809863AC 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 017D0 809863B0 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 017D4 809863B4 03E00008 */  jr      $ra                        
/* 017D8 809863B8 00000000 */  nop


