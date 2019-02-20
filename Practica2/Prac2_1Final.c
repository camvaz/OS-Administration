#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, int * argv[]){

    pid_t pidY;

    if((pidY = fork())==0){

        pid_t pidS;

        if((pidS =fork())==0){
            printf("S: %d\n", (int)getpid());
        }
        else{
            waitpid(pidS, NULL, 0);
            pid_t pid$;
            printf("Y: %d\n", (int)getpid());
            if((pid$ = fork())==0)
            {
                printf("$: %d\n", (int)getpid());
            }
            else{
                waitpid(pid$, NULL,0);
            }

        }
    }
    else{
        waitpid(pidY, NULL, 0);
        pid_t pidE;
        if((pidE=fork())==0){
            pid_t pidT;
            if((pidT=fork())==0){
                printf("T: %d\n", (int)getpid());
            }
            else{
                waitpid(pidT,NULL,0);
                printf("E: %d\n", (int)getpid());
            }
            
        }
        else{
            waitpid(pidE, NULL, 0);
            printf("M: %d\n", (int)getpid());  
        }
        
    }

}