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
	ssize_t position;
	
	fd = open("source.txt", O_RDONLY); 
	if (-1 == fd) 
	{
		printf("\n open() Error encountered [%s]\n", strerror(errno));
		perror("open"); 
		return 1;
	}	
	
	position = lseek(fd, 0, SEEK_END); 
	char buf[position]; 
	
	lseek (fd, 0, SEEK_SET); 
	
	read(fd, buf, position);
	int fd1;
	fd1 = open("destination.txt", O_RDWR | O_CREAT, 0644); 
	
	if (-1 == fd1) 
	{
		printf("\n open() Error encountered [%s]\n", strerror(errno));
		perror("open"); 
		return 1;
	}		

	write(fd1, buf, position); 
	close (fd); 
	close (fd1);
	
return 0;
}
