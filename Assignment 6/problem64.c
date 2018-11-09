/*
JTSK-320112
a6_p4.c
Fatine Tazi
f.tazi@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
    char name[20];
    int pos;
    struct user *next;
};
typedef struct user USER;

// list of data function
USER *user_list(USER *u, char *t, int pos){ 
        USER *temp = (USER*)malloc((1)*sizeof(USER));
        if (temp == NULL){
            exit(1);
        }
        strcpy(temp->name, t);
        temp->pos = pos;
        temp->next = u;
        return temp;
}

// create list of data from file 
USER *user_list_file(FILE *fp) {
    char ch, temp[20];
    int i = 0, check = 0, pos = 0;
    temp[0]='\0';
    USER *u = NULL;
    while(1){
        if(check == 1){
            break;
        }
        while((ch = fgetc(fp)) != '\n') {
            temp[i] = ch;
            i++;
            if(ch == EOF){
                check = 1;
                break;
            }
        }
        temp[i] = '\0';
        pos = ftell(fp);
        u = user_list( u, temp, pos);
        i = 0;
    }
    return u;

}

// username correctness
int checku(char *s, USER *u, int *i){
    int flag = 0;
    USER *c = u;
    *i = 0;

    while (c != NULL){
        if(strcmp(c->name, s) == 0){
            flag = 1;
            break;
        }
        c = c -> next;
        (*i)++;
    }
    return flag;
}

// password correctness
int checkp(FILE *fp, USER *u, char *pass, int *i){
    USER *c = u;
    int m = 0, flag = 0;
    char ch, temp[20];

    while(m != *i){
        c = c->next;
        m++;
    }
    m = 0;
    // position for reading password from file
    fseek(fp, c->pos, SEEK_SET); 
    while((ch = fgetc(fp)) != '\n') {
        if(ch == EOF){
            break;
        }
        temp[m] = ch;
        m++;
    }

    temp[m] = '\0';

    if(strcmp(pass, temp) == 0){
        flag = 1;
    }
    return flag;
}


int main(){
    char user[20], pass[20], file[20];
    int i = 0;

    fgets(file, sizeof(file), stdin);
    file[strlen(file) - 1] = '\0';
    FILE *fp = fopen(file, "r");
    if(fp == NULL){
        exit(1);
    }

    USER *u = user_list_file(fp);

    while(strcmp(user, "exit") != 0) {
        fgets(user, sizeof(user), stdin);
        user[strlen(user) - 1] = '\0';
        if(checku( user, u, &i)) {
            fgets(pass, sizeof(pass), stdin);
            pass[strlen(pass) - 1] = '\0';
            if(checkp( fp, u, pass, &i)){
                printf("Access to user %s is granted.\n", user);    
            }else{
                printf("Access to user %s is denied.\n", user);
            }
        }
    }

    printf("Exiting ....\n");
    fclose(fp);
    return 0;
}

