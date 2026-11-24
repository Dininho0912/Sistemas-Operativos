#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "usage: %s file1 [file2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sum_st_size = 0;
    int sum_st_blocks = 0;

    for(int i = 1; i<argc; i++){
    
        struct stat info;

        int retv = stat(argv[i], &info);

        if (retv == -1) {
            fprintf(stderr, "fsize: Can't stat %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        //printf("%s size: %d bytes, disk_blocks: %d\n",
        //argv[i], (int)info.st_size, (int)info.st_blocks);

        sum_st_size += (int)info.st_size;
        sum_st_blocks += (int)info.st_blocks;

        printf("Time since last modification of %s: %s",argv[i], ctime(&info.st_mtime));   
        printf("UID of the owner of file %s: %d\n", argv[i], info.st_uid);
    }

    printf("Total size: %d bytes, disk_blocks: %d\n", 
    sum_st_size, sum_st_blocks);    

    
    exit(EXIT_SUCCESS);
}
