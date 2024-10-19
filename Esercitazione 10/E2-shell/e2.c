//SCRIVI LA SOLUZIONE QUI...
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>

#include "e2.h"

int do_shell(const char* prompt) {
	char* argv[MAX_TOKENS];
	
start:	
	printf("prompt: %s: ", prompt);

	char buf[1024];
	fgets(buf, MAX_LINE, stdin);
	int i = 0;
	
	if (strcmp(buf, "\n") == 0) {
		argv[0] = NULL;
		goto start;
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
	
	if (argv[0] == NULL) goto start;
	
	if (strcmp(argv[0], "quit") == 0)
		return EXIT_SUCCESS;

	pid_t pid = fork();
	
	if (pid == -1) {
		perror("errore fork");
		return EXIT_FAILURE;
	}
	if (pid == 0) {
		//printf("entrato nel figlio");
		execvp(argv[0], argv);
		printf("unknwon command: ");

		int j = 0;
		while (argv[j] != NULL) {
			printf("%s ", argv[j]);
			j++;
		}
		printf("\n");
		goto start;
	}
	
	pid = wait(NULL);	
	
	if (pid == -1) {
		perror("errore wait");
		exit(EXIT_FAILURE);
	}
	goto start;
	
	return EXIT_SUCCESS;
	
}


