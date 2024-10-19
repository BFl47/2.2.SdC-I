.globl crc32
crc32:
	pushl %esi
	pushl %ebx

	movl $0xFFFFFFFF, %ecx
	xorl %edx, %edx
	movl 12(%esp), %esi
L:
	cmpl 16(%esp), %edx
	jge E
	movb (%esi, %edx, 1), %al
	movsbl %al, %eax
	xorl %eax, %ecx
	xorl %ebx, %ebx
L1:
	cmpl $8, %ebx
	jge E1
	
	movl %ecx, %eax
	andl $1, %eax
	negl %eax
	andl $0xEDB88320, %eax
	
	sarl $1, %ecx
	xorl %eax, %ecx
	incl %ebx
	jmp L1
E1:
	incl %edx
	jmp L
E:
	notl %ecx
	movl %ecx, %eax
	popl %ebx
	popl %esi
	ret
	
	
#	n		16
#	bytes	12
#	R		8
#	esi		4
#	ebx		
