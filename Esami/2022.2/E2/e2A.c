#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getStudents(const char * filename, student * in_list, int min_mark) {
	FILE* f = fopen(filename, "w+");
	if (f == NULL) {
		perror("fopen");
		return;
	}
	char c[80];
	while (in_list) {
		if (in_list->mark >= min_mark) {
			sprintf(c, "%s %s - %d\n", in_list->surname, in_list->name, in_list->mark);
			fputs(c, f);
		}
		in_list = in_list->next;
	}
	
	if (f != NULL)
		fclose(f);
		
}
