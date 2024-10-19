#include "e1A.h"

int* check_quiz(char** answers, char* solution, int n) {
	char** esi = answers;
	char* edi = solution;
	int* eax = NULL;
    if (answers == NULL)
		goto Z;
    if (solution == NULL) 
		goto Z;
    if (n <= 0) 
		goto Z;
	int edx = sizeof(int) * n;
    eax = malloc(edx);
    int c = 0;
L:
	if (c >= n)
		goto Z;
    
	eax[c] = 0;
	int d = 0;
L1:
	if (d >= 4)
		goto E1;
	char* ebp = esi[c]; // attenzione: e' un puntatore!
	char b = edi[d]; 
	if (ebp[d] != b) // attenzione: confronto di caratteri!
		goto E2;
	eax[c] += 1;
E2:
	d++;
	goto L1;
E1:  
    c++;
    goto L;
Z:
	return eax;
}
