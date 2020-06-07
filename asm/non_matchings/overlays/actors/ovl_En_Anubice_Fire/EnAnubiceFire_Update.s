.late_rodata
glabel D_809B32E8
    .float 0.6

.text
glabel EnAnubiceFire_Update
/* 00754 809B2CF4 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 00758 809B2CF8 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 0075C 809B2CFC 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00760 809B2D00 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00764 809B2D04 AFA5004C */  sw      $a1, 0x004C($sp)           
/* 00768 809B2D08 0C00B58B */  jal     Actor_SetScale
              
/* 0076C 809B2D0C 8E050150 */  lw      $a1, 0x0150($s0)           ## 00000150
/* 00770 809B2D10 8E19014C */  lw      $t9, 0x014C($s0)           ## 0000014C
/* 00774 809B2D14 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00778 809B2D18 8FA5004C */  lw      $a1, 0x004C($sp)           
/* 0077C 809B2D1C 0320F809 */  jalr    $ra, $t9                   
/* 00780 809B2D20 00000000 */  nop
/* 00784 809B2D24 0C00B5FB */  jal     func_8002D7EC              
/* 00788 809B2D28 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0078C 809B2D2C 26080024 */  addiu   $t0, $s0, 0x0024           ## $t0 = 00000024
/* 00790 809B2D30 8D0F0000 */  lw      $t7, 0x0000($t0)           ## 00000024
/* 00794 809B2D34 26050030 */  addiu   $a1, $s0, 0x0030           ## $a1 = 00000030
/* 00798 809B2D38 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 0079C 809B2D3C AE0F0160 */  sw      $t7, 0x0160($s0)           ## 00000160
/* 007A0 809B2D40 8D0E0004 */  lw      $t6, 0x0004($t0)           ## 00000028
/* 007A4 809B2D44 44810000 */  mtc1    $at, $f0                   ## $f0 = 5.00
/* 007A8 809B2D48 24A3016C */  addiu   $v1, $a1, 0x016C           ## $v1 = 0000019C
/* 007AC 809B2D4C AE0E0164 */  sw      $t6, 0x0164($s0)           ## 00000164
/* 007B0 809B2D50 8D0F0008 */  lw      $t7, 0x0008($t0)           ## 0000002C
/* 007B4 809B2D54 24A40160 */  addiu   $a0, $a1, 0x0160           ## $a0 = 00000190
/* 007B8 809B2D58 24020004 */  addiu   $v0, $zero, 0x0004         ## $v0 = 00000004
/* 007BC 809B2D5C AE0F0168 */  sw      $t7, 0x0168($s0)           ## 00000168
.L809B2D60:
/* 007C0 809B2D60 8C890000 */  lw      $t1, 0x0000($a0)           ## 00000190
/* 007C4 809B2D64 2442FFFF */  addiu   $v0, $v0, 0xFFFF           ## $v0 = 00000003
/* 007C8 809B2D68 2463FFF4 */  addiu   $v1, $v1, 0xFFF4           ## $v1 = 00000190
/* 007CC 809B2D6C AC69000C */  sw      $t1, 0x000C($v1)           ## 0000019C
/* 007D0 809B2D70 8C980004 */  lw      $t8, 0x0004($a0)           ## 00000194
/* 007D4 809B2D74 2484FFF4 */  addiu   $a0, $a0, 0xFFF4           ## $a0 = 00000184
/* 007D8 809B2D78 AC780010 */  sw      $t8, 0x0010($v1)           ## 000001A0
/* 007DC 809B2D7C 8C890014 */  lw      $t1, 0x0014($a0)           ## 00000198
/* 007E0 809B2D80 0441FFF7 */  bgez    $v0, .L809B2D60            
/* 007E4 809B2D84 AC690014 */  sw      $t1, 0x0014($v1)           ## 000001A4
/* 007E8 809B2D88 8602015A */  lh      $v0, 0x015A($s0)           ## 0000015A
/* 007EC 809B2D8C 44060000 */  mfc1    $a2, $f0                   
/* 007F0 809B2D90 44070000 */  mfc1    $a3, $f0                   
/* 007F4 809B2D94 10400003 */  beq     $v0, $zero, .L809B2DA4     
/* 007F8 809B2D98 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 007FC 809B2D9C 244AFFFF */  addiu   $t2, $v0, 0xFFFF           ## $t2 = 00000002
/* 00800 809B2DA0 A60A015A */  sh      $t2, 0x015A($s0)           ## 0000015A
.L809B2DA4:
/* 00804 809B2DA4 8602015C */  lh      $v0, 0x015C($s0)           ## 0000015C
/* 00808 809B2DA8 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 0080C 809B2DAC 44812000 */  mtc1    $at, $f4                   ## $f4 = 10.00
/* 00810 809B2DB0 10400003 */  beq     $v0, $zero, .L809B2DC0     
/* 00814 809B2DB4 240C001D */  addiu   $t4, $zero, 0x001D         ## $t4 = 0000001D
/* 00818 809B2DB8 244BFFFF */  addiu   $t3, $v0, 0xFFFF           ## $t3 = 00000002
/* 0081C 809B2DBC A60B015C */  sh      $t3, 0x015C($s0)           ## 0000015C
.L809B2DC0:
/* 00820 809B2DC0 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 00824 809B2DC4 E7A40010 */  swc1    $f4, 0x0010($sp)           
/* 00828 809B2DC8 AFAC0014 */  sw      $t4, 0x0014($sp)           
/* 0082C 809B2DCC 0C00B92D */  jal     func_8002E4B4              
/* 00830 809B2DD0 AFA8002C */  sw      $t0, 0x002C($sp)           
/* 00834 809B2DD4 3C01809B */  lui     $at, %hi(D_809B32E8)       ## $at = 809B0000
/* 00838 809B2DD8 C42632E8 */  lwc1    $f6, %lo(D_809B32E8)($at)  
/* 0083C 809B2DDC C6000150 */  lwc1    $f0, 0x0150($s0)           ## 00000150
/* 00840 809B2DE0 3C0D809B */  lui     $t5, %hi(func_809B2B48)    ## $t5 = 809B0000
/* 00844 809B2DE4 25AD2B48 */  addiu   $t5, $t5, %lo(func_809B2B48) ## $t5 = 809B2B48
/* 00848 809B2DE8 4606003C */  c.lt.s  $f0, $f6                   
/* 0084C 809B2DEC 00000000 */  nop
/* 00850 809B2DF0 4503003A */  bc1tl   .L809B2EDC                 
/* 00854 809B2DF4 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00858 809B2DF8 AFAD0030 */  sw      $t5, 0x0030($sp)           
/* 0085C 809B2DFC 8E19014C */  lw      $t9, 0x014C($s0)           ## 0000014C
/* 00860 809B2E00 3C014170 */  lui     $at, 0x4170                ## $at = 41700000
/* 00864 809B2E04 51B90035 */  beql    $t5, $t9, .L809B2EDC       
/* 00868 809B2E08 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 0086C 809B2E0C 44814000 */  mtc1    $at, $f8                   ## $f8 = 15.00
/* 00870 809B2E10 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 00874 809B2E14 44818000 */  mtc1    $at, $f16                  ## $f16 = 5.00
/* 00878 809B2E18 46080282 */  mul.s   $f10, $f0, $f8             
/* 0087C 809B2E1C 3C01BF40 */  lui     $at, 0xBF40                ## $at = BF400000
/* 00880 809B2E20 44813000 */  mtc1    $at, $f6                   ## $f6 = -0.75
/* 00884 809B2E24 3C01C170 */  lui     $at, 0xC170                ## $at = C1700000
/* 00888 809B2E28 8609015A */  lh      $t1, 0x015A($s0)           ## 0000015A
/* 0088C 809B2E2C 46060202 */  mul.s   $f8, $f0, $f6              
/* 00890 809B2E30 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00894 809B2E34 46105480 */  add.s   $f18, $f10, $f16           
/* 00898 809B2E38 44815000 */  mtc1    $at, $f10                  ## $f10 = -15.00
/* 0089C 809B2E3C 260501A8 */  addiu   $a1, $s0, 0x01A8           ## $a1 = 000001A8
/* 008A0 809B2E40 4600910D */  trunc.w.s $f4, $f18                  
/* 008A4 809B2E44 460A4400 */  add.s   $f16, $f8, $f10            
/* 008A8 809B2E48 44022000 */  mfc1    $v0, $f4                   
/* 008AC 809B2E4C 4600848D */  trunc.w.s $f18, $f16                 
/* 008B0 809B2E50 A60201E8 */  sh      $v0, 0x01E8($s0)           ## 000001E8
/* 008B4 809B2E54 A60201EA */  sh      $v0, 0x01EA($s0)           ## 000001EA
/* 008B8 809B2E58 44189000 */  mfc1    $t8, $f18                  
/* 008BC 809B2E5C 1120000E */  beq     $t1, $zero, .L809B2E98     
/* 008C0 809B2E60 A61801EC */  sh      $t8, 0x01EC($s0)           ## 000001EC
/* 008C4 809B2E64 0C0189B7 */  jal     Collider_CylinderUpdate
              
/* 008C8 809B2E68 AFA50028 */  sw      $a1, 0x0028($sp)           
/* 008CC 809B2E6C 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 008D0 809B2E70 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 008D4 809B2E74 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 008D8 809B2E78 00812821 */  addu    $a1, $a0, $at              
/* 008DC 809B2E7C AFA50034 */  sw      $a1, 0x0034($sp)           
/* 008E0 809B2E80 0C0175E7 */  jal     CollisionCheck_SetAT
              ## CollisionCheck_setAT
/* 008E4 809B2E84 8FA60028 */  lw      $a2, 0x0028($sp)           
/* 008E8 809B2E88 8FA50034 */  lw      $a1, 0x0034($sp)           
/* 008EC 809B2E8C 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 008F0 809B2E90 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 008F4 809B2E94 8FA60028 */  lw      $a2, 0x0028($sp)           
.L809B2E98:
/* 008F8 809B2E98 8FA4004C */  lw      $a0, 0x004C($sp)           
/* 008FC 809B2E9C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 00900 809B2EA0 3C0641F0 */  lui     $a2, 0x41F0                ## $a2 = 41F00000
/* 00904 809B2EA4 0C00F8C3 */  jal     func_8003E30C              
/* 00908 809B2EA8 248407C0 */  addiu   $a0, $a0, 0x07C0           ## $a0 = 000007C0
/* 0090C 809B2EAC 5040000B */  beql    $v0, $zero, .L809B2EDC     
/* 00910 809B2EB0 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00914 809B2EB4 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 00918 809B2EB8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0091C 809B2EBC 2405399D */  addiu   $a1, $zero, 0x399D         ## $a1 = 0000399D
/* 00920 809B2EC0 E6000064 */  swc1    $f0, 0x0064($s0)           ## 00000064
/* 00924 809B2EC4 E6000060 */  swc1    $f0, 0x0060($s0)           ## 00000060
/* 00928 809B2EC8 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 0092C 809B2ECC E600005C */  swc1    $f0, 0x005C($s0)           ## 0000005C
/* 00930 809B2ED0 8FAA0030 */  lw      $t2, 0x0030($sp)           
/* 00934 809B2ED4 AE0A014C */  sw      $t2, 0x014C($s0)           ## 0000014C
/* 00938 809B2ED8 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L809B2EDC:
/* 0093C 809B2EDC 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00940 809B2EE0 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000
/* 00944 809B2EE4 03E00008 */  jr      $ra                        
/* 00948 809B2EE8 00000000 */  nop
