#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char* argv[])
{
	char* filepath = argv[1];
	int returnval;
	
	// Check file existence
	returnval = access (filepath, F_OK);
	if (returnval == 0)
		printf ("\n %s exists\n", filepath);
	else
	{
		if (errno == ENOENT)
			printf ("%s does not exist\n", filepath);
		else if (errno == EACCES)
			printf ("%s is not accessible\n", filepath);
		return 0;
	}

	// Check read access 
	int readval;
	readval = access (filepath, R_OK);
	if (readval == 0)
		printf ("\n %s Read access available\n", filepath);
	else
	{
		printf ("\n %s Does not have read access\n", filepath);
		perror(" There is a Read-access Error"); 
	}

	// Check write access
	int writeval;
	writeval = access (filepath, W_OK);
	if (writeval == 0)
		printf ("\n %s Write access available \n", filepath);
	else
	{
		printf ("\n %s oes not have write access\n", filepath);
		perror("There is a write-access Error"); 
	}
	return 0;
}