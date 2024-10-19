.globl suffix
suffix:
	pushl %ebx
	pushl %ebp
	pushl %esi
	subl $4, %esp
	
	movl 24(%esp), %ebp
	movl 20(%esp), %esi
	
	movl %ebp, (%esp)
	call strlen
	movl %eax, %ebx
	
	movl %esi, (%esp)
	call strlen
	
	cmpl %eax, %ebx
	jg E
	movl %eax, %ecx
	subl %ebx, %ecx
L:
	cmpl %eax, %ecx
	jge E1
	movb (%ebp), %dl
	cmpb %dl, (%esi, %ecx, 1)
	jne E
	incl %ebp
	incl %ecx
	jmp L
E1:
	movl $1, %eax
	jmp Z
E:
	xorl %eax, %eax
Z:	
	addl $4, %esp
	popl %esi
	popl %ebp
	popl %ebx
	ret
	
#	b		24
#	a		20
#	R		16
#	ebx		12
#	ebp		8
#	esi		4
#	param
