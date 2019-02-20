#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, int * argv[]){

    pid_t pidI;

    if((pidI = fork())==0){
        pid_t pidD;

        if((pidD = fork())== 0){
            pid_t pidA;

            if((pidA = fork())==0){
                printf("A: %d\n", (int)getpid());
            }
            else{
                pid_t pidM;
                if((pidM = fork()) == 0){
                    sleep(1);
                    printf("M: %d\n", (int) getpid());
                }
                else{
                    waitpid(pidA, NULL, 0);
                    printf("D: %d\n", (int)getpid());
                    waitpid(pidM, NULL, 0);
                }
            }
        }
        else{
            waitpid(pidD, NULL, 0);
            printf("I: %d\n", (int)getpid());
        }
    }
    else{
        pid_t pid1;
        
        if((pid1 = fork())==0){
            pid_t pidN;

            if((pidN = fork())== 0){
                sleep(2);
                printf("N: %d\n", (int)getpid());
            }
            else{
                waitpid(pidN, NULL, 0);
                printf("1: %d\n", (int)getpid());
            }
        }
        else{
            pid_t pidA2;

            if((pidA2 = fork())==0){
                pid_t pidR;
                if((pidR = fork())==0){
                    pid_t pidT;

                    if((pidT = fork())==0){
                        sleep(4);
                        printf("T: %d\n", (int)getpid());
                    }
                    else{
                        pid_t pidS;
                        
                        if((pidS = fork())==0){
                            sleep(3);
                            printf("S: %d\n", (int) getpid());
                        }
                        else{
                            waitpid(pidS, NULL, 0);
                            waitpid(pidT, NULL, 0);
                            printf("R: %d\n", (int)getpid());
                        }
                    }
                }
                else{
                    waitpid(pidA2, NULL, 0);
                    printf("A: %d\n", (int)getpid());
                }
            }
            else{
                waitpid(pidI,NULL,0);
                waitpid(pid1, NULL, 0);
                waitpid(pidA2, NULL, 0);
                printf("R: %d\n", (int)getpid());
            }
        }
    }
}