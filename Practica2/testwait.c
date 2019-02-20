#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, int * argv[]){

    pid_t pid;

    if((pid = fork()) == 0){

        printf("S: %d\n", (int) getpid());

    }
    else {
        pid_t pid2;
        if((pid2 = fork()) == 0){
            sleep(1);
            printf("$: %d\n", (int) getpid());
        }

        else{
            waitpid(pid, NULL, 0);
            printf("Y: %d\n", getpid());
            waitpid(pid2, NULL, 0);
            exit(0);
        }
    }

}