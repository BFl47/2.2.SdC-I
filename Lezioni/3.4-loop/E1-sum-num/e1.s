
.globl sum

sum:
	xorl %eax, %eax
	movl 4(%esp), %ecx
L:
	testl %ecx, %ecx
	jle E
	addl %ecx, %eax
	decl %ecx
	jmp L
E:
	ret
