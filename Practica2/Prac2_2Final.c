#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, int * argv[]){

    pid_t pidI;

    if((pidI=fork())==0){
        
        pid_t pidD;
        if((pidD = fork())==0){

            pid_t pidA;

            if((pidA = fork())==0){
                printf("A: %d\n", (int)getpid());
            }
            else{
                waitpid(pidA, NULL, 0);
                printf("D: %d\n", (int)getpid());
                pid_t pidM;

                if((pidM = fork())==0){
                    printf("M: %d\n", (int)getpid());
                }
                else{
                    waitpid(pidM, NULL, 0);
                }
            }
        }
        else{
            waitpid(pidD,NULL,0);
            printf("I: %d\n", (int)getpid());
        }

    }
    else{
        waitpid(pidI, NULL, 0);

        pid_t pid1;

        if((pid1=fork())==0){

            pid_t pidN;

            if((pidN = fork())==0){
                printf("N: %d\n", (int)getpid());
            }
            else{
                waitpid(pidN, NULL, 0);
                printf("1: %d\n", (int)getpid());
            }

        } else {

            waitpid(pid1,NULL, 0);

            pid_t pidA2;

            if((pidA2 = fork())==0){
                
                pid_t pidR;

                if((pidR = fork())==0){
                    pid_t pidS;

                    if((pidS = fork())==0){
                        printf("S: %d\n", (int)getpid());

                    } else {
                        waitpid(pidS, NULL, 0);

                        pid_t pidT;

                        if((pidT = fork())==0){
                            printf("T: %d\n", (int)getpid());
                        }
                        else{
                            waitpid(pidT, NULL, 0);
                            printf("R: %d\n", (int)getpid());
                        }
                    }

                }else{
                    waitpid(pidR, NULL, 0);
                    printf("A: %d\n", (int)getpid());
                }
            }
            else{
                waitpid(pidA2, NULL, 0);
                printf("R: %d\n", (int)getpid());
            }

        }

    }

}