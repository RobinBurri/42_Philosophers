#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

// add arg: -pthread with gcc

/*
UNIX THREADS in C video 6 intro, get return value form a thread, pass arguments to threads;
*/

int mails = 0;
pthread_mutex_t mutex;

void* roll_dice() 
{
	int value = (rand() % 6) + 1;
	int *result = malloc(sizeof(int));
	*result = value;
	printf("thread res: %d\n", value);
	return ((void *) result);
}

int main(int argc, char **argv)
{
	int *res;
	srand(time(NULL));
	pthread_t th;

	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return 1;
	if (pthread_join(th, (void**) &res) != 0)
		return 2;
	printf("main res: %d\n", *res);
	free(res);
	return (0);
}

// ex roll 8 dice in parallel