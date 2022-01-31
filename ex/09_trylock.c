#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// add arg: -pthread with gcc

/*
UNIX THREADS in C video 9 mutex_lock vs mutex_trylock
pthread_mutex, create threads in a loop
*/

/*
    with mutex_lock thread will wait to have it and than run the code
    but with mutex_trylock it will try once and if EBUSY (not 0) errno
    it will continue in the else part
*/
pthread_mutex_t mutex;

void *routine()
{
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Got lock\n");
        sleep(1);
    } else {
        printf("Didin't get lock\n");
    }
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t p[4];

    for (int i = 0; i < 3; i++)
    {
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
    return (0);
}
