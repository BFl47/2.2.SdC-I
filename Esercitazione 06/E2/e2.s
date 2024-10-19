# Inserisci la soluzione qui...
.globl list_equal
list_equal:
	pushl %ebx
	movl 8(%esp), %ecx
	movl 12(%esp), %edx
	xorl %eax, %eax
L:
	cmpl $0, %ecx
	je E
	cmpl $0, %edx
	je E
	movw (%edx), %bx
	cmpw %bx, (%ecx)
	jne Z
	movl 4(%ecx), %ebx
	movl %ebx, %ecx
	
	movl 4(%edx), %ebx
	movl %ebx, %edx
	jmp L
E:
	cmpl $0, %ecx
	sete %cl
	cmpl $0, %edx
	sete %al
	movzbl %cl, %ecx
	movzbl %al, %eax
	andl %ecx, %eax
Z:
	popl %ebx
	ret
