#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
 
int main (int argc,char*argv[]){
  //const char *s = "asd";
 // size_t len = strlen(s);
  size_t written = 0;
  ssize_t wresult = 0; //ss e za da priemame adski golemi chisla
  ssize_t rresult = 0;
  char buff[100];
  int line = 0;
  int i = 0;
 
  int fd = open(argv[1], O_RDONLY);
  if(fd<0){
    perror("open:");
    return -1;
  }
 
  while((rresult = read(fd,buff,100)) !=0){
    wresult=0;
    if(rresult<0){
      perror("read");
      return -1;
    }
   // wresult = write(STDOUT_FILENO,s,len);
    while (line < 10){
      ssize_t res;
    
      res=write(STDOUT_FILENO,buff[i],1);
      if(res<0){
        return -1;
      }
      if(buff[i]== '\n'){
        line++;
      }
      i++;
     // wresult += res;
    }
	
  }
  return 0;
}
