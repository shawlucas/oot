.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .data

.balign 16

glabel D_8011FAF0
    .word 0x00000006
    .word 0x00000000
    .word 0x00000005
    .word 0x00020000
    .word 0x00000004
    .word 0x00030000
    .word 0x00000003
    .word 0x00038000
    .word 0x00000002
    .word 0x0003C000
    .word 0x00000001
    .word 0x0003E000
    .word 0x00000000
    .word 0x0003F000
    .word 0x00000000
    .word 0x0003F800

glabel D_8011FB30
    .word 0x00000000

glabel D_8011FB34
    .word 0x00000000

glabel D_8011FB38
    .word 0x00000000

glabel D_8011FB3C
    .word 0x00000000

glabel D_8011FB40
    .word 0x00000000

glabel D_8011FB44
    .word 0xFFFC0000

glabel D_8011FB48
    .word 0x00002AAC 
    .word 0x03032AAC 
    .word 0x40000300 
    .word 0x40005556 
    .word 0x00015556 
    .word 0xAAAB0101 
    .word 0xAAABB556 
    .word 0x0102B556 
    .word 0xCAAC0203 
    .word 0xCAACFFFF 
    .word 0x03030000
    .word 0x2AAC0707 
    .word 0x2AAC4000
    .word 0x07044000 
    .word 0x55560405 
    .word 0x5556AAAB 
    .word 0x0505AAAB
    .word 0xB5560506 
    .word 0xB556CAAC 
    .word 0x0607CAAC 
    .word 0xFFFF0707 
    .word 0x00002AAC 
    .word 0x0B0B2AAC 
    .word 0x40000B08 
    .word 0x40005556 
    .word 0x08095556 
    .word 0xAAAB0909 
    .word 0xAAABB556 
    .word 0x090AB556 
    .word 0xCAAC0A0B 
    .word 0xCAACFFFF 
    .word 0x0B0B0000 
    .word 0x2AAC0F0F 
    .word 0x2AAC4000 
    .word 0x0F0C4000 
    .word 0x55560C0D 
    .word 0x5556AAAB
    .word 0x0D0DAAAB 
    .word 0xB5560D0E 
    .word 0xB556CAAC 
    .word 0x0E0FCAAC 
    .word 0xFFFF0F0F 
    .word 0x00002AAC 
    .word 0x17172AAC 
    .word 0x40001714 
    .word 0x40005556 
    .word 0x14155556 
    .word 0xAAAB1515 
    .word 0xAAABB556 
    .word 0x1516B556 
    .word 0xCAAC1617 
    .word 0xCAACFFFF 
    .word 0x17170000

glabel D_8011FC1C
    .incbin "baserom.z64", 0xB96DBC, 0x120

glabel D_8011FD3C
    .word _vr_fine0_staticSegmentRomStart
    .word _vr_fine0_staticSegmentRomEnd
    .word _vr_fine0_pal_staticSegmentRomStart
    .word _vr_fine0_pal_staticSegmentRomEnd
    .word _vr_fine1_staticSegmentRomStart
    .word _vr_fine1_staticSegmentRomEnd
    .word _vr_fine1_pal_staticSegmentRomStart
    .word _vr_fine1_pal_staticSegmentRomEnd
    .word _vr_fine2_staticSegmentRomStart
    .word _vr_fine2_staticSegmentRomEnd
    .word _vr_fine2_pal_staticSegmentRomStart
    .word _vr_fine2_pal_staticSegmentRomEnd
    .word _vr_fine3_staticSegmentRomStart
    .word _vr_fine3_staticSegmentRomEnd
    .word _vr_fine3_pal_staticSegmentRomStart
    .word _vr_fine3_pal_staticSegmentRomEnd
    .word _vr_cloud0_staticSegmentRomStart
    .word _vr_cloud0_staticSegmentRomEnd
    .word _vr_cloud0_pal_staticSegmentRomStart
    .word _vr_cloud0_pal_staticSegmentRomEnd
    .word _vr_cloud1_staticSegmentRomStart
    .word _vr_cloud1_staticSegmentRomEnd
    .word _vr_cloud1_pal_staticSegmentRomStart
    .word _vr_cloud1_pal_staticSegmentRomEnd
    .word _vr_cloud2_staticSegmentRomStart
    .word _vr_cloud2_staticSegmentRomEnd
    .word _vr_cloud2_pal_staticSegmentRomStart
    .word _vr_cloud2_pal_staticSegmentRomEnd
    .word _vr_cloud3_staticSegmentRomStart
    .word _vr_cloud3_staticSegmentRomEnd
    .word _vr_cloud3_pal_staticSegmentRomStart
    .word _vr_cloud3_pal_staticSegmentRomEnd
    .word _vr_holy0_staticSegmentRomStart
    .word _vr_holy0_staticSegmentRomEnd
    .word _vr_holy0_pal_staticSegmentRomStart
    .word _vr_holy0_pal_staticSegmentRomEnd

glabel D_8011FDCC
    .incbin "baserom.z64", 0xB96F6C, 0x4

glabel D_8011FDD0
    .incbin "baserom.z64", 0xB96F70, 0x4

glabel D_8011FDD4
    .incbin "baserom.z64", 0xB96F74, 0x4

glabel D_8011FDD8
    .incbin "baserom.z64", 0xB96F78, 0x28

glabel D_8011FE00
    .incbin "baserom.z64", 0xB96FA0, 0x20

glabel D_8011FE20
    .incbin "baserom.z64", 0xB96FC0, 0x28

glabel D_8011FE48
    .incbin "baserom.z64", 0xB96FE8, 0x28

glabel D_8011FE70
    .incbin "baserom.z64", 0xB97010, 0xC

glabel D_8011FE7C
    .incbin "baserom.z64", 0xB9701C, 0xC

glabel D_8011FE88
    .incbin "baserom.z64", 0xB97028, 0xC

glabel D_8011FE94
    .incbin "baserom.z64", 0xB97034, 0xC

glabel D_8011FEA0
    .incbin "baserom.z64", 0xB97040, 0x24

glabel D_8011FEC4
    .incbin "baserom.z64", 0xB97064, 0xC

glabel D_8011FED0
    .incbin "baserom.z64", 0xB97070, 0x10
