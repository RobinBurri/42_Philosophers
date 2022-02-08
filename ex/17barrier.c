#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// add arg: -pthread with gcc

//UNIX THREADS in C video 17 detached threads

/*
    detached thread cannot bet join again
	using pthread_attr_t because there might be some case where the thread finish execution
	before he is detached, so we create it as detached and not use pthread_detach
*/

void *routine(void *args)
{
	sleep(1);
	printf("finished \n");
	return (NULL);
}


int main(int ac, char **av)
{
	pthread_t th[2];
	pthread_attr_t detachedThreads;
	pthread_attr_init(&detachedThreads);
	pthread_attr_setdetachstate(&detachedThreads, PTHREAD_CREATE_DETACHED);
	for (int i = 0; i < 2; i++)
	{
		if (pthread_create(&th[i], &detachedThreads, &routine, NULL) != 0)
			perror("Fail to create thread");
		// pthread_detach(th[i]);
	}

	// CANNOT JOIN DETACHED THREADS, IF WE DO => ERROR, FAILED TO JOIN THREADS
	// for (int i = 0; i < 2; i++)
	// {
	// 	if (pthread_join(th[i], NULL) != 0)
	// 		perror("Failed to join thread");
	// }
	pthread_attr_destroy(&detachedThreads);
	pthread_exit(0);
	return (0);
}