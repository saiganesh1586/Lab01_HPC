#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 1000
#define NUM_THREADS 16

int image[N][N];
int output[N][N];

int kernel[3][3] = {
    {-1, -1, -1},
    {-1,  8, -1},
    {-1, -1, -1}
};

void *edge_detection(void *arg)
{
    int thread_id = *(int *)arg;

    int rows_per_thread = N / NUM_THREADS;

    int start_row = thread_id * rows_per_thread;
    int end_row = start_row + rows_per_thread;

    if (thread_id == NUM_THREADS - 1)
    {
        end_row = N - 1;
    }

    for (int i = start_row; i < end_row; i++)
    {
        if (i == 0 || i == N - 1)
            continue;

        for (int j = 1; j < N - 1; j++)
        {
            int sum = 0;

            for (int ki = -1; ki <= 1; ki++)
            {
                for (int kj = -1; kj <= 1; kj++)
                {
                    sum +=
                        image[i + ki][j + kj] *
                        kernel[ki + 1][kj + 1];
                }
            }

            output[i][j] = sum;
        }
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_id[NUM_THREADS];

    // Initialize image
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            image[i][j] = rand() % 256;
        }
    }

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_id[i] = i;

        pthread_create(
            &threads[i],
            NULL,
            edge_detection,
            &thread_id[i]
        );
    }

    // Wait for threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(
            threads[i],
            NULL
        );
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double execution_time =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Image Size     : %d x %d\n", N, N);
    printf("Threads        : %d\n", NUM_THREADS);
    printf("Execution Time : %.6f seconds\n",
           execution_time);

    return 0;
}