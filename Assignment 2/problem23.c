/*
JTSK-320112
a2 p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, p, **a, **b, **c, i, j, k;
    int prod = 0;

    //dimensions
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);

    //2D arrays
    a = (int**) malloc(sizeof(int*)*n);
    if(a == NULL){
    	exit(1);
    }
    b = (int**) malloc(sizeof(int*)*m);
    if(a == NULL){
    	exit(1);
    }
    c = (int**) malloc(sizeof(int*)*n);
    if(a == NULL){
    	exit(1);
    }

    //array of integers
    for (i = 0; i < n; ++i)
    {
    	a[i] = (int*) malloc(sizeof(int)*m);
    	if(a[i] == NULL){
    		exit(1);
    	}
    }

    for (i = 0; i < m; ++i)
    {
    	b[i] = (int*) malloc(sizeof(int)*p);
    	if(b[i] == NULL){
    		exit(1);
    	}
    }

    for (i = 0; i < n; ++i)
    {
    	c[i] = (int*) malloc(sizeof(int)*p);
    	if(c[i] == NULL){
    		exit(1);
    	}
    }

    //getting the input
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < m; ++j)
    	{
    		scanf("%d", &a[i][j]);
    	}
    }

    for (i = 0; i < m; ++i)
    {
    	for (j = 0; j < p; ++j)
    	{
    		scanf("%d", &b[i][j]);
    	}
    }

    //product matrix
    for (i = 0; i < n; i++)
    {
    	for (j = 0; j < p; j++)
    	{
    		for (k = 0; k < m; k++)
    		{
    			prod = prod + (a[i][k]*b[k][j]);
    		}
    		c[i][j] = prod;
    		prod = 0;
    	}
    }

    printf("Matrix A:\n");
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < m; ++j)
    	{
    		printf("%d ", a[i][j]);
    	}
    	printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < m; ++i)
    {
    	for (j = 0; j < p; ++j)
    	{
    		printf("%d ", b[i][j]);
    	}
    	printf("\n");
    }

    printf("The multiplication result AxB:\n");
    for (i = 0; i < n; ++i)
    {
    	for (j = 0; j < p; ++j)
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

    for (i = 0; i < m; ++i)
    {
    	free(b[i]); 
    }

    free(a);
    free(b);
    free(c);

    return 0;
}