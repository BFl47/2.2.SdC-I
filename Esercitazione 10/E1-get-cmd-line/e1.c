//SCRIVERE LA SOLUZIONE QUI...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e1.h"


void get_cmd_line(char* argv[MAX_TOKENS]) {
	char buf[1024];
	char* ris = fgets(buf, MAX_LINE, stdin);
	int i = 0;
	
	if (strcmp(buf, "\n") == 0) {
		argv[0] = NULL;
		return;
	}
	
		
	char* token = strtok(buf, " ");
	while (token != NULL) {
		int len = strlen(token);
		if (token[len-1] == '\n')
			token[len-1] = '\0';
		
		argv[i] = strdup(token);		
		token = strtok(NULL, " ");
		i++;
	}
	
	argv[i] = NULL;	

}

