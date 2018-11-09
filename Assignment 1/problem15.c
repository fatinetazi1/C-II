/*
JTSK-320112
a1 p5.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned char value = '\0';
	scanf ("%c", &value);

	printf("The decimal representation is: %d\n", value);

	printf("The backwards binary representation is: ");
	for (; value; value >>= 1){
		printf("%c", '0' + (value & 1));
	}

	printf("\n");
	
	return 0;
}