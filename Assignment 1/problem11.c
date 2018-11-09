/*
JTSK-320112
a1 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#define SWAP(F, G, H) {H t = G; G = F; F = t;}
int main(){
	char value[100];

	int a, b;
	double c, d;

	
    fgets(value, sizeof(value), stdin);
    sscanf (value, "%d", &a);
    fgets(value, sizeof(value), stdin);
    sscanf (value, "%d", &b);
    fgets(value, sizeof(value), stdin);
    sscanf (value, "%lf", &c);
    fgets(value, sizeof(value), stdin);
    sscanf (value, "%lf", &d);

    SWAP(a, b, int)
    SWAP(c, d, double)

    printf("After swapping:\n%d\n%d\n%.6lf\n%.6lf\n", a, b, c, d);

    return 0;
}