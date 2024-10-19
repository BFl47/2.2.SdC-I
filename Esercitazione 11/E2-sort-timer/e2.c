#include "e2.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int i, max;

void handler(int signum) {
    printf("%.1f%%\n", 100.0*i/max);
}

static void do_sort(int *v, int n) {
    int j;
    for (i=0; i<n; ++i) 
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}

void sort(int *v, int n) {
	max = n;
	struct sigaction act = {0};
	act.sa_handler = handler;
	sigaction(SIGALRM, &act, NULL);
	
	ualarm(999999, 999999);
	
    do_sort(v, n);
}

