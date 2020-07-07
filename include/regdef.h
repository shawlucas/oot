/*----------------------------------------------------------------------*
 	Copyright (C) 1998, Nintendo.
 	
 	File		regdef.h
 	Coded    by	Yoshitaka Yasumoto.	Mar  6, 1998.
 	Modified by	
 	
 	$Id: regdef.h,v 1.1.1.1 2002/05/02 03:29:12 blythe Exp $
 *----------------------------------------------------------------------*/
/*
   $4:	IPL3 start instruction (03a04820 IPL3 start instruction)
   $5:	Counter value until the end of 1MB DMA (0004c000-0004f000)
   $6:	First instruction of Exception Handler (25290004 = a40006d0 address)
   $8:	PowerOn=0  Reset=1
   $10:	Current GCLK counter
   $11:	Last DMA processing parameter 0x000003d8
   $v12:Start data 0x00-0x0f of DMEM (cannot be ALL 0 / ALL F)
   $v13:Total value of data from 0x00000400-0x000013ff
*/
#define	zero	      $0
#define	tmp2          $2
#define	tmp           $3
#define	vtmp          $v14
#define	boot_sema     $8
#define	boot_dmadram  $11
#define	boot_ipl3     $4
#define	vboot_dmem    $v12
#define	count_cpudma  $5
#define	snap_ehandler $6
#define	vsum_4k       $v13
#define	sys0          $1	/* Fixed because it is used in rspboot0.s */
#define	sys1          $16
#define	sys2          $17
#define	return	      $31

#define	_li(a,b)	addi	a, zero, b
#define	_mov(a,b)	ori	a, b, 0

#define	VREG		0
#define	VBOOT_DMEM	VREG+0
#define	VSUM_4K		VREG+16
#define	VTMP		VREG+32
#define	SREG		16*3
#define	TMP		SREG+0
#define	BOOT_SEMA	SREG+4
#define	BOOT_DMADRAM	SREG+8
#define	BOOT_IPL3	SREG+12
#define	COUNT_CPUDMA	SREG+16
#define	SNAP_EHANDLER	SREG+20
#define	LATE_CMD_CLOCK	SREG+24
#define	LATE_TMEM_BUSY	SREG+28
#define	LATE_SP_STATUS	SREG+32

/*======== End of regdef.h ========*/
