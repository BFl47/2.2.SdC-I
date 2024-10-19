.globl max

max:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	cmpl %ecx, %eax		#if (a - c <= 0)
	jle F				#	  D   S
	jmp E
F:
	movl %ecx, %eax
E:
	ret
