/*
JTSK-320112
a5 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#define MAX 8

// initialization function
void init(struct stack *s){
	s->count = 0;
}

// converting to binary function
void binary(stack *s unsigned int input){
	int b;
	while(b>=1){
		b = (int) bin%2;
		push(s, b);
		bin /= 2;
	}
}

// printing the stack function
void show(stack *s){
	do{
		n = pop(s);
		printf("%d\n", n);
	} while(n != 1);
	printf(".");
}

// checking if empty function
int isempty(struct stack *s){
	if (s->count == 0) {
		return true;
	} else {
		return false;
	}
}

// checking if full function
int isfull(struct stack *s){
	if (s->count == MAX) {
		return true;
	} else {
		return false;
	}
}

// input function
int push(struct stack *s, int input){
	if (isfull(s) == true) {
		return 1;
	} else {
		s->array[s->count] = input;
		s->count++;
		return 0;
	}
}

// output function
int pop(struct stack *s){
	int n = 0;
	if (isempty(s) == true){
		return 1;
	} else {
		n = s->array[(s->count)-1];
		s->count--;
		return n;
	}
}

// emptying function
int empty(struct stack *s){
	int n = 0;
	while(isempty(s) == false){
		n = pop(s);
		printf("%d ", n);
	}
	return n;
}