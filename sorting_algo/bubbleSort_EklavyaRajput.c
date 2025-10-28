#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void bubbleSort(int *A, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {  // Correct comparison
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    int repetitions = 1;  // Reduced repetitions for speed
    clock_t start = clock();
    for (int i = 0; i < repetitions; i++) {
        generateRandomArray(arr, n);
        bubbleSort(arr, n);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
    printf("Average time to sort %d elements using Bubble Sort: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
