#include <process_copy.h>
int process_create(char* scrfile,char* destfile,int pronum,int blocksize)
{
	pid_t pid; 
	int i;
	for(i=0;i<pronum;i++)
	{
		pid=fork();
		if(0==pid)
		{
			break;
		}
	}
	if(pid>0)
	{
		process_wait();
	}else if(0==pid)
	{
		char Blocksize[20]={};
		char offset[20]={};
		sprintf(Blocksize,"%d",blocksize);
		sprintf(offset,"%d",i*blocksize);
		execl("/home/colin/PROCESS_COPY/mod/copy","copy",scrfile,destfile,Blocksize,offset,NULL);
	}else 
	{
		perror("fork call failed");
		return 0;
	}
	return 1;
}
