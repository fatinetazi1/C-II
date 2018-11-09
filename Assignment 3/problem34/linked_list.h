/*
JTSK-320112
a3 p4.c
Fatine Tazi
f.tazi@jacobs-university.de
*/
#ifndef HEADER_H_INCLUDE
#define HEADER_H_INCLUDE
struct list{
	int info;
	struct list* next;
};
void print_list (struct list* my_list);
struct list* push_front (struct list* my_list, int value);
struct list* push_back (struct list* my_list, int value);
void dispose_list (struct list* my_list);
void remove_first(struct list** my_list);
#endif
