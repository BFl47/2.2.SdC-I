
.globl fib

fib:
	xorl %eax, %eax				#fib1
	movl $1, %ecx				#fib2
	movl 4(%esp), %edx			#n
	
	testl %edx, %edx
	jne E
	ret
E:
	cmpl $1, %edx
	jne F
	movl %ecx, %eax
	ret	
F:
	cmpl $1, %edx
	jbe G
	
	addl %ecx, %eax            	#fib1 += fib2
	addl %ecx, %eax				#fib1 += fib2
	negl %ecx					#fib2 = -fib2
	addl %eax, %ecx				#fib2 += fib1
	subl %ecx, %eax				#fib1 -= fib2
	decl %edx
	jmp F	
	
G:	
	movl %ecx, %eax
	ret
	
	
