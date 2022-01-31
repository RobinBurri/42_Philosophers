#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// add arg: -pthread with gcc

/*
UNIX THREADS in C video 6 - 7 intro, get return value form a thread, pass arguments to threads;
*/

// int mails = 0;
// pthread_mutex_t mutex;

void* roll_dice(void *index) 
{
	int value = (rand() % 6) + 1;
	res[*(int*)index] = value;
	printf("thread res: %d\n", value);
	return ((void *) result);
}

// int main(int argc, char **argv)
// {
// 	int *res;
// 	srand(time(NULL));
// 	pthread_t th;

// 	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
// 		return 1;
// 	if (pthread_join(th, (void**) &res) != 0)
// 		return 2;
// 	printf("main res: %d\n", *res);
// 	free(res);
// 	return (0);
// }



// ex roll 8 dice in parallel

int main(int argc, char **argv)
{
	int num;
	if (argc != 2)
		return 1;
	num = atoi(argv[1]);
	srand(time(NULL));
	int res[] = malloc(sizeof(int) * num);
	pthread_t th[num];
	for (int i = 0; i < num; i++)
	{
		if (pthread_create(&th[i], NULL, &roll_dice, &i) != 0)
		{
			perror("Failed to create thread");
			return 2;
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (pthread_join(th[i], (void**)&res[i]) != 0)
			return 2;
		printf("thread:%d, value:%d\n", i, res[i] );
	}
}