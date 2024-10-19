#include "e3.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

int most_freq_char(const char *buf, size_t nel) {
    int i = 0;
    int massimo = 0;
    char piu;
    while (i < nel) {
		char corrente = *(buf+i);
		int freq = 0;
		int j = 0;
		while (j < nel) {
			if (memcmp(buf+i, buf+j, 1) == 0)
				freq++;
			j++;
		}
		if (freq > massimo) {
			massimo = freq;
			piu = corrente;
		}
		i++;
	}
	return piu;
			
				
}

