/*
JTSK-320112
a1 p2.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#define BIT(X) X&1
int main(){
	char value[100];

    unsigned char a;

    fgets(value, sizeof(value), stdin);
    sscanf (value, "%c", &a);

    int sig = BIT(a);

    printf("The decimal representation is: %d\n", a);
    printf("The least significant bit is: %d\n", sig);
    
    return 0;
}