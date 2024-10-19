#include "e6.h"
#include <string.h>

int is_prefix(const char* s, const char* t) {
	const char* c = s;
	const char* d = t;
L:
	if (*c == 0) goto E;
	if (*d == 0) goto E;
	char a = *d;
	if (*c != a) goto E;
	c++;
	d++;
	goto L;
E:;
	int a1 = 0;
	if (*c == 0) 
		a1 = 1;
	return a1;
}
