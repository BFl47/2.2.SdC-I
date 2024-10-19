.globl crc32b
crc32b:
	pushl %esi
	pushl %edi
	pushl %ebp
	pushl %ebx
	subl $12, %esp
	
	xorl %esi, %esi
	notl %esi
	movl %esi, %edi
	movl 32(%esp), %ebx
	movl 36(%esp), %ebp
L:
	cmpl $0, %ebp
	je E
	movsbl (%ebx), %ecx
	incl %ebx
	xorl %edi, %ecx
	andl $0xFF, %ecx
	movl %ecx, 4(%esp)
	leal 8(%esp), %eax
	movl %eax, (%esp)
	call get_constant
	sarl $8, %edi
	xorl 8(%esp), %edi
	decl %ebp
	jmp L
E:
	xorl %edi, %esi
	movl %esi, %eax
	
	addl $12, %esp
	popl %ebx
	popl %ebp
	popl %edi
	popl %esi
	
	ret
