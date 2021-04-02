// Project By: Sambeg Raj Subedi

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	
	int child1 = fork();
	int pid;
	if (child1 == 0)
	{
		printf("I am child one, my pid is: %d\n", getpid());
	}
	else 
	{
		waitpid(-1, NULL, 0);	
		int child2 = fork();
		if (child2 == 0)
		{
			printf("I am child two, my pid is: %d\n", getpid());
					
		}else 
		{
			waitpid(-1, NULL, 0);						
			printf("I am parent");
		}
	}
return 0;
}