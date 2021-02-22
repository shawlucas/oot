#ifndef _ULTRA64_HARDWARE_H_
#define _ULTRA64_HARDWARE_H_

#define HW_REG(reg, type) *(volatile type*)((reg) | 0xA0000000)

#define AI_DRAM_ADDR_REG 0x04500000
#define AI_LEN_REG 0x04500004
#define AI_CONTROL_REG 0x04500008
#define AI_STATUS_REG 0x0450000C
#define AI_STATUS_AI_FULL (1 << 31)
#define AI_STATUS_AI_BUSY (1 << 30)
#define AI_DACRATE_REG 0x04500010
#define AI_BITRATE_REG 0x04500014

#define VI_STATUS_REG 0x04400000
#define VI_CONTROL_REG 0x04400000
#define VI_ORIGIN_REG 0x04400004
#define VI_DRAM_ADDR_REG 0x04400004
#define VI_WIDTH_REG 0x04400008
#define VI_H_WIDTH_REG 0x04400008
#define VI_INTR_REG 0x0440000C
#define VI_V_INTER_REG 0x0440000C
#define VI_CURRENT_REG 0x04400010
#define VI_V_CURRENT_LINE_REG 0x04400010
#define VI_BURST_REG 0x04400014
#define VI_TIMING_REG 0x04400014
#define VI_V_SYNC_REG 0x04400018 //VI vertical sync
#define VI_H_SYNC_REG 0x0440001C //VI horizontal sync
#define VI_LEAP_REG 0x04400020   //VI horizontal sync leap
#define VI_H_SYNC_LEAP_REG 0x04400020
#define VI_H_START_REG 0x04400024 //VI horizontal video
#define VI_H_VIDEO_REG 0x04400024
#define VI_V_START_REG 0x04400028 //VI vertical video
#define VI_V_VIDEO_REG 0x04400028
#define VI_V_BURST_REG 0x0440002C //VI vertical burst
#define VI_X_SCALE_REG 0x04400030 //VI x-scale
#define VI_Y_SCALE_REG 0x04400034 //VI y-scale

#define SP_IMEM_START 0x04001000
#define SP_DMEM_START 0x04000000

#define SP_MEM_ADDR_REG 0x04040000
#define SP_DRAM_ADDR_REG 0x04040004
#define SP_RD_LEN_REG 0x04040008
#define SP_WR_LEN_REG 0x0404000C
#define SP_STATUS_REG 0x04040010
#define SP_PC_REG 0x04080000

#define PI_DRAM_ADDR_REG 0x04600000    //PI DRAM address
#define PI_CART_ADDR_REG 0x04600004    //PI pbus (cartridge) address
#define PI_RD_LEN_REG 0x04600008       //PI read length
#define PI_WR_LEN_REG 0x0460000C       //PI write length
#define PI_STATUS_REG 0x04600010       //PI status
#define PI_BSD_DOM1_LAT_REG 0x04600014 //PI dom1 latency
#define PI_DOMAIN1_REG 0x04600014
#define PI_BSD_DOM1_PWD_REG 0x04600018 //PI dom1 pulse width
#define PI_BSD_DOM1_PGS_REG 0x0460001C //PI dom1 page size
#define PI_BSD_DOM1_RLS_REG 0x04600020 //PI dom1 release
#define PI_BSD_DOM2_LAT_REG 0x04600024 //PI dom2 latency
#define PI_DOMAIN2_REG 0x04600024
#define PI_BSD_DOM2_PWD_REG 0x04600028 //PI dom2 pulse width
#define PI_BSD_DOM2_PGS_REG 0x0460002C //PI dom2 page size
#define PI_BSD_DOM2_RLS_REG 0x04600030 //PI dom2 release

#define PI_DOM1_ADDR1 0x06000000 /* to 0x07FFFFFF */
#define PI_DOM1_ADDR2 0x10000000 /* to 0x1FBFFFFF */
#define PI_DOM1_ADDR3 0x1FD00000 /* to 0x7FFFFFFF */
#define PI_DOM2_ADDR1 0x05000000 /* to 0x05FFFFFF */
#define PI_DOM2_ADDR2 0x08000000 /* to 0x0FFFFFFF */

#define PI_DOMAIN1                0
#define PI_DOMAIN2                1

#define PI_STATUS_BUSY 0x1
#define PI_STATUS_IOBUSY 0x2
#define PI_STATUS_ERROR 0x3

#define PI_STATUS_RESET_CONTROLLER 0x1
#define PI_STATUS_CLEAR_INTR 0x2

#define SI_DRAM_ADDR_REG 0x04800000
#define SI_PIF_ADDR_RD64B_REG 0x04800004
#define SI_PIF_ADDR_WR64B_REG 0x04800010
#define SI_STATUS_REG 0x04800018

#define SI_STATUS_DMA_BUSY 0x1
#define SI_STATUS_IO_READ_BUSY 0x2
#define SI_STATUS_DMA_ERROR 0x8
#define SI_STATUS_INTERRUPT (1 << 12)

#define PIF_RAM_START 0x1FC007C0

#define MI_INIT_MODE_REG 0x04300000
#define MI_MODE_REG MI_INIT_MODE_REG
#define MI_VERSION_REG 0x04300004
#define MI_INTR_REG 0x04300008
#define MI_INTR_MASK_REG 0x0430000C

/* source: fpu.h, OpenBSD */

#define FPCSR_FS    0x01000000

/* cause bits */
#define	FPCSR_C_E	0x00020000	/* unimplemented operation */
#define	FPCSR_C_V	0x00010000	/* invalid operation */
#define	FPCSR_C_Z	0x00008000	/* division by zero */
#define	FPCSR_C_O	0x00004000	/* overflow */
#define	FPCSR_C_U	0x00002000	/* underflow */
#define	FPCSR_C_I	0x00001000	/* inexact */

/* enable bits */
#define	FPCSR_E_V	0x00000800	/* invalid operation */
#define	FPCSR_E_Z	0x00000400	/* division by zero */
#define	FPCSR_E_O	0x00000200	/* overflow */
#define	FPCSR_E_U	0x00000100	/* underflow */
#define	FPCSR_E_I	0x00000080	/* inexact */

/* flags bits */
#define	FPCSR_F_V	0x00000040	/* invalid operation */
#define	FPCSR_F_Z	0x00000020	/* division by zero */
#define	FPCSR_F_O	0x00000010	/* overflow */
#define	FPCSR_F_U	0x00000008	/* underflow */
#define	FPCSR_F_I	0x00000004	/* inexact */

/* Status Register Flags */
#define SR_CU0      0x10000000 /* Coprocessor 0 Usable */
#define SR_CU1      0x20000000 /* Coprocessor 1 Usable */
#define SR_CU2      0x40000000 /* Coprocessor 2 Usable */
#define SR_XX       0x80000000 /* MIPS IV Instructions Usable */

/* Interrupt pending bits */
#define CAUSE_IP8   0x00008000  /* External level 8 pending - COMPARE */
#define CAUSE_IP7   0x00004000  /* External level 7 pending - INT4    */
#define CAUSE_IP6   0x00002000  /* External level 6 pending - INT3    */
#define CAUSE_IP5   0x00001000  /* External level 5 pending - INT2    */
#define CAUSE_IP4   0x00000800  /* External level 4 pending - INT1    */
#define CAUSE_IP3   0x00000400  /* External level 3 pending - INT0    */
#define CAUSE_SW2   0x00000200  /* Software level 2 pending           */
#define CAUSE_SW1   0x00000100  /* Software level 1 pending           */

#endif
