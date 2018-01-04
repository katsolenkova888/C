#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>


 
int main (int argc, char *argv[]) {
	int i;
	pid_t pid;
	int count = atoi(argv[1]);
	for (i = 1; i <= count; i++) {
		pid = fork();
		if (pid == -1) {
			perror("fork:");
			return -1;
		}		
		if (pid == 0) {
			//printf("I am a child: %d PID: %d\n",i, getpid());
			//sleep (5);
			execl(argv[2], argv[2], NULL);
			return 0;
		}
		//if(i==count) break;

	}   	
	return 0;
}
