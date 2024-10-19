// Scrivi la soluzione qui...
.globl num_vowels
num_vowels:
	pushl %ebx
	pushl %edi
	subl $4, %esp
	
	xorl %ebx, %ebx
	movl 16(%esp), %edi
L:
	cmpb $0, (%edi)
	je E
	movl (%edi), %ecx
	movl %ecx, (%esp)
	call is_vowel
	addl %eax, %ebx
	incl %edi
	jmp L
E:
	movl %ebx, %eax	
	addl $4, %esp
	popl %edi
	popl %ebx
	ret
