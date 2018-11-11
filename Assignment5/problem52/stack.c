/*
JTSK-320112
a5 p2.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#define MAX 12

// initialization function
void init(struct stack *s){
	s->c = 0;
}

// checking if empty function
int isempty(struct stack *s){
	if (s->c == 0) {
		return true;
	} else {
		return false;
	}
}

// checking if full function
int isfull(struct stack *s){
	if (s->c == MAX) {
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
		s->array[s->c] = input;
		s->c++;
		return 0;
	}
}

// output function
int pop(struct stack *s){
	int n;
	if (isempty(s) == true){
		return -1;
	} else {
		n = s->array[(s->c)-1];
		s->c--;
		return n;
	}
}

// converting to binary function
void binary(struct stack *s, unsigned int input){
	int bin;
	while(input>=1){
		bin = (int) input%2;
		push(s, bin);
		input /= 2;
	}
}

// printing the stack function
void display(struct stack *s){ 
    int r = pop(s);
    while(r != -1) {
        printf("%d", r);
        r=pop(s);
    }
}


