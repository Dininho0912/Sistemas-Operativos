#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#define LINESIZE 256
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int pipe_fd[2];
    pid_t pid;
    
    if (pipe(pipe_fd) == -1) { perror("pipe"); exit(EXIT_FAILURE); }

    if ((pid = fork()) == -1) { perror("fork"); exit(EXIT_FAILURE); }


    
    if (pid > 0) { /* parent */
        close(pipe_fd[0]);

        for(int i = 1; i < argc; i++){
            int file_fd = open(argv[i], O_RDONLY);

            if(file_fd == -1){
                printf("error: cannot open %s\n", argv[i]);
                continue;
            }
        
            char buffer[BUFFER_SIZE];
            ssize_t nbytes;

            while ((nbytes = read(file_fd, buffer, BUFFER_SIZE)) > 0){
                write(pipe_fd[1], buffer, nbytes);
            }
            close(file_fd);
        }
        close(pipe_fd[1]);
        if ( wait(NULL) == -1) { perror("wait"); exit(EXIT_FAILURE); }
        exit(EXIT_SUCCESS);

    } else { /* child */
        close(pipe_fd[1]);

        char buffer[BUFFER_SIZE];
        ssize_t nbytes;
        
        while((nbytes = read(pipe_fd[0], buffer, BUFFER_SIZE)) > 0){
            write(STDOUT_FILENO, buffer, nbytes);
        }
        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    }
}
