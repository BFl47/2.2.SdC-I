#include <stdlib.h>
#include "e3.h"
int comparator(const void* x, const void* y) {
	int xt = *(int*)x;
	int yt = *(int*)y;
	return xt-yt;
}

int search_int(int ints[], size_t size, int key) {
	void* ris = bsearch(&key, ints, size, sizeof(int), comparator);
	if (ris == NULL)
		return 0;
	return 1;
}
