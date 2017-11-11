#include <stdio.h>
#include <string.h>

char* strcat(char* destination, const char* source);

char* strcat(char* destination, const char* source){
	int i, y=0;
	y=strlen(destination);
	
		
	for(i=0; i<source[i]!='\0'; i++){
		destination[y-1]=source[i];
		y++;
		
	}
	
	y=strlen(destination);
	*(destination+y+1)='\0';
	
		//printf("%s",destination);
	
return destination;
}
int main(){
	
	/*char destination[50];
	char source[50];
	fgets(destination,50,stdin);
	fgets(source,50,stdin); 
	*destination = strcat(destination, source);*/

return 0;
}
