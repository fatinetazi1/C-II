/*
JTSK-320112
a1 p6.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned char value = '\0';
	scanf ("%c", &value);

	printf("The decimal representation is: %d\n", value);

	printf("The binary representation is: ");
	for (int i = 7; i>= 0; --i){
		printf("%c", '0' + ((value >> i) & 1));
	}

	printf("\n");
    
    return 0;
}