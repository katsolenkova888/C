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
	int count = -1;
	int line_count = 0;
	for(i=1; i<argc; i++){
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
				perror("open:");
				return -1;
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
   
	
				
				if (line_count == 10){
					break;
				}
				if(buff[0] =='\n'){
					line_count++;
				}	
				
			}
			//printf("%d",line_count);
			while(line_count>0){
				/*off = lseek(fd, 0, SEEK_CUR);
				if(off<0){
					perror("lseek");
					return -1;
				}*/
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
	
			cclose = close(fd);
				if(cclose<0){
				perror("close");
				return -1;
				}
		}
	}	

return 0;
}
