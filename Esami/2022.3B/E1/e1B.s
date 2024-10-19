.globl count_matching_vars
count_matching_vars:
	pushl %edi
	pushl %esi
	pushl %ebp
	subl $8, %esp
	
	movl $-1, %eax
	cmpl $0, 24(%esp)
	je Z
	cmpl $0, 28(%esp)
	je Z
	
	movl 24(%esp), %esi
	movl 28(%esp), %ebp
	xorl %edi, %edi
L:
	cmpl $0, (%esi)
	je E
	
	movl (%esi), %eax
	movl %eax, (%esp)
	call getenv
	cmpl $0, %eax
	je E1
	movl %eax, (%esp)
	movl %ebp, 4(%esp)
	call strstr
	cmpl $0, %eax
	je E1
	incl %edi
E1:
	addl $4, %esi
	jmp L
E:
	movl %edi, %eax
Z:
	addl $8, %esp
	popl %ebp
	popl %esi
	popl %edi
	ret
	
	
#	pattern 28
#	vars	24
#	R		20
#	edi		16
#	esi		12
#	ebp		8
#	param2	4
#	param1
