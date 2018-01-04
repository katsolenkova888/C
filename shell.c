#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char** parse_cmdline(const char *cmdline);


char** parse_cmdline(const char *cmdline){
	printf("called\n");
	int i=0, j;
	char **arr={"hell"};
	//arr = (char*)malloc(1000*sizeof(char));
	//strcpy(arr,cmdline);

	
	char **parsed;
	parsed = malloc(100*sizeof(char*));
	for(int m = 0; m<100; m++){
		*(parsed+m)=malloc(100*sizeof(char));
	}
	ssize_t wres;
	char *buff;
	int k = 0;
	printf("A\n");
	//printf("%s\n", *arr);
	//char *pch;
	//pch = strtok(arr," ");
	//while(pch != NULL){
	for(j=0; j<3; j++){
		//char space = " " ;
		printf("vleze li?");
		if(/*strcmp(cmdline[j], " ")*/ j > 0){
			//printf("AAA");
			//parsed[i]=pch;
			//pch = strtok (NULL, " ");
			//i++;
			printf("i kolko e?");
			printf("%d\n", i);
			strcpy(parsed[i],buff);
			//printf("buff: %s",buff);
			k=0;
			i++;
		}
		else{
			//wres=write(parsed[i][j],cmdline+i,1); 
			//if(wres<0){
				//perror("write");
			buff[k]=cmdline[j];
			k++;
			}
			
		}
	
	return parsed;
}


int main(){
	char *cmdline;
	//cmdline = (char*)malloc(100*sizeof(char));
	printf("$ ");
	fgets(cmdline, 100, stdin);
	char **parsed;
	//parsed = malloc(100*sizeof(char));
	parsed = parse_cmdline(cmdline);
	//for(int i=0; i<2; i++){
		//printf("hoo %s",parsed[i]);
	//}
	printf("MAIN PARSED %s\n",parsed[1]);
	pid_t pid;
	pid = fork();

	if(pid > 0){//parent process
		waitpid(pid, NULL , 0); 
		}	
	else{
		if(pid==0){
			printf("$ ");

				//char* const* exe = &parsed[i];
				//const char *filename=parsed[0];
				//execv(filename,exe);
				printf("INNNN");
				
		}

	}
	return 0;
}


