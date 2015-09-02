#define GPH0CON		(*(volatile unsigned int *)0xE0200C00)
#define GPH0DAT		(*(volatile unsigned int *)0xE0200C04)

void delay()
{
	volatile int i = 0x100000;
	while (i--);
}

int main(void)
{
	int i = 0;

	/* ÅäÖÃGPJ2_0ÎªÊä³öÒý½Å */
	GPH0CON = 0x1111;

	while (1)
	{		
		GPH0DAT = i;
		i++;
		if (i == 16)
			i = 0;
		delay();
	}

	return 0;
}

