/*
JTSK-320112
a5 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#ifndef STACK_H
#define STACK_H

struct stack {
	unsigned int count;
	int array[12]; //container
};

// initialization function
void init(struct stack *s);

// checking if empty function
int isempty(struct stack *s);

// checking if full function
int isfull(struct stack *s);

// input function
int push(struct stack *s, int input);

// output function
int pop(struct stack *s);

// emptying function
int empty(struct stack *s);

#endif 