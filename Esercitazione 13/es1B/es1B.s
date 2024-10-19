# void interleave(const char* a, const char* b, char* c) {
#     do {
#         if (*a) *c++ = *a++;
#         if (*b) *c++ = *b++;
#     } while (*a || *b);
#     *c = '\0';
# }

# inserisci la soluzione qui...

.globl interleave
interleave:
	pushl %ebx
	movl 8(%esp), %eax
	movl 12(%esp), %ebx
	movl 16(%esp), %ecx
L:
	cmpb $0, (%eax)
	je E1
	movb (%eax), %dl
	movb %dl, (%ecx)
	incl %ecx
	incl %eax
E1:
	cmpb $0, (%ebx)
	je E2
	movb (%ebx), %dl
	movb %dl, (%ecx)
	incl %ecx
	incl %ebx
E2:
	cmpb $0, (%eax)
	je I1
	jmp L
I1:
	cmpb $0, (%ebx)
	je F
	jmp L
F:
	movb $0, (%ecx)
	popl %ebx
	ret
