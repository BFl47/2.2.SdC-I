.globl adler32_simplified
adler32_simplified:
	pushl %ebx
	pushl %esi
	
	movl 12(%esp), %esi
	xorl %ecx, %ecx
	movl $1, %eax
	xorl %ebx, %ebx
L:
	cmpl 16(%esp), %ecx
	jge E	
	
	movb (%esi, %ecx, 1), %dl
	movzbl %dl, %edx
	addl %edx, %eax
	andl $0xFFFF, %eax
	
	addl %eax, %ebx
	andl $0xFFFF, %ebx
	
	incl %ecx
	jmp L
E:
	shll $16, %ebx
	orl %ebx, %eax
	
	popl %esi
	popl %ebx
	ret
	
	
#	len		16
#	data	12
#	R		8
#	ebx		4
#	esi
