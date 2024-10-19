#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getLargeTables(struct booking ** list, const char * filename, int num) {
	*list = NULL;
	struct booking * last = NULL;
	struct booking * elem;
	
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		perror("fopen");
		return;
	}
	fseek(f, 0, SEEK_END);
	int dim = ftell(f);
	fseek(f, 0, SEEK_SET);

	while (ftell(f) != dim) {
		char* cognome = malloc(30);
		char* posti = malloc(2);
		char* orario = malloc(5);
		
		fread(cognome, 30, 1, f);
		cognome[31] = '\0';
		fread(posti, 2, 1, f);
		posti[3] = '\0';
		fread(orario, 5, 1, f);
		orario[6] = '\0';
		
		int place = atoi(posti);
		strtok(cognome, "_");
		
		if (place >= num) {
			elem = malloc(sizeof(struct booking));
			elem->surname = strdup(cognome);
			elem->places = place;
			elem->time = strdup(orario);
			elem->next = NULL;
			
			if (*list == NULL) 
				*list = elem;
			else 
				last->next = elem;
			last = elem;
		}
		
		free(cognome);
		free(posti);
		free(orario);
	}
	
	if (f != NULL)
		fclose(f);

}
