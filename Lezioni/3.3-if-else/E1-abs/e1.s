.globl myabs

myabs:
	movl 4(%esp), %eax
	//cmpl $0, %eax			#S   D
	testl %eax, %eax		
	jge E
	negl %eax
E:
	ret
