glabel func_80B1778C
/* 0022C 80B1778C 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 00230 80B17790 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00234 80B17794 00803825 */  or      $a3, $a0, $zero            ## $a3 = 00000000
/* 00238 80B17798 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 0023C 80B1779C AFA70020 */  sw      $a3, 0x0020($sp)           
/* 00240 80B177A0 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 00244 80B177A4 24840150 */  addiu   $a0, $a0, 0x0150           ## $a0 = 00000150
/* 00248 80B177A8 8FA40020 */  lw      $a0, 0x0020($sp)           
/* 0024C 80B177AC 0C00BC65 */  jal     func_8002F194              
/* 00250 80B177B0 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 00254 80B177B4 1040000F */  beq     $v0, $zero, .L80B177F4     
/* 00258 80B177B8 8FA70020 */  lw      $a3, 0x0020($sp)           
/* 0025C 80B177BC 84EE020C */  lh      $t6, 0x020C($a3)           ## 0000020C
/* 00260 80B177C0 24060006 */  addiu   $a2, $zero, 0x0006         ## $a2 = 00000006
/* 00264 80B177C4 50CE000C */  beql    $a2, $t6, .L80B177F8       
/* 00268 80B177C8 8FA80024 */  lw      $t0, 0x0024($sp)           
/* 0026C 80B177CC 84EF0214 */  lh      $t7, 0x0214($a3)           ## 00000214
/* 00270 80B177D0 3C1980B1 */  lui     $t9, %hi(func_80B17B14)    ## $t9 = 80B10000
/* 00274 80B177D4 3C1880B1 */  lui     $t8, %hi(func_80B17934)    ## $t8 = 80B10000
/* 00278 80B177D8 15E00004 */  bne     $t7, $zero, .L80B177EC     
/* 0027C 80B177DC 27397B14 */  addiu   $t9, $t9, %lo(func_80B17B14) ## $t9 = 80B17B14
/* 00280 80B177E0 27187934 */  addiu   $t8, $t8, %lo(func_80B17934) ## $t8 = 80B17934
/* 00284 80B177E4 1000004F */  beq     $zero, $zero, .L80B17924   
/* 00288 80B177E8 ACF8014C */  sw      $t8, 0x014C($a3)           ## 0000014C
.L80B177EC:
/* 0028C 80B177EC 1000004D */  beq     $zero, $zero, .L80B17924   
/* 00290 80B177F0 ACF9014C */  sw      $t9, 0x014C($a3)           ## 0000014C
.L80B177F4:
/* 00294 80B177F4 8FA80024 */  lw      $t0, 0x0024($sp)           
.L80B177F8:
/* 00298 80B177F8 84E9008A */  lh      $t1, 0x008A($a3)           ## 0000008A
/* 0029C 80B177FC 84EA00B6 */  lh      $t2, 0x00B6($a3)           ## 000000B6
/* 002A0 80B17800 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 002A4 80B17804 01014021 */  addu    $t0, $t0, $at              
/* 002A8 80B17808 810B1CBC */  lb      $t3, 0x1CBC($t0)           ## 00001CBC
/* 002AC 80B1780C 012A1823 */  subu    $v1, $t1, $t2              
/* 002B0 80B17810 24060006 */  addiu   $a2, $zero, 0x0006         ## $a2 = 00000006
/* 002B4 80B17814 00031C00 */  sll     $v1, $v1, 16               
/* 002B8 80B17818 14CB0009 */  bne     $a2, $t3, .L80B17840       
/* 002BC 80B1781C 00031C03 */  sra     $v1, $v1, 16               
/* 002C0 80B17820 84EC021A */  lh      $t4, 0x021A($a3)           ## 0000021A
/* 002C4 80B17824 240D006E */  addiu   $t5, $zero, 0x006E         ## $t5 = 0000006E
/* 002C8 80B17828 240E0001 */  addiu   $t6, $zero, 0x0001         ## $t6 = 00000001
/* 002CC 80B1782C 55800005 */  bnel    $t4, $zero, .L80B17844     
/* 002D0 80B17830 84EF021A */  lh      $t7, 0x021A($a3)           ## 0000021A
/* 002D4 80B17834 A4ED010E */  sh      $t5, 0x010E($a3)           ## 0000010E
/* 002D8 80B17838 A4EE021A */  sh      $t6, 0x021A($a3)           ## 0000021A
/* 002DC 80B1783C A4E6020C */  sh      $a2, 0x020C($a3)           ## 0000020C
.L80B17840:
/* 002E0 80B17840 84EF021A */  lh      $t7, 0x021A($a3)           ## 0000021A
.L80B17844:
/* 002E4 80B17844 15E00017 */  bne     $t7, $zero, .L80B178A4     
/* 002E8 80B17848 00000000 */  nop
/* 002EC 80B1784C 84F80214 */  lh      $t8, 0x0214($a3)           ## 00000214
/* 002F0 80B17850 8FA40024 */  lw      $a0, 0x0024($sp)           
/* 002F4 80B17854 24050032 */  addiu   $a1, $zero, 0x0032         ## $a1 = 00000032
/* 002F8 80B17858 13000012 */  beq     $t8, $zero, .L80B178A4     
/* 002FC 80B1785C 00000000 */  nop
/* 00300 80B17860 A7A3001C */  sh      $v1, 0x001C($sp)           
/* 00304 80B17864 AFA70020 */  sw      $a3, 0x0020($sp)           
/* 00308 80B17868 0C00B2D0 */  jal     Flags_GetSwitch
              
/* 0030C 80B1786C AFA80018 */  sw      $t0, 0x0018($sp)           
/* 00310 80B17870 87A3001C */  lh      $v1, 0x001C($sp)           
/* 00314 80B17874 24060006 */  addiu   $a2, $zero, 0x0006         ## $a2 = 00000006
/* 00318 80B17878 8FA70020 */  lw      $a3, 0x0020($sp)           
/* 0031C 80B1787C 10400006 */  beq     $v0, $zero, .L80B17898     
/* 00320 80B17880 8FA80018 */  lw      $t0, 0x0018($sp)           
/* 00324 80B17884 24190084 */  addiu   $t9, $zero, 0x0084         ## $t9 = 00000084
/* 00328 80B17888 24090005 */  addiu   $t1, $zero, 0x0005         ## $t1 = 00000005
/* 0032C 80B1788C A4F9010E */  sh      $t9, 0x010E($a3)           ## 0000010E
/* 00330 80B17890 10000004 */  beq     $zero, $zero, .L80B178A4   
/* 00334 80B17894 A4E9020C */  sh      $t1, 0x020C($a3)           ## 0000020C
.L80B17898:
/* 00338 80B17898 240A704C */  addiu   $t2, $zero, 0x704C         ## $t2 = 0000704C
/* 0033C 80B1789C A4EA010E */  sh      $t2, 0x010E($a3)           ## 0000010E
/* 00340 80B178A0 A4E6020C */  sh      $a2, 0x020C($a3)           ## 0000020C
.L80B178A4:
/* 00344 80B178A4 04600004 */  bltz    $v1, .L80B178B8            
/* 00348 80B178A8 00031023 */  subu    $v0, $zero, $v1            
/* 0034C 80B178AC 00031400 */  sll     $v0, $v1, 16               
/* 00350 80B178B0 10000003 */  beq     $zero, $zero, .L80B178C0   
/* 00354 80B178B4 00021403 */  sra     $v0, $v0, 16               
.L80B178B8:
/* 00358 80B178B8 00021400 */  sll     $v0, $v0, 16               
/* 0035C 80B178BC 00021403 */  sra     $v0, $v0, 16               
.L80B178C0:
/* 00360 80B178C0 28414300 */  slti    $at, $v0, 0x4300           
/* 00364 80B178C4 50200018 */  beql    $at, $zero, .L80B17928     
/* 00368 80B178C8 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 0036C 80B178CC 84EB0216 */  lh      $t3, 0x0216($a3)           ## 00000216
/* 00370 80B178D0 810C1CBC */  lb      $t4, 0x1CBC($t0)           ## 00001CBC
/* 00374 80B178D4 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 00378 80B178D8 3C0642C8 */  lui     $a2, 0x42C8                ## $a2 = 42C80000
/* 0037C 80B178DC 516C0008 */  beql    $t3, $t4, .L80B17900       
/* 00380 80B178E0 84EF0218 */  lh      $t7, 0x0218($a3)           ## 00000218
/* 00384 80B178E4 8CED0004 */  lw      $t5, 0x0004($a3)           ## 00000004
/* 00388 80B178E8 2401FFFE */  addiu   $at, $zero, 0xFFFE         ## $at = FFFFFFFE
/* 0038C 80B178EC A4E00218 */  sh      $zero, 0x0218($a3)         ## 00000218
/* 00390 80B178F0 01A17024 */  and     $t6, $t5, $at              
/* 00394 80B178F4 1000000B */  beq     $zero, $zero, .L80B17924   
/* 00398 80B178F8 ACEE0004 */  sw      $t6, 0x0004($a3)           ## 00000004
/* 0039C 80B178FC 84EF0218 */  lh      $t7, 0x0218($a3)           ## 00000218
.L80B17900:
/* 003A0 80B17900 15E00006 */  bne     $t7, $zero, .L80B1791C     
/* 003A4 80B17904 00000000 */  nop
/* 003A8 80B17908 8CF80004 */  lw      $t8, 0x0004($a3)           ## 00000004
/* 003AC 80B1790C 24090001 */  addiu   $t1, $zero, 0x0001         ## $t1 = 00000001
/* 003B0 80B17910 A4E90218 */  sh      $t1, 0x0218($a3)           ## 00000218
/* 003B4 80B17914 37190001 */  ori     $t9, $t8, 0x0001           ## $t9 = 00000001
/* 003B8 80B17918 ACF90004 */  sw      $t9, 0x0004($a3)           ## 00000004
.L80B1791C:
/* 003BC 80B1791C 0C00BCB3 */  jal     func_8002F2CC              
/* 003C0 80B17920 8FA50024 */  lw      $a1, 0x0024($sp)           
.L80B17924:
/* 003C4 80B17924 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80B17928:
/* 003C8 80B17928 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 003CC 80B1792C 03E00008 */  jr      $ra                        
/* 003D0 80B17930 00000000 */  nop
