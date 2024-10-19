#include "e1A.h"

char* str_to_upper(const char* s) {
    if (s == NULL) 
		return NULL;			//goto Z
    const char* esi = s;
    char* eax = strdup(esi);
    char* edi = eax;
    char* ebx = eax;
L:	
	if (*ebx == 0)
		goto E;
	char d = *ebx;
	char al = toupper(d); 
	*ebx = al;
	ebx++;
    goto L;
E:
    return edi;
}


//	s    	-> esi
//	copy 	-> ebx
// 	s_copy 	-> edi
