/*
JTSK-320112
a6 p1.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// checking if c is a special character function
int check(char c){
	int flag = 0;
	char arr[8] = {' ', '?', '!', '.', '\t', '\r', '\n'};
	for (int i = 0; i < 8; ++i){
		if (arr[i] == c) {
			flag = 1;
		}
	}
	return flag;
}

int main(){
	int count = 0, flag = 0;
	char s[100], ch;
	fgets(s, 100, stdin);
	s[strlen(s) - 1] = '\0';
	FILE *fp = fopen(s, "r"); 
	if(!fp){
		fprintf(stderr, "Can not open file.\n");
		exit(1);
	}
	
	while((ch=getc(fp)) != EOF){
		if(check(ch) == 1){
			count++;
			flag = 1;
			while(check(ch) == 1 && ch != EOF){
				ch=getc(fp);
			}
		}else{
			flag = 0;
		}
	}

	if(flag == 0){
		count++;
	}

	printf("The file contains %d words.\n", count);
	fclose(fp);
}