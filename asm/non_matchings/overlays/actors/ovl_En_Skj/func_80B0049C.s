glabel func_80B0049C
/* 021EC 80B0049C 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 021F0 80B004A0 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 021F4 80B004A4 AFA40020 */  sw      $a0, 0x0020($sp)           
/* 021F8 80B004A8 24A420D8 */  addiu   $a0, $a1, 0x20D8           ## $a0 = 000020D8
/* 021FC 80B004AC 0C042F6F */  jal     func_8010BDBC              
/* 02200 80B004B0 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 02204 80B004B4 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 02208 80B004B8 24010006 */  addiu   $at, $zero, 0x0006         ## $at = 00000006
/* 0220C 80B004BC 14410011 */  bne     $v0, $at, .L80B00504       
/* 02210 80B004C0 8CA31C44 */  lw      $v1, 0x1C44($a1)           ## 00001C44
/* 02214 80B004C4 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 02218 80B004C8 0C041AF2 */  jal     func_80106BC8              
/* 0221C 80B004CC AFA30018 */  sw      $v1, 0x0018($sp)           
/* 02220 80B004D0 1040000C */  beq     $v0, $zero, .L80B00504     
/* 02224 80B004D4 8FA30018 */  lw      $v1, 0x0018($sp)           
/* 02228 80B004D8 8FA40020 */  lw      $a0, 0x0020($sp)           
/* 0222C 80B004DC 0C2BFDE8 */  jal     func_80AFF7A0              
/* 02230 80B004E0 AFA30018 */  sw      $v1, 0x0018($sp)           
/* 02234 80B004E4 8FA30018 */  lw      $v1, 0x0018($sp)           
/* 02238 80B004E8 3C010080 */  lui     $at, 0x0080                ## $at = 00800000
/* 0223C 80B004EC 3C1880B0 */  lui     $t8, %hi(D_80B01644)       ## $t8 = 80B00000
/* 02240 80B004F0 8C6E0680 */  lw      $t6, 0x0680($v1)           ## 00000680
/* 02244 80B004F4 01C17825 */  or      $t7, $t6, $at              ## $t7 = 00800000
/* 02248 80B004F8 AC6F0680 */  sw      $t7, 0x0680($v1)           ## 00000680
/* 0224C 80B004FC 8F181644 */  lw      $t8, %lo(D_80B01644)($t8)  
/* 02250 80B00500 AC7806A8 */  sw      $t8, 0x06A8($v1)           ## 000006A8
.L80B00504:
/* 02254 80B00504 8FBF0014 */  lw      $ra, 0x0014($sp)           
/* 02258 80B00508 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 0225C 80B0050C 03E00008 */  jr      $ra                        
/* 02260 80B00510 00000000 */  nop
