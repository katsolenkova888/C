//NAME: Katerina Solenkova
//CLASS: XiA
//NUMBER: 13
//PROBLEM #1 (it is only one, so...)
//FILE NAME: HW3.C
//FILE PURPOSE: A programe that shows the first 10 lines of a file, named a.txt
 


#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

 
int main (){
	const char *file = "a.txt";
	int line_number = 10;
	int line_count = 0;
	const int size = 1;
	int cclose;
	int i = 1;
	ssize_t wresult; //This type is used to represent the sizes of blocks that can be read or written in a single operation
	ssize_t rresult;
	char buff[size];
	int fd = open(file, O_RDONLY);//opening the file only for reading

	if(fd<0){ //test if the file was opened 
		perror("open:");
		return -1;
	}

	while(i == 1) { //the while() will stop when the programe has read 10 lines of the file
		rresult = read(fd,buff,1);
		if(rresult<0){//if rresult<0 nothing was read in the file
			perror("read");
			return -1;
		}
   
	
		if (rresult == 0){//there were less than 10 lines if this is true and nothing was read in the buff
			break;
		}

		if (line_count == line_number){
			break;
		}
		if(buff[0] =='\n'){//this indicates a new line
			line_count++;
		}	
		
		wresult=write(STDOUT_FILENO,buff,rresult);
			if(wresult<0){//if wresult<0 nothing was read and written from the buff
				perror("write");
				return -1;
			}
	}
		
	
	cclose = close(fd);//closing the file
	if(close<0){//if it's not correctly closed it will print an error
		perror("close");
		return -1;
	}
	return 0;
}
