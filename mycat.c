#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    
    int i = 1;

    while(argv[i]!=NULL){
        
        FILE* file = fopen(argv[i], "r");

        if ( file == NULL ) {
            printf("error: could not open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE];
        int nchars = fread(buffer, sizeof(char), BUFFER_SIZE, file);

        while (nchars > 0) {
            fwrite(buffer, sizeof(char), nchars, stdout);
            nchars = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        }

       fclose(file);

       i++;
    }
    exit(EXIT_SUCCESS);
}
