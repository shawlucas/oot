glabel func_80A3559C
/* 0028C 80A3559C 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 00290 80A355A0 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00294 80A355A4 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 00298 80A355A8 AFA60048 */  sw      $a2, 0x0048($sp)           
/* 0029C 80A355AC 84AE007E */  lh      $t6, 0x007E($a1)           ## 0000007E
/* 002A0 80A355B0 84A200B6 */  lh      $v0, 0x00B6($a1)           ## 000000B6
/* 002A4 80A355B4 00A08025 */  or      $s0, $a1, $zero            ## $s0 = 00000000
/* 002A8 80A355B8 8C891C44 */  lw      $t1, 0x1C44($a0)           ## 00001C44
/* 002AC 80A355BC 01C24023 */  subu    $t0, $t6, $v0              
/* 002B0 80A355C0 00084400 */  sll     $t0, $t0, 16               
/* 002B4 80A355C4 00084403 */  sra     $t0, $t0, 16               
/* 002B8 80A355C8 05010004 */  bgez    $t0, .L80A355DC            
/* 002BC 80A355CC 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 002C0 80A355D0 00084023 */  subu    $t0, $zero, $t0            
/* 002C4 80A355D4 00084400 */  sll     $t0, $t0, 16               
/* 002C8 80A355D8 00084403 */  sra     $t0, $t0, 16               
.L80A355DC:
/* 002CC 80A355DC 860F008A */  lh      $t7, 0x008A($s0)           ## 0000008A
/* 002D0 80A355E0 3C0642C8 */  lui     $a2, 0x42C8                ## $a2 = 42C80000
/* 002D4 80A355E4 24072710 */  addiu   $a3, $zero, 0x2710         ## $a3 = 00002710
/* 002D8 80A355E8 01E21823 */  subu    $v1, $t7, $v0              
/* 002DC 80A355EC 00031C00 */  sll     $v1, $v1, 16               
/* 002E0 80A355F0 00031C03 */  sra     $v1, $v1, 16               
/* 002E4 80A355F4 04610004 */  bgez    $v1, .L80A35608            
/* 002E8 80A355F8 24183E80 */  addiu   $t8, $zero, 0x3E80         ## $t8 = 00003E80
/* 002EC 80A355FC 00031823 */  subu    $v1, $zero, $v1            
/* 002F0 80A35600 00031C00 */  sll     $v1, $v1, 16               
/* 002F4 80A35604 00031C03 */  sra     $v1, $v1, 16               
.L80A35608:
/* 002F8 80A35608 AFB80010 */  sw      $t8, 0x0010($sp)           
/* 002FC 80A3560C AFA20014 */  sw      $v0, 0x0014($sp)           
/* 00300 80A35610 A7A30034 */  sh      $v1, 0x0034($sp)           
/* 00304 80A35614 AFA40040 */  sw      $a0, 0x0040($sp)           
/* 00308 80A35618 A7A80036 */  sh      $t0, 0x0036($sp)           
/* 0030C 80A3561C 0C00D52D */  jal     func_800354B4              
/* 00310 80A35620 AFA9003C */  sw      $t1, 0x003C($sp)           
/* 00314 80A35624 87A30034 */  lh      $v1, 0x0034($sp)           
/* 00318 80A35628 87A80036 */  lh      $t0, 0x0036($sp)           
/* 0031C 80A3562C 10400014 */  beq     $v0, $zero, .L80A35680     
/* 00320 80A35630 8FA9003C */  lw      $t1, 0x003C($sp)           
/* 00324 80A35634 81390842 */  lb      $t9, 0x0842($t1)           ## 00000842
/* 00328 80A35638 24010011 */  addiu   $at, $zero, 0x0011         ## $at = 00000011
/* 0032C 80A3563C 8FAA0040 */  lw      $t2, 0x0040($sp)           
/* 00330 80A35640 17210006 */  bne     $t9, $at, .L80A3565C       
/* 00334 80A35644 3C0B0001 */  lui     $t3, 0x0001                ## $t3 = 00010000
/* 00338 80A35648 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0033C 80A3564C 0C28DC2F */  jal     func_80A370BC              
/* 00340 80A35650 8FA50040 */  lw      $a1, 0x0040($sp)           
/* 00344 80A35654 100000C2 */  beq     $zero, $zero, .L80A35960   
/* 00348 80A35658 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A3565C:
/* 0034C 80A3565C 016A5821 */  addu    $t3, $t3, $t2              
/* 00350 80A35660 8D6B1DE4 */  lw      $t3, 0x1DE4($t3)           ## 00001DE4
/* 00354 80A35664 316C0001 */  andi    $t4, $t3, 0x0001           ## $t4 = 00000000
/* 00358 80A35668 51800006 */  beql    $t4, $zero, .L80A35684     
/* 0035C 80A3566C 240D2AA8 */  addiu   $t5, $zero, 0x2AA8         ## $t5 = 00002AA8
/* 00360 80A35670 0C28E10C */  jal     func_80A38430              
/* 00364 80A35674 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00368 80A35678 100000B9 */  beq     $zero, $zero, .L80A35960   
/* 0036C 80A3567C 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A35680:
/* 00370 80A35680 240D2AA8 */  addiu   $t5, $zero, 0x2AA8         ## $t5 = 00002AA8
.L80A35684:
/* 00374 80A35684 AFAD0010 */  sw      $t5, 0x0010($sp)           
/* 00378 80A35688 860E00B6 */  lh      $t6, 0x00B6($s0)           ## 000000B6
/* 0037C 80A3568C AFA9003C */  sw      $t1, 0x003C($sp)           
/* 00380 80A35690 A7A80036 */  sh      $t0, 0x0036($sp)           
/* 00384 80A35694 A7A30034 */  sh      $v1, 0x0034($sp)           
/* 00388 80A35698 8FA40040 */  lw      $a0, 0x0040($sp)           
/* 0038C 80A3569C 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00390 80A356A0 3C0642C8 */  lui     $a2, 0x42C8                ## $a2 = 42C80000
/* 00394 80A356A4 24075DC0 */  addiu   $a3, $zero, 0x5DC0         ## $a3 = 00005DC0
/* 00398 80A356A8 0C00D52D */  jal     func_800354B4              
/* 0039C 80A356AC AFAE0014 */  sw      $t6, 0x0014($sp)           
/* 003A0 80A356B0 87A30034 */  lh      $v1, 0x0034($sp)           
/* 003A4 80A356B4 87A80036 */  lh      $t0, 0x0036($sp)           
/* 003A8 80A356B8 10400036 */  beq     $v0, $zero, .L80A35794     
/* 003AC 80A356BC 8FA9003C */  lw      $t1, 0x003C($sp)           
/* 003B0 80A356C0 960F0088 */  lhu     $t7, 0x0088($s0)           ## 00000088
/* 003B4 80A356C4 8603008A */  lh      $v1, 0x008A($s0)           ## 0000008A
/* 003B8 80A356C8 31F80008 */  andi    $t8, $t7, 0x0008           ## $t8 = 00000000
/* 003BC 80A356CC A6030032 */  sh      $v1, 0x0032($s0)           ## 00000032
/* 003C0 80A356D0 13000012 */  beq     $t8, $zero, .L80A3571C     
/* 003C4 80A356D4 A60300B6 */  sh      $v1, 0x00B6($s0)           ## 000000B6
/* 003C8 80A356D8 05000003 */  bltz    $t0, .L80A356E8            
/* 003CC 80A356DC 00081023 */  subu    $v0, $zero, $t0            
/* 003D0 80A356E0 10000001 */  beq     $zero, $zero, .L80A356E8   
/* 003D4 80A356E4 01001025 */  or      $v0, $t0, $zero            ## $v0 = 00000000
.L80A356E8:
/* 003D8 80A356E8 28412EE0 */  slti    $at, $v0, 0x2EE0           
/* 003DC 80A356EC 1020000B */  beq     $at, $zero, .L80A3571C     
/* 003E0 80A356F0 3C0142B4 */  lui     $at, 0x42B4                ## $at = 42B40000
/* 003E4 80A356F4 44813000 */  mtc1    $at, $f6                   ## $f6 = 90.00
/* 003E8 80A356F8 C6040090 */  lwc1    $f4, 0x0090($s0)           ## 00000090
/* 003EC 80A356FC 4606203C */  c.lt.s  $f4, $f6                   
/* 003F0 80A35700 00000000 */  nop
/* 003F4 80A35704 45020006 */  bc1fl   .L80A35720                 
/* 003F8 80A35708 81390842 */  lb      $t9, 0x0842($t1)           ## 00000842
/* 003FC 80A3570C 0C28E0A4 */  jal     func_80A38290              
/* 00400 80A35710 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00404 80A35714 10000092 */  beq     $zero, $zero, .L80A35960   
/* 00408 80A35718 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A3571C:
/* 0040C 80A3571C 81390842 */  lb      $t9, 0x0842($t1)           ## 00000842
.L80A35720:
/* 00410 80A35720 24010011 */  addiu   $at, $zero, 0x0011         ## $at = 00000011
/* 00414 80A35724 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00418 80A35728 57210006 */  bnel    $t9, $at, .L80A35744       
/* 0041C 80A3572C 3C0142B4 */  lui     $at, 0x42B4                ## $at = 42B40000
/* 00420 80A35730 0C28DC2F */  jal     func_80A370BC              
/* 00424 80A35734 8FA50040 */  lw      $a1, 0x0040($sp)           
/* 00428 80A35738 10000089 */  beq     $zero, $zero, .L80A35960   
/* 0042C 80A3573C 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 00430 80A35740 3C0142B4 */  lui     $at, 0x42B4                ## $at = 42B40000
.L80A35744:
/* 00434 80A35744 44815000 */  mtc1    $at, $f10                  ## $f10 = 90.00
/* 00438 80A35748 C6080090 */  lwc1    $f8, 0x0090($s0)           ## 00000090
/* 0043C 80A3574C 8FAA0040 */  lw      $t2, 0x0040($sp)           
/* 00440 80A35750 3C0B0001 */  lui     $t3, 0x0001                ## $t3 = 00010000
/* 00444 80A35754 460A403C */  c.lt.s  $f8, $f10                  
/* 00448 80A35758 016A5821 */  addu    $t3, $t3, $t2              
/* 0044C 80A3575C 45000009 */  bc1f    .L80A35784                 
/* 00450 80A35760 00000000 */  nop
/* 00454 80A35764 8D6B1DE4 */  lw      $t3, 0x1DE4($t3)           ## 00011DE4
/* 00458 80A35768 316C0001 */  andi    $t4, $t3, 0x0001           ## $t4 = 00000000
/* 0045C 80A3576C 11800005 */  beq     $t4, $zero, .L80A35784     
/* 00460 80A35770 00000000 */  nop
/* 00464 80A35774 0C28E10C */  jal     func_80A38430              
/* 00468 80A35778 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0046C 80A3577C 10000078 */  beq     $zero, $zero, .L80A35960   
/* 00470 80A35780 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A35784:
/* 00474 80A35784 0C28DF5C */  jal     func_80A37D70              
/* 00478 80A35788 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0047C 80A3578C 10000074 */  beq     $zero, $zero, .L80A35960   
/* 00480 80A35790 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A35794:
/* 00484 80A35794 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 00488 80A35798 44818000 */  mtc1    $at, $f16                  ## $f16 = 80.00
/* 0048C 80A3579C 8FA40040 */  lw      $a0, 0x0040($sp)           
/* 00490 80A357A0 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 00494 80A357A4 2406FFFF */  addiu   $a2, $zero, 0xFFFF         ## $a2 = FFFFFFFF
/* 00498 80A357A8 24070003 */  addiu   $a3, $zero, 0x0003         ## $a3 = 00000003
/* 0049C 80A357AC A7A30034 */  sh      $v1, 0x0034($sp)           
/* 004A0 80A357B0 A7A80036 */  sh      $t0, 0x0036($sp)           
/* 004A4 80A357B4 AFA9003C */  sw      $t1, 0x003C($sp)           
/* 004A8 80A357B8 0C00D4FD */  jal     Actor_FindNearby
              
/* 004AC 80A357BC E7B00010 */  swc1    $f16, 0x0010($sp)          
/* 004B0 80A357C0 87A30034 */  lh      $v1, 0x0034($sp)           
/* 004B4 80A357C4 87A80036 */  lh      $t0, 0x0036($sp)           
/* 004B8 80A357C8 8FA9003C */  lw      $t1, 0x003C($sp)           
/* 004BC 80A357CC 10400033 */  beq     $v0, $zero, .L80A3589C     
/* 004C0 80A357D0 00402825 */  or      $a1, $v0, $zero            ## $a1 = 00000000
/* 004C4 80A357D4 960D0088 */  lhu     $t5, 0x0088($s0)           ## 00000088
/* 004C8 80A357D8 8603008A */  lh      $v1, 0x008A($s0)           ## 0000008A
/* 004CC 80A357DC 29012EE0 */  slti    $at, $t0, 0x2EE0           
/* 004D0 80A357E0 31AE0008 */  andi    $t6, $t5, 0x0008           ## $t6 = 00000000
/* 004D4 80A357E4 A6030032 */  sh      $v1, 0x0032($s0)           ## 00000032
/* 004D8 80A357E8 11C00003 */  beq     $t6, $zero, .L80A357F8     
/* 004DC 80A357EC A60300B6 */  sh      $v1, 0x00B6($s0)           ## 000000B6
/* 004E0 80A357F0 54200006 */  bnel    $at, $zero, .L80A3580C     
/* 004E4 80A357F4 84580000 */  lh      $t8, 0x0000($v0)           ## 00000000
.L80A357F8:
/* 004E8 80A357F8 844F0000 */  lh      $t7, 0x0000($v0)           ## 00000000
/* 004EC 80A357FC 240100DA */  addiu   $at, $zero, 0x00DA         ## $at = 000000DA
/* 004F0 80A35800 15E10022 */  bne     $t7, $at, .L80A3588C       
/* 004F4 80A35804 00000000 */  nop
/* 004F8 80A35808 84580000 */  lh      $t8, 0x0000($v0)           ## 00000000
.L80A3580C:
/* 004FC 80A3580C 240100DA */  addiu   $at, $zero, 0x00DA         ## $at = 000000DA
/* 00500 80A35810 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00504 80A35814 57010019 */  bnel    $t8, $at, .L80A3587C       
/* 00508 80A35818 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0050C 80A3581C 0C00B6D2 */  jal     ActorSearch_Distance              
/* 00510 80A35820 AFA50030 */  sw      $a1, 0x0030($sp)           
/* 00514 80A35824 3C0142A0 */  lui     $at, 0x42A0                ## $at = 42A00000
/* 00518 80A35828 44819000 */  mtc1    $at, $f18                  ## $f18 = 80.00
/* 0051C 80A3582C 8FA50030 */  lw      $a1, 0x0030($sp)           
/* 00520 80A35830 4612003C */  c.lt.s  $f0, $f18                  
/* 00524 80A35834 00000000 */  nop
/* 00528 80A35838 45020010 */  bc1fl   .L80A3587C                 
/* 0052C 80A3583C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00530 80A35840 861900B6 */  lh      $t9, 0x00B6($s0)           ## 000000B6
/* 00534 80A35844 84AA0032 */  lh      $t2, 0x0032($a1)           ## 00000032
/* 00538 80A35848 34018000 */  ori     $at, $zero, 0x8000         ## $at = 00008000
/* 0053C 80A3584C 032A5823 */  subu    $t3, $t9, $t2              
/* 00540 80A35850 01616021 */  addu    $t4, $t3, $at              
/* 00544 80A35854 000C6C00 */  sll     $t5, $t4, 16               
/* 00548 80A35858 000D7403 */  sra     $t6, $t5, 16               
/* 0054C 80A3585C 29C13E80 */  slti    $at, $t6, 0x3E80           
/* 00550 80A35860 50200006 */  beql    $at, $zero, .L80A3587C     
/* 00554 80A35864 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00558 80A35868 0C28E0A4 */  jal     func_80A38290              
/* 0055C 80A3586C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00560 80A35870 1000003B */  beq     $zero, $zero, .L80A35960   
/* 00564 80A35874 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
/* 00568 80A35878 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
.L80A3587C:
/* 0056C 80A3587C 0C28E1F4 */  jal     func_80A387D0              
/* 00570 80A35880 8FA50040 */  lw      $a1, 0x0040($sp)           
/* 00574 80A35884 10000036 */  beq     $zero, $zero, .L80A35960   
/* 00578 80A35888 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A3588C:
/* 0057C 80A3588C 0C28DF5C */  jal     func_80A37D70              
/* 00580 80A35890 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00584 80A35894 10000032 */  beq     $zero, $zero, .L80A35960   
/* 00588 80A35898 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A3589C:
/* 0058C 80A3589C 87AF004A */  lh      $t7, 0x004A($sp)           
/* 00590 80A358A0 28611B58 */  slti    $at, $v1, 0x1B58           
/* 00594 80A358A4 00001025 */  or      $v0, $zero, $zero          ## $v0 = 00000000
/* 00598 80A358A8 11E0002D */  beq     $t7, $zero, .L80A35960     
/* 0059C 80A358AC 00000000 */  nop
/* 005A0 80A358B0 14200005 */  bne     $at, $zero, .L80A358C8     
/* 005A4 80A358B4 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 005A8 80A358B8 0C28E1F4 */  jal     func_80A387D0              
/* 005AC 80A358BC 8FA50040 */  lw      $a1, 0x0040($sp)           
/* 005B0 80A358C0 10000027 */  beq     $zero, $zero, .L80A35960   
/* 005B4 80A358C4 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A358C8:
/* 005B8 80A358C8 3C014234 */  lui     $at, 0x4234                ## $at = 42340000
/* 005BC 80A358CC 44812000 */  mtc1    $at, $f4                   ## $f4 = 45.00
/* 005C0 80A358D0 C6060090 */  lwc1    $f6, 0x0090($s0)           ## 00000090
/* 005C4 80A358D4 853800B6 */  lh      $t8, 0x00B6($t1)           ## 000000B6
/* 005C8 80A358D8 861900B6 */  lh      $t9, 0x00B6($s0)           ## 000000B6
/* 005CC 80A358DC 4604303E */  c.le.s  $f6, $f4                   
/* 005D0 80A358E0 8FA40040 */  lw      $a0, 0x0040($sp)           
/* 005D4 80A358E4 03191823 */  subu    $v1, $t8, $t9              
/* 005D8 80A358E8 00031C00 */  sll     $v1, $v1, 16               
/* 005DC 80A358EC 45000018 */  bc1f    .L80A35950                 
/* 005E0 80A358F0 00031C03 */  sra     $v1, $v1, 16               
/* 005E4 80A358F4 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 005E8 80A358F8 0C00CEAE */  jal     func_80033AB8              
/* 005EC 80A358FC A7A3002E */  sh      $v1, 0x002E($sp)           
/* 005F0 80A35900 14400013 */  bne     $v0, $zero, .L80A35950     
/* 005F4 80A35904 87A3002E */  lh      $v1, 0x002E($sp)           
/* 005F8 80A35908 8FAA0040 */  lw      $t2, 0x0040($sp)           
/* 005FC 80A3590C 3C0B0001 */  lui     $t3, 0x0001                ## $t3 = 00010000
/* 00600 80A35910 016A5821 */  addu    $t3, $t3, $t2              
/* 00604 80A35914 8D6B1DE4 */  lw      $t3, 0x1DE4($t3)           ## 00011DE4
/* 00608 80A35918 316C0007 */  andi    $t4, $t3, 0x0007           ## $t4 = 00000000
/* 0060C 80A3591C 15800008 */  bne     $t4, $zero, .L80A35940     
/* 00610 80A35920 00000000 */  nop
/* 00614 80A35924 04600003 */  bltz    $v1, .L80A35934            
/* 00618 80A35928 00031023 */  subu    $v0, $zero, $v1            
/* 0061C 80A3592C 10000001 */  beq     $zero, $zero, .L80A35934   
/* 00620 80A35930 00601025 */  or      $v0, $v1, $zero            ## $v0 = 00000000
.L80A35934:
/* 00624 80A35934 284138E0 */  slti    $at, $v0, 0x38E0           
/* 00628 80A35938 10200005 */  beq     $at, $zero, .L80A35950     
/* 0062C 80A3593C 00000000 */  nop
.L80A35940:
/* 00630 80A35940 0C28DD9C */  jal     func_80A37670              
/* 00634 80A35944 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00638 80A35948 10000005 */  beq     $zero, $zero, .L80A35960   
/* 0063C 80A3594C 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A35950:
/* 00640 80A35950 0C28DA84 */  jal     func_80A36A10              
/* 00644 80A35954 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 00648 80A35958 10000001 */  beq     $zero, $zero, .L80A35960   
/* 0064C 80A3595C 24020001 */  addiu   $v0, $zero, 0x0001         ## $v0 = 00000001
.L80A35960:
/* 00650 80A35960 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 00654 80A35964 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00658 80A35968 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 0065C 80A3596C 03E00008 */  jr      $ra                        
/* 00660 80A35970 00000000 */  nop
