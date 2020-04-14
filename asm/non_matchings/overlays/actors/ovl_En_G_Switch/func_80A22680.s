.late_rodata
glabel D_80A23B0C
    .float 0.3

.text
glabel func_80A22680
/* 007C0 80A22680 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 007C4 80A22684 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 007C8 80A22688 848E00B6 */  lh      $t6, 0x00B6($a0)           ## 000000B6
/* 007CC 80A2268C 84980156 */  lh      $t8, 0x0156($a0)           ## 00000156
/* 007D0 80A22690 8CA21C44 */  lw      $v0, 0x1C44($a1)           ## 00001C44
/* 007D4 80A22694 25CF03C0 */  addiu   $t7, $t6, 0x03C0           ## $t7 = 000003C0
/* 007D8 80A22698 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 007DC 80A2269C 17000005 */  bne     $t8, $zero, .L80A226B4     
/* 007E0 80A226A0 A48F00B6 */  sh      $t7, 0x00B6($a0)           ## 000000B6
/* 007E4 80A226A4 0C00B55C */  jal     Actor_Kill
              
/* 007E8 80A226A8 00000000 */  nop
/* 007EC 80A226AC 1000002A */  beq     $zero, $zero, .L80A22758   
/* 007F0 80A226B0 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80A226B4:
/* 007F4 80A226B4 84C40156 */  lh      $a0, 0x0156($a2)           ## 00000156
/* 007F8 80A226B8 24013A98 */  addiu   $at, $zero, 0x3A98         ## $at = 00003A98
/* 007FC 80A226BC 8C480024 */  lw      $t0, 0x0024($v0)           ## 00000024
/* 00800 80A226C0 00810019 */  multu   $a0, $at                   
/* 00804 80A226C4 ACC80024 */  sw      $t0, 0x0024($a2)           ## 00000024
/* 00808 80A226C8 8C590028 */  lw      $t9, 0x0028($v0)           ## 00000028
/* 0080C 80A226CC ACD90028 */  sw      $t9, 0x0028($a2)           ## 00000028
/* 00810 80A226D0 8C48002C */  lw      $t0, 0x002C($v0)           ## 0000002C
/* 00814 80A226D4 00002012 */  mflo    $a0                        
/* 00818 80A226D8 00042400 */  sll     $a0, $a0, 16               
/* 0081C 80A226DC ACC8002C */  sw      $t0, 0x002C($a2)           ## 0000002C
/* 00820 80A226E0 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 00824 80A226E4 AFA2001C */  sw      $v0, 0x001C($sp)           
/* 00828 80A226E8 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0082C 80A226EC 00042403 */  sra     $a0, $a0, 16               
/* 00830 80A226F0 8FA60020 */  lw      $a2, 0x0020($sp)           
/* 00834 80A226F4 3C0180A2 */  lui     $at, %hi(D_80A23B0C)       ## $at = 80A20000
/* 00838 80A226F8 C4283B0C */  lwc1    $f8, %lo(D_80A23B0C)($at)  
/* 0083C 80A226FC 84C90156 */  lh      $t1, 0x0156($a2)           ## 00000156
/* 00840 80A22700 8FA2001C */  lw      $v0, 0x001C($sp)           
/* 00844 80A22704 3C014220 */  lui     $at, 0x4220                ## $at = 42200000
/* 00848 80A22708 44892000 */  mtc1    $t1, $f4                   ## $f4 = 0.00
/* 0084C 80A2270C C4520028 */  lwc1    $f18, 0x0028($v0)          ## 00000028
/* 00850 80A22710 3C0A8016 */  lui     $t2, 0x8016                ## $t2 = 80160000
/* 00854 80A22714 468021A0 */  cvt.s.w $f6, $f4                   
/* 00858 80A22718 44812000 */  mtc1    $at, $f4                   ## $f4 = 40.00
/* 0085C 80A2271C 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 00860 80A22720 46083282 */  mul.s   $f10, $f6, $f8             
/* 00864 80A22724 46049180 */  add.s   $f6, $f18, $f4             
/* 00868 80A22728 460A0402 */  mul.s   $f16, $f0, $f10            
/* 0086C 80A2272C 46068200 */  add.s   $f8, $f16, $f6             
/* 00870 80A22730 E4C80028 */  swc1    $f8, 0x0028($a2)           ## 00000028
/* 00874 80A22734 8D4AE664 */  lw      $t2, -0x199C($t2)          ## 8015E664
/* 00878 80A22738 55400007 */  bnel    $t2, $zero, .L80A22758     
/* 0087C 80A2273C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00880 80A22740 C4CA0028 */  lwc1    $f10, 0x0028($a2)          ## 00000028
/* 00884 80A22744 44819000 */  mtc1    $at, $f18                  ## $f18 = 20.00
/* 00888 80A22748 00000000 */  nop
/* 0088C 80A2274C 46125100 */  add.s   $f4, $f10, $f18            
/* 00890 80A22750 E4C40028 */  swc1    $f4, 0x0028($a2)           ## 00000028
/* 00894 80A22754 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80A22758:
/* 00898 80A22758 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 0089C 80A2275C 03E00008 */  jr      $ra                        
/* 008A0 80A22760 00000000 */  nop
