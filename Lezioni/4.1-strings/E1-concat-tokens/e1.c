#include <stdlib.h>
#include <string.h>

#define DELIM ", "

char* f(const char* s) {
	int len = strlen(s);
	char* copia = malloc(len+1);
	strcpy(copia, s);
	
	char* ris = malloc(len+1);
	int i = 0;
	
	char* token = strtok(copia, DELIM);
	while(token != NULL) {
		strcat(ris, token);
		i += strlen(token);
		token = strtok(NULL, DELIM);
	}
	ris = realloc(ris, (i+1));
	free(copia);
	return ris;
}
