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
	
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd) 
	{
		printf("\n open() Error encountered [%s]\n", strerror(errno));
		perror("open"); 
		return 1;
	}	
	else
	{
		position = lseek(fd, 0, SEEK_END);
		char buf[position]; 
		lseek (fd, 0, SEEK_SET); 
		read(fd, buf, position); 
		write(1, buf, position); 
		close (fd); 
	}
return 0;
}