.late_rodata
glabel D_80B37B88
    .float 0.8

.text
glabel func_80B34D48
/* 01098 80B34D48 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 0109C 80B34D4C AFB00018 */  sw      $s0, 0x0018($sp)           
/* 010A0 80B34D50 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 010A4 80B34D54 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 010A8 80B34D58 AFA50024 */  sw      $a1, 0x0024($sp)           
/* 010AC 80B34D5C 00A02025 */  or      $a0, $a1, $zero            ## $a0 = 00000000
/* 010B0 80B34D60 0C2CDE0C */  jal     func_80B37830              
/* 010B4 80B34D64 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 010B8 80B34D68 1440006A */  bne     $v0, $zero, .L80B34F14     
/* 010BC 80B34D6C 8FA40024 */  lw      $a0, 0x0024($sp)           
/* 010C0 80B34D70 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 010C4 80B34D74 0C2CCFEC */  jal     func_80B33FB0              
/* 010C8 80B34D78 00003025 */  or      $a2, $zero, $zero          ## $a2 = 00000000
/* 010CC 80B34D7C 54400066 */  bnel    $v0, $zero, .L80B34F18     
/* 010D0 80B34D80 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 010D4 80B34D84 860400B6 */  lh      $a0, 0x00B6($s0)           ## 000000B6
/* 010D8 80B34D88 860E008A */  lh      $t6, 0x008A($s0)           ## 0000008A
/* 010DC 80B34D8C 01C41023 */  subu    $v0, $t6, $a0              
/* 010E0 80B34D90 00021400 */  sll     $v0, $v0, 16               
/* 010E4 80B34D94 00021403 */  sra     $v0, $v0, 16               
/* 010E8 80B34D98 58400010 */  blezl   $v0, .L80B34DDC            
/* 010EC 80B34D9C 44823000 */  mtc1    $v0, $f6                   ## $f6 = 0.00
/* 010F0 80B34DA0 44822000 */  mtc1    $v0, $f4                   ## $f4 = 0.00
/* 010F4 80B34DA4 3C013E80 */  lui     $at, 0x3E80                ## $at = 3E800000
/* 010F8 80B34DA8 44814000 */  mtc1    $at, $f8                   ## $f8 = 0.25
/* 010FC 80B34DAC 468021A0 */  cvt.s.w $f6, $f4                   
/* 01100 80B34DB0 3C0144FA */  lui     $at, 0x44FA                ## $at = 44FA0000
/* 01104 80B34DB4 44818000 */  mtc1    $at, $f16                  ## $f16 = 2000.00
/* 01108 80B34DB8 46083282 */  mul.s   $f10, $f6, $f8             
/* 0110C 80B34DBC 46105480 */  add.s   $f18, $f10, $f16           
/* 01110 80B34DC0 4600910D */  trunc.w.s $f4, $f18                  
/* 01114 80B34DC4 44032000 */  mfc1    $v1, $f4                   
/* 01118 80B34DC8 00000000 */  nop
/* 0111C 80B34DCC 00031C00 */  sll     $v1, $v1, 16               
/* 01120 80B34DD0 1000000E */  beq     $zero, $zero, .L80B34E0C   
/* 01124 80B34DD4 00031C03 */  sra     $v1, $v1, 16               
/* 01128 80B34DD8 44823000 */  mtc1    $v0, $f6                   ## $f6 = 0.00
.L80B34DDC:
/* 0112C 80B34DDC 3C013E80 */  lui     $at, 0x3E80                ## $at = 3E800000
/* 01130 80B34DE0 44815000 */  mtc1    $at, $f10                  ## $f10 = 0.25
/* 01134 80B34DE4 46803220 */  cvt.s.w $f8, $f6                   
/* 01138 80B34DE8 3C0144FA */  lui     $at, 0x44FA                ## $at = 44FA0000
/* 0113C 80B34DEC 44819000 */  mtc1    $at, $f18                  ## $f18 = 2000.00
/* 01140 80B34DF0 460A4402 */  mul.s   $f16, $f8, $f10            
/* 01144 80B34DF4 46128101 */  sub.s   $f4, $f16, $f18            
/* 01148 80B34DF8 4600218D */  trunc.w.s $f6, $f4                   
/* 0114C 80B34DFC 44033000 */  mfc1    $v1, $f6                   
/* 01150 80B34E00 00000000 */  nop
/* 01154 80B34E04 00031C00 */  sll     $v1, $v1, 16               
/* 01158 80B34E08 00031C03 */  sra     $v1, $v1, 16               
.L80B34E0C:
/* 0115C 80B34E0C 0083C821 */  addu    $t9, $a0, $v1              
/* 01160 80B34E10 A61900B6 */  sh      $t9, 0x00B6($s0)           ## 000000B6
/* 01164 80B34E14 860800B6 */  lh      $t0, 0x00B6($s0)           ## 000000B6
/* 01168 80B34E18 26040188 */  addiu   $a0, $s0, 0x0188           ## $a0 = 00000188
/* 0116C 80B34E1C 1840000F */  blez    $v0, .L80B34E5C            
/* 01170 80B34E20 A6080032 */  sh      $t0, 0x0032($s0)           ## 00000032
/* 01174 80B34E24 44834000 */  mtc1    $v1, $f8                   ## $f8 = 0.00
/* 01178 80B34E28 3C013F80 */  lui     $at, 0x3F80                ## $at = 3F800000
/* 0117C 80B34E2C 44816000 */  mtc1    $at, $f12                  ## $f12 = 1.00
/* 01180 80B34E30 468042A0 */  cvt.s.w $f10, $f8                  
/* 01184 80B34E34 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 01188 80B34E38 44818000 */  mtc1    $at, $f16                  ## $f16 = 0.50
/* 0118C 80B34E3C 00000000 */  nop
/* 01190 80B34E40 46105082 */  mul.s   $f2, $f10, $f16            
/* 01194 80B34E44 4602603C */  c.lt.s  $f12, $f2                  
/* 01198 80B34E48 00000000 */  nop
/* 0119C 80B34E4C 45020011 */  bc1fl   .L80B34E94                 
/* 011A0 80B34E50 46001207 */  neg.s   $f8, $f2                   
/* 011A4 80B34E54 1000000E */  beq     $zero, $zero, .L80B34E90   
/* 011A8 80B34E58 46006086 */  mov.s   $f2, $f12                  
.L80B34E5C:
/* 011AC 80B34E5C 44839000 */  mtc1    $v1, $f18                  ## $f18 = 0.00
/* 011B0 80B34E60 3C01BF80 */  lui     $at, 0xBF80                ## $at = BF800000
/* 011B4 80B34E64 44816000 */  mtc1    $at, $f12                  ## $f12 = -1.00
/* 011B8 80B34E68 46809120 */  cvt.s.w $f4, $f18                  
/* 011BC 80B34E6C 3C013F00 */  lui     $at, 0x3F00                ## $at = 3F000000
/* 011C0 80B34E70 44813000 */  mtc1    $at, $f6                   ## $f6 = 0.50
/* 011C4 80B34E74 00000000 */  nop
/* 011C8 80B34E78 46062082 */  mul.s   $f2, $f4, $f6              
/* 011CC 80B34E7C 460C103C */  c.lt.s  $f2, $f12                  
/* 011D0 80B34E80 00000000 */  nop
/* 011D4 80B34E84 45020003 */  bc1fl   .L80B34E94                 
/* 011D8 80B34E88 46001207 */  neg.s   $f8, $f2                   
/* 011DC 80B34E8C 46006086 */  mov.s   $f2, $f12                  
.L80B34E90:
/* 011E0 80B34E90 46001207 */  neg.s   $f8, $f2                   
.L80B34E94:
/* 011E4 80B34E94 0C02927F */  jal     SkelAnime_FrameUpdateMatrix
              
/* 011E8 80B34E98 E60801A4 */  swc1    $f8, 0x01A4($s0)           ## 000001A4
/* 011EC 80B34E9C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 011F0 80B34EA0 0C00B821 */  jal     func_8002E084              
/* 011F4 80B34EA4 24051555 */  addiu   $a1, $zero, 0x1555         ## $a1 = 00001555
/* 011F8 80B34EA8 50400011 */  beql    $v0, $zero, .L80B34EF0     
/* 011FC 80B34EAC 8FA90024 */  lw      $t1, 0x0024($sp)           
/* 01200 80B34EB0 0C03F66B */  jal     Math_Rand_ZeroOne
              ## Rand.Next() float
/* 01204 80B34EB4 00000000 */  nop
/* 01208 80B34EB8 3C0180B3 */  lui     $at, %hi(D_80B37B88)       ## $at = 80B30000
/* 0120C 80B34EBC C42A7B88 */  lwc1    $f10, %lo(D_80B37B88)($at) 
/* 01210 80B34EC0 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01214 80B34EC4 4600503C */  c.lt.s  $f10, $f0                  
/* 01218 80B34EC8 00000000 */  nop
/* 0121C 80B34ECC 45000005 */  bc1f    .L80B34EE4                 
/* 01220 80B34ED0 00000000 */  nop
/* 01224 80B34ED4 0C2CD3CA */  jal     func_80B34F28              
/* 01228 80B34ED8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0122C 80B34EDC 10000004 */  beq     $zero, $zero, .L80B34EF0   
/* 01230 80B34EE0 8FA90024 */  lw      $t1, 0x0024($sp)           
.L80B34EE4:
/* 01234 80B34EE4 0C2CD1FF */  jal     func_80B347FC              
/* 01238 80B34EE8 8FA50024 */  lw      $a1, 0x0024($sp)           
/* 0123C 80B34EEC 8FA90024 */  lw      $t1, 0x0024($sp)           
.L80B34EF0:
/* 01240 80B34EF0 3C0A0001 */  lui     $t2, 0x0001                ## $t2 = 00010000
/* 01244 80B34EF4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01248 80B34EF8 01495021 */  addu    $t2, $t2, $t1              
/* 0124C 80B34EFC 8D4A1DE4 */  lw      $t2, 0x1DE4($t2)           ## 00011DE4
/* 01250 80B34F00 314B005F */  andi    $t3, $t2, 0x005F           ## $t3 = 00000000
/* 01254 80B34F04 55600004 */  bnel    $t3, $zero, .L80B34F18     
/* 01258 80B34F08 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 0125C 80B34F0C 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01260 80B34F10 2405383E */  addiu   $a1, $zero, 0x383E         ## $a1 = 0000383E
.L80B34F14:
/* 01264 80B34F14 8FBF001C */  lw      $ra, 0x001C($sp)           
.L80B34F18:
/* 01268 80B34F18 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 0126C 80B34F1C 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 01270 80B34F20 03E00008 */  jr      $ra                        
/* 01274 80B34F24 00000000 */  nop
