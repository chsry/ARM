uart.bin:start.s main.c movi.c uart.c clock.c lib.c nand.c lcd.c mem_setup.S
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c start.s -o start.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c main.c -o main.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c movi.c -o movi.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c uart.c -o uart.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c lib.c -o lib.o
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c clock.c -o clock.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c lcd.c -o lcd.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c nand.c -o nand.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c mem_setup.S -o mem_setup.o	
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-ld -T bootloader.lds start.o main.o movi.o uart.o lib.o clock.o lcd.o nand.o mem_setup.o -o uart_elf
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-objcopy -O binary -S uart_elf uart.bin
	./mkbl1 uart.bin uart.bl1

clean:
	rm -rf *.o *.bin uart_elf *.dis *.bl1
