#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>


int 
main(){

    pid_t       pidC, pidV;
    // int         ContadorV, ContadorC;
    int         fdV[2];
    int         fdC[2];
    int         fdContador[2];
    int         contador;
    char        bufferC[6];
    char        bufferV[6];
    char        letra;
    // ContadorV = 0;
    // ContadorC = 0;

    pipe(fdC);
    pipe(fdV);
    pipe(fdContador);   




    while(sizeof(bufferC) != 4 && sizeof(bufferC) != 4){
        
        scanf("%c", &letra);

        switch(letra){

            case 'a':
                if((pidV = fork())==0){
                    read(fdV[0], bufferV, sizeof(bufferV));
                } else {

                }
            break;

            case 'e':

            if((pidV = fork()) == 0){

                        size_t tam = sizeof(bufferV); 
                        read(fdV[0], bufferV, tam);
                        printf("Agregando: %c\n", letra);
                        bufferV[tam] = letra;
                        printf("%s", bufferV);

                        write(fdV[1], bufferV, sizeof(bufferV));
                
            } else{
                waitpid(pidC, NULL, 0);
            }
            break;

            case 'b':

                if((pidC = fork()) == 0){
                    
                    size_t tam = sizeof(bufferC);
                    read(fdC[0], bufferC, tam);
                    printf("Agregando: %c\n", letra);
                    bufferC[tam] = letra;
                                    printf("%s", bufferC);

                    write(fdC[1], bufferC, sizeof(bufferC));

                } else {
                    waitpid(pidC, NULL, 0);
                }
            break;

            case 'c':

                if((pidC = fork()) == 0){
                    
                    size_t tam = sizeof(bufferC);
                    read(fdC[0], bufferC, tam);
                    printf("Agregando: %c\n", letra);
                    bufferC[tam] = letra;
                                    printf("%s", bufferC);

                    write(fdC[1], bufferC, sizeof(bufferC));

                } else {
                    waitpid(pidC, NULL, 0);
                }
            break;

            default:
                printf("Opcion invalida\n");
                break;
            }
        }

    printf("%s", bufferC);
    printf("%s", bufferV);


}