#define STACK_SIZE 10 
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	size_t size;
	size_t capacity;
	int *elements;
	
} stack;

void stack_init(stack *);
void stack_destroy(stack *);
int stack_empty(stack *);
void stack_push(stack *, int);
int stack_top(stack *);
void stack_pop(stack *);

int stack_empty(stack *new_stack){
	if( (*new_stack).size!=0){
		return 0;
	}
	else return 1;
}
		
void stack_init(stack *new_stack){
	(*new_stack).size = 0;
	(*new_stack).capacity = 20;
	(*new_stack).elements = malloc((*new_stack).capacity*sizeof(int));

}

void stack_destroy(stack *new_stack){
	(*new_stack).size = 0;
	(*new_stack).capacity = 0;
	free((*new_stack).elements);	
}

void stack_push(stack *new_stack, int elem){
	if((*new_stack).size<(*new_stack).capacity){
			(*new_stack).elements[(*new_stack).size]=elem;
			(*new_stack).size++;
		}
		
	else{	
		(*new_stack).capacity = (*new_stack).capacity*2;
		(*new_stack).elements = realloc((*new_stack).elements, (*new_stack).capacity*sizeof(int));
		(*new_stack).elements[(*new_stack).size]=elem;
		(*new_stack).size++;
	}
}

int stack_top(stack *new_stack){
	int num;	
	if(stack_empty(new_stack)){
		return -789;	
	}
	else num = (*new_stack).elements[(*new_stack).size-1];
	return num;
}

void stack_pop(stack *new_stack){
	(*new_stack).elements[(*new_stack).size] = NULL;
	(*new_stack).size--;

}

int main(){

return 0;
}
