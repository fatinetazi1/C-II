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
#define MAX 12

int main(){
	struct stack s; 
	init(&s);
	int input, n;
	char c;

	do{
		scanf("%c", &c);
		getchar();
		switch(c){
			case 'q':
				printf("Quit\n");
				break;
			case 's':
				scanf("%d", &input);
				getchar();
				n = push(&s, input);
				if(n == 1){
					printf("Pushing Stack Overflow\n");
				} else {
					printf("Pushing %d\n", input);
				}
				break;
			case 'p':
				n = pop(&s);
				if (n == 1)
				{
					printf("Popping Stack Underflow\n");
				} else {
					printf("Popping %d\n", n);
				}
				break;
			case 'e':
				printf("Emptying Stack ");
				empty(&s);
				printf("\n");
				break;
		}

	} while (c != 'q');
	return 0;
}