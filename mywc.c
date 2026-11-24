#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argv[1] == "-c"){

    }
    
    if(argv[1] == "-l"){
        /* open file, exit on error */
        FILE* file = fopen(argv[2], "r");

        if ( file == NULL ) {
            printf("error: could not open %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        /* read file, line by line */
        size_t read;
        size_t size = 0;
        char* line = NULL;
        int lineno = 0;

        while ((read = getline(&line, &size, file)) != -1) {
            lineno++;
        }

        printf("%d",lineno);

        /* close file */
        fclose(file);
        /* return gracefully */
        exit(EXIT_SUCCESS);
    }
}