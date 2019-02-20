#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    pid_t pidArray[8];
    
    if((pidArray[0]=fork())==0){
        if((pidArray[1]=fork())==0){
            printf("S: %d\n", (int)getpid());
        }
        else{
            if((pidArray[2]=fork())==0){
                waitpid(pidArray[0], NULL, 0);
                printf("$: %d\n", (int)getpid());
            }
            else{
                waitpid(pidArray[1], NULL, 0);
                printf("Y: %d\n", (int)getpid());
            }
        }
    }
    else{
        if((pidArray[3]=fork())==0){
            if(pidArray[4]=fork()==0){
                waitpid(pidArray[2], NULL, 0);
                printf("T: %d\n", (int)getpid());
            }
            else{
                waitpid(pidArray[4],NULL,0);
                printf("E: %d\n", (int)getpid());
            }
        }
        else{
            waitpid(pidArray[0],NULL, 0);
            waitpid(pidArray[3], NULL, 0);
            printf("M: %d\n", (int)getpid());
        }
    }

}