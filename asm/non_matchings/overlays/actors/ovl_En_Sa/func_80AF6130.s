glabel func_80AF6130
/* 00BD0 80AF6130 8C8E000C */  lw      $t6, 0x000C($a0)           ## 0000000C
/* 00BD4 80AF6134 448E2000 */  mtc1    $t6, $f4                   ## $f4 = 0.00
/* 00BD8 80AF6138 00000000 */  nop
/* 00BDC 80AF613C 468021A0 */  cvt.s.w $f6, $f4                   
/* 00BE0 80AF6140 E4A60000 */  swc1    $f6, 0x0000($a1)           ## 00000000
/* 00BE4 80AF6144 8C8F0010 */  lw      $t7, 0x0010($a0)           ## 00000010
/* 00BE8 80AF6148 448F4000 */  mtc1    $t7, $f8                   ## $f8 = 0.00
/* 00BEC 80AF614C 00000000 */  nop
/* 00BF0 80AF6150 468042A0 */  cvt.s.w $f10, $f8                  
/* 00BF4 80AF6154 E4AA0004 */  swc1    $f10, 0x0004($a1)          ## 00000004
/* 00BF8 80AF6158 8C980014 */  lw      $t8, 0x0014($a0)           ## 00000014
/* 00BFC 80AF615C 44988000 */  mtc1    $t8, $f16                  ## $f16 = 0.00
/* 00C00 80AF6160 00000000 */  nop
/* 00C04 80AF6164 468084A0 */  cvt.s.w $f18, $f16                 
/* 00C08 80AF6168 03E00008 */  jr      $ra                        
/* 00C0C 80AF616C E4B20008 */  swc1    $f18, 0x0008($a1)          ## 00000008
