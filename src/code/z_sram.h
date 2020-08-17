#ifndef _Z_SRAM_H
#define _Z_SRAM_H

#define DEBUG_MODE 1
#define SRAM_START_ADDR       (void *)0x08000000

#define ssSRAMRead(p,s,sz)    Sram_ReadWrite(s, p, sz, OS_READ)
#define ssSRAMWrite(s,p,sz)   Sram_ReadWrite(s, p, sz, OS_WRITE)

#define Save_Size       (sizeof(int)/sizeof(u8))
#define SAVE_BASE       ( Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size )
             
#define REG0	'Z'
#define REG1	'E'
#define REG2	'L'
#define REG3	'D'
#define REG4	'A'
#define REG5	'Z'

#define CHECK_SUM S_Save.checkSum

#define	REGCK_ALL( no ) 	(sram->read_buff[sram_save_address[no]+(SAVE_BASE)+0] == REG0 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+1] == REG1 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+2] == REG2 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+3] == REG3 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+4] == REG4 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+5] == REG5 )

#define SAVE_SIZE	5200
#define SRAM_Point00	0x20
#define SRAM_Point01	SRAM_Point00 + SAVE_SIZE
#define SRAM_Point02	SRAM_Point01 + SAVE_SIZE
#define SRAM_Point10	SRAM_Point02 + SAVE_SIZE
#define SRAM_Point11	SRAM_Point10 + SAVE_SIZE
#define SRAM_Point12	SRAM_Point11 + SAVE_SIZE

#define SAVE_MAX	(SAVE_BASE + sizeof(Memory)/sizeof(u8))
#define SAVE_SAVECT	(SAVE_BASE + sizeof(S_Private.newf)/sizeof(u8))
#define SAVE_NAME	(SAVE_SAVECT + sizeof(unshort)/sizeof(u8))
#define SAVE_64DD	(SAVE_NAME + sizeof(S_Private.playerName)/sizeof(u8))
#define SAVE_LIFE	(SAVE_64DD + sizeof(short)/sizeof(u8))
#define SAVE_ITEM	((SAVE_BASE + (sizeof(S_Private)/sizeof(u8)) + (sizeof(S_Used)/sizeof(u8))  + (sizeof(S_Table)/sizeof(u8))) - (sizeof(long)/sizeof(u8) + sizeof(S_Table.key_compass_map)/sizeof(u8) + sizeof(S_Table.key_register)/sizeof(u8)+ sizeof(unshort)/sizeof(u8)) )
#define SAVE_HEART	((SAVE_BASE + (sizeof(S_Private)/sizeof(u8)) + (sizeof(S_Used)/sizeof(u8))  + (sizeof(S_Table)/sizeof(u8))) - (sizeof(S_Table.key_register)/sizeof(u8)+ sizeof(unshort)/sizeof(u8)) )
#if defined(PAL_VERSION)
#define SAVE_LIFE_NOW	(SAVE_LIFE + sizeof(short)/sizeof(u8))
#endif

#endif
