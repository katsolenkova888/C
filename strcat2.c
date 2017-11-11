#include <stdio.h>
#include <string.h>

char* strcat(char* destination, const char* source);

char* strcat(char* destination, const char* source){
	int i, y=0,m=0;
	y=strlen(destination); //length of the first string so that the second string could be placed next to it
  m=strlen(source);

	for(i=0; i<m; i++){  
		destination[i+y]=source[i];
	}


return destination;
}
int main(){
  int i=0;
	char destination[50]={"ka"};
	char source[50]={"ti"};
	strcat(destination, source);
  for(i=0; destination[i]!='\0'; i++){
    printf("%c",*(destination+i));
  }
}

