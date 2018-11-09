/*
JTSK-320112
a3 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//Creating the list structure
struct list{
	int info;
	struct list* next;
};

//Printing function of a list
void print_list (struct list* my_list){
	struct list* p;
	for (p = my_list; p; p = p->next) {
		printf ("%d ", p->info);
	}
	printf("\n");
}

//Inserting new element in the front funcion
struct list* push_front (struct list* my_list, int value){
	struct list* newel;
	newel = (struct list*) malloc(sizeof(struct list));
	if (newel == NULL){
		printf ("Error allocating memory \n");
		return my_list;
	}
	newel->info = value;
	newel->next = my_list;
	return newel;
}

//Inserting new element at the end funcion
struct list* push_back (struct list* my_list, int value){
	struct list *cursor, *newel;
	cursor = my_list;
	newel = (struct list*) malloc(sizeof(struct list));
	if (newel == NULL){
		printf("Error allocating memory \n");
		return my_list;
	}
	newel->info = value ;
	newel->next = NULL ;
	if (my_list == NULL ){
		return newel;
	}
	while (cursor->next != NULL){
		cursor = cursor->next;
	}
	cursor->next = newel;
	return my_list;
}

//Freeing a list function
void dispose_list (struct list* my_list){
	struct list* nextelem;
	while (my_list != NULL){
		nextelem = my_list->next;
 		free(my_list);
		my_list = nextelem;
	}
}

//Removing first element function 
void remove_first(struct list** my_list){
	struct list* temp = * my_list;
	if (temp == NULL)
	{
		return;
	} else {
		*my_list = temp -> next;
		free(temp);
	}
}

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