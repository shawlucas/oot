#ifndef _ULTRA64_INTERRUPT_H_
#define _ULTRA64_INTERRUPT_H_

typedef u32 OSIntMask;

/* Interrupt masks */

#define OS_IM_NONE      0x00000001
#define OS_IM_SW1       0x00000501
#define OS_IM_SW2       0x00000601
#define OS_IM_CART      0x00000C01
#define OS_IM_PRENMI    0x00001401
#define OS_IM_RDBWRITE  0x00002401
#define OS_IM_RDBREAD   0x00004401
#define OS_IM_COUNTER   0x00008401
#define OS_IM_CPU       0x0000FF01
#define OS_IM_SP        0x00010401
#define OS_IM_SI        0x00020401
#define OS_IM_AI        0x00040401
#define OS_IM_VI        0x00080401
#define OS_IM_PI        0x00100401
#define OS_IM_DP        0x00200401
#define OS_IM_ALL       0x003FFF01
#define	RCP_IMASK	    0x003F0000
#define	RCP_IMASKSHIFT	16

/*
 * Interrupt enable bits
 * (NOTE: bits set to 1 enable the corresponding level interrupt)
 */
#define	SR_IMASK	0x0000FF00	/* Interrupt mask */
#define	SR_IMASK8	0x00000000	/* mask level 8 */
#define	SR_IMASK7	0x00008000	/* mask level 7 */
#define	SR_IMASK6	0x0000c000	/* mask level 6 */
#define	SR_IMASK5	0x0000e000	/* mask level 5 */
#define	SR_IMASK4	0x0000f000	/* mask level 4 */
#define	SR_IMASK3	0x0000f800	/* mask level 3 */
#define	SR_IMASK2	0x0000fc00	/* mask level 2 */
#define	SR_IMASK1	0x0000fe00	/* mask level 1 */
#define	SR_IMASK0	0x0000ff00	/* mask level 0 */

#define	SR_IBIT8	0x00008000	/* bit level 8 */
#define	SR_IBIT7	0x00004000	/* bit level 7 */
#define	SR_IBIT6	0x00002000	/* bit level 6 */
#define	SR_IBIT5	0x00001000	/* bit level 5 */
#define	SR_IBIT4	0x00000800	/* bit level 4 */
#define	SR_IBIT3	0x00000400	/* bit level 3 */
#define	SR_IBIT2	0x00000200	/* bit level 2 */
#define	SR_IBIT1	0x00000100	/* bit level 1 */

#define	SR_IMASKSHIFT	8

#define	SR_KX		0x00000080	/* extended-addr TLB vec in kernel */
#define	SR_SX		0x00000040	/* xtended-addr TLB vec supervisor */
#define	SR_UX		0x00000020	/* xtended-addr TLB vec in user mode */
#define	SR_KSU_MASK	0x00000018	/* mode mask */
#define	SR_KSU_USR	0x00000010	/* user mode */
#define	SR_KSU_SUP	0x00000008	/* supervisor mode */
#define	SR_KSU_KER	0x00000000	/* kernel mode */
#define	SR_ERL		0x00000004	/* Error level, 1=>cache error */
#define	SR_EXL		0x00000002	/* Exception level, 1=>exception */
#define	SR_IE		0x00000001	/* interrupt enable, 1=>enable */

#endif
