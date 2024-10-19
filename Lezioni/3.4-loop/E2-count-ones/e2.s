
.globl count1

count1:
	xorl %eax, %eax
	movl 4(%esp), %ecx
L:
	testl %ecx, %ecx
	jbe E
	testl $1, %ecx
	je F
	incl %eax
F:
	shrl $1, %ecx
	jmp L
E:
	ret
