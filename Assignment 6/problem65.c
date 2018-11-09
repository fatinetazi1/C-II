/*
JTSK-320112
a6_p5.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE **fp, *out;
	int file = 0, m = 0, flag = 0;
	char temp[20], buff[64];
	memset(buff, '\0', 64);
	scanf("%d", &file);
	getchar();

	// array of file elements
	fp = (FILE**) malloc(sizeof(FILE)*file); 
    out = fopen("output.txt", "w");

    // getting file names
    for(int i = 0; i < file; i++) {
        fgets(temp, 20, stdin);
        temp[strlen(temp)-1]='\0';
        fp[i] = fopen(temp, "r");
        if(fp[i] == NULL){
            printf("Error on %d file ", i+1);
            exit(1);
        }
    }

    int u = 0;
    printf("Concating the content of 3 files ... \nThe result is: \n");
    while(m != file) {
        flag = 0;
        memset(buff, '\0', 64);
        while(fread(buff, 64, 1,fp[m]) == 0) {
           	fwrite(buff, 1, 64, out);
           	fprintf(out, "\r\n");
           	printf("%s\n", buff);
            memset(buff, '\0', 64);
            m++;
            flag=1;
            if(m == file){
                break;
                u = 1;
            }
        }
        if(flag == 1){
            continue;
        }
        while(u == 0){
        fwrite(buff, 1, 64, out);
        printf("%s\n", buff);
        }
    }
    printf("The result was written into output.txt\n");

	// closing files and deallocating memory
    for(int i = 0; i < file; i++){
        fclose(fp[i]);
    }
    free(fp);
    fclose(out);
    return 0;
}