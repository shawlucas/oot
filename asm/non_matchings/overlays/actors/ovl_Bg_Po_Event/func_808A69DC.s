glabel func_808A69DC
/* 007CC 808A69DC 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 007D0 808A69E0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 007D4 808A69E4 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 007D8 808A69E8 8482016C */  lh      $v0, 0x016C($a0)           ## 0000016C
/* 007DC 808A69EC 10400003 */  beq     $v0, $zero, .L808A69FC     
/* 007E0 808A69F0 244EFFFF */  addiu   $t6, $v0, 0xFFFF           ## $t6 = FFFFFFFF
/* 007E4 808A69F4 A48E016C */  sh      $t6, 0x016C($a0)           ## 0000016C
/* 007E8 808A69F8 8482016C */  lh      $v0, 0x016C($a0)           ## 0000016C
.L808A69FC:
/* 007EC 808A69FC 2841000F */  slti    $at, $v0, 0x000F           
/* 007F0 808A6A00 10200016 */  beq     $at, $zero, .L808A6A5C     
/* 007F4 808A6A04 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 007F8 808A6A08 0041001A */  div     $zero, $v0, $at            
/* 007FC 808A6A0C 00007810 */  mfhi    $t7                        
/* 00800 808A6A10 25F8FFFF */  addiu   $t8, $t7, 0xFFFF           ## $t8 = FFFFFFFF
/* 00804 808A6A14 44982000 */  mtc1    $t8, $f4                   ## $f4 = NaN
/* 00808 808A6A18 C4860008 */  lwc1    $f6, 0x0008($a0)           ## 00000008
/* 0080C 808A6A1C 24052838 */  addiu   $a1, $zero, 0x2838         ## $a1 = 00002838
/* 00810 808A6A20 46802020 */  cvt.s.w $f0, $f4                   
/* 00814 808A6A24 46000200 */  add.s   $f8, $f0, $f0              
/* 00818 808A6A28 46083280 */  add.s   $f10, $f6, $f8             
/* 0081C 808A6A2C E48A0024 */  swc1    $f10, 0x0024($a0)          ## 00000024
/* 00820 808A6A30 04410004 */  bgez    $v0, .L808A6A44            
/* 00824 808A6A34 30590003 */  andi    $t9, $v0, 0x0003           ## $t9 = 00000000
/* 00828 808A6A38 13200002 */  beq     $t9, $zero, .L808A6A44     
/* 0082C 808A6A3C 00000000 */  nop
/* 00830 808A6A40 2739FFFC */  addiu   $t9, $t9, 0xFFFC           ## $t9 = FFFFFFFC
.L808A6A44:
/* 00834 808A6A44 17200005 */  bne     $t9, $zero, .L808A6A5C     
/* 00838 808A6A48 00000000 */  nop
/* 0083C 808A6A4C 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 00840 808A6A50 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 00844 808A6A54 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 00848 808A6A58 8482016C */  lh      $v0, 0x016C($a0)           ## 0000016C
.L808A6A5C:
/* 0084C 808A6A5C 14400009 */  bne     $v0, $zero, .L808A6A84     
/* 00850 808A6A60 3C01808B */  lui     $at, %hi(D_808A80A0)       ## $at = 808B0000
/* 00854 808A6A64 C4900008 */  lwc1    $f16, 0x0008($a0)          ## 00000008
/* 00858 808A6A68 3C09808A */  lui     $t1, %hi(func_808A6BC8)    ## $t1 = 808A0000
/* 0085C 808A6A6C 2408003C */  addiu   $t0, $zero, 0x003C         ## $t0 = 0000003C
/* 00860 808A6A70 E4900024 */  swc1    $f16, 0x0024($a0)          ## 00000024
/* 00864 808A6A74 A02080A0 */  sb      $zero, %lo(D_808A80A0)($at) 
/* 00868 808A6A78 25296BC8 */  addiu   $t1, $t1, %lo(func_808A6BC8) ## $t1 = 808A6BC8
/* 0086C 808A6A7C A488016C */  sh      $t0, 0x016C($a0)           ## 0000016C
/* 00870 808A6A80 AC890164 */  sw      $t1, 0x0164($a0)           ## 00000164
.L808A6A84:
/* 00874 808A6A84 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00878 808A6A88 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 0087C 808A6A8C 03E00008 */  jr      $ra                        
/* 00880 808A6A90 00000000 */  nop
