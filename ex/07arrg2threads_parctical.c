#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// add arg: -pthread with gcc

/*
UNIX THREADS in C video 8 practical exemple using threads;
*/

// sum all numbers of the primes array

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{	
	int index = *(int*)arg;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += primes[index + i];
	}
	*(int*)arg = sum;
	return arg;
}

int main(int argc, char **argv)
{
	int num = 2;
	pthread_t th[num];
	for (int i = 0; i < num; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			return 2;
		}
	}
	int global_sum = 0;
	for (int i = 0; i < num; i++)
	{
		int *r;
		if (pthread_join(th[i], (void**)&r) != 0)
			return 2;
		global_sum += *r;
		free(r);
	}
	printf("global_sum: %d\n", global_sum);
	return (0);
}
