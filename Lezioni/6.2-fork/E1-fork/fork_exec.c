#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <wait.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        char* argv[] = { "ls" , "-l", NULL};
        //execvp("ls", argv);
        execvp("./myprog", argv);
        perror("execvp");
        _exit(EXIT_FAILURE);
    }
    pid = wait(NULL);
    if (pid == -1) {
		perror("wait");
		exit(EXIT_FAILURE);
	}
    return EXIT_SUCCESS;
}

