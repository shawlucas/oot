.rdata
glabel D_809C4B2C
    .asciz "[31m☆ game_play->bomchu_game_flag ☆ %d\n[m"
    .balign 4

glabel D_809C4B5C
    .asciz "[31m☆ 壁１の状態どう？ ☆ %d\n[m"
    .balign 4

glabel D_809C4B80
    .asciz "[31m☆ 壁２の状態どう？ ☆ %d\n[m"
    .balign 4

glabel D_809C4BA4
    .asciz "[31m☆ 穴情報	     ☆ %d\n[m"
    .balign 4

glabel D_809C4BC4
    .asciz "\n\n"
    .balign 4

glabel D_809C4BC8
    .asciz "[35m☆☆☆☆☆ 中央ＨＩＴ！！！！ ☆☆☆☆☆ \n[m"
    .balign 4

glabel D_809C4BFC
    .asciz "[35m☆☆☆☆☆ ボムチュウ消化 ☆☆☆☆☆ \n[m"
    .balign 4

.text
glabel func_809C3DC4
/* 00794 809C3DC4 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 00798 809C3DC8 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 0079C 809C3DCC 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 007A0 809C3DD0 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 007A4 809C3DD4 AFA5002C */  sw      $a1, 0x002C($sp)           
/* 007A8 809C3DD8 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 007AC 809C3DDC 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 007B0 809C3DE0 3C0E8016 */  lui     $t6, 0x8016                ## $t6 = 80160000
/* 007B4 809C3DE4 8DCEFA90 */  lw      $t6, -0x0570($t6)          ## 8015FA90
/* 007B8 809C3DE8 8FB8002C */  lw      $t8, 0x002C($sp)           
/* 007BC 809C3DEC 3C050001 */  lui     $a1, 0x0001                ## $a1 = 00010000
/* 007C0 809C3DF0 85CF12DA */  lh      $t7, 0x12DA($t6)           ## 801612DA
/* 007C4 809C3DF4 3C04809C */  lui     $a0, %hi(D_809C4B2C)       ## $a0 = 809C0000
/* 007C8 809C3DF8 00B82821 */  addu    $a1, $a1, $t8              
/* 007CC 809C3DFC 11E00013 */  beq     $t7, $zero, .L809C3E4C     
/* 007D0 809C3E00 24844B2C */  addiu   $a0, $a0, %lo(D_809C4B2C)  ## $a0 = 809C4B2C
/* 007D4 809C3E04 0C00084C */  jal     osSyncPrintf
              
/* 007D8 809C3E08 80A51E5D */  lb      $a1, 0x1E5D($a1)           ## 00011E5D
/* 007DC 809C3E0C 3C04809C */  lui     $a0, %hi(D_809C4B5C)       ## $a0 = 809C0000
/* 007E0 809C3E10 24844B5C */  addiu   $a0, $a0, %lo(D_809C4B5C)  ## $a0 = 809C4B5C
/* 007E4 809C3E14 0C00084C */  jal     osSyncPrintf
              
/* 007E8 809C3E18 8605023E */  lh      $a1, 0x023E($s0)           ## 0000023E
/* 007EC 809C3E1C 3C04809C */  lui     $a0, %hi(D_809C4B80)       ## $a0 = 809C0000
/* 007F0 809C3E20 24844B80 */  addiu   $a0, $a0, %lo(D_809C4B80)  ## $a0 = 809C4B80
/* 007F4 809C3E24 0C00084C */  jal     osSyncPrintf
              
/* 007F8 809C3E28 86050240 */  lh      $a1, 0x0240($s0)           ## 00000240
/* 007FC 809C3E2C 8E19025C */  lw      $t9, 0x025C($s0)           ## 0000025C
/* 00800 809C3E30 3C04809C */  lui     $a0, %hi(D_809C4BA4)       ## $a0 = 809C0000
/* 00804 809C3E34 24844BA4 */  addiu   $a0, $a0, %lo(D_809C4BA4)  ## $a0 = 809C4BA4
/* 00808 809C3E38 0C00084C */  jal     osSyncPrintf
              
/* 0080C 809C3E3C 93250164 */  lbu     $a1, 0x0164($t9)           ## 00000164
/* 00810 809C3E40 3C04809C */  lui     $a0, %hi(D_809C4BC4)       ## $a0 = 809C0000
/* 00814 809C3E44 0C00084C */  jal     osSyncPrintf
              
/* 00818 809C3E48 24844BC4 */  addiu   $a0, $a0, %lo(D_809C4BC4)  ## $a0 = 809C4BC4
.L809C3E4C:
/* 0081C 809C3E4C 8E02025C */  lw      $v0, 0x025C($s0)           ## 0000025C
/* 00820 809C3E50 A6000244 */  sh      $zero, 0x0244($s0)         ## 00000244
/* 00824 809C3E54 24030001 */  addiu   $v1, $zero, 0x0001         ## $v1 = 00000001
/* 00828 809C3E58 5040002B */  beql    $v0, $zero, .L809C3F08     
/* 0082C 809C3E5C 86080244 */  lh      $t0, 0x0244($s0)           ## 00000244
/* 00830 809C3E60 8608023E */  lh      $t0, 0x023E($s0)           ## 0000023E
/* 00834 809C3E64 8FA7002C */  lw      $a3, 0x002C($sp)           
/* 00838 809C3E68 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 0083C 809C3E6C 10680010 */  beq     $v1, $t0, .L809C3EB0       
/* 00840 809C3E70 00E12821 */  addu    $a1, $a3, $at              
/* 00844 809C3E74 86090240 */  lh      $t1, 0x0240($s0)           ## 00000240
/* 00848 809C3E78 5069000E */  beql    $v1, $t1, .L809C3EB4       
/* 0084C 809C3E7C 80AB1E5D */  lb      $t3, 0x1E5D($a1)           ## 00001E5D
/* 00850 809C3E80 904A0164 */  lbu     $t2, 0x0164($v0)           ## 00000164
/* 00854 809C3E84 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 00858 809C3E88 3C04809C */  lui     $a0, %hi(D_809C4BC8)       ## $a0 = 809C0000
/* 0085C 809C3E8C 15410008 */  bne     $t2, $at, .L809C3EB0       
/* 00860 809C3E90 24844BC8 */  addiu   $a0, $a0, %lo(D_809C4BC8)  ## $a0 = 809C4BC8
/* 00864 809C3E94 A6030244 */  sh      $v1, 0x0244($s0)           ## 00000244
/* 00868 809C3E98 A0400164 */  sb      $zero, 0x0164($v0)         ## 00000164
/* 0086C 809C3E9C 0C00084C */  jal     osSyncPrintf
              
/* 00870 809C3EA0 AFA50020 */  sw      $a1, 0x0020($sp)           
/* 00874 809C3EA4 24030001 */  addiu   $v1, $zero, 0x0001         ## $v1 = 00000001
/* 00878 809C3EA8 8FA50020 */  lw      $a1, 0x0020($sp)           
/* 0087C 809C3EAC 8FA7002C */  lw      $a3, 0x002C($sp)           
.L809C3EB0:
/* 00880 809C3EB0 80AB1E5D */  lb      $t3, 0x1E5D($a1)           ## 00001E5D
.L809C3EB4:
/* 00884 809C3EB4 2401FFFF */  addiu   $at, $zero, 0xFFFF         ## $at = FFFFFFFF
/* 00888 809C3EB8 55610013 */  bnel    $t3, $at, .L809C3F08       
/* 0088C 809C3EBC 86080244 */  lh      $t0, 0x0244($s0)           ## 00000244
/* 00890 809C3EC0 8CEC1C48 */  lw      $t4, 0x1C48($a3)           ## 00001C48
/* 00894 809C3EC4 55800010 */  bnel    $t4, $zero, .L809C3F08     
/* 00898 809C3EC8 86080244 */  lh      $t0, 0x0244($s0)           ## 00000244
/* 0089C 809C3ECC 8E0D025C */  lw      $t5, 0x025C($s0)           ## 0000025C
/* 008A0 809C3ED0 91AE0164 */  lbu     $t6, 0x0164($t5)           ## 00000164
/* 008A4 809C3ED4 55C0000C */  bnel    $t6, $zero, .L809C3F08     
/* 008A8 809C3ED8 86080244 */  lh      $t0, 0x0244($s0)           ## 00000244
/* 008AC 809C3EDC 860F023E */  lh      $t7, 0x023E($s0)           ## 0000023E
/* 008B0 809C3EE0 506F0009 */  beql    $v1, $t7, .L809C3F08       
/* 008B4 809C3EE4 86080244 */  lh      $t0, 0x0244($s0)           ## 00000244
/* 008B8 809C3EE8 86180240 */  lh      $t8, 0x0240($s0)           ## 00000240
/* 008BC 809C3EEC 3C04809C */  lui     $a0, %hi(D_809C4BFC)       ## $a0 = 809C0000
/* 008C0 809C3EF0 24190002 */  addiu   $t9, $zero, 0x0002         ## $t9 = 00000002
/* 008C4 809C3EF4 10780003 */  beq     $v1, $t8, .L809C3F04       
/* 008C8 809C3EF8 24844BFC */  addiu   $a0, $a0, %lo(D_809C4BFC)  ## $a0 = 809C4BFC
/* 008CC 809C3EFC 0C00084C */  jal     osSyncPrintf
              
/* 008D0 809C3F00 A6190244 */  sh      $t9, 0x0244($s0)           ## 00000244
.L809C3F04:
/* 008D4 809C3F04 86080244 */  lh      $t0, 0x0244($s0)           ## 00000244
.L809C3F08:
/* 008D8 809C3F08 24030001 */  addiu   $v1, $zero, 0x0001         ## $v1 = 00000001
/* 008DC 809C3F0C 8FA7002C */  lw      $a3, 0x002C($sp)           
/* 008E0 809C3F10 11000020 */  beq     $t0, $zero, .L809C3F94     
/* 008E4 809C3F14 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 008E8 809C3F18 8E020260 */  lw      $v0, 0x0260($s0)           ## 00000260
/* 008EC 809C3F1C 2409001A */  addiu   $t1, $zero, 0x001A         ## $t1 = 0000001A
/* 008F0 809C3F20 240A0004 */  addiu   $t2, $zero, 0x0004         ## $t2 = 00000004
/* 008F4 809C3F24 A609010E */  sh      $t1, 0x010E($s0)           ## 0000010E
/* 008F8 809C3F28 A60A022E */  sh      $t2, 0x022E($s0)           ## 0000022E
/* 008FC 809C3F2C 10400006 */  beq     $v0, $zero, .L809C3F48     
/* 00900 809C3F30 A2000258 */  sb      $zero, 0x0258($s0)         ## 00000258
/* 00904 809C3F34 8C4B0130 */  lw      $t3, 0x0130($v0)           ## 00000130
/* 00908 809C3F38 51600004 */  beql    $t3, $zero, .L809C3F4C     
/* 0090C 809C3F3C 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 00910 809C3F40 A4430160 */  sh      $v1, 0x0160($v0)           ## 00000160
/* 00914 809C3F44 AE000260 */  sw      $zero, 0x0260($s0)         ## 00000260
.L809C3F48:
/* 00918 809C3F48 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
.L809C3F4C:
/* 0091C 809C3F4C 00270821 */  addu    $at, $at, $a3              
/* 00920 809C3F50 A0201E5D */  sb      $zero, 0x1E5D($at)         ## 00011E5D
/* 00924 809C3F54 A603023C */  sh      $v1, 0x023C($s0)           ## 0000023C
/* 00928 809C3F58 9605010E */  lhu     $a1, 0x010E($s0)           ## 0000010E
/* 0092C 809C3F5C 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 00930 809C3F60 0C042DA0 */  jal     func_8010B680              
/* 00934 809C3F64 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 00938 809C3F68 860C0244 */  lh      $t4, 0x0244($s0)           ## 00000244
/* 0093C 809C3F6C 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 00940 809C3F70 8FA4002C */  lw      $a0, 0x002C($sp)           
/* 00944 809C3F74 15810003 */  bne     $t4, $at, .L809C3F84       
/* 00948 809C3F78 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 0094C 809C3F7C 0C00B7D5 */  jal     func_8002DF54              
/* 00950 809C3F80 24060008 */  addiu   $a2, $zero, 0x0008         ## $a2 = 00000008
.L809C3F84:
/* 00954 809C3F84 3C0D809C */  lui     $t5, %hi(func_809C4040)    ## $t5 = 809C0000
/* 00958 809C3F88 25AD4040 */  addiu   $t5, $t5, %lo(func_809C4040) ## $t5 = 809C4040
/* 0095C 809C3F8C 10000027 */  beq     $zero, $zero, .L809C402C   
/* 00960 809C3F90 AE0D0214 */  sw      $t5, 0x0214($s0)           ## 00000214
.L809C3F94:
/* 00964 809C3F94 0C00BC65 */  jal     func_8002F194              
/* 00968 809C3F98 00E02825 */  or      $a1, $a3, $zero            ## $a1 = 00000000
/* 0096C 809C3F9C 1040000B */  beq     $v0, $zero, .L809C3FCC     
/* 00970 809C3FA0 3C0142F0 */  lui     $at, 0x42F0                ## $at = 42F00000
/* 00974 809C3FA4 920E0258 */  lbu     $t6, 0x0258($s0)           ## 00000258
/* 00978 809C3FA8 3C18809C */  lui     $t8, %hi(func_809C41FC)    ## $t8 = 809C0000
/* 0097C 809C3FAC 3C0F809C */  lui     $t7, %hi(func_809C4040)    ## $t7 = 809C0000
/* 00980 809C3FB0 15C00004 */  bne     $t6, $zero, .L809C3FC4     
/* 00984 809C3FB4 271841FC */  addiu   $t8, $t8, %lo(func_809C41FC) ## $t8 = 809C41FC
/* 00988 809C3FB8 25EF4040 */  addiu   $t7, $t7, %lo(func_809C4040) ## $t7 = 809C4040
/* 0098C 809C3FBC 1000001B */  beq     $zero, $zero, .L809C402C   
/* 00990 809C3FC0 AE0F0214 */  sw      $t7, 0x0214($s0)           ## 00000214
.L809C3FC4:
/* 00994 809C3FC4 10000019 */  beq     $zero, $zero, .L809C402C   
/* 00998 809C3FC8 AE180214 */  sw      $t8, 0x0214($s0)           ## 00000214
.L809C3FCC:
/* 0099C 809C3FCC 8619008A */  lh      $t9, 0x008A($s0)           ## 0000008A
/* 009A0 809C3FD0 860800B6 */  lh      $t0, 0x00B6($s0)           ## 000000B6
/* 009A4 809C3FD4 44810000 */  mtc1    $at, $f0                   ## $f0 = 120.00
/* 009A8 809C3FD8 03281023 */  subu    $v0, $t9, $t0              
/* 009AC 809C3FDC 00021400 */  sll     $v0, $v0, 16               
/* 009B0 809C3FE0 00021403 */  sra     $v0, $v0, 16               
/* 009B4 809C3FE4 04400004 */  bltz    $v0, .L809C3FF8            
/* 009B8 809C3FE8 00021823 */  subu    $v1, $zero, $v0            
/* 009BC 809C3FEC 00021C00 */  sll     $v1, $v0, 16               
/* 009C0 809C3FF0 10000003 */  beq     $zero, $zero, .L809C4000   
/* 009C4 809C3FF4 00031C03 */  sra     $v1, $v1, 16               
.L809C3FF8:
/* 009C8 809C3FF8 00031C00 */  sll     $v1, $v1, 16               
/* 009CC 809C3FFC 00031C03 */  sra     $v1, $v1, 16               
.L809C4000:
/* 009D0 809C4000 C6040090 */  lwc1    $f4, 0x0090($s0)           ## 00000090
/* 009D4 809C4004 28614300 */  slti    $at, $v1, 0x4300           
/* 009D8 809C4008 4604003C */  c.lt.s  $f0, $f4                   
/* 009DC 809C400C 00000000 */  nop
/* 009E0 809C4010 45030007 */  bc1tl   .L809C4030                 
/* 009E4 809C4014 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 009E8 809C4018 10200004 */  beq     $at, $zero, .L809C402C     
/* 009EC 809C401C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 009F0 809C4020 44060000 */  mfc1    $a2, $f0                   
/* 009F4 809C4024 0C00BCB3 */  jal     func_8002F2CC              
/* 009F8 809C4028 8FA5002C */  lw      $a1, 0x002C($sp)           
.L809C402C:
/* 009FC 809C402C 8FBF001C */  lw      $ra, 0x001C($sp)           
.L809C4030:
/* 00A00 809C4030 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00A04 809C4034 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 00A08 809C4038 03E00008 */  jr      $ra                        
/* 00A0C 809C403C 00000000 */  nop
