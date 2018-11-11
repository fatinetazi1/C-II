/*
JTSK-320112
a1 p7.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

unsigned char set3bits(char input, int a, int b, int c){
	input |= 1 << a;
	input |= 1 << b;
	input |= 1 << c;
	return input;
}

int main(){
	unsigned char value = '\0';
	unsigned char changed = '\0';
	int a, b, c, i;
	scanf ("%c", &value);
	scanf ("%d", &a);
	scanf ("%d", &b);
	scanf ("%d", &c);

	printf("The decimal representation is: %d\n", value);

	printf("The binary representation is: ");
	for (i = 7; i>= 0; --i){
		printf("%c", '0' + ((value >> i) & 1));
	}
	printf("\n");

	changed = set3bits(value, a, b, c);

	printf("After setting the bits: ");
	for (i = 7; i>= 0; --i){
		printf("%c", '0' + ((changed >> i) & 1));
	}
	printf("\n");
    
    return 0;
}