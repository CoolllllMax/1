#include <process_copy.h>
int blockcur(char* filename,int pronum)
{
	int blocksize=0;
	int fd=open(filename,O_RDONLY);
	int size=lseek(fd,0,SEEK_END);
	blocksize=size/pronum;
	if(size%pronum!=0)
	{
		blocksize+=1;
	}

	return blocksize;
}
