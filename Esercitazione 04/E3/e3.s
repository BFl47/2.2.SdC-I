.globl my_strcmp

my_strcmp:
	movl 4(%esp), %edx
	movl 8(%esp), %ecx
L:
	cmpb $0, (%edx)
	je E
	movb (%edx), %al
	cmpb (%ecx), %al
	jne E
	incl %edx
	incl %ecx
	jmp L
E:
	movl (%ecx), %eax
	negl %eax
	addl (%edx), %eax
	ret
