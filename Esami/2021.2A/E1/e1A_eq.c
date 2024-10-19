#include "e1A.h"

int count_tokens(char* str, const char* sep) {
	char* edi = str;
	const char* ebp = sep;
    int ebx = 0;
    char* eax = strtok(edi, ebp);
    char* esi = eax;
L:
	if (esi == NULL)
		goto E;
	ebx++;
	eax = strtok(NULL, ebp);
    esi = eax;
    goto L;
E:;
	int	a = ebx;
	return a;
}

//	cnt		->	ebx
//	token	->	esi
//	str		->	edi
//	sep		->	ebp
