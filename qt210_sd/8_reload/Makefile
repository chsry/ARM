uart.bin:start.s main.c uart.c clock.c led.c lib.c command.c nand.c movi.c mem_setup.S
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c start.s -o start.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c main.c -o main.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c uart.c -o uart.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c lib.c -o lib.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c clock.c -o clock.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c led.c -o led.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c command.c -o command.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c nand.c -o nand.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c movi.c -o movi.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c mem_setup.S -o mem_setup.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-ld -T bootloader.lds start.o main.o uart.o lib.o clock.o led.o command.o nand.o movi.o mem_setup.o -o uart_elf
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-objcopy -O binary -S uart_elf uart.bin

clean:
	rm -rf *.o *.bin uart_elf *.dis
