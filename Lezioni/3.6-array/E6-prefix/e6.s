.globl is_prefix

is_prefix:
	movl 4(%esp), %ecx
	movl 8(%esp), %edx
L:
	cmpb $0, (%ecx)
	je E
	cmpb $0, (%edx)
	je E
	movb (%edx), %al
	cmpb %al, (%ecx)
	jne E
	incl %ecx
	incl %edx
	jmp L
E:
	xorl %eax, %eax
	cmpb $0, (%ecx)
	jne F
	movl $1, %eax
F:
	ret
