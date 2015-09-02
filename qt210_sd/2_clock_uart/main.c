#include "clock.h"
#include "led.h"
#include "uart.h"
#include "lib.h"

int main(void)
{
	led_init(); /* ���ö�Ӧ�ܽ�Ϊ��� */
	clock_init(); /* ��ʼ��ʱ�� */
	uart_init(); /* ��ʼ��UART0 */
	
	uart_putchar('0');
	uart_putchar('x');
	putchar_hex(0x5a);	

	while (1)
	{
		char c = 'x';
		putchar('\n');
		
		c = uart_getchar();
		putchar(c);
		
		for (c = 'a'; c <= 'z'; c++)
			putchar(c);
		break;
	}

	while(1)
	{
		led_water();
	}
	return 0;
}

