	.file	"funktionstafel.c"
	.text
	.section	.rodata
.LC0:
	.string	"%4d %11d %11d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	jmp	.L2
.L7:
	movl	-4(%rbp), %eax
	imull	%eax, %eax
	movl	%eax, -24(%rbp)
	movl	$1, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L3
.L4:
	sall	-8(%rbp)
	subl	$1, -12(%rbp)
.L3:
	cmpl	$0, -12(%rbp)
	jg	.L4
	movl	$1, -16(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	.L5
.L6:
	movl	-16(%rbp), %eax
	imull	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
	subl	$1, -20(%rbp)
.L5:
	cmpl	$0, -20(%rbp)
	jg	.L6
	movl	-16(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L2:
	cmpl	$99, -4(%rbp)
	jle	.L7
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.3.1 20230508 (Red Hat 12.3.1-1)"
	.section	.note.GNU-stack,"",@progbits
