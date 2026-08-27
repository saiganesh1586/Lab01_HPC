#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 16
#define TOTAL_POINTS 1000000

long long points_inside[NUM_THREADS];

void *calculate_pi(void *arg)
{
    int thread_id = *(int *)arg;

    long long points_per_thread =
        TOTAL_POINTS / NUM_THREADS;

    long long start =
        thread_id * points_per_thread;

    long long end =
        start + points_per_thread;

    unsigned int seed =
        time(NULL) + thread_id;

    points_inside[thread_id] = 0;

    for (long long i = start; i < end; i++)
    {
        double x =
            (double)rand_r(&seed) / RAND_MAX;

        double y =
            (double)rand_r(&seed) / RAND_MAX;

        if (x * x + y * y <= 1.0)
        {
            points_inside[thread_id]++;
        }
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_id[NUM_THREADS];

    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_id[i] = i;

        pthread_create(
            &threads[i],
            NULL,
            calculate_pi,
            &thread_id[i]
        );
    }

    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(
            threads[i],
            NULL
        );
    }

    // Combine results
    long long total_inside = 0;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        total_inside += points_inside[i];
    }

    double pi =
        4.0 * total_inside / TOTAL_POINTS;

    clock_gettime(
        CLOCK_MONOTONIC,
        &end_time
    );

    double execution_time =
        (end_time.tv_sec - start_time.tv_sec) +
        (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Total Points   : %d\n", TOTAL_POINTS);
    printf("Threads        : %d\n", NUM_THREADS);
    printf("Estimated Pi   : %.10f\n", pi);
    printf("Execution Time : %.6f seconds\n",
           execution_time);

    return 0;
}