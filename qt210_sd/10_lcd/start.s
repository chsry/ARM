
.global _start
	
_start:
	ldr sp, =0xD0030000  /* 初始化栈，因为后面要调用C函数 */
	bl clock_init              /* 初始化时钟 */
	bl ddr_init                   /* 初始化内存 */
	bl nand_init               /* 初始化NAND */

	bl movi_bl2_copy              /* 拷贝数据 */

	bl main
loop:
	b loop
