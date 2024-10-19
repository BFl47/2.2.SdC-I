.globl my_strlen

my_strlen:
	xorl %eax, %eax
	movl 4(%esp), %ecx
L:
	cmpb $0, (%ecx)
	je E
	incl %eax
	incl %ecx
	jmp L
E:
	ret
