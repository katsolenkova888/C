#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int i, size = 1;
	int fd;
	int cclose;
	ssize_t rres, res;
	ssize_t wres, wwres;
	char buff[size], buff2[size];
	off_t offset, off;
	int buff_err_open = 300;
	char open_buff[buff_err_open];
	int line_count = 0;
	int buff_size = 300;
	char write_buff[buff_size];
	for(i=1; i<argc; i++){
		int count = -1;
		int line_count = 0;
		if(*argv[i]=='-'|| argc==1){
			while(1){
				rres = read(STDIN_FILENO,buff,1);
				if(rres==0) break;
				if(rres<0){
					perror("read");
					return -1;
				}
				
			}
		//printf("OKAY");	//prowerqwam dali vliza v if-a i dali izliza ot nego					
		}
		else{
			fd = open(argv[i], O_RDONLY);
			if(fd<0){ 
				int err_open = snprintf(open_buff, buff_err_open, "tail: cannot open '%s' for reading: No such file or directory\n", argv[i]);
				write(STDOUT_FILENO, open_buff, err_open);
				return -1;
			}
			if(argc>2){
				int name = snprintf(write_buff, buff_size, "==> %s <==\n", argv[i]);
				write(STDOUT_FILENO,write_buff,name);
			}
		
			
			while(1) {
				offset = lseek(fd, count, SEEK_END);
				if(offset<0){
					break;	
				}
				count--;
				//printf("OKAY"); 
				rres = read(fd,buff,1);
				if(rres<0){
					perror("read");
					return -1;
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
			//printf("%d",line_count);
			while(line_count>-1){
				res = read(fd, buff2,1);
				if(buff2[0] =='\n'){
					line_count--;
				}
				res+=res;
				wres=write(STDOUT_FILENO,buff2,res);
				if(wres<0){
					perror("write");
					return -1;
				}
				wwres+=wres;
			}
			//int buff_size_line = sizeof('\n');
			//char line_buff[buff_size_line];			
			//int new_line = snprintf(line_buff, buff_size_line, "\n");
			//write(STDOUT_FILENO,line_buff,new_line);
			
			cclose = close(fd);
				if(cclose<0){
				perror("close");
				return -1;
				}
		}
		write(STDOUT_FILENO,'\n',sizeof('\n'));
		
	}	

return 0;
}
