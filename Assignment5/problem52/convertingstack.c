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

int main(){
	
	unsigned int input;
	scanf("%u", &input);

	struct stack s; 
	init(&s);

	printf("The binary representation of %u is ", input);

	binary(&s, input);
	display(&s);
	printf(".\n");

	return 0;
}