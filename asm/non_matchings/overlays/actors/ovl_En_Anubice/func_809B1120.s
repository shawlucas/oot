.late_rodata

glabel D_809B2410
 .float 1500.0

.text
glabel func_809B1120
/* 00000 809B1120 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 00004 809B1124 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00008 809B1128 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 0000C 809B112C AFA50024 */  sw      $a1, 0x0024($sp)           
/* 00010 809B1130 3C01809B */  lui     $at, %hi(D_809B2410)       ## $at = 809B0000
/* 00014 809B1134 C4262410 */  lwc1    $f6, %lo(D_809B2410)($at)  
/* 00018 809B1138 C4840268 */  lwc1    $f4, 0x0268($a0)           ## 00000268
/* 0001C 809B113C 8CA21C44 */  lw      $v0, 0x1C44($a1)           ## 00001C44
/* 00020 809B1140 C4900274 */  lwc1    $f16, 0x0274($a0)          ## 00000274
/* 00024 809B1144 46062200 */  add.s   $f8, $f4, $f6              
/* 00028 809B1148 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0002C 809B114C 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 00030 809B1150 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 00034 809B1154 E4880268 */  swc1    $f8, 0x0268($a0)           ## 00000268
/* 00038 809B1158 C44A0028 */  lwc1    $f10, 0x0028($v0)          ## 00000028
/* 0003C 809B115C 24840028 */  addiu   $a0, $a0, 0x0028           ## $a0 = 00000028
/* 00040 809B1160 3C074120 */  lui     $a3, 0x4120                ## $a3 = 41200000
/* 00044 809B1164 46105480 */  add.s   $f18, $f10, $f16           
/* 00048 809B1168 E4920248 */  swc1    $f18, 0x0248($a0)          ## 00000270
/* 0004C 809B116C 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 00050 809B1170 8E050270 */  lw      $a1, 0x0270($s0)           ## 00000270
/* 00054 809B1174 3C063DCC */  lui     $a2, 0x3DCC                ## $a2 = 3DCC0000
/* 00058 809B1178 34C6CCCD */  ori     $a2, $a2, 0xCCCD           ## $a2 = 3DCCCCCD
/* 0005C 809B117C 26040274 */  addiu   $a0, $s0, 0x0274           ## $a0 = 00000274
/* 00060 809B1180 3C054120 */  lui     $a1, 0x4120                ## $a1 = 41200000
/* 00064 809B1184 0C01E107 */  jal     Math_SmoothScaleMaxF
              
/* 00068 809B1188 3C073F00 */  lui     $a3, 0x3F00                ## $a3 = 3F000000
/* 0006C 809B118C C6040268 */  lwc1    $f4, 0x0268($s0)           ## 00000268
/* 00070 809B1190 4600218D */  trunc.w.s $f6, $f4                   
/* 00074 809B1194 44043000 */  mfc1    $a0, $f6                   
/* 00078 809B1198 00000000 */  nop
/* 0007C 809B119C 00042400 */  sll     $a0, $a0, 16               
/* 00080 809B11A0 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00084 809B11A4 00042403 */  sra     $a0, $a0, 16               
/* 00088 809B11A8 E6000060 */  swc1    $f0, 0x0060($s0)           ## 00000060
/* 0008C 809B11AC 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00090 809B11B0 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00094 809B11B4 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 00098 809B11B8 03E00008 */  jr      $ra                        
/* 0009C 809B11BC 00000000 */  nop


