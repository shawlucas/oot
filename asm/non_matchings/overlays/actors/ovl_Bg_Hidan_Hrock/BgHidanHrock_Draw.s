glabel BgHidanHrock_Draw
/* 0068C 808897BC 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 00690 808897C0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00694 808897C4 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 00698 808897C8 84EE001C */  lh      $t6, 0x001C($a3)           ## 0000001C
/* 0069C 808897CC 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 006A0 808897D0 3C058089 */  lui     $a1, %hi(D_808898B0)       ## $a1 = 80890000
/* 006A4 808897D4 000E7880 */  sll     $t7, $t6,  2               
/* 006A8 808897D8 00AF2821 */  addu    $a1, $a1, $t7              
/* 006AC 808897DC 0C00D498 */  jal     Gfx_DrawDListOpa
              
/* 006B0 808897E0 8CA598B0 */  lw      $a1, %lo(D_808898B0)($a1)  
/* 006B4 808897E4 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 006B8 808897E8 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 006BC 808897EC 03E00008 */  jr      $ra                        
/* 006C0 808897F0 00000000 */  nop
/* 006C4 808897F4 00000000 */  nop
/* 006C8 808897F8 00000000 */  nop
/* 006CC 808897FC 00000000 */  nop
