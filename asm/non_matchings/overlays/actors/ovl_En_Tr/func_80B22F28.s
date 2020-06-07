glabel func_80B22F28
/* 00238 80B22F28 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 0023C 80B22F2C AFBF003C */  sw      $ra, 0x003C($sp)
/* 00240 80B22F30 AFB10038 */  sw      $s1, 0x0038($sp)
/* 00244 80B22F34 AFB00034 */  sw      $s0, 0x0034($sp)
/* 00248 80B22F38 90AE1D6C */  lbu     $t6, 0x1D6C($a1)           ## 00001D6C
/* 0024C 80B22F3C 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00250 80B22F40 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 00254 80B22F44 51C00060 */  beql    $t6, $zero, .L80B230C8
/* 00258 80B22F48 8FBF003C */  lw      $ra, 0x003C($sp)
/* 0025C 80B22F4C 848602D8 */  lh      $a2, 0x02D8($a0)           ## 000002D8
/* 00260 80B22F50 00067880 */  sll     $t7, $a2,  2
/* 00264 80B22F54 00AFC021 */  addu    $t8, $a1, $t7
/* 00268 80B22F58 8F021D8C */  lw      $v0, 0x1D8C($t8)           ## 00001D8C
/* 0026C 80B22F5C 5040005A */  beql    $v0, $zero, .L80B230C8
/* 00270 80B22F60 8FBF003C */  lw      $ra, 0x003C($sp)
/* 00274 80B22F64 94430000 */  lhu     $v1, 0x0000($v0)           ## 00000000
/* 00278 80B22F68 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 0027C 80B22F6C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00280 80B22F70 10610006 */  beq     $v1, $at, .L80B22F8C
/* 00284 80B22F74 3C053C23 */  lui     $a1, 0x3C23                ## $a1 = 3C230000
/* 00288 80B22F78 24010006 */  addiu   $at, $zero, 0x0006         ## $at = 00000006
/* 0028C 80B22F7C 10610010 */  beq     $v1, $at, .L80B22FC0
/* 00290 80B22F80 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00294 80B22F84 10000046 */  beq     $zero, $zero, .L80B230A0
/* 00298 80B22F88 00000000 */  nop
.L80B22F8C:
/* 0029C 80B22F8C 0C00B58B */  jal     Actor_SetScale

/* 002A0 80B22F90 34A5D70A */  ori     $a1, $a1, 0xD70A           ## $a1 = 3C23D70A
/* 002A4 80B22F94 3C0580B2 */  lui     $a1, %hi(func_80B234D4)    ## $a1 = 80B20000
/* 002A8 80B22F98 24A534D4 */  addiu   $a1, $a1, %lo(func_80B234D4) ## $a1 = 80B234D4
/* 002AC 80B22F9C 0C2C8B3C */  jal     func_80B22CF0
/* 002B0 80B22FA0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 002B4 80B22FA4 24190018 */  addiu   $t9, $zero, 0x0018         ## $t9 = 00000018
/* 002B8 80B22FA8 A61902D6 */  sh      $t9, 0x02D6($s0)           ## 000002D6
/* 002BC 80B22FAC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 002C0 80B22FB0 0C00BE0A */  jal     Audio_PlayActorSound2

/* 002C4 80B22FB4 24053877 */  addiu   $a1, $zero, 0x3877         ## $a1 = 00003877
/* 002C8 80B22FB8 10000040 */  beq     $zero, $zero, .L80B230BC
/* 002CC 80B22FBC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B22FC0:
/* 002D0 80B22FC0 8608001C */  lh      $t0, 0x001C($s0)           ## 0000001C
/* 002D4 80B22FC4 3C0480B2 */  lui     $a0, %hi(D_80B24380)       ## $a0 = 80B20000
/* 002D8 80B22FC8 00084880 */  sll     $t1, $t0,  2
/* 002DC 80B22FCC 00892021 */  addu    $a0, $a0, $t1
/* 002E0 80B22FD0 0C028800 */  jal     SkelAnime_GetFrameCount

/* 002E4 80B22FD4 8C844380 */  lw      $a0, %lo(D_80B24380)($a0)
/* 002E8 80B22FD8 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 002EC 80B22FDC 860A001C */  lh      $t2, 0x001C($s0)           ## 0000001C
/* 002F0 80B22FE0 3C01C0A0 */  lui     $at, 0xC0A0                ## $at = C0A00000
/* 002F4 80B22FE4 468021A0 */  cvt.s.w $f6, $f4
/* 002F8 80B22FE8 44814000 */  mtc1    $at, $f8                   ## $f8 = -5.00
/* 002FC 80B22FEC 3C0580B2 */  lui     $a1, %hi(D_80B24380)       ## $a1 = 80B20000
/* 00300 80B22FF0 000A5880 */  sll     $t3, $t2,  2
/* 00304 80B22FF4 00AB2821 */  addu    $a1, $a1, $t3
/* 00308 80B22FF8 240C0002 */  addiu   $t4, $zero, 0x0002         ## $t4 = 00000002
/* 0030C 80B22FFC AFAC0014 */  sw      $t4, 0x0014($sp)
/* 00310 80B23000 8CA54380 */  lw      $a1, %lo(D_80B24380)($a1)
/* 00314 80B23004 E7A60010 */  swc1    $f6, 0x0010($sp)
/* 00318 80B23008 2604014C */  addiu   $a0, $s0, 0x014C           ## $a0 = 0000014C
/* 0031C 80B2300C 3C063F80 */  lui     $a2, 0x3F80                ## $a2 = 3F800000
/* 00320 80B23010 24070000 */  addiu   $a3, $zero, 0x0000         ## $a3 = 00000000
/* 00324 80B23014 0C029468 */  jal     SkelAnime_ChangeAnim

/* 00328 80B23018 E7A80018 */  swc1    $f8, 0x0018($sp)
/* 0032C 80B2301C 3C0580B2 */  lui     $a1, %hi(func_80B22E6C)    ## $a1 = 80B20000
/* 00330 80B23020 24A52E6C */  addiu   $a1, $a1, %lo(func_80B22E6C) ## $a1 = 80B22E6C
/* 00334 80B23024 0C2C8B3C */  jal     func_80B22CF0
/* 00338 80B23028 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0033C 80B2302C 8602001C */  lh      $v0, 0x001C($s0)           ## 0000001C
/* 00340 80B23030 3C0E80B2 */  lui     $t6, %hi(D_80B24378)       ## $t6 = 80B20000
/* 00344 80B23034 C60A0024 */  lwc1    $f10, 0x0024($s0)          ## 00000024
/* 00348 80B23038 00026880 */  sll     $t5, $v0,  2
/* 0034C 80B2303C 01CD7021 */  addu    $t6, $t6, $t5
/* 00350 80B23040 8DCE4378 */  lw      $t6, %lo(D_80B24378)($t6)
/* 00354 80B23044 240F0027 */  addiu   $t7, $zero, 0x0027         ## $t7 = 00000027
/* 00358 80B23048 A60F02D6 */  sh      $t7, 0x02D6($s0)           ## 000002D6
/* 0035C 80B2304C AE0E02E4 */  sw      $t6, 0x02E4($s0)           ## 000002E4
/* 00360 80B23050 E7AA0010 */  swc1    $f10, 0x0010($sp)
/* 00364 80B23054 C6100028 */  lwc1    $f16, 0x0028($s0)          ## 00000028
/* 00368 80B23058 24580009 */  addiu   $t8, $v0, 0x0009           ## $t8 = 00000009
/* 0036C 80B2305C 26241C24 */  addiu   $a0, $s1, 0x1C24           ## $a0 = 00001C24
/* 00370 80B23060 E7B00014 */  swc1    $f16, 0x0014($sp)
/* 00374 80B23064 C612002C */  lwc1    $f18, 0x002C($s0)          ## 0000002C
/* 00378 80B23068 AFB80028 */  sw      $t8, 0x0028($sp)
/* 0037C 80B2306C AFA00024 */  sw      $zero, 0x0024($sp)
/* 00380 80B23070 AFA00020 */  sw      $zero, 0x0020($sp)
/* 00384 80B23074 AFA0001C */  sw      $zero, 0x001C($sp)
/* 00388 80B23078 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 0038C 80B2307C 02203025 */  or      $a2, $s1, $zero            ## $a2 = 00000000
/* 00390 80B23080 240700F5 */  addiu   $a3, $zero, 0x00F5         ## $a3 = 000000F5
/* 00394 80B23084 0C00C916 */  jal     Actor_SpawnAttached

/* 00398 80B23088 E7B20018 */  swc1    $f18, 0x0018($sp)
/* 0039C 80B2308C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 003A0 80B23090 0C00BE0A */  jal     Audio_PlayActorSound2

/* 003A4 80B23094 240538A5 */  addiu   $a1, $zero, 0x38A5         ## $a1 = 000038A5
/* 003A8 80B23098 10000008 */  beq     $zero, $zero, .L80B230BC
/* 003AC 80B2309C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B230A0:
/* 003B0 80B230A0 0C2C900E */  jal     func_80B24038
/* 003B4 80B230A4 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 003B8 80B230A8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 003BC 80B230AC 02202825 */  or      $a1, $s1, $zero            ## $a1 = 00000000
/* 003C0 80B230B0 0C2C908C */  jal     func_80B24230
/* 003C4 80B230B4 860602D8 */  lh      $a2, 0x02D8($s0)           ## 000002D8
/* 003C8 80B230B8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80B230BC:
/* 003CC 80B230BC 0C00BE5D */  jal     func_8002F974
/* 003D0 80B230C0 2405317B */  addiu   $a1, $zero, 0x317B         ## $a1 = 0000317B
/* 003D4 80B230C4 8FBF003C */  lw      $ra, 0x003C($sp)
.L80B230C8:
/* 003D8 80B230C8 8FB00034 */  lw      $s0, 0x0034($sp)
/* 003DC 80B230CC 8FB10038 */  lw      $s1, 0x0038($sp)
/* 003E0 80B230D0 03E00008 */  jr      $ra
/* 003E4 80B230D4 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
