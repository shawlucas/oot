.rdata

glabel D_809B2374
    .asciz "[32m☆☆☆☆☆ 火は幾つ？ ☆☆☆☆☆ %d\n[m"
    .balign 4

glabel D_809B23A4
    .asciz "[33m☆☆☆☆☆ 火は幾つ？ ☆☆☆☆☆ %x\n[m"
    .balign 4

.text
glabel func_809B142C
/* 0030C 809B142C 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 00310 809B1430 AFBF0034 */  sw      $ra, 0x0034($sp)           
/* 00314 809B1434 AFB60030 */  sw      $s6, 0x0030($sp)           
/* 00318 809B1438 AFB5002C */  sw      $s5, 0x002C($sp)           
/* 0031C 809B143C AFB40028 */  sw      $s4, 0x0028($sp)           
/* 00320 809B1440 AFB30024 */  sw      $s3, 0x0024($sp)           
/* 00324 809B1444 AFB20020 */  sw      $s2, 0x0020($sp)           
/* 00328 809B1448 AFB1001C */  sw      $s1, 0x001C($sp)           
/* 0032C 809B144C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00330 809B1450 848E025E */  lh      $t6, 0x025E($a0)           ## 0000025E
/* 00334 809B1454 0080B025 */  or      $s6, $a0, $zero            ## $s6 = 00000000
/* 00338 809B1458 51C00029 */  beql    $t6, $zero, .L809B1500     
/* 0033C 809B145C 8FBF0034 */  lw      $ra, 0x0034($sp)           
/* 00340 809B1460 848F0264 */  lh      $t7, 0x0264($a0)           ## 00000264
/* 00344 809B1464 55E00020 */  bnel    $t7, $zero, .L809B14E8     
/* 00348 809B1468 8EC90004 */  lw      $t1, 0x0004($s6)           ## 00000004
/* 0034C 809B146C 8CB01C64 */  lw      $s0, 0x1C64($a1)           ## 00001C64
/* 00350 809B1470 3C15809B */  lui     $s5, %hi(D_809B23A4)       ## $s5 = 809B0000
/* 00354 809B1474 00009025 */  or      $s2, $zero, $zero          ## $s2 = 00000000
/* 00358 809B1478 12000018 */  beq     $s0, $zero, .L809B14DC     
/* 0035C 809B147C 26B523A4 */  addiu   $s5, $s5, %lo(D_809B23A4)  ## $s5 = 809B23A4
/* 00360 809B1480 3C14809B */  lui     $s4, %hi(D_809B2374)       ## $s4 = 809B0000
/* 00364 809B1484 26942374 */  addiu   $s4, $s4, %lo(D_809B2374)  ## $s4 = 809B2374
/* 00368 809B1488 24130049 */  addiu   $s3, $zero, 0x0049         ## $s3 = 00000049
/* 0036C 809B148C 86180000 */  lh      $t8, 0x0000($s0)           ## 00000000
.L809B1490:
/* 00370 809B1490 0012C880 */  sll     $t9, $s2,  2               
/* 00374 809B1494 02D98821 */  addu    $s1, $s6, $t9              
/* 00378 809B1498 12780003 */  beq     $s3, $t8, .L809B14A8       
/* 0037C 809B149C 02802025 */  or      $a0, $s4, $zero            ## $a0 = 809B2374
/* 00380 809B14A0 1000000C */  beq     $zero, $zero, .L809B14D4   
/* 00384 809B14A4 8E100124 */  lw      $s0, 0x0124($s0)           ## 00000124
.L809B14A8:
/* 00388 809B14A8 AE3002B0 */  sw      $s0, 0x02B0($s1)           ## 000002B0
/* 0038C 809B14AC 0C00084C */  jal     osSyncPrintf
              
/* 00390 809B14B0 02402825 */  or      $a1, $s2, $zero            ## $a1 = 00000000
/* 00394 809B14B4 02A02025 */  or      $a0, $s5, $zero            ## $a0 = 809B23A4
/* 00398 809B14B8 0C00084C */  jal     osSyncPrintf
              
/* 0039C 809B14BC 8E2502B0 */  lw      $a1, 0x02B0($s1)           ## 000002B0
/* 003A0 809B14C0 2A410004 */  slti    $at, $s2, 0x0004           
/* 003A4 809B14C4 50200003 */  beql    $at, $zero, .L809B14D4     
/* 003A8 809B14C8 8E100124 */  lw      $s0, 0x0124($s0)           ## 00000124
/* 003AC 809B14CC 26520001 */  addiu   $s2, $s2, 0x0001           ## $s2 = 00000001
/* 003B0 809B14D0 8E100124 */  lw      $s0, 0x0124($s0)           ## 00000124
.L809B14D4:
/* 003B4 809B14D4 5600FFEE */  bnel    $s0, $zero, .L809B1490     
/* 003B8 809B14D8 86180000 */  lh      $t8, 0x0000($s0)           ## 00000000
.L809B14DC:
/* 003BC 809B14DC 24080001 */  addiu   $t0, $zero, 0x0001         ## $t0 = 00000001
/* 003C0 809B14E0 A6C80264 */  sh      $t0, 0x0264($s6)           ## 00000264
/* 003C4 809B14E4 8EC90004 */  lw      $t1, 0x0004($s6)           ## 00000004
.L809B14E8:
/* 003C8 809B14E8 3C0B809B */  lui     $t3, %hi(func_809B1524)    ## $t3 = 809B0000
/* 003CC 809B14EC 256B1524 */  addiu   $t3, $t3, %lo(func_809B1524) ## $t3 = 809B1524
/* 003D0 809B14F0 352A0001 */  ori     $t2, $t1, 0x0001           ## $t2 = 00000001
/* 003D4 809B14F4 AECA0004 */  sw      $t2, 0x0004($s6)           ## 00000004
/* 003D8 809B14F8 AECB0250 */  sw      $t3, 0x0250($s6)           ## 00000250
/* 003DC 809B14FC 8FBF0034 */  lw      $ra, 0x0034($sp)           
.L809B1500:
/* 003E0 809B1500 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 003E4 809B1504 8FB1001C */  lw      $s1, 0x001C($sp)           
/* 003E8 809B1508 8FB20020 */  lw      $s2, 0x0020($sp)           
/* 003EC 809B150C 8FB30024 */  lw      $s3, 0x0024($sp)           
/* 003F0 809B1510 8FB40028 */  lw      $s4, 0x0028($sp)           
/* 003F4 809B1514 8FB5002C */  lw      $s5, 0x002C($sp)           
/* 003F8 809B1518 8FB60030 */  lw      $s6, 0x0030($sp)           
/* 003FC 809B151C 03E00008 */  jr      $ra                        
/* 00400 809B1520 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000


