#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void decodeTextFile(const char * encoded_file, const char * key, char ** decoded_text) {
	FILE* f = fopen(encoded_file, "r");
	if (f == NULL) {
		perror("fopen");
		return;
	}
	fseek(f, 0, SEEK_END);
	int dim = ftell(f);
	fseek(f, 0, SEEK_SET);

	char buf[512];
	int r = fread(buf, 1, dim, f);
	if (r != dim) {
		perror("fread");
		return;
	}
	*decoded_text = strdup(buf);
	
	if (f != NULL)
		fclose(f);
	
	FILE* chiave = fopen(key, "r");
	if (chiave == NULL) {
		perror("fopen");
		return;
	}
	fseek(chiave, 0, SEEK_END);
	int dim2 = ftell(f);
	fseek(chiave, 0, SEEK_SET);

	r = fread(buf, 1, dim2, chiave);
	if (r != dim2) {
		perror("fread");
		return;
	}
	
	if (chiave != NULL)
		fclose(chiave);
		
	for (int i = 0; i < dim; i++) {
		int cod = (*decoded_text)[i];
		if (cod >= 65 && cod <= 122) {
			cod = cod - 65;
			(*decoded_text)[i] = buf[cod];
		}
	}
}

