glabel func_808044A0
/* 00760 808044A0 27BDFFC0 */  addiu   $sp, $sp, 0xFFC0           ## $sp = FFFFFFC0
/* 00764 808044A4 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 00768 808044A8 34218000 */  ori     $at, $at, 0x8000           ## $at = 00018000
/* 0076C 808044AC AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 00770 808044B0 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 00774 808044B4 00814021 */  addu    $t0, $a0, $at              
/* 00778 808044B8 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
/* 0077C 808044BC 24090003 */  addiu   $t1, $zero, 0x0003         ## $t1 = 00000003
/* 00780 808044C0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 00784 808044C4 55230006 */  bnel    $t1, $v1, .L808044E0       
/* 00788 808044C8 96020020 */  lhu     $v0, 0x0020($s0)           ## 00000020
/* 0078C 808044CC 948E0020 */  lhu     $t6, 0x0020($a0)           ## 00000020
/* 00790 808044D0 31CF9000 */  andi    $t7, $t6, 0x9000           ## $t7 = 00000000
/* 00794 808044D4 55E00007 */  bnel    $t7, $zero, .L808044F4     
/* 00798 808044D8 85194A46 */  lh      $t9, 0x4A46($t0)           ## 00004A46
/* 0079C 808044DC 96020020 */  lhu     $v0, 0x0020($s0)           ## 00000020
.L808044E0:
/* 007A0 808044E0 2401BFFF */  addiu   $at, $zero, 0xBFFF         ## $at = FFFFBFFF
/* 007A4 808044E4 0041C027 */  nor     $t8, $v0, $at              
/* 007A8 808044E8 1700001D */  bne     $t8, $zero, .L80804560     
/* 007AC 808044EC 304C9000 */  andi    $t4, $v0, 0x9000           ## $t4 = 00000000
/* 007B0 808044F0 85194A46 */  lh      $t9, 0x4A46($t0)           ## 00004A46
.L808044F4:
/* 007B4 808044F4 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 007B8 808044F8 00300821 */  addu    $at, $at, $s0              
/* 007BC 808044FC A439CA38 */  sh      $t9, -0x35C8($at)          ## 0001CA38
/* 007C0 80804500 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 007C4 80804504 00300821 */  addu    $at, $at, $s0              
/* 007C8 80804508 240A0002 */  addiu   $t2, $zero, 0x0002         ## $t2 = 00000002
/* 007CC 8080450C A42ACA66 */  sh      $t2, -0x359A($at)          ## 0001CA66
/* 007D0 80804510 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 007D4 80804514 24020008 */  addiu   $v0, $zero, 0x0008         ## $v0 = 00000008
/* 007D8 80804518 00300821 */  addu    $at, $at, $s0              
/* 007DC 8080451C A422CA50 */  sh      $v0, -0x35B0($at)          ## 0001CA50
/* 007E0 80804520 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 007E4 80804524 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 007E8 80804528 00300821 */  addu    $at, $at, $s0              
/* 007EC 8080452C 3C0B8013 */  lui     $t3, %hi(D_801333E8)
/* 007F0 80804530 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 007F4 80804534 A422CA3E */  sh      $v0, -0x35C2($at)          ## 0001CA3E
/* 007F8 80804538 256B33E8 */  addiu   $t3, %lo(D_801333E8)
/* 007FC 8080453C 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 00800 80804540 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 00804 80804544 AFAB0014 */  sw      $t3, 0x0014($sp)           
/* 00808 80804548 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 0080C 8080454C 2404483C */  addiu   $a0, $zero, 0x483C         ## $a0 = 0000483C
/* 00810 80804550 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 00814 80804554 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 00818 80804558 100000BB */  beq     $zero, $zero, .L80804848   
/* 0081C 8080455C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80804560:
/* 00820 80804560 11800044 */  beq     $t4, $zero, .L80804674     
/* 00824 80804564 00036840 */  sll     $t5, $v1,  1               
/* 00828 80804568 3C0E8013 */  lui     $t6, %hi(sramSaveAddress)
/* 0082C 8080456C 01CD7021 */  addu    $t6, $t6, $t5              
/* 00830 80804570 95CEA4E0 */  lhu     $t6, %lo(sramSaveAddress)($t6)
/* 00834 80804574 8E0F01E0 */  lw      $t7, 0x01E0($s0)           ## 000001E0
/* 00838 80804578 2404005A */  addiu   $a0, $zero, 0x005A         ## $a0 = 0000005A
/* 0083C 8080457C 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 00840 80804580 01CF1021 */  addu    $v0, $t6, $t7              
/* 00844 80804584 9058001C */  lbu     $t8, 0x001C($v0)           ## 0000001C
/* 00848 80804588 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 0084C 8080458C 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 00850 80804590 1098002F */  beq     $a0, $t8, .L80804650       
/* 00854 80804594 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 00858 80804598 9059001D */  lbu     $t9, 0x001D($v0)           ## 0000001D
/* 0085C 8080459C 24010045 */  addiu   $at, $zero, 0x0045         ## $at = 00000045
/* 00860 808045A0 1321002B */  beq     $t9, $at, .L80804650       
/* 00864 808045A4 00000000 */  nop
/* 00868 808045A8 904A001E */  lbu     $t2, 0x001E($v0)           ## 0000001E
/* 0086C 808045AC 2401004C */  addiu   $at, $zero, 0x004C         ## $at = 0000004C
/* 00870 808045B0 11410027 */  beq     $t2, $at, .L80804650       
/* 00874 808045B4 00000000 */  nop
/* 00878 808045B8 904B001F */  lbu     $t3, 0x001F($v0)           ## 0000001F
/* 0087C 808045BC 24010044 */  addiu   $at, $zero, 0x0044         ## $at = 00000044
/* 00880 808045C0 11610023 */  beq     $t3, $at, .L80804650       
/* 00884 808045C4 00000000 */  nop
/* 00888 808045C8 904C0020 */  lbu     $t4, 0x0020($v0)           ## 00000020
/* 0088C 808045CC 24010041 */  addiu   $at, $zero, 0x0041         ## $at = 00000041
/* 00890 808045D0 1181001F */  beq     $t4, $at, .L80804650       
/* 00894 808045D4 00000000 */  nop
/* 00898 808045D8 904D0021 */  lbu     $t5, 0x0021($v0)           ## 00000021
/* 0089C 808045DC 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 008A0 808045E0 24020008 */  addiu   $v0, $zero, 0x0008         ## $v0 = 00000008
/* 008A4 808045E4 108D001A */  beq     $a0, $t5, .L80804650       
/* 008A8 808045E8 00300821 */  addu    $at, $at, $s0              
/* 008AC 808045EC A423CA5E */  sh      $v1, -0x35A2($at)          ## 0001CA5E
/* 008B0 808045F0 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 008B4 808045F4 00300821 */  addu    $at, $at, $s0              
/* 008B8 808045F8 240E0004 */  addiu   $t6, $zero, 0x0004         ## $t6 = 00000004
/* 008BC 808045FC A42ECA66 */  sh      $t6, -0x359A($at)          ## 0001CA66
/* 008C0 80804600 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 008C4 80804604 00300821 */  addu    $at, $at, $s0              
/* 008C8 80804608 A422CA50 */  sh      $v0, -0x35B0($at)          ## 0001CA50
/* 008CC 8080460C 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 008D0 80804610 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 008D4 80804614 00300821 */  addu    $at, $at, $s0              
/* 008D8 80804618 240F000A */  addiu   $t7, $zero, 0x000A         ## $t7 = 0000000A
/* 008DC 8080461C 3C188013 */  lui     $t8, %hi(D_801333E8)
/* 008E0 80804620 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 008E4 80804624 A42FCA3E */  sh      $t7, -0x35C2($at)          ## 0001CA3E
/* 008E8 80804628 271833E8 */  addiu   $t8, %lo(D_801333E8)
/* 008EC 8080462C 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 008F0 80804630 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 008F4 80804634 AFB80014 */  sw      $t8, 0x0014($sp)           
/* 008F8 80804638 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 008FC 8080463C 2404483B */  addiu   $a0, $zero, 0x483B         ## $a0 = 0000483B
/* 00900 80804640 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 00904 80804644 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 00908 80804648 1000007F */  beq     $zero, $zero, .L80804848   
/* 0090C 8080464C 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80804650:
/* 00910 80804650 3C198013 */  lui     $t9, %hi(D_801333E8)
/* 00914 80804654 273933E8 */  addiu   $t9, %lo(D_801333E8)
/* 00918 80804658 AFB90014 */  sw      $t9, 0x0014($sp)           
/* 0091C 8080465C 2404483D */  addiu   $a0, $zero, 0x483D         ## $a0 = 0000483D
/* 00920 80804660 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 00924 80804664 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 00928 80804668 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 0092C 8080466C 10000076 */  beq     $zero, $zero, .L80804848   
/* 00930 80804670 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80804674:
/* 00934 80804674 85024ABC */  lh      $v0, 0x4ABC($t0)           ## 00004ABC
/* 00938 80804678 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 0093C 8080467C 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 00940 80804680 04400003 */  bltz    $v0, .L80804690            
/* 00944 80804684 00022023 */  subu    $a0, $zero, $v0            
/* 00948 80804688 10000001 */  beq     $zero, $zero, .L80804690   
/* 0094C 8080468C 00402025 */  or      $a0, $v0, $zero            ## $a0 = 00000000
.L80804690:
/* 00950 80804690 2881001E */  slti    $at, $a0, 0x001E           
/* 00954 80804694 1420003D */  bne     $at, $zero, .L8080478C     
/* 00958 80804698 24044839 */  addiu   $a0, $zero, 0x4839         ## $a0 = 00004839
/* 0095C 8080469C 3C0A8013 */  lui     $t2, %hi(D_801333E8)
/* 00960 808046A0 254A33E8 */  addiu   $t2, %lo(D_801333E8)
/* 00964 808046A4 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 00968 808046A8 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 0096C 808046AC AFAA0014 */  sw      $t2, 0x0014($sp)           
/* 00970 808046B0 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 00974 808046B4 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 00978 808046B8 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 0097C 808046BC AFA8002C */  sw      $t0, 0x002C($sp)           
/* 00980 808046C0 8FA8002C */  lw      $t0, 0x002C($sp)           
/* 00984 808046C4 24090003 */  addiu   $t1, $zero, 0x0003         ## $t1 = 00000003
/* 00988 808046C8 850B4ABC */  lh      $t3, 0x4ABC($t0)           ## 00004ABC
/* 0098C 808046CC 2961001E */  slti    $at, $t3, 0x001E           
/* 00990 808046D0 5420001C */  bnel    $at, $zero, .L80804744     
/* 00994 808046D4 85184A38 */  lh      $t8, 0x4A38($t0)           ## 00004A38
/* 00998 808046D8 850C4A38 */  lh      $t4, 0x4A38($t0)           ## 00004A38
/* 0099C 808046DC 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 009A0 808046E0 00300821 */  addu    $at, $at, $s0              
/* 009A4 808046E4 258DFFFF */  addiu   $t5, $t4, 0xFFFF           ## $t5 = FFFFFFFF
/* 009A8 808046E8 A42DCA38 */  sh      $t5, -0x35C8($at)          ## 0001CA38
/* 009AC 808046EC 850E4A46 */  lh      $t6, 0x4A46($t0)           ## 00004A46
/* 009B0 808046F0 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
/* 009B4 808046F4 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 009B8 808046F8 00300821 */  addu    $at, $at, $s0              
/* 009BC 808046FC 15C3000A */  bne     $t6, $v1, .L80804728       
/* 009C0 80804700 246FFFFF */  addiu   $t7, $v1, 0xFFFF           ## $t7 = FFFFFFFF
/* 009C4 80804704 A42FCA38 */  sh      $t7, -0x35C8($at)          ## 0001CA38
/* 009C8 80804708 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
/* 009CC 8080470C 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 009D0 80804710 00300821 */  addu    $at, $at, $s0              
/* 009D4 80804714 0461001D */  bgez    $v1, .L8080478C            
/* 009D8 80804718 00000000 */  nop
/* 009DC 8080471C A429CA38 */  sh      $t1, -0x35C8($at)          ## 0001CA38
/* 009E0 80804720 1000001A */  beq     $zero, $zero, .L8080478C   
/* 009E4 80804724 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
.L80804728:
/* 009E8 80804728 04610018 */  bgez    $v1, .L8080478C            
/* 009EC 8080472C 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 009F0 80804730 00300821 */  addu    $at, $at, $s0              
/* 009F4 80804734 A429CA38 */  sh      $t1, -0x35C8($at)          ## 0001CA38
/* 009F8 80804738 10000014 */  beq     $zero, $zero, .L8080478C   
/* 009FC 8080473C 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
/* 00A00 80804740 85184A38 */  lh      $t8, 0x4A38($t0)           ## 00004A38
.L80804744:
/* 00A04 80804744 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00A08 80804748 00300821 */  addu    $at, $at, $s0              
/* 00A0C 8080474C 27190001 */  addiu   $t9, $t8, 0x0001           ## $t9 = 00000001
/* 00A10 80804750 A439CA38 */  sh      $t9, -0x35C8($at)          ## 0001CA38
/* 00A14 80804754 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
/* 00A18 80804758 28610004 */  slti    $at, $v1, 0x0004           
/* 00A1C 8080475C 14200004 */  bne     $at, $zero, .L80804770     
/* 00A20 80804760 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00A24 80804764 00300821 */  addu    $at, $at, $s0              
/* 00A28 80804768 A420CA38 */  sh      $zero, -0x35C8($at)        ## 0001CA38
/* 00A2C 8080476C 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
.L80804770:
/* 00A30 80804770 850A4A46 */  lh      $t2, 0x4A46($t0)           ## 00004A46
/* 00A34 80804774 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00A38 80804778 00300821 */  addu    $at, $at, $s0              
/* 00A3C 8080477C 15430003 */  bne     $t2, $v1, .L8080478C       
/* 00A40 80804780 246B0001 */  addiu   $t3, $v1, 0x0001           ## $t3 = 00000001
/* 00A44 80804784 A42BCA38 */  sh      $t3, -0x35C8($at)          ## 0001CA38
/* 00A48 80804788 85034A38 */  lh      $v1, 0x4A38($t0)           ## 00004A38
.L8080478C:
/* 00A4C 8080478C 1123002D */  beq     $t1, $v1, .L80804844       
/* 00A50 80804790 00036040 */  sll     $t4, $v1,  1               
/* 00A54 80804794 3C0D8013 */  lui     $t5, %hi(sramSaveAddress)
/* 00A58 80804798 01AC6821 */  addu    $t5, $t5, $t4              
/* 00A5C 8080479C 95ADA4E0 */  lhu     $t5, %lo(sramSaveAddress)($t5)
/* 00A60 808047A0 8E0E01E0 */  lw      $t6, 0x01E0($s0)           ## 000001E0
/* 00A64 808047A4 2404005A */  addiu   $a0, $zero, 0x005A         ## $a0 = 0000005A
/* 00A68 808047A8 01AE1021 */  addu    $v0, $t5, $t6              
/* 00A6C 808047AC 904F001C */  lbu     $t7, 0x001C($v0)           ## 0000001C
/* 00A70 808047B0 240D0004 */  addiu   $t5, $zero, 0x0004         ## $t5 = 00000004
/* 00A74 808047B4 508F0017 */  beql    $a0, $t7, .L80804814       
/* 00A78 808047B8 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00A7C 808047BC 9058001D */  lbu     $t8, 0x001D($v0)           ## 0000001D
/* 00A80 808047C0 24010045 */  addiu   $at, $zero, 0x0045         ## $at = 00000045
/* 00A84 808047C4 53010013 */  beql    $t8, $at, .L80804814       
/* 00A88 808047C8 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00A8C 808047CC 9059001E */  lbu     $t9, 0x001E($v0)           ## 0000001E
/* 00A90 808047D0 2401004C */  addiu   $at, $zero, 0x004C         ## $at = 0000004C
/* 00A94 808047D4 5321000F */  beql    $t9, $at, .L80804814       
/* 00A98 808047D8 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00A9C 808047DC 904A001F */  lbu     $t2, 0x001F($v0)           ## 0000001F
/* 00AA0 808047E0 24010044 */  addiu   $at, $zero, 0x0044         ## $at = 00000044
/* 00AA4 808047E4 5141000B */  beql    $t2, $at, .L80804814       
/* 00AA8 808047E8 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00AAC 808047EC 904B0020 */  lbu     $t3, 0x0020($v0)           ## 00000020
/* 00AB0 808047F0 24010041 */  addiu   $at, $zero, 0x0041         ## $at = 00000041
/* 00AB4 808047F4 51610007 */  beql    $t3, $at, .L80804814       
/* 00AB8 808047F8 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00ABC 808047FC 904C0021 */  lbu     $t4, 0x0021($v0)           ## 00000021
/* 00AC0 80804800 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00AC4 80804804 00300821 */  addu    $at, $at, $s0              
/* 00AC8 80804808 148C000D */  bne     $a0, $t4, .L80804840       
/* 00ACC 8080480C 2418FFFF */  addiu   $t8, $zero, 0xFFFF         ## $t8 = FFFFFFFF
/* 00AD0 80804810 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
.L80804814:
/* 00AD4 80804814 00300821 */  addu    $at, $at, $s0              
/* 00AD8 80804818 A42DCA60 */  sh      $t5, -0x35A0($at)          ## 0001CA60
/* 00ADC 8080481C 850E4A38 */  lh      $t6, 0x4A38($t0)           ## 00004A38
/* 00AE0 80804820 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00AE4 80804824 00300821 */  addu    $at, $at, $s0              
/* 00AE8 80804828 A42ECA62 */  sh      $t6, -0x359E($at)          ## 0001CA62
/* 00AEC 8080482C 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 00AF0 80804830 00300821 */  addu    $at, $at, $s0              
/* 00AF4 80804834 240F00FF */  addiu   $t7, $zero, 0x00FF         ## $t7 = 000000FF
/* 00AF8 80804838 10000002 */  beq     $zero, $zero, .L80804844   
/* 00AFC 8080483C A42FCAA0 */  sh      $t7, -0x3560($at)          ## 0001CAA0
.L80804840:
/* 00B00 80804840 A438CA60 */  sh      $t8, -0x35A0($at)          ## 0001CA60
.L80804844:
/* 00B04 80804844 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80804848:
/* 00B08 80804848 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 00B0C 8080484C 27BD0040 */  addiu   $sp, $sp, 0x0040           ## $sp = 00000000
/* 00B10 80804850 03E00008 */  jr      $ra                        
/* 00B14 80804854 00000000 */  nop
