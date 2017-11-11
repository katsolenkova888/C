#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1
 
int main(int argc, char **argv){
 
    ssize_t rres=0;
    ssize_t wres=0;
    ssize_t res;
    int endres;
    char buff[1000];
    const char *file_name = argv[1];
    //const char *byteskyp = argv[2];
    long byteskyp = atoi(argv[2]);
    //const char *byteneed = argv[3];
    long needat = atoi(argv[3]);
 
    int fd = open(file_name, O_RDONLY);
    if(fd<0){
        perror("open");
        return 1;
    }
   
    off_t size = lseek(fd, byteskyp, SEEK_SET);
    if(size<0){
            perror("lseek");
            return 2;
        }
   
    ssize_t read_bytes =0;
        while(read_bytes<needat){
            rres = read(fd, buff, SIZE);
	    wres=0;
        if (rres < 0){
            perror("read");
            return 3;
        }
        if(rres == 0) {
            break;
        }
        read_bytes += rres;
   
            while(wres!=rres){ 
            res = write(STDOUT_FILENO, buff, rres-wres);
            if(res<0){
            perror("write");
            return 4;
            }
            wres+=rres;
       
        }
    }
 
   int closed = close(fd);
    if(closed <0){
        perror("close");
        return 5;
 
    }
 
 
return 0;
}
