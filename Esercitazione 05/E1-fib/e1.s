.globl fib
fib:
	pushl %ebx 
	pushl %ebp 		#8
	subl $4, %esp
	
	movl 16(%esp), %ebx
	cmpl $2, %ebx
	jge E
	movl $1, %eax
	jmp F
E:
	decl %ebx
	movl %ebx, (%esp)
	call fib
	movl %eax, %ebp
	decl %ebx
	movl %ebx, (%esp)
	call fib
	addl %ebp, %eax
F:
	addl $4, %esp
	popl %ebp
	popl %ebx
	ret
