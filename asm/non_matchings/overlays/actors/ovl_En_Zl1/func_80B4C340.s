glabel func_80B4C340
/* 01800 80B4C340 24010004 */  addiu   $at, $zero, 0x0004         ## $at = 00000004
/* 01804 80B4C344 AFA40000 */  sw      $a0, 0x0000($sp)           
/* 01808 80B4C348 10A10008 */  beq     $a1, $at, .L80B4C36C       
/* 0180C 80B4C34C AFA7000C */  sw      $a3, 0x000C($sp)           
/* 01810 80B4C350 24010003 */  addiu   $at, $zero, 0x0003         ## $at = 00000003
/* 01814 80B4C354 10A10005 */  beq     $a1, $at, .L80B4C36C       
/* 01818 80B4C358 24010006 */  addiu   $at, $zero, 0x0006         ## $at = 00000006
/* 0181C 80B4C35C 10A10003 */  beq     $a1, $at, .L80B4C36C       
/* 01820 80B4C360 24010005 */  addiu   $at, $zero, 0x0005         ## $at = 00000005
/* 01824 80B4C364 54A10003 */  bnel    $a1, $at, .L80B4C374       
/* 01828 80B4C368 2401000A */  addiu   $at, $zero, 0x000A         ## $at = 0000000A
.L80B4C36C:
/* 0182C 80B4C36C ACC00000 */  sw      $zero, 0x0000($a2)         ## 00000000
/* 01830 80B4C370 2401000A */  addiu   $at, $zero, 0x000A         ## $at = 0000000A
.L80B4C374:
/* 01834 80B4C374 10A10013 */  beq     $a1, $at, .L80B4C3C4       
/* 01838 80B4C378 8FA20014 */  lw      $v0, 0x0014($sp)           
/* 0183C 80B4C37C 24010011 */  addiu   $at, $zero, 0x0011         ## $at = 00000011
/* 01840 80B4C380 14A1001D */  bne     $a1, $at, .L80B4C3F8       
/* 01844 80B4C384 8FA20014 */  lw      $v0, 0x0014($sp)           
/* 01848 80B4C388 8FA30010 */  lw      $v1, 0x0010($sp)           
/* 0184C 80B4C38C 844F0202 */  lh      $t7, 0x0202($v0)           ## 00000202
/* 01850 80B4C390 846E0000 */  lh      $t6, 0x0000($v1)           ## 00000000
/* 01854 80B4C394 84790002 */  lh      $t9, 0x0002($v1)           ## 00000002
/* 01858 80B4C398 846A0004 */  lh      $t2, 0x0004($v1)           ## 00000004
/* 0185C 80B4C39C 01CFC021 */  addu    $t8, $t6, $t7              
/* 01860 80B4C3A0 A4780000 */  sh      $t8, 0x0000($v1)           ## 00000000
/* 01864 80B4C3A4 84480204 */  lh      $t0, 0x0204($v0)           ## 00000204
/* 01868 80B4C3A8 03284821 */  addu    $t1, $t9, $t0              
/* 0186C 80B4C3AC A4690002 */  sh      $t1, 0x0002($v1)           ## 00000002
/* 01870 80B4C3B0 844B0200 */  lh      $t3, 0x0200($v0)           ## 00000200
/* 01874 80B4C3B4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 01878 80B4C3B8 014B6021 */  addu    $t4, $t2, $t3              
/* 0187C 80B4C3BC 03E00008 */  jr      $ra                        
/* 01880 80B4C3C0 A46C0004 */  sh      $t4, 0x0004($v1)           ## 00000004
.L80B4C3C4:
/* 01884 80B4C3C4 8FA30010 */  lw      $v1, 0x0010($sp)           
/* 01888 80B4C3C8 844E0208 */  lh      $t6, 0x0208($v0)           ## 00000208
/* 0188C 80B4C3CC 846D0000 */  lh      $t5, 0x0000($v1)           ## 00000000
/* 01890 80B4C3D0 84780002 */  lh      $t8, 0x0002($v1)           ## 00000002
/* 01894 80B4C3D4 84690004 */  lh      $t1, 0x0004($v1)           ## 00000004
/* 01898 80B4C3D8 01AE7821 */  addu    $t7, $t5, $t6              
/* 0189C 80B4C3DC A46F0000 */  sh      $t7, 0x0000($v1)           ## 00000000
/* 018A0 80B4C3E0 84590206 */  lh      $t9, 0x0206($v0)           ## 00000206
/* 018A4 80B4C3E4 03194021 */  addu    $t0, $t8, $t9              
/* 018A8 80B4C3E8 A4680002 */  sh      $t0, 0x0002($v1)           ## 00000002
/* 018AC 80B4C3EC 844A020A */  lh      $t2, 0x020A($v0)           ## 0000020A
/* 018B0 80B4C3F0 012A5821 */  addu    $t3, $t1, $t2              
/* 018B4 80B4C3F4 A46B0004 */  sh      $t3, 0x0004($v1)           ## 00000004
.L80B4C3F8:
/* 018B8 80B4C3F8 03E00008 */  jr      $ra                        
/* 018BC 80B4C3FC 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
