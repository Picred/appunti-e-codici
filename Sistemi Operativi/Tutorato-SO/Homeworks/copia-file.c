/*# Homework 1
Scrivere un programma in linguaggio C che permetta di copiare un numero arbitrario di file regolari su una directory di destinazione preesistente.

Il programma dovra' accettare una sintassi del tipo:

$ homework-1 file1.txt path/file2.txt "nome con spazi.pdf" directory-destinazione
*/

// 09-06 supporta solo txt

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int copy_file(const char* src,char dst[]){
    char dst_path[1000];
    strcpy(dst_path, dst);
    strcat(dst_path, "/");
    strcat(dst_path, src);

    FILE* source_file = fopen(src, "r");
    FILE* dst_file = fopen(dst_path, "w");


    char buffer[10000];
    while(fgets(buffer, sizeof(buffer), source_file) != NULL){
        fprintf(dst_file, "%s", buffer);
    }

    fclose(dst_file);
    fclose(source_file);

    return EXIT_SUCCESS;
}

int main(int argc, char** argv){

    //leggi argomento per argomento fino ad argc-2 e fai la copia nella cartella di destinazione che sarà argc-1

    char dest_path[strlen(argv[argc-1])];
    strcpy(dest_path,argv[argc-1]);

    for(int i=1; i<argc; i++){
        if((fopen(argv[i], "r")) < 0){
            printf("Il file %s e' inesistente. Ritenta. \n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    printf("File di destinazione selezionato: %s\n", dest_path);
    // tutti i file esistono
    
    for(int i=1; i<argc-1; i++){
        const char* src_file = argv[i];
        copy_file(src_file, dest_path);

        printf("%s copied\n", argv[i]);
        remove(argv[i]);

    }

    printf("All files copied!");
    return EXIT_SUCCESS;
}
