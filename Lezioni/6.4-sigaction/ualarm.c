#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signum) {
	printf("Catturato SIGALRM\n");
}

int main() {
	struct sigaction act = { 0 };
	act.sa_handler = handler;
//	act.sa_handler = SIG_DFL;		il segnale SIGALRM ha come default la terminazione del processo
	
	int ret = sigaction(SIGALRM, &act, NULL);
	if (ret == -1) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	
	ualarm(500000, 500000);

//	sleep(10);

	printf("prima di pause()\n");
	pause();
	printf("dopo pause()\n");		//non eseguito se handler di default	

	return EXIT_SUCCESS;
}
