.late_rodata
glabel D_809960DC
    .float 0.1

glabel D_809960E0
    .float 0.2

.text
glabel func_80995518
/* 008C8 80995518 27BDFF68 */  addiu   $sp, $sp, 0xFF68           ## $sp = FFFFFF68
/* 008CC 8099551C AFBF0044 */  sw      $ra, 0x0044($sp)           
/* 008D0 80995520 AFB10040 */  sw      $s1, 0x0040($sp)           
/* 008D4 80995524 AFB0003C */  sw      $s0, 0x003C($sp)           
/* 008D8 80995528 F7BA0030 */  sdc1    $f26, 0x0030($sp)          
/* 008DC 8099552C F7B80028 */  sdc1    $f24, 0x0028($sp)          
/* 008E0 80995530 F7B60020 */  sdc1    $f22, 0x0020($sp)          
/* 008E4 80995534 F7B40018 */  sdc1    $f20, 0x0018($sp)          
/* 008E8 80995538 AFA5009C */  sw      $a1, 0x009C($sp)           
/* 008EC 8099553C 9482021A */  lhu     $v0, 0x021A($a0)           ## 0000021A
/* 008F0 80995540 3C0F8099 */  lui     $t7, %hi(func_80995368)    ## $t7 = 80990000
/* 008F4 80995544 00808825 */  or      $s1, $a0, $zero            ## $s1 = 00000000
/* 008F8 80995548 18400004 */  blez    $v0, .L8099555C            
/* 008FC 8099554C 25EF5368 */  addiu   $t7, $t7, %lo(func_80995368) ## $t7 = 80995368
/* 00900 80995550 244EFFFF */  addiu   $t6, $v0, 0xFFFF           ## $t6 = FFFFFFFF
/* 00904 80995554 10000005 */  beq     $zero, $zero, .L8099556C   
/* 00908 80995558 A48E021A */  sh      $t6, 0x021A($a0)           ## 0000021A
.L8099555C:
/* 0090C 8099555C 24180010 */  addiu   $t8, $zero, 0x0010         ## $t8 = 00000010
/* 00910 80995560 AE2F0280 */  sw      $t7, 0x0280($s1)           ## 00000280
/* 00914 80995564 100000D6 */  beq     $zero, $zero, .L809958C0   
/* 00918 80995568 A638021A */  sh      $t8, 0x021A($s1)           ## 0000021A
.L8099556C:
/* 0091C 8099556C 9622021A */  lhu     $v0, 0x021A($s1)           ## 0000021A
/* 00920 80995570 24040005 */  addiu   $a0, $zero, 0x0005         ## $a0 = 00000005
/* 00924 80995574 00045880 */  sll     $t3, $a0,  2               
/* 00928 80995578 28410004 */  slti    $at, $v0, 0x0004           
/* 0092C 8099557C 14200007 */  bne     $at, $zero, .L8099559C     
/* 00930 80995580 01645823 */  subu    $t3, $t3, $a0              
/* 00934 80995584 0002C823 */  subu    $t9, $zero, $v0            
/* 00938 80995588 00194300 */  sll     $t0, $t9, 12               
/* 0093C 8099558C 34018000 */  ori     $at, $zero, 0x8000         ## $at = 00008000
/* 00940 80995590 01014821 */  addu    $t1, $t0, $at              
/* 00944 80995594 10000004 */  beq     $zero, $zero, .L809955A8   
/* 00948 80995598 A62900B4 */  sh      $t1, 0x00B4($s1)           ## 000000B4
.L8099559C:
/* 0094C 8099559C 240A4000 */  addiu   $t2, $zero, 0x4000         ## $t2 = 00004000
/* 00950 809955A0 A62A00B4 */  sh      $t2, 0x00B4($s1)           ## 000000B4
/* 00954 809955A4 9622021A */  lhu     $v0, 0x021A($s1)           ## 0000021A
.L809955A8:
/* 00958 809955A8 28410006 */  slti    $at, $v0, 0x0006           
/* 0095C 809955AC 1420000C */  bne     $at, $zero, .L809955E0     
/* 00960 809955B0 000B5840 */  sll     $t3, $t3,  1               
/* 00964 809955B4 00021823 */  subu    $v1, $zero, $v0            
/* 00968 809955B8 00030823 */  subu    $at, $zero, $v1            
/* 0096C 809955BC 00011940 */  sll     $v1, $at,  5               
/* 00970 809955C0 00611823 */  subu    $v1, $v1, $at              
/* 00974 809955C4 00031880 */  sll     $v1, $v1,  2               
/* 00978 809955C8 00611821 */  addu    $v1, $v1, $at              
/* 0097C 809955CC 00031880 */  sll     $v1, $v1,  2               
/* 00980 809955D0 2463F060 */  addiu   $v1, $v1, 0xF060           ## $v1 = FFFFF060
/* 00984 809955D4 00031C00 */  sll     $v1, $v1, 16               
/* 00988 809955D8 10000013 */  beq     $zero, $zero, .L80995628   
/* 0098C 809955DC 00031C03 */  sra     $v1, $v1, 16               
.L809955E0:
/* 00990 809955E0 28410004 */  slti    $at, $v0, 0x0004           
/* 00994 809955E4 54200004 */  bnel    $at, $zero, .L809955F8     
/* 00998 809955E8 28410003 */  slti    $at, $v0, 0x0003           
/* 0099C 809955EC 1000000E */  beq     $zero, $zero, .L80995628   
/* 009A0 809955F0 2403FC18 */  addiu   $v1, $zero, 0xFC18         ## $v1 = FFFFFC18
/* 009A4 809955F4 28410003 */  slti    $at, $v0, 0x0003           
.L809955F8:
/* 009A8 809955F8 1420000B */  bne     $at, $zero, .L80995628     
/* 009AC 809955FC 00001825 */  or      $v1, $zero, $zero          ## $v1 = 00000000
/* 009B0 80995600 00020823 */  subu    $at, $zero, $v0            
/* 009B4 80995604 00011940 */  sll     $v1, $at,  5               
/* 009B8 80995608 00611823 */  subu    $v1, $v1, $at              
/* 009BC 8099560C 00031880 */  sll     $v1, $v1,  2               
/* 009C0 80995610 00611821 */  addu    $v1, $v1, $at              
/* 009C4 80995614 00031880 */  sll     $v1, $v1,  2               
/* 009C8 80995618 246303E8 */  addiu   $v1, $v1, 0x03E8           ## $v1 = 000003E8
/* 009CC 8099561C 00031C00 */  sll     $v1, $v1, 16               
/* 009D0 80995620 10000001 */  beq     $zero, $zero, .L80995628   
/* 009D4 80995624 00031C03 */  sra     $v1, $v1, 16               
.L80995628:
/* 009D8 80995628 2622000C */  addiu   $v0, $s1, 0x000C           ## $v0 = 0000000C
/* 009DC 8099562C A4430196 */  sh      $v1, 0x0196($v0)           ## 000001A2
/* 009E0 80995630 A443019C */  sh      $v1, 0x019C($v0)           ## 000001A8
/* 009E4 80995634 A44301A2 */  sh      $v1, 0x01A2($v0)           ## 000001AE
/* 009E8 80995638 022B1021 */  addu    $v0, $s1, $t3              
/* 009EC 8099563C A443019C */  sh      $v1, 0x019C($v0)           ## 000001A8
/* 009F0 80995640 A44301A2 */  sh      $v1, 0x01A2($v0)           ## 000001AE
/* 009F4 80995644 A44301A8 */  sh      $v1, 0x01A8($v0)           ## 000001B4
/* 009F8 80995648 A4430196 */  sh      $v1, 0x0196($v0)           ## 000001A2
/* 009FC 8099564C 962C021A */  lhu     $t4, 0x021A($s1)           ## 0000021A
/* 00A00 80995650 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 00A04 80995654 27AD0084 */  addiu   $t5, $sp, 0x0084           ## $t5 = FFFFFFEC
/* 00A08 80995658 15810058 */  bne     $t4, $at, .L809957BC       
/* 00A0C 8099565C 3C0E8099 */  lui     $t6, %hi(D_80996030)       ## $t6 = 80990000
/* 00A10 80995660 25CE6030 */  addiu   $t6, $t6, %lo(D_80996030)  ## $t6 = 80996030
/* 00A14 80995664 8DD80000 */  lw      $t8, 0x0000($t6)           ## 80996030
/* 00A18 80995668 8DCF0004 */  lw      $t7, 0x0004($t6)           ## 80996034
/* 00A1C 8099566C 3C088099 */  lui     $t0, %hi(D_8099603C)       ## $t0 = 80990000
/* 00A20 80995670 ADB80000 */  sw      $t8, 0x0000($t5)           ## FFFFFFEC
/* 00A24 80995674 8DD80008 */  lw      $t8, 0x0008($t6)           ## 80996038
/* 00A28 80995678 2508603C */  addiu   $t0, $t0, %lo(D_8099603C)  ## $t0 = 8099603C
/* 00A2C 8099567C ADAF0004 */  sw      $t7, 0x0004($t5)           ## FFFFFFF0
/* 00A30 80995680 ADB80008 */  sw      $t8, 0x0008($t5)           ## FFFFFFF4
/* 00A34 80995684 8D0A0000 */  lw      $t2, 0x0000($t0)           ## 8099603C
/* 00A38 80995688 27B90078 */  addiu   $t9, $sp, 0x0078           ## $t9 = FFFFFFE0
/* 00A3C 8099568C 8D090004 */  lw      $t1, 0x0004($t0)           ## 80996040
/* 00A40 80995690 AF2A0000 */  sw      $t2, 0x0000($t9)           ## FFFFFFE0
/* 00A44 80995694 8D0A0008 */  lw      $t2, 0x0008($t0)           ## 80996044
/* 00A48 80995698 3C018099 */  lui     $at, %hi(D_809960DC)       ## $at = 80990000
/* 00A4C 8099569C AF290004 */  sw      $t1, 0x0004($t9)           ## FFFFFFE4
/* 00A50 809956A0 AF2A0008 */  sw      $t2, 0x0008($t9)           ## FFFFFFE8
/* 00A54 809956A4 C43A60DC */  lwc1    $f26, %lo(D_809960DC)($at) 
/* 00A58 809956A8 3C018099 */  lui     $at, %hi(D_809960E0)       ## $at = 80990000
/* 00A5C 809956AC C43860E0 */  lwc1    $f24, %lo(D_809960E0)($at) 
/* 00A60 809956B0 00008025 */  or      $s0, $zero, $zero          ## $s0 = 00000000
/* 00A64 809956B4 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
.L809956B8:
/* 00A68 809956B8 3C014220 */  lui     $at, 0x4220                ## $at = 42200000
/* 00A6C 809956BC 44816000 */  mtc1    $at, $f12                  ## $f12 = 40.00
/* 00A70 809956C0 0C00CFC8 */  jal     Math_Rand_CenteredFloat
              
/* 00A74 809956C4 E7A40070 */  swc1    $f4, 0x0070($sp)           
/* 00A78 809956C8 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 00A7C 809956CC 44816000 */  mtc1    $at, $f12                  ## $f12 = 100.00
/* 00A80 809956D0 0C00CFBE */  jal     Math_Rand_ZeroFloat
              
/* 00A84 809956D4 46000586 */  mov.s   $f22, $f0                  
/* 00A88 809956D8 E7A00074 */  swc1    $f0, 0x0074($sp)           
/* 00A8C 809956DC 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 00A90 809956E0 86240032 */  lh      $a0, 0x0032($s1)           ## 00000032
/* 00A94 809956E4 46000506 */  mov.s   $f20, $f0                  
/* 00A98 809956E8 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00A9C 809956EC 86240032 */  lh      $a0, 0x0032($s1)           ## 00000032
/* 00AA0 809956F0 C7A60074 */  lwc1    $f6, 0x0074($sp)           
/* 00AA4 809956F4 46060202 */  mul.s   $f8, $f0, $f6              
/* 00AA8 809956F8 00000000 */  nop
/* 00AAC 809956FC 4616A282 */  mul.s   $f10, $f20, $f22           
/* 00AB0 80995700 460A4400 */  add.s   $f16, $f8, $f10            
/* 00AB4 80995704 E7B0006C */  swc1    $f16, 0x006C($sp)          
/* 00AB8 80995708 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00ABC 8099570C 86240032 */  lh      $a0, 0x0032($s1)           ## 00000032
/* 00AC0 80995710 46000506 */  mov.s   $f20, $f0                  
/* 00AC4 80995714 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 00AC8 80995718 86240032 */  lh      $a0, 0x0032($s1)           ## 00000032
/* 00ACC 8099571C C7B20074 */  lwc1    $f18, 0x0074($sp)          
/* 00AD0 80995720 4600A187 */  neg.s   $f6, $f20                  
/* 00AD4 80995724 C7B0006C */  lwc1    $f16, 0x006C($sp)          
/* 00AD8 80995728 46120102 */  mul.s   $f4, $f0, $f18             
/* 00ADC 8099572C 240B012C */  addiu   $t3, $zero, 0x012C         ## $t3 = 0000012C
/* 00AE0 80995730 240C001E */  addiu   $t4, $zero, 0x001E         ## $t4 = 0000001E
/* 00AE4 80995734 46163202 */  mul.s   $f8, $f6, $f22             
/* 00AE8 80995738 8FA4009C */  lw      $a0, 0x009C($sp)           
/* 00AEC 8099573C 27A5006C */  addiu   $a1, $sp, 0x006C           ## $a1 = FFFFFFD4
/* 00AF0 80995740 46188482 */  mul.s   $f18, $f16, $f24           
/* 00AF4 80995744 27A60084 */  addiu   $a2, $sp, 0x0084           ## $a2 = FFFFFFEC
/* 00AF8 80995748 27A70078 */  addiu   $a3, $sp, 0x0078           ## $a3 = FFFFFFE0
/* 00AFC 8099574C 46082280 */  add.s   $f10, $f4, $f8             
/* 00B00 80995750 E7B20084 */  swc1    $f18, 0x0084($sp)          
/* 00B04 80995754 46009107 */  neg.s   $f4, $f18                  
/* 00B08 80995758 46185182 */  mul.s   $f6, $f10, $f24            
/* 00B0C 8099575C E7AA0074 */  swc1    $f10, 0x0074($sp)          
/* 00B10 80995760 461A2202 */  mul.s   $f8, $f4, $f26             
/* 00B14 80995764 46003487 */  neg.s   $f18, $f6                  
/* 00B18 80995768 E7A6008C */  swc1    $f6, 0x008C($sp)           
/* 00B1C 8099576C 461A9102 */  mul.s   $f4, $f18, $f26            
/* 00B20 80995770 E7A80078 */  swc1    $f8, 0x0078($sp)           
/* 00B24 80995774 C7B20070 */  lwc1    $f18, 0x0070($sp)          
/* 00B28 80995778 E7A40080 */  swc1    $f4, 0x0080($sp)           
/* 00B2C 8099577C C6280024 */  lwc1    $f8, 0x0024($s1)           ## 00000024
/* 00B30 80995780 46088180 */  add.s   $f6, $f16, $f8             
/* 00B34 80995784 E7A6006C */  swc1    $f6, 0x006C($sp)           
/* 00B38 80995788 C6240028 */  lwc1    $f4, 0x0028($s1)           ## 00000028
/* 00B3C 8099578C 46049400 */  add.s   $f16, $f18, $f4            
/* 00B40 80995790 E7B00070 */  swc1    $f16, 0x0070($sp)          
/* 00B44 80995794 C628002C */  lwc1    $f8, 0x002C($s1)           ## 0000002C
/* 00B48 80995798 AFAC0014 */  sw      $t4, 0x0014($sp)           
/* 00B4C 8099579C AFAB0010 */  sw      $t3, 0x0010($sp)           
/* 00B50 809957A0 46085180 */  add.s   $f6, $f10, $f8             
/* 00B54 809957A4 0C00A197 */  jal     func_8002865C              
/* 00B58 809957A8 E7A60074 */  swc1    $f6, 0x0074($sp)           
/* 00B5C 809957AC 26100001 */  addiu   $s0, $s0, 0x0001           ## $s0 = 00000001
/* 00B60 809957B0 24010014 */  addiu   $at, $zero, 0x0014         ## $at = 00000014
/* 00B64 809957B4 5601FFC0 */  bnel    $s0, $at, .L809956B8       
/* 00B68 809957B8 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
.L809957BC:
/* 00B6C 809957BC 962D0218 */  lhu     $t5, 0x0218($s1)           ## 00000218
/* 00B70 809957C0 8FAF009C */  lw      $t7, 0x009C($sp)           
/* 00B74 809957C4 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00B78 809957C8 31AE0001 */  andi    $t6, $t5, 0x0001           ## $t6 = 00000000
/* 00B7C 809957CC 55C00031 */  bnel    $t6, $zero, .L80995894     
/* 00B80 809957D0 96220218 */  lhu     $v0, 0x0218($s1)           ## 00000218
/* 00B84 809957D4 8DF01C44 */  lw      $s0, 0x1C44($t7)           ## 00001C44
/* 00B88 809957D8 27A50058 */  addiu   $a1, $sp, 0x0058           ## $a1 = FFFFFFC0
/* 00B8C 809957DC 0C00B6F4 */  jal     ActorSearch_PosProjectDistanceXZ              
/* 00B90 809957E0 26060024 */  addiu   $a2, $s0, 0x0024           ## $a2 = 00000025
/* 00B94 809957E4 C7A0005C */  lwc1    $f0, 0x005C($sp)           
/* 00B98 809957E8 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 00B9C 809957EC 44811000 */  mtc1    $at, $f2                   ## $f2 = 20.00
/* 00BA0 809957F0 46000005 */  abs.s   $f0, $f0                   
/* 00BA4 809957F4 4602003C */  c.lt.s  $f0, $f2                   
/* 00BA8 809957F8 C7A00058 */  lwc1    $f0, 0x0058($sp)           
/* 00BAC 809957FC 45020025 */  bc1fl   .L80995894                 
/* 00BB0 80995800 96220218 */  lhu     $v0, 0x0218($s1)           ## 00000218
/* 00BB4 80995804 46000005 */  abs.s   $f0, $f0                   
/* 00BB8 80995808 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 00BBC 8099580C 4602003C */  c.lt.s  $f0, $f2                   
/* 00BC0 80995810 C7A00060 */  lwc1    $f0, 0x0060($sp)           
/* 00BC4 80995814 4502001F */  bc1fl   .L80995894                 
/* 00BC8 80995818 96220218 */  lhu     $v0, 0x0218($s1)           ## 00000218
/* 00BCC 8099581C 44819000 */  mtc1    $at, $f18                  ## $f18 = 100.00
/* 00BD0 80995820 00000000 */  nop
/* 00BD4 80995824 4612003C */  c.lt.s  $f0, $f18                  
/* 00BD8 80995828 00000000 */  nop
/* 00BDC 8099582C 45020019 */  bc1fl   .L80995894                 
/* 00BE0 80995830 96220218 */  lhu     $v0, 0x0218($s1)           ## 00000218
/* 00BE4 80995834 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 00BE8 80995838 3C0140C0 */  lui     $at, 0x40C0                ## $at = 40C00000
/* 00BEC 8099583C 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 00BF0 80995840 4600203C */  c.lt.s  $f4, $f0                   
/* 00BF4 80995844 24080010 */  addiu   $t0, $zero, 0x0010         ## $t0 = 00000010
/* 00BF8 80995848 45020012 */  bc1fl   .L80995894                 
/* 00BFC 8099584C 96220218 */  lhu     $v0, 0x0218($s1)           ## 00000218
/* 00C00 80995850 96380218 */  lhu     $t8, 0x0218($s1)           ## 00000218
/* 00C04 80995854 44810000 */  mtc1    $at, $f0                   ## $f0 = 6.00
/* 00C08 80995858 8627008A */  lh      $a3, 0x008A($s1)           ## 0000008A
/* 00C0C 8099585C 37190001 */  ori     $t9, $t8, 0x0001           ## $t9 = 00000001
/* 00C10 80995860 A6390218 */  sh      $t9, 0x0218($s1)           ## 00000218
/* 00C14 80995864 44060000 */  mfc1    $a2, $f0                   
/* 00C18 80995868 AFA80014 */  sw      $t0, 0x0014($sp)           
/* 00C1C 8099586C 8FA4009C */  lw      $a0, 0x009C($sp)           
/* 00C20 80995870 0C00BDB5 */  jal     func_8002F6D4              
/* 00C24 80995874 E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 00C28 80995878 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00C2C 8099587C 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 00C30 80995880 240539DC */  addiu   $a1, $zero, 0x39DC         ## $a1 = 000039DC
/* 00C34 80995884 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000001
/* 00C38 80995888 0C00BDF7 */  jal     func_8002F7DC              
/* 00C3C 8099588C 2405083E */  addiu   $a1, $zero, 0x083E         ## $a1 = 0000083E
/* 00C40 80995890 96220218 */  lhu     $v0, 0x0218($s1)           ## 00000218
.L80995894:
/* 00C44 80995894 30490001 */  andi    $t1, $v0, 0x0001           ## $t1 = 00000000
/* 00C48 80995898 5520000A */  bnel    $t1, $zero, .L809958C4     
/* 00C4C 8099589C 8FBF0044 */  lw      $ra, 0x0044($sp)           
/* 00C50 809958A0 962A021A */  lhu     $t2, 0x021A($s1)           ## 0000021A
/* 00C54 809958A4 24010002 */  addiu   $at, $zero, 0x0002         ## $at = 00000002
/* 00C58 809958A8 344B0001 */  ori     $t3, $v0, 0x0001           ## $t3 = 00000001
/* 00C5C 809958AC 15410004 */  bne     $t2, $at, .L809958C0       
/* 00C60 809958B0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 00C64 809958B4 A62B0218 */  sh      $t3, 0x0218($s1)           ## 00000218
/* 00C68 809958B8 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 00C6C 809958BC 240539DE */  addiu   $a1, $zero, 0x39DE         ## $a1 = 000039DE
.L809958C0:
/* 00C70 809958C0 8FBF0044 */  lw      $ra, 0x0044($sp)           
.L809958C4:
/* 00C74 809958C4 D7B40018 */  ldc1    $f20, 0x0018($sp)          
/* 00C78 809958C8 D7B60020 */  ldc1    $f22, 0x0020($sp)          
/* 00C7C 809958CC D7B80028 */  ldc1    $f24, 0x0028($sp)          
/* 00C80 809958D0 D7BA0030 */  ldc1    $f26, 0x0030($sp)          
/* 00C84 809958D4 8FB0003C */  lw      $s0, 0x003C($sp)           
/* 00C88 809958D8 8FB10040 */  lw      $s1, 0x0040($sp)           
/* 00C8C 809958DC 03E00008 */  jr      $ra                        
/* 00C90 809958E0 27BD0098 */  addiu   $sp, $sp, 0x0098           ## $sp = 00000000
