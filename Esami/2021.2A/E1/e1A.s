.globl count_tokens
count_tokens:
	pushl %ebx
	pushl %esi
	pushl %edi
	pushl %ebp
	subl $8, %esp
	
	movl 28(%esp), %edi
	movl 32(%esp), %ebp
	xorl %ebx, %ebx
	movl %edi, (%esp)
	movl %ebp, 4(%esp)
	call strtok
	movl %eax, %esi
L:
	cmpl $0, %esi
	je E
	incl %ebx
	movl $0, (%esp)
	call strtok
	movl %eax, %esi
	jmp L
E:
	movl %ebx, %eax	
	addl $8, %esp
	popl %ebp
	popl %edi
	popl %esi
	popl %ebx
	ret
	
	
#	sep		32
#	str		28
#	R		24
#	ebx		20
#	esi		16
#	edi		12
#	ebp		8
#	param2	4
#	param1	
