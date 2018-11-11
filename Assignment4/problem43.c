/*
JTSK-320112
a4 p3.c
Fatine Tazi
f.tazi@jacobs-university.de
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascending(const void *va, const void *vb){
	const int* a = (const int*) va;
	const int* b = (const int*) vb;
	return *a-*b;
}

int descending(const void *va, const void *vb){
	const int* a = (const int*) va;
	const int* b = (const int*) vb;
	return *b-*a;
}

int main(){
	char c;
	int (*compare)(const void *va, const void *vb);

	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	getchar();

	while(1){
		scanf("%c", &c);
		getchar();
		if(c == 'e'){
			break;
		} else if (c == 'a'){
			compare = ascending;
		} else if (c == 'd'){
			compare = descending;
		}

		qsort(arr, n, sizeof(arr[0]), compare);

		for (int i = 0; i < n; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}