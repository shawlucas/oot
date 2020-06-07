.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text

.balign 16

glabel func_80101EB0
/* B79050 80101EB0 27BDFD68 */  addiu $sp, $sp, -0x298
/* B79054 80101EB4 AFB70040 */  sw    $s7, 0x40($sp)
/* B79058 80101EB8 AFB6003C */  sw    $s6, 0x3c($sp)
/* B7905C 80101EBC AFB50038 */  sw    $s5, 0x38($sp)
/* B79060 80101EC0 AFB30030 */  sw    $s3, 0x30($sp)
/* B79064 80101EC4 AFA5029C */  sw    $a1, 0x29c($sp)
/* B79068 80101EC8 30AEFFFF */  andi  $t6, $a1, 0xffff
/* B7906C 80101ECC 01C02825 */  move  $a1, $t6
/* B79070 80101ED0 00809825 */  move  $s3, $a0
/* B79074 80101ED4 AFBF0044 */  sw    $ra, 0x44($sp)
/* B79078 80101ED8 AFB40034 */  sw    $s4, 0x34($sp)
/* B7907C 80101EDC AFB2002C */  sw    $s2, 0x2c($sp)
/* B79080 80101EE0 AFB10028 */  sw    $s1, 0x28($sp)
/* B79084 80101EE4 AFB00024 */  sw    $s0, 0x24($sp)
/* B79088 80101EE8 AFA702A4 */  sw    $a3, 0x2a4($sp)
/* B7908C 80101EEC 0000B025 */  move  $s6, $zero
/* B79090 80101EF0 0000B825 */  move  $s7, $zero
/* B79094 80101EF4 11C00003 */  beqz  $t6, .L80101F04
/* B79098 80101EF8 0000A825 */   move  $s5, $zero
/* B7909C 80101EFC 14C00003 */  bnez  $a2, .L80101F0C
/* B790A0 80101F00 8FB102AC */   lw    $s1, 0x2ac($sp)
.L80101F04:
/* B790A4 80101F04 100000AC */  b     .L801021B8
/* B790A8 80101F08 24020005 */   li    $v0, 5
.L80101F0C:
/* B790AC 80101F0C 263000FF */  addiu $s0, $s1, 0xff
/* B790B0 80101F10 8FB802A8 */  lw    $t8, 0x2a8($sp)
/* B790B4 80101F14 8FB902B0 */  lw    $t9, 0x2b0($sp)
/* B790B8 80101F18 06010003 */  bgez  $s0, .L80101F28
/* B790BC 80101F1C 00107A03 */   sra   $t7, $s0, 8
/* B790C0 80101F20 260100FF */  addiu $at, $s0, 0xff
/* B790C4 80101F24 00017A03 */  sra   $t7, $at, 8
.L80101F28:
/* B790C8 80101F28 01E08025 */  move  $s0, $t7
/* B790CC 80101F2C 01E0A025 */  move  $s4, $t7
/* B790D0 80101F30 02602025 */  move  $a0, $s3
/* B790D4 80101F34 8FA702A4 */  lw    $a3, 0x2a4($sp)
/* B790D8 80101F38 A7A5029E */  sh    $a1, 0x29e($sp)
/* B790DC 80101F3C AFA602A0 */  sw    $a2, 0x2a0($sp)
/* B790E0 80101F40 AFB80010 */  sw    $t8, 0x10($sp)
/* B790E4 80101F44 0C040C04 */  jal   func_80103010
/* B790E8 80101F48 AFB90014 */   sw    $t9, 0x14($sp)
/* B790EC 80101F4C 10400005 */  beqz  $v0, .L80101F64
/* B790F0 80101F50 24010005 */   li    $at, 5
/* B790F4 80101F54 50410004 */  beql  $v0, $at, .L80101F68
/* B790F8 80101F58 8FA802B0 */   lw    $t0, 0x2b0($sp)
/* B790FC 80101F5C 10000097 */  b     .L801021BC
/* B79100 80101F60 8FBF0044 */   lw    $ra, 0x44($sp)
.L80101F64:
/* B79104 80101F64 8FA802B0 */  lw    $t0, 0x2b0($sp)
.L80101F68:
/* B79108 80101F68 2401FFFF */  li    $at, -1
/* B7910C 80101F6C 02602025 */  move  $a0, $s3
/* B79110 80101F70 8D090000 */  lw    $t1, ($t0)
/* B79114 80101F74 11210003 */  beq   $t1, $at, .L80101F84
/* B79118 80101F78 00000000 */   nop   
/* B7911C 80101F7C 1000008E */  b     .L801021B8
/* B79120 80101F80 24020009 */   li    $v0, 9
.L80101F84:
/* B79124 80101F84 0C040010 */  jal   func_80100040
/* B79128 80101F88 27A50054 */   addiu $a1, $sp, 0x54
/* B7912C 80101F8C 8FAA0054 */  lw    $t2, 0x54($sp)
/* B79130 80101F90 0151082A */  slt   $at, $t2, $s1
/* B79134 80101F94 10200003 */  beqz  $at, .L80101FA4
/* B79138 80101F98 00000000 */   nop   
/* B7913C 80101F9C 10000086 */  b     .L801021B8
/* B79140 80101FA0 24020007 */   li    $v0, 7
.L80101FA4:
/* B79144 80101FA4 16000003 */  bnez  $s0, .L80101FB4
/* B79148 80101FA8 02602025 */   move  $a0, $s3
/* B7914C 80101FAC 10000082 */  b     .L801021B8
/* B79150 80101FB0 24020005 */   li    $v0, 5
.L80101FB4:
/* B79154 80101FB4 8FAB02B0 */  lw    $t3, 0x2b0($sp)
/* B79158 80101FB8 00002825 */  move  $a1, $zero
/* B7915C 80101FBC 00003025 */  move  $a2, $zero
/* B79160 80101FC0 00003825 */  move  $a3, $zero
/* B79164 80101FC4 AFA00010 */  sw    $zero, 0x10($sp)
/* B79168 80101FC8 0C040C04 */  jal   func_80103010
/* B7916C 80101FCC AFAB0014 */   sw    $t3, 0x14($sp)
/* B79170 80101FD0 10400005 */  beqz  $v0, .L80101FE8
/* B79174 80101FD4 24010005 */   li    $at, 5
/* B79178 80101FD8 50410004 */  beql  $v0, $at, .L80101FEC
/* B7917C 80101FDC 8FAC02B0 */   lw    $t4, 0x2b0($sp)
/* B79180 80101FE0 10000076 */  b     .L801021BC
/* B79184 80101FE4 8FBF0044 */   lw    $ra, 0x44($sp)
.L80101FE8:
/* B79188 80101FE8 8FAC02B0 */  lw    $t4, 0x2b0($sp)
.L80101FEC:
/* B7918C 80101FEC 2401FFFF */  li    $at, -1
/* B79190 80101FF0 8D8D0000 */  lw    $t5, ($t4)
/* B79194 80101FF4 55A10004 */  bnel  $t5, $at, .L80102008
/* B79198 80101FF8 926E0064 */   lbu   $t6, 0x64($s3)
/* B7919C 80101FFC 1000006E */  b     .L801021B8
/* B791A0 80102000 24020008 */   li    $v0, 8
/* B791A4 80102004 926E0064 */  lbu   $t6, 0x64($s3)
.L80102008:
/* B791A8 80102008 00008025 */  move  $s0, $zero
/* B791AC 8010200C 27B20180 */  addiu $s2, $sp, 0x180
/* B791B0 80102010 19C00049 */  blez  $t6, .L80102138
/* B791B4 80102014 27B10080 */   addiu $s1, $sp, 0x80
.L80102018:
/* B791B8 80102018 02602025 */  move  $a0, $s3
/* B791BC 8010201C 02402825 */  move  $a1, $s2
/* B791C0 80102020 00003025 */  move  $a2, $zero
/* B791C4 80102024 0C040B31 */  jal   func_80102CC4
/* B791C8 80102028 320700FF */   andi  $a3, $s0, 0xff
/* B791CC 8010202C 10400003 */  beqz  $v0, .L8010203C
/* B791D0 80102030 02602025 */   move  $a0, $s3
/* B791D4 80102034 10000061 */  b     .L801021BC
/* B791D8 80102038 8FBF0044 */   lw    $ra, 0x44($sp)
.L8010203C:
/* B791DC 8010203C 27AF0290 */  addiu $t7, $sp, 0x290
/* B791E0 80102040 27B8028C */  addiu $t8, $sp, 0x28c
/* B791E4 80102044 AFB80018 */  sw    $t8, 0x18($sp)
/* B791E8 80102048 AFAF0014 */  sw    $t7, 0x14($sp)
/* B791EC 8010204C 02402825 */  move  $a1, $s2
/* B791F0 80102050 02803025 */  move  $a2, $s4
/* B791F4 80102054 27A70294 */  addiu $a3, $sp, 0x294
/* B791F8 80102058 0C040879 */  jal   func_801021E4
/* B791FC 8010205C AFB00010 */   sw    $s0, 0x10($sp)
/* B79200 80102060 10400003 */  beqz  $v0, .L80102070
/* B79204 80102064 8FA30294 */   lw    $v1, 0x294($sp)
/* B79208 80102068 10000054 */  b     .L801021BC
/* B7920C 8010206C 8FBF0044 */   lw    $ra, 0x44($sp)
.L80102070:
/* B79210 80102070 2401FFFF */  li    $at, -1
/* B79214 80102074 5061002B */  beql  $v1, $at, .L80102124
/* B79218 80102078 926B0064 */   lbu   $t3, 0x64($s3)
/* B7921C 8010207C 16A00004 */  bnez  $s5, .L80102090
/* B79220 80102080 0016C840 */   sll   $t9, $s6, 1
/* B79224 80102084 A3A30051 */  sb    $v1, 0x51($sp)
/* B79228 80102088 1000000D */  b     .L801020C0
/* B7922C 8010208C A3B00050 */   sb    $s0, 0x50($sp)
.L80102090:
/* B79230 80102090 02391021 */  addu  $v0, $s1, $t9
/* B79234 80102094 A0500000 */  sb    $s0, ($v0)
/* B79238 80102098 A0430001 */  sb    $v1, 1($v0)
/* B7923C 8010209C 02602025 */  move  $a0, $s3
/* B79240 801020A0 02202825 */  move  $a1, $s1
/* B79244 801020A4 24060001 */  li    $a2, 1
/* B79248 801020A8 0C040B31 */  jal   func_80102CC4
/* B7924C 801020AC 32E700FF */   andi  $a3, $s7, 0xff
/* B79250 801020B0 50400004 */  beql  $v0, $zero, .L801020C4
/* B79254 801020B4 8FA80290 */   lw    $t0, 0x290($sp)
/* B79258 801020B8 10000040 */  b     .L801021BC
/* B7925C 801020BC 8FBF0044 */   lw    $ra, 0x44($sp)
.L801020C0:
/* B79260 801020C0 8FA80290 */  lw    $t0, 0x290($sp)
.L801020C4:
/* B79264 801020C4 02402025 */  move  $a0, $s2
/* B79268 801020C8 02202825 */  move  $a1, $s1
/* B7926C 801020CC 0114082A */  slt   $at, $t0, $s4
/* B79270 801020D0 5020000A */  beql  $at, $zero, .L801020FC
/* B79274 801020D4 0000A025 */   move  $s4, $zero
/* B79278 801020D8 0C001BC4 */  jal   bcopy
/* B7927C 801020DC 24060100 */   li    $a2, 256
/* B79280 801020E0 8FA90290 */  lw    $t1, 0x290($sp)
/* B79284 801020E4 8FB6028C */  lw    $s6, 0x28c($sp)
/* B79288 801020E8 321700FF */  andi  $s7, $s0, 0xff
/* B7928C 801020EC 26B50001 */  addiu $s5, $s5, 1
/* B79290 801020F0 1000000B */  b     .L80102120
/* B79294 801020F4 0289A023 */   subu  $s4, $s4, $t1
/* B79298 801020F8 0000A025 */  move  $s4, $zero
.L801020FC:
/* B7929C 801020FC 02602025 */  move  $a0, $s3
/* B792A0 80102100 02402825 */  move  $a1, $s2
/* B792A4 80102104 24060001 */  li    $a2, 1
/* B792A8 80102108 0C040B31 */  jal   func_80102CC4
/* B792AC 8010210C 320700FF */   andi  $a3, $s0, 0xff
/* B792B0 80102110 10400009 */  beqz  $v0, .L80102138
/* B792B4 80102114 00000000 */   nop   
/* B792B8 80102118 10000028 */  b     .L801021BC
/* B792BC 8010211C 8FBF0044 */   lw    $ra, 0x44($sp)
.L80102120:
/* B792C0 80102120 926B0064 */  lbu   $t3, 0x64($s3)
.L80102124:
/* B792C4 80102124 26100001 */  addiu $s0, $s0, 1
/* B792C8 80102128 320A00FF */  andi  $t2, $s0, 0xff
/* B792CC 8010212C 014B082A */  slt   $at, $t2, $t3
/* B792D0 80102130 1420FFB9 */  bnez  $at, .L80102018
/* B792D4 80102134 01408025 */   move  $s0, $t2
.L80102138:
/* B792D8 80102138 1E800004 */  bgtz  $s4, .L8010214C
/* B792DC 8010213C 8FA30294 */   lw    $v1, 0x294($sp)
/* B792E0 80102140 2401FFFF */  li    $at, -1
/* B792E4 80102144 14610003 */  bne   $v1, $at, .L80102154
/* B792E8 80102148 97AC0050 */   lhu   $t4, 0x50($sp)
.L8010214C:
/* B792EC 8010214C 1000001A */  b     .L801021B8
/* B792F0 80102150 24020003 */   li    $v0, 3
.L80102154:
/* B792F4 80102154 97AD029E */  lhu   $t5, 0x29e($sp)
/* B792F8 80102158 8FAE02A0 */  lw    $t6, 0x2a0($sp)
/* B792FC 8010215C A7AC0066 */  sh    $t4, 0x66($sp)
/* B79300 80102160 A7A0006A */  sh    $zero, 0x6a($sp)
/* B79304 80102164 8FA402A4 */  lw    $a0, 0x2a4($sp)
/* B79308 80102168 27A50070 */  addiu $a1, $sp, 0x70
/* B7930C 8010216C 24060010 */  li    $a2, 16
/* B79310 80102170 A7AD0064 */  sh    $t5, 0x64($sp)
/* B79314 80102174 0C001BC4 */  jal   bcopy
/* B79318 80102178 AFAE0060 */   sw    $t6, 0x60($sp)
/* B7931C 8010217C 8FA402A8 */  lw    $a0, 0x2a8($sp)
/* B79320 80102180 27A5006C */  addiu $a1, $sp, 0x6c
/* B79324 80102184 0C001BC4 */  jal   bcopy
/* B79328 80102188 24060004 */   li    $a2, 4
/* B7932C 8010218C 8FAF02B0 */  lw    $t7, 0x2b0($sp)
/* B79330 80102190 8E79005C */  lw    $t9, 0x5c($s3)
/* B79334 80102194 8E640004 */  lw    $a0, 4($s3)
/* B79338 80102198 8DF80000 */  lw    $t8, ($t7)
/* B7933C 8010219C 8E650008 */  lw    $a1, 8($s3)
/* B79340 801021A0 AFA00010 */  sw    $zero, 0x10($sp)
/* B79344 801021A4 03193021 */  addu  $a2, $t8, $t9
/* B79348 801021A8 30C8FFFF */  andi  $t0, $a2, 0xffff
/* B7934C 801021AC 01003025 */  move  $a2, $t0
/* B79350 801021B0 0C04173C */  jal   func_80105CF0
/* B79354 801021B4 27A70060 */   addiu $a3, $sp, 0x60
.L801021B8:
/* B79358 801021B8 8FBF0044 */  lw    $ra, 0x44($sp)
.L801021BC:
/* B7935C 801021BC 8FB00024 */  lw    $s0, 0x24($sp)
/* B79360 801021C0 8FB10028 */  lw    $s1, 0x28($sp)
/* B79364 801021C4 8FB2002C */  lw    $s2, 0x2c($sp)
/* B79368 801021C8 8FB30030 */  lw    $s3, 0x30($sp)
/* B7936C 801021CC 8FB40034 */  lw    $s4, 0x34($sp)
/* B79370 801021D0 8FB50038 */  lw    $s5, 0x38($sp)
/* B79374 801021D4 8FB6003C */  lw    $s6, 0x3c($sp)
/* B79378 801021D8 8FB70040 */  lw    $s7, 0x40($sp)
/* B7937C 801021DC 03E00008 */  jr    $ra
/* B79380 801021E0 27BD0298 */   addiu $sp, $sp, 0x298

glabel func_801021E4
/* B79384 801021E4 27BDFFF0 */  addiu $sp, $sp, -0x10
/* B79388 801021E8 AFB00008 */  sw    $s0, 8($sp)
/* B7938C 801021EC 93B00023 */  lbu   $s0, 0x23($sp)
/* B79390 801021F0 AFB1000C */  sw    $s1, 0xc($sp)
/* B79394 801021F4 00C08825 */  move  $s1, $a2
/* B79398 801021F8 1A000003 */  blez  $s0, .L80102208
/* B7939C 801021FC 240B0080 */   li    $t3, 128
/* B793A0 80102200 10000002 */  b     .L8010220C
/* B793A4 80102204 24020001 */   li    $v0, 1
.L80102208:
/* B793A8 80102208 8C820060 */  lw    $v0, 0x60($a0)
.L8010220C:
/* B793AC 8010220C 28410080 */  slti  $at, $v0, 0x80
/* B793B0 80102210 1020000A */  beqz  $at, .L8010223C
/* B793B4 80102214 00401825 */   move  $v1, $v0
/* B793B8 80102218 00027040 */  sll   $t6, $v0, 1
/* B793BC 8010221C 00AE1021 */  addu  $v0, $a1, $t6
/* B793C0 80102220 240A0003 */  li    $t2, 3
.L80102224:
/* B793C4 80102224 944F0000 */  lhu   $t7, ($v0)
/* B793C8 80102228 514F0005 */  beql  $t2, $t7, .L80102240
/* B793CC 8010222C 240B0080 */   li    $t3, 128
/* B793D0 80102230 24630001 */  addiu $v1, $v1, 1
/* B793D4 80102234 146BFFFB */  bne   $v1, $t3, .L80102224
/* B793D8 80102238 24420002 */   addiu $v0, $v0, 2
.L8010223C:
/* B793DC 8010223C 240B0080 */  li    $t3, 128
.L80102240:
/* B793E0 80102240 146B0005 */  bne   $v1, $t3, .L80102258
/* B793E4 80102244 240A0003 */   li    $t2, 3
/* B793E8 80102248 2418FFFF */  li    $t8, -1
/* B793EC 8010224C ACF80000 */  sw    $t8, ($a3)
/* B793F0 80102250 10000030 */  b     .L80102314
/* B793F4 80102254 00001025 */   move  $v0, $zero
.L80102258:
/* B793F8 80102258 8FA60024 */  lw    $a2, 0x24($sp)
/* B793FC 8010225C 00602025 */  move  $a0, $v1
/* B79400 80102260 24190001 */  li    $t9, 1
/* B79404 80102264 00604025 */  move  $t0, $v1
/* B79408 80102268 2A210002 */  slti  $at, $s1, 2
/* B7940C 8010226C 24630001 */  addiu $v1, $v1, 1
/* B79410 80102270 14200018 */  bnez  $at, .L801022D4
/* B79414 80102274 ACD90000 */   sw    $t9, ($a2)
/* B79418 80102278 28610080 */  slti  $at, $v1, 0x80
/* B7941C 8010227C 10200015 */  beqz  $at, .L801022D4
/* B79420 80102280 00036040 */   sll   $t4, $v1, 1
/* B79424 80102284 00AC1021 */  addu  $v0, $a1, $t4
/* B79428 80102288 944D0000 */  lhu   $t5, ($v0)
.L8010228C:
/* B7942C 8010228C 00087040 */  sll   $t6, $t0, 1
/* B79430 80102290 00AE4821 */  addu  $t1, $a1, $t6
/* B79434 80102294 554D0008 */  bnel  $t2, $t5, .L801022B8
/* B79438 80102298 8CD90000 */   lw    $t9, ($a2)
/* B7943C 8010229C A1300000 */  sb    $s0, ($t1)
/* B79440 801022A0 A1230001 */  sb    $v1, 1($t1)
/* B79444 801022A4 8CCF0000 */  lw    $t7, ($a2)
/* B79448 801022A8 00604025 */  move  $t0, $v1
/* B7944C 801022AC 25F80001 */  addiu $t8, $t7, 1
/* B79450 801022B0 ACD80000 */  sw    $t8, ($a2)
/* B79454 801022B4 8CD90000 */  lw    $t9, ($a2)
.L801022B8:
/* B79458 801022B8 24630001 */  addiu $v1, $v1, 1
/* B7945C 801022BC 24420002 */  addiu $v0, $v0, 2
/* B79460 801022C0 0331082A */  slt   $at, $t9, $s1
/* B79464 801022C4 10200003 */  beqz  $at, .L801022D4
/* B79468 801022C8 28610080 */   slti  $at, $v1, 0x80
/* B7946C 801022CC 5420FFEF */  bnezl $at, .L8010228C
/* B79470 801022D0 944D0000 */   lhu   $t5, ($v0)
.L801022D4:
/* B79474 801022D4 146B0008 */  bne   $v1, $t3, .L801022F8
/* B79478 801022D8 ACE40000 */   sw    $a0, ($a3)
/* B7947C 801022DC 8CCC0000 */  lw    $t4, ($a2)
/* B79480 801022E0 8FAD0028 */  lw    $t5, 0x28($sp)
/* B79484 801022E4 0191082A */  slt   $at, $t4, $s1
/* B79488 801022E8 50200004 */  beql  $at, $zero, .L801022FC
/* B7948C 801022EC 00087840 */   sll   $t7, $t0, 1
/* B79490 801022F0 10000007 */  b     .L80102310
/* B79494 801022F4 ADA80000 */   sw    $t0, ($t5)
.L801022F8:
/* B79498 801022F8 00087840 */  sll   $t7, $t0, 1
.L801022FC:
/* B7949C 801022FC 00AFC021 */  addu  $t8, $a1, $t7
/* B794A0 80102300 240E0001 */  li    $t6, 1
/* B794A4 80102304 A70E0000 */  sh    $t6, ($t8)
/* B794A8 80102308 8FB90028 */  lw    $t9, 0x28($sp)
/* B794AC 8010230C AF200000 */  sw    $zero, ($t9)
.L80102310:
/* B794B0 80102310 00001025 */  move  $v0, $zero
.L80102314:
/* B794B4 80102314 8FB00008 */  lw    $s0, 8($sp)
/* B794B8 80102318 8FB1000C */  lw    $s1, 0xc($sp)
/* B794BC 8010231C 03E00008 */  jr    $ra
/* B794C0 80102320 27BD0010 */   addiu $sp, $sp, 0x10
