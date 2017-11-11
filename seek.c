#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char *file = argv[1];
	long off = atoi(argv[2]);
	long rea = atoi(argv[3]);
	ssize_t rres;
	ssize_t wres;
	off_t offset;
	char buff[100];
	ssize_t count = 0;
	int i = 0;
	int cclose;
	ssize_t res;
	
	int fd = open(file, O_RDONLY);
	if(fd<0){
		perror("open:");
		return -1;
	}
	
	offset = lseek(fd, off, SEEK_SET);
	if(offset<0){
		perror("lseek");
	}
	
	
	while(count < rea){	
		rres = read(fd, buff, 1);
		wres=0;
		if(rres<0){
			perror("read");
			return -1;
		}
		if(rres == 0){
			break;
		}
		count+=rres;
		while(wres!=rres){
			res=write(STDOUT_FILENO,buff,rres-wres);
			if(res<0){
				perror("write");
				return -1;
				}
			wres+=res;
		}
		
	}
	
	cclose = close(fd);
	if(cclose<0){
		perror("close");
		return -1;
	}
return 0;
}
 
