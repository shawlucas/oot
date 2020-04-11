.rdata
glabel D_8088CDA0
    .asciz "../z_bg_hidan_rsekizou.c"
    .balign 4

.late_rodata
glabel D_8088CE10
 .word 0x3E124925
glabel D_8088CE14
 .word 0x3EAAAAAB
glabel D_8088CE18
    .float 0.7
    .balign 4

glabel D_8088CE1C
    .float 0.7
    .balign 4



.text
glabel func_8088C70C
/* 0050C 8088C70C 27BDFFA0 */  addiu   $sp, $sp, 0xFFA0           ## $sp = FFFFFFA0
/* 00510 8088C710 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00514 8088C714 AFB10018 */  sw      $s1, 0x0018($sp)           
/* 00518 8088C718 AFB00014 */  sw      $s0, 0x0014($sp)           
/* 0051C 8088C71C AFA40060 */  sw      $a0, 0x0060($sp)           
/* 00520 8088C720 AFA60068 */  sw      $a2, 0x0068($sp)           
/* 00524 8088C724 84AE0166 */  lh      $t6, 0x0166($a1)           ## 00000166
/* 00528 8088C728 00063400 */  sll     $a2, $a2, 16               
/* 0052C 8088C72C 00063403 */  sra     $a2, $a2, 16               
/* 00530 8088C730 01C67821 */  addu    $t7, $t6, $a2              
/* 00534 8088C734 3C018089 */  lui     $at, %hi(D_8088CE10)       ## $at = 80890000
/* 00538 8088C738 C428CE10 */  lwc1    $f8, %lo(D_8088CE10)($at)  
/* 0053C 8088C73C 8FB00074 */  lw      $s0, 0x0074($sp)           
/* 00540 8088C740 3C0ADB06 */  lui     $t2, 0xDB06                ## $t2 = DB060000
/* 00544 8088C744 354A0024 */  ori     $t2, $t2, 0x0024           ## $t2 = DB060024
/* 00548 8088C748 3C038089 */  lui     $v1, %hi(D_8088CD74)       ## $v1 = 80890000
/* 0054C 8088C74C 02001025 */  or      $v0, $s0, $zero            ## $v0 = 00000000
/* 00550 8088C750 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 00554 8088C754 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 00558 8088C758 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 0055C 8088C75C 24C60001 */  addiu   $a2, $a2, 0x0001           ## $a2 = 00000001
/* 00560 8088C760 00063400 */  sll     $a2, $a2, 16               
/* 00564 8088C764 00063403 */  sra     $a2, $a2, 16               
/* 00568 8088C768 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 0056C 8088C76C 05E10004 */  bgez    $t7, .L8088C780            
/* 00570 8088C770 31F80007 */  andi    $t8, $t7, 0x0007           ## $t8 = 00000000
/* 00574 8088C774 13000002 */  beq     $t8, $zero, .L8088C780     
/* 00578 8088C778 00000000 */  nop
/* 0057C 8088C77C 2718FFF8 */  addiu   $t8, $t8, 0xFFF8           ## $t8 = FFFFFFF8
.L8088C780:
/* 00580 8088C780 0018C8C0 */  sll     $t9, $t8,  3               
/* 00584 8088C784 0338C823 */  subu    $t9, $t9, $t8              
/* 00588 8088C788 44992000 */  mtc1    $t9, $f4                   ## $f4 = 0.00
/* 0058C 8088C78C 3C188016 */  lui     $t8, 0x8016                ## $t8 = 80160000
/* 00590 8088C790 26100008 */  addiu   $s0, $s0, 0x0008           ## $s0 = 00000008
/* 00594 8088C794 468021A0 */  cvt.s.w $f6, $f4                   
/* 00598 8088C798 46083282 */  mul.s   $f10, $f6, $f8             
/* 0059C 8088C79C 4600540D */  trunc.w.s $f16, $f10                 
/* 005A0 8088C7A0 44088000 */  mfc1    $t0, $f16                  
/* 005A4 8088C7A4 00000000 */  nop
/* 005A8 8088C7A8 00085880 */  sll     $t3, $t0,  2               
/* 005AC 8088C7AC 006B1821 */  addu    $v1, $v1, $t3              
/* 005B0 8088C7B0 8C63CD74 */  lw      $v1, %lo(D_8088CD74)($v1)  
/* 005B4 8088C7B4 00036900 */  sll     $t5, $v1,  4               
/* 005B8 8088C7B8 000D7702 */  srl     $t6, $t5, 28               
/* 005BC 8088C7BC 000E7880 */  sll     $t7, $t6,  2               
/* 005C0 8088C7C0 030FC021 */  addu    $t8, $t8, $t7              
/* 005C4 8088C7C4 8F186FA8 */  lw      $t8, 0x6FA8($t8)           ## 80166FA8
/* 005C8 8088C7C8 00616024 */  and     $t4, $v1, $at              
/* 005CC 8088C7CC 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 005D0 8088C7D0 0198C821 */  addu    $t9, $t4, $t8              
/* 005D4 8088C7D4 03214821 */  addu    $t1, $t9, $at              
/* 005D8 8088C7D8 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 005DC 8088C7DC 10C1000D */  beq     $a2, $at, .L8088C814       
/* 005E0 8088C7E0 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 005E4 8088C7E4 862A0164 */  lh      $t2, 0x0164($s1)           ## 00000164
/* 005E8 8088C7E8 240B0003 */  addiu   $t3, $zero, 0x0003         ## $t3 = 00000003
/* 005EC 8088C7EC 3C018089 */  lui     $at, %hi(D_8088CE14)       ## $at = 80890000
/* 005F0 8088C7F0 016A6823 */  subu    $t5, $t3, $t2              
/* 005F4 8088C7F4 448D9000 */  mtc1    $t5, $f18                  ## $f18 = 0.00
/* 005F8 8088C7F8 C426CE14 */  lwc1    $f6, %lo(D_8088CE14)($at)  
/* 005FC 8088C7FC 44865000 */  mtc1    $a2, $f10                  ## $f10 = 0.00
/* 00600 8088C800 46809120 */  cvt.s.w $f4, $f18                  
/* 00604 8088C804 46805420 */  cvt.s.w $f16, $f10                 
/* 00608 8088C808 46062202 */  mul.s   $f8, $f4, $f6              
/* 0060C 8088C80C 10000004 */  beq     $zero, $zero, .L8088C820   
/* 00610 8088C810 46088380 */  add.s   $f14, $f16, $f8            
.L8088C814:
/* 00614 8088C814 44869000 */  mtc1    $a2, $f18                  ## $f18 = 0.00
/* 00618 8088C818 00000000 */  nop
/* 0061C 8088C81C 468093A0 */  cvt.s.w $f14, $f18                 
.L8088C820:
/* 00620 8088C820 02001025 */  or      $v0, $s0, $zero            ## $v0 = 00000008
/* 00624 8088C824 3C0EFA00 */  lui     $t6, 0xFA00                ## $t6 = FA000000
/* 00628 8088C828 3C0FFFFF */  lui     $t7, 0xFFFF                ## $t7 = FFFF0000
/* 0062C 8088C82C 35EF0096 */  ori     $t7, $t7, 0x0096           ## $t7 = FFFF0096
/* 00630 8088C830 35CE0001 */  ori     $t6, $t6, 0x0001           ## $t6 = FA000001
/* 00634 8088C834 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000008
/* 00638 8088C838 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 0000000C
/* 0063C 8088C83C 26100008 */  addiu   $s0, $s0, 0x0008           ## $s0 = 00000010
/* 00640 8088C840 02001025 */  or      $v0, $s0, $zero            ## $v0 = 00000010
/* 00644 8088C844 3C18FF00 */  lui     $t8, 0xFF00                ## $t8 = FF000000
/* 00648 8088C848 371800FF */  ori     $t8, $t8, 0x00FF           ## $t8 = FF0000FF
/* 0064C 8088C84C 3C0CFB00 */  lui     $t4, 0xFB00                ## $t4 = FB000000
/* 00650 8088C850 AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000010
/* 00654 8088C854 AC580004 */  sw      $t8, 0x0004($v0)           ## 00000014
/* 00658 8088C858 8FB90070 */  lw      $t9, 0x0070($sp)           
/* 0065C 8088C85C 00061080 */  sll     $v0, $a2,  2               
/* 00660 8088C860 26100008 */  addiu   $s0, $s0, 0x0008           ## $s0 = 00000018
/* 00664 8088C864 1720001C */  bne     $t9, $zero, .L8088C8D8     
/* 00668 8088C868 00461023 */  subu    $v0, $v0, $a2              
/* 0066C 8088C86C 00061080 */  sll     $v0, $a2,  2               
/* 00670 8088C870 00461023 */  subu    $v0, $v0, $a2              
/* 00674 8088C874 00021100 */  sll     $v0, $v0,  4               
/* 00678 8088C878 00461023 */  subu    $v0, $v0, $a2              
/* 0067C 8088C87C 862900B6 */  lh      $t1, 0x00B6($s1)           ## 000000B6
/* 00680 8088C880 000210C0 */  sll     $v0, $v0,  3               
/* 00684 8088C884 00461023 */  subu    $v0, $v0, $a2              
/* 00688 8088C888 00021080 */  sll     $v0, $v0,  2               
/* 0068C 8088C88C 01222023 */  subu    $a0, $t1, $v0              
/* 00690 8088C890 00042400 */  sll     $a0, $a0, 16               
/* 00694 8088C894 00042403 */  sra     $a0, $a0, 16               
/* 00698 8088C898 AFA20024 */  sw      $v0, 0x0024($sp)           
/* 0069C 8088C89C E7AE0050 */  swc1    $f14, 0x0050($sp)          
/* 006A0 8088C8A0 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 006A4 8088C8A4 AFA7006C */  sw      $a3, 0x006C($sp)           
/* 006A8 8088C8A8 46000107 */  neg.s   $f4, $f0                   
/* 006AC 8088C8AC 8FA20024 */  lw      $v0, 0x0024($sp)           
/* 006B0 8088C8B0 E7A40058 */  swc1    $f4, 0x0058($sp)           
/* 006B4 8088C8B4 862B00B6 */  lh      $t3, 0x00B6($s1)           ## 000000B6
/* 006B8 8088C8B8 01622023 */  subu    $a0, $t3, $v0              
/* 006BC 8088C8BC 00042400 */  sll     $a0, $a0, 16               
/* 006C0 8088C8C0 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 006C4 8088C8C4 00042403 */  sra     $a0, $a0, 16               
/* 006C8 8088C8C8 8FA7006C */  lw      $a3, 0x006C($sp)           
/* 006CC 8088C8CC C7AE0050 */  lwc1    $f14, 0x0050($sp)          
/* 006D0 8088C8D0 10000018 */  beq     $zero, $zero, .L8088C934   
/* 006D4 8088C8D4 46000307 */  neg.s   $f12, $f0                  
.L8088C8D8:
/* 006D8 8088C8D8 00021100 */  sll     $v0, $v0,  4               
/* 006DC 8088C8DC 00461023 */  subu    $v0, $v0, $a2              
/* 006E0 8088C8E0 862A00B6 */  lh      $t2, 0x00B6($s1)           ## 000000B6
/* 006E4 8088C8E4 000210C0 */  sll     $v0, $v0,  3               
/* 006E8 8088C8E8 00461023 */  subu    $v0, $v0, $a2              
/* 006EC 8088C8EC 00021080 */  sll     $v0, $v0,  2               
/* 006F0 8088C8F0 01422023 */  subu    $a0, $t2, $v0              
/* 006F4 8088C8F4 00042400 */  sll     $a0, $a0, 16               
/* 006F8 8088C8F8 00042403 */  sra     $a0, $a0, 16               
/* 006FC 8088C8FC AFA20024 */  sw      $v0, 0x0024($sp)           
/* 00700 8088C900 E7AE0050 */  swc1    $f14, 0x0050($sp)          
/* 00704 8088C904 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 00708 8088C908 AFA7006C */  sw      $a3, 0x006C($sp)           
/* 0070C 8088C90C E7A00058 */  swc1    $f0, 0x0058($sp)           
/* 00710 8088C910 8FA20024 */  lw      $v0, 0x0024($sp)           
/* 00714 8088C914 862D00B6 */  lh      $t5, 0x00B6($s1)           ## 000000B6
/* 00718 8088C918 01A22023 */  subu    $a0, $t5, $v0              
/* 0071C 8088C91C 00042400 */  sll     $a0, $a0, 16               
/* 00720 8088C920 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 00724 8088C924 00042403 */  sra     $a0, $a0, 16               
/* 00728 8088C928 8FA7006C */  lw      $a3, 0x006C($sp)           
/* 0072C 8088C92C C7AE0050 */  lwc1    $f14, 0x0050($sp)          
/* 00730 8088C930 46000306 */  mov.s   $f12, $f0                  
.L8088C934:
/* 00734 8088C934 3C018089 */  lui     $at, %hi(D_8088CE18)       ## $at = 80890000
/* 00738 8088C938 C426CE18 */  lwc1    $f6, %lo(D_8088CE18)($at)  
/* 0073C 8088C93C 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 00740 8088C940 44818000 */  mtc1    $at, $f16                  ## $f16 = 0.50
/* 00744 8088C944 460E3282 */  mul.s   $f10, $f6, $f14            
/* 00748 8088C948 3C014120 */  lui     $at, 0x4120                ## $at = 41200000
/* 0074C 8088C94C 44814000 */  mtc1    $at, $f8                   ## $f8 = 10.00
/* 00750 8088C950 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 00754 8088C954 44813000 */  mtc1    $at, $f6                   ## $f6 = 20.00
/* 00758 8088C958 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 0075C 8088C95C 3C0EDA38 */  lui     $t6, 0xDA38                ## $t6 = DA380000
/* 00760 8088C960 46105000 */  add.s   $f0, $f10, $f16            
/* 00764 8088C964 35CE0003 */  ori     $t6, $t6, 0x0003           ## $t6 = DA380003
/* 00768 8088C968 3C058089 */  lui     $a1, %hi(D_8088CDA0)       ## $a1 = 80890000
/* 0076C 8088C96C 24A5CDA0 */  addiu   $a1, $a1, %lo(D_8088CDA0)  ## $a1 = 8088CDA0
/* 00770 8088C970 46080482 */  mul.s   $f18, $f0, $f8             
/* 00774 8088C974 E4E00028 */  swc1    $f0, 0x0028($a3)           ## 00000028
/* 00778 8088C978 E4E00014 */  swc1    $f0, 0x0014($a3)           ## 00000014
/* 0077C 8088C97C E4E00000 */  swc1    $f0, 0x0000($a3)           ## 00000000
/* 00780 8088C980 C7AA0058 */  lwc1    $f10, 0x0058($sp)          
/* 00784 8088C984 C6280024 */  lwc1    $f8, 0x0024($s1)           ## 00000024
/* 00788 8088C988 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 0078C 8088C98C 460E9102 */  mul.s   $f4, $f18, $f14            
/* 00790 8088C990 2406021F */  addiu   $a2, $zero, 0x021F         ## $a2 = 0000021F
/* 00794 8088C994 46062080 */  add.s   $f2, $f4, $f6              
/* 00798 8088C998 44813000 */  mtc1    $at, $f6                   ## $f6 = 30.00
/* 0079C 8088C99C 3C018089 */  lui     $at, %hi(D_8088CE1C)       ## $at = 80890000
/* 007A0 8088C9A0 460A1402 */  mul.s   $f16, $f2, $f10            
/* 007A4 8088C9A4 46088480 */  add.s   $f18, $f16, $f8            
/* 007A8 8088C9A8 E4F20030 */  swc1    $f18, 0x0030($a3)          ## 00000030
/* 007AC 8088C9AC C430CE1C */  lwc1    $f16, %lo(D_8088CE1C)($at) 
/* 007B0 8088C9B0 C6240028 */  lwc1    $f4, 0x0028($s1)           ## 00000028
/* 007B4 8088C9B4 460E8202 */  mul.s   $f8, $f16, $f14            
/* 007B8 8088C9B8 46062280 */  add.s   $f10, $f4, $f6             
/* 007BC 8088C9BC 460C1102 */  mul.s   $f4, $f2, $f12             
/* 007C0 8088C9C0 46085480 */  add.s   $f18, $f10, $f8            
/* 007C4 8088C9C4 E4F20034 */  swc1    $f18, 0x0034($a3)          ## 00000034
/* 007C8 8088C9C8 C626002C */  lwc1    $f6, 0x002C($s1)           ## 0000002C
/* 007CC 8088C9CC 02008825 */  or      $s1, $s0, $zero            ## $s1 = 00000018
/* 007D0 8088C9D0 26100008 */  addiu   $s0, $s0, 0x0008           ## $s0 = 00000020
/* 007D4 8088C9D4 46062400 */  add.s   $f16, $f4, $f6             
/* 007D8 8088C9D8 E4F00038 */  swc1    $f16, 0x0038($a3)          ## 00000038
/* 007DC 8088C9DC 0C034A17 */  jal     Matrix_CheckFloats              
/* 007E0 8088C9E0 AE2E0000 */  sw      $t6, 0x0000($s1)           ## 00000018
/* 007E4 8088C9E4 8FAF0060 */  lw      $t7, 0x0060($sp)           
/* 007E8 8088C9E8 AFA20028 */  sw      $v0, 0x0028($sp)           
/* 007EC 8088C9EC 24050040 */  addiu   $a1, $zero, 0x0040         ## $a1 = 00000040
/* 007F0 8088C9F0 0C031A73 */  jal     Graph_Alloc
              
/* 007F4 8088C9F4 8DE40000 */  lw      $a0, 0x0000($t7)           ## 00000000
/* 007F8 8088C9F8 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 007FC 8088C9FC 0C034610 */  jal     Matrix_MtxFToMtx              
/* 00800 8088CA00 00402825 */  or      $a1, $v0, $zero            ## $a1 = 00000000
/* 00804 8088CA04 AE220004 */  sw      $v0, 0x0004($s1)           ## 0000001C
/* 00808 8088CA08 02001025 */  or      $v0, $s0, $zero            ## $v0 = 00000020
/* 0080C 8088CA0C 3C180601 */  lui     $t8, 0x0601                ## $t8 = 06010000
/* 00810 8088CA10 2718DC30 */  addiu   $t8, $t8, 0xDC30           ## $t8 = 0600DC30
/* 00814 8088CA14 3C0CDE00 */  lui     $t4, 0xDE00                ## $t4 = DE000000
/* 00818 8088CA18 AC4C0000 */  sw      $t4, 0x0000($v0)           ## 00000020
/* 0081C 8088CA1C AC580004 */  sw      $t8, 0x0004($v0)           ## 00000024
/* 00820 8088CA20 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 00824 8088CA24 26100008 */  addiu   $s0, $s0, 0x0008           ## $s0 = 00000028
/* 00828 8088CA28 02001025 */  or      $v0, $s0, $zero            ## $v0 = 00000028
/* 0082C 8088CA2C 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 00830 8088CA30 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 00834 8088CA34 03E00008 */  jr      $ra                        
/* 00838 8088CA38 27BD0060 */  addiu   $sp, $sp, 0x0060           ## $sp = 00000000


