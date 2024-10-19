// inserire il C equivalente qui...
#include "e1.h"

int is_suffix(const char* s1, const char* s2){

    const char* ecx = s1;		//s1_aux -> ecx
    const char* edx = s2;		//s2_aux -> edx
L1:
	if (*ecx == 0)
		goto L2;
	ecx++;
	goto L1;
L2:
    if (*edx == 0)
		goto L3;
	edx++;
	goto L2;
L3:
	if (s1 == ecx)
		goto E;
	if (s2 == edx)
		goto E;
	char al = *ecx;			//*s1_aux -> al
	if (al != *edx)
		goto E;
	ecx--;
	edx--;
	goto L3;
E:
	al = *ecx;
	int c = s1 == ecx;
	int eax = al == *edx;
	eax &= c;
    return eax;
}

