#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, int * argv[]){

    pid_t pidY;

    if((pidY = fork()) == 0){
        pid_t pidS;
     
        if((pidS = fork())==0){
     
            printf("S: %d\n", (int) getpid());
     
        }
        else{
            pid_t pid$;

            if((pid$ = fork())==0){
     
                sleep(1);
                printf("$: %d\n", (int)getpid());
     
            }
            else{
     
                waitpid(pidS, NULL, 0);
                printf("Y: %d\n", (int)getpid());
                waitpid(pid$, NULL, 0);

            }
        }
    }
    else {
        pid_t pidE;

        if((pidE = fork())==0){

            pid_t pidT;
            if((pidT = fork())==0){

                sleep(2);
                printf("T: %d\n", (int)getpid());

            }
            else{
                
                waitpid(pidT, NULL, 0);
                printf("E: %d\n", (int)getpid());   

            }
        }
        else{
     
            waitpid(pidY, NULL, 0);
            waitpid(pidE, NULL, 0);
            printf("M: %d\n", (int) getpid());
            exit(0);
     
        }
    }
}