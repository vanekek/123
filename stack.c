#include "stack.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

stack * create_stack(int size, STACK_ERR *err)
{ 	if (size <= 0) {
		if (err != NULL)
			err = EINVARG;
		fprintf(stderr, "Invalid argument\n");
		return NULL;
	}

	stack * s = (stack *)malloc(sizeof(stack));

	if (s == NULL) {
		if (err != NULL)
			err = EINVARG;
		fprintf(stderr, "Invalid argument\n");
		return NULL;
	}
	s->arr = (int*)malloc(size*sizeof(int));
	if(s->arr == NULL){
		if (err != NULL)
			err = EINVARG;
		fprintf(stderr, "Invalid argument\n");
		return NULL;
	}
	s->size = size;
	s->crt = 0;
	if (err != NULL) {
		err = ESUCCESS;
	}
	return s;
}
void remove_stack(stack * s){
	if (s == NULL) {
		return;
	}
	free(s->arr);
	free(s);
}
int pop(stack *s) {
if (s == NULL) {
	return -1;
}
if (s->crt == 0) {
	return -1;
}
return(s->arr[--s->crt]);
}
void push(stack *s, int val){
if (s == NULL) {
	return;
}
if (s->crt == s->size) {
	return;
}
s->arr[s->crt++] = val;
}
