glabel func_8083CB2C
/* 0A91C 8083CB2C 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 0A920 8083CB30 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 0A924 8083CB34 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0A928 8083CB38 AFA60028 */  sw      $a2, 0x0028($sp)           
/* 0A92C 8083CB3C 00C02025 */  or      $a0, $a2, $zero            ## $a0 = 00000000
/* 0A930 8083CB40 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0A934 8083CB44 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 0A938 8083CB48 3C068084 */  lui     $a2, %hi(func_808414F8)    ## $a2 = 80840000
/* 0A93C 8083CB4C 24C614F8 */  addiu   $a2, $a2, %lo(func_808414F8) ## $a2 = 808414F8
/* 0A940 8083CB50 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 0A944 8083CB54 0C20D716 */  jal     func_80835C58              
/* 0A948 8083CB58 24070001 */  addiu   $a3, $zero, 0x0001         ## $a3 = 00000001
/* 0A94C 8083CB5C 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 0A950 8083CB60 0C02907F */  jal     func_800A41FC              
/* 0A954 8083CB64 260501B4 */  addiu   $a1, $s0, 0x01B4           ## $a1 = 000001B4
/* 0A958 8083CB68 44800000 */  mtc1    $zero, $f0                 ## $f0 = 0.00
/* 0A95C 8083CB6C 00000000 */  nop
/* 0A960 8083CB70 E6000868 */  swc1    $f0, 0x0868($s0)           ## 00000868
/* 0A964 8083CB74 E6000864 */  swc1    $f0, 0x0864($s0)           ## 00000864
/* 0A968 8083CB78 87AE0026 */  lh      $t6, 0x0026($sp)           
/* 0A96C 8083CB7C A60E083C */  sh      $t6, 0x083C($s0)           ## 0000083C
/* 0A970 8083CB80 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 0A974 8083CB84 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 0A978 8083CB88 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 0A97C 8083CB8C 03E00008 */  jr      $ra                        
/* 0A980 8083CB90 00000000 */  nop
