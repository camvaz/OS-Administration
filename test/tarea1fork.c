#include <stdio.h>

int main(){

	printf("Root: M. PID: %d\n", getpid());
	int pid;

	pid = fork();

	if(pid == 0){
		printf("Hijo1 Root: Y. PID %d\n", getpid());
		printf("HIjo1 de Root: PID de Root: %d\n", getppid());
		int pid02 = fork();
		if(pid02 == 0){
			printf("Hijo1 de Hijo1: S. PID: %d\n", getpid());
			printf("Hijo1 de HIjo1: PID de Hijo1 de Root: %d\n", getppid());		
		}
		else{
			printf("Hijo1 de Root: Aun Y. PID: %d\n", getpid());
			printf("Hijo1 de Root: Hijo1 creado. PID: %d", pid02);
			int pid03 = fork();
			if(pid03 == 0){
				printf("Hijo2 de Hijo1: $. PID: %d\n", getpid());
				printf("Hijo2 de Hijo1: PID de Hijo1 de Root: %d\n", getppid());
			}
			else{
				printf("Hijo1 de Root: Aun Y. PID: %d\n", getpid());
				printf("Hijo1 de Root: Hijo2 creado. PID: %d\n", pid03);
				sleep(3);
			}
			sleep(3);
		}
	}
	else{
		printf("Root: Aun M. PID: %d\n", getpid());
		printf("Root: Hijo1 creado. PID: %d\n", pid);
		
		int pid2;
		pid2 = fork();
		
		if(pid2 == 0){
			printf("Hijo2 de Root: E. PID: %d\n", getpid());
			printf("Hijo2 de Root: PID de Root: %d\n", getppid());

			int pid21;
			pid21 = fork();

			if(pid21 == 0){
				printf("Hijo1 de Hijo2: T. PID: %d\n", getpid());
				printf("Hijo1 de Hijo2: PID de Hijo2 de Root: %d\n", getppid());
			}
			else{
				printf("Hijo2 de Root: Aun E. PID: %d\n", getpid());
				printf("Hijo2 de Root: Hijo1 creado. PID: %d\n", pid21);
				sleep(3);
			}
		
		}
		else{
			printf("Root: Aun M. PID: %d\n", getpid());
			printf("Root: Hijo2 creado. PID: %d\n", pid2);
			sleep(3);
		}
		sleep(3);
	}

}
