#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int fd1,buffersize;
	fd1 =open("file1.txt",O_RDONLY);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=300;
	char buf[maxlen];
    int fd2,size_file;
	fd2=open("file2.txt",O_WRONLY|O_CREAT, 0666);
	if(fd2<0)
	{
		perror("open");
		exit(3);
	}
    while(buffersize=read(fd1,buf,maxlen))
    {
	    size_file =	write(fd2, buf, maxlen);
        if(size_file<0)
	    {
		    perror("write");
		    exit(4);
	    }
    }

    
    close(fd1);
    close(fd2);
    printf("Copy Successful \n");
}