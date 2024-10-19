// inserisci la soluzione qui...

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if (argc <= 2) {
		perror("usage: execif <exec1-pathname> <exec2-pathname> [<exec2-args>]");
		return 1;
	}	
	//printf("%s, %s\n", argv[1], argv[2]);
	
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return 1;
	}
	if (pid == 0) {
		char** elem = (char**) malloc(sizeof(char*) * (argc-1));
		int j = 0;
		for (int i = 2; i < argc; i++) {
			elem[j] = argv[i];
			j++;
		}
		elem[j] = NULL;
		execvp(argv[2], elem);
		perror("execvp exec2");
		return 1;
	}
	
	int status;
	pid = wait(&status);
	if (pid == -1) {
		perror("wait");
		return 1;
	}
	//se c'è uno stato "restituisce" WEXITSTATUS, altrimenti errore
	if ((WIFEXITED(status) ? WEXITSTATUS(status) : 1) != 0) {
		pid = fork();
		if (pid == -1) {
			perror("fork");
			return 1;
		}
		if (pid == 0) {
			char* elem1[] = {argv[1], NULL};
			execvp(argv[1], elem1);
			perror("execvp exec1");
			return 1;
		}
		pid = wait(&status);
		if (pid == -1) {
			perror("wait");
			return 1;
		}
	}	
	return 0;
}
