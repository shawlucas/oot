glabel func_80986CFC
/* 0211C 80986CFC 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 02120 80986D00 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02124 80986D04 0C261A97 */  jal     func_80986A5C              
/* 02128 80986D08 AFA40018 */  sw      $a0, 0x0018($sp)           
/* 0212C 80986D0C 10400008 */  beq     $v0, $zero, .L80986D30     
/* 02130 80986D10 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 02134 80986D14 2442E660 */  addiu   $v0, $v0, 0xE660           ## $v0 = 8015E660
/* 02138 80986D18 944E0EDC */  lhu     $t6, 0x0EDC($v0)           ## 8015F53C
/* 0213C 80986D1C 8FB90018 */  lw      $t9, 0x0018($sp)           
/* 02140 80986D20 24180013 */  addiu   $t8, $zero, 0x0013         ## $t8 = 00000013
/* 02144 80986D24 35CF1000 */  ori     $t7, $t6, 0x1000           ## $t7 = 00001000
/* 02148 80986D28 A44F0EDC */  sh      $t7, 0x0EDC($v0)           ## 8015F53C
/* 0214C 80986D2C AF380260 */  sw      $t8, 0x0260($t9)           ## 00000260
.L80986D30:
/* 02150 80986D30 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 02154 80986D34 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 02158 80986D38 03E00008 */  jr      $ra                        
/* 0215C 80986D3C 00000000 */  nop
