.globl check_quiz
check_quiz:
	pushl %esi
	pushl %edi
	pushl %ebp
	pushl %ebx
	subl $4, %esp
	
	xorl %eax, %eax
	
	cmpl $0, 24(%esp)
	je Z
	cmpl $0, 28(%esp)
	je Z
	cmpl $0, 32(%esp)
	jle Z
	
	movl 32(%esp), %edx
	imull $4, %edx
	movl %edx, (%esp)
	call malloc
	
	xorl %ecx, %ecx
	movl 24(%esp), %esi
	movl 28(%esp), %edi
L:
	cmpl 32(%esp), %ecx
	jge Z
	movl $0, (%eax, %ecx, 4)
	xorl %edx, %edx
L1:
	cmpl $4, %edx
	jge E1
	movl (%esi, %ecx, 4), %ebp
	movb (%edi, %edx, 1), %bl
	cmpb %bl, (%ebp, %edx, 1)
	jne E2
	incl (%eax, %ecx, 4)
E2:
	incl %edx
	jmp L1
E1:
	incl %ecx
	jmp L
Z:	
	addl $4, %esp
	popl %ebx
	popl %ebp
	popl %edi
	popl %esi
	ret
	
	
#	n			32
#	solution	28
#	answers		24
#	R			20
#	esi			16
#	edi			12
#	ebp			8
#	ebx			4
#	param
