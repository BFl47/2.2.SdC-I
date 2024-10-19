#include "e2.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void swap(void* uno, void* due, size_t size) {
	void *tmp = malloc(size);
	memcpy(tmp, uno, size);
	memcpy(uno, due, size);
	memcpy(due, tmp, size);
	free(tmp);
}
	
void bubblesort(void* buf, size_t nel, size_t size){
	void* c = buf;
	int j = 0, i = 0;
	
    while (j < nel) {
		int i = 0;
		while (i < nel-1) {
			int p = i*size, d = (i+1)*size;
			if (memcmp(c+p, c+d, size) > 0) {
				swap(c+p, c+d, size);
			}
			i++;			
		}
		j++;
	}
}

