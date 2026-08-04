#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000   // Use 10000 for Bubble Sort. Increase later if required.

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int *original = (int *)malloc(SIZE * sizeof(int));
    int *bubbleArray = (int *)malloc(SIZE * sizeof(int));
    int *quickArray = (int *)malloc(SIZE * sizeof(int));

    if(original == NULL || bubbleArray == NULL || quickArray == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random temperatures
    for(int i = 0; i < SIZE; i++)
    {
        original[i] = rand() % 100;
    }

    // Copy data into two arrays
    for(int i = 0; i < SIZE; i++)
    {
        bubbleArray[i] = original[i];
        quickArray[i] = original[i];
    }

    clock_t start, end;

    // Bubble Sort Timing
    start = clock();
    bubbleSort(bubbleArray, SIZE);
    end = clock();

    double bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Quick Sort Timing
    start = clock();
    quickSort(quickArray, 0, SIZE - 1);
    end = clock();

    double quickTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nBubble Sort Time : %.4f seconds\n", bubbleTime);
    printf("Quick Sort Time  : %.4f seconds\n", quickTime);

    free(original);
    free(bubbleArray);
    free(quickArray);

    return 0;
}
