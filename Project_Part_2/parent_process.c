#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

	int a = 10, b = 25, fq = 0, fr = 0;
	fq = fork();
	if (fq == 0) 
	{
		a = a+ b;
		
		printf ("Process Q\n");
		printf ("a value: %d\n", a);
		printf ("b value: %d\n", b);
		printf ("The value of PID: %d\n", getpid());
		printf ("Parent's PID: %d\n", getppid());
		printf ("\n");
			
		fr = fork(); 
		if (fr != 0)
		{
			b = b + 15;
			printf ("\n");
			printf ("parent Process P\n");
			printf ("a value: %d\n", a);
			printf ("b value : %d\n", b);
			printf ("The value of PID: %d\n", getpid());
			printf ("Parent's PID: %d\n", getppid());
			printf ("\n");
		}
		else 
		{
			printf ("Process R\n");
			a = (a*b) + 20;
			printf ("a value: %d\n", a);
			printf ("b value: %d\n", b);
			printf ("The value of PID: %d\n", getpid());
			printf ("Parent's PID: %d\n", getppid());
			printf ("\n");
		}
			
	}else
	{
		b = a + b - 5;
		printf ("Parent Process P\n");
		printf ("a value : %d\n", a);
		printf ("b value : %d\n", b);
		printf ("The value of PID: %d\n", getpid());
		printf ("Parent's PID: %d\n", getppid());
		printf ("\n");
	}
return 0;

}
