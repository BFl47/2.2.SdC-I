# scrivere la soluzione qui...
.globl f

f:
	movl 4(%esp), %eax
	movl %eax, %ecx
	
	imull $2, %eax
	imull %ecx, %eax
	
	imull $7, %ecx
	
	subl %ecx, %eax
	incl %eax
	
	ret
