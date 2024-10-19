#include "e1.h"
#include <stdio.h>

void uint2bin(unsigned x, char bin[32]) {
	//printf("%x\n", x);
	int i, j = 31;
	for (i = 0; i < 32; i++) {
		if (x % 2) {
			//printf("1 ");
			bin[j] = '1';
		}
		else {
			//printf("0 ");
			bin[j] = '0';
		}
		
		x = x/2;
		j--;
	}
	bin[32] = '\0';
	//printf("\nstringa: %s\n", bin);
}

