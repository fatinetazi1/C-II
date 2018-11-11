/*
JTSK-320112
a1 p4.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#define INTERMEDIATE(A, B) A*B
int main(){
	char value[100];

    int size = 0;

    int* x = (int*) malloc(sizeof(int)*size);
    int* y = (int*) malloc(sizeof(int)*size);
    int* sum = (int*) malloc(sizeof(int)*size);
    int sprod = 0;

    fgets(value, sizeof(value), stdin);
    sscanf (value, "%d", &size);

    for (int i = 0; i < size; ++i)
    {
        fgets(value, sizeof(value), stdin);
        sscanf (value, "%d", &x[i]);
    }

    for (int j = 0; j < size; ++j)
    {
        fgets(value, sizeof(value), stdin);
        sscanf (value, "%d", &y[j]);
    }

    for (int z = 0; z < size; ++z)
    {
        sum[z] = INTERMEDIATE(x[z], y[z]);
        sprod += sum[z];
    }
    #ifdef INTERMEDIATE
        printf("The intermediate product values are:\n");
        for (int f = 0; f < size; ++f)
        {
            printf("%d\n", sum[f]);
        }
     #endif
    printf("The scalar product is: %d\n", sprod);
    free(x);
    free(y);
    free(sum);
    
    return 0;
}