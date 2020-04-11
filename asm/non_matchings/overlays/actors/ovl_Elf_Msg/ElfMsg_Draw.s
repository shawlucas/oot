.rdata
glabel D_809AD5C0
    .asciz "../z_elf_msg.c"
    .balign 4

glabel D_809AD5D0
    .asciz "../z_elf_msg.c"
    .balign 4

glabel D_809AD5E0
    .asciz "../z_elf_msg.c"
    .balign 4

.text
glabel ElfMsg_Draw
/* 00570 809AD090 27BDFFB8 */  addiu   $sp, $sp, 0xFFB8           ## $sp = FFFFFFB8
/* 00574 809AD094 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 00578 809AD098 AFA40048 */  sw      $a0, 0x0048($sp)           
/* 0057C 809AD09C AFA5004C */  sw      $a1, 0x004C($sp)           
/* 00580 809AD0A0 8CA50000 */  lw      $a1, 0x0000($a1)           ## 00000000
/* 00584 809AD0A4 3C06809B */  lui     $a2, %hi(D_809AD5C0)       ## $a2 = 809B0000
/* 00588 809AD0A8 24C6D5C0 */  addiu   $a2, $a2, %lo(D_809AD5C0)  ## $a2 = 809AD5C0
/* 0058C 809AD0AC 27A40034 */  addiu   $a0, $sp, 0x0034           ## $a0 = FFFFFFEC
/* 00590 809AD0B0 240701B4 */  addiu   $a3, $zero, 0x01B4         ## $a3 = 000001B4
/* 00594 809AD0B4 0C031AB1 */  jal     Graph_OpenDisps              
/* 00598 809AD0B8 AFA50044 */  sw      $a1, 0x0044($sp)           
/* 0059C 809AD0BC 3C058016 */  lui     $a1, 0x8016                ## $a1 = 80160000
/* 005A0 809AD0C0 24A5FA90 */  addiu   $a1, $a1, 0xFA90           ## $a1 = 8015FA90
/* 005A4 809AD0C4 8CAF0000 */  lw      $t7, 0x0000($a1)           ## 8015FA90
/* 005A8 809AD0C8 8FA80044 */  lw      $t0, 0x0044($sp)           
/* 005AC 809AD0CC 8FB9004C */  lw      $t9, 0x004C($sp)           
/* 005B0 809AD0D0 85F812C2 */  lh      $t8, 0x12C2($t7)           ## 000012C2
/* 005B4 809AD0D4 53000059 */  beql    $t8, $zero, .L809AD23C     
/* 005B8 809AD0D8 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 005BC 809AD0DC 8F240000 */  lw      $a0, 0x0000($t9)           ## 00000000
/* 005C0 809AD0E0 0C024F46 */  jal     func_80093D18              
/* 005C4 809AD0E4 AFA80044 */  sw      $t0, 0x0044($sp)           
/* 005C8 809AD0E8 8FA90048 */  lw      $t1, 0x0048($sp)           
/* 005CC 809AD0EC 3C058016 */  lui     $a1, 0x8016                ## $a1 = 80160000
/* 005D0 809AD0F0 24A5FA90 */  addiu   $a1, $a1, 0xFA90           ## $a1 = 8015FA90
/* 005D4 809AD0F4 852A001C */  lh      $t2, 0x001C($t1)           ## 0000001C
/* 005D8 809AD0F8 8FA80044 */  lw      $t0, 0x0044($sp)           
/* 005DC 809AD0FC 240601C0 */  addiu   $a2, $zero, 0x01C0         ## $a2 = 000001C0
/* 005E0 809AD100 314B8000 */  andi    $t3, $t2, 0x8000           ## $t3 = 00000000
/* 005E4 809AD104 5160000F */  beql    $t3, $zero, .L809AD144     
/* 005E8 809AD108 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 005EC 809AD10C 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 005F0 809AD110 3C0DFA00 */  lui     $t5, 0xFA00                ## $t5 = FA000000
/* 005F4 809AD114 3C01FF64 */  lui     $at, 0xFF64                ## $at = FF640000
/* 005F8 809AD118 244C0008 */  addiu   $t4, $v0, 0x0008           ## $t4 = 00000008
/* 005FC 809AD11C AD0C02D0 */  sw      $t4, 0x02D0($t0)           ## 000002D0
/* 00600 809AD120 AC4D0000 */  sw      $t5, 0x0000($v0)           ## 00000000
/* 00604 809AD124 8CAE0000 */  lw      $t6, 0x0000($a1)           ## 8015FA90
/* 00608 809AD128 34216400 */  ori     $at, $at, 0x6400           ## $at = FF646400
/* 0060C 809AD12C 85CF12C2 */  lh      $t7, 0x12C2($t6)           ## 000012C2
/* 00610 809AD130 31F800FF */  andi    $t8, $t7, 0x00FF           ## $t8 = 00000000
/* 00614 809AD134 0301C825 */  or      $t9, $t8, $at              ## $t9 = FF646400
/* 00618 809AD138 1000000C */  beq     $zero, $zero, .L809AD16C   
/* 0061C 809AD13C AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00620 809AD140 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
.L809AD144:
/* 00624 809AD144 3C0AFA00 */  lui     $t2, 0xFA00                ## $t2 = FA000000
/* 00628 809AD148 2401FF00 */  addiu   $at, $zero, 0xFF00         ## $at = FFFFFF00
/* 0062C 809AD14C 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 00630 809AD150 AD0902D0 */  sw      $t1, 0x02D0($t0)           ## 000002D0
/* 00634 809AD154 AC4A0000 */  sw      $t2, 0x0000($v0)           ## 00000000
/* 00638 809AD158 8CAB0000 */  lw      $t3, 0x0000($a1)           ## 8015FA90
/* 0063C 809AD15C 856C12C2 */  lh      $t4, 0x12C2($t3)           ## 000012C2
/* 00640 809AD160 318D00FF */  andi    $t5, $t4, 0x00FF           ## $t5 = 00000008
/* 00644 809AD164 01A17025 */  or      $t6, $t5, $at              ## $t6 = FFFFFF08
/* 00648 809AD168 AC4E0004 */  sw      $t6, 0x0004($v0)           ## 00000004
.L809AD16C:
/* 0064C 809AD16C 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 00650 809AD170 3C18DA38 */  lui     $t8, 0xDA38                ## $t8 = DA380000
/* 00654 809AD174 37180003 */  ori     $t8, $t8, 0x0003           ## $t8 = DA380003
/* 00658 809AD178 244F0008 */  addiu   $t7, $v0, 0x0008           ## $t7 = 00000008
/* 0065C 809AD17C AD0F02D0 */  sw      $t7, 0x02D0($t0)           ## 000002D0
/* 00660 809AD180 AC580000 */  sw      $t8, 0x0000($v0)           ## 00000000
/* 00664 809AD184 8FB9004C */  lw      $t9, 0x004C($sp)           
/* 00668 809AD188 3C05809B */  lui     $a1, %hi(D_809AD5D0)       ## $a1 = 809B0000
/* 0066C 809AD18C 24A5D5D0 */  addiu   $a1, $a1, %lo(D_809AD5D0)  ## $a1 = 809AD5D0
/* 00670 809AD190 8F240000 */  lw      $a0, 0x0000($t9)           ## FF646400
/* 00674 809AD194 AFA80044 */  sw      $t0, 0x0044($sp)           
/* 00678 809AD198 0C0346A2 */  jal     Matrix_NewMtx              
/* 0067C 809AD19C AFA20028 */  sw      $v0, 0x0028($sp)           
/* 00680 809AD1A0 8FA30028 */  lw      $v1, 0x0028($sp)           
/* 00684 809AD1A4 8FA80044 */  lw      $t0, 0x0044($sp)           
/* 00688 809AD1A8 3C0A809B */  lui     $t2, %hi(D_809AD278)       ## $t2 = 809B0000
/* 0068C 809AD1AC AC620004 */  sw      $v0, 0x0004($v1)           ## 00000004
/* 00690 809AD1B0 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 00694 809AD1B4 254AD278 */  addiu   $t2, $t2, %lo(D_809AD278)  ## $t2 = 809AD278
/* 00698 809AD1B8 3C04DE00 */  lui     $a0, 0xDE00                ## $a0 = DE000000
/* 0069C 809AD1BC 24490008 */  addiu   $t1, $v0, 0x0008           ## $t1 = 00000008
/* 006A0 809AD1C0 AD0902D0 */  sw      $t1, 0x02D0($t0)           ## 000002D0
/* 006A4 809AD1C4 AC4A0004 */  sw      $t2, 0x0004($v0)           ## 00000004
/* 006A8 809AD1C8 AC440000 */  sw      $a0, 0x0000($v0)           ## 00000000
/* 006AC 809AD1CC 8FAB0048 */  lw      $t3, 0x0048($sp)           
/* 006B0 809AD1D0 3C06809B */  lui     $a2, %hi(D_809AD5E0)       ## $a2 = 809B0000
/* 006B4 809AD1D4 24C6D5E0 */  addiu   $a2, $a2, %lo(D_809AD5E0)  ## $a2 = 809AD5E0
/* 006B8 809AD1D8 856C001C */  lh      $t4, 0x001C($t3)           ## 0000001C
/* 006BC 809AD1DC 240701C9 */  addiu   $a3, $zero, 0x01C9         ## $a3 = 000001C9
/* 006C0 809AD1E0 318D4000 */  andi    $t5, $t4, 0x4000           ## $t5 = 00000000
/* 006C4 809AD1E4 51A0000A */  beql    $t5, $zero, .L809AD210     
/* 006C8 809AD1E8 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 006CC 809AD1EC 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
/* 006D0 809AD1F0 3C0F809B */  lui     $t7, %hi(D_809AD4B8)       ## $t7 = 809B0000
/* 006D4 809AD1F4 25EFD4B8 */  addiu   $t7, $t7, %lo(D_809AD4B8)  ## $t7 = 809AD4B8
/* 006D8 809AD1F8 244E0008 */  addiu   $t6, $v0, 0x0008           ## $t6 = 00000008
/* 006DC 809AD1FC AD0E02D0 */  sw      $t6, 0x02D0($t0)           ## 000002D0
/* 006E0 809AD200 AC4F0004 */  sw      $t7, 0x0004($v0)           ## 00000004
/* 006E4 809AD204 10000008 */  beq     $zero, $zero, .L809AD228   
/* 006E8 809AD208 AC440000 */  sw      $a0, 0x0000($v0)           ## 00000000
/* 006EC 809AD20C 8D0202D0 */  lw      $v0, 0x02D0($t0)           ## 000002D0
.L809AD210:
/* 006F0 809AD210 3C19809B */  lui     $t9, %hi(D_809AD3B8)       ## $t9 = 809B0000
/* 006F4 809AD214 2739D3B8 */  addiu   $t9, $t9, %lo(D_809AD3B8)  ## $t9 = 809AD3B8
/* 006F8 809AD218 24580008 */  addiu   $t8, $v0, 0x0008           ## $t8 = 00000008
/* 006FC 809AD21C AD1802D0 */  sw      $t8, 0x02D0($t0)           ## 000002D0
/* 00700 809AD220 AC590004 */  sw      $t9, 0x0004($v0)           ## 00000004
/* 00704 809AD224 AC440000 */  sw      $a0, 0x0000($v0)           ## 00000000
.L809AD228:
/* 00708 809AD228 8FA9004C */  lw      $t1, 0x004C($sp)           
/* 0070C 809AD22C 27A40034 */  addiu   $a0, $sp, 0x0034           ## $a0 = FFFFFFEC
/* 00710 809AD230 0C031AD5 */  jal     Graph_CloseDisps              
/* 00714 809AD234 8D250000 */  lw      $a1, 0x0000($t1)           ## 00000008
/* 00718 809AD238 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L809AD23C:
/* 0071C 809AD23C 27BD0048 */  addiu   $sp, $sp, 0x0048           ## $sp = 00000000
/* 00720 809AD240 03E00008 */  jr      $ra                        
/* 00724 809AD244 00000000 */  nop
/* 00728 809AD248 00000000 */  nop
/* 0072C 809AD24C 00000000 */  nop

