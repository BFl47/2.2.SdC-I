#include "e2B.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int contaparole(const char* s) {
    int ris = 0;
    char* corrente = strdup(s);
    char* token = strtok(corrente, " ");
    while (token != NULL) {
        ris++;
        token = strtok(NULL, " ");
    }
    return ris;
}

int wordcount(const char** s, int n) {
    if (n == 0)
        return -1;

    int max = 0;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return -1;
        }
        if (pid == 0) {
            const char* stringa = s[i];
            int count = contaparole(stringa);
            _exit(count);
        }
    }
    int status;
    while (wait(&status) > 0) {
        if (WIFEXITED(status)) {
            int count = WEXITSTATUS(status);
            if (count > max) 
                max = count;
        }
    }
    return max;
}