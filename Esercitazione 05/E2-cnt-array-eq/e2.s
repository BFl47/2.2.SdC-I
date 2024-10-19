.globl counteq
counteq:
	pushl %ebx			#+4
	pushl %ebp 			#+8
	pushl %edi 			#+12
	
	xorl %ecx, %ecx
	xorl %eax, %eax
	movl 16(%esp), %ebx
	movl 20(%esp), %ebp
L:
	cmpl 24(%esp), %ecx
	jge E
	movw (%ebx, %ecx, 2), %di
	cmpw (%ebp, %ecx, 2), %di
	sete %dl
	movzbl %dl, %edi
	addl %edi, %eax
	incl %ecx
	jmp L
E:	
	popl %edi
	popl %ebp
	popl %ebx
	ret
