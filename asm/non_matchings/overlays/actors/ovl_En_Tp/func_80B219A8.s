.late_rodata
glabel D_80B22B88
    .float 0.2
    .balign 4

.text
glabel func_80B219A8
/* 00BC8 80B219A8 27BDFFD0 */  addiu   $sp, $sp, 0xFFD0           ## $sp = FFFFFFD0
/* 00BCC 80B219AC AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00BD0 80B219B0 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 00BD4 80B219B4 AFA50034 */  sw      $a1, 0x0034($sp)           
/* 00BD8 80B219B8 8CAF1C44 */  lw      $t7, 0x1C44($a1)           ## 00001C44
/* 00BDC 80B219BC 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 00BE0 80B219C0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00BE4 80B219C4 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 00BE8 80B219C8 3C073E4C */  lui     $a3, 0x3E4C                ## $a3 = 3E4C0000
/* 00BEC 80B219CC 34E7CCCD */  ori     $a3, $a3, 0xCCCD           ## $a3 = 3E4CCCCD
/* 00BF0 80B219D0 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 00BF4 80B219D4 24840068 */  addiu   $a0, $a0, 0x0068           ## $a0 = 00000068
/* 00BF8 80B219D8 3C054020 */  lui     $a1, 0x4020                ## $a1 = 40200000
/* 00BFC 80B219DC AFAF0028 */  sw      $t7, 0x0028($sp)           
/* 00C00 80B219E0 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 00C04 80B219E4 E7A40010 */  swc1    $f4, 0x0010($sp)           
/* 00C08 80B219E8 8FB80028 */  lw      $t8, 0x0028($sp)           
/* 00C0C 80B219EC 3C0142AA */  lui     $at, 0x42AA                ## $at = 42AA0000
/* 00C10 80B219F0 44814000 */  mtc1    $at, $f8                   ## $f8 = 85.00
/* 00C14 80B219F4 C7060028 */  lwc1    $f6, 0x0028($t8)           ## 00000028
/* 00C18 80B219F8 3C013E80 */  lui     $at, 0x3E80                ## $at = 3E800000
/* 00C1C 80B219FC C6040068 */  lwc1    $f4, 0x0068($s0)           ## 00000068
/* 00C20 80B21A00 46083280 */  add.s   $f10, $f6, $f8             
/* 00C24 80B21A04 44813000 */  mtc1    $at, $f6                   ## $f6 = 0.25
/* 00C28 80B21A08 C610016C */  lwc1    $f16, 0x016C($s0)          ## 0000016C
/* 00C2C 80B21A0C 26040028 */  addiu   $a0, $s0, 0x0028           ## $a0 = 00000028
/* 00C30 80B21A10 46062202 */  mul.s   $f8, $f4, $f6              
/* 00C34 80B21A14 46105480 */  add.s   $f18, $f10, $f16           
/* 00C38 80B21A18 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 00C3C 80B21A1C 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00C40 80B21A20 44059000 */  mfc1    $a1, $f18                  
/* 00C44 80B21A24 E7AA0010 */  swc1    $f10, 0x0010($sp)          
/* 00C48 80B21A28 44074000 */  mfc1    $a3, $f8                   
/* 00C4C 80B21A2C 0C01E0C4 */  jal     Math_SmoothScaleMaxMinF
              
/* 00C50 80B21A30 00000000 */  nop
/* 00C54 80B21A34 3C078013 */  lui     $a3, 0x8013                ## $a3 = 80130000
/* 00C58 80B21A38 3C198013 */  lui     $t9, 0x8013                ## $t9 = 80130000
/* 00C5C 80B21A3C 24E733E0 */  addiu   $a3, $a3, 0x33E0           ## $a3 = 801333E0
/* 00C60 80B21A40 273933E8 */  addiu   $t9, $t9, 0x33E8           ## $t9 = 801333E8
/* 00C64 80B21A44 AFB90014 */  sw      $t9, 0x0014($sp)           
/* 00C68 80B21A48 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 00C6C 80B21A4C 24043064 */  addiu   $a0, $zero, 0x3064         ## $a0 = 00003064
/* 00C70 80B21A50 260500E4 */  addiu   $a1, $s0, 0x00E4           ## $a1 = 000000E4
/* 00C74 80B21A54 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 00C78 80B21A58 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 00C7C 80B21A5C 92020184 */  lbu     $v0, 0x0184($s0)           ## 00000184
/* 00C80 80B21A60 30480002 */  andi    $t0, $v0, 0x0002           ## $t0 = 00000000
/* 00C84 80B21A64 11000008 */  beq     $t0, $zero, .L80B21A88     
/* 00C88 80B21A68 3049FFFD */  andi    $t1, $v0, 0xFFFD           ## $t1 = 00000000
/* 00C8C 80B21A6C A2090184 */  sb      $t1, 0x0184($s0)           ## 00000184
/* 00C90 80B21A70 8FAA0028 */  lw      $t2, 0x0028($sp)           
/* 00C94 80B21A74 8E0B0178 */  lw      $t3, 0x0178($s0)           ## 00000178
/* 00C98 80B21A78 240C0001 */  addiu   $t4, $zero, 0x0001         ## $t4 = 00000001
/* 00C9C 80B21A7C 554B0003 */  bnel    $t2, $t3, .L80B21A8C       
/* 00CA0 80B21A80 86020160 */  lh      $v0, 0x0160($s0)           ## 00000160
/* 00CA4 80B21A84 A60C015C */  sh      $t4, 0x015C($s0)           ## 0000015C
.L80B21A88:
/* 00CA8 80B21A88 86020160 */  lh      $v0, 0x0160($s0)           ## 00000160
.L80B21A8C:
/* 00CAC 80B21A8C 10400002 */  beq     $v0, $zero, .L80B21A98     
/* 00CB0 80B21A90 244DFFF1 */  addiu   $t5, $v0, 0xFFF1           ## $t5 = FFFFFFF1
/* 00CB4 80B21A94 A60D0160 */  sh      $t5, 0x0160($s0)           ## 00000160
.L80B21A98:
/* 00CB8 80B21A98 0C0329DD */  jal     func_800CA774              
/* 00CBC 80B21A9C C60C0168 */  lwc1    $f12, 0x0168($s0)          ## 00000168
/* 00CC0 80B21AA0 44808000 */  mtc1    $zero, $f16                ## $f16 = 0.00
/* 00CC4 80B21AA4 00000000 */  nop
/* 00CC8 80B21AA8 46100032 */  c.eq.s  $f0, $f16                  
/* 00CCC 80B21AAC 00000000 */  nop
/* 00CD0 80B21AB0 45000008 */  bc1f    .L80B21AD4                 
/* 00CD4 80B21AB4 00000000 */  nop
/* 00CD8 80B21AB8 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 00CDC 80B21ABC 00000000 */  nop
/* 00CE0 80B21AC0 3C014080 */  lui     $at, 0x4080                ## $at = 40800000
/* 00CE4 80B21AC4 44819000 */  mtc1    $at, $f18                  ## $f18 = 4.00
/* 00CE8 80B21AC8 00000000 */  nop
/* 00CEC 80B21ACC 46120102 */  mul.s   $f4, $f0, $f18             
/* 00CF0 80B21AD0 E6040170 */  swc1    $f4, 0x0170($s0)           ## 00000170
.L80B21AD4:
/* 00CF4 80B21AD4 0C0329DD */  jal     func_800CA774              
/* 00CF8 80B21AD8 C60C0168 */  lwc1    $f12, 0x0168($s0)          ## 00000168
/* 00CFC 80B21ADC 3C013E80 */  lui     $at, 0x3E80                ## $at = 3E800000
/* 00D00 80B21AE0 44814000 */  mtc1    $at, $f8                   ## $f8 = 0.25
/* 00D04 80B21AE4 C6060068 */  lwc1    $f6, 0x0068($s0)           ## 00000068
/* 00D08 80B21AE8 C6100170 */  lwc1    $f16, 0x0170($s0)          ## 00000170
/* 00D0C 80B21AEC 860E0032 */  lh      $t6, 0x0032($s0)           ## 00000032
/* 00D10 80B21AF0 46083282 */  mul.s   $f10, $f6, $f8             
/* 00D14 80B21AF4 C6060028 */  lwc1    $f6, 0x0028($s0)           ## 00000028
/* 00D18 80B21AF8 860F0164 */  lh      $t7, 0x0164($s0)           ## 00000164
/* 00D1C 80B21AFC 3C0180B2 */  lui     $at, %hi(D_80B22B88)       ## $at = 80B20000
/* 00D20 80B21B00 8602015A */  lh      $v0, 0x015A($s0)           ## 0000015A
/* 00D24 80B21B04 01CFC021 */  addu    $t8, $t6, $t7              
/* 00D28 80B21B08 A6180032 */  sh      $t8, 0x0032($s0)           ## 00000032
/* 00D2C 80B21B0C 46105480 */  add.s   $f18, $f10, $f16           
/* 00D30 80B21B10 C60A0168 */  lwc1    $f10, 0x0168($s0)          ## 00000168
/* 00D34 80B21B14 26040024 */  addiu   $a0, $s0, 0x0024           ## $a0 = 00000024
/* 00D38 80B21B18 2459FFFF */  addiu   $t9, $v0, 0xFFFF           ## $t9 = FFFFFFFF
/* 00D3C 80B21B1C 46120102 */  mul.s   $f4, $f0, $f18             
/* 00D40 80B21B20 46043200 */  add.s   $f8, $f6, $f4              
/* 00D44 80B21B24 E6080028 */  swc1    $f8, 0x0028($s0)           ## 00000028
/* 00D48 80B21B28 C4302B88 */  lwc1    $f16, %lo(D_80B22B88)($at) 
/* 00D4C 80B21B2C 46105480 */  add.s   $f18, $f10, $f16           
/* 00D50 80B21B30 10400002 */  beq     $v0, $zero, .L80B21B3C     
/* 00D54 80B21B34 E6120168 */  swc1    $f18, 0x0168($s0)          ## 00000168
/* 00D58 80B21B38 A619015A */  sh      $t9, 0x015A($s0)           ## 0000015A
.L80B21B3C:
/* 00D5C 80B21B3C 0C01E01A */  jal     Math_Vec3f_Yaw
              
/* 00D60 80B21B40 26050008 */  addiu   $a1, $s0, 0x0008           ## $a1 = 00000008
/* 00D64 80B21B44 00022C00 */  sll     $a1, $v0, 16               
/* 00D68 80B21B48 00052C03 */  sra     $a1, $a1, 16               
/* 00D6C 80B21B4C 26040032 */  addiu   $a0, $s0, 0x0032           ## $a0 = 00000032
/* 00D70 80B21B50 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 00D74 80B21B54 240702EE */  addiu   $a3, $zero, 0x02EE         ## $a3 = 000002EE
/* 00D78 80B21B58 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 00D7C 80B21B5C AFA00010 */  sw      $zero, 0x0010($sp)         
/* 00D80 80B21B60 8608015A */  lh      $t0, 0x015A($s0)           ## 0000015A
/* 00D84 80B21B64 55000004 */  bnel    $t0, $zero, .L80B21B78     
/* 00D88 80B21B68 86090032 */  lh      $t1, 0x0032($s0)           ## 00000032
/* 00D8C 80B21B6C 0C2C84A3 */  jal     func_80B2128C              
/* 00D90 80B21B70 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00D94 80B21B74 86090032 */  lh      $t1, 0x0032($s0)           ## 00000032
.L80B21B78:
/* 00D98 80B21B78 A60900B6 */  sh      $t1, 0x00B6($s0)           ## 000000B6
/* 00D9C 80B21B7C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00DA0 80B21B80 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00DA4 80B21B84 27BD0030 */  addiu   $sp, $sp, 0x0030           ## $sp = 00000000
/* 00DA8 80B21B88 03E00008 */  jr      $ra                        
/* 00DAC 80B21B8C 00000000 */  nop


