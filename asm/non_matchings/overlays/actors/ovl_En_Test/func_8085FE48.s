glabel func_8085FE48
/* 007F8 8085FE48 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 007FC 8085FE4C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00800 8085FE50 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 00804 8085FE54 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 00808 8085FE58 AFA60018 */  sw      $a2, 0x0018($sp)           
/* 0080C 8085FE5C 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00810 8085FE60 24840188 */  addiu   $a0, $a0, 0x0188           ## $a0 = 00000188
/* 00814 8085FE64 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 00818 8085FE68 3C014316 */  lui     $at, 0x4316                ## $at = 43160000
/* 0081C 8085FE6C 8CC207E8 */  lw      $v0, 0x07E8($a2)           ## 000007E8
/* 00820 8085FE70 14400020 */  bne     $v0, $zero, .L8085FEF4     
/* 00824 8085FE74 00000000 */  nop
/* 00828 8085FE78 C4C00094 */  lwc1    $f0, 0x0094($a2)           ## 00000094
/* 0082C 8085FE7C 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 00830 8085FE80 44813000 */  mtc1    $at, $f6                   ## $f6 = 150.00
/* 00834 8085FE84 3C058086 */  lui     $a1, %hi(func_80863360)    ## $a1 = 80860000
/* 00838 8085FE88 4600203E */  c.le.s  $f4, $f0                   
/* 0083C 8085FE8C 240E0003 */  addiu   $t6, $zero, 0x0003         ## $t6 = 00000003
/* 00840 8085FE90 24A53360 */  addiu   $a1, $a1, %lo(func_80863360) ## $a1 = 80863360
/* 00844 8085FE94 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 00848 8085FE98 45020004 */  bc1fl   .L8085FEAC                 
/* 0084C 8085FE9C 46000087 */  neg.s   $f2, $f0                   
/* 00850 8085FEA0 10000002 */  beq     $zero, $zero, .L8085FEAC   
/* 00854 8085FEA4 46000086 */  mov.s   $f2, $f0                   
/* 00858 8085FEA8 46000087 */  neg.s   $f2, $f0                   
.L8085FEAC:
/* 0085C 8085FEAC 4606103C */  c.lt.s  $f2, $f6                   
/* 00860 8085FEB0 00000000 */  nop
/* 00864 8085FEB4 4500000F */  bc1f    .L8085FEF4                 
/* 00868 8085FEB8 00000000 */  nop
/* 0086C 8085FEBC A0CE07C8 */  sb      $t6, 0x07C8($a2)           ## 000007C8
/* 00870 8085FEC0 0C217D94 */  jal     EnTest_SetupAction              
/* 00874 8085FEC4 AFA60018 */  sw      $a2, 0x0018($sp)           
/* 00878 8085FEC8 8FA60018 */  lw      $a2, 0x0018($sp)           
/* 0087C 8085FECC 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 00880 8085FED0 84C2008A */  lh      $v0, 0x008A($a2)           ## 0000008A
/* 00884 8085FED4 84CF001C */  lh      $t7, 0x001C($a2)           ## 0000001C
/* 00888 8085FED8 A4C20032 */  sh      $v0, 0x0032($a2)           ## 00000032
/* 0088C 8085FEDC 11E1000E */  beq     $t7, $at, .L8085FF18       
/* 00890 8085FEE0 A4C200B6 */  sh      $v0, 0x00B6($a2)           ## 000000B6
/* 00894 8085FEE4 0C03D6B3 */  jal     func_800F5ACC              
/* 00898 8085FEE8 24040038 */  addiu   $a0, $zero, 0x0038         ## $a0 = 00000038
/* 0089C 8085FEEC 1000000B */  beq     $zero, $zero, .L8085FF1C   
/* 008A0 8085FEF0 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FEF4:
/* 008A4 8085FEF4 10400003 */  beq     $v0, $zero, .L8085FF04     
/* 008A8 8085FEF8 3C014060 */  lui     $at, 0x4060                ## $at = 40600000
/* 008AC 8085FEFC 2458FFFF */  addiu   $t8, $v0, 0xFFFF           ## $t8 = FFFFFFFF
/* 008B0 8085FF00 ACD807E8 */  sw      $t8, 0x07E8($a2)           ## 000007E8
.L8085FF04:
/* 008B4 8085FF04 C4C8000C */  lwc1    $f8, 0x000C($a2)           ## 0000000C
/* 008B8 8085FF08 44815000 */  mtc1    $at, $f10                  ## $f10 = 3.50
/* 008BC 8085FF0C 00000000 */  nop
/* 008C0 8085FF10 460A4401 */  sub.s   $f16, $f8, $f10            
/* 008C4 8085FF14 E4D00028 */  swc1    $f16, 0x0028($a2)          ## 00000028
.L8085FF18:
/* 008C8 8085FF18 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L8085FF1C:
/* 008CC 8085FF1C 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 008D0 8085FF20 03E00008 */  jr      $ra                        
/* 008D4 8085FF24 00000000 */  nop


