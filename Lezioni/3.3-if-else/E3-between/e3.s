
.globl between

between:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl 12(%esp), %edx
	
	cmpl %ecx, %eax
	jg F
	cmpl %edx, %ecx
	jg F
	movl $1, %eax
	jmp E
F:
	xorl %eax, %eax
E:
	ret
