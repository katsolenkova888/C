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
	int err = 0;
	
	

	for(i = 1; i<argc; i++){
		ssize_t rres = 0;
		ssize_t wres = 0;
		ssize_t res = 0;
		off_t offset_end, offset;
		int count = -1;
		int line_count = 0;
		if(*argv[i] == '-' || argc == 1){
			//char *file = "new_file.txt";
			//fd = open("new_file.txt", O_CREAT|O_WRONLY,S_IRWXU);
			while(rres != EOF){
				rres = read(STDIN_FILENO, buff3, 1);
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
				
			
				
			}
			fd = open(buff3, O_RDONLY);
			if(fd<0){ 
				int err_open = snprintf(open_buff, buff_size, "tail: cannot open '%s' for reading: No such file or directory\n", argv[i]);
				write(STDOUT_FILENO, open_buff, err_open);
				err = 1;
				
			}
			if(argc>2){
				if(err == 0){
					int name = snprintf(write_buff, buff_size, "==> %s <==\n", argv[i]);
					write(STDOUT_FILENO,write_buff,name);
				}
			}
			while(1){
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
					//return -1;
					
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
				} 				
				
			}
			if(i<argc-1){
				write(STDOUT_FILENO, "\n", 1);
			}		
			cclose = close(fd);
			if(cclose<0){
				int err_close = snprintf(close_buff, buff_size, "tail: error reading '%s': Input/output error\n", argv[i]);
				write(STDERR_FILENO, close_buff, err_close);
				//return -1;
			}
			
		
		}
		else{
			fd = open(argv[i], O_RDONLY);
			if(fd<0){ 
				int err_open = snprintf(open_buff, buff_size, "tail: cannot open '%s' for reading: No such file or directory\n", argv[i]);
				write(STDOUT_FILENO, open_buff, err_open);
				//int err_open = snprintf(open_buff, buff_size, "tail: cannot open '%s' for reading: No such file or directory\n", argv[i]);
				//write(STDERR_FILENO, open_buff, err_open);
				err =1;
				continue;
				//return -1;
			}
			if(argc>2){
				if(i > 1){
					write(STDOUT_FILENO, "\n", 1);
				}
				//if(err == 0){
					int name = snprintf(write_buff, buff_size, "==> %s <==\n", argv[i]);
					write(STDOUT_FILENO,write_buff,name);
				//}
			}
			
			while(1){
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
					//int err_read = snprintf(read_buff, buff_size, "tail: error reading '%s': Is a directory", argv[i]);
					//write(STDERR_FILENO, read_buff, err_read);
					//return -1;
					
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
