.globl f
f:
	pushl %ebx
	call g
	movl %eax, %ebx
	call h
	addl %ebx, %eax
	popl %ebx
	ret
