#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char** parse_cmdline(const char *cmdline);
void exec_func(char **parsed);
int find_pipe(char **parsed);



char** parse_cmdline(const char *cmdline){

	int i=0, j = 100;
	
	char **parsed = (char**) malloc(j*sizeof(char*));
	char *tok;
	tok = strtok((char*)cmdline, " \n");
	while(tok != NULL){
		if(i==j){
			j*=2;	
			parsed = (char**)realloc(parsed,j*sizeof(char*));
		}
		
		parsed[i]=tok;
		tok = strtok (NULL, " \n");
		i++;
	}

	return parsed;
}

void exec_func(char **parsed){
	pid_t pid;
		pid = fork();
		if(pid==0){
			
				
			const char *filename=parsed[0];
			int ex = execv(filename,parsed);
			if(ex<0){
				perror(filename);
			}
			free(parsed[0]);
			free(parsed);
			exit(0);
				
				
		}
	
		else if(pid > 0){//parent process
			waitpid(pid, 0, 0); 
			
		}
		else if(pid<0){

			perror("fork");

		}
}

int find_pipe(char **parsed){
	int i;
	int found = 1;
	const char chertichka = '|';
	const char* pipe;
	 
	for(i=0; parsed[i]!=NULL; i++){
		strcpy(pipe, parsed[i]);
		if(strcmp(pipe, chertichka) == 0){
			
			found = 0;
		}
	}
	return found;
}

int main(){
	char *cmdline;
		while(1){

		write(STDOUT_FILENO,"$ ", 2);
		size_t capacity = 0;
		int size1 = getline(&cmdline, &capacity, stdin);
		if(size1 < 0){
			free(cmdline); 
			break;
		}
		cmdline[size1] = '\0';	
		char **parsed;
		parsed = parse_cmdline(cmdline);
		printf("HERE %s, %d", parsed[2], find_pipe(parsed));
		exec_func(parsed);
		free(parsed[0]);
		free(parsed);
				
		
	}
	
	
	return 0;
}


