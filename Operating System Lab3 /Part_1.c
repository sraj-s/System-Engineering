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
		
		execl ("/bin/date", "date", 0, NULL);
		printf ("Failed\n");
	}
	else if (child > 0)
	{
		wait (&status);
	}
	else 
	{
		perror ("Error detected");
	}
return 0;
}
