.rdata
glabel D_808B4678
    .asciz "(spot15 ロンロン木箱)(arg_data 0x%04x)\n"
    .balign 4

.text
glabel BgSpot15Rrbox_Init
/* 00234 808B3B94 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 00238 808B3B98 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 0023C 808B3B9C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00240 808B3BA0 3C060600 */  lui     $a2, 0x0600                ## $a2 = 06000000
/* 00244 808B3BA4 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00248 808B3BA8 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 0024C 808B3BAC 24C60348 */  addiu   $a2, $a2, 0x0348           ## $a2 = 06000348
/* 00250 808B3BB0 0C22CE58 */  jal     func_808B3960              
/* 00254 808B3BB4 00003825 */  or      $a3, $zero, $zero          ## $a3 = 00000000
/* 00258 808B3BB8 3C05808B */  lui     $a1, %hi(D_808B45B4)       ## $a1 = 808B0000
/* 0025C 808B3BBC 24A545B4 */  addiu   $a1, $a1, %lo(D_808B45B4)  ## $a1 = 808B45B4
/* 00260 808B3BC0 0C01E037 */  jal     Actor_ProcessInitChain
              
/* 00264 808B3BC4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00268 808B3BC8 0C22CE8D */  jal     func_808B3A34              
/* 0026C 808B3BCC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00270 808B3BD0 8605001C */  lh      $a1, 0x001C($s0)           ## 0000001C
/* 00274 808B3BD4 8FA40024 */  lw      $a0, 0x0024($sp)           
/* 00278 808B3BD8 0C00B2D0 */  jal     Flags_GetSwitch
              
/* 0027C 808B3BDC 30A5003F */  andi    $a1, $a1, 0x003F           ## $a1 = 00000000
/* 00280 808B3BE0 10400016 */  beq     $v0, $zero, .L808B3C3C     
/* 00284 808B3BE4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00288 808B3BE8 0C22D12E */  jal     func_808B44B8              
/* 0028C 808B3BEC 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 00290 808B3BF0 3C02808B */  lui     $v0, %hi(D_808B4590)       ## $v0 = 808B0000
/* 00294 808B3BF4 24424590 */  addiu   $v0, $v0, %lo(D_808B4590)  ## $v0 = 808B4590
/* 00298 808B3BF8 844E0000 */  lh      $t6, 0x0000($v0)           ## 808B4590
/* 0029C 808B3BFC 3C18808B */  lui     $t8, %hi(D_808B45C4)       ## $t8 = 808B0000
/* 002A0 808B3C00 271845C4 */  addiu   $t8, $t8, %lo(D_808B45C4)  ## $t8 = 808B45C4
/* 002A4 808B3C04 000E7880 */  sll     $t7, $t6,  2               
/* 002A8 808B3C08 01EE7823 */  subu    $t7, $t7, $t6              
/* 002AC 808B3C0C 000F7880 */  sll     $t7, $t7,  2               
/* 002B0 808B3C10 01F8C821 */  addu    $t9, $t7, $t8              
/* 002B4 808B3C14 8F290000 */  lw      $t1, 0x0000($t9)           ## 00000000
/* 002B8 808B3C18 AE090024 */  sw      $t1, 0x0024($s0)           ## 00000024
/* 002BC 808B3C1C 8F280004 */  lw      $t0, 0x0004($t9)           ## 00000004
/* 002C0 808B3C20 AE080028 */  sw      $t0, 0x0028($s0)           ## 00000028
/* 002C4 808B3C24 8F290008 */  lw      $t1, 0x0008($t9)           ## 00000008
/* 002C8 808B3C28 AE09002C */  sw      $t1, 0x002C($s0)           ## 0000002C
/* 002CC 808B3C2C 844A0000 */  lh      $t2, 0x0000($v0)           ## 808B4590
/* 002D0 808B3C30 254B0001 */  addiu   $t3, $t2, 0x0001           ## $t3 = 00000001
/* 002D4 808B3C34 10000004 */  beq     $zero, $zero, .L808B3C48   
/* 002D8 808B3C38 A44B0000 */  sh      $t3, 0x0000($v0)           ## 808B4590
.L808B3C3C:
/* 002DC 808B3C3C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 002E0 808B3C40 0C22D021 */  jal     func_808B4084              
/* 002E4 808B3C44 8FA50024 */  lw      $a1, 0x0024($sp)           
.L808B3C48:
/* 002E8 808B3C48 3C04808B */  lui     $a0, %hi(D_808B4678)       ## $a0 = 808B0000
/* 002EC 808B3C4C 24844678 */  addiu   $a0, $a0, %lo(D_808B4678)  ## $a0 = 808B4678
/* 002F0 808B3C50 0C00084C */  jal     osSyncPrintf
              
/* 002F4 808B3C54 8605001C */  lh      $a1, 0x001C($s0)           ## 0000001C
/* 002F8 808B3C58 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 002FC 808B3C5C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00300 808B3C60 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 00304 808B3C64 03E00008 */  jr      $ra                        
/* 00308 808B3C68 00000000 */  nop
