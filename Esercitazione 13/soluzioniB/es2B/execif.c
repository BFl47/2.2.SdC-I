#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int exec(const char* pathname, char* const args[]) {
    int status;
    pid_t p = fork();
    if (p == -1) {
        fprintf(stderr, "execif: cannot create new process\n");
        exit(EXIT_FAILURE);
    }
    if (p == 0) {
        execvp(pathname, args);
        fprintf(stderr, "execif: cannot execute %s\n", pathname);
        exit(EXIT_FAILURE);
    }
    while (wait(&status) != p);
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: execif <exec1-pathname> <exec2-pathname> ...\n");
        return EXIT_FAILURE;
    }
    if (exec(argv[2], argv+2) != 0) {
        char* cmd[] = { argv[1], NULL };
        exec(*cmd, cmd);
    }
    return 0;
}
