#include<stdio.h>
#include<stdlib.h>

int main() {
	int pid;
	printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
	pid = fork();
	// En cuanto llamamos a fork se crea un nuevo proceso. En el proceso
	// padre 'pid' contendrá el pid del proceso hijo. En el proceso hijo
	// 'pid' valdrá 0. Eso es lo que usamos para distinguir si el código
	// que se está ejecutando pertenece al padre o al hijo.
	if (pid) // Este es el proceso padre
	{
		printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
		printf("PADRE: Mi hijo tiene el pid: %d\n", pid);
		int pid2 = fork();
		if (pid2) // Este es el proceso padre
		{
			printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
			printf("PADRE: Mi hijo tiene el pid: %d\n", pid2);
			sleep(2);
		}
		else // Proceso hijo 2
		{
			printf("HIJO2: Soy el proceso hijo y mi pid es: %d\n", getpid());
			printf("HIJO2: mi padre tiene el pid: %d\n", getppid());
		}
		//sleep(2);
	}
	else // Proceso hijo
	{
		printf("HIJO: Soy el proceso hijo y mi pid es: %d\n", getpid());
		printf("HIJO: mi padre tiene el pid: %d\n", getppid());
	
		int pid3 = fork();
		if (pid3) // Este es el proceso hijo-padre
		{
			printf("HIJO-PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
			printf("HiJO-PADRE: Mi hijo tiene el pid: %d\n", pid3);
			sleep(2);
		}
		else // Proceso hijo 3
		{
			printf("NIETO: Soy el proceso hijo y mi pid es: %d\n", getpid());
			printf("NIETO: mi padre tiene el pid: %d\n", getppid());
		}
	}
}