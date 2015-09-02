#include "lib.h"

#define GPH2CON		(*(volatile unsigned int *)0xE0200C00)
#define GPH2DAT		(*(volatile unsigned int *)0xE0200C04)

void led_init(void)
{
	/* ����GPJ2_0Ϊ������� */
	GPH2CON = 0x1111;
	GPH2DAT = 1;
}

void led_water(void)
{
	int i = 0;
	while (1)
	{		
		GPH2DAT = i;
		i++;
		if (i == 16)
			i = 0;
		delay();
	}

	return 0;
}

