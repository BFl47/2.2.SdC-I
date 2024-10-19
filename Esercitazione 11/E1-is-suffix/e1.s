# scrivere la soluzione qui...
.globl is_suffix

is_suffix:
	movl 4(%esp), %ecx
	movl 8(%esp), %edx
L1:
	cmpb $0, (%ecx)
	je L2
	incl %ecx
	jmp L1
L2:
	cmpb $0, (%edx)
	je L3
	incl %edx
	jmp L2
L3:
	cmpl %ecx, 4(%esp)
	je E
	cmpl %edx, 8(%esp)
	je E
	movb (%ecx), %al
	cmpb (%edx), %al
	jne E
	decl %ecx
	decl %edx
	jmp L3
E:
	movb (%ecx), %al
	cmpl %ecx, 4(%esp)
	sete %cl
	movsbl %cl, %ecx
	
	cmpb (%edx), %al
	sete %al
	movsbl %al, %eax
	andl %ecx, %eax
	ret
