glabel func_80AC8048
/* 053A8 80AC8048 27BDFFE8 */  addiu   $sp, $sp, 0xFFE8           ## $sp = FFFFFFE8
/* 053AC 80AC804C AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 053B0 80AC8050 AFA5001C */  sw      $a1, 0x001C($sp)           
/* 053B4 80AC8054 AFA60020 */  sw      $a2, 0x0020($sp)           
/* 053B8 80AC8058 AFA70024 */  sw      $a3, 0x0024($sp)           
/* 053BC 80AC805C 0C031A73 */  jal     Graph_Alloc
              
/* 053C0 80AC8060 24050010 */  addiu   $a1, $zero, 0x0010         ## $a1 = 00000010
/* 053C4 80AC8064 3C0EFB00 */  lui     $t6, 0xFB00                ## $t6 = FB000000
/* 053C8 80AC8068 AC4E0000 */  sw      $t6, 0x0000($v0)           ## 00000000
/* 053CC 80AC806C 93A90023 */  lbu     $t1, 0x0023($sp)           
/* 053D0 80AC8070 93B8001F */  lbu     $t8, 0x001F($sp)           
/* 053D4 80AC8074 93AD0027 */  lbu     $t5, 0x0027($sp)           
/* 053D8 80AC8078 93A8002B */  lbu     $t0, 0x002B($sp)           
/* 053DC 80AC807C 00095400 */  sll     $t2, $t1, 16               
/* 053E0 80AC8080 0018CE00 */  sll     $t9, $t8, 24               
/* 053E4 80AC8084 032A5825 */  or      $t3, $t9, $t2              ## $t3 = 00000000
/* 053E8 80AC8088 000D7200 */  sll     $t6, $t5,  8               
/* 053EC 80AC808C 016E7825 */  or      $t7, $t3, $t6              ## $t7 = FB000000
/* 053F0 80AC8090 3C19DF00 */  lui     $t9, 0xDF00                ## $t9 = DF000000
/* 053F4 80AC8094 01E84825 */  or      $t1, $t7, $t0              ## $t1 = FB000000
/* 053F8 80AC8098 AC490004 */  sw      $t1, 0x0004($v0)           ## 00000004
/* 053FC 80AC809C AC590008 */  sw      $t9, 0x0008($v0)           ## 00000008
/* 05400 80AC80A0 AC40000C */  sw      $zero, 0x000C($v0)         ## 0000000C
/* 05404 80AC80A4 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 05408 80AC80A8 27BD0018 */  addiu   $sp, $sp, 0x0018           ## $sp = 00000000
/* 0540C 80AC80AC 03E00008 */  jr      $ra                        
/* 05410 80AC80B0 00000000 */  nop
