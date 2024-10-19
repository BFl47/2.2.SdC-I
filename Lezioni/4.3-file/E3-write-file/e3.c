#include <stdio.h>
#include <errno.h>

#include "e3.h"

 int getStudents(const char * filename, student * in_list, int min_mark) {
	FILE* f = fopen(filename, "w+");
	if (f == NULL) {
		perror("errore apertura");
		return -1;
	}	
	
	student* temp = in_list;
	while (temp != NULL) {
		int voto = temp->mark;
		if (voto >= min_mark) {
			int err = fprintf(f, "%s %s - %d\n", temp->surname, temp->name, voto);
			if (err < 0) {
				perror("errore scrittura");
				return -1;
			}
		}
		temp = temp->next;
		
	}
	if (f != NULL)
		fclose(f);
	
	return 0;
}
