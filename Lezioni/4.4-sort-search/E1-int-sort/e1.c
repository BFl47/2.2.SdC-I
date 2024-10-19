#include <stdlib.h>
#include "e1.h"

int comparator(const void *x, const void *y) {
	int xt = *(int*) x;
	int yt = *(int*) y;
	return xt - yt;
}

void sort_ints(int ints[], size_t size) {
	qsort(ints, size, sizeof(int), comparator);
}
