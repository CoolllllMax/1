#include <process_copy.h>
int pram_check(char* filename,int argc,int pronum)
{
	if(argc<3)
	{
		return 0;
	}
	if(!(pronum>=6&&pronum<=100))
	{
		return 0;
	}
	if(0!=access(filename,F_OK))
	{
		return 0;
	}

	return 1;
}
