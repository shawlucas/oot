.late_rodata
glabel D_80A061C4
    .float 0.3

.text
glabel func_80A03148
/* 01518 80A03148 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 0151C 80A0314C AFBF001C */  sw      $ra, 0x001C($sp)           
/* 01520 80A03150 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 01524 80A03154 AFA60030 */  sw      $a2, 0x0030($sp)           
/* 01528 80A03158 C486028C */  lwc1    $f6, 0x028C($a0)           ## 0000028C
/* 0152C 80A0315C C4A40000 */  lwc1    $f4, 0x0000($a1)           ## 00000000
/* 01530 80A03160 C48A0024 */  lwc1    $f10, 0x0024($a0)          ## 00000024
/* 01534 80A03164 C7AC0038 */  lwc1    $f12, 0x0038($sp)          
/* 01538 80A03168 46062200 */  add.s   $f8, $f4, $f6              
/* 0153C 80A0316C C4A60008 */  lwc1    $f6, 0x0008($a1)           ## 00000008
/* 01540 80A03170 3C0180A0 */  lui     $at, %hi(D_80A061C4)       ## $at = 80A00000
/* 01544 80A03174 44877000 */  mtc1    $a3, $f14                  ## $f14 = 0.00
/* 01548 80A03178 460A4101 */  sub.s   $f4, $f8, $f10             
/* 0154C 80A0317C C4880294 */  lwc1    $f8, 0x0294($a0)           ## 00000294
/* 01550 80A03180 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 01554 80A03184 460C2402 */  mul.s   $f16, $f4, $f12            
/* 01558 80A03188 46083280 */  add.s   $f10, $f6, $f8             
/* 0155C 80A0318C C484002C */  lwc1    $f4, 0x002C($a0)           ## 0000002C
/* 01560 80A03190 C42861C4 */  lwc1    $f8, %lo(D_80A061C4)($at)  
/* 01564 80A03194 3C0141F0 */  lui     $at, 0x41F0                ## $at = 41F00000
/* 01568 80A03198 46045181 */  sub.s   $f6, $f10, $f4             
/* 0156C 80A0319C 44815000 */  mtc1    $at, $f10                  ## $f10 = 30.00
/* 01570 80A031A0 E7B00024 */  swc1    $f16, 0x0024($sp)          
/* 01574 80A031A4 460C3482 */  mul.s   $f18, $f6, $f12            
/* 01578 80A031A8 46086300 */  add.s   $f12, $f12, $f8            
/* 0157C 80A031AC 460A7380 */  add.s   $f14, $f14, $f10           
/* 01580 80A031B0 44066000 */  mfc1    $a2, $f12                  
/* 01584 80A031B4 E7B20020 */  swc1    $f18, 0x0020($sp)          
/* 01588 80A031B8 0C280AF6 */  jal     func_80A02BD8              
/* 0158C 80A031BC E7AE0034 */  swc1    $f14, 0x0034($sp)          
/* 01590 80A031C0 C7B00024 */  lwc1    $f16, 0x0024($sp)          
/* 01594 80A031C4 C7B20020 */  lwc1    $f18, 0x0020($sp)          
/* 01598 80A031C8 C7A80030 */  lwc1    $f8, 0x0030($sp)           
/* 0159C 80A031CC 46108102 */  mul.s   $f4, $f16, $f16            
/* 015A0 80A031D0 C7AE0034 */  lwc1    $f14, 0x0034($sp)          
/* 015A4 80A031D4 2604005C */  addiu   $a0, $s0, 0x005C           ## $a0 = 0000005C
/* 015A8 80A031D8 46129182 */  mul.s   $f6, $f18, $f18            
/* 015AC 80A031DC 3C0640A0 */  lui     $a2, 0x40A0                ## $a2 = 40A00000
/* 015B0 80A031E0 46062000 */  add.s   $f0, $f4, $f6              
/* 015B4 80A031E4 46000004 */  sqrt.s  $f0, $f0                   
/* 015B8 80A031E8 4608003C */  c.lt.s  $f0, $f8                   
/* 015BC 80A031EC 00000000 */  nop
/* 015C0 80A031F0 45020004 */  bc1fl   .L80A03204                 
/* 015C4 80A031F4 4600703C */  c.lt.s  $f14, $f0                  
/* 015C8 80A031F8 10000009 */  beq     $zero, $zero, .L80A03220   
/* 015CC 80A031FC 46004086 */  mov.s   $f2, $f8                   
/* 015D0 80A03200 4600703C */  c.lt.s  $f14, $f0                  
.L80A03204:
/* 015D4 80A03204 00000000 */  nop
/* 015D8 80A03208 45020004 */  bc1fl   .L80A0321C                 
/* 015DC 80A0320C 46000306 */  mov.s   $f12, $f0                  
/* 015E0 80A03210 10000002 */  beq     $zero, $zero, .L80A0321C   
/* 015E4 80A03214 46007306 */  mov.s   $f12, $f14                 
/* 015E8 80A03218 46000306 */  mov.s   $f12, $f0                  
.L80A0321C:
/* 015EC 80A0321C 46006086 */  mov.s   $f2, $f12                  
.L80A03220:
/* 015F0 80A03220 46020032 */  c.eq.s  $f0, $f2                   
/* 015F4 80A03224 E6020068 */  swc1    $f2, 0x0068($s0)           ## 00000068
/* 015F8 80A03228 4503000D */  bc1tl   .L80A03260                 
/* 015FC 80A0322C 44058000 */  mfc1    $a1, $f16                  
/* 01600 80A03230 44805000 */  mtc1    $zero, $f10                ## $f10 = 0.00
/* 01604 80A03234 00000000 */  nop
/* 01608 80A03238 460A0032 */  c.eq.s  $f0, $f10                  
/* 0160C 80A0323C 00000000 */  nop
/* 01610 80A03240 45030007 */  bc1tl   .L80A03260                 
/* 01614 80A03244 44058000 */  mfc1    $a1, $f16                  
/* 01618 80A03248 46001303 */  div.s   $f12, $f2, $f0             
/* 0161C 80A0324C 460C8402 */  mul.s   $f16, $f16, $f12           
/* 01620 80A03250 00000000 */  nop
/* 01624 80A03254 460C9482 */  mul.s   $f18, $f18, $f12           
/* 01628 80A03258 00000000 */  nop
/* 0162C 80A0325C 44058000 */  mfc1    $a1, $f16                  
.L80A03260:
/* 01630 80A03260 0C01DE80 */  jal     Math_ApproxF
              
/* 01634 80A03264 E7B20020 */  swc1    $f18, 0x0020($sp)          
/* 01638 80A03268 C7B20020 */  lwc1    $f18, 0x0020($sp)          
/* 0163C 80A0326C 26040064 */  addiu   $a0, $s0, 0x0064           ## $a0 = 00000064
/* 01640 80A03270 3C0640A0 */  lui     $a2, 0x40A0                ## $a2 = 40A00000
/* 01644 80A03274 44059000 */  mfc1    $a1, $f18                  
/* 01648 80A03278 0C01DE80 */  jal     Math_ApproxF
              
/* 0164C 80A0327C 00000000 */  nop
/* 01650 80A03280 0C00B5FB */  jal     ActorPosition_Move              
/* 01654 80A03284 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 01658 80A03288 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 0165C 80A0328C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 01660 80A03290 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 01664 80A03294 03E00008 */  jr      $ra                        
/* 01668 80A03298 00000000 */  nop
