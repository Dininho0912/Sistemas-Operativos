#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
   
   if (argc < 2) {
   printf("usage: cat filename1 [filename2 ...]\n");
   exit(EXIT_FAILURE);
   }

   for(int i = 1; i < argc; i++){

      int fd = open(argv[i], O_RDONLY);

      if (fd == -1) {
         printf("error: cannot open %s\n", argv[i]);
         continue;
      }
   
      off_t file_size = lseek(fd, 0, SEEK_END);

      if(file_size == -1){
         printf("error: cannot seek in %s\n", argv[i]);
         close(fd);
         continue;
      }

      for(off_t pos = file_size -1; pos >=0; pos--){
         if(lseek(fd, pos, SEEK_SET) == -1){
            printf("error: cannot seek in %s\n", argv[i]);
            break;
         }

         char ch;

         if(read(fd, &ch, 1) != 1){
            printf("error: cannot seek in %s\n", argv[i]);
            break;
         }

         write(STDOUT_FILENO, &ch, 1);
      }
 
      close(fd);
      write(STDOUT_FILENO, "\n", 1);
   }
   
   exit(EXIT_SUCCESS);
}
