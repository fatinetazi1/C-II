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

// input elements the stack function
void push(UP *u, char str[30]){
    STACK *temp = malloc((1)*sizeof(STACK));
    temp->next = NULL;
    strcpy(temp->s, str);

    if(u->count == 0){
         u->up = temp;
         u->count = 1;
    }else{
        temp->next = u->up;
        u->up = temp;
        u->count++;
    }
}

// output elements function
void pop(UP *u, char str[30]){
    STACK *temp = malloc((1)*sizeof(STACK));
    temp = u->up;
    temp = temp->next;
    strcpy(str, u->up->s);
    free(u->up);
    u->up = temp;
    u->count--;
}

// creates stack function
void init(UP *u, char str[1000]){
    char temp[30];
    int i = 0, j = 0;
    while(1){
        // ' ' divide words and checking for the end 
        if(str[i] != ' ' && str[i] != '\0'){ 
            temp[j] = str[i];
            j++;
        }else{
            temp[j] = '\0'; 
            push(u, temp); // pushing into the stack
            j = 0; 
        }
        if(str[i]=='\0'){
            break;
        }
        i++;
    }
}

// print values function
void display(UP *u){
    STACK *cursor = u->up;
    while(cursor != NULL){
        printf("%s\n ", cursor->s);
        cursor = cursor->next;
    }
}

// compare function
void compare(UP *u, char *str){
    char s[100];
    s[0]='\0';
    char r[30];
    int size;

    pop(u, r);
    strcpy(s, r);

    // flipping the input
    while(u->up != NULL){ 
        size=strlen(s);
        s[size] = ' ';
        s[size+1] = '\0';
        r[0] = '\0';
        pop(u, r);
        strcat(s, r);
    }

   if(strcmp(str, s) == 0){
        printf("The sentence is palindromic by words!\n");
   } else{
        printf("The sentence is not palindromic by words!\n");
   }
}

