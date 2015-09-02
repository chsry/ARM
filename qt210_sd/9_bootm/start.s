
.global _start
	
_start:
	ldr sp, =0xD0030000  /* 初始化栈，因为后面要调用C函数 */
	bl clock_init              /* 初始化时钟 */
	bl ddr_init                   /* 初始化内存 */
	bl nand_init               /* 初始化NAND */


	bl movi_bl2_copy              /* 拷贝数据 */

clean_bss:
	ldr r0, =bss_start
	ldr r1, =bss_end
	mov r3, #0
	cmp r0, r1
	ldreq pc, =on_ddr
clean_loop:
	str r3, [r0], #4
	cmp r0, r1	
	bne clean_loop		
	ldr pc, =on_ddr

on_ddr:
	ldr sp, =0x33000000    /* 重新初始化栈，指向内存 */
	ldr pc, =main

