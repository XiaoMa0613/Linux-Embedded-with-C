	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"hello.c"       ;当前汇编文件对应的源文件名称
	.text					;代码段的起始地址
	.global	global_val		;声明一个全局符号
	.data					;声明一个数据段
	.align	2				;对齐方式 2*2 4字节对齐
	.type	global_val, %object ;设置该全局符号类型为变量
	.size	global_val, 4		;全局符号大小为4字节
global_val:					;符号入口
	.word	10				;初始化为10
	.global	global_uval		;声明一个全局符号
	.bss					;声明一的未初始化数据段
	.align	2				;4字节对齐长度
	.type	global_uval, %object 	;全局符号为变量
	.size	global_uval, 4		;四字节大小
global_uval:
	.space	4
	.text
	.align	1
	.global	add		;全局符号
	.arch armv7-	;指令集版本
	.syntax unified ;告诉汇编器使用统一的语法格式
	.thumb			;下面的指令应该使用Thumb指令集进行编码
	.thumb_func		;用于标记下面的函数是使用Thumb指令集编写的
	.fpu neon		;汇编器使用FPU和NEON指令集，以便在代码中使用浮点运算和SIMD指令
	.type	add, %function ;该全局符号为函数
add:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}		;将r7寄存器的值入栈，即刚才的栈指针sp
	sub	sp, sp, #12		;栈指针地址-12，直达栈顶
	add	r7, sp, #0		;r7存入当前栈指针
	str	r0, [r7, #4]	;将r7中的值加2作为新地址，将r0的值，也就是1保存到该地址
	str	r1, [r7]		;
	ldr	r2, [r7, #4]	;将r7中的值加2作为新地址，将该地址的值也就是1，存入r2
	ldr	r3, [r7]		;2
	add	r3, r3, r2		;r3 = 1+ 2
	mov	r0, r3			;r0 = 3
	adds	r7, r7, #12 ;r7中的值+12作为新地址，回到栈底，并影响CPSR
	mov	sp, r7 			;回到栈底
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr				;跳转回main函数的下一条指令
	.size	add, .-add	;add函数大小=当前地址（函数结束地址）-add函数开始地址
	.section	.rodata	;定义一个新的section：.rodata只读数据段
	.align	2
.LC0:					;标号，用来表示字符串的地址
	.ascii	"hello world!\000"	;定义一个字符串
	.text						;新的代码段开始的地方
	.align	1				; 以下和add函数类似
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu neon
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}	;将r7和lr压入栈
	sub	sp, sp, #8     ;指针-8
	add	r7, sp, #0		;将当前指针存入r7寄存器
	movs	r1, #2     ;将2存入r1
	movs	r0, #1		;将1存入r0
	bl	add				;跳转到add，bl指令会自动将下一条指令的地址保存到lr中
	str	r0, [r7, #4]
	movw	r0, #:lower16:.LC0
	movt	r0, #:upper16:.LC0
	bl	puts
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}		;执行完程序，恢复r7和pc
	.size	main, .-main ;设置main函数的大小=当前地址 - main开始地址
	.ident	"GCC: (GNU Toolchain for the A-profile Architecture 10.3-2021.07 (arm-10.29)) 10.3.1 20210621" ;编译器标识
	.section	.note.GNU-stack,"",%progbits
