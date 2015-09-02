leds_c.bin:start.s main.c
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c -o start.o start.s
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -nostdlib -c -o main.o main.c
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-ld start.o main.o -o led_elf
	/usr/local/arm/arm-2009q3/bin/arm-none-linux-gnueabi-objcopy -O binary -S led_elf led_c.bin
	mkbl1 led_c.bin led.bl1
	
clean:
	rm -rf led_elf led_c.bin *.o

