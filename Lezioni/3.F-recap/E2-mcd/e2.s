.globl mcd
mcd:
	pushl %ebx		#4
	
	movl 8(%esp), %eax
	movl 12(%esp), %ecx
L:
	cmpl $0, %ecx
	je E
	movl %ecx, %ebx
	movl %eax, %edx
	sarl $31, %edx
	idiv %ecx
	movl %edx, %ecx
	movl %ebx, %eax
	jmp L
E:	
	popl %ebx
	ret
