.globl div_vectors
div_vectors:
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
	je Z
	
	movl 32(%esp), %ecx
	imull $4, %ecx
	movl %ecx, (%esp)
	call malloc
	movl %eax, %ebx
	
	movl 24(%esp), %esi
	movl 28(%esp), %edi
	xorl %ecx, %ecx
L:
	cmpl 32(%esp), %ecx
	jge E
	movl (%esi, %ecx, 4), %eax
	movl %eax, %edx
	shrl $31, %edx
	movl (%edi, %ecx, 4), %ebp
	idiv %ebp
	movl %eax, (%ebx, %ecx, 4)
	incl %ecx
	jmp L
E:
	movl %ebx, %eax
Z:	
	addl $4, %esp
	popl %ebx
	popl %ebp
	popl %edi
	popl %esi
	ret


#	n			32
#	b			28
#	a			24
#	R			20
#	esi			16
#	edi			12
#	ebp			8
#	ebx			4
#	param
