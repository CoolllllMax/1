#include <process_copy.h>
int main(int argc,char* argv[])
{
	int pronum=6;
	if(argv[3]!=0)
	{
		pronum=atoi(argv[3]);
	}
	if(0==pram_check(argv[1],argc,pronum))
	{
		printf("参数不合法\n");
		exit(0);
	}
	int blocksize=blockcur(argv[1],pronum);
	process_create(argv[1],argv[2],pronum,blocksize);

	return 0;
}
