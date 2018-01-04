//NAME: Katerina Solenkova
//CLASS: XiA
//NUMBER: 13
//PROBLEM #1
//FILE NAME: multifork.c
//FILE PURPOSE: A programe that starts the programe, given as an argument to it several times and simultaneously.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
 
int main(int argc, char* argv[]){
	int i,j;
	int count = atoi(argv[1]);
	pid_t pids[100];
 
	for(i = 0; i < count; i++){
		pids[i] = fork();
 		
		if(pids[i] > 0){//parent process
			waitpid(pids[count - 1], NULL , 0); // stops after the last child process we want to execute
 
		}
		else{
			if(pids[i] == 0){//child
				if(argc > 3){// if we have more arguments for the program e.g  3 ls -la -> "-la" is the argument for "ls" 
					for(j=3; j<argc; j++){
						execlp(argv[2], argv[2], argv[j], NULL);
					}
				}else{
					char* const* exe = &argv[2];
					execvp(argv[2], exe);
					}
			}
			else{//error
				char err1[100] = "./multifork: \0";
				char err2[15] = "\0";
				strcat(err1, argv[2]);
				strcat(err1, err2);
				perror(err1);
				return -1;
      			}
    		}
		
 	}	
		return 0;
}
