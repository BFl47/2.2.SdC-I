.globl find

find:
	xorl %edx, %edx
	movl 4(%esp), %ecx
L:
	cmpl 8(%esp), %edx
	jge E1
	movl 12(%esp), %eax
	cmpl %eax, (%ecx, %edx, 4)
	jne E2
	movl $1, %eax
	jmp E1
E2:
	xorl %eax, %eax
	incl %edx
	jmp L
E1:
	ret
