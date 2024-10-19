.globl count_spaces

count_spaces:
	xorl %eax, %eax
	movl 4(%esp), %edx
L:
	cmpb $0, (%edx)
	je E
	cmpb $32, (%edx)
	sete %cl
	movzbl %cl, %ecx
	addl %ecx, %eax
	incl %edx
	jmp L
E:
	ret
