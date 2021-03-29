#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
   //create destination.txt and open
   int fd = open("destination.txt", O_RDWR|O_CREAT);
   if (errno == EACCES)
        printf (" File not found/access\n");
    
    else{
        printf("destination.txt file is created\n");
        }
   return 0;
}
