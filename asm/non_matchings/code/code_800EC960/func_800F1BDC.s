.late_rodata
glabel jtbl_8014A4D4
    .word L800F1E70
    .word L800F1E70
    .word L800F1EA4
    .word L800F1EA4
    .word L800F1F00
    .word L800F1F2C
    .word L800F1F64
    .word L800F1FE4
    .word L800F2048
    .word L800F2048
    .word L800F2010

glabel jtbl_8014A500
    .word L800F2078
    .word L800F2078
    .word L800F20C0
    .word L800F20C0
    .word L800F20D8
    .word L800F20D8
    .word L800F20D8
    .word L800F20A0

.text
glabel func_800F1BDC
/* B68D7C 800F1BDC 3C028017 */  lui   $v0, %hi(D_8016BAB0) # $v0, 0x8017
/* B68D80 800F1BE0 8C42BAB0 */  lw    $v0, %lo(D_8016BAB0)($v0)
/* B68D84 800F1BE4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* B68D88 800F1BE8 AFBF001C */  sw    $ra, 0x1c($sp)
/* B68D8C 800F1BEC 304E0004 */  andi  $t6, $v0, 4
/* B68D90 800F1BF0 11C0000E */  beqz  $t6, .L800F1C2C
/* B68D94 800F1BF4 24090001 */   li    $t1, 1
/* B68D98 800F1BF8 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B68D9C 800F1BFC 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B68DA0 800F1C00 916F0000 */  lbu   $t7, ($t3)
/* B68DA4 800F1C04 3C0A8013 */  lui   $t2, %hi(D_80131E20) # $t2, 0x8013
/* B68DA8 800F1C08 254A1E20 */  addiu $t2, %lo(D_80131E20) # addiu $t2, $t2, 0x1e20
/* B68DAC 800F1C0C 000FC040 */  sll   $t8, $t7, 1
/* B68DB0 800F1C10 0158C821 */  addu  $t9, $t2, $t8
/* B68DB4 800F1C14 972C0000 */  lhu   $t4, ($t9)
/* B68DB8 800F1C18 29810010 */  slti  $at, $t4, 0x10
/* B68DBC 800F1C1C 14200019 */  bnez  $at, .L800F1C84
/* B68DC0 800F1C20 00000000 */   nop   
/* B68DC4 800F1C24 10000017 */  b     .L800F1C84
/* B68DC8 800F1C28 24090010 */   li    $t1, 16
.L800F1C2C:
/* B68DCC 800F1C2C 304D0002 */  andi  $t5, $v0, 2
/* B68DD0 800F1C30 11A0000C */  beqz  $t5, .L800F1C64
/* B68DD4 800F1C34 3C0E8013 */   lui   $t6, %hi(D_80131CA4) # $t6, 0x8013
/* B68DD8 800F1C38 91CE1CA4 */  lbu   $t6, %lo(D_80131CA4)($t6)
/* B68DDC 800F1C3C 3C0A8013 */  lui   $t2, %hi(D_80131E20) # $t2, 0x8013
/* B68DE0 800F1C40 254A1E20 */  addiu $t2, %lo(D_80131E20) # addiu $t2, $t2, 0x1e20
/* B68DE4 800F1C44 000E7840 */  sll   $t7, $t6, 1
/* B68DE8 800F1C48 014FC021 */  addu  $t8, $t2, $t7
/* B68DEC 800F1C4C 97190000 */  lhu   $t9, ($t8)
/* B68DF0 800F1C50 2B210010 */  slti  $at, $t9, 0x10
/* B68DF4 800F1C54 1420000B */  bnez  $at, .L800F1C84
/* B68DF8 800F1C58 00000000 */   nop   
/* B68DFC 800F1C5C 10000009 */  b     .L800F1C84
/* B68E00 800F1C60 24090008 */   li    $t1, 8
.L800F1C64:
/* B68E04 800F1C64 304C0008 */  andi  $t4, $v0, 8
/* B68E08 800F1C68 11800006 */  beqz  $t4, .L800F1C84
/* B68E0C 800F1C6C 3C0D8013 */   lui   $t5, %hi(D_80131CA4) # $t5, 0x8013
/* B68E10 800F1C70 91AD1CA4 */  lbu   $t5, %lo(D_80131CA4)($t5)
/* B68E14 800F1C74 3C018013 */  lui   $at, %hi(D_80131E08)
/* B68E18 800F1C78 000D7040 */  sll   $t6, $t5, 1
/* B68E1C 800F1C7C 002E0821 */  addu  $at, $at, $t6
/* B68E20 800F1C80 A4201E08 */  sh    $zero, %lo(D_80131E08)($at)
.L800F1C84:
/* B68E24 800F1C84 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B68E28 800F1C88 8C84BAB8 */  lw    $a0, %lo(sDebugPadPress)($a0)
/* B68E2C 800F1C8C 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B68E30 800F1C90 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B68E34 800F1C94 3C0A8013 */  lui   $t2, %hi(D_80131E20) # $t2, 0x8013
/* B68E38 800F1C98 308F0800 */  andi  $t7, $a0, 0x800
/* B68E3C 800F1C9C 254A1E20 */  addiu $t2, %lo(D_80131E20) # addiu $t2, $t2, 0x1e20
/* B68E40 800F1CA0 11E00009 */  beqz  $t7, .L800F1CC8
/* B68E44 800F1CA4 91620000 */   lbu   $v0, ($t3)
/* B68E48 800F1CA8 18400005 */  blez  $v0, .L800F1CC0
/* B68E4C 800F1CAC 2419000A */   li    $t9, 10
/* B68E50 800F1CB0 2458FFFF */  addiu $t8, $v0, -1
/* B68E54 800F1CB4 A1780000 */  sb    $t8, ($t3)
/* B68E58 800F1CB8 10000003 */  b     .L800F1CC8
/* B68E5C 800F1CBC 330200FF */   andi  $v0, $t8, 0xff
.L800F1CC0:
/* B68E60 800F1CC0 A1790000 */  sb    $t9, ($t3)
/* B68E64 800F1CC4 332200FF */  andi  $v0, $t9, 0xff
.L800F1CC8:
/* B68E68 800F1CC8 308C0400 */  andi  $t4, $a0, 0x400
/* B68E6C 800F1CCC 11800009 */  beqz  $t4, .L800F1CF4
/* B68E70 800F1CD0 308E0200 */   andi  $t6, $a0, 0x200
/* B68E74 800F1CD4 2841000A */  slti  $at, $v0, 0xa
/* B68E78 800F1CD8 10200004 */  beqz  $at, .L800F1CEC
/* B68E7C 800F1CDC 244D0001 */   addiu $t5, $v0, 1
/* B68E80 800F1CE0 A16D0000 */  sb    $t5, ($t3)
/* B68E84 800F1CE4 10000003 */  b     .L800F1CF4
/* B68E88 800F1CE8 31A200FF */   andi  $v0, $t5, 0xff
.L800F1CEC:
/* B68E8C 800F1CEC A1600000 */  sb    $zero, ($t3)
/* B68E90 800F1CF0 300200FF */  andi  $v0, $zero, 0xff
.L800F1CF4:
/* B68E94 800F1CF4 11C00010 */  beqz  $t6, .L800F1D38
/* B68E98 800F1CF8 3C088013 */   lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B68E9C 800F1CFC 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B68EA0 800F1D00 00021840 */  sll   $v1, $v0, 1
/* B68EA4 800F1D04 01032821 */  addu  $a1, $t0, $v1
/* B68EA8 800F1D08 94A60000 */  lhu   $a2, ($a1)
/* B68EAC 800F1D0C 01203825 */  move  $a3, $t1
/* B68EB0 800F1D10 0143C021 */  addu  $t8, $t2, $v1
/* B68EB4 800F1D14 00C9082A */  slt   $at, $a2, $t1
/* B68EB8 800F1D18 14200003 */  bnez  $at, .L800F1D28
/* B68EBC 800F1D1C 00C77823 */   subu  $t7, $a2, $a3
/* B68EC0 800F1D20 10000005 */  b     .L800F1D38
/* B68EC4 800F1D24 A4AF0000 */   sh    $t7, ($a1)
.L800F1D28:
/* B68EC8 800F1D28 97190000 */  lhu   $t9, ($t8)
/* B68ECC 800F1D2C 00D96021 */  addu  $t4, $a2, $t9
/* B68ED0 800F1D30 01876823 */  subu  $t5, $t4, $a3
/* B68ED4 800F1D34 A4AD0000 */  sh    $t5, ($a1)
.L800F1D38:
/* B68ED8 800F1D38 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B68EDC 800F1D3C 308E0100 */  andi  $t6, $a0, 0x100
/* B68EE0 800F1D40 11C0000D */  beqz  $t6, .L800F1D78
/* B68EE4 800F1D44 25081E08 */   addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B68EE8 800F1D48 00021840 */  sll   $v1, $v0, 1
/* B68EEC 800F1D4C 01032821 */  addu  $a1, $t0, $v1
/* B68EF0 800F1D50 94AF0000 */  lhu   $t7, ($a1)
/* B68EF4 800F1D54 0143C021 */  addu  $t8, $t2, $v1
/* B68EF8 800F1D58 97060000 */  lhu   $a2, ($t8)
/* B68EFC 800F1D5C 01E92021 */  addu  $a0, $t7, $t1
/* B68F00 800F1D60 0086082A */  slt   $at, $a0, $a2
/* B68F04 800F1D64 10200003 */  beqz  $at, .L800F1D74
/* B68F08 800F1D68 0086C823 */   subu  $t9, $a0, $a2
/* B68F0C 800F1D6C 10000002 */  b     .L800F1D78
/* B68F10 800F1D70 A4A40000 */   sh    $a0, ($a1)
.L800F1D74:
/* B68F14 800F1D74 A4B90000 */  sh    $t9, ($a1)
.L800F1D78:
/* B68F18 800F1D78 24010008 */  li    $at, 8
/* B68F1C 800F1D7C 14410019 */  bne   $v0, $at, .L800F1DE4
/* B68F20 800F1D80 00401825 */   move  $v1, $v0
/* B68F24 800F1D84 00026040 */  sll   $t4, $v0, 1
/* B68F28 800F1D88 010C6821 */  addu  $t5, $t0, $t4
/* B68F2C 800F1D8C 95AE0000 */  lhu   $t6, ($t5)
/* B68F30 800F1D90 11C0000B */  beqz  $t6, .L800F1DC0
/* B68F34 800F1D94 00000000 */   nop   
/* B68F38 800F1D98 0C03DA0A */  jal   func_800F6828
/* B68F3C 800F1D9C 24040020 */   li    $a0, 32
/* B68F40 800F1DA0 3C028013 */  lui   $v0, %hi(D_80131CA4) # $v0, 0x8013
/* B68F44 800F1DA4 90421CA4 */  lbu   $v0, %lo(D_80131CA4)($v0)
/* B68F48 800F1DA8 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B68F4C 800F1DAC 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B68F50 800F1DB0 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B68F54 800F1DB4 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B68F58 800F1DB8 1000000A */  b     .L800F1DE4
/* B68F5C 800F1DBC 00401825 */   move  $v1, $v0
.L800F1DC0:
/* B68F60 800F1DC0 0C03DA0A */  jal   func_800F6828
/* B68F64 800F1DC4 00002025 */   move  $a0, $zero
/* B68F68 800F1DC8 3C028013 */  lui   $v0, %hi(D_80131CA4) # $v0, 0x8013
/* B68F6C 800F1DCC 90421CA4 */  lbu   $v0, %lo(D_80131CA4)($v0)
/* B68F70 800F1DD0 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B68F74 800F1DD4 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B68F78 800F1DD8 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B68F7C 800F1DDC 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B68F80 800F1DE0 00401825 */  move  $v1, $v0
.L800F1DE4:
/* B68F84 800F1DE4 24010009 */  li    $at, 9
/* B68F88 800F1DE8 14610012 */  bne   $v1, $at, .L800F1E34
/* B68F8C 800F1DEC 00027840 */   sll   $t7, $v0, 1
/* B68F90 800F1DF0 010FC021 */  addu  $t8, $t0, $t7
/* B68F94 800F1DF4 97190000 */  lhu   $t9, ($t8)
/* B68F98 800F1DF8 13200008 */  beqz  $t9, .L800F1E1C
/* B68F9C 800F1DFC 00000000 */   nop   
/* B68FA0 800F1E00 0C03D9E8 */  jal   func_800F67A0
/* B68FA4 800F1E04 24040020 */   li    $a0, 32
/* B68FA8 800F1E08 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B68FAC 800F1E0C 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B68FB0 800F1E10 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B68FB4 800F1E14 10000007 */  b     .L800F1E34
/* B68FB8 800F1E18 256B1CA4 */   addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
.L800F1E1C:
/* B68FBC 800F1E1C 0C03D9E8 */  jal   func_800F67A0
/* B68FC0 800F1E20 00002025 */   move  $a0, $zero
/* B68FC4 800F1E24 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B68FC8 800F1E28 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B68FCC 800F1E2C 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B68FD0 800F1E30 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
.L800F1E34:
/* B68FD4 800F1E34 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B68FD8 800F1E38 8C84BAB8 */  lw    $a0, %lo(sDebugPadPress)($a0)
/* B68FDC 800F1E3C 308C8000 */  andi  $t4, $a0, 0x8000
/* B68FE0 800F1E40 51800082 */  beql  $t4, $zero, .L800F204C
/* B68FE4 800F1E44 308E4000 */   andi  $t6, $a0, 0x4000
/* B68FE8 800F1E48 91620000 */  lbu   $v0, ($t3)
/* B68FEC 800F1E4C 2C41000B */  sltiu $at, $v0, 0xb
/* B68FF0 800F1E50 1020007D */  beqz  $at, .L800F2048
/* B68FF4 800F1E54 00401825 */   move  $v1, $v0
/* B68FF8 800F1E58 00036880 */  sll   $t5, $v1, 2
/* B68FFC 800F1E5C 3C018015 */  lui   $at, %hi(jtbl_8014A4D4)
/* B69000 800F1E60 002D0821 */  addu  $at, $at, $t5
/* B69004 800F1E64 8C2DA4D4 */  lw    $t5, %lo(jtbl_8014A4D4)($at)
/* B69008 800F1E68 01A00008 */  jr    $t5
/* B6900C 800F1E6C 00000000 */   nop   
glabel L800F1E70
/* B69010 800F1E70 00027040 */  sll   $t6, $v0, 1
/* B69014 800F1E74 010E7821 */  addu  $t7, $t0, $t6
/* B69018 800F1E78 95F80000 */  lhu   $t8, ($t7)
/* B6901C 800F1E7C 0003CE00 */  sll   $t9, $v1, 0x18
/* B69020 800F1E80 0C03E803 */  jal   Audio_SetBGM
/* B69024 800F1E84 03192025 */   or    $a0, $t8, $t9
/* B69028 800F1E88 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B6902C 800F1E8C 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B69030 800F1E90 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B69034 800F1E94 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B69038 800F1E98 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B6903C 800F1E9C 1000006A */  b     .L800F2048
/* B69040 800F1EA0 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F1EA4
/* B69044 800F1EA4 950D0004 */  lhu   $t5, 4($t0)
/* B69048 800F1EA8 950C0006 */  lhu   $t4, 6($t0)
/* B6904C 800F1EAC 3C078013 */  lui   $a3, %hi(D_801333E0) # $a3, 0x8013
/* B69050 800F1EB0 000D7B00 */  sll   $t7, $t5, 0xc
/* B69054 800F1EB4 3C188013 */  lui   $t8, %hi(D_801333E8) # $t8, 0x8013
/* B69058 800F1EB8 018F2021 */  addu  $a0, $t4, $t7
/* B6905C 800F1EBC 24E733E0 */  addiu $a3, %lo(D_801333E0) # addiu $a3, $a3, 0x33e0
/* B69060 800F1EC0 24840800 */  addiu $a0, $a0, 0x800
/* B69064 800F1EC4 271833E8 */  addiu $t8, %lo(D_801333E8) # addiu $t8, $t8, 0x33e8
/* B69068 800F1EC8 3C058013 */  lui   $a1, %hi(D_801333D4) # $a1, 0x8013
/* B6906C 800F1ECC 24A533D4 */  addiu $a1, %lo(D_801333D4) # addiu $a1, $a1, 0x33d4
/* B69070 800F1ED0 AFB80014 */  sw    $t8, 0x14($sp)
/* B69074 800F1ED4 3084FFFF */  andi  $a0, $a0, 0xffff
/* B69078 800F1ED8 AFA70010 */  sw    $a3, 0x10($sp)
/* B6907C 800F1EDC 0C03DCE3 */  jal   Audio_PlaySoundGeneral
/* B69080 800F1EE0 24060004 */   li    $a2, 4
/* B69084 800F1EE4 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B69088 800F1EE8 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B6908C 800F1EEC 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B69090 800F1EF0 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B69094 800F1EF4 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B69098 800F1EF8 10000053 */  b     .L800F2048
/* B6909C 800F1EFC 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F1F00
/* B690A0 800F1F00 0002C840 */  sll   $t9, $v0, 1
/* B690A4 800F1F04 01196821 */  addu  $t5, $t0, $t9
/* B690A8 800F1F08 0C03D9C0 */  jal   func_800F6700
/* B690AC 800F1F0C 81A40001 */   lb    $a0, 1($t5)
/* B690B0 800F1F10 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B690B4 800F1F14 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B690B8 800F1F18 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B690BC 800F1F1C 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B690C0 800F1F20 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B690C4 800F1F24 10000048 */  b     .L800F2048
/* B690C8 800F1F28 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F1F2C
/* B690CC 800F1F2C 00027040 */  sll   $t6, $v0, 1
/* B690D0 800F1F30 010E6021 */  addu  $t4, $t0, $t6
/* B690D4 800F1F34 95840000 */  lhu   $a0, ($t4)
/* B690D8 800F1F38 3C01E000 */  lui   $at, (0xE0000100 >> 16) # lui $at, 0xe000
/* B690DC 800F1F3C 34210100 */  ori   $at, (0xE0000100 & 0xFFFF) # ori $at, $at, 0x100
/* B690E0 800F1F40 0C03E803 */  jal   Audio_SetBGM
/* B690E4 800F1F44 00812025 */   or    $a0, $a0, $at
/* B690E8 800F1F48 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B690EC 800F1F4C 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B690F0 800F1F50 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B690F4 800F1F54 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B690F8 800F1F58 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B690FC 800F1F5C 1000003A */  b     .L800F2048
/* B69100 800F1F60 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F1F64
/* B69104 800F1F64 00027840 */  sll   $t7, $v0, 1
/* B69108 800F1F68 010FC021 */  addu  $t8, $t0, $t7
/* B6910C 800F1F6C 93040001 */  lbu   $a0, 1($t8)
/* B69110 800F1F70 3C01F000 */  lui   $at, 0xf000
/* B69114 800F1F74 0C03E803 */  jal   Audio_SetBGM
/* B69118 800F1F78 00812025 */   or    $a0, $a0, $at
/* B6911C 800F1F7C 3C198013 */  lui   $t9, %hi(D_80131E14) # $t9, 0x8013
/* B69120 800F1F80 97391E14 */  lhu   $t9, %lo(D_80131E14)($t9)
/* B69124 800F1F84 3C038013 */  lui   $v1, %hi(D_80131EFC) # $v1, 0x8013
/* B69128 800F1F88 24631EFC */  addiu $v1, %lo(D_80131EFC) # addiu $v1, $v1, 0x1efc
/* B6912C 800F1F8C 332D00FF */  andi  $t5, $t9, 0xff
/* B69130 800F1F90 000D70C0 */  sll   $t6, $t5, 3
/* B69134 800F1F94 01CD7023 */  subu  $t6, $t6, $t5
/* B69138 800F1F98 000E70C0 */  sll   $t6, $t6, 3
/* B6913C 800F1F9C 3C028013 */  lui   $v0, %hi(D_801337CE)
/* B69140 800F1FA0 3C048013 */  lui   $a0, %hi(D_80131F28) # $a0, 0x8013
/* B69144 800F1FA4 004E1021 */  addu  $v0, $v0, $t6
/* B69148 800F1FA8 A0790000 */  sb    $t9, ($v1)
/* B6914C 800F1FAC 904237CE */  lbu   $v0, %lo(D_801337CE)($v0)
/* B69150 800F1FB0 24841F28 */  addiu $a0, %lo(D_80131F28) # addiu $a0, $a0, 0x1f28
/* B69154 800F1FB4 908C0000 */  lbu   $t4, ($a0)
/* B69158 800F1FB8 2442FFFF */  addiu $v0, $v0, -1
/* B6915C 800F1FBC 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B69160 800F1FC0 004C082A */  slt   $at, $v0, $t4
/* B69164 800F1FC4 10200002 */  beqz  $at, .L800F1FD0
/* B69168 800F1FC8 256B1CA4 */   addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B6916C 800F1FCC A0820000 */  sb    $v0, ($a0)
.L800F1FD0:
/* B69170 800F1FD0 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B69174 800F1FD4 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B69178 800F1FD8 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B6917C 800F1FDC 1000001A */  b     .L800F2048
/* B69180 800F1FE0 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F1FE4
/* B69184 800F1FE4 00027840 */  sll   $t7, $v0, 1
/* B69188 800F1FE8 010FC021 */  addu  $t8, $t0, $t7
/* B6918C 800F1FEC 0C03DBED */  jal   func_800F6FB4
/* B69190 800F1FF0 93040001 */   lbu   $a0, 1($t8)
/* B69194 800F1FF4 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B69198 800F1FF8 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B6919C 800F1FFC 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B691A0 800F2000 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B691A4 800F2004 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B691A8 800F2008 1000000F */  b     .L800F2048
/* B691AC 800F200C 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F2010
/* B691B0 800F2010 0002C840 */  sll   $t9, $v0, 1
/* B691B4 800F2014 01196821 */  addu  $t5, $t0, $t9
/* B691B8 800F2018 95A40000 */  lhu   $a0, ($t5)
/* B691BC 800F201C 00800821 */  addu  $at, $a0, $zero
/* B691C0 800F2020 000421C0 */  sll   $a0, $a0, 7
/* B691C4 800F2024 00812023 */  subu  $a0, $a0, $at
/* B691C8 800F2028 0C03DC98 */  jal   func_800F7260
/* B691CC 800F202C 3084FFFF */   andi  $a0, $a0, 0xffff
/* B691D0 800F2030 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B691D4 800F2034 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B691D8 800F2038 3C088013 */  lui   $t0, %hi(D_80131E08) # $t0, 0x8013
/* B691DC 800F203C 25081E08 */  addiu $t0, %lo(D_80131E08) # addiu $t0, $t0, 0x1e08
/* B691E0 800F2040 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B691E4 800F2044 8C84BAB8 */  lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F2048
.L800F2048:
/* B691E8 800F2048 308E4000 */  andi  $t6, $a0, 0x4000
.L800F204C:
/* B691EC 800F204C 51C00023 */  beql  $t6, $zero, .L800F20DC
/* B691F0 800F2050 308F0004 */   andi  $t7, $a0, 4
/* B691F4 800F2054 91630000 */  lbu   $v1, ($t3)
/* B691F8 800F2058 2C610008 */  sltiu $at, $v1, 8
/* B691FC 800F205C 1020001E */  beqz  $at, .L800F20D8
/* B69200 800F2060 00036080 */   sll   $t4, $v1, 2
/* B69204 800F2064 3C018015 */  lui   $at, %hi(jtbl_8014A500)
/* B69208 800F2068 002C0821 */  addu  $at, $at, $t4
/* B6920C 800F206C 8C2CA500 */  lw    $t4, %lo(jtbl_8014A500)($at)
/* B69210 800F2070 01800008 */  jr    $t4
/* B69214 800F2074 00000000 */   nop   
glabel L800F2078
/* B69218 800F2078 3C011000 */  lui   $at, (0x100000FF >> 16) # lui $at, 0x1000
/* B6921C 800F207C 342100FF */  ori   $at, (0x100000FF & 0xFFFF) # ori $at, $at, 0xff
/* B69220 800F2080 00032600 */  sll   $a0, $v1, 0x18
/* B69224 800F2084 0C03E803 */  jal   Audio_SetBGM
/* B69228 800F2088 00812025 */   or    $a0, $a0, $at
/* B6922C 800F208C 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B69230 800F2090 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B69234 800F2094 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B69238 800F2098 1000000F */  b     .L800F20D8
/* B6923C 800F209C 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F20A0
/* B69240 800F20A0 3C041000 */  lui   $a0, (0x100000FF >> 16) # lui $a0, 0x1000
/* B69244 800F20A4 0C03E803 */  jal   Audio_SetBGM
/* B69248 800F20A8 348400FF */   ori   $a0, (0x100000FF & 0xFFFF) # ori $a0, $a0, 0xff
/* B6924C 800F20AC 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B69250 800F20B0 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B69254 800F20B4 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B69258 800F20B8 10000007 */  b     .L800F20D8
/* B6925C 800F20BC 8C84BAB8 */   lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F20C0
/* B69260 800F20C0 0C03E1E8 */  jal   func_800F87A0
/* B69264 800F20C4 91040005 */   lbu   $a0, 5($t0)
/* B69268 800F20C8 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B6926C 800F20CC 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B69270 800F20D0 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B69274 800F20D4 8C84BAB8 */  lw    $a0, %lo(sDebugPadPress)($a0)
glabel L800F20D8
.L800F20D8:
/* B69278 800F20D8 308F0004 */  andi  $t7, $a0, 4
.L800F20DC:
/* B6927C 800F20DC 51E0000E */  beql  $t7, $zero, .L800F2118
/* B69280 800F20E0 308D0001 */   andi  $t5, $a0, 1
/* B69284 800F20E4 91620000 */  lbu   $v0, ($t3)
/* B69288 800F20E8 3C198013 */  lui   $t9, %hi(D_80131E08) # $t9, 0x8013
/* B6928C 800F20EC 27391E08 */  addiu $t9, %lo(D_80131E08) # addiu $t9, $t9, 0x1e08
/* B69290 800F20F0 14400008 */  bnez  $v0, .L800F2114
/* B69294 800F20F4 0002C040 */   sll   $t8, $v0, 1
/* B69298 800F20F8 03192821 */  addu  $a1, $t8, $t9
/* B6929C 800F20FC 0C03D657 */  jal   func_800F595C
/* B692A0 800F2100 94A40000 */   lhu   $a0, ($a1)
/* B692A4 800F2104 3C048017 */  lui   $a0, %hi(sDebugPadPress) # $a0, 0x8017
/* B692A8 800F2108 3C0B8013 */  lui   $t3, %hi(D_80131CA4) # $t3, 0x8013
/* B692AC 800F210C 256B1CA4 */  addiu $t3, %lo(D_80131CA4) # addiu $t3, $t3, 0x1ca4
/* B692B0 800F2110 8C84BAB8 */  lw    $a0, %lo(sDebugPadPress)($a0)
.L800F2114:
/* B692B4 800F2114 308D0001 */  andi  $t5, $a0, 1
.L800F2118:
/* B692B8 800F2118 51A0000A */  beql  $t5, $zero, .L800F2144
/* B692BC 800F211C 8FBF001C */   lw    $ra, 0x1c($sp)
/* B692C0 800F2120 91620000 */  lbu   $v0, ($t3)
/* B692C4 800F2124 3C0C8013 */  lui   $t4, %hi(D_80131E08) # $t4, 0x8013
/* B692C8 800F2128 258C1E08 */  addiu $t4, %lo(D_80131E08) # addiu $t4, $t4, 0x1e08
/* B692CC 800F212C 14400004 */  bnez  $v0, .L800F2140
/* B692D0 800F2130 00027040 */   sll   $t6, $v0, 1
/* B692D4 800F2134 01CC2821 */  addu  $a1, $t6, $t4
/* B692D8 800F2138 0C03D6B3 */  jal   func_800F5ACC
/* B692DC 800F213C 94A40000 */   lhu   $a0, ($a1)
.L800F2140:
/* B692E0 800F2140 8FBF001C */  lw    $ra, 0x1c($sp)
.L800F2144:
/* B692E4 800F2144 27BD0020 */  addiu $sp, $sp, 0x20
/* B692E8 800F2148 03E00008 */  jr    $ra
/* B692EC 800F214C 00000000 */   nop   

