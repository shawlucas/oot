.late_rodata
glabel D_8097C228
    .float 0.8
    .balign 4

.text
glabel func_8097B128
/* 027F8 8097B128 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 027FC 8097B12C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02800 8097B130 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 02804 8097B134 0C25E60F */  jal     func_8097983C              
/* 02808 8097B138 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 0280C 8097B13C 10400019 */  beq     $v0, $zero, .L8097B1A4     
/* 02810 8097B140 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 02814 8097B144 3C060600 */  lui     $a2, 0x0600                ## $a2 = 06000000
/* 02818 8097B148 24C61F70 */  addiu   $a2, $a2, 0x1F70           ## $a2 = 06001F70
/* 0281C 8097B14C 8FA5001C */  lw      $a1, 0x001C($sp)           
/* 02820 8097B150 0C25E3D8 */  jal     func_80978F60              
/* 02824 8097B154 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 02828 8097B158 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 0282C 8097B15C 3C018098 */  lui     $at, %hi(D_8097C228)       ## $at = 80980000
/* 02830 8097B160 C420C228 */  lwc1    $f0, %lo(D_8097C228)($at)  
/* 02834 8097B164 240E0012 */  addiu   $t6, $zero, 0x0012         ## $t6 = 00000012
/* 02838 8097B168 240F0010 */  addiu   $t7, $zero, 0x0010         ## $t7 = 00000010
/* 0283C 8097B16C AC8E0164 */  sw      $t6, 0x0164($a0)           ## 00000164
/* 02840 8097B170 AC8F0168 */  sw      $t7, 0x0168($a0)           ## 00000168
/* 02844 8097B174 24820050 */  addiu   $v0, $a0, 0x0050           ## $v0 = 00000050
/* 02848 8097B178 C4440000 */  lwc1    $f4, 0x0000($v0)           ## 00000050
/* 0284C 8097B17C C4480004 */  lwc1    $f8, 0x0004($v0)           ## 00000054
/* 02850 8097B180 C4500008 */  lwc1    $f16, 0x0008($v0)          ## 00000058
/* 02854 8097B184 46002182 */  mul.s   $f6, $f4, $f0              
/* 02858 8097B188 00000000 */  nop
/* 0285C 8097B18C 46004282 */  mul.s   $f10, $f8, $f0             
/* 02860 8097B190 00000000 */  nop
/* 02864 8097B194 46008482 */  mul.s   $f18, $f16, $f0            
/* 02868 8097B198 E4460000 */  swc1    $f6, 0x0000($v0)           ## 00000050
/* 0286C 8097B19C E44A0004 */  swc1    $f10, 0x0004($v0)          ## 00000054
/* 02870 8097B1A0 E4520008 */  swc1    $f18, 0x0008($v0)          ## 00000058
.L8097B1A4:
/* 02874 8097B1A4 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 02878 8097B1A8 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 0287C 8097B1AC 03E00008 */  jr      $ra                        
/* 02880 8097B1B0 00000000 */  nop


