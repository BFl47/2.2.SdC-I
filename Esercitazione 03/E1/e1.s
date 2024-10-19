
.globl min

min:
	movl 4(%esp), %eax					#a = x
	movl 8(%esp), %ecx					#b = y
	movl 12(%esp), %edx					#c = z
	
	cmpl %ecx, %eax						#if (a >= c)
	jge E
	cmpl %edx, %eax						#if (a >= d)
	jge F
	jmp G
E:
	cmpl %edx, %ecx						#if (c >= d)
	jge F
	movl %ecx, %eax
	jmp G
	
F:
	movl %edx, %eax
G:
	ret
