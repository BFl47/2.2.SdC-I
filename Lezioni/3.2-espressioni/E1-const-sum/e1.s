
.globl f

f: 
	movl $5, %eax		#int a = 5
	addl $7, %eax		#a = a +7
	ret					#return a
