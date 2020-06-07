glabel func_80A75260
/* 00F50 80A75260 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 00F54 80A75264 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00F58 80A75268 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 00F5C 80A7526C AFA5002C */  sw      $a1, 0x002C($sp)           
/* 00F60 80A75270 848E0300 */  lh      $t6, 0x0300($a0)           ## 00000300
/* 00F64 80A75274 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00F68 80A75278 25CF01C2 */  addiu   $t7, $t6, 0x01C2           ## $t7 = 000001C2
/* 00F6C 80A7527C A48F0300 */  sh      $t7, 0x0300($a0)           ## 00000300
/* 00F70 80A75280 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00F74 80A75284 84840300 */  lh      $a0, 0x0300($a0)           ## 00000300
/* 00F78 80A75288 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 00F7C 80A7528C 3C014130 */  lui     $at, 0x4130                ## $at = 41300000
/* 00F80 80A75290 44814000 */  mtc1    $at, $f8                   ## $f8 = 11.00
/* 00F84 80A75294 4600203E */  c.le.s  $f4, $f0                   
/* 00F88 80A75298 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 00F8C 80A7529C 44815000 */  mtc1    $at, $f10                  ## $f10 = 1.00
/* 00F90 80A752A0 24180003 */  addiu   $t8, $zero, 0x0003         ## $t8 = 00000003
/* 00F94 80A752A4 45000003 */  bc1f    .L80A752B4                 
/* 00F98 80A752A8 3C014110 */  lui     $at, 0x4110                ## $at = 41100000
/* 00F9C 80A752AC 10000003 */  beq     $zero, $zero, .L80A752BC   
/* 00FA0 80A752B0 E6000168 */  swc1    $f0, 0x0168($s0)           ## 00000168
.L80A752B4:
/* 00FA4 80A752B4 46000187 */  neg.s   $f6, $f0                   
/* 00FA8 80A752B8 E6060168 */  swc1    $f6, 0x0168($s0)           ## 00000168
.L80A752BC:
/* 00FAC 80A752BC C6000164 */  lwc1    $f0, 0x0164($s0)           ## 00000164
/* 00FB0 80A752C0 4600403C */  c.lt.s  $f8, $f0                   
/* 00FB4 80A752C4 00000000 */  nop
/* 00FB8 80A752C8 45020004 */  bc1fl   .L80A752DC                 
/* 00FBC 80A752CC 4600503C */  c.lt.s  $f10, $f0                  
/* 00FC0 80A752D0 A21802FF */  sb      $t8, 0x02FF($s0)           ## 000002FF
/* 00FC4 80A752D4 C6000164 */  lwc1    $f0, 0x0164($s0)           ## 00000164
/* 00FC8 80A752D8 4600503C */  c.lt.s  $f10, $f0                  
.L80A752DC:
/* 00FCC 80A752DC 00000000 */  nop
/* 00FD0 80A752E0 45020007 */  bc1fl   .L80A75300                 
/* 00FD4 80A752E4 3C014150 */  lui     $at, 0x4150                ## $at = 41500000
/* 00FD8 80A752E8 44818000 */  mtc1    $at, $f16                  ## $f16 = 13.00
/* 00FDC 80A752EC 00000000 */  nop
/* 00FE0 80A752F0 4610003C */  c.lt.s  $f0, $f16                  
/* 00FE4 80A752F4 00000000 */  nop
/* 00FE8 80A752F8 4501000D */  bc1t    .L80A75330                 
/* 00FEC 80A752FC 3C014150 */  lui     $at, 0x4150                ## $at = 41500000
.L80A75300:
/* 00FF0 80A75300 44819000 */  mtc1    $at, $f18                  ## $f18 = 13.00
/* 00FF4 80A75304 3C014190 */  lui     $at, 0x4190                ## $at = 41900000
/* 00FF8 80A75308 4600903C */  c.lt.s  $f18, $f0                  
/* 00FFC 80A7530C 00000000 */  nop
/* 01000 80A75310 45020024 */  bc1fl   .L80A753A4                 
/* 01004 80A75314 A20002FE */  sb      $zero, 0x02FE($s0)         ## 000002FE
/* 01008 80A75318 44812000 */  mtc1    $at, $f4                   ## $f4 = 18.00
/* 0100C 80A7531C 00000000 */  nop
/* 01010 80A75320 4604003C */  c.lt.s  $f0, $f4                   
/* 01014 80A75324 00000000 */  nop
/* 01018 80A75328 4502001E */  bc1fl   .L80A753A4                 
/* 0101C 80A7532C A20002FE */  sb      $zero, 0x02FE($s0)         ## 000002FE
.L80A75330:
/* 01020 80A75330 921902FC */  lbu     $t9, 0x02FC($s0)           ## 000002FC
/* 01024 80A75334 57200012 */  bnel    $t9, $zero, .L80A75380     
/* 01028 80A75338 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
/* 0102C 80A7533C 920802FB */  lbu     $t0, 0x02FB($s0)           ## 000002FB
/* 01030 80A75340 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 01034 80A75344 5100000E */  beql    $t0, $zero, .L80A75380     
/* 01038 80A75348 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
/* 0103C 80A7534C 44813000 */  mtc1    $at, $f6                   ## $f6 = 10.00
/* 01040 80A75350 26040032 */  addiu   $a0, $s0, 0x0032           ## $a0 = 00000032
/* 01044 80A75354 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 01048 80A75358 4606003C */  c.lt.s  $f0, $f6                   
/* 0104C 80A7535C 240705DC */  addiu   $a3, $zero, 0x05DC         ## $a3 = 000005DC
/* 01050 80A75360 45020007 */  bc1fl   .L80A75380                 
/* 01054 80A75364 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
/* 01058 80A75368 8605008A */  lh      $a1, 0x008A($s0)           ## 0000008A
/* 0105C 80A7536C 0C01E1A7 */  jal     Math_SmoothScaleMaxMinS
              
/* 01060 80A75370 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 01064 80A75374 86090032 */  lh      $t1, 0x0032($s0)           ## 00000032
/* 01068 80A75378 A60900B6 */  sh      $t1, 0x00B6($s0)           ## 000000B6
/* 0106C 80A7537C 820A02FE */  lb      $t2, 0x02FE($s0)           ## 000002FE
.L80A75380:
/* 01070 80A75380 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01074 80A75384 05430004 */  bgezl   $t2, .L80A75398            
/* 01078 80A75388 240B0001 */  addiu   $t3, $zero, 0x0001         ## $t3 = 00000001
/* 0107C 80A7538C 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01080 80A75390 24053929 */  addiu   $a1, $zero, 0x3929         ## $a1 = 00003929
/* 01084 80A75394 240B0001 */  addiu   $t3, $zero, 0x0001         ## $t3 = 00000001
.L80A75398:
/* 01088 80A75398 10000002 */  beq     $zero, $zero, .L80A753A4   
/* 0108C 80A7539C A20B02FE */  sb      $t3, 0x02FE($s0)           ## 000002FE
/* 01090 80A753A0 A20002FE */  sb      $zero, 0x02FE($s0)         ## 000002FE
.L80A753A4:
/* 01094 80A753A4 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 01098 80A753A8 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 0109C 80A753AC 50400004 */  beql    $v0, $zero, .L80A753C0     
/* 010A0 80A753B0 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 010A4 80A753B4 0C29D4F4 */  jal     func_80A753D0              
/* 010A8 80A753B8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 010AC 80A753BC 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80A753C0:
/* 010B0 80A753C0 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 010B4 80A753C4 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 010B8 80A753C8 03E00008 */  jr      $ra                        
/* 010BC 80A753CC 00000000 */  nop
