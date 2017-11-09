#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

void sighandle(int signum)
{
	if (signum == SIGINT)
	{
		printf("\nReceived a SIGINT signal, exiting.\n");
		exit(0);
	}
	else
	{
		if (signum == SIGUSR1)
		{
			printf("Received SIGUSR1. How mysterious.\n");
		}
	}
}

int main()
{
	while (1)
	{
		signal(SIGINT, sighandle);
		signal(SIGUSR1, sighandle);
		printf("Hi there, my PID is: %d\n", getpid());
		sleep(2);
		
	}
	return 0;
}