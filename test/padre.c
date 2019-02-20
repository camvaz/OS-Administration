#include<stdio.h>
#include<stdlib.h>

int main() {
	int pid;
	printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
	pid = fork();
	// En cuanto llamamos a fork se crea un nuevo proceso. En el proceso
	// padre 'pid' contendr� el pid del proceso hijo. En el proceso hijo
	// 'pid' valdr� 0. Eso es lo que usamos para distinguir si el c�digo
	// que se est� ejecutando pertenece al padre o al hijo.
	if (pid) // Este es el proceso padre
	{
		printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
		printf("PADRE: Mi hijo tiene el pid: %d\n", pid);
		int pid2;
		pid2=fork();
		if(pid2==0){//codigo hijo B
			printf("HIJOB: Soy el proceso hijo B con pid: %d\n",getpid());
			printf("HIJOB: mi padre tiene el pid: %d\n",getppid());
		}
		else{//codigo del padre
			printf("Soy el proceso padre con pid: %d\n",getpid());
			printf("Mi hijoB tiene el pid: %d\n ",pid2);
			sleep(10);
		}

	}
	else // Proceso hijo A
	{
		printf("HIJO: Soy el proceso hijo y mi pid es: %d\n", getpid());
		printf("HIJO: mi padre tiene el pid: %d\n", getppid());
	}
}