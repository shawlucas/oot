glabel func_80A89304
/* 004F4 80A89304 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 004F8 80A89308 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 004FC 80A8930C AFA40018 */  sw      $a0, 0x0018($sp)           
/* 00500 80A89310 0C2A23D9 */  jal     func_80A88F64              
/* 00504 80A89314 24066077 */  addiu   $a2, $zero, 0x6077         ## $a2 = 00006077
/* 00508 80A89318 50400004 */  beql    $v0, $zero, .L80A8932C     
/* 0050C 80A8931C 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 00510 80A89320 0C2A24A5 */  jal     func_80A89294              
/* 00514 80A89324 8FA40018 */  lw      $a0, 0x0018($sp)           
/* 00518 80A89328 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80A8932C:
/* 0051C 80A8932C 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 00520 80A89330 03E00008 */  jr      $ra                        
/* 00524 80A89334 00000000 */  nop
