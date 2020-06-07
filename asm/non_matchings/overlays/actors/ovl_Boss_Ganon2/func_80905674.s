.rdata
glabel D_8090D980
    .asciz "../z_boss_ganon2.c"
    .balign 4

glabel D_8090D994
    .asciz "../z_boss_ganon2.c"
    .balign 4

glabel D_8090D9A8
    .asciz "../z_boss_ganon2.c"
    .balign 4

.late_rodata
glabel D_8090DD50
 .word 0xBF490FDB
glabel D_8090DD54
 .word 0x3D23D70B
glabel D_8090DD58
    .float 1.57079637051

.text
glabel func_80905674
/* 08734 80905674 27BDFF88 */  addiu   $sp, $sp, 0xFF88           ## $sp = FFFFFF88
/* 08738 80905678 AFBF003C */  sw      $ra, 0x003C($sp)           
/* 0873C 8090567C AFB00038 */  sw      $s0, 0x0038($sp)           
/* 08740 80905680 AFA40078 */  sw      $a0, 0x0078($sp)           
/* 08744 80905684 AFA5007C */  sw      $a1, 0x007C($sp)           
/* 08748 80905688 C4860380 */  lwc1    $f6, 0x0380($a0)           ## 00000380
/* 0874C 8090568C 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 08750 80905690 3C068091 */  lui     $a2, %hi(D_8090D980)       ## $a2 = 80910000
/* 08754 80905694 24C6D980 */  addiu   $a2, $a2, %lo(D_8090D980)  ## $a2 = 8090D980
/* 08758 80905698 4606203C */  c.lt.s  $f4, $f6                   
/* 0875C 8090569C 27A40060 */  addiu   $a0, $sp, 0x0060           ## $a0 = FFFFFFE8
/* 08760 809056A0 4502008F */  bc1fl   .L809058E0                 
/* 08764 809056A4 8FBF003C */  lw      $ra, 0x003C($sp)           
/* 08768 809056A8 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 0876C 809056AC 2407168C */  addiu   $a3, $zero, 0x168C         ## $a3 = 0000168C
/* 08770 809056B0 0C031AB1 */  jal     Graph_OpenDisps              
/* 08774 809056B4 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 08778 809056B8 0C034213 */  jal     Matrix_Push              
/* 0877C 809056BC 00000000 */  nop
/* 08780 809056C0 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 08784 809056C4 3C19E700 */  lui     $t9, 0xE700                ## $t9 = E7000000
/* 08788 809056C8 3C0ADB06 */  lui     $t2, 0xDB06                ## $t2 = DB060000
/* 0878C 809056CC 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 08790 809056D0 AE1802D0 */  sw      $t8, 0x02D0($s0)           ## 000002D0
/* 08794 809056D4 AC590000 */  sw      $t9, 0x0000($v0)           ## 00000000
/* 08798 809056D8 AC400004 */  sw      $zero, 0x0004($v0)         ## 00000004
/* 0879C 809056DC 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 087A0 809056E0 354A0020 */  ori     $t2, $t2, 0x0020           ## $t2 = DB060020
/* 087A4 809056E4 24190020 */  addiu   $t9, $zero, 0x0020         ## $t9 = 00000020
/* 087A8 809056E8 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 087AC 809056EC AE0902D0 */  sw      $t1, 0x02D0($s0)           ## 000002D0
/* 087B0 809056F0 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 087B4 809056F4 8FAC0078 */  lw      $t4, 0x0078($sp)           
/* 087B8 809056F8 8FAB007C */  lw      $t3, 0x007C($sp)           
/* 087BC 809056FC 24090020 */  addiu   $t1, $zero, 0x0020         ## $t1 = 00000020
/* 087C0 80905700 8583019C */  lh      $v1, 0x019C($t4)           ## 0000019C
/* 087C4 80905704 8D640000 */  lw      $a0, 0x0000($t3)           ## 00000000
/* 087C8 80905708 240D0020 */  addiu   $t5, $zero, 0x0020         ## $t5 = 00000020
/* 087CC 8090570C 00030823 */  subu    $at, $zero, $v1            
/* 087D0 80905710 000130C0 */  sll     $a2, $at,  3               
/* 087D4 80905714 0001C080 */  sll     $t8, $at,  2               
/* 087D8 80905718 240E0040 */  addiu   $t6, $zero, 0x0040         ## $t6 = 00000040
/* 087DC 8090571C 240F0001 */  addiu   $t7, $zero, 0x0001         ## $t7 = 00000001
/* 087E0 80905720 AFAF0018 */  sw      $t7, 0x0018($sp)           
/* 087E4 80905724 AFAE0014 */  sw      $t6, 0x0014($sp)           
/* 087E8 80905728 AFB8001C */  sw      $t8, 0x001C($sp)           
/* 087EC 8090572C AFA60020 */  sw      $a2, 0x0020($sp)           
/* 087F0 80905730 AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 087F4 80905734 AFA90028 */  sw      $t1, 0x0028($sp)           
/* 087F8 80905738 AFB90024 */  sw      $t9, 0x0024($sp)           
/* 087FC 8090573C 00002825 */  or      $a1, $zero, $zero          ## $a1 = 00000000
/* 08800 80905740 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 08804 80905744 0C0253D0 */  jal     Gfx_TwoTexScroll              
/* 08808 80905748 AFA20058 */  sw      $v0, 0x0058($sp)           
/* 0880C 8090574C 8FA80058 */  lw      $t0, 0x0058($sp)           
/* 08810 80905750 3C0BFA00 */  lui     $t3, 0xFA00                ## $t3 = FA000000
/* 08814 80905754 2401AA00 */  addiu   $at, $zero, 0xAA00         ## $at = FFFFAA00
/* 08818 80905758 AD020004 */  sw      $v0, 0x0004($t0)           ## 00000004
/* 0881C 8090575C 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 08820 80905760 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 08824 80905764 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 08828 80905768 AE0A02D0 */  sw      $t2, 0x02D0($s0)           ## 000002D0
/* 0882C 8090576C AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 08830 80905770 8FAC0078 */  lw      $t4, 0x0078($sp)           
/* 08834 80905774 3C0BFB00 */  lui     $t3, 0xFB00                ## $t3 = FB000000
/* 08838 80905778 C588037C */  lwc1    $f8, 0x037C($t4)           ## 0000037C
/* 0883C 8090577C 3C0CFFC8 */  lui     $t4, 0xFFC8                ## $t4 = FFC80000
/* 08840 80905780 358C0080 */  ori     $t4, $t4, 0x0080           ## $t4 = FFC80080
/* 08844 80905784 4600428D */  trunc.w.s $f10, $f8                  
/* 08848 80905788 44185000 */  mfc1    $t8, $f10                  
/* 0884C 8090578C 00000000 */  nop
/* 08850 80905790 331900FF */  andi    $t9, $t8, 0x00FF           ## $t9 = 00000000
/* 08854 80905794 03214825 */  or      $t1, $t9, $at              ## $t1 = FFFFAA00
/* 08858 80905798 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 0885C 8090579C 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 08860 809057A0 3C0142C8 */  lui     $at, 0x42C8                ## $at = 42C80000
/* 08864 809057A4 44810000 */  mtc1    $at, $f0                   ## $f0 = 100.00
/* 08868 809057A8 244A0008 */  addiu   $t2, $v0, 0x0008           ## $t2 = 00000008
/* 0886C 809057AC AE0A02D0 */  sw      $t2, 0x02D0($s0)           ## 000002D0
/* 08870 809057B0 AC4C0004 */  sw      $t4, 0x0004($v0)           ## 00000004
/* 08874 809057B4 AC4B0000 */  sw      $t3, 0x0000($v0)           ## 00000000
/* 08878 809057B8 3C028091 */  lui     $v0, %hi(D_8090EB2C)       ## $v0 = 80910000
/* 0887C 809057BC 8C42EB2C */  lw      $v0, %lo(D_8090EB2C)($v0)  
/* 08880 809057C0 3C01420C */  lui     $at, 0x420C                ## $at = 420C0000
/* 08884 809057C4 44812000 */  mtc1    $at, $f4                   ## $f4 = 35.00
/* 08888 809057C8 C4500024 */  lwc1    $f16, 0x0024($v0)          ## 80910024
/* 0888C 809057CC C44A002C */  lwc1    $f10, 0x002C($v0)          ## 8091002C
/* 08890 809057D0 C4520028 */  lwc1    $f18, 0x0028($v0)          ## 80910028
/* 08894 809057D4 46008300 */  add.s   $f12, $f16, $f0            
/* 08898 809057D8 3C0140E0 */  lui     $at, 0x40E0                ## $at = 40E00000
/* 0889C 809057DC 44814000 */  mtc1    $at, $f8                   ## $f8 = 7.00
/* 088A0 809057E0 46005401 */  sub.s   $f16, $f10, $f0            
/* 088A4 809057E4 46049180 */  add.s   $f6, $f18, $f4             
/* 088A8 809057E8 44068000 */  mfc1    $a2, $f16                  
/* 088AC 809057EC 0C034261 */  jal     Matrix_Translate              
/* 088B0 809057F0 46083380 */  add.s   $f14, $f6, $f8             
/* 088B4 809057F4 3C018091 */  lui     $at, %hi(D_8090DD50)       ## $at = 80910000
/* 088B8 809057F8 C42CDD50 */  lwc1    $f12, %lo(D_8090DD50)($at) 
/* 088BC 809057FC 0C034348 */  jal     Matrix_RotateY              
/* 088C0 80905800 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 088C4 80905804 3C018091 */  lui     $at, %hi(D_8090DD54)       ## $at = 80910000
/* 088C8 80905808 C42CDD54 */  lwc1    $f12, %lo(D_8090DD54)($at) 
/* 088CC 8090580C 8FAD0078 */  lw      $t5, 0x0078($sp)           
/* 088D0 80905810 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 088D4 80905814 46006386 */  mov.s   $f14, $f12                 
/* 088D8 80905818 0C0342A3 */  jal     Matrix_Scale              
/* 088DC 8090581C 8DA60380 */  lw      $a2, 0x0380($t5)           ## 00000380
/* 088E0 80905820 3C018091 */  lui     $at, %hi(D_8090DD58)       ## $at = 80910000
/* 088E4 80905824 C42CDD58 */  lwc1    $f12, %lo(D_8090DD58)($at) 
/* 088E8 80905828 0C0342DC */  jal     Matrix_RotateX              
/* 088EC 8090582C 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 088F0 80905830 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 088F4 80905834 3C0FDA38 */  lui     $t7, 0xDA38                ## $t7 = DA380000
/* 088F8 80905838 35EF0003 */  ori     $t7, $t7, 0x0003           ## $t7 = DA380003
/* 088FC 8090583C 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 08900 80905840 AE0E02D0 */  sw      $t6, 0x02D0($s0)           ## 000002D0
/* 08904 80905844 AC4F0000 */  sw      $t7, 0x0000($v0)           ## 00000000
/* 08908 80905848 8FB8007C */  lw      $t8, 0x007C($sp)           
/* 0890C 8090584C 3C058091 */  lui     $a1, %hi(D_8090D994)       ## $a1 = 80910000
/* 08910 80905850 24A5D994 */  addiu   $a1, $a1, %lo(D_8090D994)  ## $a1 = 8090D994
/* 08914 80905854 8F040000 */  lw      $a0, 0x0000($t8)           ## 00000000
/* 08918 80905858 240616B6 */  addiu   $a2, $zero, 0x16B6         ## $a2 = 000016B6
/* 0891C 8090585C 0C0346A2 */  jal     Matrix_NewMtx              
/* 08920 80905860 AFA2004C */  sw      $v0, 0x004C($sp)           
/* 08924 80905864 8FA3004C */  lw      $v1, 0x004C($sp)           
/* 08928 80905868 3C048091 */  lui     $a0, %hi(D_8090BB80)       ## $a0 = 80910000
/* 0892C 8090586C 2484BB80 */  addiu   $a0, $a0, %lo(D_8090BB80)  ## $a0 = 8090BB80
/* 08930 80905870 AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 08934 80905874 8E0202D0 */  lw      $v0, 0x02D0($s0)           ## 000002D0
/* 08938 80905878 00045100 */  sll     $t2, $a0,  4               
/* 0893C 8090587C 000A5F02 */  srl     $t3, $t2, 28               
/* 08940 80905880 24590008 */  addiu   $t9, $v0, 0x0008           ## $t9 = 00000008
/* 08944 80905884 AE1902D0 */  sw      $t9, 0x02D0($s0)           ## 000002D0
/* 08948 80905888 000B6080 */  sll     $t4, $t3,  2               
/* 0894C 8090588C 3C09DE00 */  lui     $t1, 0xDE00                ## $t1 = DE000000
/* 08950 80905890 3C0D8016 */  lui     $t5, %hi(gSegments)
/* 08954 80905894 01AC6821 */  addu    $t5, $t5, $t4              
/* 08958 80905898 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 0895C 8090589C AC490000 */  sw      $t1, 0x0000($v0)           ## 00000000
/* 08960 809058A0 8DAD6FA8 */  lw      $t5, %lo(gSegments)($t5)
/* 08964 809058A4 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 08968 809058A8 00817024 */  and     $t6, $a0, $at              
/* 0896C 809058AC 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 08970 809058B0 01AE7821 */  addu    $t7, $t5, $t6              
/* 08974 809058B4 01E1C021 */  addu    $t8, $t7, $at              
/* 08978 809058B8 0C034221 */  jal     Matrix_Pull              
/* 0897C 809058BC AC580004 */  sw      $t8, 0x0004($v0)           ## 00000004
/* 08980 809058C0 8FB9007C */  lw      $t9, 0x007C($sp)           
/* 08984 809058C4 3C068091 */  lui     $a2, %hi(D_8090D9A8)       ## $a2 = 80910000
/* 08988 809058C8 24C6D9A8 */  addiu   $a2, $a2, %lo(D_8090D9A8)  ## $a2 = 8090D9A8
/* 0898C 809058CC 27A40060 */  addiu   $a0, $sp, 0x0060           ## $a0 = FFFFFFE8
/* 08990 809058D0 240716B9 */  addiu   $a3, $zero, 0x16B9         ## $a3 = 000016B9
/* 08994 809058D4 0C031AD5 */  jal     Graph_CloseDisps              
/* 08998 809058D8 8F250000 */  lw      $a1, 0x0000($t9)           ## 00000000
/* 0899C 809058DC 8FBF003C */  lw      $ra, 0x003C($sp)           
.L809058E0:
/* 089A0 809058E0 8FB00038 */  lw      $s0, 0x0038($sp)           
/* 089A4 809058E4 27BD0078 */  addiu   $sp, $sp, 0x0078           ## $sp = 00000000
/* 089A8 809058E8 03E00008 */  jr      $ra                        
/* 089AC 809058EC 00000000 */  nop
