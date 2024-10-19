// Scrivi il C equivalente qui...
#include <stdlib.h>

int stringa_vuota(const char *s) {
	int a = 0;
	const char* c = s;
	if (c == 0) goto E;
	if (*c != 0) goto E;
	a = 1;
E:
	return a;
}
