.globl strings_are_upper
strings_are_upper:
	pushl %ebx
	pushl %edi
	pushl %esi
	pushl %ebp
	subl $4, %esp
	
	xorl %eax, %eax
	cmpl $0, 24(%esp)
	je Z
	cmpl $0, 28(%esp)
	jle	Z
	movl 28(%esp), %ecx
	imull $4, %ecx
	movl %ecx, (%esp)
	call malloc
	movl %eax, %ebx
	xorl %edi, %edi
	movl 24(%esp), %ebp
L:
	cmpl 28(%esp), %edi
	jge E
	movl (%ebp, %edi, 4), %esi
	movl $1, (%ebx, %edi, 4)
L1:
	cmpb $0, (%esi)
	je E1
	movb (%esi), %cl
	movsbl %cl, %ecx
	movl %ecx, (%esp)
	call isupper
	cmpl $0, %eax
	jne E2
	movl $0, (%ebx, %edi, 4)
	jmp E1
E2:
	incl %esi
E1:
	incl %edi
	jmp L	
E:
	movl %ebx, %eax	
Z:	
	addl $4, %esp
	popl %ebp
	popl %esi
	popl %edi
	popl %ebx
	ret
	
	
	
#	n			28
#	array		24
#	R			20
#	ebx			16
#	edi			12
#	esi			8	
#	ebp			4
#	param1
