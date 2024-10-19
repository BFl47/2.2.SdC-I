#include "e1A.h"

int suffix(const char* a, const char* b) {
	const char* ebp = b;
	int eax = strlen(ebp);
	int ebx = eax;
	
	const char* esi = a;
	eax = strlen(esi);
	
	if (ebx > eax)
		goto E;
	int c = eax;
	c = c - ebx;
L:
	if (c >= eax)
		goto E1;
	char d = *ebp;
    if (esi[c] != d) 
		goto E;
	ebp++;
    c++;
    goto L;
E1:
	eax = 1;
	goto Z;
E:
	eax = 0;
Z:
	return eax;
}

// blen -> b
// alen -> a
// i	-> c
// b 	-> ebp
// a    -> esi
