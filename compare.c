#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 64

int main(int argc, char* argv[]) {
    
    char* p1 = (char*)malloc(MAX_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_SIZE * sizeof(char));
    
    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);

    for(int i = 0; p1[i] != '\0'; i++){
        p1[i]=tolower(p1[i]);
    }

    for(int i = 0; p2[i] != '\0'; i++){
        p2[i]=tolower(p2[i]);
    }

    char *test = strstr(p2, p1);

    if(test != NULL){
        printf("resulta\n");
    }
    else printf("nao tem\n");

    printf("p1 holds:%s\n", p1);
    
    return 0;
}