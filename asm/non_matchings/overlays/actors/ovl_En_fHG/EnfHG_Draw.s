.rdata
glabel D_80B65378
    .asciz "../z_en_fhg.c"
    .balign 4

glabel D_80B65388
    .asciz "../z_en_fhg.c"
    .balign 4

.text
glabel EnfHG_Draw
/* 024E4 80B64EA4 27BDFFA0 */  addiu   $sp, $sp, 0xFFA0           ## $sp = FFFFFFA0
/* 024E8 80B64EA8 AFBF0034 */  sw      $ra, 0x0034($sp)           
/* 024EC 80B64EAC AFB20030 */  sw      $s2, 0x0030($sp)           
/* 024F0 80B64EB0 AFB1002C */  sw      $s1, 0x002C($sp)           
/* 024F4 80B64EB4 AFB00028 */  sw      $s0, 0x0028($sp)           
/* 024F8 80B64EB8 8C8E0118 */  lw      $t6, 0x0118($a0)           ## 00000118
/* 024FC 80B64EBC 00A09025 */  or      $s2, $a1, $zero            ## $s2 = 00000000
/* 02500 80B64EC0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 02504 80B64EC4 AFAE0058 */  sw      $t6, 0x0058($sp)           
/* 02508 80B64EC8 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 0250C 80B64ECC 3C0680B6 */  lui     $a2, %hi(D_80B65378)       ## $a2 = 80B60000
/* 02510 80B64ED0 24C65378 */  addiu   $a2, $a2, %lo(D_80B65378)  ## $a2 = 80B65378
/* 02514 80B64ED4 27A40040 */  addiu   $a0, $sp, 0x0040           ## $a0 = FFFFFFE0
/* 02518 80B64ED8 24070987 */  addiu   $a3, $zero, 0x0987         ## $a3 = 00000987
/* 0251C 80B64EDC 0C031AB1 */  jal     Graph_OpenDisps              
/* 02520 80B64EE0 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 02524 80B64EE4 0C024F46 */  jal     func_80093D18              
/* 02528 80B64EE8 8E440000 */  lw      $a0, 0x0000($s2)           ## 00000000
/* 0252C 80B64EEC 8FA20058 */  lw      $v0, 0x0058($sp)           
/* 02530 80B64EF0 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 02534 80B64EF4 844F01A0 */  lh      $t7, 0x01A0($v0)           ## 000001A0
/* 02538 80B64EF8 31F80004 */  andi    $t8, $t7, 0x0004           ## $t8 = 00000000
/* 0253C 80B64EFC 53000010 */  beql    $t8, $zero, .L80B64F40     
/* 02540 80B64F00 444AF800 */  cfc1    $t2, $31
/* 02544 80B64F04 905901C9 */  lbu     $t9, 0x01C9($v0)           ## 000001C9
/* 02548 80B64F08 24060032 */  addiu   $a2, $zero, 0x0032         ## $a2 = 00000032
/* 0254C 80B64F0C 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 02550 80B64F10 1720000A */  bne     $t9, $zero, .L80B64F3C     
/* 02554 80B64F14 24080384 */  addiu   $t0, $zero, 0x0384         ## $t0 = 00000384
/* 02558 80B64F18 8E2402C0 */  lw      $a0, 0x02C0($s1)           ## 000002C0
/* 0255C 80B64F1C 2409044B */  addiu   $t1, $zero, 0x044B         ## $t1 = 0000044B
/* 02560 80B64F20 AFA90018 */  sw      $t1, 0x0018($sp)           
/* 02564 80B64F24 AFA80014 */  sw      $t0, 0x0014($sp)           
/* 02568 80B64F28 AFA00010 */  sw      $zero, 0x0010($sp)         
/* 0256C 80B64F2C 0C024CDC */  jal     Gfx_SetFog              
/* 02570 80B64F30 240500FF */  addiu   $a1, $zero, 0x00FF         ## $a1 = 000000FF
/* 02574 80B64F34 10000076 */  beq     $zero, $zero, .L80B65110   
/* 02578 80B64F38 AE2202C0 */  sw      $v0, 0x02C0($s1)           ## 000002C0
.L80B64F3C:
/* 0257C 80B64F3C 444AF800 */  cfc1    $t2, $31
.L80B64F40:
/* 02580 80B64F40 44C5F800 */  ctc1    $a1, $31
/* 02584 80B64F44 C60401E8 */  lwc1    $f4, 0x01E8($s0)           ## 000001E8
/* 02588 80B64F48 8E2402C0 */  lw      $a0, 0x02C0($s1)           ## 000002C0
/* 0258C 80B64F4C 3C014F00 */  lui     $at, 0x4F00                ## $at = 4F000000
/* 02590 80B64F50 460021A4 */  cvt.w.s $f6, $f4                   
/* 02594 80B64F54 4445F800 */  cfc1    $a1, $31
/* 02598 80B64F58 00000000 */  nop
/* 0259C 80B64F5C 30A50078 */  andi    $a1, $a1, 0x0078           ## $a1 = 00000000
/* 025A0 80B64F60 50A00013 */  beql    $a1, $zero, .L80B64FB0     
/* 025A4 80B64F64 44053000 */  mfc1    $a1, $f6                   
/* 025A8 80B64F68 44813000 */  mtc1    $at, $f6                   ## $f6 = 2147483648.00
/* 025AC 80B64F6C 24050001 */  addiu   $a1, $zero, 0x0001         ## $a1 = 00000001
/* 025B0 80B64F70 46062181 */  sub.s   $f6, $f4, $f6              
/* 025B4 80B64F74 44C5F800 */  ctc1    $a1, $31
/* 025B8 80B64F78 00000000 */  nop
/* 025BC 80B64F7C 460031A4 */  cvt.w.s $f6, $f6                   
/* 025C0 80B64F80 4445F800 */  cfc1    $a1, $31
/* 025C4 80B64F84 00000000 */  nop
/* 025C8 80B64F88 30A50078 */  andi    $a1, $a1, 0x0078           ## $a1 = 00000000
/* 025CC 80B64F8C 14A00005 */  bne     $a1, $zero, .L80B64FA4     
/* 025D0 80B64F90 00000000 */  nop
/* 025D4 80B64F94 44053000 */  mfc1    $a1, $f6                   
/* 025D8 80B64F98 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 025DC 80B64F9C 10000007 */  beq     $zero, $zero, .L80B64FBC   
/* 025E0 80B64FA0 00A12825 */  or      $a1, $a1, $at              ## $a1 = 80000000
.L80B64FA4:
/* 025E4 80B64FA4 10000005 */  beq     $zero, $zero, .L80B64FBC   
/* 025E8 80B64FA8 2405FFFF */  addiu   $a1, $zero, 0xFFFF         ## $a1 = FFFFFFFF
/* 025EC 80B64FAC 44053000 */  mfc1    $a1, $f6                   
.L80B64FB0:
/* 025F0 80B64FB0 00000000 */  nop
/* 025F4 80B64FB4 04A0FFFB */  bltz    $a1, .L80B64FA4            
/* 025F8 80B64FB8 00000000 */  nop
.L80B64FBC:
/* 025FC 80B64FBC 44CAF800 */  ctc1    $t2, $31
/* 02600 80B64FC0 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 02604 80B64FC4 C60801EC */  lwc1    $f8, 0x01EC($s0)           ## 000001EC
/* 02608 80B64FC8 3C014F00 */  lui     $at, 0x4F00                ## $at = 4F000000
/* 0260C 80B64FCC 444BF800 */  cfc1    $t3, $31
/* 02610 80B64FD0 44C6F800 */  ctc1    $a2, $31
/* 02614 80B64FD4 00000000 */  nop
/* 02618 80B64FD8 460042A4 */  cvt.w.s $f10, $f8                  
/* 0261C 80B64FDC 4446F800 */  cfc1    $a2, $31
/* 02620 80B64FE0 00000000 */  nop
/* 02624 80B64FE4 30C60078 */  andi    $a2, $a2, 0x0078           ## $a2 = 00000000
/* 02628 80B64FE8 50C00013 */  beql    $a2, $zero, .L80B65038     
/* 0262C 80B64FEC 44065000 */  mfc1    $a2, $f10                  
/* 02630 80B64FF0 44815000 */  mtc1    $at, $f10                  ## $f10 = 2147483648.00
/* 02634 80B64FF4 24060001 */  addiu   $a2, $zero, 0x0001         ## $a2 = 00000001
/* 02638 80B64FF8 460A4281 */  sub.s   $f10, $f8, $f10            
/* 0263C 80B64FFC 44C6F800 */  ctc1    $a2, $31
/* 02640 80B65000 00000000 */  nop
/* 02644 80B65004 460052A4 */  cvt.w.s $f10, $f10                 
/* 02648 80B65008 4446F800 */  cfc1    $a2, $31
/* 0264C 80B6500C 00000000 */  nop
/* 02650 80B65010 30C60078 */  andi    $a2, $a2, 0x0078           ## $a2 = 00000000
/* 02654 80B65014 14C00005 */  bne     $a2, $zero, .L80B6502C     
/* 02658 80B65018 00000000 */  nop
/* 0265C 80B6501C 44065000 */  mfc1    $a2, $f10                  
/* 02660 80B65020 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 02664 80B65024 10000007 */  beq     $zero, $zero, .L80B65044   
/* 02668 80B65028 00C13025 */  or      $a2, $a2, $at              ## $a2 = 80000000
.L80B6502C:
/* 0266C 80B6502C 10000005 */  beq     $zero, $zero, .L80B65044   
/* 02670 80B65030 2406FFFF */  addiu   $a2, $zero, 0xFFFF         ## $a2 = FFFFFFFF
/* 02674 80B65034 44065000 */  mfc1    $a2, $f10                  
.L80B65038:
/* 02678 80B65038 00000000 */  nop
/* 0267C 80B6503C 04C0FFFB */  bltz    $a2, .L80B6502C            
/* 02680 80B65040 00000000 */  nop
.L80B65044:
/* 02684 80B65044 44CBF800 */  ctc1    $t3, $31
/* 02688 80B65048 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 0268C 80B6504C C61001F0 */  lwc1    $f16, 0x01F0($s0)          ## 000001F0
/* 02690 80B65050 3C014F00 */  lui     $at, 0x4F00                ## $at = 4F000000
/* 02694 80B65054 444CF800 */  cfc1    $t4, $31
/* 02698 80B65058 44C7F800 */  ctc1    $a3, $31
/* 0269C 80B6505C 00000000 */  nop
/* 026A0 80B65060 460084A4 */  cvt.w.s $f18, $f16                 
/* 026A4 80B65064 4447F800 */  cfc1    $a3, $31
/* 026A8 80B65068 00000000 */  nop
/* 026AC 80B6506C 30E70078 */  andi    $a3, $a3, 0x0078           ## $a3 = 00000000
/* 026B0 80B65070 50E00013 */  beql    $a3, $zero, .L80B650C0     
/* 026B4 80B65074 44079000 */  mfc1    $a3, $f18                  
/* 026B8 80B65078 44819000 */  mtc1    $at, $f18                  ## $f18 = 2147483648.00
/* 026BC 80B6507C 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 026C0 80B65080 46128481 */  sub.s   $f18, $f16, $f18           
/* 026C4 80B65084 44C7F800 */  ctc1    $a3, $31
/* 026C8 80B65088 00000000 */  nop
/* 026CC 80B6508C 460094A4 */  cvt.w.s $f18, $f18                 
/* 026D0 80B65090 4447F800 */  cfc1    $a3, $31
/* 026D4 80B65094 00000000 */  nop
/* 026D8 80B65098 30E70078 */  andi    $a3, $a3, 0x0078           ## $a3 = 00000000
/* 026DC 80B6509C 14E00005 */  bne     $a3, $zero, .L80B650B4     
/* 026E0 80B650A0 00000000 */  nop
/* 026E4 80B650A4 44079000 */  mfc1    $a3, $f18                  
/* 026E8 80B650A8 3C018000 */  lui     $at, 0x8000                ## $at = 80000000
/* 026EC 80B650AC 10000007 */  beq     $zero, $zero, .L80B650CC   
/* 026F0 80B650B0 00E13825 */  or      $a3, $a3, $at              ## $a3 = 80000000
.L80B650B4:
/* 026F4 80B650B4 10000005 */  beq     $zero, $zero, .L80B650CC   
/* 026F8 80B650B8 2407FFFF */  addiu   $a3, $zero, 0xFFFF         ## $a3 = FFFFFFFF
/* 026FC 80B650BC 44079000 */  mfc1    $a3, $f18                  
.L80B650C0:
/* 02700 80B650C0 00000000 */  nop
/* 02704 80B650C4 04E0FFFB */  bltz    $a3, .L80B650B4            
/* 02708 80B650C8 00000000 */  nop
.L80B650CC:
/* 0270C 80B650CC AFA00010 */  sw      $zero, 0x0010($sp)         
/* 02710 80B650D0 C60401F4 */  lwc1    $f4, 0x01F4($s0)           ## 000001F4
/* 02714 80B650D4 44CCF800 */  ctc1    $t4, $31
/* 02718 80B650D8 00000000 */  nop
/* 0271C 80B650DC 4600218D */  trunc.w.s $f6, $f4                   
/* 02720 80B650E0 440E3000 */  mfc1    $t6, $f6                   
/* 02724 80B650E4 00000000 */  nop
/* 02728 80B650E8 25CF03E3 */  addiu   $t7, $t6, 0x03E3           ## $t7 = 000003E3
/* 0272C 80B650EC AFAF0014 */  sw      $t7, 0x0014($sp)           
/* 02730 80B650F0 C60801F8 */  lwc1    $f8, 0x01F8($s0)           ## 000001F8
/* 02734 80B650F4 4600428D */  trunc.w.s $f10, $f8                  
/* 02738 80B650F8 44195000 */  mfc1    $t9, $f10                  
/* 0273C 80B650FC 00000000 */  nop
/* 02740 80B65100 272803E8 */  addiu   $t0, $t9, 0x03E8           ## $t0 = 000003E8
/* 02744 80B65104 0C024CDC */  jal     Gfx_SetFog              
/* 02748 80B65108 AFA80018 */  sw      $t0, 0x0018($sp)           
/* 0274C 80B6510C AE2202C0 */  sw      $v0, 0x02C0($s1)           ## 000002C0
.L80B65110:
/* 02750 80B65110 3C0780B6 */  lui     $a3, %hi(func_80B64E94)    ## $a3 = 80B60000
/* 02754 80B65114 24090023 */  addiu   $t1, $zero, 0x0023         ## $t1 = 00000023
/* 02758 80B65118 AFA90010 */  sw      $t1, 0x0010($sp)           
/* 0275C 80B6511C 24E74E94 */  addiu   $a3, $a3, %lo(func_80B64E94) ## $a3 = 80B64E94
/* 02760 80B65120 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 02764 80B65124 02402825 */  or      $a1, $s2, $zero            ## $a1 = 00000000
/* 02768 80B65128 0C0298CC */  jal     func_800A6330              
/* 0276C 80B6512C 26060204 */  addiu   $a2, $s0, 0x0204           ## $a2 = 00000204
/* 02770 80B65130 02402025 */  or      $a0, $s2, $zero            ## $a0 = 00000000
/* 02774 80B65134 0C02F228 */  jal     func_800BC8A0              
/* 02778 80B65138 8E2502C0 */  lw      $a1, 0x02C0($s1)           ## 000002C0
/* 0277C 80B6513C AE2202C0 */  sw      $v0, 0x02C0($s1)           ## 000002C0
/* 02780 80B65140 3C0680B6 */  lui     $a2, %hi(D_80B65388)       ## $a2 = 80B60000
/* 02784 80B65144 24C65388 */  addiu   $a2, $a2, %lo(D_80B65388)  ## $a2 = 80B65388
/* 02788 80B65148 8E450000 */  lw      $a1, 0x0000($s2)           ## 00000000
/* 0278C 80B6514C 27A40040 */  addiu   $a0, $sp, 0x0040           ## $a0 = FFFFFFE0
/* 02790 80B65150 0C031AD5 */  jal     Graph_CloseDisps              
/* 02794 80B65154 240709B0 */  addiu   $a3, $zero, 0x09B0         ## $a3 = 000009B0
/* 02798 80B65158 8FBF0034 */  lw      $ra, 0x0034($sp)           
/* 0279C 80B6515C 8FB00028 */  lw      $s0, 0x0028($sp)           
/* 027A0 80B65160 8FB1002C */  lw      $s1, 0x002C($sp)           
/* 027A4 80B65164 8FB20030 */  lw      $s2, 0x0030($sp)           
/* 027A8 80B65168 03E00008 */  jr      $ra                        
/* 027AC 80B6516C 27BD0060 */  addiu   $sp, $sp, 0x0060           ## $sp = 00000000
