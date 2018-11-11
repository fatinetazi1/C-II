/*
JTSK-320112
a4 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
 
int main(){
 
    struct list* my_list = NULL;
    char i = 'i';
    int info;
 
    while(i != 'q'){
        scanf("%c", &i);
        switch(i){
            case 'a':
                scanf("%d", &info);
                getchar();
                my_list = push_back(my_list, info);
                break;
            case 'b':
                scanf("%d", &info);
                getchar();
                my_list = push_front(my_list, info);
                break;
            case 'r':
                remove_first(&my_list);
                break;
            case 'p':
                print_list(my_list);
                break;
            case 'q':
                dispose_list(my_list);
                break;
        }
    }
 
    return 0;
}