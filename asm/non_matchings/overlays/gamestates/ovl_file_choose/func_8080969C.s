glabel func_8080969C
/* 0595C 8080969C 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 05960 808096A0 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 05964 808096A4 AFB00020 */  sw      $s0, 0x0020($sp)           
/* 05968 808096A8 948E0020 */  lhu     $t6, 0x0020($a0)           ## 00000020
/* 0596C 808096AC 2401BFFF */  addiu   $at, $zero, 0xBFFF         ## $at = FFFFBFFF
/* 05970 808096B0 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 05974 808096B4 01C17827 */  nor     $t7, $t6, $at              
/* 05978 808096B8 15E00047 */  bne     $t7, $zero, .L808097D8     
/* 0597C 808096BC 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 05980 808096C0 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 05984 808096C4 3C188013 */  lui     $t8, %hi(D_801333E8)
/* 05988 808096C8 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 0598C 808096CC 271833E8 */  addiu   $t8, %lo(D_801333E8)
/* 05990 808096D0 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 05994 808096D4 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 05998 808096D8 AFB80014 */  sw      $t8, 0x0014($sp)           
/* 0599C 808096DC AFA70010 */  sw      $a3, 0x0010($sp)           
/* 059A0 808096E0 2404483B */  addiu   $a0, $zero, 0x483B         ## $a0 = 0000483B
/* 059A4 808096E4 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 059A8 808096E8 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 059AC 808096EC AFB00038 */  sw      $s0, 0x0038($sp)           
/* 059B0 808096F0 8FA90038 */  lw      $t1, 0x0038($sp)           
/* 059B4 808096F4 3C010002 */  lui     $at, 0x0002                ## $at = 00020000
/* 059B8 808096F8 24190027 */  addiu   $t9, $zero, 0x0027         ## $t9 = 00000027
/* 059BC 808096FC 00290821 */  addu    $at, $at, $t1              
/* 059C0 80809700 A439CA3E */  sh      $t9, -0x35C2($at)          ## 0001CA3E
/* 059C4 80809704 8FA20038 */  lw      $v0, 0x0038($sp)           
/* 059C8 80809708 3C108016 */  lui     $s0, %hi(gSaveContext)
/* 059CC 8080970C 2610E660 */  addiu   $s0, %lo(gSaveContext)
/* 059D0 80809710 920A140A */  lbu     $t2, 0x140A($s0)           ## 8015FA6A
/* 059D4 80809714 8C4B01E0 */  lw      $t3, 0x01E0($v0)           ## 000001E0
/* 059D8 80809718 3C048081 */  lui     $a0, %hi(D_80812BB4)       ## $a0 = 80810000
/* 059DC 8080971C 244201E0 */  addiu   $v0, $v0, 0x01E0           ## $v0 = 000001E0
/* 059E0 80809720 A16A0000 */  sb      $t2, 0x0000($t3)           ## 00000000
/* 059E4 80809724 920C140C */  lbu     $t4, 0x140C($s0)           ## 8015FA6C
/* 059E8 80809728 8C4D0000 */  lw      $t5, 0x0000($v0)           ## 000001E0
/* 059EC 8080972C 24842BB4 */  addiu   $a0, $a0, %lo(D_80812BB4)  ## $a0 = 80812BB4
/* 059F0 80809730 A1AC0001 */  sb      $t4, 0x0001($t5)           ## 00000001
/* 059F4 80809734 0C00084C */  jal     osSyncPrintf
              
/* 059F8 80809738 AFA20028 */  sw      $v0, 0x0028($sp)           
/* 059FC 8080973C 0C02A6A7 */  jal     Sram_SaveSound              
/* 05A00 80809740 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 05A04 80809744 3C048081 */  lui     $a0, %hi(D_80812BC0)       ## $a0 = 80810000
/* 05A08 80809748 0C00084C */  jal     osSyncPrintf
              
/* 05A0C 8080974C 24842BC0 */  addiu   $a0, $a0, %lo(D_80812BC0)  ## $a0 = 80812BC0
/* 05A10 80809750 8FAE0028 */  lw      $t6, 0x0028($sp)           
/* 05A14 80809754 3C048081 */  lui     $a0, %hi(D_80812BC8)       ## $a0 = 80810000
/* 05A18 80809758 24842BC8 */  addiu   $a0, $a0, %lo(D_80812BC8)  ## $a0 = 80812BC8
/* 05A1C 8080975C 8DCF0000 */  lw      $t7, 0x0000($t6)           ## 00000000
/* 05A20 80809760 0C00084C */  jal     osSyncPrintf
              
/* 05A24 80809764 91E50002 */  lbu     $a1, 0x0002($t7)           ## 00000002
/* 05A28 80809768 8FB80028 */  lw      $t8, 0x0028($sp)           
/* 05A2C 8080976C 3C048081 */  lui     $a0, %hi(D_80812BE8)       ## $a0 = 80810000
/* 05A30 80809770 24842BE8 */  addiu   $a0, $a0, %lo(D_80812BE8)  ## $a0 = 80812BE8
/* 05A34 80809774 8F050000 */  lw      $a1, 0x0000($t8)           ## 00000000
/* 05A38 80809778 0C00084C */  jal     osSyncPrintf
              
/* 05A3C 8080977C 24A50002 */  addiu   $a1, $a1, 0x0002           ## $a1 = 00000002
/* 05A40 80809780 3C048081 */  lui     $a0, %hi(D_80812C08)       ## $a0 = 80810000
/* 05A44 80809784 24842C08 */  addiu   $a0, $a0, %lo(D_80812C08)  ## $a0 = 80812C08
/* 05A48 80809788 0C00084C */  jal     osSyncPrintf
              
/* 05A4C 8080978C 9205140A */  lbu     $a1, 0x140A($s0)           ## 8015FA6A
/* 05A50 80809790 3C048081 */  lui     $a0, %hi(D_80812C24)       ## $a0 = 80810000
/* 05A54 80809794 24842C24 */  addiu   $a0, $a0, %lo(D_80812C24)  ## $a0 = 80812C24
/* 05A58 80809798 0C00084C */  jal     osSyncPrintf
              
/* 05A5C 8080979C 9205140A */  lbu     $a1, 0x140A($s0)           ## 8015FA6A
/* 05A60 808097A0 3C048081 */  lui     $a0, %hi(D_80812C40)       ## $a0 = 80810000
/* 05A64 808097A4 24842C40 */  addiu   $a0, $a0, %lo(D_80812C40)  ## $a0 = 80812C40
/* 05A68 808097A8 0C00084C */  jal     osSyncPrintf
              
/* 05A6C 808097AC 9205140A */  lbu     $a1, 0x140A($s0)           ## 8015FA6A
/* 05A70 808097B0 3C048081 */  lui     $a0, %hi(D_80812C5C)       ## $a0 = 80810000
/* 05A74 808097B4 0C00084C */  jal     osSyncPrintf
              
/* 05A78 808097B8 24842C5C */  addiu   $a0, $a0, %lo(D_80812C5C)  ## $a0 = 80812C5C
/* 05A7C 808097BC 0C03D9C0 */  jal     func_800F6700              
/* 05A80 808097C0 8204140A */  lb      $a0, 0x140A($s0)           ## 8015FA6A
/* 05A84 808097C4 3C048081 */  lui     $a0, %hi(D_80812C60)       ## $a0 = 80810000
/* 05A88 808097C8 0C00084C */  jal     osSyncPrintf
              
/* 05A8C 808097CC 24842C60 */  addiu   $a0, $a0, %lo(D_80812C60)  ## $a0 = 80812C60
/* 05A90 808097D0 10000079 */  beq     $zero, $zero, .L808099B8   
/* 05A94 808097D4 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L808097D8:
/* 05A98 808097D8 34218000 */  ori     $at, $at, 0x8000           ## $at = 00008000
/* 05A9C 808097DC 02011821 */  addu    $v1, $s0, $at              
/* 05AA0 808097E0 84624ABA */  lh      $v0, 0x4ABA($v1)           ## 00004ABA
/* 05AA4 808097E4 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 05AA8 808097E8 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 05AAC 808097EC 2841FFE2 */  slti    $at, $v0, 0xFFE2           
/* 05AB0 808097F0 10200022 */  beq     $at, $zero, .L8080987C     
/* 05AB4 808097F4 24044839 */  addiu   $a0, $zero, 0x4839         ## $a0 = 00004839
/* 05AB8 808097F8 3C198013 */  lui     $t9, %hi(D_801333E8)
/* 05ABC 808097FC 273933E8 */  addiu   $t9, %lo(D_801333E8)
/* 05AC0 80809800 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 05AC4 80809804 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 05AC8 80809808 AFB90014 */  sw      $t9, 0x0014($sp)           
/* 05ACC 8080980C 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 05AD0 80809810 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 05AD4 80809814 AFA30028 */  sw      $v1, 0x0028($sp)           
/* 05AD8 80809818 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 05ADC 8080981C AFB00038 */  sw      $s0, 0x0038($sp)           
/* 05AE0 80809820 3C088081 */  lui     $t0, %hi(D_80813810)       ## $t0 = 80810000
/* 05AE4 80809824 25083810 */  addiu   $t0, $t0, %lo(D_80813810)  ## $t0 = 80813810
/* 05AE8 80809828 91090000 */  lbu     $t1, 0x0000($t0)           ## 80813810
/* 05AEC 8080982C 3C108016 */  lui     $s0, %hi(gSaveContext)
/* 05AF0 80809830 8FA30028 */  lw      $v1, 0x0028($sp)           
/* 05AF4 80809834 1520000C */  bne     $t1, $zero, .L80809868     
/* 05AF8 80809838 2610E660 */  addiu   $s0, %lo(gSaveContext)
/* 05AFC 8080983C 3C108016 */  lui     $s0, %hi(gSaveContext)
/* 05B00 80809840 2610E660 */  addiu   $s0, %lo(gSaveContext)
/* 05B04 80809844 920A140A */  lbu     $t2, 0x140A($s0)           ## 8015FA6A
/* 05B08 80809848 240D0003 */  addiu   $t5, $zero, 0x0003         ## $t5 = 00000003
/* 05B0C 8080984C 254BFFFF */  addiu   $t3, $t2, 0xFFFF           ## $t3 = FFFFFFFF
/* 05B10 80809850 316C00FF */  andi    $t4, $t3, 0x00FF           ## $t4 = 000000FF
/* 05B14 80809854 298100F1 */  slti    $at, $t4, 0x00F1           
/* 05B18 80809858 14200006 */  bne     $at, $zero, .L80809874     
/* 05B1C 8080985C A20B140A */  sb      $t3, 0x140A($s0)           ## 8015FA6A
/* 05B20 80809860 10000004 */  beq     $zero, $zero, .L80809874   
/* 05B24 80809864 A20D140A */  sb      $t5, 0x140A($s0)           ## 8015FA6A
.L80809868:
/* 05B28 80809868 920E140C */  lbu     $t6, 0x140C($s0)           ## 8015FA6C
/* 05B2C 8080986C 39CF0001 */  xori    $t7, $t6, 0x0001           ## $t7 = 00000001
/* 05B30 80809870 A20F140C */  sb      $t7, 0x140C($s0)           ## 8015FA6C
.L80809874:
/* 05B34 80809874 10000026 */  beq     $zero, $zero, .L80809910   
/* 05B38 80809878 8FB00038 */  lw      $s0, 0x0038($sp)           
.L8080987C:
/* 05B3C 8080987C 2841001F */  slti    $at, $v0, 0x001F           
/* 05B40 80809880 14200023 */  bne     $at, $zero, .L80809910     
/* 05B44 80809884 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 05B48 80809888 3C188013 */  lui     $t8, %hi(D_801333E8)
/* 05B4C 8080988C 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 05B50 80809890 271833E8 */  addiu   $t8, %lo(D_801333E8)
/* 05B54 80809894 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 05B58 80809898 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 05B5C 8080989C AFB80014 */  sw      $t8, 0x0014($sp)           
/* 05B60 808098A0 AFA70010 */  sw      $a3, 0x0010($sp)           
/* 05B64 808098A4 24044839 */  addiu   $a0, $zero, 0x4839         ## $a0 = 00004839
/* 05B68 808098A8 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 05B6C 808098AC AFA30028 */  sw      $v1, 0x0028($sp)           
/* 05B70 808098B0 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 05B74 808098B4 AFB00038 */  sw      $s0, 0x0038($sp)           
/* 05B78 808098B8 3C088081 */  lui     $t0, %hi(D_80813810)       ## $t0 = 80810000
/* 05B7C 808098BC 25083810 */  addiu   $t0, $t0, %lo(D_80813810)  ## $t0 = 80813810
/* 05B80 808098C0 91190000 */  lbu     $t9, 0x0000($t0)           ## 80813810
/* 05B84 808098C4 3C108016 */  lui     $s0, %hi(gSaveContext)
/* 05B88 808098C8 8FA30028 */  lw      $v1, 0x0028($sp)           
/* 05B8C 808098CC 1720000C */  bne     $t9, $zero, .L80809900     
/* 05B90 808098D0 2610E660 */  addiu   $s0, %lo(gSaveContext)
/* 05B94 808098D4 3C108016 */  lui     $s0, %hi(gSaveContext)
/* 05B98 808098D8 2610E660 */  addiu   $s0, %lo(gSaveContext)
/* 05B9C 808098DC 9209140A */  lbu     $t1, 0x140A($s0)           ## 8015FA6A
/* 05BA0 808098E0 252A0001 */  addiu   $t2, $t1, 0x0001           ## $t2 = 00000001
/* 05BA4 808098E4 314B00FF */  andi    $t3, $t2, 0x00FF           ## $t3 = 00000001
/* 05BA8 808098E8 29610004 */  slti    $at, $t3, 0x0004           
/* 05BAC 808098EC 14200002 */  bne     $at, $zero, .L808098F8     
/* 05BB0 808098F0 A20A140A */  sb      $t2, 0x140A($s0)           ## 8015FA6A
/* 05BB4 808098F4 A200140A */  sb      $zero, 0x140A($s0)         ## 8015FA6A
.L808098F8:
/* 05BB8 808098F8 10000005 */  beq     $zero, $zero, .L80809910   
/* 05BBC 808098FC 8FB00038 */  lw      $s0, 0x0038($sp)           
.L80809900:
/* 05BC0 80809900 920C140C */  lbu     $t4, 0x140C($s0)           ## 8015FA6C
/* 05BC4 80809904 398D0001 */  xori    $t5, $t4, 0x0001           ## $t5 = 00000001
/* 05BC8 80809908 A20D140C */  sb      $t5, 0x140C($s0)           ## 8015FA6C
/* 05BCC 8080990C 8FB00038 */  lw      $s0, 0x0038($sp)           
.L80809910:
/* 05BD0 80809910 84624ABC */  lh      $v0, 0x4ABC($v1)           ## 00004ABC
/* 05BD4 80809914 3C078013 */  lui     $a3, %hi(D_801333E0)
/* 05BD8 80809918 24E733E0 */  addiu   $a3, %lo(D_801333E0)
/* 05BDC 8080991C 2841FFE2 */  slti    $at, $v0, 0xFFE2           
/* 05BE0 80809920 14200003 */  bne     $at, $zero, .L80809930     
/* 05BE4 80809924 24044839 */  addiu   $a0, $zero, 0x4839         ## $a0 = 00004839
/* 05BE8 80809928 2841001F */  slti    $at, $v0, 0x001F           
/* 05BEC 8080992C 1420000E */  bne     $at, $zero, .L80809968     
.L80809930:
/* 05BF0 80809930 3C0E8013 */  lui     $t6, %hi(D_801333E8)
/* 05BF4 80809934 25CE33E8 */  addiu   $t6, %lo(D_801333E8)
/* 05BF8 80809938 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 05BFC 8080993C 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 05C00 80809940 AFAE0014 */  sw      $t6, 0x0014($sp)           
/* 05C04 80809944 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 05C08 80809948 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 05C0C 8080994C AFA70010 */  sw      $a3, 0x0010($sp)           
/* 05C10 80809950 3C088081 */  lui     $t0, %hi(D_80813810)       ## $t0 = 80810000
/* 05C14 80809954 25083810 */  addiu   $t0, $t0, %lo(D_80813810)  ## $t0 = 80813810
/* 05C18 80809958 910F0000 */  lbu     $t7, 0x0000($t0)           ## 80813810
/* 05C1C 8080995C 39F80001 */  xori    $t8, $t7, 0x0001           ## $t8 = 00000001
/* 05C20 80809960 10000014 */  beq     $zero, $zero, .L808099B4   
/* 05C24 80809964 A1180000 */  sb      $t8, 0x0000($t0)           ## 80813810
.L80809968:
/* 05C28 80809968 96190020 */  lhu     $t9, 0x0020($s0)           ## 8015E680
/* 05C2C 8080996C 3C01FFFF */  lui     $at, 0xFFFF                ## $at = FFFF0000
/* 05C30 80809970 34217FFF */  ori     $at, $at, 0x7FFF           ## $at = FFFF7FFF
/* 05C34 80809974 03214827 */  nor     $t1, $t9, $at              
/* 05C38 80809978 1520000E */  bne     $t1, $zero, .L808099B4     
/* 05C3C 8080997C 2404483B */  addiu   $a0, $zero, 0x483B         ## $a0 = 0000483B
/* 05C40 80809980 3C0A8013 */  lui     $t2, %hi(D_801333E8)
/* 05C44 80809984 254A33E8 */  addiu   $t2, %lo(D_801333E8)
/* 05C48 80809988 3C058013 */  lui     $a1, %hi(D_801333D4)
/* 05C4C 8080998C 24A533D4 */  addiu   $a1, %lo(D_801333D4)
/* 05C50 80809990 AFAA0014 */  sw      $t2, 0x0014($sp)           
/* 05C54 80809994 24060004 */  addiu   $a2, $zero, 0x0004         ## $a2 = 00000004
/* 05C58 80809998 0C03DCE3 */  jal     Audio_PlaySoundGeneral
              
/* 05C5C 8080999C AFA70010 */  sw      $a3, 0x0010($sp)           
/* 05C60 808099A0 3C088081 */  lui     $t0, %hi(D_80813810)       ## $t0 = 80810000
/* 05C64 808099A4 25083810 */  addiu   $t0, $t0, %lo(D_80813810)  ## $t0 = 80813810
/* 05C68 808099A8 910B0000 */  lbu     $t3, 0x0000($t0)           ## 80813810
/* 05C6C 808099AC 396C0001 */  xori    $t4, $t3, 0x0001           ## $t4 = 00000001
/* 05C70 808099B0 A10C0000 */  sb      $t4, 0x0000($t0)           ## 80813810
.L808099B4:
/* 05C74 808099B4 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L808099B8:
/* 05C78 808099B8 8FB00020 */  lw      $s0, 0x0020($sp)           
/* 05C7C 808099BC 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
/* 05C80 808099C0 03E00008 */  jr      $ra                        
/* 05C84 808099C4 00000000 */  nop
