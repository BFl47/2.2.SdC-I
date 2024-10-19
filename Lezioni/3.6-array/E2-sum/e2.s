.globl sum

sum:
	movl 4(%esp), %edx
	xorw %ax, %ax
	xorl %ecx, %ecx
L:
	cmpl 8(%esp), %ecx
	jge E
	addw (%edx, %ecx, 2), %ax
	incl %ecx
	jmp L
E:
	ret
