#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg)
{
    int id = *(int *)arg;

    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    for (int i = 0; i < 3; i++)
    {
        printf("Philosopher %d is thinking\n", id);

        sleep(1);

        /*
         * To avoid deadlock:
         * Even philosophers pick left first.
         * Odd philosophers pick right first.
         */

        if (id % 2 == 0)
        {
            pthread_mutex_lock(&chopsticks[left]);
            pthread_mutex_lock(&chopsticks[right]);
        }
        else
        {
            pthread_mutex_lock(&chopsticks[right]);
            pthread_mutex_lock(&chopsticks[left]);
        }

        printf("Philosopher %d is eating\n", id);

        sleep(1);

        pthread_mutex_unlock(&chopsticks[left]);
        pthread_mutex_unlock(&chopsticks[right]);

        printf("Philosopher %d finished eating\n", id);
    }

    return NULL;
}

int main()
{
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_id[NUM_PHILOSOPHERS];

    // Initialize chopsticks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        philosopher_id[i] = i;

        pthread_create(
            &philosophers[i],
            NULL,
            philosopher,
            &philosopher_id[i]
        );
    }

    // Wait for philosophers
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(
            philosophers[i],
            NULL
        );
    }

    // Destroy chopsticks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    printf("\nAll philosophers finished.\n");

    return 0;
}