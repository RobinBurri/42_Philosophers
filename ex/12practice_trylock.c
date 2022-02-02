#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = {100, 100, 100, 100};

void *routine(void *args)
{
	for (int i = 0; i < 4; i++)
	{
		if (pthread_mutex_trylock(&stoveMutex[i]) == 0)
		{
			int fuel_needed = (rand() % 20);

			if (stoveFuel[i] - fuel_needed < 0)
				printf("no more fuel... going home\n");
			else
			{
				stoveFuel[i] -= fuel_needed;
				usleep(500000);
				printf("stove number: %d, Fuel left: %d\n", i, stoveFuel[i]);
			}
			pthread_mutex_unlock(&stoveMutex[i]);
			break;
		} else {
			if (i == 3) {
				printf("no stove available\n");
				usleep(300000);
				i = 0;
			}
		}
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	int chefs = 20;
	pthread_t th[chefs];
	for (int i = 0; i < 4; i++)
	{
		pthread_mutex_init(&stoveMutex[i], NULL);
	}
	for (int i = 0; i < chefs; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}

	for (int i = 0; i < chefs; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	for (int i = 0; i < 4; i++)
	{
		pthread_mutex_destroy(&stoveMutex[i]);
	}
	return (0);
}