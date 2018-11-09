/*
JTSK-320112
a4 p2.c
Fatine Tazi
f.tazi@jacobs-university.de
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpper(char value[100]){
	char s[100];
	strcpy(s, value);

	int i = 0;
	while(s[i] != '\0'){
		if(s[i] >= 97 && s[i] <= 122){
			s[i]=s[i]-32;
		}
		i++;
	}
	printf("%s\n", s);
}

void toLower(char value[100]){
	char s[100];
	strcpy(s, value);

	int i = 0;
	while(s[i] != '\0'){
		if(s[i] >= 65 && s[i] <= 90){
			s[i]=s[i]+32;
		}
		i++;
	}
	printf("%s\n", s);
}

void toOpp(char value[100]){
	char s[100];
	strcpy(s, value);

	int i = 0;
	while(s[i] != '\0'){
		if(s[i] >= 97 && s[i] <= 122){
			s[i]=s[i]-32;
		} else if (s[i] >= 65 && s[i] <= 90){
			s[i]=s[i]+32;
		}
		i++;
	}
	printf("%s\n", s);
}

int main(){

	char value[100];
	int i = 0;
	void (*funcArray[3])(char* s) = {toUpper, toLower, toOpp};

	fgets(value, 100, stdin);
	value[strlen(value) - 1] = '\0';

	while(1){
		scanf("%d", &i);
		getchar();
		if (i == 4){
			break;
		} else {
			funcArray[i-1](value);
		}
	}
	return 0;
}