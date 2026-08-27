#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long long N = 1000000;
    long long inside = 0;

    srand(time(NULL));

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (long long i = 0; i < N; i++)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1.0)
        {
            inside++;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double pi = 4.0 * inside / N;

    double time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Total Points   : %lld\n", N);
    printf("Estimated Pi   : %.10f\n", pi);
    printf("Execution Time : %.6f seconds\n", time_taken);

    return 0;
}