#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int image[N][N];
int output[N][N];

int main()
{
    // Initialize image
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            image[i][j] = rand() % 256;
        }
    }

    int kernel[3][3] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    // Edge detection
    for (int i = 1; i < N - 1; i++)
    {
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

    clock_gettime(CLOCK_MONOTONIC, &end);

    double execution_time =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Image Size    : %d x %d\n", N, N);
    printf("Execution Time: %.6f seconds\n",
           execution_time);

    return 0;
}