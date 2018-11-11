/*
JTSK-320112
a5_p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#ifndef STACK_H
#define STACK_H

struct stack{
    char s[30];
    struct stack *next;
};
typedef struct stack STACK;

struct up{
    int count;
    STACK *up;
};
typedef struct up UP;

// input elements the stack function
void push(UP *u, char str[30]);

// output elements function
void pop(UP *u, char str[30]);

// creates stack function
void init(UP *u, char str[1000]);

// print values function
void display(UP *u);

// compare function
void compare(UP *u, char *str);

#endif 
