.globl bubble_sort
bubble_sort:
	pushl %edi
	pushl %ebx
	pushl %esi
	subl $8, %esp
	
	movl 24(%esp), %esi
L:
	xorl %edi, %edi
	movl $1, %ebx
L1:
	cmpl 28(%esp), %ebx
	jae E
	movw (%esi, %ebx, 2), %dx
	cmpw %dx, -2(%esi, %ebx, 2)
	jle E1
	leal (%esi, %ebx, 2), %edx
	movl %edx, 4(%esp)
	
	leal -2(%esi, %ebx, 2), %edx
	movl %edx, (%esp)
	
	call swap
	movl $1, %edi
E1:
	incl %ebx
	jmp L1
E:
	cmpl $1, %edi
	je L
	
	addl $8, %esp
	popl %esi
	popl %ebx
	popl %edi
	ret




#	n			28
#	v			24
#	R			20
#	edi			16
#	ebx			12
#	esi			8
#	&d[c]		4
#	&d[c-1]		
