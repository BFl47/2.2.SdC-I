#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverseTextFile(const char * input_file, const char * output_file) {
	int e;
	//apro il file di input
	FILE* f = fopen(input_file, "r");
	if (f == NULL) {
		perror("fopen");
		return;
	}
	
	//conto il numero di righe nell'input_file
	int dim = 0;
	char line[80];
	while (fgets(line, 80, f)) {
		dim++;
	}
	
	e = fseek(f, 0, SEEK_SET);
	if (e == -1) {
		perror("fseek");
		return;
	}
	
	//inizializzo un array di stringhe e copio le righe di input_file nelle stringhe
	char** array = malloc(sizeof(char*) * dim);
	if (array == NULL) {
		perror("malloc");
		return;
	}
	
	for (int i = 0; i < dim; i++) {
		fgets(line, 80, f);
		array[i] = strdup(line);
	}
	
	if (f != NULL)
		fclose(f);
	
	//apro il file output_file
	FILE* f1 = fopen(output_file, "w+");
	if (f1 == NULL) {
		perror("fopen");
		return;
	}
	//scrivo le stringhe nel file in ordine inverso
	for (int i = dim-1; i >= 0; i--) {
		fputs(array[i], f1);
	}
	
	if (f1 != NULL) 
		fclose(f1);	
	
	//libero l'array di stringhe
	for (int i = 0; i < dim; i++) 
		free(array[i]);
	free(array);
		
	
}
