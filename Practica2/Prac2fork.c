#include <stdio.h>

int main(){

	printf("Root: M. PID: %d\n", getpid());
	int pid;

	pid = fork();

	if(pid == 0){
		printf("Y: Proceso creado PID %d\n", getpid());
		printf("Y: Proceso padre Root: M. PID: %d\n", getppid());
		int pid02 = fork();
		if(pid02 == 0){
			printf("S: Proceso creado. PID: %d\n", getpid());
			printf("S: Proceso padre  Y. PID: %d\n", getppid());		
		}
		else{
			printf("Y: Aun Y. PID: %d\n", getpid());
			printf("Y: Hijo S creado. PID: %d\n", pid02);
			int pid03 = fork();
			if(pid03 == 0){
				printf("$: Proceso creado. PID: %d\n", getpid());
				printf("$: Proceso padre Y. PID: %d\n", getppid());
			}
			else{
				printf("Y: Aun Y. PID: %d\n", getpid());
				printf("Y: Hijo $ creado. PID: %d\n", pid03);
				sleep(3);
			}
			sleep(3);
		}
	}
	else{
		printf("Root: Aun M. PID: %d\n", getpid());
		printf("Root: Hijo Y creado. PID: %d\n", pid);
		
		int pid2;
		pid2 = fork();
		
		if(pid2 == 0){
			printf("E: Proceso creado. PID: %d\n", getpid());
			printf("E: Proceso padre Root: M. PID: %d\n", getppid());

			int pid21;
			pid21 = fork();

			if(pid21 == 0){
				printf("T: Proceso creado. PID: %d\n", getpid());
				printf("T: Proceso padre E. PID: %d\n", getppid());
			}
			else{
				printf("E: Aun E. PID: %d\n", getpid());
				printf("E: Hijo T creado. PID: %d\n", pid21);
				sleep(3);
			}
		
		}
		else{
			printf("Root: Aun M. PID: %d\n", getpid());
			printf("Root: Hijo E creado. PID: %d\n", pid2);
			sleep(3);
		}
		sleep(3);
	}

}
