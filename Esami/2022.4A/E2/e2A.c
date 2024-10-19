#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int contaocc(const char* s, char c) {
	int ris = 0;
	while (*s) {
		if (*s == c)
			ris++;
		s++;
	}
	return ris;	
}

int multicount(const char** s, char c, int n) {
	int max = 0;
	if (c == '\0' || n == 0) 
		return -1;
	for (int i = 0; i < n; i++) {
		pid_t pid = fork();
		if (pid == -1) {
			perror("fork");
			return -1;
		}
		if (pid == 0) {
			const char* stringa = s[i];
			int count = contaocc(stringa, c);
			_exit(count);
		}		
	}
	int status;
	while(wait(&status) > 0) {
		if (WIFEXITED(status)) {
			int ret = WEXITSTATUS(status);
			if (ret > max)
				max = ret;
		}
	}
	return max;

}
