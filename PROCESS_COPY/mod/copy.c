#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

int main(int argc,char* argv[])
{
	int src_fd;
	int des_fd;
	int blocksize=atoi(argv[3]);
	int offset=atoi(argv[4]);
	src_fd=open(argv[1],O_RDONLY);
	des_fd=open(argv[2],O_WRONLY);
	lseek(src_fd,offset,SEEK_SET);
	lseek(des_fd,offset,SEEK_SET);
	char buffer[blocksize];
	ssize_t len;
	len=read(src_fd,buffer,sizeof(buffer));
	write(des_fd,buffer,len);
	printf("copy chile success,pid=%d,offset=%d,blocksize=%d\n",getpid(),offset,blocksize);
	close(src_fd);
	close(des_fd);

	return 0;
}

