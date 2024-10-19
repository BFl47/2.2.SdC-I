# Scrivi la soluzione qui...
.globl f
f:
	subl $24, %esp
	
	movl 28(%esp), %eax
	movl %eax, 8(%esp)
	movl 32(%esp), %eax
	movl %eax, 12(%esp)
	
	leal 20(%esp), %eax
	movl %eax, 4(%esp)
	leal 16(%esp), %eax
	movl %eax, (%esp)
	call get_div_rem
	movl 16(%esp), %eax	
	
	addl $24, %esp
	ret
