.rdata
glabel D_80A72810
    .asciz "../z_en_hy.c"
    .balign 4

glabel D_80A72820
    .asciz "../z_en_hy.c"
    .balign 4

.late_rodata
glabel D_80A72A90
    .float 3.14159274101

glabel D_80A72A94
    .float 3.14159274101

glabel D_80A72A98
    .float 3.14159274101

glabel D_80A72A9C
    .float 3.14159274101

.text
glabel func_80A716B8
/* 02108 80A716B8 27BDFFA8 */  addiu   $sp, $sp, 0xFFA8           ## $sp = FFFFFFA8
/* 0210C 80A716BC AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02110 80A716C0 AFA40058 */  sw      $a0, 0x0058($sp)           
/* 02114 80A716C4 AFA5005C */  sw      $a1, 0x005C($sp)           
/* 02118 80A716C8 AFA60060 */  sw      $a2, 0x0060($sp)           
/* 0211C 80A716CC AFA70064 */  sw      $a3, 0x0064($sp)           
/* 02120 80A716D0 8C850000 */  lw      $a1, 0x0000($a0)           ## 00000000
/* 02124 80A716D4 3C0680A7 */  lui     $a2, %hi(D_80A72810)       ## $a2 = 80A70000
/* 02128 80A716D8 24C62810 */  addiu   $a2, $a2, %lo(D_80A72810)  ## $a2 = 80A72810
/* 0212C 80A716DC 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFD4
/* 02130 80A716E0 2407087A */  addiu   $a3, $zero, 0x087A         ## $a3 = 0000087A
/* 02134 80A716E4 0C031AB1 */  jal     Graph_OpenDisps              
/* 02138 80A716E8 AFA5003C */  sw      $a1, 0x003C($sp)           
/* 0213C 80A716EC 8FA9005C */  lw      $t1, 0x005C($sp)           
/* 02140 80A716F0 240C000F */  addiu   $t4, $zero, 0x000F         ## $t4 = 0000000F
/* 02144 80A716F4 8FA8003C */  lw      $t0, 0x003C($sp)           
/* 02148 80A716F8 152C0051 */  bne     $t1, $t4, .L80A71840       
/* 0214C 80A716FC 8FAA006C */  lw      $t2, 0x006C($sp)           
/* 02150 80A71700 8D0302C0 */  lw      $v1, 0x02C0($t0)           ## 000002C0
/* 02154 80A71704 3C18DB06 */  lui     $t8, 0xDB06                ## $t8 = DB060000
/* 02158 80A71708 37180018 */  ori     $t8, $t8, 0x0018           ## $t8 = DB060018
/* 0215C 80A7170C 246F0008 */  addiu   $t7, $v1, 0x0008           ## $t7 = 00000008
/* 02160 80A71710 AD0F02C0 */  sw      $t7, 0x02C0($t0)           ## 000002C0
/* 02164 80A71714 AC780000 */  sw      $t8, 0x0000($v1)           ## 00000000
/* 02168 80A71718 814D0196 */  lb      $t5, 0x0196($t2)           ## 00000196
/* 0216C 80A7171C 24060044 */  addiu   $a2, $zero, 0x0044         ## $a2 = 00000044
/* 02170 80A71720 8FB90058 */  lw      $t9, 0x0058($sp)           
/* 02174 80A71724 01A60019 */  multu   $t5, $a2                   
/* 02178 80A71728 3C070001 */  lui     $a3, 0x0001                ## $a3 = 00010000
/* 0217C 80A7172C 3C0B8000 */  lui     $t3, 0x8000                ## $t3 = 80000000
/* 02180 80A71730 3C018016 */  lui     $at, 0x8016                ## $at = 80160000
/* 02184 80A71734 00007012 */  mflo    $t6                        
/* 02188 80A71738 032E7821 */  addu    $t7, $t9, $t6              
/* 0218C 80A7173C 01E7C021 */  addu    $t8, $t7, $a3              
/* 02190 80A71740 8F0D17B4 */  lw      $t5, 0x17B4($t8)           ## DB0617CC
/* 02194 80A71744 AC6D0004 */  sw      $t5, 0x0004($v1)           ## 00000004
/* 02198 80A71748 814E0196 */  lb      $t6, 0x0196($t2)           ## 00000196
/* 0219C 80A7174C 8FB90058 */  lw      $t9, 0x0058($sp)           
/* 021A0 80A71750 3C0380A7 */  lui     $v1, %hi(D_80A722D8)       ## $v1 = 80A70000
/* 021A4 80A71754 01C60019 */  multu   $t6, $a2                   
/* 021A8 80A71758 00007812 */  mflo    $t7                        
/* 021AC 80A7175C 032FC021 */  addu    $t8, $t9, $t7              
/* 021B0 80A71760 03076821 */  addu    $t5, $t8, $a3              
/* 021B4 80A71764 8DAE17B4 */  lw      $t6, 0x17B4($t5)           ## 000017B4
/* 021B8 80A71768 01CBC821 */  addu    $t9, $t6, $t3              
/* 021BC 80A7176C AC396FC0 */  sw      $t9, 0x6FC0($at)           ## 80166FC0
/* 021C0 80A71770 854F001C */  lh      $t7, 0x001C($t2)           ## 0000001C
/* 021C4 80A71774 3C1980A7 */  lui     $t9, %hi(D_80A71F50)       ## $t9 = 80A70000
/* 021C8 80A71778 27391F50 */  addiu   $t9, $t9, %lo(D_80A71F50)  ## $t9 = 80A71F50
/* 021CC 80A7177C 31F8007F */  andi    $t8, $t7, 0x007F           ## $t8 = 00000008
/* 021D0 80A71780 00186880 */  sll     $t5, $t8,  2               
/* 021D4 80A71784 01B86823 */  subu    $t5, $t5, $t8              
/* 021D8 80A71788 000D6880 */  sll     $t5, $t5,  2               
/* 021DC 80A7178C 006D1821 */  addu    $v1, $v1, $t5              
/* 021E0 80A71790 906322D8 */  lbu     $v1, %lo(D_80A722D8)($v1)  
/* 021E4 80A71794 8FB80060 */  lw      $t8, 0x0060($sp)           
/* 021E8 80A71798 3C0100FF */  lui     $at, 0x00FF                ## $at = 00FF0000
/* 021EC 80A7179C 00037080 */  sll     $t6, $v1,  2               
/* 021F0 80A717A0 01C37023 */  subu    $t6, $t6, $v1              
/* 021F4 80A717A4 000E7080 */  sll     $t6, $t6,  2               
/* 021F8 80A717A8 01D91021 */  addu    $v0, $t6, $t9              
/* 021FC 80A717AC 8C4F0004 */  lw      $t7, 0x0004($v0)           ## 00000004
/* 02200 80A717B0 AF0F0000 */  sw      $t7, 0x0000($t8)           ## 00000008
/* 02204 80A717B4 8C440008 */  lw      $a0, 0x0008($v0)           ## 00000008
/* 02208 80A717B8 3C18DB06 */  lui     $t8, 0xDB06                ## $t8 = DB060000
/* 0220C 80A717BC 37180028 */  ori     $t8, $t8, 0x0028           ## $t8 = DB060028
/* 02210 80A717C0 50800016 */  beql    $a0, $zero, .L80A7181C     
/* 02214 80A717C4 814F0198 */  lb      $t7, 0x0198($t2)           ## 00000198
/* 02218 80A717C8 854D0218 */  lh      $t5, 0x0218($t2)           ## 00000218
/* 0221C 80A717CC 8D0302C0 */  lw      $v1, 0x02C0($t0)           ## 000002C0
/* 02220 80A717D0 3421FFFF */  ori     $at, $at, 0xFFFF           ## $at = 00FFFFFF
/* 02224 80A717D4 000D7080 */  sll     $t6, $t5,  2               
/* 02228 80A717D8 008EC821 */  addu    $t9, $a0, $t6              
/* 0222C 80A717DC 8F250000 */  lw      $a1, 0x0000($t9)           ## 80A71F50
/* 02230 80A717E0 246F0008 */  addiu   $t7, $v1, 0x0008           ## $t7 = 80A70008
/* 02234 80A717E4 AD0F02C0 */  sw      $t7, 0x02C0($t0)           ## 000002C0
/* 02238 80A717E8 00056900 */  sll     $t5, $a1,  4               
/* 0223C 80A717EC 000D7702 */  srl     $t6, $t5, 28               
/* 02240 80A717F0 000EC880 */  sll     $t9, $t6,  2               
/* 02244 80A717F4 3C0F8016 */  lui     $t7, 0x8016                ## $t7 = 80160000
/* 02248 80A717F8 01F97821 */  addu    $t7, $t7, $t9              
/* 0224C 80A717FC AC780000 */  sw      $t8, 0x0000($v1)           ## 80A70000
/* 02250 80A71800 8DEF6FA8 */  lw      $t7, 0x6FA8($t7)           ## 80166FA8
/* 02254 80A71804 00A1C024 */  and     $t8, $a1, $at              
/* 02258 80A71808 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 0225C 80A7180C 01F86821 */  addu    $t5, $t7, $t8              
/* 02260 80A71810 01A17021 */  addu    $t6, $t5, $at              
/* 02264 80A71814 AC6E0004 */  sw      $t6, 0x0004($v1)           ## 80A70004
/* 02268 80A71818 814F0198 */  lb      $t7, 0x0198($t2)           ## 00000198
.L80A7181C:
/* 0226C 80A7181C 8FB90058 */  lw      $t9, 0x0058($sp)           
/* 02270 80A71820 3C018016 */  lui     $at, 0x8016                ## $at = 80160000
/* 02274 80A71824 01E60019 */  multu   $t7, $a2                   
/* 02278 80A71828 0000C012 */  mflo    $t8                        
/* 0227C 80A7182C 03386821 */  addu    $t5, $t9, $t8              
/* 02280 80A71830 01A77021 */  addu    $t6, $t5, $a3              
/* 02284 80A71834 8DCF17B4 */  lw      $t7, 0x17B4($t6)           ## 000017B4
/* 02288 80A71838 01EBC821 */  addu    $t9, $t7, $t3              
/* 0228C 80A7183C AC396FC0 */  sw      $t9, 0x6FC0($at)           ## 80166FC0
.L80A71840:
/* 02290 80A71840 152C002F */  bne     $t1, $t4, .L80A71900       
/* 02294 80A71844 8FAA006C */  lw      $t2, 0x006C($sp)           
/* 02298 80A71848 44807000 */  mtc1    $zero, $f14                ## $f14 = 0.00
/* 0229C 80A7184C 3C0144AF */  lui     $at, 0x44AF                ## $at = 44AF0000
/* 022A0 80A71850 44816000 */  mtc1    $at, $f12                  ## $f12 = 1400.00
/* 022A4 80A71854 44067000 */  mfc1    $a2, $f14                  
/* 022A8 80A71858 0C034261 */  jal     Matrix_Translate              
/* 022AC 80A7185C 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 022B0 80A71860 8FAD006C */  lw      $t5, 0x006C($sp)           
/* 022B4 80A71864 27B80048 */  addiu   $t8, $sp, 0x0048           ## $t8 = FFFFFFF0
/* 022B8 80A71868 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 022BC 80A7186C 89AF01F0 */  lwl     $t7, 0x01F0($t5)           ## 000001F0
/* 022C0 80A71870 99AF01F3 */  lwr     $t7, 0x01F3($t5)           ## 000001F3
/* 022C4 80A71874 44814000 */  mtc1    $at, $f8                   ## $f8 = 32768.00
/* 022C8 80A71878 3C0180A7 */  lui     $at, %hi(D_80A72A90)       ## $at = 80A70000
/* 022CC 80A7187C AF0F0000 */  sw      $t7, 0x0000($t8)           ## FFFFFFF0
/* 022D0 80A71880 95AF01F4 */  lhu     $t7, 0x01F4($t5)           ## 000001F4
/* 022D4 80A71884 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 022D8 80A71888 A70F0004 */  sh      $t7, 0x0004($t8)           ## FFFFFFF4
/* 022DC 80A7188C 87B9004A */  lh      $t9, 0x004A($sp)           
/* 022E0 80A71890 C4302A90 */  lwc1    $f16, %lo(D_80A72A90)($at) 
/* 022E4 80A71894 44992000 */  mtc1    $t9, $f4                   ## $f4 = 0.00
/* 022E8 80A71898 00000000 */  nop
/* 022EC 80A7189C 468021A0 */  cvt.s.w $f6, $f4                   
/* 022F0 80A718A0 46083283 */  div.s   $f10, $f6, $f8             
/* 022F4 80A718A4 46105302 */  mul.s   $f12, $f10, $f16           
/* 022F8 80A718A8 0C0342DC */  jal     Matrix_RotateX              
/* 022FC 80A718AC 00000000 */  nop
/* 02300 80A718B0 87B80048 */  lh      $t8, 0x0048($sp)           
/* 02304 80A718B4 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 02308 80A718B8 44813000 */  mtc1    $at, $f6                   ## $f6 = 32768.00
/* 0230C 80A718BC 44989000 */  mtc1    $t8, $f18                  ## $f18 = 0.00
/* 02310 80A718C0 3C0180A7 */  lui     $at, %hi(D_80A72A94)       ## $at = 80A70000
/* 02314 80A718C4 C42A2A94 */  lwc1    $f10, %lo(D_80A72A94)($at) 
/* 02318 80A718C8 46809120 */  cvt.s.w $f4, $f18                  
/* 0231C 80A718CC 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02320 80A718D0 46062203 */  div.s   $f8, $f4, $f6              
/* 02324 80A718D4 460A4302 */  mul.s   $f12, $f8, $f10            
/* 02328 80A718D8 0C0343B5 */  jal     Matrix_RotateZ              
/* 0232C 80A718DC 00000000 */  nop
/* 02330 80A718E0 44807000 */  mtc1    $zero, $f14                ## $f14 = 0.00
/* 02334 80A718E4 3C01C4AF */  lui     $at, 0xC4AF                ## $at = C4AF0000
/* 02338 80A718E8 44816000 */  mtc1    $at, $f12                  ## $f12 = -1400.00
/* 0233C 80A718EC 44067000 */  mfc1    $a2, $f14                  
/* 02340 80A718F0 0C034261 */  jal     Matrix_Translate              
/* 02344 80A718F4 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 02348 80A718F8 8FAA006C */  lw      $t2, 0x006C($sp)           
/* 0234C 80A718FC 8FA9005C */  lw      $t1, 0x005C($sp)           
.L80A71900:
/* 02350 80A71900 24010008 */  addiu   $at, $zero, 0x0008         ## $at = 00000008
/* 02354 80A71904 55210024 */  bnel    $t1, $at, .L80A71998       
/* 02358 80A71908 24010008 */  addiu   $at, $zero, 0x0008         ## $at = 00000008
/* 0235C 80A7190C 894F01F6 */  lwl     $t7, 0x01F6($t2)           ## 000001F6
/* 02360 80A71910 994F01F9 */  lwr     $t7, 0x01F9($t2)           ## 000001F9
/* 02364 80A71914 27AD0048 */  addiu   $t5, $sp, 0x0048           ## $t5 = FFFFFFF0
/* 02368 80A71918 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 0236C 80A7191C ADAF0000 */  sw      $t7, 0x0000($t5)           ## FFFFFFF0
/* 02370 80A71920 954F01FA */  lhu     $t7, 0x01FA($t2)           ## 000001FA
/* 02374 80A71924 44812000 */  mtc1    $at, $f4                   ## $f4 = 32768.00
/* 02378 80A71928 3C0180A7 */  lui     $at, %hi(D_80A72A98)       ## $at = 80A70000
/* 0237C 80A7192C A5AF0004 */  sh      $t7, 0x0004($t5)           ## FFFFFFF4
/* 02380 80A71930 87B9004A */  lh      $t9, 0x004A($sp)           
/* 02384 80A71934 C4282A98 */  lwc1    $f8, %lo(D_80A72A98)($at)  
/* 02388 80A71938 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 0238C 80A7193C 0019C023 */  subu    $t8, $zero, $t9            
/* 02390 80A71940 44988000 */  mtc1    $t8, $f16                  ## $f16 = 0.00
/* 02394 80A71944 00000000 */  nop
/* 02398 80A71948 468084A0 */  cvt.s.w $f18, $f16                 
/* 0239C 80A7194C 46049183 */  div.s   $f6, $f18, $f4             
/* 023A0 80A71950 46083302 */  mul.s   $f12, $f6, $f8             
/* 023A4 80A71954 0C0342DC */  jal     Matrix_RotateX              
/* 023A8 80A71958 00000000 */  nop
/* 023AC 80A7195C 87AD0048 */  lh      $t5, 0x0048($sp)           
/* 023B0 80A71960 3C014700 */  lui     $at, 0x4700                ## $at = 47000000
/* 023B4 80A71964 44819000 */  mtc1    $at, $f18                  ## $f18 = 32768.00
/* 023B8 80A71968 448D5000 */  mtc1    $t5, $f10                  ## $f10 = 0.00
/* 023BC 80A7196C 3C0180A7 */  lui     $at, %hi(D_80A72A9C)       ## $at = 80A70000
/* 023C0 80A71970 C4262A9C */  lwc1    $f6, %lo(D_80A72A9C)($at)  
/* 023C4 80A71974 46805420 */  cvt.s.w $f16, $f10                 
/* 023C8 80A71978 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 023CC 80A7197C 46128103 */  div.s   $f4, $f16, $f18            
/* 023D0 80A71980 46062302 */  mul.s   $f12, $f4, $f6             
/* 023D4 80A71984 0C0343B5 */  jal     Matrix_RotateZ              
/* 023D8 80A71988 00000000 */  nop
/* 023DC 80A7198C 8FAA006C */  lw      $t2, 0x006C($sp)           
/* 023E0 80A71990 8FA9005C */  lw      $t1, 0x005C($sp)           
/* 023E4 80A71994 24010008 */  addiu   $at, $zero, 0x0008         ## $at = 00000008
.L80A71998:
/* 023E8 80A71998 11210005 */  beq     $t1, $at, .L80A719B0       
/* 023EC 80A7199C 00097040 */  sll     $t6, $t1,  1               
/* 023F0 80A719A0 24010009 */  addiu   $at, $zero, 0x0009         ## $at = 00000009
/* 023F4 80A719A4 11210002 */  beq     $t1, $at, .L80A719B0       
/* 023F8 80A719A8 2401000C */  addiu   $at, $zero, 0x000C         ## $at = 0000000C
/* 023FC 80A719AC 15210021 */  bne     $t1, $at, .L80A71A34       
.L80A719B0:
/* 02400 80A719B0 014E1821 */  addu    $v1, $t2, $t6              
/* 02404 80A719B4 8464021C */  lh      $a0, 0x021C($v1)           ## 0000021C
/* 02408 80A719B8 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0240C 80A719BC AFA3001C */  sw      $v1, 0x001C($sp)           
/* 02410 80A719C0 8FA20068 */  lw      $v0, 0x0068($sp)           
/* 02414 80A719C4 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 02418 80A719C8 44818000 */  mtc1    $at, $f16                  ## $f16 = 200.00
/* 0241C 80A719CC 844F0002 */  lh      $t7, 0x0002($v0)           ## 00000002
/* 02420 80A719D0 8FA3001C */  lw      $v1, 0x001C($sp)           
/* 02424 80A719D4 46100482 */  mul.s   $f18, $f0, $f16            
/* 02428 80A719D8 448F4000 */  mtc1    $t7, $f8                   ## $f8 = 0.00
/* 0242C 80A719DC 00000000 */  nop
/* 02430 80A719E0 468042A0 */  cvt.s.w $f10, $f8                  
/* 02434 80A719E4 46125100 */  add.s   $f4, $f10, $f18            
/* 02438 80A719E8 4600218D */  trunc.w.s $f6, $f4                   
/* 0243C 80A719EC 44183000 */  mfc1    $t8, $f6                   
/* 02440 80A719F0 00000000 */  nop
/* 02444 80A719F4 A4580002 */  sh      $t8, 0x0002($v0)           ## 00000002
/* 02448 80A719F8 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 0244C 80A719FC 8464023C */  lh      $a0, 0x023C($v1)           ## 0000023C
/* 02450 80A71A00 8FA20068 */  lw      $v0, 0x0068($sp)           
/* 02454 80A71A04 3C014348 */  lui     $at, 0x4348                ## $at = 43480000
/* 02458 80A71A08 44815000 */  mtc1    $at, $f10                  ## $f10 = 200.00
/* 0245C 80A71A0C 844D0004 */  lh      $t5, 0x0004($v0)           ## 00000004
/* 02460 80A71A10 460A0482 */  mul.s   $f18, $f0, $f10            
/* 02464 80A71A14 448D4000 */  mtc1    $t5, $f8                   ## $f8 = 0.00
/* 02468 80A71A18 00000000 */  nop
/* 0246C 80A71A1C 46804420 */  cvt.s.w $f16, $f8                  
/* 02470 80A71A20 46128100 */  add.s   $f4, $f16, $f18            
/* 02474 80A71A24 4600218D */  trunc.w.s $f6, $f4                   
/* 02478 80A71A28 440F3000 */  mfc1    $t7, $f6                   
/* 0247C 80A71A2C 00000000 */  nop
/* 02480 80A71A30 A44F0004 */  sh      $t7, 0x0004($v0)           ## 00000004
.L80A71A34:
/* 02484 80A71A34 8FB90058 */  lw      $t9, 0x0058($sp)           
/* 02488 80A71A38 3C0680A7 */  lui     $a2, %hi(D_80A72820)       ## $a2 = 80A70000
/* 0248C 80A71A3C 24C62820 */  addiu   $a2, $a2, %lo(D_80A72820)  ## $a2 = 80A72820
/* 02490 80A71A40 27A4002C */  addiu   $a0, $sp, 0x002C           ## $a0 = FFFFFFD4
/* 02494 80A71A44 240708B4 */  addiu   $a3, $zero, 0x08B4         ## $a3 = 000008B4
/* 02498 80A71A48 0C031AD5 */  jal     Graph_CloseDisps              
/* 0249C 80A71A4C 8F250000 */  lw      $a1, 0x0000($t9)           ## 00000000
/* 024A0 80A71A50 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 024A4 80A71A54 27BD0058 */  addiu   $sp, $sp, 0x0058           ## $sp = 00000000
/* 024A8 80A71A58 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 024AC 80A71A5C 03E00008 */  jr      $ra                        
/* 024B0 80A71A60 00000000 */  nop
