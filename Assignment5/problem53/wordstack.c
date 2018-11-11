/*
JTSK-320112
a5_p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
    char input[100]; 
    UP u; // initializing stack
    u.count = 0;
    u.up = NULL;

    while(1){
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0';
        if(strcmp(input, "exit") == 0){
            break;
        }
        init(&u, input);
        compare(&u, input);
    }
    
    return 0;
}
