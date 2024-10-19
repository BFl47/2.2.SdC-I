.globl get_utente
get_utente:
	pushl %ebx
	subl $8, %esp
	
	leal 4(%esp), %ebx
	movl %ebx, (%esp)
	call curr_user
	
	movl 16(%esp), %ecx
	movb (%ebx), %dl
	movb %dl, (%ecx)
	
	movl 20(%esp), %ecx
	movw 2(%ebx), %dx
	movw %dx, (%ecx)	
	
	addl $8, %esp
	popl %ebx
	ret
