.rdata
glabel D_809F5F68
    .asciz "[36m☆☆☆☆☆ 大当り ☆☆☆☆☆ %d\n[m"
    .balign 4

.late_rodata
glabel D_809F6034
 .word 0x44A78000
glabel D_809F6038
 .word 0x44A78000

.text
glabel func_809F36CC
/* 0040C 809F36CC 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 00410 809F36D0 3C0F809F */  lui     $t7, %hi(D_809F5E70)       ## $t7 = 809F0000
/* 00414 809F36D4 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00418 809F36D8 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 0041C 809F36DC AFA5007C */  sw      $a1, 0x007C($sp)           
/* 00420 809F36E0 25EF5E70 */  addiu   $t7, $t7, %lo(D_809F5E70)  ## $t7 = 809F5E70
/* 00424 809F36E4 8DF90000 */  lw      $t9, 0x0000($t7)           ## 809F5E70
/* 00428 809F36E8 3C01809F */  lui     $at, %hi(D_809F6034)       ## $at = 809F0000
/* 0042C 809F36EC C4306034 */  lwc1    $f16, %lo(D_809F6034)($at) 
/* 00430 809F36F0 27AE0048 */  addiu   $t6, $sp, 0x0048           ## $t6 = FFFFFFD0
/* 00434 809F36F4 ADD90000 */  sw      $t9, 0x0000($t6)           ## FFFFFFD0
/* 00438 809F36F8 8DF90008 */  lw      $t9, 0x0008($t7)           ## 809F5E78
/* 0043C 809F36FC 8DF80004 */  lw      $t8, 0x0004($t7)           ## 809F5E74
/* 00440 809F3700 3C09809F */  lui     $t1, %hi(D_809F5E7C)       ## $t1 = 809F0000
/* 00444 809F3704 25295E7C */  addiu   $t1, $t1, %lo(D_809F5E7C)  ## $t1 = 809F5E7C
/* 00448 809F3708 ADD90008 */  sw      $t9, 0x0008($t6)           ## FFFFFFD8
/* 0044C 809F370C ADD80004 */  sw      $t8, 0x0004($t6)           ## FFFFFFD4
/* 00450 809F3710 8D2B0000 */  lw      $t3, 0x0000($t1)           ## 809F5E7C
/* 00454 809F3714 27A8003C */  addiu   $t0, $sp, 0x003C           ## $t0 = FFFFFFC4
/* 00458 809F3718 3C0141C0 */  lui     $at, 0x41C0                ## $at = 41C00000
/* 0045C 809F371C AD0B0000 */  sw      $t3, 0x0000($t0)           ## FFFFFFC4
/* 00460 809F3720 44819000 */  mtc1    $at, $f18                  ## $f18 = 24.00
/* 00464 809F3724 8D2B0008 */  lw      $t3, 0x0008($t1)           ## 809F5E84
/* 00468 809F3728 8D2A0004 */  lw      $t2, 0x0004($t1)           ## 809F5E80
/* 0046C 809F372C 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 00470 809F3730 44812000 */  mtc1    $at, $f4                   ## $f4 = 50.00
/* 00474 809F3734 3C01C1F0 */  lui     $at, 0xC1F0                ## $at = C1F00000
/* 00478 809F3738 AD0B0008 */  sw      $t3, 0x0008($t0)           ## FFFFFFCC
/* 0047C 809F373C AD0A0004 */  sw      $t2, 0x0004($t0)           ## FFFFFFC8
/* 00480 809F3740 44813000 */  mtc1    $at, $f6                   ## $f6 = -30.00
/* 00484 809F3744 44814000 */  mtc1    $at, $f8                   ## $f8 = -30.00
/* 00488 809F3748 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 0048C 809F374C 44815000 */  mtc1    $at, $f10                  ## $f10 = 50.00
/* 00490 809F3750 46122001 */  sub.s   $f0, $f4, $f18             
/* 00494 809F3754 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00498 809F3758 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 0049C 809F375C 46123080 */  add.s   $f2, $f6, $f18             
/* 004A0 809F3760 E48000E0 */  swc1    $f0, 0x00E0($a0)           ## 0000022C
/* 004A4 809F3764 E48000EC */  swc1    $f0, 0x00EC($a0)           ## 00000238
/* 004A8 809F3768 46124301 */  sub.s   $f12, $f8, $f18            
/* 004AC 809F376C E48200E4 */  swc1    $f2, 0x00E4($a0)           ## 00000230
/* 004B0 809F3770 E48200FC */  swc1    $f2, 0x00FC($a0)           ## 00000248
/* 004B4 809F3774 46125380 */  add.s   $f14, $f10, $f18           
/* 004B8 809F3778 E48C00F0 */  swc1    $f12, 0x00F0($a0)          ## 0000023C
/* 004BC 809F377C E48C0108 */  swc1    $f12, 0x0108($a0)          ## 00000254
/* 004C0 809F3780 E49000DC */  swc1    $f16, 0x00DC($a0)          ## 00000228
/* 004C4 809F3784 E48E00F8 */  swc1    $f14, 0x00F8($a0)          ## 00000244
/* 004C8 809F3788 E48E0104 */  swc1    $f14, 0x0104($a0)          ## 00000250
/* 004CC 809F378C E49000E8 */  swc1    $f16, 0x00E8($a0)          ## 00000234
/* 004D0 809F3790 E49000F4 */  swc1    $f16, 0x00F4($a0)          ## 00000240
/* 004D4 809F3794 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 004D8 809F3798 E4900100 */  swc1    $f16, 0x0100($a0)          ## 0000024C
/* 004DC 809F379C 920202A5 */  lbu     $v0, 0x02A5($s0)           ## 000002A5
/* 004E0 809F37A0 3C01809F */  lui     $at, %hi(D_809F6038)       ## $at = 809F0000
/* 004E4 809F37A4 C4306038 */  lwc1    $f16, %lo(D_809F6038)($at) 
/* 004E8 809F37A8 304C0002 */  andi    $t4, $v0, 0x0002           ## $t4 = 00000000
/* 004EC 809F37AC 27A6003C */  addiu   $a2, $sp, 0x003C           ## $a2 = FFFFFFC4
/* 004F0 809F37B0 15800006 */  bne     $t4, $zero, .L809F37CC     
/* 004F4 809F37B4 27A70048 */  addiu   $a3, $sp, 0x0048           ## $a3 = FFFFFFD0
/* 004F8 809F37B8 3C0D8016 */  lui     $t5, 0x8016                ## $t5 = 80160000
/* 004FC 809F37BC 8DADFA90 */  lw      $t5, -0x0570($t5)          ## 8015FA90
/* 00500 809F37C0 85AE12D4 */  lh      $t6, 0x12D4($t5)           ## 801612D4
/* 00504 809F37C4 51C00078 */  beql    $t6, $zero, .L809F39A8     
/* 00508 809F37C8 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L809F37CC:
/* 0050C 809F37CC 861802BA */  lh      $t8, 0x02BA($s0)           ## 000002BA
/* 00510 809F37D0 861902BC */  lh      $t9, 0x02BC($s0)           ## 000002BC
/* 00514 809F37D4 860802BE */  lh      $t0, 0x02BE($s0)           ## 000002BE
/* 00518 809F37D8 44982000 */  mtc1    $t8, $f4                   ## $f4 = 0.00
/* 0051C 809F37DC 44995000 */  mtc1    $t9, $f10                  ## $f10 = 0.00
/* 00520 809F37E0 3C014248 */  lui     $at, 0x4248                ## $at = 42480000
/* 00524 809F37E4 468021A0 */  cvt.s.w $f6, $f4                   
/* 00528 809F37E8 44814000 */  mtc1    $at, $f8                   ## $f8 = 50.00
/* 0052C 809F37EC 3C01C1F0 */  lui     $at, 0xC1F0                ## $at = C1F00000
/* 00530 809F37F0 304FFFFD */  andi    $t7, $v0, 0xFFFD           ## $t7 = 00000000
/* 00534 809F37F4 A20F02A5 */  sb      $t7, 0x02A5($s0)           ## 000002A5
/* 00538 809F37F8 46805120 */  cvt.s.w $f4, $f10                  
/* 0053C 809F37FC 44885000 */  mtc1    $t0, $f10                  ## $f10 = 0.00
/* 00540 809F3800 46068001 */  sub.s   $f0, $f16, $f6             
/* 00544 809F3804 44813000 */  mtc1    $at, $f6                   ## $f6 = -30.00
/* 00548 809F3808 3C0140A0 */  lui     $at, 0x40A0                ## $at = 40A00000
/* 0054C 809F380C 46000085 */  abs.s   $f2, $f0                   
/* 00550 809F3810 46044001 */  sub.s   $f0, $f8, $f4              
/* 00554 809F3814 44812000 */  mtc1    $at, $f4                   ## $f4 = 5.00
/* 00558 809F3818 3C014100 */  lui     $at, 0x4100                ## $at = 41000000
/* 0055C 809F381C 46805220 */  cvt.s.w $f8, $f10                  
/* 00560 809F3820 46021282 */  mul.s   $f10, $f2, $f2             
/* 00564 809F3824 E7A40040 */  swc1    $f4, 0x0040($sp)           
/* 00568 809F3828 44812000 */  mtc1    $at, $f4                   ## $f4 = 8.00
/* 0056C 809F382C 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 00570 809F3830 46000305 */  abs.s   $f12, $f0                  
/* 00574 809F3834 46083001 */  sub.s   $f0, $f6, $f8              
/* 00578 809F3838 460C6182 */  mul.s   $f6, $f12, $f12            
/* 0057C 809F383C 46000385 */  abs.s   $f14, $f0                  
/* 00580 809F3840 460E7202 */  mul.s   $f8, $f14, $f14            
/* 00584 809F3844 46065480 */  add.s   $f18, $f10, $f6            
/* 00588 809F3848 46089000 */  add.s   $f0, $f18, $f8             
/* 0058C 809F384C 46000004 */  sqrt.s  $f0, $f0                   
/* 00590 809F3850 4604003C */  c.lt.s  $f0, $f4                   
/* 00594 809F3854 00000000 */  nop
/* 00598 809F3858 45000039 */  bc1f    .L809F3940                 
/* 0059C 809F385C 00000000 */  nop
/* 005A0 809F3860 44810000 */  mtc1    $at, $f0                   ## $f0 = 20.00
/* 005A4 809F3864 C60A0024 */  lwc1    $f10, 0x0024($s0)          ## 00000024
/* 005A8 809F3868 24090004 */  addiu   $t1, $zero, 0x0004         ## $t1 = 00000004
/* 005AC 809F386C 240A0002 */  addiu   $t2, $zero, 0x0002         ## $t2 = 00000002
/* 005B0 809F3870 46005181 */  sub.s   $f6, $f10, $f0             
/* 005B4 809F3874 8FA4007C */  lw      $a0, 0x007C($sp)           
/* 005B8 809F3878 27A5006C */  addiu   $a1, $sp, 0x006C           ## $a1 = FFFFFFF4
/* 005BC 809F387C E7A6006C */  swc1    $f6, 0x006C($sp)           
/* 005C0 809F3880 C6080028 */  lwc1    $f8, 0x0028($s0)           ## 00000028
/* 005C4 809F3884 46004100 */  add.s   $f4, $f8, $f0              
/* 005C8 809F3888 E7A40070 */  swc1    $f4, 0x0070($sp)           
/* 005CC 809F388C C60A002C */  lwc1    $f10, 0x002C($s0)          ## 0000002C
/* 005D0 809F3890 AFAA0014 */  sw      $t2, 0x0014($sp)           
/* 005D4 809F3894 AFA90010 */  sw      $t1, 0x0010($sp)           
/* 005D8 809F3898 0C00A97D */  jal     func_8002A5F4              
/* 005DC 809F389C E7AA0074 */  swc1    $f10, 0x0074($sp)          
/* 005E0 809F38A0 0C03E341 */  jal     func_800F8D04              
/* 005E4 809F38A4 24044807 */  addiu   $a0, $zero, 0x4807         ## $a0 = 00004807
/* 005E8 809F38A8 0C01E221 */  jal     func_80078884              
/* 005EC 809F38AC 24044807 */  addiu   $a0, $zero, 0x4807         ## $a0 = 00004807
/* 005F0 809F38B0 3C04809F */  lui     $a0, %hi(D_809F5F68)       ## $a0 = 809F0000
/* 005F4 809F38B4 24845F68 */  addiu   $a0, $a0, %lo(D_809F5F68)  ## $a0 = 809F5F68
/* 005F8 809F38B8 0C00084C */  jal     osSyncPrintf
              
/* 005FC 809F38BC 8605026C */  lh      $a1, 0x026C($s0)           ## 0000026C
/* 00600 809F38C0 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 00604 809F38C4 2442E660 */  addiu   $v0, $v0, 0xE660           ## $v0 = 8015E660
/* 00608 809F38C8 8C4B0004 */  lw      $t3, 0x0004($v0)           ## 8015E664
/* 0060C 809F38CC 51600036 */  beql    $t3, $zero, .L809F39A8     
/* 00610 809F38D0 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00614 809F38D4 944C0EF2 */  lhu     $t4, 0x0EF2($v0)           ## 8015F552
/* 00618 809F38D8 318D2000 */  andi    $t5, $t4, 0x2000           ## $t5 = 00000000
/* 0061C 809F38DC 55A00032 */  bnel    $t5, $zero, .L809F39A8     
/* 00620 809F38E0 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00624 809F38E4 860E026C */  lh      $t6, 0x026C($s0)           ## 0000026C
/* 00628 809F38E8 2405102C */  addiu   $a1, $zero, 0x102C         ## $a1 = 0000102C
/* 0062C 809F38EC 2406FF9D */  addiu   $a2, $zero, 0xFF9D         ## $a2 = FFFFFF9D
/* 00630 809F38F0 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 00634 809F38F4 A60F026C */  sh      $t7, 0x026C($s0)           ## 0000026C
/* 00638 809F38F8 8618026C */  lh      $t8, 0x026C($s0)           ## 0000026C
/* 0063C 809F38FC 8FA4007C */  lw      $a0, 0x007C($sp)           
/* 00640 809F3900 02003825 */  or      $a3, $s0, $zero            ## $a3 = 00000000
/* 00644 809F3904 2B010003 */  slti    $at, $t8, 0x0003           
/* 00648 809F3908 54200027 */  bnel    $at, $zero, .L809F39A8     
/* 0064C 809F390C 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00650 809F3910 0C02003E */  jal     func_800800F8              
/* 00654 809F3914 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 00658 809F3918 8FA4007C */  lw      $a0, 0x007C($sp)           
/* 0065C 809F391C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00660 809F3920 0C00B7D5 */  jal     func_8002DF54              
/* 00664 809F3924 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 00668 809F3928 3C08809F */  lui     $t0, %hi(func_809F39B8)    ## $t0 = 809F0000
/* 0066C 809F392C 24190032 */  addiu   $t9, $zero, 0x0032         ## $t9 = 00000032
/* 00670 809F3930 250839B8 */  addiu   $t0, $t0, %lo(func_809F39B8) ## $t0 = 809F39B8
/* 00674 809F3934 A619025C */  sh      $t9, 0x025C($s0)           ## 0000025C
/* 00678 809F3938 1000001A */  beq     $zero, $zero, .L809F39A4   
/* 0067C 809F393C AE080214 */  sw      $t0, 0x0214($s0)           ## 00000214
.L809F3940:
/* 00680 809F3940 460E7182 */  mul.s   $f6, $f14, $f14            
/* 00684 809F3944 3C0141C0 */  lui     $at, 0x41C0                ## $at = 41C00000
/* 00688 809F3948 44814000 */  mtc1    $at, $f8                   ## $f8 = 24.00
/* 0068C 809F394C 46069000 */  add.s   $f0, $f18, $f6             
/* 00690 809F3950 46000004 */  sqrt.s  $f0, $f0                   
/* 00694 809F3954 4608003C */  c.lt.s  $f0, $f8                   
/* 00698 809F3958 00000000 */  nop
/* 0069C 809F395C 45020012 */  bc1fl   .L809F39A8                 
/* 006A0 809F3960 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 006A4 809F3964 C6040024 */  lwc1    $f4, 0x0024($s0)           ## 00000024
/* 006A8 809F3968 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 006AC 809F396C 44810000 */  mtc1    $at, $f0                   ## $f0 = 20.00
/* 006B0 809F3970 E7A4006C */  swc1    $f4, 0x006C($sp)           
/* 006B4 809F3974 C60A0028 */  lwc1    $f10, 0x0028($s0)          ## 00000028
/* 006B8 809F3978 24090004 */  addiu   $t1, $zero, 0x0004         ## $t1 = 00000004
/* 006BC 809F397C 8FA4007C */  lw      $a0, 0x007C($sp)           
/* 006C0 809F3980 46005180 */  add.s   $f6, $f10, $f0             
/* 006C4 809F3984 27A5006C */  addiu   $a1, $sp, 0x006C           ## $a1 = FFFFFFF4
/* 006C8 809F3988 E7A60070 */  swc1    $f6, 0x0070($sp)           
/* 006CC 809F398C C608002C */  lwc1    $f8, 0x002C($s0)           ## 0000002C
/* 006D0 809F3990 AFA00014 */  sw      $zero, 0x0014($sp)         
/* 006D4 809F3994 AFA90010 */  sw      $t1, 0x0010($sp)           
/* 006D8 809F3998 0C00A97D */  jal     func_8002A5F4              
/* 006DC 809F399C E7A80074 */  swc1    $f8, 0x0074($sp)           
/* 006E0 809F39A0 A600026C */  sh      $zero, 0x026C($s0)         ## 0000026C
.L809F39A4:
/* 006E4 809F39A4 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L809F39A8:
/* 006E8 809F39A8 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 006EC 809F39AC 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
/* 006F0 809F39B0 03E00008 */  jr      $ra                        
/* 006F4 809F39B4 00000000 */  nop
