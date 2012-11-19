	.file	"strict_alias_optimization.c"
	.text
	.p2align 4,,15
	.globl	_swapWords
	.def	_swapWords;	.scl	2;	.type	32;	.endef
_swapWords:
LFB11:
	.cfi_startproc
	movl	4(%esp), %eax
	roll	$16, (%eax)
	ret
	.cfi_endproc
LFE11:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%08X\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$286326784, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.def	_printf;	.scl	2;	.type	32;	.endef
