.globl my_strcat

my_strcat:
	movl 4(%esp), %ecx
	movl 8(%esp), %edx
L:
	cmpb $0, (%ecx)
	je E1
	incl %ecx
	jmp L
E1:
	movb (%edx), %al
	movb %al, (%ecx)
	cmpb $0, (%edx)
	je E2
	incl %ecx
	incl %edx
	jmp E1
E2:
	movl 4(%esp), %eax
	ret
