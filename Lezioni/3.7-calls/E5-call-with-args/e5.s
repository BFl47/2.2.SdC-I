.globl f
f:
	pushl %ebx 		#4
	pushl %ebp		#8
	subl $4, %esp
	
	movl $1, %ebx
	movl $2, %ebp
	movl 16(%esp), %ecx
	incl %ecx
	movl %ecx, (%esp)
	call g
	addl %ebx, %eax
	addl %ebp, %eax
	
	addl $4, %esp
	popl %ebp
	popl %ebx
	ret
