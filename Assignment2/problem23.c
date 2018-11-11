/*
JTSK-320112
a2 p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, **a, **b, **c, i, j, k;
    int prod = 0;

    //dimension
    scanf("%d", &n);

    //2D arrays
    a = (int**) malloc(sizeof(int*)*n);
    if(a == NULL){
    	exit(1);
    }
    b = (int**) malloc(sizeof(int*)*n);
    if(b == NULL){
    	exit(1);
    }
    c = (int**) malloc(sizeof(int*)*n);
    if(c == NULL){
    	exit(1);
    }

    //array of integers
    for (i = 0; i < n; ++i)
    {
    	a[i] = (int*) malloc(sizeof(int)*n);
    	if(a[i] == NULL){
    		exit(1);
    	}
    }

    for (i = 0; i < n; ++i)
    {
    	b[i] = (int*) malloc(sizeof(int)*n);
    	if(b[i] == NULL){
    		exit(1);
    	}
    }

    for (i = 0; i < n; ++i)
    {
    	c[i] = (int*) malloc(sizeof(int)*n);
    	if(c[i] == NULL){
    		exit(1);
    	}
    }

    //getting the input
    for (i = 0; i < n; ++i) {
    	for (j = 0; j < n; ++j) {
    		scanf("%d", &a[i][j]);
    	}
    }

    for (i = 0; i < n; ++i) {
    	for (j = 0; j < n; ++j) {
    		scanf("%d", &b[i][j]);
    	}
    }

    //product matrix
    for (i = 0; i < n; i++) {
    	for (j = 0; j < n; j++) {
    		for (k = 0; k < n; k++) {
    			prod = prod + (a[i][k]*b[k][j]);
    		}
    		c[i][j] = prod;
    		prod = 0;
    	}
    }

    printf("Matrix A:\n");
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < n; ++j)
    	{
    		printf("%d ", a[i][j]);
    	}
    	printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < n; ++j)
    	{
    		printf("%d ", b[i][j]);
    	}
    	printf("\n");
    }

    printf("The multiplication result AxB:\n");
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < n; ++j)
    	{
    		printf("%d ", c[i][j]);
    	}
    	printf("\n");
    }

    //deallocating memory
    for (i = 0; i < n; ++i)
    {
    	free(a[i]); 
    	free(c[i]);
    }

    for (i = 0; i < n; ++i)
    {
    	free(b[i]); 
    }

    free(a);
    free(b);
    free(c);

    return 0;
}