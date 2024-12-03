#include <process_copy.h>
int process_wait()
{
	pid_t pid;
	while(-1!=(pid=waitpid(-1,NULL,WNOHANG)))
	{
		if(pid>0)
		{
			printf("parent wait success pid=%d\n",pid);
		}
	}

	return 1;
}
