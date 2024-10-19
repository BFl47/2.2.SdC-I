#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "e1.h"

int parseCSV(const char* file, person_t** out, int minAge) {
    FILE* f = NULL;
    *out = NULL;
    int ret;
    
    f = fopen(file, "r");
    if (f == NULL) goto cleanup;
    
    person_t* last = NULL;
    
    char buf[64];
    while (fgets(buf, 64*sizeof(char), f) != NULL) {
		//printf("buf: %s\n", buf);
		
		char nome[20];
		char cognome[20];
		char nascita[20];
		char phd[20];
		int giorno, mese, anno;
		int haPhd;
		
		char* token = strtok(buf, ",");
		strcpy(nome, token);
		
		token = strtok(NULL, ",");
		strcpy(cognome, token);
		
		token = strtok(NULL, ",");
		strcpy(nascita, token);
		
		token = strtok(NULL, ",");
		strcpy(phd, token);
		
		if (strcmp(phd, "yes\n") == 0)
			haPhd = 1;
		else
			haPhd = 0;
			
		//printf("str: %s,%s,%s, %d\n", nome, cognome, nascita, haPhd); 
		sscanf(nascita, "%d-%d-%d", &giorno, &mese, &anno);
		//printf("anno: %d, annomin: %d\n", anno, minAge);
		
		if (anno >= minAge) {
			person_t* persona = malloc(sizeof(person_t));
			persona->name = malloc(strlen(nome)+1);
			strcpy(persona->name, nome);
			persona->surname = malloc(strlen(cognome)+1);
			strcpy(persona->surname, cognome);
			persona->year = anno;
			persona->has_phd = haPhd;
			persona->next = NULL;
			
			if (*out == NULL) 
				*out = persona;
			else
				last->next = persona;
			last = persona;		
		}
	}
    
    fclose(f);
    return 0;
    
    
    
cleanup:
	if (f != NULL) 
		fclose(f);
	return -1;
}
