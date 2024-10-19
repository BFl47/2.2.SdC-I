.globl count1
count1:
	xorl %eax, %eax
	movl 4(%esp), %ecx
L:
	cmpl $0, %ecx
	jbe E
	testl $1, %ecx
	je E1
	incl %eax
E1:
	shrl $1, %ecx
	jmp L
E:
	ret
