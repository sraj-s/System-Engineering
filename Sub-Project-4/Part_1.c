#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main (int argc, char *argv[]) 
{
	char buffer[100];
	char *arr[100];
	while(1){
		int i = 0;	
		fgets(buffer, 100, stdin);
		int len = strlen(buffer);
		buffer[len - 1] = '\0';

		if (strcmp(buffer, "quit") == 0){
			break;		
		}
		
		char *split_string = strtok(buffer, " \t");
		while(split_string && i < 100){
			arr[i++] = split_string;
			split_string = strtok(NULL, " \t");
		}
		arr[i] = NULL;
// ------------------------- begin --------------------------------
		int status;
		int child = fork();
		if (child == 0)
		{
			printf ("Child PID, %d\n", getpid());
			execvp(arr[0], &arr[0]);
			printf ("Error detected  \n");
			exit(EXIT_SUCCESS);
		}
		else if (child > 0)
		{
			wait(&status);
		}
		else 
		{
			perror("Error detected ");
		}
	}
return 0;
}