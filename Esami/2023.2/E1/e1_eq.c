#include "e1A.h"

int* strings_are_upper(const char** array, int n) {
	int a = 0;
    if (array == NULL) 
		return NULL;		//goto Z;
    if (n <= 0) 	
		return NULL;		//goto Z;
	int c = n;
	c = c * sizeof(int);
    int* ebx = malloc(c);
    int edi = 0;
    const char** ebp = array;
L:
	if (edi >= n) 
		goto E;
    
	const char* esi = ebp[edi];
	ebx[edi] = 1;
L1:
	if (*esi == 0)
		goto E1;
	if (isupper(*esi) != 0) 
		goto E2;
	ebx[edi] = 0;
	goto E1;
E2:
	esi += 1;
E1:
    edi++;
    goto L;
E:
    return ebx;		//a = ebx + ret
}


//res 	-> ebx
//i	  	-> edi
//s   	-> esi
//array -> ebp
