#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){

	pid_t pid;

	pid = fork();

	if(pid == 0){
		
		pid_t pid02 = fork();
		if(pid02 == 0){
			printf("S: Proceso creado. PID: %d\n", (int) getpid());	
		}
		else{
			pid_t pid03 = fork();
			if(pid03 == 0){
                waitpid(-1, NULL, 0); // CREO QUE EL PEX EST AQUI
				printf("$: Proceso creado. PID: %d\n", (int) getpid());
			}
			else{
			}
			
		}
        waitpid(pid02, NULL, 0);
        printf("Y: Proceso creado PID %d\n", (int) getpid());
	}
	else{

		pid_t pid2;
		pid2 = fork();
		
		if(pid2 == 0){

			pid_t pid21;
			pid21 = fork();

			if(pid21 == 0){ 
                waitpid(-1, NULL, 0); // CREO QUE EL PEX ESTA AQUI TAMBN
				printf("T: Proceso creado. PID: %d\n", (int) getpid());

			}
			else{

			}
            waitpid(pid21, NULL, 0);
            printf("E: Proceso creado. PID: %d\n", (int) getpid());
		
		}
		else{
		}

        waitpid(pid2, NULL, 0);
		
        printf("M: Aun M. PID: %d\n", (int) getpid());
	}

}
