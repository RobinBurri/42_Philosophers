#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// add arg: -pthread with gcc

/*
UNIX THREADS in C video 6 - 7 intro, get return value form a thread, pass arguments to threads;
*/

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{	
	int index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int main(int argc, char **argv)
{
	int num = 10;
	pthread_t th[num];
	for (int i = 0; i < num; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			return 2;
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return 2;
	}
}