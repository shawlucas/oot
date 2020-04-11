.late_rodata
glabel D_80ADD890
    .float 3000.0
    .balign 4

glabel D_80ADD894
    .float 3000.0
    .balign 4

.text
glabel func_80ADAFC0
/* 02030 80ADAFC0 27BDFFE0 */  addiu   $sp, $sp, 0xFFE0           ## $sp = FFFFFFE0
/* 02034 80ADAFC4 AFBF001C */  sw      $ra, 0x001C($sp)           
/* 02038 80ADAFC8 AFB00018 */  sw      $s0, 0x0018($sp)           
/* 0203C 80ADAFCC AFA50024 */  sw      $a1, 0x0024($sp)           
/* 02040 80ADAFD0 90820198 */  lbu     $v0, 0x0198($a0)           ## 00000198
/* 02044 80ADAFD4 848E019A */  lh      $t6, 0x019A($a0)           ## 0000019A
/* 02048 80ADAFD8 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0204C 80ADAFDC 24420001 */  addiu   $v0, $v0, 0x0001           ## $v0 = 00000001
/* 02050 80ADAFE0 28410009 */  slti    $at, $v0, 0x0009           
/* 02054 80ADAFE4 25CF0001 */  addiu   $t7, $t6, 0x0001           ## $t7 = 00000001
/* 02058 80ADAFE8 14200004 */  bne     $at, $zero, .L80ADAFFC     
/* 0205C 80ADAFEC A48F019A */  sh      $t7, 0x019A($a0)           ## 0000019A
/* 02060 80ADAFF0 24180008 */  addiu   $t8, $zero, 0x0008         ## $t8 = 00000008
/* 02064 80ADAFF4 10000002 */  beq     $zero, $zero, .L80ADB000   
/* 02068 80ADAFF8 A0980198 */  sb      $t8, 0x0198($a0)           ## 00000198
.L80ADAFFC:
/* 0206C 80ADAFFC A2020198 */  sb      $v0, 0x0198($s0)           ## 00000198
.L80ADB000:
/* 02070 80ADB000 92020198 */  lbu     $v0, 0x0198($s0)           ## 00000198
/* 02074 80ADB004 2442FFFF */  addiu   $v0, $v0, 0xFFFF           ## $v0 = 00000000
/* 02078 80ADB008 18400010 */  blez    $v0, .L80ADB04C            
/* 0207C 80ADB00C 0002C880 */  sll     $t9, $v0,  2               
/* 02080 80ADB010 0322C823 */  subu    $t9, $t9, $v0              
/* 02084 80ADB014 0019C880 */  sll     $t9, $t9,  2               
/* 02088 80ADB018 02192821 */  addu    $a1, $s0, $t9              
/* 0208C 80ADB01C 24A30234 */  addiu   $v1, $a1, 0x0234           ## $v1 = 00000234
/* 02090 80ADB020 24A40228 */  addiu   $a0, $a1, 0x0228           ## $a0 = 00000228
.L80ADB024:
/* 02094 80ADB024 8C890000 */  lw      $t1, 0x0000($a0)           ## 00000228
/* 02098 80ADB028 2442FFFF */  addiu   $v0, $v0, 0xFFFF           ## $v0 = FFFFFFFF
/* 0209C 80ADB02C 2463FFF4 */  addiu   $v1, $v1, 0xFFF4           ## $v1 = 00000228
/* 020A0 80ADB030 AC69000C */  sw      $t1, 0x000C($v1)           ## 00000234
/* 020A4 80ADB034 8C880004 */  lw      $t0, 0x0004($a0)           ## 0000022C
/* 020A8 80ADB038 2484FFF4 */  addiu   $a0, $a0, 0xFFF4           ## $a0 = 0000021C
/* 020AC 80ADB03C AC680010 */  sw      $t0, 0x0010($v1)           ## 00000238
/* 020B0 80ADB040 8C890014 */  lw      $t1, 0x0014($a0)           ## 00000230
/* 020B4 80ADB044 1C40FFF7 */  bgtz    $v0, .L80ADB024            
/* 020B8 80ADB048 AC690014 */  sw      $t1, 0x0014($v1)           ## 0000023C
.L80ADB04C:
/* 020BC 80ADB04C 860B019A */  lh      $t3, 0x019A($s0)           ## 0000019A
/* 020C0 80ADB050 860A00B6 */  lh      $t2, 0x00B6($s0)           ## 000000B6
/* 020C4 80ADB054 000B6080 */  sll     $t4, $t3,  2               
/* 020C8 80ADB058 018B6023 */  subu    $t4, $t4, $t3              
/* 020CC 80ADB05C 000C6300 */  sll     $t4, $t4, 12               
/* 020D0 80ADB060 014C2021 */  addu    $a0, $t2, $t4              
/* 020D4 80ADB064 2484C000 */  addiu   $a0, $a0, 0xC000           ## $a0 = FFFFC21C
/* 020D8 80ADB068 00042400 */  sll     $a0, $a0, 16               
/* 020DC 80ADB06C 0C01DE1C */  jal     Math_Sins
              ## sins?
/* 020E0 80ADB070 00042403 */  sra     $a0, $a0, 16               
/* 020E4 80ADB074 3C0180AE */  lui     $at, %hi(D_80ADD890)       ## $at = 80AE0000
/* 020E8 80ADB078 C424D890 */  lwc1    $f4, %lo(D_80ADD890)($at)  
/* 020EC 80ADB07C C6060050 */  lwc1    $f6, 0x0050($s0)           ## 00000050
/* 020F0 80ADB080 860E019A */  lh      $t6, 0x019A($s0)           ## 0000019A
/* 020F4 80ADB084 C6100024 */  lwc1    $f16, 0x0024($s0)          ## 00000024
/* 020F8 80ADB088 46062202 */  mul.s   $f8, $f4, $f6              
/* 020FC 80ADB08C 860D00B6 */  lh      $t5, 0x00B6($s0)           ## 000000B6
/* 02100 80ADB090 000E7880 */  sll     $t7, $t6,  2               
/* 02104 80ADB094 01EE7823 */  subu    $t7, $t7, $t6              
/* 02108 80ADB098 000F7B00 */  sll     $t7, $t7, 12               
/* 0210C 80ADB09C 01AF2021 */  addu    $a0, $t5, $t7              
/* 02110 80ADB0A0 2484C000 */  addiu   $a0, $a0, 0xC000           ## $a0 = FFFFC000
/* 02114 80ADB0A4 46080282 */  mul.s   $f10, $f0, $f8             
/* 02118 80ADB0A8 00042400 */  sll     $a0, $a0, 16               
/* 0211C 80ADB0AC 00042403 */  sra     $a0, $a0, 16               
/* 02120 80ADB0B0 46105480 */  add.s   $f18, $f10, $f16           
/* 02124 80ADB0B4 0C01DE0D */  jal     Math_Coss
              ## coss?
/* 02128 80ADB0B8 E6120234 */  swc1    $f18, 0x0234($s0)          ## 00000234
/* 0212C 80ADB0BC 3C0180AE */  lui     $at, %hi(D_80ADD894)       ## $at = 80AE0000
/* 02130 80ADB0C0 C424D894 */  lwc1    $f4, %lo(D_80ADD894)($at)  
/* 02134 80ADB0C4 C6060050 */  lwc1    $f6, 0x0050($s0)           ## 00000050
/* 02138 80ADB0C8 C610002C */  lwc1    $f16, 0x002C($s0)          ## 0000002C
/* 0213C 80ADB0CC 8602019A */  lh      $v0, 0x019A($s0)           ## 0000019A
/* 02140 80ADB0D0 46062202 */  mul.s   $f8, $f4, $f6              
/* 02144 80ADB0D4 28410008 */  slti    $at, $v0, 0x0008           
/* 02148 80ADB0D8 46080282 */  mul.s   $f10, $f0, $f8             
/* 0214C 80ADB0DC 46105480 */  add.s   $f18, $f10, $f16           
/* 02150 80ADB0E0 10200008 */  beq     $at, $zero, .L80ADB104     
/* 02154 80ADB0E4 E612023C */  swc1    $f18, 0x023C($s0)          ## 0000023C
/* 02158 80ADB0E8 3C014110 */  lui     $at, 0x4110                ## $at = 41100000
/* 0215C 80ADB0EC 44813000 */  mtc1    $at, $f6                   ## $f6 = 9.00
/* 02160 80ADB0F0 C6040244 */  lwc1    $f4, 0x0244($s0)           ## 00000244
/* 02164 80ADB0F4 8602019A */  lh      $v0, 0x019A($s0)           ## 0000019A
/* 02168 80ADB0F8 46062201 */  sub.s   $f8, $f4, $f6              
/* 0216C 80ADB0FC 10000015 */  beq     $zero, $zero, .L80ADB154   
/* 02170 80ADB100 E6080238 */  swc1    $f8, 0x0238($s0)           ## 00000238
.L80ADB104:
/* 02174 80ADB104 3C014000 */  lui     $at, 0x4000                ## $at = 40000000
/* 02178 80ADB108 44818000 */  mtc1    $at, $f16                  ## $f16 = 2.00
/* 0217C 80ADB10C C60A0244 */  lwc1    $f10, 0x0244($s0)          ## 00000244
/* 02180 80ADB110 28410010 */  slti    $at, $v0, 0x0010           
/* 02184 80ADB114 26040050 */  addiu   $a0, $s0, 0x0050           ## $a0 = 00000050
/* 02188 80ADB118 46105480 */  add.s   $f18, $f10, $f16           
/* 0218C 80ADB11C 24050000 */  addiu   $a1, $zero, 0x0000         ## $a1 = 00000000
/* 02190 80ADB120 3C063A83 */  lui     $a2, 0x3A83                ## $a2 = 3A830000
/* 02194 80ADB124 1420000B */  bne     $at, $zero, .L80ADB154     
/* 02198 80ADB128 E6120238 */  swc1    $f18, 0x0238($s0)          ## 00000238
/* 0219C 80ADB12C 0C01DE80 */  jal     Math_ApproxF
              
/* 021A0 80ADB130 34C6126F */  ori     $a2, $a2, 0x126F           ## $a2 = 3A83126F
/* 021A4 80ADB134 10400003 */  beq     $v0, $zero, .L80ADB144     
/* 021A8 80ADB138 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 021AC 80ADB13C 0C2B6695 */  jal     func_80AD9A54              
/* 021B0 80ADB140 8FA50024 */  lw      $a1, 0x0024($sp)           
.L80ADB144:
/* 021B4 80ADB144 C6000050 */  lwc1    $f0, 0x0050($s0)           ## 00000050
/* 021B8 80ADB148 8602019A */  lh      $v0, 0x019A($s0)           ## 0000019A
/* 021BC 80ADB14C E6000058 */  swc1    $f0, 0x0058($s0)           ## 00000058
/* 021C0 80ADB150 E6000054 */  swc1    $f0, 0x0054($s0)           ## 00000054
.L80ADB154:
/* 021C4 80ADB154 24010010 */  addiu   $at, $zero, 0x0010         ## $at = 00000010
/* 021C8 80ADB158 14410003 */  bne     $v0, $at, .L80ADB168       
/* 021CC 80ADB15C 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 021D0 80ADB160 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 021D4 80ADB164 24053877 */  addiu   $a1, $zero, 0x3877         ## $a1 = 00003877
.L80ADB168:
/* 021D8 80ADB168 8FBF001C */  lw      $ra, 0x001C($sp)           
/* 021DC 80ADB16C 8FB00018 */  lw      $s0, 0x0018($sp)           
/* 021E0 80ADB170 27BD0020 */  addiu   $sp, $sp, 0x0020           ## $sp = 00000000
/* 021E4 80ADB174 03E00008 */  jr      $ra                        
/* 021E8 80ADB178 00000000 */  nop


