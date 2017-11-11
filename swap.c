//NAME: Katerina Solenkova
// CLASS: XIa
// NUMBER: 13
// PROBLEM: #3
// FILE NAME: swap.c
// FILE PURPOSE: At the end a must have the value of b and b must have the value of a. 


#include <stdio.h>
void swap(int *a, int *b);

void swap(int *a, int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main(){
	int a = 5;
	int b = 6;
	swap(&a,&b);
	printf("A = %d, B = %d ", a, b);



return 0;
}



