.globl f

f:
	subl $4, %esp
	movl 8(%esp), %eax
	movl %eax, (%esp)
	call g
	incl %eax
	addl $4, %esp
	ret
