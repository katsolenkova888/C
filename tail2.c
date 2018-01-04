//NAME: Katerina Solenkova
//CLASS: XiA
//NUMBER: 13
//PROBLEM #1 (it is only one, so...)
//FILE NAME: tail2.c
//FILE PURPOSE: A programe that prints the last 10 lines of one or more files just like the command 'tail'.

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	int i;
	int size = 1;
	int fd;
	int buff_size = 300;
	char open_buff[buff_size];
	char read_buff[buff_size];
	char write_buff[buff_size];
	char err_buff[buff_size];
	char close_buff[buff_size];
	char buff[size];
	char buff2[size];
	char buff3[size];
	int cclose;
	
	
	
	

	for(i = 1; i<argc; i++){ // in this loop we operate with files which can be taken as arguments of the main function or we can print out the last 10 lines of file, written in the standart input
		ssize_t rres = 0;
		ssize_t wres = 0;
		ssize_t res = 0;
		off_t offset_end, offset;
		int count = -1;
		int line_count = 0;
		int fp;
		int err = 0;
		if(*argv[i] == '-' || argc == 1){ // here we check if the argument of the main function is '-' => this means we should write a file in the standart input, also if we don't write any arguments, we read from the standart input but I couldn't make it work in this case :(
			if(argc>2){ // only if we have more than 1 file, we put headings 
					if(i > 1){
						write(STDOUT_FILENO, "\n", 1);
					}
					int name = snprintf(write_buff, buff_size, "==> standart input <==\n");//we write/save the heading in a buffer (write_buff) and name has the size of the bytes we need for the heading
					write(STDOUT_FILENO,write_buff,name); // we write the heading in the standart output 
				
			}
			char *file = "new_file.txt";
			fp = open("new_file.txt", O_CREAT|O_WRONLY,S_IRWXU); //creating a new file
			while(rres != EOF){//read from the standart input until we reach end of file
				rres = read(STDIN_FILENO, buff3, 1);
				if(rres<0){//if we haven't read anything -> error
					char err1[100] = "tail: error reading \0";
					char err2[15] = "'\0";
					strcat(err1, argv[i]);
					strcat(err1, err2);
					perror(err1);
					
				}
				if(rres == 0){
					break;
				}
				
			wres = write(fp, buff3, 1); // write the information in a file descriptor, named fp
				
			}
			cclose = close(fp); //closing the file descriptor
			fd = open(file, O_RDONLY); // opening a new file descriptor, named fd
			if(fd<0){ 
				int err_open = snprintf(open_buff, buff_size, "tail: cannot open '%s' for reading: No such file or directory\n", argv[i]);
				write(STDOUT_FILENO, open_buff, err_open);
				err = 1;
				
			}
			
			while(1){
				offset = lseek(fd, count, SEEK_END); // we set the offset to the byte before the last one and then we read one byte which is the last one
				if(offset<0){
					break;	
				}
				count--;
				rres = read(fd,buff,1); //we read one byte after the offset
				if(rres<0){//we haven't read anything 
					char err1[100] = "tail: error reading \0";
					char err2[15] = "'\0";
					strcat(err1, argv[i]);
					strcat(err1, err2);
					perror(err1);
					//return -1;
					
				}
				if(rres == 0){
					break;
				}
				if (line_count == 11){
					break;
				}
				if(buff[0] =='\n'){
					line_count++; // counting lines
				}
			}
			if(line_count<11){
				lseek(fd, 0, SEEK_SET);// if we have 10 or less lines we set the offset to the beginning of the file
			}
			else lseek(fd, offset + 2, SEEK_SET);// otherwise we set the offset to the first byte of the last 10 lines(it is not offset + 2, it prints the last symbol of the 11th new line
			while(rres = read(fd, buff, 1) > 0){
				wres=write(STDOUT_FILENO,buff,rres);//we write the last 10 lines in the standart output
				if(wres<0){
					char err1[100] = "tail: error writing '\0";
					char err2[15] = "'\0";
					strcat(err1, argv[i]);
					strcat(err1, err2);
					perror(err1);
				} 				
				
			}
			if(i<argc-1){//we need to keep a new line between the files
				write(STDOUT_FILENO, "\n", 1);
			}		
			cclose = close(fd);
			if(cclose<0){
				int err_close = snprintf(close_buff, buff_size, "tail: error reading '%s': Input/output error\n", argv[i]);
				write(STDERR_FILENO, close_buff, err_close);
				//return -1;
			}
			
		
		}
		else{// the case with more than one argument of main function
			fd = open(argv[i], O_RDONLY);//openning a file
			if(fd<0){ 
				int err_open = snprintf(open_buff, buff_size, "tail: cannot open '%s' for reading: No such file or directory\n", argv[i]);
				write(STDOUT_FILENO, open_buff, err_open);
				
				err =1;
				
				continue;
				
			}
			if(argc>2){ // if we have more than one file and if we are not on the first one, we print a new line
				if(i > 1){
					write(STDOUT_FILENO, "\n", 1);
				}
				
					int name = snprintf(write_buff, buff_size, "==> %s <==\n", argv[i]); // writing heading
					write(STDOUT_FILENO,write_buff,name);
				
			}
			
			while(1){//we do the same as in the case with the standart input except creating a new file
				offset = lseek(fd, count, SEEK_END);
				if(offset<0){
					break;	
				}
				count--;
				rres = read(fd,buff,1);
				if(rres<0){
					char err1[100] = "tail: error reading \0";
					char err2[15] = "'\0";
					strcat(err1, argv[i]);
					strcat(err1, err2);
					perror(err1);
					
					
				}
				if(rres == 0){
					break;
				}
				if (line_count == 11){
					break;
				}
				if(buff[0] =='\n'){
					line_count++;
				}
			}
			if(line_count<11){
				lseek(fd, 0, SEEK_SET);
			}
			else lseek(fd, offset + 2, SEEK_SET);
			while(rres = read(fd, buff, 1) > 0){
				wres=write(STDOUT_FILENO,buff,rres);
				if(wres<0){
					char err1[100] = "tail: error writing '\0";
					char err2[15] = "'\0";
					strcat(err1, argv[i]);
					strcat(err1, err2);
					perror(err1);
					
					//int err_write = snprintf(err_buff, buff_size, "tail: error writing '%s': No space left on device", argv[i]);
					//write(STDERR_FILENO, err_buff, err_write);
				} 				
				
			}
			//if(i<argc-1){
				//write(STDOUT_FILENO, "\n", 1);
			//}		
			cclose = close(fd);
			if(cclose<0){
				if(err == 0){
					int err_close = snprintf(close_buff, buff_size, "tail: error reading '%s': Input/output error\n", argv[i]);
					write(STDERR_FILENO, close_buff, err_close);
				}
				//return -1;
			}
		}
	
	}

	return 0;
}
