#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n) {
	int b = n;
	const void* bi = src;
    void* a = malloc(b);
    if (a==0) return 0;
    memcpy(a, bi, b);
    return a;
}
