#ifndef _ULTRA64_HARDWARE_H_
#define _ULTRA64_HARDWARE_H_

#define HW_REG(reg, type) *(volatile type*)((reg) | 0xA0000000)
#define PHYS_TO_K1(x) ((x)| 0xA0000000)

#define AI_DRAM_ADDR_REG        0x04500000
#define AI_LEN_REG              0x04500004
#define AI_CONTROL_REG          0x04500008
#define AI_STATUS_REG           0x0450000C
#define AI_STATUS_AI_FULL       (1 << 31)
#define AI_STATUS_AI_BUSY       (1 << 30)
#define AI_DACRATE_REG          0x04500010
#define AI_BITRATE_REG          0x04500014

#define VI_STATUS_REG           0x04400000
#define VI_CONTROL_REG          0x04400000
#define VI_ORIGIN_REG           0x04400004
#define VI_DRAM_ADDR_REG        0x04400004
#define VI_WIDTH_REG            0x04400008
#define VI_H_WIDTH_REG          0x04400008
#define VI_INTR_REG             0x0440000C
#define VI_V_INTER_REG          0x0440000C
#define VI_CURRENT_REG          0x04400010
#define VI_V_CURRENT_LINE_REG   0x04400010
#define VI_BURST_REG            0x04400014
#define VI_TIMING_REG           0x04400014
#define VI_V_SYNC_REG           0x04400018 //VI vertical sync
#define VI_H_SYNC_REG           0x0440001C //VI horizontal sync
#define VI_LEAP_REG             0x04400020   //VI horizontal sync leap
#define VI_H_SYNC_LEAP_REG      0x04400020
#define VI_H_START_REG          0x04400024 //VI horizontal video
#define VI_H_VIDEO_REG          0x04400024
#define VI_V_START_REG          0x04400028 //VI vertical video
#define VI_V_VIDEO_REG          0x04400028
#define VI_V_BURST_REG          0x0440002C //VI vertical burst
#define VI_X_SCALE_REG          0x04400030 //VI x-scale
#define VI_Y_SCALE_REG          0x04400034 //VI y-scale

#define SP_IMEM_START           0x04001000
#define SP_DMEM_START           0x04000000

#define SP_MEM_ADDR_REG         0x04040000
#define SP_DRAM_ADDR_REG        0x04040004
#define SP_RD_LEN_REG           0x04040008
#define SP_WR_LEN_REG           0x0404000C
#define SP_STATUS_REG           0x04040010
#define SP_PC_REG               0x04080000

#define PI_DOM1_ADDR1           0x06000000 /* to 0x07FFFFFF */
#define PI_DOM1_ADDR2           0x10000000 /* to 0x1FBFFFFF */
#define PI_DOM1_ADDR3           0x1FD00000 /* to 0x7FFFFFFF */
#define PI_DOM2_ADDR1           0x05000000 /* to 0x05FFFFFF */
#define PI_DOM2_ADDR2           0x08000000 /* to 0x0FFFFFFF */

#define PI_DRAM_ADDR_REG        0x04600000    //PI DRAM address
#define PI_CART_ADDR_REG        0x04600004    //PI pbus (cartridge) address
#define PI_RD_LEN_REG           0x04600008       //PI read length
#define PI_WR_LEN_REG           0x0460000C       //PI write length
#define PI_STATUS_REG           0x04600010       //PI status
#define PI_BSD_DOM1_LAT_REG     0x04600014 //PI dom1 latency
#define PI_DOMAIN1_REG          0x04600014
#define PI_BSD_DOM1_PWD_REG     0x04600018 //PI dom1 pulse width
#define PI_BSD_DOM1_PGS_REG     0x0460001C //PI dom1 page size
#define PI_BSD_DOM1_RLS_REG     0x04600020 //PI dom1 release
#define PI_BSD_DOM2_LAT_REG     0x04600024 //PI dom2 latency
#define PI_DOMAIN2_REG          0x04600024
#define PI_BSD_DOM2_PWD_REG     0x04600028 //PI dom2 pulse width
#define PI_BSD_DOM2_PGS_REG     0x0460002C //PI dom2 page size
#define PI_BSD_DOM2_RLS_REG     0x04600030 //PI dom2 release

#define PI_STATUS_BUSY          0x1
#define PI_STATUS_IOBUSY        0x2
#define PI_STATUS_ERROR         0x3

#define PI_STATUS_RESET_CONTROLLER  0x1
#define PI_STATUS_CLEAR_INTR        0x2

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

/*
 * Cause Register
 */
#define	CAUSE_BD	    0x80000000	/* Branch delay slot */
#define	CAUSE_CEMASK	0x30000000	/* coprocessor error */
#define	CAUSE_CESHIFT	28

/* Interrupt pending bits */
#define	CAUSE_IP8	    0x00008000	/* External level 8 pending - COMPARE */
#define	CAUSE_IP7	    0x00004000	/* External level 7 pending - INT4 */
#define	CAUSE_IP6	    0x00002000	/* External level 6 pending - INT3 */
#define	CAUSE_IP5	    0x00001000	/* External level 5 pending - INT2 */
#define	CAUSE_IP4	    0x00000800	/* External level 4 pending - INT1 */
#define	CAUSE_IP3	    0x00000400	/* External level 3 pending - INT0 */
#define	CAUSE_SW2	    0x00000200	/* Software level 2 pending */
#define	CAUSE_SW1	    0x00000100	/* Software level 1 pending */

#define	CAUSE_IPMASK	0x0000FF00	/* Pending interrupt mask */
#define	CAUSE_IPSHIFT	8

#define	CAUSE_EXCMASK	0x0000007C	/* Cause code bits */

/*
 * Status register
 */
#define	SR_CUMASK	    0xF0000000	/* coproc usable bits */
#define	SR_CU3		    0x80000000	/* Coprocessor 3 usable */
#define	SR_CU2		    0x40000000	/* Coprocessor 2 usable */
#define	SR_CU1		    0x20000000	/* Coprocessor 1 usable */
#define	SR_CU0		    0x10000000	/* Coprocessor 0 usable */
#define	SR_RP		    0x08000000	/* Reduced power (quarter speed) */
#define	SR_FR		    0x04000000	/* MIPS III FP register mode */
#define	SR_RE		    0x02000000	/* Reverse endian */
#define	SR_ITS		    0x01000000	/* Instruction trace support */
#define	SR_BEV		    0x00400000	/* Use boot exception vectors */
#define	SR_TS		    0x00200000	/* TLB shutdown */
#define	SR_SR		    0x00100000	/* Soft reset occured */
#define	SR_CH		    0x00040000	/* Cache hit for last 'cache' op */
#define	SR_CE		    0x00020000	/* Create ECC */
#define	SR_DE		    0x00010000	/* ECC of parity does not cause error */

/*
 * floating-point status register 
 */
#define FPCSR_FS	    0x01000000	/* flush denorm to zero */
#define	FPCSR_C		    0x00800000	/* condition bit */	
#define	FPCSR_CE	    0x00020000	/* cause: unimplemented operation */
#define	FPCSR_CV	    0x00010000	/* cause: invalid operation */
#define	FPCSR_CZ	    0x00008000	/* cause: division by zero */
#define	FPCSR_CO	    0x00004000	/* cause: overflow */
#define	FPCSR_CU	    0x00002000	/* cause: underflow */
#define	FPCSR_CI	    0x00001000	/* cause: inexact operation */
#define	FPCSR_EV	    0x00000800	/* enable: invalid operation */
#define	FPCSR_EZ	    0x00000400	/* enable: division by zero */
#define	FPCSR_EO	    0x00000200	/* enable: overflow */
#define	FPCSR_EU	    0x00000100	/* enable: underflow */
#define	FPCSR_EI	    0x00000080	/* enable: inexact operation */
#define	FPCSR_FV	    0x00000040	/* flag: invalid operation */
#define	FPCSR_FZ	    0x00000020	/* flag: division by zero */
#define	FPCSR_FO	    0x00000010	/* flag: overflow */
#define	FPCSR_FU	    0x00000008	/* flag: underflow */
#define	FPCSR_FI	    0x00000004	/* flag: inexact operation */
#define	FPCSR_RM_MASK	0x00000003	/* rounding mode mask */
#define	FPCSR_RM_RN	    0x00000000	/* round to nearest */
#define	FPCSR_RM_RZ	    0x00000001	/* round to zero */
#define	FPCSR_RM_RP	    0x00000002	/* round to positive infinity */
#define	FPCSR_RM_RM	    0x00000003	/* round to negative infinity */

#endif
