.globl count_vars
count_vars:
	pushl %ebx
	pushl %esi
	pushl %edi
	subl $4, %esp
	
	xorl %eax, %eax
	cmpl $0, 20(%esp)
	je Z
	cmpl $0, 24(%esp)
	jle Z
	
	movl 24(%esp), %ecx
	imull $4, %ecx
	movl %ecx, (%esp)
	call malloc
	movl %eax, %ebx
	movl 20(%esp), %esi
	xorl %edi, %edi
L:
	cmpl 24(%esp), %edi
	jge E
	movl (%esi, %edi, 4), %edx
	movl %edx, (%esp)
	call getenv
	cmpl $0, %eax
	je E1
	movl $1, (%ebx, %edi, 4)
	jmp E2
E1:
	movl $0, (%ebx, %edi, 4)
E2:
	incl %edi
	jmp L
E:
	movl %ebx, %eax	
Z:	
	addl $4, %esp
	popl %edi
	popl %esi
	popl %ebx
	ret 
	
	
#	n		24
#	vars	20
#	R		16
#	ebx		12
#	esi		8
#	edi		4
#	param
