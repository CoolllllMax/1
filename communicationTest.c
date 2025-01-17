#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <signal.h>

void sig_communication(int n,siginfo_t* info,void* arg)
{
	if(SIGUSR1==n)
	{
		printf("child received：%d\n",info->si_int);
		union sigval val;
		val.sival_int=info->si_int+1;
		sigqueue(getpgrp(),SIGUSR2,val);
	}else if(SIGUSR2==n)
	{
		printf("parent received：%d\n",info->si_int);
	}
}

int main()
{
	pid_t pid;
	union sigval val;
	val.sival_int=1;
	sigset_t set,oset;
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1);
	sigprocmask(SIG_SETMASK,&set,&oset);
	pid=fork();
	if(pid>0)
	{
		struct sigaction act,oact;
		act.sa_sigaction=sig_communication;
		act.sa_flags=SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR2,&act,&oact);
		while(1)
		{
			sigqueue(pid,SIGUSR1,val);
			val.sival_int+=2;
			pause();
			sleep(1);
		}
	}else if(0==pid)
	{
		struct sigaction act,oact;
		act.sa_sigaction=sig_communication;
		act.sa_flags=SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1,&act,&oact);
		sigprocmask(SIG_SETMASK,&oset,&set);
		while(1)
		{
			pause();
		}
	}else 
	{
		perror("fork fail");
		exit(0);
	}

	return 0;
}
