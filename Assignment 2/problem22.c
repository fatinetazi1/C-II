/*
JTSK-320112
a2 p2.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    char stringone[100];
    char stringtwo[100];

	fgets(stringone, sizeof(stringone), stdin);
    fgets(stringtwo, sizeof(stringtwo), stdin);

    int i = 0;
    while(stringone[i] != '\n'){
        i++;
    }

    int j = 0;
    while(stringtwo[j] != '\n'){
        j++;
    }

    int size = i + j;

    char* conc = (char*) malloc(sizeof(char)*size);

    int z = 0;
    for (z = 0; z < i; ++z)
    {
        conc[z] = stringone[z];
    }

    for (int k = 0; k < size; ++k)
    {
        conc[z] = stringtwo[k]; 
        z++;
    }

    printf("Result of concatenation: %s", conc);

    return 0;
}