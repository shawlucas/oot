glabel func_80837348
/* 05138 80837348 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 0513C 8083734C AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 05140 80837350 AFB30020 */  sw      $s3, 0x0020($sp)           
/* 05144 80837354 AFB2001C */  sw      $s2, 0x001C($sp)           
/* 05148 80837358 AFB10018 */  sw      $s1, 0x0018($sp)           
/* 0514C 8083735C AFB00014 */  sw      $s0, 0x0014($sp)           
/* 05150 80837360 8CAE067C */  lw      $t6, 0x067C($a1)           ## 0000067C
/* 05154 80837364 3C012000 */  lui     $at, 0x2000                ## $at = 20000000
/* 05158 80837368 34210081 */  ori     $at, $at, 0x0081           ## $at = 20000081
/* 0515C 8083736C 01C17824 */  and     $t7, $t6, $at              
/* 05160 80837370 00C08025 */  or      $s0, $a2, $zero            ## $s0 = 00000000
/* 05164 80837374 00A09025 */  or      $s2, $a1, $zero            ## $s2 = 00000000
/* 05168 80837378 15E00041 */  bne     $t7, $zero, .L80837480     
/* 0516C 8083737C 00809825 */  or      $s3, $a0, $zero            ## $s3 = 00000000
/* 05170 80837380 10E0000C */  beq     $a3, $zero, .L808373B4     
/* 05174 80837384 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 05178 80837388 0C20D99C */  jal     func_80836670              
/* 0517C 8083738C 02602825 */  or      $a1, $s3, $zero            ## $a1 = 00000000
/* 05180 80837390 3C018085 */  lui     $at, %hi(D_808535E0)       ## $at = 80850000
/* 05184 80837394 AC2235E0 */  sw      $v0, %lo(D_808535E0)($at)  
/* 05188 80837398 8E580674 */  lw      $t8, 0x0674($s2)           ## 00000674
/* 0518C 8083739C 3C198085 */  lui     $t9, %hi(func_8084E604)    ## $t9 = 80850000
/* 05190 808373A0 2739E604 */  addiu   $t9, $t9, %lo(func_8084E604) ## $t9 = 8084E604
/* 05194 808373A4 17190003 */  bne     $t8, $t9, .L808373B4       
/* 05198 808373A8 00000000 */  nop
/* 0519C 808373AC 10000035 */  beq     $zero, $zero, .L80837484   
/* 051A0 808373B0 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L808373B4:
/* 051A4 808373B4 0C023C4A */  jal     func_8008F128              
/* 051A8 808373B8 02402025 */  or      $a0, $s2, $zero            ## $a0 = 00000000
/* 051AC 808373BC 50400007 */  beql    $v0, $zero, .L808373DC     
/* 051B0 808373C0 8E4A067C */  lw      $t2, 0x067C($s2)           ## 0000067C
/* 051B4 808373C4 964806AE */  lhu     $t0, 0x06AE($s2)           ## 000006AE
/* 051B8 808373C8 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 051BC 808373CC 35090041 */  ori     $t1, $t0, 0x0041           ## $t1 = 00000041
/* 051C0 808373D0 1000002C */  beq     $zero, $zero, .L80837484   
/* 051C4 808373D4 A64906AE */  sh      $t1, 0x06AE($s2)           ## 000006AE
/* 051C8 808373D8 8E4A067C */  lw      $t2, 0x067C($s2)           ## 0000067C
.L808373DC:
/* 051CC 808373DC 314B0100 */  andi    $t3, $t2, 0x0100           ## $t3 = 00000000
/* 051D0 808373E0 55600028 */  bnel    $t3, $zero, .L80837484     
/* 051D4 808373E4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 051D8 808373E8 8E4C082C */  lw      $t4, 0x082C($s2)           ## 0000082C
/* 051DC 808373EC 3C0D8083 */  lui     $t5, %hi(func_80834A2C)    ## $t5 = 80830000
/* 051E0 808373F0 25AD4A2C */  addiu   $t5, $t5, %lo(func_80834A2C) ## $t5 = 80834A2C
/* 051E4 808373F4 518D0023 */  beql    $t4, $t5, .L80837484       
/* 051E8 808373F8 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 051EC 808373FC 82020000 */  lb      $v0, 0x0000($s0)           ## 00000000
/* 051F0 80837400 3C118085 */  lui     $s1, %hi(D_80854448)       ## $s1 = 80850000
/* 051F4 80837404 26314448 */  addiu   $s1, $s1, %lo(D_80854448)  ## $s1 = 80854448
/* 051F8 80837408 0440000F */  bltz    $v0, .L80837448            
/* 051FC 8083740C 00027080 */  sll     $t6, $v0,  2               
.L80837410:
/* 05200 80837410 022E7821 */  addu    $t7, $s1, $t6              
/* 05204 80837414 8DF90000 */  lw      $t9, 0x0000($t7)           ## 00000000
/* 05208 80837418 02402025 */  or      $a0, $s2, $zero            ## $a0 = 00000000
/* 0520C 8083741C 02602825 */  or      $a1, $s3, $zero            ## $a1 = 00000000
/* 05210 80837420 0320F809 */  jalr    $ra, $t9                   
/* 05214 80837424 00000000 */  nop
/* 05218 80837428 50400004 */  beql    $v0, $zero, .L8083743C     
/* 0521C 8083742C 82020001 */  lb      $v0, 0x0001($s0)           ## 00000001
/* 05220 80837430 10000014 */  beq     $zero, $zero, .L80837484   
/* 05224 80837434 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 05228 80837438 82020001 */  lb      $v0, 0x0001($s0)           ## 00000001
.L8083743C:
/* 0522C 8083743C 26100001 */  addiu   $s0, $s0, 0x0001           ## $s0 = 00000001
/* 05230 80837440 0443FFF3 */  bgezl   $v0, .L80837410            
/* 05234 80837444 00027080 */  sll     $t6, $v0,  2               
.L80837448:
/* 05238 80837448 3C118085 */  lui     $s1, %hi(D_80854448)       ## $s1 = 80850000
/* 0523C 8083744C 0002C023 */  subu    $t8, $zero, $v0            
/* 05240 80837450 26314448 */  addiu   $s1, $s1, %lo(D_80854448)  ## $s1 = 80854448
/* 05244 80837454 00184080 */  sll     $t0, $t8,  2               
/* 05248 80837458 02284821 */  addu    $t1, $s1, $t0              
/* 0524C 8083745C 8D390000 */  lw      $t9, 0x0000($t1)           ## 00000000
/* 05250 80837460 02402025 */  or      $a0, $s2, $zero            ## $a0 = 00000000
/* 05254 80837464 02602825 */  or      $a1, $s3, $zero            ## $a1 = 00000000
/* 05258 80837468 0320F809 */  jalr    $ra, $t9                   
/* 0525C 8083746C 00000000 */  nop
/* 05260 80837470 50400004 */  beql    $v0, $zero, .L80837484     
/* 05264 80837474 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 05268 80837478 10000002 */  beq     $zero, $zero, .L80837484   
/* 0526C 8083747C 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80837480:
/* 05270 80837480 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
.L80837484:
/* 05274 80837484 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 05278 80837488 8FB00014 */  lw      $s0, 0x0014($sp)           
/* 0527C 8083748C 8FB10018 */  lw      $s1, 0x0018($sp)           
/* 05280 80837490 8FB2001C */  lw      $s2, 0x001C($sp)           
/* 05284 80837494 8FB30020 */  lw      $s3, 0x0020($sp)           
/* 05288 80837498 03E00008 */  jr      $ra                        
/* 0528C 8083749C 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
