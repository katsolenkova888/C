//NAME: Katerina Solenkova
// CLASS: XIa
// NUMBER: 13
// PROBLEM: #4
// FILE PURPOSE: Duplicate constant char* using dynamic memory

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdup(const char * );

char *strdup(const char *str){
	char *dup=malloc(strlen(str)+1);
	if(dup==NULL){
		return NULL;
	}
	int i;
	for(i=0; i<strlen(str);i++){
		*(dup+i)=*(str+i);
	}
	*(dup+i+1)='\0';
	//printf("%s", dup);
	//free(dup);
	return dup;
}

int main(){
	char str[8]="Hello";
	strdup(str);
	
return 0;
}
