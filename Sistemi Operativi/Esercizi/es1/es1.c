/*Scrivere uno script che prende in input n file di testo (pathname)
e crea un file di testo di nome merged.txt che contiene l’unione
di tutti i file di testo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <libgen.h>

#define MAX_BUFSIZE 1024

int merge_files(int argc, char* argv[]){
    int sd, dd, size, result;
    char buffer[MAX_BUFSIZE];

    if ((dd = open("merged.txt", O_WRONLY | O_CREAT | O_TRUNC, 0660)) < 0){
        perror("merged.txt");
        return -1;
    }

    for(int i=1; i<argc; i++){
        sd = open(argv[i], O_RDONLY, 0660);
        if((sd) < 0){
            perror(argv[i]);
            return -1;
        }

        if((size = read(sd, buffer, MAX_BUFSIZE)) < 0){
            perror("read");
            return -1;
        }

        if((result = write(dd, buffer, size)) < 0){
            perror("write");
            return -1;
        }

        close(sd);

        if((result = write(dd, "\n", 1)) < 0){
            perror("write");
            return -1;
        }
    }

    close(dd);
}

int main(int argc, char** argv){
    if(argc < 2){
        printf("Usage: ./%s <file1.txt> <file2.txt> ...\n", basename((char*)argv[0]));
        return EXIT_FAILURE;
    }

    if (merge_files(argc, argv) < 0){
        perror("merge_files");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}