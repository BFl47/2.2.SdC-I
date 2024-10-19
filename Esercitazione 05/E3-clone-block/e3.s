.globl clone
clone:
	pushl %ebx		#n
	pushl %ebp		#src
	pushl %edi		#a
	subl $4, %esp
	
	movl 24(%esp), %ebx
	movl 20(%esp), %ebp
	movl %ebx, (%esp)
	call malloc
	cmpl $0, %eax
	je E
	movl %eax, %edi
	subl $8, %esp
	movl %ebp, 4(%esp)
	movl %edi, (%esp)
	call memcpy	
	movl %edi, %eax
F:
	addl $8, %esp
E:
	addl $4, %esp
	popl %edi
	popl %ebp
	popl %ebx
	ret
