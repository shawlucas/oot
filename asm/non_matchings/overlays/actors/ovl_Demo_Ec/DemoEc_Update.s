.rdata
glabel D_80970798
    .asciz "\x1B[31mメインモードがおかしい!!!!!!!!!!!!!!!!!!!!!!!!!\n\x1B[m"
    .balign 4

.text
glabel DemoEc_Update
/* 02D74 80970224 27BDFFD8 */  addiu   $sp, $sp, 0xFFD8           ## $sp = FFFFFFD8
/* 02D78 80970228 AFBF0014 */  sw      $ra, 0x0014($sp)           
/* 02D7C 8097022C AFA5002C */  sw      $a1, 0x002C($sp)           
/* 02D80 80970230 8C820194 */  lw      $v0, 0x0194($a0)           ## 00000194
/* 02D84 80970234 0440000B */  bltz    $v0, .L80970264            
/* 02D88 80970238 2841001D */  slti    $at, $v0, 0x001D           
/* 02D8C 8097023C 10200009 */  beq     $at, $zero, .L80970264     
/* 02D90 80970240 00027080 */  sll     $t6, $v0,  2               
/* 02D94 80970244 3C0F8097 */  lui     $t7, %hi(D_8097053C)       ## $t7 = 80970000
/* 02D98 80970248 25EF053C */  addiu   $t7, $t7, %lo(D_8097053C)  ## $t7 = 8097053C
/* 02D9C 8097024C 01CF1821 */  addu    $v1, $t6, $t7              
/* 02DA0 80970250 8C660000 */  lw      $a2, 0x0000($v1)           ## 00000000
/* 02DA4 80970254 3C188097 */  lui     $t8, %hi(D_8097053C)       ## $t8 = 80970000
/* 02DA8 80970258 2718053C */  addiu   $t8, $t8, %lo(D_8097053C)  ## $t8 = 8097053C
/* 02DAC 8097025C 14C00006 */  bne     $a2, $zero, .L80970278     
/* 02DB0 80970260 00000000 */  nop
.L80970264:
/* 02DB4 80970264 3C048097 */  lui     $a0, %hi(D_80970798)       ## $a0 = 80970000
/* 02DB8 80970268 0C00084C */  jal     osSyncPrintf
              
/* 02DBC 8097026C 24840798 */  addiu   $a0, $a0, %lo(D_80970798)  ## $a0 = 80970798
/* 02DC0 80970270 1000000C */  beq     $zero, $zero, .L809702A4   
/* 02DC4 80970274 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L80970278:
/* 02DC8 80970278 10780007 */  beq     $v1, $t8, .L80970298       
/* 02DCC 8097027C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 02DD0 80970280 AFA3001C */  sw      $v1, 0x001C($sp)           
/* 02DD4 80970284 0C25B76F */  jal     func_8096DDBC              
/* 02DD8 80970288 AFA40028 */  sw      $a0, 0x0028($sp)           
/* 02DDC 8097028C 8FA3001C */  lw      $v1, 0x001C($sp)           
/* 02DE0 80970290 8FA40028 */  lw      $a0, 0x0028($sp)           
/* 02DE4 80970294 8C660000 */  lw      $a2, 0x0000($v1)           ## 00000000
.L80970298:
/* 02DE8 80970298 00C0F809 */  jalr    $ra, $a2                   
/* 02DEC 8097029C 8FA5002C */  lw      $a1, 0x002C($sp)           
/* 02DF0 809702A0 8FBF0014 */  lw      $ra, 0x0014($sp)           
.L809702A4:
/* 02DF4 809702A4 27BD0028 */  addiu   $sp, $sp, 0x0028           ## $sp = 00000000
/* 02DF8 809702A8 03E00008 */  jr      $ra                        
/* 02DFC 809702AC 00000000 */  nop


