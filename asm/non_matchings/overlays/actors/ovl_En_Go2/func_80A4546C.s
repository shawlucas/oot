glabel func_80A4546C
/* 0273C 80A4546C 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 02740 80A45470 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02744 80A45474 848E0194 */  lh      $t6, 0x0194($a0)           ## 00000194
/* 02748 80A45478 C4800068 */  lwc1    $f0, 0x0068($a0)           ## 00000068
/* 0274C 80A4547C 51C00005 */  beql    $t6, $zero, .L80A45494     
/* 02750 80A45480 8C980190 */  lw      $t8, 0x0190($a0)           ## 00000190
/* 02754 80A45484 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 02758 80A45488 00000000 */  nop
/* 0275C 80A4548C E4840068 */  swc1    $f4, 0x0068($a0)           ## 00000068
/* 02760 80A45490 8C980190 */  lw      $t8, 0x0190($a0)           ## 00000190
.L80A45494:
/* 02764 80A45494 3C0F80A4 */  lui     $t7, %hi(func_80A46DBC)    ## $t7 = 80A40000
/* 02768 80A45498 25EF6DBC */  addiu   $t7, $t7, %lo(func_80A46DBC) ## $t7 = 80A46DBC
/* 0276C 80A4549C 51F80007 */  beql    $t7, $t8, .L80A454BC       
/* 02770 80A454A0 E4800068 */  swc1    $f0, 0x0068($a0)           ## 00000068
/* 02774 80A454A4 AFA40020 */  sw      $a0, 0x0020($sp)           
/* 02778 80A454A8 0C00B638 */  jal     Actor_MoveForward
              
/* 0277C 80A454AC E7A0001C */  swc1    $f0, 0x001C($sp)           
/* 02780 80A454B0 8FA40020 */  lw      $a0, 0x0020($sp)           
/* 02784 80A454B4 C7A0001C */  lwc1    $f0, 0x001C($sp)           
/* 02788 80A454B8 E4800068 */  swc1    $f0, 0x0068($a0)           ## 00000068
.L80A454BC:
/* 0278C 80A454BC 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 02790 80A454C0 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 02794 80A454C4 03E00008 */  jr      $ra                        
/* 02798 80A454C8 00000000 */  nop
