
.globl find_youngest
find_youngest:
	pushl %ebx				#4
	
	movl 8(%esp), %ecx
	movl $0, %eax
	movl $0, %ebx
L:
	cmpl 12(%esp), %ebx
	jge E
	cmpl $0, %eax
	je A
	movb 8(%ecx), %dl
	cmpb 8(%eax), %dl
	jge F
A:
	movl %ecx, %eax
F:
	addl $12, %ecx
	incl %ebx
	jmp L
E:
	popl %ebx
	ret
