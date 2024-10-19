#include "e2B.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

off_t searchfile(char* filename, char c) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("open");
		return -1;
	}
	lseek(fd, 0, SEEK_END);
	int dim = lseek(fd, 0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	
	char line[512];
	read(fd, line, dim);
	line[dim] = '\0';
	
	off_t ris = -1;
	int i = 0;
	while (line[i] != '\0') {
		if (line[i] == c) {
			ris = i;
			break;
		}
		i++;
	}
	
	close(fd);
	
	return ris;
}
