#include <rcp.h>
#include <rsp.h>
#include <os.h>
#include <sptask.h>

.text		RSPBOOTBASE

.name	zero,	$0
.name	taskp,	$1
.name	tmp,	$30
.name	return,	$31
	
RSPBoot: # Jumps to the beginning of the boot routine	
		j checkDP
 		addi taskp, zero, 0xFC0

loadUCode:
		lw	$2, 0x10(taskp) # ucode pointer
		addi $3, zero, ((4096)+(-(32*4))+(-1))	# ucode size

.name	task_base,	$7

		addi	task_base, zero, TASKBASELO
		mtc0	$7, DMA_CACHE
		mtc0	$2, DMA_DRAM
		mtc0	$3, DMA_READ_LENGTH

loadcodeloop:	
		mfc0 $4, $6	# wait for the code to load
		bne	$4, zero, loadcodeloop
		nop
		jal	YieldCheck	
		nop
 		jr	task_base
		mtc0 zero, SP_RESERVED

.name	yield,	$8
YieldCheck:
		mfc0    yield, SP_STATUS
		andi    yield, yield, SP_STATUS_YIELD
		bne     yield, zero, doYield
		nop
		jr	return

#define BOOT_YIELD (SP_SET_TASKDONE|SP_SET_YIELDED|SP_CLR_YIELD)
doYield:
		mtc0	zero, SP_RESERVED
		ori     yield, zero, BOOT_YIELD
		mtc0    yield, SP_STATUS
		break
		nop

.unname	yield

.name	flag,	$2
checkDP:
			lw	flag, 0x4(taskp) 
			andi	flag, flag, OS_TASK_DP_WAIT
			beq	flag, zero, LoadDMEM
			nop
			jal	YieldCheck
			nop

doDPWait:		
			mfc0 flag, CMD_STATUS
			andi flag, flag, 0x100	# dma busy
			bgtz flag, YieldCheck
			nop
.unname	flag

.name	daddr,	$2
.name	dsize,	$3
LoadDMEM:
		lw	daddr, 0x18(taskp)
		lw	dsize, 0x1C(taskp)
		addi	dsize, dsize, -1

#if 0
	ReqDMA:
		mfc0	tmp, SP_RESERVED
		bne	tmp, zero, ReqDMA
		nop
#endif
	DMAFull:
		mfc0	tmp, DMA_FULL
		bne	tmp, zero, DMAFull
		nop
		mtc0	zero, DMA_CACHE
		mtc0	daddr, DMA_DRAM
		mtc0	dsize, DMA_READ_LENGTH

loaddataloop:	
		mfc0	$4, $6
		bne	$4, zero, loaddataloop
		nop
		jal	YieldCheck
		nop
 		j	loadUCode
		nop
		nop

.unname	daddr
.unname	dsize
.unname	zero
.unname	tmp
.unname	return
