#include <stdlib.h>
#include <string.h>
#include "e2.h"

int comparator(const void* x, const void* y) {
	const char* xt = *(char**)x;
	const char* yt = *(char**)y;
	return strcmp(xt, yt);
}

void sort_strings(char *strings[], size_t size) {
	qsort(strings, size, sizeof(char*), comparator);
}
