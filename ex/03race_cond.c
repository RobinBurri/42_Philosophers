#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// add arg: -pthread with gcc

//UNIX THREADS in C video 1 - 3 intro, difference process & thread, race condition
/*
	Differences between processes and threads:
	processes can have multiple threads with the same pid
	ADDRESSES SPACES:
	in Processes all variables are duplicated but 
	in threads they all access the same variables
*/

int mails = 0;

void	*routine() {
	mails++;
}

int main(int argc, char **argv)
{
	pthread_t p1, p2;

	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
	// pointer to pthread var, customiztion, pointer to func, argum to func (none here) 
		return 1;
	if (pthread_create(&p2, NULL, &routine, NULL) != 0) 
		return 2;
	if (pthread_join(p1, NULL) != 0)
		return 3;
	// wait the thread, pthread var, pointer to get the return of function, (here none)
	if (pthread_join(p2, NULL) != 0)
		return 4;
}

