#include "e1A.h"

int* count_vars(char** vars, int n) {
    int a0 = 0;
    if (vars == NULL) 
		goto Z;		
	if (n <= 0) 
		goto Z;
	int c = n;
	c = c * 4;
    int* a = malloc(c);
    int* ebx = a;
    char** esi = vars;
    int edi = 0;
L:
	if (edi >= n)
		goto E;
	char* d = esi[edi];
	if (getenv(d) == NULL)
		goto E1;
	ebx[edi] = 1;
	goto E2;
E1:
	ebx[edi] = 0;
E2:
    edi++;
    goto L;
E:
	a = ebx;
    return a;

Z:
	return NULL;
}


//	i		->	edi
//	vars	->	esi
//	out		->	ebx
