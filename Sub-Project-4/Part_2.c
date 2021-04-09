// Project By: Sambeg Raj Subedi 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
	int status;
	FILE *fp;
	int c;
	int x = 2; 
	int y = 2;
    int row = 10;  
	int column = x * y;
	int info[row][column];
	fp = fopen("quiz.txt", "r");

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fscanf(fp, "%i ", &c);
			info[i][j] = c;
		}
	}
// ------------ printing the read values -----------------    
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%d ", info[i][j]);
			
		}
	printf("\n");
	}
// -------------- Creating the child process --------------	
	int pid, pid2;
	int counting_hw = 0;
	int i;
	for ( i = 1; i <= x; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("\n Manager  %d \n ", i);
            
			int j;
			for ( j = 1; j <= y; j++)
			{
				pid2 = fork();
				if (pid2 == -1)
				{
					exit(EXIT_FAILURE);
				}
				else if (pid2 == 0)
				{
					int grade_in_total = 0;
					double grade_average = 0.0;
					printf("Worker   %d \n", j);

// ------------------ Calculating the average grade -------------------
					int k;
					for ( k = 0; k < 10; k++)
					{
						 grade_in_total = grade_in_total + info[k][counting_hw];
					}
					grade_average = (double)grade_in_total / (double)row;
					printf("Average grade of HW :  %d of Chapter %d : ", j, i);
					printf("%f", grade_average);
					printf("\n");
					exit(EXIT_SUCCESS);
				}
				else 
				{
					wait(&status);	
				}
			counting_hw++;
			}
			exit(EXIT_SUCCESS);
		}
		else 
		{
			wait(&status);	
		}	
		wait(&status);	
	}
	wait(&status);	
	fclose(fp);	
return 0;
}