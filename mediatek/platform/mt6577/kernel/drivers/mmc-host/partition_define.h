#ifndef __PARTITION_DEFINE_H__
#define __PARTITION_DEFINE_H__

//#define SLOT_PER_MBR 4
//#define MBR_COUNT 8


#define KB  (1024)
#define MB  (1024 * KB)
#define GB  (1024 * MB)

#define PART_SIZE_PRELOADER			(256*KB)
#define PART_SIZE_DSP_BL			(5888*KB)
#define PART_SIZE_MBR			(16*KB)
#define PART_SIZE_EBR1			(368*KB)
#define PART_SIZE_PMT			(4096*KB)
#define PART_SIZE_NVRAM			(3072*KB)
#define PART_SIZE_SECCFG			(128*KB)
#define PART_SIZE_UBOOT			(384*KB)
#define PART_SIZE_BOOTIMG			(6144*KB)
#define PART_SIZE_RECOVERY			(6144*KB)
#define PART_SIZE_SEC_RO			(6144*KB)
#define PART_SIZE_MISC			(384*KB)
#define PART_SIZE_LOGO			(3072*KB)
#define PART_SIZE_EXPDB			(640*KB)
#define PART_SIZE_EBR2			(16*KB)
#define PART_SIZE_ANDROID			(525312*KB)
#define PART_SIZE_CACHE			(525312*KB)
#define PART_SIZE_USRDATA			(525312*KB)
#define PART_SIZE_FAT			(0*KB)
#define PART_SIZE_BMTPOOL			(0x50)


#define PART_NUM			20

#define MBR_START_ADDRESS_BYTE			(6144*KB)

#define WRITE_SIZE_Byte		512
typedef enum  {
	EMMC = 1,
	NAND = 2,
} dev_type;

typedef enum {
	USER = 0,
	BOOT_1,
	BOOT_2,
	RPMB,
	GP_1,
	GP_2,
	GP_3,
	GP_4,
} Region;


struct excel_info{
	char * name;
	unsigned long long size;
	unsigned long long start_address;
	dev_type type ;
	unsigned int partition_idx;
	Region region;
};

#ifdef  MTK_EMMC_SUPPORT
/*MBR or EBR struct*/
#define SLOT_PER_MBR 4
#define MBR_COUNT 8

struct MBR_EBR_struct{
	char part_name[8];
	int part_index[SLOT_PER_MBR];
};

extern struct MBR_EBR_struct MBR_EBR_px[MBR_COUNT];
#endif
extern struct excel_info PartInfo[PART_NUM];
#endif

