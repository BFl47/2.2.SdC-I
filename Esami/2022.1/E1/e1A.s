.globl str_to_upper
str_to_upper:
	pushl %esi
	pushl %ebx
	pushl %edi
	subl $4, %esp
	
	xorl %eax, %eax
	cmpl $0, 20(%esp)
	je Z
	movl 20(%esp), %esi
	movl %esi, (%esp)
	call strdup
	movl %eax, %edi
	movl %eax, %ebx
L:
	cmpb $0, (%ebx)
	je E
	movb (%ebx), %dl
	movsbl %dl, %edx
	movl %edx, (%esp)
	call toupper
	movb %al, (%ebx)
	incl %ebx
	jmp L
E:
	movl %edi, %eax	
Z:	
	addl $4, %esp
	popl %edi
	popl %ebx
	popl %esi	
	ret
	
	
#	s			20
#	R			16
#	esi			12	
#	ebx			8
#	edi			4
#	param
