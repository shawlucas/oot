glabel func_80A97378
/* 005C8 80A97378 3C028016 */  lui     $v0, 0x8016                ## $v0 = 80160000
/* 005CC 80A9737C 2442E660 */  addiu   $v0, $v0, 0xE660           ## $v0 = 8015E660
/* 005D0 80A97380 3C198012 */  lui     $t9, 0x8012                ## $t9 = 80120000
/* 005D4 80A97384 8F397120 */  lw      $t9, 0x7120($t9)           ## 80127120
/* 005D8 80A97388 8C4800A4 */  lw      $t0, 0x00A4($v0)           ## 8015E704
/* 005DC 80A9738C 03284824 */  and     $t1, $t9, $t0              
/* 005E0 80A97390 51200004 */  beql    $t1, $zero, .L80A973A4     
/* 005E4 80A97394 944A0F00 */  lhu     $t2, 0x0F00($v0)           ## 8015F560
/* 005E8 80A97398 03E00008 */  jr      $ra                        
/* 005EC 80A9739C 24021072 */  addiu   $v0, $zero, 0x1072         ## $v0 = 00001072
.L80A973A0:
/* 005F0 80A973A0 944A0F00 */  lhu     $t2, 0x0F00($v0)           ## 00001F72
.L80A973A4:
/* 005F4 80A973A4 314B0002 */  andi    $t3, $t2, 0x0002           ## $t3 = 00000000
/* 005F8 80A973A8 11600003 */  beq     $t3, $zero, .L80A973B8     
/* 005FC 80A973AC 00000000 */  nop
/* 00600 80A973B0 03E00008 */  jr      $ra                        
/* 00604 80A973B4 24021056 */  addiu   $v0, $zero, 0x1056         ## $v0 = 00001056
.L80A973B8:
/* 00608 80A973B8 03E00008 */  jr      $ra                        
/* 0060C 80A973BC 24021055 */  addiu   $v0, $zero, 0x1055         ## $v0 = 00001055
