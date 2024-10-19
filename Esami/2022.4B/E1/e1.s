.globl crc32b
crc32b:
    pushl %ebx
    pushl %edi
	pushl %ebp
	pushl %esi
	subl $12, %esp
	
	xorl %ebx, %ebx
	notl %ebx
	movl %ebx, %edi
	movl 36(%esp), %ebp
	movl 32(%esp), %esi
L:
	cmpl $0, %ebp
	je E
	
	movb (%esi), %al
	movsbl %al, %eax
	incl %esi
	xorl %edi, %eax
	andl $0xFF, %eax
	movl %eax, 4(%esp)
	leal 8(%esp), %eax
	movl %eax, (%esp)
	call get_constant
	
	sarl $8, %edi
	xorl 8(%esp), %edi
	decl %ebp
	jmp L
E:
	xorl %edi, %ebx
	movl %ebx, %eax

	addl $12, %esp
	popl %esi
	popl %ebp
	popl %edi
	popl %ebx
    ret


#   n       36
#   bytes   32
#   R       28
#   ebx     24
#   edi     20
#   ebp     16
#   esi     12
#   value   8
#   a		4
#   &value
