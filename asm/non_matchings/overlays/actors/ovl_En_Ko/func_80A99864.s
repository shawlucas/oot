glabel func_80A99864
/* 02AB4 80A99864 27BDFFB0 */  addiu   $sp, $sp, 0xFFB0           ## $sp = FFFFFFB0
/* 02AB8 80A99868 AFB10018 */  sw      $s1, 0x0018($sp)           
/* 02ABC 80A9986C AFA7005C */  sw      $a3, 0x005C($sp)           
/* 02AC0 80A99870 2401000F */  addiu   $at, $zero, 0x000F         ## $at = 0000000F
/* 02AC4 80A99874 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 02AC8 80A99878 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 02ACC 80A9987C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 02AD0 80A99880 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 02AD4 80A99884 14A10050 */  bne     $a1, $at, .L80A999C8       
/* 02AD8 80A99888 AFA40050 */  sw      $a0, 0x0050($sp)           
/* 02ADC 80A9988C 8FA40068 */  lw      $a0, 0x0068($sp)           
/* 02AE0 80A99890 8FB00064 */  lw      $s0, 0x0064($sp)           
/* 02AE4 80A99894 3C0FDB06 */  lui     $t7, 0xDB06                ## $t7 = DB060000
/* 02AE8 80A99898 8C830000 */  lw      $v1, 0x0000($a0)           ## 00000000
/* 02AEC 80A9989C 35EF0018 */  ori     $t7, $t7, 0x0018           ## $t7 = DB060018
/* 02AF0 80A998A0 24080044 */  addiu   $t0, $zero, 0x0044         ## $t0 = 00000044
/* 02AF4 80A998A4 246E0008 */  addiu   $t6, $v1, 0x0008           ## $t6 = 00000008
/* 02AF8 80A998A8 AC8E0000 */  sw      $t6, 0x0000($a0)           ## 00000000
/* 02AFC 80A998AC AC6F0000 */  sw      $t7, 0x0000($v1)           ## 00000000
/* 02B00 80A998B0 82180194 */  lb      $t8, 0x0194($s0)           ## 00000194
/* 02B04 80A998B4 3C090001 */  lui     $t1, 0x0001                ## $t1 = 00010000
/* 02B08 80A998B8 3C0A8000 */  lui     $t2, 0x8000                ## $t2 = 80000000
/* 02B0C 80A998BC 03080019 */  multu   $t8, $t0                   
/* 02B10 80A998C0 3C018016 */  lui     $at, 0x8016                ## $at = 80160000
/* 02B14 80A998C4 0000C812 */  mflo    $t9                        
/* 02B18 80A998C8 00F95821 */  addu    $t3, $a3, $t9              
/* 02B1C 80A998CC 01696021 */  addu    $t4, $t3, $t1              
/* 02B20 80A998D0 8D8D17B4 */  lw      $t5, 0x17B4($t4)           ## 000017B4
/* 02B24 80A998D4 AC6D0004 */  sw      $t5, 0x0004($v1)           ## 00000004
/* 02B28 80A998D8 820E0194 */  lb      $t6, 0x0194($s0)           ## 00000194
/* 02B2C 80A998DC 3C0380AA */  lui     $v1, %hi(D_80A9A500)       ## $v1 = 80AA0000
/* 02B30 80A998E0 01C80019 */  multu   $t6, $t0                   
/* 02B34 80A998E4 00007812 */  mflo    $t7                        
/* 02B38 80A998E8 00EFC021 */  addu    $t8, $a3, $t7              
/* 02B3C 80A998EC 0309C821 */  addu    $t9, $t8, $t1              
/* 02B40 80A998F0 8F2B17B4 */  lw      $t3, 0x17B4($t9)           ## 000017B4
/* 02B44 80A998F4 3C1980AA */  lui     $t9, %hi(D_80A9A158)       ## $t9 = 80AA0000
/* 02B48 80A998F8 2739A158 */  addiu   $t9, $t9, %lo(D_80A9A158)  ## $t9 = 80A9A158
/* 02B4C 80A998FC 016A6021 */  addu    $t4, $t3, $t2              
/* 02B50 80A99900 AC2C6FC0 */  sw      $t4, 0x6FC0($at)           ## 80166FC0
/* 02B54 80A99904 860D001C */  lh      $t5, 0x001C($s0)           ## 0000001C
/* 02B58 80A99908 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 02B5C 80A9990C 31AE00FF */  andi    $t6, $t5, 0x00FF           ## $t6 = 00000000
/* 02B60 80A99910 000E7880 */  sll     $t7, $t6,  2               
/* 02B64 80A99914 01EE7823 */  subu    $t7, $t7, $t6              
/* 02B68 80A99918 000F7880 */  sll     $t7, $t7,  2               
/* 02B6C 80A9991C 01EE7823 */  subu    $t7, $t7, $t6              
/* 02B70 80A99920 006F1821 */  addu    $v1, $v1, $t7              
/* 02B74 80A99924 9063A500 */  lbu     $v1, %lo(D_80A9A500)($v1)  
/* 02B78 80A99928 0003C080 */  sll     $t8, $v1,  2               
/* 02B7C 80A9992C 0303C023 */  subu    $t8, $t8, $v1              
/* 02B80 80A99930 0018C080 */  sll     $t8, $t8,  2               
/* 02B84 80A99934 03191021 */  addu    $v0, $t8, $t9              
/* 02B88 80A99938 8C4B0004 */  lw      $t3, 0x0004($v0)           ## 00000004
/* 02B8C 80A9993C 3C18DB06 */  lui     $t8, 0xDB06                ## $t8 = DB060000
/* 02B90 80A99940 37180028 */  ori     $t8, $t8, 0x0028           ## $t8 = DB060028
/* 02B94 80A99944 ACCB0000 */  sw      $t3, 0x0000($a2)           ## 00000000
/* 02B98 80A99948 8C450008 */  lw      $a1, 0x0008($v0)           ## 00000008
/* 02B9C 80A9994C 50A00016 */  beql    $a1, $zero, .L80A999A8     
/* 02BA0 80A99950 82190196 */  lb      $t9, 0x0196($s0)           ## 00000196
/* 02BA4 80A99954 860C0216 */  lh      $t4, 0x0216($s0)           ## 00000216
/* 02BA8 80A99958 8C830000 */  lw      $v1, 0x0000($a0)           ## 00000000
/* 02BAC 80A9995C 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 02BB0 80A99960 000C6880 */  sll     $t5, $t4,  2               
/* 02BB4 80A99964 00AD7021 */  addu    $t6, $a1, $t5              
/* 02BB8 80A99968 8DC60000 */  lw      $a2, 0x0000($t6)           ## 00000000
/* 02BBC 80A9996C 246F0008 */  addiu   $t7, $v1, 0x0008           ## $t7 = 80AA0008
/* 02BC0 80A99970 AC8F0000 */  sw      $t7, 0x0000($a0)           ## 00000000
/* 02BC4 80A99974 0006C900 */  sll     $t9, $a2,  4               
/* 02BC8 80A99978 00195F02 */  srl     $t3, $t9, 28               
/* 02BCC 80A9997C 000B6080 */  sll     $t4, $t3,  2               
/* 02BD0 80A99980 3C0D8016 */  lui     $t5, 0x8016                ## $t5 = 80160000
/* 02BD4 80A99984 01AC6821 */  addu    $t5, $t5, $t4              
/* 02BD8 80A99988 AC780000 */  sw      $t8, 0x0000($v1)           ## 80AA0000
/* 02BDC 80A9998C 8DAD6FA8 */  lw      $t5, 0x6FA8($t5)           ## 80166FA8
/* 02BE0 80A99990 00C17024 */  and     $t6, $a2, $at              
/* 02BE4 80A99994 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 02BE8 80A99998 01AE7821 */  addu    $t7, $t5, $t6              
/* 02BEC 80A9999C 01E1C021 */  addu    $t8, $t7, $at              
/* 02BF0 80A999A0 AC780004 */  sw      $t8, 0x0004($v1)           ## 80AA0004
/* 02BF4 80A999A4 82190196 */  lb      $t9, 0x0196($s0)           ## 00000196
.L80A999A8:
/* 02BF8 80A999A8 3C018016 */  lui     $at, 0x8016                ## $at = 80160000
/* 02BFC 80A999AC 03280019 */  multu   $t9, $t0                   
/* 02C00 80A999B0 00005812 */  mflo    $t3                        
/* 02C04 80A999B4 00EB6021 */  addu    $t4, $a3, $t3              
/* 02C08 80A999B8 01896821 */  addu    $t5, $t4, $t1              
/* 02C0C 80A999BC 8DAE17B4 */  lw      $t6, 0x17B4($t5)           ## 801617B4
/* 02C10 80A999C0 01CA7821 */  addu    $t7, $t6, $t2              
/* 02C14 80A999C4 AC2F6FC0 */  sw      $t7, 0x6FC0($at)           ## 80166FC0
.L80A999C8:
/* 02C18 80A999C8 24010008 */  addiu   $at, $zero, 0x0008         ## $at = 00000008
/* 02C1C 80A999CC 16210021 */  bne     $s1, $at, .L80A99A54       
/* 02C20 80A999D0 8FB00064 */  lw      $s0, 0x0064($sp)           
/* 02C24 80A999D4 8A0B01F6 */  lwl     $t3, 0x01F6($s0)           ## 000001F6
/* 02C28 80A999D8 9A0B01F9 */  lwr     $t3, 0x01F9($s0)           ## 000001F9
/* 02C2C 80A999DC 27B80040 */  addiu   $t8, $sp, 0x0040           ## $t8 = FFFFFFF0
/* 02C30 80A999E0 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02C34 80A999E4 AF0B0000 */  sw      $t3, 0x0000($t8)           ## FFFFFFF0
/* 02C38 80A999E8 960B01FA */  lhu     $t3, 0x01FA($s0)           ## 000001FA
/* 02C3C 80A999EC 44814000 */  mtc1    $at, $f8                   ## $f8 = 32768.00
/* 02C40 80A999F0 3C0180AA */  lui     $at, %hi(D_80A9A9C4)       ## $at = 80AA0000
/* 02C44 80A999F4 A70B0004 */  sh      $t3, 0x0004($t8)           ## FFFFFFF4
/* 02C48 80A999F8 87AC0042 */  lh      $t4, 0x0042($sp)           
/* 02C4C 80A999FC C430A9C4 */  lwc1    $f16, %lo(D_80A9A9C4)($at) 
/* 02C50 80A99A00 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02C54 80A99A04 000C6823 */  subu    $t5, $zero, $t4            
/* 02C58 80A99A08 448D2000 */  mtc1    $t5, $f4                   ## $f4 = -0.00
/* 02C5C 80A99A0C 00000000 */  nop
/* 02C60 80A99A10 468021A0 */  cvt.s.w $f6, $f4                   
/* 02C64 80A99A14 46083283 */  div.s   $f10, $f6, $f8             
/* 02C68 80A99A18 46105302 */  mul.s   $f12, $f10, $f16           
/* 02C6C 80A99A1C 0C0342DC */  jal     Matrix_RotateX              
/* 02C70 80A99A20 00000000 */  nop
/* 02C74 80A99A24 87AE0040 */  lh      $t6, 0x0040($sp)           
/* 02C78 80A99A28 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02C7C 80A99A2C 44813000 */  mtc1    $at, $f6                   ## $f6 = 32768.00
/* 02C80 80A99A30 448E9000 */  mtc1    $t6, $f18                  ## $f18 = 0.00
/* 02C84 80A99A34 3C0180AA */  lui     $at, %hi(D_80A9A9C8)       ## $at = 80AA0000
/* 02C88 80A99A38 C42AA9C8 */  lwc1    $f10, %lo(D_80A9A9C8)($at) 
/* 02C8C 80A99A3C 46809120 */  cvt.s.w $f4, $f18                  
/* 02C90 80A99A40 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02C94 80A99A44 46062203 */  div.s   $f8, $f4, $f6              
/* 02C98 80A99A48 460A4302 */  mul.s   $f12, $f8, $f10            
/* 02C9C 80A99A4C 0C0343B5 */  jal     Matrix_RotateZ              
/* 02CA0 80A99A50 00000000 */  nop
.L80A99A54:
/* 02CA4 80A99A54 2401000F */  addiu   $at, $zero, 0x000F         ## $at = 0000000F
/* 02CA8 80A99A58 5621002D */  bnel    $s1, $at, .L80A99B10       
/* 02CAC 80A99A5C 24010008 */  addiu   $at, $zero, 0x0008         ## $at = 00000008
/* 02CB0 80A99A60 44807000 */  mtc1    $zero, $f14                ## $f14 = 0.00
/* 02CB4 80A99A64 3C014496 */  lui     $at, 0x4496                ## $at = 44960000
/* 02CB8 80A99A68 44816000 */  mtc1    $at, $f12                  ## $f12 = 1200.00
/* 02CBC 80A99A6C 44067000 */  mfc1    $a2, $f14                  
/* 02CC0 80A99A70 0C034261 */  jal     Matrix_Translate              
/* 02CC4 80A99A74 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 02CC8 80A99A78 8A1901F0 */  lwl     $t9, 0x01F0($s0)           ## 000001F0
/* 02CCC 80A99A7C 9A1901F3 */  lwr     $t9, 0x01F3($s0)           ## 000001F3
/* 02CD0 80A99A80 27AF0040 */  addiu   $t7, $sp, 0x0040           ## $t7 = FFFFFFF0
/* 02CD4 80A99A84 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02CD8 80A99A88 ADF90000 */  sw      $t9, 0x0000($t7)           ## FFFFFFF0
/* 02CDC 80A99A8C 961901F4 */  lhu     $t9, 0x01F4($s0)           ## 000001F4
/* 02CE0 80A99A90 44812000 */  mtc1    $at, $f4                   ## $f4 = 32768.00
/* 02CE4 80A99A94 3C0180AA */  lui     $at, %hi(D_80A9A9CC)       ## $at = 80AA0000
/* 02CE8 80A99A98 A5F90004 */  sh      $t9, 0x0004($t7)           ## FFFFFFF4
/* 02CEC 80A99A9C 87AB0042 */  lh      $t3, 0x0042($sp)           
/* 02CF0 80A99AA0 C428A9CC */  lwc1    $f8, %lo(D_80A9A9CC)($at)  
/* 02CF4 80A99AA4 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02CF8 80A99AA8 448B8000 */  mtc1    $t3, $f16                  ## $f16 = 0.00
/* 02CFC 80A99AAC 00000000 */  nop
/* 02D00 80A99AB0 468084A0 */  cvt.s.w $f18, $f16                 
/* 02D04 80A99AB4 46049183 */  div.s   $f6, $f18, $f4             
/* 02D08 80A99AB8 46083302 */  mul.s   $f12, $f6, $f8             
/* 02D0C 80A99ABC 0C0342DC */  jal     Matrix_RotateX              
/* 02D10 80A99AC0 00000000 */  nop
/* 02D14 80A99AC4 87AC0040 */  lh      $t4, 0x0040($sp)           
/* 02D18 80A99AC8 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02D1C 80A99ACC 44819000 */  mtc1    $at, $f18                  ## $f18 = 32768.00
/* 02D20 80A99AD0 448C5000 */  mtc1    $t4, $f10                  ## $f10 = 0.00
/* 02D24 80A99AD4 3C0180AA */  lui     $at, %hi(D_80A9A9D0)       ## $at = 80AA0000
/* 02D28 80A99AD8 C426A9D0 */  lwc1    $f6, %lo(D_80A9A9D0)($at)  
/* 02D2C 80A99ADC 46805420 */  cvt.s.w $f16, $f10                 
/* 02D30 80A99AE0 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02D34 80A99AE4 46128103 */  div.s   $f4, $f16, $f18            
/* 02D38 80A99AE8 46062302 */  mul.s   $f12, $f4, $f6             
/* 02D3C 80A99AEC 0C0343B5 */  jal     Matrix_RotateZ              
/* 02D40 80A99AF0 00000000 */  nop
/* 02D44 80A99AF4 44807000 */  mtc1    $zero, $f14                ## $f14 = 0.00
/* 02D48 80A99AF8 3C01C496 */  lui     $at, 0xC496                ## $at = C4960000
/* 02D4C 80A99AFC 44816000 */  mtc1    $at, $f12                  ## $f12 = -1200.00
/* 02D50 80A99B00 44067000 */  mfc1    $a2, $f14                  
/* 02D54 80A99B04 0C034261 */  jal     Matrix_Translate              
/* 02D58 80A99B08 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 02D5C 80A99B0C 24010008 */  addiu   $at, $zero, 0x0008         ## $at = 00000008
.L80A99B10:
/* 02D60 80A99B10 12210005 */  beq     $s1, $at, .L80A99B28       
/* 02D64 80A99B14 00116840 */  sll     $t5, $s1,  1               
/* 02D68 80A99B18 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 02D6C 80A99B1C 12210002 */  beq     $s1, $at, .L80A99B28       
/* 02D70 80A99B20 2401000C */  addiu   $at, $zero, 0x000C         ## $at = 0000000C
/* 02D74 80A99B24 16210021 */  bne     $s1, $at, .L80A99BAC       
.L80A99B28:
/* 02D78 80A99B28 020D1821 */  addu    $v1, $s0, $t5              
/* 02D7C 80A99B2C 846402E4 */  lh      $a0, 0x02E4($v1)           ## 000002E4
/* 02D80 80A99B30 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 02D84 80A99B34 AFA30028 */  sw      $v1, 0x0028($sp)           
/* 02D88 80A99B38 8FA20060 */  lw      $v0, 0x0060($sp)           
/* 02D8C 80A99B3C 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 02D90 80A99B40 44818000 */  mtc1    $at, $f16                  ## $f16 = 200.00
/* 02D94 80A99B44 844E0002 */  lh      $t6, 0x0002($v0)           ## 00000002
/* 02D98 80A99B48 8FA30028 */  lw      $v1, 0x0028($sp)           
/* 02D9C 80A99B4C 46100482 */  mul.s   $f18, $f0, $f16            
/* 02DA0 80A99B50 448E4000 */  mtc1    $t6, $f8                   ## $f8 = 0.00
/* 02DA4 80A99B54 00000000 */  nop
/* 02DA8 80A99B58 468042A0 */  cvt.s.w $f10, $f8                  
/* 02DAC 80A99B5C 46125100 */  add.s   $f4, $f10, $f18            
/* 02DB0 80A99B60 4600218D */  trunc.w.s $f6, $f4                   
/* 02DB4 80A99B64 44183000 */  mfc1    $t8, $f6                   
/* 02DB8 80A99B68 00000000 */  nop
/* 02DBC 80A99B6C A4580002 */  sh      $t8, 0x0002($v0)           ## 00000002
/* 02DC0 80A99B70 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 02DC4 80A99B74 84640304 */  lh      $a0, 0x0304($v1)           ## 00000304
/* 02DC8 80A99B78 8FA20060 */  lw      $v0, 0x0060($sp)           
/* 02DCC 80A99B7C 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 02DD0 80A99B80 44815000 */  mtc1    $at, $f10                  ## $f10 = 200.00
/* 02DD4 80A99B84 84590004 */  lh      $t9, 0x0004($v0)           ## 00000004
/* 02DD8 80A99B88 460A0482 */  mul.s   $f18, $f0, $f10            
/* 02DDC 80A99B8C 44994000 */  mtc1    $t9, $f8                   ## $f8 = 0.00
/* 02DE0 80A99B90 00000000 */  nop
/* 02DE4 80A99B94 46804420 */  cvt.s.w $f16, $f8                  
/* 02DE8 80A99B98 46128100 */  add.s   $f4, $f16, $f18            
/* 02DEC 80A99B9C 4600218D */  trunc.w.s $f6, $f4                   
/* 02DF0 80A99BA0 440C3000 */  mfc1    $t4, $f6                   
/* 02DF4 80A99BA4 00000000 */  nop
/* 02DF8 80A99BA8 A44C0004 */  sh      $t4, 0x0004($v0)           ## 00000004
.L80A99BAC:
/* 02DFC 80A99BAC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 02E00 80A99BB0 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 02E04 80A99BB4 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 02E08 80A99BB8 27BD0050 */  addiu   $sp, $sp, 0x0050           ## $sp = 00000000
/* 02E0C 80A99BBC 03E00008 */  jr      $ra                        
/* 02E10 80A99BC0 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
