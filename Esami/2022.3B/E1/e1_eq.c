#include "e1B.h"

int count_matching_vars(char** vars, char* pattern) {
	int a0 = -1;
    if (vars == NULL)
		goto Z;
    if (pattern == NULL) 
		goto Z;
	char** esi = vars;
	char* ebp = pattern;
    int edi = 0;
    
L:
	if (*esi == 0)
		goto E;
    
	char* eax = getenv(*esi);
	char* ebx = eax;
	if (ebx == 0)
		goto E1;
	//eax = strstr(ebx, pattern);	
	if (strstr(ebx, ebp) == 0)
		goto E1;
	edi += 1;
E1:	
	esi++;
	goto L;
E:
    return edi;
Z:
	return a0;
}

//	count	->	edi
//	vars	-> 	esi
//	value 	-> 	ebx
//	pattern -> 	ebp
