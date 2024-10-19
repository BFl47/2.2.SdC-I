.globl f
f:
	pushl %ebx
	pushl %ebp
	subl $4, %esp
	
	movl 16(%esp), %ebx
	movl %ebx, (%esp)
	call g
	movl %eax, %ebp
	call h
	addl %ebp, %eax
	
	addl $4, %esp
	popl %ebp
	popl %ebx
	ret
