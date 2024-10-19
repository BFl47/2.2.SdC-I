.globl count_digits
count_digits:
	movl 4(%esp), %ecx
	xorl %eax, %eax
L:
	cmpb $0, (%ecx)
	je F
	cmpb $48, (%ecx)
	jl E
	cmpb $57, (%ecx)
	jg E
	incl %eax
E:
	incl %ecx
	jmp L
F:
	ret

