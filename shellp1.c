#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>  
#include <string.h>
#include <sys/types.h>
#define SIZE 1
char **parse_cmdline(const char*);
 
 
char **parse_cmdline(const char* cmdline){
       
//  printf("called");
    int i=0, count=100;
    ssize_t new_res;
    char **new_string = (char**) malloc(count*sizeof(char*));
 
    //printf("%s", cmdline);
    char *newfun;
    newfun = strtok((char*)cmdline, "\n");
 
    while(newfun!=NULL){
        if(i==count){
            count=count*2;
            new_string =(char**)realloc(new_string,count*sizeof(char*));
        }
        new_string[i] = newfun;
        newfun = strtok(NULL, "\n");
        i++;
    }
       
   
 
    return new_string;
 
 
}
 
 
 
 
int main(){
   
   
        //char buff[100];
        //ssize_t died;
       
        //int i=5;
        char* cmdline;
       
        while(1){
	    write(STDOUT_FILENO, "$ ", 2);
            int size1;
            size_t size2 = 0;
            size1 = getline(&cmdline, &size2 ,stdin);
            if(size1==-1){
		
                free(cmdline);
 
                 break;
                
                }          
            cmdline[size1] = '\0';
           char** twostr;
	   twostr = parse_cmdline(cmdline);   
           
 
            pid_t pid= fork();
 
 
 
            if(pid==0){
               
                int eres=execv(twostr[0], twostr);
                if(eres<0){
                    perror(twostr[0]);
                }
                free(twostr[0]);
                free(twostr);
                exit(0);
               
            }
 
            else if(pid>0) {
                waitpid(pid, 0, 0);
            }
 
       
            else if(pid<0){
                perror("fork");
 
            }
 
       
           
                free(twostr[0]);
                free(twostr);
 
        }
 
       
 
    return 0;
}
