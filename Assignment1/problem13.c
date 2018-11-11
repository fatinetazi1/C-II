/*
JTSK-320112
a1 p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#define MAX(A, B) (A > B ? A : B)
#define MIN(C, D) (C < D ? C : D)
#define MID(E, F) ((E + F)/2)
int main(){
	char value[100];

    double x, y, z;

    fgets(value, sizeof(value), stdin);
    sscanf (value, "%lf", &x);
    fgets(value, sizeof(value), stdin);
    sscanf (value, "%lf", &y);
    fgets(value, sizeof(value), stdin);
    sscanf (value, "%lf", &z);

    double maxi = MAX(x, MAX(y, z));
    double mini = MIN(x, MIN(y, z));
    double midr = MID(mini, maxi);

    printf("The mid-range is: %.6lf\n", midr);
    
    return 0;
}