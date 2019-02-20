#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    pid_t pidY;

    char buffer[6];
    int fd[2];

    pipe(fd);

    if((pidY = fork())==0){

        pid_t pidS;

        if((pidS =fork())==0){

            printf("S ingresado. PID: %d\n", (int)getpid());
            read(fd[0], buffer, 0);
            buffer[0] = 'S';
            write(fd[1], buffer, 1);

        }
        else{
            waitpid(pidS, NULL, 0);
            pid_t pid$;
            printf("Y ingresado. PID: %d\n", (int)getpid());

            read(fd[0], buffer, 1);
            buffer[1] = 'Y';
            write(fd[1], buffer, 2);

            if((pid$ = fork())==0)
            {
                printf("$ ingresado. PID: %d\n", (int)getpid());
                read(fd[0], buffer, 2);
                buffer[2] = '$';
                write(fd[1], buffer, 3);
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
                printf("T ingresado. PID: %d\n", (int)getpid());
                read(fd[0], buffer, 3);
                buffer[3] = 'T';
                write(fd[1], buffer, 4);
            }
            else{
                waitpid(pidT,NULL,0);
                printf("E ingresado. PID: %d\n", (int)getpid());
                read(fd[0], buffer, 4);
                buffer[4] = 'E';
                write(fd[1], buffer, 5);
            }
        }
        else{
            waitpid(pidE, NULL, 0);
            printf("M ingresado. PID: %d\n", (int)getpid());
            read(fd[0], buffer, 5);
            buffer[5] = 'M';\
            write(fd[1], buffer, 6);

            printf("\nCadena final: %s \n", buffer);
        }
        
    }

}