#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	int fd;
	
	fd = open("source.txt", O_RDONLY); 
	if (-1 == fd) 
	{
		printf("\n open() Error encountered [%s]\n", strerror(errno));
		perror("open"); 
		return 1;
	}	
	
	int fd1;
	fd1 = open ("destination.txt", O_RDWR | O_CREAT, 0644);
	
	if (-1 == fd) 
	{
		printf("\n open() Error encountered [%s]\n", strerror(errno));
		perror("open"); 
		return 1;
	}
	ssize_t read_value = 1;	
	char buf[50];
	char add[3] = "XYZ";
	
	while (read_value > 0) 
	{
		read_value = read(fd, buf, 50); 
		write (fd1, buf, read_value); 
		read_value = read(fd, buf, 50); 
		
		for(int a = 0; a < 50; a = a+ 1) 
		{
			if (buf[a] == '5')  
				buf[a] = 'A';		
		}
		write (fd1, buf, read_value); 
		write (fd1, add, 3); 

	}
	
	close (fd);
	close (fd1);
	
return 0;
}
