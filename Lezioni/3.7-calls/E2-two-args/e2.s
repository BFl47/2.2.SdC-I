.globl f

f:
	subl $8, %esp
	movl $2, (%esp)
	movl $5, 4(%esp)
	call g
	incl %eax
	addl $8, %esp
	ret
