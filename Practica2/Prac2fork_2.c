#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    printf("ROOT: R. PID: %d\n", getpid());

    int pid = fork();


    if(pid == 0){
        printf("I: Proceso creado. PID: %d\n", getpid());
        printf("I: Proceso padre ROOT. PID: %d\n", getppid());

        int pid1 = fork();

        if(pid1 == 0){
            printf("D: Proceso creado. PID: %d\n", getpid());
            printf("D: Proceso padre I. PID: %d\n", getppid());

            int pid2 = fork();

            if(pid2 == 0){
                printf("A: Proceso creado. PID: %d\n", getpid());
                printf("A: Proceso padre D. PID: %d\n", getppid());
            }
            else{
                printf("D: Aun D. PID: %d\n", getpid());
                printf("D: Hijo A creado. PID: %d\n", pid2);
                
                int pid21 = fork();

                if(pid21 == 0){
                    printf("M: Proceso creado. PID: %d\n", getpid());
                    printf("M: Proceso padre D. PID: %d\n", getppid());
                } else {
                    printf("D: Aun D. PID: %d\n", getpid());
                    printf("D: Hijo M creado. PID: %d\n", pid21);
                    sleep(3);
                }
                sleep(3);
            }
        }
        else{
            printf("I: Aun I. PID: %d\n", getpid());
            printf("I: Hijo D creado. PID: %d\n", pid1);
            sleep(3);
        }

    }
    else{
        printf("ROOT: Aun ROOT: R. PID: %d\n", getpid());
        printf("ROOT: Hijo I creado. PID de Hijo: %d\n", pid);

        int pid01 = fork();

        if(pid01 == 0){
            printf("1: Proceso creado. PID: %d\n", getpid());
            printf("1: Proceso padre ROOT. PID: %d\n", getppid());
            
            int pid12 = fork();
            
            if(pid12 == 0){
                printf("N: Proceso creado. PID: %d\n", getpid());
                printf("N: Proceso padre 1. PID: %d\n", getppid());
            }
            else{
                printf("1: Aun 1. PID: %d\n", getpid());
                printf("1: Hijo N creado. PID: %d\n", pid12);
                sleep(3);
            }

        }
        else{
            printf("ROOT: Aun ROOT: R. PID: %d\n", getpid());
            printf("ROOT: Hijo 1 creado. PID: %d\n", pid01);
            
            int pid02 = fork();

            if(pid02 == 0){
                printf("A: Proceso creado. PID: %d\n", getpid());
                printf("A: Proceso padre ROOT. PID: %d\n", getppid());

                int pid13 = fork();

                if(pid13 == 0){
                    printf("R: Proceso creado. PID: %d\n", getpid());
                    printf("R: Proceso padre A. PID: %d\n", getppid());

                    int pid22 = fork();

                    if(pid22 == 0){
                        printf("T: Proceso creado. PID: %d\n", getpid());
                        printf("T: Proceso padre R. PID: %d\n", getppid());
                    }
                    else{
                        printf("R: Aun R. PID: %d\n", getpid());
                        printf("R: Hijo T creado. PID: %d\n", pid22);

                        int pid23 = fork();
                        if(pid23 == 0){
                            printf("S: Proceso creado. PID: %d\n", getpid());
                            printf("S: Proceso padre R. PID: %d\n", getppid());
                        }
                        else{
                            printf("R: Aun R. PID: %d\n", getpid());
                            printf("R: Hijo S creado. PID: %d\n", pid23);
                            sleep(3);
                        }
                        sleep(3);
                    }
                }
                else{
                    printf("A: Aun A. PID: %d\n", getpid());
                    printf("A: Hijo R creado. PID: %d\n", pid13);
                }
            }
            else{
                printf("ROOT: Aun ROOT: R. PID: %d\n", getpid());
                printf("ROOT: Hijo A creado. PID: %d\n", pid02);
                
                sleep(3);
            }
            sleep(3);
        }
    sleep(3);
    }
}