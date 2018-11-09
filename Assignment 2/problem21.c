/*
JTSK-320112
a2 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	char value[100];

	int size;
	int elm;

	fgets(value, sizeof(value), stdin);
    sscanf (value, "%d", &size);

    double* arr = (double*) malloc(sizeof(double)*size);

    for (int i = 0; i < size; ++i)
    {
    	fgets(value, sizeof(value), stdin);
    	sscanf (value, "%lf", &arr[i]);
    }

    for (int j = 0; j < size; ++j)
    {
    	if (arr[j] < 0)
    	{
    		elm = (&arr[j] - &arr[0]);
    	}
    }

    printf("Before the first negative value: %d elements\n", elm);

    return 0;
}