本系列程序是烧写到sd卡的qt210(512M内存和nand)的裸板程序，全部调试通过。
本系列程序修改自QT210学习日记。首先感谢QT210学习日记原作者。
修改的原因:首先是发现里面附带的程序使用的参数和QT210开发板不一致。另外是需要烧写到nand，相对麻烦一点。
使用说明:
make编译uart.bin
./mkbl1 uart.bin uart.bl1制作烧写文件uart.bl1
./ddubootsdc.sh烧写到sd卡(请确认SD卡为sdb)
tools文件夹中是mkbl1的源程序
修改内容：
1_water_led
原来的程序将LED端口地址设置错误，无法点亮led

2_clock_uart
修改了LED端口

8_reload
将程序从nand复制到内存改为将程序从SD卡复制到内存
程序执行地址为0x36000000

9_bootm
根据android 2.3的uboot当中的头文件，对一些参数进行了修改。内存起始地址为：0x30000000,由两块组成，每块256M。内核起始地址为：0x30008000：内核执行地址为：0x30008040：linux参数地址为:0x30000100
cmd[] = "noinitrd root=/dev/mmcblk0p1 rw console=ttySAC0";是我SD卡上的root，需要根据自己的情况进行修改。
可能由于CPU初始化不完全，linux启动会在中途停止。

10_lcd
根据android 2.3的uboot当中的fimd.c,修改了GPD0CON和GPD0DAT设置参数。原参数无法点亮lcd屏。
    
