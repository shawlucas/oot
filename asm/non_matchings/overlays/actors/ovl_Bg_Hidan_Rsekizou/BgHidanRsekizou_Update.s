glabel BgHidanRsekizou_Update
/* 0014C 8088C34C 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 00150 8088C350 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 00154 8088C354 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 00158 8088C358 AFA5003C */  sw      $a1, 0x003C($sp)           
/* 0015C 8088C35C 848E0166 */  lh      $t6, 0x0166($a0)           ## 00000166
/* 00160 8088C360 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00164 8088C364 86020164 */  lh      $v0, 0x0164($s0)           ## 00000164
/* 00168 8088C368 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 0016C 8088C36C 05E10004 */  bgez    $t7, .L8088C380            
/* 00170 8088C370 31F80007 */  andi    $t8, $t7, 0x0007           ## $t8 = 00000001
/* 00174 8088C374 13000002 */  beq     $t8, $zero, .L8088C380     
/* 00178 8088C378 00000000 */  nop
/* 0017C 8088C37C 2718FFF8 */  addiu   $t8, $t8, 0xFFF8           ## $t8 = FFFFFFF9
.L8088C380:
/* 00180 8088C380 10400004 */  beq     $v0, $zero, .L8088C394     
/* 00184 8088C384 A6180166 */  sh      $t8, 0x0166($s0)           ## 00000166
/* 00188 8088C388 2459FFFF */  addiu   $t9, $v0, 0xFFFF           ## $t9 = FFFFFFFF
/* 0018C 8088C38C A6190164 */  sh      $t9, 0x0164($s0)           ## 00000164
/* 00190 8088C390 86020164 */  lh      $v0, 0x0164($s0)           ## 00000164
.L8088C394:
/* 00194 8088C394 14400002 */  bne     $v0, $zero, .L8088C3A0     
/* 00198 8088C398 24080003 */  addiu   $t0, $zero, 0x0003         ## $t0 = 00000003
/* 0019C 8088C39C A6080164 */  sh      $t0, 0x0164($s0)           ## 00000164
.L8088C3A0:
/* 001A0 8088C3A0 860900B6 */  lh      $t1, 0x00B6($s0)           ## 000000B6
/* 001A4 8088C3A4 252A0180 */  addiu   $t2, $t1, 0x0180           ## $t2 = 00000180
/* 001A8 8088C3A8 A60A00B6 */  sh      $t2, 0x00B6($s0)           ## 000000B6
/* 001AC 8088C3AC 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 001B0 8088C3B0 860400B6 */  lh      $a0, 0x00B6($s0)           ## 000000B6
/* 001B4 8088C3B4 860400B6 */  lh      $a0, 0x00B6($s0)           ## 000000B6
/* 001B8 8088C3B8 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 001BC 8088C3BC E7A00024 */  swc1    $f0, 0x0024($sp)           
/* 001C0 8088C3C0 8E020184 */  lw      $v0, 0x0184($s0)           ## 00000184
/* 001C4 8088C3C4 C7AE0024 */  lwc1    $f14, 0x0024($sp)          
/* 001C8 8088C3C8 C6080008 */  lwc1    $f8, 0x0008($s0)           ## 00000008
/* 001CC 8088C3CC 844B0028 */  lh      $t3, 0x0028($v0)           ## 00000028
/* 001D0 8088C3D0 844C002C */  lh      $t4, 0x002C($v0)           ## 0000002C
/* 001D4 8088C3D4 8449002A */  lh      $t1, 0x002A($v0)           ## 0000002A
/* 001D8 8088C3D8 448B2000 */  mtc1    $t3, $f4                   ## $f4 = 0.00
/* 001DC 8088C3DC 448C3000 */  mtc1    $t4, $f6                   ## $f6 = 0.00
/* 001E0 8088C3E0 24040002 */  addiu   $a0, $zero, 0x0002         ## $a0 = 00000002
/* 001E4 8088C3E4 468020A0 */  cvt.s.w $f2, $f4                   
/* 001E8 8088C3E8 00041980 */  sll     $v1, $a0,  6               
/* 001EC 8088C3EC 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 001F0 8088C3F0 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 001F4 8088C3F4 26060168 */  addiu   $a2, $s0, 0x0168           ## $a2 = 00000168
/* 001F8 8088C3F8 46803320 */  cvt.s.w $f12, $f6                  
/* 001FC 8088C3FC 46020282 */  mul.s   $f10, $f0, $f2             
/* 00200 8088C400 460A4400 */  add.s   $f16, $f8, $f10            
/* 00204 8088C404 460C7482 */  mul.s   $f18, $f14, $f12           
/* 00208 8088C408 46128100 */  add.s   $f4, $f16, $f18            
/* 0020C 8088C40C 46027482 */  mul.s   $f18, $f14, $f2            
/* 00210 8088C410 4600218D */  trunc.w.s $f6, $f4                   
/* 00214 8088C414 440E3000 */  mfc1    $t6, $f6                   
/* 00218 8088C418 460C0182 */  mul.s   $f6, $f0, $f12             
/* 0021C 8088C41C A44E0030 */  sh      $t6, 0x0030($v0)           ## 00000030
/* 00220 8088C420 C608000C */  lwc1    $f8, 0x000C($s0)           ## 0000000C
/* 00224 8088C424 4600428D */  trunc.w.s $f10, $f8                  
/* 00228 8088C428 44085000 */  mfc1    $t0, $f10                  
/* 0022C 8088C42C 00000000 */  nop
/* 00230 8088C430 01095021 */  addu    $t2, $t0, $t1              
/* 00234 8088C434 A44A0032 */  sh      $t2, 0x0032($v0)           ## 00000032
/* 00238 8088C438 C6100010 */  lwc1    $f16, 0x0010($s0)          ## 00000010
/* 0023C 8088C43C 46128101 */  sub.s   $f4, $f16, $f18            
/* 00240 8088C440 46062200 */  add.s   $f8, $f4, $f6              
/* 00244 8088C444 4600428D */  trunc.w.s $f10, $f8                  
/* 00248 8088C448 440C5000 */  mfc1    $t4, $f10                  
/* 0024C 8088C44C 00000000 */  nop
/* 00250 8088C450 A44C0034 */  sh      $t4, 0x0034($v0)           ## 00000034
/* 00254 8088C454 8E020184 */  lw      $v0, 0x0184($s0)           ## 00000184
/* 00258 8088C458 C6040008 */  lwc1    $f4, 0x0008($s0)           ## 00000008
/* 0025C 8088C45C 844D0068 */  lh      $t5, 0x0068($v0)           ## 00000068
/* 00260 8088C460 844E006C */  lh      $t6, 0x006C($v0)           ## 0000006C
/* 00264 8088C464 844B006A */  lh      $t3, 0x006A($v0)           ## 0000006A
/* 00268 8088C468 448D8000 */  mtc1    $t5, $f16                  ## $f16 = 0.00
/* 0026C 8088C46C 448E9000 */  mtc1    $t6, $f18                  ## $f18 = 0.00
/* 00270 8088C470 24420040 */  addiu   $v0, $v0, 0x0040           ## $v0 = 00000040
/* 00274 8088C474 468080A0 */  cvt.s.w $f2, $f16                  
/* 00278 8088C478 46809320 */  cvt.s.w $f12, $f18                 
/* 0027C 8088C47C 46020182 */  mul.s   $f6, $f0, $f2              
/* 00280 8088C480 46062200 */  add.s   $f8, $f4, $f6              
/* 00284 8088C484 460C7282 */  mul.s   $f10, $f14, $f12           
/* 00288 8088C488 460A4400 */  add.s   $f16, $f8, $f10            
/* 0028C 8088C48C 46027282 */  mul.s   $f10, $f14, $f2            
/* 00290 8088C490 4600848D */  trunc.w.s $f18, $f16                 
/* 00294 8088C494 44189000 */  mfc1    $t8, $f18                  
/* 00298 8088C498 460C0482 */  mul.s   $f18, $f0, $f12            
/* 0029C 8088C49C A4580030 */  sh      $t8, 0x0030($v0)           ## 00000070
/* 002A0 8088C4A0 C604000C */  lwc1    $f4, 0x000C($s0)           ## 0000000C
/* 002A4 8088C4A4 4600218D */  trunc.w.s $f6, $f4                   
/* 002A8 8088C4A8 440A3000 */  mfc1    $t2, $f6                   
/* 002AC 8088C4AC 00000000 */  nop
/* 002B0 8088C4B0 014B6021 */  addu    $t4, $t2, $t3              
/* 002B4 8088C4B4 A44C0032 */  sh      $t4, 0x0032($v0)           ## 00000072
/* 002B8 8088C4B8 C6080010 */  lwc1    $f8, 0x0010($s0)           ## 00000010
/* 002BC 8088C4BC 460A4401 */  sub.s   $f16, $f8, $f10            
/* 002C0 8088C4C0 46128100 */  add.s   $f4, $f16, $f18            
/* 002C4 8088C4C4 4600218D */  trunc.w.s $f6, $f4                   
/* 002C8 8088C4C8 440E3000 */  mfc1    $t6, $f6                   
/* 002CC 8088C4CC 00000000 */  nop
/* 002D0 8088C4D0 A44E0034 */  sh      $t6, 0x0034($v0)           ## 00000074
/* 002D4 8088C4D4 8E0F0184 */  lw      $t7, 0x0184($s0)           ## 00000184
/* 002D8 8088C4D8 C6100008 */  lwc1    $f16, 0x0008($s0)          ## 00000008
/* 002DC 8088C4DC 01E31021 */  addu    $v0, $t7, $v1              
/* 002E0 8088C4E0 84580028 */  lh      $t8, 0x0028($v0)           ## 00000068
/* 002E4 8088C4E4 8459002C */  lh      $t9, 0x002C($v0)           ## 0000006C
/* 002E8 8088C4E8 844E002A */  lh      $t6, 0x002A($v0)           ## 0000006A
/* 002EC 8088C4EC 44984000 */  mtc1    $t8, $f8                   ## $f8 = 0.00
/* 002F0 8088C4F0 44995000 */  mtc1    $t9, $f10                  ## $f10 = 0.00
/* 002F4 8088C4F4 468040A0 */  cvt.s.w $f2, $f8                   
/* 002F8 8088C4F8 46805320 */  cvt.s.w $f12, $f10                 
/* 002FC 8088C4FC 46020482 */  mul.s   $f18, $f0, $f2             
/* 00300 8088C500 46128100 */  add.s   $f4, $f16, $f18            
/* 00304 8088C504 460C7182 */  mul.s   $f6, $f14, $f12            
/* 00308 8088C508 46062200 */  add.s   $f8, $f4, $f6              
/* 0030C 8088C50C 46027182 */  mul.s   $f6, $f14, $f2             
/* 00310 8088C510 4600428D */  trunc.w.s $f10, $f8                  
/* 00314 8088C514 44095000 */  mfc1    $t1, $f10                  
/* 00318 8088C518 460C0282 */  mul.s   $f10, $f0, $f12            
/* 0031C 8088C51C A4490030 */  sh      $t1, 0x0030($v0)           ## 00000070
/* 00320 8088C520 C610000C */  lwc1    $f16, 0x000C($s0)          ## 0000000C
/* 00324 8088C524 4600848D */  trunc.w.s $f18, $f16                 
/* 00328 8088C528 440D9000 */  mfc1    $t5, $f18                  
/* 0032C 8088C52C 00000000 */  nop
/* 00330 8088C530 01AE7821 */  addu    $t7, $t5, $t6              
/* 00334 8088C534 A44F0032 */  sh      $t7, 0x0032($v0)           ## 00000072
/* 00338 8088C538 C6040010 */  lwc1    $f4, 0x0010($s0)           ## 00000010
/* 0033C 8088C53C 46062201 */  sub.s   $f8, $f4, $f6              
/* 00340 8088C540 460A4400 */  add.s   $f16, $f8, $f10            
/* 00344 8088C544 4600848D */  trunc.w.s $f18, $f16                 
/* 00348 8088C548 44199000 */  mfc1    $t9, $f18                  
/* 0034C 8088C54C 00000000 */  nop
/* 00350 8088C550 A4590034 */  sh      $t9, 0x0034($v0)           ## 00000074
/* 00354 8088C554 8E080184 */  lw      $t0, 0x0184($s0)           ## 00000184
/* 00358 8088C558 C6080008 */  lwc1    $f8, 0x0008($s0)           ## 00000008
/* 0035C 8088C55C 01031021 */  addu    $v0, $t0, $v1              
/* 00360 8088C560 84490068 */  lh      $t1, 0x0068($v0)           ## 000000A8
/* 00364 8088C564 844A006C */  lh      $t2, 0x006C($v0)           ## 000000AC
/* 00368 8088C568 8459006A */  lh      $t9, 0x006A($v0)           ## 000000AA
/* 0036C 8088C56C 44892000 */  mtc1    $t1, $f4                   ## $f4 = 0.00
/* 00370 8088C570 448A3000 */  mtc1    $t2, $f6                   ## $f6 = 0.00
/* 00374 8088C574 24420040 */  addiu   $v0, $v0, 0x0040           ## $v0 = 00000080
/* 00378 8088C578 468020A0 */  cvt.s.w $f2, $f4                   
/* 0037C 8088C57C 46803320 */  cvt.s.w $f12, $f6                  
/* 00380 8088C580 46020282 */  mul.s   $f10, $f0, $f2             
/* 00384 8088C584 460A4400 */  add.s   $f16, $f8, $f10            
/* 00388 8088C588 460C7482 */  mul.s   $f18, $f14, $f12           
/* 0038C 8088C58C 46128100 */  add.s   $f4, $f16, $f18            
/* 00390 8088C590 46027482 */  mul.s   $f18, $f14, $f2            
/* 00394 8088C594 4600218D */  trunc.w.s $f6, $f4                   
/* 00398 8088C598 440C3000 */  mfc1    $t4, $f6                   
/* 0039C 8088C59C 460C0182 */  mul.s   $f6, $f0, $f12             
/* 003A0 8088C5A0 A44C0030 */  sh      $t4, 0x0030($v0)           ## 000000B0
/* 003A4 8088C5A4 C608000C */  lwc1    $f8, 0x000C($s0)           ## 0000000C
/* 003A8 8088C5A8 4600428D */  trunc.w.s $f10, $f8                  
/* 003AC 8088C5AC 44185000 */  mfc1    $t8, $f10                  
/* 003B0 8088C5B0 00000000 */  nop
/* 003B4 8088C5B4 03194021 */  addu    $t0, $t8, $t9              
/* 003B8 8088C5B8 A4480032 */  sh      $t0, 0x0032($v0)           ## 000000B2
/* 003BC 8088C5BC C6100010 */  lwc1    $f16, 0x0010($s0)          ## 00000010
/* 003C0 8088C5C0 46128101 */  sub.s   $f4, $f16, $f18            
/* 003C4 8088C5C4 46062200 */  add.s   $f8, $f4, $f6              
/* 003C8 8088C5C8 4600428D */  trunc.w.s $f10, $f8                  
/* 003CC 8088C5CC 440A5000 */  mfc1    $t2, $f10                  
/* 003D0 8088C5D0 00000000 */  nop
/* 003D4 8088C5D4 A44A0034 */  sh      $t2, 0x0034($v0)           ## 000000B4
/* 003D8 8088C5D8 8E0B0184 */  lw      $t3, 0x0184($s0)           ## 00000184
/* 003DC 8088C5DC C6040008 */  lwc1    $f4, 0x0008($s0)           ## 00000008
/* 003E0 8088C5E0 01631021 */  addu    $v0, $t3, $v1              
/* 003E4 8088C5E4 844C00A8 */  lh      $t4, 0x00A8($v0)           ## 00000128
/* 003E8 8088C5E8 844D00AC */  lh      $t5, 0x00AC($v0)           ## 0000012C
/* 003EC 8088C5EC 844A00AA */  lh      $t2, 0x00AA($v0)           ## 0000012A
/* 003F0 8088C5F0 448C8000 */  mtc1    $t4, $f16                  ## $f16 = 0.00
/* 003F4 8088C5F4 448D9000 */  mtc1    $t5, $f18                  ## $f18 = 0.00
/* 003F8 8088C5F8 24420080 */  addiu   $v0, $v0, 0x0080           ## $v0 = 00000100
/* 003FC 8088C5FC 468080A0 */  cvt.s.w $f2, $f16                  
/* 00400 8088C600 46809320 */  cvt.s.w $f12, $f18                 
/* 00404 8088C604 46020182 */  mul.s   $f6, $f0, $f2              
/* 00408 8088C608 46062200 */  add.s   $f8, $f4, $f6              
/* 0040C 8088C60C 460C7282 */  mul.s   $f10, $f14, $f12           
/* 00410 8088C610 460A4400 */  add.s   $f16, $f8, $f10            
/* 00414 8088C614 46027282 */  mul.s   $f10, $f14, $f2            
/* 00418 8088C618 4600848D */  trunc.w.s $f18, $f16                 
/* 0041C 8088C61C 440F9000 */  mfc1    $t7, $f18                  
/* 00420 8088C620 460C0482 */  mul.s   $f18, $f0, $f12            
/* 00424 8088C624 A44F0030 */  sh      $t7, 0x0030($v0)           ## 00000130
/* 00428 8088C628 C604000C */  lwc1    $f4, 0x000C($s0)           ## 0000000C
/* 0042C 8088C62C 4600218D */  trunc.w.s $f6, $f4                   
/* 00430 8088C630 44093000 */  mfc1    $t1, $f6                   
/* 00434 8088C634 00000000 */  nop
/* 00438 8088C638 012A5821 */  addu    $t3, $t1, $t2              
/* 0043C 8088C63C A44B0032 */  sh      $t3, 0x0032($v0)           ## 00000132
/* 00440 8088C640 C6080010 */  lwc1    $f8, 0x0010($s0)           ## 00000010
/* 00444 8088C644 460A4401 */  sub.s   $f16, $f8, $f10            
/* 00448 8088C648 46128100 */  add.s   $f4, $f16, $f18            
/* 0044C 8088C64C 4600218D */  trunc.w.s $f6, $f4                   
/* 00450 8088C650 440D3000 */  mfc1    $t5, $f6                   
/* 00454 8088C654 00000000 */  nop
/* 00458 8088C658 A44D0034 */  sh      $t5, 0x0034($v0)           ## 00000134
/* 0045C 8088C65C 8E0E0184 */  lw      $t6, 0x0184($s0)           ## 00000184
/* 00460 8088C660 C6100008 */  lwc1    $f16, 0x0008($s0)          ## 00000008
/* 00464 8088C664 01C31021 */  addu    $v0, $t6, $v1              
/* 00468 8088C668 844F00E8 */  lh      $t7, 0x00E8($v0)           ## 000001E8
/* 0046C 8088C66C 845800EC */  lh      $t8, 0x00EC($v0)           ## 000001EC
/* 00470 8088C670 844D00EA */  lh      $t5, 0x00EA($v0)           ## 000001EA
/* 00474 8088C674 448F4000 */  mtc1    $t7, $f8                   ## $f8 = 0.00
/* 00478 8088C678 44985000 */  mtc1    $t8, $f10                  ## $f10 = 0.00
/* 0047C 8088C67C 244200C0 */  addiu   $v0, $v0, 0x00C0           ## $v0 = 000001C0
/* 00480 8088C680 468040A0 */  cvt.s.w $f2, $f8                   
/* 00484 8088C684 46805320 */  cvt.s.w $f12, $f10                 
/* 00488 8088C688 46020482 */  mul.s   $f18, $f0, $f2             
/* 0048C 8088C68C 46128100 */  add.s   $f4, $f16, $f18            
/* 00490 8088C690 460C7182 */  mul.s   $f6, $f14, $f12            
/* 00494 8088C694 46062200 */  add.s   $f8, $f4, $f6              
/* 00498 8088C698 46027182 */  mul.s   $f6, $f14, $f2             
/* 0049C 8088C69C 4600428D */  trunc.w.s $f10, $f8                  
/* 004A0 8088C6A0 44085000 */  mfc1    $t0, $f10                  
/* 004A4 8088C6A4 460C0282 */  mul.s   $f10, $f0, $f12            
/* 004A8 8088C6A8 A4480030 */  sh      $t0, 0x0030($v0)           ## 000001F0
/* 004AC 8088C6AC C610000C */  lwc1    $f16, 0x000C($s0)          ## 0000000C
/* 004B0 8088C6B0 4600848D */  trunc.w.s $f18, $f16                 
/* 004B4 8088C6B4 440C9000 */  mfc1    $t4, $f18                  
/* 004B8 8088C6B8 00000000 */  nop
/* 004BC 8088C6BC 018D7021 */  addu    $t6, $t4, $t5              
/* 004C0 8088C6C0 A44E0032 */  sh      $t6, 0x0032($v0)           ## 000001F2
/* 004C4 8088C6C4 C6040010 */  lwc1    $f4, 0x0010($s0)           ## 00000010
/* 004C8 8088C6C8 46062201 */  sub.s   $f8, $f4, $f6              
/* 004CC 8088C6CC 460A4400 */  add.s   $f16, $f8, $f10            
/* 004D0 8088C6D0 4600848D */  trunc.w.s $f18, $f16                 
/* 004D4 8088C6D4 44189000 */  mfc1    $t8, $f18                  
/* 004D8 8088C6D8 00000000 */  nop
/* 004DC 8088C6DC A4580034 */  sh      $t8, 0x0034($v0)           ## 000001F4
/* 004E0 8088C6E0 8FA4003C */  lw      $a0, 0x003C($sp)           
/* 004E4 8088C6E4 0C0175E7 */  jal     Actor_CollisionCheck_SetAT
              ## CollisionCheck_setAT
/* 004E8 8088C6E8 00812821 */  addu    $a1, $a0, $at              
/* 004EC 8088C6EC 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 004F0 8088C6F0 0C00BE5D */  jal     func_8002F974              
/* 004F4 8088C6F4 24052033 */  addiu   $a1, $zero, 0x2033         ## $a1 = 00002033
/* 004F8 8088C6F8 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 004FC 8088C6FC 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 00500 8088C700 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 00504 8088C704 03E00008 */  jr      $ra                        
/* 00508 8088C708 00000000 */  nop
