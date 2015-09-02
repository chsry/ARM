#!/bin/bash
####################################
#<BL1 fusing>
bl1_position=1
uboot_position=49

echo "BL1 fusing"
dd seek=1 if=uart.bl1 of=/dev/sdb oflag=dsync

####################################
#<u-boot fusing>
echo "u-boot fusing"
dd iflag=dsync oflag=dsync if=uart.bin of=/dev/sdb seek=$uboot_position

####################################
#<Message Display>
echo "U-boot image is fused successfully."
echo "Eject SD card and insert it to qt210."

