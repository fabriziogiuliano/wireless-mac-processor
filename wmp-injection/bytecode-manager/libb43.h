#ifndef LIBB43_H
#define LIBB43_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define B43_SHM_UCODE   	0
#define B43_SHM_SHARED 		1
#define B43_SHM_REGS 		2
#define B43_SHM_IHR 		3
#define B43_SHM_RCMTA 		4


#define B43_MMIO_RAM_CONTROL		0x130
#define B43_MMIO_RAM_DATA		0x134
#define B43_MMIO_CHANNEL		0x3F0
#define B43_MMIO_CHANNEL_EXT		0x3F4


#define B43_MMIO_MACCTL		0x120
#define B43_MMIO_PSMDEBUG	0x154

#define B43_MACCTL_PSM_MACEN	0x00000001
#define B43_MACCTL_PSM_RUN	0x00000002
#define B43_MACCTL_PSM_JMP0	0x00000004
#define B43_MACCTL_PSM_DEBUG	0x00002000


/* TSF */
#define B43_MMIO_TSF_0			0x632	/* core rev < 3 only */
#define B43_MMIO_TSF_1			0x634	/* core rev < 3 only */
#define B43_MMIO_TSF_2			0x636	/* core rev < 3 only */
#define B43_MMIO_TSF_3			0x638	/* core rev < 3 only */



struct debugfs_file{
	FILE * f_mmio16read;
	FILE * f_mmio16write;
	FILE * f_mmio32read;
	FILE * f_mmio32write;
	FILE * f_shm16read;
	FILE * f_shm16write;
	FILE * f_shm32read;
	FILE * f_shm32write;
};

void init_file(struct debugfs_file * df);
void close_file(struct debugfs_file * df);


u_int16_t read16(struct debugfs_file * df, int reg);
void maskSet16(struct debugfs_file * df, int reg, int mask, int set);
void write16(struct debugfs_file * df, int reg, int value);
unsigned int shmRead16(struct debugfs_file * df, int routing, int offset);
void shmMaskSet16(struct debugfs_file * df, int routing, int offset, int mask, int set);
void shmRead16_char(struct debugfs_file * df, int routing, int offset, char * buffer);

unsigned int shmRead32_int(struct debugfs_file * df, int routing, int offset);

void shmRead32(struct debugfs_file * df, int routing, int offset, char * buffer);
//void shmSharedRead(struct debugfs_file * df);

void shmWrite16(struct debugfs_file * df, int routing, int offset, int value);
void shmWrite32(struct debugfs_file * df, int routing, int offset, int value);
void shmMaskSet32(struct debugfs_file * df, int routing, int offset, int mask, int set);

void shmSharedRead(struct debugfs_file * df);
void getGprs(struct debugfs_file * df);
void getTSFRegs(struct debugfs_file * df, uint64_t * tsf);

void __debugfs_find(char *);

#endif