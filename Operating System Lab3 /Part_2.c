#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main (int argc, char *argv[]) 
{
	int status;
	int child = fork();
	if (child == 0)
	{
		printf ("PID value is , %d\n", getpid());
		char *argv[] = {"ls", "-la", 0};			
		execvp(argv[0], &argv[0]);
		printf ("EXECVP process failed\n");
	}
	else if (child > 0)
	{
		wait(&status);
	}
	else 
	{
		perror("Error detected");
	}
}