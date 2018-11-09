/*
JTSK-320112
a3 p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int c; //checking

//Creating the list structure
struct list{
	char data;
	struct list* next;
	struct list* prev;
};

//Pointers to different parts of the list
struct list* head = NULL;
struct list* current = NULL;
struct list* tail = NULL;

//Printing a list function
void print_list (struct list *my_list){
	struct list* p;
	p = my_list;
	if (p == NULL) {
		printf("List is empty.\n");
		return;
	}
	while(p != NULL){
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

//Printing backwards function
void print_list_backward (struct list *my_list){
	struct list* p;
	p = my_list;
	if (p == NULL) {
		printf("List is empty.\n");
		return;
	}
	while(p->next != NULL){
		p = p->next;
	}
	while(p != NULL){
		printf("%c ", p->data);
		p = p->prev;
	}
	printf("\n");
}

//Inserting new element in the front funcion
struct list* push_front (struct list *my_list, char value){
	struct list* newel;
	newel = (struct list*) malloc(sizeof(struct list));
	if (newel == NULL){
		printf("Error allocating memory\n");
		exit(1);
	}
	newel->data = value;
	newel->next = my_list;
	if(my_list != NULL){
		my_list->prev = newel;
	}
	newel->prev = NULL;
	return newel;
}

//Delete occurences of a given character function
struct list* deletelem(struct list *my_list, char value){
	c = 0;
	struct list *cursor, *temp;
	cursor = my_list;
	if(cursor == NULL){
		printf("List is empty.\n");
		return my_list;
	}
	while(cursor->data == value){
		c++;
		temp = cursor;
		cursor = cursor->next;
		free(temp);
		if(cursor != NULL){
			cursor->prev = NULL;
		} else {
			return NULL;
		}
	}
	my_list = cursor;
	while(cursor->next != NULL){
		if ((cursor->next)->data == value) {
			c++;
			temp = cursor->next;
			cursor->next = temp->next;
			if (temp->next !=NULL) {
				(temp->next)->prev = cursor;
			}
			free(temp);
		} else {
			cursor = cursor->next;
		}
	}

	if (c == 0){
		printf("The element is not in the list!\n");
	}

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

int main(){

	struct list* my_list = NULL;
	char ch;
	int i = 0;

	do {
		scanf("%d", &i);
		getchar();
		switch(i){
			case 1:
				scanf("%c", &ch);
				getchar();
				my_list = push_front(my_list, ch);
				break;
			case 2:
				scanf("%c", &ch);
				getchar();
				my_list = deletelem(my_list, ch);
				break;
			case 3:
				print_list(my_list);
				break;
			case 4:
				print_list_backward(my_list);
				break;
			case 5:
				dispose_list(my_list);
				break;
			default: 
				printf("Invalid Entry\n");
		}
	} while( i != 5);
	return 0;
}