void delay(void)
{
	volatile int i = 0x100000;
	while (i--);
}

void putchar_hex(char c)
{
	char * hex = "0123456789ABCDEF";
	
	uart_putchar(hex[(c>>4) & 0x0F]);
	uart_putchar(hex[(c>>0) & 0x0F]);

	return;
}

int putchar(int c)
{
	if (c == '\n') /* �����������Ϊ\n */
		uart_putchar('\r'); /* �����ն�����س������� */
		
	uart_putchar(c);

	return 0;
}

