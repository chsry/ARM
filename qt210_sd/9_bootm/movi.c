typedef unsigned long ulong;
typedef unsigned int u32;
typedef unsigned short u16;

typedef u32(*copy_sd_mmc_to_mem)
(u32 channel, u32 start_block, u16 block_size, u32 *trg, u32 init);

void movi_bl2_copy(void)
{
	ulong ch;

	ch = *(volatile u32 *)(0xD0037488);
	copy_sd_mmc_to_mem copy_bl2 =
	    (copy_sd_mmc_to_mem) (*(u32 *) (0xD0037F98));

	u32 ret;
	if (ch == 0xEB000000) {
		ret = copy_bl2(0,49, 1024,
			0x36000000, 0);

	}
	else if (ch == 0xEB200000) {
		ret = copy_bl2(2, 49, 1024,
			0x36000000, 0);
		
		}
	else
		return;

	if (ret == 0)
		while (1)
			;
	else
		return;
}

void movi_read_kernl(void)
{
	ulong ch;

	ch = *(volatile u32 *)(0xD0037488);
	copy_sd_mmc_to_mem copy_kernl =
	    (copy_sd_mmc_to_mem) (*(u32 *) (0xD0037F98));

	u32 ret;
	if (ch == 0xEB000000) {
		ret = copy_kernl(0,1073, 8192,
			0x30008000, 0);

	}
	else if (ch == 0xEB200000) {
		ret = copy_kernl(2, 1073, 8192,
			0x30008000, 0);
		
		}
	else
		return;

	if (ret == 0)
		while (1)
			;
	else
		return;
}

