
.global _start
	
_start:
	ldr sp, =0xD0030000  /* ��ʼ��ջ����Ϊ����Ҫ����C���� */
	bl clock_init              /* ��ʼ��ʱ�� */
	bl ddr_init                   /* ��ʼ���ڴ� */
	bl nand_init               /* ��ʼ��NAND */

	bl movi_bl2_copy              /* �������� */

	bl main
loop:
	b loop
