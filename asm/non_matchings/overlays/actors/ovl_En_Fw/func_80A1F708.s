.late_rodata
glabel D_80A1FC84
    .float 0.2
    .balign 4

glabel D_80A1FC88
 .word 0x3ECCCCCD, 0x00000000


.text
glabel func_80A1F708
/* 01168 80A1F708 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 0116C 80A1F70C F7B60018 */  sdc1    $f22, 0x0018($sp)          
/* 01170 80A1F710 3C0180A2 */  lui     $at, %hi(D_80A1FC84)       ## $at = 80A20000
/* 01174 80A1F714 C436FC84 */  lwc1    $f22, %lo(D_80A1FC84)($at) 
/* 01178 80A1F718 AFB10028 */  sw      $s1, 0x0028($sp)           
/* 0117C 80A1F71C AFB00024 */  sw      $s0, 0x0024($sp)           
/* 01180 80A1F720 F7B40010 */  sdc1    $f20, 0x0010($sp)          
/* 01184 80A1F724 3C0180A2 */  lui     $at, %hi(D_80A1FC88)       ## $at = 80A20000
/* 01188 80A1F728 AFBF002C */  sw      $ra, 0x002C($sp)           
/* 0118C 80A1F72C 249002A0 */  addiu   $s0, $a0, 0x02A0           ## $s0 = 000002A0
/* 01190 80A1F730 C434FC88 */  lwc1    $f20, %lo(D_80A1FC88)($at) 
/* 01194 80A1F734 00008825 */  or      $s1, $zero, $zero          ## $s1 = 00000000
.L80A1F738:
/* 01198 80A1F738 920E0000 */  lbu     $t6, 0x0000($s0)           ## 000002A0
/* 0119C 80A1F73C 51C00029 */  beql    $t6, $zero, .L80A1F7E4     
/* 011A0 80A1F740 26310001 */  addiu   $s1, $s1, 0x0001           ## $s1 = 00000001
/* 011A4 80A1F744 920F0001 */  lbu     $t7, 0x0001($s0)           ## 000002A1
/* 011A8 80A1F748 25F8FFFF */  addiu   $t8, $t7, 0xFFFF           ## $t8 = FFFFFFFF
/* 011AC 80A1F74C 331900FF */  andi    $t9, $t8, 0x00FF           ## $t9 = 000000FF
/* 011B0 80A1F750 17200002 */  bne     $t9, $zero, .L80A1F75C     
/* 011B4 80A1F754 A2180001 */  sb      $t8, 0x0001($s0)           ## 000002A1
/* 011B8 80A1F758 A2000000 */  sb      $zero, 0x0000($s0)         ## 000002A0
.L80A1F75C:
/* 011BC 80A1F75C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 011C0 80A1F760 00000000 */  nop
/* 011C4 80A1F764 46140102 */  mul.s   $f4, $f0, $f20             
/* 011C8 80A1F768 46162181 */  sub.s   $f6, $f4, $f22             
/* 011CC 80A1F76C 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 011D0 80A1F770 E606002C */  swc1    $f6, 0x002C($s0)           ## 000002CC
/* 011D4 80A1F774 C60C0020 */  lwc1    $f12, 0x0020($s0)          ## 000002C0
/* 011D8 80A1F778 C60A0014 */  lwc1    $f10, 0x0014($s0)          ## 000002B4
/* 011DC 80A1F77C 46140202 */  mul.s   $f8, $f0, $f20             
/* 011E0 80A1F780 C60E0024 */  lwc1    $f14, 0x0024($s0)          ## 000002C4
/* 011E4 80A1F784 460C5480 */  add.s   $f18, $f10, $f12           
/* 011E8 80A1F788 C6040018 */  lwc1    $f4, 0x0018($s0)           ## 000002B8
/* 011EC 80A1F78C C6100028 */  lwc1    $f16, 0x0028($s0)          ## 000002C8
/* 011F0 80A1F790 E6120014 */  swc1    $f18, 0x0014($s0)          ## 000002B4
/* 011F4 80A1F794 C612002C */  lwc1    $f18, 0x002C($s0)          ## 000002CC
/* 011F8 80A1F798 460E2180 */  add.s   $f6, $f4, $f14             
/* 011FC 80A1F79C 46164081 */  sub.s   $f2, $f8, $f22             
/* 01200 80A1F7A0 C608001C */  lwc1    $f8, 0x001C($s0)           ## 000002BC
/* 01204 80A1F7A4 E6060018 */  swc1    $f6, 0x0018($s0)           ## 000002B8
/* 01208 80A1F7A8 46126100 */  add.s   $f4, $f12, $f18            
/* 0120C 80A1F7AC C6060030 */  lwc1    $f6, 0x0030($s0)           ## 000002D0
/* 01210 80A1F7B0 C6120004 */  lwc1    $f18, 0x0004($s0)          ## 000002A4
/* 01214 80A1F7B4 46104280 */  add.s   $f10, $f8, $f16            
/* 01218 80A1F7B8 E6040020 */  swc1    $f4, 0x0020($s0)           ## 000002C0
/* 0121C 80A1F7BC C6040008 */  lwc1    $f4, 0x0008($s0)           ## 000002A8
/* 01220 80A1F7C0 46067200 */  add.s   $f8, $f14, $f6             
/* 01224 80A1F7C4 E60A001C */  swc1    $f10, 0x001C($s0)          ## 000002BC
/* 01228 80A1F7C8 E6020034 */  swc1    $f2, 0x0034($s0)           ## 000002D4
/* 0122C 80A1F7CC 46028280 */  add.s   $f10, $f16, $f2            
/* 01230 80A1F7D0 E6080024 */  swc1    $f8, 0x0024($s0)           ## 000002C4
/* 01234 80A1F7D4 46049180 */  add.s   $f6, $f18, $f4             
/* 01238 80A1F7D8 E60A0028 */  swc1    $f10, 0x0028($s0)          ## 000002C8
/* 0123C 80A1F7DC E6060004 */  swc1    $f6, 0x0004($s0)           ## 000002A4
/* 01240 80A1F7E0 26310001 */  addiu   $s1, $s1, 0x0001           ## $s1 = 00000002
.L80A1F7E4:
/* 01244 80A1F7E4 00118C00 */  sll     $s1, $s1, 16               
/* 01248 80A1F7E8 00118C03 */  sra     $s1, $s1, 16               
/* 0124C 80A1F7EC 2A210014 */  slti    $at, $s1, 0x0014           
/* 01250 80A1F7F0 1420FFD1 */  bne     $at, $zero, .L80A1F738     
/* 01254 80A1F7F4 26100038 */  addiu   $s0, $s0, 0x0038           ## $s0 = 000002D8
/* 01258 80A1F7F8 8FBF002C */  lw      $ra, 0x002C($sp)           
/* 0125C 80A1F7FC D7B40010 */  ldc1    $f20, 0x0010($sp)          
/* 01260 80A1F800 D7B60018 */  ldc1    $f22, 0x0018($sp)          
/* 01264 80A1F804 8FB00024 */  lw      $s0, 0x0024($sp)           
/* 01268 80A1F808 8FB10028 */  lw      $s1, 0x0028($sp)           
/* 0126C 80A1F80C 03E00008 */  jr      $ra                        
/* 01270 80A1F810 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000


