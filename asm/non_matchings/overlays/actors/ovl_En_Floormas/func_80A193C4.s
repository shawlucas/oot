.late_rodata
glabel D_80A1A59C
    .float 0.1
    .balign 4

.text
glabel func_80A193C4
/* 01EB4 80A193C4 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 01EB8 80A193C8 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 01EBC 80A193CC AFA5003C */  sw      $a1, 0x003C($sp)           
/* 01EC0 80A193D0 8CA71C44 */  lw      $a3, 0x1C44($a1)           ## 00001C44
/* 01EC4 80A193D4 00803025 */  or      $a2, $a0, $zero            ## $a2 = 00000000
/* 01EC8 80A193D8 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 01ECC 80A193DC 2484014C */  addiu   $a0, $a0, 0x014C           ## $a0 = 0000014C
/* 01ED0 80A193E0 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 01ED4 80A193E4 AFA70034 */  sw      $a3, 0x0034($sp)           
/* 01ED8 80A193E8 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 01EDC 80A193EC 1040001A */  beq     $v0, $zero, .L80A19458     
/* 01EE0 80A193F0 8FA70034 */  lw      $a3, 0x0034($sp)           
/* 01EE4 80A193F4 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 01EE8 80A193F8 C4C60168 */  lwc1    $f6, 0x0168($a2)           ## 00000168
/* 01EEC 80A193FC 3C014234 */  lui     $at, 0x4234                ## $at = 42340000
/* 01EF0 80A19400 4606203C */  c.lt.s  $f4, $f6                   
/* 01EF4 80A19404 00000000 */  nop
/* 01EF8 80A19408 4502000C */  bc1fl   .L80A1943C                 
/* 01EFC 80A1940C 44816000 */  mtc1    $at, $f12                  ## $f12 = 45.00
/* 01F00 80A19410 3C014234 */  lui     $at, 0x4234                ## $at = 42340000
/* 01F04 80A19414 44816000 */  mtc1    $at, $f12                  ## $f12 = 45.00
/* 01F08 80A19418 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 01F0C 80A1941C 44814000 */  mtc1    $at, $f8                   ## $f8 = -1.00
/* 01F10 80A19420 3C014210 */  lui     $at, 0x4210                ## $at = 42100000
/* 01F14 80A19424 44815000 */  mtc1    $at, $f10                  ## $f10 = 36.00
/* 01F18 80A19428 E4CC0158 */  swc1    $f12, 0x0158($a2)          ## 00000158
/* 01F1C 80A1942C E4C80168 */  swc1    $f8, 0x0168($a2)           ## 00000168
/* 01F20 80A19430 10000009 */  beq     $zero, $zero, .L80A19458   
/* 01F24 80A19434 E4CA015C */  swc1    $f10, 0x015C($a2)          ## 0000015C
/* 01F28 80A19438 44816000 */  mtc1    $at, $f12                  ## $f12 = 36.00
.L80A1943C:
/* 01F2C 80A1943C 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 01F30 80A19440 44818000 */  mtc1    $at, $f16                  ## $f16 = 1.00
/* 01F34 80A19444 3C014210 */  lui     $at, 0x4210                ## $at = 42100000
/* 01F38 80A19448 44819000 */  mtc1    $at, $f18                  ## $f18 = 36.00
/* 01F3C 80A1944C E4CC015C */  swc1    $f12, 0x015C($a2)          ## 0000015C
/* 01F40 80A19450 E4D00168 */  swc1    $f16, 0x0168($a2)          ## 00000168
/* 01F44 80A19454 E4D20158 */  swc1    $f18, 0x0158($a2)          ## 00000158
.L80A19458:
/* 01F48 80A19458 3C0F8016 */  lui     $t7, 0x8016                ## $t7 = 80160000
/* 01F4C 80A1945C 8DEFE664 */  lw      $t7, -0x199C($t7)          ## 8015E664
/* 01F50 80A19460 3C014234 */  lui     $at, 0x4234                ## $at = 42340000
/* 01F54 80A19464 44816000 */  mtc1    $at, $f12                  ## $f12 = 45.00
/* 01F58 80A19468 51E0001D */  beql    $t7, $zero, .L80A194E0     
/* 01F5C 80A1946C C4C00094 */  lwc1    $f0, 0x0094($a2)           ## 00000094
/* 01F60 80A19470 C4C00094 */  lwc1    $f0, 0x0094($a2)           ## 00000094
/* 01F64 80A19474 3C0141A0 */  lui     $at, 0x41A0                ## $at = 41A00000
/* 01F68 80A19478 44811000 */  mtc1    $at, $f2                   ## $f2 = 20.00
/* 01F6C 80A1947C 46000007 */  neg.s   $f0, $f0                   
/* 01F70 80A19480 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 01F74 80A19484 4602003C */  c.lt.s  $f0, $f2                   
/* 01F78 80A19488 00000000 */  nop
/* 01F7C 80A1948C 45020007 */  bc1fl   .L80A194AC                 
/* 01F80 80A19490 44816000 */  mtc1    $at, $f12                  ## $f12 = 30.00
/* 01F84 80A19494 46001006 */  mov.s   $f0, $f2                   
/* 01F88 80A19498 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01F8C 80A1949C 44811000 */  mtc1    $at, $f2                   ## $f2 = -10.00
/* 01F90 80A194A0 10000024 */  beq     $zero, $zero, .L80A19534   
/* 01F94 80A194A4 C4E40028 */  lwc1    $f4, 0x0028($a3)           ## 00000028
/* 01F98 80A194A8 44816000 */  mtc1    $at, $f12                  ## $f12 = -10.00
.L80A194AC:
/* 01F9C 80A194AC 3C01C120 */  lui     $at, 0xC120                ## $at = C1200000
/* 01FA0 80A194B0 4600603C */  c.lt.s  $f12, $f0                  
/* 01FA4 80A194B4 00000000 */  nop
/* 01FA8 80A194B8 45020004 */  bc1fl   .L80A194CC                 
/* 01FAC 80A194BC 46000086 */  mov.s   $f2, $f0                   
/* 01FB0 80A194C0 10000002 */  beq     $zero, $zero, .L80A194CC   
/* 01FB4 80A194C4 46006086 */  mov.s   $f2, $f12                  
/* 01FB8 80A194C8 46000086 */  mov.s   $f2, $f0                   
.L80A194CC:
/* 01FBC 80A194CC 46001006 */  mov.s   $f0, $f2                   
/* 01FC0 80A194D0 44811000 */  mtc1    $at, $f2                   ## $f2 = -10.00
/* 01FC4 80A194D4 10000017 */  beq     $zero, $zero, .L80A19534   
/* 01FC8 80A194D8 C4E40028 */  lwc1    $f4, 0x0028($a3)           ## 00000028
/* 01FCC 80A194DC C4C00094 */  lwc1    $f0, 0x0094($a2)           ## 00000094
.L80A194E0:
/* 01FD0 80A194E0 3C0141C8 */  lui     $at, 0x41C8                ## $at = 41C80000
/* 01FD4 80A194E4 44811000 */  mtc1    $at, $f2                   ## $f2 = 25.00
/* 01FD8 80A194E8 46000007 */  neg.s   $f0, $f0                   
/* 01FDC 80A194EC 3C01C1F0 */  lui     $at, 0xC1F0                ## $at = C1F00000
/* 01FE0 80A194F0 4602003C */  c.lt.s  $f0, $f2                   
/* 01FE4 80A194F4 00000000 */  nop
/* 01FE8 80A194F8 45020004 */  bc1fl   .L80A1950C                 
/* 01FEC 80A194FC 4600603C */  c.lt.s  $f12, $f0                  
/* 01FF0 80A19500 10000009 */  beq     $zero, $zero, .L80A19528   
/* 01FF4 80A19504 46001006 */  mov.s   $f0, $f2                   
/* 01FF8 80A19508 4600603C */  c.lt.s  $f12, $f0                  
.L80A1950C:
/* 01FFC 80A1950C 00000000 */  nop
/* 02000 80A19510 45020004 */  bc1fl   .L80A19524                 
/* 02004 80A19514 46000086 */  mov.s   $f2, $f0                   
/* 02008 80A19518 10000002 */  beq     $zero, $zero, .L80A19524   
/* 0200C 80A1951C 46006086 */  mov.s   $f2, $f12                  
/* 02010 80A19520 46000086 */  mov.s   $f2, $f0                   
.L80A19524:
/* 02014 80A19524 46001006 */  mov.s   $f0, $f2                   
.L80A19528:
/* 02018 80A19528 44811000 */  mtc1    $at, $f2                   ## $f2 = -30.00
/* 0201C 80A1952C 00000000 */  nop
/* 02020 80A19530 C4E40028 */  lwc1    $f4, 0x0028($a3)           ## 00000028
.L80A19534:
/* 02024 80A19534 84C400B6 */  lh      $a0, 0x00B6($a2)           ## 000000B6
/* 02028 80A19538 46002180 */  add.s   $f6, $f4, $f0              
/* 0202C 80A1953C E4C60028 */  swc1    $f6, 0x0028($a2)           ## 00000028
/* 02030 80A19540 E7A20024 */  swc1    $f2, 0x0024($sp)           
/* 02034 80A19544 AFA70034 */  sw      $a3, 0x0034($sp)           
/* 02038 80A19548 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 0203C 80A1954C AFA60038 */  sw      $a2, 0x0038($sp)           
/* 02040 80A19550 3C0180A2 */  lui     $at, %hi(D_80A1A59C)       ## $at = 80A20000
/* 02044 80A19554 C428A59C */  lwc1    $f8, %lo(D_80A1A59C)($at)  
/* 02048 80A19558 C7A20024 */  lwc1    $f2, 0x0024($sp)           
/* 0204C 80A1955C 8FA70034 */  lw      $a3, 0x0034($sp)           
/* 02050 80A19560 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 02054 80A19564 46081302 */  mul.s   $f12, $f2, $f8             
/* 02058 80A19568 C4F00024 */  lwc1    $f16, 0x0024($a3)          ## 00000024
/* 0205C 80A1956C 84C400B6 */  lh      $a0, 0x00B6($a2)           ## 000000B6
/* 02060 80A19570 460C0282 */  mul.s   $f10, $f0, $f12            
/* 02064 80A19574 46105480 */  add.s   $f18, $f10, $f16           
/* 02068 80A19578 E4D20024 */  swc1    $f18, 0x0024($a2)          ## 00000024
/* 0206C 80A1957C 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 02070 80A19580 E7AC001C */  swc1    $f12, 0x001C($sp)          
/* 02074 80A19584 C7AC001C */  lwc1    $f12, 0x001C($sp)          
/* 02078 80A19588 8FA70034 */  lw      $a3, 0x0034($sp)           
/* 0207C 80A1958C 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 02080 80A19590 460C0102 */  mul.s   $f4, $f0, $f12             
/* 02084 80A19594 C4E6002C */  lwc1    $f6, 0x002C($a3)           ## 0000002C
/* 02088 80A19598 3C0140C0 */  lui     $at, 0x40C0                ## $at = 40C00000
/* 0208C 80A1959C 46062200 */  add.s   $f8, $f4, $f6              
/* 02090 80A195A0 E4C8002C */  swc1    $f8, 0x002C($a2)           ## 0000002C
/* 02094 80A195A4 8CF80680 */  lw      $t8, 0x0680($a3)           ## 00000680
/* 02098 80A195A8 33190080 */  andi    $t9, $t8, 0x0080           ## $t9 = 00000000
/* 0209C 80A195AC 53200005 */  beql    $t9, $zero, .L80A195C4     
/* 020A0 80A195B0 8CC40118 */  lw      $a0, 0x0118($a2)           ## 00000118
/* 020A4 80A195B4 80E80A78 */  lb      $t0, 0x0A78($a3)           ## 00000A78
/* 020A8 80A195B8 05030024 */  bgezl   $t0, .L80A1964C            
/* 020AC 80A195BC 84CE0196 */  lh      $t6, 0x0196($a2)           ## 00000196
/* 020B0 80A195C0 8CC40118 */  lw      $a0, 0x0118($a2)           ## 00000118
.L80A195C4:
/* 020B4 80A195C4 3C0280A2 */  lui     $v0, %hi(func_80A193C4)    ## $v0 = 80A20000
/* 020B8 80A195C8 244293C4 */  addiu   $v0, $v0, %lo(func_80A193C4) ## $v0 = 80A193C4
/* 020BC 80A195CC 8C830190 */  lw      $v1, 0x0190($a0)           ## 00000190
/* 020C0 80A195D0 44815000 */  mtc1    $at, $f10                  ## $f10 = 6.00
/* 020C4 80A195D4 8CC5011C */  lw      $a1, 0x011C($a2)           ## 0000011C
/* 020C8 80A195D8 10430005 */  beq     $v0, $v1, .L80A195F0       
/* 020CC 80A195DC 3C01C040 */  lui     $at, 0xC040                ## $at = C0400000
/* 020D0 80A195E0 3C0980A2 */  lui     $t1, %hi(func_80A19B9C)    ## $t1 = 80A20000
/* 020D4 80A195E4 25299B9C */  addiu   $t1, $t1, %lo(func_80A19B9C) ## $t1 = 80A19B9C
/* 020D8 80A195E8 5523000C */  bnel    $t1, $v1, .L80A1961C       
/* 020DC 80A195EC 8CCC0004 */  lw      $t4, 0x0004($a2)           ## 00000004
.L80A195F0:
/* 020E0 80A195F0 8CA30190 */  lw      $v1, 0x0190($a1)           ## 00000190
/* 020E4 80A195F4 3C0A80A2 */  lui     $t2, %hi(func_80A19B9C)    ## $t2 = 80A20000
/* 020E8 80A195F8 254A9B9C */  addiu   $t2, $t2, %lo(func_80A19B9C) ## $t2 = 80A19B9C
/* 020EC 80A195FC 10430002 */  beq     $v0, $v1, .L80A19608       
/* 020F0 80A19600 240B0040 */  addiu   $t3, $zero, 0x0040         ## $t3 = 00000040
/* 020F4 80A19604 15430004 */  bne     $t2, $v1, .L80A19618       
.L80A19608:
/* 020F8 80A19608 24020020 */  addiu   $v0, $zero, 0x0020         ## $v0 = 00000020
/* 020FC 80A1960C A482001C */  sh      $v0, 0x001C($a0)           ## 0000001C
/* 02100 80A19610 A4A2001C */  sh      $v0, 0x001C($a1)           ## 0000001C
/* 02104 80A19614 A4CB001C */  sh      $t3, 0x001C($a2)           ## 0000001C
.L80A19618:
/* 02108 80A19618 8CCC0004 */  lw      $t4, 0x0004($a2)           ## 00000004
.L80A1961C:
/* 0210C 80A1961C 44818000 */  mtc1    $at, $f16                  ## $f16 = -3.00
/* 02110 80A19620 A4C000B4 */  sh      $zero, 0x00B4($a2)         ## 000000B4
/* 02114 80A19624 358D0001 */  ori     $t5, $t4, 0x0001           ## $t5 = 00000001
/* 02118 80A19628 E4CA0060 */  swc1    $f10, 0x0060($a2)          ## 00000060
/* 0211C 80A1962C ACCD0004 */  sw      $t5, 0x0004($a2)           ## 00000004
/* 02120 80A19630 E4D00068 */  swc1    $f16, 0x0068($a2)          ## 00000068
/* 02124 80A19634 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 02128 80A19638 0C285ED0 */  jal     func_80A17B40              
/* 0212C 80A1963C 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 02130 80A19640 1000001F */  beq     $zero, $zero, .L80A196C0   
/* 02134 80A19644 8FA60038 */  lw      $a2, 0x0038($sp)           
/* 02138 80A19648 84CE0196 */  lh      $t6, 0x0196($a2)           ## 00000196
.L80A1964C:
/* 0213C 80A1964C 24010014 */  addiu   $at, $zero, 0x0014         ## $at = 00000014
/* 02140 80A19650 3C188016 */  lui     $t8, 0x8016                ## $t8 = 80160000
/* 02144 80A19654 01C1001A */  div     $zero, $t6, $at            
/* 02148 80A19658 00007810 */  mfhi    $t7                        
/* 0214C 80A1965C 55E00019 */  bnel    $t7, $zero, .L80A196C4     
/* 02150 80A19660 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 02154 80A19664 8F18E664 */  lw      $t8, -0x199C($t8)          ## 8015E664
/* 02158 80A19668 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 0215C 80A1966C 24056805 */  addiu   $a1, $zero, 0x6805         ## $a1 = 00006805
/* 02160 80A19670 13000007 */  beq     $t8, $zero, .L80A19690     
/* 02164 80A19674 00000000 */  nop
/* 02168 80A19678 00E02025 */  or      $a0, $a3, $zero            ## $a0 = 00000000
/* 0216C 80A1967C 24056825 */  addiu   $a1, $zero, 0x6825         ## $a1 = 00006825
/* 02170 80A19680 0C00BDF7 */  jal     func_8002F7DC              
/* 02174 80A19684 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 02178 80A19688 10000004 */  beq     $zero, $zero, .L80A1969C   
/* 0217C 80A1968C 8FA60038 */  lw      $a2, 0x0038($sp)           
.L80A19690:
/* 02180 80A19690 0C00BDF7 */  jal     func_8002F7DC              
/* 02184 80A19694 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 02188 80A19698 8FA60038 */  lw      $a2, 0x0038($sp)           
.L80A1969C:
/* 0218C 80A1969C 8FA4003C */  lw      $a0, 0x003C($sp)           
/* 02190 80A196A0 3C190001 */  lui     $t9, 0x0001                ## $t9 = 00010000
/* 02194 80A196A4 AFA60038 */  sw      $a2, 0x0038($sp)           
/* 02198 80A196A8 0324C821 */  addu    $t9, $t9, $a0              
/* 0219C 80A196AC 8F391D58 */  lw      $t9, 0x1D58($t9)           ## 00011D58
/* 021A0 80A196B0 2405FFF8 */  addiu   $a1, $zero, 0xFFF8         ## $a1 = FFFFFFF8
/* 021A4 80A196B4 0320F809 */  jalr    $ra, $t9                   
/* 021A8 80A196B8 00000000 */  nop
/* 021AC 80A196BC 8FA60038 */  lw      $a2, 0x0038($sp)           
.L80A196C0:
/* 021B0 80A196C0 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
.L80A196C4:
/* 021B4 80A196C4 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 021B8 80A196C8 24053136 */  addiu   $a1, $zero, 0x3136         ## $a1 = 00003136
/* 021BC 80A196CC 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 021C0 80A196D0 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 021C4 80A196D4 03E00008 */  jr      $ra                        
/* 021C8 80A196D8 00000000 */  nop


