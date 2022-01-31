#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// add arg: -pthread with gcc

/*
UNIX THREADS in C video 1 - 5 intro, difference process & thread, race condition,
pthread_mutex, create threads in a loop
*/
/*
	Differences between processes and threads:
	processes can have multiple threads with the same pid
	ADDRESSES SPACES:
	in Processes all variables are duplicated but 
	in threads they all access the same variables
*/

int mails = 0;
pthread_mutex_t mutex;

void* routine() 
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		//read, increment, write
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_mutex_init(&mutex, NULL);
	// NULL = customization
	pthread_t p[3];
	
	for (int i = 0; i < 3; i++){
		if (pthread_create(&p[i], NULL, &routine, NULL) != 0)
		{
			perror("Failed to create thread");
			return 2;
		}
		printf("Thread %d has started\n", i);
	}
	for (int i = 0; i < 3; i++)
	{
		if (pthread_join(p[i], NULL) != 0)
			return 3;
		printf("Thread %d has finished\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
}

