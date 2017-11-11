#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size);

void swap(void *a, void *b, size_t size){
	void *temp = malloc(size);
	memcpy(temp,a,size);
	memcpy(a,b,size);
	memcpy(b,temp,size);
	free(temp);
}

int main(){
	
	int a = 5, b = 6;
	//swap(a,b,sizeof(int));
	printf("A = %d, B = %d", a,b);
return 0;
}

