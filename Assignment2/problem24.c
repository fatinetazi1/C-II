/*
JTSK-320112
a2 p4.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h> 

void input(int ***x, int row, int col, int dep){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < dep; ++k) {
                scanf("%d", &x[i][j][k]);
            }
        }
    }
}

void print(int ***x, int row, int col, int dep){
    int c = 1;
    for (int i = 0; i < dep; ++i) {
        printf("Section %d:\n", c);
        for (int j = 0; j < row; ++j) {
            for (int k = 0; k < col; ++k) {
                printf("%d ", x[k][j][i]);
            }
            printf("\n");
        }
        c++;
    }
}


int main(){
    int n, m, p, ***a, i, j;

    //dimensions
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);

    
    a = (int***) malloc(sizeof(int**)*n);
    if(a == NULL) {
        exit(1);
    }

    //array of integers
    for (i = 0; i < n; ++i) {
        a[i] = (int**) malloc(sizeof(int*)*m);
        if(a[i] == NULL){
            exit(1);
        }
        for (j = 0; j < m; ++j) {
            a[i][j] = (int*) malloc(sizeof(int)*p);
            if (a[i][j] == NULL) {
                exit(1);
            }
        }
    }

    input(a, n, m , p);

    print(a, n, m , p);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            free(a[i][j]);
        }
    }

    for (i = 0; i < n; ++i) {
        free(a[i]);
    }

    free(a);

    return 0;
}