/*
JTSK-320112
a4 p2.c
Fatine Tazi
f.tazi@jacobs-university.de
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct person {
	char name[100];
	int age;
}; 

int cname(struct person* a, struct person* b){
	int str_comp = strcmp(a->name, b->name);
	int int_comp = (b->age < a->age) - (a->age < b->age);

	return str_comp != 0 ? str_comp : int_comp;
}

int cage(struct person* a, struct person* b){
	int str_comp = strcmp(a->name, b->name);
	int int_comp = (b->age < a->age) - (a->age < b->age);

	return int_comp != 0 ? int_comp : str_comp;
}

void bubblesort(struct person* per, int n, int(*cmp)(struct person* a, struct person *b)){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-1; ++j) {
			if (cmp(&per[j+1], &per[j]) < 0) {
				struct person temp = per[j+1];
				per[j+1] = per[j];
				per[j] = temp;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();

	struct person *per = (struct person*)malloc(sizeof(struct person)*n);
	if (per == NULL) {
		exit(1);
	}

	for (int i = 0; i < n; ++i)
	{
		fgets(per[i].name, sizeof(per[i].name), stdin);
		per[i].name[strlen(per[i].name)-1] = '\0';
		scanf("%d", &per[i].age);
		getchar();
	}

	bubblesort(per, n, cname);
	for (int i = 0; i < n; ++i)
	{
		printf("{%s, %d}; ", per[i].name, per[i].age);
	}
	printf("\n");

	bubblesort(per, n, cage);
	for (int i = 0; i < n; ++i)
	{
		printf("{%s, %d}; ", per[i].name, per[i].age);
	}
	printf("\n"); 
	free(per);
}