.globl binsearch
binsearch:
	pushl %esi
	pushl %ebx
	pushl %edi
	
	movl 16(%esp), %esi
	movl 20(%esp), %edx
	movl 24(%esp), %ebx
	
	xorl %ecx, %ecx
	xorl %eax, %eax
L:
	cmpl %edx, %ecx
	jge F
	addl %edx, %ecx
	sarl $1, %ecx
	cmpl %ebx, (%esi, %ecx, 4)
	jne E
	movl $1, %eax
	jmp F
E:
	cmpl %ebx, (%esi, %ecx, 4)
	jle E1
	movl %ecx, %edx
	jmp L
E1:
	incl %ecx
	jmp L	
F:	
	popl %edi
	popl %ebx
	popl %esi
	ret
